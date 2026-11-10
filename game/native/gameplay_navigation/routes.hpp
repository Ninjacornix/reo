#pragma once
#include "edges.hpp"
namespace reo::native::gameplay_navigation {
enum class RankedPolicy {four_candidates,first_candidate};
struct RouteOutput {
    std::int8_t first{},second{};
    Position first_position,second_position;
    float cost{};
};
struct RouteResult {QueryStatus status{QueryStatus::unavailable};std::int8_t selected{-1};};
// Complete818010/8185C0 with their distinct root candidate counts, and complete
// single-candidate recursive companions818390/818940. Output cost may retain a
// failed attempt's accumulated prefix, or remain untouched when none starts.
RouteResult ranked_route(const Bank&,std::uint32_t room,std::int32_t source,std::int32_t destination,
    ActorFacts,std::uint32_t actor_status,std::optional<std::uint16_t> room_flags,RankedPolicy,RouteOutput&)noexcept;
}
