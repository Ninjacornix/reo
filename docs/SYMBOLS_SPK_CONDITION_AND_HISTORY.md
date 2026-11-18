# SPK conditions, active actor queries and usage history

Static File #1 US research, 2026-11-04. Nine complete original bodies reviewed.
Addresses/offsets/typeshex; countsdecimal. OriginalSPKconditionenumsunknown.
Noexecution,networkactivity,profilingorfixes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B8500](../recomp/config/output_ovl/o2/o2_006B8500_0x6b8500.cpp) | `find_active_spk_speaker_by_partner_kind_id_and_bank_mask_candidate` | High mechanics; probable role | a0kind,a1id,a2mask. Bit1triesactiveactorword74E778first;bit2tries74E774. Requiresnonnull,((signedDC7<0)?0:1)==kind,signedDC2==id,returnsmatchingactorpointer;else0. Kindismatchedexactly,nolowbytenarrowinghere. |
| [o2 0x6B85A0](../recomp/config/output_ovl/o2/o2_006B85A0_0x6b85a0.cpp) | `test_either_active_spk_actor_id_in_requested_identity_domain_candidate` | High mechanics; probable role | Both74E778then74E774nonnullactors. a0=0matchesunsignedB98toa1;nonzeroa0matchesunsignedhalfBB4toa1. Returns1firstmatchelse0. Noactivity/roomtestbeyondpointerpresence. |
| [o2 0x6B91A0](../recomp/config/output_ovl/o2/o2_006B91A0_0x6b91a0.cpp) | `choose_spk_history_key_by_lowest_use_count_then_lowest_key_candidate` | High mechanics; probable role | a0candidatekey;currentword74E7A4negative->9250(candidate),setskeyunconditionally. Otherwise9250(current),9250(candidate);bothnonnullcomparessignedhalf2usecounts,lowercandidatewins;equaluseslowercandidatehalf0. 9250mayallocatehistoryentry;notpurequery. |
| [o2 0x6B9250](../recomp/config/output_ovl/o2/o2_006B9250_0x6b9250.cpp) | `find_or_claim_first_free_spk_history_halfword_pair_candidate` | High mechanics; probable role | Scans1000decimal4-byterecords74CD10. Exact signedhalf0==originala0winsimmediately;otherwise remembersfirstnegativehalf0whilerestscancontinues. Nonnullresultwriteslowhalfa0tohalf0;half2notinitializedhere. Returnspointeror0. No keynarrowingbeforecomparison. |
| [o2 0x6B92C0](../recomp/config/output_ovl/o2/o2_006B92C0_0x6b92c0.cpp) | `copy_selected_spk_history_key_into_pending_category_three_candidate` | High mechanics; probable role | Copiesword74E7A4to74E790(pendingcategory3). No returnassignmentorvalidation. |
| [o2 0x6B92E0](../recomp/config/output_ovl/o2/o2_006B92E0_0x6b92e0.cpp) | `increment_selected_spk_history_counter_with_original_upper_threshold_candidate` | High mechanics; probable role | 9250(word74E790);nonnullpreincrementssignedhalf2,post>=2710sets270F. Signed16overflowbehaviorretained;notgeneralnonnegativeclamp. No pointerclearornewallocationbounds. |
| [o2 0x6B9330](../recomp/config/output_ovl/o2/o2_006B9330_0x6b9330.cpp) | `evaluate_four_spk_record_conditions_and_publish_category_candidate_key_candidate` | High mechanics; probable role | a0actor,a1record. Calls5F71F0(record4+8*i,actor),i0..3,storesbyte28+i. Starts signed28,then3operatorsbyte24+i:zeroANDnextresult29+i,positiveORnext,negativeignore. Resolvesbank1recordindexsignedhalf0byactorB98orcommon8. Optionalmetadatahalf8nonzeroorhalfA>=94E0zeroesaggregate. Recordbyte3=2andDC7<0/DC2>=0andrecord2CbitDC2setalsozeroes. Pending74E784+4*signedtypebyte2=aggregate?half0+1:0. No categoryboundscheckororiginalconditionnames. |
| [o2 0x6B94E0](../recomp/config/output_ovl/o2/o2_006B94E0_0x6b94e0.cpp) | `read_selected_active_spk_metadata_priority_or_default_99_candidate` | High mechanics; probable role | Ownbyte2nonzero,actor3notselected,activeidhalf74E76Azero,ormissingbank1record->63hex99decimal. OtherwiseselectedactorB98,bank1index74E76A-1,returnrecordhalfA. No directactorwritesorconditionevaluation. |
| [o2 0x6BA230](../recomp/config/output_ovl/o2/o2_006BA230_0x6ba230.cpp) | `set_or_clear_auxiliary_spk_bit_from_boolean_argument_candidate` | High mechanics; probable role | a1nonzero->7480(a0)setbit;zero->74D0(a0)clearbit. Originala0preserved,nonzeroisnotrestrictedto1. Nopriority/waitlogic. |

Pendingcategorywordsbegin74E784;category3=74E790,4=74E794,6=74E79C.
Historyrecords74CD10havekeyhalf0/usehalf2;resetinitializes(-1,0)in
[workpoolhelpers](SYMBOLS_SCENE_AUXILIARY_WORK_POOLS.md). 9250claimdoesnot
clearstaleusecount;thatdoesnotproveimproperreusewithoutcallerlifecycle.

9330calls5F71F0withfour8-byteconditionrecords;theconditioninterpreteris
aseparatedependency. Signedoperator/typebytesandordinarybitwiseAND/ORare
retained,notconvertedtoarbitraryoriginalenums. No runtimeeligibilityfrequency.
Related[dispatch](SYMBOLS_SPK_SEQUENCE_CONSTRUCTION_AND_DISPATCH.md)and
[candidatepolicy](SYMBOLS_SPK_CANDIDATE_POLICY.md).
