#pragma once
#include "link_collection.hpp"
namespace reo::native::gameplay_navigation {
using RoomFlags = std::array<std::optional<std::uint16_t>,128>;
struct CrossRoomProfile {
    // Explicit deterministic correction for the source's unspecified initial
    // collector cost. Off by default; never called an original observed zero.
    bool initialize_collection_cost{};
    std::size_t maximum_calls{4096},maximum_depth{128};
};
enum class CrossRoomFailure {none,state,collection,work_budget,depth_budget};
struct CrossRoomResult {
    QueryStatus status{QueryStatus::unavailable};std::int32_t selected{-1};
    CrossRoomFailure failure{CrossRoomFailure::state};
    CollectionFailure collection_failure{CollectionFailure::none};
    std::size_t calls{},depth{};
};
struct CrossRoomOutput {RouteProjection route;std::int16_t link{-1};};
// Complete bounded817820. selected is the source's candidate ordinal, including
// its last-recursion-result behavior. The borrowed search mask retains the
// measured write prefix, including on unavailable results; no visit rollback.
CrossRoomResult search_link_path(const Bank&,ActorFacts,std::uint32_t actor_status,
    const RoomFlags&,std::int32_t entry_link,std::int32_t destination_link,
    std::span<std::uint8_t> visits,CrossRoomProfile={})noexcept;
// Complete bounded817470. Uses the Bank's actual actor mask; recursive attempts
// get independent snapshots. Output writes and persistent visit publication
// occur in source order. Early status/empty-collection denial leaves outputs.
CrossRoomResult cross_room_route(Bank&,ActorFacts,std::uint32_t actor_status,const RoomFlags&,
    std::uint32_t source_room,std::uint32_t destination_room,std::int32_t source_node,
    std::int32_t destination_node,CrossRoomOutput&,CrossRoomProfile={})noexcept;
}
