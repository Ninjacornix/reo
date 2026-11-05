# Actor family5AA160 complete primary-three and primary-four states

Static File #1 US research, 2026-11-04. All13 distinct original owners fully
reviewed,includinginternalstate0blocksmergedwithbothdispatchers. No game,
build,replay,attachmentorlive-memoryinspection. Addresses/offsets/IDshex;
floatconstantsandexplicitcountsdecimal. Numericstatesanddescriptorsretain
theirvalueswithoutinventedoriginalreaction/death/recoveryenumlabels.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5AC4D0](../recomp/config/output_ovl/o2/o2_005AC4D0_0x5ac4d0.cpp) | `dispatch_primary_three_and_state0_paired_response_descriptor_candidate` | Probable role; full body reviewed | ORsrecordbyte45bit10 at74F250+60*actorB98 beforeuncheckedsubstate9dispatch709C20. Internalstate0at5AC520belongsmergedowner: A0->1selectsdescriptor1F+(B&1)if188else1D+(B&1),f12=0. A1ticks1,positivesignedresult->5AD820. No directhealthchangeorbankactivationcall. |
| [o2 0x5AC5D0](../recomp/config/output_ovl/o2/o2_005AC5D0_0x5ac5d0.cpp) | `primary_three_state1_four_way_response_descriptor_candidate` | Probable role; full body reviewed | A0->1usesbyte188/B1F:cleared188=>descriptor21ifB1F0else22;set188=>23/24,f12=0. A1ticks1,positivesignedresult->5AD820. No localactiontransitionorhealthbranch. |
| [o2 0x5AC6B0](../recomp/config/output_ovl/o2/o2_005AC6B0_0x5ac6b0.cpp) | `primary_three_state2_route_finished_response_by_health_and_variants_candidate` | Probable role; full body reviewed | A0->1selects25/26if188clearbyB1F,27/28ifset. A1ticks1. Positiveanimationresult:health544>0routes5ADB30(4,6)if188,else(4,0)ifB1F0or(4,3). Health<=0routes(4,8)if188,else(4,2)/(4,5). Beforepositivecompletion,orderedframe1E4>30.0calls5AEC60(actor,1). No directhealthrestoration. |
| [o2 0x5AC870](../recomp/config/output_ovl/o2/o2_005AC870_0x5ac870.cpp) | `primary_three_state3_ballistic_response_away_from_bound_entity_candidate` | Probable role; full body reviewed | Requiresactor11Cpointer,BA5=1. A0->1yawfrom5A9A40(actor,signedtarget3),Y+=70;XZvector(source-target)normalizedtospeed10unlesslength0,storedD04XYZwithY0. D0=floatglobal74F200,half12=A,descriptor29/f12=0,activate. A1tick1;ground170or188max(170,184-135),with174FFdirect184-135. D08-=D0;predecrement12,positiveaddsfullXYZmotion,elseYonly. OnY+4E8<=ground:188clear->A2,Ysnap,descriptor2A;188set->A3,health<=0Ysnap/descriptor33/f12=142;positivehealthY=ground-15,E=10/global,rotate709CD8/dividedXYZtoward184-135,descriptor2B. A2positiveanimroutes(4,0)ifhealthpositiveelse(4,2),always5AEC60(1). A3positiveanimroutes(1,0)ifhealthpositiveelse(4,6);positivehealththenEpredecrement,movesXYZonlyifE>0. Ground/healthbranchesretainedwithoutoriginalreactionenum. |
| [o2 0x5ACD00](../recomp/config/output_ovl/o2/o2_005ACD00_0x5acd00.cpp) | `dispatch_primary_four_and_state0_descriptor2c_countdown_candidate` | Probable role; full body reviewed | Uncheckedsubstate9dispatch709C30;internalstate0at5ACD20sameowner. SetsC94OR201,54AOR4;health<=0byte32=FF. A0->1flipsyaw8000ifold520in25/2A,descriptor2C/f12=0,activate,6367C0;initialE<0calls5A8060,A2,health544=0. A1predecrementsE,negative5ADB30(4,1),ticks1. A2waitsbyte3B5050+B98==FFthen(4,1),ticks1. A5setsA2,descriptor2C/activate. Allotherphasesstill5AEC60(actor,0);no blockingpoll. |
| [o2 0x5ACEC0](../recomp/config/output_ovl/o2/o2_005ACEC0_0x5acec0.cpp) | `primary_four_state1_descriptor2e_restore_health_and_record_flags_candidate` | Probable role; full body reviewed | A0->1;ifold520==2Cflipsyaw8000;descriptor2E/f12=0,byte3B5050+B98=FF,health544restored546onlyifnonpositive,C2E=0,record45=0. A1ticks1,positivesignedresult5AD820;otherwiseorderedframe>80.0setsargument2. Always5AEC60(actor,arg0or2). Noactivity/recordindexguard. |
| [o2 0x5ACFF0](../recomp/config/output_ovl/o2/o2_005ACFF0_0x5acff0.cpp) | `primary_four_state2_zero_health_and_descriptor2d_candidate` | Probable role; full body reviewed | AlwaysC94OR201,54AOR4,byte32FF. A0->1health544=0,flipsyaw8000whenold52025/2A,descriptor2D/f12=0. A1ticks1,positiveresult5ADB30(4,0). Always5AEC60(actor,0). Doesnotfreeentityhere. |
| [o2 0x5AD0D0](../recomp/config/output_ovl/o2/o2_005AD0D0_0x5ad0d0.cpp) | `primary_four_state3_descriptor2f_countdown_candidate` | Probable role; full body reviewed | AlwaysC94OR201/54AOR4,nonpositivehealth32FF. A0->1descriptor2F/f12=0,activate,6367C0;E<0calls5A8060,A2,health0. A1predecrementsE,negative->5ADB30(4,4),ticks1. A2waits3B5050+B98FFthen(4,4),ticks1. A5setsA2descriptor2F/activate. Always5AEC60(actor,0);noinitialyawflipunlikeprimary4state0. |
| [o2 0x5AD250](../recomp/config/output_ovl/o2/o2_005AD250_0x5ad250.cpp) | `primary_four_state4_descriptor31_restore_health_and_flags_candidate` | Probable role; full body reviewed | A0->1descriptor31/f12=0,timerbyte3B5050+B98FF,healthrestoreifnonpositive,C2E=0,record45=0. A1tick1,positiveresult5AD820;otherwiseframe>80gives5AEC60argument2,else0. No old-motionyawflip;distinctfrom5ACEC0. |
| [o2 0x5AD360](../recomp/config/output_ovl/o2/o2_005AD360_0x5ad360.cpp) | `primary_four_state5_zero_health_and_descriptor30_candidate` | Probable role; full body reviewed | AlwaysC94OR201,54AOR4,byte32FF. A0->1health0,descriptor30/f12=0. A1ticks1,positiveresult->5ADB30(4,3). Always5AEC60(actor,0). No old-motionyawflip. |
| [o2 0x5AD410](../recomp/config/output_ovl/o2/o2_005AD410_0x5ad410.cpp) | `primary_four_state6_descriptor32_countdown_without_contact_posthelper_candidate` | Probable role; full body reviewed | C94OR201,54AOR4,nonpositivehealth32FF. A0->1flipsyaw8000onlyold52028,descriptor32/activate,6367C0;E<0calls5A8060,A2,health0. A1predecrementsE,negative->5ADB30(4,7),tick1. A2waitstimerbyteFFthen(4,7),tick1. A5setsA2descriptor32/activate. Unlike5ACD00/5AD0D0 nofinal5AEC60call. |
| [o2 0x5AD5A0](../recomp/config/output_ovl/o2/o2_005AD5A0_0x5ad5a0.cpp) | `primary_four_state7_descriptor34_restore_health_and_flags_candidate` | Probable role; full body reviewed | A0->1descriptor34/f12=0,timerbyteFF,healthrestoreifnonpositive,C2E=0,record45=0. A1ticks1,positiveresult5AD820. No final5AEC60ortime/frame-basedpostargument,unlike2E/31restorehandlers. |
| [o2 0x5AD670](../recomp/config/output_ovl/o2/o2_005AD670_0x5ad670.cpp) | `primary_four_state8_zero_health_and_descriptor33_candidate` | Probable role; full body reviewed | AlwaysC94OR201,54AOR4,byte32FF. A0->1health544=0,descriptor33/f12=0. A1ticks1,positiveresult5ADB30(4,6). No entityfree,old-motionflipor5AEC60posthelperinbody. |

