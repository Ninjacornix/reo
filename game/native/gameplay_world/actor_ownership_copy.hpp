#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
enum class ActorCopyStatus {completed,inconsistent_model,no_memory,unavailable};
struct ActorCopied {ActorCopyStatus status{ActorCopyStatus::unavailable};std::unique_ptr<Actor> actor;};
// Serialized simulation-owner capture, without World registration or identity
// transfer. Value components/EntityId references copy as values. Mutable model,
// playback and constraint owners are copied independently; internal aliases are
// preserved. Authored assets/programs/banks remain immutable shared resources.
// Scene-specific stores, model-cache/slot handoff and retirement belong to the
// enclosing scene owner, not this general ownership snapshot operation.
ActorCopied copy_actor_owned(const Actor&)noexcept;
}
