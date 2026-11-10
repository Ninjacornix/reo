#pragma once
#include "routes.hpp"
namespace reo::native::gameplay_navigation {
struct CostRouteResult {
    QueryStatus status{QueryStatus::unavailable};std::int8_t selected{-1};
    bool budget_exhausted{};std::size_t considered_edges{};
    bool cost_written{};
    bool used_graph_solver{};
    std::size_t graph_vertex_scans{},graph_admission_checks{};
};
// Complete818B70/818E30 within a bounded work admission profile. Exhaustion
// returns unavailable without committing an approximate route. This policy
// ignores actor occupancy and preserves the original10000 sentinel/early exits.
// Known graphs use a fixed-array solver when the edge budget admits16*N+28
// inspections, with at most2*N*N independent vertex scans. Tiny budgets and
// unknown-graph preparation retain bounded enumeration; no-path is not inferred
// from an unknown predicate. Work includes graph preparation before fallback.
CostRouteResult bounded_cost_route(const Bank&,std::uint32_t room,std::int32_t source,std::int32_t destination,
    ActorFacts,std::uint32_t actor_status,std::optional<std::uint16_t> room_flags,RouteOutput&,std::size_t maximum_edges=65536)noexcept;
// Native bounded enumeration retained for unknown-graph fallback and independent
// comparison admission. It uses the same canonical Bank, not a guest runtime.
CostRouteResult enumerated_cost_route(const Bank&,std::uint32_t room,std::int32_t source,std::int32_t destination,
    ActorFacts,std::uint32_t actor_status,std::optional<std::uint16_t> room_flags,RouteOutput&,std::size_t maximum_edges=65536)noexcept;
}
