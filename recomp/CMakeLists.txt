# REO Recompiled Game Build
#
# Builds TWO executables from PS2Recomp output:
#   reo_recomp       — RE Outbreak File #1 (SLUS-20765, 3,209 functions)
#   reo_recomp_file2 — RE Outbreak File #2 (SLUS-20984, 3,525 functions)
#
# Both share the bootstrap, overrides, runtime HLE, and link against PS2Recomp runtime.

cmake_minimum_required(VERSION 3.20)
project(reo_recomp CXX)

# PS2Recomp paths (shared between both targets)
set(PS2RECOMP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../third_party/PS2Recomp")
set(PS2RECOMP_BUILD "${PS2RECOMP_DIR}/out/build")

# REO runtime sources (hardware emulation subsystems)
set(REO_RUNTIME_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../runtime")

# Build-speed knobs for the ~3,900 generated sources (see docs/BASELINE.md).
# Hand-written sources always use /O2; only generated/overlay code uses REO_RECOMP_OPT.
set(REO_RECOMP_OPT "/O2" CACHE STRING "MSVC optimization flag for generated recompiled code (/O2, /O1, /Od)")
option(REO_RECOMP_PCH "Precompile the runtime headers shared by all generated sources" ON)
# Escape hatch: generated files compiled with /Od regardless of REO_RECOMP_OPT, for
# pathological translation units. Runtime cost: the listed functions are unoptimized.
set(REO_RECOMP_OD_SOURCES "" CACHE STRING
    "Semicolon-separated generated file names to compile with /Od (empty = none)")

set(PS2RECOMP_INCLUDES
    "${PS2RECOMP_DIR}/ps2xRuntime/include"
    "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/Kernel"
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

# REO runtime HLE sources — compiled into each recomp target
set(REO_RUNTIME_SOURCES
    "${REO_RUNTIME_DIR}/gs/gs_renderer.cpp"
    "${REO_RUNTIME_DIR}/vu/vu_interpreter.cpp"
    "${REO_RUNTIME_DIR}/input/input.cpp"
    "${REO_RUNTIME_DIR}/cdvd/cdvd.cpp"
)

# Helper function to set up a recomp target
function(add_recomp_target TARGET_NAME OUTPUT_DIR GAME_DEFINE)
    file(GLOB RECOMP_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/config/${OUTPUT_DIR}/*.cpp")
    list(LENGTH RECOMP_SOURCES RECOMP_COUNT)
    message(STATUS "REO [${TARGET_NAME}]: Found ${RECOMP_COUNT} recompiled source files in ${OUTPUT_DIR}")

    if(RECOMP_COUNT EQUAL 0)
        message(WARNING "No recompiled source files found in config/${OUTPUT_DIR}/")
        message(WARNING "Run ps2xAnalyzer and ps2xRecomp first (see README)")
        return()
    endif()

    # Overlay functions (runtime-loaded code dumped from PCSX2)
    set(OVERLAY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/config/output_overlay")
    if(EXISTS "${OVERLAY_DIR}")
        file(GLOB OVERLAY_SOURCES CONFIGURE_DEPENDS "${OVERLAY_DIR}/*.cpp")
        list(LENGTH OVERLAY_SOURCES OVERLAY_COUNT)
        if(OVERLAY_COUNT GREATER 0)
            message(STATUS "REO [${TARGET_NAME}]: Found ${OVERLAY_COUNT} overlay source files")
        endif()
    else()
        set(OVERLAY_SOURCES "")
    endif()

    set(_reo_handwritten_sources
        reo_bootstrap.cpp
        overrides/reo_override.cpp
        overrides/reo_hw_bridge.cpp
        overrides/reo_trace_logger.cpp
        overrides/reo_netbio.cpp
        "${CMAKE_CURRENT_SOURCE_DIR}/../game/formats/nbd_parser.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../game/formats/amo_parser.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../game/formats/nbd_renderer.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../media/tim2/tim2_loader.cpp"
        ${REO_RUNTIME_SOURCES}
    )

    add_executable(${TARGET_NAME}
        ${_reo_handwritten_sources}
        ${RECOMP_SOURCES}
        ${OVERLAY_SOURCES}
    )

    target_include_directories(${TARGET_NAME} PRIVATE
        ${PS2RECOMP_INCLUDES}
        "${CMAKE_CURRENT_SOURCE_DIR}/config/${OUTPUT_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/config/output_overlay"
        "${CMAKE_CURRENT_SOURCE_DIR}/overrides"
        "${CMAKE_CURRENT_SOURCE_DIR}/.."
        "${CMAKE_CURRENT_SOURCE_DIR}/../game"
        "${CMAKE_CURRENT_SOURCE_DIR}/../media"
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
        )
        if(CMAKE_GENERATOR MATCHES "Visual Studio")
            # Parallel compilation (limit to 4 cores to avoid OOM); Ninja uses -j instead
            target_compile_options(${TARGET_NAME} PRIVATE /MP4)
        endif()
        set_source_files_properties(${RECOMP_SOURCES} ${OVERLAY_SOURCES}
            TARGET_DIRECTORY ${TARGET_NAME}
            PROPERTIES COMPILE_OPTIONS "${REO_RECOMP_OPT}")
        foreach(_od_name IN LISTS REO_RECOMP_OD_SOURCES)
            foreach(_src IN LISTS RECOMP_SOURCES OVERLAY_SOURCES)
                get_filename_component(_src_name "${_src}" NAME)
                if(_src_name STREQUAL _od_name)
                    set_source_files_properties("${_src}"
                        TARGET_DIRECTORY ${TARGET_NAME}
                        PROPERTIES COMPILE_OPTIONS "/Od")
                    message(STATUS "REO [${TARGET_NAME}]: ${_od_name} compiled with /Od")
                endif()
            endforeach()
        endforeach()
        set_source_files_properties(${_reo_handwritten_sources}
            TARGET_DIRECTORY ${TARGET_NAME}
            PROPERTIES COMPILE_OPTIONS "/O2")
    endif()

    if(REO_RECOMP_PCH)
        # Same include order as the generated files' preamble.
        target_precompile_headers(${TARGET_NAME} PRIVATE
            "<ps2_runtime_macros.h>"
            "<ps2_runtime.h>"
            "<ps2_recompiled_functions.h>"
            "<ps2_recompiled_stubs.h>"
            "<ps2_syscalls.h>"
            "<ps2_stubs.h>"
        )
        set_source_files_properties(${_reo_handwritten_sources}
            TARGET_DIRECTORY ${TARGET_NAME}
            PROPERTIES SKIP_PRECOMPILE_HEADERS ON)
    endif()

    target_compile_definitions(${TARGET_NAME} PRIVATE
        _CRT_SECURE_NO_WARNINGS
        NOMINMAX
        WIN32_LEAN_AND_MEAN
        REO_PLATFORM_WINDOWS
        ${GAME_DEFINE}
    )
endfunction()

# ── File #1: RE Outbreak (SLUS-20765) ──────────────────────────────
add_recomp_target(reo_recomp "output" "REO_GAME_FILE1")

# ── File #2: RE Outbreak File #2 (SLUS-20984) ─────────────────────
add_recomp_target(reo_recomp_file2 "output_file2" "REO_GAME_FILE2")
