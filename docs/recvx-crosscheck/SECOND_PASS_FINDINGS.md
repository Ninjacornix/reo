# Code Veronica cross-check: corrections and missed evidence

This is the preceding170-entry pass. The subsequent
[completed available-source audit](COMPLETE_SCOPE_REPORT.md) extends coverage
to620 curated main-image comparisons and complete per-definition scope ledgers.

Static investigation, 2026-11-05. This extends the earlier 72-entry comparison
using the clean Code Veronica decompilation at
`657b0c0c9489943116c71f151804ad7304fca975`, current Outbreak notes and original
owned File #1 instructions. The engine review also inspects the enhanced port
at its separately recorded revision `2fa8a14224ebb92d0103a8c828e6a032c338d6d4`.
No game, build, playback, target process, debugger attachment or native
replacement was run.

**The comparison found real mistakes in our documentation and additional shared
middleware evidence.** Authoritative mapping rows and their supporting notes
were corrected; the reference game's code was not imported as an implementation.

## Corrections

| Finding | Correction and evidence |
| --- | --- |
| ADX loop-parser field offset | Our final-field location was four bytes too far ahead. Following every pointer advance in the original126AC8 instructions places the last field at loop-base+0x14, agreeing with the writer and the reference parser. See the explicit trace in [audio review](AUDIO_SECOND_PASS.md). |
| Decoder stop/reset state | We had described the words cleared through125248/135020 as pending work. Their connected layout and consumers identify predictor histories at0x28..0x2F. The corrected [audio review](AUDIO_SECOND_PASS.md) distinguishes that history reset from request pointers, key state and worker completion. |
| CVFS callback argument | We had said136578's method44 received the original filename. The actual call has no argument reload after a helper that can change argument registers. The fixed note makes no guaranteed inherited-argument claim; the CVX private file-count helper also makes a no-explicit-argument callback. See [filesystem review](FILESYSTEM_SECOND_PASS.md). |
| Remote audio command8 | The generic auxiliary-state description missed a concrete mode. The owned IOP handler and its service path establish a thru/drain request that returns queued spans to free pools. The CVX SETTHRU/flag terminology supplies corroborating naming evidence, not the sole proof. Exact channel/queue and completion limits are retained in [audio review](AUDIO_SECOND_PASS.md). |
| Byte-size notation | Stream notes mixed hexadecimal literals with decimal-looking byte prose. Explicit values are now SJUNI 48 bytes (0x30), Outbreak SJRB 64 (0x40), DTX 68 (0x44), DTX create request 16 (0x10), and footer 64 (0x40). The actual immediate instructions are checked in [stream review](STREAM_SECOND_PASS.md). |

The filesystem pass also makes existing Close cleanup, transfer-count units,
archive stream ownership and sector-size refresh conditions precise. Those
clarifications preserve original behavior, including documented invalid-input
and returning-diagnostic paths; they do not silently replace it with a safer
reference implementation.

## Previously missed evidence and naming refinements

- CVFS136578's complete legacy scan corresponds to the private CVX `getNumFiles`
  helper. Its qualified legacy file-count candidate retains the newer optional
  selector4 provider/ABI/result-unit gap and absence of CVX NULL aggregation.
- The earlier `cvFsExecServer` and `cvFsLoadDirInfo` leads were checked against
  complete original bodies and adopted as candidate names on existing rows.
- Both SJUNI and ring interface UUIDs match all sixteen original bytes exactly.
  The older comparison had left this unverified. Ring layouts, pool dimensions,
  counters and callback offsets still differ across these library versions.
- The fixed-width AINF text and leading-padding-sample interpretations are
  checked through source, original producer/parser paths and caller layers;
  shared source does not establish a title/author schema or a validated string.
- The crosswalk now includes further library lifecycle, size, provider and
  audio-control comparisons. [Its generated totals](CROSSWALK.md) distinguish
  supported roles, qualified naming candidates, version differences and
  concept-only matches. Added comparison rows are not automatically new mapped
  Outbreak functions.

## Engine findings and boundaries

The [engine review](ENGINE_SECOND_PASS.md) supports several ordinary math roles,
while identifying different argument order, fallback behavior, memory overlap,
vector W handling and numerical instruction order. CVX lookup trigonometry,
actor-motion layers and byte-opcode event scheduling do not supply Outbreak's
polynomial trig, floating sampler ABI or24-bit script-dispatch contract.
No original Ninja engine symbol was assigned to Outbreak on this evidence.

The inspected enhanced port retains game-specific VU/GS/VIF/DMA behavior and
comparison paths. Its Outbreak importer targets File #2 and converts assets to
CVX structures, including different skinning. This is useful adapter/reference
design evidence; it does not establish interchangeable File #1 actor, model,
animation or rendering layouts. No engine-side canonical mapping mistake was
demonstrated in the twelve complete Outbreak bodies checked in that scope.

## Validation and remaining scope

Each detailed report records source revisions, hashes, original instruction
locations, helper commands and remaining uncertainty. [Provenance](provenance.json)
and [crosswalk data](review.json) can be regenerated with the existing offline
refresh tool. The central annotation index is reconciled after the corrections.

This is a bounded comparison of the listed shared-library and engine cases.
Lexical screening of 228 reference C files does not mean all their functions,
all current Outbreak annotations, or all network/movie/platform code were
semantically cross-checked. A supported role is not an equivalence proof, and
no runtime correctness or slowdown improvement was measured. Unavailable
providers, conditional callbacks and documented version differences remain
explicit research boundaries.
