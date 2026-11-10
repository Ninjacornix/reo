# Native resource debris lifetime and floor consumer

The canonical `PeriodicVisuals` owner now implements5DF2A0/5DF340 resource debris
and the complete58FBC0/58FD10/58FE50 ballistic lifetime. It uses the same168-work
capacity as periodic effects, fog, surface work and resource companions. There
is no second debris pool. Construction copies the actual resource model pose;
subsequent model retirement does not retarget or invalidate that copied state.

The four part offsets, phase table, gravity and fade constants are audited
against owned o2 bytes. Initialization preserves all five session RNG advances,
including values subsequently forced to zero. Signed-halfword angle/delay
wrapping, position-before-velocity integration, delayed alpha fading and the
strict below-zero retirement threshold match the original. The floor query
still executes after an alpha transition to phase2. The next phase2 invocation
retires the same native identity.

Floor queries use the actual current `ResourceFactory` room/grid lease and the
existing qualified `trace::floor` implementation. Room changes invalidate the
old floor binding. A weak factory token rejects retirement without reading a
destroyed owner. A missing room/factory capability retains the known integration
prefix, reports failure and publishes no successful new frame. Earlier retained
immutable frames remain readable after failure or shutdown.

This constructor selects effect metadata through652E20; it does not construct
children. Its admitted lifecycle allocates no256-pool children. Paired checks
also prove debris can allocate with that child pool full. Native output retains
its typed effect, part, basis, position, angle, velocity, alpha and lifetime state;
it does not invent sampled child rendering. Rendering submission belongs to
Stage5. The related source/draw findings and corrected signed-immediate addresses
are [recorded separately](RESOURCE_DEPLETION_INVESTIGATION.md).

Both compilers pass265,223,723 combined assertions each. Debris-specific checks
include65,968 constructor/initialization cases,70,248 updates,184 known missing
resources,48 capacity groups and48 refusal groups. All six owned effect banks,
all16-bit RNG seeds/angle/delay values, fade boundaries, floor crossing and
out-of-grid behavior, model retirement and actual shared-pool capacity are
covered. Floor geometry in this composition is controlled; the reused trace
internals have independent owned-grid qualification. The source57D560 boundary
is explicitly delegated to that actual native consumer, not claimed as a new
comparison of its internals.

Both parent builds/eight integration checks pass, as do current scenario VM
comparisons (14,080,853 assertions per compiler). The complete original phase
tail targets execute in the oracle. Exact inputs and results are sealed in
`native_resource_debris_qualification_v1.json`.

Comparison builds now compile original bodies separately from the fresh fixture.
Reusable objects are identified by exact compiler, generated bodies, runtime
headers and flags, hash-verified and copied into each cohort. The LLVM transition
produced identical observations before/after separation; the next changed-fixture
cohort reused the verified object. Every fixture and executable is still rebuilt.
This changes development checks, not game behavior.

Weapon depletion/cost still needs composition with actual cue and weapon refresh
consumers. Gameplay installation, remaining Stage4 owners/callers and coherent
scenario acceptance remain open. Installed V39 is unchanged. No game, physical
audio device or foreground test was used; Stage4 remains incomplete.
