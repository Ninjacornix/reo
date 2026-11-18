#pragma once
#include "cost_routes.hpp"
namespace reo::native::gameplay_navigation {
// Complete817DB0 bounded profile. Policy0/1 selects the ranked variants; every
// other32-bit value selects cost search. A denied target-link node condition
// returns completed/-1 before writing route or link outputs. Later failures
// retain their original known output prefix.
CostRouteResult local_route(const Bank&,std::uint32_t room,std::int32_t source,std::int32_t destination,
    ActorFacts,std::uint32_t actor_status,std::optional<std::uint16_t> room_flags,std::uint32_t policy,
    RouteOutput&,std::int16_t& destination_link,std::size_t maximum_edges=65536)noexcept;
}
