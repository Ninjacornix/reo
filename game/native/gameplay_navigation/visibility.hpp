#pragma once
#include "navigation.hpp"
#include "destination.hpp"
#include "../gameplay_collision/trace.hpp"
namespace reo::native::gameplay_navigation {
// Borrowed synchronous view of the existing scene collision owner. Geometry,
// dynamic triangles and disabled/type-slot flags retain their canonical owner.
struct VisibilityRoom {
    const gameplay_collision::response::Grid& walls;
    gameplay_collision::response::Filter filter;
    std::span<const gameplay_collision::response::Triangle> dynamic;
};
struct VisibilityResult {QueryStatus status{QueryStatus::unavailable};bool blocked{};std::optional<std::uint16_t> hit_kind;};
// Complete bounded81A340. Source origin rises10; destination Y is origin+20,
// independent of the target's Y. First hit/type classification is retained.
VisibilityResult navigation_visibility(const VisibilityRoom&,Position from,Position to)noexcept;
// Complete8171E0 flags1/8171C0 within finite, fully sampled scene geometry.
// Pairwise sorting and its last-swap fallback when every candidate blocks are
// source behavior, rather than a generic nearest-visible-node policy.
NodeResult nearest_visible_node(const RoomGraph&,Position,std::int8_t group,const VisibilityRoom&)noexcept;
bool node_selection_prefers_unfiltered(std::uint8_t motion_class,std::uint32_t status,std::uint32_t auxiliary_status)noexcept;
// Complete bounded815BC0/813BD0. Unknown unfiltered empty queries stay
// unavailable; no source stack value is fabricated for that fallback.
NodeResult choose_actor_node(const Bank&,const RouteActorFacts&,std::uint32_t policy,
    const VisibilityRoom&,ActorRouteState&)noexcept;
}
