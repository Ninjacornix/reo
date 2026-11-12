# Stage 4 integration ownership audit

Source audit, 2026-11-12, initially against `bc5d18b2`. Stage 4 remains
incomplete. This document replaces neither the component receipts nor the
end-to-end acceptance gate. No game, UI, audio device or power action was used
for this audit.

The native application owner is now implemented: `NativeSession` constructs
the canonical World/Session/Update graph, owns actual room scripts, records,
models, lighting and `RoomModels`; `SessionRooms` and `SessionStartup` borrow
that same graph. This is a concrete bounded application with owned
input tests. The running game has not selected it. `recomp/reo_bootstrap.cpp`
still installs the guest-backed save adapter under
`REO_BUILD_NATIVE_GAMEPLAY_SAVE` / `REO_NATIVE_GAMEPLAY_SAVE` before original
execution; that adapter does not install native World gameplay. Full native
frame behavior/physics and the platform, transport and semantic-save hosts
remain acceptance boundaries.

## Concrete ownership and closure matrix

| Required cut | Already implemented, to reuse | Missing production ownership / evidence |
|---|---|---|
| Application/session entry | `NativeSession` owns canonical World, Session, Update, archive, script providers, reception, lighting and retained room graph; `SessionStartup` borrows it | Running-game selection of this owner, source-backed launch configuration/placement and complete shutdown across the remaining hosts. |
| Scenario/room preparation | Actual owned `r0417300` room installation and script stepping; real `_H.BIN` ordinal reads; retained room generations and canonical object publication/reception; D1 kind6 owns the actual countdown event in Update; EE reads canonical optional launch difficulty;108 uses the canonical cold InventoryUi owner shared with recovery;64 writes existing model classes through the signed population loop;63 nonzero produces the canonical request gate | Complete ordinary scenario EVB admission. Current frontiers include151/D0/153; offline1A8 remains distinct. All five EVBs still encounter unsupported semantics. The current opcode mask leaves65 ordinary instructions using9 opcodes; one additional zero63 payload branch remains unimplemented, giving66 known ordinary records across4,837 authored role0 records. |
| Primary actor/model startup | `SessionStartup`, `PrimaryActorModels::start_roster`, real actor/model/motion assets and construction/restore owners; actual actor voice and dialogue owners | Compose remaining startup effects and initial motion capabilities against the application; establish authored launch-room/roster/placement producers, rather than infer them from the controlled roster-kind fixture. |
| Shared room records/models | Actual common Records identity, `RoomSceneOwner`, `RoomModels` persistent saved bank and static NBD poses, `SceneModelBindings`, complete object `Scene` construction/retirement | Qualify broader owned physical rooms through full script admission and actual gameplay scheduling. Unavailable loaded model poses/parts and unsupported retirement bindings still refuse. |
| Ordinary update | `Owner::advance` owns pause/transition gates, worker ordering, script/task/timer ordering and clock commit | Concrete terminal `PhaseServices` implementation. Existing CollisionWorkers, LinkedModelWorkers and NpcActorWorkers are decorators that forward unowned work. |
| Primary behavior and actions | `BehaviorFrameServices`, `MotionFrameServices`, `MotionTransformFrameServices`, `GridSurfaceOrientation`, status/hit/gauge/recovery, inventory/resource primitives | Concrete terminal World::Services and BehaviorServices implementations; actual action dispatch and control/cooperation/authority consumers. There is no production implementation of BehaviorServices::dispatch. Missing actions cannot be successful no-ops. |
| Collision/contact gameplay | `SessionRooms` is the real retained RoomResources provider; actual contact Invocation, pose projection, collision/contact/effect owners and concrete workers exist | Real CollisionParticipants and terminal physics composition, complete producer/consumer scheduling and owned frame acceptance. Renderer submission remains the Stage5 boundary. |
| Cinematic lifecycle | `CutscenePlayback` owns actual controller policy, voice preparation, camera/projection/display/view/descriptor consumers; `CutsceneSceneActors` owns real actor/object composition | Adopt one application lifecycle across entry, model/motion handoff, remaining light/media consumers and restoration into the same ordinary room owners. Missing owned assets remain explicit. |
| Platform input | Native ControllerFrame, remapping, edge/repeat/menu routing and World controller spans | Platform sampler feeding normalized frames, focus/disconnect policy and frame ownership. Existing pad/RAM callers have not adopted this path. |
| Transport | Typed `gameplay_update::Reception`, actor-message queues, cooperative events and control payload owners | Protocol codec and authority adapter into canonical World/Update with generation-safe references, room transition/ownership callbacks and outgoing event drains. `network/native/world_sync.h` still takes RAM, R5900Context and PS2Runtime and is not this adapter. |
| Native media calls | `gameplay_audio::Owner`, SceneBankAudio, StreamChannels/StreamInstances and retained stream catalog; Stage 3 owners | Session must own direct bank/stream/movie services, real audio service tick, cue-to-scene completion/pause/end coupling, room audio callbacks and joined retirement. Update::state.audio_tick is intentionally optional and must not be a simulated frame counter. |
| Save/resume | Legacy Container/codec, native Options/Random, typed primary-start decoder and saved initialization | Semantic native session snapshot including World state, descriptor/flag/route/task/script continuation identities, durable host file ownership and resume transaction. `gameplay_save::LiveState` still consists mainly of opaque legacy section byte arrays; the nine-entry adapter explicitly projects guest RAM. |
| Acceptance/build | Dual-compiler component oracles and native CMake target graph | Candidate linking and selecting the native game owner; owned launch/gameplay/room changes/cinematics/pause/exit/save-resume/error-recovery runs, input/transport/media acceptance, final source/build identity and joined shutdown. |

