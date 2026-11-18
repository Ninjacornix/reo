# Actor variant E update dispatch and supporting transforms

Static File #1 US research, 2026-11-04. This continues
[variant E reactions](SYMBOLS_ACTOR_VARIANT_E_REACTIONS.md) and the
[effect burst investigation](SYMBOLS_EFFECT_BURST_CONSTRUCTION.md).
“Variant E” is a research label,not a recovered actor name. Original identities
are recorded in [the central index](FUNCTION_INDEX.md). No game,build,replay,
attachment,live-memory inspection or implementation change was performed.

## Upstream action dispatch and state initialization

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5E0880](../recomp/config/output_ovl/o2/o2_005E0880_0x5e0880.cpp) | `tick_variant_e_actor_and_dispatch_primary_action_candidate` | Probable role; full body and action table reviewed | Saves XYZ38->44,angles90..96->A0..A6;clears54A/C82/32/C36,byte5 nonzero adds54A21. Calls5A9EF0(actor,related24),640210;13F nonzero calls5E4D00,nonzero return initializes5E4C20 and5A6B20(actor,2). SavesBA3->C29,probesY-1000 via57D630/616F20 toD10 on exact probe1. Health<=0 C94 OR201,positive clears bits1/200;always clears8 and OR40. Unbounded action8 table70BA50 dispatches0->5E0A60,1->5E0E10,2->5E2A20,3->5E39C0,4->5E43D0,5->5E44B0. Afterward5E5160,conditional65E3A0 whenC82==0,6347D0,5A7D00(actor,70BA40,CD8),5E53F0,5A6B20(actor,signedC36). No actor activity/null guard or action>=6 fallback. |
| [o2 0x5E0A60](../recomp/config/output_ovl/o2/o2_005E0A60_0x5e0a60.cpp) | `initialize_variant_e_actor_motion_flags_and_surface_state_candidate` | Probable role; full body reviewed | Builds matrix50 from signed90/92/94;showsbyte1=1,F0=1,C80=0,520=-1,BA5=1,C94 OR201/4,1A8=0,1D8=word710440,190=20FFFF,194=0,CE8/CFC=0. Copies16-byte color through global728FC4 toC70..C7C then1AC..1B8 and1BC..1C8;clearsBE8..BEB,C..13,setsD27=1,552=A,551=2,12=0. Class74F295 low2 nonzero chooses4/0/phase5 with floor probe orY=-2000. Otherwise savesXYZ D18;C2B nonzero chooses5/stateC2B,motion0,D27=0. Ordinary floor test chooses1/0/BA5=0/motion0 when actor below ground+1,else1/8/BA5=1/motion7(f12=20);probe failure also1/8. Calls5E4C20/C36=1 except direct action5 path. Does not initialize every actor field or allocate model. |
| [o2 0x5E0E10](../recomp/config/output_ovl/o2/o2_005E0E10_0x5e0e10.cpp) | `dispatch_variant_e_primary_one_after_shared_target_work_candidate` | Probable role; full body reviewed | Calls635E20(actor,C8C,A,f12=BCC,f13=BD0),then unbounded state9 word table70BA70 callback(actor). Distinct primary1 dispatch;table callers/admissions must establish valid state domain. No local phase/timer reset. |
| [o2 0x5E2A20](../recomp/config/output_ovl/o2/o2_005E2A20_0x5e2a20.cpp) | `dispatch_variant_e_primary_two_and_embedded_node84c_approach_candidate` | Probable role; full owner and tables reviewed | Unbounded state9 table70BAA8:0->internal5E2A40,1->5E3010,2->5E3600. Embedded0 requires related24 andphase0..5 through73EC20.0 initializesyaw/pitch,motion9,E=30/74F200,D0=4.1 rises andsteers,tick1,E<0->motionA/phase2.2 exact animation1 computesD00=20*normalized delta to target node84C,angles tosame node,motionB,clears115bit1,5DA2C0(10,1),phase3.3 integrates/floor-clamps;5A8590 nonzero advances4 and computesCC=D00/(E+1),98=-pitch/E with E=10/74F200 without reselecting motion. Alternative height/5E54F0 admission similarly enters4 butselectsD.4 integrates/turns;E<=0 enters5,zeros pitch/D00,CC=(0,owned.2,0),motionC.5 integrates/floor-clamps;exact animation1 yaw+=8000,motion7/f12=20,exits1/8. No zero-distance/divisor guard. |

