# Next cvFs resource boundary

2026-11-05. Static investigation only. No game, build, dependency edit or runtime
redirection was performed. This refines the [resource inventory](RESOURCE_BOUNDARY_INVENTORY.md)
against original File #1 US instructions and the [current native core](../../game/native/resources/README.md).

**Migrate the payload provider beneath the existing disc request owner first.**
The smallest supported integration is a positioned, wholly in-range read from
an identified immutable cached file or virtual archive, at the existing
[`readCdSectors`](../../recomp/overrides/reo_hw_bridge.cpp:2553) service boundary.
Keep SRD admission, DVCI status/service, stop/close, the original disc completion
callback and CRI borrowed-span publication in place. A complete native cvFs
backend is a later boundary: `read_exact` success does not implement its protocol.

This is a proposed integration domain, not a newly migrated caller. The native
core has synthetic validation recorded in the [status](README.md); it has no
cvFs/SRD request owner or guest buffer lease. The complete caller/backend
contract that eventually needs migration runs from the CRI reservation through
request admission, service-driven terminal status and reservation return.

## Evidence and identity

Original image: `game_data/SLUS_207.65`, SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Complete connected catalogue bodies below were read, including branch delay
slots; fresh read-only comparison against the owned ELF verified **33 bodies,
1,458 instruction comments and 44 omitted zero words**, with zero conflicts and
zero omitted nonzero words. This checks source provenance, not runtime parity.

Reproduce the word comparison by importing `audit_owned` from
[`review_recvx_platform_complete_scope.py`](../../tools/function_index/review_recvx_platform_complete_scope.py:78)
and supplying `main:` plus each eight-digit start below. It reads the index
without writing it and checks the owned ELF identity. `read_insns.py` and
`read_pc_slice.py` under `build-function-index` provide the full instructions.

| Full-body starts | Boundary reviewed |
| --- | --- |
| `135930 135A58 135AC0 135C80 135CF8 135D60 135DC8 135F50` | cvFs wrappers, slot ownership and dispatch |
| `1396D0 139A50 139BD8 139C30 139CC8 139D00 139EA8 139FA8 139FE0 139FE8` | DVCI update/open/close/seek/tell/read/stop/status/sector size/transferred bytes |
| `137340 1373C8 137468 137558 137608 137738 137868` | Shared SRD singleton create/destroy, disc/host preparation, status/wait/break |
| `130800 130B78` | CRI reservation, completion publication and stream lifecycle |
| `13B0B0 13B790 13B840 13B910 13BBA8 13BBE8` | Host padding and contrasting HTCI lifecycle/read/status semantics |

The original DVCI vtable at `21CBF8` has request/status/stop/seek/close methods
`139D00/139FA8/139EA8/139C30/139BD8`. The HTCI table at `21DA88` differs.
The owned ten-word jump table `23CA60` is
`139760,139774,139774,139738,139774,139774,139774,139774,139774,139728`.
Thus SRD state 3 reaches DVCI success, 9 reaches error and 0 reaches stopped;
the other listed states do not become a completed DVCI read. Original table and
backend ownership are also documented in [CRI backends](../SYMBOLS_CRI_BACKENDS.md).

## Contracts that constrain the cut

The cvFs wrapper is a two-word object: table pointer and underlying backend
token. [Open](../../recomp/config/output/sub_00135930_0x135930.cpp) resolves the
device and obtains one of forty wrappers at `261F28`; backend open must return
a nonzero token. [Close](../../recomp/config/output/sub_00135C80_0x135c80.cpp)
calls method `+14` first, clearing both wrapper words only after that method
returns. A missing method diagnoses without freeing the wrapper. Seek, request
and status simply dispatch; no generic byte conversion belongs to these wrappers.
Wrapper invalid status returns 3, whereas a null direct DVCI status diagnoses and
returns 0. These are not interchangeable error APIs.

### Acceptance, completion and transfer counts

In [DVCI request](../../recomp/config/output/sub_00139D00_0x139d00.cpp), the
positive accepted sector count is `min(requested, sectorLength - cursor)`, with
the original signed/word arithmetic (`139DB4..139DE0`). The method stores accepted
count at handle `+10`, destination at `+18` and the SRD pointer at `+1C`.
Preparing SRD is not completion. The singleton at `21BB88`, obtained by
[`137340`](../../recomp/config/output/sub_00137340_0x137340.cpp), prevents another
request from being admitted while occupied; replacing it with unconstrained
native parallel requests changes observed zero-admission behavior.

