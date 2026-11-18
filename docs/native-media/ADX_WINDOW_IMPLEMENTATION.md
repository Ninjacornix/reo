# Native ADX decode-window ownership

Status: independently buildable Stage3 component, 2026-11-06. No game/device,
full game build, runtime selection or original dependency modification.
The parent standalone CMake project includes this component; bootstrap and
candidate packaging remain unwired. This is a complete bounded window owner; the
resource-to-speaker ADXT player remains incomplete.

The [original window oracle](ADX_WINDOW_ORACLE.md) was generated/inspected by
this implementation's author before native implementation. Native source was
then frozen **before** comparator development. This is honest staged
qualification, not blind independent authorship. All original fixtures and
existing kernel/control/SJRB implementations remain unchanged.

## Closed transaction

[adx_window.hpp](../../game/native/adx_window/adx_window.hpp) and
[adx_window.cpp](../../game/native/adx_window/adx_window.cpp) own typed
`OuterState`, `InnerState`, the existing predictor state and actual private
native SJRB rings. A service pass implements the admitted `12D638` state gate,
`12CFD8` acquire/admission, real outer reservation behavior `12CEB8`, original
budget geometry `125370`, predictor/control dispatch `135078`, result/wrap
`125518`, default completion `124840` and publication/ack `12D338/125278`.

The native SJRB core supplies actual two-pool reservations, modulo suffix return,
transfer totals, mirror and wrap copies. Native keyed mono/stereo/downmix
kernels supply actual PCM/history/key/marker/return arithmetic. Existing
predictor control/service supplies request/processing/ready/completed and
odd-result behavior; it is not replaced by a dummy decoder. All are reused
unchanged with their hashes recorded at freeze.

After real reservations, the owner applies actual staged PCM, key and history
effects at the worker boundary, records distinct original completed units,
consumed bytes and produced samples, performs the early halfword wrap copy,
acknowledges lower ready and executes default completion. It then returns the
encoded prefix/ungets the suffix, invokes each optional readonly PCM observer
before that channel's Put, publishes its valid prefix, returns unused free
suffixes, advances outer counters and acknowledges ready.

The source's outer total-sample clamp is preserved separately from the inner
budget gap. It does not roll back extra kernel scratch, key/history changes or
consumed input. Empty/zero-budget calls still execute their admitted zero-work
phase/publication/return sequence. Backpressure can perform a balanced input
Get/Unget while leaving old inner results unchanged. Status `backpressure` from
service is therefore a completed observation with no decode, not a promise that
no source-visible guard ran.

Ordinary leading-zero bytes remain ordinary compressed input. Only the original
outer end-marker continuation scans/discards padding; a subsequent ordinary
block stays queued while outer state 3 prevents another decode. Positive fitting
marker prefixes and padding are returned through real native ring operations,
not host counter assignments. See the original document's source correction.

`constructor_default_reservation` separately implements actual `124810` scalar
geometry. It does not pretend to acquire rings: ordinary outer transactions use
the outer reservation behavior. The helper fixture applies its authored 7/12
prewrites to a real copied typed `InnerState`, invokes this scalar function and
compares its unchanged state/actual returned reservation. This is one helper
case, not a second alternative outer transaction.

## Resource staging before observability

The existing codec APIs allocate PCM vectors. The owner does **not** call them
after borrowing and hope allocation succeeds. Under exclusive serialization it:

1. Reads private ring snapshots and validates complete geometry, counts, all
   channels and current phase. A checked non-observable span copies the current
   encoded grant into fixed bounded private storage.
2. Computes request geometry from those snapshots and invokes the real existing
   codec into private result vectors. It validates actual full scratch sizes,
   consumed/produced values, all physical ranges and reservations. Failure,
   including `no_memory`, returns before any guard, Get, callback or numeric
   source-state update.
3. Acquires the actual rings and commits that already computed result in original
   observable order. Remaining library work uses fixed local buffers, strong
   chunks, scalar operations and no new result-vector allocation.

