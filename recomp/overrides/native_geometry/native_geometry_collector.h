#pragma once
#include "runtime/ps2_vu1.h"
#include "vu_specialized_route.h"
#include "native_geometry_refusal.h"
#include <array>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <memory>
#include <new>
bool ps2VifKickVuProfileActive() noexcept;
void ps2PoseOriginCapture(uint32_t, uint32_t, const void*, size_t, const void*, size_t,
                          const uint8_t*, size_t) noexcept;
namespace reo_native_collector {
constexpr unsigned MaxAttempts = 4096, MaxSamples = 32, MaxKeys = 128;
struct Key {
    uint32_t kind, reason, pc, mode, countBucket, nanMask, qClass, pClass, rawWClass;
    bool operator==(const Key&) const = default;
};
struct Counts {
    Key key{};
    uint64_t count = 0;
    uint32_t firstAttempt = 0, samples = 0;
};
struct Slot {
    uint32_t kind = 0, attempt = 0, accepted = 0, remaining = 0, pairs = 0, vertices = 0;
    uint32_t prePending = 0, preTarget = 0, postPending = 0, postTarget = 0, preMXCSR = 0,
             postMXCSR = 0;
    reo_native_refusal::Event event{};
    VU1State preState{}, postState{};
    std::array<uint8_t, 16384> preData{}, postData{};
};
// IEEE classification describes host storage only; it does not classify a PS2
// exponent255 encoding as malformed guest data. W is explicitly a raw lane.
inline uint32_t rawClass(uint32_t bits) {
    const uint32_t exponent = bits & 0x7f800000u, mantissa = bits & 0x7fffffu;
    return !exponent ? (mantissa ? 1u : 0u) : exponent != 0x7f800000u ? 2u : mantissa ? 4u : 3u;
}
inline uint32_t bucket(uint32_t count) {
    return !count         ? 0u
           : count <= 16  ? 1u
           : count <= 64  ? 2u
           : count <= 128 ? 3u
           : count <= 256 ? 4u
                          : 5u;
}
class Collector {
    std::filesystem::path directory;
    std::unique_ptr<Slot[]> slots;
    std::array<Counts, MaxKeys> keys{};
    std::array<uint8_t, 16384> code{};
    Slot beforeAccepted{};
    uint32_t attempts = 0, samples = 0, keyCount = 0;
    uint32_t incomingMXCSR = 0, incomingPending = 0, incomingTarget = 0;
    uint64_t accepted = 0, refused = 0, overflowKeys = 0, uncapturedRefusals = 0;
    bool enabled = false, haveCode = false, haveAccepted = false, preparedBefore = false;
    bool disabledByDirectory = false, ioFailure = false;

