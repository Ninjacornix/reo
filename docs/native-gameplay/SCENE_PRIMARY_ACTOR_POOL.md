# Separate cinematic player storage

Status: native storage and first-inactive selection pass both compiler focused
comparisons. Uninstalled; Step4 remains incomplete.

`World::scene_primary_actors()` owns eight temporary Actors independently of the
ordinary primary roster and ten auxiliary actors. Every temporary actor resolves
through the canonical World entity store, with its own generation and domain.
Ordinary linked retirement refuses these identities; the pool owns their lifetime.
Finding an inactive slot does not activate or reserve it, matching5F1330.

Initialization reproduces the semantic cleared actor fields and physical indices
from5F1290. It prepares all eight replacements before publication. Insufficient
entity capacity leaves the old pool intact; this deliberate native transaction
needs room for eight additional generations during reset. Old retained Actor
leases remain valid objects while their retired identities stop resolving.
Reset or explicit pool close refuses an attached model or playback model. The
World shutdown path seals all identities and releases the pool under its guard.
Cleanup callbacks see a fully published replacement or fully closed pool and
cannot recursively initialize, find, close the World or mutate the pool.

Both `scene-primary-storage-{llvm,gcc}-v2` receipts pass48,214 checks:1,024
active masks/encodings, null-base selection, complete original initialization,
23 capacity profiles,34 reset/close callbacks and three attached-model refusals.
Actual owned P00_00.NBD supplies the model lifetime case. Full5F1290 and5F1330
bodies are word-checked against the pinned owned o2 and executed. The zero-fill
routine is a bounded fixture port; scratch ownership and the following571010
sixteen-object initialization remain explicit ports.

Current paired regressions also pass:106,065 primary model/scene checks,
39,664,817 primary initialization checks,2,799,371 World checks,32,768 behavior
cases and948 original shared-bank comparisons with live publication. Evidence is
`scene-pool-{primary-models,initialization,world,behavior,shared-banks}-{llvm,gcc}-v1`.
The twelve-cohort seal is `native_scene_primary_actors_qualification_v1.json`.

This does not admit5F0DC0 assignment, roster cloning, physical model-slot handoff,
primary cinematic playback, object timelines or full scene exit. In particular,
the existing primary model cache still validates canonical main roster identities;
these tests do not authorize bypassing that check for temporary Actors. No game
was launched and no performance improvement is claimed.
