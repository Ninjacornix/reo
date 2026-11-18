# Prepared finite audio: resident refill qualification

Prepared finite audio now keeps an owned immutable encoded copy and refills from
that copy on the native control worker. This removes subsequent file/read-worker
completion waits for those admitted sources. It does not prove what physically
caused the V37 pending reads, guarantee scheduling or page residency, or establish
that a game retest is free of audible stutters. Step 3 still requires the separate
coherent candidate and actual game/A/V checks.

The [resident resource/loader qualification](NATIVE_AUDIO_RESIDENT_ASSETS.md)
covers cache identity, concurrent loading, preparation failures and the verified
File #1 asset-size inventory. The
[V37 incident](NATIVE_AUDIO_V37_INPUT_INCIDENT.md) and
[capture chronology](NATIVE_MEDIA_V37_AV_CHRONOLOGY.md) retain the original
measured stalls and their unresolved attribution.

`resources::retain_resident_view` is lazy: construction performs no body I/O. Its
first read copies the entire bounded original asset before publishing readiness.
The native loader prepares that view before exposing queued clip metadata;
ordinary sources wrap their admitted canonical asset view before the first
asynchronous header read. Per-view admission is 32 MiB with a 2 GiB live reservation
budget. Failures remain failures; partially loaded data never becomes ready.

The refill backend probes a private capability. Only a ready resource-owned
resident implementation, including slices through the known bounded wrapper,
qualifies. Arbitrary `ByteView` implementations retain asynchronous execution.
After readiness, submission copies bounded memory on the native control worker,
never the real-time output callback. There is still one accepted request, the same
request ID, one completion transfer, the original source ring publication and the
normal stop/drain/join fence. An already accepted asynchronous operation cannot be
overtaken by a later resident request. No guest reads, synthetic clock, decoder,
sample-rate or original game speed change is introduced by this backend.

The focused verifier compiles sealed copies of the actual production refill,
resource and asynchronous worker sources. Both LLVM and GCC pass the existing
refill suite plus the new checks (133,418 assertions in each final run):

- A gated first read remains asynchronous and unready until the complete original
  16 KiB body has been copied, even when requested through a smaller slice.
- The original provider is then armed to sleep 2.5 seconds and fail if called.
  A real asynchronous read of that untrusted provider demonstrably blocks while
  32 prepared requests return immediate, exact memory payloads without calling it.
- Pending-slot refusal, exact IDs, one-shot completion, asynchronous-to-resident
  transition, overflow/range/budget rejection and shutdown-before-drain refusal
  retain their existing contracts.
- An actual `EncodedSource` close drains its accepted resident result through
  normal ring publication before source retirement and join.

The injected 2.5-second provider block is a controlled component check, not a
reproduction of the unexplained operating-system/resource delay in the V37 game
capture. The full native-core tests and strict ordinary-adapter regressions are
separately bound in `native_resident_refill_qualification.json`; its receipts
identify exact sources, compiler binaries, all linked archives and retained logs.

Final focused receipts are
`build-native-sjuni/refill-resident-results-{llvm,gcc}-v2/receipt.json`.
Complete native-core receipts are
`build-native-sjuni/media-resident-audio-results-{llvm,gcc}-v1/receipt.json`,
using `native_resident_audio_manifest_v1.json` with no source exclusions.

Both fresh complete native-core builds pass **80/80 suites**. The matching strict
ordinary-adapter regressions also pass **34 positive scenarios and 10 deliberately
introduced, detected adapter faults per compiler** (55 checks including builds).
They link all 68 freshly verified archives, exclude none and permit no source
drift. The actual immutable File #1 import's manifest and file identities remain
unchanged. These ordinary fixtures use real imported audio and native workers
with declared game-runtime/factory ports; they do not execute the original game
bodies, acquire the production game runtime or open a physical output device.
Their receipts are
`build-native-sjuni/adxt-binding/ordinary-resident-audio-regression-{llvm,gcc}-v1/receipt.json`.
LLVM receipt SHA256 is
`d0deb8de334b178d40123acc65bf3616bad83ec435fbd2bcfcb1c51849364518`;
GCC is `936d15e4e3377ce018a3e7159eaee9562925023782b9668263e513599ae20728`.

The earlier focused v1 folders are retained. They failed at a new fixture assertion
that incorrectly expected `begin_shutdown()` to request source-view close. The
fixture now invokes the existing explicit `request_close()` operation before
asserting retirement. The production refill implementation did not change for
that correction. Those v1 builds used the mutable source tree while the resource
implementation was being finalized; retained metadata records the initial and
final resource hashes without claiming its exact compiler read-time version.
Final focused v2 builds use sealed source snapshots and verify source hashes again
afterward. Full native-core cohorts verify all manifest inputs before and after.

Owned immutable memory is not physically pinned memory. Allocation, page faults,
native owner contention, output scheduling and the first whole-asset preparation
remain possible delay sources. A cold first gallery playback must verify that
audio readiness and the first displayed movie frame still align; successful warm
replay alone cannot establish that. The prior historical stutters remain measured
incidents, not automatically proven fixed causes.
