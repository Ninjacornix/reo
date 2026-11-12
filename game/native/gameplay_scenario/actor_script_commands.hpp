#pragma once
#include "../gameplay_world/world.hpp"
#include <bit>

namespace reo::native::gameplay_scenario {
inline bool actor_room_query_ready(const gameplay_world::World& world,std::uint32_t selector)noexcept{
    return !world.closed()&&(selector==4?world.selected_actor:selector)<gameplay_world::World::primary_capacity;
}
// Complete693300 with complete666080 admission. Missing native generations are
// inactive physical primary slots. The negative condition includes inactive or
// status-excluded actors; inversion applies to the complete admitted match.
inline std::optional<bool> actor_room_matches(const gameplay_world::World& world,
    std::uint32_t selector,std::uint16_t room,bool equal)noexcept{
    if(!actor_room_query_ready(world,selector))return{};
    const auto actor=world.primary(selector==4?world.selected_actor:selector);
    return bool(actor&&actor->active&&!(actor->status&0x5e0u)&&actor->room==room)==equal;
}
inline bool actor_weight_profile_ready(const gameplay_world::World& world,
    std::uint32_t mode,std::uint32_t selector,std::int32_t profile)noexcept{
    if(world.closed())return false;
    const auto admitted=[&](const std::shared_ptr<gameplay_world::Actor>& actor){
        return !actor||!actor->active||!actor->ai_control||profile>=20||
               (profile>=0&&actor->ai_execution.has_value());
    };
    if(!mode)return selector<gameplay_world::World::primary_capacity&&admitted(world.primary(selector));
    const auto count=world.session().primary_population;
    if(!count||*count>gameplay_world::World::primary_capacity)return false;
    for(std::uint32_t i=0;i<*count;++i){const auto actor=world.primary(i);
        if(actor&&actor->character==selector&&!admitted(actor))return false;
    }
    return true;
}
// Complete offline702650. Direct slots deliberately do not use selected alias4;
// every nonzero mode scans the full unsigned authored primary population.
// Actual8123E0 is the shared native AI execution primitive, never a query port.
inline bool set_actor_weight_profile(gameplay_world::World& world,
    std::uint32_t mode,std::uint32_t selector,std::int32_t profile)noexcept{
    if(!actor_weight_profile_ready(world,mode,selector,profile))return false;
    const auto apply=[&](const std::shared_ptr<gameplay_world::Actor>& actor){
        if(actor&&actor->active&&actor->ai_control&&profile<20)
            (void)gameplay_ai::select_weight_profile(*actor->ai_execution,profile);
    };
    if(!mode)apply(world.primary(selector));
    else for(std::uint32_t i=0;i<*world.session().primary_population;++i){const auto actor=world.primary(i);
        if(actor&&actor->character==selector)apply(actor);
    }
    return true;
}
}
