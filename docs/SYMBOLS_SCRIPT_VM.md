# Gameplay script VM and verified overlay dispatch tables

Static research, 2026-11-03. No target execution, build, replay, debugger attachment or live memory read. Addresses remain original; labels are research annotations.

## Owned image provenance

The imported File #1 main ELF matches SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Imported `BIN/2.DAT` matches its import manifest: SHA-256 `22510ef160322f977ff070feae029a247844316c87928fcbac29aaa771a2fb29`. Offline decompression yields MWo3 id **3**, base **0x570000**, 1,913,088 bytes, SHA-256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. All **387,193** indexed o2 instruction comments match the decoded bytes, with **zero conflicts**. This establishes the image-to-source relationship for these tables; no original assets are committed. Local provenance lives in ignored `build-function-index/owned-overlays`.

The earlier notebooks accurately described their then-unverified table data. The tables below now supply independently checked numeric slots. `o2` is catalogue partition 2, runtime image id 3 for this owned file.

## VM execution contract

Existing mapped dispatcher 0x68C660 uses current pointer array **0x4BACE0**, countdown **0x4BACF8**, block index **0x4BAD10**, saved pointer **0x4BAD28**, block-table pointer **0x4BAD40**, condition ordinal **0x4BAD58**; selected slot byte is **0x4BADC1**. Opcode is the low **24 bits**, not necessarily an 8-bit value. The owned image contains **432 contiguous handler words** (opcodes 000..1AF). At 1B0 the next word is 00040404, not an indexed code entry. This data boundary is a strong table-extent candidate, not a runtime bounds guarantee. The condition-opener list independently contains opcodes above FF. Dispatcher has **no local bounds check**.

Header high byte determines record span `4 * (1 << exponent)` with guest variable-shift rules. Return 2 reloads current record and re-enters dispatch, return 1 continues without automatic pointer advance, return zero advances then continues. Opcodes 0A/0D instead yield after their handler. A nonzero per-slot countdown decrements and returns on subsequent calls. None of this proves a millisecond timeout or a safe host interpreter replacement.

The condition-failure helper walks bytecode and nested markers rather than sleeping. This is a candidate investigation boundary for scripts that stop progressing, **not a measured culprit for the player's slowdown**.

## Reviewed entries

