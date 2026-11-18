# Actor motion transition, response choice and surface incline helpers

Static File #1 US research, 2026-11-04. Sixteen complete original bodies reviewed, including the connected candidate-list selector63F7E0. Addresses/offsets/statevalues/masks hexadecimal; explicit physical quantities decimal. No execution, attachment, build, replay or engine changes. Function labels preserve observed class/state selectors without claiming recovered original names.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6AB0E0](../recomp/config/output_ovl/o2/o2_006AB0E0_0x6ab0e0.cpp) | `select_or_advance_actor_motion_with_state_sensitive_blend_and_start_frame_candidate` | High mechanics; actor role probable | a0 actor,a1 requestedmotion,a2 signed8trackmode. Same signedhalf520==fulla1 ->58C300(actor,f12=1). Changed ->f12=0,f13=decimal10*unsigned74F200, then state-specific adjustments in full table below; start frame62 forold7/new5 or56 fornew8/C37 nonzero. signedtrackmode1 ->5A86F0(actor,signed16motion,1),else5A85F0(actor,signed16motion,1). No actor/descriptor admission here. |
| [o2 0x6AB500](../recomp/config/output_ovl/o2/o2_006AB500_0x6ab500.cpp) | `select_or_advance_actor_motion_preserving_start_frame_candidate` | High mechanics; actor role probable | Same520/request ->58C300(actor,f12=1). Changed startsblend10*unsigned74F200 while preserving incomingf12;primary2/subA blend0, primary5/old5B/new5 blend10literal. signed8a2==1 uses5A86F0 track1;else5A85F0 alltracks. Request comparison occurs before signed16 conversion. |
| [o2 0x6AB600](../recomp/config/output_ovl/o2/o2_006AB600_0x6ab600.cpp) | `select_or_advance_actor_motion_with_zero_blend_and_special_start_frame_candidate` | High mechanics; actor role probable | Same520/request ->58C300(f12=1). Changed f12=0,exceptold7/new5 ->62,new8andC37nonzero ->56;f13=0. signed8a2==1 configuresone track1 via5A86F0;elsealltracks5A85F0. Parameterconstants decimal. |
| [o2 0x63F7E0](../recomp/config/output_ovl/o2/o2_0063F7E0_0x63f7e0.cpp) | `choose_random_predicate_admitted_u16_from_ffff_terminated_list_candidate` | High mechanics; actor role probable | a0 actor,a1 u16list. Tests58D320(actor,ID), acceptsiflow16returnnonzero, storingup to16 candidates. Stops atFFFF orafter16 accepted candidates; number of rejected entries has no separate cap. Empty returns0;else chooseslist[low16(1AEC80(1)) % acceptedcount]. No distribution, total source-span or callback-cost guarantee. |
| [o2 0x6AB6C0](../recomp/config/output_ovl/o2/o2_006AB6C0_0x6ab6c0.cpp) | `choose_actor_admitted_id_64_65_66_and_rebase_candidate` | High mechanics; actor role probable | Calls63F7E0 with owned7198B0=[64,65,66,FFFF]. Nonzeroresult subtract64;zero remains0. Thus zero can meanemptychoice oraccepted64; no actorstatewrites. |
| [o2 0x6AB700](../recomp/config/output_ovl/o2/o2_006AB700_0x6ab700.cpp) | `test_actor_admitted_id_6f_via_rebased_choice_candidate` | High mechanics; actor role probable | Calls63F7E0 with7198B8=[6F,FFFF]. Nonzeroresult subtract6E,so admitted6F ->1;otherwise0. Tableloaded asraw4bytes despitelwc1 instruction;it is not used asfloat arithmetic. |
| [o2 0x6AB740](../recomp/config/output_ovl/o2/o2_006AB740_0x6ab740.cpp) | `choose_actor_variant_initial_response_substate_and_aux_bits_candidate` | High mechanics; actor role probable | B1F==0 chooses7198C0=[12D,137,FFFF],nonzero7198C8=[12E,136,FFFF] through63F7E0. Nonzeroresult subtract12C. Alwaysbyte9=0,byteB=lowrebasedresult. Does notwriteprimary8,phaseAorBA3. |
| [o2 0x6AB7D0](../recomp/config/output_ovl/o2/o2_006AB7D0_0x6ab7d0.cpp) | `choose_actor_variant_response_140_141_or_idle_fallback_candidate` | High mechanics; actor role probable | B1F==0 ->7198D0=[140,FFFF],else7198D8=[141,FFFF].63F7E0 result140 ->9=4,B=0;141 ->9=4,B=1;other ->8=1,9=B=0. NophaseAreset. Ifbyte13E==0,alwaysrequestsbank1sound1B9310(actor,A,0),includingfallback. Does not proveactualplayback. |
| [o2 0x6AB890](../recomp/config/output_ovl/o2/o2_006AB890_0x6ab890.cpp) | `enter_actor_primary_three_response_from_type_and_byte140_candidate` | High mechanics; actor role probable | Initially8=3,A=B=0. Type4==6 ->9=5,return0;type9 ->9=7,return0. Otherbyte140=0 calls6AB740;oldmotion5/8/66/67 thenrandomlow16%100>=decimal21 ORsB mask10;returns0.140=1 ->9=1,return0.140=2 calls6AB7D0,BA3=1ifBnonzeroelse2,returns1evenfallbackchangedprimary. Other140 leavesold9 andreturns0. |
| [o2 0x6AB9D0](../recomp/config/output_ovl/o2/o2_006AB9D0_0x6ab9d0.cpp) | `enter_actor_primary_three_alternate_response_from_type_and_byte140_candidate` | High mechanics; actor role probable | Initially8=3,A=B=0. Type6 ->9=6,BA3=2;type9 ->9=8,BA3=1. Otherbyte1400 ->9=2,BA3=1;1 ->9=3,BA3=1;2 ->6AB7D0thenBA3=2ifB1F==0else1. Other140 leaves9/BA3 unchangedafterinitialwrites. No definedstatusreturn. |
| [o2 0x6ABAA0](../recomp/config/output_ovl/o2/o2_006ABAA0_0x6abaa0.cpp) | `enter_actor_primary_four_response_from_category_health_and_roster_candidate` | High mechanics; actor role probable | Initially8=4,A=B=0. Type6 ->9=8;type9 ->9=9. OthersBA3==1 ->9=Bifhealth544<=0and6ACB00 true,else2. BA3!=1 ->9=Aifhealth<=0andunsignedroster74F294+60*B98==1,else0. No motionselection/counterinitialization. |
| [o2 0x6ABB80](../recomp/config/output_ovl/o2/o2_006ABB80_0x6abb80.cpp) | `test_actor_descriptor_metadata_byte5_equals_one_candidate` | High mechanics; actor role probable | Returnswhether byte5 of record(word387E90+8*unsignedactor3)+10*unsignedhalfBBA equals1. No null/bounds guard; doesnotreadactor4category directly. |
| [o2 0x6ABBC0](../recomp/config/output_ovl/o2/o2_006ABBC0_0x6abbc0.cpp) | `apply_two_actor_joint_incline_response_slots_then_optional_clear_candidate` | High mechanics; actor role probable | IfsignedhalfCF8nonzero calls58C720(actor,byteD09,actorCF8);ifhalfD0Anonzero calls58C720(actor,byteD1B,actorD0A). SignedbyteD45==0thenzerosbothhalfresponsesafterapplication. Posehelperownsactualjointwrites;no animationadvance here. |
| [o2 0x6ABC30](../recomp/config/output_ovl/o2/o2_006ABC30_0x6abc30.cpp) | `sample_two_actor_joint_surface_heights_and_approach_incline_angles_candidate` | High mechanics; actor role probable | Saves20bytesactor170..183.6ABB80true choosesmodel34nodes83C/858,else844/870;positionsnode+30XYZeachY+decimal200. Queries616ED0 filter1;iftype174!=1queriesagainfilterFF. ReplacesprobeYbyreturnedactor170,thenrestoressaved20bytes.376EF0pairdirectiondependsonsigned8a1. ApproacheshalfCF8/D0AinstepsC8 withliteralasymmetricclampsbelow. Noactivity/model/nodeguard. |
| [o2 0x6ABFB0](../recomp/config/output_ovl/o2/o2_006ABFB0_0x6abfb0.cpp) | `decay_two_actor_incline_response_halves_toward_zero_by_sign_mode_candidate` | High mechanics; actor role probable | SignedbyteD45==1 addsC8toCF8/D0A,clampspostpositive0. OtherD45subtractsC8,clampspostnegative0. Eachadd/substoredhalfandreadbackbeforerangecheck,preserving16-bitwrap. Doesnotchoosebasedonactualinitialsign. |
| [o2 0x6AC040](../recomp/config/output_ovl/o2/o2_006AC040_0x6ac040.cpp) | `advance_actor_route_and_publish_randomized_interaction_transition_candidate` | High mechanics; actor role probable | Argsactor,a1node,a2interaction. Type4==1 writes6AC5C0(B98,1). Resolvesrostersequence6D45A0 andadvances6D46B0ifnonnull. Samples5FE150(stackXYZ,signed8node,signedactor1E2),discardingresultXYZ;randomlow16&7 ->5A6CB0(actor,originala2,23,variant). Finally6AA3C0(actor,7,2). No guarantee sampler/recordpublication succeeds. |

