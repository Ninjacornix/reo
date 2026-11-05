# Gameplay UI state, stat notification and obtained-item text helpers

Static File #1 US research, 2026-11-04. Nine complete original bodies reviewed.
Addresses/offsets hexadecimal; explicit counts decimal. No game/build/replay,
attachment or live-memory inspection. The central dispatchers are already in
SYMBOLS_DISPATCH.md and are not recounted. W=755EC0 UIwork, G=4BAD30 globals.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6DEBB0](../recomp/config/output_ovl/o2/o2_006DEBB0_0x6debb0.cpp) | `snapshot_gameplay_ui_input_and_actor_stat_words_candidate` | Probable role; full body reviewed | W3CE0=low16global4BAE90. If1B0310==1useslocal4BADEDactorF80elseactor0F80->W3CE2. Copies324228wordtoW3CE4,324234/36/30/3C/3E/38halvestoW3CE6/EA/EE/E8/EC/F0. Valuesnotsigned-normalized;nosamplingrateorglobalgame-updateclaim. |
| [o2 0x6DEC80](../recomp/config/output_ovl/o2/o2_006DEC80_0x6dec80.cpp) | `initialize_gameplay_ui_work_and_shared_page_pointers_candidate` | Probable role; full body reviewed | ClearsW[3E84],755B70/755BF0/755A70;sets4BAE33=1,4BAE8C=1. Publishes755770=W+10,755768=759A28mapwork. NolocalallocationorUIwindowconstruction. |
| [o2 0x6DEE20](../recomp/config/output_ovl/o2/o2_006DEE20_0x6dee20.cpp) | `test_gameplay_ui_active_page_with_modal_gate_candidate` | High mechanics; candidate role | 4BAE33zeroorW4zero->0. W4==2returns1onlyif4BADEE!=0;allothernonzeropagesreturn1. Doesnotmutatepageorreadkeyboarddirectly. |
| [o2 0x6DEE80](../recomp/config/output_ovl/o2/o2_006DEE80_0x6dee80.cpp) | `test_gameplay_ui_primary_page_four` | High; full body reviewed | ReturnsunsignedbyteW4==4asboolean. Nolocalgateby4BAE33unlikeEE20. |
| [o2 0x6DF160](../recomp/config/output_ovl/o2/o2_006DF160_0x6df160.cpp) | `start_or_extend_actor_stat_notification_candidate` | Probable role; full body reviewed | Rejects3243D2,G+BD,orW4nonzero. DDD70(0)ensuresUIresources. ExistingG+B0setsB2=300decimal;elsestartsB0=B1=1,B2=300,andifselectedactorBA0bit8clearcalls1B87E0(9,0). D190initializesstatuspalette/motioncount,1AFA00(6EA050)registersoriginalcallbackdescriptor. Doesnotownhostdiagnostictoast. |
| [o2 0x6DF260](../recomp/config/output_ovl/o2/o2_006DF260_0x6df260.cpp) | `tick_actor_stat_threshold_notification_state_candidate` | Probable role; full body reviewed | 667F90returnsselectedactorBAC/actor-type-table*100. Roundspercentandpercent*10usingoriginalcvt.w.s. If4BAE8DnonzerocallsF230andreturns. G+B1phase0percent>=95startsF160;otherwisecomparesroundedtenthsagainst12ownedthresholds10/40/60/70/75/80/85/90/91/92/93/94times10;matchandlocalactorBB6/BB8/BBAall0startsF160. Phase1D0A0refresh;W4==2setsB2=1,W4==1holds,otherwisepercent<95decrementsB2and<=0callsF230. Phase2samepage/percenttimeradmission,expiry1AFA70(6EA050),B0=B1=0. Nooriginalstatnameorwall-clocktimerunitclaimed. |
| [o2 0x6DF550](../recomp/config/output_ovl/o2/o2_006DF550_0x6df550.cpp) | `resolve_and_decode_item_name_for_obtained_notification_candidate` | Probable role; full body reviewed | a0low16ID;clearsstatic759CA2. ID>=10000decimalqueries6EC920(scenariolowbyte),searches32fourbyteIDsafterbase4usingID-global759BC4,thenbase84+40*indexstringifindex<=headercount3. LowerIDsrequire755778,selectoneof9owned732A30ranges(firstID<start+size,elselast),scaninclusiveordinalbounds732A58/59matchingrecordbyte3thenbase204+40*recordindex. DecodesselectedstringviaE220;missingreturnsstaticempty759CA2. Noheapallocationorfallbackinventedname. |
| [o2 0x6DF700](../recomp/config/output_ovl/o2/o2_006DF700_0x6df700.cpp) | `show_local_player_obtained_item_text_candidate` | Probable role; full body reviewed | a0itemID,a1low8player mustequallocal4BADED,andW5!=10. F550name;formatsinto755A70usingownedlocalizedobtainedformatselected3243FD. Englishformatcontainsquoted<c2>name<c7>and" obtained.". ComputesX=(640-10*(strlen-8))/2trunctowardzero,then1B4820(7,X,380,90,20,text). Nostatusrecordingorperformanceincidentbundle. |
| [o2 0x6DF7E0](../recomp/config/output_ovl/o2/o2_006DF7E0_0x6df7e0.cpp) | `configure_actor_ui_text_from_type_pointer_table_candidate` | Probable role; full body reviewed | a0actor;unsignedB98indexes7342C0wordtableintoa2,tailcalls1BA250(actor,0,pointer). Noindexcheck,lookupsideeffectsdelegated. Notafontflushadapter. |

Threshold comparisons use rounded guest COP1 values, not a floating epsilon.
Notification logic and page updates are guest UI behavior; their frequency,
visibility and slowdown relevance remain unmeasured.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
