# Shared-source Window2

The concrete `StreamWindowOwner` owns exactly one Source2,
its private link, finite header state/key context, allocation-free workspace and
phased PCMv2 store. It implements header/ready, first/repeat/seamless transitions,
normal decode, ordered credits, stop/drain and actual source retirement.

This folder is **not integrated into the game**. Its independent owner is
registered in the parent native suite. The
[qualification report](../../../../docs/native-media/ADX_WINDOW_V2_IMPLEMENTATION.md)
records bounded original comparisons, failure controls and explicit exclusions.
The [composition contract](../../../../docs/native-media/ADX_SHARED_WINDOW_CONTRACT.md)
remains the acceptance boundary. Actual player/RNA/DTR integration, partial
final-sector source support and estimated clocks remain unfinished.

Malformed short end markers and unqualified math/channel/geometry are retained
as explicit unsupported owned faults. A measured provider error preserves safe
buffered decode and original retry state; a broken identity/credit protocol faults
the graph. No fallback after effects or fabricated provider/device fence exists.

The pure header's `output_cursor` is the acknowledged per-window offset; the
engine's cumulative decoded count is separate. Source2's private link is the
only mutable sample-limit owner. Snapshot coordinates explicitly distinguish
unbound storage from a bound zero-length/zero-offset grant.
