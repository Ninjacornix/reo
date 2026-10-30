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



option(REO_BUILD_GPU_GS "Link the validated paraLLEl-GS adapter; select with REO_GS_BACKEND=parallel" OFF)

# Source-only guarded wrapper registration. Runtime source ownership remains
# hard-disabled until the direct-context/upstream/reset closure is implemented.
option(REO_BUILD_GPU_PARENT_NATURAL_HOOKS "Build connected guarded File1 parent wrappers" OFF)
option(REO_BUILD_GUARDED_SOURCE_OVERLAY "Compile build-only guarded generated source copies" OFF)

set(REO_PARALLEL_GS_BUILD "${CMAKE_CURRENT_SOURCE_DIR}/../build-ninja/m2-gpu-gs-adapter/out" CACHE PATH "Built pinned paraLLEl-GS libraries")

set(REO_PARALLEL_GS_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/../build-ninja/parallel-gs-source" CACHE PATH "Pinned headers matching the existing GS libraries")

# The live handwritten adapter is built below; an old external adapter archive
# cannot safely share the evolving private Config/Frame ABI with this executable.

set(REO_VULKAN_LOADER_FILE "" CACHE FILEPATH "Optional existing Vulkan loader to copy beside the executable")

set(REO_VU_SPECIALIZED_SOURCE "" CACHE FILEPATH "Optional locally generated VU programs; game bytes remain outside the runtime")

# Vulkan SDK shader tools. Any installed SDK at or above the minimum works; its location comes from the
# VULKAN_SDK variable set by the LunarG installer (or PATH). 1.4.321 is the oldest SDK this project has been
# built with (1.4.363 also verified); lower REO_VULKAN_SDK_MIN only to try an older, untested SDK.
set(REO_VULKAN_SDK_MIN "1.4.321" CACHE STRING "Minimum Vulkan SDK version for shader compilation")
if(NOT Vulkan_FOUND)
    find_package(Vulkan QUIET)
endif()
set(_reo_vulkan_bin "")
if(Vulkan_INCLUDE_DIRS)
    get_filename_component(_reo_vulkan_bin "${Vulkan_INCLUDE_DIRS}/../Bin" ABSOLUTE)
endif()
find_program(REO_GLSLANG_VALIDATOR NAMES glslangValidator
    HINTS "${_reo_vulkan_bin}" "$ENV{VULKAN_SDK}/Bin" "$ENV{VULKAN_SDK}/bin")
find_program(REO_SPIRV_VAL NAMES spirv-val
    HINTS "${_reo_vulkan_bin}" "$ENV{VULKAN_SDK}/Bin" "$ENV{VULKAN_SDK}/bin")
macro(reo_require_vulkan_shader_tools)
    if(NOT REO_GLSLANG_VALIDATOR OR NOT REO_SPIRV_VAL)
        message(FATAL_ERROR "glslangValidator/spirv-val not found. Install the Vulkan SDK ${REO_VULKAN_SDK_MIN} or newer "
                            "(its installer sets VULKAN_SDK), or set REO_GLSLANG_VALIDATOR and REO_SPIRV_VAL.")
    endif()
    if(NOT Vulkan_VERSION)
        message(FATAL_ERROR "Vulkan SDK version could not be determined; install the Vulkan SDK ${REO_VULKAN_SDK_MIN} or newer.")
    endif()
    if(Vulkan_VERSION VERSION_LESS REO_VULKAN_SDK_MIN)
        message(FATAL_ERROR "Vulkan SDK ${Vulkan_VERSION} is older than the required ${REO_VULKAN_SDK_MIN}. "
                            "Install a newer SDK, or set -DREO_VULKAN_SDK_MIN to try an older one (untested).")
    endif()
endmacro()

set(REO_VU_WHOLE_SOURCE "" CACHE FILEPATH "Optional locally generated whole-program VU AOT (tools/vu_whole_aot); game bytes stay in ignored output")

set(REO_VU_NATIVE_GEOMETRY_SOURCE "" CACHE FILEPATH "Optional File #1 native geometry factory; requires exact generated VU identities")

option(REO_BUILD_NATIVE_64E_RIGID "Enable proved additional File #1 rigid kernel; generated factory must contain its exact image" OFF)

option(REO_BUILD_NATIVE_STATIC_HALFSPACE "Enable proved File #1 native polygon clipping" OFF)

option(REO_BUILD_NATIVE_STATIC_PROJECTION "Enable proved File #1 native clipped-polygon projection" OFF)

if(REO_VU_SPECIALIZED_SOURCE AND NOT EXISTS "${REO_VU_SPECIALIZED_SOURCE}")

    message(FATAL_ERROR "Generated VU source missing: ${REO_VU_SPECIALIZED_SOURCE}")

endif()

if(REO_VU_NATIVE_GEOMETRY_SOURCE)

    if(NOT REO_VU_SPECIALIZED_SOURCE OR NOT EXISTS "${REO_VU_NATIVE_GEOMETRY_SOURCE}")

        message(FATAL_ERROR "Native geometry requires existing generated VU source and factory: ${REO_VU_NATIVE_GEOMETRY_SOURCE}")

    endif()

endif()

if((REO_BUILD_NATIVE_64E_RIGID OR REO_BUILD_NATIVE_STATIC_HALFSPACE OR REO_BUILD_NATIVE_STATIC_PROJECTION)

        AND NOT REO_VU_NATIVE_GEOMETRY_SOURCE)

    message(FATAL_ERROR "Optional native geometry kernels require a configured native factory")

endif()

if(REO_BUILD_GPU_GS)

    set(_reo_gpu_libraries)

    foreach(_entry IN ITEMS "Granite/vulkan/granite-vulkan"

            "Granite/third_party/granite-volk" "Granite/util/granite-util" "Granite/math/granite-math")

        get_filename_component(_part "${_entry}" DIRECTORY)

        get_filename_component(_stem "${_entry}" NAME)

        list(APPEND _reo_gpu_libraries "${REO_PARALLEL_GS_BUILD}/parallel-gs/${_part}/Release/${_stem}.lib")

    endforeach()

    foreach(_library IN LISTS _reo_gpu_libraries)

        if(NOT EXISTS "${_library}")

            message(FATAL_ERROR "GPU GS library missing: ${_library}")

        endif()

    endforeach()

    set(_reo_adapter_source "${CMAKE_CURRENT_SOURCE_DIR}/../tools/parallel_gs_backend")
    set(_reo_native_gs_dir "${_reo_adapter_source}/resident_gs")
    # These handwritten targets exchange C++ objects and inline methods. Keep
    # their header cohort explicit even when a compiler launcher does not
    # return /showIncludes dependencies (a stale movie object otherwise reads
    # GS registers at the old class offset). Generated game TUs stay separate.
    file(GLOB_RECURSE _reo_graphics_cohort_headers CONFIGURE_DEPENDS
        "${_reo_adapter_source}/*.h" "${_reo_adapter_source}/*.hpp")
    list(APPEND _reo_graphics_cohort_headers
        "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/gs_backend_route.h"
        "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/resident_vif_commands.h")
    add_library(reo_parallel_gs_resident_native STATIC
        "${_reo_native_gs_dir}/gs_interface.cpp" "${_reo_native_gs_dir}/gs_renderer.cpp"
        "${_reo_native_gs_dir}/gs_util.cpp" "${_reo_native_gs_dir}/page_tracker.cpp")
    target_include_directories(reo_parallel_gs_resident_native PRIVATE
        "${_reo_native_gs_dir}" "${REO_PARALLEL_GS_SOURCE}/gs"
        "${REO_PARALLEL_GS_SOURCE}/Granite/vulkan" "${REO_PARALLEL_GS_SOURCE}/Granite/util"
        "${REO_PARALLEL_GS_SOURCE}/Granite/math" "${REO_PARALLEL_GS_SOURCE}/Granite/application/global"
        "${REO_PARALLEL_GS_SOURCE}/Granite/third_party/volk"
        "${REO_PARALLEL_GS_SOURCE}/Granite/third_party/khronos/vulkan-headers/include")
    target_compile_features(reo_parallel_gs_resident_native PRIVATE cxx_std_17)
    reo_require_vulkan_shader_tools()
    set(_aniso_source "${_reo_native_gs_dir}/shaders")
    set(_aniso_output "${CMAKE_CURRENT_BINARY_DIR}/anisotropic-shaders")
    file(GLOB _aniso_includes "${REO_PARALLEL_GS_SOURCE}/gs/shaders/*.h")
    add_custom_command(OUTPUT "${_aniso_output}/anisotropic_spirv.hpp"
        COMMAND ${CMAKE_COMMAND}
            "-DUPSTREAM=${REO_PARALLEL_GS_SOURCE}/gs/shaders"
            "-DOUT=${_aniso_output}"
            "-DGLSLANG=${REO_GLSLANG_VALIDATOR}"
            "-DVALIDATOR=${REO_SPIRV_VAL}"
            -P "${_aniso_source}/BuildAnisotropic.cmake"
        DEPENDS "${_aniso_source}/BuildAnisotropic.cmake" "${_aniso_source}/anisotropic.glsl"
            "${REO_PARALLEL_GS_SOURCE}/gs/shaders/ubershader.comp" ${_aniso_includes}
        VERBATIM)
    target_sources(reo_parallel_gs_resident_native PRIVATE "${_aniso_output}/anisotropic_spirv.hpp")
    target_include_directories(reo_parallel_gs_resident_native PRIVATE "${_aniso_output}")
    target_compile_definitions(reo_parallel_gs_resident_native PRIVATE NOMINMAX GRANITE_SHIPPING
        HAVE_WSI_DXGI_INTEROP _CRT_SECURE_NO_WARNINGS)
    if(MSVC)
        set_property(TARGET reo_parallel_gs_resident_native PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
        target_compile_options(reo_parallel_gs_resident_native PRIVATE /O2 /fp:precise /wd4267 /wd4244 /wd4309 /wd4005)
    endif()
    set_property(TARGET reo_parallel_gs_resident_native PROPERTY UNITY_BUILD OFF)
    target_link_libraries(reo_parallel_gs_resident_native PRIVATE ${_reo_gpu_libraries})
    list(PREPEND _reo_gpu_libraries reo_parallel_gs_resident_native)

    set(_reo_route_source "${PS2RECOMP_DIR}/ps2xRuntime/src/lib")
    foreach(_required IN ITEMS "${_reo_adapter_source}/parallel_backend.cpp"
            "${_reo_route_source}/gs_backend_route.h"
            "${_reo_route_source}/gpu_display_transport.h"
            "${_reo_native_gs_dir}/gs_interface.hpp")
        if(NOT EXISTS "${_required}")
            message(FATAL_ERROR "GPU adapter source/header missing: ${_required}")
        endif()
    endforeach()
    # One handwritten TU. Header dependencies automatically rebuild the private
    # adapter when Config/Frame/presenter/route changes; no generated TU defines
    # or include paths are introduced by this target.
    add_library(reo_parallel_backend_native STATIC "${_reo_adapter_source}/parallel_backend.cpp")
    target_include_directories(reo_parallel_backend_native PRIVATE
        "${_reo_adapter_source}" "${_reo_route_source}" "${_reo_native_gs_dir}"
        "${REO_PARALLEL_GS_SOURCE}/gs" "${REO_PARALLEL_GS_SOURCE}/Granite/vulkan"
        "${REO_PARALLEL_GS_SOURCE}/Granite/util" "${REO_PARALLEL_GS_SOURCE}/Granite/math"
        "${REO_PARALLEL_GS_SOURCE}/Granite/application/global"
        "${REO_PARALLEL_GS_SOURCE}/Granite/third_party/volk"
        "${REO_PARALLEL_GS_SOURCE}/Granite/third_party/khronos/vulkan-headers/include")
    # Resident owner/catalogue includes are private to handwritten sources.
    # Public runtime/PCH/generated-TU headers and compile definitions are intact.
    set(_reo_resident_geometry_dir "${_reo_adapter_source}/resident_geometry")
    target_include_directories(reo_parallel_backend_native PRIVATE "${_reo_resident_geometry_dir}")
    target_include_directories(reo_parallel_backend_native PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/.."
        "${PS2RECOMP_DIR}/ps2xRuntime/include" "${PS2RECOMP_DIR}/ps2xRuntime/src/lib"
        "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/Kernel")
    target_sources(reo_parallel_backend_native PRIVATE "${_reo_resident_geometry_dir}/enrollment/installer.cpp")
    if(WIN32)
        target_sources(reo_parallel_backend_native PRIVATE
            "${_reo_adapter_source}/movie_runtime/movie_owner_service.cpp"
            "${_reo_adapter_source}/movie_runtime/import_receipt.cpp")
        target_compile_features(reo_parallel_backend_native PRIVATE cxx_std_20)
        target_link_libraries(reo_parallel_backend_native PRIVATE d3d11 dxgi dxguid)
        # Replace the pinned allocator object at the final executable link. The
        # original vendor source stays untouched; only its successful external
        # NT-handle close emits a receipt used by the ownership transaction.
        set(_reo_movie_allocator_source "${REO_PARALLEL_GS_SOURCE}/Granite/vulkan/memory_allocator.cpp")
        file(SHA256 "${_reo_movie_allocator_source}" _reo_movie_allocator_sha)
        if(NOT _reo_movie_allocator_sha STREQUAL "259c858fe1af5daff2a8a61129e333bf8dff0daa52219f0eeea63d63150a4143")
            message(FATAL_ERROR "Native movie import provider requires its reviewed pinned Granite allocator")
        endif()
        file(READ "${_reo_movie_allocator_source}" _reo_movie_allocator_original)
        string(REPLACE "::CloseHandle(external->handle);"
            "const bool reo_movie_handle_closed = ::CloseHandle(external->handle) != FALSE;\n\t\treo_movie_import::provider_closed(reinterpret_cast<uintptr_t>(external->handle), reo_movie_handle_closed);"
            _reo_movie_allocator_patched "${_reo_movie_allocator_original}")
        if(_reo_movie_allocator_patched STREQUAL _reo_movie_allocator_original)
            message(FATAL_ERROR "Pinned Granite external handle import site was not found")
        endif()
        set(_reo_movie_allocator_cpp "${CMAKE_CURRENT_BINARY_DIR}/reo_movie_memory_allocator.cpp")
        file(GENERATE OUTPUT "${_reo_movie_allocator_cpp}"
            CONTENT "#include \"movie_runtime/import_receipt.h\"\n${_reo_movie_allocator_patched}")
        add_library(reo_movie_allocator_native OBJECT "${_reo_movie_allocator_cpp}")
        target_compile_features(reo_movie_allocator_native PRIVATE cxx_std_20)
        target_include_directories(reo_movie_allocator_native PRIVATE
            "${_reo_adapter_source}" "${REO_PARALLEL_GS_SOURCE}/Granite/vulkan"
            "${REO_PARALLEL_GS_SOURCE}/Granite/util" "${REO_PARALLEL_GS_SOURCE}/Granite/math"
            "${REO_PARALLEL_GS_SOURCE}/Granite/application/global"
            "${REO_PARALLEL_GS_SOURCE}/Granite/third_party/renderdoc"
            "${REO_PARALLEL_GS_SOURCE}/Granite/third_party/volk"
            "${REO_PARALLEL_GS_SOURCE}/Granite/third_party/khronos/vulkan-headers/include")
        target_compile_definitions(reo_movie_allocator_native PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS
            GRANITE_SHIPPING HAVE_WSI_DXGI_INTEROP GRANITE_RENDERDOC_CAPTURE)
        if(MSVC)
            set_property(TARGET reo_movie_allocator_native PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
            target_compile_options(reo_movie_allocator_native PRIVATE /O2 /fp:precise /W0)
        endif()
        set_property(TARGET reo_movie_allocator_native PROPERTY UNITY_BUILD OFF)
    endif()
    set_property(SOURCE "${_reo_resident_geometry_dir}/enrollment/installer.cpp" APPEND PROPERTY COMPILE_DEFINITIONS REO_GPU_CATALOG_LITERAL_REUSE)
    set_property(SOURCE reo_bootstrap.cpp APPEND PROPERTY INCLUDE_DIRECTORIES
        "${_reo_resident_geometry_dir}" "${_reo_route_source}" "${_reo_native_gs_dir}"
        "${REO_PARALLEL_GS_SOURCE}/gs" "${REO_PARALLEL_GS_SOURCE}/Granite/vulkan"
        "${REO_PARALLEL_GS_SOURCE}/Granite/util" "${REO_PARALLEL_GS_SOURCE}/Granite/math"
        "${REO_PARALLEL_GS_SOURCE}/Granite/application/global"
        "${REO_PARALLEL_GS_SOURCE}/Granite/third_party/volk"
        "${REO_PARALLEL_GS_SOURCE}/Granite/third_party/khronos/vulkan-headers/include")
    set_property(SOURCE reo_bootstrap.cpp APPEND PROPERTY COMPILE_DEFINITIONS
        NOMINMAX GRANITE_SHIPPING HAVE_WSI_DXGI_INTEROP)
    target_compile_features(reo_parallel_backend_native PRIVATE cxx_std_17)
    target_compile_definitions(reo_parallel_backend_native PRIVATE NOMINMAX GRANITE_SHIPPING)
    if(WIN32)
        target_compile_definitions(reo_parallel_backend_native PRIVATE HAVE_WSI_DXGI_INTEROP)
    endif()
    if(MSVC)
        set_property(TARGET reo_parallel_backend_native PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
        target_compile_options(reo_parallel_backend_native PRIVATE /O2 /fp:precise /W4)
    endif()
    set_property(TARGET reo_parallel_backend_native PROPERTY UNITY_BUILD OFF)
    target_link_libraries(reo_parallel_backend_native PRIVATE ${_reo_gpu_libraries})
    list(PREPEND _reo_gpu_libraries reo_parallel_backend_native)

    foreach(_reo_graphics_target IN ITEMS
            reo_parallel_gs_resident_native reo_parallel_backend_native)
        get_target_property(_reo_graphics_sources ${_reo_graphics_target} SOURCES)
        set_property(SOURCE ${_reo_graphics_sources} APPEND PROPERTY
            OBJECT_DEPENDS "${_reo_graphics_cohort_headers}")
    endforeach()
    set_property(SOURCE reo_bootstrap.cpp APPEND PROPERTY
        OBJECT_DEPENDS "${_reo_graphics_cohort_headers}")

endif()



set_property(SOURCE overrides/reo_gpu_palette_origin.cpp APPEND PROPERTY INCLUDE_DIRECTORIES
    "${PS2RECOMP_DIR}/ps2xRuntime/src/lib")

# REO runtime sources (hardware emulation subsystems)

set(REO_RUNTIME_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../runtime")



# Build-speed knobs for the ~3,900 generated sources (see docs/BASELINE.md).

# Hand-written sources always use /O2; only generated/overlay code uses REO_RECOMP_OPT.

set(REO_RECOMP_OPT "/O2" CACHE STRING "MSVC optimization flag for generated recompiled code (/O2, /O1, /Od)")

option(REO_RECOMP_PCH "Precompile the runtime headers shared by all generated sources" ON)

# Unity build (as upstream PS2Recomp's runner does): generated sources are compiled in

# batches, so the shared runtime headers are parsed once per batch instead of per file.

# Batch 8 keeps a compiler process around 0.5-1 GB. Hand-written sources are never merged.

option(REO_UNITY_BUILD "Compile generated sources as unity batches" ON)

set(REO_UNITY_BATCH 8 CACHE STRING "Generated sources per unity batch")

set(REO_UNITY_MAX_FILE 500000 CACHE STRING "Generated sources larger than this (bytes) are not merged")

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



# Diagnostics: AddressSanitizer on hand-written code only (reo sources + the PS2Recomp

# runtime built in out/build-asan with /fsanitize=address); generated code is untouched,

# so toggling it recompiles only the hand-written files.

option(REO_ASAN "Instrument hand-written sources and link the ASan ps2_runtime (out/build-asan)" OFF)

if(REO_ASAN)

    set(_reo_ps2_runtime_lib "${PS2RECOMP_DIR}/out/build-asan/ps2xRuntime/Release/ps2_runtime.lib")

else()

    set(_reo_ps2_runtime_lib "${PS2RECOMP_BUILD}/ps2xRuntime/Release/ps2_runtime.lib")

endif()



set(PS2RECOMP_LIBS

    "${_reo_ps2_runtime_lib}"

    "${PS2RECOMP_BUILD}/_deps/raylib-build/raylib/Release/raylib.lib"

    "${PS2RECOMP_BUILD}/_deps/raylib-build/raylib/external/glfw/src/glfw.dir/Release/glfw.lib"

    "${PS2RECOMP_BUILD}/_deps/fmt-build/Release/fmt.lib"

    "${PS2RECOMP_BUILD}/_deps/libdwarf-build/src/lib/libdwarf/Release/dwarf.lib"

)



if(WIN32)
    enable_language(C)
    include("${CMAKE_CURRENT_SOURCE_DIR}/../cmake/ReoAudioOutput.cmake")
    set(REO_AUDIO_OUTPUT_SOURCE "${CMAKE_CURRENT_BINARY_DIR}/reo_audio_output.c")
    reo_audio_output_source("${PS2RECOMP_BUILD}/_deps/raylib-src/src/raudio.c" "${REO_AUDIO_OUTPUT_SOURCE}")
    set_source_files_properties("${REO_AUDIO_OUTPUT_SOURCE}" PROPERTIES SKIP_UNITY_BUILD_INCLUSION ON SKIP_PRECOMPILE_HEADERS ON
        COMPILE_DEFINITIONS "MA_DEFAULT_PERIOD_SIZE_IN_MILLISECONDS_LOW_LATENCY=5;MA_DEFAULT_PERIODS=2")
endif()

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

    # Sibling generated directories (output_overlay, output_extra, output_ovl) sit
    # next to OUTPUT_DIR: recomp/config for File #1, recomp/config/output_file2 for
    # File #2 (tools/local_build/generate_game.py --game file2).
    get_filename_component(_reo_generated_root "${CMAKE_CURRENT_SOURCE_DIR}/config/${OUTPUT_DIR}" DIRECTORY)

    list(LENGTH RECOMP_SOURCES RECOMP_COUNT)

    message(STATUS "REO [${TARGET_NAME}]: Found ${RECOMP_COUNT} recompiled source files in ${OUTPUT_DIR}")



    if(RECOMP_COUNT EQUAL 0)

        message(WARNING "No recompiled source files found in config/${OUTPUT_DIR}/")

        message(WARNING "Run ps2xAnalyzer and ps2xRecomp first (see README)")

        return()

    endif()



    # Overlay functions (runtime-loaded code dumped from PCSX2)

    set(OVERLAY_DIR "${_reo_generated_root}/output_overlay")

    if(EXISTS "${OVERLAY_DIR}")

        file(GLOB OVERLAY_SOURCES CONFIGURE_DEPENDS "${OVERLAY_DIR}/*.cpp")

        list(LENGTH OVERLAY_SOURCES OVERLAY_COUNT)

        if(OVERLAY_COUNT GREATER 0)

            message(STATUS "REO [${TARGET_NAME}]: Found ${OVERLAY_COUNT} overlay source files")

        endif()

    else()

        set(OVERLAY_SOURCES "")

    endif()



    # Code overlays extracted from the user's ISO and recompiled per overlay

    # (tools/overlay_extract.py, tools/overlay_recomp.py); dispatched by resident overlay id.

    # Extra main-ELF entry points the Ghidra map merged into neighbours (tools/extra_recomp.py).

    set(EXTRA_DIR "${_reo_generated_root}/output_extra")

    if(EXISTS "${EXTRA_DIR}/register_extra.cpp")

        file(GLOB EXTRA_SOURCES CONFIGURE_DEPENDS "${EXTRA_DIR}/*.cpp")

        list(APPEND OVERLAY_SOURCES ${EXTRA_SOURCES})

        set(REO_HAVE_EXTRA ON)

    endif()



    set(OVL_DIR "${_reo_generated_root}/output_ovl")

    if(EXISTS "${OVL_DIR}/register_overlays.cpp")

        file(GLOB OVL_SOURCES CONFIGURE_DEPENDS "${OVL_DIR}/*.cpp" "${OVL_DIR}/*/*.cpp")

        list(LENGTH OVL_SOURCES OVL_COUNT)

        message(STATUS "REO [${TARGET_NAME}]: Found ${OVL_COUNT} per-overlay source files")

        list(APPEND OVERLAY_SOURCES ${OVL_SOURCES})

        set(REO_HAVE_OVL ON)

    endif()



    if(REO_BUILD_GUARDED_SOURCE_OVERLAY)
        include("${CMAKE_CURRENT_SOURCE_DIR}/../tools/source_instrumentation/build_overlay.cmake")
        reo_emit_guarded_sources(RECOMP_SOURCES ${RECOMP_SOURCES})
        reo_emit_guarded_sources(OVERLAY_SOURCES ${OVERLAY_SOURCES})
    endif()

    set(_reo_handwritten_sources

        reo_bootstrap.cpp

        overrides/reo_override.cpp

        overrides/reo_hw_bridge.cpp

        overrides/reo_gpu_palette_origin.cpp

        overrides/reo_trace_logger.cpp

        overrides/reo_netbio.cpp

        overrides/reo_vu_specialized.cpp

        "${CMAKE_CURRENT_SOURCE_DIR}/../game/formats/nbd_parser.cpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/../game/formats/amo_parser.cpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/../game/formats/nbd_renderer.cpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/../media/tim2/tim2_loader.cpp"

        ${REO_RUNTIME_SOURCES}

    )

    # File #1 code images must never be registered for File #2.

    if(GAME_DEFINE STREQUAL "REO_GAME_FILE1")
        if(REO_BUILD_GPU_PARENT_NATURAL_HOOKS)
            list(APPEND _reo_handwritten_sources
                overrides/gpu_parent_natural/parent_natural_body.cpp
                overrides/gpu_parent_natural/parent_natural_aggregate.cpp
                overrides/gpu_parent_natural/parent_body_install.cpp)
        endif()
        # Integer IRQ control implementations belong only to File #1.
        # Runtime remains independently linkable; these sources contain no FP/VF work.
        set(_reo_irq_integer_sources
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/irq_cpu_control.cpp"
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/irq_cpu_game_provider.cpp"
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/irq_cpu_original/sub_00102F08_0x102f08.cpp"
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/irq_cpu_original/sub_00103000_0x103000.cpp"
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/irq_cpu_original/sub_00103390_0x103390.cpp"
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/irq_cpu_original/sub_001036A0_0x1036a0.cpp"
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/irq_cpu_original/sub_001143C0_0x1143c0.cpp"
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/irq_cpu_original/sub_001152A0_0x1152a0.cpp"
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/irq_cpu_original/sub_0011D660_0x11d660.cpp"
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/irq_cpu_original/sub_0011D6B8_0x11d6b8.cpp"
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/irq_cpu_original/sub_0018D160_0x18d160.cpp"
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/irq_cpu_original/sub_0018DCA0_0x18dca0.cpp"
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/irq_cpu_original/sub_001A0D70_0x1a0d70.cpp"
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib/irq_cpu_original/sub_001A1330_0x1a1330.cpp")
        list(APPEND _reo_handwritten_sources ${_reo_irq_integer_sources})
        set_property(SOURCE ${_reo_irq_integer_sources} APPEND PROPERTY INCLUDE_DIRECTORIES
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/.."
            "${CMAKE_CURRENT_SOURCE_DIR}/../tools/parallel_gs_backend/resident_geometry")
        list(APPEND _reo_handwritten_sources overrides/ground_query_diagnostic.cpp)
        # Unregistered File #1 entry points (resume PCs, stutter fixes).
        list(APPEND _reo_handwritten_sources overrides/reo_missing_entries.cpp)
        if(WIN32 AND REO_BUILD_GPU_GS)
            set(_reo_movie_game_sources
                "${_reo_adapter_source}/movie_runtime/native_movie_game.cpp"
                "${_reo_adapter_source}/movie_runtime/original_graphics_route.cpp"
                "${_reo_adapter_source}/movie_runtime/original_transport_route.cpp"
                "${_reo_adapter_source}/movie_runtime/original_transport_1570d8.cpp"
                "${_reo_adapter_source}/movie_runtime/original_transport_170ae8.cpp"
                "${_reo_adapter_source}/movie_runtime/original_transport_170d90.cpp"
                "${_reo_adapter_source}/movie_runtime/original_transport_171880.cpp"
                "${_reo_adapter_source}/movie_runtime/original_transport_171d10.cpp"
                "${_reo_adapter_source}/movie_runtime/original_transport_16aea0.cpp"
                "${_reo_adapter_source}/movie_runtime/original_transport_174030.cpp"
                "${_reo_adapter_source}/movie_runtime/original_transport_171920.cpp")
            list(APPEND _reo_handwritten_sources ${_reo_movie_game_sources})
            set_property(SOURCE ${_reo_movie_game_sources} APPEND PROPERTY
                OBJECT_DEPENDS "${_reo_graphics_cohort_headers}")
            set_property(SOURCE ${_reo_movie_game_sources} APPEND PROPERTY INCLUDE_DIRECTORIES
                "${PS2RECOMP_DIR}/ps2xRuntime/src/lib"
                "${CMAKE_CURRENT_SOURCE_DIR}/.."
                "${_reo_adapter_source}" "${_reo_native_gs_dir}"
                "${REO_PARALLEL_GS_SOURCE}/gs" "${REO_PARALLEL_GS_SOURCE}/Granite/vulkan"
                "${REO_PARALLEL_GS_SOURCE}/Granite/util" "${REO_PARALLEL_GS_SOURCE}/Granite/math"
                "${REO_PARALLEL_GS_SOURCE}/Granite/application/global"
                "${REO_PARALLEL_GS_SOURCE}/Granite/third_party/volk"
                "${REO_PARALLEL_GS_SOURCE}/Granite/third_party/khronos/vulkan-headers/include")
            set_property(SOURCE ${_reo_movie_game_sources} APPEND PROPERTY COMPILE_DEFINITIONS
                NOMINMAX GRANITE_SHIPPING HAVE_WSI_DXGI_INTEROP)
        endif()
        list(APPEND _reo_handwritten_sources
            overrides/movie_join_observed_caller.cpp
            overrides/reo_movie_commit_observed.cpp
            overrides/reo_movie_initialize_observed.cpp
            overrides/gpu_palette_parent/parent_observed.cpp
            overrides/gpu_palette_parent/observer_install.cpp)
    elseif(GAME_DEFINE STREQUAL "REO_GAME_FILE2")
        list(APPEND _reo_handwritten_sources overrides/reo_file2_network.cpp)
        # Native movie route: shared handwritten sources (addresses from
        # movie_addresses/file2) plus File #1's copied functions translated by
        # tools/file2_port/port_movie.py copies into the generated tree.
        set(_reo_movie_copies "${_reo_generated_root}/movie_copies")
        if(WIN32 AND REO_BUILD_GPU_GS)
            set(_reo_movie_game_sources
                "${_reo_adapter_source}/movie_runtime/native_movie_game.cpp"
                "${_reo_adapter_source}/movie_runtime/original_graphics_route.cpp"
                "${_reo_adapter_source}/movie_runtime/original_transport_route.cpp"
                "${_reo_movie_copies}/original_transport_1570d8.cpp"
                "${_reo_movie_copies}/original_transport_170ae8.cpp"
                "${_reo_movie_copies}/original_transport_170d90.cpp"
                "${_reo_movie_copies}/original_transport_171880.cpp"
                "${_reo_movie_copies}/original_transport_171d10.cpp"
                "${_reo_movie_copies}/original_transport_16aea0.cpp"
                "${_reo_movie_copies}/original_transport_174030.cpp"
                "${_reo_movie_copies}/original_transport_171920.cpp")
            list(APPEND _reo_handwritten_sources ${_reo_movie_game_sources})
            set_property(SOURCE ${_reo_movie_game_sources} APPEND PROPERTY
                OBJECT_DEPENDS "${_reo_graphics_cohort_headers}")
            set_property(SOURCE ${_reo_movie_game_sources} APPEND PROPERTY INCLUDE_DIRECTORIES
                "${PS2RECOMP_DIR}/ps2xRuntime/src/lib"
                "${CMAKE_CURRENT_SOURCE_DIR}/.."
                "${_reo_adapter_source}" "${_reo_adapter_source}/movie_runtime" "${_reo_native_gs_dir}"
                "${REO_PARALLEL_GS_SOURCE}/gs" "${REO_PARALLEL_GS_SOURCE}/Granite/vulkan"
                "${REO_PARALLEL_GS_SOURCE}/Granite/util" "${REO_PARALLEL_GS_SOURCE}/Granite/math"
                "${REO_PARALLEL_GS_SOURCE}/Granite/application/global"
                "${REO_PARALLEL_GS_SOURCE}/Granite/third_party/volk"
                "${REO_PARALLEL_GS_SOURCE}/Granite/third_party/khronos/vulkan-headers/include")
            set_property(SOURCE ${_reo_movie_game_sources} APPEND PROPERTY COMPILE_DEFINITIONS
                NOMINMAX GRANITE_SHIPPING HAVE_WSI_DXGI_INTEROP)
        endif()
        list(APPEND _reo_handwritten_sources
            "${_reo_movie_copies}/movie_join_observed_caller.cpp"
            "${_reo_movie_copies}/reo_movie_commit_observed.cpp"
            "${_reo_movie_copies}/reo_movie_initialize_observed.cpp")
    endif()
    if(REO_VU_SPECIALIZED_SOURCE AND GAME_DEFINE MATCHES "^REO_GAME_FILE[12]$")

        list(APPEND _reo_handwritten_sources "${REO_VU_SPECIALIZED_SOURCE}")

        get_filename_component(_reo_vu_generated_dir "${REO_VU_SPECIALIZED_SOURCE}" DIRECTORY)

    endif()

    if(REO_VU_WHOLE_SOURCE AND GAME_DEFINE MATCHES "^REO_GAME_FILE[12]$")
        list(APPEND _reo_handwritten_sources "${REO_VU_WHOLE_SOURCE}")
        get_filename_component(_reo_vu_whole_dir "${REO_VU_WHOLE_SOURCE}" DIRECTORY)
    endif()

    if(REO_VU_NATIVE_GEOMETRY_SOURCE AND GAME_DEFINE MATCHES "^REO_GAME_FILE[12]$")

        list(APPEND _reo_handwritten_sources "${REO_VU_NATIVE_GEOMETRY_SOURCE}")

        get_filename_component(_reo_vu_native_dir "${REO_VU_NATIVE_GEOMETRY_SOURCE}" DIRECTORY)

    endif()



    add_executable(${TARGET_NAME}

        ${_reo_handwritten_sources}

        ${RECOMP_SOURCES}

        ${OVERLAY_SOURCES}

    )

    if(WIN32)
        # A direct object supplies raylib audio before its archive is considered.
        # This replaces only the host audio provider, for both game editions.
        target_sources(${TARGET_NAME} PRIVATE "${REO_AUDIO_OUTPUT_SOURCE}")
        target_sources(${TARGET_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../network/native/snap_iop_transport.cpp")
        target_sources(${TARGET_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../network/native/netcnf_profile.cpp")
        target_link_libraries(${TARGET_NAME} PRIVATE ws2_32)
    endif()

    if(REO_VU_WHOLE_SOURCE AND GAME_DEFINE MATCHES "^REO_GAME_FILE[12]$")
        set_property(SOURCE overrides/reo_vu_specialized.cpp "${REO_VU_WHOLE_SOURCE}"
            TARGET_DIRECTORY ${TARGET_NAME} APPEND PROPERTY INCLUDE_DIRECTORIES
                "${PS2RECOMP_DIR}/ps2xRuntime/src/lib" "${_reo_vu_whole_dir}"
                "${CMAKE_CURRENT_SOURCE_DIR}/../tools/vu_whole_aot")
        set_property(SOURCE overrides/reo_vu_specialized.cpp TARGET_DIRECTORY ${TARGET_NAME}
            APPEND PROPERTY COMPILE_DEFINITIONS REO_HAVE_WHOLE_VU_PROGRAMS=1)
    endif()

    if(REO_VU_SPECIALIZED_SOURCE AND GAME_DEFINE MATCHES "^REO_GAME_FILE[12]$")

        set_property(SOURCE overrides/reo_vu_specialized.cpp "${REO_VU_SPECIALIZED_SOURCE}"

            TARGET_DIRECTORY ${TARGET_NAME}

            APPEND PROPERTY INCLUDE_DIRECTORIES

                "${PS2RECOMP_DIR}/ps2xRuntime/src/lib" "${_reo_vu_generated_dir}")

        set_property(SOURCE overrides/reo_vu_specialized.cpp TARGET_DIRECTORY ${TARGET_NAME}

            APPEND PROPERTY COMPILE_DEFINITIONS REO_HAVE_GENERATED_VU_PROGRAMS=1)

    endif()

    if(REO_VU_NATIVE_GEOMETRY_SOURCE AND GAME_DEFINE MATCHES "^REO_GAME_FILE[12]$")

        set_property(SOURCE overrides/reo_vu_specialized.cpp "${REO_VU_NATIVE_GEOMETRY_SOURCE}"

            TARGET_DIRECTORY ${TARGET_NAME}

            APPEND PROPERTY INCLUDE_DIRECTORIES

                "${PS2RECOMP_DIR}/ps2xRuntime/src/lib" "${_reo_vu_native_dir}")

        set_property(SOURCE overrides/reo_vu_specialized.cpp TARGET_DIRECTORY ${TARGET_NAME}

            APPEND PROPERTY COMPILE_DEFINITIONS REO_HAVE_NATIVE_GEOMETRY=1)

        set_property(SOURCE "${REO_VU_NATIVE_GEOMETRY_SOURCE}" TARGET_DIRECTORY ${TARGET_NAME}

            APPEND PROPERTY COMPILE_DEFINITIONS

                REO_HAVE_NATIVE_STATIC_GEOMETRY=1 REO_HAVE_NATIVE_MULTIBONE_GEOMETRY=1)

        if(REO_BUILD_NATIVE_64E_RIGID)

            set_property(SOURCE "${REO_VU_NATIVE_GEOMETRY_SOURCE}" TARGET_DIRECTORY ${TARGET_NAME}

                APPEND PROPERTY COMPILE_DEFINITIONS REO_HAVE_NATIVE_64E_RIGID_GEOMETRY=1)

        endif()

        if(REO_BUILD_NATIVE_STATIC_HALFSPACE)

            set_property(SOURCE "${REO_VU_NATIVE_GEOMETRY_SOURCE}" TARGET_DIRECTORY ${TARGET_NAME}

                APPEND PROPERTY COMPILE_DEFINITIONS REO_HAVE_NATIVE_STATIC_HALFSPACE_GEOMETRY=1)

        endif()

        if(REO_BUILD_NATIVE_STATIC_PROJECTION)

            set_property(SOURCE "${REO_VU_NATIVE_GEOMETRY_SOURCE}" TARGET_DIRECTORY ${TARGET_NAME}

                APPEND PROPERTY COMPILE_DEFINITIONS REO_HAVE_NATIVE_STATIC_PROJECTION_GEOMETRY=1)

        endif()

    endif()



    target_include_directories(${TARGET_NAME} PRIVATE

        ${PS2RECOMP_INCLUDES}

        "${CMAKE_CURRENT_SOURCE_DIR}/config/${OUTPUT_DIR}"

        "${_reo_generated_root}/output_overlay"

        "${CMAKE_CURRENT_SOURCE_DIR}/overrides/movie_addresses/$<IF:$<STREQUAL:${GAME_DEFINE},REO_GAME_FILE2>,file2,file1>"
        "${CMAKE_CURRENT_SOURCE_DIR}/overrides"

        "${CMAKE_CURRENT_SOURCE_DIR}/.."

        "${CMAKE_CURRENT_SOURCE_DIR}/../game"

        "${CMAKE_CURRENT_SOURCE_DIR}/../media"

    )



    target_link_libraries(${TARGET_NAME} PRIVATE ${PS2RECOMP_LIBS})

    if(REO_BUILD_GPU_PARENT_NATURAL_HOOKS AND GAME_DEFINE STREQUAL "REO_GAME_FILE1")
        set_property(SOURCE reo_bootstrap.cpp TARGET_DIRECTORY ${TARGET_NAME}
            APPEND PROPERTY COMPILE_DEFINITIONS REO_HAVE_GPU_PARENT_NATURAL_HOOKS=1)
        set_property(SOURCE
            overrides/gpu_parent_natural/parent_natural_body.cpp
            overrides/gpu_parent_natural/parent_natural_aggregate.cpp
            overrides/gpu_parent_natural/parent_body_install.cpp
            TARGET_DIRECTORY ${TARGET_NAME} APPEND PROPERTY INCLUDE_DIRECTORIES
            "${PS2RECOMP_DIR}/ps2xRuntime/src/lib")
    endif()

    # Keep private runtime/Vulkan headers and definitions out of generated code.

    set_property(SOURCE reo_bootstrap.cpp TARGET_DIRECTORY ${TARGET_NAME}

        APPEND PROPERTY INCLUDE_DIRECTORIES "${PS2RECOMP_DIR}/ps2xRuntime/src/lib")

    set_property(SOURCE overrides/reo_vu_specialized.cpp TARGET_DIRECTORY ${TARGET_NAME}

        APPEND PROPERTY INCLUDE_DIRECTORIES "${PS2RECOMP_DIR}/ps2xRuntime/src/lib")

    if(REO_BUILD_GPU_GS)

        set_property(SOURCE reo_bootstrap.cpp TARGET_DIRECTORY ${TARGET_NAME}

            APPEND PROPERTY INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/../tools/parallel_gs_backend")

        set_property(SOURCE reo_bootstrap.cpp TARGET_DIRECTORY ${TARGET_NAME}

            APPEND PROPERTY COMPILE_DEFINITIONS REO_HAVE_PARALLEL_GS=1)

        if(WIN32)

        reo_require_vulkan_shader_tools()
        set(_present_source "${CMAKE_CURRENT_SOURCE_DIR}/../tools/parallel_gs_backend")

        set(_present_output "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}-present-shaders")

        foreach(_present_stage IN ITEMS "present_opaque.vert" "present_native.frag" "present_smaa_edge.frag" "present_smaa_weights.frag" "present_smaa_blend.frag")

            get_filename_component(_present_kind "${_present_stage}" LAST_EXT)

            string(SUBSTRING "${_present_kind}" 1 -1 _present_kind)

            add_custom_command(OUTPUT "${_present_output}/${_present_stage}.spv"

                COMMAND ${CMAKE_COMMAND} -E make_directory "${_present_output}"

                COMMAND "${REO_GLSLANG_VALIDATOR}" -V --target-env vulkan1.2 -S ${_present_kind}

                        -o "${_present_output}/${_present_stage}.spv" "${_present_source}/${_present_stage}"

                COMMAND "${REO_SPIRV_VAL}" --target-env vulkan1.2 "${_present_output}/${_present_stage}.spv"

                DEPENDS "${_present_source}/${_present_stage}" "${_present_source}/present_color.glsl" "${_present_source}/present_layout.glsl" "${_present_source}/present_performance.glsl" "${_present_source}/smaa/upstream/SMAA.hlsl" VERBATIM)

        endforeach()

        set(_present_modules "${_present_output}/present_opaque.vert.spv" "${_present_output}/present_native.frag.spv" "${_present_output}/present_smaa_edge.frag.spv" "${_present_output}/present_smaa_weights.frag.spv" "${_present_output}/present_smaa_blend.frag.spv")
        add_custom_target(${TARGET_NAME}_gpu_present_shaders DEPENDS ${_present_modules})

        add_dependencies(${TARGET_NAME} ${TARGET_NAME}_gpu_present_shaders)

        # Shader-only edits must also refresh the shaders beside the executable.
        # Otherwise POST_BUILD does not run and the launcher copies stale SPIR-V.
        set_property(TARGET ${TARGET_NAME} APPEND PROPERTY LINK_DEPENDS
            ${_present_modules})

        add_custom_command(TARGET ${TARGET_NAME} POST_BUILD

            COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${TARGET_NAME}>/reo-gpu-present"

            COMMAND ${CMAKE_COMMAND} -E copy_if_different ${_present_modules} "$<TARGET_FILE_DIR:${TARGET_NAME}>/reo-gpu-present")

        endif()

        target_link_libraries(${TARGET_NAME} PRIVATE ${_reo_gpu_libraries} winspool oleaut32 uuid comdlg32)
        if(WIN32)
            target_sources(${TARGET_NAME} PRIVATE $<TARGET_OBJECTS:reo_movie_allocator_native>)
            target_link_libraries(${TARGET_NAME} PRIVATE d3d11 dxgi dxguid)
        endif()

        if(REO_VULKAN_LOADER_FILE)

            add_custom_command(TARGET ${TARGET_NAME} POST_BUILD

                COMMAND ${CMAKE_COMMAND} -E copy_if_different "${REO_VULKAN_LOADER_FILE}"

                    "$<TARGET_FILE_DIR:${TARGET_NAME}>/vulkan-1.dll")

        endif()

    endif()



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

        # Target-wide (not per source): CMake never merges sources that carry their own

        # COMPILE_OPTIONS into unity batches. Hand-written sources override it below.

        target_compile_options(${TARGET_NAME} PRIVATE ${REO_RECOMP_OPT})

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

        if(REO_ASAN)

            set(_reo_handwritten_opts "/O2;/fsanitize=address;/Zi;/D_DISABLE_STRING_ANNOTATION;/D_DISABLE_VECTOR_ANNOTATION")

            target_link_options(${TARGET_NAME} PRIVATE /DEBUG /INFERASANLIBS /INCREMENTAL:NO)

        else()

            set(_reo_handwritten_opts "/O2")

        endif()

        set_source_files_properties(${_reo_handwritten_sources}

            TARGET_DIRECTORY ${TARGET_NAME}

            PROPERTIES COMPILE_OPTIONS "${_reo_handwritten_opts}")

        if(REO_VU_WHOLE_SOURCE AND GAME_DEFINE MATCHES "^REO_GAME_FILE[12]$")
            set_property(SOURCE "${REO_VU_WHOLE_SOURCE}" TARGET_DIRECTORY ${TARGET_NAME}
                APPEND PROPERTY COMPILE_OPTIONS /fp:precise)
        endif()

        # The hardware bridge uses private source access guards. Keep that
        # include path on this handwritten source, preserving generated/PCH flags.
        set_property(SOURCE overrides/reo_hw_bridge.cpp TARGET_DIRECTORY ${TARGET_NAME}
            APPEND PROPERTY INCLUDE_DIRECTORIES "${PS2RECOMP_DIR}/ps2xRuntime/src/lib")

        if(REO_VU_SPECIALIZED_SOURCE AND GAME_DEFINE MATCHES "^REO_GAME_FILE[12]$")

            set_property(SOURCE "${REO_VU_SPECIALIZED_SOURCE}" TARGET_DIRECTORY ${TARGET_NAME}

                APPEND PROPERTY COMPILE_OPTIONS /fp:precise)

        endif()

        if(REO_VU_NATIVE_GEOMETRY_SOURCE AND GAME_DEFINE MATCHES "^REO_GAME_FILE[12]$")

            set_property(SOURCE overrides/reo_vu_specialized.cpp "${REO_VU_NATIVE_GEOMETRY_SOURCE}"

                TARGET_DIRECTORY ${TARGET_NAME} APPEND PROPERTY COMPILE_OPTIONS /fp:precise)

        endif()

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



    if(REO_HAVE_OVL)

        target_compile_definitions(${TARGET_NAME} PRIVATE REO_HAVE_OVL=1)

    endif()

    if(REO_HAVE_EXTRA)

        # Only the bootstrap needs it; a target-wide define would rebuild every source.

        set_property(SOURCE reo_bootstrap.cpp TARGET_DIRECTORY ${TARGET_NAME}

                     APPEND PROPERTY COMPILE_DEFINITIONS REO_HAVE_EXTRA=1)

    endif()



    if(REO_UNITY_BUILD)

        set_target_properties(${TARGET_NAME} PROPERTIES

            UNITY_BUILD ON

            UNITY_BUILD_BATCH_SIZE ${REO_UNITY_BATCH})

        set_source_files_properties(${_reo_handwritten_sources}

            TARGET_DIRECTORY ${TARGET_NAME}

            PROPERTIES SKIP_UNITY_BUILD_INCLUSION ON)

        # Very large generated functions compile alone: merged, they spike a compiler

        # process to several GB.

        set(_reo_big_sources "")

        foreach(_src IN LISTS RECOMP_SOURCES OVERLAY_SOURCES)

            file(SIZE "${_src}" _sz)

            if(_sz GREATER ${REO_UNITY_MAX_FILE})

                list(APPEND _reo_big_sources "${_src}")

            endif()

        endforeach()

        list(LENGTH _reo_big_sources _reo_big_count)

        message(STATUS "REO [${TARGET_NAME}]: ${_reo_big_count} generated sources > ${REO_UNITY_MAX_FILE} bytes compile outside unity batches")

        if(_reo_big_sources)

            set_source_files_properties(${_reo_big_sources}

                TARGET_DIRECTORY ${TARGET_NAME}

                PROPERTIES SKIP_UNITY_BUILD_INCLUSION ON)

        endif()

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

add_recomp_target(reo_recomp_file2 "output_file2/output" "REO_GAME_FILE2")
