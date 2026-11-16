#include "primary_movement_selection.hpp"
#include "idle_action.hpp"
#include "motion.hpp"
#include <initializer_list>
#include <algorithm>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
bool change(Actor& actor,std::uint16_t state,std::uint8_t phase=0){
    actor.primary=1;actor.secondary=std::uint8_t(state);actor.phase=phase;actor.subphase=0;
    save_action_pose(actor);return true;
}
std::uint8_t row_for_motion(const Actor& actor){
    switch(actor.motion_class){case 0x22:case 0x23:case 0x24:return 1;case 0x2e:case 0x2f:return 2;default:return 0;}
}
bool held_turn(Actor& actor,const LocomotionActionRow& row){
    if(actor.input.held&8u)return change(actor,row[1]);
    if(actor.input.held&4u)return change(actor,row[2]);
    return false;
}
bool finish(Actor& actor){actor.phase=0xff;return true;}
enum class Choice {interaction,request,modal,weapon,resource_move,fast_forward,forward,backward,turn,pressed_turn,stop_turn,stop_walk,stop_run,stop_backward,stop_sprint,resume_walk,resume_run,resume_backward,resume_sprint};
}
bool select_pressed_turn(Actor& actor,const LocomotionActionRow& row){
    if(actor.input.pressed&8u)return change(actor,row[1]);
    if(actor.input.pressed&4u)return change(actor,row[2]);
    return false;
}
bool stop_turn(Actor& actor){return !(actor.input.held&0xcu)&&finish(actor);}
bool stop_walk(Actor& actor){
    if(actor.input.held&1u)return false;
    if(!(actor.status&0x2000u)){
        if(held_turn(actor,locomotion_action_row(row_for_motion(actor))))return true;
    }else if(actor.category==0&&select_turn_action(actor,locomotion_action_row(0)))return true;
    return finish(actor); // complete5D5990 returns1 with no effects.
}
bool stop_run(Actor& actor){
    if(actor.input.held&1u)return !(actor.input.held&0x10u)&&change(actor,3);
    if(held_turn(actor,locomotion_action_row(row_for_motion(actor))))return true;
    return finish(actor);
}
bool stop_sprint(Actor& actor){
    if(actor.input.held&1u)return !(actor.input.held&0x10u)&&change(actor,0x32);
    if(actor.class_marker>=2||actor.surface_kind==1)return finish(actor);
    return change(actor,0x32);
}
bool stop_backward(Actor& actor){
    if(actor.input.held&2u)return false;
    //5D5990 returns1 before the motion-class selection.
    if(held_turn(actor,locomotion_action_row(row_for_motion(actor))))return true;
    return finish(actor);
}
bool resume_movement(Actor& actor,std::uint8_t secondary){
    if(secondary!=3&&secondary!=6&&secondary!=9&&secondary!=12)
        throw std::out_of_range("Native movement resume selector unavailable");
    return (actor.input.held&(secondary==9?2u:1u))&&change(actor,secondary,1);
}
bool select_movement_action(World& world,Actor& actor,const animation_events::Metadata& metadata,PrimaryActionSelectionServices& services){
    using C=Choice;
    std::array<C,10> choices{};std::size_t count{};
    const auto set=[&](std::initializer_list<C> value){std::copy(value.begin(),value.end(),choices.begin());count=value.size();};
    switch(actor.secondary){
    case 1:case 2:set({C::interaction,C::request,C::modal,C::weapon,C::fast_forward,C::forward,C::backward,C::pressed_turn,C::stop_turn});break;
    case 3:set({C::interaction,C::request,C::modal,C::weapon,C::resource_move,C::fast_forward,C::backward,C::turn,C::stop_walk});break;
    case 4:case 5:set({C::interaction,C::request,C::modal,C::weapon,C::resource_move,C::fast_forward,C::backward,C::stop_walk,C::turn,C::resume_walk});break;
    case 6:set({C::interaction,C::request,C::modal,C::weapon,C::resource_move,C::backward,C::turn,C::stop_run});break;
    case 7:case 8:set({C::interaction,C::request,C::modal,C::weapon,C::backward,C::stop_run,C::turn,C::resume_run});break;
    case 9:set({C::interaction,C::modal,C::weapon,C::resource_move,C::turn,C::stop_backward});break;
    case 10:case 11:set({C::interaction,C::modal,C::weapon,C::resource_move,C::stop_backward,C::turn,C::resume_backward});break;
    case 12:set({C::interaction,C::modal,C::stop_sprint,C::turn});break;
    case 13:case 14:set({C::interaction,C::modal,C::stop_sprint,C::turn,C::resume_sprint});break;
    default:throw std::out_of_range("Native primary movement selector unavailable");
    }
    if(actor.category==0&&select_status_action(actor))return true;
    if(select_changed_health_action(actor))return true; // this call is not category gated.
    const auto& row=locomotion_action_row(0);
    for(const auto choice:std::span<const C>(choices).first(count)){
        //64E950 and64DCF0 are original zero-return entries. Every other
        //call after the health policy rechecks the current category byte.
        if(actor.category!=0)continue;
        bool selected{};
        switch(choice){
        case C::interaction:selected=services.interaction(world,actor);break;
        case C::request:selected=services.request(world,actor);break;
        case C::modal:selected=services.modal(world,actor);break;
        case C::weapon:selected=select_weapon_action(world,actor,metadata,services);break;
        case C::resource_move:selected=select_resource_movement(actor,metadata);break;
        case C::fast_forward:selected=select_fast_forward_action(actor,row);break;
        case C::forward:selected=select_forward_action(actor,row);break;
        case C::backward:selected=select_backward_action(actor,row);break;
        case C::turn:selected=select_turn_action(actor,row);break;
        case C::pressed_turn:selected=select_pressed_turn(actor,row);break;
        case C::stop_turn:selected=stop_turn(actor);break;
        case C::stop_walk:selected=stop_walk(actor);break;
        case C::stop_run:selected=stop_run(actor);break;
        case C::stop_backward:selected=stop_backward(actor);break;
        case C::stop_sprint:selected=stop_sprint(actor);break;
        case C::resume_walk:selected=resume_movement(actor,3);break;
        case C::resume_run:selected=resume_movement(actor,6);break;
        case C::resume_backward:selected=resume_movement(actor,9);break;
        case C::resume_sprint:selected=resume_movement(actor,12);break;
        }
        if(selected)return true;
    }
    return false;
}
}
