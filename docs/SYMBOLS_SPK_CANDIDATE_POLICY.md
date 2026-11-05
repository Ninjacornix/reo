# SPK candidate admission, partner selection and bounded entry scans

Static File #1 US research, 2026-11-04. Seven complete original bodies reviewed.
Addresses/offsets/typeshex; scanlimits/distancesdecimal. Candidatefieldrolesare
provisional. No runtimeprofile,slowdownreproductionorenginechanges.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B8640](../recomp/config/output_ovl/o2/o2_006B8640_0x6b8640.cpp) | `return_without_actor_spk_trigger_side_effects_candidate` | High mechanics; probable role | OriginaljrrawithNOPdelay,doesnotreadarguments,mutatememoryorassignv0. Callswithmode1/2mustnotbeinterpretedasactualhelperwork. |
| [o2 0x6B8650](../recomp/config/output_ovl/o2/o2_006B8650_0x6b8650.cpp) | `select_first_admitted_spk_pending_category_and_publish_actor_trigger_candidate` | High mechanics; probable role | Scans5categories74E784+4*i,positivevalueonly;actorresolvesbank0andbank1atvalue-1,common8skipscategory3. Optionalbank1requireshalfA<94E0(actor). Requiresbank0nonnull. NegativeDC7peerBA0bit20rejects. Recordtype4skipstoaccept;otherstypebyte3=0invalidateshalf0=-1;typebyte3=1andcategory!=1updatesrecord2Cbitmaskandmayinvalidatewhenallotheractiveactorsacknowledged. Category3calls92E0. FirstacceptDB4=pendingvalue,pending0,DC0/DA8=1,DBE0,return1;none0. Detailedmaskfieldsemanticsunresolved. |
| [o2 0x6B88E0](../recomp/config/output_ovl/o2/o2_006B88E0_0x6b88e0.cpp) | `select_nearby_spk_partner_or_retain_existing_partner_within_300_candidate` | High mechanics; probable role | Collectsactivebyte0/1actorsfromfirst8rosterentriesand3B59F0linkedlistintostackpointerlist;noexplicitcapacityguard. Excludesownbyte3onlyforcandidatebyte2=0;requiresmatching1E2,abs16headingdelta<6000hex,665DC0distance<100decimalstrictclosest. RetainexistingDC5partnerwhenmatchanddistance<300. OtherwiseDC5=0,DC2=chosenB98orBB4,DC7=FFFFforrosterorownbyte3forlinked;nochoicewritesDC2=FFFFandDC7=FFthroughmaskedunsignedpath. Ownbyte2nonzerofinallyDC2/DC7=-1. No livepartnergeometryobserved. |
| [o2 0x6B8BF0](../recomp/config/output_ovl/o2/o2_006B8BF0_0x6b8bf0.cpp) | `try_spk_linked_response_against_active_or_selected_counterpart_candidate` | High mechanics; probable role | Ownbyte2=0:actor3selectedpassesword74E774to8CC0,elsepassesselectedactorpointer. Ownbyte2nonzero:firstword74E778then74E774. Returns1onfirstnonzero8CC0,else0. No nullpointerdereferenceherebecause8CC0guards. |
| [o2 0x6B8CC0](../recomp/config/output_ovl/o2/o2_006B8CC0_0x6b8cc0.cpp) | `evaluate_four_spk_followup_records_for_admitted_partner_candidate` | High mechanics; probable role | a0actor,a1partner;requiresnonnullactivepartner,differentbyte3,targetadmissionfrompartnerDC2/DC7andownB98/BB4. RequirespartnerDB4;resolvespartnerbank1accordingtoactor/commoncombinations,common-commonreturns0. FourhalfindicesC..12nonzero->ownbank0,recordhalf0>=0,typebyte2==4,pending4zero->9330. Pending4nonzerozerosothersevenpendingwords,mode1clearspartnerDB4;calls8650,ownDC0nonzerochanged2,returnsDC0. Usespartnerselectioncontracts,no proximitytesthere. |
| [o2 0x6B8F60](../recomp/config/output_ovl/o2/o2_006B8F60_0x6b8f60.cpp) | `scan_actor_spk_type_six_candidates_and_publish_pending_trigger_candidate` | High mechanics; probable role | Loops5000decimalindices,no null-entrybreak;ownbyte2nonzeroonlyskipseachiteration. Actorbank0recordhalf0>=0,typebyte2==6 ->bank1indexrecordhalf0;optionalbank1halfA<94E0required,9330. Firstpending6nonzeroDB4=value,pending6zero,DC0/DA8=1,DBE0,break. ReturnboolDA9nonzeroonly;successfulpendingtriggerwithDA9zeroalsoreturns0. No frequency/durationevidence. |
| [o2 0x6B90A0](../recomp/config/output_ovl/o2/o2_006B90A0_0x6b90a0.cpp) | `scan_selected_actor_spk_type_three_records_and_choose_history_key_candidate` | High mechanics; probable role | Sets74E7A4=-1;loopsall5000indices,selectedB98bank0,recordnonnull,half0>=0,typebyte2=3->9330(selected,record). Pending3nonzero->91A0(pendingkey). Doesnotbreakonmissingrecordsorafterhistoryselection;no recordcountfieldused. |

8650acknowledgementlogicforrecordbyte3=1andcategory!=1:whenDC7<0andDC2>=0,
record2C|=1<<DC2. Builds8-rosteractivebyte0maskexcludingselectedbyte3,
removesbitselectedindex,comparesfullrecord2Cexactlywithmask;equalorinitial
mask0setsrecordhalf0=-1. Thefirstadmittedpendingcategoryisstillconsumedafter
thatwrite. No originalconversation/completionenumassigned.

8CC0partneradmission:bothpartnerDC2andDC7negativeacceptunrestricted;
ownbyte2=0requirespartnerDC7<0andpartnerDC2==ownB98;ownbyte2nonzero
requirespartnerDC7>=0andpartnerDC2==ownBB4. Partnerbyte3==own3rejectsfirst.

8F60initialreturnaccumulator0isnotsetbyitsacceptedcandidatebranch;finalDA9
alonechangesreturn1. ThisdifferencefromDC0/DA8sideeffectswasverifiedthrough
branchtargets,notrewrittenasconventionalbooleanreturn.

The5000scanlimitsarestaticboundsandbothnullrecordloopscontinue. No proof
ofhotfrequency,expensivecalleeorplayerincidentcausation. Related
[dispatch](SYMBOLS_SPK_SEQUENCE_CONSTRUCTION_AND_DISPATCH.md),
[score/historyhelpers](SYMBOLS_SPK_CONDITION_AND_HISTORY.md).
