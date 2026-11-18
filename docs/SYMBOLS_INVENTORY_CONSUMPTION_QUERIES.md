# Inventory consumption, property queries and position records

Static File #1 US research, 2026-11-04. This continues
[recipe application](SYMBOLS_INVENTORY_USE_RECIPES.md). Original identities are
recorded in [the central index](FUNCTION_INDEX.md). Only static source comments
and owned file-backed bytes were inspected. No game, build, replay, attachment,
live-memory inspection or implementation change was performed.

The resource-record and template layouts are described in
[quantity operations](SYMBOLS_INVENTORY_QUANTITY.md). IDs are distinguished from
content types and actor inventory slot numbers below. In particular, some
consumption helpers index records with a **low16** ID before passing a **low8**
ID to their cleanup helpers; no unproven bounds guarantee is added here.

## Consumption and transformation paths

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5B4460](../recomp/config/output_ovl/o2/o2_005B4460_0x5b4460.cpp) | `consume_matching_primary_inventory_content_with_flag200_candidate` | Probable role; full body reviewed | Null actor ignored. Scans four C84 slots for unsigned low16 a1 content and template flag200. First qualifying entry records local scenario event37BBC0(content) when1B0340(actor)==1. If template flag40000 is set, calls5B58C0(resourceID,actor byte3,0), then5B4550(actor,resourceID). Returns after first qualifying match even if flag40000 absent. No independent resource-activity check before first template lookup. |
| [o2 0x5B4550](../recomp/config/output_ovl/o2/o2_005B4550_0x5b4550.cpp) | `decrement_actor_resource_and_destroy_when_depleted_candidate` | Confirmed/static mechanics | Null actor ignored; indexes active record using low16 a1. Decrements signed quantity24 without positive admission. If remainder<=0, removes references/selected instances through5F2180(actor,low8 ID), compacts5F2330(actor), destroys through5B1AF0(low8 ID). Positive remainder leaves references unchanged. No ownership or template-flag admission here. |
| [o2 0x5B45E0](../recomp/config/output_ovl/o2/o2_005B45E0_0x5b45e0.cpp) | `consume_or_transform_matching_primary_inventory_content_candidate` | Probable role; mechanics verified | Null actor ignored. Scans four C84 nonzero slots matching unsigned low16 content. Calls5B46A0(actor,ID); nonzero signed-byte result emits5B58C0(ID,actor byte3,1) and stops. A matching resource whose helper returns0 does not stop later matching-slot search. No C88 scan in this wrapper. |
| [o2 0x5B46A0](../recomp/config/output_ovl/o2/o2_005B46A0_0x5b46a0.cpp) | `consume_or_transform_resource_by_template_flags_candidate` | Probable role; full body reviewed | Nonnull actor and active low16 ID required. Local actor emits37BBC0(content) before template admission. Flag40000 decrements quantity and returns1; depleted removes references, compacts and destroys low8 ID. Otherwise flag80000 directly changes content to template signed halfA, returning1; if resulting content3717, also resets quantity from5B4E60. Without either flag returns0. Event may therefore occur on a no-change return. No owner or positive-quantity guard. |
| [o2 0x5B47F0](../recomp/config/output_ovl/o2/o2_005B47F0_0x5b47f0.cpp) | `destroy_first_matching_inventory_content_with_class6_secondary_scan_candidate` | Probable role; mechanics verified | Nonnull actor scans four C84 slots for unsigned low16 content. First match emits5B58C0(ID,actor byte3,2), then5B4900(actor,ID), and stops. If no primary match and actor B98==6, scans C88 slots1..31 with same operation, deliberately skipping slot0. No activity or quantity test in this search wrapper. |
| [o2 0x5B4900](../recomp/config/output_ovl/o2/o2_005B4900_0x5b4900.cpp) | `remove_compact_and_destroy_actor_resource_candidate` | Confirmed/static mechanics | Nonnull actor only. Local actor records37BBC0 using content from low16 a1 indexed record. Then calls5F2180(actor,low8 ID),5F2330(actor),5B1AF0(low8 ID), regardless removal result. No local activity/owner validation before content lookup and no quantity decrement. |
| [o2 0x5B4990](../recomp/config/output_ovl/o2/o2_005B4990_0x5b4990.cpp) | `transform_resource_to_template_half_a_when_flag80000_candidate` | Probable role; mechanics verified | Requires nonnull actor and active low16 resource ID. Local actor records37BBC0(content) before flag admission. Template flag80000 directly replaces content with signed template halfA through5B4C90, returns1; absent flag returns0. Unlike5B46A0, does not decrement quantity or reset quantity for content3717. |
| [o2 0x5B4AD0](../recomp/config/output_ovl/o2/o2_005B4AD0_0x5b4ad0.cpp) | `replace_depleted_owned_resource_with_template_alternate_candidate` | Probable role; mechanics verified | a0 low8 resource ID, a1 actor/context pointer. Requires active/owned record, template flags1 and80000, quantity<=0, and template signed halfA>=0. Existing model with signed byte1 exactly1 calls5DF2A0(model), then1B8C70(context,5). Directly changes content, resets quantity from5B4E60(ID), calls1D3B00(context), returns1. Rejected paths return0. Does not independently verify context matches resource owner. |
| [o2 0x5B5850](../recomp/config/output_ovl/o2/o2_005B5850_0x5b5850.cpp) | `set_resource_instance_high_flag_from_signed_byte_switch_candidate` | Confirmed/static mechanics | Active low8 ID and nonnull model1C only. Signed lowbyte a1==0 sets model flags23C bit80000000; nonzero clears it. Does not modify record18 flags or resource activity. Rendering/visibility meaning of the high bit remains unproven. |
| [o2 0x5B58C0](../recomp/config/output_ovl/o2/o2_005B58C0_0x5b58c0.cpp) | `route_resource_operation_state_message_candidate` | Probable role; mechanics verified | Only when mapped1B0310 submode predicate succeeds. Stack message has byte0=9,byte1=8,half4=a0,byte6=a1,byte7=a2; calls mapped1AFDD0(5,message,0,4). Consumption wrappers pass operation0/1/2. No allocation, inventory mutation or proven immediate socket-delivery contract here. Bytes2..3 are not initialized locally. |

