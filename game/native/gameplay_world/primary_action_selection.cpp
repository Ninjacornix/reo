#include "primary_action_selection.hpp"
#include "motion.hpp"
#include <stdexcept>

namespace reo::native::gameplay_world {
namespace {
constexpr std::array<LocomotionActionRow,4> rows{{
    {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,0}},
    {{74,75,76,77,78,79,80,81,82,83,84,85,80,81,82,74}},
    {{116,117,118,119,120,121,119,120,121,122,123,124,119,120,121,116}},
    {{74,75,76,77,78,79,80,81,82,83,84,85,80,81,82,74}}
}}; //File1 o2 711810..71188F; subsequent data is a different table.
bool change(Actor& actor,std::uint8_t primary,std::uint16_t secondary,std::uint8_t phase=0){
    actor.primary=primary;actor.secondary=std::uint8_t(secondary);
    actor.phase=phase;actor.subphase=0;save_action_pose(actor);return true;
}
}
const LocomotionActionRow& locomotion_action_row(std::uint8_t index){
    if(index>=rows.size())throw std::out_of_range("Native locomotion action row unavailable");
    return rows[index];
}
bool select_status_action(Actor& actor){
    return (actor.status&0x80u)&&(actor.input.pressed&0x20u)&&change(actor,1,0xb7);
}
bool select_character_action(const World& world,Actor& actor){
    if((actor.status&0x98u)||actor.character!=1||actor.slot!=world.selected_actor)return false;
    return (actor.input.held&0x10u)&&(actor.input.held&0x440u)&&change(actor,2,0x15,10);
}
bool select_directional_action(Actor& actor){
    if((actor.status&0x98u)||(actor.input.held&0x80u)||!(actor.input.pressed&0xf00000u))return false;
    const auto sector=((std::uint16_t(actor.input.analog[1])+0x2000u)&0xc000u)>>14;
    if(sector==0&&actor.motion_class!=0x1e)return change(actor,1,0x11);
    if(sector==2&&actor.motion_class!=0x42)return change(actor,1,0x3c);
    return false;
}
bool select_forward_action(Actor& actor,const LocomotionActionRow& row){
    return (actor.input.held&1u)&&change(actor,1,row[3]);
}
bool select_fast_forward_action(Actor& actor,const LocomotionActionRow& row){
    return !(actor.status&8u)&&(actor.input.held&0x10u)&&(actor.input.held&1u)&&change(actor,1,row[6]);
}
bool select_backward_action(Actor& actor,const LocomotionActionRow& row){
    return (actor.input.held&2u)&&change(actor,1,row[actor.status&0x80u?5:9]);
}
bool select_turn_action(Actor& actor,const LocomotionActionRow& row){
    std::uint32_t buttons=actor.input.held;
    std::size_t left=1,right=2;
    std::uint8_t phase=0;
    switch(actor.motion_class){
    case 1:case 0x22:case 0x2e:
        left=4;right=5;
        if(actor.status&0x2000u)phase=1;else buttons=actor.input.pressed;
        break;
    case 2:case 0x23:case 0x2f:
        if(actor.status&0x80u){left=4;right=5;}
        else{
            left=11;right=10;
            if(actor.status&0x2000u)phase=1;else buttons=actor.input.pressed;
        }
        break;
    case 3:case 0x24:
        left=7;right=8;
        if(actor.status&0x2000u)phase=1;else buttons=actor.input.pressed;
        break;
    case 4:
        left=13;right=14;
        if(actor.status&0x2000u)phase=1;else buttons=actor.input.pressed;
        break;
    default:break;
    }
    if(buttons&8u)return change(actor,1,row[left],phase);
    if(buttons&4u)return change(actor,1,row[right],phase);
    return false;
}
bool select_resource_movement(Actor& actor,const animation_events::Metadata& metadata){
    if((actor.status&0x98u)||actor.class_marker==3)return false;
    if(actor.resource_action&&!(metadata.action_flags(actor.resource_action)&4u))return false;
    return (actor.input.pressed&0x10u)&&(actor.input.held&2u)&&change(actor,1,0x15);
}
bool select_weapon_action(World& world,Actor& actor,const animation_events::Metadata& metadata,PrimaryActionSelectionServices& services){
    if(actor.status&0x98u)return false;
    if(actor.resource_action&&!(metadata.action_flags(actor.resource_action)&1u))return false;
    if(actor.input.held&0x400u){services.prepare_weapon_target(world,actor,true);return change(actor,2,0);}
    if(actor.input.held&0x40u){services.prepare_weapon_target(world,actor,false);return change(actor,2,0);}
    return false;
}
bool select_reload_action(World& world,Actor& actor,PrimaryActionSelectionServices& services){
    if((actor.status&0x98u)||!actor.selected_resource)return false;
    // Availability is queried before the input gate in the original.
    if(!services.reload_available(world,actor,actor.selected_resource))return false;
    return (actor.input.pressed&0x800u)&&change(actor,1,0x38);
}
bool select_idle_action(World& world,Actor& actor,const animation_events::Metadata& metadata,PrimaryActionSelectionServices& services){
    if(actor.category!=0)return false;
    if(world.locally_controlled(actor)&&services.dialogue_suppressed())
        return actor.category==0&&services.modal(world,actor);
    actor.interaction_request_count=0;
    if(actor.category==0&&select_status_action(actor))return true;
    if(actor.category==0&&select_character_action(world,actor))return true;
    if(actor.category==0&&select_directional_action(actor))return true;
    //64F680 and64E950 are original zero-return bodies.
    if(actor.category==0&&services.interaction(world,actor))return true;
    if(actor.category==0&&services.request(world,actor))return true;
    if(actor.category==0&&services.modal(world,actor))return true;
    //64FB70 and64FB80 are original zero-return bodies.
    if(actor.category==0&&select_weapon_action(world,actor,metadata,services))return true;
    if(actor.category==0&&select_resource_movement(actor,metadata))return true;
    //64DCF0 is an original zero-return body.
    const auto& row=locomotion_action_row(0);
    if(actor.category==0&&select_fast_forward_action(actor,row))return true;
    if(actor.category==0&&select_forward_action(actor,row))return true;
    if(actor.category==0&&select_backward_action(actor,row))return true;
    if(actor.category==0&&select_turn_action(actor,row))return true;
    return actor.category==0&&select_reload_action(world,actor,services);
}
}
