# Actor 6C primary-one grounded and aligned movement handlers

Static File #1 US research, 2026-11-04. Twelve complete original bodies reviewed.
Addresses/offsets/stateIDshex; physical scalars and animationsteps decimal.
Actor identity and original state names unresolved. No target execution,
attachment, replay, profiling or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C5E60](../recomp/config/output_ovl/o2/o2_006C5E60_0x6c5e60.cpp) | `wait_actor_6c_motion_zero_cycles_then_delay_route_action_candidate` | High mechanics; probable role | A0->1,select0step0activate. A1advance1;result==1predecE,onlynegative->9990,otherwisereturn;result!=1and635640(actor,FA)nonzero ->A2,C=6349C0(C86). A2predecC;negative->635640,nonzero9AD0elseA1;alwaysadvance1afterward. Strictnegativepredicatesretained,notchangedto<=0. |
| [o2 0x6C5FA0](../recomp/config/output_ovl/o2/o2_006C5FA0_0x6c5fa0.cpp) | `walk_actor_6c_until_timer_route_policy_or_surface_steering_candidate` | High mechanics; probable role | A0->1select1step0activate. A1predecE<=0->9990;otherwise635640(actor,FA)nonzero->9AD0,zero->B420surfacesteering. AllA1pathsfinally58C300stepfloat7290F0+12*unsignedBA1. No BA1boundscheck. |
| [o2 0x6C6080](../recomp/config/output_ovl/o2/o2_006C6080_0x6c6080.cpp) | `play_actor_6c_motion_two_to_frame_48_then_default_four_candidate` | High mechanics; probable role | AlwaysBA5=1. A0->1select2step0activate. A1advance1;frame1E4>=decimal48->9ED0(actor,1,4). Completionreturnunused. |
| [o2 0x6C6120](../recomp/config/output_ovl/o2/o2_006C6120_0x6c6120.cpp) | `play_actor_6c_mode_three_motion_then_half_turn_and_default_four_candidate` | High mechanics; probable role | Always54A|1,BA5=1. A0->1,BA3=3,select3step0activate. A1advance1,result==1->yaw+=8000,select2step48,9ED0(actor,1,4). NoBA3clearorpositionwrite. |
| [o2 0x6C61F0](../recomp/config/output_ovl/o2/o2_006C61F0_0x6c61f0.cpp) | `pursue_actor_6c_related_target_with_alignment_oscillation_and_height_policy_candidate` | High mechanics; probable role | AlwaysBA5=1,BA3=3;reads24peer. A0->1,9A=C,BE70initvariant,select2step48activate;unlessprior1/4clears9C/D58;fallsA1samecall. A1advance1,BB30(BD8),headingtouncheckedpeerXYZminus9A->BD30,BE70integrate. Heightpolicybelow. 635640(actor,FA)==0->9ED0(actor,1,10);nonzeropredecE<=0->9B90. Laterpeer-nullheightfallbackisnotacompletenullguard. |
| [o2 0x6C64E0](../recomp/config/output_ovl/o2/o2_006C64E0_0x6c64e0.cpp) | `descend_actor_6c_with_forward_root_motion_until_ground_or_surface_candidate` | High mechanics; probable role | AlwaysBA3=3,BA5=1. A0->1,CC0,D0=-5,D4=5,select2step48activate. A1advance1,4EC=D4,Y=max(D28,Y-5);Y<=D28+44.655 ->A2select4step0activate;elseCAA20distance106.511,yawoffset0,outputsD00/D0C;successyaw=heading(D00,zero),9ED0(actor,1,6). A2advance1,result==1->BA3=0,9ED0(actor,1,0);thenframe<18decimalsets4EC=D4,Y=max(D28,Y-5)evenafterstatechange. Noimplicitjumpaftercompletion. |
| [o2 0x6C66F0](../recomp/config/output_ovl/o2/o2_006C66F0_0x6c66f0.cpp) | `play_actor_6c_alternate_shape_motion_then_enter_alignment_one_candidate` | High mechanics; probable role | AlwaysBA3=3,BA5=1. A0->1,select5step0,copysecondshapevia728FC8->730780+4toC70..7Cand1AC..1B8. A1advance1,positivecompletion->BA3=1,C82=1,savestate8/9,8/9=1/0,A/B0,select0step0activate,quaternionD18fromD00,C36=7. Nonpositivecompletionrecopiessecondshape. No defaultshape restorationhere. |
| [o2 0x6C6870](../recomp/config/output_ovl/o2/o2_006C6870_0x6c6870.cpp) | `play_actor_6c_surface_transition_then_restore_saved_secondary_and_motion_candidate` | High mechanics; probable role | AlwaysBA5=1,boundedA<7dispatch740F70;alwayscopiesXYZtomatrix80/84/88atend. A0motion9->A4;A1motionA->A4;A2motion9->A5;A3motion9->A6;allstep0,C82=1. A4/5/6advance1,positivecompletionC82=1,savestate,9=B,A=1,B0,selectsavedmotionD46step0activate,refreshquaternion,C36=7;A4keepsBA3,A5toggles1->0orother->1,A6toggles1->2orother->1. No 8writeonrestore. |
| [o2 0x6C6AF0](../recomp/config/output_ovl/o2/o2_006C6AF0_0x6c6af0.cpp) | `rotate_actor_6c_yaw_by_signed_100_until_action_timer_expires_candidate` | High mechanics; probable role | A0->1,9A=-100ifC==0else+100,select1step0activate. A1yaw+=signed9A,advance1,predecE<=0->9990. NoBD8deadbandorframe-factordivision. |
| [o2 0x6C6BB0](../recomp/config/output_ovl/o2/o2_006C6BB0_0x6c6bb0.cpp) | `wait_actor_6c_policy_then_play_motion_two_for_scaled_record_timer_candidate` | High mechanics; probable role | Always54A5,32FF,C94|209. A0->1,byte1=1,select2step48activate. A1predecE<=0setsE0,635640(actor,FA);nonzero->A2,E=decimal10*unsignedBB1. A2advance1,predecE<=0->9990. PositiveEphase1doesnotadvanceanimation;BB1timerhasnofactordivision. |
| [o2 0x6C6CC0](../recomp/config/output_ovl/o2/o2_006C6CC0_0x6c6cc0.cpp) | `play_actor_6c_motion_zero_then_admit_route_action_on_expiry_candidate` | High mechanics; probable role | A0->1select0step0activate. A1advance1,predecE<=0and635640(actor,FA)nonzero->9AD0. Ifpolicyzero,retainsphaseandcontinuesdecrementingonlatercalls;nobusyloop. |
| [o2 0x6C6D70](../recomp/config/output_ovl/o2/o2_006C6D70_0x6c6d70.cpp) | `move_actor_6c_with_random_heading_bias_and_surface_probe_candidate` | High mechanics; probable role | AlwaysBA5=1,BA3=3. A0->1select2step48activate,rotatesowned(0,0,20)byyaw/addsX/Zonce. A1->2,RNG&7indexes730630;0->9A0,1->+200,2->-200,E14;fallsA2samecall. A2advance1,yaw+=9A;174!=FFheightbandY<=D28+200add10,Y>=D28+300subtract10. 635640(actor,FA)nonzero->9ED0(actor,1,4),returnwithoutfinalmovement. OtherwiseCAA20distance106.511:successyawheading(D00,zero),9ED0(actor,1,6);failurepredecE<=0setsA1. Boththenrotate(0,0,20)byyaw/addX/Z. No nearest-playersearchorunboundedloop. |

