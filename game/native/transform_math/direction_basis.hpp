#pragma once
#include "transform_math.hpp"
namespace reo::native::transform_math {
// Complete191820 ordered cross/normalization construction. Degenerate zero
// vectors preserve the original zero axes; no arbitrary fallback axis is made.
Matrix direction_basis(Vector forward,Vector auxiliary);
void direction_basis(Matrix&,Vector forward,Vector auxiliary);
// Complete1911D0 and191220 orthonormal-axis transpose/translation operation.
// This is the source operation, not a general matrix inverse or determinant test.
Matrix inverse_orthonormal(Matrix);
}
