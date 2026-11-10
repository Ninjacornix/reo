#pragma once
#include "conditions.hpp"
#include "scene_candidates.hpp"
namespace reo::native::gameplay_navigation {
struct SceneLookupResult {
    QueryStatus status{QueryStatus::unavailable};
    std::optional<gameplay_scene::RecordId> record;
    std::size_t visited{};
};
// Complete819FF0/81A080: resolve applicability, then compare signed3F to index+1.
// A rejected condition resolves-1 and therefore searches for ordinal ZERO.
// No activation/geometry gate is added to these lookup helpers. Candidate IDs
// must still belong to the borrowed pool; stale/foreign identities refuse.
SceneLookupResult find_scene_candidate(const Bank&,ActorFacts,std::uint32_t room,std::int32_t condition,const gameplay_scene::Records&,const SceneCandidates&)noexcept;
SceneLookupResult find_global_scene_candidate(const Bank&,ActorFacts,std::uint32_t room,std::int32_t condition,const gameplay_scene::Records&)noexcept;
}
