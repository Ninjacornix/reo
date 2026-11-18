# Map composition, options/catalog drawing and shared render callback

Static File #1 US research, 2026-11-04. Ten complete original bodies reviewed,
including every arm of the owned seven-target options table. Addresses/offsets
hexadecimal. W=755EC0, P=pointer at755770, M=pointer at755768. No game/build/
replay/attachment/live-memory work. Render selectors retain numeric identities.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6EA300](../recomp/config/output_ovl/o2/o2_006EA300_0x6ea300.cpp) | `compose_interactive_map_tiles_markers_players_controls_and_labels_candidate` | Probable role; full body reviewed | Starts scale f20=M6C clamped to minimum1, emits two193F90 background rectangles, clears MD8/F8 labels. Derives origin from map pan2C/2E and offsets16/18 times actual M6C; calls6D9A80(tile scaleM1C,M20*M6C),6DB450 flush,6DA500 markers. First fixed64-entry M128 pass selects nonFF8-byte759D50 records with bit80, maps low7 through734480 atlas, projects integer XZ via6D97A0, scales/centers dimensions in zoom level2 and clips sprites to280x1C0. If M14==M1A, composes two rotated local-player triangle templates734450 using actor yaw92+4000 and owned2pi/10000, width aspect29F9BC/640. Then iterates four nonlocal players, choosing animated marker/status atlas by M168 and M70, projects6D9680 and clips. Draws owned control groups7333E0/7335C0, substitutes controller-specific icons through734428/4438 and centers MB8 label. A second fixed64 pass draws admitted point sprites after controls, then centers MD8/MF8 text, draws borders89F0 and restores render6C/mode. Both64 passes are original layer-order work, not automatically redundant rendering or measured hotspots. All scaling/guest rounding branches reviewed. |
| [o2 0x6EB700](../recomp/config/output_ovl/o2/o2_006EB700_0x6eb700.cpp) | `compose_special_item_catalog_list_or_selected_title_and_description_candidate` | Probable role; full body reviewed | Draws shared frame7330A0 last variation73309A and733630. W0==3 uses selected row+scroll, maps ordinal through halfword4BAC72 unless1B82A0(5B), renders6DE290 title at8C,8C and6DE2E0 description at8C,B4. Other phases require P3A9A count; loops from scroll3A9C to count, draws only first six rows with733740 Y positions and admitted ID table4BAC72, selected row adds three733790 highlights. Loop still walks remaining ordinals after six rows; no additional text draw for them. Up arrow if nonzero scroll, down if visited remainder>=7. Borders89F0/render restore follow except zero-count early exit. This is the previously unnamed detail preparation for6400's alternate list controller. |
| [o2 0x6EBA50](../recomp/config/output_ovl/o2/o2_006EBA50_0x6eba50.cpp) | `draw_original_options_categories_values_and_quit_confirmation_candidate` | High role from owned text; full body/table reviewed | Configures font, selects frame733930 versus7337D0 by1B0300. W1==B or W1==9 with W2!=0 draws quit confirmation: owned734490 strings ask main menu/lobby return, warning and YES/NO; mode-dependent omission and W3 choose split colored answer segments. Other states draw seven category rows via owned742D70,733AB0 text and733A90 XY, coloring selected group. Displays controller TYPE+('A'+3243EC), three input-role labels733B10 via733B20 layout; vibration3243EF ON/OFF; sound3243C5 STEREO/MONAURAL; BGM/SE byte3243C9/CA; brightness3243F0-80; screen signed3243ED and half of3243EE with sign-specific formats. No settings mutation/save occurs here. Full default/quit/exit string-index and color branches reviewed. |
| [o2 0x6EC360](../recomp/config/output_ovl/o2/o2_006EC360_0x6ec360.cpp) | `draw_fixed_ui_descriptor_group_and_restore_render_mode_candidate` | High adapter; full body reviewed | Counts negative-sentinel C-byte descriptors733B40 through8B00, draws group throughC710 white, sets render6C=1 and1AF1E0(4,5). No UI mode mutation. |
| [o2 0x6EC3B0](../recomp/config/output_ovl/o2/o2_006EC3B0_0x6ec3b0.cpp) | `dispatch_inventory_catalog_or_document_page_composition_candidate` | High routing; probable role | 759C9E==0 calls90C0 inventory;1 B700 special catalog;2 96A0 documents; other values skip page body. Always draws89F0 borders, sets6C=1 and mode4,5. Catalog body may also draw borders internally; original call layering retained. |
| [o2 0x6EC440](../recomp/config/output_ovl/o2/o2_006EC440_0x6ec440.cpp) | `draw_item_message_background_with_explicit_render_parameter_reset_candidate` | High mechanics; probable role | Sets6C=1,1A0BC0(0,0),D=0,5F=5,60=0,6C=0; calls6DB250(P). Restores6C=1, calls empty1AF770, sets5F=5,60=0 again. Underlying background helper does not consume this pointer as an object argument. No host wait or settings access. |
| [o2 0x6EC4E0](../recomp/config/output_ovl/o2/o2_006EC4E0_0x6ec4e0.cpp) | `draw_ui_background_then_fixed_border_candidate` | High adapter; full body reviewed | CallsC440 then89F0; no extra branching or state writes. |
| [o2 0x6EC510](../recomp/config/output_ovl/o2/o2_006EC510_0x6ec510.cpp) | `registered_ui_render_callback_acquire_resources_and_dispatch_current_page_candidate` | High routing; probable role | W4!=5 drawsC440 background first. Every invocation fetches2600..2603 into759BB4..BC0, returns if any zero. W4=1 dispatchesC3B0 inventory/catalog/documents,2 A300 map,4 BA50 options,5 C360 fixed group. Other modes drawA050 actor ratio only if4BADF8==0 and signed4BADD0==2. No active polling loop or host presentation wait. Resource queries are observed repeated work; their cost is not measured. |
| [o2 0x6EC680](../recomp/config/output_ovl/o2/o2_006EC680_0x6ec680.cpp) | `enable_shared_ui_render_callback_once_candidate` | High; full body reviewed | If759C95!=0 exits. Otherwise6D8100(1) clears/sets item-message cache state, sets759C95=1 and registers callback6EC510 through1AFA00. Does not construct a launcher/native UI thread. Registration capacity behavior belongs to resident helper. |
| [o2 0x6EC6D0](../recomp/config/output_ovl/o2/o2_006EC6D0_0x6ec6d0.cpp) | `disable_shared_ui_render_callback_when_registered_flag_one_candidate` | High; full body reviewed | Only759C95==1 clears flag and unregisters6EC510 through1AFA70. Other nonzero flag values are not normalized/removed. |

Owned options jump table742D70 is
6EBD14,6EBD30,6EBD54,6EBD70,6EBD94,6EBDB0,6EBDE4 for category0..6.
Selection predicates respectively test W1<2,2..4,5,6..7,8,9,A. Owned733AB0 labels
are CONTROLLER SETTINGS, SOUND SETTINGS, BRIGHTNESS ADJUST, SCREEN ADJUST,
DEFAULT SETTING, QUIT GAME, QUIT GAME, EXIT; mode-dependent text indexing explains
the repeated quit entry. These are internal branches, not independent functions.

The common render callback connects [interactive map controls](SYMBOLS_MAP_VIEW_INTERACTION.md),
[map tile/marker records](SYMBOLS_MAP_TILE_AND_MARKER_COMPOSITION.md),
[inventory/document drawing](SYMBOLS_INVENTORY_DOCUMENT_DRAW.md) and
[file/catalog selection](SYMBOLS_FILE_DOCUMENT_SELECTION.md). Original font bodies
remain subject to the [native font override boundary](SYMBOLS_FONT_OVERRIDE_BOUNDARY.md).
No static repeated pass is promoted to an optimization without runtime/correctness
evidence; no captured incident or slowdown cause was reproduced.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
