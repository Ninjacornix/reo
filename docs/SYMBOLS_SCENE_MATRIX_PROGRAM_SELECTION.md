# Scene matrix program selection and admission

Static File #1 US research, 2026-11-04. Nine complete original bodies reviewed.
Addresses/offsets/selectors hexadecimal; explicit countsdecimal. Original actor
interaction and object names unresolved. No execution, attachment, build or replay.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B5350](../recomp/config/output_ovl/o2/o2_006B5350_0x6b5350.cpp) | `admit_actor_scene_slot_and_choose_interaction_matrix_program_candidate` | High mechanics | a0actor,a1objectslot.5817A0(slot)lowbyteC;4B9E24+12*half3243DC bitCsetrejects. W=4A3620+60*C;categoryactor2=0 mayreplaceactiveW onlywhenactor3=selected4BADED,othersrequireW4=0. Binds5D8280(slot,W20),W6=slot,W3=W4=1;category0/1or2choosesAB9programmapsbelow,othercategoryreturnsafterbind/statewrites. Initialprogramsetupbelow. |
| [o2 0x6B5760](../recomp/config/output_ovl/o2/o2_006B5760_0x6b5760.cpp) | `choose_scene_slot_program_from_resource_type_and_room_variant_candidate` | High mechanics | a0lowbyte selectsW,5819C0(lowbyte)nonnull. R30=0takesobjectR4C/typeR60;R30=2takesR44/R58;otherkindsleaveinheriteds0/s1forlateruse. Type0W7=10,type1/3=1C,othertypeleavesW7. Bindobject/W20,W6=object,W3=W4=1,initprogram;W9=4*curvegroup+2if4B9E26+12*room bitoriginalslotset,else4*group. |
| [o2 0x6B5920](../recomp/config/output_ovl/o2/o2_006B5920_0x6b5920.cpp) | `choose_scene_program_from_resource_type_and_descriptor_first_byte_candidate` | High mechanics | Originala0unused; a1lowbyte selectsW/5819C0. R30=0takesobjectR4C,typeR60,descriptorbyte70B190+R54;2takesR44/R58 andbyte70B190+R48;otherkindinheritedregisters. Type0W7=descriptorbyte+7,1W7=9,3W7=17,othersleavesW7. Bind/initprogram,W9=4*firstcurvegroup. |
| [o2 0x6B5AB0](../recomp/config/output_ovl/o2/o2_006B5AB0_0x6b5ab0.cpp) | `choose_scene_program_c_plus_descriptor_and_resource_mode_candidate` | High mechanics | a0lowbyteW/5819C0,sameR30sourcepairsas5920andR71mode. Type0W7=C+2*R71+descriptorbyte,type1=18,type3=19,otherleavesW7. Bind/init,W9=4*group. |
| [o2 0x6B5C60](../recomp/config/output_ovl/o2/o2_006B5C60_0x6b5c60.cpp) | `choose_scene_program_1d_plus_descriptor_and_resource_mode_candidate` | High mechanics | Samefieldselection/bindingas5AB0;type0W7=1D+2*R71+descriptorbyte,type1=21,type3=22,othersleavesW7. Init,W9=4*group. |
| [o2 0x6B5E10](../recomp/config/output_ovl/o2/o2_006B5E10_0x6b5e10.cpp) | `commit_admitted_scene_program_terminal_first_segment_matrix_candidate` | High mechanics | a0lowbyte;requires4B9E24+12*room bitselectedindexsetand5819C0nonnull. Sameobject/type/descriptor/R71fields. Type0W7=12+2*R71+descriptorbyte,1=1A,2=11,3=1B,othersreturn. Bind,W6object,W3=2,W4=0,initprogram,W9=4*group,6B5050(W). No timer advancement. |
| [o2 0x6B6020](../recomp/config/output_ovl/o2/o2_006B6020_0x6b6020.cpp) | `restart_current_scene_program_curve_group_at_existing_cursor_candidate` | High mechanics | a0lowbyteW;W4=1,W9=4*byte(program721AB0[W7]+W8). DoesnotadvanceW8orresetotherfields. |
| [o2 0x6B6080](../recomp/config/output_ovl/o2/o2_006B6080_0x6b6080.cpp) | `restart_scene_slot_curve_from_direct_remap_selector_candidate` | High mechanics | a0lowbyte remapselector,a1lowbyteWslot;W4=1,W9=4*byte721950[selector]. Otherfieldsunchanged. |
| [o2 0x6B60E0](../recomp/config/output_ovl/o2/o2_006B60E0_0x6b60e0.cpp) | `request_position_sound_with_scenario_slot_byte_or_event_half_candidate` | High mechanics | Tail1B9360(originalposition,a1=(a2low16 OR byte[word730AF0[scenario3243DA]+a1low8])). ThisisbitwiseOR,notaddition;pointer/indexadmissioncaller-owned. |

W=4A3620+60*index. Commoninitialprogramsetup: P=word721AB0[W7],W8=0,
W.A=P[0]transformkind,W8++->1,W1=byte7218D0[2*P[1]],W9=4*P[1]
plusvariantasstated. Allprograms/metadata/remapsand59curvegroupsare
[ownedtableaudited](SYMBOLS_SCENE_MATRIX_PROGRAM_TABLES.md);runtimeindexbounds
are not supplied by these initializers.

6B5350 category0/1 AB9->W7 map:
`2->0,1->1,6->2,5->3,1A->4,29->16,1D->5,1E->6,20->7,1F->8,2E->23,2F->9,30->17`.
UnmatchedAB9leavespreviousW7. W9=4*firstgroup+actorB99+(actorB9B=2?2:0).
Category2map:`2->A,1->B,6->2,5->3,1A->4,29->16,1D->5,1E->6,20->7,1F->8`;
unmatchedleavespreviousW7;W9=4*firstgroupwithoutactorvariant.
The2->A/1->Bvaluesareconfirmedbranchdelayliterals,notinferredoriginalenums.

For5819C0non-nullresourcekindsotherthan0/2, selectionhelpers5760/5920/5AB0/
5C60/5E10canreadcallee-savedregistervaluesnotlocallyassignedbytheadmitted
branches. Thisisrecordedasacontractgap,notassumedinvalidruntimeassetorbug.
6B60D0isreviewedjrra/NOP,leftwithoutduplicatealiasrow.

Full-body owned-word audit: 9 rows, 830 verified instruction words,
zero conflicts, 32 omitted zero/NOP words, zero omitted nonzero words.
