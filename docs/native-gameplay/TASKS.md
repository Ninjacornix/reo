# Native gameplay tasks, ownership and simulation clocks

Status: independent native core implemented and compared on LLVM and GCC;
production callers are not integrated. This is a Stage 4 component, not a claim
that gameplay, every task callback or the entire game now runs natively.

The library is [gameplay_tasks](../../game/native/gameplay_tasks/). It owns normal
C++ task objects, opaque lifetime handles, ordered event slots, signed countdowns
and explicit simulation-clock state. It includes no generated function API,
register context, guest memory/address model, PS2 syscall wrapper, OS worker,
render loop or host-time accumulator. The separate `game/native/tasks` serial
worker remains a media/resource OS worker; it is not this gameplay scheduler.

The [qualification](../../tools/native_reconstruction/gameplay_tasks_qualification.json)
binds complete owned instruction bodies, actual caller sites, both compiler
cohorts, source snapshots, mutation failures and the initial failed experiments.
Original instructions are verification evidence only. Neither their bounded
instruction runner nor its synthetic memory is linked into the native library.

## Two different task owners

| Original boundary | Observed contract | Native interface |
| --- | --- | --- |
| `5735A0`, `573630`, `573740`, `573890` | Initialize the 32-entry linked callback pool, allocate at either end, release/unlink, and construct the usual newest/head task. Constructors and raw allocation differ. | `Scheduler` owns up to 32 `shared_ptr<Task>` objects and returns domain/serial-checked `Handle`s. No physical record address, stride or original slot byte is exposed. |
| `573840` | Traverse tail through the predecessor, invoking primary callbacks regardless of active flags. Read the predecessor **after** callback return. | `Scheduler::run(Pass::update)`, oldest first, with live links. New head children can execute in this pass; a new tail waits for the next pass. |
| `5738F0` | Same traversal, but secondary callback requires `(signed active byte & signed mask byte) != 0` and a nonnull secondary callback. | Separate presentation pass with explicit active flags, presentation mask and callback admission. Bytewise bit intersection preserves the boolean result, including high-bit values. |
| `5B91B0`, `5B92B0`, `5B93B0` | A different family: ten fixed event slots in bank 0; banks 1 and 2 additionally run only when `1B02D0()==1`. Scan slots ascending, invoking only active records. Installation is distinct from clearing a record and matching render registration. | `EventTasks` owns three ordered banks of ten native `EventTask` objects. Each callback receives explicit bank/slot and native `OwnerSelection` context. |

Event-bank traversal preserves an easy-to-miss detail: bank 0 sees the incoming
selected actor; the original does not first force it to zero. In owner-bank mode,
selection becomes 1 before bank 1 and 2 before bank 2, then returns to 0. In
shared-bank mode it is left as the callbacks/caller supplied it. A callback's
change to native `OwnerSelection` remains visible to subsequent callbacks in that
bank. A newly installed later slot runs this pass; an earlier slot waits.

Both owners are single simulation-thread objects. Reentrant traversal/reset is
refused. Callbacks can retire themselves or other tasks; storage remains alive
until an executing callback returns. A recycled slot cannot validate an old or
foreign handle. Bulk retirement completes state removal before destroying task
owners and refuses destructor-driven creation during that fence.

The linked owner has a bounded traversal budget and reports an incomplete pass
instead of hanging on endlessly generated work. The fixed event scan is naturally
bounded to ten or thirty visits. These native admission/lifetime safeguards are
deliberate design choices; malformed old records, raw-pointer reuse aliases,
double frees and missing callbacks are not reconstructed as a new native ABI.
The original active-task ordering and admitted allocation failure remain relevant.

Native event installation refuses an occupied slot. Its eventual factory must
make retirement/replacement explicit and reconstruct any state intentionally
retained by a legacy caller; the eight direct installation sites have not all
been migrated or proved to start from empty slots. The fixtures admit empty-slot
construction and explicit clear/reinstall. This is an integration precondition,
not permission to switch those legacy callers to the native owner unchanged.

## Timers and clock units are separate contracts

`FlagTimers` reconstructs the eight script flag timers at `68C7B0` and arming
opcode 45 at `68E1F0`. Each tick visits slots 0 through 7. Only a signed-positive
count decrements; a transition to zero synchronously emits its typed expiry
before the next slot is examined. Zero/negative values remain unchanged.
Synchronous consumption matters: rearming a later timer can affect this same
tick, while rearming an already visited timer waits for the next invocation.

The script decoder narrows duration to a signed low halfword. Its encoded target
uses the low halfword ID, ORs `8000` if payload word 0 is nonzero, then selects
session-owner-zero versus scenario scope from that bit, with a low-15-bit ID.
The native API carries those choices as `FlagTarget`, without bit-packed runtime
storage. A scenario expiry's consumer must set the flag **and send its selected-
actor notification**; session-owner-zero expiry uses the session setter without
that scenario notification. The core emits the event; it does not invent a
network/actor notification implementation.

`SimulationClock` reconstructs the normal admitted `5FEE80` play-clock step in
sixtieth units: mode byte zero contributes one, nonzero contributes two. Valid
time carries through seconds/minutes and wraps after 100 hours. Its independent
32-bit update counter advances once per committed gameplay update. Explicit
counter adjustments remain separate: `5FEA30` also contains +150/+360 branches,
so that counter is not a universal count of ordinary actor updates. Restoring
invalid, non-normalized native play time is refused rather than emulating
corrupted byte overflow behavior.

