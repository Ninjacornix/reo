# Actor 6C motion helpers and action timer initialization

Static File #1 US research, 2026-11-04. Ten complete original bodies reviewed.
Addresses/offsets hex unless marked decimal. Actor identity and original action
names unresolved. No target execution, attachment, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C9ED0](../recomp/config/output_ovl/o2/o2_006C9ED0_0x6c9ed0.cpp) | `save_actor_6c_state_and_initialize_requested_action_candidate` | High mechanics; probable role | Saves8/9 toBE8/BE9,sets8/9 from a1/a2 lowbytes,clearsA/B,calls9F70. Requested primarylowbyteA ->C36=20,otherwise1. No transform or animation selection. |
| [o2 0x6C9F70](../recomp/config/output_ovl/o2/o2_006C9F70_0x6c9f70.cpp) | `initialize_actor_6c_action_timers_and_saved_yaw_parameter_candidate` | High mechanics; probable role | ClearsC/E. Primary1 uses secondary-specific cases listed below;other primaries leave timers0. Always calls existing9F40 field-read adapter. Timer writes retain factor division only where present; RNG calls remain separate. No global clock or presentation observations. |
| [o2 0x6CA900](../recomp/config/output_ovl/o2/o2_006CA900_0x6ca900.cpp) | `consume_actor_6c_alignment_local_world_deltas_and_commit_matrix_candidate` | High mechanics; probable role | Identity matrix50. BA3==3 builds5E5370 basis from90/92/94 and skips quaternion;other modes build370320 Euler,nonzeroBA3 then quaternionD18 via192250/1913E0. TransformsD8XYZ through1919D0,adds plusE4XYZ toposition38;clears both delta groups,commits XYZ to matrix80/84/88. Distinct from6D2340 specialmode behavior; no animation root clear or collision. |
| [o2 0x6CBA80](../recomp/config/output_ovl/o2/o2_006CBA80_0x6cba80.cpp) | `refresh_actor_6c_alignment_quaternion_and_commit_movement_candidate` | High mechanics; probable role | State1/7 first copies currentXYZ to80/84/88.5A82A0(outD18,directionD00,signedBA3),thenA900 local/world delta consumption/matrixcommit. Related6D3D30 differs in final callee,so no cross-family equality assumed. |
| [o2 0x6CBAF0](../recomp/config/output_ovl/o2/o2_006CBAF0_0x6cbaf0.cpp) | `select_actor_6c_primary_one_variant_default_four_or_e_candidate` | High routing | Calls9ED0(actor,1,E) when unsignedbyte4==1,otherwise9ED0(actor,1,4). Therefore saves priorstate,clearsphases,reseeds timers and C36=1; no direct animation. |
| [o2 0x6CBB30](../recomp/config/output_ovl/o2/o2_006CBB30_0x6cbb30.cpp) | `add_actor_6c_yaw_delta_clamped_ccd_outside_deadband_candidate` | High mechanics; probable role | a1 signed-low16 in inclusive-38E..38E returns without yawwrite. Outside calls634B20(original a1,CCD),addsresult to signedyaw92. No position/timerwrites. |
| [o2 0x6CBB90](../recomp/config/output_ovl/o2/o2_006CBB90_0x6cbb90.cpp) | `turn_actor_6c_toward_fixed_point_for_variant_one_or_cached_bearing_candidate` | High mechanics; probable role | Byte4==1 computes376E70(currentXYZ,owned7305E0)-yaw92 narrowed16;other variants read signedBD8. Passes resultBB30. Owned point decimal(4504,-3200,3526). No actor peer query on fixedpoint path. |
| [o2 0x6CBC00](../recomp/config/output_ovl/o2/o2_006CBC00_0x6cbc00.cpp) | `integrate_actor_6c_rotated_oscillating_local_displacement_candidate` | High mechanics; probable role | D34+=D0;predecrements signedD58,post<=0 resetsdecimal12 and negatesD0. D38+=D4 clamped upperdecimal40 by ordered comparison. Rotates vector(D30,D34,D38) inXZ through191BC0 using unsigned9A*owned2pi/65536,adds XYZ toactorposition. If174!=FF andY<D28,clampsY=D28. Does not build actor matrix,checkmodel or scale by frame factor. |
| [o2 0x6CBD30](../recomp/config/output_ovl/o2/o2_006CBD30_0x6cbd30.cpp) | `advance_actor_6c_horizontal_heading_parameter_toward_target_candidate` | High mechanics; probable role | a0actor,a1headingdelta,a2targetXYZ. Computes XZdistance;threshold=max(decimal50,10*unsignedBAC). Only distance>=threshold and signed-low16 delta outside inclusive-38E..38E updates9A +=634B20(original delta,3D7). Alwaysrotates owned(0,0,20)7305F0 by unsigned9A*2pi/65536,addsX/Z toposition;Yunchanged. Distance gate controls heading adjustment,not whether movement happens. |
| [o2 0x6CBE70](../recomp/config/output_ovl/o2/o2_006CBE70_0x6cbe70.cpp) | `initialize_or_integrate_actor_6c_reversing_vertical_acceleration_candidate` | High mechanics; probable role | a1signed-lowbyte0 initialization:D3C0,D40=float7306B8[signed a2],D44=signed7306B0[a2]/2 with truncation toward0. Nonzeroa1 updatesD3C+=D40,Y+=D3C,clampsY>=D28 onlyif174!=FF,predecrementsD44;post<=0 resetsfull7306B0[a2] and negatesD40. Owned two selectors h(decimal12,8),f(1.2,2.4). No caller selector bounds/factor scaling added. |

9F70 primary-one secondary cases, RNG values use unsigned low16 and timer
numbers below are decimal unless explicitly a hexstate:

| Secondary | C and E writes after initial zeros |
| --- | --- |
| 0 | E=634AB0() result |
| 1 | E=(random%600+300)/byte74F200 |
| 4 | C=9A if savedstateBE8=1/BE9 in{B,4,F},otherwise currentyaw;E=30 |
| 8 | C=first random&1;E=30+30*(second random&1),no factor division |
| E | C=9A only saved1/F,else currentyaw;E=30*(random%6+3)/factor |
| B | C=9A only saved1/4,else currentyaw;E remains0 |
| F/10 | C=9A;E=10*(random%3+1),no factor division |
| Other | C/E remain0 |

The original mixed timer scaling, signed narrowing and numeric state contracts
are preserved.9F40 already has a live identical-body alias mapping and receives
no duplicate row. Owned vectors/constants/two-entry vertical parameters were
read from file-backed o2 bytes; no live process data inspected.

Related [actor model quaternion helper](SYMBOLS_ACTOR_MODEL_STATE_HELPERS.md),
[alignment family](SYMBOLS_ACTOR_6D_ALIGNMENT_MOTION.md), and
[surface probes](SYMBOLS_ACTOR_6D_SURFACE_PROBES.md).
