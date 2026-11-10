std::uint64_t off_room_motion_cases{}, off_room_action_cases{};

void compare_off_room_action(gw::Actor& actor, bool dispatch) {
#ifdef REO_AI_ORIGINAL
    constexpr unsigned at = 0x10000;
    std::fill_n(memory.begin() + at, 0x1100, 0xa5);
    project_steering_actor(memory, at, actor);
    put(memory, at + 0x1054, actor.navigation_route->action);
    auto expected = std::vector<std::uint8_t>(memory.begin() + at, memory.begin() + at + 0x1100);
#endif
    const auto status =
        dispatch ? ai::dispatch_off_room_action(actor) : ai::synthesize_off_room_motion(actor);
    check(status == ai::Status::completed);
#ifdef REO_AI_ORIGINAL
    project_steering_actor(expected, 0, actor);
    R5900Context context;
    PS2Runtime runtime;
    context.pc = dispatch ? 0x81beb0 : 0x81c1a0;
    SET_GPR_U32(&context, 4, at);
    SET_GPR_U32(&context, 29, 0x1f00000);
    SET_GPR_U32(&context, 31, 0x100);
    original_transform_port(memory.data(), &context, &runtime);
    check(context.pc == 0x100 && GPR_U32(&context, 29) == 0x1f00000);
    check(std::memcmp(expected.data(), memory.data() + at, 0x1100) == 0);
#endif
    if (dispatch)
        ++off_room_action_cases;
    else
        ++off_room_motion_cases;
}

void off_room_action_contracts() {
    gw::Actor actor;
    actor.navigation_route.emplace();
    for (unsigned waypoint = 0; waypoint < 65536; ++waypoint) {
        for (std::uint8_t steer : {0, 1, 255}) {
            actor.motion_class = 255;
            actor.ai_execution = state(waypoint);
            actor.ai_execution->action = 2;
            actor.ai_execution->steering_button_10 = steer;
            actor.navigation_route->action = std::uint16_t(waypoint);
            compare_off_room_action(actor, false);
        }
    }
    for (auto action : {0, 1, 3, 4, 5, 6, 7, 8, 9, 10}) {
        for (unsigned phase = 0; phase < 256; ++phase) {
            actor.motion_class = 255;
            actor.ai_execution = state(phase);
            actor.ai_execution->action = std::uint16_t(action);
            actor.ai_execution->action_phases[0] = std::uint8_t(phase);
            if (action >= 4 && action <= 6 && !phase) {
                check(ai::dispatch_off_room_action(actor) == ai::Status::unavailable &&
                      actor.ai_execution->action == action &&
                      actor.ai_execution->action_phases[0] == 0);
                continue;
            }
            compare_off_room_action(actor, true);
        }
    }
    actor.ai_execution->action = 2;
    actor.navigation_route->action = 0x770d;
    check(ai::dispatch_off_room_action(actor) == ai::Status::unavailable &&
          actor.motion_class == 0x31);
    actor.navigation_route.reset();
    check(ai::synthesize_off_room_motion(actor) == ai::Status::unavailable &&
          actor.motion_class == 0x31);
    actor.ai_execution->action = 65535;
    check(ai::dispatch_off_room_action(actor) == ai::Status::unavailable &&
          actor.motion_class == 0x31);
}
