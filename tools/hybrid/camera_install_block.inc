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