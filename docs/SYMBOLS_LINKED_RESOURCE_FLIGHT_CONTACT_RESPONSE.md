# Linked resource flight and contact response

Static File #1 US owned o2 analysis, 2026-11-05. Entire 0x583C50 body reviewed, including every exit and the owned six-row table. [Identity](FUNCTION_INDEX.md). No trajectory, sound or collision was executed. Offsets and masks hexadecimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x583C50](../recomp/config/output_ovl/o2/o2_00583C50_0x583c50.cpp) | `integrate_linked_resource_flight_apply_contact_policy_and_commit_pose` | Confirmed complete state machine and lookup; visible resource names partial | Resolves linked object from3C564C+60 decimal*byte3. Null or linked23C bit20000 sets phase8=FF. Phase0 enters1,render1=0,timerC=60 decimal,copies linked velocity20C XYZ toC0,angular increments224..22A to98..9E,and adds work yaw92 to linked21E; falls through phase1. Phase1 subtracts signed-halfword(1<<3243CC) from timerC. Negative timer increments phase to2, skips contact handling, but still integrates/commits this call. Nonzero contact116 otherwise selects resource-specific or generic policy described below. Integration always subtracts1 fromC4 for3243CC=0,else2, adds velocityC0 to XYZ38 and copies XYZ to linked200; adds work98/9A/9C to linked21C/21E/220. Phase2 ORs linked23C bit40000000 if pointer nonnull, then sets work115 bit1 and lifetime12=1. Other phases, including FF, set the work stop bit/lifetime without moving. No owner admission, index bound, normalized vector precondition or divisor operation here. |

In phase1, resources with linked half36 in {72,9B,9C,9D,9E,9F} enter the six-row policy table. Resource72 first queries floor616F20 at current XYZ with maskFF, uses height+3, and when returned type is notFF constructs type14/descriptor6A/bank0/lifetime2 at that position through5822A0, then calls6B2760(owner28,position). It still proceeds through the table even if that query returnsFF.

The six table triples at708EF0 are `(resource, replacement descriptor, sound selector)`:

| Resource | Descriptor | Sound selector |
| --- | --- | --- |
|72|69|12|
|9C|65|12|
|9F|64|12|
|9D|0|12|
|9E|0|12|
|9B|0|12|

When all contact bytes117..11A equalFF and contact116 is1 or2, a matching table row calls1BA5E0(work,sound selector). A nonzero descriptor clears115 bit1 and attaches that descriptor in bank0. Match with zero descriptor, attachment case and no match all increment phase. These branches clear contact116 before integration. Sound request does not prove playback.

Other resources: if any byte117..11A differs fromFF, multiply velocityX/Z by owned73DF50=-0.3f. If all four equalFF and116==1, compute `T=cross(work160,velocity)`, `T=2*T`, `T=cross(T,work160)`, `T=T-velocity` with original191E50/3705E0/370570, then replace only velocityX/Z with0.3*T.X/Z (owned73DF58); velocityY remains as before gravity. This is the literal double-cross construction, not asserted equivalent to a unit-normal reflection. If all four equalFF and116!=1, increment phase instead. All these generic contact branches clear116, then perform the same integration. No-contact branch also performs integration.

Owned708EF0[18] hex `7269129c65129f64129d00129e00129b0012`, SHA-256 `019b4395b19d47c66c4a1ea183591c2bd86d40552897713df1fc1b54151d1c39`. Constant73DF50 bytes`9a9999be`, SHA-256 `7789e3a0f83ccd29ff3405eeb59cf2fc8f09a5e275f557def60de0f24ecf893d`;73DF58 bytes`9a99993e`, SHA-256 `45a6d738a7607576d3fe0862200bc67b10c12d5ed74167b4d5d5a708974c0f32`.

[Constructor](SYMBOLS_RESOURCE_BOUND_POSE_WORK_CONSTRUCTION.md) selects type9; [pool service](SYMBOLS_SCENE_POSE_WORK_POOL_AND_CALLBACK_SERVICE.md) performs the outer lifetime decrement and render gate. [VU0 vector contracts](SYMBOLS_OVERLAY_MATH.md) and [cross product](SYMBOLS_RENDER_MATH.md) establish child operations. These vector helpers are separate from interpreting VU1 geometry programs; this body establishes no measured rendering bottleneck.
