# Native World target metrics

2026-11-11 field correction. Linked model-point selection now owns its551
index in TargetingState. The earlier implementation and fixture reused the
motion-style value atB99 for that index. This review corrected that field
association before native game installation. Selected-point queries require a
known in-range index. The position fallback has its existing source admission.

The revised original comparison varies551 independently ofB99 and tests a
valid model point with motion style255, an unknown index and an out-of-range
index. Both compilers pass5,781,403 checks across192 profiles, including75
strict source profiles and192 comparisons with the explicit scratch policy.
The fixture observes333 floor hits. Four current parent tests pass per compiler,
including target metrics and the real collision worker. Evidence is sealed in
`native_target_model_point_qualification_v1.json`. Earlier target-metric receipts
retain their historical source identities and do not cover this correction.

2026-11-10: complete admitted6D6240 cache rebuild now has a native World owner.
It borrows the actual eight primary, ten auxiliary and fifty linked physical
slots, canonical model poses, room walls and floors. The installed game remains
V39; full Stage4 acceptance remains open.

Primary pairs preserve full XYZ distance and bearing, including the raw mode0
gate. Linked distance uses actor positions; bearing and wall/floor probes use
actual source node11 and the selected linked model point or its known position
fallback. The linked targeting component owns the linked-family flags once.
Missing required points, components or complete bounded collision queries refuse
the rebuild; no partially rebuilt cache is published. The same identity retains
skipped metric cells. Slot reuse invalidates its old values before publication.

The three order families preserve their source indexing. Reverse linked rows
use compact candidate ordinal, which is not a linked actor identity. The last
family uses compact active primary rows for its lists and physical primary rows
for metrics and counts; sorting reads the original physical count prefix with
the compact active limit. The native snapshot exposes those compact row sources
as actual generation identities. The source floor byte left untouched in the
primary/auxiliary bank is not given an invented native value.

Two bounded distance work arrays are initialized to finite maximum once, the
explicit correction tested in the [scratch audit](TARGET_CACHE_SCRATCH_AUDIT.md).
Their contents are reused across all three source phases. With finite values,
repeated sorts of a completed row cannot swap anything, so the native path sorts
each reached row once. In the comparison cohort this gives4,744 sort calls and
380,102 comparisons versus31,860 calls and11,420,860 comparisons in the original
initialized profile. These counts do not establish a frame-rate improvement.

Both compilers pass5,781,399 checks and22,218 pair computations across192
profiles.75 naturally defined profiles compare the strict original output;
117 reach unwritten original scratch and are tracked separately. All192 compare
the explicit initialized policy, including sparse primary layouts. The complete
original cache/sort/mode/distance code executes. Heading and actual native Grid
wall/floor children are declared ports. The current trace regression also passes
482,015 checks and366 owned grids per compiler; all thirteen parent tests pass.
Evidence: `native_target_metrics_qualification_v1.json`.

The native frame worker now adopts the cache in its existing pre-actor stage,
after the pause gate. It borrows the same room provider as collision height
work. Its real frame tests verify two primary-to-linked metrics, ordering before
actor motion, pause behaviour, and that room acquisition failure invalidates
the published view before later workers run. Thirteen parent tests pass per
compiler; `native_target_metrics_worker_qualification_v1.json` seals adoption.

No game was launched. This cache does not by itself complete observation,
goal/action execution or the remaining native gameplay integration.
