"""Concrete shared visual World dependencies for source-frozen comparisons."""
SURFACE_WORLD_UNITS=[
    'game/native/'+group+'/'+name+'.cpp'
    for group,names in [
        ('gameplay_effects',['surface_work','resource_debris']),
        ('gameplay_world',['world','linked_models','auxiliary_actors','bodies','model_poses','model_constraints']),
        ('gameplay_actors',['input','health']),
        ('gameplay_navigation',['navigation','bank','conditions','edges','routes','cost_routes','cost_graph','local_routes','link_collection','cross_room','actor_routes','destination','visibility','scene_candidates','scene_lookup']),
        ('gameplay_collision',['collision','response','actors','actor_views','trace']),
        ('animation',['constraints','constraint_math']),
    ] for name in names
]
