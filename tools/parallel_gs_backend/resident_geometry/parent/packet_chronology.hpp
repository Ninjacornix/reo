#pragma once
// Private command metadata only. No numerical work or ownership certificate.
#include <algorithm>
#include <cstdint>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <vector>

namespace reo_palette_authority {
constexpr uint32_t RamBytes = 32u * 1024u * 1024u, PacketBytes = 0xfb0u, PayloadBytes = 0xf80u;
constexpr uint32_t PayloadOffset = 0x20u;
enum class ResetKind : uint8_t { GsOnly, GuestMemory, ContextHandoff, Stop };
enum class Phase : uint8_t { Allocated, Uniforms, Palette, Copy3FC0, Light, Material, Finalized };
struct Allocation {
    const void* memory = nullptr;
    const void* context = nullptr;
    uint64_t session = 0, generation = 0, revision = 0, epoch = 0, contextGeneration = 0;
    uint32_t packet = 0, descriptor = 0, parent = 0, stack = 0, outerReturnPC = 0;
    int32_t task = -1;
    bool live = false, gpuOwned = false, finalized = false, unknownWriter = false;
};
struct SnapshotKey {
    uint64_t session = 0, epoch = 0, bankGeneration = 0, allocation = 0, revision = 0, ordinal = 0;
    uint32_t source = 0, bytes = 0;
};
struct OriginSpan {
    uint32_t offset = 0, address = 0, bytes = 0;
    uint64_t allocation = 0, revision = 0;
    bool scratch = false;
};
// An immutable DMA snapshot can remain alive after allocation reuse. A live
// lookup must never resolve an old generation from a matching pointer/address.
struct FrozenIdentity {
    SnapshotKey key{};
    std::shared_ptr<const Allocation> source;
};
struct SourceCoverage {
    bool independentParentDeviceParity = false, allParentPhases = false;
    bool allVu0Accesses = false, allRamSprWriters = false, realContextWait = false;
    bool chronologyCaptured = false, sameDeviceOrderedOwner = false;
    bool complete() const noexcept {
        return independentParentDeviceParity && allParentPhases && allVu0Accesses &&
               allRamSprWriters && realContextWait && chronologyCaptured && sameDeviceOrderedOwner;
    }
};
class Chronology {
    mutable std::recursive_mutex mutex_;
    std::vector<std::shared_ptr<Allocation>> live_;
    uint64_t session_ = 1, epoch_ = 1, nextGeneration_ = 1, nextSnapshot_ = 1,
             contextGeneration_ = 1;
    static bool range(uint32_t at, uint32_t bytes) noexcept {
        return bytes && at < RamBytes && bytes <= RamBytes - at;
    }
    static bool overlaps(uint32_t a, uint32_t n, uint32_t b, uint32_t m) noexcept {
        return uint64_t(a) < uint64_t(b) + m && uint64_t(b) < uint64_t(a) + n;
    }

