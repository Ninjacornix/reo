# Special inventory capacity, pickup routing and selected action tables

Static File #1 US, 2026-11-04. Six complete original o2 bodies, physical menu/dispatch tables decoded. Hexadecimal fields/addresses/masks; stated slot counts decimal. High mechanics confidence; gameplaylabels remain candidates. No execution, builds, attachment or measurements.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5F2810](../recomp/config/output_ovl/o2/o2_005F2810_0x5f2810.cpp) | `insert_resource_id_into_category_six_or_content_grouped_special_bank_then_compact_candidate` | High mechanics; role probable | a0actor,a1ID. CategoryB98=6fillsfirstzerooffourC89byteswithresourcebyte2. Category7/content12C/12D/12EscansninebytesinC89/C92/C9Brespectively,thenwritesresourcebyte2atfirstemptyorindex9whenallninefull. Always5F2330(actor);othercategoriesonlycompact. Capacityproof/externaladmissionremainopen. |
| [o2 0x5F29A0](../recomp/config/output_ovl/o2/o2_005F29A0_0x5f29a0.cpp) | `compute_four_slot_inventory_capacity_with_flag_20000_two_unit_cost_candidate` | High mechanics; role probable | FourC84..C87IDs;zero costs0,nonzerocost1if5B43F0(ID,20000)==0else2. Returns4-sumwithoutclamp,maynegativeforinconsistentinput. DoesnotcountC88orauxiliarybanks. |
| [o2 0x5F2A20](../recomp/config/output_ovl/o2/o2_005F2A20_0x5f2a20.cpp) | `count_category_special_bank_capacity_for_active_resource_content_candidate` | High mechanics; role probable | Category6countszeroamongfourC89bytes,evenifrequestedrecordinactive. Thenfullwidtha1IDrecordactivityrequiredforfurtherwork. Category7/content12C/D/EcountszeroamongonlyfirstthreebytesofC89/C92/C9B. Othercategory/contentreturnspriorcount(usually0). Boundsdifferfromnine-byteinsertionsearch;notcollapsed. |
| [o2 0x5F2B70](../recomp/config/output_ovl/o2/o2_005F2B70_0x5f2b70.cpp) | `route_selected_resource_pickup_or_replacement_through_capacity_and_transfer_helpers_candidate` | High mechanics; role probable | a0actor,a1replacementID;sourceactorC7AÃ¢â€ â€™resourceS. EarlyC7F=a1,C80=S2evenclass1reject0. Newpickupusesordinary/specialcapacity,5F5670,5F6DF0,soundandbankinsertion. Replacementcan5F5170combinationor5F54A0/5F5870transfer. Return0forcapacity/classrejection,1forotherhandledpaths;doesnotuniversallypromisephysicaltransfer. Fullroutingbelow. |
| [o2 0x5F2FA0](../recomp/config/output_ovl/o2/o2_005F2FA0_0x5f2fa0.cpp) | `build_selected_resource_eight_byte_inventory_action_menu_candidate` | High mechanics; role probable | SelectedID=actorC84[global3B85A0],5B4380template;signedbyte10==-1returns0. Otherwisecopiesexact8bytes70C5A0+8*rowto3B85A8..AFandreturns1. Nosourcecategorybound,selectionclamporqueryownershipcheck. |
| [o2 0x5F3020](../recomp/config/output_ovl/o2/o2_005F3020_0x5f3020.cpp) | `dispatch_selected_inventory_command_and_flush_pending_actor_state_notification_candidate` | High mechanics; role probable | a0actor;selectedbyteactorC84[3B85A0]==0returns1. Otherwisemodebyte3B85A8[3B85A1]indexes70C620,call(actor,&selectedSlot). Saveslow8result;nonzeroD92calls67E230(actor,7),clearsD92,returnssavedresult. No8entryguardoritemmutationrollback. |

5F2810 category6hasproperfour-entryloopandonlywritesonfoundempty. Category7loopchecksindices0..8butfallsthroughwhenindex9isreachedandstillwritesbankBase+9. Thisexactlocalbehaviorrequirescaller-capacityadmission;itdoesnotproveanactualoverflowincident.5F2A20category7countsonlyindices0..2,not9;neitherhelperchecksquantity/ownershipbeforecounting.5F2A20fulla1addressarithmeticdiffersfromlow8queryhelpers;actualobservedcallerpassesunsignedresourcebyte2.