6AB0E0 changed-motion blend selection (u=unsignedbyte74F200). Values in the blend/start columns decimal; motion/state values hexadecimal. Conditions within a primary state are evaluated in this order; first matching branch exits that state's blend decision.

| Primary8 / condition | f13 blend |
| --- | --- |
| 0 | 0 |
| 1, requestedmotion in1..3 OR oldmotion in1..3 | 20*u |
| 1, requested8 | 5*u |
| 1, substate9=6 andoldmotion8/C/E | 20*u |
| 1, old8 andrequested66/67 | 15*u |
| 1, old66/67 andrequested5 | 15*u |
| 4, old36/request33 ORold37/request32 | 20literal |
| 4, other | 10literal |
| 5, savedBE8=4 andsavedBE9=A/B andold32/33 | 0 |
| 5, old57/request58 ORold58/request68 | 10literal |
| 2, old6B/request6F ORold6F/request70 ORold70/request6C | 0 |
| All other paths | Default10*u |

Then old7/request5 sets startframef12=62; otherrequested8 withC37nonzero sets56;otherwise0. One-track configuration usesliteraltrack1, notincominga2asatrackindex.5A86F0's descriptor track mapping is documented in [actor model state helpers](SYMBOLS_ACTOR_MODEL_STATE_HELPERS.md).58C300 advances animation; these helpers do not define a global game tick or speedup path.

