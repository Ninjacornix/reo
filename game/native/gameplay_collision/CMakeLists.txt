add_library(reo_native_gameplay_collision STATIC collision.cpp response.cpp sweep.cpp actors.cpp ownership.cpp trace.cpp room_objects.cpp footprint.cpp regions.cpp postmove.cpp room_geometry.cpp spatial.cpp hit_regions.cpp radius.cpp directed.cpp postmove_view.cpp object_interactions.cpp object_lifetime.cpp object_queries.cpp actor_views.cpp actor_metadata.cpp secondary_ground.cpp delivery.cpp contact_scan.cpp contact_content.cpp contact_packets.cpp packet_service.cpp contact_routes.cpp room_damage.cpp packet_shapes.cpp impact_policy.cpp impact_populations.cpp)
target_compile_features(reo_native_gameplay_collision PUBLIC cxx_std_20)
target_sources(reo_native_gameplay_collision PRIVATE object_scene.cpp)
target_include_directories(reo_native_gameplay_collision PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(reo_native_gameplay_collision PUBLIC reo_native_gameplay_actors reo_native_transform_math reo_native_gameplay_session)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(reo_native_gameplay_collision PRIVATE -Wall -Wextra -Wpedantic -Werror -fno-fast-math -ffp-contract=off)
endif()
