# DVCI owner boundary after the scalar core

2026-11-05. Static review only; no game, runtime, build or target process was
run for this review. This extends the [request boundary](CVFS_REQUEST_BOUNDARY.md)
using the [native scalar core](../../game/native/disc_stream/README.md), its
[independent oracle](DVCI_ORACLE.md), actual stream lifecycle callers and the
current [CD worker pilot](../../recomp/overrides/native_cd_owner/README.md).

**The next complete replacement cut is four per-call scalar entries: seek,
tell, status and transferred bytes.** Import only their needed fields from an
admitted live DVCI slot, invoke the native core, and selectively publish the
original writes. Retain guest wire state as authority; do not create a durable
native DVCI owner yet. Keep request/update, SRD, service, stop/close, disc callback
and SJ publication on their existing paths.

The scalar fixture match proves the declared preserving/no-reentry arithmetic
domain. It does not admit forwarding arbitrary real SRD/guard/device calls
through native request/update hooks. A real wait can run shared services or
allow another guest thread/callback to progress; retaining a local FileState
through it needs an additional exclusivity/reentry contract.

## Ownership facts that prevent a larger cut

| Source / exact PCs | Consequence |
| --- | --- |
| [Open](../../recomp/config/output/sub_00139A50_0x139a50.cpp), `139B80..139BA4`; [free-slot lookup](../../recomp/config/output/sub_001399F8_0x1399f8.cpp) | Forty 72-byte DVCI records at `21CC60`. Open sets active byte, size/sector/cursor/count/request fields; lookup chooses the last inactive slot. The same address can denote a later open. No generation is stored here. |
| [Close](../../recomp/config/output/sub_00139BD8_0x139bd8.cpp), `139BEC..139C18`; [clear](../../recomp/config/output/sub_00139A30_0x139a30.cpp) | State below 2 skips stop. Otherwise stop runs first, then close clears all 72 bytes. Active/cleared state alone does not certify an independent host worker has stopped writing its target. |
| [Stop](../../recomp/config/output/sub_00139EA8_0x139ea8.cpp), `139F10..139F80` | Break sets a request flag, then stop pumps shared server/DVCI service until no longer pending or an iteration cap is exceeded. It clears completed/state after the loop. The cap path does not itself destroy/clear the request pointer. |
| [SRD break](../../recomp/config/output/sub_00137868_0x137868.cpp), `1378A0..1378A8` | Writes request `+4=1`; this is not host-I/O cancellation or acknowledgement that the destination is no longer borrowed. |
| [DVCI service](../../recomp/config/output/sub_00139798_0x139798.cpp), `1397D0..1397EC` | Scans active slots and calls update. Original [update](../../recomp/config/output/sub_001396D0_0x1396d0.cpp) consumes the SRD result, destroys terminal requests and clears their pointer. A worker finishing its payload/callback is a different transition. |
| [Stream stop](../../recomp/config/output/sub_001306E0_0x1306e0.cpp), `1306F4..130728` | Reading+inflight sets stop flag `+44` and may clear service request `+43`. It does not immediately return the reserved span or cancel host I/O. |
| [Synchronous stream stop](../../recomp/config/output/sub_00130748_0x130748.cpp), `130768..130780` | Pumps `12A020` until stream state is 1 **and reserved pointer `+20` is zero**. State alone is insufficient. There is no deadline here. |
| [Stream close wait](../../recomp/config/output/sub_00130560_0x130560.cpp); [destroy](../../recomp/config/output/sub_00130420_0x130420.cpp) | Wait-stop precedes close request. Close wait pumps until owned-open byte `+45` clears; only afterward does destroy clear the 92-byte stream. It does not destroy the borrowed SJ. |
| [Lifecycle service](../../recomp/config/output/sub_00130B78_0x130b78.cpp), `130B8C..130BD8` | Defers stop/close/open handling while inflight. The file field is cleared in the cvFs-close call delay slot, before backend close returns. Native persistent ownership cannot be inferred from that field remaining nonzero. |
| [Read service](../../recomp/config/output/sub_00130800_0x130800.cpp), `13084C..1308F8` | Successful later service clears inflight, puts accepted prefix in SJ pool 1, ungets suffix to pool 0, then clears reservation/progress fields. This publication, including callback/error reentry order, stays guest-owned. |
| [Reset/start](../../recomp/config/output/sub_00130620_0x130620.cpp), `130644..130654` | Clears inflight/reservation fields without returning a prior span. Its public use requires preceding stop/quiescence; the reset itself is not a cancellation primitive. |

If a stop cap were reached while an independent host read still existed, close
could clear the slot and lookup could reuse that address before the old read
finishes. This is a **conditional lifetime hazard**, not a claim that the player
reproduced it. Do not address it by inventing a generation check that silently
drops completion while returning an SJ span early: the actual payload write must
also cease or retain its old destination lease.

## The current native CD owner does not own a DVCI request

