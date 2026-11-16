#pragma once
#include "flags.hpp"
#include "../gameplay_world/world.hpp"
#include <bit>
namespace reo::native::gameplay_scenario {
struct ScenarioEnemyRelocationPlan {
    bool ready{};
    std::uint8_t room{};
    std::optional<std::uint16_t> descriptor;
    std::shared_ptr<gameplay_world::Actor> wake;
};
// Complete6946B0 reads the signed low population byte, uses two canonical
// class/room route banks, then counts eligible family27 descriptors. Native
// admission bounds physical actor records and the source36-byte scratch array.
inline ScenarioEnemyRelocationPlan scenario_enemy_relocation_plan(const gameplay_world::World& world,
    const FlagState* flags,std::uint8_t condition)noexcept{
    ScenarioEnemyRelocationPlan plan;
    const auto& session=world.session();
    if(world.closed()||!session.scenario)return plan;
    if(*session.scenario!=28){plan.ready=true;return plan;}
    if(!session.primary_population)return plan;
    const auto count=std::bit_cast<std::int8_t>(std::uint8_t(*session.primary_population));
    if(count>std::int32_t(gameplay_world::World::primary_capacity))return plan;
    for(std::int32_t i=0;i<count;++i)if(!world.primary(std::uint32_t(i)))return plan;
    for(std::int32_t i=0;i<count;++i){
        const auto actor=world.primary(std::uint32_t(i));
        if(!actor->active||(actor->status&0x5e0u))continue;
        const auto& routes=session.enemy_routes;
        const auto group=routes.classes[0]==27?0:routes.classes[1]==27?1:2;
        if(group==2)continue;
        if(actor->room>=routes.room_banks[0].size())return plan;
        if(!routes.room_banks[std::size_t(group)][actor->room])continue;
        plan.room=std::uint8_t(actor->room);break; // The first qualifying room0 also stops the scan.
    }
    if(!plan.room){plan.ready=true;return plan;}
    if(plan.room>=36||!flags)return plan;
    std::array<std::uint8_t,36> counts{};
    const auto records=session.enemy_descriptors.records();
    const auto enemies=session.enemy_descriptors.count();
    for(unsigned i=0;i<enemies;++i){
        const auto& descriptor=records[i];
        if(descriptor.family!=27||!flags->snapshot().scene_record_eligibility.get(descriptor.condition).value_or(false))continue;
        if(descriptor.room>=counts.size()||descriptor.condition==condition)continue;
        counts[descriptor.room]=std::uint8_t(counts[descriptor.room]+1u);
    }
    // The original increments through LB/SB and tests LB<2, including wrap.
    if(std::bit_cast<std::int8_t>(counts[plan.room])>=2){plan.ready=true;return plan;}
    for(unsigned i=0;i<enemies;++i)if(records[i].condition==condition&&records[i].family==27){plan.descriptor=std::uint16_t(i);break;}
    const auto character=std::int32_t(condition)-16;
    for(std::int32_t i=0;i<count;++i){
        const auto actor=world.primary(std::uint32_t(i));
        if(!actor->active||!(actor->status&0x5e0u)||std::int32_t(actor->character)!=character)continue;
        plan.wake=actor;break;
    }
    plan.ready=true;return plan;
}
inline bool relocate_scenario_enemy(gameplay_world::World& world,const FlagState* flags,std::uint8_t condition)noexcept{
    const auto plan=scenario_enemy_relocation_plan(world,flags,condition);if(!plan.ready)return false;
    if(plan.descriptor){auto* descriptor=world.session().enemy_descriptors.record(*plan.descriptor);
        descriptor->room=plan.room;descriptor->parameter20=5;}
    if(plan.wake)plan.wake->status|=0x1000u;
    return true;
}
}
