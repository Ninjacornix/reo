#pragma once
#include "../pcm/pcm.hpp"
#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>

namespace reo::native::pcm_bridge {
namespace core = reo::native::pcm;
enum class Status {
    ok, invalid_input, queue_full, domain_capacity, metadata_capacity,
    unsupported_alias, unsupported_gain, core_refused, closed,
    output_fence_required, reentrant_shutdown
};
template<class T> struct Result { Status status{Status::ok}; T value{}; };

// A finite, deliberately narrower domain than the unrestricted legacy maps.
// Channel records include latent nonzero references and live until reset.
// These numbers are declarations, never a proof of whole-game reachability.
struct Domain {
    std::uint32_t version{1}, max_channels{64}, max_voices{64};
    std::uint32_t max_render_frames{16384};
    std::size_t channel_metadata_bytes{262144}, voice_metadata_bytes{262144};
};
struct PreRunState {
    Domain declared;
    bool before_first_operation{}, healthy{}, admission_open{};
    // This isolated component has no authority to certify provider/runtime or
    // unrestricted guest input domains. A bootstrap must not equate the three
    // flags above with permission to install it for an arbitrary game session.
    bool complete_runtime_installation_proved{false};
};

// No device, guest, process or global-clock types. A future provider owner must
// implement these hooks and prove its actual callback detach/unload fence.
// poll/settings/gain/route hooks must not reenter PCM (same source lock rule).
// ensure_output may start a callback synchronously: it runs outside PCM locks.
// All hooks are noexcept and Host is strongly retained through shutdown.
class Host {
  public:
    virtual ~Host() = default;
    virtual std::int64_t now_ns() noexcept = 0;
    virtual void poll_settings() noexcept = 0;
    virtual void ensure_output() noexcept = 0;
    virtual bool output_ready() noexcept = 0;
    virtual float stream_gain(std::uint32_t raw_voice) noexcept = 0;
    virtual void mix_banks(float* stereo, std::uint32_t frames) noexcept = 0;
    virtual float master_gain() noexcept = 0;
    virtual void reset_stream_routes() noexcept = 0;
    // true means the real provider has detached, stopped and fenced/unloaded
    // callbacks. A false result preserves PCM/banks for a later shutdown retry.
    virtual bool stop_join_output() noexcept = 0;
    virtual void reset_banks() noexcept = 0;
};
struct ChannelObservation { bool source_visible{}; core::ChannelInfo info; };
struct VoiceObservation { std::uint32_t left{}, right{}; core::VoiceInfo info; };

// Owns the one core and raw-ID maps. No second PCM queue or per-operation
// fallback. This is an isolated composition component, not an installed backend.
// Destroy only after shutdown returned ok and external users have relinquished
// their strong references. Destruction does not guess or call a device fence.
class Session final {
  public:
    explicit Session(std::shared_ptr<Host>, Domain = {});
    ~Session();
    Session(const Session&) = delete;
    Session& operator=(const Session&) = delete;
    [[nodiscard]] PreRunState pre_run_state() const noexcept;
    [[nodiscard]] Status ensureHostOutput() noexcept;
    [[nodiscard]] Status queue(std::uint32_t key, const std::uint8_t* bytes,
                               std::uint32_t length, std::uint64_t& end_byte) noexcept;
    [[nodiscard]] Status configure(std::uint32_t voice, std::uint32_t left,
                                   std::uint32_t right, std::uint32_t channels,
                                   std::uint32_t frequency, std::uint32_t volume,
                                   bool playing) noexcept;
    [[nodiscard]] Result<std::uint64_t> consumed(std::uint32_t key) noexcept;
    [[nodiscard]] Status render(float* stereo, std::uint32_t frames) noexcept;
    [[nodiscard]] Status discard(std::uint32_t key) noexcept;
    [[nodiscard]] Status drain(std::uint32_t voice) noexcept;
    [[nodiscard]] Status release(std::uint32_t voice) noexcept;
    [[nodiscard]] Result<std::size_t> queuedSamples(std::uint32_t key) noexcept;
    [[nodiscard]] Status reset() noexcept;
    [[nodiscard]] Status shutdown() noexcept;
    // Nonblocking admission signal only, not a provider fence or joined state.
    void close_admission() noexcept;

    // Read-only observations for isolated checks, not facade mutations. Unknown
    // IDs return zero/default records; copy_order preserves actual host STL order.
    [[nodiscard]] ChannelObservation inspect_channel(std::uint32_t) const noexcept;
    [[nodiscard]] VoiceObservation inspect_voice(std::uint32_t) const noexcept;
    [[nodiscard]] Status copy_samples(std::uint32_t, std::span<std::int16_t>) const noexcept;
    [[nodiscard]] Result<std::size_t> copy_order(std::span<std::uint32_t>) const noexcept;
    [[nodiscard]] std::size_t voice_bucket_count() const noexcept;
    [[nodiscard]] core::Statistics statistics() const noexcept;
    [[nodiscard]] core::Clock clock() const noexcept;
  private:
    struct State;
    std::unique_ptr<State> state_;
};
} // namespace reo::native::pcm_bridge
