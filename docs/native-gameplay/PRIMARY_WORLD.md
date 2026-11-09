# Canonical native primary actor world

`gameplay_world::World` owns primary actor identities through the native
`EntityStore`. Each actor contains the health/status/hit state exactly once.
Frame orchestration and native input operate directly on that object. Session
mode, selected actor, pause, room and authority-filter aliases refer to one
shared native `HitSession`; RNG and options also belong to that session. There
is no guest-memory import/export or simulated CPU context inside this owner.

An update holds a strong lease for the admitted actor generation. Retirement
invalidates future resolution immediately; replacing the same primary slot
cannot redirect writes from the old invocation into the replacement. A later
slot is resolved afresh and can participate in the same traversal. This is
explicit native ownership policy, not an emulation of physical slot reuse.
The executing primary index names the traversal slot; services must use their
passed actor reference instead of resolving that index to a newer generation.

Input is now a composed native operation, using normalized controller snapshots
and the admitted layout profile. It preserves original mode/AI/controller
binding gates and history/remapping order. Unported behavior, AI, pose, motion,
scene and grid operations remain required typed services. No successful dummy
providers or generated functions are hidden behind the interface.

World, Session and borrowed controller spans are simulation-owner-thread only.
Reentry and close during an update return busy. Destruction seals the owner
before member teardown, so actor destructor reentry sees intact closed state.
Destroying the owner during its synchronous update violates an explicit C++
lifetime precondition and terminates; no deferred recovery is promised after
that object's lifetime ends. Actor leases may outlive retirement, but cannot
retain/use a raw World reference after the owner's lifetime.

Input admission errors and throwing services leave a partial frame. Earlier
actors and current preparation writes can already have changed state; offline
selected-actor normalization may not have run. Callers must handle that error
explicitly and cannot assume rollback or transparently fall back to old code.
This actor pass does not commit a simulation clock update by itself.

Both compiler cohorts pass 4,096 comparisons executing complete original
669F30 and its actual 1B0B80 input callee. Other listed services remain declared
fixture providers. A separate 75-check cohort covers shared canonical state,
health/input composition, cross-world identities, reentry, partial errors,
retirement/replacement, same-pass births, callback accumulator mutation and
closed-owner destructor reentry. The [qualification](../../tools/native_reconstruction/native_gameplay_world_qualification_v1.json)
binds exact source and output identities. The first failed run omitted the
owned remap table from the reference RAM fixture; final matching sources pass.

The [independent review](WORLD_OWNER_REVIEW.md) identified teardown and grid
ordering tests. The original loads its grid accumulator after the callback.
The older isolated frame core now makes that ordering explicit too, with four
detected fault variants in its [updated comparison](../../tools/native_reconstruction/native_gameplay_actor_frame_qualification_v2.json).
These are source/fixture findings, not a live slowdown diagnosis.

Actual actor/scenario callers, full behavior/animation/resource providers,
enemy/auxiliary families, semantic save snapshots and game acceptance remain
Stage 4 gates. This owner has not been installed into the game candidate.

The subsequent [native behavior consumer](ACTOR_BEHAVIOR.md) now connects this
primary frame to native behavior orchestration and the native status/hit cores.
It adds transform history, saturating action/control invocation counters and
shared action snapshots to these canonical objects. Individual action/effect
providers and game installation remain explicit gaps; the newer qualification
includes a fresh regression of this owner's original-frame/lifetime comparisons.
