# Native ARM64 development dependencies. No Windows archives are used on macOS.
if(NOT CMAKE_SYSTEM_PROCESSOR MATCHES "arm64|aarch64")
    message(FATAL_ERROR "The macOS port currently targets Apple Silicon")
endif()
set(PS2RECOMP_LIBS
    "${PS2RECOMP_BUILD}/ps2xRuntime/libps2_runtime.a"
    "${PS2RECOMP_BUILD}/_deps/raylib-build/raylib/libraylib.a"
    "${PS2RECOMP_BUILD}/_deps/fmt-build/libfmt.a"
    "-framework CoreGraphics" "-framework Cocoa" "-framework IOKit" "-framework CoreVideo"
    "-framework OpenGL" "-framework Metal" "-framework QuartzCore"
    "-framework CoreAudio" "-framework AudioToolbox" "-framework GameController" "-framework CoreHaptics")
list(APPEND PS2RECOMP_INCLUDES
    "${PS2RECOMP_BUILD}/_deps/sse2neon-src")
if(REO_BUILD_GPU_GS)
    target_compile_definitions(reo_parallel_backend_native PRIVATE REO_MACOS_METAL_PRESENT USE_SSE2NEON)
    target_include_directories(reo_parallel_backend_native PRIVATE
        "${PS2RECOMP_BUILD}/_deps/sse2neon-src")
    target_compile_features(reo_parallel_backend_native PRIVATE cxx_std_20)
endif()
