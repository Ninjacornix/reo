#pragma once
#include "flags.hpp"
#include "../gameplay_world/world.hpp"

namespace reo::native::gameplay_scenario {
// Complete admitted693920 predicate. The count is the full unsigned authored
// population; inactive actors still own slot/character/style/flag-tag fields.
inline std::optional<bool> actor_condition_matches(const gameplay_world::World& world,
    const FlagState* flags,std::uint32_t mode,std::uint32_t selector,
    std::uint32_t query,std::uint32_t parameter,std::uint32_t expected)noexcept{
    if(world.closed()||!world.session().primary_population||
       *world.session().primary_population>gameplay_world::World::primary_capacity)return{};
    const auto count=*world.session().primary_population;
    std::shared_ptr<gameplay_world::Actor> actor;
    if(!mode){
        const auto slot=selector==4?world.selected_actor:selector;
        if(slot>=gameplay_world::World::primary_capacity)return{};
        if(slot>=count)return false;
        actor=world.primary(slot);if(!actor)return{};
    }else if(mode==1){
        for(std::uint32_t i=0;i<count;++i){const auto candidate=world.primary(i);
            if(!candidate)return{};
            if(candidate->character==selector){actor=candidate;break;}
        }
        if(!actor)return false;
    }else return false;
    const bool excluded=!actor->active||(actor->status&0x5e0u)!=0;
    bool result{};
    switch(query){
    case 0:result=(parameter&0x80000000u)?
        ((parameter&15u)&(1u<<(actor->slot&31u)))!=0:actor->slot==parameter;break;
    case 1:result=(parameter&0x80000000u)?
        ((parameter&255u)&(1u<<(actor->character&31u)))!=0:actor->character==parameter;break;
    case 2:result=actor->motion_style==parameter;break;
    case 3:result=excluded||(parameter==1&&(actor->status&8u)!=0);break;
    case 4:result=!excluded&&actor->room==parameter;break;
    case 5:{
        if(!flags)return{};
        const auto owner=flags->scenario_owner(parameter);if(!owner)return{};
        result=*owner==std::uint32_t(actor->slot)+1u;break;
    }
    case 6:result=(actor->status&(world.mode==0?0x20u:0x100u))!=0;break;
    case 7:result=world.mode==0&&actor->ai_control!=0;break;
    default:break; // Unknown query retains the source's zero result for comparison.
    }
    // The fifth argument compares the full word, not its boolean or low byte.
    return std::uint32_t(result)==expected;
}
inline bool actor_ai_counter_ready(const gameplay_world::World& world)noexcept{
    if(world.closed())return false;
    for(std::size_t i=0;i<gameplay_world::World::primary_capacity;++i){const auto actor=world.primary(i);
        if(actor&&actor->active&&actor->ai_control&&!actor->ai_execution)return false;
    }
    return true;
}
// Complete offline702A60. This is always eight physical slots, independent of
// the authored population, and only full-word1 selects the stored one value.
inline bool set_actor_ai_counter(gameplay_world::World& world,std::uint32_t value)noexcept{
    if(!actor_ai_counter_ready(world))return false;
    for(std::size_t i=0;i<gameplay_world::World::primary_capacity;++i){const auto actor=world.primary(i);
        if(actor&&actor->active&&actor->ai_control)actor->ai_execution->action_counter=value==1?1u:0u;
    }
    return true;
}
}
