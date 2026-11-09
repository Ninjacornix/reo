add_library(reo_native_gameplay_collision STATIC collision.cpp response.cpp sweep.cpp actors.cpp ownership.cpp trace.cpp room_objects.cpp footprint.cpp regions.cpp postmove.cpp room_geometry.cpp)
target_compile_features(reo_native_gameplay_collision PUBLIC cxx_std_20)
target_include_directories(reo_native_gameplay_collision PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(reo_native_gameplay_collision PRIVATE -Wall -Wextra -Wpedantic -Werror -fno-fast-math -ffp-contract=off)
endif()
