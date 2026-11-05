# Actor bounded motion response sequences

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed. Addresses/offsets/motions/state values hexadecimal; timer constants explicitly decimal. No execution, attachment, build, replay or engine changes. Sequence names use observed motion IDs, not recovered animation or enemy names.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6A88B0](../recomp/config/output_ovl/o2/o2_006A88B0_0x6a88b0.cpp) | `advance_actor_motion36_8_68_sequence_then_primary_four_substate_c_candidate` | High mechanics; sequence role probable | Everycall54A=5,BA5=1,32=FF,C94OR201then8. PhaseA0:visible1=1,A1,6AC7D0(actor,1),6AB600(motion36,alltracks);category1clearsD58and74F289+60*B98;C37=0,CCC..CCF=FF. Phase1positive signed8 animationresult ->A2,selectmotion8via6AB0E0,58C7B0. Phase2positive ->A3,motion68,58C7B0. Phase3positive ->6AA3C0(actor,4,C). Othersheaderwritesonly. |
| [o2 0x6A8A60](../recomp/config/output_ovl/o2/o2_006A8A60_0x6a8a60.cpp) | `advance_actor_timed_motion8_then68_sequence_with_room_specific_skip_candidate` | High mechanics; sequence role probable | Samepercallheader54A5/BA51/32FF/C94OR209. Phase0visible1,A1,publish6AC7D0(actor,1). Ifscenario3243DA=1,room3DC=1,variant3DE=1: A2andselectmotion8. OtherwiseE=decimal180/u,select8,58C7B0. Thencommoncategory1D58/rosterbyteclear,C37=0,CCC..FFreset. Phase1advanceanimation;predecE<=0 ->6A8DA0. Phase2positiveanimation ->A3,motion68. Phase3positive ->4/C. uunsigned74F200,nodivisorguard. |
| [o2 0x6A8C70](../recomp/config/output_ovl/o2/o2_006A8C70_0x6a8c70.cpp) | `advance_actor_four_motion_a_completions_then_primary_four_substate_c_candidate` | High mechanics; sequence role probable | Samepercallheader. Phase0visible1,A1,publish6AC7D0(actor,1),E=4,selectmotionAalltrackszeroBlend6AB600,58C7B0;category1D58/rosterbyteclear;CCC..CCF=FF (doesnotclearC37here). Phase1onlysigned8animationreturn==1decrementsE;post<=0 ->6AA3C0(actor,4,C). Othervalue/stateonlyheaderwrites. Fouradmittedcompletionresults,notthecountofglobalframes. |

Thesearecallbackstate machines:eachcallperformsboundedlocalworkandreturns. No loopwaitsforanimationcompletioninsideoneinvocation.58C300issteppedwithf12=1;6AB600/6AB0E0retainoriginalmotionselectionandblending.58C7B0isdelegatedafterparticulartransitions;itmustnotbeassumedtohaveidenticaleffectsforeverytransition.

AllthreeheaderORoperationsareexecutedbeforephaseclassification. Type1D58and74F289roster-byteclearsoccuronlyinitialization;6ACB50clearsfourtargetselectionbytes. The explicitroomtriplebranchin6A8A60setsphase2andbypassesEinitializationand58C7B0;itdoesnotmodifytheglobalfactor. Eunderflowisnotastallclaim:phase1decrementsandimmediatelydispatchesresetwhenpost<=0. Motioncompletionreturn==1in6A8C70differsfromsignedpositiveinothersequences.

[Motion wrapper contracts](SYMBOLS_ACTOR_MOTION_RESPONSE_INCLINE.md), [action record publication](SYMBOLS_ACTOR_ACTION_ADMISSION_TURN.md),and [entry authority banks](SYMBOLS_ACTOR_DEFAULT_AUTHORITY_BANKS.md)provideconnectedcallees. No callfrequency,timecostorplayerincidentisclaimed.

Full-body owned-word audit: 3 rows, 284 verified instruction words, zero conflicts, 30 omitted zero/NOP words, zero omitted nonzero words.