This moves computation before observable borrowing without moving any visible
payload/history/key/state change before its source boundary. Private rings have
no external mutable access, callbacks observe only, and public mutation reentry
refuses. Thus input/configuration/storage cannot change between staging and
commit in this admitted domain. Arbitrary concurrent/reentrant mutation would
invalidate this argument and is explicitly excluded.

Unit checks exercise a **real kernel vector-allocation failure** and verify
unchanged typed/ring state and zero guard/callback count. Another unit
turns on a global allocation-denial probe at the first guard; the complete real
decode/publication still succeeds with zero denied late allocations. No new
in-place kernel API or frozen decoder change was required.

## Storage, views, stop and requests

Each Window exclusively owns its encoded and PCM ring objects; those own full
physical backing. Private actual chunks retain strong storage references through
the transaction. A Get updates the caller descriptor before its leave observer,
matching the original's actual out-parameter timing. Returned descriptors remain
numeric observations after ownership return, not another outstanding lease.

Readonly `PcmView` retains an actual chunk privately and provides bounded read
copies without exposing a mutable token, data pointer or guest address. It can
keep bytes allocated after Window destruction. It does not freeze data: reading
after credit return/reuse requires the caller's own content/lifetime policy.
Callbacks and retained views require externally serialized access.

`Request` contains private owner identity and generation, so foreign/stale work
refuses before effects. A request stamp is an admission identity, not a storage
lease or a strong Window reference. The caller must keep Window/callback context
alive throughout an enclosing synchronous call.

`stop()` refuses mutating reentry during an active call, then closes subsequent
decode/feed admission when called outside it. It preserves already accepted PCM
for selected-channel drain and invalidates old requests. It does not reset rings,
clear history, call original cancel, interrupt a worker, join a device or reset
the shared PCM backend. There is no restart API; another admitted stream gets a
new owner. Destroying an owner during its callback remains excluded. No internal
worker threads or invented lock-free SPSC/atomic protocol exist.

An unexpected post-effect invariant fault closes admission, reports
`invariant_fault` and retains current descriptors/chunks/backing. It does not
claim success, restart an original call, reclaim an active kernel's storage or
guess which partial publication can be undone. The ledger is diagnostic retained
state, not a promise of whole-transaction rollback/recovery. Such a fault is not
reached by any admitted paired fixture.

## Explicit admitted domain and refusals

- One/two channels, fixed 18-byte/32-sample keyed integer geometry. Per-owner
  downmix selection is explicit; no global downmix/rendering option is enabled.
- Encoded ring 2048+36 bytes and PCM **16384+192 bytes per channel**. PCM virtual
  spacing is 8288 halfwords. Entire owned storage exists before usable service.
- Total samples 1..4096, sample limit -1..4096 and requested maximum 0..256 samples.
  Coefficients/history/key are provided typed scalar inputs; header parsing,
  trig/float coefficients and reachability from a particular real file are
  separate. No movie/game simulation clock is inferred from sample counts.
- Bootstrap can position empty rings and provide initial accepted PCM, with
  equal PCM cursors/occupancy; it is not guest-state import or module lifecycle.
  Feed and selected-channel consumption use real ring Get/Put operations.
- Every service requires balanced counts and aligned PCM geometry. Unequal
  channel grants refuse before borrowing. Consumers may return credits separately;
  decode waits for a qualified symmetric configuration rather than overwriting
  another channel's occupied storage.
- Actual **kernel scratch**, not just published prefix size, must fit every
  actual reservation and physical extent. A partial 35-sample budget with only 40
  samples reserved can require 64 scratch samples; that state refuses before
  effects. Releasing enough credit admits the original operation. This is a
  deliberate safety restriction beyond the original unchecked caller.
- Short malformed outer`8001` records and negative wrapped marker lengths refuse
  before effects. Ordinary short encoded grants can execute zero work. No
  fabricated parser result, plugin or header/refill retry policy is supplied.
- Callback domain is synchronous, nonthrowing and readonly. Mutating Window
  reentry refuses; general cancel/reset/destroy/rebind and cross-thread stop are
  not original-equivalence claims. Accepted PCM consumption is an explicit
  caller credit action, not measured DAC playback or atomic stereo transport.

