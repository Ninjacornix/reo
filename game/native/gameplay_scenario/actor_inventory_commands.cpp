#include "actor_inventory_commands.hpp"
#include "inventory_compaction.hpp"
#include "resource_templates.hpp"
#include "scene_resources.hpp"
#include "../gameplay_world/world.hpp"
#include <algorithm>
#include <bit>
#include <span>
#include <utility>

namespace reo::native::gameplay_scenario {
namespace {
using gameplay_world::Actor;
using gameplay_world::World;

std::int8_t population(const World& world) noexcept {
    return std::bit_cast<std::int8_t>(std::uint8_t(world.session().primary_population.value_or(0)));
}
std::int32_t full_population(const World& world) noexcept {
    return std::bit_cast<std::int32_t>(world.session().primary_population.value_or(0));
}

bool insert_first(Actor& actor, std::int16_t content, std::uint8_t resource) noexcept {
    const auto slots = content >= 400 && content <= 420 ?
        std::span<std::uint8_t>(actor.inventory.storage) : std::span<std::uint8_t>(actor.inventory.carried);
    const auto vacant = std::find(slots.begin(), slots.end(), 0);
    if (vacant == slots.end()) return false;
    *vacant = resource;
    return true;
}
}

bool actor_inventory_population_ready(const gameplay_world::World& world,bool full_count) noexcept {
    return !world.closed() && world.session().primary_population &&
        (full_count ? full_population(world) : population(world)) <= std::int32_t(World::primary_capacity);
}

bool grant_actor_resource(World& world,SceneResources& resources,const ResourceTemplates& templates,
                          std::int16_t index,std::int16_t content,std::int16_t quantity) noexcept {
    if (!actor_inventory_population_ready(world)) return false;
    if (index < 0 || content < 0) return true;
    const auto allocation = resources.allocate_owned(std::uint16_t(index),std::uint16_t(content),quantity,templates);
    if (allocation.status != SceneStatus::completed) return allocation.status == SceneStatus::full;
    if (index < population(world)) {
        const auto actor = world.primary(std::uint16_t(index));
        if (actor && actor->active) (void)insert_first(*actor,content,allocation.slot);
    }
    return true;
}

bool grant_character_resource(World& world,SceneResources& resources,const ResourceTemplates& templates,
                              std::int8_t character,std::int16_t content,std::int16_t quantity) noexcept {
    if (!actor_inventory_population_ready(world)) return false;
    if (character < 0 || content < 0) return true;
    const auto count = population(world);
    for (std::int16_t i = 0; i < count; ++i) {
        const auto actor = world.primary(std::uint16_t(i));
        if (!actor || !actor->active || actor->character != std::uint8_t(character)) continue;
        const auto allocation = resources.allocate_owned(std::uint16_t(i),std::uint16_t(content),quantity,templates);
        if (allocation.status != SceneStatus::completed) return allocation.status == SceneStatus::full;
        if (insert_first(*actor,content,allocation.slot)) break;
    }
    return true;
}

bool grant_special_inventory(World& world,SceneResources& resources,const ResourceTemplates& templates,
                             std::uint16_t content,std::int32_t quantity) noexcept {
    if (!actor_inventory_population_ready(world,true)) return false;
    if (quantity <= 0 || content < 300 || content > 302) return true;
    const auto population = full_population(world);
    for (std::int32_t i = 0; i < population; ++i) {
        const auto actor = world.primary(std::uint16_t(i));
        if (!actor || !actor->active || actor->character != 7) continue;
        bool has_required_item = false;
        std::uint32_t matching = 0;
        for (const auto id : actor->inventory.storage) {
            if (!id) continue;
            const auto item = resources.get(*resources.slot(id));
            if (!item) return false;
            if (item->attachment_id == 413) has_required_item = true;
            else if (item->attachment_id == content) ++matching;
        }
        if (!has_required_item || matching >= 3) return true;
        const auto total = std::bit_cast<std::int32_t>(std::uint32_t(quantity) + matching);
        const auto grants = total < 4 ? quantity : 3 - std::int32_t(matching);
        for (std::int32_t n = 0; n < grants; ++n) {
            const auto allocation = resources.allocate_owned(std::uint16_t(i),content,1,templates);
            if (allocation.status != SceneStatus::completed) return allocation.status == SceneStatus::full;
            auto storage = std::span<std::uint8_t>(actor->inventory.storage);
            auto bucket = storage.subspan(1 + 9 * (content - 300),9);
            const auto slot = std::find(bucket.begin(),bucket.end(),0);
            if (slot == bucket.end()) return false;
            *slot = allocation.slot;
            try { compact_inventory(actor->inventory,actor->character,resources,templates); }
            catch (const std::exception&) { return false; }
        }
        break;
    }
    return true;
}
}