Its [Session/Request](../../recomp/overrides/native_cd_owner/runtime_adapter.cpp)
retains one runtime/RAM identity, LBA/count/destination/end-parameter/GP, callback
binding and private callback stack. Admission verifies the original sceCdRead
RPC shape and in-RAM sector destination. Runtime external-worker joining closes
runtime destruction ordering. It has no DVCI slot/generation, SRD identity,
stream identity, SJ span lease or mounted resource identity.

The internal return PC `101908` identifies sceCdRead's SifCallRpc site, not its
higher-level caller. Another sceCdRead caller can have the same RPC shape.
Consequently an admitted worker job does not prove that it belongs to a specific
DVCI slot or CRI stream. Its session stop is runtime stop, not mid-game stream
stop; do not route DVCI stop to Session::requestStop.

The original [read](../../recomp/config/output/sub_00101788_0x101788.cpp) stores
global command/copyback pointers and busy state before RPC (`1017F4..101900`).
Data-pattern byte 1 or 2 selects 2328/2340-byte sector arithmetic
(`101830..101864`). The narrowed worker now requires pattern byte zero before
admission, matching its 2048-byte reads; other patterns retain original HLE.
This does not establish the latter's nonstandard-format behavior or show that
normal gameplay selected such a pattern.

The [completion](../../recomp/config/output/sub_001004D8_0x1004d8.cpp) reads the
shared end-parameter block at callback time: two positive counts and target
pointers drive prefix/suffix copies before it tails to
[`100298`](../../recomp/config/output/sub_00100298_0x100298.cpp). That tail
updates status/busy words and may signal semaphores. Retaining the parameter
pointer is not a snapshot/lease of every target the callback may write. The
pilot now requires matching packet pointers, zero prefix/suffix copy counts and
payload disjointness from the shared 0x90-byte callback block. It rechecks the
two counts under guest execution before callback dispatch, diagnosing an
unexpected change without retry or invented success. Thus admitted unchanged
metadata takes neither copy loop. Nonzero edge-copy targets remain original
HLE responsibilities; their general target-span lifetime is not reconstructed.
Original protocol serialization and callback metadata remain necessary.

These pilot changes close the specific non-2048/edge-copy admission gaps in the
earlier source snapshot. The registry also uses a short mutex around shared
session ownership for the bundled libc++ implementation. None of these changes
adds DVCI/SRD/CRI provenance, cancellation or a mid-game SJ target lease.

## Concrete admission for the four-entry adapter

Bind the exact File #1 body identities and installed/runtime/RAM identity before
guest execution. On each call, admit a canonical active slot in
`[21CC60,21D7A0)` aligned to 72 bytes. Reject unsupported register encodings,
aliases/raw enum values and unstable/unowned ranges before mutation, delegating
the original entry exactly once. Null calls also remain original so their real
diagnostic/error-hook behavior is preserved.

- Tell reads only cursor `+0C`. Status reads the admitted signed status byte `+2`.
  Transferred reads status and, only when ready, completed count `+14`.
- First seek admission can require request `+1C=0` and status idle/ready, with
  finite sector/cursor metadata. It reads `+8/+0C` and writes exactly cursor
  `+0C` and completed `+14`. Pending seeks remain original until their interleave
  contract is deliberately admitted. Preserve invalid-origin clamping and word
  wrap; do not replace them with host seek semantics.
- Operate under the existing guest execution ownership, import afresh every
  call and retain no FileState after return. Guest slot clear/reuse therefore
  cannot revive a stale native shadow. Any host payload/control-range aliasing
  must be excluded or otherwise serialized; a guest lock alone does not lock
  host payload I/O performed outside that lock.

This replaces complete scalar entry contracts while leaving the payload and
request owner intact. It is not a native open/close/file lifetime implementation.

## Gates for request/update after that cut

1. Establish a request token linking runtime session, DVCI slot incarnation,
   SRD admission and (where applicable) the exact CRI reservation. A raw pointer,
   LBA or worker-queue position is insufficient. Check every real producer,
   including borrowed file handles and direct device callers.
2. Extend owned-word fixtures through real break/stop/cap/close/reopen and stream
   stop/wait/reset/publication. Model controlled callback reentry and suspension
   boundaries, not just preserving hooks.
3. Specify when an accepted target and copyback metadata can be reused. Native
   source leases preserve providers; they do not preserve SJ nodes or guest
   target spans. Completion failure/missing continuation cannot be treated as
   successful reservation release.
4. Preserve SRD singleton admission, backend service gate, shared server progress,
   requested-versus-accepted counters and original callback/error policy. Avoid
   holding a new native mutex across original service or callback code.
5. Only then replace real request/update hooks or move publication into a native
   owner. Payload read success alone must never set DVCI ready or free an SJ span.

## Static verification scope

Owned ELF SHA-256:
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Fresh whole-body word audit covers 25 reviewed bodies: **1,074 instruction
comments plus 35 omitted zero words, zero conflicts/nonzero omissions**.
Starts: `139BD8 139EA8 139A30 139798 1399F8 139A50 130420 1304E8 130520
130560 130620 130658 1306E0 130748 130B78 137868 1004D8 100298 135EF0 137640
137610 101788 137738 1396D0 130800`. Prior scalar/core test results are referenced
from their reports; no tests were rerun for this static investigation.
