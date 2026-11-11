#include "actor_placements.hpp"
#include "world.hpp"
#include <bit>

namespace reo::native::gameplay_world {
namespace {
std::uint32_t word(std::span<const std::byte> bytes) noexcept {
    return std::to_integer<std::uint32_t>(bytes[0]) |
           std::to_integer<std::uint32_t>(bytes[1]) << 8 |
           std::to_integer<std::uint32_t>(bytes[2]) << 16 |
           std::to_integer<std::uint32_t>(bytes[3]) << 24;
}
}

bool ActorPlacements::load_positions(std::span<const std::byte> packet) noexcept {
    constexpr std::size_t stride = 32;
    if (packet.size() < 4) return false;
    const auto count = word(packet);
    if (count > position_capacity || packet.size() != 4 + count * stride) return false;
    for (std::size_t i = 0; i < count; ++i) {
        const auto bytes = packet.subspan(4 + i * stride, stride);
        positions_[i] = {
            std::bit_cast<std::int32_t>(word(bytes)),
            std::bit_cast<std::int32_t>(word(bytes.subspan(0x14))),
            std::bit_cast<std::int32_t>(word(bytes.subspan(4))),
            std::bit_cast<std::int16_t>(std::uint16_t(word(bytes.subspan(8))))
        };
    }
    position_count_ = count;
    return true;
}

std::optional<ActorPlacement> ActorPlacements::position(std::uint8_t index) const noexcept {
    if (index >= position_count_) return {};
    return positions_[index];
}

void ActorPlacements::clear_requests() noexcept {
    for (auto& request : requests_) request.state = 255;
}

bool ActorPlacements::queue(std::size_t actor, std::uint8_t room, std::uint8_t position) noexcept {
    if (actor >= requests_.size()) return false;
    requests_[actor] = {0, room, position};
    return true;
}

bool queue_character_placement(World& world, std::uint8_t character, std::uint8_t room,
                               std::uint8_t position) noexcept {
    std::array<std::shared_ptr<Actor>,ActorPlacements::request_count> actors;
    for (std::size_t i = 0; i < actors.size(); ++i) {
        actors[i] = world.primary(i);
        if (!actors[i]) return false;
    }
    auto& placements = world.session().actor_placements;
    for (std::size_t i = 0; i < actors.size(); ++i) {
        if (actors[i]->character != character) continue;
        (void)placements.queue(i, room, position);
        if (actors[i]->slot == world.selected_actor) placements.selected_request = true;
    }
    return true;
}

bool script_actor_placement(World& world, std::uint8_t slot, std::uint8_t command,
                            std::uint8_t position) noexcept {
    if (slot == 4) slot = world.selected_actor;
    const auto actor = world.primary(slot);
    if (!actor) return false;
    auto& placements = world.session().actor_placements;
    if (command == 0xf0) {
        const auto target = placements.position(position);
        if (!target || (actor->transient_action && !actor->interaction_request)) return false;
        if (!actor->interaction_request) actor->interaction_request.emplace();
        auto& interaction = *actor->interaction_request;
        interaction.anchor = {float(target->x), float(target->y), float(target->z)};
        interaction.orientation = std::uint32_t(std::int32_t(target->yaw));
    }
    if (command == 0xf0 || command == 0xf1) {
        if (!actor->interaction_request) return false;
        const auto& interaction = *actor->interaction_request;
        actor->position = actor->previous_position = interaction.anchor;
        actor->orientation[0] = actor->orientation[2] = 0;
        actor->orientation[1] = std::bit_cast<std::int16_t>(std::uint16_t(interaction.orientation));
        actor->previous_orientation = actor->orientation;
        actor->action_flags &= std::uint16_t(~std::uint16_t(1));
        actor->surface_blend_weight = 0;
        actor->root_motion_delta = {};
        actor->collision.pose_ready = false;
    } else if (!placements.queue(slot, command, position)) return false;
    if (actor->slot == world.selected_actor) placements.selected_request = true;
    return true;
}
}
