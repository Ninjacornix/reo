# Actor 6C steering, crossing and contact motion sequences

Static File #1 US research, 2026-11-04. Eleven complete catalog bodies reviewed,
including merged7BB0 in7B90 and8270 in8220. Addresses/offsets/stateIDshex;
physical scalars and animationsteps decimal. Actor identity/original action names
unknown. No target execution, attachment, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C70A0](../recomp/config/output_ovl/o2/o2_006C70A0_0x6c70a0.cpp) | `lower_actor_6c_during_motion_then_select_route_or_default_action_candidate` | High mechanics; probable role | A0->1,select0step0,activate. A1Y-=decimal10,advance1,predecE;post<=0 and635640(actor,FA)nonzero ->A2select17step0. A1thenfallsintosecondadvance1unconditionally,includingEpositiveorpolicyzero;A2alsoenterssecondadvance. Positive secondcompletion tests635640again;nonzero9AD0routeaction,zero9990variantaction. No automaticglobaltick interpretation. |
| [o2 0x6C71C0](../recomp/config/output_ovl/o2/o2_006C71C0_0x6c71c0.cpp) | `move_actor_6c_vertical_mode_three_to_fixed_height_band_then_default_candidate` | High mechanics; probable role | Always54A|5,BA5=1,BA3=3. A0->1,D0=+8ifY+200<owned-3200else-8;select8step0activate. A1advance1,Y+=D0;negativeD0stopsY<=-3050,nonnegativewhenY>=-3050;thenA2select17step0. A2advance1,positivecompletion9990. Scalars8/200/-3050decimal;no finalYsnap. |
| [o2 0x6C7340](../recomp/config/output_ovl/o2/o2_006C7340_0x6c7340.cpp) | `steer_actor_6c_toward_fixed_point_with_vertical_band_and_contact_timer_candidate` | High mechanics; probable role | AlwaysBA5=1,BA3=3. A0->1,9A=C,BE70(actor,0,signedvariant4),select2step48,activate. A1advance1,635640(actor,FA)sideeffectsretainedbutreturnunused;headingto7305E0minusyaw->BB30;headingminus9A->BD30withsamepoint. Y>-2950subtract5;Y<-3000add5;otherunchanged. PredecE<=0->9B90contactselector. DoesnotcallBE70integrationinA1. |
| [o2 0x6C74D0](../recomp/config/output_ovl/o2/o2_006C74D0_0x6c74d0.cpp) | `advance_actor_6c_oscillating_crossing_then_sine_scaled_return_candidate` | High mechanics; probable role | A0initializesA1,9A=C,timer10=10hex,D4=20/16,D30..38=owned(0,0,20),D0=-(2*(rng%5)+10)/10,D58=6,select2step48activate;fallsA1samecall. A1advance1,BB90,CBC00,predec10<=0->A2/10=8,D4=D38/8. A2sameadvance/turn/CBC00,conditionalfloorY>=D28,predec10<=0->A3,BE70initvariant. A3advance1,BB90,BE70integrate;predecE<=0->A4,10=3C,D4=0,D0=90/60,9A=yaw. A4advance1,turn,verticalintegrate,D4=min(90,D4+D0),sine65536*D4/360roundedsigned16scalesowned(0,0,20),rotates9A/addsX/Z;predec10<=0->1/Eifvariant1else1/4. Scalars20/90/360/48decimal;timerhexexplicit. |
| [o2 0x6C78D0](../recomp/config/output_ovl/o2/o2_006C78D0_0x6c78d0.cpp) | `decelerate_actor_6c_horizontal_motion_wait_then_restore_speed_candidate` | High mechanics; probable role | A0->1,9A=C,10=1E,D30..38=(0,0,20),D4=20/30,select2step48activate;fallsA1samecall. A1advance1,D38=max(0,D38-D4),rotates(D30,D34,D38)by9A/addsX/Z,predec10<=0->A2. A2advance1,predecE<=0->A3,10=1E,D38=0,9A=yaw. A3advance1,D38=min(20,D38+D4),samerotatedXZmovement,predec10<=0->9ED0(actor,1,B). Noverticalmovement. |
| [o2 0x6C7B90](../recomp/config/output_ovl/o2/o2_006C7B90_0x6c7b90.cpp) | `dispatch_actor_6c_secondary_launch_sequence_with_merged_contact_crossing_candidate` | High mechanics; probable role | Tail730568[unsigned9],ownedtwoentriesmerged7BB0/7F00. Merged7BB0alwaysBA3=3,BA5=1,requires24nonnull;fivephasesdetailedbelow. Noindexguardandno originalactionenum. |
| [o2 0x6C7F00](../recomp/config/output_ovl/o2/o2_006C7F00_0x6c7f00.cpp) | `run_actor_6c_three_axis_oscillating_contact_sequence_candidate` | High mechanics; probable role | AlwaysBA3=3,BA5=1,requires24nonnull. A0->1,E=F,D0=2,select8step0activate. A1advance1,Y+=D0,yaw+=634B20(BD8,800),predecE<=0 ->A2,zeroD30..38/CC,D0=-1.8,D4=.8,D58/C=28,E=D58/2,10=D58/4,115&=FE,5DA2C0(actor,81,1),select18step0activate. A2:54A|4,advance1,D30..38+=CC/D0/D4;D38=max(20,D38),rotatevectorbyyaw/addXYZ;predecE<=0resethalfD58,negateCC/D4;predec10<=0resethalfD58,negateD0;predecC<=0->115|1,BAF0variantdefault. No force-based interpretation. |
| [o2 0x6C8220](../recomp/config/output_ovl/o2/o2_006C8220_0x6c8220.cpp) | `mark_actor_6c_record_reaction_bit_and_dispatch_secondary_sequence_candidate` | High mechanics; probable role | ORrecord74F295+60*B98with10,tail730570[unsigned9]. Elevenownedcallbacks;merged8270phase0->1select12step0activate;A1advance1result==1->A2select13step0activate;A2advance1result==1->9ED0(actor,3,6). Nohealthread. |
| [o2 0x6C8360](../recomp/config/output_ovl/o2/o2_006C8360_0x6c8360.cpp) | `play_actor_6c_motions_12_13_then_primary_three_six_candidate` | High mechanics; probable role | A0->1select12step0activate;A1advance1signedbyteresult==1->A2select13step0activate;A2advance1result==1->9ED0(actor,3,6). No recordflagORinthisbody;notcollapsedwithmerged8270withoutreview. |
| [o2 0x6C8450](../recomp/config/output_ovl/o2/o2_006C8450_0x6c8450.cpp) | `play_actor_6c_motion_e_with_floor_clamp_then_default_four_candidate` | High mechanics; probable role | AlwaysBA5=1. A0->1selectEstep0activate. A1advance1,result==1->9ED0(actor,1,4),thenclampY>=D28regardlesscompletion. A2advance1,result==1->same1/4withoutfloorclamp. Otherphasesreturn. |
| [o2 0x6C8540](../recomp/config/output_ovl/o2/o2_006C8540_0x6c8540.cpp) | `run_actor_6c_six_phase_floor_descent_or_short_delay_reaction_candidate` | High mechanics; probable role | AlwaysBA5=1,boundedA<6dispatchowned740F90. A0->1select10step0activate. A1advance1,frame1E4>=18decimal ->A4/E2if174FF,elseA2. A2advance1,Y<=D28+H ->A3/Y=D28+H/BA3=0/select13step0;thenclampY>=D28. A3BA5=0,advance1,positivecompletion->9ED0(actor,4,1). A4advance1,predecE<=0->A5selectEstep16. A5advance1,positivecompletion9990. Hdecimal45.1150017. |

