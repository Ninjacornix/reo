#include "predictor_control.hpp"

namespace reo::native::adx_control {
namespace {
BufferPosition add_word_bytes(BufferPosition position, std::uint32_t bytes) noexcept {
    position.word_byte_offset += bytes;
    return position;
}
} // namespace
Phase phase(const PredictorState& state) noexcept {
    return state.phase;
}
std::uint32_t completed(const PredictorState& state) noexcept {
    return state.completed_units;
}
bool configure_mono(PredictorState& state, BufferPosition input, std::uint32_t units,
                    BufferPosition output) noexcept {
    if (state.phase != Phase::idle)
        return false;
    state.encoded_input = input;
    state.requested_units = units;
    state.left_output = output;
    state.mode = ChannelMode::mono;
    state.right_output = {};
    return true;
}
bool configure_stereo(PredictorState& state, BufferPosition input, std::uint32_t units,
                      BufferPosition left, BufferPosition right) noexcept {
    if (state.phase != Phase::idle)
        return false;
    state.right_output = right;
    state.encoded_input = input;
    state.requested_units = units;
    state.mode = ChannelMode::stereo;
    state.left_output = left;
    return true;
}
std::uint32_t request_if_idle(PredictorState& state) noexcept {
    if (state.phase == Phase::idle) {
        state.completed_units = 0;
        state.phase = Phase::requested;
    }
    return 1;
}
void cancel(PredictorState& state) noexcept {
    state.phase = Phase::idle;
    state.history = {};
}
void acknowledge_ready(PredictorState& state) noexcept {
    if (state.phase == Phase::ready)
        state.phase = Phase::idle;
}
std::uint32_t request_mono_window(PredictorState& state, const WindowState& window,
                                  std::uint32_t units) noexcept {
    const auto output = add_word_bytes(window.output_base, window.sample_offset << 1);
    (void)configure_mono(state, window.encoded_input, units, output);
    return request_if_idle(state);
}
std::uint32_t request_stereo_window(PredictorState& state, const WindowState& window,
                                    std::uint32_t units) noexcept {
    const auto left = add_word_bytes(window.output_base, window.sample_offset << 1);
    const auto right = add_word_bytes(left, window.channel_spacing_samples << 1);
    (void)configure_stereo(state, window.encoded_input, units << 1, left, right);
    return request_if_idle(state);
}
} // namespace reo::native::adx_control
