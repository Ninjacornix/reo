# Actual owned ADX asset streaming validation

Status: offline connected native graph completed, 2026-11-06. No game process or
audio device was opened. This closes real non-looping asset/source/decode/drain
coverage; it does not complete the native ADXT player or stage3.

The [harness](../../tools/native_reconstruction/adx_asset_stream_check.cpp)
connects actual retained ISO bytes through the [AFS range binder](AFS_SOURCE_RANGE_IMPLEMENTATION.md),
unchanged real asynchronous backend, [Window2 owner](ADX_WINDOW_V2_IMPLEMENTATION.md),
native header/workspace, and phased PCM store. It copies PCM through actual read
leases, explicitly returns credit, stops decoding, and waits for the actual
provider join. It does not supply provider completion, codec output or a fence.

The [driver](../../tools/native_reconstruction/verify_adx_asset_streams.py)
first verifies the full owned ISO SHA-256, then records the exact compiler,
core/header identities, generated input plan and all observations. The ISO is
opened read-only. Its size/write-time remain unchanged afterward. That is not a
hostile concurrent-writer exclusion guarantee. Owned payloads are not extracted
or committed. The fixture's file reader is a serialized offline provider, not a
new production filesystem implementation.

## Completed scope

Both GCC15.2 and actual bundled UCRT LLVM21.1.8 pass:

- **8,910 ADX references** bind through actual AFS headers in18 immediate
  containing archives. The retained sector view's logical length matches the
  pinned asset metadata. Partial tails use real container bytes.
- **6,706 distinct non-looping payloads** decode fully to their declared sample
  totals, drain PCM, and report actual source join. Duplicate payload hashes
  retain their own range validation but are decoded once per compiler.
- The selected distinct payloads total **677,073,911 samples per-channel summed
  across files**, emitting **2,396,811,288 PCM bytes** including channel count.
  These are decoded outputs, not samples audibly presented to a device.
- Every complete result row is equal between compilers, including published
  channel sample totals, join observations, source extents, and per-channel
  64-bit byte digests. Those rolling digests are noncryptographic observations;
  they are not a full-byte comparison to original gameplay output.

The89 references with loop metadata (80 distinct payloads) have actual range
validation only. Their full decode/control is explicitly excluded here. That
does not label the original loop path invalid or demonstrate native loop/player
completion. The partial-final sample paths in the non-looping corpus are real
data rather than fabricated padded compressed blocks.

GCC's native fixture phase took124.234seconds and LLVM's141.172seconds in these
overlapping runs. They share host resources, perform differing worker timing,
and are offline validation jobs. These durations are not a game-performance
comparison, stutter reproduction, or accepted speedup claim.

## Evidence identities

Owned ISO SHA-256:
`69ae2c48e6f01e2605659feabb54eb9b82c63a809bdc8a78ad2d160b3c59a4a1`.
Private outputs are under`build-native-sjuni/adx-asset-streams/`:

| Receipt | SHA-256 |
| --- | --- |
| `probe-gcc-v1/receipt.json` (16 references,12 distinct decodes) | `87828ef28392480615b2b56a7b56f005137c1d8f3a4c60e8424e962854809dfa` |
| `full-gcc-v1/receipt.json` | `15e362bc1da039f20f88c7353a6e35f34250718c6350c275f73cdf8bcd97486e` |
| `full-llvm-v1/receipt.json` | `fc74bda9d6cd70f1648c04f2b9075ae34feed4e1d47790771e807fc5c6c5e3ee` |

The retained`cases.json`, `plan.txt`, exact executable, compile/run logs and
`results.jsonl` record selection, exclusions and each completed asset. Both
full-run source postchecks are empty. Reproduction accepts an explicit owned
`--iso`, exact`--cxx`, fresh scoped`--output`, and optional positive`--limit`.

The next functional integration boundary remains the player: output transfer
and consumption credits, actual clock/scheduling ownership, loops/LSC, controls,
and live media validation. Existing guest adapters remain until their callers
have moved and these behaviors pass controlled tests.
