#include "pose_ground_flight.hpp"
#include <bit>
#include <cmath>
namespace reo::native::gameplay_world {
namespace {
float scaled_direction(float value){
    // The source's1118B8/111DB0/112470 chain flushes subnormal inputs
    // and truncates the final finite unit-direction product toward zero.
    if(std::fpclassify(value)==FP_SUBNORMAL)return std::copysign(0.f,value);
    const double exact=double(value)*1.5;const float rounded=float(exact);
    if(std::fpclassify(rounded)==FP_SUBNORMAL)return std::copysign(0.f,rounded);
    return std::fabs(double(rounded))>std::fabs(exact)?std::nextafter(rounded,0.f):rounded;
}
}
bool advance_ground_pose_flight(Actor& actor,const actors::EntityId& id,GroundPoseEffects& effects){
    if(!actor.pose_work)return false;
    auto& state=*actor.pose_work;
    if(actor.primary==0){
        actor.primary=1;actor.visible=true;state.velocity.y=-2.f;state.acceleration.y=std::bit_cast<float>(0xbf4ccccdu);
        const auto floor=effects.floor({actor.position.x,actor.position.y,actor.position.z});if(!floor)return false;
        actor.sampled_surface_height=floor->height;
        return effects.packet(id,3,1)&&effects.flare(id)&&effects.trail(id);
    }
    if(actor.primary!=1)return true;
    auto basis=transform_math::identity();transform_math::compose_euler_axes(basis,{std::uint16_t(actor.orientation[0]),std::uint16_t(actor.orientation[1]),std::uint16_t(actor.orientation[2])});
    const auto direction=transform_math::direction(basis,{0,0,1});
    const float dx=scaled_direction(direction.x),dz=scaled_direction(direction.z);
    actor.position.x=actor.position.x+dx;actor.position.z=actor.position.z+dz;actor.position.y=actor.position.y+state.velocity.y;
    if(actor.position.y<=actor.sampled_surface_height){
        ++actor.primary;actor.position.y=actor.sampled_surface_height;actor.auxiliary_status|=1;
        if(!effects.retire(id))return false;
        return effects.sound(actor.contact.related,7);
    }
    state.velocity.y=state.velocity.y+state.acceleration.y;return true;
}
}
