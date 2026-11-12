# Actor action families, progression and surface queries

Static research, 2026-11-04, identity-checked owned File #1 overlay2 (runtime id3). See [overlay provenance](SYMBOLS_SCRIPT_VM.md). No game, replay, build or live attachment.

Action and substate bytes are indices, not recovered original enum names. Numerical labels preserve that distinction. Most action families contain both a primary decision phase and a secondary state/animation phase. Replacing a dispatch call with the whole actor service loop would duplicate pre/postwork.

The paired action-one tables each have **226 contiguous code-pointer words**, followed by zero, at0x711A10 and0x712C50. This supports a shared substate domain000..0E1; the dispatcher does not bounds-check the byte index. Their entries are recorded as relationships below; unreviewed destination bodies remain unknown. Adjacent code pointers alone are not named functions.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x585190](../recomp/config/output_ovl/o2/o2_00585190_0x585190.cpp) | `actor_action_two_primary_dispatch` | Confirmed/static mechanics | Primary action2 at0x712BD0[2]. If0x6673C0 consumes a flag,sets+BA4 bit4 and returns. Else unsigned+9<28 selects internal branch table0x73DFA0. Branches call action handlers; assignments in numeric table below. |
| [o2 0x593650](../recomp/config/output_ovl/o2/o2_00593650_0x593650.cpp) | `actor_action_three_primary_dispatch` | Confirmed/static mechanics | Primary action3:consume0x6673C0->+BA4 bit4/return;0x64F110 nonzero preempts. Direct +9 compare chain covers0..21 and64..74,mostly0x593640 no-op. States16/17 call0x593C50,20 calls0x593CF0 no-op,64 calls0x593D00; other unmatched state calls0x593640. Preserve preemption side effects. |
| [o2 0x593A50](../recomp/config/output_ovl/o2/o2_00593A50_0x593a50.cpp) | `actor_action_five_primary_dispatch` | Confirmed/static mechanics | Primary action5:consume flag then+BA4 bit4,else mode0x1B0340==1 calls0x5BF0C0; +A==0 calls0x662BC0. Unsigned+9<22 jumps through0x73E1C0 to animation/state handlers; out-of-range0x593640. |
| [o2 0x678130](../recomp/config/output_ovl/o2/o2_00678130_0x678130.cpp) | `actor_action_two_secondary_resource_animation_candidate` | Probable role; mechanics verified | Secondary action2 sets+BA4 bit100,indexes0x713040 using unchecked+9. Initial branch recalculates+CA8 resource,handles flag-consumption fallback to action1,substates0/A/B/C/D select animation from0x725AD0 with resource table0x719A65. Rotates yaw over5/10 ticks using0x377000/376EF0,target+CDC/+FDC. Calls0x58C300/58D340 for progress; completion may action2,state1. No original action name proven. |
| [o2 0x5C6810](../recomp/config/output_ovl/o2/o2_005C6810_0x5c6810.cpp) | `actor_action_three_secondary_dispatch` | Confirmed/static mechanics | Secondary action3 clears+BD0,ORs+BA0 masks20000/200,+54A bit4000. +A==0 ORs+BA4 bit200000,optionally clears+FAA. Explicit+9 branches0..21 and64..74; mostly0x5C6E70 with distinct interaction handlers. Unknown state resets action1,+9=0,+A=1,+B=0,saves position,selects2050 animation with floats0/10. |
| [o2 0x5C6C80](../recomp/config/output_ovl/o2/o2_005C6C80_0x5c6c80.cpp) | `actor_action_four_secondary_dispatch` | Confirmed/static mechanics | Secondary action4 ORs+BA0 bit20000,releases selected resource+C7C through0x5B1A90,clears+C7C/+CA8. Unless+BA4 bit2000000 calls0x5F6800(actor,0). Conditional mode callback0x37C060(26,0,0). +9<12 jumps table0x73E8F0; unknown resets action1 and animation2050. Type4 gameplay death semantics probable but not asserted. |
| [o2 0x640A50](../recomp/config/output_ovl/o2/o2_00640A50_0x640a50.cpp) | `actor_action_five_secondary_dispatch` | Confirmed/static mechanics | Secondary action5 ORs+BA0 masks20000/2000000/200,clears+BD0,ORs+54A4000. Initial+A==0 ORs+BA4 bit400000 and mode-dependent+FAA clear. Dispatches unchecked+9 through0x711730,22 contiguous code pointers followed by0. |
| [o2 0x67BE90](../recomp/config/output_ovl/o2/o2_0067BE90_0x67be90.cpp) | `actor_action_six_secondary_initialize_and_tick` | Confirmed/static mechanics | Action6 secondary-pass target712C10[6] selects signed+B38. State0 sets action6,clears9/A/B,rootdelta4E4XYZ and twelve32-byte channel records1E4;cue remains0. State1 sets visibilitybyte1=1,incrementscue2,clears9/A/B. BOTH states1/2 call67BC90 then67BE60. All paths propagateBA4bit2 to54Abit40. No outer pause gate;66A2E0 owns later root/basis work. The earlier state2-only67BE60 description was wrong; full original comparisons correct it. |
| [o2 0x67C240](../recomp/config/output_ovl/o2/o2_0067C240_0x67c240.cpp) | `actor_action_seven_secondary_noop` | Confirmed/static mechanics | Secondary table action7 points here; JR ra, no work or result assignment. |
| [o2 0x666580](../recomp/config/output_ovl/o2/o2_00666580_0x666580.cpp) | `sample_actor_surface_height_type81_candidate` | Probable role; mechanics verified | Copies actorXYZ,+Y1000,queries0x616F20(position,&type,81). If returned byte type81,stores height+184 and flag+188=1;else clears both. Surface-height interpretation supported by paired caller but underlying geometry query still under review. |
| [o2 0x666450](../recomp/config/output_ovl/o2/o2_00666450_0x666450.cpp) | `update_actor_surface_state_and_restore_transform_candidate` | Probable role; mechanics verified | Copies actorXYZ,+Y50,calls0x616ED0(actor,pos,FF). Special returned actor type+174==3 clears+553 and sets height+170 from previous type81 sample or actorY+160. Other path compares returned height,may restore Y. If+BA0 mask88 and type3 restores savedXYZ+44 and angles+A0 to current+38/+90. Multi-step state mutation,not pure collision query. |
| [o2 0x666D60](../recomp/config/output_ovl/o2/o2_00666D60_0x666d60.cpp) | `increment_actor_counter_d2c_unless_disabled` | Confirmed/static mechanics | Null/category+2!=0 returns. Word+D2C!=FFFFFFFF increments wrapping32; sentinel remains unchanged. |
| [o2 0x666DB0](../recomp/config/output_ovl/o2/o2_00666DB0_0x666db0.cpp) | `increment_actor_counter_d28_unless_disabled` | Confirmed/static mechanics | Same guard/sentinel as0x666D60,word+D28. |
| [o2 0x667420](../recomp/config/output_ovl/o2/o2_00667420_0x667420.cpp) | `update_selected_actor_progression_gauge_candidate` | Probable role; mechanics verified | Only category0 selected actor,global0x4BADF8==0,+BA0 bit400000 clear. Adds per-type rate table0x71ADD0 scaled by state,30/60 mode and three timed modifiers+BB6/+BB8/+BBA. Uses cap table0x71ADB0; may trigger+BA0 flags/action4 or0x65FCB0. Below cap calls0x667E90(old,new),stores unsigned+B?AC. Increasing gauge/threshold behavior resembles infection,not proven health. Original quantization is not freely replaceable by wall-time delta. |
| [o2 0x668740](../recomp/config/output_ovl/o2/o2_00668740_0x668740.cpp) | `actor_auxiliary_tick_unless_ui_or_state15` | Confirmed/static mechanics | If0x1B0340(actor)==1 and0x6DEE20()!=0 skips. Also actor byte+54F==15 skips. Otherwise calls0x5B6450(actor). Specific auxiliary subsystem unresolved. |
| [o2 0x6687A0](../recomp/config/output_ovl/o2/o2_006687A0_0x6687a0.cpp) | `actor_flag1000_timed_action_four_transition` | Confirmed/static mechanics | Requires+BA4 bit1000 and action+8!=4;clears word+BAC. Only+BA0 mask18 proceeds. Countdown halfword+C62 nonzero decrements; reaching0 ORs+BA0 bit40000000,calls0x5F6800,sets+54F=A0,action4,clears+9..B,saves transform. If initially0 loads10800 for nonzero0x3243CC,else21600. |
| [o2 0x593640](../recomp/config/output_ovl/o2/o2_00593640_0x593640.cpp) | `actor_action_three_default_zero_stub` | Confirmed/static mechanics | Returns0,no mutation. |
| [o2 0x593C50](../recomp/config/output_ovl/o2/o2_00593C50_0x593c50.cpp) | `actor_action_three_substate_two_flag_transition` | Confirmed/static mechanics | Only+A==2 and+CE2 bits80 AND40 bothset. Sets byte+32 to60 if0x3243CC!=0 else120,ORs+CE2 bit20,sets action1/clears+9..B,saves transform,tail-action dispatch0x66B8A0,returns1. Else0. |
| [o2 0x593CF0](../recomp/config/output_ovl/o2/o2_00593CF0_0x593cf0.cpp) | `actor_action_three_state20_zero_stub` | Confirmed/static mechanics | Distinct returns0,no mutation. |
| [o2 0x593D00](../recomp/config/output_ovl/o2/o2_00593D00_0x593d00.cpp) | `actor_action_three_state64_resource_adapter` | Confirmed/static mechanics | Only+A==0 calls0x5F6A80(actor,0,actor+C7C). Always returns0. |
| [o2 0x585180](../recomp/config/output_ovl/o2/o2_00585180_0x585180.cpp) | `actor_action_two_default_zero_stub` | Confirmed/static mechanics | Returns0,no mutation. |
| [o2 0x64AFA0](../recomp/config/output_ovl/o2/o2_0064AFA0_0x64afa0.cpp) | `actor_action_one_primary_zero_stub` | Confirmed/static mechanics | Returns0,no mutation; many primary substate slots reuse it. |
| [o2 0x64AFB0](../recomp/config/output_ovl/o2/o2_0064AFB0_0x64afb0.cpp) | `actor_category_zero_transition_predicate` | Confirmed/static mechanics | Category+2!=0 returns0. Else calls0x64F110(actor),normalizes nonzero to1; despite predicate label it may mutate state through callee. |
| [o2 0x64AFF0](../recomp/config/output_ovl/o2/o2_0064AFF0_0x64aff0.cpp) | `actor_action_one_ce2_f80_transition` | Confirmed/static mechanics | Requires+CE2 bit80 and word+F80 maskF3F nonzero. ORs+CE2 bit20,sets action1/clears+9..B,saves transform,calls0x66B8A0,returns1. Else0. |
| [o2 0x616ED0](../recomp/config/output_ovl/o2/o2_00616ED0_0x616ed0.cpp) | `query_actor_surface_into_state_candidate` | Probable role; mechanics verified | Passes position a1 into0x617000 with outputs actor+178,+174,+175,+176 and stack scratch,filter original a2,t3=0. Stores returned f0 at actor+170. |
| [o2 0x616F20](../recomp/config/output_ovl/o2/o2_00616F20_0x616f20.cpp) | `query_surface_height_and_type_candidate` | Probable role; mechanics verified | Adapts a0 position,a1 caller type output,a2 filter into0x617000 with temporary geometry/other byte outputs,t3=0. Returns f0. Underlying selector contract unresolved. |
| [o2 0x64F110](../recomp/config/output_ovl/o2/o2_0064F110_0x64f110.cpp) | `consume_actor_control_request_or_timeout_transition` | Confirmed/static mechanics | Calls0x663190(actor,3,7) and(actor,3,1). +AD4 queued request clears+AB8 and returns1. Other branches consume+AB8/+AB9 to action1,stateDD;0x64EF10 success sends message3; unchanged+BBD clears. Timeout threshold20/40 and state+54F1/3 select action1,stateAE,timer900/1800,notify0x67FF80. Return1 can mean admitted transition,not pure eligibility. |
| [o2 0x65FC90](../recomp/config/output_ovl/o2/o2_0065FC90_0x65fc90.cpp) | `set_actor_flag400_and_reset_motion_candidate` | Probable role; mechanics verified | ORs actor+BA0 bit400,tailcalls0x5F6800(actor,0). |
| [o2 0x65FCB0](../recomp/config/output_ovl/o2/o2_0065FCB0_0x65fcb0.cpp) | `actor_recovery_or_action_four_transition_candidate` | Probable role; mechanics verified | Clears+BA0 mask38,sets80,timer+C5E=3600/7200,calls0x6605B0 ids5/8. Mode1 clears80,ORs40000000,action4/A0,notifies/reset. Other modes0x65FAB0,+B9C=2;input selector0->action3,state11;1->action3,state10;2->action1 with2050 animation,then message1 and0x65FC90. Numeric behavior proven,recovery/death naming provisional. |
| [o2 0x667E90](../recomp/config/output_ovl/o2/o2_00667E90_0x667e90.cpp) | `notify_progression_gauge_threshold_crossings_candidate` | Probable role; mechanics verified | Requires0x1B0340(actor)!=0. Converts old/new unsigned values through0x668050; upward crossings50/70/90 trigger0x37C060 ids21/22/23,first matching branch only. Conversion helper owns denominator,not automatically actor argument. |
| [o2 0x66B8A0](../recomp/config/output_ovl/o2/o2_0066B8A0_0x66b8a0.cpp) | `dispatch_actor_primary_action_immediately` | Confirmed/static mechanics | Loads unchecked unsigned actor+8,tailjumps pointer0x712BD0[action]. Does not execute full actor service pre/postwork from0x66B500. |