Confidence is **Confirmed/static** for the stated loads/stores/control flow and verified opcode assignment; semantic labels marked candidate remain **Probable**. Original SDK/game symbol names are not claimed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x66B8E0](../recomp/config/output_ovl/o2/o2_0066B8E0_0x66b8e0.cpp) | `actor_enter_action_one_and_run_substate` | Confirmed/static mechanics | Increments action +8, writes active byte +1=1, calls 0x61A620, sets +BA4 bit 0x08000000, clears +BD0 only for category +2==0, reports actor id through 0x1AFF90, then executes 0x66B960. |
| [o2 0x66B950](../recomp/config/output_ovl/o2/o2_0066B950_0x66b950.cpp) | `actor_dispatch_noop` | Confirmed/static mechanics | JR ra with no body; reused by both action dispatch tables. This slot does not advance actor state. |
| [o2 0x66B960](../recomp/config/output_ovl/o2/o2_0066B960_0x66b960.cpp) | `actor_action_one_substate_dispatch` | Confirmed/static mechanics | Clears +BA0 bit 0x200, indexes 0x712C50 by unsigned actor +9, jumps to the selected block. No local range check. Initial block 0x66B990 clears movement vector +C0..C8 and saved position, drives 0x5D4CF0/0x58C300; gameplay names of subsequent states remain under review. |
| [o2 0x64AF50](../recomp/config/output_ovl/o2/o2_0064AF50_0x64af50.cpp) | `actor_action_one_primary_substate_dispatch` | Confirmed/static mechanics | Skips dispatch if +BA4 bit 4 is set; otherwise indexes 0x711A10 using unsigned actor +9 and calls the selected function. No local bounds check. |
| 0x68C7B0 [existing mapped source](../recomp/config/output_ovl/o2/o2_0068C7B0_0x68c7b0.cpp) | `script_tick_eight_flag_timers` | Confirmed/static mechanics | Visits eight signed halfword countdowns at 0x4BAD88. Only positive values decrement. On reaching zero, paired halfword at 0x4BAD98 selects 0x5705F0 when bit 0x8000 set, else 0x5703E0, with low 15 bits as id. This is per caller tick, not proven wall time. |
| [o2 0x68C950](../recomp/config/output_ovl/o2/o2_0068C950_0x68c950.cpp) | `script_skip_encoded_records` | Confirmed/static mechanics | Advances pointer a0 across unsigned count a1 records; record header high byte controls byte span 4*(1 << exponent), with guest variable-shift semantics. Count zero returns original pointer. No bytecode bounds or opcode validation. |
| [o2 0x68C9E0](../recomp/config/output_ovl/o2/o2_0068C9E0_0x68c9e0.cpp) | `script_skip_failed_condition_group_candidate` | Probable semantic role; mechanics verified | Uses selected script slot byte 0x4BADC1, advances current record by header exponent; updates nesting through 0x68C990 and slot+0x78. Handles marker opcodes E4/E5 and 0A/0D to find condition boundaries. This walks records, not a timed sleep; malformed streams may prevent termination. |
| 0x68CD80 [existing mapped source](../recomp/config/output_ovl/o2/o2_0068CD80_0x68cd80.cpp) | `script_op_default_advance` | Confirmed/static mechanics | Default handler for 220 of the 432 observed opcode slots, returns zero without writes. Dispatcher then advances by encoded record span; zero is not a general whole-script abort. |
| [o2 0x68CD90](../recomp/config/output_ovl/o2/o2_0068CD90_0x68cd90.cpp) | `script_op_save_next_record_and_yield` | Confirmed/static mechanics | Opcode 01: computes next record from current header high byte and stores in per-slot 0x4BAD28, returns zero. Dispatcher also advances current instruction. Saved pointer is subsequently used by 02 and 0A. |
| [o2 0x68CDF0](../recomp/config/output_ovl/o2/o2_0068CDF0_0x68cdf0.cpp) | `script_op_restore_saved_record_continue` | Confirmed/static mechanics | Opcode 02: copies saved per-slot pointer at 0x4BAD28 to current pointer 0x4BACE0, returns 1. Distinct numeric opcode from otherwise identical handler 0A. |
| [o2 0x68CE30](../recomp/config/output_ovl/o2/o2_0068CE30_0x68ce30.cpp) | `script_op_skip_record_count` | Confirmed/static mechanics | Opcode 03: passes current record and first payload word count to 0x68C950, installs returned pointer, returns 1. |
| [o2 0x68CE90](../recomp/config/output_ovl/o2/o2_0068CE90_0x68ce90.cpp) | `script_op_set_tick_delay` | Confirmed/static mechanics | Opcode 04: writes first payload word to per-slot countdown 0x4BACF8, returns zero. The dispatcher reenters its countdown check after advancing this opcode, so the first decrement occurs in the same invocation; no clock conversion or sleep here. |
| [o2 0x68CEC0](../recomp/config/output_ovl/o2/o2_0068CEC0_0x68cec0.cpp) | `script_op_arm_selected_actor_event_slot_candidate` | Probable semantic role; mechanics verified | Opcode 05: selected actor id at 0x4BADED chooses 16-byte bank. If bank active byte at 0x4BAC94+16*id+payload[0] is zero, sets it to 1, stores payload byte +8 in parallel byte bank +4, halfword payload +4 in bank +8. Returns zero; no local slot bound. |
| [o2 0x68CF40](../recomp/config/output_ovl/o2/o2_0068CF40_0x68cf40.cpp) | `script_op_clear_selected_actor_event_slot_candidate` | Probable semantic role; mechanics verified | Opcode 06: clears active byte in 0x4BAC94 bank using selected actor stride 16 and first payload word as offset. No local range check; returns zero. |
| [o2 0x68CF70](../recomp/config/output_ovl/o2/o2_0068CF70_0x68cf70.cpp) | `script_op_next_block_pointer` | Confirmed/static mechanics | Opcode 07: increments per-slot block index at 0x4BAD10 and reads indexed word from table pointer 0x4BAD40 into current instruction pointer; returns 1. |
| [o2 0x68CFE0](../recomp/config/output_ovl/o2/o2_0068CFE0_0x68cfe0.cpp) | `script_op_condition_global_flag` | Confirmed/static mechanics | Opcode 08: increments condition ordinal at 0x4BAD58; tests bit id payload +0 in word array 0x4B9C00, desired set/clear from signed byte payload +4. On mismatch calls 0x68C9E0 and returns 2, else zero. |
| 0x68D0B0 [existing mapped source](../recomp/config/output_ovl/o2/o2_0068D0B0_0x68d0b0.cpp) | `script_op_restore_saved_record_boundary` | Confirmed/static mechanics | Opcode 0A: copies 0x4BAD28 slot pointer to 0x4BACE0 and returns 1. Dispatcher explicitly yields on opcode 0A after the call; unlike opcode 02. |
| [o2 0x68D0F0](../recomp/config/output_ovl/o2/o2_0068D0F0_0x68d0f0.cpp) | `script_op_set_or_clear_flag_bank` | Confirmed/static mechanics | Opcode 0B: payload word 0 selects external flag mutators 0x5703E0 / 0x570450 or local bit bank 0x4B9A80 for selector 1. Payload word +4 is bit id, byte +8 set/clear. Returns zero. |
| [o2 0x68D1B0](../recomp/config/output_ovl/o2/o2_0068D1B0_0x68d1b0.cpp) | `script_op_set_or_clear_two_flag_banks` | Confirmed/static mechanics | Opcode 0C: payload first word zero selects 0x4B9C40, nonzero selects 0x4B9B40. Payload +4 is bit id, word +8 nonzero sets and zero clears; returns zero. |
| 0x68D2A0 [existing mapped source](../recomp/config/output_ovl/o2/o2_0068D2A0_0x68d2a0.cpp) | `script_op_next_block_pointer_boundary` | Confirmed/static mechanics | Opcode 0D: same block-index advance and table lookup as opcode 07, returns 1. Dispatcher explicitly yields on 0D rather than immediately executing the next command. |
| [o2 0x68D310](../recomp/config/output_ovl/o2/o2_0068D310_0x68d310.cpp) | `script_op_enable_sequence_record_candidate` | Probable semantic role; mechanics verified | Opcode 10: writes byte 1 to 0x3DDDE4+0x198*payload_word0; returns zero. Record type inferred from shared sequence-control family, not proven original name. |
| [o2 0x68D350](../recomp/config/output_ovl/o2/o2_0068D350_0x68d350.cpp) | `script_op_disable_sequence_record_candidate` | Probable semantic role; mechanics verified | Opcode 11: writes byte zero to 0x3DDDE4+0x198*payload_word0; returns zero. |
| [o2 0x68D380](../recomp/config/output_ovl/o2/o2_0068D380_0x68d380.cpp) | `script_op_enable_all_sequence_records_candidate` | Probable semantic role; mechanics verified | Opcode 12: loops signed byte count at 0x3DDDB1, writes +0x34=1 for stride 0x198 records from 0x3DDDB0. No iterations for nonpositive count. |
| [o2 0x68D3D0](../recomp/config/output_ovl/o2/o2_0068D3D0_0x68d3d0.cpp) | `script_op_sequence_parameter_adapter_candidate` | Probable semantic role; mechanics verified | Opcode 13: unsigned payload byte 0 and unsigned halfword +4 are passed to 0x5BF0F0; returns zero. |
| [o2 0x68D400](../recomp/config/output_ovl/o2/o2_0068D400_0x68d400.cpp) | `script_op_disable_current_sequence_if_id_matches_candidate` | Probable semantic role; mechanics verified | Opcode 15: compares payload byte with current id 0x3DDDB5; on match clears halfword 0x3DDDB6 and corresponding record active byte 0x3DDDE4+0x198*id. |
| [o2 0x68D450](../recomp/config/output_ovl/o2/o2_0068D450_0x68d450.cpp) | `script_op_condition_sequence_state_four_candidate` | Probable semantic role; mechanics verified | Opcode 14: increments condition ordinal; payload word zero requires byte 0x3DDDD5 equal 4; nonzero requires it differ from 4. Mismatch invokes condition-group skip and returns 2. |
| [o2 0x68D4E0](../recomp/config/output_ovl/o2/o2_0068D4E0_0x68d4e0.cpp) | `script_op_sequence_percent_parameter_adapter_candidate` | Probable semantic role; mechanics verified | Opcode 16: converts unsigned payload word +C to float and divides by 100; passes signed halfwords +4/+8 and unsigned byte 0 to 0x5BF1B0; returns zero. Units beyond percent-scale unknown. |
| [o2 0x68D550](../recomp/config/output_ovl/o2/o2_0068D550_0x68d550.cpp) | `script_op_condition_sequence_id_candidate` | Probable semantic role; mechanics verified | Opcode 17: increments condition ordinal, compares 0x3DDDB3 with payload word 0; payload word +4==1 requires equality, zero requires inequality; all other desired values fail. Mismatch skips group and returns 2. |
| [o2 0x68D5D0](../recomp/config/output_ovl/o2/o2_0068D5D0_0x68d5d0.cpp) | `script_op_select_effect_bank_candidate` | Probable semantic role; mechanics verified | Opcode 20: Passes unsigned payload byte to 0x6B1FE0 then returns zero. Callee selects one of four nonempty banks, not an enable flag. |
| [o2 0x68D5F0](../recomp/config/output_ovl/o2/o2_0068D5F0_0x68d5f0.cpp) | `script_op_create_effect_instance_candidate` | Probable semantic role; mechanics verified | Opcode 23: Passes unsigned payload byte to 0x6B2020 then returns zero. Callee removes old instance, creates replacement and sets bank mask bit. |
| [o2 0x68D610](../recomp/config/output_ovl/o2/o2_0068D610_0x68d610.cpp) | `script_op_remove_effect_instance_candidate` | Probable semantic role; mechanics verified | Opcode 24: Unsigned payload byte forwarded to 0x6B2170; returns zero. Callee removes registered instance and clears bank mask bit. |
| [o2 0x68D630](../recomp/config/output_ovl/o2/o2_0068D630_0x68d630.cpp) | `script_op_create_32_effect_instances_candidate` | Probable semantic role; mechanics verified | Opcode 25: Calls 0x6B2020 for each index 0 through 31; returns zero. Ignores payload. |
| [o2 0x68D670](../recomp/config/output_ovl/o2/o2_0068D670_0x68d670.cpp) | `script_op_entity_enable_adapter_candidate` | Probable semantic role; mechanics verified | Opcode 30: signed payload halfword forwarded to 0x592960; returns zero. Pair/family role inferred, target name not established. |
| [o2 0x68D690](../recomp/config/output_ovl/o2/o2_0068D690_0x68d690.cpp) | `script_op_entity_disable_adapter_candidate` | Probable semantic role; mechanics verified | Opcode 31: signed payload halfword forwarded to 0x592A10; returns zero. |
| [o2 0x68D6B0](../recomp/config/output_ovl/o2/o2_0068D6B0_0x68d6b0.cpp) | `script_op_entity_reset_adapter_candidate` | Probable semantic role; mechanics verified | Opcode 32: signed payload halfword forwarded to 0x592B00; returns zero. |
| [o2 0x68D6D0](../recomp/config/output_ovl/o2/o2_0068D6D0_0x68d6d0.cpp) | `script_op_entity_update_adapter_candidate` | Probable semantic role; mechanics verified | Opcode 33: signed payload halfword forwarded to 0x592B90; inspect target before treating this as destroy or hide. |
| [o2 0x68D6F0](../recomp/config/output_ovl/o2/o2_0068D6F0_0x68d6f0.cpp) | `script_op_condition_entity_status_candidate` | Probable semantic role; mechanics verified | Opcode 34: increments condition ordinal, calls 0x592C20(signed payload halfword), sign-extends low return byte. Zero result skips condition group and returns 2; nonzero returns zero. |
| [o2 0x68D760](../recomp/config/output_ovl/o2/o2_0068D760_0x68d760.cpp) | `script_op_entity_parameter_adapter_candidate` | Probable semantic role; mechanics verified | Opcode 35: signed payload halfword forwarded to 0x592CA0; returns zero. |
| [o2 0x68D780](../recomp/config/output_ovl/o2/o2_0068D780_0x68d780.cpp) | `script_op_condition_entity_halfword_compare` | Confirmed/static mechanics | Opcode 36: resolves payload signed id via 0x5B4A50. Missing/inactive record fails; otherwise compares record signed halfword +24 to payload signed +4 using six-case operator payload +8, table 0x740890. Failed comparison skips condition group and returns 2. |
| [o2 0x68D8F0](../recomp/config/output_ovl/o2/o2_0068D8F0_0x68d8f0.cpp) | `script_op_entity_signed_byte_parameter_candidate` | Probable semantic role; mechanics verified | Opcode 37: passes signed halfword payload 0 and signed byte +4 to 0x592D50; returns zero. |
| [o2 0x68D920](../recomp/config/output_ovl/o2/o2_0068D920_0x68d920.cpp) | `script_op_attach_resource_to_actor_candidate` | Probable semantic role; mechanics verified | Opcode 38: nonnegative actor/resource ids and helper 0x592A90 required. Active actor 0x4A5C30+0x10E0*id receives returned record byte +2 in first free resource slot: +C88..CA7 for resource 400..420 inclusive, else +C84..C87. No free slot means no store. |
| [o2 0x68DA50](../recomp/config/output_ovl/o2/o2_0068DA50_0x68da50.cpp) | `script_op_attach_resource_to_actor_type_candidate` | Probable semantic role; mechanics verified | Opcode 39: scans active actors with +B98 matching signed payload type; resolves resource per actor through 0x592A90. First free slot receives returned byte +2, same 32-vs-4 split as 38. Returns after first store, rather than attaching to every matching actor. |
| [o2 0x68DBA0](../recomp/config/output_ovl/o2/o2_0068DBA0_0x68dba0.cpp) | `script_op_attach_resource_to_object_candidate` | Probable semantic role; mechanics verified | Opcode 3A: resolves resource with id argument object+4 through 0x592A90, scans 64 active 0x78-byte objects at 0x390210 for object halfword +4 match, fills first free byte among +4C..4F. |
| [o2 0x68DC70](../recomp/config/output_ovl/o2/o2_0068DC70_0x68dc70.cpp) | `script_op_select_actor_resource_by_id_candidate` | Probable semantic role; mechanics verified | Opcode 3B: selects active actor by payload byte; scans 32 or 4 resource indices, resolves each via 60-byte table 0x3C5630, matches halfword +6 against payload resource id, invokes 0x666DE0(actor) at first match. Exact selection mutation requires callee review. |
| [o2 0x68DDB0](../recomp/config/output_ovl/o2/o2_0068DDB0_0x68ddb0.cpp) | `script_op_select_actor_type_resource_candidate` | Probable semantic role; mechanics verified | Opcode 3C: scans active actors by +B98 type and attached resources via 0x3C5630; first matching resource id invokes 0x666DE0(actor), then returns. |
| [o2 0x68DF10](../recomp/config/output_ovl/o2/o2_0068DF10_0x68df10.cpp) | `script_op_select_object_resource_candidate` | Probable semantic role; mechanics verified | Opcode 3D: scans 64 active objects at 0x390210, matches object id +4, scans four resource indices +4C..4F and matches resource table +6; copies selected resource index to object +50. |
| [o2 0x68DFD0](../recomp/config/output_ovl/o2/o2_0068DFD0_0x68dfd0.cpp) | `script_op_set_matching_resource_triplet_mode_one` | Confirmed/static mechanics | Opcode 3E: unless global signed halfword 0x3B5150 equals 0x80, walks linked list from 0x3B5160 through +28. Matches node type +30==0x80 and resource table +4/+3. Writes mode +44=1 and payload halfwords +4/+8/+C into +46/+48/+4A at first match. |
| [o2 0x68E070](../recomp/config/output_ovl/o2/o2_0068E070_0x68e070.cpp) | `script_op_set_matching_resource_triplet_mode_two` | Confirmed/static mechanics | Opcode 3F: same linked-list/resource search as 3E, but writes mode +44=2; first matching eligible node only. |
| [o2 0x6B1FE0](../recomp/config/output_ovl/o2/o2_006B1FE0_0x6b1fe0.cpp) | `select_nonempty_effect_bank_candidate` | Probable semantic role; mechanics verified | Low byte of input must be below 4; chooses 0x3DC1E0 + index*0x6F4, requires nonzero leading halfword, then stores selection byte to 0x3240BE. Does not create an instance. |
| [o2 0x6B2020](../recomp/config/output_ovl/o2/o2_006B2020_0x6b2020.cpp) | `create_effect_from_selected_bank_entry_candidate` | Probable semantic role; mechanics verified | Requires selected bank id >=0 and bank leading halfword nonzero, entry stride 0x34 and radius/scalar +9C>0. Calls 0x6B2170 to remove previous entry; copies template 0x34 bytes to stack, invokes 0x6B3090, stores returned instance in 0x7474B0[index], sets bank mask +6F0 bit. No local entry<32 check; does not check nonzero create result before setting mask. |
| [o2 0x6B2170](../recomp/config/output_ovl/o2/o2_006B2170_0x6b2170.cpp) | `remove_registered_effect_instance_candidate` | Probable semantic role; mechanics verified | Looks up 0x7474B0[low input byte], calls 0x6B3020 when nonzero, then clears selected bank +6F0 bit. Does not clear the instance-array word in this body; negative bank selection is not rejected locally. |
| [o2 0x592960](../recomp/config/output_ovl/o2/o2_00592960_0x592960.cpp) | `enable_resource_and_lazy_create_candidate` | Probable semantic role; mechanics verified | Resolves id via 0x592900; requires resource active byte +0 and eligible +3. Sets flags +18 bit 1 and clears 0x200000. Construction is skipped only when both +1C/+20 pointers are nonzero. Otherwise matching room byte +1 and +28==0 call 0x591620. |
| [o2 0x592A10](../recomp/config/output_ovl/o2/o2_00592A10_0x592a10.cpp) | `disable_resource_and_release_live_object_candidate` | Probable semantic role; mechanics verified | For resolved active/eligible resource clears +18 bits 1 and 0x200000. When +1C or +20 is nonzero calls 0x5B1850(resource byte +2). No whole-record zeroing. |
| [o2 0x592B00](../recomp/config/output_ovl/o2/o2_00592B00_0x592b00.cpp) | `enable_resource_forced_mode_candidate` | Probable semantic role; mechanics verified | Sets resolved eligible resource flags +18 mask 0x200001; if room matches and +28==0 calls 0x591620, without the both-pointer-present exclusion used by 0x592960. |
| [o2 0x592B90](../recomp/config/output_ovl/o2/o2_00592B90_0x592b90.cpp) | `enable_resource_alternate_create_candidate` | Probable semantic role; mechanics verified | Sets flag 1 and clears 0x200000; matching room and +28==0 invokes 0x591860. Its alternate constructor distinguishes it from 0x592960. |
| [o2 0x592C20](../recomp/config/output_ovl/o2/o2_00592C20_0x592c20.cpp) | `resource_inactive_or_flag29_predicate` | Confirmed/static mechanics | Missing record returns 0. Active record with +3==0 returns 1; active record with +3!=0 returns 0. Inactive record returns whether flags +18 bit 0x20000000 is set. This is not simply is-loaded. |
| [o2 0x592CA0](../recomp/config/output_ovl/o2/o2_00592CA0_0x592ca0.cpp) | `detach_actor_resource_and_release_candidate` | Probable semantic role; mechanics verified | Resolves id and owner via 0x5B4A50. Releases live +1C object when present; resolves actor from owner<4 or 0x682F80(owner-4), calls 0x5F2180/0x5F2330 then 0x591BE0. Destructive resource lifecycle role, not a passive parameter getter. |
| [o2 0x592D50](../recomp/config/output_ovl/o2/o2_00592D50_0x592d50.cpp) | `set_resource_and_live_object_flag_800` | Confirmed/static mechanics | Resolves active/eligible resource, sets or clears flags +18 bit 0x800 from a1. If live pointer +1C nonzero mirrors flag at live object +23C. |
| [o2 0x666DE0](../recomp/config/output_ovl/o2/o2_00666DE0_0x666de0.cpp) | `select_actor_attached_resource_candidate` | Probable semantic role; mechanics verified | Requires nonzero resource index a1 and 0x5B43F0 eligibility for resource byte +2. Stores low index to actor +C7C, writes resource ownership halfword +28 using actor category/id, calls 0x5B18D0, recalculates actor halfword +CA8 through 0x5F1F70. Resource argument is a1; actor alone insufficient. |
| [o2 0x68E110](../recomp/config/output_ovl/o2/o2_0068E110_0x68e110.cpp) | `script_op_flag_bank_call_570670` | Confirmed/static mechanics | Opcode 40: payload words 0/+4 forwarded to 0x570670 with a2=0; returns zero. Target flag-bank semantics need separate review. |
| [o2 0x68E140](../recomp/config/output_ovl/o2/o2_0068E140_0x68e140.cpp) | `script_op_flag_bank_call_570620` | Confirmed/static mechanics | Opcode 41: payload words 0/+4 forwarded to 0x570620 with a2=0; returns zero. |
| [o2 0x68E170](../recomp/config/output_ovl/o2/o2_0068E170_0x68e170.cpp) | `script_op_flag_bank_call_5706b0` | Confirmed/static mechanics | Opcode 42: payload words 0/+4 forwarded to 0x5706B0 with a2=0; returns zero. |
| [o2 0x68E1A0](../recomp/config/output_ovl/o2/o2_0068E1A0_0x68e1a0.cpp) | `script_op_flag_bank_call_570700` | Confirmed/static mechanics | Opcode 43: payload words 0/+4 forwarded to 0x570700 with a2=0; returns zero. |
| [o2 0x68E1D0](../recomp/config/output_ovl/o2/o2_0068E1D0_0x68e1d0.cpp) | `script_op_flag_value_adapter_candidate` | Probable semantic role; mechanics verified | Opcode 44: payload word 0 forwarded to 0x570970; returns zero. |
| [o2 0x68E1F0](../recomp/config/output_ovl/o2/o2_0068E1F0_0x68e1f0.cpp) | `script_op_arm_flag_timer` | Confirmed/static mechanics | Opcode 45: unsigned payload word +8 must be <8. Stores low halfword payload +4, optionally OR 0x8000 according to word 0, at 0x4BAD98+2*index; low halfword +C stored countdown 0x4BAD88+2*index. Tick worker 0x68C7B0 triggers only initially positive countdowns. |
| [o2 0x68E250](../recomp/config/output_ovl/o2/o2_0068E250_0x68e250.cpp) | `script_op_three_argument_message_adapter_candidate` | Probable semantic role; mechanics verified | Opcode 46: forwards payload word 0, unsigned byte +4, word +8 to 0x680220; returns zero. Exact protocol role unresolved. |
| [o2 0x68E280](../recomp/config/output_ovl/o2/o2_0068E280_0x68e280.cpp) | `script_op_condition_predicate_nonzero` | Confirmed/static mechanics | Opcode 47: increments condition ordinal. For payload +4 nonzero requires 0x680850(payload word0) zero; zero requires nonzero. Failed condition skips group and returns 2. |
| [o2 0x68E310](../recomp/config/output_ovl/o2/o2_0068E310_0x68e310.cpp) | `script_op_condition_predicate_equals_one` | Confirmed/static mechanics | Opcode 48: like 47 but specifically compares return to 1. Other nonzero values differ from true in opcode 47. |
| [o2 0x68E3A0](../recomp/config/output_ovl/o2/o2_0068E3A0_0x68e3a0.cpp) | `script_op_condition_byte_flag_bank` | Confirmed/static mechanics | Opcode 49: increments condition ordinal, tests bit payload word0 in byte bank 0x4B9C80. Payload word +4 selects required set/clear; failure skips group and returns 2. |
| [o2 0x68E460](../recomp/config/output_ovl/o2/o2_0068E460_0x68e460.cpp) | `script_op_set_linked_render_record_packed_parameter_candidate` | Probable semantic role; mechanics verified | Opcode 4A: walks linked list 0x3B5160 unless count sentinel 0x80. All nodes matching id +40 and type +30 0 or 2 receive packed halfword (payload +4<<12)\|payload +8 at +74 and byte 1 at +73 or +72. Does not stop at first match; naming render role provisional. |
| [o2 0x68E500](../recomp/config/output_ovl/o2/o2_0068E500_0x68e500.cpp) | `script_op_set_type_one_packed_parameter` | Confirmed/static mechanics | Opcode 4B: same list/sentinel, matches type +30==1 and id +40; sets +88 byte 1 and +84 packed halfword for every matching node. |
| [o2 0x68E570](../recomp/config/output_ovl/o2/o2_0068E570_0x68e570.cpp) | `script_op_flag_value_adapter_5709e0` | Confirmed/static mechanics | Opcode 4C: payload word 0 forwarded to 0x5709E0, returns zero. |
| [o2 0x68E590](../recomp/config/output_ovl/o2/o2_0068E590_0x68e590.cpp) | `script_op_condition_halfword_mask` | Confirmed/static mechanics | Opcode 4D: increments condition ordinal; tests 0x4BAC50 halfword against guest variable-shift mask 1<<payload word0, required set/clear from payload +4. Failure skips group and returns 2; out-of-range ids not checked locally. |
| [o2 0x68E630](../recomp/config/output_ovl/o2/o2_0068E630_0x68e630.cpp) | `script_op_set_type_zero_two_word6c` | Confirmed/static mechanics | Opcode 50: Walks list 0x3B5160 with sentinel 0x3B5150 !=0x80. Matching id +40, type 0: writes payload +4 to +6C and clears +72. Type 2 additionally requires node +50==payload +8, writes +6C. All matches visited. |
| [o2 0x68E6D0](../recomp/config/output_ovl/o2/o2_0068E6D0_0x68e6d0.cpp) | `script_op_set_type_one_halfword86` | Confirmed/static mechanics | Opcode 51: Same list/sentinel. Matching type 1 and id +40 receive low halfword payload +4 at node +86. |
| [o2 0x68E730](../recomp/config/output_ovl/o2/o2_0068E730_0x68e730.cpp) | `script_op_enable_type_three_four_even_modes` | Confirmed/static mechanics | Opcode 52: For matching id: type 3 with +44 in {0,2} sets +3C=1 and, only mode 2, sets +58 from payload halfword +4. Type 4 with +64==0 sets +3C=1. All matching nodes. |
| [o2 0x68E800](../recomp/config/output_ovl/o2/o2_0068E800_0x68e800.cpp) | `script_op_disable_type_three_four_even_modes` | Confirmed/static mechanics | Opcode 53: Inverse +3C=0 for type 3 modes {0,2} or type 4 +64==0, matching id. Does not call a destructor. |
| [o2 0x68E8B0](../recomp/config/output_ovl/o2/o2_0068E8B0_0x68e8b0.cpp) | `script_op_set_type_zero_word_and_byte` | Confirmed/static mechanics | Opcode 54: Matches type 0/id in linked list; writes payload word +4 to +6C and byte +8 to +72. |
| [o2 0x68E920](../recomp/config/output_ovl/o2/o2_0068E920_0x68e920.cpp) | `script_op_restart_type_five_parameters_candidate` | Probable semantic role; mechanics verified | Opcode 55: For every type 5/id match calls 0x5C45C0, writes +3C=1, payload halfwords to +50/+6A, clears +6C halfword, sets +74 word=-1. Exact visual subsystem unknown. |
| [o2 0x68E9E0](../recomp/config/output_ovl/o2/o2_0068E9E0_0x68e9e0.cpp) | `script_op_reset_type_five_candidate` | Probable semantic role; mechanics verified | Opcode 56: For every type 5/id match calls 0x5C45C0; no additional parameter writes in this handler. |
| [o2 0x68EA70](../recomp/config/output_ovl/o2/o2_0068EA70_0x68ea70.cpp) | `script_op_restart_type_five_byte_parameter_candidate` | Probable semantic role; mechanics verified | Opcode 57: For every type 5/id match calls 0x5C45C0, writes +3C=1, halfword payload +4 to +50, byte +8 to +58, halfword +C to +56. |
| [o2 0x68EB30](../recomp/config/output_ovl/o2/o2_0068EB30_0x68eb30.cpp) | `script_op_enable_type_three_four_odd_modes` | Confirmed/static mechanics | Opcode 58: For matching id: type 3 mode +44 in {1,3} sets +3C=1; only mode 3 writes halfword +58 from payload +4. Type 4 +64==1 sets +3C=1. |
| [o2 0x68EBF0](../recomp/config/output_ovl/o2/o2_0068EBF0_0x68ebf0.cpp) | `script_op_disable_type_three_four_odd_modes` | Confirmed/static mechanics | Opcode 59: For matching id sets +3C=0 on type 3 modes {1,3} or type 4 +64==1. All matches visited. |
| [o2 0x68ECA0](../recomp/config/output_ovl/o2/o2_0068ECA0_0x68eca0.cpp) | `script_op_store_indexed_byte_4b9d20` | Confirmed/static mechanics | Opcode 5A: Writes low byte of payload word +4 at 0x4B9D20+payload word0. No local index or capacity check. |
| [o2 0x68ECC0](../recomp/config/output_ovl/o2/o2_0068ECC0_0x68ecc0.cpp) | `script_op_enable_type_one_record` | Confirmed/static mechanics | Opcode 5B: Sets +3C=1 on all linked type 1 records with +40==payload id. Shared list and sentinel as opcode 50. |
| [o2 0x68ED30](../recomp/config/output_ovl/o2/o2_0068ED30_0x68ed30.cpp) | `script_op_disable_type_one_record` | Confirmed/static mechanics | Opcode 5C: Sets +3C=0 on all matching linked type 1 records. No deallocation in handler. |
| [o2 0x68EDA0](../recomp/config/output_ovl/o2/o2_0068EDA0_0x68eda0.cpp) | `script_op_enable_type_zero_two_record` | Confirmed/static mechanics | Opcode 5D: Sets +3C=1 for all linked type 0 or 2 records with matching id +40. |
| [o2 0x68EE30](../recomp/config/output_ovl/o2/o2_0068EE30_0x68ee30.cpp) | `script_op_disable_type_zero_two_record` | Confirmed/static mechanics | Opcode 5E: Sets +3C=0 for all linked type 0 or 2 records with matching id +40. |
| [o2 0x68EEC0](../recomp/config/output_ovl/o2/o2_0068EEC0_0x68eec0.cpp) | `script_op_set_type_zero_two_halfword68` | Confirmed/static mechanics | Opcode 5F: Stores payload halfword +4 to +68 in all matching linked type 0 or 2 records. |
| [o2 0x68EF50](../recomp/config/output_ovl/o2/o2_0068EF50_0x68ef50.cpp) | `script_op_selected_actor_transition_candidate` | Probable semantic role; mechanics verified | Opcode 60: Resolves globally selected actor. If 0x666080(actor,0)==0 writes 1 to bytes 0x4BADF9 and 0x3B84F6, calls 0x669E00(actor). Payload ignored; transition semantics require callees. |
| [o2 0x68EFF0](../recomp/config/output_ovl/o2/o2_0068EFF0_0x68eff0.cpp) | `script_op_actor_control_adapter_6671d0` | Confirmed/static mechanics | Opcode 61: Passes payload word0 to 0x6671D0; returns zero. Control role inferred from adjacent scripted-actor operations. |
| [o2 0x68F010](../recomp/config/output_ovl/o2/o2_0068F010_0x68f010.cpp) | `script_op_enter_scripted_actor_control_candidate` | Probable semantic role; mechanics verified | Opcode 62: Reads selected actor +BA0. Bit 0x80 path may substitute 0x7174D0 payload and set 0x4BAE77; other paths set 0x4BADF8, consider flags 0x120, pack five payload words into halfwords plus three zeroes, call 0x5F0150. Optional 0x6671D0(0), clears 0x4BADC0. Not unconditional control enable. |
| [o2 0x68F140](../recomp/config/output_ovl/o2/o2_0068F140_0x68f140.cpp) | `script_op_select_paired_control_action` | Confirmed/static mechanics | Opcode 63: Payload word0 nonzero calls 0x604300; zero calls 0x604310. Returns zero; exact flag semantics need target review. |
| [o2 0x68F180](../recomp/config/output_ovl/o2/o2_0068F180_0x68f180.cpp) | `script_op_set_all_actor_byte54d` | Confirmed/static mechanics | Opcode 64: Loads actor count as signed word at 0x4BAEA0, loops count records with stride 0x10E0 from 0x4A5C30, writes unsigned payload byte to +54D. Does not require active actor byte. |
| [o2 0x68F1D0](../recomp/config/output_ovl/o2/o2_0068F1D0_0x68f1d0.cpp) | `script_op_store_global_byte_4b9d17` | Confirmed/static mechanics | Opcode 65: Stores low byte payload word0 to 0x4B9D17; returns zero. Field semantics unresolved. |
| [o2 0x68F1F0](../recomp/config/output_ovl/o2/o2_0068F1F0_0x68f1f0.cpp) | `script_op_queue_actor_type_control_triplet_candidate` | Probable semantic role; mechanics verified | Opcode 68: Scans exactly four actors, matches +B98 with payload byte0. Writes triplet {0,payload byte+4,payload byte+8} to 0x4B9D00+3*index; matching actor id +3 equal selected id sets byte 0x4BADC0=1. No active-byte test. |
| [o2 0x68F280](../recomp/config/output_ovl/o2/o2_0068F280_0x68f280.cpp) | `script_op_queue_actor_control_or_position_candidate` | Probable semantic role; mechanics verified | Opcode 69: Actor byte0==4 selects global selected id; otherwise literal actor index, without local bound. Command F0 reads 0x20-byte indexed position record at 0x4B8A70, converts signed integer fields to actor +ABC/+AC0/+AC4 floats, yaw to +AC8, then calls 0x6268D0. F1 branches directly to that restore call with the existing saved pose. Other commands queue triplet as opcode 68. Matching selected actor sets 0x4BADC0. |
| [o2 0x68F3C0](../recomp/config/output_ovl/o2/o2_0068F3C0_0x68f3c0.cpp) | `script_op_clear_four_actor_control_triplets` | Confirmed/static mechanics | Opcode 6A: Writes first byte FF for each of four triplets at 0x4B9D00+3*index; leaves other two bytes untouched. |
| [o2 0x68F400](../recomp/config/output_ovl/o2/o2_0068F400_0x68f400.cpp) | `script_op_raise_global_request_4bae30` | Confirmed/static mechanics | Opcode 6B: Stores byte 1 at 0x4BAE30, returns zero; downstream request meaning unknown. |
| [o2 0x68F420](../recomp/config/output_ovl/o2/o2_0068F420_0x68f420.cpp) | `script_op_queue_actor_control_with_mode_candidate` | Probable semantic role; mechanics verified | Opcode 6C: Like opcode 69, but first writes actor +AD4=1 and +AD5=payload byte+C, then command F0 position path/F1 bypass/ordinary triplet path. Selected actor notification byte as 69. |
| [o2 0x68F570](../recomp/config/output_ovl/o2/o2_0068F570_0x68f570.cpp) | `script_op_call_audio_or_event_1ba170` | Confirmed/static mechanics | Opcode 70: Calls main 0x1BA170(0,payload word0,0); returns zero. Audio/event role provisional until main target reviewed. |
| [o2 0x68F5A0](../recomp/config/output_ovl/o2/o2_0068F5A0_0x68f5a0.cpp) | `script_op_call_1ae190_zero` | Confirmed/static mechanics | Opcode 71: Calls main 0x1AE190(0), ignores payload and returns zero; target role unresolved. |
| [o2 0x68F5C0](../recomp/config/output_ovl/o2/o2_0068F5C0_0x68f5c0.cpp) | `script_op_enable_type_nine_with_word44` | Confirmed/static mechanics | Opcode 72: Unless list sentinel 0x80, visits all linked nodes; type +30==9/id +40 match receives +3C=1 and payload word +4 at +44. |
| [o2 0x68F640](../recomp/config/output_ovl/o2/o2_0068F640_0x68f640.cpp) | `script_op_sound_with_optional_position_candidate` | Probable semantic role; mechanics verified | Opcode 73: Payload word +4 selects 0x1B8930 argument: mode0 null; mode1 actor position +38 using payload +8 actor id (4 means selected); mode2 stack XYZ floats converted from signed payload +8/+C/+10. Payload word0 passed as a1. Other modes no call. |
| [o2 0x68F710](../recomp/config/output_ovl/o2/o2_0068F710_0x68f710.cpp) | `script_op_create_callback_task_5d93f0` | Confirmed/static mechanics | Opcode 74: Calls 0x573890(0,0x5D93F0); if allocated writes low payload halfword to task +C, unsigned payload words +4/+8/+C converted to floats at +70/+74/+78. No opcode-side bounds or parameter units established. |
| [o2 0x68F7F0](../recomp/config/output_ovl/o2/o2_0068F7F0_0x68f7f0.cpp) | `script_op_set_record32_flag1` | Confirmed/static mechanics | Opcode 7E: Requires payload unsigned index <32 and nonzero byte0 at 0x3C3000+0x68*index; sets record byte+1 bit1. Returns zero. |
| [o2 0x68F860](../recomp/config/output_ovl/o2/o2_0068F860_0x68f860.cpp) | `script_op_clear_record32_flag1` | Confirmed/static mechanics | Opcode 7F: Same index/activity admission as 7E; clears record byte+1 bit1 preserving other bits. |
| [o2 0x68F8D0](../recomp/config/output_ovl/o2/o2_0068F8D0_0x68f8d0.cpp) | `script_op_object_create_default_adapter_candidate` | Probable semantic role; mechanics verified | Opcode 80: Payload id <200 passed unchanged; >=200 maps through byte 0x4BACF0[id]+200. Calls 0x684010(id,0,0,0). No upper bound on translation-table index in handler. |
| [o2 0x68F970](../recomp/config/output_ovl/o2/o2_0068F970_0x68f970.cpp) | `script_op_object_release_and_notify_candidate` | Probable semantic role; mechanics verified | Opcode 81: Same word-id remapping, calls 0x684450, scans 64 stride-0x78 records at 0x390210 for matching +4 id, calls 0x681330(1) on first match. Does not test object activity byte in this scan. |
| [o2 0x68FA00](../recomp/config/output_ovl/o2/o2_0068FA00_0x68fa00.cpp) | `script_op_object_action_adapter_6844c0` | Confirmed/static mechanics | Opcode 82: Same word-id remapping, calls 0x6844C0(id), returns zero. Destroy/hide role not yet established. |
| [o2 0x68FBE0](../recomp/config/output_ovl/o2/o2_0068FBE0_0x68fbe0.cpp) | `script_op_store_indexed_byte_4b9da0` | Confirmed/static mechanics | Opcode 83: Stores low byte payload word +4 to 0x4B9DA0+payload word0, no local bound. |
| [o2 0x68FC00](../recomp/config/output_ovl/o2/o2_0068FC00_0x68fc00.cpp) | `script_op_remap_absent_actor_and_object_ids_candidate` | Probable semantic role; mechanics verified | Opcode 84: Builds missing actor-type list 0..7 by scanning count 0x4BAEA0 without active checks. Remaps active object ids >=200 in 64 records; 128x4 halfword slots at 0x4B8E80 except FFFF; 256 stride-0x60 records at 0x74F250 with type+2==1 and id+3 60..69 map via byte table then +70. Mutates data; cannot repeat blindly as pure query. |
| [o2 0x68FDC0](../recomp/config/output_ovl/o2/o2_0068FDC0_0x68fdc0.cpp) | `script_op_insert_object_halfword_pair` | Confirmed/static mechanics | Opcode 85: Selects 16-byte row 0x4B8E80+16*payload word0; finds first of four entries with BOTH halfwords FFFF, stores payload halfwords +4/+8. No row-index check; no store if full. |
| [o2 0x68FE40](../recomp/config/output_ovl/o2/o2_0068FE40_0x68fe40.cpp) | `script_op_remove_object_pairs_all_rows` | Confirmed/static mechanics | Opcode 86: Scans 128 rows, four pairs each at 0x4B8E80; matches first halfword with payload halfword0, clears BOTH halfwords to FFFF. All matches removed. |
| [o2 0x68FEB0](../recomp/config/output_ovl/o2/o2_0068FEB0_0x68feb0.cpp) | `script_op_remove_object_pairs_selected_row` | Confirmed/static mechanics | Opcode 87: Selects unchecked row index payload word0, scans four pairs, removes matches to payload halfword+4 by writing both FFFF. |
| [o2 0x68F920](../recomp/config/output_ovl/o2/o2_0068F920_0x68f920.cpp) | `script_op_object_create_parameter_adapter_candidate` | Probable semantic role; mechanics verified | Opcode 88: Like opcode80 id remapping, but forwards payload words +4/+8/+C to 0x684010 as remaining arguments. |
| [o2 0x68FA40](../recomp/config/output_ovl/o2/o2_0068FA40_0x68fa40.cpp) | `script_op_object_position_adapter_candidate` | Probable semantic role; mechanics verified | Opcode 89: Unsigned halfword id uses >=200 remapping; converts signed payload +8/+C/+10 to XYZ floats, forwards word +4 and halfword +14 to 0x6841E0(id,arg,position,angle). Exact world units unknown. |
| [o2 0x68FAC0](../recomp/config/output_ovl/o2/o2_0068FAC0_0x68fac0.cpp) | `script_op_object_flags_40000000` | Confirmed/static mechanics | Opcode 8A: Halfword id remapping then calls 0x6842B0(id,payload word+4,0x40000000). Meaning of mask flag requires target. |
| [o2 0x68FB20](../recomp/config/output_ovl/o2/o2_0068FB20_0x68fb20.cpp) | `script_op_object_flags_40000008` | Confirmed/static mechanics | Opcode 8B: Halfword id remapping then calls 0x6842B0(id,-1,0x40000008). |
| [o2 0x68FB80](../recomp/config/output_ovl/o2/o2_0068FB80_0x68fb80.cpp) | `script_op_object_flags_select_high_bit` | Confirmed/static mechanics | Opcode 8C: Halfword id remapping; payload word+4 nonzero selects mask 0x80000010, zero 0x40000010. Calls 0x6842B0(id,-1,mask). |
| [o2 0x68FF10](../recomp/config/output_ovl/o2/o2_0068FF10_0x68ff10.cpp) | `script_op_create_callback_task_5d8850` | Confirmed/static mechanics | Opcode 90: Allocates through 0x573890(0,0x5D8850); if nonzero stores low payload word0 byte at task+3, returns zero. |
| [o2 0x68FF60](../recomp/config/output_ovl/o2/o2_0068FF60_0x68ff60.cpp) | `script_op_store_global_word_49f784` | Confirmed/static mechanics | Opcode 91: Stores payload word0 at 0x49F784, returns zero. Field purpose unknown. |
| [o2 0x68FF80](../recomp/config/output_ovl/o2/o2_0068FF80_0x68ff80.cpp) | `script_op_create_actor_callback_task_6b6990` | Confirmed/static mechanics | Opcode 92: Allocates callback 0x6B6990. Maps payload byte0 via 0x581830 to task byte+6, calls 0x5D8280(mappedId,task+30), stores low payload word+4 byte at task+4. |
| [o2 0x68FFF0](../recomp/config/output_ovl/o2/o2_0068FFF0_0x68fff0.cpp) | `script_op_create_resource_callback_task_6b7000` | Confirmed/static mechanics | Opcode 93: Allocates callback 0x6B7000. Uses resource base [0x324424]+0x8000: byte mapping table +4 maps payload byte0 to task+6; relative pointer table +10 maps payload byte+8 to task+24. Calls 0x5D8280 for task+30; payload +4 ->byte+4, +C->halfword+10. |
| [o2 0x6900A0](../recomp/config/output_ovl/o2/o2_006900A0_0x6900a0.cpp) | `script_op_create_linked_task_type_five` | Confirmed/static mechanics | Opcode 94: Resolves scenario callback pointer from payload byte0 via 0x573950; allocates through 0x573630(1). Sets bytes +0=1,+2=5,+3=id,+4/+5 from payload; words +18/+28=0,+14=resolved callback pointer. Returns zero even if lookup/allocation fails. |
| [o2 0x690140](../recomp/config/output_ovl/o2/o2_00690140_0x690140.cpp) | `script_op_room_event_flag_trigger_candidate` | Probable semantic role; mechanics verified | Opcode 95: Uses current room stride0x30 halfword table 0x4A1DF0 and payload index. Combines timer sign/flag 0x4B9C00 state, may clear timer, mutate actor-specific event record, clear flag via 0x5705F0, call 0x570270(selected actor,resource mapped byte,mode 0 or6), then set supplied flag through 0x5703E0. Admission side effects retained; not just an unconditional event call. |
| [o2 0x690340](../recomp/config/output_ovl/o2/o2_00690340_0x690340.cpp) | `script_op_set_global_mask_bit_4b9d0c` | Confirmed/static mechanics | Opcode A0: ORs 0x4B9D0C word with guest variable-shift mask 1<<payload word0. No explicit id range check. |
| [o2 0x690370](../recomp/config/output_ovl/o2/o2_00690370_0x690370.cpp) | `script_op_clear_global_mask_bit_4b9d0c` | Confirmed/static mechanics | Opcode A1: Clears guest variable-shift bit in 0x4B9D0C. |
| [o2 0x6903A0](../recomp/config/output_ovl/o2/o2_006903A0_0x6903a0.cpp) | `script_op_set_global_mask_all` | Confirmed/static mechanics | Opcode A2: Writes FFFFFFFF to 0x4B9D0C; payload ignored. |
| [o2 0x6903C0](../recomp/config/output_ovl/o2/o2_006903C0_0x6903c0.cpp) | `script_op_clear_global_mask_all` | Confirmed/static mechanics | Opcode A3: Writes zero to 0x4B9D0C; payload ignored. |
| [o2 0x6903D0](../recomp/config/output_ovl/o2/o2_006903D0_0x6903d0.cpp) | `script_op_set_extended_flag_bit` | Confirmed/static mechanics | Opcode A4: Bit id payload word0 selects word 0x4BAE10+4*(id>>5), ORs bit id&31; no overall array bound. |
| [o2 0x690410](../recomp/config/output_ovl/o2/o2_00690410_0x690410.cpp) | `script_op_clear_extended_flag_bit` | Confirmed/static mechanics | Opcode A5: Clears selected bit in extended word bank 0x4BAE10, same id addressing as A4. |
| [o2 0x690450](../recomp/config/output_ovl/o2/o2_00690450_0x690450.cpp) | `script_op_call_scene_parameter_577ab0` | Confirmed/static mechanics | Opcode A6: Forwards payload word0 to 0x577AB0, returns zero; scene meaning provisional. |
| [o2 0x690470](../recomp/config/output_ovl/o2/o2_00690470_0x690470.cpp) | `script_op_call_scene_parameter_577b00` | Confirmed/static mechanics | Opcode A7: Forwards payload word0 to 0x577B00, returns zero; downstream role unresolved. |
| [o2 0x690490](../recomp/config/output_ovl/o2/o2_00690490_0x690490.cpp) | `script_op_set_four_thousandth_scaled_parameters` | Confirmed/static mechanics | Opcode A8: Only payload word0==1 acts: ORs halfword 0x4B9D1A bit1, converts four unsigned words +4/+8/+C/+10 to float, divides each by 1000, stores 0x4BAC84..90, calls 0x5DFA90. Other selectors return zero unchanged. |
| [o2 0x690600](../recomp/config/output_ovl/o2/o2_00690600_0x690600.cpp) | `script_op_clear_actor_mapping_flag80` | Confirmed/static mechanics | Opcode B0: Maps payload byte0 through 0x581830; clears bit 0x80 in byte 0x49F790[low mapped id]. |
| [o2 0x690640](../recomp/config/output_ovl/o2/o2_00690640_0x690640.cpp) | `script_op_set_actor_mapping_flag80` | Confirmed/static mechanics | Opcode B1: Same 0x581830 mapping, sets byte-table bit 0x80 at 0x49F790. |
| [o2 0x690680](../recomp/config/output_ovl/o2/o2_00690680_0x690680.cpp) | `script_op_clear_alternate_actor_mapping_flag80` | Confirmed/static mechanics | Opcode B2: Maps through 0x5817F0, clears bit 0x80 at 0x49F790[low mapped id]. |
| [o2 0x6906C0](../recomp/config/output_ovl/o2/o2_006906C0_0x6906c0.cpp) | `script_op_set_alternate_actor_mapping_flag80` | Confirmed/static mechanics | Opcode B3: Maps through 0x5817F0, sets bit 0x80 at 0x49F790[low mapped id]. |
| [o2 0x690700](../recomp/config/output_ovl/o2/o2_00690700_0x690700.cpp) | `script_op_adjust_mapped_actor_matrix_candidate` | Probable semantic role; mechanics verified | Opcode B4: Resolves actor via 0x581830 to matrix 0x49FA10+0x40*id. Payload +4 selects 24-byte rotation/offset record at 0x7174F0. Transforms offset through original basis, builds XYZ rotation, composes/copies basis preserving W and translation, then adds transformed offset to translation. No local table-index bounds. |
| [o2 0x690810](../recomp/config/output_ovl/o2/o2_00690810_0x690810.cpp) | `script_op_set_type_zero_two_byte71_and_refresh` | Confirmed/static mechanics | Opcode B5: Walks list 0x3B5160 with sentinel guard, matches id +40 and type0/2. Writes payload byte +4 to +71. Type0 always calls 0x6B5E10(node byte+40), type2 only when node +50!=0. All matches. |
| [o2 0x6908E0](../recomp/config/output_ovl/o2/o2_006908E0_0x6908e0.cpp) | `script_op_condition_strided_halfword_bank_plus4` | Confirmed/static mechanics | Opcode B7: Increments condition ordinal; tests halfword at 0x4B9E24+12*payload word0 against mask 1<<payload word+4. Payload +8 selects required set/clear; failure skips group and returns 2. |
| [o2 0x6909B0](../recomp/config/output_ovl/o2/o2_006909B0_0x6909b0.cpp) | `script_op_condition_strided_halfword_bank_base` | Confirmed/static mechanics | Opcode B8: Same as B7 but halfword bank starts 0x4B9E20. Distinct fields in each 12-byte record. |
| [o2 0x690A80](../recomp/config/output_ovl/o2/o2_00690A80_0x690a80.cpp) | `script_op_signed_byte_adapter_6ae310` | Confirmed/static mechanics | Opcode C0: Signed payload byte0 forwarded to 0x6AE310; returns zero. Negative input preserved. |
| [o2 0x690AA0](../recomp/config/output_ovl/o2/o2_00690AA0_0x690aa0.cpp) | `script_op_signed_byte_adapter_6ae390` | Confirmed/static mechanics | Opcode C1: Signed payload byte0 forwarded to 0x6AE390; returns zero. |
| [o2 0x690AC0](../recomp/config/output_ovl/o2/o2_00690AC0_0x690ac0.cpp) | `script_op_condition_mapped_resource_type` | Confirmed/static mechanics | Opcode C2: Signed payload byte0 indexes byte 0x3C5613+4*id. Negative mapped byte fails. Otherwise record 0x3C4580+60*mappedId must have unsigned type+2 equal signed payload byte+4 and flags+24 bit2 clear. Increments condition ordinal, failure skips/returns2. |
| [o2 0x690B80](../recomp/config/output_ovl/o2/o2_00690B80_0x690b80.cpp) | `script_op_condition_mapped_resource_presence` | Confirmed/static mechanics | Opcode C3: Same signed mapping lookup. Nonzero payload byte+4 requires nonnegative mapped index; zero requires absent index OR mapped resource flags+24 bit2 set. Increments condition ordinal; failure skips/returns2. |
| [o2 0x690C40](../recomp/config/output_ovl/o2/o2_00690C40_0x690c40.cpp) | `script_op_set_resource_pair_and_refresh_candidate` | Probable semantic role; mechanics verified | Opcode C4: Payload unsigned id byte <32, parameter bytes +4/+8 below signed halfword limits at 0x3C4D0C/0E. Scans32 active stride60 records at 0x3C4580, matches id+2; writes +18/+19 bytes, calls 0x6B0780(record byte+3), stops first. Explicit negative checks on unsigned bytes do not admit negatives. |
| [o2 0x690D40](../recomp/config/output_ovl/o2/o2_00690D40_0x690d40.cpp) | `script_op_set_resource_flag10` | Confirmed/static mechanics | Opcode C5: Payload id byte <32, scans32 active records at 0x3C4580, first matching +2 id ORs flags+24 bit0x10. Returns zero on miss. |
| [o2 0x690DD0](../recomp/config/output_ovl/o2/o2_00690DD0_0x690dd0.cpp) | `script_op_clear_resource_flag10` | Confirmed/static mechanics | Opcode C6: Same search/admission as C5, clears flags+24 bit0x10. |
| [o2 0x690E60](../recomp/config/output_ovl/o2/o2_00690E60_0x690e60.cpp) | `script_op_set_resource_flag20` | Confirmed/static mechanics | Opcode C7: Same search/admission as C5, ORs flags+24 bit0x20. |
| [o2 0x690EF0](../recomp/config/output_ovl/o2/o2_00690EF0_0x690ef0.cpp) | `script_op_create_scenario_event_record_candidate` | Probable semantic role; mechanics verified | Opcode D0: Uses selected actor bank only when session mode 0x1B02D0==1, with selected ids0..2 admitted; other modes bank0. Event record 0x3B64D0+0xAA0*bank+0x110*payload byte+4 must be inactive. Clears0x110, calls 0x5B92B0(slot,type,scenario table0x70A0D0[scenario],selectedId), copies five payload words +8..18 to +60..70. No local event slot bound. |
| [o2 0x691010](../recomp/config/output_ovl/o2/o2_00691010_0x691010.cpp) | `script_op_create_type_event_record_candidate` | Probable semantic role; mechanics verified | Opcode D1: Same bank/slot admission and five-word copy as D0. Chooses callback/data table by bank: 0x70A180[type] for bank0, 0x70A1B0[type] for bank1/2; calls 0x5B92B0. No local type or event-slot bound. |
| [o2 0x691170](../recomp/config/output_ovl/o2/o2_00691170_0x691170.cpp) | `script_op_condition_flag_bank_4b9a80` | Confirmed/static mechanics | Opcode E3: Increments condition ordinal; tests payload bit id in word bank 0x4B9A80. Payload +4 selects required set/clear; failed condition skips group and returns2. |
| [o2 0x691240](../recomp/config/output_ovl/o2/o2_00691240_0x691240.cpp) | `script_op_condition_else_marker_candidate` | Probable semantic role; mechanics verified | Opcode E4: Calls 0x68CBE0 and returns2, forcing dispatcher reload of current instruction. Marker role corroborated by condition scanner E4 handling; callee body needs separate annotation. |
| [o2 0x691260](../recomp/config/output_ovl/o2/o2_00691260_0x691260.cpp) | `script_op_increment_condition_depth_marker` | Confirmed/static mechanics | Opcode E5: Increments selected slot word at 0x4BAD58, returns0. Condition scanner also interprets opcode E5; semantic endif name not proven. |
| [o2 0x691290](../recomp/config/output_ovl/o2/o2_00691290_0x691290.cpp) | `script_op_condition_flag_bank_4b9c40` | Confirmed/static mechanics | Opcode E6: Like E3 but tests bit in word bank 0x4B9C40. |
| [o2 0x691360](../recomp/config/output_ovl/o2/o2_00691360_0x691360.cpp) | `script_op_trigger_flag_for_actor_region_occupancy_candidate` | Probable semantic role; mechanics verified | Opcode E7: Finds linked type3 record with +44 in {0,2} and +40 id. Payload +4 mode0: counts actors passing 0x666080 OR point test 0x5DC9B0(region,actor+38), sets flag when total equals actor count. Mode1: counts actors not excluded by 0x666080 that pass region test, sets flag when none pass. Other modes no action. Iteration uses global count 0x4BAEA0; point geometry unproven. |
| [o2 0x6915C0](../recomp/config/output_ovl/o2/o2_006915C0_0x6915c0.cpp) | `script_op_store_session_counter` | Confirmed/static mechanics | Opcode E8: Session mode1 uses selected actor bank, otherwise bank0. Writes payload word+4 into 0x4BAD70+8*bank+4*payload word0. No local bank/index bounds; stride8 suggests two counters but does not enforce two. |
| [o2 0x691630](../recomp/config/output_ovl/o2/o2_00691630_0x691630.cpp) | `script_op_condition_consume_session_counter` | Confirmed/static mechanics | Opcode E9: Same bank/index addressing as E8; increments condition ordinal. Desired nonzero: requires counter!=0 then decrements; desiredzero: counter0 passes, nonzero decrements before condition-skip. Negative counters count as nonzero. Failure returns2. |
| [o2 0x691720](../recomp/config/output_ovl/o2/o2_00691720_0x691720.cpp) | `script_op_condition_actor_type_present` | Confirmed/static mechanics | Opcode EA: Scans global actor count, matches +B98 to payload byte0 without checking activity. Payload byte+4==1 requires presence; ==0 requires absence; other values bypass condition failure. Increments condition ordinal; failure skips/returns2. |
| [o2 0x691800](../recomp/config/output_ovl/o2/o2_00691800_0x691800.cpp) | `script_op_set_flag_on_actor_pair_match_candidate` | Probable semantic role; mechanics verified | Opcode EB: For each actor resolves 0x665780 then 0x663350(2,value). If returned record nonzero and bytes +3/+4 match payload bytes0/+4, calls 0x5703E0(payload word+8,1) and exits. No actor active check here. |
| [o2 0x6918C0](../recomp/config/output_ovl/o2/o2_006918C0_0x6918c0.cpp) | `script_op_condition_flag_transition_bank_pair` | Confirmed/static mechanics | Opcode EC: Increments condition ordinal. Desired nonzero passes iff bit in 0x4B9C00 is set AND corresponding bit in 0x4B9C40 clear; desiredzero passes iff that expression false. Names current/previous or rising edge are plausible but not established by body alone. |
| [o2 0x6919D0](../recomp/config/output_ovl/o2/o2_006919D0_0x6919d0.cpp) | `script_op_condition_alternate_flag_transition_pair` | Confirmed/static mechanics | Opcode ED: Same Boolean expression as EC using banks 0x4B9A80 and 0x4B9B40. Failure skips/returns2. |
| [o2 0x691AE0](../recomp/config/output_ovl/o2/o2_00691AE0_0x691ae0.cpp) | `script_op_condition_global_byte_compare` | Confirmed/static mechanics | Opcode EE: Increments condition ordinal, compares global unsigned byte0x4BAE8A to payload byte0 using six-case operator byte+4/table0x7408B0. Out-of-range operator>=6 bypasses failure and returns0. Verified numeric operator table below. |
| [o2 0x691C10](../recomp/config/output_ovl/o2/o2_00691C10_0x691c10.cpp) | `script_op_condition_byte_index_flag_bank` | Confirmed/static mechanics | Opcode EF: Increments condition ordinal; unsigned payload byte0 (0..255) selects bit in word bank0x4B9B40; payload byte+4 selects required set/clear. Failure skips/returns2. |
| [o2 0x691CE0](../recomp/config/output_ovl/o2/o2_00691CE0_0x691ce0.cpp) | `script_op_word_adapter_5dcb60` | Confirmed/static mechanics | Opcode F0: Payload word0 forwarded to 0x5DCB60; returns0. Target role requires separate review. |
| [o2 0x691D00](../recomp/config/output_ovl/o2/o2_00691D00_0x691d00.cpp) | `script_op_word_adapter_5dcb90` | Confirmed/static mechanics | Opcode F1: Payload word0 forwarded to 0x5DCB90; returns0. |
| [o2 0x691D20](../recomp/config/output_ovl/o2/o2_00691D20_0x691d20.cpp) | `script_op_set_room_timer_from_difficulty_table_candidate` | Probable semantic role; mechanics verified | Opcode F2: Destination halfword0x4A1DF0+0x30*payload word0+2*payload word+4. Signed payload word+8<100 selects low4bit column in halfword table0x717690+32*global byte0x4BAE8A; otherwise low4bits(value-100) select word table at [0x324424]+34 +64*global byte. Stores low halfword. Negative values take first branch; no local destination bounds. |
| [o2 0x691DE0](../recomp/config/output_ovl/o2/o2_00691DE0_0x691de0.cpp) | `script_op_set_linked_actor_halfword66` | Confirmed/static mechanics | Opcode F3: Resolves low payload id via0x581A50(id,0). Type0 stores payload halfword+4 at +66. Type2 also resolves(id,1) and stores same +66 there, without second-result null check. Other types no store. |
| [o2 0x691E70](../recomp/config/output_ovl/o2/o2_00691E70_0x691e70.cpp) | `script_op_set_strided_halfword_bank_plus_a` | Confirmed/static mechanics | Opcode F4: ORs halfword at0x4B9E2A+12*payload word0 with low16 of guest-shift mask1<<payload word+4. No local bounds. |
| [o2 0x691EB0](../recomp/config/output_ovl/o2/o2_00691EB0_0x691eb0.cpp) | `script_op_clear_strided_halfword_bank_plus_a` | Confirmed/static mechanics | Opcode F5: Clears corresponding low16 mask in same halfword bank as F4. |
| [o2 0x691F00](../recomp/config/output_ovl/o2/o2_00691F00_0x691f00.cpp) | `script_op_enable_type_thirteen_parameter` | Confirmed/static mechanics | Opcode F6: Walks shared linked list/sentinel, matches type+30==13 and node WORD+44==payload word0, sets byte+3C=1 and signed payload halfword+4 to node+62. All matches. |
| [o2 0x691F80](../recomp/config/output_ovl/o2/o2_00691F80_0x691f80.cpp) | `script_op_store_global_halfword_49f788` | Confirmed/static mechanics | Opcode F7: Stores low halfword payload word0 at0x49F788; returns0. Field meaning unresolved. |

