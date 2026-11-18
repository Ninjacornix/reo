#pragma once
#include <array>
#include <cstdint>
namespace reo::native::gameplay_world {
struct InventorySlots {
    std::array<std::uint8_t,4> carried{};
    std::array<std::uint8_t,32> storage{};
};
}
