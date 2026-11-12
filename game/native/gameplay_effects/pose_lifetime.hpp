#pragma once
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_effects {
struct PoseLifetimeStep {bool retire{};std::optional<std::uint8_t> update;};
// Complete582B80 gate. Asset update kinds are retained; shared visibility
// kinds3/4/5 normalize to0. A required reached consumer runs after this gate.
PoseLifetimeStep advance_pose_lifetime(std::int16_t&,std::uint8_t kind)noexcept;
}
