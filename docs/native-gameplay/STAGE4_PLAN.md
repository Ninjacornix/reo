# Stage 4: native gameplay and scheduling

Status, 2026-11-10: implementation started; **Stage 4 is incomplete**. The user
requested the whole stage. Their latest instruction revokes the earlier
conditional sleep request: continue the work and do not put the PC to sleep.

The current resource and inventory implementation includes:

- [Native navigation inputs and queries](NAVIGATION_INPUTS.md) now supply all five
  owned SGL inputs and bounded unfiltered nearest/reverse-action queries with
  original comparisons on both compilers. Canonical variant production, mutable
  room/visit/occupancy state, dynamic conditions, route/AI consumers and game
  installation remain open.
- [World navigation and room variants](NAVIGATION_BANK.md) now bind those inputs
  through the sole Session map and ordinary script5A, own mutable occupancy and
  visits, and seal on World closure. Complete original comparisons and current
  full VM suites pass on both compilers. Dynamic conditions, routes/AI and actual
  loading/installation remain open.

- [Primary construction](RESOURCE_FACTORY.md) from actual NBD poses and ITEM
  templates through the canonical64-model owner.
- [Placed-resource collisions](RESOURCE_COLLISIONS.md) through the shared128
  scene owner and [primary placement](RESOURCE_PLACEMENT.md) through actual
  models, template offsets, session RNG and floor queries.
- [Delayed construction and callbacks](RESOURCE_DELAYED.md), including
  self-replacement, same-pass continuation and the corrected factory insertion
  end. Fresh comparisons cover multi-model list order.
- [Scenario commands](RESOURCE_SCENARIO_ACTIONS.md) bound to actual construction,
  release and deactivation owners, with failure status propagated to the VM.
- [Canonical inventory primitives](INVENTORY_PRIMARY_OWNER.md), including actual
  primary SceneOwners detach/refresh, plus [resource use and content lookup](RESOURCE_USE.md)
  through the same descriptor, actor and model owners.
- [Content replacement and model rebinding](RESOURCE_CONTENT.md), preserving
  untouched instance state and selecting work through its actual descriptor.
- [Compatibility and quantity transfer](RESOURCE_PAIRS.md), including the
  character-specific table and actual model/collision retirement on depletion.
- [Recipe primitive execution](RESOURCE_RECIPES.md), including actual content,
  model and inventory consumers, and the [main owned dispatcher](OWNED_RESOURCE_RECIPES.md)
  with its actual cooperative event consumer.
- [Cooperative event evidence](COOPERATIVE_EVENTS.md), with a bounded native
  pool bound to the actual update clock and room. The owned-recipe producer is
  bound; other event producers and statistics/save consumers remain open.
- [Completion statistics and explicit item events](COMPLETION_STATISTICS.md),
  using all five owned rule groups and the same actual event pool, and
  [automatic completion](AUTOMATIC_COMPLETION.md) through the actual native
  worker/flag/actor/action-choice owners. Other ownership writers, statistics
  counters and game caller installation remain open.
- [Scenario ownership publication](SCENARIO_OWNERSHIP_PUBLICATION.md) through
  actual flag writes and timer callbacks. The admitted local writer is native;
  other writers and actual message queue/transport consumers remain open.
- [Actor health/status messages](ACTOR_STATUS_MESSAGES.md), including actual
  Owner status clearing, phase/authority/suppression and mapped-channel behavior.
  Other message selectors, actual network consumers and game installation remain
  open.
- [Item healing/status core](RESOURCE_HEALTH_EFFECTS.md), including actual actor
  mutations, native status messages and cooperative event publication. The outer
  required UI/device/text consumers and real game callers remain open.
- [Outer item effects](RESOURCE_EFFECTS.md) through those actual healing and
  deployment consumers, including quantity/statistics ordering and real model
  retirement on depletion. Weapon depletion/cost and actual UI/transport
  consumers remain open.
- [Weapon depletion and use cost](RESOURCE_DEPLETION.md) through actual content,
  debris, equipped-resource cue and weapon refresh consumers. The
  [explicit absence/sound-queue correction](WEAPON_WMD_ABSENCE.md) additionally
  admits all eighteen audited stock selectors without WMD files, continuing
  actual sound enqueue through the canonical loader.
- [Outer owned-resource use](OWNED_RESOURCE_USE.md) through those same actual
  cost/depletion and primary/shared-secondary retirement owners. Saved flags,
  quantity rereads and retained actor/inventory references compare; actual actor
  callers and installation remain open.