These wrappers deliberately differ in when they record local scenario events,
which flags they require and whether they destroy, decrement or transform.
Their shared callees do not make their externally observable behavior identical.

## Resource searches and property queries

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5B4A50](../recomp/config/output_ovl/o2/o2_005B4A50_0x5b4a50.cpp) | `find_active_flagged_owned_resource_by_signed_content_candidate` | Confirmed/static mechanics | a0 signextended low16 content; scans all256 records from3C5630. First active record with flags18 bit1, unsigned content6 equal signed input and owner28>0 returns record pointer and writes owner-1 to a1 output halfword. No null-output guard. Failure returns0 and leaves output unchanged. Since stored content is unsigned, negative signed inputs cannot match. |
| [o2 0x5B4CE0](../recomp/config/output_ovl/o2/o2_005B4CE0_0x5b4ce0.cpp) | `get_active_resource_template_signed_byte_e_candidate` | Confirmed/static mechanics | Low8 ID must active and template selector!=FF, else-1. Returns signed template byteE from74BB50+24*selector. No owner/quantity check or inferred enum name. |
| [o2 0x5B4DC0](../recomp/config/output_ovl/o2/o2_005B4DC0_0x5b4dc0.cpp) | `get_resource_template_signed_byte_a_when_flag10_candidate` | Confirmed/static mechanics | Low8 ID active and selector!=FF required, plus5B43F0(ID,10)!=0. Returns signed template byteA; rejected paths-1. This byte access differs from transformation callers' signed halfwordA. |
| [o2 0x5B4F00](../recomp/config/output_ovl/o2/o2_005B4F00_0x5b4f00.cpp) | `get_content_property_zero_scaled_by_one_hundred_candidate` | Confirmed/static mechanics | Unsigned low16 a0>=2710 normalizes to(id%100)+1F4, otherwise signed low16 retained. Normalized range0..257 indexes unsigned byte74B6E0, then8-byte property table74B2D0. Returns unsigned property half0 converted float/100; fallback0.5. Has no FF selector guard. Its unsigned threshold differs from5B42B0's signed threshold. No gameplay property meaning asserted. |
| [o2 0x5B4FD0](../recomp/config/output_ovl/o2/o2_005B4FD0_0x5b4fd0.cpp) | `get_content_property_unsigned_half_two_candidate` | Confirmed/static mechanics | Same unsigned-low16 normalization, range and unsigned selector as5B4F00. Returns unsigned half2 of74B2D0+8*selector; invalid normalized content returns0. Full body reviewed separately; no active resource lookup. |
| [o2 0x5B5060](../recomp/config/output_ovl/o2/o2_005B5060_0x5b5060.cpp) | `get_content_property_unsigned_half_four_candidate` | Confirmed/static mechanics | Same normalization and selector mechanics; returns unsigned property half4, invalid normalized content0. Does not return quantity24 or template capacity8. |
| [o2 0x5B50F0](../recomp/config/output_ovl/o2/o2_005B50F0_0x5b50f0.cpp) | `get_content_property_signed_half_six_scaled_candidate` | Confirmed/static mechanics | Same unsigned-low16 normalization/range/selector. Returns signed property half6 converted float/100, invalid normalized content0. No FF-selector admission or clamp. |
| [o2 0x5B5190](../recomp/config/output_ovl/o2/o2_005B5190_0x5b5190.cpp) | `classify_resource_template_low_flags_by_priority_candidate` | Confirmed/static mechanics | Active low8 ID and selector!=FF, else0. Template flags priority:bit4->1,otherwise bit1->2,otherwise bit2->3,otherwise4. Does not return the mask itself and ignores higher template flags for this classification. |
| [o2 0x5B5350](../recomp/config/output_ovl/o2/o2_005B5350_0x5b5350.cpp) | `test_actor_inventory_resource_predicate_by_selector_candidate` | Probable role; full body and jump table reviewed | a0 actor without null guard; signed low8 a1 must0..7, otherwise0. Table73E550 chooses eight predicates detailed below, returning0/1. Most scan four C84 slots plus all32 C88 slots only for actor B98==6. Template flag helper independently rejects inactive/FF-selector resources. Case5 only tests C88 slot0 nonzero and does not validate its resource. Case2 has an unreachable secondary-bank condition noted below. |