  public:
    Collector() noexcept {
        const char* value = std::getenv("REO_VU_NATIVE_DIAG_DIR");
        if (!value || !*value)
            return;
        try {
            directory = value;
            if (std::filesystem::exists(directory) && !std::filesystem::is_empty(directory)) {
                disabledByDirectory = true;
                std::fputs("[VU-NATIVE-DIAG] disabled: directory is not empty\n", stderr);
                return;
            }
            std::filesystem::create_directories(directory);
            slots.reset(new (std::nothrow) Slot[MaxSamples]);
            enabled = bool(slots);
        } catch (...) {
            disabledByDirectory = true;
            std::fputs("[VU-NATIVE-DIAG] disabled: directory initialization failed\n", stderr);
        }
    }
    ~Collector() {
        if (enabled)
            exportOwned();
    }
    bool active() const noexcept {
        return enabled && attempts < MaxAttempts && ps2VifKickVuProfileActive();
    }
    bool begin(unsigned kind, const vu_specialized::Invocation& invocation,
               const uint8_t* selectedCode) noexcept {
        if (!active() || kind > 1 || !selectedCode || !invocation.data ||
            invocation.dataBytes != 16384)
            return false;
        if (!haveCode) {
            std::memcpy(code.data(), selectedCode, code.size());
            haveCode = true;
        }
        incomingMXCSR = _mm_getcsr();
        incomingPending = unsigned(invocation.branchPending);
        incomingTarget = invocation.branchTarget;
        // Preserve the actual incoming state only while selecting the first accepted
        // sample. Failed transactions are copied afterwards because they did not mutate.
        preparedBefore = !haveAccepted;
        if (preparedBefore) {
            beforeAccepted.kind = kind;
            beforeAccepted.remaining = invocation.remainingPairs;
            beforeAccepted.prePending = unsigned(invocation.branchPending);
            beforeAccepted.preTarget = invocation.branchTarget;
            beforeAccepted.preMXCSR = _mm_getcsr();
            std::memcpy(&beforeAccepted.preState, &invocation.state, sizeof(VU1State));
            std::memcpy(beforeAccepted.preData.data(), invocation.data, 16384);
        }
        ++attempts;
        return true;
    }
    void finish(unsigned kind, const vu_specialized::Invocation& invocation, bool ok,
                uint32_t pairs, uint32_t vertices,
                const reo_native_refusal::Event& event) noexcept {
        // Called exactly once for a successfully begun attempt, before any fallback.
        Slot* sample = nullptr;
        if (ok) {
            ++accepted;
            if (!haveAccepted && preparedBefore && samples < MaxSamples) {
                sample = &slots[samples++];
                *sample = beforeAccepted;
                haveAccepted = true;
            }
        } else {
            ++refused;
            const bool arithmetic = event.reason == reo_native_refusal::Reason::QuantizationNaN;
            if (arithmetic)
                ps2PoseOriginCapture(kind, attempts, &event, sizeof(event), &invocation.state,
                                     sizeof(VU1State), invocation.data, invocation.dataBytes);
            const Key key{kind,
                          uint32_t(event.reason),
                          event.pc,
                          event.mode,
                          bucket(event.count),
                          event.nanMask,
                          arithmetic ? rawClass(event.q) : 5u,
                          arithmetic ? rawClass(event.p) : 5u,
                          arithmetic ? rawClass(event.input[3]) : 5u};
            unsigned index = 0;
            for (; index < keyCount; ++index)
                if (keys[index].key == key)
                    break;
            if (index == keyCount) {
                if (keyCount == MaxKeys) {
                    ++overflowKeys;
                    index = MaxKeys;
                } else {
                    keys[index].key = key;
                    keys[index].firstAttempt = attempts;
                    ++keyCount;
                }
            }
            if (index < MaxKeys) {
                auto& counter = keys[index];
                ++counter.count;
                // One cold sample per precise classification, reserving one slot for the
                // first accepted transaction; aggregate all remaining observed refusals.
                const unsigned cap = haveAccepted ? MaxSamples : MaxSamples - 1;
                if (!counter.samples && samples < cap) {
                    sample = &slots[samples++];
                    ++counter.samples;
                    sample->kind = kind;
                    sample->remaining = invocation.remainingPairs;
                    sample->event = event;
                    sample->prePending = incomingPending;
                    sample->preTarget = incomingTarget;
                    sample->preMXCSR = incomingMXCSR;
                    std::memcpy(&sample->preState, &invocation.state, sizeof(VU1State));
                    std::memcpy(sample->preData.data(), invocation.data, 16384);
                } else
                    ++uncapturedRefusals;
            } else
                ++uncapturedRefusals;
        }
        if (sample) {
            sample->attempt = attempts;
            sample->accepted = unsigned(ok);
            sample->pairs = pairs;
            sample->vertices = vertices;
            sample->postPending = unsigned(invocation.branchPending);
            sample->postTarget = invocation.branchTarget;
            sample->postMXCSR = _mm_getcsr();
            std::memcpy(&sample->postState, &invocation.state, sizeof(VU1State));
            std::memcpy(sample->postData.data(), invocation.data, 16384);
        }
        preparedBefore = false;
    }

