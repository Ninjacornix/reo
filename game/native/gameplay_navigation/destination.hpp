#pragma once
#include "actor_routes.hpp"
namespace reo::native::gameplay_navigation {
// Ephemeral values from the actual Actor, never another persistent owner.
struct RouteActorFacts {
    ActorFacts identity;std::uint32_t status{},auxiliary_status{};
    std::uint16_t room{};Position position;
    std::uint8_t motion_class{},transient_marker{};
};
// Complete bounded816890. Retains the already-written destination, visits,
// route/action and normalization prefix if later evidence is unavailable.
CrossRoomResult begin_actor_route(Bank&,const RouteActorFacts&,std::uint16_t session_room,
    const RoomFlags&,ActorRouteState&,Position destination,std::uint16_t destination_room,
    CrossRoomProfile={})noexcept;
}
