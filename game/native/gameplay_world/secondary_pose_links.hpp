#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
struct SecondaryPoseLinkSelection {
    bool available{true};
    std::optional<std::uint8_t> profile{};
};
// Complete admitted61A6A0 selection. No profile means measured source no-work;
// unavailable means an index outside the owned table profile, not a no-op.
SecondaryPoseLinkSelection select_secondary_pose_links(const Actor&)noexcept;
enum class SecondaryPoseLinksStatus {unchanged,restored,unavailable,no_memory};
struct SecondaryPoseLinksRestored {
    SecondaryPoseLinksStatus status{SecondaryPoseLinksStatus::unavailable};
    std::optional<std::uint8_t> profile{};
    std::size_t patches{};
};
// Simulation-owner operation on the canonical Actor. The enclosing traversal
// validates identity/lifetime and must stop on unavailable. This only restores
// links;61A820's secondary chain solver/publication is a separate consumer.
SecondaryPoseLinksRestored restore_secondary_pose_links(Actor&)noexcept;
}
