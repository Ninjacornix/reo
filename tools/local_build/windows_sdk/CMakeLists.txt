cmake_minimum_required(VERSION 3.21)
project(reo_portable_windows_sdk LANGUAGES C CXX)

if(NOT MINGW OR NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    message(FATAL_ERROR "Build this SDK with the pinned LLVM/MinGW UCRT toolchain")
endif()
enable_language(RC)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
foreach(component PS2RECOMP RAYLIB FMT LIBDWARF RABBITIZER TOML11 ELFIO PARALLEL)
    if(NOT IS_DIRECTORY "${REO_${component}_SOURCE}")
        message(FATAL_ERROR "Supply the exact source tree: REO_${component}_SOURCE")
    endif()
endforeach()
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
set(BUILD_DWARFDUMP OFF CACHE BOOL "" FORCE)
set(ENABLE_DECOMPRESSION OFF CACHE BOOL "" FORCE)
set(LIBDWARF_STATIC ON CACHE BOOL "" FORCE)
set(PARALLEL_GS_STANDALONE ON CACHE BOOL "" FORCE)
add_compile_definitions(NOMINMAX WIN32_LEAN_AND_MEAN)
add_subdirectory("${REO_RAYLIB_SOURCE}" raylib)
target_compile_definitions(raylib PRIVATE
    MA_DEFAULT_PERIOD_SIZE_IN_MILLISECONDS_LOW_LATENCY=5 MA_DEFAULT_PERIODS=2)
add_subdirectory("${REO_FMT_SOURCE}" fmt)
add_subdirectory("${REO_LIBDWARF_SOURCE}" dwarf)
add_subdirectory("${REO_PARALLEL_SOURCE}" parallel)

file(GLOB_RECURSE rabbitizer_sources CONFIGURE_DEPENDS
    "${REO_RABBITIZER_SOURCE}/src/analysis/*.c"
    "${REO_RABBITIZER_SOURCE}/src/common/*.c"
    "${REO_RABBITIZER_SOURCE}/src/instructions/*.c")
add_library(rabbitizer STATIC ${rabbitizer_sources})
target_include_directories(rabbitizer PUBLIC
    "${REO_RABBITIZER_SOURCE}/include" "${REO_RABBITIZER_SOURCE}/tables"
    "${REO_RABBITIZER_SOURCE}/tables/tables")
file(GLOB_RECURSE recompiler_sources CONFIGURE_DEPENDS
    "${REO_PS2RECOMP_SOURCE}/ps2xRecomp/src/lib/*.cpp"
    "${REO_PS2RECOMP_SOURCE}/ps2xRecomp/src/runner/*.cpp")
add_executable(ps2_recomp ${recompiler_sources})
target_sources(ps2_recomp PRIVATE
    "${REO_PS2RECOMP_SOURCE}/ps2xRecomp/src/runner/ps2_recomp.rc")
target_include_directories(ps2_recomp PRIVATE
    "${REO_PS2RECOMP_SOURCE}/ps2xRecomp/src/runner")
target_include_directories(ps2_recomp PRIVATE
    "${REO_PS2RECOMP_SOURCE}/ps2xRecomp/include"
    "${REO_PS2RECOMP_SOURCE}/ps2xRuntime/include"
    "${REO_ELFIO_SOURCE}" "${REO_ELFIO_SOURCE}/include"
    "${REO_TOML11_SOURCE}" "${REO_TOML11_SOURCE}/include"
    "${REO_LIBDWARF_SOURCE}/src/lib/libdwarf")
target_compile_definitions(ps2_recomp PRIVATE LIBDWARF_STATIC)
target_link_libraries(ps2_recomp PRIVATE fmt::fmt dwarf rabbitizer)
