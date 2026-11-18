#pragma once
#include "../gameplay_actors/entity.hpp"
#include "../transform_math/transform_math.hpp"
#include <array>
#include <cstdint>
namespace reo::native::gameplay_world {
// Humanoid head/reaction state. Other families can reuse the original byte
// offsets for unrelated fields; only their actual initializer grants this owner.
struct HeadReactionState {
    std::uint8_t mode{}; // BD1
    std::int16_t ticks{}; // BD2
    std::array<std::int16_t,2> step{},current{},applied{}; // BD4..BDE
    gameplay_actors::EntityId target; // BE0
    transform_math::Matrix local{}; // BF0, copied local head matrix
    std::int16_t retarget_ticks{}; // C30
    std::array<std::int16_t,2> input{}; // FA4/FA6
};
}
