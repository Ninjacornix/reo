# Inventory action guards, response messages and cursor movement

Static File #1 US, 2026-11-04. Eight complete original o2 bodies. Hexadecimal addresses/fields/masks; fixedscan/stringcountandexplicitvaluesdecimal. High mechanics confidence, role labels candidates. No game, builds, attachment, live memory or measured cost.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5F1B40](../recomp/config/output_ovl/o2/o2_005F1B40_0x5f1b40.cpp) | `test_actor_substate_blocks_resource_action_with_auxiliary_mode_exception_candidate` | High mechanics; role probable | Returns1ifaction8!=1. Class0/mode1B02D0==1/FF0nonzero:state9<Creturns0through12identicalownedtargets,otherwise1. Otheractorsstate9in1A,34,4A,6D,74,81,98,A3,C5,CDreturns1;others0. Noresource/roomqueryormutation. |
| [o2 0x5F1C50](../recomp/config/output_ovl/o2/o2_005F1C50_0x5f1c50.cpp) | `test_actor_flags_and_mode_specific_resource_action_blocking_candidate` | High mechanics; role probable | BA0&160,action8!=1,BD0nonzeroorBA080reject1. BA018permitsonlylow8mode2. Modes1/3/6/9delegate5F1B40;mode7delegatesandalsorejectsbyte174==1. Othermodespass0aftercommongates. Notgeneralactorreadinessorsuccess1. |
| [o2 0x5F1E80](../recomp/config/output_ovl/o2/o2_005F1E80_0x5f1e80.cpp) | `copy_default_or_content_3201_item_use_rejection_text_to_shared_buffer_candidate` | High mechanics; role probable | Copiesresident1C1DA0(0)to743550with10AFC0;resourcehalf6==3201replaceswith1C1DA0(1). Returns743550. Noresourceactivityorstringlengthguard;residentownedtextsidentifyunnecessary-useversusadditional-placementrejection. Destinationisruntimeoutsidefile-backedo2. |
| [o2 0x5F1F10](../recomp/config/output_ovl/o2/o2_005F1F10_0x5f1f10.cpp) | `test_selected_resource_template_flag_one_is_absent_candidate` | High mechanics | Ignoresa0;a1resourceIDâ†’5B43F0(ID,1),returnBoolean(result==0). Inactive/defaultquery0thereforereturns1. Neverreturns2;callerbranchesfor2arenotreachablethroughthisbody. |
| [o2 0x5F1F40](../recomp/config/output_ovl/o2/o2_005F1F40_0x5f1f40.cpp) | `get_resource_action_class_as_signed_byte_adapter_candidate` | Confirmed adapter | Calls5B4D50(originala0),returnsresultsignedlow8. Noactorargument,UIselectionorresourceownershipcheck. |
| [o2 0x5F1FA0](../recomp/config/output_ovl/o2/o2_005F1FA0_0x5f1fa0.cpp) | `apply_resource_effect_record_actor_target_context_and_show_result_message_candidate` | High mechanics; role probable | a0resourceID,a1initiatingactor,a2targetactor;a3unused.5B2080(ID,target)resultpreservedsignedlow8. AlwaysinitiatorC82/C7F=ID,D92|10,DA2=targettype3,663190(actor,1,2). Result0shows5F1E80rejection;1/2shows6E8980completionunlessselectedUIaction7;fixedcounter78/messagepublication. Returnsoriginaleffectcode. |
| [o2 0x5F46C0](../recomp/config/output_ovl/o2/o2_005F46C0_0x5f46c0.cpp) | `move_inventory_slot_action_or_binary_target_cursor_from_prioritized_direction_input_candidate` | High mechanics; role probable | a0actor,a1numericcursorcontext<9. Inputowner0when1B0310==1elseactorbyte3. Reads324318+30*owner,mergesheldlowFwithbits16..19;exactmask1/2decrements/incrementsoneofthreeUIcursorsbyowned73EE70dispatch. Bounds/nextnonzeroactioncontrolsound1B8820. Noitemmutationorconfirmhandling. |
| [o2 0x5F4F00](../recomp/config/output_ovl/o2/o2_005F4F00_0x5f4f00.cpp) | `clear_matching_actor_ui_owner_gate_when_inventory_ui_is_closed_candidate` | High mechanics; role probable | Class0andfull(actorbyte3+1)==globalbyte4BADEErequired;gate1..4only. Ifhalf324200!=1and6DEE20()==0clearsgate0. Otherpathsreturn. Encoded6E1430callrequiresgate0afterearlier1..4admission,soisunreachableundernormalentryinvariants;noactualclosecallclaim. |

Commonguardreturnsareblocked1,allowed0.5F1C50low8mode2canpassBA018butstillmustpassBA0160/80/BD0/actiongates;itisnotanunconditionaloverride. Mode7firstmust5F1B40==0,thenbyte174!=1. Originalreasonfor174/BD0blockedstatesremainsnumeric;nointeractionnameinvented.

5F1FA0messagepathsstorepointer743650andhalf743548=78,then6EC980(pointer,78). Thathelpercopiesexact80bytesandscalescounterby3243CC;itisnotasynchronousfileexport. Effect0rejectionbuilderfirstcopiesgeneraltextthenspecialcontent3201replacement. Effect1/2whenbyte3B85A8[unsignedbyte3B85A1]==7skipscompletionmessage;otherwise6E8980sharedmessage,thenpublication. Othercodesnomessage. Noactorinventoryreferencecleanuphere;highercallersinterpretcodes2/3.

5F46C0ownedcontexts0/1/4/6selectrespectivelyslotcursor3B85A0,actioncursor3B85A1,binarytargetcursor3B85A2,secondslotcursor3B85A2;contexts2/3/5/7/8return. InputD=(word&F)|((word&F0000)>>16),thenD&F;onlyexact1/2processed,simultaneousoppositesignored. Context0moves0..3. Context1decrementfloors0,incrementonlyifcurrent<7andbyte3B85A9[current]!=0;keepswithinavailableactionlist. Context4decrementfloors0/incrementwhen<1;context6moves0..3. Changedcursoremits1B8820;nochangeissilent.

Owned o2base570000SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Span | Exact words | SHA256 |
| --- | --- | --- |
|73EE20..73EE4F|Twelveidentical5F1BB8targets,allreturn0|`edbbfd0636a56e564b481ba9d3a8ec04c64f9ca397df20ab5febcf7b4da7f81f`|
|73EE70..73EE93|5F4720,5F47C0,5F49B4,5F49B4,5F4884,5F49B4,5F491C,5F49B4,5F49B4|`a0ebd13b26e67de86de4e98ec667a592e6afb82b2718d8b37fc84dd24dbf2763`|

Plainaliases5F1B30and5F46B0areeachJRRA/NOP,byte-identicaltoexisting573590noop. Theyarecheckedbutnotaddedassemanticrows. [Residentrejectiontexts](SYMBOLS_RESIDENT_TEXT_TABLES_AND_TAG_PARSER.md),[resourcestate/effecthelpers](SYMBOLS_RESOURCE_EFFECTS_AUX_LISTS.md) and [inventorycompletionformatting](SYMBOLS_INVENTORY_ICON_AND_DRAW_HELPERS.md)providecalleeprovenance. NooriginalUIfeaturecostorslowdowncauseproven.

Owned-word audit:8 rows,469 distinct instruction words verified,65 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited. Plainbyte-equivalentaliasesarenotnewsemanticrows.
