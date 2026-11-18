# Native ordered worker owner

`gameplay_update::Owner` composes the canonical native World with owned script
channels, offline flag deltas, canonical flags, flag timers, linked/event tasks
and simulation clock. Its worker pass replaces the orchestration represented
by original5FED00 and script-service68C8D0. Production contains no original
addresses, generated ABI, simulated registers or guest memory.

The original order is significant. Queue/request work precedes flag timers,
script0, interaction-activity clearing, script1 and proxy-work clearing. Scripts
can run before the later actor pause gate. The signed update-counter limit has
its own override and action. The admitted path calls native World primary
actors, then the declared auxiliary/model/collision owners; native fixed event
tasks follow camera work, and native linked tasks follow scene-pose work.
Presentation tasks are not automatically run by this update pass.

The final contact/ownership/transition/event-scan group only runs when its
signed session-work gate is zero. The paused path has a separate event scan.
The initial comparison caught an incorrect unconditional final scan; the
native branch was corrected before this checkpoint. This was a source-fixture
finding, not a reproduced game symptom.

Event owner selection borrows the exact canonical session byte. Changes made by
the scheduler and inside callbacks are synchronously visible to all World
consumers, without a temporary shadow selection. Existing value-owned selection
remains available for independent users. Flag expiries use canonical scenario
notification or owner-zero primary flags, retaining notification order.

Reentry and close during a pass return busy. Missing scripts, unavailable
required flags, task-budget exhaustion and actor failures return explicit
partial-pass failures; throwing effects propagate with the running fence reset.
Close seals the owner before task destruction so destructor reentry cannot
observe torn-down script/flag members. Destroying the owner while its own
synchronous pass is active violates a C++ lifetime precondition and terminates.
The borrowed World and flag notification owner must outlive this owner.

Both compilers pass2048 comparisons against complete owned5FED00/68C8D0 and
the actual5FEE60 pause getter, with151060 ordered trace words each. The fixture
uses already-qualified native actor/script/timer/task children as **declared
ports**, plus explicit remaining worker effects. It has no active actors and
does not establish transitive actor/action coverage. It exercises568limit paths
and callback changes to gates/selection, with15independent owner admission,
partial-error, reentry, exception and teardown checks. The refreshed task cohort
also passes its154original-word transcripts/109868instructions, eight detected
counterfactuals and new canonical-selection checks on both compilers.

Qualification: [native update composition](../../tools/native_reconstruction/native_gameplay_update_qualification_v1.json).
Earlier failed setup cohorts included an active, separate audio-adapter source
outside this snapshot's dependency closure; the isolated source list now names
the qualified scenario core explicitly. No production warning was suppressed.

The subsequent native `advance` method now reconstructs the outer5FEA30
phase/transition service too. Required UI/audio/phase effects remain explicit
native interfaces. It preserves the initial primary-input/armed-control route,
request-state2 early exit, post-worker pause/transition gates, ordinary clock
commit, exit notification/phase3, conditional150/360counter adjustments,
secondary-input pause latch and the final primary-input/mode/session/control
toggle rules. Effects may change state synchronously, so later gates reread it.

Only an admitted ordinary update commits play time, once, in the original
one/two-sixtieth units. Worker calls alone still do not advance it. Both compiler
cohorts compare4096phase cases/234506ordered trace words against the complete
original5FEA30 and its actual5FEE80 clock body;440ordinary updates commit.
The existing2048worker cases remain, with explicit qualified native child ports
and no active actors. Native owner checks additionally exercise clock binding,
duplicate-owner refusal and detachment on close.

An ownership audit identified that status feedback reads the same original
seconds/subsecond bytes. `StatusTiming` now binds the canonical native update
clock directly to World health/status consumers; standalone value profiles
retain their explicitly supplied clock bytes. The native owner refuses a second
timing owner and detaches before its clock can be destroyed. Seven full original
status bodies were rechecked on both compilers after the accessor change.

Close now preflights and seals both child task stores before releasing either
store's payloads. Cross-store destructor callbacks therefore cannot publish new
tasks into a sibling that has already been cleared. The lifecycle cohort checks
both event/linked admission refusal during owner destruction; no deliberate
active-owner destruction crash test was run.

The newer [phase/clock qualification](../../tools/native_reconstruction/native_gameplay_update_qualification_v2.json)
binds these cohorts separately from the earlier worker-only checkpoint.
Task factories/payloads, remaining worker and UI/audio/scene effect owners and
game installation are still Stage4 gates. Representative scripts here are
admitted fixtures, not complete retail banks. Neither path uses host-time catchup.

The subsequent [signed pause and audio-tick cohort](../../tools/native_reconstruction/native_gameplay_update_qualification_v3.json)
compares all 256 raw pause patterns across 2,048 worker and 4,096 outer cases.
Both compilers match 97,354 worker and 287,578 phase trace words; 686 ordinary
updates commit. This cohort explicitly pins scenario source to local commit
`7d304de9` while the next script component is developed independently.

The native owner now forwards an optional actual audio/SDK tick to ordinary and
offline script execution. Twelve additional real-caller cases cover both script
channels, both dispatch profiles and tick values 0, 17 and UINT32_MAX. Without
that tick, the stream command fails admission before stream effects or script
movement. With it, start and resume receive that exact tick and the simulation
counter stays independent. These are caller integration checks, not a new
physical audio or game-performance measurement.
