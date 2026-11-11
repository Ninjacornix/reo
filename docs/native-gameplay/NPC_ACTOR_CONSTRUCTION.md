# Native NPC actor construction

NpcActorConstruction now implements the admitted6837C0 construction contract
through the canonical ten-actor AuxiliaryActorPool, ActorAssets, native model/
animation objects, collision profiles and actor-owned hit definitions. The
factory prepares allocations/content before publishing a live actor. World
busy/closed state, pool exhaustion and missing input bindings are explicit.

The generated profile contains130 NPC identities witnessed by owned model
aliases or246 actual0950 NPC scene headers. It decodes the actual716450+20*id
construction metadata: character/style selection, subtype, signed health,
scale and height parameter. It preserves the source's low-halfword identity
and low-byte model-class arguments. Four actual hit-region definitions come
from the owned contact-selector0 table; other selectors remain unadmitted.

Construction creates the actual model and independent Playback, supplies the
three required native motion-bank references, sets the one-channel contract,
initializes the source state/health/scale/room, and adopts the real body/local
collision profiles. Part visibility starts enabled except part1 for classes
other than1. Class1 claims from the actual four-slot attachment owner; full
attachment capacity is an admitted absent/FF result. No original callback,
model-work address or guest-addressed contact buffer is retained in production.

Motion bindings must be supplied by their real owners. Their content selection
and actual NPC animation callback are still open; an absent bank is refused.
The constructor test uses distinct known bank identities and does not animate
them. This qualifies reference selection/binding, not a common-motion loader.
The old model/work, attachment and AB0 pointer consumers still require their
corresponding native/rendering migration audit before game installation. Their
addresses are not recreated as native gameplay state.

Both compiler cohorts pass19,964 checks with505 supported constructor cases
compared against complete, source-word-audited6837C0. They use all130 admitted
identities across classes0/1/2/255 with argument wrapping. Five identities lack
ordinary N bundles, producing15 explicit preparation refusals for non-HP
classes; all130 class1 HP preparations succeed. Source model and allocation
requests are declared observations while actual native asset/model/animation
construction and pool behavior run separately in the same executable. The130
original attachment calls are observed; the native four-slot owner is tested
through exhaustion independently.

The comparisons include initial state, room, health, styles, scale, height,
part visibility, bank selection, collision center/radius and markers. The
composition also covers50 pool retirements, full actor capacity, missing bank
inputs, and a real NPC-targeted cutscene voice callback that attempts reentrant
construction/closure and verifies busy refusal. Voice/facial providers are test
ports; no sound device or game is opened. Existing406-model/330-construction
owned tests still pass5,681 checks; all ten current parent CTest entries pass
on both compilers.

The initial compiler attempt caught a signedness error in the test scaffolding,
and the first LLVM comparison caught an omitted pointed-to local-shape constant
in that fixture. The corrected fixture copies the independently verified owned
target bytes and passes both compilers. No production solver change was needed.
Historical failed receipts remain preserved.

Reproduce with generate_npc_actor_definitions.py and
verify_npc_actor_construction.py, explicit compiler/CMake/build/data-root paths
and fresh output folders. The evidence seal is
native_npc_actor_construction_qualification_v1.json. NPC scene assignment,
actual bank/content callers, NPC callbacks, native gameplay installation and
full Step4 acceptance remain open. No new performance result is claimed.
