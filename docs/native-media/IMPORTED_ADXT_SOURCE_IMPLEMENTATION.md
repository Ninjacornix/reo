# Imported ADXT source integration

The verified File #1 base import now supplies all **8,910 ADX references** to
the native archive hierarchy and clocked player without opening the ISO. Both
GCC 15.2 and bundled LLVM 21.1.8 pass. **Stage 3 remains in progress**; no game
ran, no audio device opened and no production path changed.

The [contract](IMPORTED_ADXT_SOURCE_CONTRACT.md) and
[implementation](../../game/native/afs_hierarchy/hierarchy.hpp) retain the actual
parent archive bytes. This corrects the earlier blanket logical-PAK-tail blocker:
the installed base import preserves complete NETBIO archives, including real
sector tails. Standalone logical replacements, overlays and File #2 still need
their own source/lifetime qualification. Frozen historical reports are retained.

The unchanged Windows mount factory hashes all 85 imported files through their
retained handles. The selected actual NETBIO01 archive matches the independently
inventoried owned root hash and length. One root and 19 cached archive indices
(9,724 entries) resolve every ADX reference. Native resolution takes member
indices; inventoried offsets and logical sizes are checked afterward. It does
not consume facade pseudo-LBAs, synthetic read-ahead or the manifest's ISO path.

Both runs fully decode the **6,706 distinct finite payloads** through real native
source workers into one persistent shared output session. Every payload count
and digest matches the earlier independently qualified native decoder baseline:
677,073,911 summed per-file channel samples, 2,396,811,288 PCM bytes. Actual
source joins, per-player output retirement and terminal raw-clock ratios pass.
The provider detaches, stops and unloads exactly once after all players; occupied
producers end at zero. The 89 loop references resolve but are excluded from full
player playback; the earlier 80-payload decoder-cycle evidence remains separate.

All 8,910 complete result rows match across compilers, including observed padding
counts. The comparator permits only explicitly retained padding-count variation;
this cohort has none. Model consumption is deliberately buffered and has zero
underruns/skips. This proves neither real-time throughput nor audible output,
original whole-player parity, the original global schedule or stutter removal.

Nineteen hierarchy ownership checks pass on both compilers, including actual
nonzero sector tails, sibling cache keys, cache budgets, invalid nested sources,
partial read failures and view lifetime after tree/root release. Two compiling
negative controls fail as required: a cache keyed by depth alone and a leaf view
truncated to its logical size. Both parent Release CTest targets pass. The combined
native project registers 44 suites; suite counts are not migration percentages.

The frozen manifest is
`142aee04a67e0746609897a1ba734cb82e49b75f6e86d2e7ce7c056161a4d04d`.
The checked-in qualification pins receipts under:

- `build-native-sjuni/afs-hierarchy/qualified-{gcc,llvm}-v1`
- `build-native-sjuni/afs-hierarchy/parent-{gcc,llvm}-v1`
- `build-native-sjuni/imported-adxt-player/full-{gcc,llvm}-v1`
- `build-native-sjuni/imported-adxt-player/comparison-v1`

The import manifest, imported file identities and frozen inputs remain unchanged
through both runs. Whole-archive hashes bind real source tails to the owned
inventory; a locally generated manifest is not retail-disc attestation. These
checks leave SDK/RPC publication, bank aggregation, original global scheduling,
LSC/seamless ownership, movies and game transition validation open. Stages 4–6
and final compatibility-runtime removal remain required.
