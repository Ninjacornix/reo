# Actor interaction pose, wait and phase routing

Static File #1 US research, 2026-11-04. Twelve complete original catalogue bodies reviewed, including merged internal entries6A7C20/6A7F70/6A8420 inside their owning bodies. They are not extra semantic rows. Addresses/offsets/IDs hexadecimal; physical quantities and countdown constants explicitly decimal. No execution, attachment, build, replay or engine changes. Interaction descriptors/statuses retain numeric contracts; original action names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6A7630](../recomp/config/output_ovl/o2/o2_006A7630_0x6a7630.cpp) | `advance_actor_animation_and_wait_counter_then_enter_primary_one_one_candidate` | High mechanics; interaction role probable | Advance58C300(f12=1),predec signedhalfE;post<=0 ->6AA3C0(actor,1,1),else return. No animation-completiongate on counterdecrement;halfwrapretained. |
| [o2 0x6A7690](../recomp/config/output_ovl/o2/o2_006A7690_0x6a7690.cpp) | `route_actor_interaction_status_to_wait_bind_or_flag_phase_candidate` | High mechanics; interaction role probable | ID=byteR24, R=74F250+60*B98;status581DC0(ID).1/6 ->A=553=D7A=1,E=signed7197B0[signedR3E],motion8via6AB0E0,58C7B0,6B5920(actor,ID).4 ->A3,D7A1,E=decimal30,570260(actor,ABB).5andotherstatusreturn. Doesnotadvanceanimation,orselectmotion0onstatus4. |
| [o2 0x6A77C0](../recomp/config/output_ovl/o2/o2_006A77C0_0x6a77c0.cpp) | `advance_actor_wait_then_rearm_interaction_motion_and_matrix_binding_candidate` | High mechanics; interaction role probable | Advance58C300(f12=1),predecE;post<=0 ->A=1,553=1,E=7197B0[signedR3E],motion8,58C7B0,6B5920(actor,R24). DoesnotsetD7Ainthisbody. Stillwaitingreturn;notablockingloop. |
| [o2 0x6A7890](../recomp/config/output_ovl/o2/o2_006A7890_0x6a7890.cpp) | `enter_actor_interaction_motion58_and_reset_periodic_record_counter_candidate` | High mechanics; interaction role probable | SetsC82=1,A++,byte115clearmask1;selectsmotion58via6AB0E0alltracks,58C7B0,half10=decimal60. Doesnotresetprimary/substate orclaiminteractionstatus. |
| [o2 0x6A78F0](../recomp/config/output_ovl/o2/o2_006A78F0_0x6a78f0.cpp) | `tick_actor_interaction_motion58_pose_hold_and_periodic_record_publication_candidate` | High mechanics; interaction role probable | SetsC82=1,advance58C300,clearAB8/AB9,581730(1,R24,actor). CopiesAC8->yaw92 andD48XYZ->actorXYZ. Clampssignedhalf10>60to60,predecrements;post<=0reset60and5A6B20(actor,22).581DC0(R24)status1/5/6,orotherstatuswithAB8nonzero/AB9=7 ->A++,115OR1,motion59. Otherreturn;descriptorhelpermaywriteAB8/9afterinitialclear. |
| [o2 0x6A7A80](../recomp/config/output_ovl/o2/o2_006A7A80_0x6a7a80.cpp) | `advance_actor_completion_to_next_phase_and_motion_zero_candidate` | High mechanics; interaction role probable | Advance58C300(f12=1);signed8return>0 ->A++,6AB0E0(actor,0,alltracks). Otherreturn;no58C7B0callorcounterreset. |
| [o2 0x6A7AE0](../recomp/config/output_ovl/o2/o2_006A7AE0_0x6a7ae0.cpp) | `advance_actor_animation_and_route_interaction_status_zero_through_six_candidate` | High mechanics; interaction role probable | Advance58C300(f12=1),status581DC0(R24). Unsignedstatus<7dispatches740AF0:1/6 ->A=553=D7A=1,E=7197B0[signedR3E],motion8,58C7B0;2/3/4 ->A4,motion57;0/5return. Outside0..6return. No6B5920bindinthe1/6branchunlike6A7690. |
| [o2 0x6A7BE0](../recomp/config/output_ovl/o2/o2_006A7BE0_0x6a7be0.cpp) | `dispatch_two_phase_actor_interaction_pose_and_incline_wait_candidate` | High mechanics; interaction role probable | Everyentry54A=F,32=FF,C94OR201;dispatch7197F0[byteA],nolocalbound. Phase0internal6A7C20:A++,visible1=1;R45mask8requests584880(actor,3);581730(2,(R24-10)&FF,actor). SetyawAC8andXYZABC. SignedD45=1 ->D7C1/motionC,-1 ->D7C2/motionE,otherD7C0/motion8;58C7B0;E=7197B0[signedR3E]. Phase1external6A7D90. Otherphysicalslotsnull. |
| [o2 0x6A7D90](../recomp/config/output_ovl/o2/o2_006A7D90_0x6a7d90.cpp) | `advance_actor_interaction_wait_with_incline_dependent_motion_switches_candidate` | High mechanics; interaction role probable | 54A=C,advance58C300(f12=1),predecE. post<=0 ->6AA3C0(actor,1,1). Positivecounter:whileD7C0/1/2comparecurrent signedD45,changeamongD7C0/motion8,1/motionC,2/motionEontransition;eachchange6AB0E0and58C7B0. UnsupportedD7Cnochange. Full3x3tablebelow;nocounterreloadoninclinechange. |
| [o2 0x6A7F30](../recomp/config/output_ovl/o2/o2_006A7F30_0x6a7f30.cpp) | `dispatch_actor_eight_phase_interaction_position_probe_and_motion_sequence_candidate` | High mechanics; interaction role probable | Everyentry54A=F,32=FF,C94OR201,dispatch719800[byteA]withoutbound. Phase0internal6A7F70unpacksR24descriptor581B60;failure returnswithvisible1/5530writesretained. SuccessfulbranchesresolveXYZ/yaw,optionalforward60unit5DC570probe,rngrotatedlateraloffset[-30,29],saveD48XYZ,thenclassifyAB8/9and581DC0into phases1..4/motions/timers/binding. Otherphaseslistedbelow. Fullphase0contractretainedbelow;returndoesnotmeansuccess. |
| [o2 0x6A8400](../recomp/config/output_ovl/o2/o2_006A8400_0x6a8400.cpp) | `dispatch_actor_primary_seven_response_and_initialize_hidden_record_state_candidate` | High mechanics; interaction role probable | Dispatch718C30[byte9]withoutlocalbound;sub0internal6A8420header54A5/BA51/32FF/C94OR209. Phase0:A1,BA3=0,visible1=0,R24=R43,R3E=R41&7,E=A;motion0via6AB600,58C7B0,6AC7D0(actor,1),category1D58/R39clear,CCC..CCFreset. Phase1visible1=0,Epredec<=0 ->8=7,9=6,A=B=0. Other phasesheaderonly. Dispatchothernonnulltargetsreviewedseparately. |
| [o2 0x6A85B0](../recomp/config/output_ovl/o2/o2_006A85B0_0x6a85b0.cpp) | `tick_actor_incline_wait_from_record_kind_and_reenter_initial_authority_bank_candidate` | High mechanics; interaction role probable | Everycall54A=D,32FF,C94OR201then8. Phase0A1/visible1;D45selectsD7C0/1/2andmotions8/C/Evia6AB600then58C7B0. R3E=unsignedR41&7,E=signed719700[R3E],category1D58/R39clear,CCC..FFreset. Phase1advance58C300,Epredec;expired6A8DA0. PositivecounterusesD7C/D45motion-switchtablematching6A7D90. No BA5write inthisbody. |

