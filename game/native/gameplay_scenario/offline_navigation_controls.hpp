#pragma once
#include "scene_controls.hpp"
#include "../gameplay_world/world.hpp"
namespace reo::native::gameplay_scenario {
// Complete7012C0/701550 after the offline dispatch relation gate. Current-room
// controls commit before SGL conditions. The canonical disabled/freecount128
// gate returns before any Bank read; relation2 does not read controls at all.
inline bool apply_offline_navigation_control(gameplay_world::World* world,SceneControls* controls,
    std::uint16_t room,std::uint32_t relation,bool enable,std::uint32_t authored,std::uint16_t parameter)noexcept{
    if(relation==0){
        if(!controls)return false;
        if(!controls->enabled())return true; //source3B5150==128 whole-handler exit
        const auto result=controls->apply(enable?ControlCommand::enable_odd:ControlCommand::disable_even,
            {authored,parameter,0,0},nullptr);
        if(result.status!=ControlStatus::completed)return false;
    }
    if(!world||world->closed()||!world->navigation_if_created())return false;
    auto& bank=world->navigation();const auto count=bank.condition_count(room);if(!count)return false;
    if(!*count)return true;
    const auto graph=bank.room(room);if(!graph)return false;
    for(std::size_t i=0;i<*count;++i){const auto& condition=graph->conditions()[i];
        const auto mode=condition[3];
        if(condition[1]==3&&std::uint32_t(condition[2])==authored&&
            (enable?(mode==1||mode==3):(mode==0||mode==2)))
            if(!bank.condition_active(room,i,enable?1:0))return false;
    }
    return true;
}
}
