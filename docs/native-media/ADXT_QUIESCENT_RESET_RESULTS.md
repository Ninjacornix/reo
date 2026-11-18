# Native source reset ownership results

The canonical source reset boundary is implemented and checked; original guest
reset/destruction hooks and whole-game return-to-title/restart validation remain
open. Step 3 is not complete, and no sleep action has run.

Both LLVM and GCC pass all **77 standalone native suites** with the new scoped
empty-owner proof. The controller tests check idle constructed handles, a real
blocked source after its output fence, actual joined destruction, wrong submix,
wrong thread, nested admission/join refusal, later creation serialized behind
reset, and stop/closed admission. Deliberate removal of the constructed-instance
check and of the thread/scope check is detected with both compilers.

Aggregate4 has a distinct namespace/ABI. Its derivation verifies and preserves
the frozen Aggregate3 bodies and shared port types, adding only the scoped
`reset_native` entry. Both compilers pass the 15 retained aggregate scenarios
plus two reset scenarios. The new scenarios cover refused foreign/null proofs,
an occupied source, post-epoch refusal through the unqualified old API, a later
qualified reset after real destruction, fresh native source playback afterward,
and reset while an accepted outer audio callback is paused between raw mixing
and native submix rendering. Banks and the one output provider remain active;
callback allocation/free checks still pass. A deliberately accepted foreign
proof is detected before it can qualify the implementation. Production SDK130
objects compile for the aggregate and factory with both compilers.

The complete factory now selects Aggregate4 for its explicit native-source
entry. Its 14 protocol scenarios include the same reset ordering through the
actual factory and SDK facade: initial cold reset, refusal with an idle handle,
refusal after output fencing while its source worker is still blocked, success
after the actual join, and a newly playable source on the same owner/device.
The read-only actual voice-order capability still passes its existing checks.
The legacy original-source entry keeps its prior backend/reset route.

The native-source game adapter is still unbound; the ordinary bootstrap still
selects the earlier original-source route. Protocol acquisition/device ports
remain declared fixtures. No game or audio device was launched for these checks.
No live stutter fix, original gameplay PCM parity, general error-profile parity
or native movie scheduling is claimed.

The V1 native archive build and V2/V3 runtime qualification manifests separate
unchanged native libraries from separately rebuilt factory fixtures. The
qualification tools permit only an explicit factory/fixture input allowlist
when reusing those libraries; every archive body, header and contract must still
match. Frozen prior files and receipts remain unchanged. See the
[contract](ADXT_QUIESCENT_RESET_CONTRACT.md) and
[qualification](../../tools/native_reconstruction/adxt_quiescent_reset_qualification.json)
for exact inputs and evidence.
