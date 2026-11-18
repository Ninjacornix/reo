# Actor family5AA160 shared state and motion transitions

Static File #1 US research, 2026-11-04. All eight original bodies fully
reviewed,includinginitialtimerbranches,byteversuswordwrites,andcontact
return-valueadmission. No game,build,replay,attachmentorlive-memoryinspection.
Addresses/offsets/IDshex;explicitcounts/floatconstantsdecimal. This connects
thecompleteprimaryfamiliesinthe[updatenotebook](SYMBOLS_ACTOR_5AA160_PRIMARY_ONE.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5AD720](../recomp/config/output_ovl/o2/o2_005AD720_0x5ad720.cpp) | `reset_actor_family_to_primary_one_with_random_idle_choice_candidate` | Probable role; full body reviewed | Savesaction8/phase9->BE8/BE9,clearsA/B. Onlyprevious(1,0)randomizeslowBYTEBA0:188setRNG%A<3gives0else1;188clearonlyremainder0gives0else1. OtherpreviousstatesBA0byte=0. Thenaction8=1,phase9=BA0byte,5ADC60,C36=1. This writesbyteBA0,notentirewordflags; exactRNGchannel1. |
| [o2 0x5AD820](../recomp/config/output_ovl/o2/o2_005AD820_0x5ad820.cpp) | `choose_actor_family_next_state_from_contact_policy_and_target_geometry_candidate` | Probable role; full body reviewed | Related24nonnullrequired;saveold8/9->BE8/BE9,clearA/B. SignedhalfBF8+14*C25+2*C26<FA->half10=0,5AD720,return. Otherwise5AE8E0nonzerostops. Response5A62D0(actor,3FFC,11,f12=120)routes1->(1,4),2->(1,3),3->(1,3)ifBD4<120else(1,4),others0/5->(1,3). Response4uses188/targetgeometry tablebelow. Finallychosenprimary1withBD4<200andsignedBD8outside[-3000,3000]saveschosenphaseB,phase9=5. Allcompletedchoices5ADC60,C36=1. Q/contactpolicycallsretain sideeffects; nohealthwriteinthisbody. |
| [o2 0x5ADB30](../recomp/config/output_ovl/o2/o2_005ADB30_0x5adb30.cpp) | `set_actor_family_primary_substate_and_reinitialize_phase_timer` | Probable role; full body reviewed | a0 actor,a1 primary,a2 substate. Savesold8/9->BE8/BE9,storeslowbytesa1/a2,zerosA/B,5ADC60,C36=1. Nobounds,enumvalidationormotionselectioninwrapper. |
| [o2 0x5ADB80](../recomp/config/output_ovl/o2/o2_005ADB80_0x5adb80.cpp) | `randomize_actor_family_secondary_variant_for_selected_states_candidate` | Probable role; full body reviewed | Only(8,9)in{(1,0),(1,2),(1,6),(1,7),(3,0)}setsB=RNG(1)lowbit. OthersleaveBunchanged. Doesnotinitializephaseortimer;calledby5ADC60aftertimerwork. |
| [o2 0x5ADC60](../recomp/config/output_ovl/o2/o2_005ADC60_0x5adc60.cpp) | `initialize_actor_family_state_timer_and_secondary_variant_candidate` | Probable role; full body reviewed | ClearsEfirst. Primary1:sub0 E=1+(RNG&1);sub1 E=((RNG%12C)+12C)/unsignedglobal74F200;sub4 E=((RNG%B4)+78)/global;sub2/5 E=((RNG%78)+3C)/global. Otherprimary1substatesretain0. Primary4sub0/3/6 E=634880(actor,C2A)ifhealth544>0elseFFFF. Otherprimary4statesretain0. Always5ADB80afterward. No zero-divisorguard; alltimerstoresnarrowedsigned16,andunitsareoriginalupdatetimesnotwalltime. |
| [o2 0x5ADE10](../recomp/config/output_ovl/o2/o2_005ADE10_0x5ade10.cpp) | `consume_actor_contact_select_response_and_update_family_state_candidate` | Probable role; full body reviewed | 637490(actor)resultstored11C anddereferencedwithoutlocalnullguard. B1E1clearsownB1E,setstargetB1E6. B1F=((5A9AA0(actor,target3)+4000)&FFFF)>>15. Calls728820[actor141](actor,17),audio6,optional666D40(target)whenword138>0;status=signedlow8(6407D0(actor,target,3E8)). Status1/2writesrecord45=1/2;nonzero140=2. Savesold8/9,positivehealth636EB0(actor,C24). Detailedprimaryresponsesbelow. Returns0forcancelledP2earlyphase,2forresponse-slotsetup,1foractualstateassignmentafterclearingA/B. DoesnotitselfreinitializeE/C36;updaterdoeswhenresult1. |
| [o2 0x5AE160](../recomp/config/output_ovl/o2/o2_005AE160_0x5ae160.cpp) | `apply_actor_family_root_delta_through_state_specific_scale_and_rotation_candidate` | Probable role; full body reviewed | Buildsmatrixfromactorangles90. Primary1sub6scales(1,pairY,pairZ)fromowned709CF0+8*C37;sub7(1,2.5,1). Primary2sub0scales(1,C40,1). OtherstatesuseactorB4/B8/BCscaleonlywhen54Abit8clear. Alwaysclears54Abit8. Rotates/transformsrootdelta4E4via1919D0intoC0XYZ,multiplieseachbyF0,addsactorXYZ. Copies6scale-pairsonto48-bytestackbuffer;C37unboundedhere. Originalrootmotion/clockbehaviorretained,no renderingpathchange. |
| [o2 0x5AE360](../recomp/config/output_ovl/o2/o2_005AE360_0x5ae360.cpp) | `select_actor_family_motion_descriptor_with_transition_specific_blend_candidate` | Probable role; full body reviewed | a0 actor,a1 fulltargetdescriptor,f12 initialframe. Current signed520==fulltargetdoesnoreconfiguration,ticks58C300(actor,1). Differenttargetselectsblendbasedprimary/old/targettablebelow;somepaths58C7F0beforechange. Calls5A85F0(actor,signedlow16target,incomingframe,blend). No directenumormodelnameinference;negativeblendsemanticsinexistinganimationhelperpreserved. |

