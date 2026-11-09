"""Concrete shared visual World dependencies for source-frozen comparisons."""
SURFACE_WORLD_UNITS=[
    'game/native/'+group+'/'+name+'.cpp'
    for group,names in [
        ('gameplay_effects',['surface_work']),
        ('gameplay_world',['world','linked_models','bodies','model_poses','model_constraints']),
        ('gameplay_actors',['input','health']),
        ('gameplay_collision',['collision','response','actors','actor_views']),
        ('animation',['constraints','constraint_math']),
    ] for name in names
]
