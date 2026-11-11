# Native playback model replacement

`Playback::replace_model` supplies the animation-owner operation needed by
resident primary-model reconstruction. It replaces the mutable primary instance
and, when present, creates an independently mutable secondary instance from the
new skeleton. It preserves actor-owned channel records, resource bindings,
selectors, transition deltas, progress and the previous root-translation history.
Old node clip bindings are not copied into the new allocations. Allocation and
root validation finish before either model pointer is published. Same-primary
replacement preserves both owners; a null replacement refuses without mutation.
The enclosing simulation owner must serialize the operation and update its
canonical actor model/constraint ownership before callbacks resume.

The source distinction is visible in complete 5EBF80: resident selection and
model reconstruction (1D1E70/1D0420) precede 66A750 actor initialization. The
node allocations and the actor's 1E4/364 channel records and 508 root history
are separate. This operation alone does not implement the complete model-cache
caller, archive/texture loading or rendering registration.

Both compilers pass 2,949,346 playback checks, including 72 replacements,
264 subsequent continuation cases and 64 null refusals. Sixty-four cases start
from real clip playback, retain published old poses and compare rebinding and
advancement with the complete original routines. Eight additional cases cross
both owned skeletons with and without the secondary-bank policy. Independent
original node allocations are rebuilt using complete owned packing/construction
bodies; archive selection and full 5EC100 orchestration remain outside this
focused fixture. This is not a whole-loader parity claim.

Reproduce with `animation/verify_playback.py`, the pinned
`animation-owned-corpus-v2`, explicit compiler and fresh output directory.
Current evidence is `playback-model-replacement-{llvm,gcc}-v3`. V1 lacks the
cross-skeleton cases. V2 caught a fixture clock-mode value retained from a prior
case; v3 explicitly initializes that independent clock input. Historical outputs
remain available. No game was launched; installation and Step 4 remain open.