R=74F250+60*unsignedB98. R24istheunsigneddescriptor/statusID,R3Easignedhalfwait-tableindex,R41asourcebytewhose&7isstoredatR3Ebytheinitializershere,R43anotherdescriptorbyte. No original statusenumisassignedto581DC0values. Somehelpercalleesarenotfullymapped;theirreturn/outputcontractsarelistedwithoutinventingnetworkdeliveryorpropagatingoldsideeffect-freeassumptions.

6A7F30 phase0 completion path:

1. Setvisible1,553=0;581B60(R24,out7F,out7E,out7D)mustnonzero. Itdoesnotlocallychecksource-sizeordescriptorranges.
2. out7Fnonzero:581730(1,ID,actor),copyAC8yawandABCXYZtoactor. Otherwise5816F0(ID,actor,&ABC,&AC8,0)mustsucceed,copyitsyaw/XYZ,rotateactorlocal(0,0,decimal60)through634DF0,probe5DC570(point,actor,4,f12=50)afterclearingAB8/9.
3. Addhorizontalrandomoffset:localX=(low16random%decimal60)-30,Y=Z=0,rotate191BC0byunsignedyaw*owned740BB0/decimal65536;addXZtoactorandcopyactorXYZ->D48XYZ.
4. IfAB8==0returnwithoutphaseincrement. ForAB8nonzero,AB9in1,2,3,4,5,6,27,28 ->A4/motion57. AB9=0orunsupportedreturns. AB9=7 ->A=553=D7A=1,E=7197B0[R3E],motion8,58C7B0,6B5920(actor,ID).
5. AB9=1Aor29queries581DC0(ID):status1/6 takesphase1wait/bindpathabove;status5 ->A2,motion0,58C7B0;status4 ->A3,D7A1,E=30,570260(actor,ABB),motion0,58C7B0;other ->A4,motion57.