## Verified paired action-one substate pointers

| Substate | Primary target | Secondary target |
| --- | --- | --- |
| 00 | 0x64B060 | 0x66B990 |
| 01 | 0x64B370 | 0x66BB10 |
| 02 | 0x64B370 | 0x66BB10 |
| 03 | 0x64B560 | 0x66C160 |
| 04 | 0x64B750 | 0x66C160 |
| 05 | 0x64B750 | 0x66C160 |
| 06 | 0x64B960 | 0x66C4B0 |
| 07 | 0x64BB10 | 0x66C4B0 |
| 08 | 0x64BB10 | 0x66C4B0 |
| 09 | 0x64BCC0 | 0x66C840 |
| 0A | 0x64BE00 | 0x66C840 |
| 0B | 0x64BE00 | 0x66C840 |
| 0C | 0x64BF60 | 0x66CB40 |
| 0D | 0x64C080 | 0x66CB40 |
| 0E | 0x64C080 | 0x66CB40 |
| 0F | 0x64C8B0 | 0x66CB50 |
| 10 | 0x64C8B0 | 0x66CCC0 |
| 11 | 0x629330 | 0x631120 |
| 12 | 0x6C1BC0 | 0x6C1BD0 |
| 13 | 0x64AFF0 | 0x62FEE0 |
| 14 | 0x64AFF0 | 0x630350 |
| 15 | 0x64C1C0 | 0x66CE30 |
| 16 | 0x64C3D0 | 0x66CFE0 |
| 17 | 0x64AFA0 | 0x66E670 |
| 18 | 0x64AFA0 | 0x66EC50 |
| 19 | 0x64C410 | 0x66F330 |
| 1A | 0x64C450 | 0x66F340 |
| 1B | 0x64AFA0 | 0x66F7F0 |
| 1C | 0x64AFB0 | 0x66FA10 |
| 1D | 0x64C500 | 0x66FB50 |
| 1E | 0x64AFA0 | 0x66FDC0 |
| 1F | 0x64AFA0 | 0x6700E0 |
| 20 | 0x64AFB0 | 0x6700F0 |
| 21 | 0x64AFB0 | 0x670230 |
| 22 | 0x64AFB0 | 0x670230 |
| 23 | 0x64AFA0 | 0x67BFF0 |
| 24 | 0x64DA40 | 0x670470 |
| 25 | 0x64AFB0 | 0x670740 |
| 26 | 0x64AFA0 | 0x670870 |
| 27 | 0x64AFA0 | 0x670870 |
| 28 | 0x64AFA0 | 0x670870 |
| 29 | 0x64AFA0 | 0x670870 |
| 2A | 0x64AFA0 | 0x670C00 |
| 2B | 0x64AFA0 | 0x671180 |
| 2C | 0x64C630 | 0x671A80 |
| 2D | 0x64AFA0 | 0x672140 |
| 2E | 0x64AFA0 | 0x672A40 |
| 2F | 0x64AFB0 | 0x672D50 |
| 30 | 0x64AFA0 | 0x673030 |
| 31 | 0x64AFB0 | 0x6730C0 |
| 32 | 0x64C6D0 | 0x673260 |
| 33 | 0x64AFA0 | 0x673270 |
| 34 | 0x64C8B0 | 0x673580 |
| 35 | 0x64AFA0 | 0x673650 |
| 36 | 0x64C940 | 0x673AD0 |
| 37 | 0x64AFA0 | 0x673DB0 |
| 38 | 0x64AFB0 | 0x674340 |
| 39 | 0x64C560 | 0x66FF90 |
| 3A | 0x64D9E0 | 0x677D10 |
| 3B | 0x64AFA0 | 0x630350 |
| 3C | 0x629440 | 0x632730 |
| 3D | 0x64AFA0 | 0x66B990 |
| 3E | 0x64CA90 | 0x674340 |
| 3F | 0x64CA90 | 0x674340 |
| 40 | 0x64CA90 | 0x675710 |
| 41 | 0x64AFA0 | 0x66B990 |
| 42 | 0x64AFA0 | 0x6713D0 |
| 43 | 0x64AFA0 | 0x672370 |
| 44 | 0x64AFA0 | 0x6717F0 |
| 45 | 0x64AFA0 | 0x672770 |
| 46 | 0x64B060 | 0x672910 |
| 47 | 0x64AFF0 | 0x62FEE0 |
| 48 | 0x64AFA0 | 0x676690 |
| 49 | 0x64AFA0 | 0x676690 |
| 4A | 0x64CAD0 | 0x6767F0 |
| 4B | 0x64CCF0 | 0x6768B0 |
| 4C | 0x64CCF0 | 0x6768B0 |
| 4D | 0x64CEA0 | 0x676A00 |
| 4E | 0x64D040 | 0x676A00 |
| 4F | 0x64D040 | 0x676A00 |
| 50 | 0x64D210 | 0x676B50 |
| 51 | 0x64D3C0 | 0x676B50 |
| 52 | 0x64D3C0 | 0x676B50 |
| 53 | 0x64D5A0 | 0x676CA0 |
| 54 | 0x64D6D0 | 0x676CA0 |
| 55 | 0x64D6D0 | 0x676CA0 |
| 56 | 0x64AFA0 | 0x676DE0 |
| 57 | 0x64AFA0 | 0x676F30 |
| 58 | 0x64AFA0 | 0x6770C0 |
| 59 | 0x64AFA0 | 0x6772F0 |
| 5A | 0x64D800 | 0x677450 |
| 5B | 0x64AFA0 | 0x6717F0 |
| 5C | 0x64AFA0 | 0x672770 |
| 5D | 0x64AFA0 | 0x673270 |
| 5E | 0x64AFA0 | 0x673650 |
| 5F | 0x64AFA0 | 0x66EEA0 |
| 60 | 0x6292A0 | 0x630750 |
| 61 | 0x629320 | 0x630EE0 |
| 62 | 0x64AFF0 | 0x6775E0 |
| 63 | 0x64AFA0 | 0x673650 |
| 64 | 0x64AFA0 | 0x62F940 |
| 65 | 0x64AFA0 | 0x6713D0 |
| 66 | 0x64AFA0 | 0x672370 |
| 67 | 0x64AFA0 | 0x6777D0 |
| 68 | 0x64AFA0 | 0x671A80 |
| 69 | 0x64AFA0 | 0x670870 |
| 6A | 0x64AFA0 | 0x670870 |
| 6B | 0x626AD0 | 0x6298E0 |
| 6C | 0x626AE0 | 0x629B20 |
| 6D | 0x626AF0 | 0x629D20 |
| 6E | 0x626B70 | 0x629E30 |
| 6F | 0x626B80 | 0x62A070 |
| 70 | 0x626B90 | 0x62A200 |
| 71 | 0x626BB0 | 0x62A5E0 |
| 72 | 0x626BB0 | 0x62A5E0 |
| 73 | 0x626BB0 | 0x62A5E0 |
| 74 | 0x626BC0 | 0x62A880 |
| 75 | 0x626D50 | 0x62A970 |
| 76 | 0x626D50 | 0x62A970 |
| 77 | 0x626E80 | 0x62AB00 |
| 78 | 0x626FA0 | 0x62AB00 |
| 79 | 0x626FA0 | 0x62AB00 |
| 7A | 0x6270F0 | 0x62AC60 |
| 7B | 0x6271B0 | 0x62AC60 |
| 7C | 0x6271B0 | 0x62AC60 |
| 7D | 0x6272A0 | 0x62ADC0 |
| 7E | 0x6272B0 | 0x62AEE0 |
| 7F | 0x6272D0 | 0x62B1A0 |
| 80 | 0x627310 | 0x62B320 |
| 81 | 0x627320 | 0x62B540 |
| 82 | 0x6274F0 | 0x62B630 |
| 83 | 0x627540 | 0x62B630 |
| 84 | 0x64AFA0 | 0x66B990 |
| 85 | 0x64AFA0 | 0x66B990 |
| 86 | 0x64AFA0 | 0x66B990 |
| 87 | 0x64AFA0 | 0x66B990 |
| 88 | 0x627590 | 0x62B7F0 |
| 89 | 0x6275A0 | 0x62BB50 |
| 8A | 0x6275F0 | 0x62BCD0 |
| 8B | 0x627600 | 0x62BE70 |
| 8C | 0x627650 | 0x62BFE0 |
| 8D | 0x627660 | 0x62C180 |
| 8E | 0x627670 | 0x62C2E0 |
| 8F | 0x627670 | 0x62C2E0 |
| 90 | 0x627680 | 0x62C4F0 |
| 91 | 0x627680 | 0x62C4F0 |
| 92 | 0x627760 | 0x62C6D0 |
| 93 | 0x627760 | 0x62C6D0 |
| 94 | 0x627760 | 0x62C6D0 |
| 95 | 0x627760 | 0x62C6D0 |
| 96 | 0x64AFA0 | 0x62C970 |
| 97 | 0x64AFA0 | 0x62CAD0 |
| 98 | 0x627770 | 0x62D550 |
| 99 | 0x627770 | 0x62D550 |
| 9A | 0x627770 | 0x62D550 |
| 9B | 0x627770 | 0x62D550 |
| 9C | 0x627770 | 0x62D550 |
| 9D | 0x627770 | 0x62D550 |
| 9E | 0x627770 | 0x62D550 |
| 9F | 0x627770 | 0x62D550 |
| A0 | 0x627770 | 0x62D550 |
| A1 | 0x627770 | 0x62CC30 |
| A2 | 0x627770 | 0x62DB90 |
| A3 | 0x628360 | 0x62DF20 |
| A4 | 0x628360 | 0x62DF20 |
| A5 | 0x628360 | 0x62DF20 |
| A6 | 0x628360 | 0x62DF20 |
| A7 | 0x628360 | 0x62DF20 |
| A8 | 0x628360 | 0x62DF20 |
| A9 | 0x628360 | 0x62DF20 |
| AA | 0x628360 | 0x62DF20 |
| AB | 0x628360 | 0x62DF20 |
| AC | 0x628360 | 0x62DF20 |
| AD | 0x628360 | 0x62E330 |
| AE | 0x628550 | 0x62E5F0 |
| AF | 0x6289A0 | 0x62E7F0 |
| B0 | 0x628D20 | 0x62EA40 |
| B1 | 0x628D30 | 0x62ED20 |
| B2 | 0x628D40 | 0x62EF00 |
| B3 | 0x64AFA0 | 0x66B990 |
| B4 | 0x628EA0 | 0x62F6E0 |
| B5 | 0x627770 | 0x62DB90 |
| B6 | 0x629180 | 0x62FB20 |
| B7 | 0x629260 | 0x62FD30 |
| B8 | 0x6292E0 | 0x630D30 |
| B9 | 0x588BE0 | 0x5892E0 |
| BA | 0x588BF0 | 0x5893F0 |
| BB | 0x588C90 | 0x5894E0 |
| BC | 0x588D00 | 0x5895D0 |
| BD | 0x588D10 | 0x589740 |
| BE | 0x588D20 | 0x5898B0 |
| BF | 0x588EA0 | 0x589EC0 |
| C0 | 0x588EB0 | 0x58A080 |
| C1 | 0x588EC0 | 0x58A210 |
| C2 | 0x588ED0 | 0x58A3D0 |
| C3 | 0x588EE0 | 0x58A710 |
| C4 | 0x588FC0 | 0x58ABE0 |
| C5 | 0x588FD0 | 0x58ADC0 |
| C6 | 0x589110 | 0x58AEC0 |
| C7 | 0x589120 | 0x58B050 |
| C8 | 0x589130 | 0x58B1C0 |
| C9 | 0x5892C0 | 0x58B2C0 |
| CA | 0x5892D0 | 0x58B430 |
| CB | 0x64AFA0 | 0x58B730 |
| CC | 0x64AFA0 | 0x58B890 |
| CD | 0x587720 | 0x5878E0 |
| CE | 0x64AFA0 | 0x5879D0 |
| CF | 0x64AFA0 | 0x5879D0 |
| D0 | 0x587840 | 0x587CC0 |
| D1 | 0x587890 | 0x587CC0 |
| D2 | 0x64AFA0 | 0x587FB0 |
| D3 | 0x64AFA0 | 0x587FB0 |
| D4 | 0x64AFA0 | 0x588170 |
| D5 | 0x64AFA0 | 0x588170 |
| D6 | 0x64AFA0 | 0x5883D0 |
| D7 | 0x57E970 | 0x57EAD0 |
| D8 | 0x57EA00 | 0x57EBC0 |
| D9 | 0x57EAA0 | 0x57ECB0 |
| DA | 0x57EAB0 | 0x57EE20 |
| DB | 0x64AFA0 | 0x57F1A0 |
| DC | 0x64AFA0 | 0x57F300 |
| DD | 0x627770 | 0x62DB90 |
| DE | 0x6272C0 | 0x62B040 |
| DF | 0x57EAC0 | 0x57F490 |
| E0 | 0x626BA0 | 0x62A360 |
| E1 | 0x708320 | 0x708330 |

