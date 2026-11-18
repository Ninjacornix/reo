# Actor 6D alignment, movement and sound helpers

Static File #1 US research, 2026-11-04. Eleven complete original bodies
reviewed. Addresses and offsets are hex unless marked decimal. Actor identity,
original action names and coordinate conventions remain uncertain. No target
execution, engine edits, replay, attachment or measured slowdown claim.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6D2340](../recomp/config/output_ovl/o2/o2_006D2340_0x6d2340.cpp) | `consume_actor_6d_alignment_local_and_world_deltas_and_commit_matrix_candidate` | High mechanics; probable role | Resets actor matrix50,builds rotation from signed90/92/94. BA3 nonzero additionally converts quaternionD18 through192250 and composes1913E0. Transforms localD8..E0 using1919D0,adds result plus worldE4..EC to currentXYZ38..40,clears both delta triples,commits XYZ to matrix translation80/84/88. Does not clear animation root4E4,apply collisions or alter game time. |
| [o2 0x6D37A0](../recomp/config/output_ovl/o2/o2_006D37A0_0x6d37a0.cpp) | `test_actor_6d_forward_trace_in_selector29_alignment_mode_two_candidate` | High mechanics; probable role | Requires3243DA==29,C390,BA3==2. Length of motionC0 must compare>0; scales it to decimal130 then adds currentXYZ as trace endpoint.5795E0(start,end,stackouts,-1,0,&flags) must return nonzero; result flags bit1 set and100000 clear then returns1. All other admitted query paths0. Output points otherwise unused. No trace frequency or cost measurement. |
| [o2 0x6D38B0](../recomp/config/output_ovl/o2/o2_006D38B0_0x6d38b0.cpp) | `select_actor_6d_motion_descriptor_with_exit_yaw_and_conditional_blend_candidate` | High mechanics; probable role | a0 actor,a1 full requested descriptor,f12 initial frame. If signed current520==full a1, advances58C300 at1. Otherwise old descriptor11/18/1B/C subtracts8000 from yaw. Blend defaults0; primary byte8==1 and old descriptor outside2/3/11/16/5/C sets blend=decimal5*byte74F200. Calls5A85F0(actor,signed-low16 requested,original f12,computed blend). Comparison precedes low16 narrowing of requested descriptor. |
| [o2 0x6D39E0](../recomp/config/output_ovl/o2/o2_006D39E0_0x6d39e0.cpp) | `select_actor_6d_base_motion_for_primary_four_response_candidate` | High routing | Primary4 uses descriptor15 when secondary2,otherwise14; other primary0. Calls5A85F0(frame0,blend0),then58C7B0. No action-byte writes. |
| [o2 0x6D3A70](../recomp/config/output_ovl/o2/o2_006D3A70_0x6d3a70.cpp) | `select_actor_6d_descriptor_one_for_modes_one_or_four_candidate` | High routing | a1 signed-lowbyte==1/4 calls38B0(actor,descriptor1,frame0),otherwise descriptor0; then58C7B0. Inherits38B0 possible yaw change or animation advancement when descriptor already selected. |
| [o2 0x6D3AF0](../recomp/config/output_ovl/o2/o2_006D3AF0_0x6d3af0.cpp) | `compute_actor_6d_target_heading_in_alignment_frame_candidate` | High mechanics; probable role | a0 actor,a1 targetXYZ. BA3==0 uses376E70(currentXYZ,target). Mode1 builds up-to-directionD00 quaternion via5A8220,converts to matrix192250,transforms homogeneous target-current displacement370420 through191A40,then heading from zeroXYZ. Mode2 composes up->D00 and D00->down quaternions using192360 before same transform/heading. Other modes return without a locally defined result. Owned731690=(0,1,0),7316A0=(0,-1,0); no input normalization added. |
| [o2 0x6D3C70](../recomp/config/output_ovl/o2/o2_006D3C70_0x6d3c70.cpp) | `derive_actor_6d_ballistic_timer_from_height_and_velocity_candidate` | High mathematics; probable role | f12 height-like input,f13 initial velocity. Stores AC=f13,D0=float(byte74F200). Signed-half E receives guest cvt.w.s of (velocity+sqrt(velocity^2+2*factor*f12))/factor. Only exactly0 narrowed result replaced1; negative values are retained. No zero-factor or negative-radicand guard in this original body. Units and actual caller motion remain separate. |
| [o2 0x6D3D30](../recomp/config/output_ovl/o2/o2_006D3D30_0x6d3d30.cpp) | `refresh_actor_6d_alignment_quaternion_and_commit_movement_candidate` | High mechanics; probable role | State1/7 first copies currentXYZ to80/84/88. Then5A82A0(outD18,directionD00,signed BA3) rebuilds alignment quaternion and2340 consumes movement deltas/publishes matrix. Initial snapshot and final matrix translation writes both retained; no global-clock change. |
| [o2 0x6D3DA0](../recomp/config/output_ovl/o2/o2_006D3DA0_0x6d3da0.cpp) | `test_actor_6d_cached_target_class_one_within_500_candidate` | High mechanics; probable role | Requires BA3==0,CCB==0,CC2==1 and unsigned CC3<6. Owned741060 six pointers all enter3E00. Computes CB0=CA4-currentXYZ,fullXYZ length,CC0=CBE-yaw92; returns1 only distance<decimal500. Both delta outputs still written on distance rejection. Failed preconditions0 without those writes. |
| [o2 0x6D3E60](../recomp/config/output_ovl/o2/o2_006D3E60_0x6d3e60.cpp) | `select_actor_6d_primary_one_secondary_eight` | Confirmed/static mechanics | Writes action8=1,secondary9=8,phasesA/B=0; no calls,transform or motion selection. |
| [o2 0x6D3E80](../recomp/config/output_ovl/o2/o2_006D3E80_0x6d3e80.cpp) | `dispatch_actor_6d_motion_primary_track_sound_crossings_candidate` | High mechanics; probable role | Switches motion1F2 across eighteen literal IDs and calls mapped5A9250(frame,actor,baseEvent,variantCount,original stepf12). Default no callback. Ordered crossing arguments listed below; same-frame paired requests retained. Preserves f12 throughf20 after calls. Does not advance animation itself or mix sound. |

