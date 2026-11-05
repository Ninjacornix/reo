# Actor interaction probes, target deltas and post-movement publication

Static File #1 US research, 2026-11-04. Eleven complete original bodies reviewed. Hexadecimal fields, masks and IDs; float distances/radii50/46/60/500 decimal. Confidence high in mechanics, probable gameplay role candidates. No execution, attachment, build, live memory or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x663170](../recomp/config/output_ovl/o2/o2_00663170_0x663170.cpp) | `publish_actor_category_model_variant_and_pose_dirty_bytes` | High mechanics; role probable | A.B98=low8a1,A54D=low8a2,BBC=0,553=1. Return delay slot performs553store. No validation, allocation, model reload or Boolean result. |
| [o2 0x663190](../recomp/config/output_ovl/o2/o2_00663190_0x663190.cpp) | `query_and_dispatch_actor_nearby_interaction_proxy_by_probe_mode_candidate` | High mechanics; role probable | a0 actor,a1 low8mode,a2 queryclass. Mode0 point=currentXYZ,radius50 ->5DC570(point,A,originala2). Mode1 point=current+forward*(46+A1B4),radius50,querya2. Mode2 point+forward46 ->5DCA90(point,A,A.byteCB0),not5DC570. Mode3 point+forwardA1B4,radius60,querya2. Othermodesnoquery. Trig3700C0/370100 of signed yaw92. Query can publish proxy owner and dispatch callback; not read-only. |
| [o2 0x663350](../recomp/config/output_ovl/o2/o2_00663350_0x663350.cpp) | `resolve_actor_pool_pointer_from_class_and_identity_unchecked_candidate` | High mechanics; role probable | Low8class0 ->4A5C30+10E0*low8ID;class1 ->417090+1170*low8ID;class2 ->42EB00+D90*byte(74F251+60*low8ID). Others0. No active, pool bound or class2 mapping validity checks; runtime mapping74F251 is beyond owned file. |
| [o2 0x663990](../recomp/config/output_ovl/o2/o2_00663990_0x663990.cpp) | `compute_actor_target_xyz_delta_per_unsigned_step_with_far_snap_candidate` | High mechanics; role probable | a0 actor,a1 targetXYZ,a2 outDelta,a3 unsignedsteps. steps0 writes deltaXYZ0 without moving actor. Else difference=target-current, sqrt sum squares via371880; when distance<=500 false (includingNaN),copies targetXYZintoactor38 andzerosdifference. Divides each remainingdifference byfloat(uint32steps),writesoutDelta. Can teleport actor; not pure delta math. |
| [o2 0x663B70](../recomp/config/output_ovl/o2/o2_00663B70_0x663b70.cpp) | `compute_actor_signed_yaw_delta_per_step_adapter` | High mechanics; role probable | a0actor,a1targethalfptr,a2outhalf,a3divisor. Fulla3zero ->out0. Else377140(signedA92,signedtarget,fulla3),storeslowhalf. Callee narrows divisor signed16; fulla3nonzero withlow16zero has no local guard. |
| [o2 0x663BB0](../recomp/config/output_ovl/o2/o2_00663BB0_0x663bb0.cpp) | `refresh_actor_d90_target_position_and_yaw_deltas` | High mechanics; role probable | Calls663990(A,A.D74XYZ,A.D80XYZ, unsignedhalfD90),then663B70(A,&D8C,&D8E,unsignedhalfD90). May mutatecurrentXYZthroughfar snap. ReadsD90 again afterfirstcall;no decrement or timer advancement here. |
| [o2 0x6647B0](../recomp/config/output_ovl/o2/o2_006647B0_0x6647b0.cpp) | `set_actor_d90_target_xyz_and_clear_delta_fields` | High mechanics; role probable | D90=1 iff fulla2==0,elselow16a2;D74XYZ=a1XYZ,D80/84/88=0,D8E=0. Does not initialize targetyawD8C. Fulla2=10000 hexadecimal storesD90zero,not1. |
| [o2 0x6655F0](../recomp/config/output_ovl/o2/o2_006655F0_0x6655f0.cpp) | `tick_actor_ce8_highbyte_direction_from_ba4_priority_adapter` | High mechanics; role probable | BA4 bit4000 ->665640(A) andexit;elsebit8000 ->665690(A);else no call. Bothbits gives increasehelperpriority. Existing callees defineCE8highbyteincrement/decrement;no data-rate normalization. |
| [o2 0x665780](../recomp/config/output_ovl/o2/o2_00665780_0x665780.cpp) | `get_actor_primary_or_fallback_related_identity_byte` | High mechanics; role probable | IfA.byte14A!=FF returnunsigned14B,elseunsigned149. Does not resolve actorpool, checkfallback148class, or filteridentityFF. |
| [o2 0x663420](../recomp/config/output_ovl/o2/o2_00663420_0x663420.cpp) | `emit_actor_contact_effect_from_random_model_node_and_related_actor_candidate` | High mechanics; role probable | A141==A delegates5E0280(A),return. Else RNG1AEC80(1)&3selects2-byte(node,signedoffset)pairat71B940+8*A13E+2*index;copiesnode modelmatrix64bytes,extractsXYZ. Resolvesrelated actorprimary14A/B iff14B!=FF,elsefallback148/149 through663350;missingreturns. Normalized direction target-current is passed asthree1902D0arguments,not assumed a proper look-at. Offset(0,0,signedtablebyte) rotated,addedtonodeXYZ;effecttype/owner routingbelow. |
| [o2 0x6636D0](../recomp/config/output_ovl/o2/o2_006636D0_0x6636d0.cpp) | `update_actor_collision_height_contact_and_publish_motion_displacement_candidate` | High mechanics; role probable | Requiresactive signedbyte0 and(roommatches3243DC unlesssigned4BADF8nonzero). Calls5DA420(A),optionally measuresCF4XYZdisplacement, updatesheight170/currentY/surface176, may adjustpositionthrough57C0B0. Fullflags/surfacebranchesbelow;callees remain numeric where unreviewed, no generic rendererrole. |

