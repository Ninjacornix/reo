#include "room_rules.hpp"
#include "flags.hpp"
#include "scene_controls.hpp"
#include "../gameplay_world/world.hpp"
namespace reo::native::gameplay_scenario {
RoomRuleStatus apply_scenario_room_rules(gameplay_world::World& world,FlagState& flags,SceneControls& controls)noexcept{
    if(!world.scenario)return RoomRuleStatus::unavailable;
    if(*world.scenario!=2)return RoomRuleStatus::completed;
    if(world.room==0x1f&&flags.get(FlagBank::secondary,496).value_or(false)){
        const auto result=controls.disable_three();
        if(result.status!=ControlStatus::completed)return result.status==ControlStatus::budget_exhausted?RoomRuleStatus::budget_exhausted:RoomRuleStatus::unavailable;
    }
    if(world.room!=0x23)return RoomRuleStatus::completed;
    const auto primary=[&](unsigned id){return (flags.snapshot().primary[0][id/32]&(std::uint32_t(1)<<(id%32)))!=0;};
    const auto write=[&](unsigned id,bool value){return flags.actor_flag(ActorFlagFamily::primary,{false,0},id,value);};
    if(primary(111)&&!write(112,true))return RoomRuleStatus::unavailable;
    if(flags.get(FlagBank::scenario,298).value_or(false)){
        if(!write(113,true))return RoomRuleStatus::unavailable;
        if(primary(112)&&primary(113)&&!write(114,true))return RoomRuleStatus::unavailable;
    }else if(!write(113,false))return RoomRuleStatus::unavailable;
    if(!primary(111)&&!write(112,false))return RoomRuleStatus::unavailable;
    return RoomRuleStatus::completed;
}
}
