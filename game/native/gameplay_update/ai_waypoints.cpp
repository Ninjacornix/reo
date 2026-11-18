#include "update.hpp"
#include "../gameplay_ai/steering.hpp"
#include "../transform_math/heading.hpp"
#include <bit>
#include <cmath>
#include <exception>

namespace reo::native::gameplay_update {
namespace {

namespace collision = gameplay_collision;

bool contact_wall_type(std::uint16_t type) noexcept {
    switch (type) {
        case 0x004:
        case 0x008:
        case 0x010:
        case 0x020:
        case 0x040:
        case 0x080:
        case 0x100:
        case 0x200:
        case 0x800:
            return true;
        default:
            return false;
    }
}

// 81A210 uses the wall probe point and the actor's previously recorded
// contact normal for distinct tests.
std::optional<bool> waypoint_contact(const world::Actor& actor,
                                     const gameplay_navigation::VisibilityRoom& room,
                                     gameplay_navigation::Position waypoint) {
    const auto position = actor.position;
    const collision::Vec3 start{position.x, position.y, position.z};
    const collision::Vec3 end{waypoint.x, position.y + 10.f, waypoint.z};
    auto filter = room.filter;
    filter.include = UINT32_MAX;
    filter.exclude = 0;
    filter.dynamic_kind_gate = false;
    const auto wall = collision::trace::shorten(room.walls, start, end, filter, room.dynamic);
    if (wall.status != collision::trace::SamplingStatus::complete)
        return {};
    if (!wall.hit || !contact_wall_type(std::uint16_t(wall.hit->type)))
        return false;
    const float x = position.x - wall.hit->point.x;
    const float y = position.y - wall.hit->point.y;
    const float z = position.z - wall.hit->point.z;
    if (!(std::sqrt((x * x + y * y) + z * z) < 55.f))
        return false;
    const auto normal = actor.projectile_contact.normal;
    const auto facing = std::uint16_t(transform_math::direction_turn(normal.x, normal.z) + 0x8000);
    const auto yaw = std::bit_cast<std::uint16_t>(actor.orientation[1]);
    const auto difference = std::bit_cast<std::int16_t>(std::uint16_t(yaw - facing));
    return std::abs(int(difference)) <= 0x2000;
}

} // namespace

gameplay_ai::Status
Owner::advance_active_ai_waypoint(world::Actor& actor,
                                  const gameplay_navigation::VisibilityRoom* room,
                                  std::optional<std::uint16_t> camera_heading) {
    using gameplay_ai::Status;
    if (!actor.navigation_route)
        return Status::unavailable;
    auto& route = *actor.navigation_route;
    auto& execution = *actor.ai_execution;
    if (std::uint8_t(route.action) == std::uint8_t(route.previous_action)) {
        route.action = route.previous_action;
    } else if (!execution.action_marker) {
        route.action = route.previous_action;
        execution.action_phases.fill(0);
    }

    if (std::uint8_t(route.action) != 0)
        return Status::unavailable;
    if (route.completed == 1) {
        gameplay_ai::set_action(execution, 0);
        return Status::completed;
    }
    if (!room)
        return Status::unavailable;

    const auto waypoint = route.output.route.first_position;
    try {
        execution.steering_value = transform_math::position_direction_turn(
            waypoint.x - actor.position.x, waypoint.z - actor.position.z);
        const auto contact = waypoint_contact(actor, *room, waypoint);
        if (!contact)
            return Status::unavailable;
        if (*contact)
            execution.steering_button_20 = 1;
        return gameplay_ai::apply_steering(actor, 0, camera_heading);
    } catch (const std::exception&) {
        return Status::unavailable;
    }
}

} // namespace reo::native::gameplay_update