Failedprobescanleavevisible/posewritesbeforetheearlyreturn. Thefunctiondoesnotspinwaitingfortheprobeandthisisnotareproducedrepeated-workdiagnosis. Thephasemustbeadmittedbyitsownerbeforetreatingtherepeatedphase0pathasafailure.

| 6A7F30 phaseA | Target |
| --- | --- |
| 0 | internal6A7F70 |
| 1 | 6A7630 countdown->1/1 |
| 2 | 6A7690 statusrouting |
| 3 | 6A77C0 countdown->phase1 |
| 4 | 6A7890 select58 |
| 5 | 6A78F0 posehold/status->select59 |
| 6 | 6A7A80 completion->motion0 |
| 7 | 6A7AE0 statusrouting |

6A7D90and6A85B0positivecountermotionupdates(unchangedcellsdonothing);everychangedcellsetsD7Cthen6AB0E0followed58C7B0:

| PreviousD7C | D45=0 | D45=1 | D45=-1 |
| --- | --- | --- | --- |
| 0 | unchanged | 1/motionC | 2/motionE |
| 1 | 0/motion8 | unchanged | 2/motionE |
| 2 | 0/motion8 | 1/motionC | unchanged |

OtherD45valuesandunsupportedD7Creturnwithoutswitch. Thecountdownisdecrementedfirst;expirychoosesstateentry/resetinsteadofperformingtheswitch. Eachcallbackdoesboundedworkthenreturns;nonewaitsinternallyforcounter/animationcompletion.

Owned o2base570000,SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Span | Exact contents / SHA256 |
| --- | --- |
| 7197F0..7197FF | words6A7C20,6A7D90,0,0;`8d344aaf681a33e89bd9a2b2b32418043df3840ed9aa3ffe4a3a58d10759cc91` |
| 719800..71981F | words6A7F70,6A7630,6A7690,6A77C0,6A7890,6A78F0,6A7A80,6A7AE0;`f61cdbecff635dc8ccbe5e7e350b563e7098d8ce4d60c746341724c5c9d2c145` |
| 718C30..718C47 | words6A8420,6A85B0,6A88B0,6A8A60,6A8C70,0;`cedae9e06c538df526a4267ade765f333f6bf79b62a0eaede6a1df80b7d93942` |
| 740AF0..740B0B | words6A7BC4,6A7B44,6A7BAC,6A7BAC,6A7BAC,6A7BC4,6A7B44;`9a9b63ef4fe95d8e7ed258377fc4d794e342b4771e5b8b84341fc3eb4edb9fee` |
| 7197B0..7197BF | first8signedtimerhalvesdecimal80,75,85,70,90,65,95,60;`cffb0cdffabcd908456f008a550e1ba23db57c262dd7f1ae67413af171387d5a` |
| 719700..71970F | first8signedtimerhalvesdecimal60,55,50,45,70,70,75,80;`424edea7f65b420dd9b5556eeaeee1189474da9df8136830bd596bbace78a52a` |
| 740BB0..740BB3 | float6.2831854820251465;`12d85026b5109a3119231704608d5991a63d8d397d2867a9fc522305810ddb76` |

Physicaltablelengthsarenotautomaticphase/substate/indexadmission.719700isfullycoveredforR41&7producerindices;otherR3Ewritersmayneedmoretableevidence. Nullslotsremainpointervalues,notfunctions. [Bounded motion sequences](SYMBOLS_ACTOR_BOUNDED_MOTION_SEQUENCES.md)close718C30othernonnulltargets;[authority banks](SYMBOLS_ACTOR_DEFAULT_AUTHORITY_BANKS.md)defineexpiredwait resets;[motionwrappers](SYMBOLS_ACTOR_MOTION_RESPONSE_INCLINE.md)defineblending;[matrixprogramselection](SYMBOLS_SCENE_MATRIX_PROGRAM_SELECTION.md)defines6B5920bindingselection.

Full-body owned-word audit: 12 rows, 1084 verified instruction words, zero conflicts, 77 omitted zero/NOP words, zero omitted nonzero words.
