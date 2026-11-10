# Native cooperative gameplay event evidence

`gameplay_events::Events` replaces the cooperative128-record evidence pool and
simple/typed append/prune paths37BFB0/37C060/37C170/37C200/37C2C0/37C3B0.
This is gameplay event evidence, distinct from scheduled EventTasks and audio.
The native update Owner owns this pool once alongside its existing canonical
clock. Its record methods take the timestamp from that clock's update counter
and room from its actual World. There is no shadow clock or display-frame count.

Simple events have type1 and priority9. Typed events have type2, retain low16
ID/arguments and use the owned signed priority byte. Both clamp unsigned time to
A4C478. Allocation uses a bounded free stack and ordered list; saturation
prunes records at the current priority threshold, then increments the threshold
even if none were removed. Typed admission is checked again after pruning, so
the pruning prefix can be observable even when the incoming event is rejected.
Snapshot values remain readable after retirement; generation/domain handles
refuse stale, foreign, reset and closed-owner access instead of retargeting reuse.

The measured priority prefix is39 bytes, IDs0..26 hexadecimal. It includes every
event emitted by the pending owned-recipe consumer. Larger typed IDs explicitly
return unavailable; this does not invent a boundary for the original table.
Simple IDs retain the complete low16 domain without consulting that table.

Both compiler pool cohorts pass22,944,588 assertions each, with74,282 append
attempts,3,584 retirements,1,989 prune calls,300 resets and five refusal groups.
Tests compare full ordered live payloads, actual physical allocation order,
list/free counts, timestamp saturation, priority rejection, full high-priority
pools, unlink positions, reuse, all unadmitted typed IDs and serial exhaustion.
Complete original bodies execute; bounded clearing is the declared oracle port.

The actual CMake update-owner test also verifies counter wrapping, room changes,
simple/typed payloads, missing metadata and closure. Both parent builds and seven
integration tests pass. Current worker/phase comparisons pass2,048 ordering cases,
4,096 phase cases,686 committed updates and12 audio-tick cases per compiler.
Those worker comparisons retain their declared separately qualified child ports.
Their historical dependency list was incomplete for the current World/VM; the
driver now freezes its transitive headers and concrete dependencies and verifies
cached production objects. Missing-header/link cohorts and the initial parent
fixture constructor error are retained. Production warning checks remain enabled.
Evidence is sealed in `native_cooperative_events_qualification_v1.json`.

The owned recipe consumer is the next binding. Remaining event producers,
statistics/export/save consumers and actual game caller installation remain
open. No game, audio output device or foreground test was used. Installed V39
is unchanged and Stage4, including coherent gameplay acceptance, is incomplete.
