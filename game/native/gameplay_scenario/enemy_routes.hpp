#pragma once
#include <array>
#include <cstdint>
#include <optional>

namespace reo::native::gameplay_scenario {
struct EnemyRoutePosition {
    bool available{};
    std::int8_t position{-1};
};

// Class-to-room bank assignments are mutable session state shared by spawn
// initialization and subsequent enemy route consumers.
class EnemyRoutes final {
public:
    std::array<std::uint16_t,2> classes{};
    std::array<std::array<std::uint16_t,128>,2> room_banks{};

    // Complete bounded5A7BC0 + 6D45A0 + 6D4650 + 6BC210 query. An absent route
    // has position-1. An unavailable authored bank remains an explicit failure.
    EnemyRoutePosition position(std::optional<std::uint16_t> scenario,
        std::uint8_t family,std::uint8_t room,std::uint8_t selector) const noexcept;
};
}
