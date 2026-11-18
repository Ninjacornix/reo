#pragma once
#include "../gameplay_world/world.hpp"
#include <bit>
namespace reo::native::gameplay_scenario {
// Complete68F180 visits physical records without an active-actor predicate.
// Its LW/SLT population comparison is signed; negative words perform no writes.
inline bool actor_model_classes_ready(const gameplay_world::World& world)noexcept{
    if(world.closed()||!world.session().primary_population)return false;
    const auto count=std::bit_cast<std::int32_t>(*world.session().primary_population);
    if(count<=0)return true;
    if(count>std::int32_t(gameplay_world::World::primary_capacity))return false;
    for(std::int32_t i=0;i<count;++i)if(!world.primary(std::uint32_t(i)))return false;
    return true;
}
inline bool set_actor_model_classes(gameplay_world::World& world,std::uint8_t value)noexcept{
    if(!actor_model_classes_ready(world))return false;
    const auto count=std::bit_cast<std::int32_t>(*world.session().primary_population);
    for(std::int32_t i=0;i<count;++i)world.primary(std::uint32_t(i))->model_pose_class=value;
    return true;
}
}
