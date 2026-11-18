#pragma once
#include "../gameplay_actors/reference.hpp"
#include <array>
#include <cstdint>

namespace reo::native::gameplay_world {
// Linked enemy-family state. Primary inventory and pending-hit fields that
// occupied the same original offsets have separate family-specific roles.
// Numeric parameter names retain their source locations until consumers
// establish a more specific meaning.
struct EnemyState {
    std::uint8_t header_parameter{};                         // 5
    std::uint8_t owner_mode{},parameter_b9d{},phase{};        // B9A/B9D/B9F
    std::uint8_t condition{},parameter_baa{};                // BA9/BAA
    std::array<float,2> distance_parameters{};               // BCC/BD0
    std::int16_t initial_timer{};                            // BDA
    std::array<std::uint8_t,4> control_state{};               // C20..C23
    std::uint8_t class_flags{},target_pool{},target_slot{};   // C24..C26
    std::array<std::uint8_t,2> parameters_c27_c28{};
    std::uint8_t parameter_c2a{},parameter_c2b{};
    std::uint16_t timer_c2e{};
    std::uint8_t behavior_mode{};                            // C84
    std::array<std::uint8_t,4> behavior_parameters{};         // C85..C88
    std::array<std::uint8_t,2> score_parameters{};            // C89/C8A
    std::array<std::uint32_t,2> score_masks{};                // C8C/C90
    // The binder's final selected-player reference is independent of the
    // earlier encoded target_pool/target_slot hints.
    gameplay_actors::ActorReference target;
    friend bool operator==(const EnemyState&,const EnemyState&) = default;
};
}
