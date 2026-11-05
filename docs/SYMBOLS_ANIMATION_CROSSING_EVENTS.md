# Animation crossing events and actor effect adapters

Static File #1 US research, 2026-11-04. This resolves the shared helpers called
by [motion-specific event sets](SYMBOLS_SCENARIO_LOADING_TRANSITIONS.md).
Every named originalbodyandbranchdelayslotwasreviewed. No game,build,replay,
attachment,live-memory inspection or runtime codechangewasperformed. Numeric
fields/IDs/masks/stridesarehexadecimal;floatingvaluesaredecimal.

The existing [573480 crossing gate](SYMBOLS_TASK_FLAGS.md) tests a targetframe
against the current animationrange,handleswrap,andsuppresseseventsbybankflags.
It doublesstepwhen3243CC==1. This differsfromtheexact-framecutscenecommand
consumers;these adaptersdo notjustcomparefloat equality. Every frame-gatedrow
below passesoriginalincomingstepf12asgatef13,andconvertsfullsigneda0tofloat
forgatef12. That is staticargumentrouting,not a performance measurement.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x595B70](../recomp/config/output_ovl/o2/o2_00595B70_0x595b70.cpp) | `emit_actor_surface_audio_pair_on_bank_one_frame_crossing_candidate` | Probable role; full body reviewed | a0signedframe,a1actor,a2kind,f12step. Gate573480(actor,1,targetfloat,step). Nonzero1B8D70(actor,signedlow8kind),thenrandomstream1 lowbitselects1B8BB0(actor,C orD). Maskedrandom0..FFFFmakessignednegativecorrectionbranchunreachable. No soundsorRNGconsumedwhenframegatedout;audiooperationrolesinheritcallees. |
| [o2 0x595C00](../recomp/config/output_ovl/o2/o2_00595C00_0x595c00.cpp) | `emit_actor_surface_audio_pair_on_bank_zero_frame_crossing_candidate` | Probable role; full body reviewed | Individuallyreviewedsameaudio/RNGsequenceas595B70but573480bank0. Targetframefromfulla0convertedfloat,stepfromincomingf12;kindissignedlow8. Emits1B8D70then1B8BB0(C+randomlowbit)onlycrossing. No actor/model/nulladmissionlocally. |
| [o2 0x595C90](../recomp/config/output_ovl/o2/o2_00595C90_0x595c90.cpp) | `emit_actor_audio_in_randomized_range_on_frame_crossing_candidate` | Probable role; full body reviewed | Gatebank1;nonzeroa2selectsID=low16a3+(randomlow16%low16a2),then1B8BB0(actor,ID). Fulla2==0useslow16a3withoutRNG. Fullnonzeroa2withlow16zeroentersdividebyzeroinstruction;inputadmissionnotproved. No localrangeoroverflowguard. |
| [o2 0x595D30](../recomp/config/output_ovl/o2/o2_00595D30_0x595d30.cpp) | `emit_alternate_actor_audio_range_on_frame_crossing_candidate` | Probable role; full body reviewed | Samefullargumentgate/randomselectioncontractas595C90,butdestination1B8B20. Bank1crossingrequired;zero fullrange directlow16base,nonzero range narrowedlow16fordivisor. Doesnotcall1B8BB0oradvanceanimation. |
| [o2 0x595DD0](../recomp/config/output_ovl/o2/o2_00595DD0_0x595dd0.cpp) | `emit_actor_1b8c70_event_on_frame_crossing_candidate` | Probable role; full body reviewed | Gatebank1usinga0frame,a1actor,f12step;nonzero1B8C70(actor,low16a3). a2notused. No RNG,modellookuporwalltimefrequencyclaim;calleeoperationnameleftcrossref. |
| [o2 0x595E30](../recomp/config/output_ovl/o2/o2_00595E30_0x595e30.cpp) | `create_actor_effect_callback_after_resource_frame_crossing_candidate` | Probable role; full body reviewed | Bank1crossingplusactorC7Cnonzero required.573890(actor,callback5D8A70);nonnullresult halfC=20when3243CCnonzero,otherwise40. DoesnotallocatewhenC7Czero,anddoesnothalf-countbyanassumedFPS. Callbackrolecandidate. |
| [o2 0x595EB0](../recomp/config/output_ovl/o2/o2_00595EB0_0x595eb0.cpp) | `create_class_two_actor_callback_on_frame_crossing_candidate` | Probable role; full body reviewed | ActorB98must2beforebank1gate;success573890(actor,callback5D8E60). No postallocationwrites,resourceC7Cgateoraggregatedsuccessresult. |
| [o2 0x595F10](../recomp/config/output_ovl/o2/o2_00595F10_0x595f10.cpp) | `emit_model_node_audio_selected_by_kind_and_surface_table_candidate` | Probable role; full body reviewed | a0actor,a1low16kind:0baseB,1baseD,otherbase0. Surfacebyte4A1D70[actorABB]==1adds8;other valuesleavebase. Resultnonzero calls1B8A10(model34->node85C translation30,ID). Thereforeunsupportedkindstillselects8when surfacebyte1. No framegate,actoractivityorABB/nodebounds. |
| [o2 0x595FA0](../recomp/config/output_ovl/o2/o2_00595FA0_0x595fa0.cpp) | `emit_model_node_audio_selector_on_frame_crossing_candidate` | Probable role; full body reviewed | Bank1crossingthen595F10(actor,originala2). Signedfulla0frameconvertedfloat,incomingf12step;noextraadmissionorRNG. |
| [o2 0x596000](../recomp/config/output_ovl/o2/o2_00596000_0x596000.cpp) | `emit_position_audio_event_on_frame_crossing_candidate` | Probable role; full body reviewed | Bank1crossingthen1B8930(actorXYZ38,originalfulla2). DoesnotnarroweventIDorquerysurface;no independentactivity/nullcheck. |
| [o2 0x596060](../recomp/config/output_ovl/o2/o2_00596060_0x596060.cpp) | `dispatch_actor_action_effect_flag_events_on_frame_crossing_candidate` | Probable role; full body reviewed | Bank1gate;kind=low16a2.0clearsactor115bit1,5DA2C0(actor,low8a3,0).1clearsbit1,ID=unsignedbyte719A66+44*unsignedhalfCA8,5DA2C0(actor,ID,0).2clearsbit1,5823E0(actor,matrix50,XYZ38,unsignedC7C).3setsbit1withoutcall. Otherkindsno-opaftergate. Noresourceindexboundsorreturnbooleancontract. |
| [o2 0x596180](../recomp/config/output_ovl/o2/o2_00596180_0x596180.cpp) | `dispatch_seven_node_resource_effect_kinds_on_frame_crossing_candidate` | Probable role; full body reviewed | Loadsmodel34+820beforebank1gate;kindlow16a2<7table73E2B0.0optional4BAE30/category2/class1overridea3node12;uses24-byte709590 profileindexedlow16t0toformrotation/translation,composeswithmodelnode[low16a3],extractsvector1900E0;identityscale,5DCD70(0,matrix,vector,1),5DD080(actor).1BA0OR80000000,65E710(actor).2 586D80(actorXYZ).3 5E9EE0(actor,low16a3).4logicalresource[C7C].instance14nonnull58E6D0(actor,instance+1C0,CA8-1).5sameinstanceadmission;localmatrixidentity/copyactor50via191530,6525D0(localmatrix,stackA0,FF,low16a3,0,1A193,653DB0),successchild24=actor/28=instance.6onlyscenario23calls5E9AC0(actor,low16a3). No localnode/profileindexbounds;stackvectorcontentsinheritactualmatrixhelpercontract. |
| [o2 0x596470](../recomp/config/output_ovl/o2/o2_00596470_0x596470.cpp) | `dispatch_actor_6b4420_control_on_frame_crossing_candidate` | Probable role; full body reviewed | Bank1gate,kindlow16a2<6table73E2D0.0/1no-op;2calls6B4420(actor,1),3(...,2),4(...,3).5onlyBA4bit100000set calls6B4420(actor,0),thenclearsbit100000. Otherkindsreturn. No game-speedsettingchangeorfixedoperationmeaningassigned. |

Owned73E2B0 targetsfor0..6 are5961F8/596328/596380/59636C/596390/
5963D4/596348. Owned73E2D0 targetsfor0..5 are596534/596534/596500/
596514/596528/5964CC. These are internaltargets,not additionalfunctionlabels.
The scenario23kind6 route calls [5E9AC0](SYMBOLS_SURFACE_EFFECT_CONTROLLERS.md),
whichrejectsa1bit40;callerspassing41/42thereforehitthatrejection. Thisstates
actualroutingwithoutclaimingtheoriginalintentionor a missed-effectbug.

Audiohelperrolesareconstrainedbytheirconcretecalltargets;originalsoundnames,
visualeffectnamesandunreviewedcalleecategorysemanticsremainunknown. Artifact
identitiesarein [the central index](FUNCTION_INDEX.md). No runtimeoccurrence,
slowdown,fixorcontrolledretestisclaimed.
