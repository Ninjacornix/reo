# Inventory page controller, selection identity and recipe finalization

Static File #1 US research, 2026-11-04. Five complete original bodies reviewed.
Addresses/offsets hexadecimal. No game/build/replay/attachment/live-memory work.
W=755EC0, P=pointer at755770, G=3B85A0. Actor stride10E0, UI item strideB8.
Numeric actor categories, operation codes and input masks are retained literally.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6E4930](../recomp/config/output_ovl/o2/o2_006E4930_0x6e4930.cpp) | `reset_inventory_cursor_flags_after_selected_player_change_candidate` | High mechanics; probable role | Clears G0,759C9A,755E83/6C/72/80,W2; sets755E82=1 and tailcalls1B8820. This resets slot/secondary/menu flags, with no item transfer or snapshot rebuild. |
| [o2 0x6E4980](../recomp/config/output_ovl/o2/o2_006E4980_0x6e4980.cpp) | `selected_inventory_record_differs_from_type_id_and_value_candidate` | High; full body reviewed | a0 expected byte0, a1 expected byte1, a2 expected half2. Dereferences primary UI record755E64 and returns1 if any field differs, else0. Order is byte0, half2, byte1; no pointer guard. Used to invalidate an action menu when its source record changes. |
| [o2 0x6E49D0](../recomp/config/output_ovl/o2/o2_006E49D0_0x6e49d0.cpp) | `tick_inventory_page_ordinary_storage_selection_and_action_menus_candidate` | Probable role; full body reviewed | W1 phases0 initialization,1 ordinary selection,2 storage selection; other phases return. Init clears755E60..+5B and P3B58 bytes, selects local player, seeds four slot counts4, resets G0/W3DDA, FF-clears four visible-player IDs. Actor54F==9 instead prepares special recordP22A0 from C7A through5B4380/6E0880, selects first empty ordinary ID, enters W2=2 and resets cooperation globals. Ordinary phase calls6EC680/0340 and detects player changes via4930, refreshes descriptions0B90, builds primary pointer P20+8A0*player+B8*cursor. W2=0 handles close/page requests, wide navigation, player cycling5FC0 and entry into action menus; local input100 can initiate literal actor state8=1/9=24 after5F6E90 and5F1C50 admission, then closes UI. W2=1 calls2740 and compares saved source fields through4980; changed source clears secondary flags, modal state and timer. W2=2 handles actor-assisted selection and pair-recipe admission, including5B3DD0 classification and bounded count/width arithmetic. Storage phase W2=0 handles storage selection and category-dependent bank entry, W2=1/3 calls3610, W2=2 navigates bank records. Category7 uses storage index9*cursor+1; others cursor+1. It restores pointers/cursors after menu completion or changed identity and callsEC9D0. All branches reviewed, including input400/800 page requests, local-only ordinary-to-storage transition and literal item-record presence tests. |
| [o2 0x6E5DC0](../recomp/config/output_ovl/o2/o2_006E5DC0_0x6e5dc0.cpp) | `apply_inventory_storage_pair_recipe_and_finalize_item_slots_candidate` | Probable role; full body reviewed | a0 actor,a1 source ID byte pointer. Saves source toDA2 and C88[G2] toDA3, then5B28F0(source,selected storage ID), signed-byte result. Result0 error sound;1 refreshes through6ECA70;2 removes source, optionally clears matching C7C/CA8 via5B1A90, moves C88[G2] toCA4 and clears that selected slot;3 clears selected storage slot, optionally clears selected C7C/CA8, and moves source toCA4 unless source already points there. Result2/3 compact through5F2330; all1..3 refresh via6ECA70, optionally clear D92 after67E230(actor,7), emit success sounds and1B87E0(5,0). No stable success-return contract inferred from residual v0. Underlying pair recipe is already mapped separately. |
| [o2 0x6E5FC0](../recomp/config/output_ovl/o2/o2_006E5FC0_0x6e5fc0.cpp) | `find_adjacent_visible_inventory_player_from_direction_mask_candidate` | High mechanics; probable role | a0 input mask. Finds selected P5 among four entriesP14..17; scans cyclic rank modulo4 forward when mask8 set, backward otherwise, skipping FF and stopping before returning to original rank. Returns the visible player ID byte, not its rank; -1 if no other entry. Both searches bounded to four iterations. If selected ID was absent, original starting rank4 remains literal; no extra normalization guard added. |

The page controller delegates action mechanics to
[primary/storage action states](SYMBOLS_INVENTORY_ACTION_STATES.md), cursor rules
to [cursor control](SYMBOLS_INVENTORY_CURSOR_CONTROL.md) and pair recipes to
[owned inventory recipes](SYMBOLS_INVENTORY_USE_RECIPES.md). At6E54B0 its item-width
scan starts from the current primary record pointer and advances B8 for the
selected player's declared slot count; it is not silently rewritten here as a
scan starting from the inventory base. Allocation and gameplay implications need
caller-state evidence. None of these static observations proves a slowdown cause.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
