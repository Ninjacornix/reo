# Window2 lifecycle and PCM boundary original replay

Status: original-word evidence, 2026-11-06. **No native Window2 implementation,
composed parity, game run or speedup is established by this corpus.** It closes
the new-input gate in [the composition contract](ADX_SHARED_WINDOW_CONTRACT.md).

## Authority and method

The owned File1 ELF remains authoritative, SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The unchanged EE/FP instruction engines execute 163 owned function bodies.
The current public generated companions are audited against the ELF: 5,664
matching instruction comments and 82 omitted zero words. There is no dependency
on a private candidate's old generated-source directory for this audit.

The [new oracle](../../tools/native_reconstruction/adx_window_v2_oracle.py)
freezes inputs before replay. It reuses the historical 39 authored clients with
an explicitly different source entry, complete `130B78 -> 130800`. It adds
90 partial-final PCM cases across mono/stereo/downmix, totals1/17/31/33/65 and
free byte counts2/30/32/62/64/96, plus four asymmetric stereo probes. No native
output, supplied consumer count, loop teleport or substitute decoder determines
the original's results.

The GCC15.2 worker and actual bundled UCRT LLVM21.1.8 worker retain their prior
qualification, executable and compiler identities. The oracle verifies their
emitted FP instructions, runtime macro and conversion source against current
inputs. The old conversion header used LF; the final127 SDK has identical C++
text with CRLF. Both raw hashes are retained; only CRLF-to-LF source translation
is compared. Numeric results and instruction transcripts are never normalized.
These are generated-runtime FP observations, without a PS2 hardware FP claim.

## Results and preserved earlier cohorts

Both full normal-service runs execute **133 clients /6,801,810 original
instructions**. Every per-client transcript hash agrees across compilers.
129 clients return; four remain explicit partials: negative end-record length
(`126688`, unmapped synthetic extent), unqualified math (`120AE8`), null file
(`1307B4`, unmapped `+2C`) and insufficient-channel diagnostic (`1282A0`).
They are not successful comparisons or candidates for automatic fallback.

All three long streams reach decoded/position40,017 and outer/source state3:
mono44.1k, stereo48k and downmix24k. Their counters progress through actual
decode, consumer, provider and lifecycle actions. Full loop requests, pending
producer/two-grant seamless handling, explicit provider errors and stop/target
mutations remain in the corpus.

The first lifecycle cohort (`frozen-v2`, `gcc-v1`, `llvm-v1`) is preserved, with
4,347,511 instructions per compiler. Its inherited raw-refill status script's
second poll3 injects an I/O error when a zero-sector submit accepts nothing.
The complete service stops after source state4; long mono stops at14,368,
stereo39,936 and downmix7,168. The old raw-refill caller continued invoking
`130800` even after terminal state. Neither observation was relabeled.

For `frozen-v3`, ordinary source actions explicitly use second-poll status2
instead. First-poll3 remains an authored error. The new stimuli were frozen
before replay; no original algorithm, old expected file, or runtime/native
implementation was changed to force a match. The preceding `frozen-v1` raw
header-hash refusal is also retained, including its exact former oracle source.

## PCM ownership findings

| Prepared original case | Measured observation | Native composition implication |
| --- | --- | --- |
| All60 cases with fewer than64 free bytes | No predictor call or PCM backing changes; rings unchanged. | Preserve backpressure, including partial final totals. |
| Mono total17/free64 | One full block is written, but only34 bytes are published;30 free bytes remain. | Raw output and logical publication are distinct. |
| Stereo total33/free96 | Two complete stereo groups are requested, with128 raw output bytes per plane. Actual changed bytes extend into the physical extension. Only66 bytes per plane are published;30 free bytes remain. No queued main-prefix bytes change. | A blanket `raw_bytes <= grant` restriction rejects this useful case. Own the extension explicitly, preserve unpublished padding, and do not invent logical credit. |
| Asymmetric stereo free64/32 | The right raw output starts at the first channel's offset16,320, changing bytes16,320..16,351 that were queued in the right plane. The original returns without an error callback. | Reject asymmetric grants/cursors before effects. Taking the minimum grant would silently change the original. This synthetic shape is not evidence of an actual-game bug or stutter cause. |

Backing deltas identify **changed** bytes, not all stores; unchanged writes are
not inferred from the delta. Raw block sizes follow actual kernel entry counts
and the separately verified scalar store contract. Guard extents and complete
transcripts are retained for later whole-owner comparisons.

A native physical ownership check must cover raw stores, the decoder's explicit
wrap copy using corrected produced samples, and the Ring's publication mirror
copies. It must protect queued main bytes, queued data whose current read spans
the physical extension, and every outstanding read lease's actual physical span.
Protecting every queued prefix's mirror unconditionally would incorrectly reject
the safe total33/free96 case: that queued prefix is read at the main beginning,
not through the extension. Storage lifetime alone does not grant write credit.

## Reproduction and identities

Artifacts are local under `build-native-sjuni/adx-window-v2-oracle/`.

| Artifact | SHA-256 |
| --- | --- |
| Frozen-v3 oracle source | `c9f9f4c7c6338b461eea659b26120d7e1bef048d57937e74dd74030092121797` |
| Frozen-v3 inputs | `5544af1932b0362a9cbca0a64acd4cf2db9b87200e2f097d4edd0beb8ad3488b` |
| Frozen-v3 input manifest | `c28d49395aa089b63843e11d925ec5be86204022100efb4bdd79bd3e4ddb6c5e` |
| Normal GCC manifest (`gcc-v2`) | `f3a8c7527d7a36420e269b989232487bd9e649a8f34ce43d58da20d4a8aef78b` |
| Normal bundled LLVM manifest (`llvm-v2`) | `76261fc897ba050f94ce06d959bbda95d8176ec405cdca7007422de9ab8e1d9f` |
| Earlier injected-error GCC manifest (`gcc-v1`) | `f968dd02bb71f5b215f0021dcd1ba3906783cb0d25d8f57346ee8313c7d019b2` |
| Earlier injected-error LLVM manifest (`llvm-v1`) | `1414c3da6ce3bc9e9009c1b84ea8dab7dcf5633c72c43b2ccdbe1551a489aac5` |

`python -m unittest discover -s tools/native_reconstruction -p test_adx_window_v2_oracle.py -v`
passes eight authority/transcript/lifecycle/physical-effect checks. They verify
the completed replay artifacts, not a native implementation. Full replays use
the oracle's `--frozen .../frozen-v3 --compiler gcc|llvm --output <fresh-dir>`.
The runner requires fresh scoped output and preserves existing cohorts.

Next: implement and qualify native physical PCM ownership, then the composed
Source2/header/loop/workspace owner. Native RNA/DTR/device credits, estimated
clock ownership, LSC and the full player still remain stage3 work.