`selectM stepS`=6CA610(actor,M,f12=S),`advance1`=58C300step1,
`activate`=58C7B0;motionIDsremainhex,stepsdecimal. TimerfieldsC/E/10/D58
are signedhalves;everypredecrementbranchusespostvalue<=0.

Merged6C7BB0 complete sequence,alwaysBA3=3/BA5=1 andrequires24:

- A0->1,E=F,D0=2,select8step0,activate.
- A1advance1,Y+=D0,yaw+=634B20(BD8,800);predecE<=0->A2,selectBstep0,activate.
- A2advance1;frame1E4>=decimal24->A3,rotateowned(0,-25,25)730638byyaw,
  copytoCC/D0/D4,E=A,115&=FE,5DA2C0(actor,6D,1).
- A3advance1,XYZ+=CC/D0/D4;174!=FFclampsY>=170. If5A8590(actor)nonzero:
  A4,115|1,1B9310(actor,8,0),selectCstep0. OtherwisepredecE<=0or
  positiveCAA20(actor,normal-out,point-out,yawoffset0,f12=50) ->A4,115|1,
  selectCstep0. Traceoutputsarenotreadhere;traceisskippedafterexpiry.
- A4advance1,positivecompletionyaw+=8000,A6C0motion2step48(argument
  isoverriddenbyA6C0'sownstep1),thenBAF0variantdefault1/Eor1/4.

Owned730568twopointers6C7BB0/6C7F00;730570elevenpointersinorder:
6C8270,6C8360twice,6C8450,6C8540twice,6C8740,6C87D0,6C89C0,6C8B90,6C8D40.
Owned740F90sixinternalPCs6C8580/85A4/8600/8680/86B4/8708 correspondA0..5.
Owned7305E0=(4504,-3200,3526),7305F0=(0,0,20),730638=(0,-25,25),
740FD8=45.1150016785,740FE0=.8000000119,740FE8=-1.7999999523,
740FF0=6.28318548. Onlyfile-backeddataused.

The70A0twoanimationadvancesinphase1and74D0/78D0initializationfallthrough
werecheckedagainstbranch/delayslots,notnormalizedtoonecallperupdate.
No claim is made that any such behavior causes lag.
Related [motionhelpers](SYMBOLS_ACTOR_6C_MOTION_CONTROLS.md),
[alignmentcollision](SYMBOLS_ACTOR_6C_ALIGNMENT_COLLISION.md),
[variantselection](SYMBOLS_ACTOR_6C_VARIANT_ACTION_SELECTION.md),and
[descentreactions](SYMBOLS_ACTOR_6C_DESCENT_REACTIONS.md).
