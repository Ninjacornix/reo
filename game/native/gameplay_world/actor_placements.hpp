#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>

namespace reo::native::gameplay_world {
class World;

struct ActorPlacementRequest {
    std::uint8_t state{255}, room{}, position{};
};

struct ActorPlacement {
    std::int32_t x{}, y{}, z{};
    std::int16_t yaw{};
};

class ActorPlacements {
public:
    static constexpr std::size_t request_count = 4, position_capacity = 32;
    // Counted 32-byte records from the placement packet. Only coordinates and
    // yaw are consumed by the current placement commands.
    bool load_positions(std::span<const std::byte>) noexcept;
    bool apply_packet(World&,std::span<const std::byte>) noexcept;
    bool finish_room_transition(World&) const noexcept;
    std::optional<ActorPlacement> position(std::uint8_t index) const noexcept;
    void clear_requests() noexcept;
    bool queue(std::size_t actor, std::uint8_t room, std::uint8_t position) noexcept;
    const auto& requests() const noexcept { return requests_; }
    std::uint8_t selected_request{};

private:
    std::array<ActorPlacementRequest, request_count> requests_{};
    std::array<ActorPlacement, position_capacity> positions_{};
    std::size_t position_count_{};
};

bool queue_character_placement(World&, std::uint8_t character, std::uint8_t room,
                               std::uint8_t position) noexcept;
bool script_actor_placement(World&, std::uint8_t actor, std::uint8_t command,
                            std::uint8_t position) noexcept;
}
