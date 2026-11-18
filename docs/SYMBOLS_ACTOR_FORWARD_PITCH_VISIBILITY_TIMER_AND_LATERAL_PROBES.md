# Forward pitch, visibility timer and lateral probes

Static File #1 US owned o2 analysis, 2026-11-05. Full65C780..65C9F7,65CA00..65CAE7,65CCF0..65CE5F and65CE60..65D1E7 reviewed, including all predicates, delay slots and returns. [Identity](FUNCTION_INDEX.md). No runtime work or measurements. Offsets/states/filters hexadecimal; distances/durations decimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x65C780](../recomp/config/output_ovl/o2/o2_0065C780_0x65c780.cpp) | `derive_actor_pitch_from_yaw_forward_floor_sample_and_reference_height_candidate` | High complete mechanics; original action unknown | GateC37/BA5/BA3; yaw-rotated owned(0,50,60) sample, floorquery, strict2<heightdifference<99, horizontal/full-distance angle and signedpitch90 conversion. Exact failure writes below. |
| [o2 0x65CA00](../recomp/config/output_ovl/o2/o2_0065CA00_0x65ca00.cpp) | `hide_c37_actor_and_periodically_request_state_e_under_room_owner_gate_candidate` | High complete mechanics; C37 meaning unknown | C37nonzero exceptaction1/D hidesrender1,32FF. Only local roomowner decrements12; expiryRNGbit0 andC36zero request65A9E0(actor,1,E),else reset600/byte74F200. |
| [o2 0x65CCF0](../recomp/config/output_ovl/o2/o2_0065CCF0_0x65ccf0.cpp) | `probe_lateral_yaw_offset_segment_and_enter_turn_or_response_state_candidate` | High complete mechanics; intended mode range partial | a0actor,a1yaw,a2signedmode. Scale150forwardvector byBC, rotateyaw +/-4000;5795E0 filter20FFFF; hit enters1/8 for secondary4..8 else1/3 andB=mode XOR1; missreturns0. |
| [o2 0x65CE60](../recomp/config/output_ovl/o2/o2_0065CE60_0x65ce60.cpp) | `probe_oriented_lateral_segment_and_admit_turn_on_height_or_missing_contact_candidate` | High complete admitted-mode mechanics; invalid mode unknown | a0actor,a1yaw,a2signedmode,a3XYZdirectionpointer. Modes0..3 define yaw, D18derivedorientation, endpointheight/D28 gate then constructed segment. HeightbelowD28 or query!=1 selects response1/8 or1/3; query1returns0. Uninitialized angle on other modes retained as limitation. |

## Pitch65C780

C37==1 orBA5==1 returns without changing pitch90. BA3!=0 clears pitch90 andreturns. Otherwise rotate owned7126C0=(0,50,60) by unsignedyaw92*binary32(2pi)/65536 using191BC0, add actorXYZ and query616F20(point,&type,FF). TypeFF returns without pitchwrite. Replace sampleY with returnedheight. Compute absolute difference from currentactorY using original orderedcomparisons. Difference<=2 or not<99 clears pitch90. Only strict(2,99) proceeds.

ReferenceP=(actorX,actor170,actorZ),sampleQ=(sampleX,height,sampleZ),horizontalQ=(sampleX,actor170,sampleZ). Use191D10(P,horizontalQ)/191D10(P,Q); exactlyzero denominator replaced by binary32(0.0001). Call192100(ratio),scale result by65536/binary32(2pi),add0.5 andoriginalCVT.W.S. Store signedlow16 to pitch90, negated whenactor170<=sampleheight; otherwisepositive. No ratio clamp, finiteness normalization or positionwrite occurs. These notes preserve the numeric transcendental call without claiming an independently recovered original function name.

## Visibility timer65CA00

C37==0 returns. Action8==1 andsecondary9==D returns before hiding. Allother admitted calls clear renderbyte1 andset32=FF, then compare local4BADED to1B0240(room1E2). Mismatchreturnswithouttimercounterupdate. Match predecrements signedhalf12; newnonnegative returns. Negative draws1AEC80(1):lowbit1 withC36==0 calls65A9E0(actor,1,E) andreturns without resetting12. Allotheroutcomesstore signedintegerquotient600/unsignedbyte74F200 to12. No divisor-zero guard or wallclock present; original room authority and game update cadence govern the timer.

