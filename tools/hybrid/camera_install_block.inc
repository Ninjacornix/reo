#if defined(REO_BUILD_NATIVE_ROOM_CAMERA) && REO_BUILD_NATIVE_ROOM_CAMERA
    // REO_NATIVE_ROOM_CAMERA=1 | shadow | shadow-writes (docs/MODERN_CAMERA.md,
    // docs/native-gameplay/HYBRID_INTEGRATION_PLAN.md). Both File #1 and File #2.
    if (const auto* requested = std::getenv("REO_NATIVE_ROOM_CAMERA"); requested && *requested) {
        using reo::native::room_camera_adapter::Mode;
        const Mode mode = !std::strcmp(requested, "1") ? Mode::native
                        : !std::strcmp(requested, "shadow") ? Mode::shadow
                        : !std::strcmp(requested, "shadow-writes") ? Mode::shadow_writes
                        : throw std::runtime_error("REO_NATIVE_ROOM_CAMERA must be 1, shadow or shadow-writes");
#if defined(REO_GAME_FILE2)
        const char* cameraSerial = "SLUS-20984";
#else
        const char* cameraSerial = "SLUS-20765";
#endif
        if (std::strcmp(g.serial, cameraSerial) ||
            !reo::native::room_camera_adapter::install_before_run(runtime, mode))
            throw std::runtime_error("Selected native room camera unavailable; inspect build identity");
        std::fprintf(stdout, "[NATIVE-ROOM-CAMERA] installed mode=%s\n", requested);
    }
#endif
#if defined(REO_BUILD_NATIVE_ROOM_CAMERA) && REO_BUILD_NATIVE_ROOM_CAMERA && !defined(REO_GAME_FILE2)
    // REO_NATIVE_ANALOG=1 | shadow: player analog control 0x6621F0 (File #1),
    // docs/native-gameplay/HYBRID_INTEGRATION_PLAN.md step 3.
    if (const auto* requested = std::getenv("REO_NATIVE_ANALOG"); requested && *requested) {
        using reo::native::analog_control_adapter::Mode;
        const Mode mode = !std::strcmp(requested, "1") ? Mode::native
                        : !std::strcmp(requested, "shadow") ? Mode::shadow
                        : throw std::runtime_error("REO_NATIVE_ANALOG must be 1 or shadow");
        if (std::strcmp(g.serial, "SLUS-20765") ||
            !reo::native::analog_control_adapter::install_before_run(runtime, mode))
            throw std::runtime_error("Selected native analog control unavailable; inspect build identity");
    }
#endif
    // No PS2 hard drive on PC, so no HDD INSTALL in the main menu: the original HDD
    // initialisation (File #1 1BCF60, File #2 148B50) loads the DEV9/ATAD/HDD/PFS drivers and
    // stores the drive status (devctl hdd0: 0x4807). Its "not connected" outcome is kept:
    // status 3 at File #1 0x235008 / File #2 0x2185E8 and the flag at 0x3244E0 / 0x300A70
    // cleared, exactly what the original writes before probing; no drivers are loaded.
    {
        static constexpr bool file2 =
#if defined(REO_GAME_FILE2)
            true;
#else
            false;
#endif
        runtime.registerFunction(file2 ? 0x148B50u : 0x1BCF60u, [](uint8_t* ram, R5900Context* ctx, PS2Runtime*) {
            const uint32_t none = 3, zero = 0;
            std::memcpy(ram + (file2 ? 0x300A70u : 0x3244E0u), &zero, 4);
            std::memcpy(ram + (file2 ? 0x2185E8u : 0x235008u), &none, 4);
            ctx->pc = static_cast<uint32_t>(ctx->r[31][0]);
        });
    }
    // Start at the main menu (REO_SKIP_INTRO=1): the boot scene handler (File #1 1BC8F0,
    // File #2 1483C0) is a step machine (task byte +9, jump table File #1 0x2502C0 / File #2
    // 0x254F00). Steps 0-6 run as original: startup
    // checks, the memory card / system data load and the front-end data load. Steps 7-11 are
    // the timed logo and notice screens (Sofdec, ACCESS, SN@P, ESRB, content warning); the
    // handler goes from step 7 straight to step 12, its original exit to the front end, so
    // those screens are never created. The title prompt is answered by reo_hw_bridge.cpp.
    if (const char* skip = std::getenv("REO_SKIP_INTRO"); skip && !std::strcmp(skip, "1")) {
#if defined(REO_GAME_FILE2)
        void sub_001483C0_0x1483c0(uint8_t*, R5900Context*, PS2Runtime*);
        static constexpr auto bootScene = &sub_001483C0_0x1483c0;
        static constexpr uint32_t bootSceneAddress = 0x1483C0u;
#else
        void sub_001BC8F0_0x1bc8f0(uint8_t*, R5900Context*, PS2Runtime*);
        static constexpr auto bootScene = &sub_001BC8F0_0x1bc8f0;
        static constexpr uint32_t bootSceneAddress = 0x1BC8F0u;
#endif
        runtime.registerFunction(bootSceneAddress, [](uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
            const uint32_t task = static_cast<uint32_t>(ctx->r[4][0]) & 0x1FFFFFFu;
            uint8_t step = 0;
            std::memcpy(&step, ram + task + 9, 1);
            if (step >= 7 && step <= 11) {
                const uint8_t exit = 12, timer = 0;
                std::memcpy(ram + task + 9, &exit, 1);
                std::memcpy(ram + task + 10, &timer, 1);
                static bool reported = false;
                if (!reported) { reported = true; std::fprintf(stderr, "[SKIP-INTRO] boot logos skipped (step %u -> 12)\n", unsigned(step)); }
            }
            bootScene(ram, ctx, rt);
        });
    }