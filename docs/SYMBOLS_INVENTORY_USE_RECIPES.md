# Inventory use, recipe application and owner admission

Static File #1 US research, 2026-11-04. This continues
[inventory quantity operations](SYMBOLS_INVENTORY_QUANTITY.md). Original executable
and overlay identities are recorded in [the central index](FUNCTION_INDEX.md).
Only generated instruction comments and owned file-backed bytes were inspected;
no game, build, replay, attachment or live-memory inspection was performed.

Resource records below are at `0x3C5630 + 60 * lowByteID`: activity byte0,
self-ID byte2, content halfword6, flags word18, model pointer1C, signed quantity
halfword24, owner halfword28 and template selector byte2B. Numeric content,
recipe, actor-class and event identifiers are preserved without guessing their
original enum names. Candidate labels describe reviewed behavior.

## Full owned-pair recipe dispatcher

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5B28F0](../recomp/config/output_ovl/o2/o2_005B28F0_0x5b28f0.cpp) | `apply_owned_resource_pair_recipe_dispatch_candidate` | Probable role; full body and jump table reviewed | Lowbyte a0/a1 IDs must both active and owned, but need not share owner. Classifies through 5B3E40(first,second,extraOut), dispatches lowbyte types below18 through owned table73E4F0. Uses signed-byte helper results; reversed operations translate destruction result3 to2, except reversed type13 translates2 to3. Nonzero result calls 5B6740(recipe,extra,oldContent,actor). Actor is first owner's array entry if first remains active, otherwise second's; this post-operation owner lookup has no upper-bound guard. TypesF/10 save the target's old content in a2 for that event callback; other cases pass0. No direct actor inventory compaction here. |
| [o2 0x5B2D00](../recomp/config/output_ovl/o2/o2_005B2D00_0x5b2d00.cpp) | `merge_owned_pair_quantity_to_first_capacity_candidate` | Probable role; mechanics verified | a0 destination/a1 source records. Requires source signed quantity>0 and destination below its template capacity8. Adds quantities, narrows sum to signed16 before capacity comparison, caps destination and leaves excess in source. Returns1 if source remains positive; otherwise destroys source through5B1AF0(selfID) and returns3. No matching-content, activity, ownership or alias guard inside this helper. |
| [o2 0x5B2DC0](../recomp/config/output_ovl/o2/o2_005B2DC0_0x5b2dc0.cpp) | `merge_matching_owned_pair_unless_either_at_capacity_candidate` | Probable role; mechanics verified | Requires equal unsigned content halfwords. Rejects if either quantity equals first template capacity; values above capacity are not the equality rejection. Signed16-narrowed sum is distributed to first capped quantity and second remainder. Second positive returns1, otherwise destroys second through5B1AF0 and returns3. No independent positive-quantity admission, so preserve signed arithmetic and exact equality tests. |
| [o2 0x5B2E70](../recomp/config/output_ovl/o2/o2_005B2E70_0x5b2e70.cpp) | `replace_first_owned_content_and_destroy_second_candidate` | Confirmed/static mechanics | a0/a1 record pointers, a2 signed low16 new content. Negative content returns0; otherwise calls5B4BF0(first selfID,newContent), ignores its result, destroys second through5B1AF0 and returns3. Does not independently check activity, ownership or distinct records. |
| [o2 0x5B2EC0](../recomp/config/output_ovl/o2/o2_005B2EC0_0x5b2ec0.cpp) | `replace_owned_content_by_record_id_recipe_adapter_candidate` | Confirmed/static mechanics | Nonnegative signed low16 a2 calls5B4BF0(a0 byte2,a2) and returns1 even if callee does nothing; negative returns0. a1 is unused. No destruction or quantity transfer here. |
| [o2 0x5B2F00](../recomp/config/output_ovl/o2/o2_005B2F00_0x5b2f00.cpp) | `replace_first_content_and_redistribute_pair_quantities_candidate` | Probable role; full body reviewed | Requires second quantity>=0 and first content17..1B, mapping those first types to replacement101..105. Saves first quantity, zeroes it, directly replaces first content with a2, fills it from second up to its new template capacity and calculates signed16 excess. If saved first quantity>0, directly replaces second content with101..105 and sets second quantity to that saved amount; calculated excess is not additionally retained in this branch. Otherwise stores positive excess in second, or destroys second and returns3. Other successful paths return1. a2 has no local nonnegative validation. |
| [o2 0x5B3080](../recomp/config/output_ovl/o2/o2_005B3080_0x5b3080.cpp) | `swap_pair_quantities_when_second_below_capacity_candidate` | Confirmed/static mechanics | a0/a1 records. If second signed quantity is below second template capacity and first quantity>0, swaps the quantities without clamping the new second amount. Always returns1, including the no-change paths. No matching-content or activity guard. |
| [o2 0x5B30F0](../recomp/config/output_ovl/o2/o2_005B30F0_0x5b30f0.cpp) | `fill_first_quantity_using_second_template_capacity_candidate` | Probable role; mechanics verified | Second quantity must>0; first must be below capacity read from second's template. Transfers min(second quantity,signed16(capacity-first quantity)), with halfword stores. Returns0 when admission fails,1 when source remains, or destroys second through5B1AF0 and returns3. Capacity comes from second, unlike5B2D00; no matching-content guard inside. |
| [o2 0x5B31B0](../recomp/config/output_ovl/o2/o2_005B31B0_0x5b31b0.cpp) | `replace_target_content_when_first_type195_candidate` | Confirmed/static mechanics | First record content must195 and a2 signed low16 must nonnegative. Directly replaces second record content through5B4C90 and returns1, else0. Does not decrement or destroy the first record. |
| [o2 0x5B3200](../recomp/config/output_ovl/o2/o2_005B3200_0x5b3200.cpp) | `apply_owner_bank199_recipe_and_destroy_second_candidate` | Probable role; full body reviewed | First owner must<5 and a2 signed low16 nonnegative. Scans corresponding actor's32 C88 slots for active content199 with positive quantity; decrements first match. If exhausted, calls5F2180(actor,slotID), then reads the same saved slot address for5B1AF0's ID (see caveat below). Missing content199 does not prevent the recipe. For new content1D, preserves first quantity if first old content1C, otherwise second quantity. Calls5B4BF0(first selfID,newContent), optionally restores that quantity, destroys second through5B1AF0 and returns3. Owner0 is not rejected before owner-1 array arithmetic. |
| [o2 0x5B3380](../recomp/config/output_ovl/o2/o2_005B3380_0x5b3380.cpp) | `consume_type19a_quantity_to_replace_target_content_candidate` | Confirmed/static mechanics | First record content must19A and signed low16 new content a2 must nonnegative. Directly replaces second content, then decrements first signed quantity without a positive-quantity guard. Positive remainder returns1; otherwise5B1AF0(first selfID) and return2. Activity/ownership are admitted by caller, not locally. |
| [o2 0x5B3400](../recomp/config/output_ovl/o2/o2_005B3400_0x5b3400.cpp) | `replace_pair_content_with_reverse_type14_followup_candidate` | Probable role; mechanics verified | Negative signed low16 a2 returns0. Otherwise directly replaces first content, then reclassifies(second,already-modified first,&extra). If signed classification is14 and extra nonnegative, directly replaces second too. Returns1 regardless direct replacement results. No active/owner checks locally. |

