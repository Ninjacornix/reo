# Actor 6C multi-motion descent and recovery reactions

Static File #1 US research, 2026-11-04. Six complete catalog bodies reviewed,
including merged internal9020 in8FE0. Addresses/offsets/states hex; explicitly
marked scalar steps and positions decimal. Original reaction enums and actor
identity unresolved. No execution, attachment, replay, profiling or fixes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C8740](../recomp/config/output_ovl/o2/o2_006C8740_0x6c8740.cpp) | `play_actor_6c_motion_15_and_return_to_primary_one_four_candidate` | High mechanics; probable role | AlwaysBA5=1. A0->1,select15step0,activatebanks. A1advance1;onlysignedbyte result==1 ->9ED0(actor,1,4). Otherphasesreturn. |
| [o2 0x6C87D0](../recomp/config/output_ovl/o2/o2_006C87D0_0x6c87d0.cpp) | `play_actor_6c_mode_three_descent_then_choose_health_restore_state_candidate` | High mechanics; probable role | AlwaysBA5=1. A0->1,BA3=3,select11step0,activate. A1advance1,result==1->A2,select10step18,activate. A2advance1;Y<=D28+ownedH ->A3,Y=D28+H,BA3=0,select13step0;clampsY>=D28. A3setsBA5=0,advance1;positivecompletion->primary4secondary1if544>0,else2ifrecord74F294+60*B98==1,otherwise0. H=decimal45.1150017. |
| [o2 0x6C89C0](../recomp/config/output_ovl/o2/o2_006C89C0_0x6c89c0.cpp) | `reflect_actor_6c_yaw_then_wait_for_floor_and_health_restore_candidate` | High mechanics; probable role | A0->1,select4step0. A1advance1,positivecompletion->A2,BA5=1,BA3=3,5A8420(actor,D00)reflectyaw,D0=-5,select10step18,activate. A2advance1,Y<=170 ->A3,Y=170,BA3=0,select13step0. A3advance1,positivecompletion->primary4secondary1if544>0,else2ifrecordbyte==1else0. Recordbyte74F294+60*B98. No BA5clearinthisbody. |
| [o2 0x6C8B90](../recomp/config/output_ovl/o2/o2_006C8B90_0x6c8b90.cpp) | `play_actor_6c_three_motion_reaction_and_select_record_restore_state_candidate` | High mechanics; probable role | Always54A|4,32FF,C94|1,C82=1. A0->1select12step0activate. A1result==1->A2select13step0activate. A2result==1->A3select16step0activate. A3result==1->primary4secondary2ifrecord74F294+60*B98==1,else0. AllA1/2/3advance1. NohealthcomparisonorBA3write. |
| [o2 0x6C8D40](../recomp/config/output_ovl/o2/o2_006C8D40_0x6c8d40.cpp) | `play_actor_6c_six_phase_descent_and_record_restore_reaction_candidate` | High mechanics; probable role | Always54A|4,32FF,C94|1;boundedA<6dispatchowned740FB0. A0->1,BA5=1,select10step0activate. A1BA5=1,advance1,frame1E4>=18decimal ->A5/E28if174FF,elseA2. A2BA5=1,advance1;Y<=D28+H ->A3,Y=D28+H,BA3=0,select13step0activate;clampsY>=D28. A3advance1,result==1 ->A4select16step0activate. A4BA5=0,advance1,result==1 ->primary4secondary2ifrecordbyte1else0. A5advance1,predecE<=0 ->A3select13step0activate. H45.1150017decimal,record74F294+60*B98. |
| [o2 0x6C8FE0](../recomp/config/output_ovl/o2/o2_006C8FE0_0x6c8fe0.cpp) | `dispatch_actor_6c_fade_secondary_with_merged_inactive_fade_handler_candidate` | High mechanics; probable role | Always54A|4,32FF,C94|1;tail7305A0[unsigned9]. Threeownedtargets merged9020,9180,9200. Merged9020 always54A4,C94|209,32FF;A0->1/E14,6367C0,select14step0;A1predecE<=0 advancesA,advance0;A2CCC>=8subtract8elseA3,byte1=0,CCCFF;copiesCCCtoCCD/CCE/CCF,advance0. A3byte1=0. A5->A3,select14step0,activate. Unlike9200,no relocationrecordorhealthrestore. |

In this notebook `selectM stepS` means6CA610(actor,motionM,f12=S);`advance1`
means58C300(actor,f12=1),and`activate` means58C7B0. Scalar steps0/1/18
are decimal. Motion/phase/state IDs stay hex. Completion predicates distinguish
exact==1fromsignedbyte>0;noequivalenceisassumed.

Owned740FB0sixinternalPCs8D98,8DC4,8E24,8EB0,8F00,8F78 correspondtoA0..5.
Owned7305A0threecallbacks6C9020,6C9180,6C9200,nextword0.
Owned740FD8float45.1150016785. Health544 andrecordbytearenotreadlive.
Related [relocation/resume](SYMBOLS_ACTOR_6C_RELOCATION_RESUME.md),
[motionhelpers](SYMBOLS_ACTOR_6C_MOTION_CONTROLS.md),and
[reactionselection](SYMBOLS_ACTOR_6C_CONTACT_REACTIONS.md).
