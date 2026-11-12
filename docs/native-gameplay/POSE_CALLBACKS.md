# Pose cloud, motion and quarter-turn arcs

Native callbacks implemented and qualified, 2026-11-12. Stage4 remains
incomplete; no game, audio device, window or power action was used here.

The five callbacks5846C0,584160,583BF0,583430 and5835E0 use the existing canonical
`Actor`, `PoseWorkState` and64-slot `PoseWorkPool`. There is no extra trajectory
or timer pool. They compose through `PoseCloudUpdates`, `PoseMotionUpdates` and
`RoomPoseArcs`; reached callbacks outside their actual families require another
concrete consumer.

The cloud callback creates effect55, sets both lifetime and timer to75, requests
the real gated6B2680 light, and decrements the timer in the initial call. Its
retirement predicate uses the old timer. The outer lifetime can expire first.
The authored7123F5 value0xC0 is a child-enable mask:6525D0 forwards a2 to child
enablement and t0 to animation-group variation. The variation here is0. An
early owner test caught and corrected treating that mask as a variation.

`PoseCloudUpdates` uses the real shared168-work/256-piece `PeriodicVisuals` and
existing task/light owners. Five of the six owned effect banks complete their
tested lifecycles. EF28/EF41 have no geometry55, so the original constructor's
early no-effect result applies before their unconsumed efdata mapping. EF35's
actual empty group255 remains admitted. EF02 has geometry55 but maps it to an
unadmitted apparent group255 part table. That path reports unavailable after
the completed constructor/update prefix. It does not fabricate a replacement
group, reinterpret an invalid table or claim an original continuation.

The vertical callback preserves FP32 velocity/acceleration and signed timer
ordering, including contact termination without a timer decrement. Its74F200
timing quantum requires a read-only view of the actual producer. It is not
aliased to3243CC `clock_mode`; an absent producer preserves the reached prefix
and reports unavailable. The isolated numeric profile includes the audited
SDK/R5900 divide-by-zero result. This does not establish that a real scene uses
a zero quantum. The Z-offset callback subtracts400 only on its first phase and
subsequently decrements its timer only without contact; it has no local expiry.

The quarter-turn arcs preserve variant/yaw narrowing, their separate velocity
and acceleration profiles, initial-call return, rotated position integration,
floor-height publication and retirement. The complete5833B0 operation uses the
existing qualified native Euler/trig/matrix helpers. `RoomPoseArcs` queries real
retained room generations; unknown or retired rooms refuse rather than becoming
successful misses. Kind16 additionally requires actual578620 trail consumers
on its two reached initial calls. Those emitters remain a separate integration
requirement.

| Immutable dual-compiler cohort | Observed coverage per compiler |
| --- | --- |
|`pose-cloud-policy-*-v2`|1,540,100 checks;262,144 complete5846C0 states;98,304 observed retirements|
|`pose-cloud-owner-*-v5`|255,268 checks;1,110 actual constructors;120 full pool/visual/task lifecycles over9,120 frames;444 known missing-geometry results;one explicit bank-profile refusal|
|`pose-motion-policy-*-v1`|2,752,199 checks;524,288 complete584160/583BF0 states;130,758 observed retirements|
|`pose-arcs-policy-*-v1`|2,818,081 checks;393,216 complete arc states with full original math;131,072 floor queries and131,072 ordered trail requests|
|`pose-callbacks-current-*-v2`|1,267 checks against the current CMake graph;all six owned banks;380 cloud frames;six real-room/generation cases;one bank refusal;registered contract passes;670 source inputs and52 native archives|

Original callback/helper instructions and owned constants are checked against
the pinned executable/overlays. Private comparisons retain exact headers and
matching immutable native archives. Current CMake qualification rebuilds the
actual dependency graph and rejects source drift. Earlier failed cohorts are
retained, including the mask/variation discovery, bank-admission investigation
and a strict GCC fixture-formatting warning.

These components still need complete frame/session installation, the remaining
pose callbacks and producers, and installed gameplay/transition/save-resume
acceptance. The current contract is a native owner test, not a game playtest.
