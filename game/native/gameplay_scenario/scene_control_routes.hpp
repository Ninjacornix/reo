#pragma once
#include "scene_controls.hpp"
#include "../gameplay_collision/contact_routes.hpp"
namespace reo::native::gameplay_scenario {
// Retains the canonical scene owner and selected identity. Native route effects
// belong to the collision/session owners supplied by the actual caller.
gameplay_collision::delivery::RouteLookup lookup_scene_route(std::shared_ptr<SceneControls>,std::uint8_t edge)noexcept;
}
