# Native cutscene NPC assignment and parameters

The kind-1 adapter prepares owned scene-header requests and constructs actual
NPCs through `NpcActorConstruction`. It imports the raw halfword identity,
low-byte `(header_class XOR 1)`, scale-profile byte and 32-bit visibility mask.
It retains the first 15 stream-3 parameter records, stopping at timestamp FFFF,
with signed halfword keys and raw word values. Physical exhaustion before that
terminal/cap is an error. Parameter lookup/consumption remains a scene-owner gate.

Creation restores every real part to visible before scale/graphics preparation,
applies unit scale and actual native constraint initialization for profile zero,
then writes the first 32 visibility bits. Parts beyond 32 retain visibility 1.
The canonical pause byte is reread at the original shadow boundary. An unpaused
scene requires its rendering provider; completed no-shadow is distinct from a
missing provider. Reentrant world/pool mutation and closure are refused while
that provider runs. A failure after publication returns the actual actor ID and
preceding effects; the enclosing scene owner must latch and handle the partial
result. The adapter does not invent a rollback or retry the construction itself.

Both compiler cohorts pass 37,640 checks over all 548 supported 0950 descriptors,
each with pause on and off: 1,096 scene passes, 490 actual native constructions,
245 completed shadow-provider requests and 128 retained parameter entries.
Complete source-word-audited 5F0610 and 5F0B50 compare selected NPC behavior in
1,094 passes / 470 NPCs. Primary and kind-2 headers are explicitly disabled in
that restricted original fixture; this is not a whole-scene ownership claim.
Constructor/model and shadow calls are declared observations while the real
native factory, assets, constraints, part state and track bindings run separately.
False and throwing graphics providers verify actual partial IDs/effects and
release of both mutation guards. All eleven parent tests, corrected base NPC
constructors and the existing owned actor baseline pass on each compiler.

Scenario 1 `dm0600A.BIN` contains 11 active NPC headers. Original 682C60 initializes
ten auxiliary slots and 682D10 returns null on exhaustion. The native owner
therefore constructs ten and reports full for the eleventh, on both pause
passes. The original full case is deliberately not executed through its
unchecked caller. The first ten native actors remain real and retained. This
static content/capacity mismatch has not been reproduced in gameplay, and does
not establish that the scene is reachable or unused. Changing only pool capacity
would conflict with other ten-slot consumers; scene lifecycle/modernization and
actual acceptance must resolve it before installation.

The scene tests first exposed the constructor's incorrect association with the
primary substitution filename route. That production association is corrected
as documented in NPC_ACTOR_ASSETS.md and NPC_ACTOR_CONSTRUCTION.md. A subsequent
fixture incorrectly asserted an unused second constraint argument; complete
5D6850 reads only its actor input, so that assertion was removed. Failed receipts
remain available. Corrected scene receipts are
`cutscene-npc-construction-{llvm,gcc}-v3`.

Current World cohorts pass 2,687,826 checks and 7,989,320 original calls per
compiler. They compare all 233 auxiliary skeletons / 12,475 nodes against original
initialization/rebuilding, reject 466 truncated skeletons and preserve strict
handling outside the seven bounded noncanonical-length profiles. All 1,469
descriptor actor groups / 77 parameter records are compared independently of
scene actor-kind selection. These comparisons retain the prior native World,
commands, tracks, linked-model, movement and animation regression coverage.

Reproduce using `verify_cutscene_npc_construction.py`,
`animation/verify_world_playback.py`, the pinned owned inventory/corpora,
explicit compiler/CMake/build/data-root paths and fresh output folders. Evidence
is sealed in `native_cutscene_npc_construction_qualification_v1.json`.
Actual motion content, NPC callbacks, remaining actor kinds, complete scene
creation/teardown, rendering owners, legacy descriptors, coherent game
installation and full Step 4 acceptance remain open. No game was launched and
no runtime slowdown or performance improvement is claimed.
