cmake_minimum_required(VERSION 3.20)
project(reo_native_sjuni LANGUAGES CXX)

add_library(reo_native_sjuni STATIC sjuni.cpp)
target_include_directories(reo_native_sjuni PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(reo_native_sjuni PUBLIC cxx_std_20)

option(REO_NATIVE_SJUNI_TESTS "Build standalone SJUNI contract tests" ON)
if(REO_NATIVE_SJUNI_TESTS)
    enable_testing()
    add_executable(reo_native_sjuni_tests sjuni_tests.cpp)
    target_link_libraries(reo_native_sjuni_tests PRIVATE reo_native_sjuni)
    add_test(NAME sjuni_contract COMMAND reo_native_sjuni_tests)
endif()
