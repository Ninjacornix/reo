#pragma once
#include "model_math.hpp"
namespace reo::native::animation::constraint_math {
//191D80-compatible finite XYZ normalization, including its zero-vector policy.
Vector normalize(Vector);
Vector add(Vector,Vector);
Vector subtract(Vector,Vector);
float squared_length(Vector);
float square_root(float);
Matrix product(const Matrix& left,const Matrix& right);
Matrix rotation_x(float radians);
Matrix basis_xy(Matrix initial,Vector first,Vector auxiliary);
Matrix basis_xz(Matrix initial,Vector first,Vector auxiliary);
Matrix inverse_scaled(const Matrix&);
} // namespace reo::native::animation::constraint_math
