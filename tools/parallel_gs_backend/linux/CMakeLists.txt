cmake_minimum_required(VERSION 3.21)
project(reo_linux_gpu_backend LANGUAGES C CXX)
option(REO_LINUX_XLIB_PRESENT "Build the native Linux X11 Vulkan swapchain path" ON)

if(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(FATAL_ERROR "This target checks the native Linux backend")
endif()
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PARALLEL_GS_SOURCE "" CACHE PATH "Pinned paraLLEl-GS source matching the published patches")
set(REO_ROUTE_SOURCE "" CACHE PATH "Matching ps2xRuntime/src/lib header/source cohort")
set(REO_ANISOTROPIC_HEADERS "" CACHE PATH "Independent generated anisotropic_spirv.hpp directory")
set(REO_PROJECT_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../.." CACHE PATH "Project root matching the runtime header cohort")
if(NOT EXISTS "${PARALLEL_GS_SOURCE}/CMakeLists.txt" OR
   NOT EXISTS "${REO_ROUTE_SOURCE}/gs_backend_route.cpp")
    message(FATAL_ERROR "Supply the pinned renderer source and matching runtime route sources")
endif()
set(PARALLEL_GS_STANDALONE ON CACHE BOOL "" FORCE)
add_subdirectory("${PARALLEL_GS_SOURCE}" parallel-gs EXCLUDE_FROM_ALL)
if(NOT EXISTS "${REO_ANISOTROPIC_HEADERS}/anisotropic_spirv.hpp")
    message(FATAL_ERROR "Supply the independently compiled anisotropic shader header")
endif()
set(_resident_gs "${CMAKE_CURRENT_LIST_DIR}/../resident_gs")
set_property(TARGET parallel-gs PROPERTY SOURCES
    "${_resident_gs}/gs_interface.cpp" "${_resident_gs}/gs_util.cpp"
    "${_resident_gs}/gs_renderer.cpp" "${_resident_gs}/page_tracker.cpp")
target_include_directories(parallel-gs BEFORE PUBLIC "${_resident_gs}"
    "${CMAKE_CURRENT_LIST_DIR}/../resident_geometry" "${REO_ANISOTROPIC_HEADERS}"
    "${REO_PROJECT_ROOT}")
target_compile_features(parallel-gs PUBLIC cxx_std_20)
add_library(reo_parallel_backend_linux STATIC ../parallel_backend.cpp)
target_include_directories(reo_parallel_backend_linux PUBLIC .. "${REO_ROUTE_SOURCE}"
    "${REO_ROUTE_SOURCE}/../../include" "${REO_ROUTE_SOURCE}/Kernel"
    "${REO_PROJECT_ROOT}" "${CMAKE_CURRENT_LIST_DIR}/../resident_geometry"
    "${CMAKE_CURRENT_LIST_DIR}/../resident_gs")
target_link_libraries(reo_parallel_backend_linux PUBLIC parallel-gs)
target_compile_features(reo_parallel_backend_linux PUBLIC cxx_std_20)
target_compile_options(reo_parallel_backend_linux PRIVATE -O2 -fno-fast-math -ffp-contract=off)
if(REO_LINUX_XLIB_PRESENT)
    find_package(X11 REQUIRED)
    target_compile_definitions(reo_parallel_backend_linux PRIVATE REO_LINUX_XLIB_PRESENT=1)
    target_link_libraries(reo_parallel_backend_linux PUBLIC X11::X11)
    add_executable(linux_present_check present_check.cpp)
    target_include_directories(linux_present_check PRIVATE ..)
    target_link_libraries(linux_present_check PRIVATE granite-vulkan X11::X11)
    target_compile_features(linux_present_check PRIVATE cxx_std_20)
endif()
add_executable(parallel_backend_linux_check ../check.cpp headless_services.cpp
    "${REO_ROUTE_SOURCE}/gs_backend_route.cpp")
target_link_libraries(parallel_backend_linux_check PRIVATE reo_parallel_backend_linux)
target_compile_options(parallel_backend_linux_check PRIVATE -UNDEBUG)

# The check exercises native Vulkan drawing/ordering. It is not a game or a
# substitute for Linux swapchain/movie/room-route validation.
