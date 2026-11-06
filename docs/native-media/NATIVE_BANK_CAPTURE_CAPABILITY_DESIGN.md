# Bank capture capability: proposed implementation contract

Status: design for root implementation review. No0125 dependency mutation,
runtime factory, cohort2 adapter change, game or device test is performed here.
This extends [the runtime capture review](NATIVE_BANK_RUNTIME_CAPTURE_REVIEW.md)
and keeps the published0124/V2 layouts and packet cohort2 evidence intact.

## Recommended components and source changes

Implement three cooperating capabilities, not an identity-based memcpy helper:

1. An actual CD RAM-writer configuration receipt and retained seal, issued by
   the configured legacy/native CD module for this Runtime/backing.
2. A per-RAM parent binding pin plus nonblocking canonical group read/transfer
   service. Pins and parent locks live only through bounded memory operations.
3. A new SDK companion capture registration installed atomically with the same
   complete V2 audio owner, with explicit hooks at the EARLIER SIF input/transfer
   boundaries. Add this in a new public0125 patch/cohort; do not append fields
   to published BackendApiV2/BankApiV2/BackendRegistrationV2.

The eventual factory requires these actual objects. A session nonce, hash,
depth integer, environment setting or current-empty registry is not a substitute.

## 1. Seal the observed writer configuration

Add a versioned `CdRamConfigurationV1` receipt to the actual configure branches
in `reo_cd_async.h` and `native_cd_owner/runtime_adapter.cpp`. It must record
the Runtime/RAM identity, configuration generation, compiled route, actual
disposition, worker/queue/in-flight state and whether this async route ever
started. Update it under the same configuration/admission mutex as changes.
The receipt is issued after actual configuration, including its early-disabled
branch; it is not computed by rereading environment strings in the bank factory.

Proposed API shape:

```cpp
enum class CdRamModeV1 { configured_sync, legacy_async, native_async, unknown };
Result<DisabledAsyncWriterSealV1> trySealConfiguredSyncRamWrites(
    PS2Runtime&, ActualRamBackingV1);
```

The move-only/strong seal is accepted only for the actual configured synchronous
route with no prior/queued/in-flight asynchronous writer. Never stop/disable a
working path to obtain it. Its generation remains frozen until all admitted
audio calls drain and the native owner releases the seal. A later conflicting
configuration returns an explicit conflict before changing actual mode; it must
not silently choose another path. Bootstrap must treat that as a setup conflict,
not silently suppress a requested feature. Legitimate initial CD configuration
runs before seal acquisition.

Mint this under a genuine pre-run setup transaction, then RELEASE the Runtime
PreRunSetupLease before run: retaining that phase lease for the entire capture
lifetime would prevent `beginExternalWorkerRun` from proceeding. Runtime worker
registration and the outer audio owner retain the mapping during gameplay.
The persistent object is the configuration seal, not the pre-run phase lock.

The conditional writer catalogue must also identify actual bridge/module
configuration and unknown host writers. Other ordinary EE/IRQ file, libc,
SPR-to-RAM, ADX/movie and RPC writes are serialized by real guest ownership in
the inspected call paths. This is an actual supported profile, not permission
for arbitrary host callbacks to write RAM without joining the protocol.

If async coexistence is later needed, introduce destination-range writer
reservations at these real points:

| Integration point | Required reservation lifetime |
| --- | --- |
| Legacy `reo_cd_async::sifCallRpc` queue admission | Before request/client publication; retain through queued and actual `complete` I/O. |
| Native CD `worker.submit` and publication callback | Reserve before publish, transfer into accepted task; release on pre-publication refusal/cancellation or after real I/O returns. |
| `ReoHwBridge::readCdSectors` | Async invocation must carry its matching reservation; unqualified async callers cannot use the raw RAM sink. Synchronous guest calls use their actual guest write authority. |
| Async completion callback | RELEASE the writer reservation BEFORE acquiring GuestExecutionScope or invoking guest completion, even after false/partial I/O. |

That ordering prevents a reader holding guest ownership from waiting for a
writer whose release requires the completion to acquire guest ownership. All
writers must participate; an empty pending set without a closed writer catalogue
is not proof. Immutable typed asset views from the loader are preferable to
reading a mutable RAM destination when their identity/provenance is available.

## 2. One capability for a complete asset group

Extend CaptureSource in a separately identified adapter cohort with an optional
versioned batch method. Proposed exact data shape:

```cpp
enum class CopySourceV1 { ram, direct_hd, direct_bd, direct_tq };
struct PartCopyV1 {
    CopySourceV1 source;
    std::size_t offset;
    std::span<std::uint8_t> destination; // already allocated/charged
};
virtual Status copy_parts_v1(std::span<const PartCopyV1>) const noexcept {
    return Status::unsupported;
}
```

The production contract is one coherent group. The default is unsupported,
not automatic fallback to three independent reads. Existing synthetic providers
explicitly override it with a loop over immutable fixture borrows; that is not
a runtime qualification. For a load, adapter first allocates all three charged
v2 capture vectors, then invokes this method ONCE with all ranges/destinations.
Direct HD/BD/TQ uses the same group operation or an immutable host-asset lease.
Loaded0x4E must bypass the group call and every unused asset admission/read.

