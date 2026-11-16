#include "idle_action.hpp"
#include "motion.hpp"
#include "../gameplay_actors/health_class.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
animation::Playback& playback(Actor& actor){
    if(!actor.animation||actor.animation->model()!=actor.model)
        throw std::runtime_error("Native primary action playback unavailable");
    return *actor.animation;
}
void clear_action_pose(Actor& actor)noexcept{
    actor.saved_action_position={};actor.saved_action_yaw=0;
}
PrimaryLocomotionState& locomotion(Actor& actor){
    if(!actor.locomotion)throw std::runtime_error("Native primary locomotion state unavailable");
    return *actor.locomotion;
}
}
std::uint8_t consume_action_reset(Actor& actor){
    if(!(actor.auxiliary_status&4u))return 0;
    actor.auxiliary_status&=~4u;
    playback(actor).motion=0;
    if(actor.phase==0xff)return 0;
    return actor.auxiliary_status&0x80u?2:1;
}
bool select_changed_health_action(Actor& actor){
    if(actor.status&0x80u)return false;
    constexpr std::array<float,2> thresholds{50,25};
    if(actors::derive_health_class(actor,thresholds)==actors::ClassResult::invalid_maximum)
        throw std::runtime_error("Native primary action health denominator unavailable");
    const auto classification=actor.status&8u?3:actor.class_marker;
    if(classification==actor.previous_motion_class)return false;
    actor.contact_flags|=0x10;
    actor.primary=1;actor.secondary=0x62;actor.phase=actor.subphase=0;
    save_action_pose(actor);return true;
}
NativeActionAnimation::NativeActionAnimation(World& world,WorldAnimation& animation):
    world_(world),animation_(animation){
    if(!animation_.bound_to(world_))throw std::invalid_argument("Canonical action animation required");
}
actors::EntityId NativeActionAnimation::admit(Actor& actor)const{
    const auto id=world_.identity_of(actor);
    if(!animation_.bound_to(world_)||!id||world_.resolve(id).get()!=&actor)
        throw std::runtime_error("Native action actor retired or foreign");
    return id;
}
void NativeActionAnimation::select(Actor& actor,std::uint32_t motion,float initial,float blend){
    animation_.select(admit(actor),motion,initial,blend);
}
void NativeActionAnimation::activate(Actor& actor){
    (void)admit(actor);auto& state=playback(actor);state.activate(state.channel_count);
}
std::int8_t NativeActionAnimation::tick(Actor& actor,float step){return animation_.tick(admit(actor),step);}
void ActionAnimation::or_flags(Actor&){throw std::runtime_error("Native action animation flag consumer unavailable");}
float ActionAnimation::first_frame(Actor&,std::uint32_t,std::uint16_t){throw std::runtime_error("Native action initial frame consumer unavailable");}
float ActionAnimation::last_frame(Actor&,std::uint32_t,std::uint16_t){throw std::runtime_error("Native action last frame consumer unavailable");}
float ActionAnimation::matched_frame(Actor&,std::uint32_t,std::uint16_t){throw std::runtime_error("Native action matched frame consumer unavailable");}
void NativeActionAnimation::or_flags(Actor& actor){(void)admit(actor);playback(actor).or_primary_flags82();}
float NativeActionAnimation::first_frame(Actor& actor,std::uint32_t motion,std::uint16_t track){return animation_.first_frame(admit(actor),motion,track);}
float NativeActionAnimation::last_frame(Actor& actor,std::uint32_t motion,std::uint16_t track){return animation_.last_frame(admit(actor),motion,track);}
float NativeActionAnimation::matched_frame(Actor& actor,std::uint32_t motion,std::uint16_t track){return animation_.matched_frame(admit(actor),motion,track);}
void update_idle_action(Actor& actor,ActionAnimation& animation){
    actor.auxiliary_status|=0x100u;actor.action_flags&=~std::uint16_t(1);
    if(consume_action_reset(actor))actor.phase=0;
    if(select_changed_health_action(actor))return;
    if(actor.phase==0){
        actor.phase=1;actor.motion_class=0;locomotion(actor).marker=0;
        clear_action_pose(actor);locomotion(actor).velocity={};actor.motion_rate=1;
        animation.select(actor,0x2050,0,0);animation.activate(actor);return;
    }
    if(actor.phase==1){
        actor.phase=10;actor.motion_class=0;locomotion(actor).marker=0;
        clear_action_pose(actor);actor.motion_rate=1;
    }
    if(actor.phase==10){
        if(animation.tick(actor,1)!=1)return;
        ++actor.phase;
        if(playback(actor).motion!=0x2001){
            animation.select(actor,0x2051,0,8);animation.activate(actor);
        }
    }else if(actor.phase==11)(void)animation.tick(actor,1);
}
}
