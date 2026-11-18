# Sixteen cinematic objects and pose timelines

Status: component qualification passed on both compilers; not installed. Step4 is incomplete.

The separate category10 records now have a World-owned sixteen-slot native pool.
They reuse a generic generation token in their own domain; they do not allocate
Actors or consume the128 room-scene records. World closure revokes the object
identities and model capabilities. Retained invocation leases can survive
retirement without granting lookup through a stale ID.

The5F1390 first-free selector also reserves exactly one inactive/unreserved
record, without activating it. Full, absent, busy and closed results remain
explicit. Source reservation word1198 is represented as native reservation state.

Initialization reproduces571010's signed pause gate. Pause0 leaves prior storage
unchanged; nonzero pause prepares sixteen cleared records with category10. The
native replacement prepares allocations before publishing a new generation.
This changes allocation internals without inventing successful content loading.
The paused571080 pass visits exactly sixteen physical records and services active
ones, including hidden objects. Phase0 becomes1 and initializes the matrix;
phase1 runs the service; phase2 and other states perform no model update.

The571150 service consumes a literal motion slot200*(key/100)+key%100 from the
supplied canonical bank, binds track0 at frame0 on request, toggles flag2, then
applies the current pose segment. It builds the rotation and translation matrix,
clears flag4, advances the standalone scalar record according to the original
byte5 protocol, and rebuilds the real model hierarchy. The first motion-request
frame binds without ticking. Later ticks use0.5 before canonical clock-mode
scaling. Required absent models/tokens remain explicit failures.

A bounded decoder reads adjacent36-byte pose records. The next timestampFFFF
selects a constant key and needs only the next sentinel header. Otherwise5712D0
uses an unclamped parameter from the canonical scene frame, quadratic DeCasteljau
position interpolation, signed degree interpolation and low16 turn conversion.
Equal timestamps select1. Signed frame subtraction preserves word wrapping;
backwards durations are not silently clamped or normalized. The finite numeric
profile includes the original >=2^31 conversion split; exceptional/out-of-range
conversion remains an explicit native refusal.

Both cinematic-objects-{llvm,gcc}-v4 cohorts pass13,062,220 checks, including
16,384 reservations,67,585 pose evaluations,1,024 complete passes and9,336 actual
model publications. Five native refusal cases remain explicit. Close-time model
destructors also check recursive World/object closure guards. The cohort includes
the full signed degree sweep, controlled interpolated segments, matching actual
scene-bank clips and owned skeletons, cold/reset/paused storage, repeated model
publication and identity/closure checks. Current model-lifetime regression passes
150,804 checks and all five dependent parents pass on both compilers.
V1 retains an unadmitted numeric fixture case; V2/V3 retain reference initialization
findings. V4 explicitly zeroes node arenas as in the prior packing qualification
and publishes the same prior pose on both sides before held-state comparisons. Reference object records are initialized by complete
571010; the bounded memset implementation is an explicit observation port.
Original model packing, binding, sampling and matrix publication execute. All
models are explicitly relabeled to track0 for matching clip cardinality on both
implementations; that fixture preparation does not prove original object model
construction. Pose selection and content binding are supplied, not guessed.

The static header audit covers548 descriptors and726 object groups in221 scenes.
Every construction header is valid; the largest scene has11 objects and none has
holes that would shift first-free allocation. The literal demo model/texture
formats are source-verified. Candidate requests derived from descriptor filenames
find452 exact named model occurrences;274 remain unresolved. Filename candidates
are not proof of live scene request identity, aliases or actual load attempts.
The descriptor's header words4/8/12 must not be substituted for the request bytes. The later
[Cinematic object stream/load audit](CUTSCENE_OBJECT_TRACKS.md) establishes that
the destination scenario from the first header word is applied before object path
formatting. With that destination and the separate request sequence,671 of726
candidate occurrences match;55 remain unresolved. This supersedes treating all
274 same-archive misses as unresolved runtime destinations.

Evidence: tools/native_reconstruction/native_cinematic_objects_qualification_v1.json.

Actual descriptor object selection/construction, track/event cadence, attachment
composition, full scene entry/exit, actor reaction/secondary poses and installed
native gameplay acceptance remain open. No game run or performance gain is claimed.
