# Native periodic scene-effect tasks

The complete `5D9630`, `573890`, `5D9680` and `5DDC70` task/request policies now
have native ownership and timing implementations. `PeriodicEffects` uses the
real native linked scheduler, canonical scene-control identities, FlagState and
shared RNG. It snapshots the control's position at creation and rereads the
current stop code on subsequent updates. Retired identities reap the task;
native work cannot retarget a reused scene-control record.

Phase zero falls through to the first emission on that same update. Phase one
uses signed wrapping halfword decrement. Phase two increments for four calls,
then restores the low 12-bit wait and resumes phase one. Cancellation precedes
all phase work. The high-bit stop-code path preserves the original halfword
flag helper's low-four-bit mask. Ordinary byte-bit codes outside the admitted
128-bit bank refuse before state, RNG or emission changes; unrelated memory is
not manufactured as a native flag bank.

Each emission advances the actual shared primary RNG once and selects one of
descriptors 24/25/26 hex. The returned visual receives current position, zero
delay and scale 30. Packed scheduling preserves the signed top-nibble cycle,
signed duration division toward zero, wrapping intermediate halfwords and the
unmasked delay OR. A full visual pool is a normal missed emission and still
advances the task phase. A missing native consumer is an explicit sticky error.
Owner close removes only its own tasks; other linked work remains owned by its
original producer.

Both compiler cohorts pass 920,608 checks: 131,072 complete original task cases,
69,715 emission attempts, 51,907 retirements, exhaustive packed-word values,
64 actual factory/capacity cases and 32,640 explicit out-of-profile flag codes.
Native scheduler/control ownership checks cover captured position, cancellation,
retirement/reuse, missing consumer and close. The actual original flag and RNG
bodies execute, including their real state locations. Allocation/removal use the
separately qualified scheduler profile. `6525D0` remains a declared emission
fixture in this cohort; its real resource and visual consumer is not supplied.

The [qualification](../../tools/native_reconstruction/native_gameplay_periodic_effects_qualification_v1.json)
retains sealed compiler/source copies. Scenario infrastructure is pinned to
`ab4e10fd`; the periodic implementation is captured from the working source.
Reproduce with `verify_periodic_effects.py --compiler ... --scenario-ref
ab4e10fd --output NEW_PRIVATE_DIRECTORY`.

Earlier private harness failures exposed missing shift surroundings and test
RNG projections copied from a declared-port fixture. The final cohort uses the
actual original RNG locations and an SDK-compatible signed word setter. These
were test setup issues, not observed game incidents.

The actual effect resource import, visual lifecycle/update/presentation consumer,
opcode 131 caller and stock-content admission remain required. No opcode or
gameplay feature is enabled by this module, and this does not close Stage 4.
