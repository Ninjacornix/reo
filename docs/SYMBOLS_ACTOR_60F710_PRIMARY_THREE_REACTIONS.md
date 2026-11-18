# Actor60F710 primary-three reaction and recoil family

Static File #1 US,2026-11-04. Ten complete o2 catalog bodies including mergeddispatcher/interiorfirststateandverifiedtailadapter. High-confidence mechanics; originalreaction/motionnamesunknown. No execution/build/attachment/live memory/input/timing. Addresses/IDs/fieldoffsetshexadecimal;distancesandexplicitcountsdecimal. [Root/channels/motion](SYMBOLS_ACTOR_60F710_ROOT_PRIMARY_ONE_AND_AIM.md),[reaction/state/probehelpers](SYMBOLS_ACTOR_60F710_REACTION_AND_CONTROL_HELPERS.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x611A90](../recomp/config/output_ovl/o2/o2_00611A90_0x611a90.cpp) | `dispatch_actor_60f710_primary_three_and_tick_merged_recoil_variant_candidate` | High mechanics; candidate role | Setsruntime74F295slotbit10,uncheckedten-target70EBE0taildispatch. Interior611AE0A0motion9ifB1Fnonzero,else6+RNG16%3;A1tick1positive635640FA?614D30:614C50. Dispatcherandfirststateonecatalogrole. |
| [o2 0x611BC0](../recomp/config/output_ovl/o2/o2_00611BC0_0x611bc0.cpp) | `tick_actor_60f710_primary_three_secondary_one_recoil_with_segment_classification_candidate` | High mechanics; candidate role | A0B1Fnonzero probes150unitsyaw0,choosesmotionB,half10=1onhitelse0. B1F0probesyaw8000,motionA,half10=2onhitelse0. Probeoutputnormal/pointdiscarded;A1positiveanimationtargetpredicatechooses614D30or614C50. |
| [o2 0x611CE0](../recomp/config/output_ovl/o2/o2_00611CE0_0x611ce0.cpp) | `tick_actor_60f710_primary_three_secondary_two_health_direction_recovery_candidate` | High mechanics; candidate role | A0savesB1Fto10,motionCifzeroelseD. A1positiveendpositivehealth->(4,3)if10nonzeroelse(4,1);nonpositivehealthruntime74F294flag1->(4,4),else(4,2)if10nonzeroelse(4,0). Allthrough615570. |
| [o2 0x611E70](../recomp/config/output_ovl/o2/o2_00611E70_0x611e70.cpp) | `tick_actor_60f710_primary_three_secondary_three_ballistic_recoil_candidate` | High mechanics; candidate role | A0flightchannels,bearing634FD0fromword11C,selectmotion1B/B1FnonzeroandvelocityZ+5/yawXOR8000,else1A/Z-5;rotate,vertical12,10=0. A1flightchannels/tick1,position+=CCXYZ,gravity-3.2,surfaceYsnapclearsBA5/10=1/motion5/A2. A2positiveendpredicatechooses614D30or614C50. |
| [o2 0x612110](../recomp/config/output_ovl/o2/o2_00612110_0x612110.cpp) | `tick_actor_60f710_primary_three_secondary_four_exact_completion_recovery_candidate` | High mechanics; candidate role | EverycallC94bit1/54A4. A0motionC/DbyB1F. A1onlysignedanimationstatus1:health>0->(4,3)ifBA3==1else(4,1);nonpositive->(4,2)ifBA3==1else(4,0). Otherpositive statusesretainstate. |
| [o2 0x612220](../recomp/config/output_ovl/o2/o2_00612220_0x612220.cpp) | `tick_actor_60f710_primary_three_secondary_five_motion1d_terminal_variant_candidate` | High mechanics; candidate role | C94bit1;A0motion1D. A1positivecompletionruntime74F294slotflag==1->(4,4),else(4,2). Doesnotcheckorrestorehealth. |
| [o2 0x6122F0](../recomp/config/output_ovl/o2/o2_006122F0_0x6122f0.cpp) | `tick_actor_60f710_primary_three_secondary_six_motion1e_or1d_terminal_variant_candidate` | High mechanics; candidate role | C94bit1;A0motion1EwhenB1F0else1D. A1onlysignedstatus1:runtimeflag1->(4,4);elseBA3==1->(4,2),other->(4,0). No healthtest. |
| [o2 0x612400](../recomp/config/output_ovl/o2/o2_00612400_0x612400.cpp) | `tick_actor_60f710_primary_three_secondary_seven_ballistic_terminal_recoil_candidate` | High mechanics; candidate role | C94bit1andthreephaseflightmatches611E70throughlanding;A2positivecompletion->(3,5)through615570,insteadtargetpredicatepolicy. No separateBA51write;retainsentryflaguntilgroundclear. |
| [o2 0x612690](../recomp/config/output_ovl/o2/o2_00612690_0x612690.cpp) | `tick_actor_60f710_primary_three_secondary_eight_saved_probe_motion_exit_candidate` | High mechanics; candidate role | A0motionAifhalf10==1elseB,then58C7B0. A1onlysignedstatus1:health<=0->(4,0),positive->614CD0(1,3). No targetpointerquery. |
| [o2 0x612760](../recomp/config/output_ovl/o2/o2_00612760_0x612760.cpp) | `tail_actor_60f710_primary_three_secondary_nine_to_secondary_three_transition` | High mechanics; candidate role | Complete8B J614CD0/NOP,returnsviacallee. Transitionhelper savesBE8/9,setsprimary1/secondary3/A/B0,reseedsC/E,C361. Not return-only. |

