cmake_minimum_required(VERSION 3.20)
project(reo VERSION 0.2.0 LANGUAGES C CXX)

# Compiler cache: recompiling identical inputs (regenerated code, reverted changes, branch
# switches, rebuilds forced by build-setting mistakes) is served from the cache.
# sccache cannot cache MSVC precompiled-header compiles, so the PCH is off while it is on.
option(REO_USE_SCCACHE "Use sccache as the C/C++ compiler launcher when found" ON)
if(REO_USE_SCCACHE)
    find_program(REO_SCCACHE sccache
        HINTS "$ENV{LOCALAPPDATA}/Microsoft/WinGet/Links"
              "$ENV{LOCALAPPDATA}/Microsoft/WinGet/Packages/Mozilla.sccache_Microsoft.Winget.Source_8wekyb3d8bbwe/sccache-v0.18.0-x86_64-pc-windows-msvc")
    if(REO_SCCACHE)
        set(CMAKE_C_COMPILER_LAUNCHER "${REO_SCCACHE}")
        set(CMAKE_CXX_COMPILER_LAUNCHER "${REO_SCCACHE}")
        set(REO_RECOMP_PCH OFF CACHE BOOL "Precompile the runtime headers shared by all generated sources" FORCE)
        message(STATUS "REO: compiler cache ${REO_SCCACHE} (PCH off)")
    else()
        message(STATUS "REO: sccache not found; building without a compiler cache")
    endif()
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options
option(REO_BUILD_TOOLS "Build extraction and analysis tools" ON)
option(REO_BUILD_RUNTIME "Build the game runtime" ON)
option(REO_BUILD_NETWORK "Build online play support" ON)
option(REO_USE_VULKAN "Use Vulkan for GS rendering" ON)

# Platform detection
if(WIN32)
    add_definitions(-DREO_PLATFORM_WINDOWS)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-DNOMINMAX)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
endif()

# Find packages
if(REO_USE_VULKAN)
    find_package(Vulkan QUIET)
    if(Vulkan_FOUND)
        message(STATUS "Vulkan found: ${Vulkan_INCLUDE_DIRS}")
    else()
        message(WARNING "Vulkan SDK not found - GS renderer will be stubbed")
    endif()
endif()

# Third-party dependencies
# SDL3 - windowing, input, audio fallback
# add_subdirectory(third_party/SDL3)

# Project-wide include paths
include_directories(${CMAKE_SOURCE_DIR})

# Tools
if(REO_BUILD_TOOLS)
    add_subdirectory(tools)
endif()

# Runtime HAL
if(REO_BUILD_RUNTIME)
    add_subdirectory(runtime)
endif()

# Network
if(REO_BUILD_NETWORK)
    add_subdirectory(network)
endif()

# Media decoders
add_subdirectory(media)

# Game-specific code
add_subdirectory(game)

# Recompiled game (PS2Recomp output)
add_subdirectory(recomp)

# Main executable
add_executable(reo
    src/main.cpp
    src/config.cpp
)

target_link_libraries(reo PRIVATE
    reo_runtime
    reo_network
    reo_media
    reo_game
)

target_include_directories(reo PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Install
install(TARGETS reo DESTINATION bin)
