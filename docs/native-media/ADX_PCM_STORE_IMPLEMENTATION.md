# Window2 PCM storage implementation and qualification

Status: independent native storage core qualified, 2026-11-06. **Window2 remains
unimplemented; no game integration or performance fix is claimed.**

[The contract](ADX_PCM_STORE_CONTRACT.md) preceded the new
[`adx_pcm_store` implementation](../../game/native/adx_pcm_store/pcm_store.hpp).
It owns real SJRB storage, explicit all-channel producer/read leases, fixed
staging and physical write checks. No CPU context, guest address, provider or
device API exists. Actual ordered Ring operations preserve raw padding,
corrected production and publication separately.

## Evidence

| Check | GCC15.2 and bundled UCRT LLVM21.1.8 |
| --- | --- |
| Native ownership checks | 3,574 pass per compiler; zero allocation attempts in guarded post-construction paths. Construction failure tested separately. |
| Cursor matrix | 64 cursor/queue combinations with actual held reads and drain. Queued bytes and held views remain unchanged. |
| Post-effect fault | Actual first-channel Put completes, then private source injection fails. First30-byte suffix and second96-byte producer stay held; first66 bytes remain published. Restore and retirement refuse. |
| Negative ignored error | Removing injected failure handling makes the fault test fail. Private mutant only. |
| ID exhaustion | Private constructor injection sets both counters to maximum; reserve/read refuse before Ring effects. |
| Original storage-only comparison | All90 symmetric partial-tail clients match complete backing bytes, callback payloads and eight Ring counters/positions per plane. |
| Negative padding truncation | Truncating raw stores to corrected production differs in21 clients per compiler, including stereo total33/free96. |
| Parent Release CMake builds | New target and selected test pass in both existing standalone builds. Parent now exposes31 suites; this is not migration percentage. |

Stop/drain, simultaneous producer/consumer ownership, wrap, stale/foreign/moved/
lost tokens, zero-byte leases, invalid extents, callback reentry, outliving storage
and retained publication views are covered. Destructors return no credit; fault
checks retain the partial ledger rather than asserting rollback.

The comparison is **storage-only**: decoded original PCM is supplied as input,
without revalidating the codec. Sixty backpressure clients perform no storage
operation, preserving the original caller's branch. This store does not decide
the decoder's minimum-free-block threshold. The other30 clients perform actual
reserve/write/publication/disposition. The projector only accepts shapes where
final backing preserves the raw PCM span; it never invents pre-store data.
Complete Window2 still needs original loop/codec/callback ordering and whole-state
comparisons.

No API permits asymmetric channel configuration or credit mutation. This prevents
the synthetic asymmetric overwrite at this boundary, without claiming equivalence
for arbitrary original asymmetric states. A refused write retains its existing
reservation for explicit validated restore. A partial disposition failure retains
remaining credit and faults the owner.

## Provenance and identities

The core followed the original PCM boundary observations and was frozen before
the new storage-only projection/comparator. Both facts are recorded. Original
expected results and frozen dependencies were unchanged. An initial unit assumed
one Get drained a wrapped queue; that test was corrected to drain bounded spans.
The production core needed no changes after its initial implementation for the
unit or original comparisons.

Freeze: `f4b7d300bac0318fc2a3879a9bc5160f1281cb426142fdcc4d332ae89a3199c0`.
Header: `f35df0c86868cb9252eb9be7959a775de1389db574483093a41d39a651375fe9`.
Implementation: `2ef48f108a1319794163ab2fc98000da44c48de061fc5299e46c508434ff6bfd`.

Artifacts under `build-native-sjuni/adx-pcm-store/`:

| Receipt | SHA-256 |
| --- | --- |
| GCC unit/fault (`gcc-v1/receipt.json`) | `536bf1de6b5e4f240a801b6b2a061f62ad781e88291f0e998a5cc6ae7c4cd0f8` |
| Bundled LLVM unit/fault (`llvm-v1/receipt.json`) | `7b28298ba5165617bfa080602e85456ebf2b8897a32dc4fa90f4275873ed839d` |
| Original projection (`original-v1/manifest.json`) | `e04d6d6dc08547f58f33ce6e41c512dbd8c83b1f0020e52b14af9a247731f131` |
| GCC storage comparison | `50f25580da9134cee332825d4f9c7c92f2131d01dae8195db2fa559dea8cd73f` |
| Bundled LLVM storage comparison | `a34882248d8b3c84c3ebf00e69ad06a784ebb42a9912e34b9c52fb83f7efdc2f` |
| GCC negative padding | `6254886c76bdaf6b613647f4438d53c5968d5bf9c1dd9a5738b7fdfe728572fb` |
| Bundled LLVM negative padding | `8ffc990f2cc3e2f333a1ad4e05039214393ef655bd17f04fcb10e617c50b0eea` |

Reproduce using `verify.py`, `original_projection.py` and `compare_original.py`
in the component directory; all require fresh scoped artifacts. The comparator's
`--negative-padding` must detect differences. The qualification manifest pins
source, tools, receipts and selected parent CTest results.

Next: composed Source2/header/loop/workspace/PCM owner and complete state/effect
comparisons. RNA/DTR credits, device completion, estimated-clock ownership, LSC
and full-player integration remain separate stage3 gates.