The complete static dispatch chain to the bounded mode1 effect emitter is:

```text
5E0880: actor action8 == 2
  -> table70BA50[2] = 5E2A20
5E2A20: actor state9 == 2
  -> table70BAA8[2] = 5E3600
5E3600: related pointer present; related54F == B0;
  admitted phase1 contact or repeated phase2 followup
  -> 5DDF50(actor,1)
```

These are verified static table/argument relationships. They do not establish
the original actor name,that this state occurred during a captured incident,
or any timing consequence. Mode1 selects zero or one bounded attempt;the earlier
underflow interpretation is withdrawn. No timing or fix/retest is claimed.

## Transform, motion flags and forward query helpers

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5E5160](../recomp/config/output_ovl/o2/o2_005E5160_0x5e5160.cpp) | `set_variant_e_f4_f5_flags_from_motion_and_frame_candidate` | Confirmed/static mechanics | Unsigned motion1F2 in64..6A setsF4=0/F5=1. Motion96 uses frame1E4<10,12C/12D use<1:before threshold0/1,otherwise1/0 including unordered. Other motion1/0. Does not test actor action,resource or input flags and never leaves these bytes unchanged. |
| [o2 0x5E5270](../recomp/config/output_ovl/o2/o2_005E5270_0x5e5270.cpp) | `apply_variant_e_yaw_scaled_root_translation_candidate` | Probable role; full body reviewed | Builds yaw92 matrix. Unless54A bit8 set,composes scale(B4,1,BC) through18FE60/191300. Clears54A bit8 regardless. Transforms root4E4..4EC through1919D0,multiplies all XYZ byF0,adds actor position38..40. Does not clear root input orE4 deltas,update actor matrix translation or invokecollision. |
| [o2 0x5E5370](../recomp/config/output_ovl/o2/o2_005E5370_0x5e5370.cpp) | `build_variant_e_rotation_from_three_unsigned_turn_angles_candidate` | Probable role; mechanics verified | a0/a1/a2 low16 angles separately191F80 to radians,then190ED0(output a3,f12/f13/f14). No angle wrap/narrow beyond unsigned16,identity preclear or actor lookup;matrix order inherits190ED0 rather than presumed same as370220. |
| [o2 0x5E53F0](../recomp/config/output_ovl/o2/o2_005E53F0_0x5e53f0.cpp) | `consume_variant_e_local_world_deltas_and_publish_matrix_candidate` | Confirmed/static mechanics | Identity actor matrix50;action2 uses370220(signed angles),others5E5370. Transforms localD8..E0 through1919D0,adds that plus worldE4..EC toXYZ38..40. Clears both three-float delta groups,then writes finalXYZ to matrix50 translation30/34/38. Does not clear animation-root4E4 or perform collision. |
| [o2 0x5E54F0](../recomp/config/output_ovl/o2/o2_005E54F0_0x5e54f0.cpp) | `query_variant_e_forward_segment_with_pitch_yaw_candidate` | Probable role; full body reviewed | a0 actor,a1/a2 XYZ output pointers,a3 signedlow16 yaw offset,f12 length. Builds370220(pitch90,signed16(yaw92+offset),0),transforms local(0,0,length),adds actorXYZ. Calls5795E0(start,end,stackOutA,stackOutB,t0=20FFFF,t1=0,t2=&stackWord). Nonzero query copies stackOutB to a1,stackOutA to a2 and returns1;zero leaves outputs unchanged,returns0. No output null/alias checks or claim about which collision surface the two outputs represent. |
| [o2 0x5E0680](../recomp/config/output_ovl/o2/o2_005E0680_0x5e0680.cpp) | `find_linked_actor_by_byte_three_without_activity_admission_candidate` | Confirmed/static mechanics | Walks head3B5850 throughnext1C;first unsigned byte3 equal full a0 returns pointer,else0. No inputlow8 mask,activity/category or room admission. Distinct fromBB4 lookup682F80. |
| [o2 0x5E06C0](../recomp/config/output_ovl/o2/o2_005E06C0_0x5e06c0.cpp) | `test_actor_below_surface_type81_query_height_candidate` | Probable role; mechanics verified | a0 actorXYZ copied,Y+200;616F20(position,&type,81). Returns1 only returned type81 and original actorY<=queryY,else0,including unordered. Does not change actor position or resource state. No actor null guard. |
| [o2 0x5E07F0](../recomp/config/output_ovl/o2/o2_005E07F0_0x5e07f0.cpp) | `route_variant_e_motion_specific_callback_parameters_candidate` | Probable role; mechanics verified | a0 actor saved as a1. Motion1F2=C8 calls5A96F0(36,actor,0,2A);motion82 chooses(44,actor,0,3D) foraction7/8,otherwise(44,actor,0,2B). Other motions do nothing. No direct call to5E0880;source-end PC references are not caller evidence. Callee meaning remains cross-reference. |

