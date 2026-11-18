#pragma once
#include <cstdint>

namespace reo::native::gameplay_world { class World; }
namespace reo::native::gameplay_scenario {
class SceneResources;
class ResourceTemplates;

bool actor_inventory_population_ready(const gameplay_world::World&,bool full_count=false) noexcept;
bool grant_actor_resource(gameplay_world::World&, SceneResources&, const ResourceTemplates&,
                          std::int16_t actor, std::int16_t content, std::int16_t quantity) noexcept;
bool grant_character_resource(gameplay_world::World&, SceneResources&, const ResourceTemplates&,
                              std::int8_t character, std::int16_t content, std::int16_t quantity) noexcept;
bool grant_special_inventory(gameplay_world::World&, SceneResources&, const ResourceTemplates&,
                             std::uint16_t content, std::int32_t quantity) noexcept;
}
