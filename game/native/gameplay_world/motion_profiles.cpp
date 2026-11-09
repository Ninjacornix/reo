#include "motion_profiles.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
#include "motion_body_profile.inc"
}
gameplay_collision::actors::ShapeDefinition File1MotionProfiles::body(std::uint8_t model,
                                                                      std::uint8_t offset) const {
    if (model >= 8 || offset != 0)
        throw std::out_of_range("Native File1 motion body profile unavailable");
    const auto& raw = body_bytes[model];
    return gameplay_collision::actors::import_shape(std::as_bytes(std::span(raw)));
}
MotionShapeProfile File1MotionProfiles::shape(std::uint8_t model, std::uint8_t selector) const {
    if (model >= 8 || selector >= 9)
        throw std::out_of_range("Native File1 motion local-shape profile unavailable");
    const auto& bits = shape_words[model >= 5 ? 1 : 0][selector];
    return {{{std::bit_cast<float>(bits[0]), std::bit_cast<float>(bits[1]),
              std::bit_cast<float>(bits[2])},
             std::bit_cast<float>(bits[3])},
            std::uint8_t(bits[4])};
}
} // namespace reo::native::gameplay_world
