#pragma once
#include "world.hpp"
#include "secondary_pose_state.hpp"
namespace reo::native::gameplay_world {
enum class SecondaryPoseStatus {unchanged,applied,unavailable,no_memory};
struct SecondaryPoseSelection {bool available{true};bool contacts{};std::optional<std::uint8_t> profile;};
// Complete61A820 admission and table selection. FAC is consumed only by
// mode1 while unpaused; an absent required producer remains unavailable.
SecondaryPoseSelection select_secondary_pose_dynamics(const Actor&,std::int16_t mode,std::int8_t paused)noexcept;
//61A620's admitted history reset, called by the actual actor constructors.
void reset_secondary_pose_history(Actor&)noexcept;
// Complete61AAA0 for all four owned descriptor rows. No guessed history.
SecondaryPoseStatus apply_secondary_pose_dynamics(Actor&,std::uint8_t profile)noexcept;
//61A820 order: capsule contacts, dynamics, then61B1A0 topology publication.
SecondaryPoseStatus update_secondary_pose(Actor&,std::int16_t mode,std::int8_t paused)noexcept;
}
