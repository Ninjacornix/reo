#pragma once

#include <array>
#include <cstdint>

namespace reo::native::adx_control {

// Tokens identify borrowed native storage; they contain no pointer or lease.
// The owning media layer must validate and retain storage before any use.
struct SpanToken {
    std::uint64_t value{};
    friend bool operator==(const SpanToken&, const SpanToken&) = default;
};
struct BufferPosition {
    SpanToken span;
    // Deliberate modulo-2^32 byte coordinate, never host pointer arithmetic.
    std::uint32_t word_byte_offset{};
    friend bool operator==(const BufferPosition&, const BufferPosition&) = default;
};
enum class Phase : std::uint32_t { idle = 0, requested = 1, processing = 2, ready = 3 };
enum class ChannelMode : std::uint32_t { unset = 0, mono = 1, stereo = 2 };
struct KeyState {
    std::uint16_t value{}, multiplier{}, addend{};
    friend bool operator==(const KeyState&, const KeyState&) = default;
};
struct PredictorState {
    Phase phase{Phase::idle};
    std::uint32_t completed_units{};
    ChannelMode mode{ChannelMode::unset};
    BufferPosition encoded_input;
    std::uint32_t requested_units{};
    BufferPosition left_output, right_output;
    std::array<std::int16_t, 4> history{};
    std::array<std::int16_t, 2> coefficients{};
    KeyState key;
    friend bool operator==(const PredictorState&, const PredictorState&) = default;
};
struct WindowState {
    BufferPosition encoded_input, output_base;
    std::uint32_t sample_offset{}, channel_spacing_samples{};
};

[[nodiscard]] Phase phase(const PredictorState&) noexcept;
[[nodiscard]] std::uint32_t completed(const PredictorState&) noexcept;
[[nodiscard]] bool configure_mono(PredictorState&, BufferPosition input, std::uint32_t units,
                                  BufferPosition output) noexcept;
[[nodiscard]] bool configure_stereo(PredictorState&, BufferPosition input, std::uint32_t units,
                                    BufferPosition left, BufferPosition right) noexcept;
// Returns the original word result 1 on BOTH idle and busy paths. It does not
// report acceptance, queue work or execute a decoder.
[[nodiscard]] std::uint32_t request_if_idle(PredictorState&) noexcept;
// Reset phase/history only; no completion, cancellation acknowledgement or join.
void cancel(PredictorState&) noexcept;
void acknowledge_ready(PredictorState&) noexcept;
// Counts/offset shifts intentionally wrap as unsigned words. These wrappers
// ignore configuration refusal then request, preserving the original behavior.
[[nodiscard]] std::uint32_t request_mono_window(PredictorState&, const WindowState&,
                                                std::uint32_t requested_units) noexcept;
[[nodiscard]] std::uint32_t request_stereo_window(PredictorState&, const WindowState&,
                                                  std::uint32_t requested_units) noexcept;
} // namespace reo::native::adx_control