| Situation | Original observable behavior |
| --- | --- |
| DVCI already state 2 | Request returns 0; does not admit another request. |
| Nonnull buffer, request 0, not busy | Sets state 1, returns 0, retaining prior completed count. Null buffer rejects before this branch. |
| Asynchronous accepted request | Sets state 2 and returns accepted sectors. `1396D0` later consumes terminal SRD status, advances cursor by accepted count, stores accepted count at `+14`, sets state 1 and destroys/clears the SRD token. |
| Synchronous mode `21D8E4 == 1` | Pumps/waits/destroys SRD, advances cursor by accepted count, but stores **original requested count** at `+14` (`139E6C`); returns accepted count. |
| Status query | `139FA8` loads signed state byte `+2`; it does not service pending work. |
| Transferred-byte query | `139FE8` returns `completed << 11` only in state 1, otherwise 0; this is not an independent measurement of payload bytes. |

The synchronous near-EOF discrepancy is real instruction evidence, not a reason
to normalize the counters. It does not affect the selected strict in-range
domain, where requested equals accepted, but must survive any later general
backend reconstruction. Open may also set sector length `7FFFFFFF` for a special
cache lookup result: a finite native view cannot silently stand for that sentinel.

### CRI owns the reservation and publication order

The [stream service](../../recomp/config/output/sub_00130800_0x130800.cpp) first
polls cvFs status (`130828`) and then enters its CRI guard. It borrows a pool-0
SJ span, seeks by logical sectors and calls ReqRd (`130A40..130ACC`). It records
the whole reservation at stream `+20/+24` and the **returned accepted sector
count** at `+1C` (`130AD0..130AE4`). A positive return leaves it in flight. Even
a synchronous provider is not published by this same submission pass.

On a later service pass with backend state 1, it clears the in-flight byte
*before* leaving the guard (`13084C..130854`), splits the reservation at
`accepted << 11` (`130858..130874`), puts the prefix into SJ pool 1, then ungets
the suffix to pool 0 (`130878..1308A4`). Only afterward does it update progress
and clear the stored reservation (`1308A8..1308F8`). The optional progress
callback follows these updates. Backend state 3 instead returns the whole
reservation and enters retry handling; other statuses retain it.

Consequently neither actual host bytes read nor GetNumTr may replace the
accepted prefix length. A short-success byte API would publish unwritten data.
SJ/error reentry can observe in-flight cleared while the old reservation still
exists; changing this order or surrounding the entire operation with a new
native mutex is not justified by these reads. See the separate
[SJUNI synchronization review](../native-sjuni/SYNCHRONIZATION_AND_ERRORS.md).

The [lifecycle service](../../recomp/config/output/sub_00130B78_0x130b78.cpp)
defers its stop/close/open work while in flight. Close clears the stream's file
field in the call delay slot before cvFs close. New opens use seek-end/tell/
seek-start to establish sector bounds, and subsequent servicing depends on the
stream's ownership byte. Borrowed backend handles and owned opens therefore
cannot share an invented uniform native-close policy.

### Seek, stop and host I/O are separate obligations

[DVCI seek](../../recomp/config/output/sub_00139C30_0x139c30.cpp) changes a
logical sector cursor, clamps it and clears completed count; it does not perform
an OS seek or cancel an outstanding request. An unrecognized origin still
clamps the previous cursor and clears completed count. Preserve word arithmetic
or reject unsupported values before mutation; do not substitute host `seek`.

[DVCI stop](../../recomp/config/output/sub_00139EA8_0x139ea8.cpp) can request
SRD break, pump the shared server and DVCI service, and poll status up to an
iteration cap. Break is a request flag, not proof of an aborted native read.
After the stop loop it clears state/completed count; a cap exit does not itself
prove request-token destruction. [Close](../../recomp/config/output/sub_00139BD8_0x139bd8.cpp)
can invoke this stop path before clearing its record. Native session close
instead invalidates future handles while already accepted reads retain their
provider and may finish. Native drain waits for reads; it does not pump original
callbacks. Neither method is an implementation of the original stop/close.

HTCI is excluded from the first domain. Its
[request](../../recomp/config/output/sub_0013B910_0x13b910.cpp) uses a host-byte
budget and shared SRD admission; its
[padding helper](../../recomp/config/output/sub_0013B0B0_0x13b0b0.cpp) explicitly
zeroes the accepted sector span beyond declared file length. Its synchronous
completed count uses accepted sectors, unlike DVCI's original-request store.
Its close also distinguishes borrowed/cached host descriptors. A shared cvFs
wrapper does not establish the same provider contract.