- [Resource claims and ownership primitives](RESOURCE_OWNERSHIP.md) use those
  same canonical inventory, descriptor, primary/shared-secondary and factory
  owners. Owner assignment and world/owned swaps have complete original
  comparisons; pickup/peer/journal/statistics/transport callers, saved-placement
  producers, extended actors and installation remain open.
- [Actor resource operations](ACTOR_RESOURCE_OPERATIONS.md) are qualified
  through actual quantity/inventory cleanup, release and remap consumers. The
  same work corrects a duplicate native D92 notice field so equipment and item
  producers reach the canonical World publication stage. Higher-level pickup,
  peer/statistics/final delivery consumers and installation remain open.
- [Actor action messages](ACTOR_ACTION_MESSAGES.md) are qualified through
  the update Owner and canonical World notice state, including actual offline
  peer requests. The work also joins the frame and message-suppression views of
  744638. Actual queue/receiver/transport and installation remain open.
- [Interaction and inventory messages](ACTOR_INVENTORY_MESSAGES.md) add the real
  selectors4/10/12/15 through canonical request/pair/inventory state and preserve
  intentional no-message selectors0/13. All eight admitted actor branches share
  one qualified gate/dispatch; remaining selectors, actual producers, transport
  and installation remain open.
- [Actor state and periodic publication](ACTOR_STATE_MESSAGES.md) supplies
  selector2, its actual primary/substate and selected-gauge helpers, and664F60's
  clock/slot gate. The [actual behavior composition](ACTOR_ACTIVITY_PUBLICATION.md)
  now binds World/frame/behavior through the UpdateOwner's same actor identity
  and clock. BAC writers/import, other behavior frontiers, transport and
  installation remain open.
- [Gauge adjustment and threshold events](ACTOR_GAUGE_EFFECTS.md) now supply
  complete660060/667E90/668050 through the actual canonical actor and cooperative
  event pool. The BBA modifier reuses the existing model-variant view. The
  [pending-hit consumer](ACTOR_HIT_GAUGE.md) now binds that owner through actual
  World/frame/behavior and resets the canonical D28 control counter directly.
  Other hit effects, periodic progression, initialization/import and installation
  remain open.
- [Auxiliary resource lists and inventory transfer](RESOURCE_AUXILIARY_LISTS.md)
  now supply5B5F10/5B6180/5B6300 and the actual5F6800 actor caller through the
  canonical Session, descriptors, templates and real model retirement. Terminal
  and periodic-gauge callers, other list producers/consumers, semantic save/load
  and game installation remain open.
- [Terminal countdown and transition](ACTOR_TERMINAL_TIMER.md) now supplies
  complete6687A0 through actual inventory transfer, model retirement, action-pose
  capture and the native behavior stage. A native frame comparison includes later
  action7 publication and rejection. Other terminal/cap transitions, periodic
  progression, initialization/import and installation remain open.
- [Periodic gauge policy](ACTOR_PERIODIC_GAUGE.md) now supplies667420 through
  actual inventory, resource retirement, threshold/cap events, action snapshots
  and its native behavior stage. Both compiler comparisons include timer
  modifiers, callback mutation, actual models and retained failure prefixes.
  UI/recovery/off-room effects remain required consumers; their migration,
  other actions, semantic save/load and installation remain open.
- [Full actor snapshot publication](ACTOR_SNAPSHOT_MESSAGES.md) now supplies
  selector1 through canonical action/aim/resource state and the shared frame
  suppression word. Both compiler comparisons cover callback mutation and
  recursive suppression. Real field producers, remaining selectors, actual
  queue/receiver/transport and installation remain open.
- [Recovery transition and gauge caller](ACTOR_RECOVERY.md) now supplies65FCB0
  through canonical status/full-state messages, inventory/resource retirement,
  health classification, actual animation selection and channel activation. The
  gauge owner can bind it directly. Both compiler comparisons include confirmed
  absent animation banks; loaded-clip recovery, actual UI and game installation
  remain open.
- [Zero-health entry and behavior](ACTOR_ZERO_HEALTH.md) now supplies65FBA0 and
  complete6607D0 through actual inventory/model retirement, action poses and
  full-state publication. The behavior adapter uses that same status core with
  real native effects. Both compiler comparisons include retained delivery
  failures and later action7 publication. Other actions, initialization, actual
  UI/transport, semantic saves and installation remain open.
