"""Concrete shared visual World dependencies for source-frozen comparisons."""
SURFACE_WORLD_UNITS=[
    'game/native/'+group+'/'+name+'.cpp'
    for group,names in [
        ('gameplay_effects',['surface_work','resource_debris','resource_flight','resource_flight_queries','actor_contact_channels','inherited_trail']),
        ('gameplay_world',['world','linked_models','target_metrics','auxiliary_actors','scene_primary_actors','bodies','model_poses','model_constraints','humanoid_motion_bindings']),
        ('gameplay_actors',['input','health']),
        ('gameplay_ai',['execution','control_requests','initialization','priority_goals','reactions','observation_gates']),
        ('gameplay_navigation',['navigation','bank','conditions','edges','routes','cost_routes','cost_graph','local_routes','link_collection','cross_room','actor_routes','destination','visibility','scene_candidates','scene_lookup']),
        ('gameplay_collision',['collision','response','actors','actor_views','trace']),
        ('animation',['constraints','constraint_math']),
        ('transform_math',['heading']),
    ] for name in names
]
