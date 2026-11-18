std::uint64_t waypoint_timing_cases{}, waypoint_travel_cases{};

#ifdef REO_AI_ORIGINAL
constexpr unsigned waypoint_actor_at = 0x10000, waypoint_node_at = 0x1e01000;

void project_waypoint_actor(std::vector<std::uint8_t>& bytes, unsigned at, const gw::Actor& actor) {
    project_steering_actor(bytes, at, actor);
    const auto& route = *actor.navigation_route;
    bytes[at + 0x100c] = std::uint8_t(route.current_node);
    bytes[at + 0x100d] = std::uint8_t(route.destination_node);
    bytes[at + 0x100e] = std::uint8_t(route.output.route.first);
    bytes[at + 0x100f] = std::uint8_t(route.output.route.second);
    put(bytes, at + 0x101c, route.output.route.first_position);
    put(bytes, at + 0x1054, route.action);
    put(bytes, at + 0x1058, route.destination_room);
    bytes[at + 0x105a] = route.completed;
    put(bytes, at + 0x105c, route.travel_ticks);
}
#endif

void compare_waypoint_timing(const gw::Actor& actor, gn::Position target, std::uint8_t clock_mode) {
    const auto result = ai::waypoint_travel_ticks(actor, target, clock_mode);
    check(result.has_value());
#ifdef REO_AI_ORIGINAL
    put(memory, waypoint_actor_at + 0x38, actor.position);
    put(memory, waypoint_actor_at + 0x101c, target);
    memory[waypoint_actor_at + 0xb98] = actor.character;
    memory[waypoint_actor_at + 0xb9b] = actor.class_marker;
    memory[0x3243cc] = clock_mode;
    R5900Context context;
    PS2Runtime runtime;
    context.pc = 0x81a470;
    SET_GPR_U32(&context, 4, waypoint_actor_at);
    SET_GPR_U32(&context, 5, actor.motion_class);
    SET_GPR_U32(&context, 6, waypoint_actor_at + 0x38);
    SET_GPR_U32(&context, 7, waypoint_actor_at + 0x101c);
    SET_GPR_U32(&context, 29, 0x1f00000);
    SET_GPR_U32(&context, 31, 0x100);
    original_transform_port(memory.data(), &context, &runtime);
    check(context.pc == 0x100 && GPR_U32(&context, 29) == 0x1f00000);
    check(*result == GPR_S32(&context, 2));
#endif
    ++waypoint_timing_cases;
}

void compare_waypoint_travel(gw::Actor& actor, const gn::Bank& bank, std::uint8_t clock_mode) {
#ifdef REO_AI_ORIGINAL
    std::fill_n(memory.begin() + waypoint_actor_at, 0x1100, 0xa5);
    project_waypoint_actor(memory, waypoint_actor_at, actor);
    auto expected = std::vector<std::uint8_t>(memory.begin() + waypoint_actor_at,
                                              memory.begin() + waypoint_actor_at + 0x1100);
    memory[0x3243cc] = clock_mode;
#endif
    check(ai::dispatch_off_room_action(actor, bank, clock_mode) == ai::Status::completed);
#ifdef REO_AI_ORIGINAL
    project_waypoint_actor(expected, 0, actor);
    R5900Context context;
    PS2Runtime runtime;
    context.pc = 0x81beb0;
    SET_GPR_U32(&context, 4, waypoint_actor_at);
    SET_GPR_U32(&context, 29, 0x1f00000);
    SET_GPR_U32(&context, 31, 0x100);
    original_transform_port(memory.data(), &context, &runtime);
    check(context.pc == 0x100 && GPR_U32(&context, 29) == 0x1f00000);
    const auto mismatch =
        std::mismatch(expected.begin(), expected.end(), memory.begin() + waypoint_actor_at);
    if (mismatch.first != expected.end()) {
        std::cerr << "Waypoint case " << waypoint_travel_cases << " offset " << std::hex
                  << std::distance(expected.begin(), mismatch.first) << std::dec << '\n';
        check(false);
    }
#endif
    ++waypoint_travel_cases;
}

