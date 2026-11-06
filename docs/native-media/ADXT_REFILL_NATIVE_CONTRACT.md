# Native encoded-source/refill contract

Status: implementation design, 2026-11-06. Root reviewed the proposed API and
authorized a separate native core. No runtime integration, game/device run or
claim of full ADXT playback follows from this design. The
[original oracle](ADXT_REFILL_ORACLE.md) was authored and its observations were
seen before this design; a later native freeze must say so explicitly.

## One ring, two retained credits

One nonmovable `EncodedSource` owns one real `sjrb::Ring`, one held producer
free chunk and at most one active consumer data chunk. Refill and the future
Window v2 use this same owner; the window does not keep a second encoded ring
or receive an independently copied feed. No mutable `Ring`, `Chunk`, backing
span or guest address escapes. Public snapshots contain counts/positions/totals
and lifecycle metadata, not mutable payload.

`DataLease` is move-only. It carries a strong private chunk, owner identity,
incarnation and nonwrapping lease ID. `read_into` copies only the bounded granted
bytes into caller-supplied storage. `finish_data(lease, consumed)` validates the
actual owner/stamp before effects, splits the owned descriptor, puts the consumed
prefix into free pool, then ungets the unread data suffix. `consumed=0` returns
the entire data grant. A lease destructor never returns credit from an arbitrary
thread. Losing a live lease leaves the owner busy; it does not authorize another
borrow or reset. A stale/foreign/duplicate return refuses before any ring effect.
The strong chunk retains actual storage after facade destruction, but owner
identity is then closed and the lease cannot return credit or obtain new data.

The producer ledger independently retains the entire actual free grant, its
incarnation, accepted sector count and provider ticket until completion. While
either side holds credit, `data+free` can be below capacity. The invariant is
`data + free + heldProducerBytes + heldConsumerBytes == capacity`, with checked
extents and disjoint admitted logical ownership; ring extension is mirrored
storage, not extra credit. Scalar equality with capacity alone is invalid.

All owner calls, snapshots, lease reads/returns and destruction require external
serialization on one host control domain. Provider workers access private read
results only; they never touch ring/owner state or invoke owner callbacks.
Pause/stop/close are serialized methods, not unsafely cross-thread plain flags.
Optional application cross-thread signals must be marshalled to this domain.
Synchronous hooks are read-only/nonreentrant; mutation or destroy during a hook
is refused or outside the domain. No provider I/O/join occurs under a ring hook,
data/RPC/guest lock or shared PCM/bank lock.

## Proposed API

```cpp
struct SourceDescriptor; // retained immutable ByteView + mount/file identity/range
struct Config;           // all geometry/byte/request/queue bounds admitted up front
class DataLease;         // private strong chunk; read_into, size, offset, stamp
class EncodedSource {
  StepResult service() noexcept; // one actual lifecycle/refill pass
  BorrowResult borrow_data(std::int32_t maximum) noexcept;
  Status finish_data(DataLease&, std::int32_t consumed) noexcept;
  Status set_paused(std::uint8_t) noexcept;
  Status request_stop() noexcept;
  Status request_close() noexcept;
  Status reset_quiescent() noexcept;
  Status replace_source(SourceDescriptor) noexcept;
  Snapshot snapshot() const noexcept;
  Status begin_shutdown() noexcept;
  bool finalize_shutdown_and_join() noexcept;
};
```

Names may be refined without changing the contract. Snapshot exposes original
state/flags, progress, cumulative accepted bytes, retry count, target and ring
totals; native lifecycle and refusal statuses remain separate from original
signed state values. Original void entries do not acquire invented returns.
An optional bounded constructor bootstrap may establish initial position and
preloaded bytes using real SJRB operations before external callbacks are
enabled. It is an explicit prepared-state input, never a writable ring escape
or a claim that the file backend produced those bytes.

## Provider protocol and existing reuse

Use existing unchanged `AsyncReadOwner`, which already owns a bounded
`SerialWorker`. Do not stack another worker on it. First owner has one provider
request slot and one outstanding producer lease; asynchronous views, task
captures, output and exact-read staging remain charged until retirement.

