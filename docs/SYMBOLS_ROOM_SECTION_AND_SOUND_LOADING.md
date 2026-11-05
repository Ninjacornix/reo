# Room section dispatch, auxiliary motion banks and sound loading

Static File #1 US research, 2026-11-04. Main **SLUS_207.65**, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Full original bodies, room callback table and filename bytes reviewed. No game, loading, audio playback, build or live state inspection.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1D3560](../recomp/config/output/sub_001D3560_0x1d3560.cpp) | `allocate_secondary_model_node_bank_and_bind_static_defaults_candidate` | Confirmed reviewed node helpers | If model pointer4 exists, fills816 halfword count of pointer entries via1B1260 and binds them through193580(pointer4,resource80C). No allocation-failure or existing-node release guard. No motion evaluation here. |
| [0x1D35D0](../recomp/config/output/sub_001D35D0_0x1d35d0.cpp) | `assign_six_slot_enemy_motion_bank_and_optional_second_bank_candidate` | Confirmed cache/constructor chain; second file role partial | Low8 a1 group skips if4BAEB0[group]!=FF. Finds first of six banks4BEC30 strideC84 with byte1==0; assigns group->slot before loading. Tries1CF960(copy cached enemy group; variant argument ignored by reviewed callee). On miss selects descriptor387E90[group]+16*low8 a2, byte2 indexes filename-pointer region3889E0; reads flags20001 and constructs1D1960(stride200,bias0) without positive-read guard. Descriptor byte2<50 decimal additionally selects388AA0 filename; positive read builds kind2 bank4BD4A0+3EC*slot via1D1990. No rollback of group assignment on failed read. Original a0 unused. |
| [0x1D3790](../recomp/config/output/sub_001D3790_0x1d3790.cpp) | `read_current_room_rdt_from_disk_or_archive_and_store_byte_count_candidate` | Confirmed owned filename | Current halves3243DA/DC/DE form `data/rdt/r%03d%02d%02d.rdt` through1CC8F0(mode1), or short `r%03d%02d%02d.rdt` through1AA3E0 when3243D7!=0. Destination324420; return count stored32441C without validation. |
| [0x1D3830](../recomp/config/output/sub_001D3830_0x1d3830.cpp) | `load_relocate_and_dispatch_room_sections_through_owned_callback_table_candidate` | Confirmed table-driven room resource orchestration | Zeroes300000 bytes at324420, invokes1D3790, relocates32 offset words in eight-byte section records by adding buffer base. Scratch begins align4(base+180000). Walks owned236800 until operation999 decimal: optional section copy18DBB0 to scratch0/1; operation0 calls callback(ptr,size) only for nonzero stored size,1 calls callback(scratch1) if its size nonzero,2 passes both when both sizes nonzero,99 calls with inherited arguments. All12 actual owned rows use section->scratch0 and operation0. No file-read success or section-extent validation before relocation/dispatch. |
| [0x1D3A70](../recomp/config/output/sub_001D3A70_0x1d3a70.cpp) | `load_actor_selected_weapon_sound_bank_synchronously_candidate` | Probable sound role; owned weapon filename and loader | Actor.C7C==FF skips; o2 5B4CE0 returns signed low byte of selected resource template, -1 skips. Calls6B4AE0(slot,selection), formats `weapon%02d`, invokes1D3DC0(name,slot+8).6B4AE0 side effect remains helper-owned. |
| [0x1D3B00](../recomp/config/output/sub_001D3B00_0x1d3b00.cpp) | `queue_actor_selected_weapon_sound_bank_request_candidate` | Confirmed queue distinction | Same actor/template guards and6B4AE0 call as1D3A70, formats `weapon%02d`; invokes1AD610(name,slot+8), the eight-slot bounded request queue, rather than synchronously reading. Ignores queue return. |
| [0x1D3B90](../recomp/config/output/sub_001D3B90_0x1d3b90.cpp) | `load_common_sound_bank_into_slot_zero_candidate` | Confirmed owned string adapter | Tail-routes1D3DC0(owned256658 `common`,0). |
| [0x1D3BA0](../recomp/config/output/sub_001D3BA0_0x1d3ba0.cpp) | `load_start_download_result_or_shop_sound_and_enqueue_cue_candidate` | Confirmed complete catalogue interval including merged entries | Entry1D3BA0 selects0; internal jump entries3BB0/3BC0/3BD0 select1/2/3, all owned in this single catalogue body. Shared1D3BE0 selects `start`/`download`/`result`/`shop`, cue id2000/2500/2500/2500; synchronously loads slotC then calls1ACF80(1,4,cue,0,0). Invalid direct mode can leave stack name/cue uninitialized; only four owned wrappers establish the normal domain. No extra function count for merged entries. |
| [0x1D3CA0](../recomp/config/output/sub_001D3CA0_0x1d3ca0.cpp) | `load_actor_character_voice_bank_into_slot_four_plus_actor_candidate` | Confirmed owned filename | Actor.B98 formats `pl%02d_voi`; loads through1D3DC0 with slot4+actor.byte3. No local character/slot admission. |
| [0x1D3CF0](../recomp/config/output/sub_001D3CF0_0x1d3cf0.cpp) | `load_s01_npc00_sound_bank_into_slot_thirteen_candidate` | Confirmed adapter | Tail-routes1D3DC0(owned256698 `s01_npc00`,D). |
| [0x1D3D00](../recomp/config/output/sub_001D3D00_0x1d3d00.cpp) | `load_current_scenario_common_sound_bank_into_slot_one_candidate` | Confirmed owned filename | Formats `s%02d_com` from half3243DA, invokes1D3DC0(name,1). |
| [0x1D3D40](../recomp/config/output/sub_001D3D40_0x1d3d40.cpp) | `prepare_enemy_sound_banks_until_complete_then_commit_tq_tsb_candidate` | Confirmed reviewed state machine and synchronous wrapper | Enqueues sound command4A(slotC) via1ACEA0, resets preparation1B8360, repeatedly calls1B8380(config) until result!=0. No yield/timeout in this outer loop. Negative result skips commit; otherwise calls1AD150(base32440C,base+4000,C). State-machine file work and SDR completion are separate; no measured wait duration. |
| [0x1D3DC0](../recomp/config/output/sub_001D3DC0_0x1d3dc0.cpp) | `read_named_snd_file_wait_for_cri_completion_and_install_sound_bank_candidate` | Confirmed `.snd` suffix and SDK boundaries | Copies name and appends owned`.snd`;1AB310 lookup<0 skips. Creates CRI file object129240(3,id), reads reported129C08 size through1297A0 into32440C, polls129D48 until exact state3 without timeout/error exit, closes129350, calls synchronous1AC730(buffer,slot). No local name/buffer-capacity check or guaranteed progress. Does not establish how active native overrides implement the wait. |
| [0x1D3E90](../recomp/config/output/sub_001D3E90_0x1d3e90.cpp) | `load_scenario_evb_script_and_route_present_or_absent_initialization_candidate` | Confirmed owned path; event initializer details partial | `data/rom/scene/script/r%03d.evb` into324424, or short archive name when3243D7!=0. Normal positive result calls68C260, else68C1A0; alternate uses nonzero rather than positive. No local EVB parsing or extent validation. |
| [0x1D3F60](../recomp/config/output/sub_001D3F60_0x1d3f60.cpp) | `load_single_mode_navigation_resource_and_initialize_owned_overlay_consumers_candidate` | Confirmed filename and reviewed o9 consumers | Only1B02D0(modezero)!=0; reads `data/rom/scene/single/r%03d.sgl` or short archive name to843780. Nonpositive result clears destination word0; positive calls o9 8163F0(relocate records) and815E70(2,bind navigation). Overlay address identity remains distinct from main. No game/pathfinding run. |
| [0x1D4020](../recomp/config/output/sub_001D4020_0x1d4020.cpp) | `load_scenario_message_binary_with_optional_u_variant_candidate` | Confirmed owned filename selection | Destination32443C; flag3243FD chooses `r%03d.bin` or `r%03du.bin` under `data/rom/scene/message`, or short archive names. Both source modes require positive result, otherwise zero destination first word. Does not parse or render messages. |
| [0x1BA420](../recomp/config/output/sub_001BA420_0x1ba420.cpp) | `install_room_sound_section_as_bank_slot_three_candidate` | Confirmed owned callback row and adapter | Tail-routes1AC730(section,3). Actual owned dispatch row236800 selects room section2. |
| [0x1BA430](../recomp/config/output/sub_001BA430_0x1ba430.cpp) | `install_room_sound_section_as_bank_slot_two_candidate` | Confirmed owned callback row and adapter | Tail-routes1AC730(section,2); owned dispatch row236810 selects room section3. |

