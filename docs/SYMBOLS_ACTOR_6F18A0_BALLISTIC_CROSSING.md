# Actor 6F18A0 ballistic crossing state

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed.
Addresses/offsets hex unless marked decimal; velocity constants decimal.
Crossing is a candidate role inferred from fixed launch velocity, gravity,
phase transitions and landing; original actor/action identity is unknown.
No execution, attachment, build, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6F56E0](../recomp/config/output_ovl/o2/o2_006F56E0_0x6f56e0.cpp) | `dispatch_actor_6f18a0_primary_seven_ballistic_crossing_candidate` | High routing; probable role | Caches actor24 as75A108; null target calls77E0 and returns. Otherwise dispatches unchecked73C170[actor9], owned5750/5AF0, then5705F0(50,1,0). No target coordinate copy here. |
| [o2 0x6F5750](../recomp/config/output_ovl/o2/o2_006F5750_0x6f5750.cpp) | `tick_actor_6f18a0_primary_seven_high_ballistic_crossing_candidate` | High mechanics; probable role | A0/FF enters1, descriptorE/frame0/blend20 unless motion136; FF alsoC3640. Room50 transforms forward15 into velocityD58..D60 then replaces Y with45 ifD6C==16 else55; room56 forward7,Y55. X/Z accelerationCC/D4 are negative zero, gravityD0=-3. Other rooms retain advanced phase without setting these velocities. A1 advances until frame>=36, thenA2. A2 advances,BA5=1,54A=1, integrates full XYZ and all velocity components, entersA3 when Y velocity<0. A3 integrates Y and Z, with gravity updating Y velocity; does not advance animation or X in this phase. If currentY<field170 floor, snapsY, selectsdescriptorF/blend10,58C780,A4. A4 increments5,spawns effect81 at50 and falls through A5 animation advance;1F1bit40 resets77E0. |
| [o2 0x6F5AF0](../recomp/config/output_ovl/o2/o2_006F5AF0_0x6f5af0.cpp) | `tick_actor_6f18a0_primary_seven_low_ballistic_crossing_candidate` | High mechanics; probable role | Same phase structure and descriptorE/F as5750, but room50 forward15,Y24,gravity-4; room56 forward8,Y20,gravity-3. InitCC/D4 negativezero. A2 integrates XYZ with velocity/gravity and BA5/54A=1; A3 additionally advances58C300 on each tick while integrating only Y/Z, then snapsY to field170 and selects F at landing. A4 effect81 then A5 tick/reset on1F1bit40. These phase-specific differences are preserved; neither body is called redundant or a measured hotspot. |

Owned73C170 contains5750,5AF0; adjacent zero words do not extend the
known two-secondary table. Owned half73C5C8=136 is the initial motion
comparison. The original bodies use current floor-height field170, not a
fixed numeric landing Y. All integrations are original per-call arithmetic,
with no invented elapsed-time or performance semantics.

Related [pursuit](SYMBOLS_ACTOR_6F18A0_PURSUIT.md),
[route selection](SYMBOLS_ACTOR_6F18A0_ROUTE_STATES.md), and
[shared controls](SYMBOLS_ACTOR_6F18A0_SHARED_CONTROLS.md).
