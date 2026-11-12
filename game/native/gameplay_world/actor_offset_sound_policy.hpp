#pragma once
#include "actor_sound_state.hpp"
#include "../gameplay_audio/routing.hpp"
#include <optional>
namespace reo::native::gameplay_world {
struct ActorOffsetSoundPlan {bool available{};std::optional<gameplay_audio::Request> request;};
// Actual1B9310 gate. Unknown metadata is distinct from a known silent actor.
ActorOffsetSoundPlan plan_actor_offset_sound(std::optional<ActorSoundState>,std::uint32_t event)noexcept;
}
