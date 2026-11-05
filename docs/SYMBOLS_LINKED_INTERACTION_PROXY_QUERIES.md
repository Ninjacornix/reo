# Linked interaction descriptors and collision proxy query publication

Static File #1 US research, 2026-11-04. Eleven complete original bodies reviewed. Addresses/offsets/IDs/masks hexadecimal; explicit counts/physical quantities decimal. No execution, attachment, build, replay or engine changes. Geometry/proxy naming follows connected fields/consumers; original authoring enum names and valid dynamic list contents remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5816F0](../recomp/config/output_ovl/o2/o2_005816F0_0x5816f0.cpp) | `resolve_interaction_pose_through_two_id_banks_candidate` | High mechanics; interaction role probable | Branchesonlow8a0ID<10:581250withoriginalargsincludingfulla0. Else5815F0((low8ID-10)&FF,originala1/a2/a3/t0). Calleereturnpropagates;noadditionalargumentvalidation. |
| [o2 0x581730](../recomp/config/output_ovl/o2/o2_00581730_0x581730.cpp) | `dispatch_interaction_update_mode_zero_through_five_adapter_candidate` | High mechanics; interaction role probable | Low8a0mode<6dispatchesowned73DF30:0/3nocall,1/5->580380withoriginalargs,2->580A10(originala1ID,originala2actor),4->580E70(sameadaptation). Mode>=6nocall. Doesnotnormalizereturnorclaimread-onlybehavior. |
| [o2 0x5819C0](../recomp/config/output_ovl/o2/o2_005819C0_0x5819c0.cpp) | `find_linked_interaction_proxy_kind_zero_or_two_by_id_candidate` | High mechanics; interaction role probable | Ifsignedhalf3B5150==80return0. Elsehead3B5160,next28;firstnodewithbyte30=0or2andword40==low8a0returned;none0. Doesnotrequireactivity3C/busy3Dguardsusedbyspatialquery. |
| [o2 0x581AF0](../recomp/config/output_ovl/o2/o2_00581AF0_0x581af0.cpp) | `find_linked_interaction_proxy_kind_one_by_id_candidate` | High mechanics; interaction role probable | Sameglobalhalf80disable/head/nextconvention;firstnodebyte30==1andword40==low8a0returned,else0. Noactivity/filter-room/ownercheck. |
| [o2 0x581B60](../recomp/config/output_ovl/o2/o2_00581B60_0x581b60.cpp) | `unpack_linked_interaction_proxy_endpoint_bank_and_id_candidate` | High mechanics; interaction role probable | Low8ID<10lookup5819C0,else581AF0((ID-10)&FF). Nullreturn0. Byte30kind0 ->outa1=1,outa2=lowword44,outa3=lowword48;kind1sameexceptouta3=low(word48+10);kind2 ->outa1=0andotheroutputbytesuntouched;thesevalidkindsreturn1. Otherkind0. Outputsnonnullnotguarded. |
| [o2 0x581DC0](../recomp/config/output_ovl/o2/o2_00581DC0_0x581dc0.cpp) | `classify_interaction_status_from_room_masks_and_scene_slot_state_candidate` | High mechanics; interaction role probable | Originala0low16shiftselects1<<(ID&1F). Currentroom3243DC*decimal12:half4B9E24maskhitreturns1;else4B9E20hit2;else4B9E26hit3. Otherwise5819C0(low8ID)mustnonnull;byte4A3621+60*originalLow16ID=0/1/2 ->4/5/6,other0. NoID<10guard,andlookupuseslow8whilemask/slotarithmeticuseslow16. |
| [o2 0x5DC570](../recomp/config/output_ovl/o2/o2_005DC570_0x5dc570.cpp) | `select_lowest_priority_linked_collision_proxy_at_point_and_publish_actor_candidate` | High mechanics; interaction role probable | a0XYZ,a1actor,a2queryclass,f12radius. Head3B5160,next28;requiresnode3Cnonzero/3Dzero,class31admissionandshape30testsbelow,thenheightacceptance. Chooseslowestunsignedpriority32,tiesfirst. Selectednodeword34=actor,byte3E=low8originalqueryclass,then5C1710dispatch. ActorC82andmodelslotstateareadditionalfilters;notaread-onlyprobeorBoolean-normalizedreturn. |
| [o2 0x5C1710](../recomp/config/output_ovl/o2/o2_005C1710_0x5c1710.cpp) | `dispatch_linked_collision_proxy_callback_from_type_high_bit_candidate` | High mechanics; interaction role probable | a0proxy;byte30high80clear ->70A6E0[byte30],else70A720[byte30&7F]. Callsselectedpointerwithoriginalproxyarg. Nolocalindex/nullcallbackguardoractivitycheck. Targettablesphysicallyauditedbelow;callbacksremainseparatebodies. |
| [o2 0x5C59F0](../recomp/config/output_ovl/o2/o2_005C59F0_0x5c59f0.cpp) | `admit_class_zero_actor_cross_axis_span_for_room_grid_proxy_candidate` | High mechanics; interaction role probable | a0proxy,a1actor. Nonzeroclassactor2returns1. Class0 readsinstance=proxy40,slot=unsignedinstance240, calls6B0CF0(actor,slot),returnsBoolean(nonzero). No instance-nullguard;gridspanhelperisfullymappedseparately. |
| [o2 0x5C2B00](../recomp/config/output_ovl/o2/o2_005C2B00_0x5c2b00.cpp) | `admit_collision_proxy_by_actor_class_policy_and_local_identity_candidate` | High mechanics; interaction role probable | a0proxyP,a1actor. Pbyte31==2orword6C==6 ->0. Actorclass0usesPword7Cpolicy0..6table,main1B0340/1B03C0checksandoptionalB98/3matchingword80,thenrequiresactor3==4BADED. Class1acceptsiffpolicy0. Class2acceptspolicy0/7,or8andactor3==P80. Otheractorclassesaccept1afterinitialrejects. Fullpolicytablebelow;notageometrycontainmenttest. |
| [o2 0x570260](../recomp/config/output_ovl/o2/o2_00570260_0x570260.cpp) | `select_actor_scene_matrix_program_argument_preserving_tail_adapter_candidate` | High mechanics; interaction role probable | SingleJtailto6B5350withallargumentsunchanged;delaywordzero. Targetisalready-reviewedscene matrixprogramselection. Thisisnotareturn-only/no-opentry. |

