# Optional DVCI scalar runtime adapter

Status: isolated adapter/core tests and real-header compilation pass. Root
build/override wiring uses a separate default-OFF REO_BUILD_NATIVE_DISC_STREAM
option; a newly linked candidate and live-call proof are pending. Installation additionally requires
exactly REO_NATIVE_DISC_STREAM=1. File #2 compilation is refused.

Call install after final ELF and original function registration, before guest
execution, for one runtime/RAM/process lifetime. Like the SJUNI pilot, this has
no teardown/adoption API for runtime-address reuse or in-place ELF reload.
Repeated installation checks identity and wrapper bindings; changed bindings or
memory disable admission. Runtime environment changes are not live toggles.
REO_NATIVE_DISC_STREAM_TRACE=1 separately enables sampled body proof after
successful commit: first four calls and powers of two per operation, naming
operation and slot. Atomic counters saturate rather than wrap. It defaults off,
does not log fallbacks, and is fixed at installation for that process lifetime.

Only these entries are intercepted:

| Entry | Native scalar operation | Live guest fields |
| --- | --- | --- |
| 139C30 | Seek | Reads sector bound/cursor; writes completed +14=0 and cursor +0C |
| 139CC8 | Tell | Reads cursor +0C |
| 139FA8 | Status | Reads status byte +2 |
| 139FE8 | Transferred bytes | Reads status; reads completed +14 only when ready |

Request, update, open/close, stop, guards, diagnostics, SRD, callbacks and SJ
publication remain original. The independent
[core](../../../game/native/disc_stream/README.md) has no guest types or layout.
This temporary adapter imports only needed scalar fields afresh per call and
retains no FileState, request ID or borrowed payload reference.

## Identity and admission

Installation verifies exact hashes of all four bodies, DVCI free/open/clear/close
bodies and the DVCI vtable. Every original binding must exist before any wrapper
is registered; a nonnull default lookup is insufficient. Calls recheck their
own original-body hash and exact canonical entry PC.

First admission is deliberately quiescent: normal direct active 72-byte slot in
21CC60..21D7A0, known nonpending status, request pointer zero and global CD busy
word 207934 zero. Seek additionally requires idle/ready, finite nonnegative
sector metadata and an in-range nonnegative existing cursor. Pending/busy and
stale-request calls, including getters, remain original. These checks do not
construct a general request or SJ target lease; valid original protocol
serialization/stable data remain the admitted context.

Consumed arguments, SP and RA must have canonical lower64 representations of
their 32-bit values. Stack bounds/alignment and alias checks exclude the DVCI
pool, verified identity ranges and busy word. Returns into verified body/data
ranges are refused. Null, unsupported alias/raw enum, delay-slot and
noncanonical calls delegate to their individually captured original exactly
once, before adapter writes. Diagnostics are never translated through native
hooks. A runtime/RAM mismatch or stopped runtime also delegates.

Preparation computes entirely in native local values. Commit is separately
allocation-free/hook-free, with no fallback catcher around it. It writes the
same eight-byte RA save at caller SP-16, writes only the two seek fields when
applicable, sign-extends the defined v0 result and supplies the final JR PC/
branch_pc. SP, RA, callee-saved state and upper GPR halves are retained. Unused
caller-saved volatile clobbers are not manufactured; they are not a returned ABI
contract. Every other RAM byte remains unchanged.

## Repeatable checks

```powershell
python recomp/overrides/native_disc_stream/tests/run_checks.py --runtime-headers build-native-sjuni/dependency-workers-reapply-v2
```

GCC 15.2 and bundled LLVM C++20 -O1 -Wall -Wextra -Wpedantic -Werror:
eleven fresh-process scenarios
pass. They cover opt-out/identity/missing-binding refusal, partial registration,
all four operations, signed seek wrap/clamps, all-RAM selective-write snapshots,
complete modeled context preservation, canonical/alias/quiescence fallbacks,
slot clear/reuse, text/binding changes, another runtime/moved RAM and stop.
Trace checks require the expected 15 sampled records for 18 committed calls,
and no native records for disabled or fallback calls. Modeled context equality
compares every field and GPR half, excluding only unspecified C++ padding.
Fallback mocks assert unchanged RAM/context on entry and count exactly one call.
Compilation against the actual patched runtime headers also passes, without
linking its libraries. Its pre-existing unused-header warnings are excluded
only for that real-header object check.

Receipts: build-native-sjuni/disc-stream-adapter-checks/receipt-gcc.json and
receipt-llvm.json. The LLVM run prepends its toolchain bin to the child process
PATH for its matching runtime DLLs; no machine environment is changed. Owned ELF
bytes are read locally into an ignored identity fixture; no instruction arrays
are distributed in tests. The scalar core's separate original-word comparison
covers 178 calls/159 returns/142 hooks/462 snapshots.

Mocks establish adapter selection, writes and ABI policy. They do not execute
original methods, a real runtime, game or device. Mid-game request ownership,
stop/close/cap/reuse, payload/copyback lifetime and callback reentry remain gates
in [the owner review](../../../docs/native-resources/DVCI_OWNER_BOUNDARY.md).
