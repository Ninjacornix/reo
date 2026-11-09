add_library(reo_native_gameplay_collision STATIC collision.cpp response.cpp sweep.cpp actors.cpp ownership.cpp trace.cpp room_objects.cpp)
target_compile_features(reo_native_gameplay_collision PUBLIC cxx_std_20)
target_include_directories(reo_native_gameplay_collision PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
