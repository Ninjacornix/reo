# Inventory item actions and storage transfer state machines

Static File #1 US research, 2026-11-04. Six complete original bodies reviewed,
including all arms of four owned jump tables. Addresses and offsets hexadecimal.
No game, build, replay, attachment or live-memory inspection. Numeric action and
actor-category values retain their original values; candidate roles do not assign
original button, character or command names.

Here W is UI work 755EC0, P is the pointer at 755770, and G is modal work 3B85A0.
The selected actor is 4A5C30+10E0*P[5]. Inventory UI records have stride B8;
actor C84 is the ordinary item-ID array and C88 begins the storage item-ID array.
Input masks 20/10 are described as confirm/cancel candidates from their effects.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6E2180](../recomp/config/output_ovl/o2/o2_006E2180_0x6e2180.cpp) | `handle_inventory_alternate_confirm_or_cancel_and_close_candidate` | Probable role; full body reviewed | a0 W, a1 item UI record. Sets 759C94=1. Input W3CE0 bit20 admits nonzero signed byte 3C5630[3C*record1] to 681090(local,selected player,record half2,record byte1,t0=1), with success/error sounds; decrements G4, calls 6EC9D0 and closes through 6E1430. Nonzero record type also emits 6DFDC0(selected actor,1). Independently tests bit10 afterwards, with another decrement/reset and return0; otherwise returns1, including no input. Compared with 6E2000, t0 and message operation are1 rather than0, and no local 6DF7E0 call occurs. |
| [o2 0x6E22D0](../recomp/config/output_ovl/o2/o2_006E22D0_0x6e22d0.cpp) | `tick_inventory_actor_assisted_selection_and_completion_candidate` | Probable role; full body reviewed | a0 W, a1 item record; G5 phases0..3. Phase0 saves record1 to local actor C7A, calls 67FF80(actor,1,C7A), sets P3B2D, initializes actor halfC to decimal600/1200 by 3243CC and advances. Phase1 synchronizes G1=P5, clears incompatible B34/B35 state, advances on B34==1, decrements halfC and exits on post-decrement zero or B34==2. Phase2 polls 6E25F0(actor,0), cancels with operation2 on completion; captured input759BA0 bit20 instead selects local player and enters phase3. Phase3 uses 6E1BF0/1540 to navigate/place the ordinary cursor; bit20 commits through 25F0(actor,1), clears P3B2D and optionally D92 via 67E230(actor,7); bit10 cancels through 67FF80(actor,2,C7A). This is a tick state machine, not a blocking retry loop. |
| [o2 0x6E25F0](../recomp/config/output_ovl/o2/o2_006E25F0_0x6e25f0.cpp) | `poll_or_commit_inventory_actor_assisted_item_selection_candidate` | Probable role; full body reviewed | a0 actor, a1 mode. Mode0 calls 5F46B0(actor,0); with 4BAE84<2 and actor F78 bit20 clear, bit10 of F78 completes/cancels; otherwise captured input759BA0 bit10 does so. Completion calls 67FF80(actor,2,C7A), returns1; waiting returns0. Mode1 emits 1B87E0(5 or8,0) by 4BAE85==1, saves selected C84[G0], calls 5F2B70(actor,ID), conditionally emits operation2 if the same nonzero ID remains, always emits operation2 for C7A, clears 4BAE84 and returns1. Other modes return0. |
| [o2 0x6E2740](../recomp/config/output_ovl/o2/o2_006E2740_0x6e2740.cpp) | `tick_inventory_primary_item_action_menu_and_transfers_candidate` | Probable role; full body reviewed | a0 current item UI record. Configures font and uses G4 modal depth, P3A58 states0..8 and G8[G1] numeric actions0..8. Depth1 routes W5=F/11/10 to 6E2000,2180,22D0; other cases call 5F46C0. Depth2 handles wide-item cursor for action4, actor action polling through 5F3020 and cancel/reset. Main state1 admits active record plus input20, rejects action6 when 5F1C50 is nonzero, increments depth and dispatches the owned action table. State2 places a secondary cursor and pointer, with ordinary slot versus storage branches; special actor categories move C84[G0] to an empty C89 slot and clear source, calling 5F2330/6ECA70. Other categories admit literal UI item IDs12C/12D/12E into three distinct storage banks. States3/4 display localized E/F text for exact actor-state gates; state6 confirms through 6ECA00(2,actor,&C84[G0]); state8 polls completion. Reset paths clear secondary selection, P1 and timer3A66. All delay-slot decrements and conditional returns retained; no original action-enum or runtime-defect claim. |
| [o2 0x6E3560](../recomp/config/output_ovl/o2/o2_006E3560_0x6e3560.cpp) | `find_empty_actor_storage_slot_in_numeric_item_bank_candidate` | High mechanics; probable role | a0 actor, a1 numeric bank. Supported banks0/1/2 test three item bytes beginning C89/C92/C9B and return absolute C88 index1..3/A..C/13..15 for first zero, else -1. Bank3 tests CA4 and returns1C/-1. The three-entry loop is pretested. Invalid bank values do not receive a safe generic rejection: original fallback retains the supplied a1 as a read address before the loop, so no broader input-domain guarantee is inferred. |
| [o2 0x6E3610](../recomp/config/output_ovl/o2/o2_006E3610_0x6e3610.cpp) | `tick_inventory_storage_item_action_menu_and_hand_bank_transfers_candidate` | Probable role; full body reviewed | a0 current storage item UI record. Configures font, uses P3A58 states0..A and FF-terminated action lists at 732AF0. State1 navigates P3A5C, dispatches action0..A; actor category7/W2==3/inactive record forces list index3. Actions other than4/8/9/A call 6ECA00(action,actor,&C88[P3A8B]); category4/action4 enters a separate stateA path. State2 selects secondary ordinary slots or category7 bank indices9*P12+1, with 6E5DC0 admission and literal storage handling. States3/4 show localized E/F or commit operation3; state6 confirms operation2 against ordinary or stored item pointers. State8 swaps C84[hand cursor] and C89[storage cursor], rejecting the currently selected C7C ID; state9 transfers between hand and three storage banks via 3560, accepting only UI IDs12C/12D/12E on its nonempty-hand path. Successful moves call 5F2330. StateA navigates hand selection then calls operation4 on the stored-item pointer. Cancel/reset paths restore cursors/pointers and clear secondary flags, P1 and timer. Full body reviewed; no assumption that numeric actions are original named use/combine/give commands. |

