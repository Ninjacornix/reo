#include "scripted_motion.hpp"
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
animation::Playback& playback(Actor& actor){
    if(!actor.animation||actor.animation->model()!=actor.model)
        throw std::runtime_error("Native scripted actor animation/model unavailable");
    return *actor.animation;
}
animation::RootMotionRef root(Actor& actor){return{actor.root_motion_delta.x,actor.root_motion_delta.y,actor.root_motion_delta.z};}
const animation::MotionBank& bank(const std::shared_ptr<const animation::MotionBank>& value){
    if(!value)throw std::runtime_error("Native scripted motion bank unavailable");
    return *value;
}
void configure(World& world,Actor& actor,const animation::MotionBank& resource,std::int16_t motion,float duration){
    if(resource.kind()==animation::MotionBankKind::sparse)
        throw std::runtime_error("Native scripted configuration requires strided scene motion data");
    if(actor.auxiliary_status&2){actor.auxiliary_status&=~2u;duration=0;}
    auto& state=playback(actor);
    const animation::MotionClock clock{world.session().clock_mode,actor.category,actor.motion_rate};
    if(resource.track_count()==1){
        if(!resource.find(std::uint16_t(motion),0))
            throw std::runtime_error("Native scripted whole-model motion token unavailable");
        (void)state.configure_whole(resource,motion,0,duration,clock,root(actor));
        return;
    }
    for(unsigned index=0;index<resource.track_count();++index){
        const auto track=std::uint16_t(resource.first_track()+index);
        const auto block=resource.find(std::uint16_t(motion),track);
        if(!block)throw std::runtime_error("Native scripted track motion metadata unavailable");
        (void)state.configure(resource,motion,track,0,duration,clock,root(actor));
        const auto clip=block->clip();auto& timing=state.channel(animation::ModelBank::primary,track).timing;
        //5D1F20 queries loop metadata again after58B9A0's own adjustments.
        timing.loop=std::int8_t(clip->looping());timing.restart=clip->looping()?clip->loop_start():0;
        if(timing.restart<0)timing.restart=0;
    }
}
void advance(World& world,Actor& actor,const animation::MotionBank& resource,float step){
    if(resource.kind()==animation::MotionBankKind::sparse)
        throw std::runtime_error("Native scripted advancement requires strided scene motion data");
    auto& state=playback(actor);const auto mode=world.session().clock_mode;
    if(resource.track_count()==1){
        if(resource.kind()==animation::MotionBankKind::sparse||resource.first_track()!=0||
           !resource.find(state.channel(animation::ModelBank::primary,0).selector,0))
            throw std::runtime_error("Native scripted whole-model motion binding unavailable");
        (void)state.advance_whole(step,mode,root(actor));return;
    }
    const unsigned first=resource.first_track(),end=first+resource.track_count();
    for(unsigned track=first+1;track<end;++track)(void)state.advance_primary(std::uint16_t(track),step,mode,root(actor));
    (void)state.advance_primary(std::uint16_t(first),step,mode,root(actor));
}
}
void ScriptedActorMotion::tick(const actors::EntityId& id){
    const auto actor=world_.resolve(id);
    if(!actor||!actor->scripted||actor->category!=2)
        throw std::runtime_error("Native scripted linked actor unavailable");
    auto& control=*actor->scripted;
    actor->contact_flags|=0x17;
    if(actor->phase==0){
        actor->phase=1;actor->motion_class=0x14;actor->motion_rate=1;
        auto& state=playback(*actor);
        state.resources[0]=control.motion_rate_mode==1?banks_.mode_one:banks_.other_modes;
        actor->root_motion_delta={};
        const float duration=control.motion_blend_duration*(control.motion_rate_mode==0?1.f:2.f);
        if(!std::isfinite(duration))throw std::domain_error("Native scripted motion finite blend duration required");
        configure(world_,*actor,bank(state.resources[0]),control.motion_selector,duration);
        state.activate(state.channel_count);
    }else if(actor->phase==1){
        auto& state=playback(*actor);
        if(!state.resources_known)throw std::runtime_error("Native scripted motion bank bindings unavailable");
        advance(world_,*actor,bank(state.resources[0]),control.motion_rate_mode==0?1.f:.5f);
    }
    if(control.track_two_motion!=0&&actor->model_pose_class!=1){
        auto& state=playback(*actor);
        const animation::MotionClock clock{world_.session().clock_mode,actor->category,actor->motion_rate};
        (void)state.configure(bank(banks_.track_two),control.track_two_motion,2,0,0,clock,root(*actor));
        control.track_two_motion=0;
    }
}
}
