#pragma once
#include "humanoid_motion_bindings.hpp"
#include <array>
#include <vector>
namespace reo::native::gameplay_world {
struct PrimaryActorState {
    std::uint8_t model_group{};
    std::vector<std::uint8_t> part_visibility;
    // Original A8/AC/B0 model adjustment, independent of actor orientation.
    // Its downstream rendering meaning is not assumed by initialization.
    std::array<float,3> model_adjustment{};
    float statistic_multiplier{1}; // BC0; BC4 is canonical contact.damage_scale
    std::uint16_t initialization_marker{}; // D90; downstream role still unresolved
    std::array<HumanoidMotionAlias,3> default_motion_aliases;
};
}
