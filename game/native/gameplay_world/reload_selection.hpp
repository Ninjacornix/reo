#pragma once
#include "animation_events.hpp"
#include "../gameplay_scenario/scene_resources.hpp"
#include "../gameplay_scenario/resource_templates.hpp"
namespace reo::native::gameplay_world {
// Complete586220,586310 and586440 for the actual reload modes1/12.
// Reads the canonical inventory, descriptor and template tables directly.
std::uint8_t select_inventory_quantity(const Actor&,const gameplay_scenario::SceneResources&,
    std::uint8_t mode,std::uint16_t content);
std::uint8_t select_reload_source(const Actor&,const gameplay_scenario::SceneResources&,
    const gameplay_scenario::ResourceTemplates&,std::uint8_t resource,std::int16_t mode);
bool reload_available(const Actor&,const gameplay_scenario::SceneResources&,
    const gameplay_scenario::ResourceTemplates&,const animation_events::Metadata&,std::uint8_t resource);
}
