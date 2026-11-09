#pragma once
#include "model.hpp"
namespace reo::native::animation {
Matrix unscaled_pose(const Parameters&);
Matrix scaled_pose(const Parameters&);
Matrix hierarchical_pose(const NodePose&,const Matrix& parent,Vector parent_scale);
} // namespace reo::native::animation
