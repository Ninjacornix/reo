# Native AI scene candidates

2026-11-10. The complete reachable819BC0 actor probe and819DA0 collector are
qualified native components. Stage4 remains incomplete; installed gameplay is
still V39. No game or performance incident was tested for this change.

The collector borrows the canonical128-record scene pool used by scripts and
collision. It walks newest to oldest, checks raw nonzero activation and the busy
flag, then performs native polygon/overlap and asymmetric height admission.
Kinds80/81 use the query position and radius; kind85 uses actor X/Z with query Y;
other kinds use the query position. It returns generation-checked record IDs.
Missing required geometry or invalid finite conversions returns unavailable,
which callers must distinguish from a completed empty collection.

The original pairwise priority sort excludes the final candidate from its inner
loop. Native code preserves this behavior, including when that final candidate
has the lowest priority. No general stable sort or full priority sort replaces it.

The actor probe uses actor position for motion1A. Other motion classes offset
X/Z by the original sine/cosine of yaw times `46 + local collision center Z`.
The source offset1B4 is **not radius**: existing complete World collision and
playback comparisons establish the local center at1AC..1B4 and radius at1B8.
The actual Owner borrows these existing fields, without a second radius or
byte-layout state. The unreachable selector2/3 blocks are not new native policies.

Both compilers pass67621991 identical checks, including:

- 7172 completed collector comparisons: all256 kind bytes, activation/busy gates,
  height boundaries, actor/query differences, sort behavior, reuse and capacity.
- 131329 completed actor-probe comparisons: all65536 headings with two different
  center-Z values, all256 motion classes and unused NaN center for motion1A.
  Sampled query XYZ is bit-compared against original scratch independently of
  the final geometry result.
- Five explicit missing-geometry, nonfinite or out-of-range refusals.
- Both parent builds and ten integration tests. Actual Owner tests distinguish
  center54/radius999, radius-only mutation and center-only mutation; script
  disable/re-enable affects the same records, and retirement invalidates results.

The original executes complete polygon/overlap helpers and the complete
3700C0/370100 SDK sine/cosine chain. Native code uses the already qualified
original polynomial math, rather than host trig. Failed v1 compile evidence is
retained: the original-only context needed HI1/LO1 and generated tail-jump locals
needed an original-translation-unit warning exception. Native warnings remain
errors. v2 passes without removing original instructions.

Evidence: `build-native-sjuni/navigation-scene-{llvm,gcc}-v2/receipt.json`, both
`navigation-scene-parent-*-v1.log` and `navigation-scene-tests-*-v1.log`, sealed by
`native_navigation_scene_candidates_qualification_v1.json` (SHA256
`1c8d5599e42f758938d7f5c00fcb949e06bf8320d6ea87a5aa8ce61efd2a8a86`).

The actual room provider must supply its shared Records. Full812540 observation,
condition-based scene lookup, remaining AI/movement, real loading, semantic saves
and coherent native gameplay installation/acceptance remain open. Earlier graph
comparison limits remain unchanged and are not claimed source matches.
