#include "steering.hpp"
#include "../gameplay_world/world.hpp"
#include "../transform_math/heading.hpp"
#include <bit>
#include <exception>
#include <limits>

namespace reo::native::gameplay_ai {
namespace {

std::uint32_t direction_mask(std::uint16_t delta) noexcept {
    return delta <= 0x8000 ? 8u : 4u;
}

Status turn_toward_reference(gameplay_world::Actor& actor,
                             const gameplay_world::Actor* reference) noexcept {
    if (!reference)
        return Status::unavailable;
    if (actor.room != reference->room || actor.motion_class == 0x3b)
        return Status::completed;

    auto& state = *actor.ai_execution;
    const auto yaw = std::bit_cast<std::uint16_t>(actor.orientation[1]);
    switch (state.action_phases[0]) {
        case 0: {
            const auto x = reference->position.x - actor.position.x;
            const auto z = reference->position.z - actor.position.z;
            try {
                const auto heading = transform_math::position_direction_turn(x, z);
                if (std::uint16_t(yaw - heading + 0x4000) <= 0x8000)
                    set_action(state, 0);
                else {
                    state.action_phases[0] = 1;
                    state.steering_value = heading;
                }
            } catch (const std::exception&) {
                return Status::unavailable;
            }
            break;
        }
        case 1:
            if (std::uint16_t(yaw - state.steering_value + 0x300) < 0x600)
                set_action(state, 0);
            else
                return apply_steering(actor, 2);
            break;
    }
    return Status::completed;
}

} // namespace

Status apply_steering(gameplay_world::Actor& actor, std::int32_t mode,
                      std::optional<std::uint16_t> camera_heading) noexcept {
    if (!actor.ai_execution || mode == std::numeric_limits<std::int32_t>::max())
        return Status::unavailable;
    const auto& state = *actor.ai_execution;
    auto& input = actor.input;
    const auto delta =
        std::uint16_t(std::bit_cast<std::uint16_t>(actor.orientation[1]) - state.steering_value);
    const bool behind = std::uint16_t(delta - 0x7800) < 0x1000;

    if ((mode == 0 || mode == 4) && behind) {
        if (actor.motion_class != 5) {
            input.held |= 0x12;
            input.pressed |= 0x10;
        }
    } else {
        switch (mode) {
            case 0:
                if (std::uint16_t(delta + 0x3000) <= 0x6000) {
                    if (!camera_heading)
                        return Status::unavailable;
                    input.analog[0] = 127;
                    input.analog[1] = std::bit_cast<std::int16_t>(
                        std::uint16_t(state.steering_value - *camera_heading));
                } else
                    input.held |= direction_mask(delta);
                break;
            case 1:
                if (state.steering_value == 1 || state.steering_value == 2)
                    input.held |= state.steering_value;
                break;
            case 2:
                if (std::uint16_t(delta + 0x100) > 0x200)
                    input.held |= direction_mask(delta);
                break;
            case 3:
                input.held |= state.steering_value ? 8u : 4u;
                break;
            case 4:
                if (std::uint16_t(delta + 0x800) < 0x1000)
                    input.held |= 1;
                input.held |= direction_mask(delta);
                break;
        }
    }
    if (state.steering_button_10 == 1) {
        input.held |= 0x10;
        input.pressed |= 0x10;
    }
    if (state.steering_button_20 == 1) {
        input.held |= 0x20;
        input.pressed |= 0x20;
    }
    input.released = 0;
    return Status::completed;
}

Status dispatch_active_room_action(gameplay_world::Actor& actor,
                                   const gameplay_world::Actor* reference, bool paused) noexcept {
    if (!actor.ai_execution)
        return Status::unavailable;
    if (paused || !actor.ai_execution->action)
        return Status::completed;
    if (actor.ai_execution->action == 1)
        return turn_toward_reference(actor, reference);
    return Status::unavailable;
}

} // namespace reo::native::gameplay_ai
