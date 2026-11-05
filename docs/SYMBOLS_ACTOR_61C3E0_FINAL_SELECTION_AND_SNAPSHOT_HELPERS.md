# Actor61C3E0 final target selection, surface bearing, and snapshot admission

Static File #1 US,2026-11-04. Sixcompletecatalogrolesclosingremaininghelpersin61C130..6250FC. High-confidence mechanics; originalsemanticenumsunknown. No execution/build/attachment/live memory/input/timing. Numericaddresses/IDs/fieldoffsetshexadecimal;explicitdistances/countsdecimal. [Root](SYMBOLS_ACTOR_61C3E0_ROOT_SURFACES_AND_SHARED_CONTROLS.md), [primary-one](SYMBOLS_ACTOR_61C3E0_PRIMARY_ONE.md), [selection/motion](SYMBOLS_ACTOR_61C3E0_MOTION_SELECTION_AND_TRACKING.md), [linkedactions](SYMBOLS_ACTOR_61C3E0_PRIMARY_TWO_LINKED_ACTIONS.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x621330](../recomp/config/output_ovl/o2/o2_00621330_0x621330.cpp) | `select_actor_61c3e0_close_target_action_by_surface_and_vertical_gap_candidate` | High mechanics; candidate role | Requires24target;targetBA0bit2000000orabsYgap>310->(1,D). ElseBA30closebearing1FFF/distance<=130->(2,0);RNG&1admitted+5A9BF0==0+bearing17FF/distance<=600->(2,1),elsefar>130->(1,5or6),near->(1,D). BA31bearingFFF/dist<=600->(2,1),elsefar/nearpolicy;BA32dist<50and5AA110->(2,2),elsebearing17FF/dist<=600->(2,1),else(1,D). Onlywrites8/9,notA/B/timers. |
| [o2 0x624B00](../recomp/config/output_ovl/o2/o2_00624B00_0x624b00.cpp) | `calculate_actor_61c3e0_point_bearing_in_selected_surface_frame_candidate` | High mechanics; candidate role | a0actor/a1point. BA30signed376E70(P,point). BA31derivesbasis5A8220(normal,owneddown),transforms(point-P),signedbearing(zero,transformed). BA32composestwo5A8220quaternions(normal,normal),(normal,ownedup),192360,thenpoint-Ptransform/bearing. OtherBA3returnswithoutlocallycomputedangle. |
| [o2 0x624D70](../recomp/config/output_ovl/o2/o2_00624D70_0x624d70.cpp) | `refresh_actor_61c3e0_surface_basis_and_commit_pose_candidate` | High mechanics; candidate role | Onlystate(1,F)copiespositionto80XYZ. Always5A82A0(D18,D00,signedBA3),then622630posecommit. No tick, state8/9changeornewcollisionquery. |
| [o2 0x624DE0](../recomp/config/output_ovl/o2/o2_00624DE0_0x624de0.cpp) | `prepare_actor_61c3e0_saved_snapshot_interpolation_when_distance_admitted_candidate` | High mechanics; candidate role | RequiresBA30,CCB0,savedprimaryCC2=1,savedsecondaryCC3<15and21target73FCE0gate. ComputesCB0=CA4XYZ-currentXYZ,CC0=savedCBEyaw-currentyaw beforedistancecheck. Acceptonly10<length<500;CCA0iflength<=200else1;return1. Reject0retainsalreadycomputedCB0/CC0whereapplicable. |
| [o2 0x624ED0](../recomp/config/output_ovl/o2/o2_00624ED0_0x624ed0.cpp) | `enter_actor_61c3e0_primary_one_snapshot_interpolation_state_candidate` | High mechanics; candidate role | Complete28B:primary1/secondary15/A/B0. Doesnotsetsaved8/9,timers,blend,ortransformvalues;callerpreparedsnapshotrequired. |
| [o2 0x624EF0](../recomp/config/output_ovl/o2/o2_00624EF0_0x624ef0.cpp) | `dispatch_actor_61c3e0_secondary_motion_sound_crossings_candidate` | High mechanics; candidate role | a0actor/f12step;unsignedmotion1F2 recognizes11keys,ordered5A9250requestsbelow,defaultreturns. Originalstepf20preserved. NoownRNGadvanceoranimationtick;variantsdrawonlyinsideadmittedcrossinghelper. |