Ownedtablescloseeveryprimary3/4slot:

| Table | Substate | Target / owner |
| --- | --- | --- |
| 709C20 | 0 | 0x5AC520 (internalowner5AC4D0) |
| 709C20 | 1 | 0x5AC5D0 |
| 709C20 | 2 | 0x5AC6B0 |
| 709C20 | 3 | 0x5AC870 |
| 709C30 | 0 | 0x5ACD20 (internalowner5ACD00) |
| 709C30 | 1 | 0x5ACEC0 |
| 709C30 | 2 | 0x5ACFF0 |
| 709C30 | 3 | 0x5AD0D0 |
| 709C30 | 4 | 0x5AD250 |
| 709C30 | 5 | 0x5AD360 |
| 709C30 | 6 | 0x5AD410 |
| 709C30 | 7 | 0x5AD5A0 |
| 709C30 | 8 | 0x5AD670 |

Togetherwith[primary-one](SYMBOLS_ACTOR_5AA160_PRIMARY_ONE.md)and
[primary-two](SYMBOLS_ACTOR_5AA160_PRIMARY_TWO.md),allfivevalidprimary
callbacksandtheirownedsubstatefamiliesareclosed. Sharedtransitions5AD720/
5AD820/5ADB30andresource/motionhelpersstillrequireindependentbodyreview.
InitialE<0takesaone-timealternatepath;laterpredecrementconditionisnegative,
notzero. No timerunderfloworautomaticroot-causeinterpretationismade.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