- [Alignment-target publication](ACTOR_ALIGNMENT_MESSAGES.md) now supplies
  selector6 through a canonical optional target, independently of current pose
  and gauge state. Both compiler comparisons cover raw values, mapping and
  callback mutation. Real target producers, alignment movement, remaining
  selectors, transport and game installation remain open.
- [Contact alignment preparation](ACTOR_CONTACT_ALIGNMENT.md) now supplies
  complete666F50 through canonical contact geometry and the same optional
  target. Native heading math compares against the complete original atan/
  quadrant/turn and separate sine/cosine chain on both compilers. The actual
  UpdateOwner prepares and publishes the result. Other target producers,
  alignment motion, remaining messages, transport and installation remain open.
- [Contact snapshots](ACTOR_CONTACT_SNAPSHOTS.md) now supply selector5 through
  the canonical hit/collision state, finite position conversion and shared
  suppression. Native entity identities replace the embedded guest pointer.
  Both compiler comparisons cover mapped callback mutation and recursive sends;
  messages3/8/9/11, actual consumers/transport and installation remain open.
- [Room-object messages](ACTOR_ROOM_OBJECT_MESSAGES.md) now supply selector9
  through the canonical imported32-record owner shared with geometry and
  scenario commands. Both compiler comparisons cover signed coordinates,
  initialized inactive records and owner replacement during lookup. Incoming
  application, messages3/8/11, transport and installation remain open.
- [Native reception and bounded queue](ACTOR_RECEPTION_AND_QUEUE.md) now apply
  branches4/6/9/10/12/14/15 through actual actor/inventory/room-object state,
  shared pose cleanup and real equipment/resource/model reconciliation. Both
  compiler comparisons include actual UpdateOwner-to-queue-to-receiver delivery,
  retained failures and model exhaustion. External transport, remaining message/
  action/AI branches, semantic saves and installation remain open.
- [Auxiliary actor ownership](AUXILIARY_ACTOR_POOL.md) now supplies the distinct
  ten-actor pool, four attachment reservations and filtered/unfiltered identifier
  lookup in the canonical World. Both compiler comparisons cover reuse/order,
  retirement and coexistence with the fifty-model pool. Actual auxiliary actor
  construction, callbacks/AI/movement, peer binding and installation remain open.
- [Paired actor requests](ACTOR_PEER_MESSAGES.md) now bind selector8 and its
  receiver to that same primary/auxiliary ownership, using portable logical
  references and the existing hit-state byte. Both compiler comparisons include
  actual hit cleanup, missing-target prefixes and queue delivery across Worlds.
  Higher producers, senders3/11, remaining consumers/transport and installation
  remain open.
- [Speech-state messages and peer-map presence](ACTOR_SPEECH_MESSAGES.md) now
  bind selector11 and its receiver to canonical SPK state, actual selected gauge
  and a World-bound inventory-map cache. Partial off-room receipts preserve
  unknown state. Higher speech/text/UI consumers, sender3, other incoming
  branches, external transport and installation remain open.
- [Semantic interaction requests](ACTOR_INTERACTION_REQUESTS.md) now bind
  outgoing/incoming selector3 through the same canonical hit pending byte and
  model reference, preserving the typed anchor/orientation/distance/endpoint.
  All16 outgoing branches have native policy within their capability profiles;
  real producers/consumption, remaining incoming/action/AI/VM branches,
  external transport, semantic saves and game installation remain open.
- [Interaction state selection](ACTOR_INTERACTION_TRANSITIONS.md) now consumes
  the canonical request through64EF10's admitted table branch and the actual
  UpdateOwner, including queued delivery across Worlds. Pending consumption on
  rejection is preserved. The room/network-dependent branch, actual primary
  frame callers and remaining Stage4 consumers/installation remain open.
- [Room control and shared state](ACTOR_ROOM_CONTROL.md) now join actor hold,
  typed room-release publication and the actual outer exit-request consumer.
  Script/control pending bytes reuse the hit owner's sameBD0/AD4 fields,
  correcting earlier duplicate storage. Both compiler VM/hit/scheduler
  compositions qualify these boundaries. Offline off-room reconstruction,
  membership application/transport and remaining Stage4 installation remain open.
- [Actor fades and offline resume](ACTOR_COLOR_FADES.md) now own the actual
  primary color state and World finish-stage consumer, including integer-step
  fades, expiry/wrap behavior and status-rejected offline resume. Successful
  offline scene/navigation reconstruction, remaining higher consumers,
  renderer submission and game installation remain open.
