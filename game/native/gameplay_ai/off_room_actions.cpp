#include "off_room_actions.hpp"
#include "../gameplay_world/world.hpp"

namespace reo::native::gameplay_ai {

Status synthesize_off_room_motion(gameplay_world::Actor& actor) noexcept {
    if (!actor.ai_execution)
        return Status::unavailable;
    const auto& state = *actor.ai_execution;
    if (state.action != 2) {
        actor.motion_class = 0;
        return Status::completed;
    }
    if (!actor.navigation_route)
        return Status::unavailable;
    switch (std::uint8_t(actor.navigation_route->action)) {
        case 1:
        case 2:
        case 8:
        case 9:
            actor.motion_class = 0x1a;
            break;
        case 6:
        case 7:
            actor.motion_class = 0x27;
            break;
        case 13:
            actor.motion_class = 0x31;
            break;
        default:
            actor.motion_class = state.steering_button_10 ? 3 : 1;
            break;
    }
    return Status::completed;
}

Status dispatch_off_room_action(gameplay_world::Actor& actor) noexcept {
    if (!actor.ai_execution || actor.ai_execution->action > 10)
        return Status::unavailable;
    if (synthesize_off_room_motion(actor) != Status::completed)
        return Status::unavailable;

    auto& state = *actor.ai_execution;
    switch (state.action) {
        case 2:
            return Status::unavailable;
        case 4:
        case 5:
        case 6:
            // Phase zero must publish the real resource request before it can
            // advance. An unavailable handler leaves that request pending.
            if (!state.action_phases[0])
                return Status::unavailable;
            if (state.action_phases[0] != 1)
                return Status::completed;
            break;
    }
    set_action(state, 0);
    return Status::completed;
}

} // namespace reo::native::gameplay_ai