void off_room_travel_contracts() {
    gw::Actor actor;
    actor.position = {1.25f, -3.5f, 17.125f};
    const std::array targets{
        gn::Position{1.25f, -3.5f, 17.125f},
        gn::Position{1.5f, -3.25f, 17.875f},
        gn::Position{-305.75f, 415.1f, -629.25f},
        gn::Position{2.5e9f, 0.f, 0.f},
    };
    for (unsigned motion = 0; motion < 256; ++motion) {
        for (auto actor_class : {0, 1, 2, 3, 4, 255}) {
            for (std::uint8_t character = 0; character < 8; ++character) {
                actor.motion_class = std::uint8_t(motion);
                actor.class_marker = std::uint8_t(actor_class);
                actor.character = character;
                for (std::uint8_t clock_mode : {0, 1, 255})
                    for (const auto target : targets)
                        compare_waypoint_timing(actor, target, clock_mode);
            }
        }
    }

    reo::native::gameplay_session::RoomVariants variants;
    gn::Bank bank(variants);
    check(variants.store(7, 0) && bank.bind(reevaluation_asset(true, true)));
    const auto* graph = bank.room(7);
    check(graph && graph->nodes().size() == 1);
    const auto& node = graph->nodes()[0];
    check(node.neighbor_count == 2 && node.actions[0] == 0x6602 && node.actions[1] == 0x7788);
#ifdef REO_AI_ORIGINAL
    put(memory, 0x83e55c + 164 * 7, waypoint_node_at);
    put(memory, waypoint_node_at + 1, node.neighbor_count);
    put(memory, waypoint_node_at + 20, node.neighbors);
    put(memory, waypoint_node_at + 24, node.actions);
#endif
    actor.room = 7;
    for (unsigned seed = 0; seed < 4096; ++seed) {
        actor.position = {100, 20, 400};
        actor.character = std::uint8_t(seed % 8);
        actor.class_marker = std::uint8_t(seed / 3 % 6);
        actor.ai_execution = state(seed);
        auto& execution = *actor.ai_execution;
        execution.action = 2;
        execution.action_phases[0] = std::uint8_t(seed % 3);
        execution.steering_button_10 = std::uint8_t(seed % 2);
        actor.navigation_route = gn::ActorRouteState{};
        auto& route = *actor.navigation_route;
        route.current_node = -1;
        route.destination_room = seed / 23 % 2 ? 7 : 8;
        route.destination_node = 0;
        route.output.route.first = 0;
        route.output.route.second = seed / 5 % 2 ? 0 : -1;
        route.output.route.first_position =
            seed / 19 % 2 ? gn::Position{105, 25, 403} : gn::Position{100, 20, 400};
        route.action = std::array<std::uint16_t, 9>{0, 1, 2, 3, 6, 7, 10, 13, 0xff02}[seed % 9];
        route.completed = std::uint8_t(seed / 11 % 3);
        route.travel_ticks = std::array<std::int32_t, 6>{-1, 0, 1, 2, 40, INT32_MAX}[seed / 7 % 6];
        compare_waypoint_travel(actor, bank, std::uint8_t(seed / 2 % 2));
    }
    actor.ai_execution->action = 2;
    actor.ai_execution->action_phases[0] = 1;
    actor.navigation_route->action = 4;
    actor.navigation_route->travel_ticks = 1;
    actor.navigation_route->completed = 0;
    check(ai::dispatch_off_room_action(actor, bank, 0) == ai::Status::completed);
    check(actor.navigation_route->travel_ticks == 0);
    const auto previous_position = actor.position;
    check(ai::dispatch_off_room_action(actor, bank, 0) == ai::Status::unavailable);
    check(actor.position.x == previous_position.x && actor.position.y == previous_position.y &&
          actor.position.z == previous_position.z && actor.ai_execution->action_phases[0] == 1);
    check(!ai::waypoint_travel_ticks(actor, {1e20f, 0, 0}, 0));
    actor.character = 8;
    check(!ai::waypoint_travel_ticks(actor, {}, 0));
}
