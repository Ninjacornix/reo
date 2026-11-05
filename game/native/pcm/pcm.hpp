#pragma once
#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>
#include <span>

namespace reo::native::pcm {
struct SessionIdentity;
class Session;
template <class Tag> class Handle final {
  public:
    Handle() = default;

  private:
    friend class Session;
    std::weak_ptr<const SessionIdentity> owner_;
    std::uint32_t slot_{std::numeric_limits<std::uint32_t>::max()};
    std::uint64_t generation_{};
};
struct ChannelTag;
struct VoiceTag;
using Channel = Handle<ChannelTag>;
using Voice = Handle<VoiceTag>;
enum class Status {
    ok,
    closed,
    invalid_handle,
    invalid_input,
    capacity,
    channel_in_use,
    unsupported_alias,
    unsupported_mix,
    counter_limit,
    clock_limit
};
template <class T> struct Result {
    Status status{Status::invalid_handle};
    T value{};
};
struct Config {
    std::uint32_t max_channels{16}, max_voices{16};
    std::size_t channel_samples{96000}, max_enqueue_bytes{0x4000};
    std::uint32_t max_render_frames{16384};
    std::uint64_t max_generation{std::numeric_limits<std::uint64_t>::max()};
    std::uint64_t max_counter{std::numeric_limits<std::uint64_t>::max()};
};
enum class Channels : std::uint32_t { disabled = 0, mono = 1, stereo = 2 };
struct VoiceConfig {
    Channel left, right;
    Channels channels{Channels::mono};
    std::uint32_t frequency{48000}, volume{256};
    bool playing{};
};
struct ChannelInfo {
    std::size_t samples{};
    std::uint64_t queued_bytes{}, consumed_bytes{};
};
struct VoiceInfo {
    Channels channels{Channels::disabled};
    std::uint32_t frequency{48000}, volume{256};
    bool playing{}, draining{};
    double phase{};
    std::uint64_t late_samples{}, skipped_samples{};
    float gain{1};
};
struct Statistics {
    std::uint64_t output_frames{}, signal_frames{}, underrun_frames{};
};
struct Clock {
    bool frame_clock{};
    std::int64_t last_tick_ns{};
};
enum class StopAction { drain, cut };
struct StopResult {
    Status status{Status::invalid_handle};
    StopAction action{StopAction::drain};
};

// Owns all storage and state. Synchronous, internally serialized, no worker,
// device/global clock/callback/guest types. All capacities allocate at creation;
// operations retain no caller buffer. Stop producers/device callbacks and join
// them before destruction; shutdown alone cannot make an external callback safe.
class Session final {
  public:
    explicit Session(Config config = {}, std::int64_t initial_clock_ns = 0);
    ~Session();
    Session(const Session&) = delete;
    Session& operator=(const Session&) = delete;
    Session(Session&&) = delete;
    Session& operator=(Session&&) = delete;
    [[nodiscard]] Result<Channel> create_channel() noexcept;
    [[nodiscard]] Result<Voice> create_voice() noexcept;
    // Complete permutation of current voice records, including paused/disabled
    // voices. Creating/releasing a voice, cut-stop or reset invalidates it.
    // Allows larger mixes without assuming an implicit float summation order.
    [[nodiscard]] Status set_mix_order(std::span<const Voice>) noexcept;
    [[nodiscard]] Status close_channel(const Channel&) noexcept;
    [[nodiscard]] Status release(const Voice&) noexcept;
    [[nodiscard]] Status configure(const Voice&, const VoiceConfig&, std::int64_t now_ns) noexcept;
    // Gain is supplied by the host at a render boundary; finite [0,8] admitted.
    [[nodiscard]] Status gain(const Voice&, float value) noexcept;
    // Valid requests advance the current headless clock before queue-cap refusal,
    // matching the reference. Other admission failures occur before changes.
    [[nodiscard]] Result<std::uint64_t> enqueue(const Channel&, std::span<const std::byte>,
                                                std::int64_t now_ns) noexcept;
    [[nodiscard]] Result<std::uint64_t> consumed(const Channel&, std::int64_t now_ns) noexcept;
    [[nodiscard]] Status discard(const Channel&) noexcept;
    [[nodiscard]] Status drain(const Voice&) noexcept;
    // Implements current short-tail policy; raw_rate defaults only if zero.
    // A cut releases the voice handle while preserving its channels.
    [[nodiscard]] StopResult stop(const Voice&, bool has_unreturned,
                                  std::uint32_t raw_rate) noexcept;
    // Without an explicit valid mix order, at most two playing non-disabled
    // voices for positive frame requests. Larger implicit mixes are refused.
    [[nodiscard]] Status render(std::span<float> stereo) noexcept;
    [[nodiscard]] Status advance_frames(std::uint32_t frames) noexcept;
    [[nodiscard]] Status advance_headless(std::int64_t now_ns) noexcept;
    [[nodiscard]] Status select_frame_clock() noexcept;
    [[nodiscard]] Result<ChannelInfo> inspect(const Channel&) const noexcept;
    [[nodiscard]] Result<VoiceInfo> inspect(const Voice&) const noexcept;
    [[nodiscard]] Status copy_samples(const Channel&, std::span<std::int16_t>) const noexcept;
    [[nodiscard]] Statistics statistics() const noexcept;
    [[nodiscard]] Clock clock() const noexcept;
    [[nodiscard]] Status reset(std::int64_t now_ns) noexcept;
    void shutdown(std::int64_t now_ns) noexcept;

  private:
    struct State;
    std::unique_ptr<State> state_;
};

// Separate non-host-PCM fallback calculation; never automatically applied by
// Session. Caller owns its raw-rate/active-ring policy and supplied timestamps.
struct PacedState {
    std::uint64_t last_ns{};
};
[[nodiscard]] std::uint32_t paced_budget(PacedState&, std::uint32_t rate, std::uint32_t channels,
                                         bool left_ring, bool right_ring,
                                         std::uint64_t now_ns) noexcept;
} // namespace reo::native::pcm
