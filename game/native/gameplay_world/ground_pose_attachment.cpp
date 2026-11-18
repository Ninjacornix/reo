#include "ground_pose_attachment.hpp"
#include <span>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
#include "ground_pose_attachment_profile.inc"
}
std::optional<std::uint8_t> ground_pose_attachment_joint(std::uint8_t type,std::uint16_t variant)noexcept{
    if(type>=attachment_flags.size()||variant>=attachment_flags[type].size())return{};
    return attachment_flags[type][variant]==1?14:21;
}
GroundPoseAttachment prepare_ground_pose_attachment(std::int16_t yaw,const transform_math::Matrix& joint,bool trail){
    GroundPoseAttachment result;result.basis=transform_math::identity();transform_math::reset_euler_axes(result.basis,{0,std::uint16_t(yaw),0});
    const auto delta=transform_math::direction(joint,{0,-10,trail?25.f:20.f});
    result.position={joint[3][0]+delta.x,joint[3][1]+delta.y,joint[3][2]+delta.z};
    if(!std::isfinite(result.position.x)||!std::isfinite(result.position.y)||!std::isfinite(result.position.z))throw std::domain_error("Native ground attachment finite position required");
    return result;
}
}
