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

The outer5FEA30 phase/UI/transition service still controls whether play time is
committed after the worker chain. This pass deliberately does not advance the
clock or use host elapsed time. That caller, task factories/payloads, remaining
worker owners, scene providers and game installation are still Stage4 gates.
Representative scripts here are admitted fixtures, not complete retail banks.