663190 delegates point query5DC570 already mapped in [linked proxy queries](SYMBOLS_LINKED_INTERACTION_PROXY_QUERIES.md). That callee mutates selected proxy34/3E and dispatches a callback. Mode2 has a separate5DCA90 path; no common radius or queryclass inferred there. [Grid callback](SYMBOLS_COLLISION_PROXY_CONTACT_CALLBACKS.md) consumes CB0.663350 class2 indirection uses byte74F251+60*ID, whereas637490 independently scans active class2 actors by stored ID; these are distinct lookup contracts.

663420 effect routing after related-target resolution and point construction:

| Related actor class / A141 | Call |
| --- | --- |
| Related class0,types3/9 |5DCD70(owner0,matrix,position,type3). |
| Related class0,type1 |5DCD70(owner0,matrix,position,type1). |
| Related class0,type6 |5DCD70(ownerA,matrix,position,type6). |
| Related class0,other |No call. |
| Other related classes,type0 |No call. |
| Other related classes,nonzero type |5DCD70(ownerA,matrix,position,A141);type1 additionally5DF8F0(A,position). |

Selected-node matrix orientation is replaced byidentity then1902D0(normalized direction XYZ),so numerical convention retained without claiming direction-to-basis conversion. Normalization has no localzero-distanceguard. Original modelnode/attack-category table indices are unbounded locally.5DCD70 is [contact effect emission](SYMBOLS_ACTOR_CONTACT_EFFECT_EMISSION.md),not a collision search.

6636D0:when54A bit1clear,bookmark currentXYZ inCF4/CF8/CFC,ifBA0bit80then190=41FFFF,call5DA420(A),thenreplacebookmarkbyactualXYZdifference. When54A bit1set stillcalls5DA420 withoutbookmarkupdates. If54A bit2clear,54F14 usesmodelmatrix pointer(model34->828)+30 for616F60(point,&A175,FF) and574680(point)->half176;the floatheightreturnisnotstoredhere. Other54Fvalues useactor174surface:

| Surface174 | Height170 update |
| --- | --- |
| 3 |desired=A184-160.0;BA4bit80 ->desired immediately,elsecurrentY+(desired-currentY)/2. |
| 2 |BA4bit80 retains existing170 through arithmetic currentY+(170-currentY);else170=currentY+(old170-currentY)/2. |
| 1 orother |Retain170. |

Then ifD90==0 or54A bit4000set copy170tocurrentY;574680(actorXYZ)->half176. If54Abit2setskiptheseheight/surfaceupdates. Independentlysurface1742/3 clears553;other surfaces retainit. Finalpositioncorrection57C0B0(actor38,actor44,outXYZ) runs only54Abit2clear and(eitherbit1clear orBA0bit4000set);copiesoutXYZintocurrentpositionwithouttestingreturn. This is o2:57C0B0,not unrelatedsame-addresso3workconstructor. No claimthat5DA420/57C0B0arefullyclosedinthisnotebook.

663980isJRra+zero/NOPdelay,plainno-opcross-referenceequivalenttoreviewed573590ratherthannewsemanticrow.6647B0initializesD90butneitherD8C norallfuturecalleradmission;663B70'ssigned16divisioncontractis [overlay math](SYMBOLS_OVERLAY_MATH.md). Thefar-snapthreshold500includesNaNthroughorderedcomparisonfalse,andsameoutputalias/partialoverlapbehaviorisnotgeneralized.

Owned o2base570000SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:the8-bytecategory0node/offsetrow71B940..71B947 (four2-bytepairs) is audited below. It is one physicalconsumed row,notcompleteauthoredattackcategorycount. Runtime74F251mappingisoutsidefileend743100andisnotdecoded. No liveinputdistribution, collisioncost, visualeffectname orslowdowncausalityisclaimed.

Category0 row byteshex:15 08 15 08 14 08 14 08,SHA256 `ae91f1ac79d7b656cbb92f702e83455102f4256f03a1a9a96c64b041bb02510d`.

Owned-word audit:11 rows,659 distinct instruction words verified,44 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