- [Resource deployment](RESOURCE_DEPLOYMENT.md) through actual content, model,
  visual, floor and update owners, including repeated-placement retention and
  the eleven-instance limit. Position messages share canonical publication;
  actual transport and game installation remain open.
- [Direct item consumption and visibility](RESOURCE_CONSUMPTION.md), using the
  actual inventory/model lifecycle and completion-event consumers, and
  [inventory callers/message frontend](RESOURCE_INVENTORY_CALLERS.md) over the
  same owners. Health/status effects, actual transport and game installation
  remain open.

Those components pass both compiler comparisons and parent checks. The
[weapon resource owner](WEAPON_RESOURCE_OWNER.md) also passes both compiler
comparisons with actual ROM/SND assets and background decode/PCM checks.
[Equipment attachment construction](EQUIPMENT_ATTACHMENTS.md) also passes with
actual model/secondary release, canonical weapon refresh and natural full-pool
side effects. [Primary equipment selection](EQUIPMENT_SELECTION.md) also compares
through actual attachment construction and signed action publication, including
full model and sound capacity. Equipment use/recipe/transfer, extended actors, actual
installation and game acceptance remain open; the stage is still incomplete.
The [inventory owner correction](INVENTORY_OWNER_TAG.md) preserves the modal
owner byte rather than collapsing player identities to a boolean. Current
behavior comparisons cover all256 values; the actual inventory UI remains open.
The [resource debris lifetime](RESOURCE_DEBRIS.md) now uses the same168-work
owner, copied native model poses and the actual current resource-factory floor
lease. Paired checks cover physics, fade, retirement, full pools and invalidated
owners. Weapon depletion/cost composition and game installation remain open.
The [resource companions](RESOURCE_COMPANIONS.md) now implement all six bound
factory routes through the actual shared visual/child, model, audio and timed
lighting owners. Both compiler comparisons include full construction, material
fading, action gates and capacity. Unbound or foreign owners still refuse.
Ordinary room-lighting script commands and all166 LIG inputs already have a
native owner. [Temporary-light access](LIGHTING_CAPABILITIES.md) now reuses that
same owner. The [timed resource light](TIMED_LIGHTS.md) now uses that owner and
the actual scheduler and canonical actor floor/material tag. Actual game caller
installation remains open; rendering submission belongs to Stage5.

The [modernization direction](../NATIVE_MODERNIZATION_DIRECTION.md) is
authoritative. Stage 3 closed on source-identified V38; its media/resource owners
are reused. Their temporary guest consumers do not qualify as migrated gameplay.
File #1 US is the selected edition; File #2 requires a separate validation.

| Boundary | Required native result | Current implementation/integration state |
| --- | --- | --- |
| Actor/session ownership | Native entities, player/AI ownership, state transitions, actions, movement, health/status, inventory, spawning and retirement. | Canonical native primary world now owns entity lifetimes and composes native input, behavior orchestration, health/status and pending hits. Shared RNG/options and action snapshots use one session. Individual action/surface/pose providers, inventory, game installation and enemy/auxiliary families remain open. |
| Scenario execution | Native room/scenario flags, event commands and the game's authored script interpreter; preserve all required stock opcodes and event-task behavior. | Native canonical flag banks, offline actor-delta coordinator and partial interpreter/resource lifecycle compare on both compilers. Ordinary/offline tables remain distinct; unsupported required opcodes/providers prevent installation. |
| Collision | Typed room geometry/proxies, broad/narrow queries, floor/contact resolution and actor interaction. | Native room geometry, proxy lifetime, body solver, primary post-move, ordered secondary floor pass and canonical body-queue consumer compare or pass scoped integration checks on both compilers. Full model/pose import, attack delivery and game installation remain gates. |
| Scheduling/timers | Native owner ordering, task lifetime and game clocks at original speed; preserve pause, mutation and same-pass callback rules. | Native worker and outer phase owners compose World, flags, script channels, timers, tasks and gated clock commit. Event selection and status timing share canonical session/clock state. Task factories/payloads, remaining worker/UI/audio/scene effects and game installation remain open. |
| Save/load | Native session snapshots, original save import/codec, durable file ownership and load/resume transitions. | Qualified complete native snapshot/codec and nine-entry guarded adapter, with actual SDK object checks. Temporary legacy state projection remains explicit; live save/reload, durable native ownership and semantic world snapshots remain gates. |
| Input, networking and media consumers | Native input/action frames, world/authority events and direct native resource/audio/movie interfaces. | Qualified independent actor/menu edges, remapping and repeat core. Actual input/network/media callers and platform sampling still require migration. |
| Integration/validation | A coherent native gameplay candidate, representative scenarios/rooms, controls, save/reload, pause/resume, co-op and joined shutdown. | V39 exercises all nine guarded save/session hooks across eight successful background cases, including save/load, corrupt-save dialogs and gameplay options with resumed movement. New native World/Update/scenario components are not yet installed in the game. This is not a coherent native gameplay candidate. |

