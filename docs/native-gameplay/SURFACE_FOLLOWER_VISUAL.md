# Surface follower visual

Status2026-11-12: the actual584760 caller's58DA20 subtype0 constructor,
58DAB0 dispatch and58DB50 billboard lifetime now use `PeriodicVisuals` and
`ForwardPoseVisuals`. This is a CPU/state/ownership qualification. It does not
claim Stage4 completion, a rendered native billboard or installed-game acceptance.

The constructor uses the same168 work slots as existing effects and consumes
no256 track-child slots. Category7 and subtype0 retain the original cleared
constructor state. Phase0 copies the retained parent's position, enables the
billboard and sets its actual color, scale,22-tick delay and two-by-four tile
cadence; delay decrements during that same first call. Phase2 hides before the
following retirement. An actual null parent and unexpected phases retire.
Signed16 timer/column/row wrapping follows the source. The parent activity byte
is not a source liveness gate and is not invented as one by the native policy.

The actual pose-projectile adapter creates the follower in that shared owner
and writes its position directly, preserving first-callback initialization order.
Pool exhaustion is an admitted no-visual result; missing ownership is a failure.
A retained actor generation never retargets a subsequently recycled physical
slot. This is explicit native identity protection; the comparison fixture does
not claim to reproduce unsafe original pointer reuse. Room/application teardown
closes the visual owner. Immutable frames preserve old billboard state while
simulation continues. No original address, callback pointer or emulated work
record is stored in production native state.

Each compiler passes38,535,168 pure-policy checks across2,621,440 complete
original58DB50 cases, including all signed16 delay/interval/row/column values,
null/present parents and unusual phases. The first comparison caught the
unexpected-phase retirement branch; final pairedv2 receipts cover its correction.
The current six-bank ownership contract passes3,086 checks and the whole
constructor/dispatcher comparison10,346 checks, each with480 moving frames,
1,020 counted constructor cases, six full-pool controls and twelve generation/
retention controls. Original651A30 allocation/category/592-byte clear and651D00
retirement are declared observation boundaries; actual native shared capacity,
lookup, updates and retirement are exercised independently.

The final paired current graph passes34 CTests and actual resource, session
Dialogue,33 speech clips and227 room-light keys. The first owned Dialogue test
failed because its isolated inactive-actor fixture lacked required coordinator
channels; its corrected fixture explicitly supplies the same controlled channels
as prior DialogueWorkers tests. Production Dialogue code was unchanged.

Only subtype0, actually requested by584760, is admitted. Other58DAB0 subtype
bodies remain separate work. The immutable payload preserves billboard CPU
parameters; texture resolution, GPU commands and pixel parity belong to Stage5.
Remaining ground attachments57F990/57FAA0, delayed bursts, sound/variant producers,
whole native frame installation and end-to-end game acceptance remain open.
