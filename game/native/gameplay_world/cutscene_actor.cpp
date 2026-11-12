#include "cutscene_actor.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
float finite(float value){
    if(!std::isfinite(value))throw std::domain_error("Native cutscene actor finite displacement required");
    return value;
}
}
CutsceneActor::CutsceneActor(World& world,ScriptedActorMotion& motion,const gameplay_collision::response::Grid& floors):
    world_(world),motion_(motion),pose_(floors){
    if(!motion_.bound_to(world_))throw std::invalid_argument("Native cutscene actor motion owner mismatch");
}
void CutsceneActor::tick(const actors::EntityId& id){
    if(world_.closed())throw std::runtime_error("Native cutscene actor World closed");
    if(world_.paused==0)return;
    const auto actor=world_.resolve(id);
    if(!actor)throw std::runtime_error("Native cutscene actor identity unavailable");
    if(actor->primary!=6)return;
    if(!actor->scripted||actor->category>2)throw std::runtime_error("Native cutscene actor state unavailable");
    auto& state=*actor->scripted;
    if(state.cue_phase==1){actor->visible=true;state.cue_phase=2;}
    else if(state.cue_phase!=2)return;
    if(state.request_flags&2){
        actor->secondary=0x23;state.request_flags&=~2u;
        actor->phase=0;actor->subphase=0;state.request_phase=0;
    }
    if(state.scale_lock==0)actor->contact_flags|=8;
    if(state.movement_remaining){
        auto rotation=transform_math::identity();
        transform_math::reset_euler_axes(rotation,{std::bit_cast<std::uint16_t>(state.movement_angles[0]),
                                                   std::bit_cast<std::uint16_t>(state.movement_angles[1]),0});
        const auto delta=transform_math::direction(rotation,{0,0,finite(state.forward_step)});
        actor->position.x=finite(actor->position.x+delta.x);
        actor->position.y=finite(delta.y+actor->position.y);
        actor->position.z=finite(delta.z+actor->position.z);
        actor->collision.pose_ready=false;
        actor->orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(actor->orientation[1])+std::uint16_t(state.yaw_step)));
        --state.movement_remaining;
        if(!state.movement_remaining){state.yaw_step=0;state.movement_angles={};state.forward_step=0;}
    }
    if(actor->secondary==0x23){
        motion_.tick(id);integrate_local_motion(*actor);rebuild_actor_pose(world_,*actor,pose_);
    }
}
}