## Verified numeric dispatch assignments

Every slot below was read from the decoded owned image, not inferred from generated switch labels. Table words are code addresses; internal branch blocks are not counted as additional function entries.

### Actor primary action: 0x712BD0

| Slot | Target address |
| --- | --- |
| 00 | 0x66B950 |
| 01 | 0x64AF50 |
| 02 | 0x585190 |
| 03 | 0x593650 |
| 04 | 0x66B950 |
| 05 | 0x593A50 |
| 06 | 0x66B950 |
| 07 | 0x66B950 |
| 08 | 0x66B950 |
| 09 | 0x66B950 |
| 0A | 0x66B950 |
| 0B | 0x66B950 |
| 0C | 0x66B950 |
| 0D | 0x000000 |
| 0E | 0x000000 |
| 0F | 0x000000 |

### Actor secondary action: 0x712C10

| Slot | Target address |
| --- | --- |
| 00 | 0x66B8E0 |
| 01 | 0x66B960 |
| 02 | 0x678130 |
| 03 | 0x5C6810 |
| 04 | 0x5C6C80 |
| 05 | 0x640A50 |
| 06 | 0x67BE90 |
| 07 | 0x67C240 |
| 08 | 0x66B950 |
| 09 | 0x66B950 |
| 0A | 0x66B950 |
| 0B | 0x66B950 |
| 0C | 0x66B950 |
| 0D | 0x66B950 |
| 0E | 0x000000 |
| 0F | 0x000000 |

