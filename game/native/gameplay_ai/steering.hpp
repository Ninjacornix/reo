#pragma once
#include "execution.hpp"

namespace reo::native::gameplay_world {
struct Actor;
}

namespace reo::native::gameplay_ai {

// Complete 81BB80. Camera heading is required only for the analog branch.
Status apply_steering(gameplay_world::Actor&, std::int32_t mode,
                      std::optional<std::uint16_t> camera_heading = {}) noexcept;

// 81A720 with active-room action 0 or 1. The pause fact comes from the caller.
Status dispatch_active_room_action(gameplay_world::Actor&, const gameplay_world::Actor* reference,
                                   bool paused) noexcept;

} // namespace reo::native::gameplay_ai