The complete `0x73E4F0` table was decoded from the owned o2 blob. Argument
order below uses A=first, B=second, X=classifier extra halfword.

| Recipe type | Owned branch | Operation |
| --- | --- | --- |
| 00,15 | 5B2C5C | No operation |
| 01,16 | 5B29B4,5B2C20 | 5B2D00(A,B) |
| 02,17 | 5B29CC,5B2C38 | 5B2D00(B,A), translate3 to2 |
| 03 | 5B29F4 | 5B2DC0(A,B) |
| 04,05 | 5B2A0C,5B2A28 | 5B2E70(A,B,X) |
| 06 | 5B2A44 | 5B2E70(B,A,X), translate3 to2 |
| 07 | 5B2A70 | 5B2F00(A,B,X) |
| 08 | 5B2A8C | 5B2F00(B,A,X), translate3 to2 |
| 09,0A | 5B2AB8,5B2AD4 | 5B2EC0(A,B,X), respectively(B,A,X) |
| 0B,0C | 5B2AF0,5B2B08 | 5B3080(A,B), respectively(B,A) |
| 0D | 5B2B20 | 5B30F0(A,B) |
| 0E | 5B2B38 | 5B30F0(B,A), translate3 to2 |
| 0F,10 | 5B2B60,5B2B80 | 5B31B0(A,B,X), respectively(B,A,X); save target old content |
| 11 | 5B2BA0 | 5B3200(A,B,X) |
| 12 | 5B2BBC | 5B3380(A,B,X) |
| 13 | 5B2BD8 | 5B3380(B,A,X), translate2 to3 |
| 14 | 5B2C04 | 5B3400(A,B,X) |

