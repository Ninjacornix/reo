#pragma once
#include "../gameplay_world/world.hpp"
#include <bit>

namespace reo::native::gameplay_scenario {
inline bool actor_forced_policy_ready(const gameplay_world::World& world,std::uint32_t selector)noexcept{
    if(world.closed()||selector>=gameplay_world::World::primary_capacity)return false;
    const auto actor=world.primary(selector);
    return !actor||!actor->active||!actor->ai_control||actor->ai_execution.has_value();
}
// Complete702AD0/702BC0. The physical selector has no selected-actor alias.
//702AD0 stores a word at10A0; its sole reached consumer812540 reads LHU10A0,
// represented by the canonical typed content ID rather than an unused high half.
inline bool set_actor_forced_policy(gameplay_world::World& world,std::uint32_t selector,
    std::uint32_t content,std::uint32_t mode,bool clear)noexcept{
    if(!actor_forced_policy_ready(world,selector))return false;
    const auto actor=world.primary(selector);if(!actor||!actor->active||!actor->ai_control)return true;
    auto& state=*actor->ai_execution;
    state.forced_content=clear?0:std::uint16_t(content);
    state.forced_priority=clear?-1:mode==0?4:mode==1?2:mode==2?0:mode==3?1:-1;
    gameplay_ai::set_goal(state,0);gameplay_ai::set_action(state,0);return true;
}
inline bool actor_destination_policy_ready(const gameplay_world::World& world,std::uint32_t room,std::uint32_t variant,std::uint32_t policy)noexcept{
    if(world.closed())return false;
    if(std::bit_cast<std::int32_t>(policy)>=4)return true;
    const auto bank=world.navigation_if_created();
    if(!bank||!bank->descriptor_policy(std::bit_cast<std::int32_t>(room),std::bit_cast<std::int32_t>(variant)))return false;
    for(std::size_t i=0;i<gameplay_world::World::primary_capacity;++i){const auto actor=world.primary(i);
        if(actor&&actor->active&&actor->ai_control&&!actor->ai_execution)return false;}
    return true;
}
// Complete702620/816460. The signed>=4 gate precedes every graph/actor read.
// Negative selectors retain their full word; the eventual byte consumer owns
// bounded offset admission. First-descriptor write precedes physical AI resets.
inline bool set_actor_destination_policy(gameplay_world::World& world,std::uint32_t room,std::uint32_t variant,std::uint32_t policy)noexcept{
    if(!actor_destination_policy_ready(world,room,variant,policy))return false;
    if(std::bit_cast<std::int32_t>(policy)>=4)return true;
    if(!world.navigation().descriptor_policy(std::bit_cast<std::int32_t>(room),std::bit_cast<std::int32_t>(variant),policy))return false;
    for(std::size_t i=0;i<gameplay_world::World::primary_capacity;++i){const auto actor=world.primary(i);
        if(actor&&actor->active&&actor->ai_control){gameplay_ai::set_goal(*actor->ai_execution,0);gameplay_ai::set_action(*actor->ai_execution,0);}}
    return true;
}
inline bool actor_ai_inhibition_ready(const gameplay_world::World& world,std::uint32_t selector,std::uint32_t value)noexcept{
    if(world.closed()||selector>=gameplay_world::World::primary_capacity)return false;
    const auto actor=world.primary(selector);
    return value>1||!actor||!actor->active||!actor->ai_control||actor->ai_execution.has_value();
}
// Complete7029E0: direct physical selector (no selected-actor alias4). Unknown
// full-word values return without changing FF1; active/status filtering differs.
inline bool set_actor_ai_inhibition(gameplay_world::World& world,std::uint32_t selector,std::uint32_t value)noexcept{
    if(!actor_ai_inhibition_ready(world,selector,value))return false;
    const auto actor=world.primary(selector);
    if(value<=1&&actor&&actor->active&&actor->ai_control)actor->ai_execution->inhibited=std::uint8_t(value);
    return true;
}
// Physical primary traversal:702C50 never reads the authored population or
// selected actor. Missing generations represent inactive physical slots.
inline bool actor_ai_damage_policy_ready(const gameplay_world::World& world)noexcept{
    if(world.closed())return false;
    for(std::size_t i=0;i<gameplay_world::World::primary_capacity;++i){
        const auto actor=world.primary(i);
        if(actor&&actor->active&&actor->ai_control&&!actor->ai_execution)return false;
    }
    return true;
}
// Complete offline1A8/702C50. Only full-word1 and2 retain those values;
// every other word selects zero. Status-excluded active AI actors still change.
inline bool set_actor_ai_damage_policy(gameplay_world::World& world,std::uint32_t value)noexcept{
    if(!actor_ai_damage_policy_ready(world))return false;
    const std::uint8_t policy=value==2?2:value==1?1:0;
    for(std::size_t i=0;i<gameplay_world::World::primary_capacity;++i){
        const auto actor=world.primary(i);
        if(actor&&actor->active&&actor->ai_control)actor->ai_execution->action_damage_policy=policy;
    }
    return true;
}
}