The real provider acquires one registry pin and one parent group reservation,
copies all three parts, then releases ALL pins/locks before returning. Decode,
prepare and install happen afterwards. It must not use a magic third-call
counter or keep locks until packet return. Preserve adapter identity checks,
native bank epoch checks and accepted stop/drain behavior independently of the
group; a bank epoch is not a RAM incarnation.

The bounded private implementation should accept at most three asset spans
(total at most6MiB), or the explicitly declared small packet/query/ABI batch.
Metadata lives in fixed storage; no extra vector allocation or raw RAM pointer
escapes the operation. Validate destination ownership/nonalias with guest banks
as well as checked source intervals. Failure before any copy/effect returns a
typed status; a failed later load preserves its accepted packet prefix.

### Binding and owner lifetime

Current `installActualOwnerTarget`/`stopActualOwnerTarget` publish under
`bindingsMutex`, not NativeTarget's source/protocol locks. A current no-target
lookup followed by memcpy is therefore not a reservation. Add a stable per-RAM
binding entry created before publication and a short group copy pin:

1. Under registry lock, validate Runtime/backing/incarnation, retain the entry,
   current target AND actual parent/service storage lifetime, and increment its
   bounded copy count. Release registry lock before virtual calls or memory copy.
2. While pinned, publication cannot replace/rebind the entry out from under the
   group. Installation may defer its publication until pins retire, outside
   guest/RPC/source/protocol locks; do not reject normal initial GS setup because
   an audio configuration seal exists. The pin is group-scoped, not a global
   prohibition on parent/CD feature paths.
3. Stop remains a signal; defer final storage destruction until pins/accepted
   reader lifetimes retire. A Target shared_ptr by itself is insufficient:
   NativeTarget stores `Service&`. Retain its actual owning storage, or provide
   an owner retirement gate that prevents Service/device destruction while a
   read capability can access its mutexes/state.

An already-admitted outer SoundCall can start its capture after stop was signaled.
Retained mapping/parent storage must therefore survive outer drain, not merely
currently-running copies. Runtime teardown currently drains registered workers
before guest/GS/memory destruction; encode that actual ordering in the owner
contract and prevent an early live rebind/destruction from bypassing it. Do not
invalidate the accepted mapping solely because Runtime.stop is now set.

### Parent locks and deferred ownership

The group method must use nonblocking acquisition under already-held guest/RPC
ownership: try NativeTarget `sourceMutex_`, then try Service
`hostProtocolMutex_`. On contention, release what was acquired and return busy/
unsupported. Do not wait/flush/release-and-reacquire guest execution underneath
RPC mutexes. No registry lock is held during this method.

Both locks are needed. Source mutex protects `frozenRanges_`, held-T1 state and
pending exact writes; write permits can temporarily unlock it while keeping a
pending-range guard (`native_owner_target.hpp:2057..2180`). Protocol mutex
protects GPU service/bridge publication. For example
`waitOriginal191280OnOwner` publishes RAM ranges into `upstreamOpaque_` after
its fence (`parent_owner_service.hpp:2200..2245`) without acquiring source
mutex. Holding only source mutex or checking only current opaque ranges misses
that transition.

Add a NONMUTATING admission query inside those locks. Existing `read()` can
make the graphics owner sticky-failed on refusal, and returns no lease. The new
query returns status without claiming a CPU read occurred. It must cover:

- held/fresh source fences, frozen RAM spans and pending exact writes;
- current upstream and bridge opaque RAM spans;
- parent bridge inputs/recorded/submitted/waiting phases and deferred ownership;
- queued/uncommitted matrix, perspective, composition, viewport, setter,
  allocator and queue work, including retained invocations whose GPU effects are
  not yet published into the opaque set;
- binding/epoch/context/storage validity and unknown writer profiles.

In particular,191280 can already be queued BEFORE the audio thread acquires
guest execution. Its result span need not be in `upstreamOpaque_` yet. Existing
NativeTarget prepares held ranges before guest release for these paths, but the
new query must explicitly validate the queued frontier, not assume that a
currently-empty opaque vector means no future publication. For an operation
whose complete future RAM footprint is not source-qualified, conservatively
return busy for the group. Per-span refinement requires a recorded footprint
published at prepare time before releasing ownership, and retained until the
actual corresponding completion/retirement.

Raw copies occur while the actual group reservation and both locks remain
held. No GPU readback of opaque numerical values is permitted. Any required
fence that needs guest release belongs at an explicit earlier boundary with a
retained range claim, not hidden inside this copy callback.

## 3. Cover the EARLIER SIF chain

The FINAL125 code is explicit: `SifCallRpc` calls `rpcCopyToRdram` before entering
the bank table (`RPC.cpp:1829..1831`). The helper (`Helpers/Runtime.h:269..301`)
is a1MiB-clamped BYTEWISE FORWARD guest-to-guest copy. There is no explicit
payload vector at that site; no unbounded allocation gap is asserted there.

The packet adapter's later owned packet snapshot does not qualify this earlier
read/write. The same service must cover these earlier native-audio operations:

