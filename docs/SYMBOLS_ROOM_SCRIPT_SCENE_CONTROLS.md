# Room-script scene activation and parameter controls

Static File #1 US research, 2026-11-04. Sixteen complete original bodies
reviewed. Addresses/offsets hex unless marked decimal. Original scene category
enums are unknown; names preserve numeric predicates and concrete writes.
No execution, attachment, build or engine changes.

Common contract for live-plus-stored operations: live mutation happens only
when context75A4C0==0; signed3B5150==80 returns0 before stored mutation.
Otherwise scan linked3B5160 through28. Contextnonzero skips live scan and
still updates stored room records. Stored base=[83E5EC+A4*75A4B8],
count=[83E550+A4*room+98],stride10; no ID,room or cyclic-list bounds guard.
Rows note operations with different admission. All entries return0.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x701130](../recomp/config/output_ovl/o2/o2_00701130_0x701130.cpp) | `script_op_52_enable_scene_subtypes_zero_or_two_candidate` | High mechanics; role tentative | Payloadword0ID,half4value. Livectx0:category3subtypeword44in0/2andword40ID ->byte3C=1,subtype2alsohalf58=value;category4word64==0andword40IDalso3C1. Storedrecords:kindbyte1=3,IDbyte2,subtypebyte3in0/2 ->activebyte0=1. No storedhalf58 equivalentwrite. |
| [o2 0x7012C0](../recomp/config/output_ovl/o2/o2_007012C0_0x7012c0.cpp) | `script_op_53_disable_scene_subtypes_zero_or_two_candidate` | High mechanics | Same livecategory3subtypes0/2 andcategory4mode64==0matchingas1130,writebyte3C0. Storedkind3IDandsubtype0/2 ->active0. Payloadonlyword0IDused. |
| [o2 0x701430](../recomp/config/output_ovl/o2/o2_00701430_0x701430.cpp) | `script_op_54_set_live_scene_mode_and_byte_72_candidate` | High mechanics | Payloadwords0ID/4mode,byte8value. Livecategory0word40ID ->word6Cmode,byte72value. Storedactivekind0,byte2ID ->half4mode. Storedrecordsdo not receivebyte72value. Returns0. |
| [o2 0x701550](../recomp/config/output_ovl/o2/o2_00701550_0x701550.cpp) | `script_op_58_enable_scene_subtypes_one_or_three_candidate` | High mechanics | Payloadword0ID,half4value. Livecategory3word44in1/3 andword40ID->3C1;subtype3half58=value. Livecategory4modeword64==1/word40ID->3C1. Storedkind3,ID,subtype1/3->active1. Distinctadmissionfrom1130. |
| [o2 0x7016D0](../recomp/config/output_ovl/o2/o2_007016D0_0x7016d0.cpp) | `script_op_59_disable_scene_subtypes_one_or_three_candidate` | High mechanics | Same subtype1/3andcategory4mode1matchingas1550,write3C0;storedkind3IDsubtype1/3active0. Nohalf58write. |
| [o2 0x701840](../recomp/config/output_ovl/o2/o2_00701840_0x701840.cpp) | `script_op_5a_set_room_variant_byte_and_rebind_navigation_candidate` | High call contract; probable role | Payloadword0byteoffset,word4value;writeslowbytevalueat4B9D20+offset,then815E70(2),witha1stillinheritingvalue. Returns0. Nooffsetrangeguard;related815E70mode2suppressesroom-scriptcalls. |
| [o2 0x701880](../recomp/config/output_ovl/o2/o2_00701880_0x701880.cpp) | `script_op_5b_enable_category_one_scene_records_candidate` | High mechanics | Payloadword0ID. Livecategory1word40ID->3C1;storedkind1byte2ID->active1. Scansallmatches,doesnotstopfirst. |
| [o2 0x701990](../recomp/config/output_ovl/o2/o2_00701990_0x701990.cpp) | `script_op_5c_disable_category_one_scene_records_candidate` | High mechanics | Samecategory1/IDmatchingas1880,live3C0,storedactive0. |
| [o2 0x701AA0](../recomp/config/output_ovl/o2/o2_00701AA0_0x701aa0.cpp) | `script_op_5d_enable_category_zero_or_two_scene_records_candidate` | High mechanics | Payloadword0ID. Livecategories0/2word40ID->3C1. Storedkind0/2byte2ID->active1,withoutrequiringprioractive. No secondaryIDfilterforcategory2. |
| [o2 0x701BE0](../recomp/config/output_ovl/o2/o2_00701BE0_0x701be0.cpp) | `script_op_5e_disable_category_zero_or_two_scene_records_candidate` | High mechanics | Samecategory0/2andIDmatchingas1AA0,live3C0,storedactive0. Doesnotdeleteorunlinkrecords. |
| [o2 0x701EF0](../recomp/config/output_ovl/o2/o2_00701EF0_0x701ef0.cpp) | `script_op_f0_clear_room_mask_byte_and_live_mask_candidate` | High mechanics | Payloadword0index. Context0calls5DCB60(index);allordinarypathsreadroompointer83E5F0+A4*roomandclearbyte[index]. NoIDboundscheck;notanactor-stateclear. |
| [o2 0x701F60](../recomp/config/output_ovl/o2/o2_00701F60_0x701f60.cpp) | `script_op_f1_set_room_mask_byte_and_live_mask_candidate` | High mechanics | Payloadword0index. Context0calls5DCB90(index);allpathsroompointer83E5F0+A4*room,byte[index]=1. Separatefromcontextflagbanks7009A0. |
| [o2 0x701FD0](../recomp/config/output_ovl/o2/o2_00701FD0_0x701fd0.cpp) | `script_op_f3_set_scene_half_66_for_category_zero_or_pair_two_candidate` | High mechanics | Contextnonzeroreturns0.581A50(payloadword0low8,0)lookup;nullreturns0. Category0storespayloadhalf4at66. Category2stores66then581A50(ID,1)andstores66againwithoutnullcheckonthesecondlookup. Othercategoriesnosideeffect. No persistentroomdescriptorupdate. |
| [o2 0x702060](../recomp/config/output_ovl/o2/o2_00702060_0x702060.cpp) | `script_op_f6_activate_category_d_scene_record_with_parameter_candidate` | High mechanics | Contextnonzeroreturns0;livecount80returns0. ScanscategoryDwithword44==payloadword0ID,sets3C1,half62=payloadsignedhalf4. Allmatches;no storedrecordpass. |
| [o2 0x7020E0](../recomp/config/output_ovl/o2/o2_007020E0_0x7020e0.cpp) | `script_op_104_enable_matching_scene_category_and_id_records_candidate` | High mechanics; generic helper | Payloadwords0category,4ID,8secondary. Livefirstrequiresrecord30==category;admitted0/1/Bcompareword40,2compares40and50==secondary,3compares40and(word44&1)==secondary,4/Dcompare44,6compare54,7compare70;set3C1. Storedkindbyte1==category,byte2ID;kind2requiresbyte3secondary,kind3requires(byte3&1)==secondary;allothermatchingkindsadmittedwithoutlivecategoryallowlist,active1. No original enumlabelsasserted. |
| [o2 0x702380](../recomp/config/output_ovl/o2/o2_00702380_0x702380.cpp) | `script_op_105_disable_matching_scene_category_and_id_records_candidate` | High mechanics; generic helper | Same observedlivecategoryallowlist/fieldmatchesandstoredkind/ID/secondarymatchesas20E0,butlive3C0,storedactive0. Readoverallbodyincludingcategory2branchandcommonnext-recordentry;nofirstmatchreturn. |

Owned73CBE0 descriptorsforopcodes52/53/54,58..5E,F0/F1/F3/F6point
tothelistedentries;filterbytes+4/+5/+6/+7are(0,1,0,0). Consequently
[context interpreter](SYMBOLS_ROOM_SCRIPT_BANK_RUNTIME.md)mayfilterthese
forselector>=2. Owned descriptors at73D400/73D408 additionally bind opcodes104/105
to7020E0/702380 with the same filter bytes. These extended IDs follow
owned pointer evidence, not source adjacency.

The live andstored schemasdiffer: 3Cis a live activation/requestbyte,
while storedbyte0is writtenevenforpreviouslyinactive records. The subtype
setsandtheirpairparametersmustnotbecollapsedintoa generictoggle
withoutretainingthesepredicates. No capturedincidentorcostclaim.
