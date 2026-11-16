#include "primary_locomotion.hpp"
#include "primary_turn.hpp"
#include "motion.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
animation::Playback& playback(Actor& actor){
    if(!actor.animation||actor.animation->model()!=actor.model)throw std::runtime_error("Native locomotion playback unavailable");
    return *actor.animation;
}
void idle(Actor& actor,ActionAnimation& actions){
    actor.motion_class=0;actor.action_flags&=~std::uint16_t(1);
    actor.primary=1;actor.secondary=0;actor.phase=1;actor.subphase=0;
    save_action_pose(actor);actions.select(actor,0x2050,0,10);actions.activate(actor);
}
void marker(Actor& actor,std::uint8_t value){
    if(!actor.locomotion)throw std::runtime_error("Native locomotion state unavailable");
    actor.locomotion->marker=value;
}
void clear_pose(Actor& actor){actor.saved_action_position={};actor.saved_action_yaw=0;}
void rate(Actor& actor,bool boost){
    actor.motion_rate=1;
    if(boost&&(actor.status&0x80u))actor.motion_rate=actor.motion_rate*std::bit_cast<float>(0x3f99999au);
    if(!actor.primary_state)throw std::runtime_error("Native locomotion statistic unavailable");
    actor.motion_rate=actor.motion_rate*actor.primary_state->statistic_multiplier;
}
}
void update_locomotion_action(World& world,Actor& actor,const gameplay_collision::response::Grid& floors,ActionAnimation& actions){
    if(actor.secondary<3||actor.secondary>11)throw std::out_of_range("Native locomotion secondary unavailable");
    const bool backward=actor.secondary>=9,running=actor.secondary>=6&&!backward;
    const auto base=std::uint8_t(backward?9:running?6:3);
    if(backward||running)actor.auxiliary_status|=0x100u;
    if(consume_action_reset(actor)){idle(actor,actions);return;}
    actor.auxiliary_status|=0x100u;
    if(actor.secondary!=base){
        const auto step=primary_turn_step(world,actor);
        const bool positive=backward?actor.secondary==10:actor.secondary==base+2;
        actor.orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(int(actor.orientation[1])+(positive?int(step):-int(step))));
    }
    const auto surface=probe_locomotion_floor(actor,floors).type;
    select_floor_locomotion(actor,std::uint8_t(backward?1:running?2:0),floors,actions);
    const auto clock=world.session().clock_mode;
    const auto finish=[&]{if(!backward)finish_locomotion_step(actor,clock);};
    if(actor.phase!=0&&actor.phase!=1&&actor.phase!=2){idle(actor,actions);finish();return;}
    if(actor.phase==0){
        ++actor.phase;
        if(backward){
            actor.motion_rate=1;actions.or_flags(actor);
            if(playback(actor).motion!=0x2004)actions.select(actor,0x2004,0,10);
            actor.motion_class=2;marker(actor,1);return;
        }
        float initial=0;
        if(surface!=1&&(running?actor.motion_class==1:(actor.motion_class==3||actor.motion_class==4))){
            advance_floor_locomotion(actor,clock,floors);
            initial=locomotion_transition_frame(actor,std::uint16_t(running?0x2005:0x2003),actions);
        }
        actor.motion_class=std::uint8_t(running?3:1);marker(actor,std::uint8_t(running?2:1));
        const auto motion=std::uint16_t(running?0x2005:0x2003),current=std::uint16_t(playback(actor).motion);
        if(current!=motion){
            float blend=10;
            if(running&&actor.character==0&&current!=0x2003&&initial<1){actions.or_flags(actor);blend=-10;}
            actions.select(actor,motion,initial,blend);
        }
        finish();return;
    }
    if(actor.phase==1){
        if(backward){
            ++actor.phase;actor.motion_class=2;marker(actor,1);clear_pose(actor);actor.motion_rate=1;
            if(surface!=1&&playback(actor).motion!=0x2009&&playback(actor).motion!=0x2004)actions.select(actor,0x2004,0,10);
            if(!actor.primary_state)throw std::runtime_error("Native locomotion statistic unavailable");
            actor.motion_rate=actor.motion_rate*actor.primary_state->statistic_multiplier;actions.activate(actor);
        }else{
            const auto motion=std::uint16_t(running?0x2005:0x2003);
            if(surface!=1&&playback(actor).motion!=motion){if(!running)actor.root_motion_delta={};actions.select(actor,motion,0,10);}
            ++actor.phase;actor.motion_class=std::uint8_t(running?3:1);marker(actor,std::uint8_t(running?2:1));clear_pose(actor);
            if(!running)actions.activate(actor);
            rate(actor,true);
            if(running)actions.activate(actor);
        }
    }
    advance_floor_locomotion(actor,clock,floors);(void)actions.tick(actor,actor.motion_rate);finish();
}
}
