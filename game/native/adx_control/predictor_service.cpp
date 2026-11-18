#include "predictor_service.hpp"

#include <bit>

namespace reo::native::adx_control {

ServiceDisposition service(PredictorState& state, std::uint32_t& odd_result_flag,
                             Decoder* decoder) noexcept {
    if (state.phase != Phase::requested && state.phase != Phase::processing)
        return ServiceDisposition::inactive;
    if (!decoder)
        return ServiceDisposition::decoder_unavailable;
    if (state.phase == Phase::requested)
        state.phase = Phase::processing;

    const auto route = state.mode == ChannelMode::mono ? DecodeRoute::mono
                                                      : DecodeRoute::stereo_selector;
    const DecodeRequest request{route, state.encoded_input,
        std::bit_cast<std::int32_t>(state.requested_units), state.left_output,
        route == DecodeRoute::mono ? BufferPosition{} : state.right_output,
        state.coefficients, std::bit_cast<std::int16_t>(state.key.multiplier),
        std::bit_cast<std::int16_t>(state.key.addend)};
    const auto result = decoder->decode(request, state);
    state.completed_units = std::bit_cast<std::uint32_t>(result);
    if (route == DecodeRoute::stereo_selector && result > 0 &&
        (static_cast<std::uint32_t>(result) & 1u))
        odd_result_flag = 1;
    state.phase = Phase::ready;
    return ServiceDisposition::decoded;
}

} // namespace reo::native::adx_control
