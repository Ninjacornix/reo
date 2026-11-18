# Source2: shared encoded credit, file-target actions and Window2

Status: design for review, 2026-11-06. No Source2 or Window2 implementation,
runtime integration, new instruction replay, device test or game run is claimed.
The proposed new code directory is `game/native/adxt_shared_source`. Frozen
Source1 (`adxt_refill`), Header1 and Window1 remain unchanged.

This contract follows [ADX_WINDOW_V2_CONTRACT.md](ADX_WINDOW_V2_CONTRACT.md) and
the independent [ADX_SHARED_WINDOW_ORACLE.md](ADX_SHARED_WINDOW_ORACLE.md).
The source oracle was seen before this design; a future native source freeze
must say so, rather than claim blind authoring.

## Evidence admitted for this design

The owned File1 ELF SHA256 is
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The frozen original corpus is
`build-native-sjuni/adx-shared-window-oracle-v14`:

| Artifact | SHA256 |
| --- | --- |
| `inputs.json` | `d3adee3434a56a218b6a67040ee44a2df99b1cdd813bcaf15c067d8d0adb4d46` |
| `manifest.json` | `e41b48940b06b95d5b5641160225e10b0902dd5808d9eaf1dca5b1aa0b127972` |

The manifest records 39 cases: 35 complete returned transcripts and four
explicit partial cuts. The returned direct repeat-helper probe is not a full
ready/window transaction. All original body, engine, table and FP-worker
identities remain those in that manifest. This design does not rerun or modify
the evidence.

All v14 shared-window cases use an 8192-byte encoded ring plus 36 mirror bytes.
The earlier independent Source1/refill/SJRB evidence also covers capacities
2048/4096; a Source2 implementation must qualify its new two-consumer behavior
at those geometries before claiming all three. The first shared-window parity
claim should therefore explicitly start at 8192. The unchanged real backend's
maximum read remains at most8192 bytes.

The concrete physical-end pair is decisive. At source publication the actual
`133AB8` entry observes progress sector2, target2 and accepted cumulative2048
on a two-sector file. Enabled looping runs actual `1305C0`, changes progress to0,
and the later `130800` terminal branch leaves state2. Disabled looping first
changes decoder outer `+3C` from32 to-1, then source target `+2C` to`INT32_MAX`;
progress stays2 and the later physical-end branch sets state3. Cumulative
accepted bytes stay2048 in both. This action cannot be replayed after service.

## Owners and lifetime

`SharedEncodedSource` owns exactly one actual private `sjrb::Ring`, one retained
immutable source view and one `adxt_refill::Backend`. Reusing the frozen real
`make_async_backend` retains unchanged AsyncReadOwner/SerialWorker behavior;
workers write private result buffers only. No second encoded ring, arbitrary
backing pointer, mutable Ring, `make_span`, numeric checkpoint import or provider
destination pointer is exposed.

There is one producer ledger entry and one consumer batch ledger with up to two
ordered grants. Zero-byte grants are recorded as actual Get results, not as
invented positive credits. Source service may proceed with a batch outstanding;
it cannot reset, replace or invalidate that batch. Workers never access the
ledger or loop state. Every control call, service call and batch read requires
the same external serialized control domain; the provider worker is outside it.

A `ReadBatch` retains a strong fixed `LeaseDomain` identity and actual Chunk
storage, not the whole provider/control owner. It records source epoch,
nonwrapping batch ID, grant count, order, offsets and sizes. It has a move
constructor that makes the old token inert, deleted copy operations and no
overwrite of a live token by move assignment. Destruction returns no credit,
invokes no callback, and performs no provider join. Losing it keeps the source
ledger busy; it is not permission to recover credit automatically.

The enclosing Window2/pipeline must retain the real Source control owner through
explicit provider drain and fence. A token that outlives emergency control-owner
destruction sees a closed/stale LeaseDomain and cannot call back into dead
control state; its remaining strong storage can only be dropped. This avoids a
last token drop running a provider destructor/join on an arbitrary thread.

No new original cancellation or generation-fence equivalence is claimed. Source
epochs and retained leases are newly owned safety policy.

## Proposed public data and operation surface

Names are proposed, not existing declarations. All steady-state metadata is
fixed and allocated before the first accepted operation.