## Action2 primary internal branch table:0x73DFA0

| State | Target |
| --- | --- |
| 00 | 0x5851E8 |
| 01 | 0x5851F8 |
| 02 | 0x585208 |
| 03 | 0x585218 |
| 04 | 0x585228 |
| 05 | 0x585238 |
| 06 | 0x585248 |
| 07 | 0x585258 |
| 08 | 0x585268 |
| 09 | 0x585278 |
| 0A | 0x585288 |
| 0B | 0x585298 |
| 0C | 0x5852A8 |
| 0D | 0x5852B8 |
| 0E | 0x5852C8 |
| 0F | 0x5852D8 |
| 10 | 0x5852E8 |
| 11 | 0x5852F8 |
| 12 | 0x585308 |
| 13 | 0x585318 |
| 14 | 0x585328 |
| 15 | 0x585338 |
| 16 | 0x585348 |
| 17 | 0x585358 |
| 18 | 0x585368 |
| 19 | 0x585378 |
| 1A | 0x585388 |
| 1B | 0x585398 |

## Action5 primary internal branch table:0x73E1C0

| State | Target |
| --- | --- |
| 00 | 0x593AD8 |
| 01 | 0x593AE8 |
| 02 | 0x593AF8 |
| 03 | 0x593B08 |
| 04 | 0x593B18 |
| 05 | 0x593B28 |
| 06 | 0x593B38 |
| 07 | 0x593B48 |
| 08 | 0x593B58 |
| 09 | 0x593B68 |
| 0A | 0x593B78 |
| 0B | 0x593B88 |
| 0C | 0x593B98 |
| 0D | 0x593BA8 |
| 0E | 0x593BB8 |
| 0F | 0x593BC8 |
| 10 | 0x593BD8 |
| 11 | 0x593BE8 |
| 12 | 0x593BF8 |
| 13 | 0x593C08 |
| 14 | 0x593C18 |
| 15 | 0x593C28 |

