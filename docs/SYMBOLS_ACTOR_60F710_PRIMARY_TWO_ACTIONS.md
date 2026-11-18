# Actor60F710 primary-two turning and ballistic action family

Static File #1 US,2026-11-04. Six complete original o2 catalog bodies; dispatcher611030includesinteriorsecondary0611050. Mechanics high confidence, actionlabels candidateswithoutoriginalattacknames. No target execution/build/attachment/live memory/input/timing. Addresses,IDsandfieldoffsetshexadecimal;distancesandexplicitcountsdecimal. [Root/motionhelpers](SYMBOLS_ACTOR_60F710_ROOT_PRIMARY_ONE_AND_AIM.md),[state/timers](SYMBOLS_ACTOR_60F710_REACTION_AND_CONTROL_HELPERS.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x611030](../recomp/config/output_ovl/o2/o2_00611030_0x611030.cpp) | `dispatch_actor_60f710_primary_two_and_tick_merged_motion12_action_candidate` | High mechanics; candidate role | Unchecked6-target70EBC0taildispatch. Interior611050hasfourphases:save10=yaw+BD8,optionalturnaroundmotion1Cwhenbearingoutside(-5000,5000),clears115bit1;turn637B40(limit800),motion12;positivecompletion115bit1and615570(1,2). Mergeddispatcherandsecondary0onecatalogbody. |
| [o2 0x6111E0](../recomp/config/output_ovl/o2/o2_006111E0_0x6111e0.cpp) | `tick_actor_60f710_primary_two_secondary_one_turn_and_motion13_candidate` | High mechanics; candidate role | Fourphaseslike611050:optional1C/yaw8000reversal,turntosaved10limit800,motion13. Positivecompletionrestores115bit1andcalls614D30insteadfixed(1,2). No localtargetNULLgate. |
| [o2 0x611360](../recomp/config/output_ovl/o2/o2_00611360_0x611360.cpp) | `tick_actor_60f710_primary_two_secondary_two_motion14_with_early_tracking_candidate` | High mechanics; candidate role | A0motion14,clear115bit1. A1motionposition<=128calls637B40(BD8,200),thentick1;positivecompletionrestore115bit1and614D30. Turnhelperreturnignored;unorderedframetestdoesnotturn. |
| [o2 0x611420](../recomp/config/output_ovl/o2/o2_00611420_0x611420.cpp) | `tick_actor_60f710_primary_two_secondary_three_motion15_and_yaw_offset_candidate` | High mechanics; candidate role | Fourphasesoptional1C/yaw8000reversal/turn800tomotion15;positiveend115bit1,615380motion0,yaw+=5000,then614D30. Notinterchangeablewithmotion13helperwhichomitsfinalyawoffset. |
| [o2 0x6115C0](../recomp/config/output_ovl/o2/o2_006115C0_0x6115c0.cpp) | `tick_actor_60f710_primary_two_secondary_four_ballistic_motion16_action_candidate` | High mechanics; candidate role | Fivephases:saveyaw+BD8,motion16/32FF;frame not<18launchforward16,Yvelocity32,clear115bit1/BA51. Copiesflightchannels,position/gravityuntilapex;descendingphaseuses10aslandedflag,stopsphysicalmoveafterlandingbutkeepsanimation. PositiveanimationANDlanded->motion17/A4/BA50;positiveend614D30. |
| [o2 0x611900](../recomp/config/output_ovl/o2/o2_00611900_0x611900.cpp) | `tick_actor_60f710_primary_two_secondary_five_turn_and_motion1f_candidate` | High mechanics; candidate role | Fourphaseoptionalturnaround1C,savedtargetyaw/turn800,motion1F;positivecompletionrestore115bit1and615570(1,2). Sameoutcomeasmergedsecondary0butdistinctmotion1F. |

Thefourphasefamilies611050/6111E0/611420/611900allreadcachedBD8,savehalf10=ownyaw+BD8,thenbranchonbearingstrictly(-5000,5000). InsidewindowinitializeA2/motion0;outsideinitializeA1/motion1C. Bothclear115bit1. A1tick1positiveadvancesA2,flipsyaw8000,andrequests0throughno-blend615380. A2calls637B40(actor,sign16(saved10-yaw),800);nonzero->A3/finalmotion. A3tick1positiveperformsitsdistinctoutcome. Frameupdatesarenotcountedglobally;thehookperactorcallfrequencyremainsunmeasured.

| Entry | Final motion | Positive final outcome |
| --- | --- | --- |
|611050(interior)|12|115bit1,(1,2)through615570|
|6111E0|13|115bit1,614D30|
|611420|15|115bit1,motion0withoutblend,yaw+=5000,614D30|
|611900|1F|115bit1,(1,2)through615570|

611360isdistinct:itdoesnotperformtheoptionalinitialhalfturnorsavestargetyaw. Motion14ticksafteranoptionalturnonlywhilecurrentframe<=128(floatorderedcomparison),withlimit200. Positivecompletionrestores115bit1then614D30. No targetpointerisdereferencedinthesebodies;callerpolicyhasalreadyselectedtheactionusingcachedtargetmetrics.

6115C0phase0selects16,saves10,32FF. Phase1tick1andturn637B40(saved10-yaw,800)everycall;whenframenot<18,launchCCXYZ=(16sin(yaw),32,16cos(yaw)),BA51,clear115bit1,A2. Phase2copiesflightchannelsetfromword729008secondpointer,tick1,position+=CCXYZ,D0+=owned-3.2;whenD0<=0setsA3AND10=0. Phase3copiesflightchannels,thenonlywhile10==0integratesmovement/gravityandqueries616F20. Heightnot<YsnapsYandsets10=1. Everyphase3callticks1;positivecompletionaloneisinsufficient,landedflag10mustalsononzero. BoththenA4,motion17,BA50. A4positivecompletion614D30. Surfacequerytypeoutputisignored. Once10==1physicalballisticupdatesstopwhileanimationcontinues,distinguishingthisactionfromtheprimary1hop6/7contract.

Thisbodydoesnotset115bit1ontheballisticaction'snormalexit;theflagwasclearedatlaunchandremainssubjecttootheroriginalstatehelpers. The omissionisrecordedwithoutdeclaringabug. Eachcallrunsonephasebranch;nointernalwaitinguntilcontactoranimationcompletionandnoanimationframecountasglobaltickassumption.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Full6-targetdispatch70EBC0..70EBD7:

`611050, 6111E0, 611360, 611420, 6115C0, 611900`,SHA256 `6085cf94d017020f930ba0e86b9cbf0483b2eab1e8239d91e173f4d8ccb31c09`. Thefirsttarget611050isinteriorto611030catalogbody,notanextracoveragecount. Flightchannelandgravityfixedbytesretainpriorrootnotebookhashes. Noactualactoridentity,slowroomadmission,executionfrequencyorperformancecausewasmeasured.

Owned-word audit:six complete bodies,602 original instruction words verified,53 omitted zero/NOP words,zero conflicts and zero omitted nonzero words.Full6-targetdispatchhashed.CurrentliveIDs/actualannotations/links/diffclean; no shared index mutation.
