# Native periodic visual/resource consumer

`EffectBank` preflights all three variant0 logical36/37/38 profiles against actual
owned geometry, group transforms and material curves. `PeriodicVisuals` now owns
their real creation, bounded168 visual /256 child domain, delayed visibility,
signed timer/age wrapping, expiry, child transforms/materials and camera-relative
position updates. This supplies the previously missing actual6525D0/6535C0
consumer behind `PeriodicEmitter`. It introduces no host clock, speed change,
guest memory, CPU/register context or generated function in production.

This is the selected periodic family: null parent, variant0, flags1A193 and the
complete6535C0 callback. Other flags, parent/variant profiles and effect families
remain unavailable. The shared original168/256 domains must become one canonical
owner as those remaining families migrate; independent per-family capacities
must not be installed in the game. The native owner is not a whole gameplay
installation, opcode131 is not yet admitted by this checkpoint, and Stage4
remains incomplete.

The complete caller corrected an initial native metadata interpretation. For
5903E0's output, offset0 is **translation**, default0 and sampled by channels6..8.
OffsetC is **scale**, default1 and sampled by channels0..2.6526F0 proves these
roles when it copies the first vector into position and the second into child
scale. The earlier scalar v1 byte comparisons passed but the field labels and
default roles were reversed. Current fields and channel assignments are fixed.
Both compilers re-pass1,288,852 scalar checks under the corrected source, with
the same357,580 samples and61,380 complete transforms. Historical v1 receipts
and documentation remain their own source snapshots; this supersedes their
semantic field-label statements.

Creation resolves the logical resource independently of efdata's group map,
retains the selected immutable bank, and inserts the visual at the source mode1
list head. A full visual domain is a natural miss. A full child domain admits the
same successful prefix, including a live zero-child visual. All three admitted
groups have valid geometry/material/selector bounds in all six physical owned
banks; every consumed material slot is written by its curve. Unknown parts in
other groups and EF35's stale-workspace palette remain explicit refusals.

Phase0 decrements/narrows delay before its signed test, then enables visibility
and enters the active phase. Remaining lifetime decrements/narrows by2; negative
retires children and the visual before age advances. Active children select the
authored transform-part index, sample materials and receive baseXYZ plus sampled
translation.652CE0 then moves each point by the source normalized vector toward
the camera, using the caller's scalar distance. The vector normalization follows
the finite SDK profile, including its zero-length maximum-float reciprocal
fallback. No extra tick or host-time estimate is introduced.

Renderer handoff is an immutable frame containing native IDs, retained asset
banks, visibility, three rotation angles, position/scale and material values.
The unassigned fourth source stack halfword is omitted from this typed output.
A short publication mutex protects only shared frame-pointer exchange; old frame
and resource destruction occurs after unlocking. Both compiler libraries support
this route; the pinned LLVM library did not provide atomic shared_ptr
specialization. Retained frames survive later updates, retirement and close,
while fresh lookup never reassigns a retired ID. Actual native renderer resource
submission belongs to Stage5.

Both compilers pass **1,300,872 checks** each. The actual chain executes complete
6525D0,652390,652E20,590760,652470,6535C0,6526F0,652CE0 and all consumed pool,
curve, material and camera helpers. It also executes complete5D9680/5DDC70 and
real1AEC80 RNG, with the actual native emitter replacing the old successful
visual fixture.48 task sequences over the six banks provide8688 task/visual
steps, including flag cancellation. Separate checks exercise7200 visual updates,
2616 direct creations plus192 task creations,32,532 observed child updates,
all65,536 signed delay/lifetime input patterns,65,536 independent camera cases,
168/256 exhaustion, partial child allocation, expiry/manual retirement and stale
IDs. A concurrent reader repeatedly retains immutable frames during2000 owner
updates.5058 private resource allocations/releases balance. Counts overlap and
include repeated assets; they are not unique content or game coverage.

Original words and the transform jump table are checked against the owned
ELF/o0/o2 bytes. Private bounded memset, resource allocation/lookup/release and
cache bookkeeping are declared seams; task retirement uses the independently
qualified scheduler seam. Debug overfree remains a throwing unadmitted path.
The source pool starts with known zeroed storage in this cohort. Native creation
owns/clears all256 piece states, whereas source reset only clears168 active
bytes; unspecified old pool/padding contents are not emulated. Physical PS2 FPU
exceptions, subjective visual quality and game performance are not claimed.

Earlier failed test directories retain missing test-context fields, jump-table
initialization and logical-map setup discoveries, plus the caught scale versus
translation role error. None was a game run. No original assets were changed.

Reproduce: `verify_periodic_visuals.py --compiler <LLVM-or-GCC> --corpus
build-native-sjuni/effect-geometry-owned-v1 --output <fresh-directory>`.
Final visual receipts: periodic-visuals-llvm-v7 / periodic-visuals-gcc-v1;
corrected scalar receipts: effect-tracks-llvm-v3 / effect-tracks-gcc-v3 under
build-native-sjuni. Qualification binds exact sources, compilers and these results.
