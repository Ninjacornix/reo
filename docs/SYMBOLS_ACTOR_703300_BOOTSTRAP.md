# Actor 703300 update and initialization

Static File #1 US research, 2026-11-04. Three complete original bodies
reviewed. Addresses and offsets are hex unless marked decimal. Actor identity,
original state names and timer units remain unknown. No game, build, attachment,
replay or live-memory work; these findings do not establish a slowdown cause.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x703300](../recomp/config/output_ovl/o2/o2_00703300_0x703300.cpp) | `update_actor_703300_snapshots_contact_state_and_primary_dispatch_candidate` | High mechanics; probable role | Caches actor24 at75A4F8. Compares current X38/Z40 exactly against saved44/4C to set75A4C8, then snapshots XYZ and rotation. Runs54A10/C360/BA50/C820 setup, clears C94 mask201 and motion4E4..4EC, resets75A4D0. When signed C80 is0, copies shared72905C->word4 color into C70,1AC,1BC banks. Optional peer distance5A98F0 updates BD4. Skips635E20 only for primary3/4; contact response707870 requires primary nonzero, not4, and13F nonzero. Calls640210 once here, sets C94 mask201 from signed544<=0, dispatches73D960[byte8], optionally5E0100 when byte4 nonzero. C82 suppresses C0 motion; otherwise75A4D0 selects63F490 versus65E3A0. Maintains D48/D4A/D50; D4A expiry resets to decimal30 and calls1B9310(actor,6,0). Tail calls6F1B40(actor,1),6F1F20,6347D0,707CB0,703630,706C40. Callback frequency is not a global game update count. |
| [o2 0x703630](../recomp/config/output_ovl/o2/o2_00703630_0x703630.cpp) | `advance_actor_703300_three_stage_timed_effect_candidate` | High mechanics; probable role | D6D0 clears D6E; D6D1/2/3 predecrement signed byteD6E. On post<=0, seed signed-byte timer from73D9E9[2*D6D]/74F200, call5BF1B0(0,0,signed timer,unsigned amplitude73D9E8[2*D6D]), then increment D6D. D6D4 clears selector; other selectors return. Owned pairs are decimal(12,20),(12,20),(8,20),(2,20); selector0 pair is not emitted here. Exact visual effect remains a callee contract. |
| [o2 0x703760](../recomp/config/output_ovl/o2/o2_00703760_0x703760.cpp) | `initialize_actor_703300_peer_motion_shape_and_route_defaults_candidate` | High mechanics; probable role | 63F6B0 lowbyte selects player4A5C30+10E0*i, stored in actor24/75A4F8; peer byte3 becomes C26. Clears D45, builds matrix50, sets byte1,553,C94mask201 and calls706E70 with descriptor0/bank0/frame0/blend0. Sets F0=1,520=-1,C841,D4A1,55110,55216; clears D56/D67/D50/C9A/C9B/D48/CE8/CFC and other setup fields. Copies544 to546 and544-decimal1000 to D4E. Pretested track loop clears1FF+20*i up to actor51C->byte1. Restores1A8=73C454 and1D8=73C52C plus shared word4 color banks. Clears four bytes BE8 and eight bytes C..13, then707110 route reset. |

Owned73D960 has eight primary pointers:703760,703990,704970,706A80,
706C80,7047D0,7057B0,6F8740. The last is the previously reviewed cached-pose
restore body. Owned-word checks use the file-backed o2 blob at base570000;
mapping does not assert a player-facing identity or a measured cost ranking.

Related [route states](SYMBOLS_ACTOR_703300_ROUTE_STATES.md) and
[shared controls](SYMBOLS_ACTOR_703300_SHARED_CONTROLS.md).
