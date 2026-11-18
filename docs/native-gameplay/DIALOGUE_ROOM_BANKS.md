# Dialogue room banks and application ownership

`DialoguePool::refresh_room_banks` implements the admitted complete `1D41F0`
body and its `6B7720` reset, using the existing World, Session AuxiliaryScene,
retained scenario EVB and ScenarioArchive. `DialogueBankBindings` owns five
physical actor/common cue/text pairs and the actual eight-character indirection.
The nine logical banks are derived views. Duplicate characters, independent
missing cue/text halves, physical-write-before-invalid-character refusal, and
old record/text leases retain the source ordering.

The section lookup reads **World.room (`3243DC`)**. Session.room_variant is the
distinct `3243DE` value. A row greater than the row count returns signed `-1`
without reading room state; an equal row reaches the source's `FFFFFFFF`
sentinel and is refused before an unbounded read. A signed `-1` never equals
the cached unsigned byte `255`, so that missing section resets on every call.
Cache hits do not require the later scenario or asset-loading mode capability.

Both formatting branches in this caller pass flags `0x10001` and select the
scenario catalogue. The loader uses the real H.BIN key/ordinal lookup and
retains real logical member bytes. The original comparison executes the SDK
sector-count/copy bodies against the corresponding owned padded member extent.
This is different from the cinematic DM loader's mode-zero flags `1` path.

Reset clears records, represented selection/history/cooldown roles and actual
primary speech fields. It preserves banks, shared flags/durations, text leases,
other speech roles and the section cache until the source publishes it. The
source's unused DC4/DC6 bytes and unused selection-header words have no native
consumer and are not invented as additional actor state.

`SessionDialogue` borrows one existing NativeSession and its World, Update,
InventoryUi, archive and optional initialized SessionResources. It owns the
exclusive DialoguePool, TextCache and existing inventory presentation adapter.
Voice, remaining phase services and actual menu inputs are explicit borrowed
capabilities. Its frame method installs the real sequence worker and the Update
owner advances shared durations once. Nested close/reset/frame calls refuse
while busy, and retained snapshots survive closing the application.

Bank refresh is an explicit `finish_banks(actual_scenario_evb)` entry for the
real child at `5EB720`. The complete parent `5EB6D0` also requires pending I/O
closure, stream preparation, motion defaults, script reset, room setup and
per-primary finalization. That whole finish path remains an integration
frontier. Refresh is not attached to generic room installation or the separate
`5EB520` roster startup. The scene priority/front text banks remain distinct
from these actor/common windows.

## Verification

Both GCC and LLVM passed:

- Physical publication: 3,461,739 checks, 70,217 complete original `6B7350`
  publications, 8,192 invalid-character write prefixes and 32,796 retained leases.
- Corrected room loader: 294,193 checks, 120 complete original refreshes,
  90 resets, 270 real SDK sector reads, 30 cache hits and 15 sentinel refusals.
- Dialogue continuation with independent room-global exports: 7,141,270 checks,
  4,128 complete original frames and 62 real queued speech messages.
- Current graph: 34 CTests, 55 actual-owned SessionDialogue checks and 44
  actual-owned DialogueWorkers checks per compiler.

The original-body proofs hash complete generated bodies against the owned ELF
and overlays and compile against immutable matching source/archive graphs.
Unrelated later live graph changes are recorded rather than hidden. Initial
loader v1/v2 snapshots exported room_variant as room in both sides; those are
retained diagnostic evidence and superseded by v3. The earlier core v8 evidence
omitted the independent room export; core v10 supplies it. Other retained
failures include a fixture indentation warning, mixed snapshot include roots,
and the first SessionDialogue fixture's missing script-channel setup. The final
owned fixture explicitly uses the normal coordinator and controlled script
channels with inactive actors; it does not prove active actor/physics services.

Run `qualify_dialogue_room_banks_v1.py` to revalidate and seal the recorded
evidence. No game launch, audio device, presentation renderer or full Stage4
acceptance is claimed by this checkpoint.
