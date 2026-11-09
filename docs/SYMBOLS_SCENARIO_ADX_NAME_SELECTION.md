# Scenario ADX name selection

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed.
Addresses/offsets are hexadecimal. No game/build/replay/attachment/live-memory
inspection. Static names identify ADX input selection; no audio playback or
captured-incident relationship was measured.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6D73F0](../recomp/config/output_ovl/o2/o2_006D73F0_0x6d73f0.cpp) | `prepare_current_scene_adx_stream_from_scenario_name_table_candidate` | Probable role; full body reviewed | Formats currentunsigned scene bytes38ECD0/D1/D2 with owned7426B8 "%02d_%02d_%d";7520 resolvesbasename. Nonnullname formats "%s%s.adx" with "demo\\" prefix, then1AE7D0(channel1,mode0,path,archive0). No readinesspollorstartconfirmationhere. |
| [o2 0x6D7470](../recomp/config/output_ovl/o2/o2_006D7470_0x6d7470.cpp) | `select_scene_list_adx_entries_and_restart_stream_candidate` | Probable role; full body reviewed | Pretestedcount unsigned4BAE0B;eachindex reads scene triples at4BADD0+3*i+66/67/68 (base4BAE36),formatskey/resolves7520. Nonnullformatsdemo ADXpath and1AE9F0(1,path). Afterallentries1AEA70(1),1ADF00(1). Zerocountstillcallsrestart/finalcall; doesnotvalidateeachstreamentryorwaitforcompletion. |
| [o2 0x6D7520](../recomp/config/output_ovl/o2/o2_006D7520_0x6d7520.cpp) | `lookup_scene_adx_basename_by_scenario_and_scene_key_candidate` | High mechanics; probable role | a0 keystring. Globalunsignedhalf3243DA==0 returnsnull. Otherwise scans owned732890 (scenarioID,pointer) pairs untilnegativeID:1->731E40,2->732190,1C->7322E0,23->732440,29->7325A0. Matchedtable scans (key,value)8bytepairs untilnullkey;10AE78 strcmp==0 returnsvaluepointer,else null return. Originalnoexplicitlengthlimit; terminationestablishedforownedtables,notarbitraryexternaldata. |

Owned table verification: scenario1 has105 nonnull scene pairs,2 has40,1C
has42,23 has43,29 has93; each terminates with a null key before the next
owned table. Main scenario table has five entries then FFFFFFFF/0 sentinel.
Example keys/names include03_00_0/s010300a,00_00_0/s020000a,
00_00_0/s280001a,01_00_0/s350100a,00_00_0/s410000a. These are basename
associations, not mappings of individual engine-rendered cutscene functions.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