5DC570 first convertsinputpointX/Zwithguestcvt.w.s intotwointegerwords. Itwalksthemutablelinkedlistwithnolocalnode-countlimit. Eligibilityonnode31andquerylow8Q:

| Node31 | Additional admission |
| --- | --- |
| 4 | Q in0,2,4,5,6 |
| 2 | Q==2 andnodeword48==unsignedhalf(3C5630+3C*actorC82+6) |
| 6 | Q==2or6 andthatobjecthalf>=19Eand<1A2 |
| Other | Node31==Q |

Shape-node30testsaftereligibility:

| Shape30 | Local tests |
| --- | --- |
| 1 | 5C2B00(node,actor),then370960(node,intPointXZ,4)bothnonzero |
| 2 | Ifword58!=2requirebyte4A3621+60*nodeword40==0;then370960(node,intPointXZ,4) |
| 80 | 370DD0(node,intPointXZ,4,f12originalradius) |
| 81 | 5C59F0(node,actor),then370DD0sameargs/radius |
| 85 | 370960(node,guestint(actorX/Z),4),usingactorpositionratherthaninputpoint |
| Other | 370960(node,intPointXZ,4) |

Heightvaluesnodeword20/24areconvertedfromsigned32integers tofloatlo/hi. LetY=inputpointY: lo>Yacceptsifflo<=Y+decimal200;lo==Yaccepts;lo<Yacceptsiffhi>=Y. Thecodepreservesthisorderingwithoutfirstnormalizinglo/hi. Lowestunsignednodeprioritybyte32winswithstrict<replacement,tieskeepfirst. Onlyaftertheentirewalkdoesselectednode34=actorand3E=Qpublishbefore5C1710. No livecycle/failureortriggerfrequencyisclaimed.

5C2B00class0policyword7C, admittedonly0..6;afterthelistedgateallpathsrequireactorunsignedbyte3==4BADED:

| Policy | Required gate / identity |
| --- | --- |
| 0 | Noadditionalmainpredicate |
| 1 | 1B0340(actor)==1 |
| 2 | 1B0340==1 andactorB98==proxyword80 |
| 3 | 1B0340==1 andactor3==proxyword80 |
| 4 | 1B03C0(actor)==1 |
| 5 | 1B03C0==1 andactorB98==proxyword80 |
| 6 | 1B03C0==1 andactor3==proxyword80 |

Policies>=7rejectclass0withoutthefinalidentitytest. Theseareactor-policygates,notpointcontainment;5DC570performsgeometryafterward. 5819C0/581AF0listlookupdonotapplytheactive/busy/geometrytestsof5DC570.581B60kind2leavessecondaryoutputbytesunchangedonreported1;callersmustnotassumeeveryoutputiswrittenonallsuccesspaths.

Owned o2base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Table / physical span | Exact words / SHA256 |
| --- | --- |
| 73DF30..73DF47 | 581790,581760,581770,581790,581784,581760;`a2e34f20ab211a3eb2b3f07e1fd8f98fc1c550d658d3aa8f089a6e3deb5c4970` |
| 73E8D0..73E8EB | 5C2CA4,5C2B94,5C2BB0,5C2BE4,5C2C18,5C2C34,5C2C68;`772ab999dda39ccb1e2ee1fec2ac18160967bd784c26ec74b1336a2687e4a18c` |
| 70A6E0..70A71F | 5C1780,5C27D0,5C3000,5C3FE0,5C4230,5C4600,5C4940,5C4DE0,5C56E0,5C5730,5C5800,5C5810,5C5860,5C5870,0,0;`d0c688a63d090fa035c853376b2ad5553c0af1e041022b118ce72f4a90a27311` |
| 70A720..70A73F | 5931F0,5C5A30,5C5B50,5C5BD0,5C2D40,5C2F00,5C5CC0,0;`2dbd912bf865917e9779eaffef7286b32769990c045c04a5edbb99a19d5b48eb` |

Callbackphysicalspansdonotestablishthatallbyte30valuesarevalidoraddcoverageforpointedbodies. Zeroentriesremain0pointers.570260ownedbytesareJ6B5350pluszero/NOPdelay,anargument-preservingadapter: [scene matrix programselection](SYMBOLS_SCENE_MATRIX_PROGRAM_SELECTION.md)definesitsdestination.58C7B0isalreadyknownas [activate animation track banks](SYMBOLS_ANIMATION.md),ratherthanarewindorcompletionoperation.

[Interaction phase routing](SYMBOLS_ACTOR_INTERACTION_PHASE_ROUTING.md)providesdescriptorcallersandtheirpartialfailureeffects.[Room grid object interaction](SYMBOLS_ROOM_GRID_OBJECT_INTERACTION.md)fullydefines6B0CF0usedbytheclass0/shape81gate. Lower pose bank resolvers581250/5815F0 and mode handlers580380/580A10/580E70 are now fully reviewed in [interaction pose banks](SYMBOLS_INTERACTION_POSE_BANKS.md).

Owned-word audit:11 rows,603 distinct instruction words verified,80 omitted zero/NOP words,0 conflicts and0 omitted nonzero words.
