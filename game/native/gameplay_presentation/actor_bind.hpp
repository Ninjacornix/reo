#pragma once
#include "../transform_math/transform_math.hpp"
#include <cstddef>
#include <span>
#include <vector>
namespace reo::native::gameplay_presentation {
// Immutable inverse bind matrices from the actual AHI quaternion hierarchy.
// These are independent of the actor's live, canonical animated matrices.
std::vector<transform_math::Matrix> actor_inverse_bind(std::span<const std::byte> nbd);
}
