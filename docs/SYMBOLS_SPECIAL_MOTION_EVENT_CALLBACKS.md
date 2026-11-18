# Specialized motion and scenario event callbacks

Static File #1 US research, 2026-11-04. This closes the contiguous callbacks
following the [large motion schedule routers](SYMBOLS_MOTION_EVENT_DISPATCH.md).
Every namedbodywasreviewed individually,includingoriginalreturn-delay slots.
No game,build,replay,attachment,live-memory inspection or runtime change was made.
IDs,frames,node/profileindexesandmasksarehexadecimal;explicitcountsaredecimal.
Allactivecallbacksacceptactor a0andanimationstepf12,anduseshared
[crossing-eventadapters](SYMBOLS_ANIMATION_CROSSING_EVENTS.md). Callback
identitiesarekeptseparateevenwhenbehaviorisidentical.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x59F610](../recomp/config/output_ovl/o2/o2_0059F610_0x59f610.cpp) | `motion3_35_node14_effect_profile1_at_frame1a_candidate` | Probable role; full body reviewed | Motion212 in3/35 calls596180(frame1A,actor,kind0,node14,profile1,incomingstep). Othersreturn. No directeffectallocationorframeequality;crossinggateiscallee. |
| [o2 0x59F660](../recomp/config/output_ovl/o2/o2_0059F660_0x59f660.cpp) | `dispatch_eighteen_paired_motion_audio_node_effect_schedules_candidate` | Probable role; full body reviewed | Motion212 has18pairedIDsseetablebelow. Uses595B70/595C90audio,596060actioneffectflagsand596180nodeeffectswithincomingstepsavedf20. Pureforwardselection,no directactor/globalwrites. Examples4/36frame0randomaudio3/4+frameAeffect7A;5/37frame8Ekind1nodeevent+90effect7A;9/3Bframe42kind0node11/profile3;1A/4Cfourkind0node5/profile4events15/25/34/45. Doesnotadvanceanimationororiginalglobalclock. |
| [o2 0x59FB50](../recomp/config/output_ovl/o2/o2_0059FB50_0x59fb50.cpp) | `dispatch_three_paired_motion_node_and_audio_schedule_variants_candidate` | Probable role; full body reviewed | Motion2/34 frame32randomaudio3/4andkind0effect7A.5/37frame4Ekind1nodeeventandeffect7A.8/3Atwo kind0nodeF/profile1events4E/78plusrandomaudio1/2sameframes. Othersreturn;allstep-basedcrossinghelpers. |
| [o2 0x59FCA0](../recomp/config/output_ovl/o2/o2_0059FCA0_0x59fca0.cpp) | `motion_event_callback_59fca0_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x59FCB0](../recomp/config/output_ovl/o2/o2_0059FCB0_0x59fcb0.cpp) | `motion12_44_node14_effect_profile1_at_frame12_candidate` | Probable role; full body reviewed | Motion21212/44calls596180(frame12,actor,0,14,1,incomingstep). Othersreturn;node/profileindexesnotvalidatedhere. |
| [o2 0x59FD00](../recomp/config/output_ovl/o2/o2_0059FD00_0x59fd00.cpp) | `motion1_4_node_a_effect_profile1_schedules_candidate` | Probable role; full body reviewed | Motion1/33frame4Ckind0nodeA/profile1;motion4/36frame80samekind/node/profile. Othersreturnwithoutwork. Incomingf12stepforwardedunchanged. |
| [o2 0x59FD80](../recomp/config/output_ovl/o2/o2_0059FD80_0x59fd80.cpp) | `dispatch_five_paired_motion_node15_and_flag_schedules_candidate` | Probable role; full body reviewed | Motion1/33frame38kind0node15/profile1;4/36frame60kind1;C/3Eframe2Ekind0node15/profile1;F/41frame50kind1;16/48frames20/88kind0node15/profile1. Calls596180only;othersreturn. Kind1writesBA0bit80000000incallee,notnode15. |
| [o2 0x59FEE0](../recomp/config/output_ovl/o2/o2_0059FEE0_0x59fee0.cpp) | `alternate_motion3_35_node14_effect_profile1_at_frame1a_candidate` | Probable role; full body reviewed | Individuallyreviewedsameargumentcontractas59F610:motion3/35,frame1A,596180kind0/node14/profile1,originalstep. Separateentry retained ratherthanaliasedbybehavioralone. |
| [o2 0x59FF30](../recomp/config/output_ovl/o2/o2_0059FF30_0x59ff30.cpp) | `dispatch_long_paired_motion_node_audio_and_effect41_schedules_candidate` | Probable role; full body reviewed | Motion1/33or2/34kind0profile1nodeB/B/A/B/A/A/Beventsframes0/A/14/28/3C/50/64.1/33also595B70kind0frames28/3C/50,kind2D8/104,and596550effect41D8.2/34kind0audio2C/44/58,kind2D4/FE,effect41D4. Othermotionsreturn. Eachhelperindependentlycrossing-gated,no callbackcountpromise. |
| [o2 0x5A0210](../recomp/config/output_ovl/o2/o2_005A0210_0x5a0210.cpp) | `motion1_2_kind2_audio_at_variant_frame_candidate` | Probable role; full body reviewed | Motion1/33frame24,2/34frame28;calls595B70(actor,kind2)withincomingstep. No nodeeffectorRNGoutsidehelper. |
| [o2 0x5A0280](../recomp/config/output_ovl/o2/o2_005A0280_0x5a0280.cpp) | `dispatch_six_paired_motion_node_audio_effect_schedules_candidate` | Probable role; full body reviewed | Motion4/36frame0randomaudio3/4andframeAeffect7A;8/3Aframe2Erandomaudio3/4andframe28effect7B;2/34frame1Akind0node10/profile1;3/35frame1AnodeC/profile1;6/38frame26nodeC/profile2;7/39frame26node10/profile2. Nodecases596180kind0. Othersreturn;no directstatewrites. |
| [o2 0x5A0420](../recomp/config/output_ovl/o2/o2_005A0420_0x5a0420.cpp) | `motion1_2_paired_kind2_audio_and_effect41_candidate` | Probable role; full body reviewed | Motion1/2frame16calls595B70(kind2)and596550;motion33/34frame18samepair. Eachhelpergetsoriginalstepindependently. Othersreturn;framesnotwalltimeduration. |
| [o2 0x5A04E0](../recomp/config/output_ovl/o2/o2_005A04E0_0x5a04e0.cpp) | `motion_event_callback_5a04e0_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A04F0](../recomp/config/output_ovl/o2/o2_005A04F0_0x5a04f0.cpp) | `dispatch_four_paired_motion_node14_and_random_audio_schedules_candidate` | Probable role; full body reviewed | Motion1/33frameAkind0node14/profile1;2/34frame3Crandomaudio3/4;6/38frame64kind1nodeevent;3/35frame42kind0node14/profile3. Othersreturn. Singlecallperselectedschedule,withframeadmissionandspawningownedbyhelper. |
| [o2 0x5A05D0](../recomp/config/output_ovl/o2/o2_005A05D0_0x5a05d0.cpp) | `dispatch_four_paired_motion_kind2_audio_schedule_sets_candidate` | Probable role; full body reviewed | Motion1/33frames106/13E;2/34framesF2/154;3/35and4/36frame16. Calls595B70kind2foreachselectedframe,originalsteprestoredbetweenmultiplecalls. No directactorwrites. |
| [o2 0x5A06F0](../recomp/config/output_ovl/o2/o2_005A06F0_0x5a06f0.cpp) | `dispatch_scenario_specific_motion_audio_callback_candidate` | Probable role; full body reviewed | Readsunsignedscenario3243DA;20explicitIDs0/1/2/4/6/A/F/10/12/13/18/1A/1C/20/22/23/25/27/28/29route5A0920..5A0B90asreviewedtablebelow. Actor a0andf12forwarded;no numericdomainfallbackwork. Onlytargets5A0930(scenario1)and5A0A30(1C)havework;other18targetsoriginalno-ops. |
| [o2 0x5A0920](../recomp/config/output_ovl/o2/o2_005A0920_0x5a0920.cpp) | `motion_event_callback_5a0920_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A0930](../recomp/config/output_ovl/o2/o2_005A0930_0x5a0930.cpp) | `scenario_one_motion640_position_audio34_at_frame60_candidate` | Probable role; full body reviewed | Unsignedmotion212must640;573480(actor,bank1,target60.0,originalstep). Success1B8930(actorXYZ,34). Othersreturn;no fixedtimeinterpretation. |
| [o2 0x5A0990](../recomp/config/output_ovl/o2/o2_005A0990_0x5a0990.cpp) | `motion_event_callback_5a0990_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A09A0](../recomp/config/output_ovl/o2/o2_005A09A0_0x5a09a0.cpp) | `motion_event_callback_5a09a0_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A09B0](../recomp/config/output_ovl/o2/o2_005A09B0_0x5a09b0.cpp) | `motion_event_callback_5a09b0_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A09C0](../recomp/config/output_ovl/o2/o2_005A09C0_0x5a09c0.cpp) | `motion_event_callback_5a09c0_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A09D0](../recomp/config/output_ovl/o2/o2_005A09D0_0x5a09d0.cpp) | `motion_event_callback_5a09d0_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A09E0](../recomp/config/output_ovl/o2/o2_005A09E0_0x5a09e0.cpp) | `motion_event_callback_5a09e0_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A09F0](../recomp/config/output_ovl/o2/o2_005A09F0_0x5a09f0.cpp) | `motion_event_callback_5a09f0_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A0A00](../recomp/config/output_ovl/o2/o2_005A0A00_0x5a0a00.cpp) | `motion_event_callback_5a0a00_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A0A10](../recomp/config/output_ovl/o2/o2_005A0A10_0x5a0a10.cpp) | `motion_event_callback_5a0a10_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A0A20](../recomp/config/output_ovl/o2/o2_005A0A20_0x5a0a20.cpp) | `motion_event_callback_5a0a20_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A0A30](../recomp/config/output_ovl/o2/o2_005A0A30_0x5a0a30.cpp) | `scenario1c_motion64a64b_kind0_audio_sequences_candidate` | Probable role; full body reviewed | Motion21264A595B70kind0frames16/27/46.64Bframes5D/7F/AC/C5/DC. Motion0andothersdo nothing. Originalstepretainedf20betweenhelpers;no globalspeedorstatewrites. |
| [o2 0x5A0B30](../recomp/config/output_ovl/o2/o2_005A0B30_0x5a0b30.cpp) | `motion_event_callback_5a0b30_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A0B40](../recomp/config/output_ovl/o2/o2_005A0B40_0x5a0b40.cpp) | `motion_event_callback_5a0b40_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A0B50](../recomp/config/output_ovl/o2/o2_005A0B50_0x5a0b50.cpp) | `motion_event_callback_5a0b50_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A0B60](../recomp/config/output_ovl/o2/o2_005A0B60_0x5a0b60.cpp) | `motion_event_callback_5a0b60_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A0B70](../recomp/config/output_ovl/o2/o2_005A0B70_0x5a0b70.cpp) | `motion_event_callback_5a0b70_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A0B80](../recomp/config/output_ovl/o2/o2_005A0B80_0x5a0b80.cpp) | `motion_event_callback_5a0b80_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |
| [o2 0x5A0B90](../recomp/config/output_ovl/o2/o2_005A0B90_0x5a0b90.cpp) | `motion_event_callback_5a0b90_no_op` | Confirmed/static mechanics | Originaljrra/nopbody.No calls,memorywritesorv0assignment;separatecallbackidentityretained. |

The eighteenpairedmotionsetsin59F660are4/36,5/37,6/38,7/39,8/3A,
9/3B,B/3D,C/3E,D/3F,10/42,11/43,12/44,13/45,14/46,15/47,
1A/4C,1E/50,20/52. Pairingdescribessharedbranchbodies,notoriginalmotionnames.

| Scenario | Callback |
| --- | --- |
| 0 | 5A0920 |
| 1 | 5A0930 |
| 2 | 5A0990 |
| 4 | 5A09A0 |
| 6 | 5A09B0 |
| A | 5A09C0 |
| F | 5A09D0 |
| 10 | 5A09E0 |
| 12 | 5A09F0 |
| 13 | 5A0A00 |
| 18 | 5A0A10 |
| 1A | 5A0A20 |
| 1C | 5A0A30 |
| 20 | 5A0B30 |
| 22 | 5A0B40 |
| 23 | 5A0B50 |
| 25 | 5A0B60 |
| 27 | 5A0B70 |
| 28 | 5A0B80 |
| 29 | 5A0B90 |

Thetwentyno-opmappingsareoriginalcodefacts,notguessedfeaturelabels. A return
withoutv0assignmentdoesnotprovefalse. Ownedartifactidentitiesarein
[the central index](FUNCTION_INDEX.md);no timingorcontrolledretestisclaimed.