## Concrete first integration domain

Use the existing native [VirtualFileView](../../game/native/resources/virtual_file_view.hpp),
[owned subrange view](../../game/native/resources/bounded_view.hpp) and
[ResourceSession](../../game/native/resources/resource_session.hpp). Keep the
existing AFS parser and virtual layout; do not resolve a replacement archive
using original-file offsets. The proposed owner mounts one verified edition/
content/layout snapshot and retains it through all accepted work.

Admission for the first candidate requires all of the following:

1. The original File #1 disc route and expected request/callback shape are
   verified. The cvFs object uses the DVCI table; no host/custom device is assumed
   equivalent merely because it reaches the same wrapper.
2. Existing CDVD/overlay lookup resolves the entire LBA range to exactly one
   retained native view. The translation establishes `offset = sectorDelta *
   2048` with checked arithmetic and coherent replacement-aware layout identity.
   No physical ISO/raw-volume request, cross-file range or unknown synthetic-LBA
   padding area is admitted by the first candidate.
3. Count is positive, representable in both original and native domains, and
   `count * 2048` fits the configured native read limit, the verified writable
   guest target and the view's **actual byte extent**. No rounded EOF or read-ahead
   padding is inferred from the native size. Requests crossing a partial final
   sector remain on the existing route.
4. The owner provides immutable backing bytes and retains the session/view and
   writable target until the existing completion path releases ownership. A
   native provider lease alone does not retain guest memory or the SJ reservation.

For an admitted request, replace only the payload read in the existing host
worker/service with `read_exact(handle, offset, target)`. Publish the returned
bytes before invoking the original callback, through the existing execution/
memory synchronization. Do not write DVCI state, SRD terminal status, cursor,
counts or SJ queues from this provider. Preserve the worker's original callback
and service ordering. This advances native resource ownership without claiming
that the console request protocol has disappeared.

Before admission, a declined request has no guest mutation or completion side
effects and follows the existing path. A native read failure is a separate
decision: transactional staging leaves the target unchanged, which can permit
the existing read path to run in the *same* request before completion, provided
the owner has proved provider immutability and absence of observable retry side
effects. It must not issue a second completion or claim backend state 3 from a
native typed error without original failure-contract evidence. Initially retain
the original path for such failures; do not call fallback after native output or
completion has already been published.

## Gates before enabling that candidate

| Gate | Required evidence or implementation boundary |
| --- | --- |
| Stable mount identity | Bind executable/edition, cached content and replacement-aware LBA/view translation; enforce backing-file lifetime/immutability. Current size checks do not prove content immutability. |
| Destination and shutdown ownership | Prove borrowed guest target remains valid through pending worker completion, stop, close and runtime shutdown. The current detached worker stores raw RAM/runtime pointers; ResourceSession leases do not settle this. |
| Completion/error propagation | Trace the underlying CD error result and original SRD terminal publication. Current `reo_cd_async::complete` logs a false read result but still calls the original completion callback; it supplies no direct mapping from native typed errors to DVCI error state. |
| Exact visibility/order | Demonstrate payload is visible before the original callback and before `130800`'s next successful publication; retain its one-pass gap and callback/reentry observations. |
| EOF and padding admission | Existing PAK CDVD supplies a bounded zero-filled read-ahead area and can zero bytes before a later read failure. Native exact reads reject overrun and preserve output. Keep those requests on the original route until their policy is deliberately represented and compared. |
| Original request parity | Build independent original-word fixtures for request 0/busy/singleton occupied, positive/full/clamped acceptance, both sync modes, each terminal state, seek while pending, stop/cap/reentry, close and CRI prefix/suffix ownership. Compare observable returns, fields, callbacks and destination bytes, not only final file contents. |

The [current CDVD sector implementation](../../runtime/cdvd/cdvd.cpp:205) and
[async completion adapter](../../recomp/overrides/reo_cd_async.h:64) are source
evidence for these gates, not proof of a controlled game test. Existing synthetic
range/sector comparisons validate byte-prefix/padding distinctions only. A later
fully native DVCI/SRD owner must close all request/status/stop and consumer gates
above; until then the next complete native unit is the retained, bounded payload
provider under the original request owner.