```cpp
enum class BatchShape { one, two };
struct BatchRequest { BatchShape shape; int32_t first_max, second_max; };
enum class FinishKind {
    consume_single_prefix,
    restore_reverse,
    consume_first_prefix_restore_second,
    consume_second_prefix_consume_first
};
struct FinishPlan { FinishKind kind; int32_t prefix_bytes; };
struct BatchResult { Status status; ReadBatch batch; };

// ReadBatch: count(), bytes(index), offset(index), read_into(index,out,relative).
// No mutable Chunk, independent finish(index), or guessed destructor disposition.

class SharedEncodedSource {
    Snapshot snapshot() const noexcept;
    ServiceResult service() noexcept;
    BatchResult borrow_batch(BatchRequest) noexcept;
    Status finish_batch(ReadBatch&, FinishPlan) noexcept;
    Status set_paused(uint8_t) noexcept;        // Original comparison is byte==1.
    Status set_loop_enabled(bool) noexcept;    // Only the owned enable flag.
    Status request_stop() noexcept;
    Status request_close() noexcept;
    Status begin_shutdown() noexcept;
    bool finalize_shutdown_and_join() noexcept;
};
```

The constructor receives source/refill configuration, a retained immutable view,
the owned backend, a prepared prefix and an owned LoopControl domain. Preparing
a prefix uses actual Ring operations, including cursor advance; it never imports
raw Ring counts. `PreparedPrefix` includes its independent initial logical file
progress in sectors. The v14 setup executes actual source start, then sets that
progress to`seed_bytes/2048`, then target-1. Queued seed bytes do **not** increase
cumulative accepted bytes. A physical read position and queued prefix are not
interchangeable with cumulative publication.

One active batch can request one or two actual Gets. For `two`, the second Get
runs even when its actual grant is zero. Requested maxima may be greater than
capacity, including the original positive `INT32_MAX` request; bounded grants
come from the real Ring. Source1's maximum-request<=capacity consumer API cannot
substitute for that original two-Get contract. Counts are nonnegative and all
physical extents are checked before exposing read access.

`service` returns typed status and an observational transition summary. A
summary is not a deferred action callback. Read-only observations may use a
fixed event recorder; no observer can select a disposition or mutate owner state.

## Atomic preflight, exact ordered dispositions

`finish_batch` first validates the entire operation without returning any credit:

1. Live owner identity/epoch, exact outstanding batch ID, actual Ring incarnation,
   complete acquired-grant ledger, no duplicate or already-finished token, and
   the caller's externally serialized/nonreentrant scope.
2. Exact supported shape/plan and prefix extent. A two-grant plan cannot be
   applied to one grant; no plan can dispose an unrelated producer reservation.
3. Wide accounting and bounded physical/logical extents for every positive grant.
4. The full ordered sequence, including expected read position for **each** Unget,
   resulting counts, modulo positions and conservation, before the first Put.

This last check is essential: frozen `sjrb::Ring::unget` can emit a position
mismatch diagnostic and still return `completed`. That return alone is not proof
that credit or position was restored. The wrapper must check
`(read + capacity - bytes) % capacity == chunk_offset % capacity` using safe
wide arithmetic at each simulated step, then execute the actual Ring operation.
The simulation is admission only; it does not replace actual Ring byte/mirror
effects or independently observed oracle expectations.

The complete whitelist is:

| Plan | Actual ordered operations |
| --- | --- |
| Single prefix | Split grant0; Put free(prefix0); Unget data(suffix0). |
| Reverse restore | Unget data(grant1), then Unget data(grant0); for one grant, only grant0. |
| First prefix | Unget data(grant1), split grant0, Put free(prefix0), Unget data(suffix0). |
| Second prefix | Put free(grant0), split grant1, Put free(prefix1), Unget data(suffix1). |

Zero-byte Put/Unget retains the original Ring's no-effect/no-hook behavior. The
two original Gets still occurred. Every successful actual step retires only its
known ledger portion and checks the predicted postcondition. A malformed plan
returns before all disposition effects and leaves the batch usable for a valid
plan. An unexpected post-effect credit/position/hook failure marks a terminal
invariant fault and retains the remaining explicit ledger. It never retries the
whole original call, silently returns the remainder, or resets/recycles storage.

For every stable boundary, including a pending producer and both consumers:

```text
queued_data + free + held_producer + held_consumer0 + held_consumer1 = capacity
```

