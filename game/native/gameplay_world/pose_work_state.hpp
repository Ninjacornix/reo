#pragma once
#include "../transform_math/transform_math.hpp"
#include "../gameplay_actors/entity.hpp"
namespace reo::native::gameplay_world {
// Specialty state of the actual64-entry scene pose-work domain. Its root
// matrix is canonical here; contact queries derive a temporary Basis view.
// Common active/render/phase/position/angles/related fields stay in Actor.
struct PoseWorkState {
    bool update_bound{};
    transform_math::Matrix basis{};
    std::uint8_t kind{},variant{},selector{},ordinal{};
    std::int16_t timer{},secondary_timer{},age{},lifetime{};
    transform_math::Vector velocity,acceleration,offset;
    float travel_speed{}; // actual F0 in forward projectile584250
    gameplay_actors::EntityId emitter_owner; // actual24 assigned with28 by preset582720
    gameplay_actors::EntityId follower_visual; // actual24 shared visual created by58DA20

};
}
