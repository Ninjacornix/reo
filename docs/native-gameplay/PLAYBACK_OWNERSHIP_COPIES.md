# Independent playback ownership

Status: qualified on LLVM and GCC; uninstalled. Step4 remains incomplete.

`Playback::clone_independent` captures a distinct actor's animation snapshot on
the serialized simulation owner. It copies channels, timing, progress, resources,
deltas, root history, model nodes, bindings and caches. Mutable primary and
secondary Instance storage is separate; immutable skeletons, clips, bank resources
and retained joint snapshots may be shared. Later pose publication creates a new
immutable snapshot. A detached source produces a detached copy with the same
secondary policy. Allocation failure leaves the source unchanged. Public shallow
copy/assignment is unavailable, so that path cannot accidentally share mutable
model banks between actor lifetimes.

Both `playback-independent-copy-{llvm,gcc}-v2` cohorts pass3,113,688 checks:
72 independent copies,1,288 continuation comparisons against the complete original
animation routines, and64 source-isolation cases after changing both copied model
banks, channels and root history. Both owned skeletons and secondary-bank policies
are included. Existing replacement, whole-model and timing comparisons also pass.

Both `primary-model-independent-copy-{llvm,gcc}-v1` cohorts pass107,089 focused
CPU model/scene checks, including256 detached copies. Advancing those copies
refuses without changing timing; channel edits and reconstruction of the source
do not change the detached copy. Actual owned models and bank resources supply
these cases. V1 playback receipts are an unchanged-behavior baseline before the
new copy assertions; V2 contains the focused comparisons.

This is a native ownership operation, not an assertion that5F1400 copies original
model allocations. That original Actor copy includes model pointers. The complete
native scene handoff still must choose physical model work, retarget constraints,
apply typed Actor state and publish cache ownership under the correct phase.
No temporary identity bypass was added to primary model admission, and no game
was launched or installed. No performance improvement is inferred.
