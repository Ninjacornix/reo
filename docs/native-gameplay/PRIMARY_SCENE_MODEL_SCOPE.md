# Scoped cinematic primary model ownership

Status: qualified native CPU composition, not a complete cinematic owner or
installed gameplay. Stage4 remains incomplete; installed game remains V39. No
game, rendering test or performance measurement was run.

Actual primary construction now records the group, temporary identity and
source release policy inside the model owner. `open_scene_models` validates
those records against the separate eight-player pool and issues a domain/epoch
scope. Normal main-cache captures and earlier prepared work cannot cross that
scope implicitly. Scoped kind0 capture requires the actual constructed identity,
group and header class. Public primary initialization still refuses temporary IDs.

Preparation uses the physical slot's resident model for cache reuse, rather than
the unrelated model copied from a different roster actor. It clones mutable poses
and preserves Actor-owned channels/root history. Rebuilds acquire actual assets
and perform the existing character-bank retirement. The private fresh initializer
admits only this validated temporary pool binding. Temporary notification/zero-
pause restore is explicitly unavailable: its borrowed physical-pointer association
requires separate evidence. This is not enabled by changing ordinary game speed.

`reset_scene_actors` performs the guarded generation reset while physical rows
retain their resources. Insufficient spare generations leave all old identities
and resources intact. `release_scene_model` then uses retained construction policy
and physical slot metadata, without resolving a stale temporary Actor. Only
release-marked groups visited by the source's sixteen-descriptor exit walk are
admitted. Character-bank publication, cache retirement and resource destruction
stay within one outer guard. Repeated cleanup is harmless.

`return_scene_models` requires reset and the required selected releases first.
It clones remaining resident work into previously capable canonical bindings,
preserving their own channels and root history. Absent/uninitialized inactive main
actors gain no model capability. Returned actors remain hidden with invalidated
collision poses; **the caller must reinitialize them before gameplay resumes**.
The tests execute that reinitialization. Old external Actor/resource leases remain
independently valid; old scopes and identities cannot mutate a later phase.

Both `primary-scene-scope-{llvm,gcc}-v4` cohorts pass128942 checks. Sixteen owned
kind0 headers feed64 controlled source-slot/pause compositions:32 physical cache
reuses,32 rebuilds,64 resets/returns,32 selected retirements and128 canonical
reinitializations. Full original cache/release comparisons cover the decisions;
native model/asset/publication/initialization operations execute independently.
There are96 cleanup callback guard observations,448 boundary refusals, one
capacity failure and two absent/inactive return cases. This is controlled binding
evidence, not execution of complete descriptor selection/entry/exit for all scenes.

The full initializer regressions are `scene-scope-initialization-{llvm,gcc}-v1`,
including39837137 checks and fifteen parents per compiler. Pool regressions are
`scene-scope-pool-{llvm,gcc}-v1`. The combined source/evidence seal is
`tools/native_reconstruction/native_primary_scene_model_scope_qualification_v1.json`.
The earlier static lifetime audit verifies5ED340/5ED770's reset-before-retirement
order. Existing original resource/I/O/renderer ports retain their stated limits;
the complete5ED770 body is not newly executed as one integrated native exit here.

Remaining cinematic work includes the extra5ED340 bank/object cleanup, all sixteen
category10 objects, sparse primary retargeting, kind3 and other scene consumers,
restore ownership and the real entry/update/exit caller. Installed gameplay, save,
co-op and shutdown acceptance remain open.
