#pragma once
#include "../transform_math/transform_math.hpp"
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
};
}
