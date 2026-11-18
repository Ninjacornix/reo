# Native actor terminal countdown and transition

Status: qualified on both compilers; uninstalled. Stage4 remains incomplete.
InstalledV39 is unchanged; no game or physical audio device was launched.

`ActorTerminalTimer` implements complete6687A0 through actual inventory-bank
transfer, auxiliary lists, resource-frame retirement and native action-pose
snapshot. It borrows a same-World ActorResourceOperations owner and can bind
directly into `BehaviorFrameServices` at its original terminal-timer stage.
That owner must outlive the adapter. Without the binding, the explicit terminal
provider remains required. Foreign worlds, detached/retired actors and closed
owners refuse rather than silently succeeding.

Auxiliary1000 and primary!=4 first clear the canonical gauge to a known zero,
even when its previous value was unavailable. Status8 or10 then admits C62.
Initially zero loads21600 in clock-mode0 or10800 for every nonzero mode.
Otherwise it decrements; reaching zero sets status40000000 before invoking
actual5F6800(actor,0). Its ordinary signed result is ignored as in the original.
Afterward the actor receives motion-classA0 and action4/0/0/0, then position/yaw
are captured through `save_action_pose`. The countdown is distinct from status
and hit-recovery timers. The direct function has no pause gate; behavior retains
its own surrounding admission. No wall-time scaling or update-count inference
changes these original per-invocation rules.

Both compilers pass709,511,182 combined assertions with identical observations.
The new source comparison has396,288 cases over all five owned ITEM banks plus
a controlled bank, including all65536 countdown values and3072 admitted
transitions. Sixteen actual model cases cover selected primary/shared-secondary
retirement, the earlier transferred flag and nonlocal transfer rejection.
Action fields, gauge, timer, status, inventory, auxiliary lists, claims and pose
snapshots compare against complete6687A0 and its actual child bodies. All89,597
source allocations and releases balance in the combined resource suite.

Two native World/frame/behavior compositions invoke the real timer, inventory
consumer and later action7 publication through UpdateOwner. Other frame/action
effects and selector5 transition notification remain declared providers. A
successful action7 notice clears D92 afterward; a rejected sink retains the
completed transition, transferred inventory and pending2000 flag. Four refusal/
lifetime groups cover unavailable identities, foreign binding and shutdown.
Fresh32,768-case original behavior regressions pass2,572,551 ordered trace words
per compiler, preserving the old unbound provider path. Both parent builds and
all eight integration tests per compiler pass. The first LLVM fixture compile
caught an ambiguous comparison-helper name; the corrected run keeps strict
warnings. Evidence: `native_actor_terminal_timer_qualification_v1.json`.

This supplies one real gauge-clearing producer and terminal caller. Other
initialization/import, periodic667420 progression and its cap transitions,
remaining actions/UI/transport/save consumers, coherent native game installation
and representative acceptance remain open.
