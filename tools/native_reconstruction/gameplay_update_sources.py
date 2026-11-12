"""Concrete native World/VM/update production closure for comparisons."""
UPDATE_UNITS=[
    "game/native/"+group+"/"+name+".cpp"
    for group,names in [
        ('gameplay_world',['world', 'behavior', 'surfaces', 'motion', 'linked_models','target_metrics','auxiliary_actors','scene_primary_actors','inventory_presence','interaction_transitions','color_fade', 'bodies', 'model_poses', 'model_constraints', 'resource_models', 'model_attachments','alignment','actor_placements']),
        ('gameplay_actors',['entity', 'health', 'status', 'hit', 'input']),
        ('gameplay_session',['session','activity']),
        ('gameplay_ai',['execution','control_requests','initialization','priority_goals','reactions','observation_gates','steering','off_room_actions','off_room_travel']),
        ('gameplay_navigation',['navigation','bank','conditions','edges','routes','cost_routes','cost_graph','local_routes','link_collection','cross_room','actor_routes','destination','visibility','scene_candidates','scene_lookup']),
        ('gameplay_tasks',['tasks', 'events']),
        ('gameplay_events',['events','statistics']),
        ('gameplay_scenario',['interpreter', 'flags', 'offline', 'scene_resources', 'scene_controls', 'content', 'sequence_control', 'lighting', 'stream_channels', 'room_rules', 'scene_models', 'room_scene_input', 'room_scene_owner', 'scene_model_bindings', 'scene_matrix_programs', 'scene_matrix_playback', 'scene_matrix_tables', 'actor_requests', 'room_object_commands', 'periodic_effects', 'resource_templates', 'fog','script_program','actor_inventory_commands','auxiliary_room_rows','cutscene_requests']),
        ('gameplay_update',['update','actor_gauge','navigation','ai','ai_observation','ai_waypoints','script_setup']),
        ('gameplay_collision',['collision', 'response', 'actors', 'actor_views', 'sweep', 'ownership', 'room_objects', 'footprint', 'trace', 'room_geometry', 'object_interactions', 'object_lifetime', 'room_damage']),
        ('gameplay_effects',['surface_work', 'periodic_visuals', 'geometry', 'tracks', 'resource_companion','resource_debris']),
        ('animation',['constraints', 'constraint_math', 'model', 'model_math', 'curves']),
        ('gameplay_lighting',['lights']),
        ('transform_math',['transform_math','heading']),
    ] for name in names
]
UPDATE_UNITS.append('game/native/gameplay_scenario/scenario_archive.cpp')
UPDATE_UNITS.append('game/native/gameplay_scenario/cutscene_cues.cpp')
UPDATE_UNITS += ['game/native/gameplay_session/launch.cpp','game/native/gameplay_world/launch_roster.cpp']
UPDATE_UNITS += ['game/native/gameplay_scenario/npc_descriptors.cpp']
UPDATE_UNITS += ['game/native/gameplay_scenario/enemy_descriptors.cpp','game/native/gameplay_scenario/enemy_routes.cpp']
UPDATE_UNITS += ['game/native/gameplay_scenario/character_remap.cpp']
UPDATE_UNITS += ['game/native/gameplay_world/enemy_initialization.cpp']
UPDATE_UNITS += ['game/native/gameplay_update/material_animation.cpp',
                 'game/native/gameplay_update/linked_model_workers.cpp']
UPDATE_UNITS += ['game/native/gameplay_world/'+name+'.cpp' for name in
                 ['linked_updates','scripted_motion','cutscene_actor','motion_transforms',
                  'surface_orientation','surface_orientation_math']]
UPDATE_UNITS += ['game/native/animation/'+name+'.cpp' for name in
                 ['playback','model_blend','motion_bank','motion_descriptors']]
UPDATE_UNITS += ['game/native/gameplay_scenario/cutscene_actor_commands.cpp',
                 'game/native/gameplay_scenario/cutscene_actor_tracks.cpp']
UPDATE_UNITS += ['game/native/gameplay_scenario/script_audio.cpp']
UPDATE_UNITS += ['game/native/gameplay_scenario/script_resource_parameters.cpp']
UPDATE_UNITS += ['game/native/gameplay_audio/'+name+'.cpp' for name in
                 ['routing','import','spatial','owner','scenario_cues']]
UPDATE_UNITS += ['game/native/audio_banks/v2/'+name+'.cpp' for name in
                 ['algorithms','session']]