| Stage | Qualification required |
| --- | --- |
| Host SID/RPC classification | Primitive registers/host client binding; do not access payload just to decide whether the native capture service applies. |
| ABI stack metadata | A valid caller-owned actual Context/stack ABI witness, or a bounded canonical batch for the stack words. Real guest scope alone does not classify GPU-opaque stack data. |
| Client/server generic transport fields | May retain the existing valid-caller administrative domain if explicitly justified; do not imply full generic SIF migration. |
| `rpcCopyToRdram` | One source+destination canonical transfer reservation, bounded mapping checks and exact forward overlap semantics. |
| Audio driver adoption/status initialization/backfill | Retain existing order; use a qualified CPU-control/administrative write domain or corresponding canonical write reservation. Runtime identity checks alone do not authorize opaque RAM writes. |
| Command logging before table | Native logging consumes owned packet/actually captured asset bytes; it must not dump raw RAM descriptors before the read capability, especially for unused loaded0x4E. |
| Query input word(s) | Canonical bounded capture before reading; return path must qualify its control reply destination. |
| Packet snapshot and HD/BD/TQ | Capture packet after preceding original transport/adoption effects, then invoke one asset batch before decode. |

Preserve transport order and overlap. For example, copying six forward bytes
from offset0 to offset2 in `ABCDEFGH` produces `ABABABAB`; memmove or a snapshot
of original source bytes would produce `ABABCDEF`. Source/destination aliases
must be normalized to the same actual backing before deciding overlap. Prefer
executing the same forward loop under a joint read/write reservation. If typed
write provenance requires staging a result, the staged operation must simulate
that exact evolving copy and prove intermediate effects unobservable under the
reservation; ordinary memcpy/memmove is not an automatic substitute.

Retain the1MiB clamp and declared native packet admission policy. A native profile
may conservatively reject scratchpad/MMIO/wrapping/noncontiguous forms before
effects rather than incorrectly implement them as ordinary RAM. Such a refusal
is a declared profile limit, not equivalence for every legacy address form.
Transport writes can modify the original send buffer when aliases overlap, so
parse the POST-transfer/post-adoption packet, not an earlier unchanged snapshot.

There are two relevant lifetimes: outer SoundCall owns the WHOLE producer/RAM
lifetime before this transport; the bank's epoch-qualified Submission starts at
its semantic bank operation after original adoption/reset, before native packet
capture. Do not prematurely mint a bank epoch token, then unknowingly invalidate
it by the same call's legitimate adoption reset. Conversely, do not reacquire
outer admission after initial capture or after stop.

### SDK API versioning

Use a new companion API such as `NativeSoundRamApiV1` with bounded batch read,
exact forward transfer and typed control-write callbacks, sharing the SAME
registered owner. A new atomic install function validates complete V2 audio plus
the companion before worker registration/publication. Existing V2 layouts and
registration entry remain unchanged. New helper entry points take the explicit
accepted SoundCall; implementation accesses its retained private Binding rather
than selecting/reacquiring a backend. SDK source hooks must be added at the
actual earlier sites above, not merely in BankApiV2 callbacks.

Native runtime selection for the new aggregate requires the companion. Existing
V1/V2 users retain their published contracts and cannot be mislabeled as having
this capture qualification. All dependency changes require the next reproducible
patch, fresh reapply, matching headers/objects/libraries and candidate identity.

## Prerequisite implementation/test sequence

1. Implement actual CD mode receipts/seals and configuration conflict tests.
   Test enabled-but-idle, disabled-after-start, wrong Runtime/backing and changed
   environment against actual configured state; none may invent a safe receipt.
2. Add binding pins/storage retirement and parent nonmutating group API.
   Instrument real method bodies/locks and compile real headers. Test initial
   no-parent GS installation waits outside locks then succeeds after group
   release, stop/epoch/rebind lifetime, lock contention and no callbacks under
   registry lock.
3. Test queued191280 BEFORE opaque publication, pending exact writes while source
   mutex is temporarily unlocked, bridge waiting entries and unknown future
   footprints. Each must refuse appropriately; private variants omitting those
   pending checks must fail the tests.
4. Add versioned batch adapter entry. Test all three parts remain one asset when
   a writer or protocol publication attempts to interleave between copies.
   Test leases are released before a paused decode/allocation, loaded0x4E never
   calls batch, and reset/stop/later publication preserve their existing rules.
5. Add the new SDK companion and earlier transport/query/logging hooks. Compare
   exact source forward-copy results for both overlap directions, exact alias,
   zero/clamped sizes and the declared address domain. Test control/arena writes
   refuse opaque/frozen destinations before effects. No invented source vector
   budget test; any NEW staging must use actual allocator accounting.
6. Keep prior0124/cohort2 artifacts; issue new cohorts and rerun both compiler
   unit/negative controls, whole-source packet/DSP corpus, actual new SDK header/
   RPC/helper objects, then rebuild the complete selected owner coherently.

Only after these capabilities close the actual input chain should root wire the
real-game CaptureSource and aggregate selection. Current packet/core tests are
necessary evidence, not a replacement for these missing memory authority APIs.