## Response4 admission in5AD820

Actor188nonzero:ifhalfC<=0,targetBA0bit800000clearandtarget188nonzero,
choose(2,5);else(1,3). Actor188zero:ifC<=0,targethealth544<=signed546/4
(integerdivisiontowardzero),abs(targetY-sourceY)<20,targetBA0bit800000
clear,and5AA110(actor)true,choose(2,3). OtherwiseifBD4<120and(target54F31
orabsdeltaY<110),choose(2,7);else(1,3). The subsequent relative-bearing
redirectdescribedabovecanreplaceanyprimary1choicewithsubstate5.

## Contact response routing in5ADE10

Allactualassignmentsreturn1andclearA/B. Primary2sets115bit1first.

| Current primary/substate | Additional gate | Result |
| --- | --- | --- |
| 2,sub2/4/6 | A<2 | SetownandoptionalB24targetB1E6,667060(actor),return0withoutphaseassignment. |
| 2,sub2/4/6 | A>=2 |5A7C40(709C58,actorCD8),return2;retaincurrentprimary. |
| 2,sub0 | Always |(3,3). |
| 2,others | Always |(3,byte140). |
| 3,sub0/1 | status!=0 |(3,2). |
| 3,other/sub0/1status0 | Always |Initializepairedresponse-slots,return2. |
| 4,sub0/3/6 | status==1 |Keepprimary4,substate+=2. |
| 4,sub1/4/7 | status==1 |(3,2). |
| 4,others | Always |Initializepairedresponse-slots,return2. |
| Otherprimary,sub6/7 | Always |(3,3). |
| Otherprimary,others | Always |(3,byte140). |

## Complete descriptor blending rules in5AE360

Orderedruleswithfirstmatchwinning.Floatvaluesaredecimal.

| Primary | Old / target | Blend duration / additional action |
| --- | --- | --- |
| Any | old520==fulltarget |Tick1.0andreturnbeforeconfiguration. |
| 1 | E->3 | -10. |
| 1 | 5->3 | -20. |
| 1 | old9/A,target3 ORold3,target9/A | +20. |
| 1 | 3->B | -10. |
| 1 | targetD/E |0. |
| 1 | Otherdifferenttarget |+10. |
| 2 | target16/17/1B/1C | -4. |
| 2 | target11 | -14;58C7F0(actor). |
| 2 | target12 | -16;58C7F0(actor). |
| 2 | Other |0. |
| 3,sub3 | target2B | -16;58C7F0(actor). |
| 3,sub3 | 29->33 |+10. |
| Other | Any |0. |

These are original contracts,notconfirmedrootcauses. Missinglocaladmission
checksarekeptasuncertaintiesratherthanproposedbugfixes. Noanimationduration,
originalspeed,sourcecodeorruntimepipelinewaschanged.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
