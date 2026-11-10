#pragma once
#include "navigation.hpp"
#include "../gameplay_scene/records.hpp"
namespace reo::native::gameplay_navigation {
struct SceneCandidates {
    QueryStatus status{QueryStatus::unavailable};
    std::array<gameplay_scene::RecordId,128> records;
    std::size_t count{},visited{};
    Position sampled_position;
};
// Complete819DA0 over the canonical shared scene pool. Preserve newest-to-oldest
// traversal and the source pairwise priority sort that excludes the last item.
// Missing geometry/finite conversion refuses; unavailable is not an empty list.
SceneCandidates collect_scene_candidates(const gameplay_scene::Records&,Position actor,Position query,float radius)noexcept;
// Complete819BC0's reachable0/1 policy. The source1B4 is local collision center Z,
// NOT radius1B8. Motion1A uses actor position and does not consume that field.
SceneCandidates collect_actor_scene_candidates(const gameplay_scene::Records&,Position actor,std::uint8_t motion_class,std::uint16_t yaw,float local_center_z)noexcept;
}
