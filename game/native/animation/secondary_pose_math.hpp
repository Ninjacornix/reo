#pragma once
#include "constraint_math.hpp"
namespace reo::native::animation {
struct PoseCapsule {
    Vector first,last;
    float radius{};
    Vector direction,center;
    float bounding_radius{};
};
//61B250's finite nonnegative-radius preparation, without model or actor state.
PoseCapsule prepare_pose_capsule(Vector first,Vector last,float radius);
//61B330/61B390. The particle radius affects admission but the correction uses
// the capsule radius alone. False leaves output untouched. Near-axis fallback
// preserves the source's shifted projection rather than inventing a normal.
bool constrain_pose_point(Vector point,float particle_radius,const PoseCapsule&,Vector& output);
}