  public:
    static constexpr size_t MaxLive = 4096;
    uint64_t epoch() const {
        std::lock_guard<std::recursive_mutex> g(mutex_);
        return epoch_;
    }
    std::shared_ptr<const Allocation> allocationReturned(const void* memory, const void* context,
                                                         uint32_t packet, uint32_t descriptor,
                                                         uint32_t parent, uint32_t stack,
                                                         uint32_t outerReturnPC, int32_t task) {
        std::lock_guard<std::recursive_mutex> g(mutex_);
        if (!memory || !context || !range(packet, PacketBytes) || (packet & 15u) ||
            (parent != 0x19bbd0u && parent != 0x19b1c0u))
            throw std::invalid_argument("Not an actual palette allocator return");
        for (auto& a : live_)
            if (a->memory == memory && overlaps(packet, PacketBytes, a->packet, PacketBytes))
                a->live = false;
        live_.erase(
            std::remove_if(live_.begin(), live_.end(), [](const auto& a) { return !a->live; }),
            live_.end());
        if (live_.size() >= MaxLive)
            throw std::overflow_error(
                "Live allocation chronology requires retirement; no ID recycling");
        if (!nextGeneration_)
            throw std::overflow_error("Allocation generation exhausted");
        auto a = std::make_shared<Allocation>();
        a->memory = memory;
        a->context = context;
        a->session = session_;
        a->generation = nextGeneration_++;
        a->revision = 1;
        a->epoch = epoch_;
        a->contextGeneration = contextGeneration_;
        a->packet = packet;
        a->descriptor = descriptor;
        a->parent = parent;
        a->stack = stack;
        a->outerReturnPC = outerReturnPC;
        a->task = task;
        a->live = true;
        live_.push_back(a);
        return a;
    }
    std::shared_ptr<const Allocation> resolve(const void* memory, uint32_t at,
                                              uint32_t bytes) const {
        std::lock_guard<std::recursive_mutex> g(mutex_);
        if (!range(at, bytes))
            return {};
        for (auto i = live_.rbegin(); i != live_.rend(); ++i) {
            const auto& a = *i;
            if (a->live && !a->unknownWriter && a->memory == memory && a->epoch == epoch_ &&
                a->session == session_ && at >= a->packet &&
                uint64_t(at) + bytes <= uint64_t(a->packet) + PacketBytes)
                return a;
        }
        return {};
    }
    void notedWrite(const void* memory, uint32_t at, uint32_t bytes, bool knownOrderedWriter) {
        std::lock_guard<std::recursive_mutex> g(mutex_);
        if (!range(at, bytes))
            throw std::out_of_range("Invalid raw writer range");
        for (auto& a : live_)
            if (a->live && a->memory == memory && overlaps(at, bytes, a->packet, PacketBytes)) {
                if (a->revision == UINT64_MAX)
                    throw std::overflow_error("Packet revision exhausted");
                ++a->revision;
                a->finalized = false;
                if (!knownOrderedWriter)
                    a->unknownWriter = true;
            }
    }
    void own(uint64_t generation, const SourceCoverage& coverage) {
        std::lock_guard<std::recursive_mutex> g(mutex_);
        if (!coverage.complete())
            throw std::runtime_error("Whole parent/VU0/writer authority is unproved");
        for (auto& a : live_)
            if (a->live && a->generation == generation && !a->unknownWriter) {
                a->gpuOwned = true;
                return;
            }
        throw std::runtime_error("Missing or invalidated parent allocation");
    }
    // Called only after the complete parent GPU commands have been RECORDED in
    // their actual owner FIFO. This does not authorize PC=RA or a busy clear.
    void finalizedRecorded(uint64_t generation) {
        std::lock_guard<std::recursive_mutex> g(mutex_);
        for (auto& a : live_)
            if (a->live && a->generation == generation && a->gpuOwned && !a->unknownWriter) {
                a->finalized = true;
                return;
            }
        throw std::runtime_error("Cannot finalize an unowned or stale palette packet");
    }
    FrozenIdentity freeze(const void* memory, uint64_t generation, uint64_t bankGeneration) {
        std::lock_guard<std::recursive_mutex> g(mutex_);
        for (auto& a : live_)
            if (a->live && a->memory == memory && a->generation == generation &&
                a->epoch == epoch_ && a->gpuOwned && a->finalized && !a->unknownWriter &&
                bankGeneration) {
                if (!nextSnapshot_)
                    throw std::overflow_error("DMA snapshot ordinal exhausted");
                FrozenIdentity f;
                f.key = {session_,
                         epoch_,
                         bankGeneration,
                         a->generation,
                         a->revision,
                         nextSnapshot_++,
                         a->packet + PayloadOffset,
                         PayloadBytes};
                // Freeze the allocation fields themselves; later revisions do not
                // mutate this snapshot. The backend also copies the actual GPU bytes.
                f.source = std::make_shared<const Allocation>(*a);
                return f;
            }
        throw std::runtime_error("No generation-exact finalized GPU source for DMA snapshot");
    }
    static bool exactJoin(const FrozenIdentity& frozen, const OriginSpan* spans, size_t count,
                          uint32_t bytes) noexcept {
        if (!frozen.source || !spans || !count || bytes != PayloadBytes ||
            frozen.key.bytes != bytes)
            return false;
        uint64_t cursor = 0;
        for (size_t i = 0; i < count; ++i) {
            const auto& s = spans[i];
            if (!s.bytes || s.scratch || s.offset != cursor ||
                s.address != uint64_t(frozen.key.source) + cursor ||
                s.allocation != frozen.key.allocation || s.revision != frozen.key.revision ||
                uint64_t(s.bytes) > bytes - cursor)
                return false;
            cursor += s.bytes;
        }
        return cursor == bytes;
    }
    void reset(ResetKind kind, uint64_t newEpoch, bool actualPriorQueueRetired) {
        std::lock_guard<std::recursive_mutex> g(mutex_);
        if (!actualPriorQueueRetired || newEpoch <= epoch_)
            throw std::runtime_error(
                "Reset requires actual prior device retirement and newer epoch");
        epoch_ = newEpoch;
        if (kind == ResetKind::GsOnly) {
            for (auto& a : live_)
                a->epoch = epoch_;
            return;
        }
        for (auto& a : live_)
            a->live = false;
        live_.clear();
        if (kind == ResetKind::ContextHandoff)
            ++contextGeneration_;
        else
            ++session_;
        if (!session_ || !contextGeneration_)
            throw std::overflow_error("Producer identity exhausted");
        // Frozen buffers retain their immutable lifetime, but old epoch tokens
        // cannot enter a new VIF owner. Counters never recycle after a reset.
    }
};
} // namespace reo_palette_authority
