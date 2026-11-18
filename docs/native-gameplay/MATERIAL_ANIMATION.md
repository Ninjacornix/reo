# Native linked-actor material animation

The complete File #1 callback5D0C90 now has a native implementation and a real
consumer in `gameplay_update::Owner`. `MaterialAnimations` borrows the World's
actual linked actors and the existing32-entry `Scheduler`. It creates no extra
actor or task pool. The reviewed6BA5C0 constructor requests this callback for
class27. [Native scripted construction](SCRIPTED_ACTOR_CONSTRUCTION.md) now
adopts this task. Installing native gameplay remains open.

The first callback sets phase1, clears the secondary phase, initializes450/90
timers and sets presentation mask1. It leaves the actor's UVs untouched. Later
phase1 callbacks decrement each signed16-bit timer with wrapping, reset negative
results to449/89, and publish timer/450 and timer/90. Other phases leave state
alone. There is no host time scaling or guessed terminal phase. Initialization
changes only the task's presentation mask, preserving its other policies.

`Actor.material_uv` represents the linked visual family's D24/D28. It never
aliases the primary family's `control_elapsed` at D28. The real linked-pool
allocator supplies the known zero initial UVs from its cleared actor record.
Arbitrary primary actors do not gain this capability. Creation also requires
actual linked-pool membership, a live World identity, and the UV component.

Tasks retain native generation identities. Retirement, pool reset, World close
or removal of the UV capability retires the task before further writes. An old
actor lease and a new occupant cannot retarget one another. Component closure
seals its own admission before erasing its tasks, and Update closure seals the
shared scheduler first. Models, UVs, callbacks and observers have no ownership
cycle. Separate scheduler users keep their own tasks and capacity.

The original comparison executes the complete checked5D0C90 body. Cases cover
all256 phases, every signed16-bit value for both timers, and1802 consecutive
updates. Each of the67,594 calls compares the entire actor and task projections,
including untouched bytes and arbitrary preserved UV bit patterns. Production
contains no original CPU context, instruction execution or guest-memory model.

The actual Update worker tests cover pause, first-call preservation, subsequent
UV publication, duplicate-task ordering, presentation exclusion, shared32-entry
capacity, pool reset, stale identities, replacement, independent component
destruction and both closure orders. They also assert that primary control state
and unrelated task policies survive. Full scenario comparisons and the tasks,
cooperative update, collision worker and AI owner regressions run with LLVM and
GCC. Qualification identities are recorded in
`tools/native_reconstruction/native_material_animation_qualification_v1.json`.

Reproduce the original comparisons with
`python tools/native_reconstruction/gameplay_scenario/verify.py --compiler <compiler> --output build-native-sjuni/<fresh-directory>`.
Build `gameplay_tasks_tests`, `gameplay_cooperative_events_tests`,
`gameplay_collision_workers_tests` and `gameplay_ai_owner_tests` in the native
CMake tree, then run their corresponding CTest entries. These are component and
composition checks. They do not establish installed gameplay or close Step4.
