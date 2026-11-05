cmake_minimum_required(VERSION 3.20)
project(reo_native_resources LANGUAGES CXX)
find_package(Threads REQUIRED)

add_library(reo_native_resources STATIC resource_session.cpp virtual_file_view.cpp)
target_compile_features(reo_native_resources PUBLIC cxx_std_20)
target_include_directories(reo_native_resources PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../..)
target_link_libraries(reo_native_resources PUBLIC Threads::Threads)

option(REO_NATIVE_RESOURCES_TESTS "Build standalone native resource tests" ON)
if(REO_NATIVE_RESOURCES_TESTS)
    enable_testing()
    add_executable(reo_native_resources_tests resource_tests.cpp)
    target_include_directories(reo_native_resources_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../..)
    target_link_libraries(reo_native_resources_tests PRIVATE reo_native_resources)
    add_test(NAME native_resources_contract COMMAND reo_native_resources_tests)
endif()