`0x5B3200`'s exhausted-199 path saves the address of the matching C88 slot,
removes the ID through `0x5F2180`, then reloads the ID from that address. The
reviewed removal helper clears that slot before returning; its selected-instance
release calls do not refill it. Consequently the subsequent destruction request
uses zero for this ordinary successful removal sequence. This is a static
candidate defect to investigate with a controlled case, not a reproduced crash
or an explanation for the player's slowdown. No code was changed.

## Alternate pair path and content replacement

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5B3490](../recomp/config/output_ovl/o2/o2_005B3490_0x5b3490.cpp) | `apply_active_resource_pair_recipe_types_three_four_candidate` | Probable role; mechanics verified | Lowbyte a0/a1 IDs must active. ORs flags18 bit1 in both before classification. Signed16 classifier result is masked lowbyte:3 calls5B3590(first,second),4 calls5B3640(first,second,extra), all others0. Returns signed-byte helper result. No owner admission and no event callback. Flag writes occur even when no recipe is applied. |
| [o2 0x5B3590](../recomp/config/output_ovl/o2/o2_005B3590_0x5b3590.cpp) | `merge_same_content_resource_quantity_with_signed16_sum_candidate` | Confirmed/static mechanics | a0/a1 records require identical unsigned content. Adds signed quantities and narrows sum signed16 before comparing first template capacity. First receives cap or sum, second receives excess or0. Positive second remainder returns1; otherwise calls general destruction5B1B50(second selfID) and returns2. Unlike5B2DC0, no rejection for either quantity already equal to capacity. No local activity/ownership/alias guard. |
| [o2 0x5B3640](../recomp/config/output_ovl/o2/o2_005B3640_0x5b3640.cpp) | `replace_first_content_and_destroy_second_general_candidate` | Confirmed/static mechanics | Negative signed low16 a2 returns0; otherwise directly replaces first content through5B4C90, destroys second through general5B1B50 and returns2. Direct replacement result ignored; activity/ownership admitted only by caller. |
| [o2 0x5B3DD0](../recomp/config/output_ovl/o2/o2_005B3DD0_0x5b3dd0.cpp) | `query_active_resource_id_pair_compatibility_candidate` | Confirmed/static mechanics | Lowbyte a0/a1 IDs must active. Calls5B3E40(recordA,recordB,stackExtra) and returns its raw result; discards extra. No ownership or quantity admission and no content/slot mutation. |
| [o2 0x5B42B0](../recomp/config/output_ovl/o2/o2_005B42B0_0x5b42b0.cpp) | `lookup_template_index_from_normalized_content_id_candidate` | Confirmed/static mechanics | Input is signed low16 content ID, not resource slot ID. Values>=2710 normalize to signed16((id%100)+1F4). Negative or>=258 after normalization returns0; otherwise returns signed byte74B6E0[id]. Zero is both fallback and a possible table value. No activity or template validity check here. |
| [o2 0x5B4BF0](../recomp/config/output_ovl/o2/o2_005B4BF0_0x5b4bf0.cpp) | `replace_owned_resource_content_and_reset_quantity_candidate` | Probable role; mechanics verified | Lowbyte a0 ID must active, existing unsigned content must differ from signed low16 a1, and owner must nonzero. Calls direct5B4C90(record,newContent), then sets quantity from5B4E60(ID), returns1. Inactive, same-content or unowned returns0. No local nonnegative new-content guard. |
| [o2 0x5B4C90](../recomp/config/output_ovl/o2/o2_005B4C90_0x5b4c90.cpp) | `replace_resource_content_template_and_attached_instance_candidate` | Confirmed/static mechanics | a0 record pointer, a1 content. Writes content6 unconditionally, computes selector through5B42B0, writes byte2B. Nonzero model pointer1C calls591510(model,low16 content). Does not reset quantity, validate activity/owner or allocate an instance. Callers needing quantity reset use5B4BF0. |
| [o2 0x5B4E60](../recomp/config/output_ovl/o2/o2_005B4E60_0x5b4e60.cpp) | `get_resource_template_initial_quantity_with_3717_override_candidate` | Probable role; mechanics verified | Lowbyte ID must active and template selector!=FF, else0. Ordinary result is signed template halfword8 at74BB50+24*selector. Content3717 instead returns4B0 when global byte3243CC==0, otherwise258. No quantity mutation here and no assumption that the global byte is elapsed time. |
| [o2 0x591510](../recomp/config/output_ovl/o2/o2_00591510_0x591510.cpp) | `rebind_resource_instance_content_and_indexed_blocks_candidate` | Probable role; full body reviewed | Null model pointer is ignored. Writes content36; resolves resource template through model byte240 and writes word14 from709580[template signed byte14]. Resolves signed content to index through mapped o0 helper372490 and stores half242. Negative index clears model byte1. Otherwise byte1=1, then for each signed-count block at3DBB14+2*index, sets model byte30+i=1 and copies64 bytes from3C9A50+180*index+40*i to model40+40*i. No local destination-count capacity check. |

