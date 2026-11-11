#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>

namespace reo::native::gameplay_session {
struct ActorLaunch {
    std::uint8_t character{},appearance{};
    bool ai_control{};
    std::uint16_t model_variant{};
};
struct LaunchRoster {
    std::uint8_t gameplay_flags{},scenario{},choice_row{};
    std::array<ActorLaunch,6> actors{};
    std::size_t count{};
};

// The roster prefix has four player slots and two AI slots, each with its own
// character, appearance and model-variant arrays. Later launch fields remain
// the responsibility of their own consumers.
std::optional<LaunchRoster> parse_launch_roster(std::span<const std::byte>) noexcept;
}
