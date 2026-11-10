#pragma once
#include "execution.hpp"

namespace reo::native::gameplay_world {
struct Actor;
}
namespace reo::native::gameplay_navigation {
class Bank;
}

namespace reo::native::gameplay_ai {

// Complete 81C1A0. The waypoint action is read from the canonical route.
Status synthesize_off_room_motion(gameplay_world::Actor&) noexcept;

// 81BEB0 for ordinary waypoints, resets and request phases after publication.
Status dispatch_off_room_action(gameplay_world::Actor&, const gameplay_navigation::Bank&,
                                std::uint8_t clock_mode) noexcept;

} // namespace reo::native::gameplay_ai
