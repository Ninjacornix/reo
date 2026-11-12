# Stage 4 integration ownership audit

Source audit, 2026-11-12, initially against `bc5d18b2`. Stage 4 remains
incomplete. This document replaces neither the component receipts nor the
end-to-end acceptance gate. No game, UI, audio device or power action was used
for this audit.

The immediate integration cut is a native application/session owner that
constructs the existing World, Update and content owners and supplies their
remaining real service implementations. There is currently no production
construction of `gameplay_world::World` or `gameplay_update::Owner`. Searching
production outside `game/native`, tools, generated source and documentation finds
only the legacy save/session adapter importing native gameplay headers.
`recomp/reo_bootstrap.cpp` installs that adapter under
`REO_BUILD_NATIVE_GAMEPLAY_SAVE` / `REO_NATIVE_GAMEPLAY_SAVE`, immediately before
starting original execution. It does not install native World gameplay.

## Concrete ownership and closure matrix

| Required cut | Already implemented, to reuse | Missing production ownership / evidence |
|---|---|---|
| Application/session entry | `World(Profile, shared_ptr<Session>)`; `gameplay_update::Owner(World&, FlagNotifications&, shared_ptr<const RuleBook>, GameplayMessageSink*, const room_objects::Owner*)`; `Owner::initialize_launch_roster` | An application entry selecting the native session before original gameplay starts; explicit immutable launch configuration and imported sources; one simulation owner and shutdown order. Do not create a RAM/register projection of World. |
| Scenario/room preparation | `ScenarioArchive` reads actual retained NETBIO00; `room(RoomId)`, `scenario_scripts`, `read_member`, `read_resource`; `Owner::load_scenario_scripts/load_room_scripts/load_scenario_npcs/load_scenario_enemies` | Native session must call these and keep their content leases. All five EVBs still encounter unsupported semantics. A room-only proof must not claim complete scenario launch. |
| Primary actor/model startup | `spawn_primary`, launch roster import, `ActorAssets`, `HumanoidMotionAssets`, `HumanoidMotionOwner`, `PrimaryActorModels::capture/prepare/apply` and initialization/restore selector | A coherent startup transaction creating roster actors, preparing and applying actual models and default motion banks, equipment context and any saved overrides. Source selection of actual launch room/placement is not established by the parser alone. |
| Shared room records | `SceneControls`, `ownership::Proxies`, `RoomSceneInput`, `RoomSceneOwner::install`, `SceneModels`, `SceneMatrixPrograms`, `SceneModelBindings` | Actual room model preparation/publication and common Records identity; room transition owner must retire bindings/tasks before replacing records, and install admitted channel tables/models. `RoomSceneOwner` is a room proxy initializer, not the whole game/session. |
| Ordinary update | `Owner::advance` owns pause/transition gates, worker ordering, script/task/timer ordering and clock commit | Concrete terminal `PhaseServices` implementation. Existing CollisionWorkers, LinkedModelWorkers and NpcActorWorkers are decorators that forward unowned work. |
| Primary behavior and actions | `BehaviorFrameServices`, `MotionFrameServices`, `MotionTransformFrameServices`, `GridSurfaceOrientation`, status/hit/gauge/recovery, inventory/resource primitives | Concrete terminal World::Services and BehaviorServices implementations; actual action dispatch and control/cooperation/authority consumers. There is no production implementation of BehaviorServices::dispatch. Missing actions cannot be successful no-ops. |
| Collision/contact gameplay | Existing room geometry, body solver, collision-height workers, target cache, contact packet/region/route owners | Real CollisionParticipants, model pose leases, current room floor/wall/proxy publication, hit-region/contact producer ordering and packet consumers. Renderer submission can remain the Stage 5 boundary; gameplay pose/contact production cannot. |
| Cinematic lifecycle | Separate primary/NPC/object pools, roster construction, model cache handoff, typed actor/object streams, actual object assets/motion banks and resource-index lookup | One scene owner for request selection, entry, authored group construction, timeline/media cadence, model passes, exit and restoration; explicit handling of unresolved authored model/track cases. Pose work in parallel does not supply this owner. |
| Platform input | Native ControllerFrame, remapping, edge/repeat/menu routing and World controller spans | Platform sampler feeding normalized frames, focus/disconnect policy and frame ownership. Existing pad/RAM callers have not adopted this path. |
| Transport | Typed `gameplay_update::Reception`, actor-message queues, cooperative events and control payload owners | Protocol codec and authority adapter into canonical World/Update with generation-safe references, room transition/ownership callbacks and outgoing event drains. `network/native/world_sync.h` still takes RAM, R5900Context and PS2Runtime and is not this adapter. |
| Native media calls | `gameplay_audio::Owner`, SceneBankAudio, StreamChannels/StreamInstances and retained stream catalog; Stage 3 owners | Session must own direct bank/stream/movie services, real audio service tick, cue-to-scene completion/pause/end coupling, room audio callbacks and joined retirement. Update::state.audio_tick is intentionally optional and must not be a simulated frame counter. |
| Save/resume | Legacy Container/codec, native Options/Random, typed primary-start decoder and saved initialization | Semantic native session snapshot including World state, descriptor/flag/route/task/script continuation identities, durable host file ownership and resume transaction. `gameplay_save::LiveState` still consists mainly of opaque legacy section byte arrays; the nine-entry adapter explicitly projects guest RAM. |
| Acceptance/build | Dual-compiler component oracles and native CMake target graph | Candidate linking and selecting the native game owner; owned launch/gameplay/room changes/cinematics/pause/exit/save-resume/error-recovery runs, input/transport/media acceptance, final source/build identity and joined shutdown. |