Numeric offsets/sizes/slots are hexadecimal unless explicitly stated. The six-slot motion bank base is **4BEC30** (4C0000-13D0), independent from the four-slot enemy cache. Its byte1 admission tests a header byte; it is not independently proven to be an allocated flag. Runtime filename-pointer/descriptor contents were not read or invented.

Owned236800 rows are `(callback, section, scratch, operation)`:

| Callback | Section | Scratch | Operation |
| --- | --- | --- | --- |
|1BA420|2|0|0|
|1BA430|3|0|0|
|5BE3E0|0|0|0|
|6B1EC0|B|0|0|
|662C90|7|0|0|
|6847E0|4|0|0|
|6B23E0|D|0|0|
|68C570|1|0|0|
|5C1390|A|0|0|
|6AD860|E|0|0|
|633600|F|0|0|
|573DE0|10|0|0|
|0|63|63|3E7 (terminator)|

This establishes original room resource setup and blocking sound installation boundaries. It does not establish that a synchronous call occurred during an incident or that changing it would fix gameplay/cutscene lag. Any later asynchronous rewrite needs source-buffer lifetime, bank slot ownership, command completion and caller state evidence.

Related: [model/texture cache lifecycle](SYMBOLS_MODEL_TEXTURE_CACHE_LIFECYCLE.md), [motion bank construction](SYMBOLS_MOTION_BANK_CONSTRUCTION.md), [sound bank preparation](SYMBOLS_AUDIO_SETTINGS_BANK_FLOW.md), [CRI/file loading](SYMBOLS_CRI_BACKENDS.md), [central index](FUNCTION_INDEX.md).
