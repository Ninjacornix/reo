#pragma once
#include "model.hpp"
namespace reo::native::animation {
// Complete573480 finite frame-window policy. Runs before channel advancement;
// the supplied step is the caller's actual argument, not a wall-clock delta.
bool crosses_frame(const FrameRecord&, float target, float step, std::uint8_t clock_mode);
} // namespace reo::native::animation
