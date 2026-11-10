# Native timed resource lights

`gameplay_lighting::TimedLights` implements the6B2680 request and
5D85E0/5D8630 task through the existing World,32-task scheduler and canonical
64-light pool. The authored7202C0 definition receives the caller's position.
Only actor action2/secondary11 admits a request. Its tag comes directly from the
existing canonical actor `surface_material` byte, original175. The floor and
collision owners already publish that field. The first draft added a redundant
optional tag; this was an overly restrictive binding and is superseded by the
material-bound qualification. No second mutable actor scalar remains.

Clock mode zero initializes44/30/20/20 counters; other modes initialize
22/15/10/10. Signed halfword counters wrap, phase0 falls through to phase1,
phase1 captures its final two values before fading, and phase2 reaches phase3
one update before retirement. Flicker is370080's byte-angle sine through
192190/18F340, with the exact authored pi/4 multiplier. No RNG or host-time
timer replaces it. Actual actor action changes cancel the task immediately.

The scheduler owns the real task and enforces shared capacity, newest admission,
same-pass creation and presentation behavior. Task destruction retires only its
own light. Owner close preserves unrelated tasks and lights. Native generations
prevent actor replacement, lighting reset or physical-slot reuse from retargeting
an old task.

Two explicit modernization policies differ from unsafe source pointer behavior:

- When the light pool is full, the original constructor retains a task with a
  null light pointer; later updates can write through it. Native construction
  removes that new task and returns `light_full` without changing other lights.
- A retired actor or reset/reused light retires its native task safely. It never
  follows the new occupant of a recycled physical record.

LLVM and GCC each pass3,694,722 checks, including131,072 controlled state cases,
all65,536 action/secondary admission pairs,1,024 complete lifecycles and25,152
real scheduler updates. Tests cover every clock byte and lighting tag, mode
changes, cancellation, same-pass construction, pool exhaustion, explicit task
erasure, foreign identities, reset/reuse, actor replacement and cleanup. Four
parent world/collision tests also pass on both compilers. The sealed qualification
is `tools/native_reconstruction/native_timed_lights_qualification_v1.json` for
the earlier draft and `native_timed_lights_qualification_v2.json` for the current
canonical material binding. The latter has seven genuine refusals; an invented
unknown-tag refusal is removed.

The oracle executes complete constructor, update, light-pool and sine bodies.
Scheduler admission/retirement are declared captured ports on the original side;
the native side uses the actual canonical scheduler, which has its own earlier
complete-word comparisons.370080 has no current standalone generated file.
The test-only entry is extracted from the older combined file, with all16 words
audited against owned o0. Three formerly uncommented nonzero delay slots have
explicit comments in the extracted fixture. The older file's module-header
entry is never executed. The failed first comparison lacked fixture-only AND/OR
macros; the retained v3 receipts cover the corrected fixture.

This component is not installed in a game candidate. The1D companion caller,
renderer consumption and full Stage4
acceptance remain required. No game or audio device was launched.
