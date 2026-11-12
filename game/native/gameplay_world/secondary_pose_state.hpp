#pragma once
#include "../transform_math/transform_math.hpp"
#include <array>
namespace reo::native::gameplay_world {
// The admitted61AAA0 profiles have one chain of two joints.61A620 zeros
// their XYZ history explicitly; the other bytes in each old record are unused.
struct SecondaryPoseHistory {std::array<transform_math::Vector,2> displacement{};};
}