  private:
    void write(const std::filesystem::path& path, const void* data, size_t bytes) {
        std::ofstream out(path, std::ios::binary);
        out.write(static_cast<const char*>(data), bytes);
        if (!out)
            throw 1;
    }
    void exportOwned() noexcept {
        try {
            if (haveCode)
                write(directory / "weighted2ea.code.bin", code.data(), code.size());
            for (unsigned n = 0; n < samples; ++n) {
                const auto& s = slots[n];
                char prefix[32];
                std::snprintf(prefix, sizeof(prefix), "sample-%04u", n);
                const std::string base = prefix;
                write(directory / (base + ".pre-state.bin"), &s.preState, sizeof(s.preState));
                write(directory / (base + ".post-state.bin"), &s.postState, sizeof(s.postState));
                write(directory / (base + ".pre-data.bin"), s.preData.data(), s.preData.size());
                write(directory / (base + ".post-data.bin"), s.postData.data(), s.postData.size());
                write(directory / (base + ".event.bin"), &s.event, sizeof(s.event));
                std::ofstream meta(directory / (base + ".json"));
                meta << "{\"version\":1,\"kind\":" << s.kind << ",\"attempt\":" << s.attempt
                     << ",\"accepted\":" << s.accepted << ",\"remaining\":" << s.remaining
                     << ",\"pairs\":" << s.pairs << ",\"vertices\":" << s.vertices
                     << ",\"pre_pending\":" << s.prePending << ",\"pre_target\":" << s.preTarget
                     << ",\"post_pending\":" << s.postPending << ",\"post_target\":" << s.postTarget
                     << ",\"pre_mxcsr\":" << s.preMXCSR << ",\"post_mxcsr\":" << s.postMXCSR
                     << "}\n";
                if (!meta)
                    throw 1;
            }
            std::ofstream out(directory / "reason-counts.csv");
            out << "kind,reason,pc,mode,count_bucket,nan_mask,q_host_class,p_host_class,raw_input_"
                   "w_host_class,count,first_attempt,samples\n";
            for (unsigned n = 0; n < keyCount; ++n) {
                const auto& c = keys[n];
                const auto& k = c.key;
                out << k.kind << ',' << k.reason << ',' << k.pc << ',' << k.mode << ','
                    << k.countBucket << ',' << k.nanMask << ',' << k.qClass << ',' << k.pClass
                    << ',' << k.rawWClass << ',' << c.count << ',' << c.firstAttempt << ','
                    << c.samples << '\n';
            }
            if (!out)
                throw 1;
            std::ofstream summary(directory / "summary.json");
            summary << "{\"version\":1,\"profile_scope_only\":true,\"attempts\":" << attempts
                    << ",\"attempt_limit\":" << MaxAttempts << ",\"samples\":" << samples
                    << ",\"sample_limit\":" << MaxSamples << ",\"accepted\":" << accepted
                    << ",\"refused\":" << refused << ",\"keys\":" << keyCount
                    << ",\"key_limit\":" << MaxKeys << ",\"overflow_key_refusals\":" << overflowKeys
                    << ",\"uncaptured_refusals\":" << uncapturedRefusals
                    << ",\"state_bytes\":" << sizeof(VU1State)
                    << ",\"event_bytes\":" << sizeof(reo_native_refusal::Event)
                    << ",\"data_bytes\":16384,\"have_code\":" << unsigned(haveCode)
                    << ",\"have_accepted_sample\":" << unsigned(haveAccepted)
                    << ",\"attempt_window_censored\":" << unsigned(attempts == MaxAttempts)
                    << "}\n";
            if (!summary)
                throw 1;
        } catch (...) {
            ioFailure = true;
            std::fputs("[VU-NATIVE-DIAG] owned-buffer export failed\n", stderr);
        }
    }
};
inline Collector& collector() {
    static Collector value;
    return value;
}
} // namespace reo_native_collector