All terms are nonnegative bounded logical bytes. Physical 36-byte mirror
storage is not extra logical credit. Partial provider acceptance retains the
entire producer grant until completion, then publishes only its accepted prefix
and restores its suffix. Do not count only accepted sectors as held producer
credit. Ring totals retain their original uint32 wrap semantics; conservation
uses independent wide checked arithmetic, not those cumulative totals.

Ring enter/leave events inside a multi-step publication/disposition are
microstates, not stable owner boundaries: the original source reservation can
still be present after Put has changed ring counts. A fixed internal pending-step
record must distinguish completed and remaining transfers; observers must not
double-count the old full descriptor as live credit or claim a whole-plan commit
at each nested guard. No external observer may return/reuse in-transfer credit.

## Canonical shared LoopControl and the source target action

LoopControl is strongly owned typed state, not a caller pointer or function.
It is shared by Source2 and its single bound Window2. Creation issues one private
`WindowLink` capability; only the concrete Window2 implementation can write
decoder/loop transitions through it. General users can observe snapshots and
change the single runtime loop-enable flag between serialized calls. They
cannot set source progress, substitute a callback, or mutate decoder fields.

The canonical state includes current admitted header loop geometry, runtime
loop enable, decoder sample limit and two **distinct** action selectors:

- `DecoderLimitAction`: none / first snapshot / repeat / seamless. Window2 runs
  it at actual `12CFD8` before its normal input Get, with owned predictor/history,
  key, counters and PCM state.
- `FileTargetAction`: none / file loop. Source2 runs it at actual `130800`
  publication. It is independent of the decoder-limit callback phase.

`LoopControl.sample_limit` is the sole mutable decoder limit (original outer
`+3C`). Window2 reads it directly and projects it in snapshots; it must not keep
a separate mutable cached copy. Current loop start-byte geometry is canonical
too: an admitted next header updates it through the concrete header transition,
and the later target action uses the current value, not an arm-time copy.
Configured key material and first-loop history/key snapshots remain distinct.

For a verified completed accepted result, service follows this sequence:

1. Check result identity/length and all possible numeric target outcomes before
   publishing. Copy owned result bytes into the retained producer grant.
2. Clear the completed source in-flight flag, retaining the producer ledger;
   execute actual split/Put data(prefix)/Unget free(suffix).
3. Update cumulative accepted bytes and progress, then clear the producer
   reservation. Internal microstate observations preserve those separate points.
4. If the updated progress equals target, execute the internal FileTargetAction:
   enabled: set progress to`min(floor(loop_start_bytes/2048),file_sector_extent)`;
   disabled: write canonical decoder limit-1, then source target`INT32_MAX`.
5. Reload the resulting progress/target/control for the actual later physical
   end and finite accepted-sector terminal checks; then finish retry accounting.

The typed action itself does no I/O, ring reset, decode, external callback,
allocation, cancellation, predictor restore or cumulative-byte reset. Existing
queued bytes and both consumer grants remain valid. The `INT32_MAX` target is
an explicit unbounded-target sentinel; Source1's target<=file-extent validator
must not be copied to reject it.

Changing loop enable while I/O is pending is an ordinary serialized typed flag
change; the eventual publication uses the current flag. Header/ready/first-loop
configuration is concrete Window2 code with checked source/Window incarnation,
not an arbitrary mutating user hook. This also preserves a first-loop snapshot
and source file rewind as separate events rather than one generalized reset.

## Numeric admission and post-effect faults

Initial Source2 parity uses file-backed tag0, positive sector geometry, immutable
in-view whole sectors, capacity8192+36 and the finite original corpus. No
SJMEM mode2 reset, no-file ready loop, partial final-sector padding, borrowed
file handle or LSC replacement is admitted. Broader geometries require new
paired proof, not a configuration constant change.

Use checked wider arithmetic before each operation to ensure all source guest
signed-word values remain representable: start+progress, sector-byte offsets,
request/accepted-byte products, cumulative publication, target/loop positions,
retry increments and every position+grant operation. Requested provider work
must be safe for its whole possible accepted prefix **before** reservation and
submission. Source progress stays within physical file extent; only the target
has the explicit unbounded sentinel. IDs/epochs never wrap or recycle. A
maximum-safe source counter is not a proof that an `INT_MAX` decoder total,
sample-rate expression or arbitrary Window2 arithmetic is safe.

