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

Completion requires native ownership and migrated real consumers across every
row, with source/build identities, behavioral comparisons and game acceptance.
An isolated module, hook into a native function, mirrored guest layout, or
generated-body count alone does not close this stage. Callback/provider seams
must identify their remaining owners and be removed as those callers migrate.

Ordinary game-script bytecode and asset encodings may remain. The new gameplay
core must not execute MIPS, contain a simulated register file or depend on a
guest-addressed RAM model. Renderer/model submission remains an explicit Stage 5
interface; final compatibility/build dependency deletion belongs to Stage 6.

Preserve rules, content, original game speed, saves and co-op. Native state and
ownership can modernize obsolete allocation/scheduling internals; do not turn
unknown original behavior into a guessed successful implementation. Record
unsupported profiles and missing evidence explicitly.