## Frozen proof and comparison

Historical freeze: `game/native/adx_window/frozen_identity.json`, SHA
`013f78abe930130471082ff47cba00145273b1dcf7b337dd13454184ab56a77a`.

| Frozen file | SHA-256 |
| --- | --- |
| `adx_window.cpp` | `479deb13ae9894158b2fcd81d35b9c400c02f0e472f8df6c47f484723a1121f3` |
| `adx_window.hpp` | `a443e48c83762a1be0c814b346d48d2f250a77154c18f9c5e9af864b8c1fbffe` |

Both GCC and LLVM pass **86 native unit assertions** and the exact frozen
**33-case** original corpus: 32 outer transaction cases and one scalar default
reservation helper. Each comparison checks 50 actions, 590 guard/PCM observations,
**673 typed state observations**, 2,029,484 physical byte snapshots and 52 PCM
callbacks, including whole physical planes at callback boundaries. The same
unchanged frozen core/header passes both compilers.

The C++ executable receives **only authored input/profile commands**, not expected
values or case-name branches. Python reconstructs original observable state by
applying the fixture's captured STORE bytes to its recorded before-state. It
does not implement an expected ring, budget or decoder. This reconstruction is
checked against directly recorded original callback state, actual callback-plane
hashes and final state/backing. Therefore guard enter/leave comparisons include
precise mutable state, not only event counts. Staged real codec results are not
expected-driven test hooks.

Compared typed projections include outer phase/descriptors/counters, inner
phase/input/block/reservation/result/completion fields, predictor request/mode/
history/key/output positions, ring positions/counts/totals, odd flag and exact
owned physical bytes. Original raw static identity/header-layout fields, guest
register/stack ABI and libc dispatch boundaries have no typed-layout equivalent
and are excluded explicitly. Initialization module/pool constructors are not
native lifecycle claims. No per-instruction scheduler/interruption equivalence
is claimed for committing the privately staged kernel result.

Retained paired receipts:

- `build-native-sjuni/adx-window-native-parity-v2/gcc/receipt.json`, SHA
  `5cf7a61c7523c5b3a29116ee2a0ece09bd655dff35448ceb3982070763854f26`.
- `build-native-sjuni/adx-window-native-parity-v2/llvm/receipt.json`, SHA
  `ac44f1a8eb2734ae3c0deec47ca28542c15bb7fefa3af746fa507b12cc43153d`.

Original fixture SHA
`62dfa91bf99698bc10c84356e8320912967cefadbd6a83feb95f453122fafeff`,
authored input SHA
`55a7b1bdda757fbeeb764e3766453b062bab9f692e5da7f2ea23eefe5d8dcbee`.
All original and dependency hashes are checked before native comparison.
The earlier v1 comparison directory retains a harness-only warning/compile
failure; correcting the transport formatting did not change frozen core source.

Independent CMake/Ninja build and CTest also pass at
`build-native-sjuni/adx-window-cmake-gcc`; retained qualification receipt
`build-native-sjuni/adx-window-native-checks/cmake-receipt.json`, SHA
`72a821f2b89705071acab9434f700ac8327f8564dc7142029f29fc3aca7b921b`.
This compiles only the standalone native project/dependencies. No root wiring,
game/runtime build or device execution occurred.

## Remaining owner boundaries

This component supplies a real complete bounded decode window. Full native
ADXT still needs admitted header/key/coefficient production, source/LSC refill
and immutable result ownership, loop snapshot/seek/end/drain policy, authoritative
stream scheduling and stop/join, and a qualified RNA/PCM credit/control/position
binding with incarnations. Per-stream stop must not reset a shared audio session.
No runtime adapter selects this owner yet, no slowdown cause is diagnosed and
no gameplay speedup/full-player completion is claimed. See
[ADX_STREAM_NATIVE_BOUNDARY.md](ADX_STREAM_NATIVE_BOUNDARY.md).