The original jump tables were decoded directly from owned o2 bytes. These are
internal branch arms in the two large functions, not extra function mappings.

| Owned table | Numeric index in order | Original branch destinations in order |
| --- | --- | --- |
| 742AB0: primary action | 0..8 | 6E2CB8,6E2CB8,6E2D1C,6E2CC8,6E2CE4,6E2D78,6E2D98,6E2DBC,6E2DB4 |
| 742AE0: primary state | 0..8 | 6E2B28,6E2B54,6E2E1C,6E3318,6E3368,6E33C8,6E33EC,6E3498,6E34A4 |
| 742B10: storage action | 0..A | 6E3A14,6E3A14,6E3A74,6E3A24,6E3A40,6E3B28,6E3B48,6E3C2C,6E3B64,6E3B98,6E3BFC |
| 742B40: storage state | 0..A | 6E36BC,6E3728,6E3C94,6E3F60,6E3FBC,6E4008,6E4028,6E4184,6E4198,6E43B0,6E474C |

Primary action4 selects secondary-item state2, action3 state4, action6 state3,
action5 starts timer120 and 759C94, and action2 can commit directly when record48
bit4 is present. Storage actions8/A select swap/bank-transfer states8/9; action9
commits operation2 for C88[9*storage cursor+1]. These assignments describe exact
state transitions while leaving their original labels unknown. Countdowns here
are per invocation; no assertion about frame rate or global game-update count.

Related cursor and snapshot contracts are in
[inventory cursor control](SYMBOLS_INVENTORY_CURSOR_CONTROL.md) and
[inventory UI snapshots](SYMBOLS_INVENTORY_UI_SNAPSHOTS.md). Called action helpers
require their own review before drawing stronger gameplay or performance claims.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
