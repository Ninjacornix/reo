# Remote target interpolation, locomotion classification and surface orientation

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed. Numeric IDs/fields/masks hexadecimal; speed/height/weight constants decimal. Local mechanics high confidence; locomotion/orientation roles probable. No original animation enums, network receipt, runtime timing, target execution, builds or engine fixes claimed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x663C00](../recomp/config/output_ovl/o2/o2_00663C00_0x663c00.cpp) | `select_actor_numeric_locomotion_substate_from_target_delta_candidate` | High mechanics; role probable | ComputeslengthD80XYZ andbearing current38->targetD74 before early54F15/action!=1 exits. Current substate familiesCD/D0/D1,81..83,74..7C,54F16,4A..55 then general eachchoose numeric idle/turn/move IDs from D90,delta speed andyaw. Changes action1/substate,clearsA/B,savestransform onlywhenneeded; generalidle also clears54F/548bit1 andselects2050. Exact family priority,thresholds andtablesbelow. |
| [o2 0x6647F0](../recomp/config/output_ovl/o2/o2_006647F0_0x6647f0.cpp) | `interpolate_nonlocal_class_zero_actor_target_and_select_substate_candidate` | High mechanics; role probable | Requires1B0310()!=0,1B02D0()!=1,class0,actor3!=4BADED. Sticky54A4000/664D00setcontrolsdisable. Admitted action1setS ->663BB0 deltas,addXYZ/yaw,663C00 classification,thenD90decrement/snap/result codes. Unrecognizedsubstateorotheractioncan directlysnapandclear whenD90nonzero. Fullreturn/flagsemanticsbelow. |
| [o2 0x6657B0](../recomp/config/output_ovl/o2/o2_006657B0_0x6657b0.cpp) | `blend_actor_model_orientation_from_three_sampled_surface_heights_candidate` | High mechanics; role probable | Class0/1 BA0bit8 canenable548bit1 andB94=owned0.1. Without548bit1 returns1. ElseB90+=B94,clampbydirection,threeownedoffsetsrotatedbyyawandfloorheightqueried,trianglecrosscomputed. Requiresheightdifferencegatesandstorednormal-updotgate,thenmatrix191740/191900weightedblendintoA50. Failureclears548bit1/B90. Processedpathsreturn0; no GPUsubmission. |

663C00 let speed=length(A.D80XYZ),steps=unsignedhalfD90,delta=signedhalfD8E,bearing=376E70(currentXYZ,targetD74),yaw=signedhalf92,targetYaw=signedhalfD8C. Define B=((bearing-yaw+4000)&FFFF),T=((targetYaw-yaw+4000)&FFFF). After computing speed/bearing,54F==15 oraction8!=1 exits. Numeric family priority:

| Current substate / classification | Desired substate |
| --- | --- |
| CD/D0/D1 |steps0 or speed<0.5 ->CD;else377110(yaw,bearing)==1 ->D1,elseD0. |
| 81/82/83 |steps0 or speed<0.5 ->81;else same turn-sign ->83when1,82otherwise. |
| 74..7C |steps0 ->74. speed<0.5 ->74ifabs(delta)<128,else76when delta>=0 or75whennegative. Otherwise ->7AifB>=8000 andT<8000,else77. |
| Other substate with54F16 |steps0 ->98;elseB<8001 ->9B,else9E. The inclusive-boundary distinction from B<8000 is literal. |
| 4A..55 |steps0 ->4A. speed<0.5 ->4Aifabs(delta)<128,else4Cwhen delta>=0 or4Bwhennegative. 0.5<=speed<owned1.2 ->53ifB>=8000 andT<8000,else4D. speed>=1.2 or unordered ->50. |
| Other |steps0 ->generalbase0. speed<0.5 ->base0ifabs(delta)<threshold (64whenBA0bit80set,otherwise256),else2when delta>=0 or1negative. 0.5<=speed<3.5 ->9ifB>=8000,T<8000,BA0bit80clear,else3. speed>=3.5 or unordered ->6. |

377110 checks bit8000 of target-current signed16 difference,return+1whenbitclear,-1otherwise; negativehalfturntie retained. Each desired nonbase substate already current returns without clearingphases/saving. Otherwise writes action1/substate,phaseA/B0 and667370. General base0 checks whether alreadyaction1/substate0;onlychangingpaths clear54F,548bit1,setaction1/sub0/phaseA1/B0,save,select2050with(0,10),activatebanks. NoBooleanresultcontract. Thresholdspeed is delta magnitude per this invocation,notdisplayFPS,originalupdatefrequency orwall-timevelocity.

