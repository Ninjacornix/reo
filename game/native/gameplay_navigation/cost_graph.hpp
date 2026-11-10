#pragma once
#include "routes.hpp"
namespace reo::native::gameplay_navigation {
struct GraphCostResult {
    QueryStatus status{QueryStatus::unavailable};std::int8_t selected{-1};bool cost_written{};
    std::size_t admission_checks{},relaxations{},vertex_scans{},construction_checks{},selection_checks{};
};
// Bounded graph formulation of818B70/818E30. It requires every graph
// edge predicate to be known for this immutable query snapshot; otherwise it
// refuses without output writes. The cost API selects it only within its work
// budget. Standalone invocation does not establish live-game admission.
GraphCostResult graph_cost_route(const Bank&,std::uint32_t room,std::int32_t source,std::int32_t destination,
    ActorFacts,std::uint32_t actor_status,std::optional<std::uint16_t> room_flags,RouteOutput&)noexcept;
}