The provider interface returns typed acceptance plus an opaque owner-bound
ticket. Positive accepted sectors must not exceed the actual source request or
retained grant. A later poll yields pending, complete exact accepted bytes, or
error. It never returns a short successful buffer. The production adapter admits
the whole checked request if `AsyncReadOwner::submit` accepts; a deterministic
test provider can accept a positive prefix using the same protocol. Zero-sector
requests retain original request/accounting observations but enqueue no host
read; an idle zero response is distinct from an error response. Resource refusal
after a ring borrow returns that entire free grant and reports the typed native
failure; it never calls original fallback after effects.

`AsyncReadOwner` reads into **private owned output**, and `ResourceSession`
stages exact reads. A provider may modify its own staging before failure; no
unpublished ring bytes are exposed. On a later serialized owner pass, exact
successful result bytes are copied into the retained free chunk, then actual
SJRB split/put-data/unget-free runs. Publication length remains accepted sectors
times2048. Failed reads return the entire free grant and enter the source-derived
retry/error path. The result is consumed once; no completion for a foreign,
cancelled, reused or retired ticket can mutate the owner.

This is an explicit native safety policy: original inline `ReqRd` can write free
backing during submission; this adapter writes it only at later successful
publication. **Raw intermediate free-backing parity is excluded.** Admitted
consumers can read only an actual data lease. Their byte sequence, ring credits,
progress/counters, callback ordering and completed publication are comparison
targets. No production diagnostic API exposes unpublished backing to erase that
distinction.

Mount/route selection happens before owner admission. Reuse retained
`MountedResources`/`MountedReader` identities, `PinnedFile` and returned immutable
views. `MountedReader` is synchronous, not an async ticket provider; either
resolve an exact retained view for `AsyncReadOwner`, or explicitly run its exact
sector method on an owned worker with private output. The first implementation
should prefer the existing view/AsyncReadOwner path. Never reopen a pathname
after identity admission or substitute a generic ByteView size for pinned
immutable content proof.

## Service and control ordering

One service pass follows actual `130B78→130800` decisions. Pending work prevents
stop/close transition until its result is observed. Completion clears in-flight
metadata at the source-observed point, publishes accepted data, returns suffix,
updates counters, clears reservation and then invokes the read-only target
callback. It does not submit a second read in that same pass. Later service
handles stopped state/close. Original target, finite cumulative sector limit,
threshold strict inequality and pause byte==1 remain distinct.

Normal `request_stop` rejects new refill but **drains accepted publication**.
Do not call `AsyncReadOwner::cancel`: that suppresses the very result ordinary
stop must publish. `request_close` requests stop, waits through pending result,
then releases this owner's source view; buffered encoded bytes and an active
consumer lease remain valid for drain. It does not clear accepted PCM or touch
shared PCM/bank owners. This close is not itself a worker join.

`reset_quiescent`/replacement refuse while provider work or a consumer borrow
exists. First profile also requires the encoded ring fully drained. Only then
may they advance a checked incarnation and reset/reconfigure. Exhausted owner,
request, lease or incarnation IDs refuse without reuse. Original permissive
`130620` behavior losing a pending pointer is **not** reproduced by this safe
API, and no original generation is retroactively invented.

`begin_shutdown` is a separate terminal admission signal. Normal finalization
requires all pending accepted results to have been serviced and all consumer
credits returned; otherwise it reports busy. Only then shut down/join this
owner's private read worker outside all ring/provider/guest locks. A true join
means accepted tasks/captures/provider reads are finished, not DAC output drain.
An emergency destructor may suppress pending encoded publication while joining
retained private results; this is teardown policy, not ordinary ADXT stop. It
must retain all actual storage and cannot run on its own provider worker.

## First admitted domain and bounded resources

- Tag0 encoded file source only; prepared owned-open descriptor, exact retained
  immutable view and checked range. No borrowed cvFs handle, memory/LSC/plugin
  route, filename parsing, implicit global pool or open/wait pumping.
- Capacities2048/4096/8192 plus36-byte extension match the frozen refill corpus.
  Larger real workareas require new original and native geometry qualification.
  Initial/preloaded positions and bytes must be physically bounded; no numeric
  raw descriptor restoration or partial credit fabrication.
- Nonnegative checked sector start/progress/target and whole-sector byte range,
  representable original signed arithmetic. Native byte/ID arithmetic is checked
  before effects. Original negative/overflowed geometry is refused.
