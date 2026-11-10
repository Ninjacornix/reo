#include "off_room_travel.hpp"
#include "../gameplay_navigation/bank.hpp"
#include "../gameplay_world/world.hpp"
#include <bit>
#include <cmath>

namespace reo::native::gameplay_ai {
namespace {

#include "off_room_travel_speeds.inc"

unsigned travel_speed_row(std::uint8_t motion, std::uint8_t actor_class) noexcept {
    switch (motion) {
        case 1:
            if (actor_class == 2)
                return 1;
            if (actor_class == 3)
                return 2;
            return 0;
        case 2:
            if (actor_class == 2)
                return 4;
            if (actor_class == 3)
                return 5;
            return 3;
        case 3:
            if (actor_class == 2)
                return 1;
            if (actor_class == 3)
                return 2;
            return 6;
        case 0x1a:
            return 7;
        case 0x22:
            return 8;
        case 0x23:
            return 9;
        case 0x24:
            return 10;
        case 0x27:
            return 11;
        case 0x31:
            return 12;
        case 0x2e:
            return 13;
        case 0x2f:
            return 14;
        default:
            return 0;
    }
}

bool scripted_arrival(std::uint8_t action) noexcept {
    switch (action) {
        case 4:
        case 5:
        case 8:
        case 9:
        case 11:
        case 12:
            return true;
        default:
            return false;
    }
}

} // namespace

std::optional<std::int32_t> waypoint_travel_ticks(const gameplay_world::Actor& actor,
                                                  gameplay_navigation::Position destination,
                                                  std::uint8_t clock_mode) noexcept {
    if (actor.character >= travel_speed_words.front().size())
        return {};
    const float x = actor.position.x - destination.x;
    const float y = actor.position.y - destination.y;
    const float z = actor.position.z - destination.z;
    const float distance = std::sqrt((x * x + y * y) + z * z);
    const auto row = travel_speed_row(actor.motion_class, actor.class_marker);
    const auto speed = std::bit_cast<float>(travel_speed_words[row][actor.character]);
    float ticks = distance / speed;
    if (clock_mode)
        ticks /= 2.f;
    if (!std::isfinite(ticks) || double(ticks) >= 4294967296.0)
        return {};
    return std::bit_cast<std::int32_t>(std::uint32_t(ticks));
}

Status advance_off_room_waypoint(gameplay_world::Actor& actor,
                                 const gameplay_navigation::Bank& bank,
                                 std::uint8_t clock_mode) noexcept {
    if (!actor.ai_execution || !actor.navigation_route)
        return Status::unavailable;
    auto& execution = *actor.ai_execution;
    auto& route = *actor.navigation_route;
    const auto& waypoint = route.output.route;
    if (!execution.action_phases[0]) {
        const auto duration = waypoint_travel_ticks(actor, waypoint.first_position, clock_mode);
        if (!duration)
            return Status::unavailable;
        route.travel_ticks = *duration;
        execution.action_phases[0] = 1;
    }
    if (route.travel_ticks > 0) {
        --route.travel_ticks;
        if (route.completed == 1)
            set_action(execution, 0);
        return Status::completed;
    }

    if (scripted_arrival(std::uint8_t(route.action)))
        return Status::unavailable;
    const auto point = waypoint.first_position;
    if (!std::isfinite(point.x) || !std::isfinite(point.y) || !std::isfinite(point.z))
        return Status::unavailable;
    const bool reached_destination =
        actor.room == route.destination_room && waypoint.first == route.destination_node;
    const bool completed = route.completed == 1 || reached_destination;
    const gameplay_navigation::Node* arrival_node = nullptr;
    if (!completed) {
        const auto* graph = bank.room(actor.room);
        if (!graph || waypoint.first < 0 || std::size_t(waypoint.first) >= graph->nodes().size())
            return Status::unavailable;
        arrival_node = &graph->nodes()[std::size_t(waypoint.first)];
        if (arrival_node->neighbor_count > int(arrival_node->neighbors.size()))
            return Status::unavailable;
    }
    execution.action_phases[0] = 0;
    actor.position = {point.x, point.y, point.z};
    route.current_node = waypoint.first;
    if (reached_destination)
        route.completed = 1;
    if (completed) {
        set_action(execution, 0);
        return Status::completed;
    }
    for (int i = 0; i < arrival_node->neighbor_count; ++i) {
        if (arrival_node->neighbors[i] == waypoint.second) {
            route.action = arrival_node->actions[i];
            break;
        }
    }
    return Status::completed;
}

} // namespace reo::native::gameplay_ai
