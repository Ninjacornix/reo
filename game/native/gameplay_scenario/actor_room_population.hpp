#pragma once
#include "actor_script_commands.hpp"
namespace reo::native::gameplay_scenario {
// Complete693430 uses a signed population loop. Positive loops require actual
// canonical physical records; an absent generation does not prove exclusion.
inline bool actor_population_rooms_ready(const gameplay_world::World& world)noexcept{
    const auto count=world.session().primary_population;
    if(world.closed()||!count)return false;
    const auto signed_count=std::bit_cast<std::int32_t>(*count);
    if(signed_count>std::int32_t(gameplay_world::World::primary_capacity))return false;
    for(std::int32_t i=0;i<signed_count;++i)if(!world.primary(std::uint32_t(i)))return false;
    return true;
}
inline std::optional<bool> actor_population_rooms_match(const gameplay_world::World& world,
    std::uint16_t room,std::uint32_t mode)noexcept{
    if(!actor_population_rooms_ready(world))return{};
    const auto count=std::bit_cast<std::int32_t>(*world.session().primary_population);bool any{};
    for(std::int32_t i=0;i<count;++i){const auto actor=world.primary(std::uint32_t(i));
        if(!actor->active||(actor->status&0x5e0u))continue;
        any=true;if((actor->room==room)!=(mode!=0))return false;
    }
    return any;
}
// Complete6936B0 reads each physical room BEFORE the exclusion predicate, so
// even inactive slots require their canonical room record. The -1 shortcut
// reads only the full population word and bypasses the loop/count transform.
inline bool actor_room_population_ready(const gameplay_world::World& world,std::uint32_t room)noexcept{
    const auto count=world.session().primary_population;if(world.closed()||!count)return false;
    if(room==UINT32_MAX)return true;
    if(*count>gameplay_world::World::primary_capacity)return false;
    for(std::uint32_t i=0;i<*count;++i)if(!world.primary(i))return false;
    return true;
}
inline std::optional<bool> actor_room_population_matches(const gameplay_world::World& world,
    std::uint32_t room,std::uint32_t threshold,std::uint32_t expected)noexcept{
    if(!actor_room_population_ready(world,room))return{};
    const auto population=*world.session().primary_population;bool matched{};
    if(room==UINT32_MAX)matched=threshold==population;
    else{
        const bool excluded=threshold>=7;if(excluded)threshold-=6;
        if(threshold==6)threshold=population;
        std::uint32_t count{};
        for(std::uint32_t i=0;i<population;++i){const auto actor=world.primary(i);
            if(std::uint32_t(actor->room)!=room)continue;
            const bool inactive=!actor->active||(actor->status&0x5e0u);
            if(inactive==excluded)++count;
        }
        matched=threshold==5?count!=0:count==threshold;
    }
    // Other full-word expectation values return0 without the failure scan.
    return expected==1?matched:expected==0?!matched:true;
}
}