6647F0admission precedesanytargetstatewrites. If54A4000initiallyclear,664D00(actor)setS from [substate gates](SYMBOLS_ACTOR_SUBSTATE_ADMISSION_MESSAGES.md) keepsitclearwhen1,setswhen0. Initiallyset4000remainssetwithoutrecheckingS. Ifset,clearD90,D80XYZ,D8E,return0withoutsnapping. Ifclear butaction!=1 orsubstateoutsideS: D90nonzero ->snapcurrentXYZ=D74,yaw92=D8C,clearD90/deltas,return0;D900return0. AdmittedS path always663BB0,addD80XYZ/currentXYZ andD8E/yaw,call663C00 evenwhenD90zero. IfremainingD90zero aftercall return0. Otherwisedecrement D90;nonzero ->OR54A bit1,return2. New0 ->snapXYZ/yaw toexacttarget,clearD80XYZ/D8E,return1. It doesnotclear54Abit1oncompletion. Far-snap behavior inside663990 is retained; [probe/target helpers](SYMBOLS_ACTOR_PROBE_TARGET_POSTMOVE.md) giveits500-distancecontract. These codesarelocalprogressreturns,notnetworkdeliveryacks.

6657B0actorclass0/1 only:BA0bit8 and548bit1absent ->set548bit1,B94=owned0.1. Otherclassesdonotauto-enable. Anyclasswithout548bit1returns1withoutmatrixwork. ActiveweightB90+=B94;B94>0clampsabove1,nonpositiveclampsbelow0,usingoriginalorderedcomparisonswithoutNaNnormalization. PreparethreeXYZoffsets712B68/78/88,rotatebyyaw92,yaw-71C,yaw+71C respectively (low16angleconversionthroughowned2pi/65536). AddactorcurrentXYZ,query616F20(point,&localclass,FF)foreach;replacepointYwithreturnedheight,noquerysuccessclassificationgate. Compute V1=point1-point0,V2=point2-point0,191E50(outCross,V1,V2).

Requires orderedabs(height0-height2)<=80andabs(height0-height1)<=80. Then dot(actor178XYZ,ownedup712B98)<=370100(100) musthold; thiscomparisonuses**stored actor normal**,notjustcomputedcross. Failedgateclears548bit1,B90=0,returns0. Accepted:191740(outMatrix,cross,actorA8);copycurrentactor50matrix;zerotemporarytranslationXYZinbothmatrices;191900(actor50,oldMatrix,newMatrix, f12=1-B90,f13=B90),return0. No localcross-normalization/zero guard beyondcalleecontracts; nofloorchangesarewrittenbythisbody. Matrixprimitivearithmeticisretainedratherthancallingit quaternion/sphericalinterpolation. Acceptedandfailurebothreturn0,absenceofrequestedworkreturns1.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Physical span | Exact owned table / constant | SHA256 |
| --- | --- | --- |
| 740390..7403BF | 664254,664254,664254,664254,664254,664254,664254,664254,664254,664254,664254,664254 | `4fe12ca35178e65c8b2f5d5779704594377676ab435acc957208f70a022cb217` |
| 7403C0..7403E3 | 663F2C,663F2C,663F2C,663F2C,663F2C,663F2C,663F2C,663F2C,663F2C | `ddba5f7b4b41ba28c87c00a9a3e0dd2c7602d4203f824ec1e1df94ab822e36b1` |
| 740430..740433 | (0.10000000149011612,) | `fb360f7241a770dc32cade9a1d1273c92b13bd4959b1c130931312b7fe95e63f` |
| 740438..74043B | (1.2000000476837158,) | `2817a2b3ce848459dce7da01a0c7ca38abecd4441cf8da0a0b4dd8769d66da31` |
| 712B68..712B73 | (0.0, 0.0, -40.0) | `f348fb462698e289f80b0110399693bc039e624e535484223dbccf7c4d2aae1c` |
| 712B78..712B83 | (0.0, 0.0, 40.0) | `50935839eb2068f4c75216984034e4f971f4844261f272fc4bcb4ff80a426ef4` |
| 712B88..712B93 | (0.0, 0.0, 40.0) | `50935839eb2068f4c75216984034e4f971f4844261f272fc4bcb4ff80a426ef4` |
| 712B98..712BA3 | (0.0, 1.0, 0.0) | `3695fc5961dab4c804313662c5662248a3536224fb1dd93f8fb23304c437ff0c` |

All12entries740390target664254andall9entries7403C0target663F2C,buttheirphysicaltablesremainseparateowneddataandthecallerfamilieshave differentthresholds. [Original math](SYMBOLS_RENDER_MATH.md) and [collision grid](SYMBOLS_COLLISION_GRID.md) preservecalleecontracts. No repeated-callfrequency,CPUcost,player-executableoverrideuseorslowdownresponsibilityisproved.

Owned-word audit:3 rows,1209 distinct instruction words verified,172 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