5F2B70 sourceS=3C5630+3C*unsignedactorC7A. Storesreplacementlow8C7F,S.byte2Ã¢â€ â€™C80beforeclass1return0. Ifreplacementlow8==0:when3B85A0<4orB98<6,requiredcost=1/2fromS2flag20000andfree5F29A0must>=cost;otherwiserequires5F2A20(actor,S2)!=0. Then5F5670(actor,0,low8S.half28,S2),signedlow8result0returns1withoutlaterinsertion;nonzeroauthority1sound7,5F6DF0(actor,S2),commoninsert.

Replacementnonzero:when4BAE84>=2and4BAE85==1,or5B3DD0(replacement,S2)==3,call5F5170(actor,0,low8owner,Sreplacement,S2). Itsresult0returns1;result1authoritysound5andreturns1;result2also5F6DF0beforethatsound/return;othercodesfallnormalreplacement. Ordinaryreplacementchecksfree5F29A0+cost(replacement)>=cost(S2),elsereject0. IfS.half28==0:5F54A0(actor,0,S2,replacement);result0returns1,other5F6DF0(S2),5F6D20(replacement),authoritysound8,commoninsert. Nonzeroowner:5F5870(actor,0,low8owner,S2,replacement);onlyresult1continuesauthoritysound8andfinalreplacement-eventpath;otherresultsreturn1becausev0isexplicitlyreset1beforethecomparison,notpropagated.

Commoninsertwhen3B85A0>=4andB98>=6uses5F2810(actor,S2),elseexisting5F27B0ordinaryslotinsertion. Authorityexact1andS2templateflag10set:5B4DC0(S2) signedbyte!= -1Ã¢â€ â€™570970(event). Newpickupfinishes1. SuccessfulownedreplacementfinalpathinsteadchecksreplacementIDflag10andpublishesits5B4DC0eventthenreturns1. Lowerhelperstate/resourceownershipmutationsareseparatecontracts;thiscoordinatorhasnocallsiteevidenceprovingeveryhandledcodecompletedtransfer.

Owned o2base570000SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Span | Exact content | SHA256 |
| --- | --- | --- |
|70C5A0..70C61F|Sixteen8-bytemenurowslistedbelow;physicalextentnotnewvalidtemplaterowbound|`7ac043b135b236d32d06aecd6a5e6f434fd4c1c3c9115fef4a60fb01e0fc680c`|
|70C620..70C63F|Eightcallbackwords5F30C0,5F30D0,5F31C0,5F34D0,5F3EA0,5F4310,5F4370,5F4660|`a957311069a09aaf803a66daccd27baf9336e1286fa63c12d5c6c384d770f43f`|

Bytesafter70C63Farenotadditionalprovenfunctionpointers;adjacencydoesnotjustifya16-entrydispatchclaim. Allsevennontrivialcallbacktargetsareindependentlyreviewedin [selectedcommandflows](SYMBOLS_INVENTORY_SELECTED_COMMAND_FLOWS.md).5F30C0isJRRAwithdelayreturn1,identicaltoexisting5B2870andnotanewsemanticrow. Existing [inventorymutationhelpers](SYMBOLS_SINGLE_INVENTORY.md) and [resourcequeries](SYMBOLS_INVENTORY_QUANTITY.md)retaintheirseparateidentities.

| Rowhex | Exact bytes hex |
| --- | --- |
|0|00 00 00 00 00 00 00 00|
|1|02 04 06 00 00 00 00 00|
|2|01 03 04 06 00 00 00 00|
|3|01 04 06 00 00 00 00 00|
|4|04 06 00 00 00 00 00 00|
|5|02 04 06 00 00 00 00 00|
|6|01 03 00 00 00 00 00 00|
|7|01 00 00 00 00 00 00 00|
|8|02 00 00 00 00 00 00 00|
|9|04 00 00 00 00 00 00 00|
|A|00 00 00 00 00 00 00 00|
|B|02 04 00 00 00 00 00 00|
|C|02 04 01 06 00 00 00 00|
|D|07 04 06 00 00 00 00 00|
|E|04 00 00 00 00 00 00 00|
|F|00 00 00 00 00 00 00 00|

Owned-word audit:6 rows,494 distinct instruction words verified,53 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited. Plainbyte-equivalentaliasesarenotnewsemanticrows.
