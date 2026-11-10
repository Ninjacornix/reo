std::uint64_t goal_dispatch_cases{}, goal_dispatch_refusals{};
#ifdef REO_AI_ORIGINAL
std::optional<std::uint16_t> reference_dispatched_goal;
#endif

void compare_goal_dispatch(gw::Actor& actor, const gn::Bank& bank,
                           const gs::SceneResources& resources, std::uint16_t expected_goal,
                           std::uint16_t seed) {
    reo::native::gameplay_session::Random random({seed, 4321, 99});
#ifdef REO_AI_ORIGINAL
    constexpr unsigned actor_at = 0x10000;
    std::fill_n(memory.begin() + actor_at, 0x1100, 0xa5);
    project_goal_actor(memory, actor_at, actor);
    auto expected =
        std::vector<std::uint8_t>(memory.begin() + actor_at, memory.begin() + actor_at + 0x1100);
    put(memory, 0x3244b0, random.state().primary);
    put(memory, 0x3244b8, random.state().secondary);
#endif
    const auto result = ai::dispatch_goal(actor, nullptr, nullptr, bank, resources, random);
    check(result.status == ai::Status::completed && result.selected == expected_goal);
    check(random.state().secondary == 4321 && random.state().observed == 99);
#ifdef REO_AI_ORIGINAL
    project_goal_actor(expected, 0, actor);
    R5900Context context;
    PS2Runtime runtime;
    context.pc = 0x813330;
    SET_GPR_U32(&context, 4, actor_at);
    SET_GPR_U32(&context, 29, 0x1f00000);
    SET_GPR_U32(&context, 31, 0x100);
    reference_dispatched_goal.reset();
    original_transform_port(memory.data(), &context, &runtime);
    check(context.pc == 0x100 && GPR_U32(&context, 29) == 0x1f00000);
    check(reference_dispatched_goal == result.selected);
    check(std::memcmp(expected.data(), memory.data() + actor_at, 0x1100) == 0);
    check(random.state().primary == transform_read<std::uint16_t>(memory.data(), 0x3244b0));
    check(random.state().secondary == transform_read<std::uint16_t>(memory.data(), 0x3244b8));
#endif
    ++goal_dispatch_cases;
}

void goal_dispatch_contracts() {
    reo::native::gameplay_session::RoomVariants variants;
    gn::Bank bank(variants);
    gs::SceneResources resources;
    check(variants.store(7, 0) && bank.bind(reevaluation_asset()));
#ifdef REO_AI_ORIGINAL
    project_goal_bank(bank);
#endif
    gw::Actor actor;
    actor.slot = 1;
    actor.room = 7;
    for (unsigned seed = 0; seed < 65536; ++seed) {
        actor.ai_execution = state(seed);
        auto& execution = *actor.ai_execution;
        actor.character = std::uint8_t(seed % 8);
        actor.motion_class = 0x3b;
        execution.goal = 14;
        execution.goal_refresh = 0;
        execution.goal_phases[0] = 1;
        execution.goal_parameters[0] = std::uint16_t(seed);
        compare_goal_dispatch(actor, bank, resources, 14, std::uint16_t(seed));
        check(execution.goal_parameters[0] == (seed ? seed - 1 : execution.goal_parameters[1]));

        execution.goal_parameters[0] = 0;
        execution.goal_phases[1] = std::uint8_t(seed % 2);
        compare_goal_dispatch(actor, bank, resources, 14, std::uint16_t(seed));
    }
    for (unsigned motion = 0; motion < 256; ++motion) {
        for (auto goal : {std::uint16_t(0), std::uint16_t(6), std::uint16_t(14)}) {
            actor.ai_execution = state(motion);
            auto& execution = *actor.ai_execution;
            actor.motion_class = std::uint8_t(motion);
            execution.goal = goal;
            execution.goal_refresh = 0;
            execution.goal_phases[0] = 0;
            compare_goal_dispatch(actor, bank, resources, goal, std::uint16_t(motion));
            if (goal == 14 && motion == 0x3b)
                check(execution.goal_phases[0] == 1 && execution.goal_parameters[0] == 9 &&
                      execution.goal_parameters[1] == 180);
        }
    }
    actor.motion_class = 0x3b;
    actor.ai_execution = state(1);
    actor.ai_execution->goal = 6;
    actor.ai_execution->goal_refresh = 1;
    compare_goal_dispatch(actor, bank, resources, 14, 1);
    check(actor.ai_execution->goal == 14 && actor.ai_execution->goal_parameters[0] == 9);

    reo::native::gameplay_session::Random random({1234, 4321, 99});
    for (const auto goal : {1u, 2u, 3u, 4u, 5u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 15u, 65535u}) {
        actor.ai_execution = state(goal);
        actor.ai_execution->goal = std::uint16_t(goal);
        actor.ai_execution->goal_refresh = 0;
        const auto before = *actor.ai_execution;
        const auto random_before = random.state();
        const auto result = ai::dispatch_goal(actor, nullptr, nullptr, bank, resources, random);
        check(result.status == ai::Status::unavailable && result.selected == goal);
        check(*actor.ai_execution == before && random.state() == random_before);
        ++goal_dispatch_refusals;
    }
}
