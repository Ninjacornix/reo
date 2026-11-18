# Standalone scalar animation playback

Status: component qualification passed; not installed. Step4 remains incomplete.

The sixteen cinematic objects use58C810/58C8A0's standalone timing record,
which differs from an ordinary actor channel. Native bind_scalar_frame preserves
flags, keeps odd clip endpoints and the raw loop policy, binds/samples track0,
then installs duration and a nonnegative loop restart. It does not normalize the
endpoint or loop byte using actor-channel rules.

advance_scalar_frame returns immediately when a nonlooping record is already
complete, including unordered frame/end comparisons. It performs no sampling or
frame mutation there. Otherwise the canonical clock mode doubles the supplied
step when nonzero, the existing qualified timing policy advances once, and
track0 samples even when that advance reports completion. Model ownership stays
with the actual native Instance; no second mutable animation owner is created.
An absent/unadmitted clip is an explicit native failure.

Both scalar-playback-{llvm,gcc}-v2 cohorts pass7,762,899 checks, including2,048
scalar bindings,8,192 scalar ticks,3,470 early returns and1,024 odd-end bindings.
They execute complete original adapters, packing, bind/sample and timing bodies
checked against owned instructions. Models are explicitly relabeled to track0
on both sides for matching clip cardinality. Four controlled clips provide odd
endpoints and negative restart values; the other inputs come from actual owned
scene banks. Existing topology, channel, whole-motion and lifetime comparisons
run in the same cohort. All five dependent CMake parents pass on both compilers.
V1 retains the GCC fixture indentation warning; V2 passes strict warnings.

Evidence: tools/native_reconstruction/native_scalar_playback_qualification_v1.json.
The sixteen-object pool, timeline pose, actual object construction and complete
scene caller ownership remain open. No game was run or speedup measured.
