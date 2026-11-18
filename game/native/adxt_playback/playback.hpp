#pragma once
#include "../adx_pcm_store/v2/pcm_store.hpp"
#include <array>
#include <cstdint>
#include <optional>

namespace reo::native::adxt_playback {
enum class Status { completed, pending, busy, invalid_input, fault };
enum class Phase : std::uint8_t { buffering=2, playing=3, draining=4, ended=5 };
struct State {
    Phase phase{Phase::buffering};
    std::uint32_t estimate_base{}, tick_base{}, padding_samples{};
    std::int32_t request_samples{128};
    bool inhibit{}, paused{}, started{}, stopping_transfer{}, fault{};
};
struct Decoder {
    bool ended{}; std::uint32_t channels{1};
    std::int32_t samples_per_block{32}; std::uint32_t tick{};
};
struct Padding { Status status{Status::fault}; std::uint32_t samples{}; };

// All calls on a player and its PCM/output ports require one control owner.
// Output observations are in samples per channel, never bytes or frames.
// An adapter must synchronize these operations with its real output consumer.
class Output {
public:
    virtual ~Output() = default;
    virtual Status queued_samples(std::uint32_t&) noexcept = 0;
    virtual Status free_samples(std::uint32_t&) noexcept = 0;
    virtual Status play(bool) noexcept = 0;
    // completed means the actual transfer owner has stopped and joined. A
    // request/flag is insufficient. pending is retried without more padding.
    virtual Status stop_transfer() noexcept = 0;
    virtual Status through() noexcept = 0;
};
class Pcm {
public:
    virtual ~Pcm() = default;
    virtual Status data_bytes(std::uint32_t channel, std::uint32_t&) noexcept = 0;
    virtual Padding silence(std::uint32_t maximum_samples) noexcept = 0;
};

// Owns the complete buffering/playing/draining control cut (1343B8..1347F8).
// Decoder/source ownership, copy/consumption credits and device lifetime remain
// with their ports. ended is a queue/control result, not a device fence.
class Playback final {
public:
    explicit Playback(State = {});
    [[nodiscard]] const State& state() const noexcept { return state_; }
    [[nodiscard]] Status service(Decoder, Pcm&, Output&) noexcept;
    // Prepared flags only; the full ADXT pause/clock API is a separate owner.
    [[nodiscard]] Status set_paused_flag(bool value) noexcept;
    [[nodiscard]] Status set_start_inhibit(bool value) noexcept;
private:
    State state_; bool busy_{};
    [[nodiscard]] Status fail() noexcept;
    [[nodiscard]] Status finish(Output&) noexcept;
};

// Concrete bridge to the unchanged phased PCM owner. It borrows all available
// free credit, publishes a bounded common zero prefix, then restores the rest.
// This changes private free-borrow traffic counts compared with the original
// capped Get; byte contents, queue positions and published credit are compared
// explicitly. A failed transaction retains its real token until destruction.
class StorePcm final : public Pcm {
public:
    StorePcm(adx_pcm::v2::Store&, std::uint32_t channels);
    Status data_bytes(std::uint32_t, std::uint32_t&) noexcept override;
    Padding silence(std::uint32_t) noexcept override;
private:
    adx_pcm::v2::Store& store_; std::uint32_t channels_{};
    std::array<std::int16_t, adx_pcm::v2::capacity/2> zero_{};
    std::optional<adx_pcm::v2::WriteLease> held_;
    bool fault_{};
};
} // namespace reo::native::adxt_playback