### Actor message selector: 0x740710

| Slot | Target address |
| --- | --- |
| 00 | 0x67E314 |
| 01 | 0x67E31C |
| 02 | 0x67E454 |
| 03 | 0x67E4D0 |
| 04 | 0x67E510 |
| 05 | 0x67E548 |
| 06 | 0x67E670 |
| 07 | 0x67E6A4 |
| 08 | 0x67E898 |
| 09 | 0x67E964 |
| 0A | 0x67E9C8 |
| 0B | 0x67EA00 |
| 0C | 0x67EA74 |
| 0D | 0x67EA9C |
| 0E | 0x67EAA4 |
| 0F | 0x67EAC8 |

### Gameplay UI raw state: 0x7429F0

| Slot | Target address |
| --- | --- |
| 00 | 0x6DEF5C |
| 01 | 0x6DF06C |
| 02 | 0x6DF11C |
| 03 | 0x6DF144 |
| 04 | 0x6DF12C |
| 05 | 0x6DF13C |

### Resource comparison operator (opcode 36): 0x740890

| Slot | Target address |
| --- | --- |
| 00 | 0x68D7F0 |
| 01 | 0x68D814 |
| 02 | 0x68D838 |
| 03 | 0x68D860 |
| 04 | 0x68D888 |
| 05 | 0x68D8B0 |