## Actual APIs needed by the new owner

`gameplay_world::Profile` supplies controller layouts/count; `World::controllers()` exposes
the native ControllerFrame span, and `controller_bindings` maps actors to ports.
The Session is shared once and must not be re-created by each subsystem.

The admitted ordinary tick is:

```cpp
Owner::advance(PhaseServices&, world::Services&, scenario::Providers = {},
               std::size_t script_budget = 4096,
               std::size_t task_budget = 1024);
```

World::Services must implement `begin_offline_frame`, `run(Stage, World&, Actor&)`,
`remote_motion`, `find_grid`, `switch_grid` and `grid_response`.
BehaviorServices additionally implements stage effects, primary/secondary
`dispatch`, action-notice suppression and inherited health/status/hit services.
The frame stages are declared in `gameplay_actors/frame.hpp`; their canonical
consumer is `gameplay_world/world.cpp::World::update_primary`.

`BehaviorFrameServices` owns only `Stage::update_behavior` and delegates the rest.
`MotionFrameServices` and `MotionTransformFrameServices` similarly compose
specific native operations. `BehaviorServices::dispatch` is called for primary
and secondary action passes from `update_behavior`; finding native status/motion
helpers therefore does not prove actual action execution.

PhaseServices requires `run(Worker, Owner&)`, `button`, `transition_request` and
`effect(PhaseEffect, Owner&, argument)`. Existing production decorators cover:

- CollisionWorkers: target_caches, actor_collision_shapes, collision_heights.
- LinkedModelWorkers: scenario_model_poses.
- NpcActorWorkers: auxiliary_actors.
- Bound `Owner::linked_actor_updates_`: scenario_actors.

The remaining Worker list in `gameplay_update/update.hpp` is the exact closure
checklist: reset queues, armed/limit action, interaction/proxy preparation,
primary/auxiliary model and postprocess work, hit regions, camera modes, model
interactions, resources, scene tasks, callback/UI/audio/sequence work, occupancy,
contact production/delivery, entity ownership, action publication and transition
control. Some have qualified native primitives; each still needs an explicit
terminal caller and correct ordering. `render_work_banks` may publish an
immutable Stage 5 submission boundary; it must not run gameplay via the original
CPU to obtain it.

