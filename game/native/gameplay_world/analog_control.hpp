#pragma once
#include "world.hpp"
#include "../transform_math/direction_basis.hpp"
#include <optional>

namespace reo::native::gameplay_world {
enum class AnalogControlStatus { completed, unavailable };

// Source-qualified6621F0 preparation. Optional global UI reads are requested
// only at the corresponding original gate, after prior side effects remain.
AnalogControlStatus update_analog_control(
    World&,Actor&,transform_math::Vector camera_eye,transform_math::Vector camera_aim,
    std::uint8_t& camera_latch,std::optional<std::uint8_t> request_blocked,
    std::optional<bool> dialogue_suppressed);
} // namespace reo::native::gameplay_world
