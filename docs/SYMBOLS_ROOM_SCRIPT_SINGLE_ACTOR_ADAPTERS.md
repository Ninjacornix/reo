# Room-script single-actor navigation and resource adapters

Static File #1 US research, 2026-11-04. Sixteen complete original bodies
reviewed. Addresses/offsets hex unless marked decimal. Actor table is4A5C30
with10E0 stride; FF0 admission connects these adapters to previously mapped
single-actor overlay behavior. No execution, attachment, build or engine changes.
Original action/flag enum names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x702620](../recomp/config/output_ovl/o2/o2_00702620_0x702620.cpp) | `script_op_1a0_select_single_resource_variant_candidate` | High call contract; role supported by callee | Passespayloadwords0/4/8to816460(ids,variant),returns0. Existingcalleeeditsresourcevariantandresetsall8activeFF0actors;thiswrapperisnotread-only. |
| [o2 0x702650](../recomp/config/output_ovl/o2/o2_00702650_0x702650.cpp) | `script_op_1a1_set_single_actor_weight_profile_by_slot_or_identity_candidate` | High mechanics; probable role | Payloadword0selector,word4index/identity,word8profile. Selector0directplayer4A5C30+10E0*index,requiresactivebyte0andFF0,8123E0(actor,profile). Nonzeroselectorscanunsigned4BAEA0count,activeFF0actorswhoseB98==identity;calls8123E0forallmatches. Returns0;wrapperdoesnotvalidateprofilelowerbound. |
| [o2 0x702740](../recomp/config/output_ovl/o2/o2_00702740_0x702740.cpp) | `script_op_1a2_warp_single_actor_room_and_bind_navigation_candidate` | High mechanics; probable role | Payloadslot0,room4,entry8;requiresactivebyte0/FF0. Writes1E2room,100Centry;817170(XYZ,room,entry),813380(actor,0),81A6E0(actor,0). Ifnewroom!=3243DC,byte1=0,BA4&FFFF3FFF,CEC/CF00,CE8=-1. Allpaths54F0,8=1,9/A/B0,667370.8196E0(room,entry)!=-1writes1054,100Dentry,1058room,then819880(actor,1);return-1skipstail812170. Otherwise812170(actor,1). Returns0;callerindexboundsunknown. |
| [o2 0x7028A0](../recomp/config/output_ovl/o2/o2_007028A0_0x7028a0.cpp) | `script_op_1a3_set_single_actor_script_action_and_yaw_candidate` | High mechanics; probable role | Payloadslot0,action4,signedyawhalf8;activeFF0required. AD4=1,AD5=actionlowbyte,yaw92;offroomclearsbyte1,BA4bitsC000,CEC/CF0,CE8=-1.54F0,8=1,9/A/B0,667370. Fornonzeroactorslot,offroomaction25calls64AE50. Always813380(actor,0),81A6E0(actor,0),returns0. Doesnotwriteactorroom. |
| [o2 0x7029E0](../recomp/config/output_ovl/o2/o2_007029E0_0x7029e0.cpp) | `script_op_1a4_set_active_single_actor_byte_ff1_candidate` | High mechanics; original flag meaning unknown | Payloadslot0,state4. Activebyte0andFF0required;state0->FF1=0,state1->FF1=1,otherspreserve. Returns0;noprofile/navigationreset. |
| [o2 0x702A60](../recomp/config/output_ovl/o2/o2_00702A60_0x702a60.cpp) | `script_op_1a5_set_eight_active_single_actor_word_1034_candidate` | High mechanics; original flag meaning unknown | Fixed8actorrecords;activebyte0/FF0required. Payloadword0==1sets1034=1;allothervaluesclear1034. Noqueryorwriteforinactiveactors;returns0. |
| [o2 0x702AD0](../recomp/config/output_ovl/o2/o2_00702AD0_0x702ad0.cpp) | `script_op_1a6_set_single_actor_navigation_target_and_state_candidate` | High mechanics; probable role | Payloadslot0,target4,state8;activeFF0required. Writes10A0=targetbeforestatebranch. State0/1/2/3maps109Cto4/2/0/1,respectively;others-1.813380(actor,0),81A6E0(actor,0),returns0. Noassumedoriginalenumlabels. |
| [o2 0x702BC0](../recomp/config/output_ovl/o2/o2_00702BC0_0x702bc0.cpp) | `script_op_1a7_clear_single_actor_navigation_target_override_candidate` | High mechanics; probable role | Payloadslot0,activeFF0required;10A0=0,109C=-1,813380(actor,0),81A6E0(actor,0),returns0. Doesnotclearentireactor. |
| [o2 0x702C50](../recomp/config/output_ovl/o2/o2_00702C50_0x702c50.cpp) | `script_op_1a8_set_eight_active_single_actor_byte_10a8_candidate` | High mechanics; original mode meaning unknown | Fixed8activeFF0actors;payloadword0==1/2stores10A8=1/2;allothers0. Noactoridentityfilter;returns0. |
| [o2 0x702CE0](../recomp/config/output_ovl/o2/o2_00702CE0_0x702ce0.cpp) | `script_op_1a9_deactivate_single_actor_with_status_cleanup_candidate` | High mechanics; probable role | Payloadslot0,activeFF0required;BA0|5E0,5F6800(actor,0),clearbytes0/1,returns0. DoesnotclearFF0orzero110-bytecontrollerrecord. |
| [o2 0x702D70](../recomp/config/output_ovl/o2/o2_00702D70_0x702d70.cpp) | `script_op_1aa_condition_single_actor_at_room_entry_within_30_candidate` | High mathematical contract; probable role | Payloadslot0,room4,entry8. MissingactiveFF0actor->68C9E0andreturn2. Requiresactor1E2roomandsignedbyte100C==entry;817170(stackXYZ,room,entry),817100(actorXYZ,stack,30decimal)==0 (strictdistance<30)passesreturn0. Otherwisefailedskipand2. ThisconditiondoesNOTincrement4BAD58ordinalinthisbody. |
| [o2 0x702E40](../recomp/config/output_ovl/o2/o2_00702E40_0x702e40.cpp) | `script_op_1ab_deactivate_selected_single_actor_when_flag_matches_candidate` | High mechanics; probable role | Usescurrentselected4BADEDactor,activeFF0required. Payloadword0family,4flagID,8desiredtruth. Family0tests4B9C00;nonzeroqueries7008C0contextfamily. Onlytruthmatchesdesiredwordnonzero ->5F6800(actor,0),bytes0/1clear. Returns0;noBA0|5E0unlike2CE0. |
| [o2 0x702F90](../recomp/config/output_ovl/o2/o2_00702F90_0x702f90.cpp) | `script_op_1ac_condition_explicit_threeway_first_flag_bank_candidate` | High mechanics; probable condition role | Payloadword0bank,4ID,8desiredtruth. bank>=3unsignedreturns0withoutordinalincrement. Elseincrement4BAD58[4BADC1],testrawbitat4B9A80+40*bank. Truthmatchreturns0,mismatch68C9E0and2. Explicitbankselectionignores75A4B0contextselector. |
| [o2 0x703080](../recomp/config/output_ovl/o2/o2_00703080_0x703080.cpp) | `script_op_1ad_mark_active_first_three_actor_status_bit_candidate` | High mechanics; flag meaning unknown | Payloadslot0unsigned<3andactoractivebyte0nonzero ->byte32=1,BA0|400000. NoFF0gate. Othersreturn0withoutwrites. |
| [o2 0x7030F0](../recomp/config/output_ovl/o2/o2_007030F0_0x7030f0.cpp) | `script_op_175_allocate_owned_resource_then_try_single_actor_action_candidate` | High mechanics; probable resource role | Payloadsignedhalfslot0,content4,quantity8,actionargC. Content>=0and0<=slot<signedbyte4BAEA0,activeFF0actorrequired.592A90(slot,content,quantity)nonnull->826CB0(actor,resourcebyte2,actionarg). Return0always. Doesnotdirectlyinsertresourceintoabankinthiswrapper;allocationownershipandactionfailurehandledelsewhere. |
| [o2 0x7031E0](../recomp/config/output_ovl/o2/o2_007031E0_0x7031e0.cpp) | `script_op_176_allocate_resource_for_first_matching_single_actor_identity_candidate` | High mechanics; probable role | Payloadsignedbyteidentity0,signedhalfcontent4,quantity8,actionargC. Content>=0,identity0..7;scan signedbyte4BAEA0countforFIRSTactivebyte0actorB98match. ThenrequiresFF0;failuredoesnotsearchlatermatchingactors.592A90(foundactorslot,content,quantity)nonnull->826CB0(actor,resourcebyte2,actionarg). Return0always. Preservesidentityversusroster-slotdistinction. |

Owned extended descriptor sites73D8E0..73D948 bind opcodes1A0..1AD
to the fourteen listed702620..703080 entries.175/176bindat73D788/73D790
to7030F0/7031E0. Filters+4/+5/+6/+7:1A0..1A4and1A9=(1,1,1,0);
1A5..1A8,1AA/1AC/1AD=(0,0,0,0);1AB=(0,0,1,0);175/176=(0,1,1,0).
TheseareownedpointerevidenceforextendedopcodeIDs,notaproposednew
maximumopcodeboundfortheinterpreter.

Related[single navigation](SYMBOLS_SINGLE_NAVIGATION.md),
[single goals](SYMBOLS_SINGLE_GOALS.md),
[resource allocation](SYMBOLS_RESOURCE_DATA_LOADING.md), and
[resource action](SYMBOLS_RESULTS.md). The conditionradiusisstrict;
equalityandunorderedfloatcomparisonfail817100'sadmission. Nooriginal
resource/gameplaynames,measuredperformanceorincidentcauseisasserted.