## Action2 secondary internal branch table:0x713040

| State | Target |
| --- | --- |
| 00 | 0x678160 |
| 01 | 0x6786A0 |
| 02 | 0x678BD0 |
| 03 | 0x679070 |
| 04 | 0x6797E0 |
| 05 | 0x679A80 |
| 06 | 0x679C90 |
| 07 | 0x679EA0 |
| 08 | 0x67A200 |
| 09 | 0x67A490 |
| 0A | 0x67A6D0 |
| 0B | 0x67ABB0 |
| 0C | 0x67AFA0 |
| 0D | 0x67B300 |
| 0E | 0x679070 |
| 0F | 0x67B860 |
| 10 | 0x67B860 |
| 11 | 0x67BAE0 |
| 12 | 0x66B990 |
| 13 | 0x66B990 |
| 14 | 0x631350 |
| 15 | 0x6315E0 |
| 16 | 0x631830 |
| 17 | 0x631C00 |
| 18 | 0x631DF0 |
| 19 | 0x631FD0 |
| 1A | 0x6321A0 |
| 1B | 0x632570 |

## Action4 secondary internal branch table:0x73E8F0

| State | Target |
| --- | --- |
| 00 | 0x5C6D44 |
| 01 | 0x5C6D54 |
| 02 | 0x5C6D64 |
| 03 | 0x5C6D74 |
| 04 | 0x5C6D84 |
| 05 | 0x5C6D94 |
| 06 | 0x5C6DA4 |
| 07 | 0x5C6DB4 |
| 08 | 0x5C6DC4 |
| 09 | 0x5C6DD4 |
| 0A | 0x5C6DE4 |
| 0B | 0x5C6DF4 |

## Action5 secondary function table:0x711730

| State | Target |
| --- | --- |
| 00 | 0x640B00 |
| 01 | 0x6412B0 |
| 02 | 0x6421D0 |
| 03 | 0x645220 |
| 04 | 0x643E30 |
| 05 | 0x649850 |
| 06 | 0x643930 |
| 07 | 0x6432A0 |
| 08 | 0x649EC0 |
| 09 | 0x645A00 |
| 0A | 0x646140 |
| 0B | 0x6427C0 |
| 0C | 0x640B00 |
| 0D | 0x644620 |
| 0E | 0x644BC0 |
| 0F | 0x6467D0 |
| 10 | 0x649020 |
| 11 | 0x64A6D0 |
| 12 | 0x646F90 |
| 13 | 0x647410 |
| 14 | 0x648010 |
| 15 | 0x648BA0 |