Crossing arguments are hex triples(frame,baseEvent,variantCount), with actor
argument omitted only from this table.5A9250 applies its own primary-track frame
crossing test and conditional random variant selection:

| Motion | Ordered crossings |
| --- | --- |
| 64 | (0,B,0) |
| C8 | (2,0,2),(C,0,2) |
| C9 | (10,0,2),(1A,0,2),(32,0,2),(40,0,2) |
| CA | (1E,0,2),(34,0,2),(46,0,2),(52,0,2),(6C,0,2),(78,0,2) |
| CD | (C,2,0) |
| CE/CF | (10,0,2),(1C,0,2) |
| 12C | (10,5,0),(2A,0,2) |
| 12D | (12,0,2),(1E,0,2),(7E,3,0),(98,2,0) |
| 12E | (2A,5,0) |
| 12F | (14,3,0),(32,2,0) |
| 191 | (16,0,2),(3E,4,0) |
| 192 | (16,4,0),(22,4,0) |
| 193 | (0,2,0),(20,0,2),(32,0,2),(44,0,2) |
| 194 | (36,2,0),(3C,0,2) |
| 195 | (0,7,0),(16,0,2),(20,0,2),(60,0,2),(76,0,2),(B2,4,0),(C0,4,0) |
| 196 | (0,7,0),both(16,6,0)/(16,B,0),both(22,6,0)/(22,B,0),both(2C,6,0)/(2C,B,0),both(38,6,0)/(38,B,0),both(4C,6,0)/(4C,B,0),both(5E,6,0)/(5E,B,0),(6E,A,0) |
| 199 | (8,4,0),(20,4,0) |

All listed switch paths were followed through their actual branch targets and
delay slots. Mode names, target class semantics and player-visible actions
remain candidates. Related [alignment quaternion helper](SYMBOLS_ACTOR_MODEL_STATE_HELPERS.md),
[animation sound adapters](SYMBOLS_ANIMATION_SOUND.md), and
[record route controls](SYMBOLS_RECORD_ROUTE_CONTROLS.md).
