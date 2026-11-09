# Native resource periodic visuals

The common resource callback now implements complete5925C0 through the existing
native periodic visual owner. This supersedes the missing pulse branch in
[the first resource-frame checkpoint](RESOURCE_FRAMES.md). Following5DDC70
establishes that this is visual emission, not a room-query service.

The model owns content ID, phase, signed timer, packed cycle/delay and distance
separately from WMD playback and asset index. Four special content IDs skip the
operation. Phase zero counts down with signed16 wrapping, sets flag1000 and
emits; phase one holds for four invocations, clears the flag and reloads the
packed low12 delay. Other phases retain their state. A nonzero distance and
pitch produce the original yaw/pitch offset with the original turn conversion
and ordered FP32 arithmetic. Zero distance or pitch emits at the model position.

The existing complete5DDC70 emission policy is shared with scenario tasks,
including the canonical Session RNG, descriptor selection, actual visual
lifetime, delay packing and natural pool-full result. `PeriodicVisuals` owns
the same168 work records and256 child pieces used by other effect consumers.
An emitter must explicitly prove its RNG binding before a required resource
emission; missing or foreign owners fail after the measured state prefix.
An optional constructor argument does not claim a default successful provider.

Both compilers pass4,060,214 checks,92,542 resource updates and66,562 actual
emissions across six owned effect banks. The paired65,536-angle sweep visits
every yaw and pitch bit pattern; it does not exhaust all angle combinations.
Tests cover content skips, signed timer wrap, phases, packed cycles, zero/nonzero
offsets, actual168/256 capacity, and twelve missing/foreign-owner refusals.
The same run checks existing visual creation/update/retirement,8,688 scenario
task frames,65,536 camera cases,65,536 signed-timer cases and concurrent immutable
frame readers. Native and original pool usage, output pieces, emitted positions
and RNG states agree under the declared finite SDK131 profile.

The current weapon/pose regression also passes49,584,917 checks per compiler.
Its immutable header differs from the pulse cohort only by a corrected comment;
the qualification records that exact byte replacement explicitly. Both parent
builds and four World/contact tests pass. Evidence is bound in
`native_resource_pulses_qualification_v1.json` with original word audits, frozen
sources, extracted asset hashes and all receipt/output hashes. Failed test
fixtures remain preserved independently.

Shared secondary retirement, extended actors, required reconstruction, native
asset/resource construction, game installation and Stage4 acceptance remain
open. The installed game is unchanged; no game run or speedup is claimed.
