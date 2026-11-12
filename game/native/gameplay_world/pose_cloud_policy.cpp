#include "pose_cloud.hpp"
#include <bit>
namespace reo::native::gameplay_world {
PoseCloudStep advance_pose_cloud(Actor& actor,PoseCloudEffects& effects){
    if(!actor.pose_work)return PoseCloudStep::unavailable;
    auto& state=*actor.pose_work;
    if(actor.primary==0){
        actor.primary=1;actor.visible=false;const transform_math::Vector point{actor.position.x,actor.position.y,actor.position.z};
        if(!effects.visual(point))return PoseCloudStep::unavailable;
        state.lifetime=75;state.timer=75;
        if(!effects.light(actor.contact.related,point))return PoseCloudStep::unavailable;
    }
    const auto before=state.timer;state.timer=std::bit_cast<std::int16_t>(std::uint16_t(std::int32_t(before)-1));
    if(before<0){++actor.primary;actor.auxiliary_status|=1;return PoseCloudStep::retire;}
    return PoseCloudStep::completed;
}
}
