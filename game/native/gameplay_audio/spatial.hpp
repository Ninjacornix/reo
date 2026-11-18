#pragma once
#include "routing.hpp"
#include "../transform_math/transform_math.hpp"

namespace reo::native::gameplay_audio {
using Vector = transform_math::Vector;
using Matrix = transform_math::Matrix;
using Attenuation = std::array<std::uint32_t, 17>;
struct SpatialContext {
    Vector listener;
    // Already composed canonical world-to-logical-640-screen matrix. This is
    // an explicit camera input, never temporary PS2 render state.
    Matrix world_to_screen;
};
struct SpatialResult {
    Status status{Status::skipped};
    std::uint32_t gain{}, pan{63};
};
const Attenuation* attenuation(unsigned selector) noexcept;
SpatialResult locate(Vector, const SpatialContext&, const Attenuation&) noexcept;
Result positional(const Descriptors&, bool requested, std::uint8_t phase, Request, Vector,
                  const SpatialContext&, unsigned attenuation_selector, gameplay_session::Random&,
                  CommandSink&) noexcept;
} // namespace reo::native::gameplay_audio
