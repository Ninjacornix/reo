std::uint64_t steering_cases{}, active_room_action_cases{};

#ifdef REO_AI_ORIGINAL
constexpr unsigned steering_actor_at = 0x10000, reference_actor_at = 0x4a5c30;
constexpr gw::Position camera_position{0, 80, 400}, camera_target{100, 0, 600};

void project_steering_actor(std::vector<std::uint8_t>& target, unsigned at,
                            const gw::Actor& actor) {
    project_goal_actor(target, at, actor);
    put(target, at + 0x38, actor.position);
    put(target, at + 0x92, actor.orientation[1]);
    const auto& state = *actor.ai_execution;
    put(target, at + 0x1038, state.steering_value);
    target[at + 0xff2] = state.steering_button_10;
    target[at + 0xff3] = state.steering_button_20;
    put(target, at + 0xf78, actor.input.pressed);
    put(target, at + 0xf7c, actor.input.released);
    put(target, at + 0xf80, actor.input.held);
    put(target, at + 0xf84, actor.input.history);
    put(target, at + 0xf90, actor.input.repeat);
    put(target, at + 0xf94, actor.input.repeat_timer);
    put(target, at + 0xf98, actor.input.analog);
}

void compare_heading_port(std::uint8_t* bytes, R5900Context* context) {
    const bool position_turn = context->pc == 0x370140;
    const auto from_at = GPR_U32(context, 4), to_at = GPR_U32(context, 5);
    check(from_at == (position_turn ? steering_actor_at + 0x38 : 0x324138));
    check(to_at == (position_turn ? reference_actor_at + 0x38 : 0x324144));
    const auto from = transform_read<gw::Position>(bytes, from_at);
    const auto to = transform_read<gw::Position>(bytes, to_at);
    const auto x = to.x - from.x, z = to.z - from.z;
    const auto heading = position_turn ? reo::native::transform_math::position_direction_turn(x, z)
                                       : reo::native::transform_math::direction_turn(x, z);
    SET_GPR_U32(context, 2, heading);
    context->pc = GPR_U32(context, 31);
}
#endif

void compare_steering(gw::Actor& actor, std::int32_t mode, std::uint16_t camera_heading,
                      const gw::Actor* reference = nullptr, bool paused = false) {
    const bool dispatch = reference != nullptr;
#ifdef REO_AI_ORIGINAL
    std::fill_n(memory.begin() + steering_actor_at, 0x1100, 0xa5);
    project_steering_actor(memory, steering_actor_at, actor);
    auto expected = std::vector<std::uint8_t>(memory.begin() + steering_actor_at,
                                              memory.begin() + steering_actor_at + 0x1100);
    if (dispatch) {
        put(memory, reference_actor_at + 0x1e2, reference->room);
        put(memory, reference_actor_at + 0x38, reference->position);
        memory[0x3243d2] = paused ? 255 : 0;
    }
#endif
    const auto status = dispatch ? ai::dispatch_active_room_action(actor, reference, paused)
                                 : ai::apply_steering(actor, mode, camera_heading);
    check(status == ai::Status::completed);
#ifdef REO_AI_ORIGINAL
    project_steering_actor(expected, 0, actor);
    R5900Context context;
    PS2Runtime runtime;
    context.pc = dispatch ? 0x81a720 : 0x81bb80;
    SET_GPR_U32(&context, 4, steering_actor_at);
    SET_GPR_S32(&context, 5, mode);
    SET_GPR_U32(&context, 29, 0x1f00000);
    SET_GPR_U32(&context, 31, 0x100);
    original_transform_port(memory.data(), &context, &runtime);
    check(context.pc == 0x100 && GPR_U32(&context, 29) == 0x1f00000);
    const auto mismatch =
        std::mismatch(expected.begin(), expected.end(), memory.begin() + steering_actor_at);
    if (mismatch.first != expected.end()) {
        std::cerr << "Steering mode " << mode << " dispatch " << dispatch << " case "
                  << (dispatch ? active_room_action_cases : steering_cases) << " offset "
                  << std::hex << std::distance(expected.begin(), mismatch.first) << std::dec
                  << '\n';
        check(false);
    }
#endif
    if (dispatch)
        ++active_room_action_cases;
    else
        ++steering_cases;
}

void steering_contracts() {
    gw::Actor actor;
    gw::Actor reference;
    actor.room = 7;
    actor.position = {300, 10, 200};
    reference.room = 7;
    reference.position = {100, 50, 200};
    constexpr gw::Position from{0, 80, 400}, to{100, 0, 600};
    const auto camera_heading =
        reo::native::transform_math::direction_turn(to.x - from.x, to.z - from.z);
#ifdef REO_AI_ORIGINAL
    put(memory, 0x324138, camera_position);
    put(memory, 0x324144, camera_target);
#endif
    for (unsigned angle = 0; angle < 65536; ++angle) {
        for (std::int32_t mode = -1; mode <= 4; ++mode) {
            actor.ai_execution = state(angle);
            auto& execution = *actor.ai_execution;
            execution.steering_value = std::uint16_t(3 * angle + 5);
            execution.steering_button_10 = std::uint8_t(angle % 5);
            execution.steering_button_20 = std::uint8_t((angle / 3) % 6);
            actor.motion_class = angle % 2 ? 5 : 7;
            actor.orientation[1] =
                std::bit_cast<std::int16_t>(std::uint16_t(execution.steering_value + angle));
            actor.input = {0x1300, 0x146, 0x4500, {17, 25, 37}, 22, -1, {1, 2, 3, 4, 5, 6, 7, 8}};
            compare_steering(actor, mode, camera_heading);
        }
        actor.ai_execution = state(angle);
        auto& execution = *actor.ai_execution;
        execution.action = 1;
        execution.action_phases[0] = std::uint8_t(angle % 2);
        execution.steering_value = 0x9040;
        actor.orientation[1] = std::bit_cast<std::int16_t>(std::uint16_t(angle));
        actor.motion_class = 0;
        actor.input = {};
        compare_steering(actor, 0, camera_heading, &reference);
    }
    for (const auto mode : {INT32_MIN, -2, 5, 65535})
        compare_steering(actor, mode, camera_heading);
    for (const auto action : {0u, 1u, 65535u}) {
        actor.ai_execution->action = std::uint16_t(action);
        compare_steering(actor, 0, camera_heading, &reference, true);
    }
    actor.ai_execution->action = 0;
    compare_steering(actor, 0, camera_heading, &reference);
    actor.ai_execution->action = 1;
    reference.room = 8;
    compare_steering(actor, 0, camera_heading, &reference);
    reference.room = 7;
    actor.motion_class = 0x3b;
    compare_steering(actor, 0, camera_heading, &reference);

    const auto input_before = actor.input;
    actor.ai_execution->steering_value = std::bit_cast<std::uint16_t>(actor.orientation[1]);
    check(ai::apply_steering(actor, 0) == ai::Status::unavailable && actor.input == input_before);
    check(ai::apply_steering(actor, INT32_MAX) == ai::Status::unavailable &&
          actor.input == input_before);
    check(ai::dispatch_active_room_action(actor, nullptr, false) == ai::Status::unavailable);
    actor.ai_execution->action = 2;
    check(ai::dispatch_active_room_action(actor, &reference, false) == ai::Status::unavailable);
}