### Global byte comparison operator (opcode EE): 0x7408B0

| Slot | Target address |
| --- | --- |
| 00 | 0x691B38 |
| 01 | 0x691B54 |
| 02 | 0x691B70 |
| 03 | 0x691B90 |
| 04 | 0x691BB0 |
| 05 | 0x691BD0 |

### Script opcode table prefix 000..0FF: 0x717830

The first 256 slots are listed here; extended slots follow below. This prefix has 101 defaults sharing 0x68CD80 and 155 nondefault entries. It is not the complete table.

| Opcode | Target address |
| --- | --- |
| 00 | 0x68CD80 |
| 01 | 0x68CD90 |
| 02 | 0x68CDF0 |
| 03 | 0x68CE30 |
| 04 | 0x68CE90 |
| 05 | 0x68CEC0 |
| 06 | 0x68CF40 |
| 07 | 0x68CF70 |
| 08 | 0x68CFE0 |
| 09 | 0x68CD80 |
| 0A | 0x68D0B0 |
| 0B | 0x68D0F0 |
| 0C | 0x68D1B0 |
| 0D | 0x68D2A0 |
| 0E | 0x68CD80 |
| 0F | 0x68CD80 |
| 10 | 0x68D310 |
| 11 | 0x68D350 |
| 12 | 0x68D380 |
| 13 | 0x68D3D0 |
| 14 | 0x68D450 |
| 15 | 0x68D400 |
| 16 | 0x68D4E0 |
| 17 | 0x68D550 |
| 18 | 0x68CD80 |
| 19 | 0x68CD80 |
| 1A | 0x68CD80 |
| 1B | 0x68CD80 |
| 1C | 0x68CD80 |
| 1D | 0x68CD80 |
| 1E | 0x68CD80 |
| 1F | 0x68CD80 |
| 20 | 0x68D5D0 |
| 21 | 0x68CD80 |
| 22 | 0x68CD80 |
| 23 | 0x68D5F0 |
| 24 | 0x68D610 |
| 25 | 0x68D630 |
| 26 | 0x68CD80 |
| 27 | 0x68CD80 |
| 28 | 0x68CD80 |
| 29 | 0x68CD80 |
| 2A | 0x68CD80 |
| 2B | 0x68CD80 |
| 2C | 0x68CD80 |
| 2D | 0x68CD80 |
| 2E | 0x68CD80 |
| 2F | 0x68CD80 |
| 30 | 0x68D670 |
| 31 | 0x68D690 |
| 32 | 0x68D6B0 |
| 33 | 0x68D6D0 |
| 34 | 0x68D6F0 |
| 35 | 0x68D760 |
| 36 | 0x68D780 |
| 37 | 0x68D8F0 |
| 38 | 0x68D920 |
| 39 | 0x68DA50 |
| 3A | 0x68DBA0 |
| 3B | 0x68DC70 |
| 3C | 0x68DDB0 |
| 3D | 0x68DF10 |
| 3E | 0x68DFD0 |
| 3F | 0x68E070 |
| 40 | 0x68E110 |
| 41 | 0x68E140 |
| 42 | 0x68E170 |
| 43 | 0x68E1A0 |
| 44 | 0x68E1D0 |
| 45 | 0x68E1F0 |
| 46 | 0x68E250 |
| 47 | 0x68E280 |
| 48 | 0x68E310 |
| 49 | 0x68E3A0 |
| 4A | 0x68E460 |
| 4B | 0x68E500 |
| 4C | 0x68E570 |
| 4D | 0x68E590 |
| 4E | 0x68CD80 |
| 4F | 0x68CD80 |
| 50 | 0x68E630 |
| 51 | 0x68E6D0 |
| 52 | 0x68E730 |
| 53 | 0x68E800 |
| 54 | 0x68E8B0 |
| 55 | 0x68E920 |
| 56 | 0x68E9E0 |
| 57 | 0x68EA70 |
| 58 | 0x68EB30 |
| 59 | 0x68EBF0 |
| 5A | 0x68ECA0 |
| 5B | 0x68ECC0 |
| 5C | 0x68ED30 |
| 5D | 0x68EDA0 |
| 5E | 0x68EE30 |
| 5F | 0x68EEC0 |
| 60 | 0x68EF50 |
| 61 | 0x68EFF0 |
| 62 | 0x68F010 |
| 63 | 0x68F140 |
| 64 | 0x68F180 |
| 65 | 0x68F1D0 |
| 66 | 0x68CD80 |
| 67 | 0x68CD80 |
| 68 | 0x68F1F0 |
| 69 | 0x68F280 |
| 6A | 0x68F3C0 |
| 6B | 0x68F400 |
| 6C | 0x68F420 |
| 6D | 0x68CD80 |
| 6E | 0x68CD80 |
| 6F | 0x68CD80 |
| 70 | 0x68F570 |
| 71 | 0x68F5A0 |
| 72 | 0x68F5C0 |
| 73 | 0x68F640 |
| 74 | 0x68F710 |
| 75 | 0x68CD80 |
| 76 | 0x68CD80 |
| 77 | 0x68CD80 |
| 78 | 0x68CD80 |
| 79 | 0x68CD80 |
| 7A | 0x68CD80 |
| 7B | 0x68CD80 |
| 7C | 0x68CD80 |
| 7D | 0x68CD80 |
| 7E | 0x68F7F0 |
| 7F | 0x68F860 |
| 80 | 0x68F8D0 |
| 81 | 0x68F970 |
| 82 | 0x68FA00 |
| 83 | 0x68FBE0 |
| 84 | 0x68FC00 |
| 85 | 0x68FDC0 |
| 86 | 0x68FE40 |
| 87 | 0x68FEB0 |
| 88 | 0x68F920 |
| 89 | 0x68FA40 |
| 8A | 0x68FAC0 |
| 8B | 0x68FB20 |
| 8C | 0x68FB80 |
| 8D | 0x68CD80 |
| 8E | 0x68CD80 |
| 8F | 0x68CD80 |
| 90 | 0x68FF10 |
| 91 | 0x68FF60 |
| 92 | 0x68FF80 |
| 93 | 0x68FFF0 |
| 94 | 0x6900A0 |
| 95 | 0x690140 |
| 96 | 0x68CD80 |
| 97 | 0x68CD80 |
| 98 | 0x68CD80 |
| 99 | 0x68CD80 |
| 9A | 0x68CD80 |
| 9B | 0x68CD80 |
| 9C | 0x68CD80 |
| 9D | 0x68CD80 |
| 9E | 0x68CD80 |
| 9F | 0x68CD80 |
| A0 | 0x690340 |
| A1 | 0x690370 |
| A2 | 0x6903A0 |
| A3 | 0x6903C0 |
| A4 | 0x6903D0 |
| A5 | 0x690410 |
| A6 | 0x690450 |
| A7 | 0x690470 |
| A8 | 0x690490 |
| A9 | 0x68CD80 |
| AA | 0x68CD80 |
| AB | 0x68CD80 |
| AC | 0x68CD80 |
| AD | 0x68CD80 |
| AE | 0x68CD80 |
| AF | 0x68CD80 |
| B0 | 0x690600 |
| B1 | 0x690640 |
| B2 | 0x690680 |
| B3 | 0x6906C0 |
| B4 | 0x690700 |
| B5 | 0x690810 |
| B6 | 0x68CD80 |
| B7 | 0x6908E0 |
| B8 | 0x6909B0 |
| B9 | 0x68CD80 |
| BA | 0x68CD80 |
| BB | 0x68CD80 |
| BC | 0x68CD80 |
| BD | 0x68CD80 |
| BE | 0x68CD80 |
| BF | 0x68CD80 |
| C0 | 0x690A80 |
| C1 | 0x690AA0 |
| C2 | 0x690AC0 |
| C3 | 0x690B80 |
| C4 | 0x690C40 |
| C5 | 0x690D40 |
| C6 | 0x690DD0 |
| C7 | 0x690E60 |
| C8 | 0x68CD80 |
| C9 | 0x68CD80 |
| CA | 0x68CD80 |
| CB | 0x68CD80 |
| CC | 0x68CD80 |
| CD | 0x68CD80 |
| CE | 0x68CD80 |
| CF | 0x68CD80 |
| D0 | 0x690EF0 |
| D1 | 0x691010 |
| D2 | 0x68CD80 |
| D3 | 0x68CD80 |
| D4 | 0x68CD80 |
| D5 | 0x68CD80 |
| D6 | 0x68CD80 |
| D7 | 0x68CD80 |
| D8 | 0x68CD80 |
| D9 | 0x68CD80 |
| DA | 0x68CD80 |
| DB | 0x68CD80 |
| DC | 0x68CD80 |
| DD | 0x68CD80 |
| DE | 0x68CD80 |
| DF | 0x68CD80 |
| E0 | 0x68CD80 |
| E1 | 0x68CD80 |
| E2 | 0x68CD80 |
| E3 | 0x691170 |
| E4 | 0x691240 |
| E5 | 0x691260 |
| E6 | 0x691290 |
| E7 | 0x691360 |
| E8 | 0x6915C0 |
| E9 | 0x691630 |
| EA | 0x691720 |
| EB | 0x691800 |
| EC | 0x6918C0 |
| ED | 0x6919D0 |
| EE | 0x691AE0 |
| EF | 0x691C10 |
| F0 | 0x691CE0 |
| F1 | 0x691D00 |
| F2 | 0x691D20 |
| F3 | 0x691DE0 |
| F4 | 0x691E70 |
| F5 | 0x691EB0 |
| F6 | 0x691F00 |
| F7 | 0x691F80 |
| F8 | 0x68CD80 |
| F9 | 0x68CD80 |
| FA | 0x68CD80 |
| FB | 0x68CD80 |
| FC | 0x68CD80 |
| FD | 0x68CD80 |
| FE | 0x68CD80 |
| FF | 0x68CD80 |

