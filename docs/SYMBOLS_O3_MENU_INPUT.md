# Overlay o3 menu input and repeat contracts

Static File #1 US research,2026-11-04. Owned decoded BIN/3.DAT is image o3,
runtime id4,load base0x570000,795136bytes;SHA256
`5d23ef8bf97c107421f4bcf8589cf8941f3305ae5f6715573ed68837b9511dfb`.
Header name netwk.bin does not make every body a network protocol operation.
All143662distinct original instruction sites within catalogue source bounds match
owned bytes,zero mismatches/conflicts. No game,build,replay,network access or live
attachment. The13source-less catalogue entries are not promoted to executable code.

Snapshot globals6D8830/38/40 and keyboard bytes6D8848/A/B are read by these
bodies. They do not establish the upstream device contract or wall-clock timing.
This notebook records static roles,not original names or handwritten translations.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o3 0x570080](../recomp/config/output_ovl/o3/o3_00570080_0x570080.cpp) | `step_byte_menu_cursor_with_axis_wrap_or_clamp` | Confirmed/static mechanics; semantic labels proposed | Pointer a0 signedbyte index,a1 last admitted index,a2 lowbyte mode. Modes0/2 use up/down masks10001/20002 and key52/51;other modes left/right40004/80008,key50/4F. Mode<2 wraps endpoints;mode>=2 returns0 at endpoint. Successful movement calls1B8860(0),returns1;no movement0. Signed loads require a representable cursor range. |
| [o3 0x570210](../recomp/config/output_ovl/o3/o3_00570210_0x570210.cpp) | `step_halfword_menu_cursor_with_axis_wrap_or_clamp` | Confirmed/static mechanics; semantic labels proposed | Same axis/mode and success/audio contract as570080,with signedhalfword cursor and low16 maximum comparison. No repeat countdown in this body. |
| [o3 0x5703A0](../recomp/config/output_ovl/o3/o3_005703A0_0x5703a0.cpp) | `repeat_byte_menu_cursor_after_initial_and_held_delays` | Confirmed/static mechanics; semantic labels proposed | Same cursor bounds/modes as570080. Halfword countdown632200 vertical or632202 horizontal: edge570AD0/keyboard6D884A sets20;while nonzero decrements and returns0;held570CE0/keyboard6D8848 atzero sets10. Counts invocations,not measured milliseconds. |
| [o3 0x5705D0](../recomp/config/output_ovl/o3/o3_005705D0_0x5705d0.cpp) | `repeat_byte_menu_cursor_with_tab_and_modifier_navigation` | Confirmed/static mechanics; semantic labels proposed | Repeat timers632208/63220A and delays20 then10;axis/wrap/clamp as570080. Keyboard code2B decrements if6D884B&22,otherwise increments;axis keys remain admitted. Code2B paths exist for both edge6D884A and held6D8848. Successful step audio1B8860(0),return1;clamped boundary0. |
| [o3 0x570860](../recomp/config/output_ovl/o3/o3_00570860_0x570860.cpp) | `step_scrolling_list_origin_and_visible_byte_cursor` | Confirmed/static mechanics; semantic labels proposed | a0 signedbyte origin,a1 visible cursor,a2 lowbyte total count,a3 lowbyte visible count. Up/down edge starts632210 countdown20;held after countdown starts5. Cursor crosses visible endpoints by adjusting origin when admitted. Returns1 for an accepted direction even on some immovable endpoint paths;do not interpret as guaranteed content change. Audio accompanies admitted moves. |
| [o3 0x570A40](../recomp/config/output_ovl/o3/o3_00570A40_0x570a40.cpp) | `test_menu_confirm_edge_or_keyboard_enter` | Confirmed/static mechanics; semantic labels proposed | Returns normalized bit10 of word6D8840 OR word6D8838,or keyboard edge byte6D884A==28. Shared snapshots are inputs;no polling hardware in this body. |
| [o3 0x570A80](../recomp/config/output_ovl/o3/o3_00570A80_0x570a80.cpp) | `test_menu_cancel_edge_or_keyboard_escape` | Confirmed/static mechanics; semantic labels proposed | Returns1 iff (((word6D8840&F000F) OR word6D8838)&20)!=0,or6D884A==29. Preserve mask on first snapshot;not the same raw union as confirm helper. |
| [o3 0x570AD0](../recomp/config/output_ovl/o3/o3_00570AD0_0x570ad0.cpp) | `test_requested_menu_edge_with_prioritized_keyboard_fallback` | Confirmed/static mechanics; semantic labels proposed | Tests (((word6D8840&F000F) OR word6D8838)&requestedMask),then keyboard edge6D884A. Keyboard fallback classes in priority order:10->28,20->29,40004->50,80008->4F,10001->52,20002->51,800->4E,400->4B,80->4D,40->4A,8000->3A,100->3B. Combined request masks use first admitted keyboard class,not all independently. |
| [o3 0x570CE0](../recomp/config/output_ovl/o3/o3_00570CE0_0x570ce0.cpp) | `test_requested_held_menu_input_mask` | Confirmed/static mechanics; semantic labels proposed | Returns normalized ((word6D8830&a0)!=0);no keyboard fallback or mutation. |
| [o3 0x570D00](../recomp/config/output_ovl/o3/o3_00570D00_0x570d00.cpp) | `test_text_entry_key_edge_excluding_control_keys_candidate` | Confirmed/static mechanics; semantic labels proposed | First admits word6D8838 bit200. Else examines keyboard edge6D884A:rejects values outside admitted numeric ranges and explicit navigation/function controls28/29/2A/2B/39/49..52/88/8A/8B;other admitted values return1. Numeric filtering is verified;character encoding and exact printable-key policy remain candidate. |