## Neighboring actor effect helpers

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5E0070](../recomp/config/output_ovl/o2/o2_005E0070_0x5e0070.cpp) | `spawn_effect54_with_optional_local_vector_candidate` | Confirmed/static mechanics | Preserves a0 as original matrix argument;copies optional a1 XYZ orzeros local vector.6525D0(matrix,vector,0,54,0,1A193,655240). No actor/resource admission or post-allocation field write. |
| [o2 0x5E0100](../recomp/config/output_ovl/o2/o2_005E0100_0x5e0100.cpp) | `periodically_spawn_effect80_near_random_actor_node_candidate` | Probable role; full body reviewed | Increments actor unsigned byteC39;newlow8 count must>4+(random&1),else return. Clears counter,selects model->820 node index via70B8B0[random low16%10]. Adds independentXYZ jitters random%50-25 to node translation;spawns80/palette0 withnull matrix. Threshold random consumed every call;node/jitter random only onemission. No activity/node bounds or wall-time frequency claim. |
| [o2 0x5E0280](../recomp/config/output_ovl/o2/o2_005E0280_0x5e0280.cpp) | `spawn_category_selected_effect8f_and_seeded90_cloud_candidate` | Probable role; full body and tables reviewed | a0 source. Category0 choosesnodeA,count8,scale1. Category2 scans terminated70B8C0 triples keyed sourcebyte3;owned tuples(id,node,count)=(0,3,8),(1,A,8),(5,2,5),(14,14,8),(2B,4,C),sentinel-1. Scale70B910[entry*8] is1,1,.5,1,owned1.3 respectively. Source modelnodeXYZ iscenter;spawns8F/callback653E80,always6B2810(center),andfirstallocation failure aborts cloud. Successful8F half23E24,EC=50*scale,uniformscale. Up tocount90/callback6545A0 attemptsuse local seed recurrence W(s)=s?112*s%FF53:B0:XYZ offsets=(s%140-70,W(s)%140-70,W(W(s))%140-70)*scale;success C=W^3(s)&F,yaw94=W^3(s),half23E26,EC/scale match. First90 allocation failure ends. Null orunsupported category paths do not initialize v1 selection reliably;entry's later v1==-1 test is not a proven generalnull/category rejection. |
| [o2 0x5E0760](../recomp/config/output_ovl/o2/o2_005E0760_0x5e0760.cpp) | `spawn_effect_by_id_palette_with_optional_vector_and_counter_candidate` | Confirmed/static mechanics | a0 full effectID,a1 matrix,a2 optionalXYZ,a3 counter. NullXYZ becomeszero vector;palette=7123A0[fullID] without bounds.6525C0(matrix,vector,palette,ID,0,1A193);successhalfC=low16 counter. No actor lookup,ID narrowing or mode-specific behavior. |

All16 named entries were reviewed within indexed ownership boundaries and their
instruction words checked against owned o2 bytes. Primary/action/phase tables
and the five terminated category records/scales were read from that same blob.
No original actor taxonomy,runtime symptom,root-cause proof or implemented
optimization is claimed.
