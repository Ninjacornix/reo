# Room script banks, contextual flags and filtered interpreter

Static File #1 US research, 2026-11-04. Sixteen complete original bodies
reviewed. Addresses/offsets hex unless marked decimal. No execution, build,
attachment or engine changes. Script roles follow record headers, payload
handlers and the previously mapped68C990/68C9E0 condition helpers.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x700210](../recomp/config/output_ovl/o2/o2_00700210_0x700210.cpp) | `bind_room_script_banks_for_first_three_active_players_candidate` | High routing; probable role | Pretestedfixedthreeplayers4A5C30+i*10E0;active signedbyte0nonzero ->700330(owned73CBD0[i],playerroom1E2). Ownedmappingis1,2,3. Doesnotvisitfourthplayerorswapselectedplayerindex. |
| [o2 0x700290](../recomp/config/output_ovl/o2/o2_00700290_0x700290.cpp) | `bind_room_script_bank_selected_by_actor_slot_threeway_candidate` | High routing | Actorbyte3<3 ->700330(73CBD0[byte3],actorroom1E2),otherwiseonlyreturns. Noactorbyte0admissionqueryhere. |
| [o2 0x7002D0](../recomp/config/output_ovl/o2/o2_007002D0_0x7002d0.cpp) | `bind_and_execute_room_script_in_explicit_room_mode_candidate` | High mechanics; probable role | a0room.700330(73CBD0[0]=1,room);sets75A4B8=room,75A4C0=2,75A4B0=1;7006D0(1). Leavescontextvaluespublished;nostaterestoreinthisbody. |
| [o2 0x700330](../recomp/config/output_ovl/o2/o2_00700330_0x700330.cpp) | `initialize_room_script_bank_from_room_resource_descriptor_candidate` | High mechanics; probable role | a0fullbank,a1room. Sets3243E9=1,readsdescriptorpointer83E5E4+A4*room. Bankarrays:4BAD10[bank]=8,4BACF8[bank]=0,4BACE0[bank]=descriptor20,4BAD40[bank]=descriptor. Globals4BAD24=C,4BAD0C=0,4BACF4=descriptor30,4BAD54=descriptor. Nobank/room/pointervalidationinthisbody. |
| [o2 0x7003E0](../recomp/config/output_ovl/o2/o2_007003E0_0x7003e0.cpp) | `execute_three_player_room_scripts_and_merge_two_flag_families_candidate` | High mechanics; probable role | a0lowbyte1:save4B9C00/4B9C40two64-byteflagbanksincache75A430/75A470. Fixedi0..2 setsselectedplayer4BADED=i;activeactorsonlyset75A4C0=(actorroom!=3243DC),75A4B8=room,75A4B0=actor3+1,restorebothflagbanksfromcache,execute7006D0(lowbyte73CBD0[actor3]). Computes16wordsperfamily set-delta=new&~cached andclear-delta=cached&~new intoperplayer128-bytebanks75A2B0/75A130+80*i. ThenmergesALLthreecachedbankssequentiallyintooriginalcacheusingORsets/AND~clears,publishesbothflagbanks,andsetsselectedplayer0. Inactiveplayerdeltabanksarenotrefreshedinthisbodybutareincludedinmerge. Allothermodevaluesreset75A4C0/4B8/4B0to0thenexecute7006D0withinheritedoriginala0,notanexplicitbank0argument. Noassumptionaboutunsupportedmodesorinitialcacheadmission. |
| [o2 0x7006D0](../recomp/config/output_ovl/o2/o2_007006D0_0x7006d0.cpp) | `interpret_context_filtered_room_script_bank_candidate` | High mechanics; probable role | a0low8bank->4BADC1;3243E8zeroexits. Clear4BAD58[bank]conditionordinal;currentPC=4BACE0[bank]. Readsheaderthenifwait4BACF8[bank]nonzero,decrementswaitandexits. Oplow24indexes8-byte73CBE0descriptor(function,+4/+5/+6filters). Skipwhenfilter5andselector75A4B0>=2;orcontext75A4C0==1andfilter4;orcontext2andfilter6. Admittedhandler(payloadPC+4)returnsstatus. Skippednestingopenervia68C990incrementsbank+78and68C9E0skipsgroup,status2. Status2reloadsheaderfrompossiblychangedPC;otherwiseopA/Dreturns. Nonzerostatusreturns toloopwithoutnormalPCadvance. ZerostatusadvancesPCby4*(1<<headerhigh8),thencontinues. Noopcodeboundorper-callbudgetcheck;well-formedstream/admissionunknown,notareproducedhang. |
| [o2 0x7008C0](../recomp/config/output_ovl/o2/o2_007008C0_0x7008c0.cpp) | `query_first_context_selected_script_flag_family` | High bit mechanics | a0bitID. selector75A4B0zero->base4B9A80;nonzero->4B9A40+40*selector. Returnsrawbitmaskword&(1<<(ID&1F));wordindexID>>5. Notnormalizedboolean;noboundscheck. |
| [o2 0x700930](../recomp/config/output_ovl/o2/o2_00700930_0x700930.cpp) | `query_second_context_selected_script_flag_family` | High bit mechanics | Samequerybutselector0base4B9B40,nonzero4B9B00+40*selector. Rawbitmaskreturn. |
| [o2 0x7009A0](../recomp/config/output_ovl/o2/o2_007009A0_0x7009a0.cpp) | `set_first_script_flag_in_selected_or_all_three_banks` | High bit mechanics | selector0ORsbitintothreebanks4B9A80/4B9AC0/4B9B00;nonzerowritesonly4B9A40+40*selector. IDword/bitindexas8C0. Noarrayboundsvalidation. |
| [o2 0x700A50](../recomp/config/output_ovl/o2/o2_00700A50_0x700a50.cpp) | `set_second_script_flag_in_selected_or_all_three_banks` | High bit mechanics | selector0ORsbitintothreebanks4B9B40/4B9B80/4B9BC0;nonzerowrites4B9B00+40*selector. Separateflagfamilyfrom9A0. |
| [o2 0x700B00](../recomp/config/output_ovl/o2/o2_00700B00_0x700b00.cpp) | `clear_first_script_flag_in_selected_or_all_three_banks` | High bit mechanics | AND~bitinthreefirst-familybankswhenselector0,otherwiseselectedbank4B9A40+40*selector. SameIDcontractas9A0. |
| [o2 0x700BB0](../recomp/config/output_ovl/o2/o2_00700BB0_0x700bb0.cpp) | `clear_second_script_flag_in_selected_or_all_three_banks` | High bit mechanics | AND~bitinthreesecond-familybankswhenselector0,otherwiseselectedbank4B9B00+40*selector. Noimplicitpaired-familyclear. |
| [o2 0x700C60](../recomp/config/output_ovl/o2/o2_00700C60_0x700c60.cpp) | `script_op_spawn_actor_bound_callback_after_room_counter_and_flag_admission_candidate` | High mechanics; probable role | Payloadwords0IDoffset,4mode,8counterindex,Ctaskslot,10flagID. Requires signedhalf4A1DF0+30*3243DC+2*counterindex<=0and4B9C00flagIDclear. Existingtask3B64D0+AA0*selectedplayer+110*taskslot:ifactive,callback1C==word70A18Candphase4==6,calls5F4FD0,playeraction1C,conditionallyclearsitsresourceflag,optionally6803C0(task60,0,0,selectedplayer),then5B93B0. ReadsmodelIDbytefrom[324424]+8004relativebank+IDoffset;nonzeromodebecomes6.570270(selectedplayer,mappedID,mode),5703E0(flagID,1). Returns0onallpaths. Nooriginalcallbackclassguess. |
| [o2 0x700E70](../recomp/config/output_ovl/o2/o2_00700E70_0x700e70.cpp) | `script_op_route_global_or_context_flag_write_candidate` | High mechanics | Payloadword0type,word4flagID,byte8state. Type0->5703E0(ID,state);type1statezero700B00else7009A0;type2->570450(ID,state). Othertypesnosideeffect. Returns0. |
| [o2 0x700F00](../recomp/config/output_ovl/o2/o2_00700F00_0x700f00.cpp) | `script_op_route_second_context_or_scene_flag_write_candidate` | High mechanics | Payloadword0type,word4ID,word8state. Type0directclear/set4B9C40bit;nonzerotype statezero700BB0else700A50. Returns0. Typeiszero/nonzero,notanuncheckedmulticaseswitch. |
| [o2 0x700FB0](../recomp/config/output_ovl/o2/o2_00700FB0_0x700fb0.cpp) | `script_op_update_matching_live_and_room_descriptor_scene_modes_candidate` | High mechanics; probable role | Payloadwords0ID,4newmode,8secondaryID. Context75A4C0zero:3B5150==80earlyreturns0;otherwisewalkslive3B5160/next28. Category0word40==IDwrites6C=newmodeand72=0;category2word40==IDand50==secondarywrites6C. Theneveryordinarypathwalksstaticroomarray:descriptorpointer83E5EC+164*75A4B8,count83E550+A4*room+98,16-byterecords. Activebyte0,kindbyte1==0/2,andIDbyte2match;kind2additionallybyte3secondarymatch ->half4=newmode. Returns0;allmatchesupdated,nocycliclistorroomrangeguard. |

Owned73CBD0 hasthreewordbankIDs1,2,3. Descriptor73CBE0 uses8-byte
entries;opcodeBpoints700E70withfilterbytes(1,0,1,0),opcodeC700F00
withthesamebytes. Existing opcodes0..AandD largelyreuse68C-series
handlers. Reviewingtheinterpreterdoesnotautomaticallyrevieweveryopcode
destinationorsupplyasupportednumericopcodebound.

Contextglobalsare75A4B0(selector),75A4B8(room),75A4C0(mode). Aselector
zero write updates threebanks; queriesatselectorzero read the firstbank.
Theseobservedsemanticscannotbereplacedbyanassumedglobal/per-player
namespacewithouttracingthecaller. The three-player merging routine resets
selectedplayerindex0onexitratherthanrestoringtheincomingindex.

Related[script VM](SYMBOLS_SCRIPT_VM.md),
[condition helpers](SYMBOLS_TASK_FLAGS.md), and
[single-room navigation binding](SYMBOLS_SINGLE_NAVIGATION.md). The latter
providesstaticcallersforthethreebank/explicit-roomentrypoints. Original
streamadmissionandtheplayerartifactstillrequireevidencebeforeany
performanceorcorrectnessdiagnosis.