## Extended opcodes 100..1AF

The low-24-bit opcode field admits values above FF; these entries are part of the same contiguous owned table.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x691FA0](../recomp/config/output_ovl/o2/o2_00691FA0_0x691fa0.cpp) | `script_op_queue_selected_actor_request_default` | Confirmed/static mechanics | Opcode 100: Selected actor at0x4A5C30+0x10E0*id receives byte+AD4=1,byte+AD5=low payload word0,halfword+AD6=FFFF. No selected-id bound. |
| [o2 0x692000](../recomp/config/output_ovl/o2/o2_00692000_0x692000.cpp) | `script_op_enable_records_matching_two_words` | Confirmed/static mechanics | Opcode 101: Shared linked list unless sentinel0x80; all nodes with +40==payload word0 and +44==payload word+4 receive byte+3C=1. Does not check node type. |
| [o2 0x692070](../recomp/config/output_ovl/o2/o2_00692070_0x692070.cpp) | `script_op_duplicate_byte_adapter_63f370` | Confirmed/static mechanics | Opcode 102: Calls0x63F370(unsigned payload byte0,same byte) then returns0. |
| [o2 0x6920A0](../recomp/config/output_ovl/o2/o2_006920A0_0x6920a0.cpp) | `script_op_store_actor_byte54d` | Confirmed/static mechanics | Opcode 103: Unchecked payload word0 indexes actor stride0x10E0; stores low payload word+4 byte at actor+54D. |
| [o2 0x6920E0](../recomp/config/output_ovl/o2/o2_006920E0_0x6920e0.cpp) | `script_op_enable_typed_linked_records` | Confirmed/static mechanics | Opcode 104: Shared list/sentinel, first matches type+30 against payload word0, then type-specific id fields. Types0/1/B use+40,2 additionally+50==payload+8,3 matches+40 and parity of+44,4/D use+44,6 uses+54,7 uses+70. Matching nodes set+3C=1. No allocation. |
| [o2 0x6922B0](../recomp/config/output_ovl/o2/o2_006922B0_0x6922b0.cpp) | `script_op_disable_typed_linked_records` | Confirmed/static mechanics | Opcode 105: Type-specific linked-record dispatch counterpart to104, clears byte+3C. Type 2 reaches 692394 with a0==2, so its branch to 6923C0 is not taken; type 3 reaches 6923C4 directly and bypasses the extra next-pointer advance. Offline 702380 preserves the corresponding 702470/7024A0 paths. Complete v10 ordinary/offline original-dispatch comparisons qualify these branches; the earlier extra-advance suspicion was incorrect. |
| [o2 0x692480](../recomp/config/output_ovl/o2/o2_00692480_0x692480.cpp) | `script_op_set_actor_target_transform` | Confirmed/static mechanics | Opcode 106: Payload actor word0==4 substitutes selected id, else unchecked index. Unsigned payload words+4/+8/+C converted to floats ->actor+ABC/+AC0/+AC4; signed halfword+10 ->word+AC8. Unlike position queue opcode69 uses unsigned XYZ and does not call0x6268D0. |
| [o2 0x692570](../recomp/config/output_ovl/o2/o2_00692570_0x692570.cpp) | `script_op_set_type_four_word68` | Confirmed/static mechanics | Opcode 107: Walks list0x3B5160 without sentinel guard, matches type4 and word+44==payload word0, writes payload word+4 to+68 on every match. |
| [o2 0x6925C0](../recomp/config/output_ovl/o2/o2_006925C0_0x6925c0.cpp) | `script_op_set_selected_actor_flag400_and_refresh` | Confirmed/static mechanics | Opcode 108: ORs selected actor+BA4 bit400 and global byte0x4BAE89 mask3, calls0x5F4FD0; payload ignored. |
| [o2 0x692630](../recomp/config/output_ovl/o2/o2_00692630_0x692630.cpp) | `script_op_queue_selected_actor_request_parameter` | Confirmed/static mechanics | Opcode 109: Same request fields as100 but +AD6 lowhalfword supplied from payload word+4 instead ofFFFF. |
| [o2 0x692690](../recomp/config/output_ovl/o2/o2_00692690_0x692690.cpp) | `script_op_set_global_byte_4bae89_bit1` | Confirmed/static mechanics | Opcode 10A: ORs byte0x4BAE89 mask1,returns0. |
| [o2 0x6926B0](../recomp/config/output_ovl/o2/o2_006926B0_0x6926b0.cpp) | `script_op_set_bounded_actor_flag80000` | Confirmed/static mechanics | Opcode 10B: Payload actor id4 substitutes selected; resulting unsigned id<4 required. ORs actor+BA4 bit0x80000. Negative word ids rejected as unsigned. |
| [o2 0x692710](../recomp/config/output_ovl/o2/o2_00692710_0x692710.cpp) | `script_op_set_counter_four` | Confirmed/static mechanics | Opcode 110: Unsigned payload word0<4, stores word+4 to0x4BADA8+4*id. Out-of-range no store. |
| [o2 0x692750](../recomp/config/output_ovl/o2/o2_00692750_0x692750.cpp) | `script_op_add_counter_four` | Confirmed/static mechanics | Opcode 111: Same id<4 guard, wraps32-bit addition payload+4 into0x4BADA8[id]. |
| [o2 0x692790](../recomp/config/output_ovl/o2/o2_00692790_0x692790.cpp) | `script_op_subtract_counter_four` | Confirmed/static mechanics | Opcode 112: Same id<4 guard, wraps32-bit subtraction payload+4 from0x4BADA8[id]. |
| [o2 0x6927D0](../recomp/config/output_ovl/o2/o2_006927D0_0x6927d0.cpp) | `script_op_condition_counter_four_unsigned_compare` | Confirmed/static mechanics | Opcode 113: Payload id<4 required before condition ordinal increment. Six operator modes payload word+8 compare unsigned counter0x4BADA8[id] with payload word+4 using table0x7408D0. Operator>=6 bypasses failure after increment. Failed test skips group/returns2; unsigned comparisons differ from opcode36. |
| [o2 0x692970](../recomp/config/output_ovl/o2/o2_00692970_0x692970.cpp) | `script_op_clear_counter_four` | Confirmed/static mechanics | Opcode 114: Clears four words at0x4BADA8..B4 in reverse index order; ignores payload. |
| [o2 0x6929A0](../recomp/config/output_ovl/o2/o2_006929A0_0x6929a0.cpp) | `script_op_index_enable_adapter_6ba230` | Confirmed/static mechanics | Opcode 120: Calls0x6BA230(payload word0,1),returns0. Semantic resource kind unresolved. |
| [o2 0x6929D0](../recomp/config/output_ovl/o2/o2_006929D0_0x6929d0.cpp) | `script_op_index_disable_adapter_6ba230` | Confirmed/static mechanics | Opcode 121: Calls0x6BA230(payload word0,0),returns0. |
| [o2 0x692A00](../recomp/config/output_ovl/o2/o2_00692A00_0x692a00.cpp) | `script_op_change_global_byte_and_invalidate` | Confirmed/static mechanics | Opcode 122: Compares byte0x4B9D15 with full payload word0; if unequal stores low input byte and writes0xFF to0x4B9D14. High bits in input can force invalidation even when low byte same. |
| [o2 0x692A40](../recomp/config/output_ovl/o2/o2_00692A40_0x692a40.cpp) | `script_op_set_type_five_indexed_halfword` | Confirmed/static mechanics | Opcode 130: Shared list/sentinel, type5/id match resets0x5C45C0, sets+3C=1,+50=payload halfword+4, sets bit(payload word+8&7) in byte+59 and writes same halfword into+5A+2*slot. All matches. |
| [o2 0x692B10](../recomp/config/output_ovl/o2/o2_00692B10_0x692b10.cpp) | `script_op_restart_type_five_three_halfwords` | Confirmed/static mechanics | Opcode 131: Type5/id matches:reset0x5C45C0,+3C=1,decrement byte+32 wrapping,halfwords payload+4/+8/+C ->+50/+52/+54,call0x5D9630(node). All matches. |
| [o2 0x692BE0](../recomp/config/output_ovl/o2/o2_00692BE0_0x692be0.cpp) | `script_op_halfword_adapter_570120` | Confirmed/static mechanics | Opcode 132: Calls0x570120(unsigned payload halfword0,60,1),returns0. Time/lifetime units require target. |
| [o2 0x692C10](../recomp/config/output_ovl/o2/o2_00692C10_0x692c10.cpp) | `script_op_draw_eight_digit_tick_timer_candidate` | Probable semantic role; mechanics verified | Opcode 133: Global0x4BADEE!=0 suppresses. Setup calls0x1CD250(0x2500),0x1AF780/1AF1E0/19D720. Reads signed halfword timer0x4BAD88+2*payload word+8; splits using1800 and30 divisors, scales fractional remainder*100/30; clamps minutes0..99,seconds0..59,hundredths0..99. Emits eight glyphs via0x692E60 including separator index10. Assumes30 ticks/sec for display; does not change game speed. |
| [o2 0x692F40](../recomp/config/output_ovl/o2/o2_00692F40_0x692f40.cpp) | `script_op_restart_type_five_extended_parameters` | Confirmed/static mechanics | Opcode 134: Type5/id reset0x5C45C0,+3C=1; halfword payload+C ->+50,signed halfword+10 ->+6A,clear+6C,word+4 ->+74,unsigned halfword+8 ->word+70. All matches; shared sentinel guard. |
| [o2 0x693020](../recomp/config/output_ovl/o2/o2_00693020_0x693020.cpp) | `script_op_random_filtered_type_five_action_candidate` | Probable semantic role; mechanics verified | Opcode 135: Requires shared sentinel valid and0x1B0340(selectedActor)!=0. Finds type5/id match; global count0x4B9D19<8. Picks one of four payload words using random low2 and table0x717820[difficulty],rejectsFFFFFFFF and already-used lowhalfword list0x4BAC72. Highhalfword8 accepts any selected actor type; otherwise must equal+B98. Resets node,+3C=1,byte+32--,halfword+52=choice\|4000. First eligible action only. |
| [o2 0x693230](../recomp/config/output_ovl/o2/o2_00693230_0x693230.cpp) | `script_op_restart_type_five_with_byte6e` | Confirmed/static mechanics | Opcode 136: All shared-list type5/id matches reset0x5C45C0,+3C=1,halfword payload+4 ->+50,byte+6E=1. |
| [o2 0x6932D0](../recomp/config/output_ovl/o2/o2_006932D0_0x6932d0.cpp) | `script_op_store_banked_halfword_4ba420` | Confirmed/static mechanics | Opcode 140: Writes low payload word+8 halfword at0x4BA420+256*payload word0+2*payload word+4. No local bank/index bound. |
| [o2 0x693300](../recomp/config/output_ovl/o2/o2_00693300_0x693300.cpp) | `script_op_condition_actor_room` | Confirmed/static mechanics | Opcode 150: Actor word0==4 means selected,else unchecked actor. Increments condition ordinal. Desired nonzero requires0x666080(actor,0)==0 AND actor halfword+1E2==payload halfword+4. Desiredzero inverts this composite. Failure skips/returns2. |
| [o2 0x693430](../recomp/config/output_ovl/o2/o2_00693430_0x693430.cpp) | `script_op_condition_all_participating_actor_rooms` | Confirmed/static mechanics | Opcode 151: Increments condition ordinal; loops actor count. Predicate0x666080!=0 counts as accepted/excluded. Remaining actors must have +1E2 equal payload halfword0 when word+4 nonzero, unequal whenzero. Any violation skips/returns2; also fails when count of accepted records zero. |
| [o2 0x6935A0](../recomp/config/output_ovl/o2/o2_006935A0_0x6935a0.cpp) | `script_op_condition_any_actor_excluded_predicate` | Confirmed/static mechanics | Opcode 152: Increments condition ordinal. Payload word0 nonzero requires every actor0x666080==0; zero requires at least one actor predicate!=0. Failed condition skips/returns2. Negative actor count skips loop under signed comparison. |
| [o2 0x6936B0](../recomp/config/output_ovl/o2/o2_006936B0_0x6936b0.cpp) | `script_op_condition_count_actors_in_room` | Confirmed/static mechanics | Opcode 153: Increments condition ordinal; filters room payload word0 and counts0x666080 lowbyte==0 normally,!=0 when payload count+4>6 (then subtract6). Count code6 means total actor count;5 tests nonzero counted actors. RoomFFFFFFFF special compares requested count directly with total without scan. Payload+8 selects required Boolean; failure skips/returns2. |
| [o2 0x693840](../recomp/config/output_ovl/o2/o2_00693840_0x693840.cpp) | `script_op_condition_selected_actor_type` | Confirmed/static mechanics | Opcode 155: Increments condition ordinal; selected actor+B98 compared to unsigned payload byte0. Payload word+4 selects equality/inequality; failed condition skips/returns2. |
| [o2 0x693920](../recomp/config/output_ovl/o2/o2_00693920_0x693920.cpp) | `script_op_condition_actor_selected_field` | Confirmed/static mechanics | Opcode 156: Payload words choose actor lookup mode0 literal id(4=selected) or1 first actor+B98 match,field selector0..7,comparison value,required result. Actor index must be below global count; otherwise condition skip. Verified field-case table0x7408F0 covers actor id+3/type+B98 (highbit value enables masks),byte+B99,mode-dependent+BA0 flags20/100,room+1E2 with0x666080 gate,byte table0x4BAA50,excluded-or-flag8 predicate,mode1 byte+FF0. Failure returns2. |
| [o2 0x693C30](../recomp/config/output_ovl/o2/o2_00693C30_0x693c30.cpp) | `script_op_set_flag_if_actor_in_type12_region_candidate` | Probable semantic role; mechanics verified | Opcode 157: Finds first shared-list type12 record with+40==0,+44==payload id,sets+3C=1 before actor admission. Resolves actor literal(4=selected) or type scan; rejects out-of-range/excluded. If0x5DC9B0(region,actor+38)==1,selector payload+4 zero uses0x5703E0(flag,1),nonzero sets local0x4B9A80 flag. Actor search has specific static upper pointer gates,not generic count loop. |
| [o2 0x693DF0](../recomp/config/output_ovl/o2/o2_00693DF0_0x693df0.cpp) | `script_op_condition_selected_actor_room_owner_candidate` | Probable semantic role; mechanics verified | Opcode 158: Increments condition ordinal; compares selected actor id against0x1B0240(current room),payload word0 chooses equality/inequality. Failure skips/returns2. |
| [o2 0x693EA0](../recomp/config/output_ovl/o2/o2_00693EA0_0x693ea0.cpp) | `script_op_condition_selected_actor_flag80_clear` | Confirmed/static mechanics | Opcode 159: Increments condition ordinal. Payload word0 nonzero always passes; zero requires selected actor+BA0 bit80 clear,otherwise skip/return2. This is not a symmetric set/clear test. |
| [o2 0x693F30](../recomp/config/output_ovl/o2/o2_00693F30_0x693f30.cpp) | `script_op_arm_type33_records_in_two_pools` | Confirmed/static mechanics | Opcode 160: Requires positive payload halfwords0/+8. Visits256 stride0x60 records at0x74F250,matching byte+2A id,byte+2==33,+2F==0: sets halfword+1C,+2F from unsigned word+C float conversion lowbyte,+30/+31 from payload+10/+4. Also scans50 active stride0xD90 records at0x42EB00 with matching+C2B/+3==33,+BAC==0; sets+544/+BAC/+BAD/+BAE, writes float parameter through pointer+1D8 to pointed+C,byte+8=1. No pointed-record null check. |
| [o2 0x6940F0](../recomp/config/output_ovl/o2/o2_006940F0_0x6940f0.cpp) | `script_op_disarm_type33_records_in_two_pools` | Confirmed/static mechanics | Opcode 161: Payload id unsigned byte must be positive. Same256/50 record pools,matching type33/id and armed+2F/+BAC nonzero: clears halfword+1C/+544 and armed byte; large record also byte+8=0. |
| [o2 0x6941C0](../recomp/config/output_ovl/o2/o2_006941C0_0x6941c0.cpp) | `script_op_set_armed_type33_toggle` | Confirmed/static mechanics | Opcode 162: Same pools/matching armed records as161, sets byte+32 or large+BAF to payload byte+4&1. No positive-id requirement here. |
| [o2 0x6942A0](../recomp/config/output_ovl/o2/o2_006942A0_0x6942a0.cpp) | `script_op_arm_type35_records_in_two_pools` | Confirmed/static mechanics | Opcode 163: Positive payload id byte and signed halfword+8>0 required. Same pools,matching type35/id and unarmed: sets halfword+1C/+544,armed byte1,+30/+BAD lowword+C,+31/+BAE lowword+4. Unlike160 no float parameter write or large byte+8 change. |
| [o2 0x694390](../recomp/config/output_ovl/o2/o2_00694390_0x694390.cpp) | `script_op_set_flag_bank_4baa30` | Confirmed/static mechanics | Opcode 164: Sets payload bit id in word bank0x4BAA30, no overall bounds. |
| [o2 0x6943D0](../recomp/config/output_ovl/o2/o2_006943D0_0x6943d0.cpp) | `script_op_clear_flag_and_notify_matching_scene_records` | Confirmed/static mechanics | Opcode 165: Clears bit in0x4BAA30, then scans256 stride0x60 scene records at0x74F250; if byte+26!=0 and byte+4 equals FULL payload word id calls0x681330(2,index). All matches, no record active-byte admission. |
| [o2 0x694470](../recomp/config/output_ovl/o2/o2_00694470_0x694470.cpp) | `script_op_three_byte_adapter_5a8f40` | Confirmed/static mechanics | Opcode 166: Forwards unsigned payload bytes0/+4/+8 to0x5A8F40,returns0. |
| [o2 0x6944A0](../recomp/config/output_ovl/o2/o2_006944A0_0x6944a0.cpp) | `script_op_flag_from_type12_region_entity_scan_candidate` | Probable semantic role; mechanics verified | Opcode 167: Shared-list/sentinel finds type12,+40==0,+44==payload id; sets+3C=1. Scans active list0x3B5900 via+1C, filters+BA9 by payload+C and point0x5DC9B0(region,entity+38)==1. Payload+10 controls early selection/rejection. Success flag path uses0x5703E0 or local0x4B9A80 per payload+4. Branch-dependent first-region selection and point-test admission retained. |
| [o2 0x694620](../recomp/config/output_ovl/o2/o2_00694620_0x694620.cpp) | `script_op_update_matching_scene_record_transform` | Confirmed/static mechanics | Opcode 168: Scans stride0x60 pool0x74F250, signed halfword loop index bounded by unsigned count byte0x4BAE8E, matching byte+4 and+2D to payload bytes0/+4. First match stores payload words+8/+C/+10 at+10/+14/+18 and unsigned halfword+14 zero-extended word+C. Loop initially enters once even if count0. |
| [o2 0x6946B0](../recomp/config/output_ovl/o2/o2_006946B0_0x6946b0.cpp) | `script_op_scenario1c_reassign_type1b_room_candidate` | Probable semantic role; mechanics verified | Opcode 169: Only scenario1C. Finds active participating actor room using two gate halfwords0x4BA820/22 equal1B and room-indexed halfword banks0x4BA620/4BA720. Requires chosen lowbyte room>0. Counts enabled type1B scene records by room into36-byte stack array,excluding requested id; room count>=2 rejects. Assigns first matching record room byte+22 and+2A=5, then marks first excluded actor of type(requestedId-16) with+BA0 bit1000. Selected room indexing lacks local<36 guard. |
| [o2 0x6949A0](../recomp/config/output_ovl/o2/o2_006949A0_0x6949a0.cpp) | `script_op_set_resource_quantity_with_cap_candidate` | Probable semantic role; mechanics verified | Opcode 170: Mode1+global0x4BAE96 bit1 suppresses resource1F. Resolves signed id via0x5B4A50,requires active. Caps signed requested halfword+4 to template signed+8 via0x5B4380; does not clamp lower bound. If0x5B43F0(resource,0x40000) and quantity0, calls0x592CA0; otherwise writes record+24. No template-null guard. |
| [o2 0x694AA0](../recomp/config/output_ovl/o2/o2_00694AA0_0x694aa0.cpp) | `script_op_resource_signed_byte_adapter_592df0` | Confirmed/static mechanics | Opcode 171: Signed payload halfword0 and signed byte+4 forwarded to0x592DF0,returns0. |
| [o2 0x694AD0](../recomp/config/output_ovl/o2/o2_00694AD0_0x694ad0.cpp) | `script_op_set_session_flag_from_actor_resource_test` | Confirmed/static mechanics | Opcode 172: Selected actor must active and+FF0==0. Calls0x5F2210(actor,payload halfword0). Nonzero low return byte sets payload word+4 bit in0x4B9A80;zero clears. Early rejected actor leaves flag unchanged. |
| [o2 0x694BC0](../recomp/config/output_ovl/o2/o2_00694BC0_0x694bc0.cpp) | `script_op_add_resource_to_type7_actor_candidate` | Probable semantic role; mechanics verified | Opcode 173: Payload quantity word+4!=0 and resource halfword id<300 or>=303; excludes300..302. Finds active actor type7, scans32 attached resources for special id413 and count matching input. Requires special present and count<3, caps added quantity so total<=3. Repeatedly0x592A90(actorId,id,1) then0x5F2810(actor,returned byte+2), stops on allocation failure. Negative quantity may skip additions. No gameplay inventory names established. |
| [o2 0x694D70](../recomp/config/output_ovl/o2/o2_00694D70_0x694d70.cpp) | `script_op_resource_two_halfword_adapter_592e90` | Confirmed/static mechanics | Opcode 174: Signed payload halfwords0/+4 forwarded to0x592E90,returns0. |
| [o2 0x694DA0](../recomp/config/output_ovl/o2/o2_00694DA0_0x694da0.cpp) | `script_op_condition_session_mode_zero_or_one` | Confirmed/static mechanics | Opcode 180: Increments condition ordinal. Payload0 requires0x1B02D0==1;payload1 requires mode0. Other selectors fail. On failure calls condition skipper and returns2,else0. |
| [o2 0x694E50](../recomp/config/output_ovl/o2/o2_00694E50_0x694e50.cpp) | `script_op_file1_return_only` | Confirmed complete pinned File1 body and offline comparison | Opcode190 calls main1B3C30, whose complete8-byte File1 body is `jr ra; nop`; wrapper returns flow0 without decoding payload. Native no-op admission is specific to the pinned File1 ELF, not inferred for opcode191 or other builds. See [native VM v8](native-gameplay/SCENARIO_LINKED_CONTROL_VM.md). |
| [o2 0x694E70](../recomp/config/output_ovl/o2/o2_00694E70_0x694e70.cpp) | `script_op_call_1b3c40` | Confirmed/static mechanics | Opcode 191: Calls0x1B3C40 with existing argument registers,returns0. No decoded payload. |
| [o2 0x694E90](../recomp/config/output_ovl/o2/o2_00694E90_0x694e90.cpp) | `script_op_secondary_noop_192` | Confirmed/static mechanics | Opcode 192: Distinct entry returns0 without mutation; one slot references it rather than shared default0x68CD80. |
| [o2 0x694EA0](../recomp/config/output_ovl/o2/o2_00694EA0_0x694ea0.cpp) | `script_op_call_681c70` | Confirmed/static mechanics | Opcode 193: Calls0x681C70 with existing argument registers,returns0. Handler itself does not load payload. |

