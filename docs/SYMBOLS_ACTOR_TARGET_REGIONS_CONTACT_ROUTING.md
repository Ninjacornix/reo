# Actor home regions, target bands and contact response routing

Static File #1 US research, 2026-11-04. Six complete original bodies reviewed. Addresses/offsets/selectors/masks hexadecimal; distances and capacities explicitly decimal. No execution, attachment, build, replay or engine changes. Contact/response terminology describes connected field and state flow; exact collision callback and classification enums remain unresolved.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6A9F80](../recomp/config/output_ovl/o2/o2_006A9F80_0x6a9f80.cpp) | `choose_actor_home_radius_or_related_target_action_after_reset_candidate` | High mechanics; behavioral role probable | Saves8/9->BE8/BE9,clearsA/B.6AC200and634C80(self,related24,10000,D55,limitdecimal150)success ->6AA3C0(self,2,C),return. Else sqrtXZdistancefromsignedhalf7193E0+8*BA7 centerXZ exceeds signedradius+6 ->primary1/sub14. Inside:relatednonnull andsignedBF8+20*C25+2*C26>=FA0 ->sub6 ifBD4<=150,else13;otherwise sub0. Then6AA530and6AC640(self,0). No table-indexbound. |
| [o2 0x6AA130](../recomp/config/output_ovl/o2/o2_006AA130_0x6aa130.cpp) | `choose_actor_related_target_action_or_distance_band_state_candidate` | High mechanics; behavioral role probable | Nullrelated24returnsunchanged. Otherwise saves8/9,clearsA/B. Relation-score<FA0 ->6AA3C0(self,1,19). Else6AC200trueattempts6AC2E0andreturnsifhandled. FallbacksqrtXZrelateddistance<=decimal150 ->primary1/sub1C;else1B. Then6AA530and6AC640(self,0). Doesnotreselectrelatedpointer. |
| [o2 0x6AA250](../recomp/config/output_ovl/o2/o2_006AA250_0x6aa250.cpp) | `test_related_actor_inside_selected_inclusive_xz_rectangle_candidate` | High mechanics; behavioral role probable | a0 selectorowner,a1 actorposition. signedbyteD79<0returns1. Otherwise root719020[D79],record+8*unsignedBA7, signedhalvesxmin0,zmin2,xmax4,zmax6;returns1iffa1X/Zinsideinclusivebounds. Yunused;nopointer/indexadmission. |
| [o2 0x6AA300](../recomp/config/output_ovl/o2/o2_006AA300_0x6aa300.cpp) | `select_actor_substate_from_signed_incline_mode_candidate` | High mechanics; behavioral role probable | SignedD45==1 ->byte9=7;==-1 ->9=8;other ->9=4. No primary/phase/motion writes or guard. |
| [o2 0x6AA340](../recomp/config/output_ovl/o2/o2_006AA340_0x6aa340.cpp) | `route_actor_target_gate_to_controlled_reset_or_category_idle_candidate` | High mechanics; behavioral role probable | 6372B0(actor,byteD55)nonzero ->6A9490(actor). False ->6AA3C0(actor,1,19)forcategory4=9,else(actor,1,0). Calleecontract6372B0/6A9490remainseparate;notanunconditionalAIreset. |
| [o2 0x6AA9A0](../recomp/config/output_ovl/o2/o2_006AA9A0_0x6aa9a0.cpp) | `process_actor_contact_candidate_and_route_response_state_with_record_publication_candidate` | High mechanics; behavioral role probable | Candidate637490(self)->self11C. SelfB1E==1clearsitandcandidateclass2 in0/1 getsB1E=6. ComputesB1Ffacinghalfplaneor0null. Callback72B820[byte141],passing(self,mode11ifB9Bmask1else1). Positiveword138calls666D40(candidate). K=low8(6407D0(self,candidate,3E8));category6/9 convertsK2->0. Admissionflags/primary-specificresponse/finalactionpublicationfullytabulatedbelow. Alwaysreturns1includingearlydescriptorpath;doesnotmeannewdamageornewstatewasproduced. |

6AA9A0 full routing, after candidate callback and K classification. Let N=6AB890 (normal response, stores returned signed8 H), A=6AB9D0 (alternate response), F=6ABAA0 (primary4 response), R=5A7C40(owned718C48,selfD1C). H and auxiliary final flagJ start0. "Cancel" means: if B24nonnull, both linked actor and selfB1E=6; call667060(self). Before this table, if6ACB70(self) andbyte143mask10, previouslyclearroster74F295+60*B98 mask8 requests584880(self,3),thenalwaysORsthatrosterflag8. Savescurrent8/9->BE8/BE9 after those operations.

