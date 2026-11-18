#pragma once
#include "primary_actor_initialization.hpp"
namespace reo::native::gameplay_world {
struct PrimaryCustomStatisticRow {
    std::uint16_t identity{};
    std::uint8_t classification{},health_band{},fraction_band{},gauge_rate{},multiplier_band{};
    float damage_scale{};
};
struct PrimarySubstitutionDefinition {std::uint16_t variant{};std::uint32_t hidden_parts{};};
std::span<const PrimaryCustomStatisticRow> file1_primary_custom_statistics()noexcept;
// Excludes the terminal record. The original two callers use different absent
// sentinels; an optional index keeps those policies out of this shared lookup.
std::optional<std::size_t> primary_custom_actor_index(std::uint16_t)noexcept;
const PrimarySubstitutionDefinition& primary_substitution_definition(std::uint16_t);
// Complete669860 on an admitted primary component and canonical RNG. This is
// a scalar policy called under the enclosing simulation owner's mutation guard.
// BB4==0 returns without requiring a component or reading RNG. Missing custom
// IDs use the actual table's terminal row; unknown metadata profiles refuse.
PrimaryInitializationStatus apply_primary_custom_statistics(Actor&,gameplay_session::Random&)noexcept;
}