## Initial provider audit and checkpoint history

The B99/B9B integration audit found two distinct existing owners: B99 is
`Actor::motion_style`, already established by actual primary initialization
and motion-resource selection; B9B is inherited `HealthState::class_marker`,
used by health classification and hit processing. Dialogue prefix consumers
must use `motion_style`. Reusing the health marker for the dialogue fixture
would couple separately qualified source offsets and is not an admissible
canonical-state mapping.

The following detailed inventory records the original `bc5d18b2` audit and
subsequent closure checkpoints. The matrix above is the current integration
status; historical missing-provider statements below are superseded by the
later linked implementations and receipts.

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
The [156/1A5 cut](ACTOR_SCRIPT_PREDICATES_AND_COUNTER.md) subsequently qualifies
all actor predicate branches and the real fixed-eight AI counter command.
Coverage reaches361/335; admission remains31/26. All five ordinary EVB
frontiers are now170/D0/108, and all five offline frontiers are1A8. These
remain concrete unsupported authored-content uses rather than evidence of
complete scenario execution.

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

## Concrete application composition after the 156/1A5 checkpoint

A current native `Program` probe reads and hash-checks all 171 owned archive
members, constructs both dispatch profiles, and asks their actual provider
admission predicates. Its read-only evidence is
`build-native-sjuni/native-session-provider-probe-v1/receipt.json` and
`requirements.json`. The uniquely smallest admitted room bank is still
`r0417300.rdt`, in both profiles: sequences, lighting, scene channels, scene
controls, World, scenario identity and canonical flags. Its 16-block closure
does not request stream, selected-actor, model, periodic or surface providers.
This is complete script admission evidence, not geometry, actor construction,
whole-scenario bootstrap or frame-execution evidence.

The smallest concrete application owner should retain `ScenarioArchive`, a
shared `gameplay_world::Session`, `World`, `gameplay_update::Owner`,
`SequenceControl`, `Lighting`, `SceneChannels` and `SceneControls`. Canonical
flags must come from `Owner::flags()` rather than a second bank. Scenario is
the existing `Session::scenario` optional mirrored by `World::scenario`; it is
not a missing service class. Retain the room-bank backing and bind it using
`Owner::load_room_scripts(archive, RoomId{41,73,0}, 1)`, which routes to existing
`bind_room_scripts`. The ordinary second room entry uses channel5; offline
room channels1..3 use existing coordinator rules. The actual native provider
map points at these retained owners. Script stepping must not claim a full
simulation tick or advance the simulation clock.

The public Update constructor is
`Owner(World&, FlagNotifications&, shared_ptr<const RuleBook>, GameplayMessageSink*, const room_objects::Owner*)`.
Its full frame entry points are
`run_workers(Services&, world::Services&, Providers, script_budget, task_budget)`
and `advance(PhaseServices&, world::Services&, Providers, script_budget, task_budget)`.
No terminal production `BehaviorServices::dispatch` implementation exists:
current behavior/motion classes decorate another service. Supplying empty
workers or successful no-op physics would falsify this boundary. A concrete
application owner can install and step the actual admitted room script now,
while full-frame entry explicitly refuses until real terminal behavior,
physics, required workers, room geometry and actor assets are bound.

The native host-input source already exists at `runtime/input/input.h`:
`reo::Input::get_pad(port)` exposes typed `DualShock2State` after normal host
polling. A future native adapter should feed `ControllerFrame` through the
canonical native controller routing. Exact axis/pressure normalization still
needs source comparison; the existing production RAM packet writers are not
an acceptable NativeSession implementation.

The [concrete NativeSession implementation](NATIVE_SESSION_APPLICATION.md) now
owns this application lifetime and exercises the actual owned room scripts,
section10 records/helpers, section11Lighting and B5 terminal matrix consumer.
It adds the real scene/model/matrix ownership that the read-only Program probe
could not identify. Full frame services, actual actor startup and installed game
selection remain explicit open boundaries; cold empty controls/lighting are not
used as a successful room bootstrap.