6ABC30 keeps exact signed-pitch ordering: signed8mode0 computes P=pitch(probeA->actor),Q=pitch(actor->probeB);othermode reversesboth. CF8: P<0 subtractC8 andlower-clampP; P>0 addC8 butupper-clampQ (notP);P==0 sets0. D0A: Q<0 subtractC8/lower-clampQ;Q>0 addC8/upper-clampQ;Q==0 sets0. Halfwordwrap andquerysideeffectsoutsideactor170..183 are not undone. Original skeleton joint names and intended asymmetric clamp rationale remain unknown; no reproduced foot-placement defect is claimed.

The choice lists are owned u16 IDs andFFFF terminators, copied asinteger/rawFPloads; they are not float curves. Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Address / byte span | Exact halfwords | SHA256 |
| --- | --- | --- |
| 7198B0..7198B7 | 64,65,66,FFFF | `f66e0b24fe8b31717ac0d2c01291a9266a4ac27ded82254a645ff41e90ed0342` |
| 7198B8..7198BB | 6F,FFFF | `5a53e1409a5407f5bcd67ed7c61d72cc897fb02c8276ac631a5755e8bccb9ca4` |
| 7198C0..7198C5 | 12D,137,FFFF | `1bfa7fd4dd5814a8f7b9194c396fdd10f2278c13cce2a7200e94151b12688ecb` |
| 7198C8..7198CD | 12E,136,FFFF | `59a8c3547482048e5367e9961502287408a3a4e6aa5749b7317a1ea6b760ac10` |
| 7198D0..7198D3 | 140,FFFF | `d39b1606bca72bfe5801c8fe753668064bc910c985aff395f21029ead6ec8434` |
| 7198D8..7198DB | 141,FFFF | `182b4ee067fbdf26b617b743853b362c8acc6b2d6fcd6f2bf2381c9763f87c4e` |

63F7E0's scan cap applies to accepted candidates, not rejected source items; all six lists above have explicit owned terminators. Its delegated58D320 tail-adapts58D1C0(actor,actor51C,ID); thelowerdescriptorlookupwaslaterfullyreviewedin [contact and descriptor admission](SYMBOLS_ACTOR_CONTACT_DAMAGE_ADMISSION.md),establishingmotion-variantentryadmissionratherthanagenericcollisionpredicate. Already-reviewed route and interaction publication helpers are in [route controls](SYMBOLS_RECORD_ROUTE_CONTROLS.md), [route queries](SYMBOLS_ROUTE_GRAPH_POINT_QUERIES.md), [response records](SYMBOLS_ACTOR_RESPONSE_RECORD_EVENTS.md). The next state initializer6AA530 is documented separately in [state initialization](SYMBOLS_ACTOR_ACTION_STATE_INITIALIZATION.md).

Full-body owned-word audit: 16 rows, 988 verified instruction words, zero conflicts, 73 omitted zero/NOP words, zero omitted nonzero words.
