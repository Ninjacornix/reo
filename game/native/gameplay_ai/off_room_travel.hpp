#pragma once
#include "execution.hpp"
#include "../gameplay_navigation/navigation.hpp"

namespace reo::native::gameplay_world {
struct Actor;
}

namespace reo::native::gameplay_navigation {
class Bank;
}

namespace reo::native::gameplay_ai {

// Complete 81A470 for finite travel durations in the unsigned word domain.
std::optional<std::int32_t> waypoint_travel_ticks(const gameplay_world::Actor&,
                                                  gameplay_navigation::Position destination,
                                                  std::uint8_t clock_mode) noexcept;

// 81BF10 through countdown and ordinary waypoint arrival. Scripted room
// transitions need their own consumers before they can commit arrival.
Status advance_off_room_waypoint(gameplay_world::Actor&, const gameplay_navigation::Bank&,
                                 std::uint8_t clock_mode) noexcept;

} // namespace reo::native::gameplay_ai
