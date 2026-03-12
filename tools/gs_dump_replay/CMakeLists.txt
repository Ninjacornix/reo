add_executable(reo-gs-replay
    main.cpp
    ${CMAKE_SOURCE_DIR}/runtime/gs/gs_renderer.cpp
)

target_include_directories(reo-gs-replay PRIVATE
    ${CMAKE_SOURCE_DIR}
)

# Need windows libs for GDI (GSRenderer has #ifdef _WIN32)
if(WIN32)
    target_link_libraries(reo-gs-replay PRIVATE user32 gdi32)
endif()

# Test dump generator
add_executable(reo-gs-gen-test
    gen_test_dump.cpp
)
