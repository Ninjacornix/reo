# Resource flight effects

The native recorder-independent gameplay core now supplies the actual58E6D0
flight constructor and58E850 lifetime through `PeriodicVisuals`. These use its
existing168 work slots, canonical session RNG, retained effect geometry, actual
room wall/floor traces and the canonical `BasicAudio` frontend. `FlightWeaponEffects`
connects this family to firing; other families still require their own consumers.
This code is not installed in V39 and does not complete Stage4.

Construction uses the complete32-entry owned style map. Authored FF entries,
missing resources and natural pool exhaustion retain normal no-effect outcomes.
The constructor derives yaw from the input Y axis, constructs a fresh identity
basis and applies the owned offset. It does not copy the input basis. Outputs
retain geometry and immutable flight state for the later native renderer.

The update preserves the45-tick lifetime, delayed retirement, exact FP32 X/Y
integration, wall correction, floor bounce, canonical RNG order, sticky81 floor
behavior and four-tick cue cooldown. The original overwrites the wall-hit scratch
point with the basis origin before its floor query; a floor miss therefore cues
at that origin. Non-player audio follows the original category1 gate and actor
position. Ignored bank outcomes remain distinguishable from audible success.

Room capture is lazy: expiry and retirement require no room provider. Reached
queries require a retained invocation of the canonical current room, and reject
generation replacement. Missing audio/room capabilities preserve the measured
prefix and refuse publication. Retired parent identities cannot target reused
actors. No callback blocks on a game thread or adds another effect pool.

Both LLVM and GCC pass the complete original constructor/update policy corpus:
32,768 constructors and1,310,720 update cases, with22,014,002 assertions each.
The composed owner corpus passes1,152 cases and12,408 frames on each compiler,
including372 real cue requests,3,176,448 mixed PCM frames and2,172,728 nonzero
samples. Construction/state/audio comparisons use unchanged original bodies.
The existing visual corpus also passes7,200 updates and pool/concurrency checks.

The composed fixture retains stock wall/floor grids and real six effect-bank
pairs. Its explicit cue binding uses owned `weapon01.snd` in bank slots8..11/13;
it proves actual audio composition rather than the installed game's bank setup.
Original query ports call the independently qualified native trace operations;
their internal collision semantics are not requalified here. Geometry allocation,
render lookup and original retirement remain declared oracle ports. No rendering,
physical PS2 exceptional-value parity, installed game test or performance claim
is implied. Partial failed cohorts remain available alongside the final receipts.

Reproduce the frozen qualifications with `verify_resource_flight.py` and
`verify_periodic_visuals.py --resource-flights`; each requires the explicit owned
corpus/compiler paths. `qualify_resource_flight_v1.py` verifies source snapshots,
paired results, current parent receipts and both actual CMake target builds,
then writes the immutable qualification record.
