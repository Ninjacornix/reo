#pragma once

#include "predictor_control.hpp"

namespace reo::native::adx_control {

enum class DecodeRoute { mono, stereo_selector };

// Scalar arguments are captured before the synchronous decoder is invoked.
// Storage tokens carry no lifetime proof. The selected decoder/owner must
// validate and retain actual encoded/output storage before calling service.
struct DecodeRequest {
    DecodeRoute route{DecodeRoute::mono};
    BufferPosition encoded_input;
    std::int32_t requested_units{};
    BufferPosition left_output, right_output;
    std::array<std::int16_t, 2> coefficients{};
    std::int16_t key_multiplier{}, key_addend{};
    friend bool operator==(const DecodeRequest&, const DecodeRequest&) = default;
};

class Decoder {
  public:
    virtual ~Decoder() = default;
    // Live history/key are in state. Explicit synchronous reentry may mutate
    // any state field; service still publishes completed/ready after return.
    // This admitted callback has no refusal/exception path. Resolve decoder,
    // storage and allocation admission before service can publish processing.
    virtual std::int32_t decode(const DecodeRequest&, PredictorState&) noexcept = 0;
};

// These describe the native call's admission/work, not the original void
// service's return register or a decoder success/error interpretation.
enum class ServiceDisposition { inactive, decoded, decoder_unavailable };

// requested -> processing -> ready; processing -> ready; other phases unchanged.
// The stereo selector's actual downmix choice remains the decoder owner's job.
// A positive odd stereo result sets odd_result_flag=1; other results preserve it.
[[nodiscard]] ServiceDisposition service(PredictorState&, std::uint32_t& odd_result_flag,
                                          Decoder*) noexcept;

} // namespace reo::native::adx_control
