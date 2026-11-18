# Native AI execution state

2026-11-10. Goal/action state primitives and weight-profile selection are
qualified components. Stage4 remains incomplete; installed gameplay remains V39.

The actual World Actor now has an optional `ExecutionState`. Its goal/current
and previous IDs, execution-action IDs, phase bytes, goal parameters and weight
banks are logical fields. They are separate from navigation edge actions.
An actual producer/import must establish this component; calling a setter does
not invent missing prior state. UpdateOwner checks actor identity and presence.

Complete813380 clears goal phases/parameters. A nonzero **low halfword** clears
the refresh byte and preserves the old previous-goal field. A zero low halfword
sets refresh and copies current goal to previous goal. The older mapping note's
low-byte wording was wrong:8133A8 uses ANDI FFFF. Input256 is nonzero, while65536
resets. Complete81A6E0 always copies the previous action, narrows the new action
and calls complete81A6F0 to clear its phases/marker. Complete814B30 resets goal
zero and returns zero; its full dispatcher is not yet migrated.

Complete8123E0 selects one of twenty immutable56-byte authored profiles. The
native state stores a logical index, replacing the original pointer. Selection
copies eight base weights, clears reactive/status banks and preserves combined
weights. Indices20 and above preserve the original no-op. Negative input would
address adjacent original content and remains explicitly unavailable.

Both compiler comparisons pass6629721 identical checks:131072 goal resets,
131072 action selections,256 action-phase resets,65536 complete goal-six calls,
256 nonnegative profile calls and four negative refusals. Every unsigned
halfword is tested with two high-halfword patterns. All twenty authored profile
rows match the pinned owned overlay exactly. Complete original107AB0 executes;
the two exact eight-byte zero fills are declared original-only surroundings.

Both parent builds and twelve integration tests pass, including actual Owner
composition, route/execution action separation, profile bank preservation,
missing component and foreign/retired/closed identity checks. Evidence is sealed
by `native_gameplay_ai_execution_qualification_v1.json` (SHA256
`9c508c4e2da02f72ee3c59baf5d7cc205f66ef7524dea673e0fefdb2a1203a2c`).

Full initialization/control production, observations, goal reevaluation and
remaining goal/action callbacks, actual input/network/save ownership and coherent
native game installation/acceptance remain open. No game was launched, slowdown
reproduced or speed change measured for this work.