621330shortcircuits targetflag2000000beforeverticaldistancecalculation. absYgap<=310admitssurface-specificpolicy;greaterrejectsto(1,D). BA30closebearingwindow[-1FFF,1FFF],BA31[-FFF,FFF],BA32secondary1window[-17FF,17FF];allboundsexactfromSLTItests. BA30randombranchconsumesoneRNGbefore5A9BF0;onlyiflowbitnonzeroandhelperlow8zeroareadditionalbearing/distancechecksperformed. Ifthatbranchrejectsanddistance>130,anotherRNGchooses5/6. Thesearedistinctdraws,notonedrawreusedfortwodecisions. BA3outside0..2andNULLtargetleave8/9unchanged. Itsvoid-like statecontractdoesnotpromiseanormalizedreturncode.

624B00plainbearingforBA30andmode-relativepointtransformfor1/2areseparatefrom624C80worldyaw. 624D70commits poseandconsumesextraD8/E4displacementsvia622630;itcannotbedroppedmerelybecausebasiswasalreadycomputedelsewhere. Originaldataup/downvectorsarehash-pinnedbelow;coordinateandmatrixconventionsremainthoseofmappedguesthelpers.

624DE0snapshotgateadmits savedsecondary0..Dand12..14;E/F/10/11rejectthrough73FCE0. ItcomputesCB0XYZ/CC0yawbeforethenontrivialdistancecheck;rejectingdistance<=10or>=500doesnotrestoretheoldvalues. CCAsetonlyonacceptedpath;thepairedentry624ED0doesnotvalidatetheseinputs. Theexistingsecondary15handleruses20interpolationinvocationsandthenrestoresfullsavedstate/timers;thishelperneitherappliesthatmovementnorchangesoriginalspeed.

Sound notationS(frame,event,variantCount)=5A9250(frame,actor,event,count,originalstep). [Soundgate](SYMBOLS_ANIMATION_SOUND.md)appliesprimarytrackcrossingandconditionalvariantRNG;theseareorderedrequests,notunconditionalaudioemissions.

| Motion1F2 | Ordered requests |
| --- | --- |
|6E|S(4,0,2);S(16,0,2)|
|6F|S(6,0,2);S(10,0,2)|
|C8|S(4,8,0);S(10,A,0)|
|CA|S(4E,B,4)|
|CB|S(6,2,2)|
|130,132|S(6,7,2)|
|133,136|S(0,5,2)|
|134|S(E,4,2)|
|135|S(16,4,2)|

CBa2=2comesfrombranchdelayslot624F58andiscopiedtoa3at625050,soitseventandvariantwidthareboth2. Do not infer a previoustablekey'svalue. Allhelperbodyanddelay-slotwordswereverifiedagainstownedoverlay.

| Owned span | All values | SHA256 |
| --- | --- | --- |
|73FCE0..73FD33|624E40, 624E40, 624E40, 624E40, 624E40, 624E40, 624E40, 624E40, 624E40, 624E40, 624E40, 624E40, 624E40, 624E40, 624EC0, 624EC0, 624EC0, 624EC0, 624E40, 624E40, 624E40|`ce9b606574188761f5e04e4f7419da1e6e87213f0f34e52cafd71be2786846fa`|
|70FBD0..70FBDB|0.0, 1.0, 0.0|`3695fc5961dab4c804313662c5662248a3536224fb1dd93f8fb23304c437ff0c`|
|70FBE0..70FBEB|0.0, -1.0, 0.0|`8ba4ff0e2bc29c816d60e0bb02875011798578207f6cbf661c1438c6159f1324`|

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Runtimeadmission/callfrequency,actualactoridentityandperformancerootcauseunknown. No sharedindex/sourcechangesor runtimeexecution.

Owned-word audit: six complete catalog bodies,469 original instruction words verified,31 omitted zero/NOP words,zero conflicts and zero omitted nonzero words. Fullsnapshotgate/referencevectorshashed. No sharedindexmutation.
