# Cinematic temporary-player and auxiliary actor frames

Status: bounded native5ECAE0 traversal qualified on both compilers. Uninstalled.
Step4 remains incomplete; the installed game remains V39.

`CinematicActorFrames` visits the separate eight temporary player records in
physical order, then the existing ten-capacity auxiliary NPC list from its head.
It restores secondary-pose links before each active actor's real CommonActorFrame.
Inactive records are visited without callbacks. Hidden active actors still get
their common frame, as the source requires. The ordinary NPC camera/inhibition
filters do not belong here. There is no invented outer pause gate or timer tick.
The canonical primary roster and fifty-node linked-model population are separate.

One owner binds to a World. Reentry/closure during a pass refuses. The fixed actor
generation reset remains protected by the World guard. Auxiliary reset is guarded
during that list pass; a fixed callback may still reset the auxiliary population
before its head is read. The next auxiliary identity is read after the current
callback, preserving a callback's retirement of a later actor. CommonActorFrame
continues to reject retirement of its own current actor. Provider exceptions keep
their completed prefix and unwind both inner and outer guards. Required link
restoration failure stops before the common prelude with an explicit result.

The comparison executes complete5ECAE0,61A6A0,61B1A0,66A2E0 and its qualified
root/basis bodies.66B500 behavior remains the existing explicit observation port;
the actual native behavior/action implementations are not substituted into this
cohort. Native CommonActorFrame, typed link restoration, the actual temporary/
auxiliary owners, root integration and floor/basis consumer all execute. Initial
original model links project the separately qualified importer. Real P07/HP07/
HN54 inputs supply required nodes; the original packing is not newly executed.

Cases vary activity, visibility, contact suppression, signed pause and input
filtering. They compare restore/common callback order, actual frame effects,
later fixed activation, auxiliary reset before head sampling, next-actor retirement,
singleton ownership, provider failure, absent populations and joined closure.
Mutation of the original auxiliary links/head is an explicit behavior observation
port corresponding to actual native pool mutation, not execution of its original
allocator in the callback.

Both `cinematic-actor-frames-{llvm,gcc}-v3` cohorts pass10,508,336 checks, including
256 traversal cases,3,014 completed common frames,428 link restorations and33
passes with callback mutations. Three native failure cases cover missing required
models, provider exceptions and actual current auxiliary retirement. V1 retained
a missing fixture include; V2 passed but counted an overlapping mutation setup
twice. V3 corrects that counter and adds current-retirement coverage. Current
model-lifetime regressions pass150,804 checks, and all five dependent parents
pass on both compilers. Combined evidence is
`tools/native_reconstruction/native_cinematic_actor_frames_qualification_v1.json`.

This owns the specific traversal; its phase admission still belongs to the full
scene scheduler. Actual behavior/action dispatch, later61A820 secondary chains,
5ECB80 model publication,5ECBE0 reaction/secondary-pose traversal, category10
objects and complete scene entry/exit remain required. No game run, measured
speedup or new slowdown cause is claimed.
