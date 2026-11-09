add_library(reo_native_gameplay_scenario STATIC interpreter.cpp flags.cpp offline.cpp scene_resources.cpp scene_controls.cpp content.cpp sequence_control.cpp)
target_compile_features(reo_native_gameplay_scenario PUBLIC cxx_std_20)
target_include_directories(reo_native_gameplay_scenario PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../..)
target_link_libraries(reo_native_gameplay_scenario PUBLIC reo_native_gameplay_tasks)
