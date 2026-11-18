#pragma once

#include "../adx_control/predictor_service.hpp"
#include "../sjrb/sjrb.hpp"
#include <array>
#include <cstdint>
#include <memory>
#include <span>

namespace reo::native::adx_window {

inline constexpr std::int32_t encoded_capacity = 2048, encoded_extension = 36;
inline constexpr std::int32_t pcm_capacity = 16384, pcm_extension = 192;
inline constexpr std::int32_t pcm_spacing_samples = (pcm_capacity + pcm_extension) / 2;
inline constexpr std::int32_t max_window_samples = 256;

enum class Status {
    completed, inactive, backpressure, admission_closed, stale_request, busy,
    unsupported_geometry, unsupported_state, malformed_marker, output_extent,
    codec_refusal, no_memory,
    invariant_fault // Effects may have happened. Never restart an original call.
};
enum class OuterPhase : std::uint8_t { decoding = 2, ended = 3 };
enum class EnginePhase : std::uint32_t { idle, requested, processing, ready };
enum class Buffer : std::uint8_t { null, encoded, left_pcm, right_pcm };
struct Span {
    Buffer buffer{};
    std::int32_t offset{}, bytes{};
    friend bool operator==(const Span&, const Span&) = default;
};
struct OuterState {
    OuterPhase phase{OuterPhase::decoding};
    bool end_when_input_empty{};
    Span encoded;
    std::array<Span, 2> pcm{};
    std::int32_t decoded_samples{}, encoded_bytes{}, position{};
    std::int32_t max_request_samples{128}, sample_limit{-1};
    std::int32_t sample_progress{}, encoded_progress{};
    friend bool operator==(const OuterState&, const OuterState&) = default;
};
struct InnerState {
    EnginePhase phase{EnginePhase::idle};
    adx_control::BufferPosition encoded_input;
    std::int32_t input_blocks{};
    std::int32_t sample_offset{}, available_samples{}, remaining_samples{};
    std::int32_t decoded_total{}, local_output_offset{};
    std::int32_t produced_samples{}, consumed_bytes{};
    friend bool operator==(const InnerState&, const InnerState&) = default;
};
struct Reservation {
    std::int32_t offset{}, available{}, remaining{};
    adx_control::BufferPosition backing{adx_control::SpanToken{2}, 0};
    friend bool operator==(const Reservation&, const Reservation&) = default;
};
// Original124810 scalar contract only: does not acquire any ring reservation.
[[nodiscard]] Reservation constructor_default_reservation(const InnerState&, std::int32_t total_samples) noexcept;

struct Config {
    std::uint32_t channels{1};
    bool downmix{};
    std::int32_t total_samples{1000}, max_request_samples{128}, sample_limit{-1};
    bool end_when_input_empty{};
    std::array<std::int16_t, 4> history{1234,-5678,-9012,3456};
    std::array<std::int16_t, 2> coefficients{7192,-3172};
    std::uint16_t key{23456};
    std::int16_t multiplier{7}, addend{-9};
    // Empty-ring bootstrap/initial accepted PCM, not a guest checkpoint import.
    std::int32_t initial_encoded_cursor{};
    std::array<std::int32_t, 2> initial_pcm_cursor{}, initial_pcm_bytes{};
};

class PcmView final {
public:
    [[nodiscard]] std::int32_t offset() const noexcept;
    [[nodiscard]] std::int32_t bytes() const noexcept;
    [[nodiscard]] sjrb::Status read(std::span<std::uint8_t> output, std::size_t relative = 0) const noexcept;
private:
    sjrb::Chunk chunk_; // Strong actual storage owner; no mutable token escapes.
    friend class Window;
};
struct Hooks {
    void* context{};
    void (*guard)(void*, std::uint32_t ring, bool entering) noexcept {};
    void (*error)(void*, std::uint32_t ring, std::int32_t code) noexcept {};
    void (*pcm)(void*, std::uint32_t channel, const PcmView&) noexcept {};
    void (*limit)(void*) noexcept {};
};
struct Snapshot {
    OuterState outer;
    InnerState inner;
    adx_control::PredictorState predictor;
    std::uint32_t odd_result_flag{};
    std::array<sjrb::Snapshot, 3> rings{};
    bool admission_closed{}, invariant_fault{};
    friend bool operator==(const Snapshot&, const Snapshot&) = default;
};

struct Epoch;
class Window;
class Request final {
public:
    Request() = default;
private:
    std::shared_ptr<const Epoch> owner_;
    std::uint64_t generation_{};
    friend class Window;
};

// Exclusive synchronous owner. Callers serialize all access, including views.
// Readonly callbacks can observe; public mutating reentry refuses. Keep Window
// and callback context alive until every enclosing call returns. No OS worker,
// lock-free queue, raw guest data or simulated join exists in this component.
class Window final {
public:
    explicit Window(Config config, Hooks hooks = {}, std::uint8_t initial_byte = 0xA5);
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(Window&&) = delete;
    ~Window();
    [[nodiscard]] static bool admits(const Config&) noexcept;
    [[nodiscard]] Request request() const noexcept;
    // Allocating real codec staging finishes before the first guard/Get. Refusal
    // then has no original ring/state/callback effects. After borrowing, an
    // unexpected fault closes admission and retains its ledger/storage.
    [[nodiscard]] Status service(const Request&) noexcept;
    [[nodiscard]] Status feed_encoded(std::span<const std::uint8_t> bytes) noexcept;
    // Explicit selected-channel credit, not stereo atomicity or DAC position.
    [[nodiscard]] Status consume_pcm(std::uint32_t channel, std::int32_t requested,
                                     std::int32_t& consumed) noexcept;
    // Closes future admission; accepted PCM may still drain. Not original125248,
    // a reset, cancellation interrupt or worker/device join. No restart API.
    [[nodiscard]] Status stop() noexcept;
    [[nodiscard]] Snapshot snapshot() const noexcept;
    [[nodiscard]] Status read_encoded_backing(std::span<std::uint8_t>) const noexcept;
    [[nodiscard]] Status read_pcm_backing(std::uint32_t channel, std::span<std::uint8_t>) const noexcept;
    [[nodiscard]] const Config& config() const noexcept;
private:
    struct RingContext { Window* owner{}; std::uint32_t ring{}; };
    struct Prepared;
    class PreparedDecoder;
    class BusyScope;
    Config config_;
    Hooks hooks_;
    std::shared_ptr<Epoch> epoch_;
    std::array<std::unique_ptr<sjrb::Ring>, 3> rings_;
    std::array<RingContext, 3> ring_contexts_{};
    OuterState outer_;
    InnerState inner_;
    adx_control::PredictorState predictor_;
    std::uint32_t odd_{};
    bool busy_{}, fault_{};
    int get_target_{-1}; // A live Get writes its caller descriptor before leave.
    sjrb::Chunk input_;
    std::array<sjrb::Chunk, 2> output_{};
    bool input_borrowed_{};
    std::array<bool, 2> output_borrowed_{};

    static void enter(void*) noexcept;
    static void leave(void*) noexcept;
    static void error(void*, std::int32_t) noexcept;
    [[nodiscard]] bool completed(sjrb::Status) noexcept;
    [[nodiscard]] Status fault() noexcept;
    [[nodiscard]] Status prepare(Prepared&) noexcept;
    [[nodiscard]] Status execute(Prepared&) noexcept;
    [[nodiscard]] bool write_samples(std::uint32_t, std::int32_t, std::span<const std::int16_t>) noexcept;
    [[nodiscard]] bool wrap(std::uint32_t, std::int32_t) noexcept;
    [[nodiscard]] bool put_input_prefix(std::int32_t, bool in_place) noexcept;
    [[nodiscard]] bool get_input() noexcept;
    [[nodiscard]] bool bootstrap_advance(std::uint32_t, std::int32_t) noexcept;
    [[nodiscard]] bool bootstrap_occupy(std::uint32_t, std::int32_t) noexcept;
};

} // namespace reo::native::adx_window
