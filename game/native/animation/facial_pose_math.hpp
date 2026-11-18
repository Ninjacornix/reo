#pragma once
#include "../transform_math/transform_math.hpp"
#include <array>
namespace reo::native::animation {
using FacialWeights=std::array<float,6>;
using FacialMatrices=std::array<transform_math::Matrix,6>;
// Complete1A5050: normalize two directions, reconstruct the third basis and
// preserve the supplied translation. Exact zero vectors remain zero.
transform_math::Matrix facial_basis(transform_math::Vector first,
    transform_math::Vector second,transform_math::Vector translation);
// Complete67C990 over the selected node's six source matrices. W lanes and
// the third source direction are not consumed; weights are not normalized.
transform_math::Matrix blend_facial_pose(const FacialMatrices&,const FacialWeights&);
} // namespace reo::native::animation
