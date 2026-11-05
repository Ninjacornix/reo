# Actor 6BDA50 command dispatch and class64 phase script

Static File #1 US research, 2026-11-04. Ten complete original bodies reviewed.
Addresses, offsets, selectors and phases hexadecimal. Original scenario and
animation labels remain unknown. No execution, attachment, build, replay or
engine changes. The six small adapters were individually read through delay slots.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6BDA50](../recomp/config/output_ovl/o2/o2_006BDA50_0x6bda50.cpp) | `dispatch_actor_6bda50_eight_command_states_and_common_post_steps_candidate` | High mechanics | Signed FCF cast unsigned<8 dispatches740E10. State0/1/2/3/4/5/6/7 calls6BDB40/6BDC20/6BDC90/6BDC60/6BDC80/6BDC40/6BDC50/6BDC70. Invalid state skips case. All then66B850,626190,5BE2D0,6261C0(actor). |
| [o2 0x6BDB40](../recomp/config/output_ovl/o2/o2_006BDB40_0x6bdb40.cpp) | `initialize_command_state_one_and_select_script_start_from_1040_candidate` | High mechanics | R=390210+78*FB5; OR halfR22 with9. ClearsFD0..3/8..B/FB8/FB7, setsFCF1 and idle byte1=1 unless BA0 bit80000. Word1040=9 initializes1150=28;1040=6 sets14; otherwise0. No original scene identifier inferred. |
| [o2 0x6BDC20](../recomp/config/output_ovl/o2/o2_006BDC20_0x6bdc20.cpp) | `enter_command_state_two_and_tail_route_actor_motion_candidate` | High mechanics | SetsFCF2, byte1=1; tail6257A0(actor,actor+10A4). |
| [o2 0x6BDC40](../recomp/config/output_ovl/o2/o2_006BDC40_0x6bdc40.cpp) | `tail_enter_command_625930_without_selector_write_candidate` | High mechanics | Direct tail625930, NOP delay. Unlike6BC4C0, does not write32. |
| [o2 0x6BDC50](../recomp/config/output_ovl/o2/o2_006BDC50_0x6bdc50.cpp) | `tail_enter_command_625c50_from_6bda50_candidate` | High mechanics | Direct tail625C50, NOP delay; same original words as6BC4D0. |
| [o2 0x6BDC60](../recomp/config/output_ovl/o2/o2_006BDC60_0x6bdc60.cpp) | `tail_enter_command_625670_from_6bda50_candidate` | High mechanics | Direct tail625670, NOP delay; same original words as6BC4E0. |
| [o2 0x6BDC70](../recomp/config/output_ovl/o2/o2_006BDC70_0x6bdc70.cpp) | `tail_route_actor_motion_10a4_from_6bda50_candidate` | High mechanics | Direct tail6257A0; delay setsa1=actor+10A4. Same original words as6BC4F0. |
| [o2 0x6BDC80](../recomp/config/output_ovl/o2/o2_006BDC80_0x6bdc80.cpp) | `actor_6bda50_command_state_four_noop` | High mechanics | jrra and NOP; no assigned return. Same original words as6BC500. |
| [o2 0x6BDC90](../recomp/config/output_ovl/o2/o2_006BDC90_0x6bdc90.cpp) | `classify_command_admission_or_tick_class64_phase_script_candidate` | High mechanics | 625630=0 runs6BDD10 then6257A0(actor,+10A4). Result1 setsFCF3; other nonzeroFCF4,health544=0,6260E0(FB5). Both nonzero684810(actor,0). |
| [o2 0x6BDD10](../recomp/config/output_ovl/o2/o2_006BDD10_0x6bdd10.cpp) | `dispatch_class64_script_phases_or_generic_114c_action_candidate` | High mechanics; original class meaning unknown | HalfBB4=64 admits unsigned1150<16 through740E30. Phases below. OtherBB4 ORsBA0 bit400000,sets32=FF,6BE580(actor). BB4=64 invalid phase returns. A numeric64 match does not identify the original character. |

Owned740E10 length20 targets:
`[6BDA88,6BDA98,6BDAA8,6BDAB8,6BDAF8,6BDAC8,6BDAD8,6BDAE8]`;
SHA256`bffc34c2594f62701a8160a4bd939cd72bdafcff8c77ef60fc4f543b02ee2ee5`.

Owned740E30 length58 (22 decimal words):
`[6BDD50,6BDD60,6BDD88,6BDD50,6BDD60,6BDD88,6BDD50,6BDD60,6BDD88,6BDD50,6BDD60,6BDD88,6BDD50,6BDD60,6BDDB0,6BDE14,6BDE14,6BDE14,6BDE14,6BDE14,6BDDC0,6BDDDC]`;
SHA256`ce45b3ada06df581b143fd9206d7fd623992a85f382e7524a1719cf52c9dc7e4`.

| Phases | Complete dispatch behavior |
| --- | --- |
| 0,3,6,9,C | 6BDE40(actor). |
| 1,4,7,A,D | 6BDF10(actor,(phase-1)/3), signed integer division. |
| 2,5,8,B | 6BE020(actor,(phase-2)/3); callee overwrites this argument. |
| E | 6BE150(actor). |
| F..13 | Return without handler. |
| 14 | OR BA0 bit400000 then6BE2D0(actor). |
| 15 | OR BA0 bit400000 then6BE3C0(actor). |

The already-reviewed6BDE20 body is word-for-word identical to6BCB00: clearsFD0,
increments1150, clearsFD2/FD3. It is cited as a plain-address cross-reference here
so identical-body propagation can be handled centrally.

Owned image: `build-function-index/owned-overlays/o2.bin`, base570000,
SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.
See [phase handlers](SYMBOLS_ACTOR_CLASS64_SCRIPT_HANDLERS.md) and
[earlier command family](SYMBOLS_ACTOR_6BC270_COMMAND_DISPATCH.md).

Full-body owned-word audit: ten rows, 192 verified instruction words,
zero conflicts, 35 omitted zero/NOP words, zero omitted nonzero words.
