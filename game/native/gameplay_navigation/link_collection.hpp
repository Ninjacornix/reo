#pragma once
#include "local_routes.hpp"
namespace reo::native::gameplay_navigation {
struct RouteProjection {std::int8_t first{},second{};Position first_position,second_position;};
struct LinkCandidate {std::uint16_t link{};float cost{};std::optional<RouteProjection> projection;};
struct CollectionProfile {
    bool reverse{},omit_metadata{};
    // The source's initial cost scratch is not initialized. No invented zero:
    // callers must supply a known seed, or admit only paths that first write it.
    std::optional<float> initial_cost;
    std::size_t maximum_results{16}; // Explicit817470 caller profile.
};
enum class CollectionFailure {none,state,unknown_cost,capacity};
struct CollectionResult {
    QueryStatus status{QueryStatus::unavailable};CollectionFailure failure{CollectionFailure::state};
    std::array<LinkCandidate,16> candidates{};std::size_t count{};
    std::optional<float> last_cost;
    std::optional<std::size_t> unavailable_link;
    std::span<const LinkCandidate> values()const noexcept{return std::span(candidates).first(count);}
};
// Complete8179F0 within bounded known-cost/valid-record profiles. Both directions
// use local policy1. The visit mask is borrowed from the actual bank or an owned
// search snapshot. Unavailable results retain a diagnostic, unsorted prefix.
CollectionResult collect_links(const Bank&,std::uint32_t room,std::int32_t variant,std::int32_t node,
    ActorFacts,std::uint32_t actor_status,std::optional<std::uint16_t> room_flags,
    std::span<const std::uint8_t> visits,CollectionProfile={})noexcept;
}
