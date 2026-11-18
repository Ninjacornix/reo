#include "camera_math.hpp"
namespace reo::native::gameplay_scenario {
transform_math::Matrix camera_view(const CameraPose& pose){
    auto rotation=transform_math::identity();
    transform_math::compose_euler_axes(rotation,{0,0,std::uint16_t(pose.roll)});
    const transform_math::Vector backward{-(pose.aim.x-pose.eye.x),-(pose.aim.y-pose.eye.y),-(pose.aim.z-pose.eye.z)};
    auto basis=transform_math::direction_basis(backward,pose.up);
    basis[3]={pose.eye.x,pose.eye.y,pose.eye.z,1};
    transform_math::concatenate_left(rotation,basis);
    return transform_math::inverse_orthonormal(rotation);
}
}
