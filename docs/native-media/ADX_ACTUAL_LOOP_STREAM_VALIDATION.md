# Actual owned ADX loop-cycle validation

Status: offline connected corrected-owner loop checks completed, 2026-11-06.
No game or audio device was opened. Actual player/output-credit/LSC integration
remains open in stage3.

The [loop harness](../../tools/native_reconstruction/adx_loop_asset_stream_check.cpp)
uses the actual retained AFS/source/decoder/PCM graph from the
[non-looping run](ADX_ACTUAL_ASSET_STREAM_VALIDATION.md), selecting only the
[corrected enable predicate](ADX_READY_FLAG_IMPLEMENTATION.md). It enables file
looping, keeps the original-sized requests, drains actual PCM read leases, and
stops only after the owner reports its second repeat transition. It never
supplies a provider result or substitutes a worker join.

Both GCC15.2 and bundled UCRT LLVM21.1.8 pass:

- All **89 loop-bearing references** bind to actual member ranges in7 immediate
  archives; **80 distinct payloads** execute the full loop test.
- Every tested channel completes two full loop cycles with exactly the parsed
  loop-span sample count and equal per-cycle byte digests. Intro audio is
  separate from those cycle observations.
- Complete cycles total **962,466,636 channel samples** /
  **1,924,933,272 PCM bytes** per compiler. These are decoded outputs, not
  samples audibly presented.
- Each owner stops, drains its emitted PCM, and observes the real provider join.
- All cycle/source/geometry/fence observations match between compilers. The
  comparison checks every field except two explicitly retained full-stream
  stop-prefix observations, as described below.

This includes the previously excluded count0/enable1 assets which exposed the
ready-predicate defect. The48 independent original flag/count clients and prior
whole-owner regression are separate evidence for that correction; this actual
asset run is not a new full original-gameplay PCM comparison.

## Timing-dependent stop prefix

The service call which reports repeat iteration2 can also decode a prefix of
the following cycle. Its size depends on the accepted source bytes available
on that call. The harness drains that real accepted output before stopping.
Consequently full-stream sample totals and full-stream digests differ on18
reference rows between the two compiler runs. Those raw values are preserved
in both result files and copied into the comparison receipt; they are not
normalized into whole-run equality.

GCC emitted1,057,989,772 channel samples including intro/following prefix; LLVM
emitted1,057,943,628. Both observed the same two complete-cycle samples/digests.
The [comparison tool](../../tools/native_reconstruction/compare_adx_loop_runs.py)
validates input/source identities, successful raw receipts, each cycle's extent
and digest equality, and compares every other result field. Its only exclusions
are`samples` and`byte_digest` for those complete-stream observations. It
explicitly records`full_run_byte_equality=false`.

The64-bit rolling digests are noncryptographic. They provide repeat and compiler
consistency observations, not full-byte original-output or audible-playback
equivalence. No stutter or game-performance conclusion follows from this run.

## Reproduction and identities

The [driver](../../tools/native_reconstruction/verify_adx_loop_asset_streams.py)
verifies the full owned ISO SHA-256, actual archive metadata, exact corrected
source/dependency freezes and compiler. It records inputs, binary, per-asset
results and compile/run logs; checks source hashes and ISO size/write-time
afterward. It is a read-only validation fixture, not a production file provider.

| Receipt under`build-native-sjuni/adx-loop-asset-streams` | SHA-256 |
| --- | --- |
| `probe-gcc-v1/receipt.json` | `8509ef29bd64252c4769b5587e1aa0a25f495c9b0fa98892d7c420d3261efe1e` |
| `full-gcc-v1/receipt.json` | `19758393bffa884b8c92400edf57c952709ce0391db4baa0feffc118092f5610` |
| `full-llvm-v1/receipt.json` | `6ce657f31ea504f8fb0db2d8dc6a8f50d725f0b1b0d2fe98f26fb01013bb400e` |
| `comparison-v1/receipt.json` | `9a18376b7f8101c7ecaabd526583538394ed17356ed1b636843bb14fafd189db` |

Together with the non-looping run, every identified distinct ADX payload now
has either finite completion or this repeated-cycle coverage. That does not
close program-stream demux, native player controls, actual output consumption,
LSC transitions, or the remaining stage3 integration gates.
