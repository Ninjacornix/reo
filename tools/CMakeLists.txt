add_subdirectory(iso_extract)
add_subdirectory(elf_analyze)
add_subdirectory(gs_dump_replay)

if(Vulkan_FOUND)
    add_executable(reo_display_sync_check parallel_gs_backend/display_sync_check.cpp)
    target_compile_features(reo_display_sync_check PRIVATE cxx_std_17)
    target_include_directories(reo_display_sync_check PRIVATE ${Vulkan_INCLUDE_DIRS})
endif()