### Verified extended numeric slots

| Opcode | Target address |
| --- | --- |
| 100 | 0x691FA0 |
| 101 | 0x692000 |
| 102 | 0x692070 |
| 103 | 0x6920A0 |
| 104 | 0x6920E0 |
| 105 | 0x6922B0 |
| 106 | 0x692480 |
| 107 | 0x692570 |
| 108 | 0x6925C0 |
| 109 | 0x692630 |
| 10A | 0x692690 |
| 10B | 0x6926B0 |
| 10C | 0x68CD80 |
| 10D | 0x68CD80 |
| 10E | 0x68CD80 |
| 10F | 0x68CD80 |
| 110 | 0x692710 |
| 111 | 0x692750 |
| 112 | 0x692790 |
| 113 | 0x6927D0 |
| 114 | 0x692970 |
| 115 | 0x68CD80 |
| 116 | 0x68CD80 |
| 117 | 0x68CD80 |
| 118 | 0x68CD80 |
| 119 | 0x68CD80 |
| 11A | 0x68CD80 |
| 11B | 0x68CD80 |
| 11C | 0x68CD80 |
| 11D | 0x68CD80 |
| 11E | 0x68CD80 |
| 11F | 0x68CD80 |
| 120 | 0x6929A0 |
| 121 | 0x6929D0 |
| 122 | 0x692A00 |
| 123 | 0x68CD80 |
| 124 | 0x68CD80 |
| 125 | 0x68CD80 |
| 126 | 0x68CD80 |
| 127 | 0x68CD80 |
| 128 | 0x68CD80 |
| 129 | 0x68CD80 |
| 12A | 0x68CD80 |
| 12B | 0x68CD80 |
| 12C | 0x68CD80 |
| 12D | 0x68CD80 |
| 12E | 0x68CD80 |
| 12F | 0x68CD80 |
| 130 | 0x692A40 |
| 131 | 0x692B10 |
| 132 | 0x692BE0 |
| 133 | 0x692C10 |
| 134 | 0x692F40 |
| 135 | 0x693020 |
| 136 | 0x693230 |
| 137 | 0x68CD80 |
| 138 | 0x68CD80 |
| 139 | 0x68CD80 |
| 13A | 0x68CD80 |
| 13B | 0x68CD80 |
| 13C | 0x68CD80 |
| 13D | 0x68CD80 |
| 13E | 0x68CD80 |
| 13F | 0x68CD80 |
| 140 | 0x6932D0 |
| 141 | 0x68CD80 |
| 142 | 0x68CD80 |
| 143 | 0x68CD80 |
| 144 | 0x68CD80 |
| 145 | 0x68CD80 |
| 146 | 0x68CD80 |
| 147 | 0x68CD80 |
| 148 | 0x68CD80 |
| 149 | 0x68CD80 |
| 14A | 0x68CD80 |
| 14B | 0x68CD80 |
| 14C | 0x68CD80 |
| 14D | 0x68CD80 |
| 14E | 0x68CD80 |
| 14F | 0x68CD80 |
| 150 | 0x693300 |
| 151 | 0x693430 |
| 152 | 0x6935A0 |
| 153 | 0x6936B0 |
| 154 | 0x68CD80 |
| 155 | 0x693840 |
| 156 | 0x693920 |
| 157 | 0x693C30 |
| 158 | 0x693DF0 |
| 159 | 0x693EA0 |
| 15A | 0x68CD80 |
| 15B | 0x68CD80 |
| 15C | 0x68CD80 |
| 15D | 0x68CD80 |
| 15E | 0x68CD80 |
| 15F | 0x68CD80 |
| 160 | 0x693F30 |
| 161 | 0x6940F0 |
| 162 | 0x6941C0 |
| 163 | 0x6942A0 |
| 164 | 0x694390 |
| 165 | 0x6943D0 |
| 166 | 0x694470 |
| 167 | 0x6944A0 |
| 168 | 0x694620 |
| 169 | 0x6946B0 |
| 16A | 0x68CD80 |
| 16B | 0x68CD80 |
| 16C | 0x68CD80 |
| 16D | 0x68CD80 |
| 16E | 0x68CD80 |
| 16F | 0x68CD80 |
| 170 | 0x6949A0 |
| 171 | 0x694AA0 |
| 172 | 0x694AD0 |
| 173 | 0x694BC0 |
| 174 | 0x694D70 |
| 175 | 0x68CD80 |
| 176 | 0x68CD80 |
| 177 | 0x68CD80 |
| 178 | 0x68CD80 |
| 179 | 0x68CD80 |
| 17A | 0x68CD80 |
| 17B | 0x68CD80 |
| 17C | 0x68CD80 |
| 17D | 0x68CD80 |
| 17E | 0x68CD80 |
| 17F | 0x68CD80 |
| 180 | 0x694DA0 |
| 181 | 0x68CD80 |
| 182 | 0x68CD80 |
| 183 | 0x68CD80 |
| 184 | 0x68CD80 |
| 185 | 0x68CD80 |
| 186 | 0x68CD80 |
| 187 | 0x68CD80 |
| 188 | 0x68CD80 |
| 189 | 0x68CD80 |
| 18A | 0x68CD80 |
| 18B | 0x68CD80 |
| 18C | 0x68CD80 |
| 18D | 0x68CD80 |
| 18E | 0x68CD80 |
| 18F | 0x68CD80 |
| 190 | 0x694E50 |
| 191 | 0x694E70 |
| 192 | 0x694E90 |
| 193 | 0x694EA0 |
| 194 | 0x68CD80 |
| 195 | 0x68CD80 |
| 196 | 0x68CD80 |
| 197 | 0x68CD80 |
| 198 | 0x68CD80 |
| 199 | 0x68CD80 |
| 19A | 0x68CD80 |
| 19B | 0x68CD80 |
| 19C | 0x68CD80 |
| 19D | 0x68CD80 |
| 19E | 0x68CD80 |
| 19F | 0x68CD80 |
| 1A0 | 0x68CD80 |
| 1A1 | 0x68CD80 |
| 1A2 | 0x68CD80 |
| 1A3 | 0x68CD80 |
| 1A4 | 0x68CD80 |
| 1A5 | 0x68CD80 |
| 1A6 | 0x68CD80 |
| 1A7 | 0x68CD80 |
| 1A8 | 0x68CD80 |
| 1A9 | 0x68CD80 |
| 1AA | 0x68CD80 |
| 1AB | 0x68CD80 |
| 1AC | 0x68CD80 |
| 1AD | 0x68CD80 |
| 1AE | 0x68CD80 |
| 1AF | 0x68CD80 |

Across all 432 observed slots, **220** share the default handler; **212** nondefault slots target distinct entries, including the separate no-op at opcode192. All **213 distinct targets** have body-reviewed entries (existing annotations reused where present). This is complete structural/body coverage of the observed table, not proof that every downstream semantic role or original opcode name is known. The next word at0x717EF0 is00040404, supporting the candidate data boundary.

Implementation comparison correction, 2026-11-09: complete owned original-body
comparisons corrected the 04 countdown timing, 0C auxiliary bank, 14/17 condition
semantics, inverted 47 predicate and 592960 pointer gate above. Evidence is in
[native VM](native-gameplay/SCENARIO_VM.md),
[sequence control](native-gameplay/SCENARIO_SEQUENCE_CONTROL.md) and
[resource lifecycle](native-gameplay/SCENARIO_RESOURCE_LIFECYCLE.md).
These are source/isolated comparison findings, not new game measurements.
