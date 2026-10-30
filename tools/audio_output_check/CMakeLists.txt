cmake_minimum_required(VERSION 3.21)
project(reo_audio_output_check LANGUAGES C)
if(NOT WIN32)
    message(FATAL_ERROR "This check verifies Windows audio endpoints")
endif()
get_filename_component(REO_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
set(REO_RAYLIB "${REO_ROOT}/third_party/PS2Recomp/out/build/_deps/raylib-src/src")
include("${REO_ROOT}/cmake/ReoAudioOutput.cmake")
reo_audio_output_source("${REO_RAYLIB}/raudio.c" "${CMAKE_CURRENT_BINARY_DIR}/reo_audio_output.c")
add_executable(audio_output_check main.c)
target_include_directories(audio_output_check PRIVATE "${CMAKE_CURRENT_BINARY_DIR}" "${REO_ROOT}" "${REO_RAYLIB}")
target_compile_definitions(audio_output_check PRIVATE _CRT_SECURE_NO_WARNINGS
    MA_DEFAULT_PERIOD_SIZE_IN_MILLISECONDS_LOW_LATENCY=5 MA_DEFAULT_PERIODS=2)
target_link_libraries(audio_output_check PRIVATE
    "${REO_ROOT}/third_party/PS2Recomp/out/build/_deps/raylib-build/raylib/Release/raylib.lib"
    "${REO_ROOT}/third_party/PS2Recomp/out/build/_deps/raylib-build/raylib/external/glfw/src/glfw.dir/Release/glfw.lib"
    winmm ole32 uuid avrt user32 shell32 gdi32 opengl32)
