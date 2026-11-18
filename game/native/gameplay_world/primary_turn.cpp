#include "primary_turn.hpp"
#include "motion.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
#include "primary_turn_profile.inc"
std::int16_t half(std::int32_t value){return std::bit_cast<std::int16_t>(std::uint16_t(value));}
std::int32_t integer(float value){
    if(!std::isfinite(value)||double(value)<-2147483648.||double(value)>=2147483648.)
        throw std::domain_error("Native primary turn conversion outside supported range");
    return std::int32_t(value);
}
const animation::Playback& playback(const Actor& actor){
    if(!actor.animation||actor.animation->model()!=actor.model)
        throw std::runtime_error("Native primary turn playback unavailable");
    return *actor.animation;
}
void return_to_idle(Actor& actor,ActionAnimation& animation,float blend){
    actor.motion_class=0;actor.action_flags&=~std::uint16_t(1);
    actor.primary=1;actor.secondary=0;actor.phase=1;actor.subphase=0;
    save_action_pose(actor);animation.select(actor,0x2050,0,blend);animation.activate(actor);
}
}
std::int16_t primary_turn_step(const World& world,const Actor& actor){
    if(!actor.primary_state)throw std::runtime_error("Native primary turn initialization unavailable");
    if(actor.primary_state->initialization_marker)return 0;
    auto health=actor.class_marker;
    if(actor.status&0x18u)health=3;
    if(actor.status&0x20u)health=0;
    std::size_t row=0;float scale=1;
    switch(actor.motion_class){
    case 0:case 0xa:scale=actor.motion_rate;break;
    case 1:case 2:case 3:case 4:row=actor.motion_class;break;
    case 7:case 0x2d:case 0x2f:row=5;break;
    case 0x2e:row=5;break;
    case 0x80:scale=actor.motion_rate;break;
    case 0x21:row=6;scale=actor.motion_rate;break;
    case 0x22:row=7;break;
    case 0x23:row=8;break;
    case 0x24:row=9;break;
    default:break;
    }
    if(health>=4||actor.resource_action>=turn_resource_classes.size())
        throw std::out_of_range("Native primary turn content selector unavailable");
    const bool analog=(actor.status&0x2000u)!=0;
    const auto resource=turn_resource_classes[actor.resource_action];
    std::int16_t step{};
    if(actor.motion_class==0x80){
        if(resource[1]>=13)throw std::out_of_range("Native aim turn resource class unavailable");
        step=aim_turns[health][resource[1]];
    }else{
        if(resource[0]>=10)throw std::out_of_range("Native movement turn resource class unavailable");
        step=(analog?analog_turns:digital_turns)[row][health*10+resource[0]];
        if(actor.status&0x80u)step=status_turns[row];
    }
    if(step<0){
        const auto index=std::uint16_t(step)&0x7fffu;
        if(index>=6||actor.character>=8)throw std::out_of_range("Native character turn profile unavailable");
        step=(analog?analog_character_turns:digital_character_turns)[index][actor.character];
    }
    step=half(std::int32_t(step)*(world.session().clock_mode?2:1));
    if(!(scale<=0))step=half(integer(float(step)*scale));
    if(!analog||actor.motion_class==0x80)return step;
    if(actor.secondary==4||actor.secondary==5||actor.secondary==7||actor.secondary==8){
        const auto& timing=playback(actor).channel(animation::ModelBank::primary,0).timing;
        if(timing.frame<timing.restart)step=half(std::int32_t(step)*2);
    }
    if(!actor.analog_control)throw std::runtime_error("Native primary turn heading unavailable");
    const auto target=actor.analog_control->control_target_heading;
    if(actor.secondary==9||actor.secondary==10||actor.secondary==11){
        // Original backward branch takes abs before the final signed-half
        // conversion, without first wrapping the heading subtraction.
        const float difference=std::fabs(float(std::int32_t(target)-0x8000-actor.orientation[1]));
        if(difference<=float(step))step=half(integer(difference));
        return step;
    }
    auto difference=half(std::int32_t(target)-actor.orientation[1]);
    if(difference==INT16_MIN)difference=INT16_MAX;
    difference=half(integer(std::fabs(float(difference))));
    if(difference<step)return difference;
    if(difference>0x6000)return half(std::int32_t(step)*4);
    if(difference>0x4000)return half(std::int32_t(step)*2);
    return step;
}
void update_turn_action(World& world,Actor& actor,ActionAnimation& animation){
    actor.auxiliary_status|=0x100u;
    if(consume_action_reset(actor)){return_to_idle(actor,animation,10);return;}
    const auto step=primary_turn_step(world,actor);
    actor.orientation[1]=half(std::int32_t(actor.orientation[1])+(actor.secondary==1?-std::int32_t(step):std::int32_t(step)));
    if(actor.phase==0xff){return_to_idle(actor,animation,12);return;}
    if(actor.phase==2){(void)animation.tick(actor,actor.motion_rate);actor.root_motion_delta={};return;}
    if(actor.phase==0){
        actor.phase=1;actor.motion_class=0;
        if(!actor.locomotion)throw std::runtime_error("Native primary turn locomotion unavailable");
        actor.locomotion->marker=1;actor.saved_action_position={};actor.saved_action_yaw=0;
        actor.motion_rate=1;
        if(actor.status&0x80u)actor.motion_rate=std::bit_cast<float>(0x3f99999au);
    }else if(actor.phase!=1){return_to_idle(actor,animation,12);return;}
    ++actor.phase;
    if(actor.status&0x2000u)(void)animation.tick(actor,actor.motion_rate);
    else{
        animation.or_flags(actor);
        const auto current=playback(actor).motion;
        const std::uint32_t selected=current==0x2004?0x2004u:0x2003u;
        if(current!=std::int16_t(selected)){
            const auto first=animation.first_frame(actor,selected,0);
            animation.select(actor,selected,first,14);animation.activate(actor);
        }else{(void)animation.tick(actor,actor.motion_rate);animation.activate(actor);}
    }
    actor.root_motion_delta={};
}
}
