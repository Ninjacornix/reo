# Actor 6CE motion, contact and frame-event helpers

Static File #1 US research, 2026-11-04. Seven complete original bodies reviewed.
Addresses/offsets hex unless marked decimal. Actor identity and original action
enums unresolved. No game, build, live attachment, replay or engine edits.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6CE050](../recomp/config/output_ovl/o2/o2_006CE050_0x6ce050.cpp) | `set_actor_6ce_descriptor_after_track_count_scan_candidate` | High mechanics; probable role | Resets signed-half755720 to0,pretested loop increments it until actor51C->byte1. Loop body only increments the global counter;no per-track flag writes. Calls6346C0(actor,signed-low16 original a1,inherited a2/f12/f13),then58C7B0. No blend-factor conversion or extra animation advancement in wrapper. |
| [o2 0x6CE0C0](../recomp/config/output_ovl/o2/o2_006CE0C0_0x6ce0c0.cpp) | `reset_actor_6ce_route_shape_and_variant_color_defaults_candidate` | High mechanics; probable role |6367C0(actor),180 state preset,shape1A8=owned730988 and1D8=730A08. Shared pointer729018 selects color pointer[unsigned byte4],copies fourfloats toC70,1AC,1BC banks. No local variant bound or model-null check. |
| [o2 0x6CE180](../recomp/config/output_ovl/o2/o2_006CE180_0x6ce180.cpp) | `select_actor_6ce_primary_one_variant_secondary_candidate` | High mechanics | Byte4zero writes1/0/AFF/B0;nonzero1/1/AFF/B0. No calls,animation or timers. |
| [o2 0x6CE1D0](../recomp/config/output_ovl/o2/o2_006CE1D0_0x6ce1d0.cpp) | `select_actor_6ce_variant_primary_one_or_two_candidate` | High mechanics | Byte4zero writes1/0/AFF/B0;nonzero2/1/AFF/B0. Distinct from180 primary-one preset. |
| [o2 0x6CE220](../recomp/config/output_ovl/o2/o2_006CE220_0x6ce220.cpp) | `dispatch_actor_6ce_contact_response_and_snapshot_indexed_health_candidate` | High mechanics; probable role |637490 contact cached755710/actor11C.634F80 relative angle maskedC000 then>>14 ->B1F0..3;10=8/factor,115bit1.6407D0(actor,contact,decimal1000) signed-lowbyte saved;calls72B820[141](actor,1A),stores signed544 to half74F26C+60*B98,666D40(contact). Classification1 ->32FF,4/0/AFF/B0,666D00(contact),returns0. Other classifications:1401 ->3/1/AFF/B0;1402 ->3/2/AFF/B0;1400/other values preserve state. All these return1. Exact callback/response enums unconfirmed. |
| [o2 0x6CE400](../recomp/config/output_ovl/o2/o2_006CE400_0x6ce400.cpp) | `force_actor_6ce_height_minus_1280_when_ba5_is_99_candidate` | High mechanics | Only unsignedBA5==63 (decimal99) writes floatY3C=decimal-1280. No other writes/calls. It does not inspect a general actor flagword. |
| [o2 0x6CE420](../recomp/config/output_ovl/o2/o2_006CE420_0x6ce420.cpp) | `dispatch_actor_6ce_motion_sound_surface_and_event_crossings_candidate` | High mechanics; probable role | Switches actor1F2 across fourteen literal motions. Calls mapped5A9250 sound,5A96F0 event or5A9440 node-surface crossing adapters with original stepf12 preservedf20. Default does nothing. Exact ordered arguments below; repeated same-frame node calls preserved. Does not advance animation,read game clock or provide a cost ranking. |

Crossing notation, all arguments hex: A(frame,event,count)=5A9250;
E(frame,mode,event)=5A96F0;S(frame,kind,node)=5A9440 with original a3=0.
Actor/step arguments omitted only in the table:

| Motion | Ordered crossings |
| --- | --- |
| 64 | A(4,0,2),A(76,0,2) |
| 6F/70 | A(8,0,2) |
| C8 | E(E,0,54) |
| C9 | A(4,3,2),A(54,4,2),A(58,B,0),A(6A,2,0),A(78,4,2),A(AA,4,2),A(D8,B,0),E(60,0,55),S(6E,3,4),S(8C,3,4),S(B4,3,4) |
| D2 | A(A,3,0),S(0,2,E) |
| D3 | A(1A,3,0),A(1E,4,2),A(36,B,0),A(40,0,2),A(54,0,2),A(5C,0,2),E(3E,0,6B) |
| D4 | A(28,3,0),A(4C,9,0),A(6E,9,0),A(90,B,0),S(1E,2,E),S(3C,2,E),S(96,2,E) |
| D5 | A(1E,3,0),A(3C,B,0) |
| D6 | S(1E,2,E),S(5A,2,E),E(58,0,6B),A(22,3,0),A(30,4,2),A(5E,B,0) |
| 12C | A(2,6,0) |
| 12D | A(4,6,0) |
| 12E | A(8,6,0) |
| 136 | A(4,7,0),A(1E,B,0),S(4,2,E),S(6,2,4),S(1E,2,3),S(1E,2,4),S(1E,2,1A),S(3C,1,3),S(3C,1,4),S(3C,1,1A) |

These event lists are not sorted into time order: source order can affect
shared random state and callback side effects. The14 literals include shared
6F/70 branch.6CE3C0 already has a live mapping and is excluded from new rows.
Related [sound adapters](SYMBOLS_ANIMATION_SOUND.md),
[surface event adapter](SYMBOLS_ENTITY_CROSSING_EVENTS.md), and
[record relocation](SYMBOLS_RECORD_ROOM_RELOCATION.md).