| Selector | Branch | Predicate |
| --- | --- | --- |
| 0 | 5B539C | Any template flags1 |
| 1 | 5B542C | Any template flagsC02 |
| 2 | 5B54BC | Template flag4 and template signed halfA low nibble nonzero; primary bank only in reachable flow |
| 3 | 5B5584 | Template flag4 and template halfA bit10 nonzero |
| 4 | 5B5644 | Template flag4 and template halfA low1F all zero |
| 5 | 5B5704 | Actor C88 slot0 nonzero |
| 6 | 5B5718 | Any template flags208 |
| 7 | 5B57A8 | Any template flags10 |

Case2 reads B98 once, requires it equal6 at `0x5B5518`, then immediately
requires that same unchanged value equal7 at `0x5B5520`. Thus its C88 scan is
unreachable through this entry, even though the scan body exists. The other
cases' class6 admissions were reviewed independently. This is recorded guest
control flow, not a reproduced gameplay bug or a diagnosis of a slowdown.

## World resource position records and connected bounded pool

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5B5240](../recomp/config/output_ovl/o2/o2_005B5240_0x5b5240.cpp) | `collect_flagged_unowned_resource_positions_for_byte_group_candidate` | Probable role; full body reviewed | a0 low16 group compared to resource byte1; scans256 records. Active,owner0,flags18 bit1 and matching group generate8-byte record:type5,selfID byte1,group half2,X/Z converted from float through guest CVT.W.S and narrowed to half4/6. Calls6ECAE0 for each admitted record. Returns admitted count narrowed signed8 after each increment, not actual number accepted by the pool. No room-global lookup or distance filter here. |
| [o2 0x6ECAC0](../recomp/config/output_ovl/o2/o2_006ECAC0_0x6ecac0.cpp) | `clear_sixty_four_position_record_pool_candidate` | Confirmed/static mechanics | Tailcalls mapped memset107C68(759D50,0,200), clearing exactly64 eight-byte records. No deallocation or resource destruction. |
| [o2 0x6ECAE0](../recomp/config/output_ovl/o2/o2_006ECAE0_0x6ecae0.cpp) | `insert_or_replace_bounded_position_record_by_byte_id_candidate` | Probable role; full body reviewed | Mutates caller record byte0 from5 to4. Scans64 records759D50, stopping at first inactive highbit or first active byte1 match. Matching existing low7 type!=4 drops incoming record; matching type4 deactivates matching ID through6ECD90 then overwrites its slot. Full pool shifts records1..63 down and inserts at last. Copies all8 bytes and sets active bit80 while preserving low7 type. Because search stops at first hole, a matching ID after a hole is not considered. No locking or dynamic allocation. |
| [o2 0x6ECC10](../recomp/config/output_ovl/o2/o2_006ECC10_0x6ecc10.cpp) | `remove_first_position_record_id_and_shift_suffix_candidate` | Confirmed/static mechanics | Scans all64 active records for byte1 equal full a0. Clears first match's active bit, then copies subsequent eight-byte records left through original slot63. Does not explicitly clear the final copied-from slot; no-match does not shift. Distinct from simple deactivation6ECD90. No input low8 mask or content-type restriction. |
| [o2 0x6ECCA0](../recomp/config/output_ovl/o2/o2_006ECCA0_0x6ecca0.cpp) | `deactivate_type_four_position_records_and_compact_once_candidate` | Probable role; mechanics verified | First walks64 records; active low7 type4 calls6ECD90(byte1), which deactivates first active matching ID. Second pass shifts suffix left for each encountered inactive record and clears final slot byte0. Outer index still advances after a shift, so consecutive holes can leave a moved-in hole unexamined at the previous position. Records' remaining bytes are not globally zeroed. No general stable-compaction guarantee inferred. |
| [o2 0x6ECD80](../recomp/config/output_ovl/o2/o2_006ECD80_0x6ecd80.cpp) | `collect_world_resource_positions_adapter_candidate` | Confirmed/static mechanics | Tailjump5B5240 preserving incoming arguments. Separate original entry; does not clear pool or normalize its group argument itself. |
| [o2 0x6ECD90](../recomp/config/output_ovl/o2/o2_006ECD90_0x6ecd90.cpp) | `deactivate_first_position_record_by_byte_id_candidate` | Confirmed/static mechanics | Scans all64 records759D50 for active bit80 and byte1 equal full a0. Clears only active bit80 in first match and returns, leaving type/ID/coordinates and all other records untouched. No suffix shift, all-match deletion or input low8 mask. |

