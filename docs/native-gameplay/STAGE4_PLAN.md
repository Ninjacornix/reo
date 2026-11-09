# Stage 4: native gameplay and scheduling

Status, 2026-11-09: implementation started; **Stage 4 is incomplete**. The user
requested the whole stage and explicitly revoked the earlier conditional
PC-sleep action for this work. Do not request sleep after this stage.

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

Ordinary game-script bytecode and asset encodings may remain. The new gameplay
core must not execute MIPS, contain a simulated register file or depend on a
guest-addressed RAM model. Renderer/model submission remains an explicit Stage 5
interface; final compatibility/build dependency deletion belongs to Stage 6.

Preserve rules, content, original game speed, saves and co-op. Native state and
ownership can modernize obsolete allocation/scheduling internals; do not turn
unknown original behavior into a guessed successful implementation. Record
unsupported profiles and missing evidence explicitly.
