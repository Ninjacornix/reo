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
| Actor/session ownership | Native entities, player/AI ownership, state transitions, actions, movement, health/status, inventory, spawning and retirement. | Eight-primary-actor update orchestration is being implemented from complete 669F30. Its behavior/input/contact/pose ports still require migration. Enemy/auxiliary actor families remain separate. |
| Scenario execution | Native room/scenario flags, event commands and the game's authored script interpreter; preserve all required stock opcodes and event-task behavior. | Inventory identifies the 432-entry original opcode table and 24 event-task kinds. No partial-opcode interpreter is admitted as the replacement. |
| Collision | Typed room geometry/proxies, broad/narrow queries, floor/contact resolution and actor interaction. | Exact query/proxy and original geometry contracts are being implemented. The complete actor/floor solver and native import/caller binding remain gates. |
| Scheduling/timers | Native owner ordering, task lifetime and game clocks at original speed; preserve pause, mutation and same-pass callback rules. | Gameplay tasks/timers are being separated from the existing OS media workers. Original callback-list and scenario timer contracts are under implementation. |
| Save/load | Native session snapshots, original save import/codec, durable file ownership and load/resume transitions. | Complete original snapshot/codec is being ported; actual UI/autosave and native world-state consumers remain to migrate. |
| Input, networking and media consumers | Native input/action frames, world/authority events and direct native resource/audio/movie interfaces. | Existing network/game/media adapters still expose guest state; those dependencies must move with their callers. |
| Integration/validation | A coherent native gameplay candidate, representative scenarios/rooms, controls, save/reload, pause/resume, co-op and joined shutdown. | Not started for Stage 4. Stage 3 game tests are regression evidence, not Stage 4 execution. |

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
