#pragma once
#include "world.hpp"
#include "../gameplay_collision/response.hpp"
namespace reo::native::gameplay_world {
enum class SurfaceTransitionStatus {unchanged,applied,unavailable};
// Complete6660B0 policy once616F20 has returned the new surface type.
// The caller supplies the actual CE2 owner; absence is not a zero notice byte.
SurfaceTransitionStatus apply_surface_transition(Actor&,std::uint8_t new_type,std::optional<std::uint8_t>& transition_flags)noexcept;
// The actual room floor adapter samples positionY+50 only after source gates.
SurfaceTransitionStatus update_surface_transition(Actor&,const gameplay_collision::response::Grid&,std::optional<std::uint8_t>& transition_flags)noexcept;
}
