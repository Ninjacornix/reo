#pragma once
#include "../transform_math/transform_math.hpp"

namespace reo::native::gameplay_world::surface_math {
using transform_math::Vector;
using transform_math::Matrix;
// The direct 6657B0 turn conversion has different rounding from radians().
Vector rotate_probe(Vector,std::uint16_t turn);
float turn_cosine(std::uint16_t turn);
Vector cross(Vector,Vector);
float dot(Vector,Vector);
Matrix normal_basis(Vector normal,Vector heading);
Matrix blend_basis(const Matrix&,const Matrix&,float old_weight,float new_weight);
} // namespace reo::native::gameplay_world::surface_math
