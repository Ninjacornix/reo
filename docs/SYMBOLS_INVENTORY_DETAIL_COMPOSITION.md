# Inventory detail text, action labels, quantities and player panels

Static File #1 US research, 2026-11-04. Four complete original bodies reviewed.
Addresses and offsets hexadecimal. W=755EC0, P=pointer at755770. No game/build/
replay/attachment/live-memory work. Labels describe measured instruction effects
and probable UI roles, without assigning original actor or item enumeration names.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6E7BB0](../recomp/config/output_ovl/o2/o2_006E7BB0_0x6e7bb0.cpp) | `compose_inventory_selected_item_pair_prompts_quantity_and_description_candidate` | Probable role; full body reviewed | IfP3A93 nonzero decrements and exits; otherwise sets font14/Y14A. Special recordP22A0 active bit and3A8A gate produce leading name line, moving Y by14. Primary755E64 required, active bit plus G0!=selected slot count admit normal detail. Formats inline name+8; numeric admission7940/7A20 adds localized quantity label and signed half4 using owned formats742B98/BA0. Secondary755E83 path draws primary and optional755E68 names on separate lines with localized operation9-dependent prompts. Special-item path chooses localized prompts via759C96/97,4BAE84, pair classifier7AC0 and numeric half2 range190..1C1; ordinary item path prints selected name. Depending W1/W2, active record54 description is drawn at Y+28 only when transient-message timer759BE0==0. Predicate78E0 modal mode takes separate name-only branch. Original checks compare addresses record+8/+54 with zero, not first string bytes; numeric fallback format branches are retained, not assumed to detect empty names. All color/position and empty-slot branches reviewed; no input mutation/item transfer here. |
| [o2 0x6E8470](../recomp/config/output_ovl/o2/o2_006E8470_0x6e8470.cpp) | `draw_local_inventory_quantities_selected_item_badges_and_storage_bank_counts_candidate` | Probable role; full body reviewed | a0 player must equal local4BADED. With755E61==0 traverses declared ordinary slot count atP20+8A0*player, skips inactive records, formats signed half4 as owned '%03d' only when7940 admits, draws82F0; actorC7C==record1 adds8400 badge. Then repeats for extra recordP2358. With selection mode nonzero startsP2410: category7 counts active records in three consecutive banks of nine and draws only nonzero counts, other categories traverse ordinary declared slot count, applying7940 and C7C badge tests without a separate active-byte guard. No resource-use/quantity modification. |
| [o2 0x6E8710](../recomp/config/output_ovl/o2/o2_006E8710_0x6e8710.cpp) | `draw_inventory_action_popup_from_ff_terminated_numeric_action_list_candidate` | High mechanics; probable role | Requires755E80 nonzero, selected list pointer732AF0[755E81] nonnull, P3A58<5. Configures font10/color80808080, copies background/highlight C-byte descriptors733340/334C. For each nonFF action byte, owned733320+4*ordinal gives XY; draws background and current755E62 highlight, places textX+12/Y+4, resolves1C1DE0(action-1), except UI mode9/action4 resolves localizedB. Advances action byte and ordinal once. Sentinel list and position-table extent are caller/owned-data contracts; no local maximum or action effects. |
| [o2 0x6E8B30](../recomp/config/output_ovl/o2/o2_006E8B30_0x6e8b30.cpp) | `compose_visible_player_inventory_panel_badges_slot_frames_and_selection_highlights_candidate` | Probable role; full body reviewed | a0 player,a1 visible rank. Adds owned733100 rank XY to five descriptors733130..+3B; first color from733110[755EA9[player]], second white, third atlas ID adjusted by actorB98 and omitted when actorBB4 nonzero, fourth atlas ID adjusted by755EB1[player] capped78, fifth atlas ID adjusted by755EA9 with atlas dimensions. Nonlocal cooperation flag755EB5==1 or nonlocal category6 selects eight slot frames7331D0/highlights7332B0; normal path four frames733190/highlights733270. Offsets733180 position frames, primary755E6C highlights white when755E82 and mode permits, secondary755E72 highlightsFFFF0000 when755E83. Extra-slot highlight73324C handled separately. Calls7370(player,rank) for item icons and labels; local nonstorage state additionally draws733240 and optional highlight. All sentinel loops and branch-dependent counts reviewed; no actual actor ownership/state update. |

Owned table decoding confirms five initial panel descriptors, four normal slot
frames and eight alternate frames. Owned strings include '%s', '%03d', '\n %s %d',
'\n %s %3d', '\n%s', '/', and '<< EMPTY >>'. The original code sometimes tests
an inline buffer address for zero; that is preserved as an observed condition,
without treating it as validation of the text contents or a reproduced defect.

These complete the remaining composers called by
[inventory/document draw](SYMBOLS_INVENTORY_DOCUMENT_DRAW.md), using the shared
[icon, badge and numeric admission helpers](SYMBOLS_INVENTORY_ICON_AND_DRAW_HELPERS.md).
Original font calls are subject to the
[native font override boundary](SYMBOLS_FONT_OVERRIDE_BOUNDARY.md). No UI path
cost or relation to captured world/cutscene slowdowns was measured here.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
