#pragma once
#include "routes.hpp"
namespace reo::native::gameplay_navigation {
struct CostRouteResult {
    QueryStatus status{QueryStatus::unavailable};std::int8_t selected{-1};
    bool budget_exhausted{};std::size_t considered_edges{};
};
// Complete818B70/818E30 within a bounded work admission profile. Exhaustion
// returns unavailable without committing an approximate route. This policy
// ignores actor occupancy and preserves the original10000 sentinel/early exits.
CostRouteResult bounded_cost_route(const Bank&,std::uint32_t room,std::int32_t source,std::int32_t destination,
    ActorFacts,std::uint32_t actor_status,std::optional<std::uint16_t> room_flags,RouteOutput&,std::size_t maximum_edges=65536)noexcept;
}
