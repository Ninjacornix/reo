#include "enemy_initialization.hpp"

namespace reo::native::gameplay_world {
namespace {
#include "enemy_priority_profiles.inc"
}

bool initialize_enemy_priorities(World& world, const actors::EntityId& id) noexcept {
    const auto actor = world.resolve(id);
    if (!actor) return false;
    const auto mode = std::uint8_t(actor->auxiliary_status);
    if (mode > 2) return true;
    const auto priority = world.session().enemy_descriptors.records()[actor->character].route_seed;
    if (priority >= 8) return false;
    const auto& row = enemy_priorities[8u*mode+priority];
    const bool skip_marker = mode == 1 && row[0] == 4;
    const unsigned first = skip_marker ? 1 : 0;
    if (skip_marker) actor->auxiliary_status = (actor->auxiliary_status&0xffffff00u)|2u;
    actor->gauge_modifier_one = std::uint16_t(row[first]|std::uint16_t(row[first+1])<<8);
    actor->gauge_modifier_two = std::uint16_t(row[first+2]|std::uint16_t(row[first+3])<<8);
    return true;
}
}