## Lateral segment65CCF0

Scale owned7126E0=(0,0,150) by actorBC through3705E0. Let M=signedlow8a2. Angle=signedlow16(a1)+(M==0?4000:-4000),wrappedlow16; rotate byunsignedangle*2pi/65536 thenaddactorXYZ. Query5795E0(actorXYZ,endpoint,outpoint,outnormal,20FFFF,0,&type). Missreturns0withoutstatechange. Any nonzero hit:secondary9 in[4,8] invokes65A9E0(actor,1,8); others65A9E0(actor,1,3),thenstorelow8(M XOR1) toB. Returns1. There is no contact-type rejection, originalrequestedM normalization or outputpointcopy to actor. M outside0/1 still chooses the nonzero rotation branch and writes its XOR lowbyte on the3responsepath.

## Oriented lateral segment65CE60

M=signedlow8a2, D=a3inputXYZpointer. Scale owned7126F0=(0,0,150) by actorBC. Modes0/2 usewrapped(a1+4000),1/3usewrapped(a1-4000); other modes reachrotationusingincoming savedregisters1 without a local definition. No valid default angle or calleradmission is inferred for those modes.

For modes0..3 rotatevector byangle*2pi/65536,call192250(actorD18,localmatrix),transformrotatedvector bylocalmatrix using191A40,addactorXYZ toQ. If Q.Y<actorD28, respond immediately:secondary[4,7] enters65A9E0(actor,1,8); others enter(actor,1,3) andB=((M&1) XOR1);return1.

Otherwise construct endpoints with X/Z arithmetic only, keeping Q.Y:

- SignedM<2: Q.X +=actorD00*(150*actorB4), Q.Z +=actorD08*(150*actorBC). CopyQtoR; R.X -=D.X*(150*actorB4),R.Z -=D.Z*(150*actorBC).
- SignedM>=2: Q.X -=actorD00*(150*actorB4),Q.Z -=actorD08*(150*actorBC). CopyQtoR,then **modifyQ**, Q.X +=D.X*(150*actorB4),Q.Z +=D.Z*(150*actorBC). This deliberate asymmetry preserves the actual two endpoints.

Query5795E0(Q,R,outpoint,outnormal,FFFFFFFF,0,&type). Result exactly1 returns0withoutstatechange. Otherresults use the same response/secondary[4,7] rule above andreturn1. The helper itself returns Boolean, but the exact comparison and opposite admission relativeto65CCF0 are retained. D is unchecked andreadsonlyX/Z. Contact point/normal/type are not committed to actor in either branch.

Owned literal evidence:7126C0[12]=`000000000000484200007042`,SHA-256 `ee860866e3b8a1b198c5c2e89a98c9a41a1b352b058e6d8e9dfa0feaa8d89dd3`;7126E0[12] and7126F0[12]=`000000000000000000001643`,SHA-256 `f890c982011824adde5f2b415fbdfa25005ada48c4bf31174ee835785feb233a` each.740330[4]=`db0fc940`,binary32(6.2831854820251465),SHA-256 `12d85026b5109a3119231704608d5991a63d8d397d2867a9fc522305810ddb76`;7402E0[4]=`17b7d138`,binary32(0.00009999999747378752),SHA-256 `0f2f3591427956b004ca17393783192e0f81858c06bb5496aa2cea004f1ee863`.

[Segment query](SYMBOLS_SEGMENT_SWEEP_CONTACT_HELPERS.md), [state entry](SYMBOLS_ACTOR_65A_BASE_TARGET_SELECTION_AND_ENTRY_TIMERS.md), [session roomowner](SYMBOLS_SESSION_INPUT_STATUS.md) and [related recovery relocation](SYMBOLS_ACTOR_659380_SURFACE_REENTRY_AND_RELOCATION.md) establish supporting contracts. No live collision, visibility problem or slowdown was observed. ActorD18/D28 meanings and invalid-mode callerinvariants remain unresolved.
