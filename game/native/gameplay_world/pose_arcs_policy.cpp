#include "pose_arcs.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
void integrate_rotated_pose_velocity(Actor& actor){
    if(!actor.pose_work)throw std::invalid_argument("Native pose velocity requires its actual domain");
    auto basis=transform_math::identity();transform_math::reset_euler_axes(basis,
        {std::uint16_t(actor.orientation[0]),std::uint16_t(actor.orientation[1]),std::uint16_t(actor.orientation[2])});
    const auto velocity=transform_math::direction(basis,actor.pose_work->velocity);
    actor.position={actor.position.x+velocity.x,actor.position.y+velocity.y,actor.position.z+velocity.z};
}
PoseArcStep advance_quarter_turn_pose_arc(Actor& actor,std::uint8_t kind,const actors::EntityId& id,PoseArcEffects& effects){
    if(kind!=13&&kind!=16)return PoseArcStep::unhandled;
    if(!actor.pose_work)return PoseArcStep::unavailable;
    auto& state=*actor.pose_work;
    if(actor.primary==0){
        actor.primary=1;state.velocity=kind==13?transform_math::Vector{0,8,-4}:transform_math::Vector{0,4,8};
        state.acceleration={0,std::bit_cast<float>(0xbfb33333u),std::bit_cast<float>(kind==13?0xbecccccdu:0x3e4ccccdu)};
        actor.orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(std::uint32_t(std::uint16_t(actor.orientation[1]))+(std::uint32_t(state.variant)<<14)));
        if(kind==16){if(!effects.trail(actor.contact.related,id,0))return PoseArcStep::unavailable;if(!effects.trail(actor.contact.related,id,1))return PoseArcStep::unavailable;}
        return PoseArcStep::completed;
    }
    if(actor.primary!=1)return PoseArcStep::completed;
    integrate_rotated_pose_velocity(actor);
    state.velocity.y=state.velocity.y+state.acceleration.y;state.velocity.z=state.velocity.z+state.acceleration.z;
    const auto sampled=effects.floor({actor.position.x,actor.position.y,actor.position.z});if(!sampled)return PoseArcStep::unavailable;
    actor.sampled_surface_height=sampled->height;
    if(actor.position.y<=sampled->height){actor.position.y=sampled->height;++actor.primary;actor.auxiliary_status|=1;return PoseArcStep::retire;}
    return PoseArcStep::completed;
}
}