## Resource-use configuration and inventory admission

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5B3AA0](../recomp/config/output_ovl/o2/o2_005B3AA0_0x5b3aa0.cpp) | `use_resource_instance_and_decrement_quantity_unless_mode_override_candidate` | Probable role; mechanics verified | Lowbyte a0 active resource, optional a1 XYZ/a2 parameter pointers passed to5B3B80. When1B02D0()==1 and global4BAE96 bit1, configures instance without decrement and returns2. Otherwise decrements signed quantity even if already nonpositive, configures instance and returns2 for positive remainder or1 otherwise. Does not destroy the depleted record. Inactive returns0. |
| [o2 0x5B3B80](../recomp/config/output_ovl/o2/o2_005B3B80_0x5b3b80.cpp) | `configure_resource_instance_use_vectors_and_flags_candidate` | Probable role; mechanics verified | Lowbyte active resource: clears record flags18 bit20000, including when model pointer1C is null. Existing model clears23C bits20000/800, ORs180000 and zeroes halfwordC. Copies12 bytes from a1 to20C, or zeroes them; copies8 bytes from a2 to224, or zeroes them. No allocation, model release, quantity change or content replacement. Physical interpretation of the vectors/parameters remains provisional. |
| [o2 0x5B3C70](../recomp/config/output_ovl/o2/o2_005B3C70_0x5b3c70.cpp) | `remap_active_resource_content_zero_one_b_candidate` | Confirmed/static mechanics | Active lowbyte ID: content0->1C5,1->1C8,B->1C6 through direct5B4C90, returning1. Other content or inactive returns0. No quantity/ownership admission or independent instance allocation. |
| [o2 0x5B3D00](../recomp/config/output_ovl/o2/o2_005B3D00_0x5b3d00.cpp) | `start_owned_resource_action_nine_at_owner_location_candidate` | Probable role; mechanics verified | Active lowbyte ID must owned. Owner<5 resolves array4A5C30+(owner-1)*10E0, otherwise682F80(owner-5). If owner actor exists, copies XYZ38..40 to resource8/C/10 and adds90 to Y. Regardless missing dynamic actor, sets resource byte2C=9 and calls591860(record). Does not decrement quantity or directly destroy model. |
| [o2 0x5F2210](../recomp/config/output_ovl/o2/o2_005F2210_0x5f2210.cpp) | `find_actor_inventory_resource_id_by_content_candidate` | Confirmed/static mechanics | a0 actor, unsigned low16 a1 content. Scans4 C84 slots then32 C88 slots, skipping zero IDs; returns first resource ID whose unsigned content6 matches, or0. Does not verify record activity, ownership or positive quantity. Returns ID, not normalized boolean or slot index. |
| [o2 0x682F80](../recomp/config/output_ovl/o2/o2_00682F80_0x682f80.cpp) | `find_active_linked_actor_by_bb4_identifier_candidate` | Confirmed/static mechanics | Walks linked head3B59F0 through next pointer1C; first node with signed activity byte0 nonzero and unsigned halfBB4 equal full a0 returns its pointer. No low16 mask on input, category or room test; otherwise0. This is a linked-pool lookup, unlike the fixed four-actor array. |
| [o2 0x593060](../recomp/config/output_ovl/o2/o2_00593060_0x593060.cpp) | `admit_actor_resource_by_duplicate_flag_and_room23_exclusions_candidate` | Probable role; full body reviewed | a0 low16 zero-based actor index:0..3 fixed array,>=4 linked lookup682F80(index-4). a1 lowbyte resource must active; actor must exist. Template flag08000000 rejects when5F2210 finds any same content in actor inventory. Outside global room3243DA==23, otherwise accepts. In room23, content34BE rejects if inventory contains34BC or34BD;34BC/34BD reject if inventory contains34BE. Other content accepts. No inventory free-slot, quantity or existing-owner test: this is content admission, not full pickup feasibility. |
| [o2 0x5B6740](../recomp/config/output_ovl/o2/o2_005B6740_0x5b6740.cpp) | `record_local_actor_resource_recipe_events_candidate` | Probable role; body and jump table reviewed | a0 recipe,a1 extra/new content,a2 old content,a3 actor. Requires mapped1B0340(actor) local admission. ClassB98=3 recipesF/10 map extra136->event13,137->15,13A->14,13B->16,13C->17,13D->18 via73E590; event argument1=oldContent low16, argument2=0. Class4 recipes11/12/13 map extras71->event1A,1D->1B,73->1C,0/1->1D,B->1E, args0. Remaining fallthrough supports recipes9/A extra72->event19,args0. Calls mapped o0 cooperative-event append37C060; these are event records, not proven audio or rendering calls. |

The alternate pair path uses general destruction `0x5B1B50`, whereas the owned
recipe path mostly uses `0x5B1AF0`. Its different return numbering and ownership
admission are preserved. An optimization or reconstruction should not replace
these related helpers solely because their central quantity arithmetic resembles
each other.

## Verification and limits

All29 named entries above were reviewed within their indexed ownership ranges.
Instruction-comment words were checked against the owned file-backed o2 bytes;
the two indirect tables were read from the same blob. Index import and source
links are checked separately. No performance measurement, original symbol
recovery or controlled fix/retest is claimed. Signed16 narrowing, signed-byte
dispatch results and mutations on unsuccessful paths are intentional parts of
the recorded guest behavior.
