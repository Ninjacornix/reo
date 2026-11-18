#include "pose_parent_flight.hpp"
namespace reo::native::gameplay_world {
ParentFlightStep advance_parent_pose_flight(Actor& actor,const actors::EntityId& id,std::uint8_t clock_mode,ParentFlightEffects& effects){
    if(!actor.pose_work)return ParentFlightStep::unavailable;
    auto& state=*actor.pose_work;
    if(actor.primary==0){
        actor.primary=1;const auto parent=effects.launch(actor.contact.related);if(!parent)return ParentFlightStep::unavailable;
        if(parent->primary==2&&parent->secondary==0)state.velocity=transform_math::direction(parent->basis,{0,2,15});
        else if(parent->primary==2&&parent->secondary==2)state.velocity={};
        else{actor.primary=255;actor.auxiliary_status|=1;state.lifetime=1;return ParentFlightStep::completed;}
        state.acceleration.y=clock_mode?-1.f:-.5f;
        if(!effects.trail(actor.contact.related,id,0)||!effects.trail(actor.contact.related,id,1))return ParentFlightStep::unavailable;
    }else if(actor.primary!=1)return ParentFlightStep::completed;
    actor.position={actor.position.x+state.velocity.x,actor.position.y+state.velocity.y,actor.position.z+state.velocity.z};
    state.velocity.y=state.velocity.y+state.acceleration.y;
    const auto sampled=effects.floor({actor.position.x,actor.position.y,actor.position.z});if(!sampled)return ParentFlightStep::unavailable;
    actor.sampled_surface_height=sampled->height;
    if(actor.position.y<sampled->height){
        if(!effects.sound(actor.contact.related,9))return ParentFlightStep::unavailable;
        ++actor.primary;actor.auxiliary_status|=1;return ParentFlightStep::retire;
    }
    return ParentFlightStep::completed;
}
}
