cmake_minimum_required(VERSION 3.20)
project(reo_scene_voice_preparation_checks LANGUAGES CXX)
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
add_executable(scene_voice_preparation_checks "${CMAKE_CURRENT_SOURCE_DIR}/../stream_instances_oracle/tests.cpp"
  "${REO_ROOT}/game/native/gameplay_scenario/stream_voice_queue.cpp"
  "${REO_ROOT}/game/native/gameplay_scenario/stream_instances.cpp"
  "${REO_ROOT}/game/native/gameplay_scenario/stream_channels.cpp")
target_compile_features(scene_voice_preparation_checks PRIVATE cxx_std_20)
target_include_directories(scene_voice_preparation_checks PRIVATE "${REO_ROOT}")
target_link_libraries(scene_voice_preparation_checks PRIVATE reo_native_adxt_control_owner reo_native_afs_source_range reo_native_audio_cue_queue)
target_compile_options(scene_voice_preparation_checks PRIVATE -Wall -Wextra -Wpedantic -Werror -fno-fast-math -ffp-contract=off)

target_compile_definitions(scene_voice_preparation_checks PRIVATE REO_SCENE_VOICE_PREPARATION=1)
target_include_directories(scene_voice_preparation_checks PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_options(scene_voice_preparation_checks PRIVATE -ffunction-sections -fdata-sections)
target_link_options(scene_voice_preparation_checks PRIVATE -Wl,--gc-sections)
target_sources(scene_voice_preparation_checks PRIVATE
  "${REO_ROOT}/game/native/gameplay_world/world.cpp"
  "${REO_ROOT}/game/native/gameplay_world/linked_models.cpp"
  "${REO_ROOT}/game/native/gameplay_world/auxiliary_actors.cpp"
  "${REO_ROOT}/game/native/gameplay_world/scene_primary_actors.cpp"
  "${REO_ROOT}/game/native/gameplay_world/model_poses.cpp"
  "${REO_ROOT}/game/native/gameplay_world/model_constraints.cpp"
  "${REO_ROOT}/game/native/gameplay_world/bodies.cpp"
  "${REO_ROOT}/game/native/gameplay_world/cinematic_objects.cpp"
  "${REO_ROOT}/game/native/gameplay_actors/entity.cpp"
  "${REO_ROOT}/game/native/gameplay_actors/input.cpp"
  "${REO_ROOT}/game/native/gameplay_actors/health.cpp"
  "${REO_ROOT}/game/native/gameplay_collision/collision.cpp"
  "${REO_ROOT}/game/native/gameplay_collision/response.cpp"
  "${REO_ROOT}/game/native/gameplay_collision/actors.cpp"
  "${REO_ROOT}/game/native/gameplay_collision/actor_views.cpp"
  "${REO_ROOT}/game/native/animation/model.cpp"
  "${REO_ROOT}/game/native/animation/model_math.cpp"
  "${REO_ROOT}/game/native/animation/curves.cpp"
  "${REO_ROOT}/game/native/animation/constraints.cpp"
  "${REO_ROOT}/game/native/animation/constraint_math.cpp"
  "${REO_ROOT}/game/native/animation/playback.cpp"
  "${REO_ROOT}/game/native/animation/model_blend.cpp"
  "${REO_ROOT}/game/native/animation/motion_bank.cpp"
  "${REO_ROOT}/game/native/animation/scalar_playback.cpp"
  "${REO_ROOT}/game/native/transform_math/transform_math.cpp"
  "${REO_ROOT}/game/native/gameplay_session/session.cpp"
  "${REO_ROOT}/game/native/gameplay_navigation/bank.cpp"
  "${REO_ROOT}/game/native/gameplay_scenario/scene_voice_assets.cpp"
  "${REO_ROOT}/game/native/gameplay_scenario/scene_voice_preparation.cpp"
)
