#include "pose_splitting_arc.hpp"
#include "head_reaction.hpp"
#include <bit>
namespace reo::native::gameplay_world {
bool advance_splitting_pose_arc(Actor& actor,const actors::EntityId& id,SplittingArcEffects& effects){
    if(!actor.pose_work)return false;
    auto& state=*actor.pose_work;
    if(actor.primary==0){
        ++actor.primary;state.velocity={0,15,-9};state.acceleration={0,std::bit_cast<float>(0xbfb33333u),std::bit_cast<float>(0x3c23d70au)};
        const auto target=effects.primary_zero_position();if(!target)return false;
        const auto angles=head_direction_turns(*target,{actor.position.x,actor.position.y,actor.position.z});actor.orientation[0]=actor.orientation[2]=0;actor.orientation[1]=angles[1];
        return effects.packet(id,0x1b,1)&&effects.trail(actor.contact.related,id,0)&&effects.trail(actor.contact.related,id,1);
    }
    if(actor.primary!=1)return true;
    integrate_rotated_pose_velocity(actor);state.velocity.y=state.velocity.y+state.acceleration.y;state.velocity.z=state.velocity.z+state.acceleration.z;
    if(state.velocity.z>0){state.velocity.z=0;state.acceleration.z=0;}
    const auto floor=effects.floor({actor.position.x,actor.position.y,actor.position.z});if(!floor)return false;actor.sampled_surface_height=floor->height;
    if(actor.position.y<=floor->height){
        ++actor.primary;actor.position.y=floor->height;
        if(!effects.sound(actor.contact.related,7))return false;
        for(std::uint8_t variant=0;variant<4;++variant)if(!effects.preset(state.emitter_owner,state.basis,{actor.position.x,actor.position.y,actor.position.z},actor.orientation,7,variant))return false;
        actor.auxiliary_status|=1;return effects.retire(id);
    }
    return true;
}
}