## Adjacent scene-context helpers

These small entries precede the position pool but have different storage and
argument contracts. They are kept separate instead of assigning them the pool's
resource meaning merely from address proximity.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6EC920](../recomp/config/output_ovl/o2/o2_006EC920_0x6ec920.cpp) | `find_four_entry_scene_record_by_first_byte_candidate` | Confirmed/static mechanics | Null global pointer755780 returns0. Otherwise scans exactly four1484-byte records for byte0==low8 a0, returns first pointer or0. No active-bit test or resource-ID resolution. Structure role remains provisional. |
| [o2 0x6EC980](../recomp/config/output_ovl/o2/o2_006EC980_0x6ec980.cpp) | `copy_fixed_scene_text_and_set_clock_scaled_counter_candidate` | Probable role; mechanics verified | a0 source pointer,a1 integer counter. Stores arithmetic32-bit a1 right-shifted by global byte3243CC (guest shift masks low5) at759BE0. Copies exactly80 bytes from source to759BE4 through mapped forward memcpy; clears759C63, the final destination byte. No source-length scan or null admission; string role inferred from final terminator. |
| [o2 0x6EC9D0](../recomp/config/output_ovl/o2/o2_006EC9D0_0x6ec9d0.cpp) | `clear_scene_text_counter_and_first_byte_candidate` | Confirmed/static mechanics | Clears word759BE0 and byte759BE4 only. Leaves remainder of the80-byte buffer unchanged. No pool reset. |
| [o2 0x6EC9F0](../recomp/config/output_ovl/o2/o2_006EC9F0_0x6ec9f0.cpp) | `scene_context_noop_entry_6ec9f0` | Confirmed/static mechanics | JR ra with nop delay slot; no argument, memory or return-value write. Original API role unknown. |
| [o2 0x6ECA00](../recomp/config/output_ovl/o2/o2_006ECA00_0x6eca00.cpp) | `dispatch_actor_context_callback_and_consume_d92_notification_candidate` | Probable role; mechanics verified | a0 full-width selector indexes unbounded word table7344B0. Calls selected pointer with(a1 actor/context,a2), preserves unsigned low8 callback result. If context halfD92 nonzero afterward, calls67E230(context,7) then clears halfD92. Returns preserved lowbyte. Does not establish table length, callback taxonomy or context ownership. |
| [o2 0x6ECA70](../recomp/config/output_ovl/o2/o2_006ECA70_0x6eca70.cpp) | `mark_selected_actor_context_notification_bit80_candidate` | Confirmed/static mechanics | a0 pointer must exactly equal fixed actor4A5C30+10E0*global byte4BADED. Then ORs actor halfD92 with80 and sets global byte4BAE70=1. Other pointers unchanged. No actor activity or selected-index bounds check inside. |

## Verification and limits

All32 named entries were reviewed within indexed ownership boundaries and
instruction words checked against the owned o2 blob. The eight-case inventory
predicate table was decoded from that same file. Import and link checks do not
recover original names or prove runtime reachability. The scene text and position
record roles are candidate interpretations; no measured performance cost or
controlled fix/retest is claimed.
