add_library(reo_native_gameplay_save STATIC snapshot.cpp primary_start.cpp)
target_compile_features(reo_native_gameplay_save PUBLIC cxx_std_20)
target_include_directories(reo_native_gameplay_save PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
