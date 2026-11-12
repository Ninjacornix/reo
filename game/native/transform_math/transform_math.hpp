#pragma once
#include <array>
#include <cstdint>

namespace reo::native::transform_math {
struct Vector {float x{},y{},z{};};
// Four owned columns. Preserved fourth components are real values rather than
// implicitly discarded scratch lanes; world consumers admit affine bases.
using Matrix=std::array<std::array<float,4>,4>;
using Angles=std::array<std::uint16_t,3>;
struct SinCos {float sine{},cosine{};};
Matrix identity()noexcept;
float radians(std::uint16_t turn);
// Finite radians with nonwrapping signed16 winding reduction and round-to-nearest
// FP32 arithmetic. Uses the
// admitted original polynomial and reduction, never host sin/cos functions.
SinCos sin_cos(float);
// Reset only axis XYZ, preserving W and the fourth column, then apply X,Y,Z.
void reset_euler_axes(Matrix&,Angles);
// Resource1904A0 order: X,Z,Y. Preserve W and the fourth column.
void reset_euler_axes_xzy(Matrix&,Angles);
// Compose those same rotations onto existing axis XYZ; preserve W/column4.
void compose_euler_axes(Matrix&,Angles);
//190A10 consumes caller-computed radians without191F80 turn conversion/wrap.
void compose_euler_radians(Matrix&,Vector radians);
Matrix scale(Vector);
// Ordered four-term column product, left*destination; aliasing is supported.
void concatenate_left(Matrix& destination,const Matrix& left);
Vector direction(const Matrix&,Vector);
// Admission failures throw before publishing a private computed matrix/result.
// This profile matches the current finite FP32/SSE recompiler surroundings;
// it does not claim physical PS2 exceptional arithmetic equivalence.
void require_profile();
} // namespace reo::native::transform_math
