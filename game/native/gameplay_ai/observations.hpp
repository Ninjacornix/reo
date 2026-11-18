#pragma once
#include "execution.hpp"
#include "../gameplay_navigation/scene_candidates.hpp"
namespace reo::native::gameplay_ai {
struct ObservationUpdated {
    Status status{Status::unavailable};
    gameplay_navigation::SceneCandidates scene_candidates;
    bool wall_probe{}, wall_hit{}, goal_and_action_reset{};
    std::optional<std::uint8_t> scheduled_event;
    std::size_t targets_examined{};
};
} // namespace reo::native::gameplay_ai
