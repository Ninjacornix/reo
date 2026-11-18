#pragma once
#include "Kernel/Syscalls/Helpers/CriAudioBackend.h"
#include <cstdint>
#include <memory>
#include <optional>

namespace reo_native_pcm {

// The bootstrap must pass an ACTUALLY OBSERVED configured File #1 layout.
// Equality validates this narrow profile, not all reachable game behavior or
// stability of the layout after the snapshot. This type has no default proof.
class ProfileProof final {
public:
    static std::optional<ProfileProof> from_observed_file1(
        std::uint32_t rpc_sid, std::uint32_t begin, std::uint32_t limit,
        std::uint32_t stride, std::uint32_t function_table,
        std::uint32_t object_table, std::uint32_t dispatcher) noexcept;
private:
    ProfileProof() = default;
};
inline constexpr std::uint32_t declared_raw_ids = 2040;
inline constexpr std::uint64_t declared_pcm_storage_bytes =
    std::uint64_t{declared_raw_ids} * 96000 * sizeof(std::int16_t);
inline constexpr std::uint32_t declared_render_frames = 16384;

enum class Operation : std::uint8_t {
    ensure_output, queue, configure, consumed, render, discard, drain, release,
    queued_samples, reset, shutdown
};
enum class Fault : std::uint8_t { none, outside_profile, bridge_refused, output_fence };
struct Diagnostic {
    Fault fault{};
    Operation operation{};
    std::uint8_t bridge_status{};
    std::uint32_t raw{};
    std::uint64_t hard_failures{}, queue_rejections{};
};

// Strongly retained hooks. No hook may reenter PCM or perform guest/RPC work.
// poll/settings/gains/routes follow the existing host mixer contract; mix_banks
// runs after PCM data locks are released. report_fault is never called from the
// device renderer and is invoked outside the bridge's data locks.
class HostServices {
public:
    virtual ~HostServices() = default;
    virtual std::int64_t now_ns() noexcept = 0;
    virtual void poll_settings() noexcept = 0;
    virtual float stream_gain(std::uint32_t raw_voice) noexcept = 0;
    virtual void mix_banks(float*, std::uint32_t frames) noexcept = 0;
    virtual float master_gain() noexcept = 0;
    virtual void reset_stream_routes() noexcept = 0;
    virtual void reset_banks() noexcept = 0;
    virtual void report_fault(const Diagnostic&) noexcept = 0;
};
std::shared_ptr<HostServices> runtime_host_services();

class Backend;
enum class BuildStatus { ready, disabled, invalid_services, allocation_failed, provider_reserved };
struct BuildResult { BuildStatus status; std::shared_ptr<Backend> backend; };

// Construction only: no provider stream/callback is opened and no facade or
// runtime worker is installed. Exact environment value REO_NATIVE_PCM=1 is
// required. The domain remains an explicit candidate restriction.
BuildResult create_candidate(const ProfileProof&, std::shared_ptr<HostServices>) noexcept;
// Default-off pre-run bootstrap entry. Checks the environment again, constructs
// runtime host hooks and installs the complete table; no per-method fallback.
bool install(PS2Runtime&, const ProfileProof&) noexcept;

class DeviceRenderer;
class Backend final : public std::enable_shared_from_this<Backend> {
public:
    ~Backend();
    ps2_cri_audio::BackendRegistrationV1 registration() noexcept;
    void request_stop() noexcept;
    bool join() noexcept;
    Diagnostic diagnostic() const noexcept;
private:
    friend BuildResult create_candidate(const ProfileProof&, std::shared_ptr<HostServices>) noexcept;
    friend class DeviceRenderer;
    struct State;
    explicit Backend(std::shared_ptr<HostServices>);
    bool initialize_output(const std::shared_ptr<Backend>&);
    void ensure_output() noexcept;
    bool queue(std::uint32_t, const std::uint8_t*, std::uint32_t, std::uint64_t&) noexcept;
    void configure(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,
                   std::uint32_t,std::uint32_t,bool) noexcept;
    std::uint64_t consumed(std::uint32_t) noexcept;
    void render(float*, unsigned, bool device = false) noexcept;
    void discard(std::uint32_t) noexcept;
    void drain(std::uint32_t) noexcept;
    void release(std::uint32_t) noexcept;
    std::size_t queued_samples(std::uint32_t) noexcept;
    void reset() noexcept;
    std::unique_ptr<State> state_;
};
} // namespace reo_native_pcm
