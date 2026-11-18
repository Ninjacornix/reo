# Actor 6F18A0 turning and cached-state restoration

Static File #1 US research, 2026-11-04. Six complete original bodies reviewed.
Addresses/offsets hex unless marked decimal. Original actor/action identities
remain unknown; names describe observed state and geometry. No execution,
attachment, build or engine changes; no measured slowdown claim.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6F3F80](../recomp/config/output_ovl/o2/o2_006F3F80_0x6f3f80.cpp) | `dispatch_actor_6f18a0_primary_two_secondary_and_post_flag_candidate` | High routing | Calls unchecked73C160[actor9](actor), then5705F0(50,1,0). Owned four entries are3FD0,3FD0,45C0,3FD0; adjacent73C170 belongs to primary-six dispatch, not additional primary-two states. |
| [o2 0x6F3FD0](../recomp/config/output_ovl/o2/o2_006F3FD0_0x6f3fd0.cpp) | `tick_actor_6f18a0_primary_two_turning_motion_and_frame_gate_candidate` | High mechanics; probable role | A=FF selects descriptor73C210[9] at frame0/blend10, setsA1,C363C. Both FF and A0 align636CF0 toward cached75A108+38, seed C80/C81=1,C78/C68 from73C218+2*9, and calculate44E0 turn rate with B6 if alignment fails. A0 selects the same descriptor after those fields, then58C780; FF selected it before them. A1 rechecks angle1554; success setsA2 and C=-1, but either result advances58C300 in the same call. A2 also advances; track byte1F1bit40 resets77E0. Independent B0 waits until frame1E4>=73C1F8[9], then alignment1554 chooses B=63 or B1 and44E0 with73C208[9]. B1 checks alignment73C200[9]; success increments B, failure adds saved yaw delta9A only when43C0 accepts current motion frame. Other B values return. |
| [o2 0x6F43C0](../recomp/config/output_ovl/o2/o2_006F43C0_0x6f43c0.cpp) | `test_actor_6f18a0_motion_specific_turning_frame_window_candidate` | High mathematical mechanics | Returns1 for inclusive frame1E4 windows: motion1F2=12C with decimal30..44, CB with16..32,12D with158..168,139 with16..36; all other combinations0. No animation advance or state writes. |
| [o2 0x6F44E0](../recomp/config/output_ovl/o2/o2_006F44E0_0x6f44e0.cpp) | `derive_actor_6f18a0_signed_yaw_increment_and_turn_count_candidate` | High mathematical mechanics; original units unknown | a0 actor, a1 target XYZ, a2 signed-low16 step magnitude. Copies target, computes heading376E70, forms unsigned wrapped difference to yaw92. If difference<=8000, writes9A=step*74F200 and C=unsignedDifference/product. Otherwise writes9A=-product and C=(difference-8000)/product using unsigned divide. The literal subtraction is8000, not10000; preserve this original arithmetic without assuming a conventional shortest-angle implementation. Writes rates/counts without applying rotation. |
| [o2 0x6F45C0](../recomp/config/output_ovl/o2/o2_006F45C0_0x6f45c0.cpp) | `tick_actor_6f18a0_primary_two_secondary_two_motion_and_turn_gate_candidate` | High mechanics; probable role | A0/FF entersA1, descriptor14/frame0/blend10; FF additionallyC363C. A1 advances58C300; any nonzero resets77E0 and returns immediately. Other paths use the same independent B frame threshold, target alignment,44E0 rate and43C0-gated yaw increment scheme as3FD0, retaining current actor9 as the table index. No guessed original attack/action name. |
| [o2 0x6F8740](../recomp/config/output_ovl/o2/o2_006F8740_0x6f8740.cpp) | `tick_actor_6f18a0_primary_four_interpolate_and_restore_cached_state_candidate` | High mechanics; probable role | Every invocation sets54A=5,C82=1. A0 enters1,CBC=decimal20 and divides XYZ deltaCB0..CB8 and signed yaw deltaCC0 by20; CCA chooses descriptor4 or3, frame0/blend10 via76C0, then calls58C7B0 again. A1 advances58C300(1), adds deltas to current XYZ/yaw, predecrements signed-halfCBC; post<=0 snaps XYZ toCA4..CAC and yawCBE, restores state8..B fromCC2..CC5 and timersC/E fromCC6/CC8. Other phases return. Timer is a fixed20 calls here, not divided by74F200; this is an original interpolation contract, not a runtime timing measurement. |

Owned73C1F8 frame thresholds for the four secondary indices are decimal28,14,156,14;
73C200 alignment halves are18E2,1554,1554,1554;73C208 turn magnitudes are38E,16C,38E,38E.
Descriptor bytes73C210 are16,17,14,6. Pairs at73C218 are decimal(30,3),
(50,5),(100,5),(130,5), converted to C78/C68 floats by the original body.

The primary-four restore handler consumes the target deltas and admission fields
documented in [shared controls](SYMBOLS_ACTOR_6F18A0_SHARED_CONTROLS.md).
The turning helper records original unsigned arithmetic, not an inferred fix.
Original asset/motion admission is still required to explain why these states
occur in a scenario; no handler has been identified as a captured hotspot.
