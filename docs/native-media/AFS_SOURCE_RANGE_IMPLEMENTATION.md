# AFS sector-range binding qualification

Status: independent bounded index/range binder qualified, 2026-11-06. Actual
partition loading, LSC, ADXT player control, output credits and media integration
remain stage-3 work. This does not advance the project to gameplay migration.

The [native core](../../game/native/afs_source_range/afs_source_range.hpp)
implements the [range contract](AFS_SOURCE_RANGE_CONTRACT.md). It reads a bounded
AFS header/index from a retained immutable ByteView, keeps logical lengths and
sector extents separate, and returns views over actual parent bytes. It never
manufactures a final sector. Source2, Window2 and their frozen proofs are unchanged.

## Original evidence and native comparison

The [original-word oracle](../../tools/native_reconstruction/afs_source_range_oracle.py)
executes the full128B18/128B30 parser across header windows,1284D0 rounding,
129D78 admission and129E18 resolution, plus130478 configuration and130B78
deferred-open/clamping. Header transfer/status, loader cleanup, bounded string
operations and backend open/sector-size are explicitly declared hooks. They
provide bytes/status only, never a parsed table, member range or clamp result.

All **67 cases return**, executing **1,226,554 original instructions**. Inputs
include16/32-bit tables, zero/1/2047/2048/2049-byte logical entries,254/255/256/
1000-entry header boundaries, invalid member indices,18 open-range cases, and
35 archive tables reconstructed from the pinned inventory metadata. The default
count sentinel's distinct branch is retained. No game or OS provider was run.

Both exact GCC15.2 and bundled UCRT LLVM21.1.8 pass:

- All67 native range/table comparisons, including **22,228 complete parsed
  descriptor entries** across synthetic and indexed cases and the selected
  original member-resolution calls. These are not22,228 independent API calls.
- **23 ownership/range checks**: real nonzero tail bytes, immutable-parent
  retention after index destruction, member/view bounds, malformed indices,
  source failures after writing private output, exceptions, and range limits.
- A sector-length floor mutant differs in33 cases. A separate mutant returns
  logical-length views despite correct sector metadata; real-byte/view tests
  reject it. Production source and original evidence stay unchanged.
- Parent Release builds and selected `afs_source_range` CTest. The parent now
  registers35 suites; this is not a measure of native migration completion.

The first original harness retained incomplete setup: a header-read handle/status
byte and two critical boundary hooks were absent. Its partial records remain in
`original-v1`. The second added those and exposed a missing idle backend-status
boundary in the deferred-open tests; those partials remain in`original-v2`.
`original-v3` closes these declared transport observations without changing
original words or supplying parsed results. Frozen inputs are identical across
these revisions. Earlier oracle sources are retained alongside their freezes.
The native source existed by the third oracle freeze; that fact is recorded.

## Geometry implication and remaining limits

The previous [geometry audit](ADX_SOURCE_GEOMETRY_AND_ROUTE_GATE.md) found8,819
ADX logical partial tails. That finding is correct, but logical payload length
alone does not describe the original file-reader range. Original130478 shifts
an AFS sector count by11; the parser rounds member lengths to sectors before
resolution. All18,682 indexed archive child offsets agree for nonempty entries
with that cumulative sector layout. Every identified ADX sector extent remains
inside its immediate archive. The retained archive can therefore supply those
real tail bytes without fabricating padding or widening a logical leaf view.
This is a range finding, not proof of full native playback for all8,910 assets.

`prepare_open` reconstructs arithmetic separately from I/O admission. In the
default0xFFFFF-count branch, original code selects the full backend byte length
without clamping a nonzero start. Native output preserves those values but
sets`inside_backend=false`; callers must refuse I/O through such a result.
The actual Archive member-view API always checks complete retained extents.
The original descriptor's65536-count boundary and wrapped/negative geometry are
outside the native profile rather than silently widened to a different ABI.

The core reads private admission buffers, publishes only a complete immutable
index, and retains no guest record, path pointer, original loader handle or
mutable partition. View creation may allocate. It supplies no asynchronous
open/stop/close completion or device fence. Header-table metadata is not a
substitute for actual compressed-payload and player integration tests.

## Local identities

Native freeze:`8acea5ad1f65b142f0a283a12e6ec5e5a0a36de5c715418f222162529114178a`.
`game/native/afs_source_range/manifest.json` pins source/dependencies; its
qualification file pins the oracle, fixture, report and receipts.

| Receipt under `build-native-sjuni/afs-source-range` | SHA-256 |
| --- | --- |
| `native-gcc-v2/receipt.json` | `c21b86bc7fbbe6408cdf365561509fa83ad0dad792c1fb1535deab8929b4a742` |
| `native-llvm-v2/receipt.json` | `79bbf4c81ff20024c80e0b6ffbd28c9e4be214946b4aa544fc29e6bcd774d536` |

The oracle has separate`--freeze` and`--frozen` stages; its outputs are preserved.
`game/native/afs_source_range/verify.py --cxx <exact compiler> --output <fresh
scoped directory>` verifies immutable source, original inputs and observations,
then builds units, comparisons and private negative variants.
