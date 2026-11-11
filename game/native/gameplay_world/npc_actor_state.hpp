#pragma once
#include <optional>
#include <cstdint>
namespace reo::native::gameplay_world {
struct NpcActorState {
    float height_parameter{}; // AA8, literal construction metadata
    std::optional<std::uint8_t> attachment; // FB4; known absent when the four slots are full
    std::uint8_t constructor_marker{}; // FD7
};
}