These APIs take no elapsed host milliseconds. Neither a task pass, actor callback,
render frame nor a media worker visit implicitly advances play time. The actual
simulation owner decides when one original gameplay update is admitted. This
does not select or unlock a higher frame rate.

Other countdowns are not interchangeable with script flag timers. Full owned
`5A1EF0` decrements a signed counter and retries/resets only after a negative
result. The o9 single-actor policy predicate `8217B0`, when mask `200000` is
enabled, decrements a positive counter but matches an **already-zero** value.
Those bodies are separately word-verified; their task state machines remain
consumer work. The o9 `+FFE/+FFF` nested states are actor behavior continuations,
not this linked task pool or a new host thread.

## Actual ordering and integration cut

`5FE440` selects active scenario phase `5FEA30`. Its UI/control branches determine
whether the gameplay worker chain is called. Within `5FED00`, the order begins:

`6816F0 → 371A90 → 68C8D0 → read F8 gate`.

`68C8D0` normally runs flag timers, script channel 0, `5D7ED0`, script channel 1,
then `581EE0`. Its distinct limit branch skips that sequence when the signed
room counter is at least `83D60` and the quit gate is zero. Thus timers/scripts
can run before the later F8 actor-work gate. A single blanket pause rule would
change behavior. On the full worker path, fixed event tasks `5B91B0` appear after
`5BE9A0` and before `5D8160`; linked primary tasks `573840` appear after `5821F0`
and before `651ED0`, followed by the separate four-record callback service.

After the worker chain returns, `5FEA30` checks F8 and transition gate E76. Only
the admitted path advances `5FEE80` and the normal update counter. Meanwhile,
resident scene service `371BA0` calls secondary tasks at `371DE4`, after `582240`.
The primary and presentation passes must therefore remain separately placed;
there is no evidence for firing both on every presentation.

The direct integration inventory verifies **227 original call sites in 181
source files** within the common/scenario o0/o2 partitions. It includes 49 calls
to the normal linked constructor, 56 releases, 103 event-record clears, eight
event installations, two primary passes and one secondary pass. This is a
bounded direct-call inventory, not a complete count of indirect callbacks or
other overlays with overlapping address ranges.

The next integration is concrete:

1. The native scenario/session owner calls the timer/script service once at the
   admitted pipeline point and commits native play time after the real gates.
   Preserve script channel order; do not count per-actor callbacks as updates.
2. Migrate task factories and their state together. Script opcodes 74, 90 and 94
   create linked work with actual typed parameters; 94 resolves scenario-specific
   callback tables before allocation. Native factories must preserve a failed
   lookup/full-pool nonblocking result. `5B7470` replaces an owned child after
   releasing it; it is not evidence for reusing the executing task's raw address.
3. Native event dispatch supplies explicit owner context, task phases, actor and
   resource handles. Clearing an event also retires its matching presentation
   registration before owner destruction; that consumer is not implemented by
   merely erasing a task from this library.
4. Room/session reset callers `5EAEB0`, `5EB8B0`, `5ED200` invalidate task handles
   through native owner teardown. Remaining direct record reads, child pose/model
   bindings, saved task state and co-op messages must move with their consumers.

The separate four large callbacks (`573D10/573D30`), actor AI task steps, actor
updates, script bytecode, collision, saves, network notifications and the render
registration path remain explicit integration dependencies. No generated entry
has been replaced or deleted, and the shared parent CMake/build preparer is
unchanged. A future adapter, if needed, belongs outside these native core files.

## Verification

Both final v6 cohorts pass **196,697 native assertions**, **154 original-word
transcript comparisons**, **109,868 executed original instructions**, and eight
detected counterfactuals. All twelve claimed original entries are asserted to
have executed. Full source-body words, including omitted zero/delay words, are
checked against owned o2 bytes; seven broader integration callers are statically
checked and are not claimed executed by the native fixture.

Tests cover same-pass head children, delayed tail insertion, predecessor/self
retirement, full pools, stale/foreign identity, callback lifetime, clear/destructor
reentry, all 65,536 signed script countdown values, synchronous timer rearm,
secondary gating, fixed owner/slot order, later-slot installation, selection
mutation, modular play-time carry and wrapping update counters. The fixture
uses declared callbacks, flag consumers, zero-fill and session-mode ports;
it does not run original actor/flag/render implementations or a game session.

Mutants detect premature predecessor capture, active-gating primary work,
wrong secondary mask, decrementing negative timers, early timer expiry,
ignoring two-unit clock mode, running owner banks in shared mode, and failing
to restore selected actor zero. Final receipts are
`build-native-sjuni/native-gameplay/tasks/{llvm,gcc}-v6/receipt.json`.

Earlier runs are retained: v1 exposed a fixture initialization omission before
compilation; v3 added a teardown reentry test that caught the native clear fence
and prompted its fix. v2/v4 passed their smaller scopes. v5 included event-bank
tests but counted loaded entries; v6 explicitly executes the normal constructor
wrapper and checks executed entry coverage. These are component results, not
game integration or performance measurements.