611A90 owns only runtimeflagbit10anddispatch;itdoesnotinitializeactivebyte/colorsforeveryreaction. Thefirsttarget611AE0liesinsamecataloginterval;interiorbodywasreadalongwithdispatcherandpadding. Ten ownedtargets70EBE0..70EC07include9secondaryhandlersandtheJ614CD0adapter;noextraentrycountfor611AE0.

Secondary1initialprobeonlyrecordshitclasshalf10,motionA/B;itdoesnotusecopiednormalorpointtonudgeposition. Secondary8laterreads10==1tochooseAversusB. Bothselectorsaremechanicscandidates,notproofofanactualcollisioninaplayercapture. B1F==0/nonzerointerpretationretains [un-normalizeddirectionbyte](SYMBOLS_ACTOR_60F710_REACTION_AND_CONTROL_HELPERS.md)contract.

| Entry | Animation end admission | Result |
| --- | --- | --- |
|611AE0,611BC0|signedstatus>0|635640(FA)nonzero614D30,else614C50|
|611CE0|signedstatus>0|Health/direction/runtimeflagtableabove|
|612110|signedstatus==1|Health/BA3recoverytableabove|
|612220|signedstatus>0|Runtimeflag1->(4,4),else(4,2)|
|6122F0|signedstatus==1|Runtimeflag/BA3terminaltableabove|
|612690|signedstatus==1|Health<=0->(4,0),else(1,3)|

611E70and612400bothreadword11Ctobearinghelper634FD0withoutlocalNULLadmissionandinitiallycopyflightchannels. TheyuseB1Ftosetyawandmotion1A/1B;Zvelocity-5forB1F0,+5andhalfturnyawfornonzero,thenrotatebyyawandsetverticalvelocity12. Phase1flightchannels,tick1,position+=CCXYZ,D0+=owned-3.2,616F20surfacequeryignoringtype. Heightnot<Ysnaps,clearsBA5,10=1,selectsmotion5/A2. No bodysetsBA5=1atentry;thecorrectentryflagdependsontheupstreamreactionstate. 612400additionallysetsC94bit1everycallanditsfinalpositivecompletiontransitions(3,5),while611E70usesnormaltargetpredicatepolicy. Theyarerelatedbutarenotbyteidenticalorinterchangeable.

Allhealthtestsandsuccessstatusesarelocallypreserved;positivehealthversusnonpositivehealthdoesnotestablishanoriginaldead/incapacitatedenum. Runtime74F294slotflagusedhereisdistinctfrom74F295bit10setbythedispatcher. Fieldsnapshot/resetownersremainsharedhelpers615570and614CD0,nottheselectedmotionadapter6152A0.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Fullten-targetdispatch:

`611AE0, 611BC0, 611CE0, 611E70, 612110, 612220, 6122F0, 612400, 612690, 612760`,SHA256 `adf60c2885a8d2ef129aba753d03e7781c8bc5db32a36fe415c708557050282e`.

Complete612760..612767tailbytes`3453180800000000`,SHA256 `b2e73f03a92b5103b7fa6ea1477e4736da31dd8309a7a354f8c561b14a7b9612`. Noactualactoridentity,slowroomadmission,callfrequencyorperformancecausewasmeasured.

Owned-word audit:ten complete bodies,743 original instruction words verified,67 omitted zero/NOP words,zero conflicts and zero omitted nonzero words.Full10-targetdispatchand8Btailadapterhashed.CurrentliveIDs/actualannotations/links/diffclean; no shared index mutation.