The [opcode170 cut](SCRIPT_RESOURCE_PARAMETERS.md) now passes paired complete
original dispatcher/native owner qualification and current17-parent cohorts.
At that checkpoint all171-bank admission remains31/26 and r001 advances to174
at block2+2508. The subsequent [174 cut](SCRIPT_RESOURCE_ACTIVATION.md) uses
the actual delayed factory and raises admission to34ordinary/27offline banks,
with nineteen current parents passing on both compilers. Scenario r001 now
advances toD1 at block2+3420; no scenario EVB is fully admitted.
The next scenario-bank cuts remain authored uses: ordinary `D1`, `D0`, `108`
and offline `1A8`. For D0, the owned r035 kind11 offline callback is5B8880,
which calls the already native contact-visual impact path5DD6F0; the missing
layer is a concrete typed scenario-event task factory/state owner and the
other required callback families. Opcode108 also reaches inventory UI close,
whose complete application owner is absent. These are subsequent work items,
not reasons to defer creating the concrete application owner.

The [SessionRooms integration](SESSION_ROOM_RESOURCES.md) now closes the missing
positive `RoomResources` provider for the admitted owned r0417300 room. Its
`RoomInvocation` retains the actual NativeSession room graph and immutable
archive geometry, rejects replaced/closed identities, reads canonical matrix
gate/kind bytes and owns the source-backed Session collision mask producer.
Actual flight and contact callers consume this provider. The separate
SessionStartup owner now adopts qualified roster startup; those owners are
implemented, rather than still missing helper targets.

The next room cut is precise: `StatePublication` receives its object owner only
in the Update constructor, while scenario selection occurs later. A guarded
late binding must connect the retained canonical scenario placement owner to
publication/reception. Actual `InteractionOwner::Lifetime` and
`SceneModelBindings` already implement6AD4E0/model/proxy creation, update and
retirement; their production application composition is still required. Rooms
with current movable-object placements refuse until that composition exists.
Neither the global placement count nor an empty successful binding is a valid
substitute for the actual current instance count745D60.

The [guarded late-binding cut](SESSION_OBJECT_BINDING.md) now implements that
Update/StatePublication and NativeSession/ActorReception connection, with real
typed type9 queue composition and scope/lifetime checks. It leaves actual
object construction and the saved/current model-pose producer as the immediate
next integration boundary, rather than claiming those consumers from binding
alone.

The [room object Scene](ROOM_OBJECT_SCENE.md) now implements the complete
6AD4E0 outer owner and6AD820 grid retirement, using the actual existing
instance/proxy/model-binding graph. NativeSession retains it and preserves
all64 physical instance slots independently of room identity. The complete
original comparison exposed and corrected premature native object-center
publication during grid import. Positive-instance source comparisons pass
with explicitly supplied model-pose/remapping preconditions. Production
SessionRooms executes the real zero-current-object branch; initial saved
model-pose ownership and the ordinary static room-model asset path remain
the specific restriction on positive-instance rooms.

The [static RoomModels owner](ROOM_MODEL_ASSETS.md) now closes that producer:
actual1D2CB0 matrix/group import, one persistent saved bank, current live-binding
capture, source byte-cache semantics and loaded-part visibility are implemented
and adopted by NativeSession. The current matrix above reflects this boundary.
Full ordinary EVB admission and concrete terminal frame services are now the
next application cuts; no installed-game or full Stage4 claim follows from the
bounded room/model proof.

The [cold inventory UI owner](INVENTORY_UI.md) now supplies actual6DEC80 and
complete108/6925C0 through the cold6E1430 branch in NativeSession. Recovery uses
that same owner. Active UI phases remain explicitly unavailable. The five
ordinary frontiers are r001:64, r002:D0, r028:63, r035:D0 and r041:D0; all offline
frontiers remain1A8. The next small source-backed cut is64's physical population
loop writing the existing Actor.model_pose_class54D. Opcode63 nonzero sets a UI
request gate, while its zero branch reaches the larger resource-reset6DDD70;
those branches must retain their distinct capability requirements.

The [physical model-class command](ACTOR_MODEL_CLASSES.md) now executes64 against
the existing54D field. The owned r001 ordinary EVB advances to151 at block2+7844.
The other four ordinary frontiers and all five offline1A8 frontiers remain as
above. The application still needs a canonical resource graph: SceneResources,
templates, primary resource models/frames/factory, inventory, pose-work pool and
their actual frame-worker routing. Existing isolated native owners must be
composed with the retained SessionRooms records/floors and Update identity;
unbound terminal physics/behavior and phase operations must continue to refuse.

The [inventory request gate](INVENTORY_REQUEST_GATE.md) now closes actual63's
nonzero branch and supplies the same optional8D value borrowed by dialogue.
Owned r028 advances to153 at block2+2536. Zero63 remains a distinct required
604310/6DDD70 asset-reset operation; the frontier inventory records that authored
use separately instead of treating the opcode's positive branch as complete.

The [pose projectile/preset checkpoint](POSE_PROJECTILES.md) now supplies typed
policies for the remaining6/12/15/17/100 families and concrete room/pool/packet/
trail/preset ownership. Both compilers pass the complete source cohorts and
current contracts against all six owned effect banks. The optional special
visual/light actions and actual actor audio metadata remain reached requirements;
this checkpoint does not close the terminal frame services or native application
installation/acceptance gates in the matrix above.
