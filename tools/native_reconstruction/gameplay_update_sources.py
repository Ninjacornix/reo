"""Concrete native World/VM/update production closure for comparisons."""
UPDATE_UNITS=[
    "game/native/"+group+"/"+name+".cpp"
    for group,names in [
        ('gameplay_world',['world', 'behavior', 'surfaces', 'motion', 'linked_models','auxiliary_actors','inventory_presence','interaction_transitions','color_fade', 'bodies', 'model_poses', 'model_constraints', 'resource_models', 'model_attachments','alignment']),
        ('gameplay_actors',['entity', 'health', 'status', 'hit', 'input']),
        ('gameplay_session',['session','activity']),
        ('gameplay_ai',['execution','control_requests','initialization','priority_goals','reactions','observation_gates']),
        ('gameplay_navigation',['navigation','bank','conditions','edges','routes','cost_routes','cost_graph','local_routes','link_collection','cross_room','actor_routes','destination','visibility','scene_candidates','scene_lookup']),
        ('gameplay_tasks',['tasks', 'events']),
        ('gameplay_events',['events','statistics']),
        ('gameplay_scenario',['interpreter', 'flags', 'offline', 'scene_resources', 'scene_controls', 'content', 'sequence_control', 'lighting', 'stream_channels', 'room_rules', 'scene_models', 'room_scene_input', 'room_scene_owner', 'scene_model_bindings', 'scene_matrix_programs', 'scene_matrix_playback', 'scene_matrix_tables', 'actor_requests', 'room_object_commands', 'periodic_effects', 'resource_templates', 'fog']),
        ('gameplay_update',['update','actor_gauge','navigation','ai']),
        ('gameplay_collision',['collision', 'response', 'actors', 'actor_views', 'sweep', 'ownership', 'room_objects', 'footprint', 'trace', 'room_geometry', 'object_interactions', 'object_lifetime']),
        ('gameplay_effects',['surface_work', 'periodic_visuals', 'geometry', 'tracks', 'resource_companion','resource_debris']),
        ('animation',['constraints', 'constraint_math', 'model', 'model_math', 'curves']),
        ('gameplay_lighting',['lights']),
        ('transform_math',['transform_math','heading']),
    ] for name in names
]
