# REO Recompiled Game Build
#
# Builds TWO executables from PS2Recomp output:
#   reo_recomp       — RE Outbreak File #1 (SLUS-20765, 3,209 functions)
#   reo_recomp_file2 — RE Outbreak File #2 (SLUS-20984, 3,525 functions)
#
# Both share the bootstrap, overrides, and link against PS2Recomp runtime.

cmake_minimum_required(VERSION 3.20)
project(reo_recomp CXX)

# PS2Recomp paths (shared between both targets)
set(PS2RECOMP_DIR "${CMAKE_SOURCE_DIR}/../third_party/PS2Recomp")
set(PS2RECOMP_BUILD "${PS2RECOMP_DIR}/out/build")

set(PS2RECOMP_INCLUDES
    "${PS2RECOMP_DIR}/ps2xRuntime/include"
    "${PS2RECOMP_DIR}/ps2xRecomp/include"
    "${PS2RECOMP_BUILD}/_deps/elfio-src/include"
    "${PS2RECOMP_BUILD}/_deps/fmt-src/include"
    "${PS2RECOMP_BUILD}/_deps/raylib-src/src"
)

set(PS2RECOMP_LIBS
    "${PS2RECOMP_BUILD}/ps2xRuntime/Release/ps2_runtime.lib"
    "${PS2RECOMP_BUILD}/_deps/raylib-build/raylib/Release/raylib.lib"
    "${PS2RECOMP_BUILD}/_deps/raylib-build/raylib/external/glfw/src/glfw.dir/Release/glfw.lib"
    "${PS2RECOMP_BUILD}/_deps/fmt-build/Release/fmt.lib"
    "${PS2RECOMP_BUILD}/_deps/libdwarf-build/src/lib/libdwarf/Release/dwarf.lib"
)

# Helper function to set up a recomp target
function(add_recomp_target TARGET_NAME OUTPUT_DIR GAME_DEFINE)
    file(GLOB RECOMP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/config/${OUTPUT_DIR}/*.cpp")
    list(LENGTH RECOMP_SOURCES RECOMP_COUNT)
    message(STATUS "REO [${TARGET_NAME}]: Found ${RECOMP_COUNT} recompiled source files in ${OUTPUT_DIR}")

    if(RECOMP_COUNT EQUAL 0)
        message(WARNING "No recompiled source files found in config/${OUTPUT_DIR}/")
        message(WARNING "Run ps2xAnalyzer and ps2xRecomp first (see README)")
        return()
    endif()

    add_executable(${TARGET_NAME}
        reo_bootstrap.cpp
        overrides/reo_override.cpp
        ${RECOMP_SOURCES}
    )

    target_include_directories(${TARGET_NAME} PRIVATE
        ${PS2RECOMP_INCLUDES}
        "${CMAKE_CURRENT_SOURCE_DIR}/config/${OUTPUT_DIR}"
    )

    target_link_libraries(${TARGET_NAME} PRIVATE ${PS2RECOMP_LIBS})

    if(WIN32)
        target_link_libraries(${TARGET_NAME} PRIVATE
            opengl32 gdi32 winmm user32 shell32 ole32 advapi32
        )
    endif()

    target_compile_features(${TARGET_NAME} PRIVATE cxx_std_20)

    if(MSVC)
        target_compile_options(${TARGET_NAME} PRIVATE
            /W0           # Disable warnings for generated code
            /bigobj       # Generated files can be large
            /MP           # Parallel compilation (use all cores)
            /O2           # Optimize
        )
    endif()

    target_compile_definitions(${TARGET_NAME} PRIVATE
        _CRT_SECURE_NO_WARNINGS
        NOMINMAX
        WIN32_LEAN_AND_MEAN
        ${GAME_DEFINE}
    )
endfunction()

# ── File #1: RE Outbreak (SLUS-20765) ──────────────────────────────
add_recomp_target(reo_recomp "output" "REO_GAME_FILE1")

# ── File #2: RE Outbreak File #2 (SLUS-20984) ─────────────────────
add_recomp_target(reo_recomp_file2 "output_file2" "REO_GAME_FILE2")
