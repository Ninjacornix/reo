cmake_minimum_required(VERSION 3.20)
project(reo_scenario_stream_instance_checks LANGUAGES CXX)
get_filename_component(REO_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../../.." ABSOLUTE)
# Match the established native topological order while keeping every private
# binary directory short enough for the Windows GCC dependency-file writer.
foreach(part sjuni sjrb resources afs_source_range afs_hierarchy
    adxt_service_group adxt_transfer_groups lsc_queue tasks resource_io disc_stream
    adx_control adx_block adx_stereo adx_window adxt_refill adxt_shared_source
    adx_header adx_workspace adx_pcm_store adx_pcm_store/v2 adx_window/v2
    adx_window/v2/ready_flag_r1 adxt_integer_clock adxt_estimated_clock adxt_playback
    adx_window/v2/playback_r2 adx_window/v2/queue_safe_r3 pcm pcm_bridge audio_output
    adxt_player adxt_output_session adxt_shared_player adxt_clocked_player
    adxt_serviced_clock adxt_phased_player adxt_control_session adxt_instances
    adxt_control_owner)
  string(REPLACE "/" "_" binary_part "${part}")
  add_subdirectory("${REO_ROOT}/game/native/${part}" "${binary_part}" EXCLUDE_FROM_ALL)
endforeach()
add_subdirectory("${REO_ROOT}/game/native/audio_cue_queue" "audio_cue_queue" EXCLUDE_FROM_ALL)
add_executable(stream_instance_checks tests.cpp
  "${REO_ROOT}/game/native/gameplay_scenario/stream_voice_queue.cpp"
  "${REO_ROOT}/game/native/gameplay_scenario/stream_instances.cpp"
  "${REO_ROOT}/game/native/gameplay_scenario/stream_channels.cpp")
target_compile_features(stream_instance_checks PRIVATE cxx_std_20)
target_include_directories(stream_instance_checks PRIVATE "${REO_ROOT}")
target_link_libraries(stream_instance_checks PRIVATE reo_native_adxt_control_owner reo_native_afs_source_range reo_native_audio_cue_queue)
target_compile_options(stream_instance_checks PRIVATE -Wall -Wextra -Wpedantic -Werror -fno-fast-math -ffp-contract=off)
