#pragma once
#include "flags.hpp"
#include "scene_resources.hpp"
#include "../gameplay_world/world.hpp"
#include <bit>
namespace reo::native::gameplay_scenario {
//692480 converts the full unsigned coordinate with the original signed
// conversion/half-and-double sequence, including values above INT32_MAX.
inline float script_coordinate_float(std::uint32_t value)noexcept{
    if(value<0x80000000u)return float(std::int32_t(value));
    return float(std::int32_t((value>>1)|(value&1u)))*2.0f;
}
inline std::shared_ptr<gameplay_world::Actor> script_anchor_actor(const gameplay_world::World& world,std::uint32_t selector)noexcept{
    if(world.closed())return{};
    return world.primary(selector==4?world.selected_actor:selector);
}
inline bool script_anchor_ready(const gameplay_world::World& world,std::uint32_t selector)noexcept{
    const auto actor=script_anchor_actor(world,selector);
    // With no pending AB8 request, writing ABC..ACB can establish its pose
    // without admitting any unproduced kind/parameter as an active request.
    return actor&&(!actor->transient_action||actor->interaction_request.has_value());
}
inline bool set_script_anchor(gameplay_world::World& world,std::uint32_t selector,
    std::uint32_t x,std::uint32_t y,std::uint32_t z,std::int16_t yaw)noexcept{
    if(!script_anchor_ready(world,selector))return false;
    const auto actor=script_anchor_actor(world,selector);
    if(!actor->interaction_request)actor->interaction_request.emplace();
    auto& request=*actor->interaction_request;
    request.anchor={script_coordinate_float(x),script_coordinate_float(y),script_coordinate_float(z)};
    request.orientation=std::uint32_t(std::int32_t(yaw));
    return true;
}
inline bool script_control_placement_ready(const gameplay_world::World& world,
    std::uint8_t selector,std::uint8_t command,std::uint8_t position)noexcept{
    const auto actor=script_anchor_actor(world,selector);if(!actor)return false;
    if(command==0xf0)return world.session().actor_placements.position(position).has_value()&&script_anchor_ready(world,selector);
    if(command==0xf1)return actor->interaction_request.has_value();
    return (selector==4?world.selected_actor:selector)<gameplay_world::ActorPlacements::request_count;
}
inline bool script_control_placement(gameplay_world::World& world,std::uint8_t selector,
    std::uint8_t command,std::uint8_t position,std::uint8_t kind)noexcept{
    if(!script_control_placement_ready(world,selector,command,position))return false;
    const auto actor=script_anchor_actor(world,selector);
    actor->transient_equipment=1;actor->control_request.kind=kind; //68F478/68F480, before placement.
    return gameplay_world::script_actor_placement(world,selector,command,position);
}
inline bool inventory_flag_ready(const gameplay_world::World& world,const SceneResources* resources)noexcept{
    if(world.closed()||world.selected_actor>=gameplay_world::World::primary_capacity)return false;
    const auto actor=world.primary(world.selected_actor);
    return !actor||!actor->active||actor->ai_control||resources;
}
inline bool update_inventory_flag(gameplay_world::World& world,const SceneResources* resources,
    FlagState& flags,std::uint16_t content,std::uint32_t flag)noexcept{
    if(!inventory_flag_ready(world,resources))return false;
    const auto actor=world.primary(world.selected_actor);
    if(!actor||!actor->active||actor->ai_control)return true; //694B0C..694B34, before5F2210.
    return flags.write(FlagBank::local_primary,flag,resources->find_inventory_content(actor->inventory,content)!=0);
}
}