`selectM stepS`=6CA610(actor,M,f12=S),`advance1`=58C300step1,
`activate`=58C7B0;motionIDshex. PhaseA and timers C/E/10 retain original
narrowing. 5E60 usesstrictnegativeC/Etestswhereothersuse<=0.

61F0 heightpolicy afterverticaloscillation,withF=D28,U=D2C,Q=peerY:

| Gate | Exact ordered action |
| --- | --- |
| BA7!=0 | Y<U-100 ->Y+=10;elseY>U-20 ->Y-=10;elseretain |
| BA7=0,174!=FF | Q=peerYwhenpeernonnull,otherwiseF;Y<F+150orY<=Q+200 ->Y+=5;elseY>=F+250 ->Y-=5;elseretain |
| BA7=0,174=FF,peernonnull | Y<=Q+200 ->Y+=5;elseY>=Q+300 ->Y-=5;elseretain |
| BA7=0,174=FF,peernull | RetainYhere;earlierheadingalreadydereferencedpeer |

6870 ownedseveninternalPCs740F70:6C68B0,68D0,68F0,6910,6930,69A8,6A38.
InitializationA0/1bothadvanceA4ratherthanordinaryA++;completionrestores
savedsecondaryBbutkeepsprimary8. This followsbranch/delayslotsliterally.

Owned730630eightchoicebytes[0,0,0,0,1,1,2,2].7305F0=(0,0,20).
Owned7290F0hasfour12-bytefloatrows(.3,.3,.3),(.5,.5,.5),(.8,.8,.8),(1,1,1);
5FA0consumesfirstfloatofrowBA1,noindexguard. Owned740FF8=106.5110015869,
741000=44.6549987793. Shape730780+4->730770=(0,0,-48,48).
No runtime records or non-file-backedtables decoded.

Allseventeenprimary-onecallbacks730520nowhavefullbodyroles:theotherfive
70A0/71C0/7340/74D0/78D0arein[crossingsequences](SYMBOLS_ACTOR_6C_CROSSING_SEQUENCES.md).
See[bootstrap](SYMBOLS_ACTOR_6C_BOOTSTRAP.md),[alignmentcollision](SYMBOLS_ACTOR_6C_ALIGNMENT_COLLISION.md),
and[variantselection](SYMBOLS_ACTOR_6C_VARIANT_ACTION_SELECTION.md).
No actioncount or animationadvancecount is interpreted as global gameupdates.
