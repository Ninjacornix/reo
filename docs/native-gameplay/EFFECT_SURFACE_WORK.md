# Native room effect modulation and actor water surfaces

Qualified component checkpoint, 2026-11-09. This component is
not installed in the game and does not complete Stage4.

`Modulation` owns the one shared room flag halfword and color/intensity values.
Construction requires explicit native initial state. `reset` implements only
the corresponding fields of the room reset; the full room reset caller remains
an integration gate. Selector1 retains the original unsigned-word conversion
sequence and division by1000. Other selectors leave state unchanged.

`PeriodicVisuals` supplies the actual5DFA90 factory and5EA970 update through
its existing168 work identities and256 child slots. There is no second ripple
pool or scheduler. The canonical World holds an explicitly known primary
population, independently of actor active/visible bits. Factory admission
requires that count be known, at most8, and backed by registered actors.
An unknown count or missing actor is refused before changing modulation.
Natural work-pool exhaustion continues through later population entries.

Each watcher retains its native actor generation. It reads the actual World
room, canonical collision.pose_ready (original198), published native model
snapshot, retained room floor Grid and canonical session RNG. The source198
field is not the actor visible byte. Watchers are hidden and own no child
geometry. Source renderer371EF0 remains a Stage5 boundary.

The eleven joint records come from owned70BF48, not71BF48: the low half of
the original address construction is a signed addiu. Their actual independent
scales include1.2/1/1.2. The existing scaled visual consumer therefore receives
all three scale components, the second angle for descriptor36hex, exact child
masks255/254 and shared feedback color/intensity. Variant remains0.

The callback preserves initialization and room/pose early-outs, signed byte
cooldowns, all eleven previous positions, surface-height offsets, crossings
and the separate horizontal movement threshold. The two cooldowns reset only
when their respective allocation succeeds. Missing effect roots and full pools
are natural misses; neither silently resets a cooldown. RNG is drawn once per
eligible joint before those allocation attempts, even when both miss.

During a work pass, new effects enter the head and wait until the next pass.
Immutable published frames may retain their initial hidden state. Retiring a
native actor generation retires its watcher rather than retargeting a reused
slot. This is an explicit ownership repair to the original raw actor pointer.
Retained room/model/frame leases preserve backing data; stale room leases or
unsupported numerical/resource profiles produce diagnostics failure with prior
effects retained, not guessed success or an automatic legacy retry.

The [explicit floor-type correction](FLOOR_EXPLICIT_SURFACE_TYPES.md) is a
prerequisite: generic floor requests exclude high-bit surfaces, while a matching
explicit81 request admits water.

Qualification uses complete owned690490/5DFA90/5EA970, actual shared pool and
effect constructors, actual scaled/material updates, original floor import and
query, and original RNG. Native model rebuilds provide controlled external
poses; their independent animation qualification is reused. Resource heap/cache
and bounded memory operations are declared test-only surroundings. The room
lease fixture owns real native geometry and lifetime; it is not the game's
resource installer. A coherent room installer, aggregate room reset, scenario
dispatch installation and game acceptance remain required.

Fresh LLVM/GCC surface cohorts each pass767347 checks:16400 modulation cases,
8076 callback frames,3513 created effects,216 shared-pool factory profiles and
384 complete World/room/watcher/child passes across all six owned effect banks.
Each executes4851851 original helper calls. The unchanged general/periodic/fog
regression passes3888287 checks and20425446 original calls per compiler.
Source closures and immutable copies are recorded in
`native_effect_surface_work_qualification_v1.json`. Initial draft differences
in crossing rules and success-only cooldown resets were caught before sealing;
their failed/debug cohorts remain retained. A first GCC fixture compilation
also rejected misleading indentation and signed comparisons; the corrected
fresh pair uses identical production and fixture sources.