`scenario::Providers` has explicit fields for flags, timers, signals, canonical
flags, SceneResources/effects/owners, counters, sequences, lighting, channels,
controls/effects, stream channels/backend, saved controls, World, action choices,
models, room objects, periodic/surface effects, templates and forced terminal.
Update::run_script injects its canonical flags/timers/action choices. It does
not manufacture the other providers. Interpreter::execute checks whole-program
provider requirements before execution, so even the first instruction of a
program requires its complete declared provider set.

## Smallest useful owned-room bootstrap

Use `r0417300.rdt` as the first content integration fixture because its ordinary
and offline script roots were previously admitted and compared with actual
original dispatch. Keep this explicitly a room bootstrap until its scenario EVB
also admits. The original controlled script proof used fixture scene resources;
it did not establish that this room's complete geometry/model setup is admitted.

1. Create retained host asset Sources, ScenarioArchive, the canonical shared
   Session, World and Update on the simulation owner. Feed a real launch record,
   normalized controller layouts/ports and actual imported settings/seed.
2. Prepare the room RdtDirectory and section1 ScriptBank off the simulation
   path; import real room collision grids, proxy definitions, navigation,
   matrices, static models, object definitions and resource templates as their
   existing import APIs require. Record every refusal with room/member identity.
   Source proof of exactly which sections form every bootstrap provider remains
   required; do not copy a synthetic CMake fixture into production.
3. Build the actual primary actors and model/motion owner, then publish the
   admitted immutable room content through the shared Records/SceneControls/
   Proxies/SceneModels domain. Keep prepared leases alive through room retirement.
4. Bind room scripts through Owner::bind_room_scripts (ordinary channel1,
   secondary5); bind scenario channels0/4 only after the corresponding EVB
   fully admits. Offline room channels1..3 have distinct context semantics.
5. Construct all real providers declared by the prepared Program, and the
   concrete frame/phase service roots underneath existing decorators. Run
   Owner::advance; require completed status, actual controller/action/motion
   effects, script progress and correct committed clocks. Never count a call
   trace-only service implementation as gameplay.
6. Exercise transition away/back, failure rollback or explicit committed prefix,
   pause/media retirement, actor/model generation replacement and shutdown.
   Only then expand to a full scenario launch, cinematic lifecycle and save/load.

The first two useful implementation boundaries are a source-qualified complete
scenario flag/opcode tranche and a concrete session owner with a preparation
result that lists unfulfilled providers. This prevents another set of isolated
helpers from being mistaken for an installed game.

## Current stock-script frontier evidence

This audit compiled a small source-extracted coverage probe from the current
Interpreter::coverage and control_command bodies and the actual binding includes.
It reports355 ordinary and327 offline supported table entries out of432,
including original no-ops. It then reused `inventory_content_v9.py::prefix_graph`
with those masks against all171 individually hash-verified owned RDT/EVB members.
Local outputs are under `build-native-sjuni/stage4-integration-audit`.

This is a **conservative prefix model**, not native full-Program admission or
runtime reachability. It retains both conditional/context outcomes and stops at
unsupported semantics. It finds28 ordinary and23 offline banks with closed
prefixes; one ordinary payload frontier and one additional offline unknown-saved-
pointer frontier remain distinct from unsupported opcodes. The historical25/20
full-Program admission receipt remains historical; these new counts do not
replace it.

All five ordinary EVBs stop first at opcode164, target694390:

| EVB | Absolute script-bank offset | Block |
|---|---:|---:|
| r001.evb |3924|1|
| r002.evb |3380|1|
| r028.evb |2132|1|
| r035.evb |2784|1|
| r041.evb |5704|1|

Ordinary unsupported frontier occurrences, ordered by frequency:

`D0(57), 094(34), D1(15), 073(14), 156(13), 166(12), F0(12), F1(12),
132(12), F3(11), 164(11), 07F(9), 07E(9), 107(8), 134(8), F7(7),
174(6), EE(5), 150(4), A6(3), E7(3), 063(3), 106(3), 06C(3),
108(2), 10A(2), 165(2), 151(1), 06B(1), 04A(1), 03F(1), 167(1),
136(1), 093(1), 153(1)`.

These35 kinds have actual owned prefix evidence and require implementation or
source proof that an admitted native session cannot reach them. Occurrence
counts are frontier records, not executed calls and not completion percentages.

Offline has62 unsupported frontier kinds. In addition to ordinary gaps it has
distinct handlers for already-supported ordinary operations, notably
`050/052/053/054/058/059/05B/05C/05D/05E/F6`, plus offline-only behavior such as
`1A0..1A5`. Reusing ordinary semantics for these without source proof is invalid.
Highest offline frontier counts are166(145), D0(139), 058(113),164(75),094(71),
073(65), D1/059/1A0(57 each). Offline gates can conservatively expose paths that
a specific actor would skip; runtime reachability remains unproven.

Opcode164 was the first small concrete cut: source694390 sets a payload-selected
bit in the distinct bank4BAA30 and returns0; it calls no external provider. This
bank gates real scene-record eligibility and was absent from FlagStateSnapshot.
The existing ownership bank4BAA50 is different. Adjacent165 clears that bit and
notifies matching scene records; implementing164 alone does not close165 or the
later EVB frontiers. A bounded typed native owner must not silently reproduce
the original unbounded aliasing beyond its admitted bit-bank extent.

The [implemented164 follow-up](SCENE_RECORD_ELIGIBILITY.md) now supplies that
canonical bank and whole-program admission/dispatch. Its complete native Program
probe checks all171 owned banks and corrects an important distinction from the
prefix model: four EVBs advance beyond164; r041's full closure encounters156
while scanning a conditional first. Both compiler full admission counts are
28ordinary/23offline before and after this cut. The table above is specifically
the earlier executed-prefix model, not a claim about the complete closure's
first refusal. Actual native gameplay callers remain uninstalled.

## Explicit exclusions and evidence limits

The later [166 command/queue qualification](SCENE_RECORD_PARAMETERS.md) replaces
the initial coverage frontier for implemented `73`, `164`, `165` and `166`.
Complete native Program admission now checks all171 owned banks and admits
31ordinary/26offline, versus28/23 at baseline42b792a2. The five EVBs still
refuse later source-owned semantics: ordinary170/156/150 and offline1A1/156.
These are complete-import refusals rather than a claim that each command runs
on every session. Canonical Update message-sink adoption now exists for166;
concrete native room/session bootstrap and remaining gameplay services remain
the integration boundary described above.
The subsequent [150/1A1 cut](ACTOR_SCRIPT_ROOM_AND_AI.md) admits both room
predicate bindings and the real offline AI profile owner. Coverage becomes
360/333 while full-bank admission stays31/26. Current five-EVB import
frontiers are ordinary170/156/108/D0 and offline1A5/156; all remain required
closure work before a complete scenario bootstrap can be claimed.

The native asset/primary initialization/cache, temporary primary/NPC/object
ownership, typed tracks, object motion-bank loading and new _H.BIN resource
lookup already exist and should be integrated, not reimplemented. Outstanding
pose dynamics is being closed separately and is not counted as a session owner.

Unknown whole-file binary regions, debug-only calls and unsupported original
table entries with no owned-prefix evidence are not automatically required
work. The35/62 sets above are concrete content frontiers; their remaining suffixes
can reveal more work after each cut. No claim of exhaustive runtime coverage is
made. Stage 5 renderer replacement and Stage 6 compatibility deletion remain
separate, but Stage 4 completion requires actual native gameplay callers and
semantic save ownership, not an interpreter/register/RAM engine with native
function names.