Window2 separately preflights its request, loop span/counter, cumulative sample,
header-math, channel/PCM and codec workspace domains before mutating a loop.
It must actually pass the source-observed640/1152/1216/2240/2432 requests and
long40017-sample transactions; clipping a request to256 or resetting counters is
not a shared-window implementation. The new allocation-free codec workspace is
a separate prerequisite. It reads post-loop input/history/key, never a
predecoded old-input result replayed after the loop.

Parsing after actual two Gets is already an owned transaction with held credit.
A negative signed end-record extent or unqualified next-header math remains an
excluded original unsafe/partial case, not successful native parity. Numeric
plan rejection returns no disposition credit; any already-applied prefix or
selective reset remains explicit. There is no whole-call rollback/fallback
promise. Failure/defer after a valid seamless prefix preserves original consumed
bytes, accumulated samples and selective decoder reset before clearing seamless
enable. First/second span boundaries remain distinct even if staging shares one
owned buffer; do not search an invented concatenated span across a boundary.

## Stop, close, faults and real provider retirement

Ordinary stop blocks new submissions but preserves accepted publication. An
in-flight result is polled and serviced normally; close is deferred until that
result retires. Paused-byte==1 prevents new source requests without canceling
accepted work. Buffered bytes and existing consumer credit remain available for
ordinary drain. Do not call `AsyncReadOwner::cancel` or shutdown at ordinary stop:
both suppress accepted publication and change the observed source policy.

Terminal `begin_shutdown` closes new producer/batch admission, permits accepted
publication and explicit existing-batch finish, and marks an independent terminal
lifecycle. Finalization requires no in-flight request, retained producer,
consumer ledger or enclosing service/callback; it invokes actual backend join
outside all owner/ring/provider/guest locks. It is a read-worker/storage fence,
not DAC/PCM drain. Remaining queued bytes are terminal-owned storage; calling
shutdown is not a normal decode-to-end operation.

Reset/reuse/replacement is refused with any accepted request, result, held batch
or queued data. A bound Window2 cannot survive a source epoch change silently;
reuse needs its explicit drained rebind or a newly constructed pipeline. Initial
Source2 need not offer filename replacement or live reset. Reentrant public
mutation returns `reentrant_call` without effects; no backend or observer may
call into the serialized owner while executing it. Cross-thread unsynchronized
use is outside the API, not made safe by a boolean reentry guard.

A lying/wrong-ID/overaccepting backend cannot be treated as a completion fence.
Retain the producer and fault admission; never publish unproven bytes. Normal
finalization remains busy if retirement is unproven. Emergency teardown may
retain/suppress private results and join the actual worker before destroying
storage, on a valid control thread, with no storage reuse. This is a separately
labeled owned policy, not equivalence to original unsafe reset or cancellation.

## Original projection and implementation gates

Before implementation, freeze a declarative projection of the v14 authored
transcripts. Only authored inputs, actual file bytes and source-qualified typed
field layouts enter native transport; expected snapshots never configure a
candidate ring, decoder result, history or target outcome.

Compare source state/flags, independent file progress and accepted cumulative,
actual request/acceptance geometry, retained producer and both consumer offsets
and counts, real SJRB data/free/read/write/totals, ordered Get/Put/Unget events,
published data/mirror behavior, and canonical loop limit at target entry/exit
and preterminal boundaries. The physical-end enabled/disabled pair must differ
inside service exactly as above. Source-only native fixtures may prepare the
documented queued prefix/cursor/progress through actual constructor operations;
they may not reconstruct a ring from an expected numeric snapshot.

Map original `write_job` to completion of a private owned provider result, not a
native free-space ring write. Unpublished original free backing and its raw
intermediate store-sequence hash are deliberately outside this approved owned
staging projection. Published/held consumer bytes and state/order remain exact.
Scripted completion/status inputs do not prove real provider completion.

Required new checks include two positive consumers with pending full/partial/
error producer, all four ordered plans and zero grants, invalid-last-disposition
zero effects, fake/stale/foreign/moved tokens, lost-token busy state, observer
reentry, mismatch diagnostic despite Ring.completed, source stop with accepted
I/O, target loop-flag changes while pending, ID/counter exhaustion, real blocked
AsyncReadOwner publication and actual join, and retained storage after owner
retirement. Allocation denial must cover complete service/loop/disposition
paths; worker result allocations retain their existing explicit bounded failure
policy. No mutating target callback or decoder/loop implementation starts before
this API/projection review and the separately qualified codec workspace.
