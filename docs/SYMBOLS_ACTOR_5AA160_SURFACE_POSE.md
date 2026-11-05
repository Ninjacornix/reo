# Actor family5AA160 surface, pose and reentry helpers

Static File #1 US research, 2026-11-04. Allsevenoriginalbodiesfullyreviewed,
includingearlyreturns,per-surfaceprofileupdatesandoriginalangleconversion.
No game,build,replay,attachmentorlive-memoryinspection. Numericstate/
surfacetypesremainliteralIDs; nooriginalactororroomnameisasserted. Addresses/
offsets/IDshex;floatconstantsandexplicitcountsdecimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5AE5C0](../recomp/config/output_ovl/o2/o2_005AE5C0_0x5ae5c0.cpp) | `select_initial_actor_family_descriptor_for_resume_state_candidate` | Probable role; full body reviewed | Direct5A85F0(frame0,blend0),thenactivatesbanks. Primary4sub0->descriptor2C,sub3->2F,sub6->32;otherprimary4substates32if188else2C. Nonprimary4descriptor3if188else0. Doesnotuse5AE360same-motiontickortransitionblendlogic;no statebytechanges. |
| [o2 0x5AE6E0](../recomp/config/output_ovl/o2/o2_005AE6E0_0x5ae6e0.cpp) | `query_actor_ground_and_upper_surface_then_select_collision_profile_candidate` | Probable role; full body reviewed | Skipsprimary0andprimary2withA!=0. Otherwise616F20(actorXYZ,out174,FF)->170;secondqueryXYZY+500,mask81->184/outupper. upper81 ANDground1743setsBA5/188=1;states(1,6/7),(3,3)returnearlywithoutprofilecopy. OtheradmittedcaseY=184-135,553=0,C38=81. Otherwise(upper!=81ANDground3)ORgroundFFsetsBA5=1,Y=oldD00,retaining188/553/C38. Othercases188=0,553=1,C38=0. Finaltable70EFE0[188]pointerfourfloats->C70,1AC,1BC. No surfacequerysuccessassumptionsbeyondliteralreturnedbytes. |
| [o2 0x5AE8E0](../recomp/config/output_ovl/o2/o2_005AE8E0_0x5ae8e0.cpp) | `select_actor_surface_variant_transition_from_target_geometry_candidate` | Probable role; full body reviewed | Related24required,signedBD8mustbe[-4000,4000]. ClassifytargetT=2if54F31,else1if188nonzeroAND1743,else0. Source188setwithT!=1 usesnear/fartarget-heightbranches;source188clearusesT/relativeangle/sightline/timers. Fulldecisiontablebelow. Returns1onlyafter5ADB30stateassignment,else0. No localper-framepollorrecursivecall;unknowncollision/transitionenumkeptnumeric. |
| [o2 0x5AEC60](../recomp/config/output_ovl/o2/o2_005AEC60_0x5aec60.cpp) | `set_actor_pitch_from_two_yaw_rotated_surface_height_samples_candidate` | Probable role; full body reviewed | Onlysource188clearandprimary8in3/4;otherspitch90=0. Rotateownedoffsets709D20=(0,20,-50),709D30=(0,20,50)byyaw,addactorXYZ,616F20(maskFF)each. Eitherreturnedtype>=2clearspitch. Ifneithertype1,requiresabsheightdifferencein[10,99],elseclears. Buildsratio horizontalXYZdistance/3Ddistance;zero3Ddenominatorreplacedconstant73E480,then192100(ratio),convertsangleby65536/constant73E488 withoriginal+.5/cvt.w.s,signnegativewhenfirstheight<=second. a1signedbyte1movestowardtargetbyC8withclamp;2movestoward0byC8;othersassignpitchdirectly. No healthorYassignment;groundsamplecoordinatesnotactorrootmotion. |
| [o2 0x5AF070](../recomp/config/output_ovl/o2/o2_005AF070_0x5af070.cpp) | `redirect_target_motion_when_surface_variant_changes_ahead_candidate` | Probable role; full body reviewed | Requiresactor16C. QueriesC44targetXYZY+500mask81andactorXYZ+yawrotated709D40=(0,500,200)mask81;computessignedrelativeyawtotarget. Specialscenario29/roomA/source188/C9BC->5ADB30(1,7). Otherwiseanglein[-1FFF,1FFF]:source188clearandBOTHsurfaces81->(1,6);source188setandBOTHsurfaces!=81->(1,6). Othercasesreturn;firstreturnedheightunused,onlytypebytesdrivebranches. |
| [o2 0x5AF260](../recomp/config/output_ovl/o2/o2_005AF260_0x5af260.cpp) | `prepare_short_saved_transform_reentry_delta_candidate` | Probable role; full body reviewed | RequirescachedprimaryCC2==1andcachedsubstateCC3<8;owned73E460alleighttargetsinternal5AF2A8. Calls370570(outCB0,savedXYZCA4,currentXYZ38),length191CC0,storeswrappedyawdeltaCC0=CBE-current92evenwhenrejecting. Length>=500returns0. Length<500setsCCA=0if<=200else1,returns1. NoCBCassignmentorswitchtoprimary1state8;separate5AF320adapterdoesit. |
| [o2 0x5AF320](../recomp/config/output_ovl/o2/o2_005AF320_0x5af320.cpp) | `enter_actor_family_saved_transform_interpolation_state` | Probable role; full body reviewed | Setsaction8=1,substate9=8,A/B=0. No timer/delta initialization andno calls; callerpreparation5AF260and5AB280initializercontractsrequired. |

## Complete transition admission in5AE8E0

A=source, O=relatedtarget,T=targetclassificationabove,G=unsigned74F200.
CommonnulltargetandBD8outside[-4000,4000]return0. Branchesareordered.
Alllistedassignmentscall5ADB30andreturn1;failedgatesreturn0.

| Source branch | Ordered condition | Action |
| --- | --- | --- |
| A188!=0,T!=1,BD4<200 | O.BA0bit2000000set |Return0. |
| Same | scenario29,roomA |(2,0)withoutheighttest. |
| Same | delta=O.Y-A184>50;exceptscenario29/room6 |(2,0). |
| Same | delta<50 andO.BA0bit800000clear |(2,1). Delta==50doesnottransition. |
| A188!=0,T!=1,BD4>=200 | signedhalfA10>168/G |(1,6). |
| A188==0,T==1 | BD8in[-1FFF,1FFF]and579980(A.XYZ,O.XZwithY=A.Y,20FFFF,0,out)producesoutmask848nonzero |(1,6). Thisbranchdoesnotfallthroughwhenanglefails. |
| A188==0,otherT | signedhalfA10>78/G,BD4>200,RNG(1)bit1 |(1,6). Iftheseconditionsarenotmet,followingrowmayapply. |
| A188==0,T==0 | A16C!=0,abs(O.Y-A.Y)>=50,BD8in[-1FFF,1FFF] |(1,6). |
| Remaining | Any |Return0. |

The source188set/targetT1 path returns0 through later source188 tests.
No original swimming/climbing enum is inferred from surface81. Cacheproducer
timingandquerycostremainunmeasured.

Ownedscale-pairs709CF0usedby5AE160: `(1,1),(.75,1.6666666),(1.8,1),
(1.55,1.6666666),(2.5,1),(2.5,1.6666666)`;pairvaluesaredecimalfloats.
Theseareexistingmotionscales,notnewperformance settings.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
