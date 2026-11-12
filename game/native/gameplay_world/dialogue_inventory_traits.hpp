#pragma once
#include "world.hpp"
#include "../gameplay_scenario/scene_resources.hpp"
#include "../gameplay_scenario/resource_templates.hpp"
namespace reo::native::gameplay_world {
// Complete5B5350 over the canonical actor inventory and resource metadata.
// No mutation, mirror records or implicit metadata capabilities.
std::optional<bool> dialogue_inventory_trait(const Actor&,
    const gameplay_scenario::SceneResources*,const gameplay_scenario::ResourceTemplates*,
    std::uint32_t selector)noexcept;
}