The [shared scenario-control/collision-proxy pool](SCENARIO_SHARED_PROXY_POOL.md)
is an explicit installation gate: the original 128 records form one identity,
capacity, order and retirement owner. That [shared native owner](SCENARIO_SHARED_PROXY_OWNER.md)
and the [bounded room importer](SCENARIO_ROOM_SCENE_IMPORT.md) now have original
comparisons. The importer admits163 of166 owned rooms under controlled external
poses; three authoredFF rooms remain an explicit modernization/acceptance gate.
Their counter/pointer aliases must not become a native guest-memory model.
The [explicit authored NoModel repair](SCENARIO_AUTHORED_NO_MODEL_REPAIR.md)
admits all166 controlled room inputs when opted in, with measured source
deviations and lease revocation checks. It stays disabled by default and still
requires actual affected-room acceptance and the remaining matrix consumers.
Full room model/resource construction and actual game installation remain open.

Completion requires native ownership and migrated real consumers across every
row, with source/build identities, behavioral comparisons and game acceptance.
An isolated module, hook into a native function, mirrored guest layout, or
generated-body count alone does not close this stage. Callback/provider seams
must identify their remaining owners and be removed as those callers migrate.

The current periodic-effect checkpoint supplies the actual native resource,
material, pose, camera-offset and visual lifetime consumer behind opcode131,
with both compiler comparisons passing. Its [visual contract](PERIODIC_VISUALS.md)
corrects the earlier scalar track field labels; the [scenario command](SCENARIO_PERIODIC_EFFECTS.md)
uses the canonical scheduler/flags/RNG with full ownership checks. These are
qualified components. The game's installed gameplay still remains the V39
guarded save/session checkpoint, with the new World/scenario owners uninstalled.

Further qualified components now include [matrix curve playback](SCENARIO_MATRIX_PLAYBACK.md),
[actor motion selection/playback](ANIMATION_PLAYBACK.md), [resource attachments](ANIMATION_RESOURCE_ATTACHMENTS.md),
the [single World-owned linked model pool](ANIMATION_LINKED_MODELS.md), and
[active constrained attachment composition](ANIMATION_CONSTRAINED_ATTACHMENTS.md).
The [ground fixture correction](ANIMATION_GROUND_FIELD_AUDIT.md) supersedes an
earlier coverage claim; it did not require a production solver change.
Contact effects now use the corrected mask/variant contract and checked canonical
RNG binding, with a generation-checked World/model/room interface. The
[shared effect work and fog owner](EFFECT_WORK_AND_FOG.md) supplies actual general
visual consumers and the fog companion through the same168/256 domains.
These do not close actual animation-event, resource-creation, scene/audio/input,
network, save-owner, stock-script and game-acceptance gates.

