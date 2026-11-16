#pragma once
#include "destination.hpp"
#include "../gameplay_session/session.hpp"
namespace reo::native::gameplay_navigation {
// Complete bounded816530. Clears the actor's visits/occupancy before reading
// policy; failed later admission retains that prefix. Unknown graph views and
// encoded reads outside their owned graph are refused, never zero-filled.
NodeResult weighted_destination_node(Bank&,const RouteActorFacts&,const ActorRouteState&,std::int32_t excluded_node,
    std::uint32_t target_room,std::uint32_t mode,const RoomFlags&,gameplay_session::Random&)noexcept;
}
