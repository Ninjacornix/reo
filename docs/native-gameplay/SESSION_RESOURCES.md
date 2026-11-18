# Native application resources

`NativeSession` now owns one opaque `SessionResources` lifetime. Binding real
assets does not admit resource scripts: `initialize_resources()` must first
execute the actual ordinary591C50 selection, item import, placement and starting
inventory producer. The graph shares the session's World, Update, Records,
SessionRooms geometry, Lighting and RNG. It contains no guest CPU or RAM model.

## Production ownership

`session_resource_assets.cpp` reads the actual `itemNNN.dat` and an explicitly
supplied static-resource NBD from the session's ScenarioArchive. Imported effect
geometry and the contact Catalog remain required immutable asset capabilities.
This API does not claim the wider1CDFE0 asset-selection caller.

The graph owns one live SceneResources table, one ResourceTemplates table,
ResourceModels/ResourceFrames/ResourceFactory, WorldInventory and the existing
170/174 facades. Its PoseWorkPool registers exclusively with that same World's
EntityStore. Packets, ResourcePoseWork, presets, timing, motion, arc, cloud and
room projectile consumers borrow those exact owners. TimedLights uses the
session's existing linked scheduler and Lighting auxiliary pool. No replacement
World, room records, mutable descriptor table or simulation clock is created.

The immutable input's parsed templates are asset validation only. Bootstrap
writes the graph's sole mutable template bank; every runtime factory, inventory,
descriptor and script consumer references that same bank.

The floor lease aliases SessionRooms' existing immutable geometry object without
retaining a RoomInvocation/NativeSession. SessionRooms itself keeps a weak host
reference. This avoids a session→resource→room lease→session cycle, while floor
data can outlive retirement.

## Actual startup and callers

`ResourceBootstrap` implements complete ordinary591C50 and its5919F0 clear,
591D50 weighted table selection,5920C0 three-section item importer,
5921D0 templates,592370 placements,5924A0 tuning and5924E0 starting inventory.
The152-entry starting table is immutable converted owned metadata at723810.
Selection uses actual difficulty×4 plus the observed RNG selector and reads the
actual archive key. The roll is a read of the canonical secondary RNG, not a
new random advance. One roll applies to each weighted row, as in the source.

Clear establishes all256 sixty-byte descriptors, the actual zero template
selector, template bank,129 tuning rows and Session's four auxiliary lists.
Starting inventory uses existing allocation, capacity, insertion and compact
owners; it does not introduce a parallel inventory. Generic unknown population,
difficulty or asset mode refuses before that prefix. Offline4BAE96 adjustment
and filesystem asset mode remain unavailable profiles.

The NativeSession archive host adopts only the constant3243D7=1 subproducer
within1AC650. Its complete original body is audited and executed up to1A8CE0,
after observing the four prior platform setup calls and the actual delay-slot
write. This does not qualify the remaining platform startup.

After successful startup, NativeSession supplies the real descriptor, factory,
inventory, template,170 and174 providers to its interpreter caller.
`SessionResourceWorkers` intercepts only `Worker::resource_instances` and
`Worker::scene_pose_tasks`; all other phases require the supplied real services.
Resource models use the sole registered CutscenePlayback's actual
`state().cinematic_enabled`4BAE9A. Absence refuses, including an empty model
domain. World.paused is a different source role and is not substituted.

The resource post-update request calls the existing room object
`InteractionOwner::Lifetime::rebuild_dynamic()`6AEDA0. SessionRooms reads that
same cached dynamic storage. The admitted r0417300 fixture takes the actual
zero-current-object/no-grid branch; this does not prove positive movable-object
sampling. Resource callbacks mark the canonical World busy; nested close,
startup and room replacement refuse while the invocation is active.

The graph remains pinned to its installed room. Replacement refuses before
discarding descriptors or inventory until the actual591920 persistent model
reset/rebind caller is adopted. Closing retires model and pose generations,
releases descriptor attachments, tasks, packets and visuals before the World.

## Verification

`session-resource-import-{llvm,gcc}-v4/receipt.json` both pass9,125,409 checks:
8,765 owned cases across five scenarios,17,530 actual reads,953,401 selections,
953,201 placements and18,425 starting resources. The complete original bodies
compare all256 descriptor projections,129 tuning rows, template metadata,
whole eight actor record projections, RNG and auxiliary lists. Each compiler
also checks256 asset-mode producer prefixes and four pre-prefix refusals.
Original register/memory scaffolding exists only in this offline oracle.

`session-resources-current-{llvm,gcc}-v5/receipt.json` both pass68 checks against
the actual archive, imported contact catalog and effect geometry, capturing863
source/header/CMake inputs and67 native libraries without source drift. The
owned fixture loads222 selected/placed records and four starting resources,
runs four actual resource/pose worker visits, tests real interpreter174 routing,
exclusive pose ownership, foreign owner refusal, callback close guards and both
explicit and destructor-only shutdown. Retained floors do not keep the host
alive. The controlled174 instruction and cinematic state are caller-composition
fixtures, not an inferred authored launch or full cinematic playback.

The finalv4/v5 fixture constructs actual DEF41 content129, root0 with four real
part poses, and uses that same real key in its174 command. Priorv3 used content1,
which has no DEF41 geometry and correctly exercises the source's normal missing
geometry result. Native production did not change for this stronger positive
asset check.

Earlier current-v2 receipts retain a fixture-only failure: a test poisoned the
derived dynamic cache even though the real room has no object grid;6AEDA0
correctly preserves it in that branch. The invalid fixture mutation was removed;
production code did not change. Current-v1 is the smaller54-check passing cohort.

`session-resources-vm-{llvm,gcc}-v1/receipt.json` both pass586,070,532 checks,
46,249 original dispatcher invocations and12,388 owned instruction comments
against this graph's current application library closure. Supported table
coverage remains368 ordinary and342 offline entries; this integration does not
claim a new script handler or a newly admitted scenario EVB.

`session-resources-parents-{llvm,gcc}-v3/receipt.json` both pass all31 current
parent contracts, including the new projectile trail owner. The same cohorts
run the expanded actual dialogue worker44 checks, actual cinematic speech
4,715,864 checks across33 clips/21,649 frames/129,696 model patches, and actual
room lighting285,448 checks across227 keys. Their complete source/CMake closure
has no drift. These are current caller proofs, not installed-game acceptance.
The finalv5/v3 refresh also captures the corrected independent dialogue bank
room-field consumer and additive transient-light method. This resource graph
does not consume either newly developed operation; their complete source
qualifications remain with their respective owners.

## Remaining Stage4 gates

This graph does not supply successful stand-ins for missing resource companion
audio/light actions, inherited trail mode1, projectile actions, general surface
effects, real audio/spatial host or periodic frame publication. Reached missing
consumers continue to refuse. Complete ordinary/offline EVB admission, canonical
cinematic application installation, terminal actor/physics and phase services,
input, transport/media hosts, semantic save/resume and replacement/acceptance of
installed gameV39 remain open. Renderer submission remains a Stage5 boundary.
No game or device was launched and this component does not complete Stage4.