| Primary / substate / phase | Exact routing |
| --- | --- |
| 2,anysubstate | ORbyte115mask1 first |
| 2,sub0/1,phaseA<6 | Cancel;Knonzero A,elseN |
| 2,sub0/1,phaseA>=6,Knonzero | A |
| 2,sub0/1,phaseA>=6,K0, (CEFnonzeroand140=1)OR140=2 | N |
| 2,sub0/1,phaseA>=6,K0,other | CEF=1;R |
| 2,sub2,phaseA<4 | Cancel;Knonzero A,elseN |
| 2,sub2,phaseA>=4 | Knonzero A,elseR |
| 2,sub8,phaseA<5 | Cancel;health544=0;K=1;A |
| 2,sub8,phaseA>=5 | R andimmediatereturn1;skipallfinalpublication |
| 2,othersubstates | Knonzero A,elseN |
| 3,6AC8B0true | R |
| 3,6AC8B0false,Knonzero | A |
| 3,6AC8B0false,K0 | 6AC830true N,elseR |
| 4,6AC920true | K1 F,elseR |
| 4,6AC920false,6AC980true,Knonzero | A |
| 4,6AC920false,6AC980true,K0 | byte140=1/2 N,elseR |
| 4,bothpredicatesfalse,Knonzero | F;J=1 |
| 4,bothpredicatesfalse,K0,140=2 | F;H=1;J=1 |
| 4,bothpredicatesfalse,K0,other140 | R |
| Otherprimary,Knonzero | A |
| Otherprimary,K0 | N;category6/9additionallyR |

Common post-routing behavior (except the explicit earlyreturn):

- K=1 selects5A8140 action8 forcategory6,9 forcategory9. Othercategories:6ACB00true ->actionBifBA3=1elseA;6ACB00false ->action2ifBA3=1else0. Thenroster74F295+60*B98 isassigned1, replacingitswholebyte.
- Otherwise K=2 orHnonzero:category6forcesprimary8=3/sub9=6only. Othercategoriesassignrosterflagbyte2,setB9E=2ifBA3=1else0,andcall5A6B20(self,9).
- Finallyifcurrentprimary8=4,byteB=J. Returns1regardlesswhetheracallbackchangedstateorarecordpublicationwasadmitted.

K is reclassified0 forcategory6/9 whenraw6407D0returns2. Candidatepointer andK share the same saved register at different phases; this doesnotmean the classification byte is a pointer. The positiveword138 path calls666D40 oncandidatewithoutalocalnonnullguard. The owned callbackdispatch andtheseadmissiongapsdo notestablish a playerfault or collisionrootcause.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. At72B820..72B877,22consecutivefunctionpointerwords:slot0=635630,slots1..21=635010;followingword72B878=0.88-byte SHA256 `14b15ab10fd756d54d7f23f8515b590e2ed90f6eae5cf72ef622841766ac8ad1`. Thisphysicalspanisnotalocalbyte141<22check;neitherzero noradjacenttableinferenceisusedasadditionalfunctioncoverage. Thecallback635010wassubsequentlyfullyreviewedasan effecttransform/emissionproducerin [contact effects](SYMBOLS_ACTOR_CONTACT_EFFECT_EMISSION.md);635630isthereturn-onlyadapter.

Rectangle root719020 first8physicalpointers are718E70,718EA0,718ED0,718F00,718F30,718F60,718F90,718FC0 (32-byte SHA256 `977f070330c43657492a885cf175142353293ae0f3fd48bf8349d28be913ebb8`). This is an explicitly bounded inspectedspan,notproof ofthefullrootlength orvalidD79range. Likewise7193E0 circle records are addressed8*BA7;theirvalidselectoradmissionmustcomefrominitialization/callers. Neitherfunctionislabelledfullyadmittedforallbytevalues.

Related [action admission and frame windows](SYMBOLS_ACTOR_ACTION_ADMISSION_TURN.md), [response choice helpers](SYMBOLS_ACTOR_MOTION_RESPONSE_INCLINE.md), and[state initialization](SYMBOLS_ACTOR_ACTION_STATE_INITIALIZATION.md) supplytheclosedlocalcallees. Laterreviewresolves637490asastoredcontact-reference resolverand6407D0asdamage/authority/responseclassificationin [damage admission](SYMBOLS_ACTOR_CONTACT_DAMAGE_ADMISSION.md). Regionselectoradmissionanddelegatedlowercontractsremainopen;thecontrolroutingaloneisnotatimingmeasurement.

Full-body owned-word audit: 6 rows, 660 verified instruction words, zero conflicts, 67 omitted zero/NOP words, zero omitted nonzero words.

Authoritydispatch6A9490wassubsequentlyfullyreviewedin [response timers/authority](SYMBOLS_ACTOR_RESPONSE_TIMERS_AUTHORITY.md);6372B0assignsrelatedtarget/score/timersunderthatgatein [damage admission](SYMBOLS_ACTOR_CONTACT_DAMAGE_ADMISSION.md).635010effectcallbackclosureislinkedabove. These addcalleecontractswithoutretrospectivelyclaimingruntimeexecution.