Further component checkpoints include [frame crossings and caller timing](ANIMATION_FRAME_EVENTS.md),
[player event schedules](ANIMATION_PLAYER_EVENTS.md), [reached event primitives](ANIMATION_EVENT_PRIMITIVES.md),
[native bank audio routing](AUDIO.md), and [shared water-surface effect work](EFFECT_SURFACE_WORK.md).
The [explicit floor-type correction](FLOOR_EXPLICIT_SURFACE_TYPES.md) restores
specific high-bit surface queries while preserving generic floor filtering.
These have paired source comparisons; they do not establish a fully migrated
scene/resource/input/network/save owner or native game acceptance.
The [A8 scenario effect command](SCENARIO_SURFACE_EFFECTS.md) additionally
compares the current World/scenario/shared effect owners together without
historical source pins. This closes that bounded composition check, not game
installation or the remaining script families.
The [actor/resource animation audio frontends](ANIMATION_AUDIO_FRONTENDS.md)
now supply real canonical bank consumers for their qualified routes, including
exact PCM comparison. The [surface audio route](ANIMATION_SURFACE_AUDIO.md)
also reuses canonical room regions and adds bounded footwear profiles.
The [node/scenario position routes](ANIMATION_NODE_POSITION_AUDIO.md) now also
use canonical scene/model/session state and the actual bank mixer. Actual room
bank/model assignment and the remaining event/resource consumers remain open.
The [scene matrix bank consumer](SCENE_BANK_AUDIO.md) also connects real native
channel playback to the same bank mixer with complete source consumer checks.
The [bounded named bank loader](NAMED_BANK_LOADING.md) now supplies actual
archive reads and off-thread bank preparation for direct SND loads. Combined
enemy/staged banks and real game caller installation remain open.
The [weapon program selector and scalar sampler](WEAPON_PROGRAMS.md) now use
actual owned WMD data and the existing native actor/resource owners. Resource
visual callbacks and loading on weapon changes remain separate work.
The distinct [64-primary-resource model owner](RESOURCE_MODELS.md) now also
preserves allocation, retirement and mutation-sensitive update ordering. Its
actual visual callbacks and resource factory/release composition remain open.

The [resource frame consumers](RESOURCE_FRAMES.md) now supply canonical primary
visibility/retirement and full admitted WMD playback through that 64-model pass.
The primary-only release composition is compared; shared secondary release,
extended owners, room pulses, required rebuild, nonattached pose updates and
the real asset/resource factory remain open. This is a component checkpoint;
the installed game is still V39 and the stage remains incomplete.
The [nonattached pose follow-up](RESOURCE_POSES.md) closes the1904A0 XZY/axis-scale
branch with full turn-domain comparisons and current weapon-frame regression.
The other resource factory and integration gates above remain open.
The [resource periodic-visual follow-up](RESOURCE_PULSES.md) also closes5925C0
through the actual existing168/256 visual owner and canonical RNG. Its complete
source comparison includes natural pool exhaustion; this emits visuals rather
than querying room regions. Secondary retirement, extended actors, required
reconstruction, construction/loading and installed gameplay remain open.
The [shared secondary retirement follow-up](RESOURCE_SECONDARY_RELEASE.md)
closes5B1850/5B1A90 through the actual64-primary and shared128 scene owners,
including self-retirement during a real model pass. Current frame, pulse,
scene-resource and full scenario regressions pass on both compilers.592770's
remaining action is conditional deactivation, not a reconstruction factory.
The [conditional deactivation follow-up](RESOURCE_DEACTIVATION.md) now closes
that592770/591BE0 branch through canonical descriptors, templates and instance
retirement. Active count is a derived table view. Extended actors, actual asset/
resource construction and installed native gameplay acceptance remain open.
The [descriptor allocation follow-up](RESOURCE_DESCRIPTOR_ALLOCATION.md)
closes591AE0/5B42B0 in the canonical table and template owners, with all five
owned item-template sections and the complete signed selector domain compared.
The allocator preserves reserved slot0 and the255-active gate. This supplies
descriptor creation; actual instance/resource factories remain open.
The [static resource asset follow-up](RESOURCE_STATIC_ASSETS.md) imports actual
owned NBD forests into immutable primary part poses, with full signed lookup
comparisons. This removes the need for controlled matrices on admitted roots
when construction adopts it. Two larger-part roots remain explicit unavailable
cells under the current six-part primary contract; the factory is still open.
The [model slot-reuse follow-up](RESOURCE_MODEL_REUSE.md) removes the earlier
unadmitted-reuse gate for valid construction callbacks. Traversal follows the
new occupant's continuation while old model capabilities remain retired.
Actual factory and delayed callback composition remain open.
The [resource correction-matrix fix](RESOURCE_CORRECTION_MATRIX.md) joins the
weapon part5 and attachment correction views to one actual matrix. Current
frame and attachment regressions pass; this fixes native composition before
installation and is not a measured cause of the historical slowdown.

Ordinary game-script bytecode and asset encodings may remain. The new gameplay
core must not execute MIPS, contain a simulated register file or depend on a
guest-addressed RAM model. Renderer/model submission remains an explicit Stage 5
interface; final compatibility/build dependency deletion belongs to Stage 6.

Preserve rules, content, original game speed, saves and co-op. Native state and
ownership can modernize obsolete allocation/scheduling internals; do not turn
unknown original behavior into a guessed successful implementation. Record
unsupported profiles and missing evidence explicitly.
