#pragma once
#include <cstdint>
namespace reo::native::transform_math {
// Finite value math with the owned arctangent polynomial and quadrant rules.
// No guest context, FP-control mutation or physical exceptional parity claim.
float arctangent(float);
float quadrant_angle(float y,float x);
// Original game turn units; a zero X delta uses the admitted small positive
// bias before heading selection. Y height is deliberately not an input.
std::uint16_t direction_turn(float delta_x,float delta_z);
// Position-to-position heading uses the original Z bias at 370140.
std::uint16_t position_direction_turn(float delta_x, float delta_z);
}
