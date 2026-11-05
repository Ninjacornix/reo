#include "runtime_adapter.h"
#include "game/native/pcm_bridge/session_bridge.hpp"
#include "runtime/audio/native_stream_provider.h"
#include "Kernel/Syscalls/Helpers/ReoSoundBanks.h"
#include "ps2_runtime.h"
#include "../native_geometry/reo_vu_native_sha256.h"
#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <utility>

float reoAudioMasterGain();
float reoAudioStreamGain(std::uint32_t);
void reoAudioResetStreams();
void reoAudioPoll();

namespace reo_native_pcm {
namespace bridge = reo::native::pcm_bridge;
namespace output = reo::audio_output;
namespace {
constexpr std::uint64_t closed_bit = std::uint64_t{1} << 63;
static_assert(std::atomic<std::uint64_t>::is_always_lock_free);
constexpr const char* operation_names[] = {"ensure_output","queue","configure","consumed","render","discard","drain","release","queued_samples","reset","shutdown"};
constexpr const char* fault_names[] = {"none","outside_profile","bridge_refused","output_fence"};
constexpr const char* status_names[] = {"ok","invalid_input","queue_full","domain_capacity","metadata_capacity","unsupported_alias","unsupported_gain","core_refused","closed","output_fence_required","reentrant_shutdown"};
reo_native_image_identity::Digest digest(const char* hex) {
    reo_native_image_identity::Digest result{};
    const auto nibble = [](char c) { return c <= '9' ? c - '0' : c - 'a' + 10; };
    for (unsigned i = 0; i < result.size(); ++i)
        result[i] = std::uint8_t((nibble(hex[2*i]) << 4) | nibble(hex[2*i+1]));
    return result;
}
bool runtime_identity(PS2Runtime& runtime) {
    if (ps2RamBackingBytes != 32u * 1024u * 1024u || runtime.isStopRequested()) return false;
    const auto* ram = runtime.memory().getRDRAM();
    return ram && reo_native_image_identity::sha256(ram + 0x1392f8, 0x40) ==
        digest("48af9491776a966a35a3dd46ed6122d2aa237c85f2a1967c38f204a488517be8") &&
        reo_native_image_identity::sha256(ram + 0x135078, 0xf8) ==
        digest("a6ac3b23bfac0c9862d0facae8e02be99f08a69e6e20cb2dda05a10ffd3813bd");
}
bool raw_allowed(std::uint32_t raw) {
    return raw == 0 || (raw >= 0x001e0000 && raw < 0x001eff00 &&
                        (raw - 0x001e0000) % 0x20 == 0);
}
struct Frame {
    const void* owner;
    bool device;
    Frame* previous;
    static thread_local Frame* current;
    Frame(const void* value, bool callback) : owner(value), device(callback), previous(current) { current = this; }
    ~Frame() { current = previous; }
    static bool contains(const void* owner) {
        for (auto* frame = current; frame; frame = frame->previous)
            if (frame->owner == owner) return true;
        return false;
    }
    static bool device_thread() {
        for (auto* frame = current; frame; frame = frame->previous)
            if (frame->device) return true;
        return false;
    }
};
thread_local Frame* Frame::current = nullptr;

class RuntimeServices final : public HostServices {
public:
    std::int64_t now_ns() noexcept override {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count();
    }
    void poll_settings() noexcept override { reoAudioPoll(); }
    float stream_gain(std::uint32_t raw) noexcept override { return reoAudioStreamGain(raw); }
    void mix_banks(float* stereo, std::uint32_t frames) noexcept override {
        if (stereo) ps2_reo_sound::mix(stereo, frames);
    }
    float master_gain() noexcept override { return reoAudioMasterGain(); }
    void reset_stream_routes() noexcept override { reoAudioResetStreams(); }
    void reset_banks() noexcept override { ps2_reo_sound::reset(); }
    void report_fault(const Diagnostic& error) noexcept override {
        std::fprintf(stderr, "[NATIVE-PCM-ERROR] fault=%s operation=%s bridge_status=%s raw=%08x failures=%llu\n",
            fault_names[unsigned(error.fault)], operation_names[unsigned(error.operation)],
            error.bridge_status < std::size(status_names) ? status_names[error.bridge_status] : "unknown",
            error.raw, static_cast<unsigned long long>(error.hard_failures));
    }
};

struct Host final : bridge::Host {
    std::shared_ptr<HostServices> services;
    // Assigned exactly once before publication; never changed by callbacks.
    std::shared_ptr<output::Owner> output;
    std::atomic<bool> ready{false}, closing{false}, ever_started{false};
    std::mutex ensure_mutex; // Outside PCM locks; callback/output_ready never use it.
    explicit Host(std::shared_ptr<HostServices> value) : services(std::move(value)) {}
    std::int64_t now_ns() noexcept override { return services->now_ns(); }
    void poll_settings() noexcept override { services->poll_settings(); }
    void ensure_output() noexcept override {
        std::lock_guard ensure(ensure_mutex);
        if (closing.load(std::memory_order_acquire)) return;
        // Reserve the frame clock before publication: Play may allow a callback
        // before start returns. Failed attach guarantees no published callback.
        ready.store(true, std::memory_order_release);
        const auto result = output->start(); // Bridge invokes this outside PCM locks.
        if (result == output::StartResult::started || result == output::StartResult::already_started) {
            ready.store(true, std::memory_order_release);
            ever_started.store(true, std::memory_order_release);
        } else if (!ever_started.load(std::memory_order_acquire))
            ready.store(false, std::memory_order_release);
    }
    bool output_ready() noexcept override {
        // NEVER provider.status/control here: tick calls this under PCM data lock.
        return ready.load(std::memory_order_acquire);
    }
    float stream_gain(std::uint32_t raw) noexcept override { return services->stream_gain(raw); }
    void mix_banks(float* stereo, std::uint32_t frames) noexcept override { services->mix_banks(stereo, frames); }
    float master_gain() noexcept override { return services->master_gain(); }
    void reset_stream_routes() noexcept override { services->reset_stream_routes(); }
    bool stop_join_output() noexcept override {
        const auto result = output->join();
        if (result != output::JoinResult::joined) return false;
        ready.store(false, std::memory_order_release);
        return true;
    }
    void reset_banks() noexcept override { services->reset_banks(); }
    void request_stop() noexcept {
        closing.store(true, std::memory_order_release);
        output->request_stop();
        // Keep ready until fenced so already admitted work cannot switch to a
        // simultaneous headless clock while a callback is still active.
    }
};
bridge::Domain candidate_domain() {
    bridge::Domain domain;
    domain.max_channels = declared_raw_ids;
    domain.max_voices = declared_raw_ids + 1; // Original configure accepts raw voice0.
    domain.max_render_frames = declared_render_frames;
    domain.channel_metadata_bytes = domain.voice_metadata_bytes = 2 * 1024 * 1024;
    return domain;
}
}

struct Backend::State {
    std::shared_ptr<Host> host;
    bridge::Session bridge;
    std::atomic<std::uint64_t> admission{0}, first_fault{0}, hard_failures{0}, rejections{0};
    std::array<std::atomic<std::uint64_t>, 11> calls{};
    std::array<std::atomic<std::uint64_t>, 11> completed{};
    std::atomic<std::uint64_t> device_callbacks{0}, device_frames{0}, device_completed{0}, stop_requests{0}, join_attempts{0}, self_join_refusals{0};
    std::atomic<bool> reported{false};
    std::mutex lifecycle;
    bool joined = false;
    explicit State(std::shared_ptr<HostServices> services)
        : host(std::make_shared<Host>(std::move(services))), bridge(host, candidate_domain()) {}
    struct Lease {
        State& state;
        Frame frame;
        bool admitted = false;
        Lease(State& value, Operation operation, bool device) : state(value), frame(&value, device) {
            ++state.calls[unsigned(operation)];
            auto current = state.admission.load(std::memory_order_acquire);
            while (!(current & closed_bit) && current != closed_bit - 1)
                if (state.admission.compare_exchange_strong(current, current + 1,
                       std::memory_order_acq_rel, std::memory_order_acquire)) { admitted = true; break; }
        }
        ~Lease() {
            if (admitted) {
                state.admission.fetch_sub(1, std::memory_order_acq_rel);
                state.admission.notify_all();
            }
        }
    };
    void stop() {
        ++stop_requests;
        admission.fetch_or(closed_bit, std::memory_order_acq_rel);
        host->request_stop();
    }
    void fault(Operation operation, Fault reason, bridge::Status status, std::uint32_t raw = 0) {
        ++hard_failures;
        const auto encoded = (std::uint64_t(reason) << 56) | (std::uint64_t(operation) << 48) |
                             (std::uint64_t(status) << 40) | raw;
        std::uint64_t empty = 0;
        first_fault.compare_exchange_strong(empty, encoded, std::memory_order_acq_rel);
        stop();
    }
    bool key(Operation operation, std::uint32_t raw) {
        if (raw_allowed(raw)) return true;
        fault(operation, Fault::outside_profile, bridge::Status::invalid_input, raw);
        return false;
    }
    bool checked(Operation operation, bridge::Status status, std::uint32_t raw = 0) {
        if (status == bridge::Status::ok) { ++completed[unsigned(operation)]; return true; }
        if (status == bridge::Status::closed) return false; // Expected after stop.
        if (operation == Operation::queue && (status == bridge::Status::queue_full ||
                                             status == bridge::Status::invalid_input)) {
            ++rejections; return false; // Original false result; no legacy retry.
        }
        fault(operation, Fault::bridge_refused, status, raw);
        return false;
    }
    Diagnostic diagnostic() const {
        const auto encoded = first_fault.load(std::memory_order_acquire);
        return {Fault(encoded >> 56), Operation((encoded >> 48) & 255),
                std::uint8_t((encoded >> 40) & 255), std::uint32_t(encoded),
                hard_failures.load(), rejections.load()};
    }
    void report() {
        if (Frame::device_thread() || !first_fault.load(std::memory_order_acquire)) return;
        if (!reported.exchange(true, std::memory_order_acq_rel)) host->services->report_fault(diagnostic());
    }
    void report_join() {
        const auto stats = bridge.statistics();
        std::fprintf(stderr, "[NATIVE-PCM-REPORT] output_owner_joined=1 host_output_started=%u stream_fence_joined=%u frames=%llu signal_frames=%llu underrun_frames=%llu device_callback_attempts=%llu device_frame_requests=%llu device_callbacks_completed=%llu hard_failures=%llu queue_rejections=%llu stop_requests=%llu join_attempts_at_report=%llu self_join_refusals=%llu method_order=ensure_output,queue,configure,consumed,render,discard,drain,release,queued_samples,reset,shutdown method_attempts=",
            unsigned(host->ever_started.load()), unsigned(host->ever_started.load()),
            static_cast<unsigned long long>(stats.output_frames), static_cast<unsigned long long>(stats.signal_frames),
            static_cast<unsigned long long>(stats.underrun_frames), static_cast<unsigned long long>(device_callbacks.load()),
            static_cast<unsigned long long>(device_frames.load()), static_cast<unsigned long long>(device_completed.load()), static_cast<unsigned long long>(hard_failures.load()),
            static_cast<unsigned long long>(rejections.load()), static_cast<unsigned long long>(stop_requests.load()),
            static_cast<unsigned long long>(join_attempts.load()), static_cast<unsigned long long>(self_join_refusals.load()));
        for (unsigned i = 0; i < calls.size(); ++i)
            std::fprintf(stderr, "%s%llu", i ? "," : "", static_cast<unsigned long long>(calls[i].load()));
        std::fprintf(stderr, " method_completed=");
        for (unsigned i = 0; i < completed.size(); ++i)
            std::fprintf(stderr, "%s%llu", i ? "," : "", static_cast<unsigned long long>(completed[i].load()));
        std::fprintf(stderr, "\n");
    }
};

class DeviceRenderer final : public output::Renderer {
    std::weak_ptr<Backend> backend_;
public:
    explicit DeviceRenderer(const std::shared_ptr<Backend>& backend) : backend_(backend) {}
    void render(float* stereo, std::uint32_t frames) noexcept override {
        // No strong Backend cycle: callback takes a temporary lifetime lease.
        if (auto backend = backend_.lock()) backend->render(stereo, frames, true);
        else if (stereo) std::fill_n(stereo, std::size_t(frames) * 2, 0.0f);
    }
};

std::optional<ProfileProof> ProfileProof::from_observed_file1(
    std::uint32_t sid, std::uint32_t begin, std::uint32_t limit, std::uint32_t stride,
    std::uint32_t functions, std::uint32_t objects, std::uint32_t dispatcher) noexcept {
    if (sid != 0x90000200 || begin != 0x001e0000 || limit != 0x001eff00 ||
        stride != 0x20 || functions || objects || dispatcher) return std::nullopt;
    return ProfileProof{};
}
std::shared_ptr<HostServices> runtime_host_services() { return std::make_shared<RuntimeServices>(); }
Backend::Backend(std::shared_ptr<HostServices> services) : state_(std::make_unique<State>(std::move(services))) {}
Backend::~Backend() = default;
bool Backend::initialize_output(const std::shared_ptr<Backend>& self) {
    auto provider = output::NativeStreamProvider::create();
    if (!provider) return false;
    auto renderer = std::make_shared<DeviceRenderer>(self);
    state_->host->output = output::Owner::create(output::native_stream_callback_slot(), provider, renderer);
    return bool(state_->host->output);
}
BuildResult create_candidate(const ProfileProof&, std::shared_ptr<HostServices> services) noexcept {
    const char* enabled = std::getenv("REO_NATIVE_PCM");
    if (!enabled || std::strcmp(enabled, "1") != 0) return {BuildStatus::disabled, {}};
    if (!services) return {BuildStatus::invalid_services, {}};
    try {
        auto backend = std::shared_ptr<Backend>(new Backend(std::move(services)));
        if (!backend->initialize_output(backend)) return {BuildStatus::provider_reserved, {}};
        return {BuildStatus::ready, std::move(backend)};
    } catch (...) { return {BuildStatus::allocation_failed, {}}; }
}
static ps2_cri_audio::BackendInstallStatusV1 install_before_run(PS2Runtime& runtime,
    const std::shared_ptr<Backend>& backend) noexcept {
    if (!backend) return ps2_cri_audio::BackendInstallStatusV1::invalid_owner;
    return ps2_cri_audio::installBackendBeforeRunV1(runtime, backend->registration());
}
bool install(PS2Runtime& runtime, const ProfileProof& proof) noexcept {
    const char* enabled = std::getenv("REO_NATIVE_PCM");
    if (!enabled || std::strcmp(enabled, "1") != 0) return false;
    try {
        PS2Runtime::GuestExecutionScope scope(&runtime);
        if (!runtime_identity(runtime)) {
            std::fprintf(stderr, "[NATIVE-PCM-ERROR] runtime identity or 32MiB backing refused\n");
            return false;
        }
        const auto built = create_candidate(proof, runtime_host_services());
        if (built.status != BuildStatus::ready) {
            std::fprintf(stderr, "[NATIVE-PCM-ERROR] construction=%u\n", unsigned(built.status));
            return false;
        }
        const auto status = install_before_run(runtime, built.backend);
        if (status != ps2_cri_audio::BackendInstallStatusV1::installed) {
            std::fprintf(stderr, "[NATIVE-PCM-ERROR] installation=%u\n", unsigned(status));
            return false;
        }
        std::fprintf(stderr, "[NATIVE-PCM] candidate installed channels=%u voices=%u pcm_bytes=%llu metadata_bytes=%u\n",
            declared_raw_ids, declared_raw_ids + 1,
            static_cast<unsigned long long>(declared_pcm_storage_bytes), 4u * 1024 * 1024);
        return true;
    } catch (...) {
        std::fprintf(stderr, "[NATIVE-PCM-ERROR] host services allocation failed\n");
        return false;
    }
}
void Backend::request_stop() noexcept { state_->stop(); }
Diagnostic Backend::diagnostic() const noexcept { return state_->diagnostic(); }
bool Backend::join() noexcept {
    auto& s = *state_;
    ++s.join_attempts;
    request_stop();
    if (Frame::contains(&s)) { ++s.self_join_refusals; return false; }
    auto keep_alive = weak_from_this().lock();
    std::lock_guard control(s.lifecycle);
    if (s.joined) { s.report(); return true; }
    s.bridge.close_admission(); // Only outside stop/callback; may take short gate lock.
    auto current = s.admission.load(std::memory_order_acquire);
    while ((current & ~closed_bit) != 0) {
        s.admission.wait(current, std::memory_order_acquire);
        current = s.admission.load(std::memory_order_acquire);
    }
    const auto status = s.bridge.shutdown();
    if (status != bridge::Status::ok) {
        s.fault(Operation::shutdown, Fault::output_fence, status);
        s.report(); return false;
    }
    s.joined = true;
    if (s.calls[unsigned(Operation::shutdown)].load()) ++s.completed[unsigned(Operation::shutdown)];
    s.report();
    s.report_join();
    return true;
}

void Backend::ensure_output() noexcept {
    auto& s = *state_; State::Lease lease(s, Operation::ensure_output, false);
    if (lease.admitted) s.checked(Operation::ensure_output, s.bridge.ensureHostOutput());
    s.report();
}
bool Backend::queue(std::uint32_t raw, const std::uint8_t* bytes, std::uint32_t length,
                    std::uint64_t& end) noexcept {
    auto& s = *state_; State::Lease lease(s, Operation::queue, false);
    const bool ok = lease.admitted && s.key(Operation::queue, raw) &&
        s.checked(Operation::queue, s.bridge.queue(raw, bytes, length, end), raw);
    s.report(); return ok;
}
void Backend::configure(std::uint32_t raw, std::uint32_t left, std::uint32_t right,
    std::uint32_t channels, std::uint32_t frequency, std::uint32_t volume, bool playing) noexcept {
    auto& s = *state_; State::Lease lease(s, Operation::configure, false);
    if (lease.admitted && s.key(Operation::configure, raw) && s.key(Operation::configure, left) &&
        (std::min(channels, 2u) != 2 || s.key(Operation::configure, right)))
        s.checked(Operation::configure, s.bridge.configure(raw, left, right, channels, frequency, volume, playing), raw);
    s.report();
}
std::uint64_t Backend::consumed(std::uint32_t raw) noexcept {
    auto& s = *state_; State::Lease lease(s, Operation::consumed, false); std::uint64_t value = 0;
    if (lease.admitted && s.key(Operation::consumed, raw)) {
        const auto result = s.bridge.consumed(raw);
        if (s.checked(Operation::consumed, result.status, raw)) value = result.value;
    }
    s.report(); return value;
}
void Backend::render(float* stereo, unsigned frames, bool device) noexcept {
    auto& s = *state_; State::Lease lease(s, Operation::render, device);
    if (frames > declared_render_frames) {
        if (lease.admitted) s.fault(Operation::render, Fault::bridge_refused, bridge::Status::invalid_input);
        s.report(); return; // Unqualified request: no output read/write or unbounded loop.
    }
    if (stereo) std::fill_n(stereo, std::size_t(frames) * 2, 0.0f);
    if (device) { ++s.device_callbacks; s.device_frames.fetch_add(frames); }
    if (lease.admitted) {
        if (!s.checked(Operation::render, s.bridge.render(stereo, frames))) {
            if (stereo) std::fill_n(stereo, std::size_t(frames) * 2, 0.0f);
        } else if (device) ++s.device_completed;
    }
    s.report(); // Device marker defers logging to a producer/control call.
}
void Backend::discard(std::uint32_t raw) noexcept {
    auto& s = *state_; State::Lease lease(s, Operation::discard, false);
    if (lease.admitted && s.key(Operation::discard, raw)) s.checked(Operation::discard, s.bridge.discard(raw), raw);
    s.report();
}
void Backend::drain(std::uint32_t raw) noexcept {
    auto& s = *state_; State::Lease lease(s, Operation::drain, false);
    if (lease.admitted && s.key(Operation::drain, raw)) s.checked(Operation::drain, s.bridge.drain(raw), raw);
    s.report();
}
void Backend::release(std::uint32_t raw) noexcept {
    auto& s = *state_; State::Lease lease(s, Operation::release, false);
    if (lease.admitted && s.key(Operation::release, raw)) s.checked(Operation::release, s.bridge.release(raw), raw);
    s.report();
}
std::size_t Backend::queued_samples(std::uint32_t raw) noexcept {
    auto& s = *state_; State::Lease lease(s, Operation::queued_samples, false); std::size_t value = 0;
    if (lease.admitted && s.key(Operation::queued_samples, raw)) {
        const auto result = s.bridge.queuedSamples(raw);
        if (s.checked(Operation::queued_samples, result.status, raw)) value = result.value;
    }
    s.report(); return value;
}
void Backend::reset() noexcept {
    auto& s = *state_; State::Lease lease(s, Operation::reset, false);
    if (lease.admitted) s.checked(Operation::reset, s.bridge.reset());
    s.report();
}
ps2_cri_audio::BackendRegistrationV1 Backend::registration() noexcept {
    ps2_cri_audio::BackendApiV1 api;
    api.abi_version = ps2_cri_audio::backendAbiVersionV1;
    api.structure_bytes = sizeof(api);
    api.capabilities = ps2_cri_audio::backendRequiredCapabilitiesV1;
    api.ensure_host_output = [](void* p) noexcept { static_cast<Backend*>(p)->ensure_output(); };
    api.queue = [](void* p, std::uint32_t k, const std::uint8_t* b, std::uint32_t n, std::uint64_t& end) noexcept { return static_cast<Backend*>(p)->queue(k,b,n,end); };
    api.configure = [](void* p,std::uint32_t v,std::uint32_t l,std::uint32_t r,std::uint32_t n,std::uint32_t f,std::uint32_t volume,bool playing) noexcept { static_cast<Backend*>(p)->configure(v,l,r,n,f,volume,playing); };
    api.consumed = [](void* p,std::uint32_t k) noexcept { return static_cast<Backend*>(p)->consumed(k); };
    api.render = [](void* p,float* out,unsigned n) noexcept { static_cast<Backend*>(p)->render(out,n); };
    api.discard = [](void* p,std::uint32_t k) noexcept { static_cast<Backend*>(p)->discard(k); };
    api.drain = [](void* p,std::uint32_t v) noexcept { static_cast<Backend*>(p)->drain(v); };
    api.release = [](void* p,std::uint32_t v) noexcept { static_cast<Backend*>(p)->release(v); };
    api.queued_samples = [](void* p,std::uint32_t k) noexcept { return static_cast<Backend*>(p)->queued_samples(k); };
    api.reset = [](void* p) noexcept { static_cast<Backend*>(p)->reset(); };
    api.shutdown = [](void* p) noexcept {
        auto& backend = *static_cast<Backend*>(p);
        ++backend.state_->calls[unsigned(Operation::shutdown)];
        (void)backend.join();
    };
    api.request_stop = [](void* p) noexcept { static_cast<Backend*>(p)->request_stop(); };
    api.join = [](void* p) noexcept { return static_cast<Backend*>(p)->join(); };
    return {api, weak_from_this().lock()};
}
} // namespace reo_native_pcm
