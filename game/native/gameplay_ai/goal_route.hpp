#pragma once
#include "execution.hpp"
#include "../gameplay_navigation/weighted_destination.hpp"
namespace reo::native::gameplay_world {struct Actor;}
namespace reo::native::gameplay_ai {
struct GoalRouteContext {
    std::uint16_t session_room;
    const gameplay_navigation::RoomFlags& flags;
};
// Complete8139C0, with reference ownership required only at its actual read.
std::optional<bool> route_goal_interrupted(const gameplay_world::Actor&,
    const gameplay_world::Actor* reference,std::uint32_t mask)noexcept;
// Complete bounded813DF0 goal1. Existing canonical route/AI state, shared RNG,
// descriptor policy and actual session room/flags retain their own owners.
Status update_route_goal(gameplay_world::Actor&,const gameplay_world::Actor* reference,
    gameplay_navigation::Bank&,gameplay_session::Random&,const GoalRouteContext*)noexcept;
}