- Strict entire read lies inside actual view extent. Partial final sectors,
  read-ahead zero padding, DVCI sync near-EOF count discrepancy and HTCI remain
  excluded. A 2049-byte original case demonstrates a zero-sector tail request,
  not a license to invent a successful padded final sector.
- Config bounds maximum request bytes to capacity and sectors to512, one producer
  and one consumer lease, one queued/active/ready provider result. Provision ring
  backing, fixed metadata and error/trace capacity before service. AsyncReadOwner
  output plus staging budget is twice maximum read bytes; task allocation failure
  becomes a typed read/submission failure and returns the grant. No unbounded
  event queue, retry log or per-poll allocation is added by this owner.
- Integer retry limit -1..127, finite cumulative limit and bounded counters. No
  hidden wrap correction; reject unsupported signed/overflow domains explicitly.

The first integration remains blocked by frozen Window's256 request and4096
total limits, mutating pre-admission loop callbacks, and its private-ring API.
Future Window v2 must consume this owner's real data lease and return an exact
consumed prefix. Its real1152/2240-size and long-stream corpus is a separate
qualification, not automatic admission from this refill design.

## Comparison projection and negative controls

Freeze the native core before writing a comparator, honestly after original
oracle exposure. Feed authored input only to the native runner; expected data
must remain in the independent comparator. Transport all29 original cases,
classifying admitted observable comparisons versus explicit refusals:

| Original cases | Native comparison or explicit exclusion |
| --- | --- |
| Inline/later publication, partial acceptance, pending, consumer during pending, wrap/split, full/threshold backpressure | Compare source flags/counters, actual ring snapshots/totals, callback observations and returned published bytes. Exclude raw unpublished free bytes and instruction/stack/volatile-register artifacts. |
| Zero/negative acceptance, pending error, retry limits, target/finite limit | Deterministic provider supplies the same typed status/acceptance transcript. Verify full free return, no duplicate request/publication and same source-domain state. |
| Pause/stop/deferred close | Same admitted source ordering and published bytes. Real blocked-provider tests additionally prove that signal/close do not join or suppress accepted result, and storage survives until completion. |
| Subsector tail2049 | Original evidence retained; first production strict whole-sector range refuses before any source/ring/provider effect. No normalized EOF success. |
| Reset-pending, reset+ring-reuse+latewrite, reset-close-latewrite | Before-effect busy refusal rather than original unsafe state loss. Keep original observations unchanged; explicitly mark safety-policy difference. No fabricated parity by injecting expected bytes or a new original generation. |

Native negative controls must exercise foreign/stale/moved/duplicate data leases,
overconsumption and invalid extents, ignored lease destructor, ring conservation
with both grants outstanding, provider capacity/allocation/read error, wrong
ticket or wrong-size success, counter exhaustion, reentrant callbacks, and stop
or close during a genuinely blocked ByteView read. Verify no provider lock is
held through data hooks and no stale result mutates a later incarnation. Test
normal drain and terminal shutdown separately. Both GCC and LLVM host checks
and paired projected original comparisons are required before root wiring.

## Source reuse audited for this design

Read the current actual headers/implementations, without changing them:
`resource_io/async_read_owner`, `tasks/serial_worker`, `sjrb/sjrb`,
`resources_windows/mounted_reader`, `mounted_resources`, `pinned_file` and
`resources/byte_view`. AsyncReadOwner implementation SHA-256
`09235718523d8fa684bbdd96957376a89482a46c906236a8e233086083b1226a`;
SJRB implementation `29a888b091cf7284876cabcab0aa78062632e6192d98782edc0b065d926d25a2`.
`ByteView::read` may block, throw or modify its private destination before failure;
`size()` is immutable/nonblocking but alone does not establish immutable bytes.
AsyncReadOwner's ready phase follows the actual read and ResourceSession handle
release; cancel/shutdown suppress publication and cannot interrupt active I/O.
Its `join` requires shutdown and detects worker self-join. These are actual
reuse constraints, not invented original cvFs fences. Lower original DVCI/HTCI
stop/close and padding differences remain in
[CVFS_REQUEST_BOUNDARY.md](../native-resources/CVFS_REQUEST_BOUNDARY.md).
