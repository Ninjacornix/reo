#include "pose_motion.hpp"
#include <bit>
namespace reo::native::gameplay_world {
namespace {std::int16_t decrement(std::int16_t v){return std::bit_cast<std::int16_t>(std::uint16_t(std::int32_t(v)-1));}}
PoseMotionStep advance_pose_motion(Actor& actor,std::uint8_t kind,std::optional<std::uint8_t> quantum){
    if(kind!=11&&kind!=19)return PoseMotionStep::unhandled;
    if(!actor.pose_work)return PoseMotionStep::unavailable;
    auto& state=*actor.pose_work;
    if(kind==19){
        if(actor.primary==0){actor.primary=1;actor.position.z=actor.position.z-400.f;}
        else if(actor.primary==1&&!actor.contact.serial)state.timer=decrement(state.timer);
        return PoseMotionStep::completed;
    }
    if(actor.primary==0){
        actor.primary=1;actor.visible=true;state.velocity.y=std::bit_cast<float>(0xbf4ccccdu);state.acceleration.y=std::bit_cast<float>(0xbd8f5c29u);
        if(!quantum)return PoseMotionStep::unavailable;
        // SDK/R5900 signed DIV by zero returns -1 for this positive dividend.
        const int count=*quantum?60/int(*quantum):-1;state.timer=std::int16_t(3*count);
    }
    if(actor.primary!=1)return PoseMotionStep::completed;
    actor.position.y=actor.position.y+state.velocity.y;state.velocity.y=state.velocity.y+state.acceleration.y;
    if(!actor.response_class){state.timer=decrement(state.timer);if(state.timer>0)return PoseMotionStep::completed;}
    ++actor.primary;actor.auxiliary_status|=1;return PoseMotionStep::retire;
}
}
