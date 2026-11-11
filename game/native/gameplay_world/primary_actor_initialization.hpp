#pragma once
#include "humanoid_motion_assets.hpp"
namespace reo::native::gameplay_world {
struct PrimaryDefaultDefinition {
    std::int8_t motion_style{};std::uint8_t motion_subtype{};std::int16_t health{};
    Position scale;float height_correction{};
    std::array<gameplay_collision::hit_regions::Definition,4> hit_regions;
};
const PrimaryDefaultDefinition& primary_actor_default(std::uint8_t);
enum class PrimaryInitializationStatus {completed,unavailable,busy,closed,no_memory};
// Full fresh/default branch of66A750, after actual model loading. Explicitly
// excludes custom BB4 statistics and imported saved-state override profiles.
// Existing channels and unrelated actor fields are retained in source order.
PrimaryInitializationStatus initialize_primary_defaults(World&,actors::EntityId,
    std::uint8_t character,const HumanoidMotionBanks&)noexcept;
// Fresh initialization including the admitted File1 BB4 substitution profiles.
// Imported saved-state override remains a separate required caller contract.
PrimaryInitializationStatus initialize_primary_slot(World&,actors::EntityId,
    std::uint8_t character,const HumanoidMotionBanks&)noexcept;
// Complete restore branch for a caller that selected notification_pending!=0
// and paused==0. This operation consults the canonical exit request and pose.
PrimaryInitializationStatus restore_primary_slot(World&,actors::EntityId)noexcept;
// Complete663170 setter. Does not select an asset or invent model bindings.
bool select_primary_appearance(World&,actors::EntityId,std::uint8_t character,std::uint8_t model_class)noexcept;
}
