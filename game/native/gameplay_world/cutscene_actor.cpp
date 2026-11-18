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
void request(Actor& actor,ScriptedActorState& state){
    if(state.request_flags&2){
        actor.secondary=0x23;state.request_flags&=~2u;
        actor.phase=0;actor.subphase=0;state.request_phase=0;
    }
    if(state.scale_lock==0)actor.contact_flags|=8;
}
void movement(Actor& actor,ScriptedActorState& state){
    if(state.movement_remaining){
        auto rotation=transform_math::identity();
        transform_math::reset_euler_axes(rotation,{std::bit_cast<std::uint16_t>(state.movement_angles[0]),
                                                   std::bit_cast<std::uint16_t>(state.movement_angles[1]),0});
        const auto delta=transform_math::direction(rotation,{0,0,finite(state.forward_step)});
        actor.position.x=finite(actor.position.x+delta.x);
        actor.position.y=finite(delta.y+actor.position.y);
        actor.position.z=finite(delta.z+actor.position.z);
        actor.collision.pose_ready=false;
        actor.orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(actor.orientation[1])+std::uint16_t(state.yaw_step)));
        --state.movement_remaining;
        if(!state.movement_remaining){state.yaw_step=0;state.movement_angles={};state.forward_step=0;}
    }
}
void node_offset(World& world,Actor& actor,std::int16_t remaining,unsigned mode){
    if(actor.model_pose_class!=0||world.paused==0)return;
    if(!actor.model_offset_frame||!actor.model||actor.model->nodes().size()<=26)
        throw std::runtime_error("Native scripted paired-node offset model unavailable");
    // Owned70B010/70B040: only the two consumed endpoints are retained.
    const float first=actor.motion_style?std::bit_cast<float>(0x40d33333u):7.f;
    const float last=actor.motion_style?5.5f:6.f;
    float value=last;
    if(mode!=1){
        const float start=mode==0?first:last,end=mode==0?last:first;
        const float total=float(std::bit_cast<std::uint16_t>(actor.model_offset_frame.value()));
        const float increment=finite((end-start)/total);
        value=finite(start+finite(increment*(total-float(remaining))));
    }
    auto position=actor.model->local_translation(24);position.y=value;
    actor.model->local_translation(24,position);
    position=actor.model->local_translation(26);position.y=value;
    actor.model->local_translation(26,position);
}
}
PrimaryCutsceneAction::PrimaryCutsceneAction(World& world,ScriptedActorMotion& motion):world_(world),motion_(motion){
    if(!motion_.bound_to(world_))throw std::invalid_argument("Native primary cutscene motion owner mismatch");
}
void PrimaryCutsceneAction::tick(const actors::EntityId& id){
    if(world_.closed())throw std::runtime_error("Native primary cutscene World closed");
    const auto actor=world_.resolve(id);
    if(!actor||!actor->scripted||actor->category>1)
        throw std::runtime_error("Native primary cutscene actor state unavailable");
    auto& state=*actor->scripted;
    if(state.cue_phase==0){
        actor->primary=6;actor->secondary=actor->phase=actor->subphase=0;actor->root_motion_delta={};
        if(!actor->animation)throw std::runtime_error("Native primary cutscene channels unavailable");
        // The source clears twelve records. Native Playback exposes only the
        // five admitted channels; its unused record tail has no native state.
        for(unsigned track=0;track<5;++track)actor->animation->channel(animation::ModelBank::primary,track)={};
    }else if(state.cue_phase==1||state.cue_phase==2){
        if(state.cue_phase==1){actor->visible=true;state.cue_phase=2;actor->secondary=actor->phase=actor->subphase=0;}
        request(*actor,state);
        for(unsigned mode=0;mode<state.command_angles.size();++mode){
            auto& timer=state.command_angles[mode];if(timer==0)continue;
            node_offset(world_,*actor,timer,mode);
            timer=std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(timer)-1));
            if(timer==0)actor->model_offset_frame=mode<2?state.command_angles[mode+1]:0;
            break;
        }
        movement(*actor,state);
        if(actor->secondary==0x23)motion_.tick(id);
    }
    if(actor->auxiliary_status&2)actor->contact_flags|=0x40;
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
    if(!actor->scripted||actor->category!=2)throw std::runtime_error("Native linked cutscene actor state unavailable");
    auto& state=*actor->scripted;
    if(state.cue_phase==1){actor->visible=true;state.cue_phase=2;}
    else if(state.cue_phase!=2)return;
    request(*actor,state);movement(*actor,state);
    if(actor->secondary==0x23){
        motion_.tick(id);integrate_local_motion(*actor);rebuild_actor_pose(world_,*actor,pose_);
    }
}
}
