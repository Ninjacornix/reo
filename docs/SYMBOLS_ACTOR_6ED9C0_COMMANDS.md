# Actor 6ED9C0 command dispatch and scenario 1C auxiliary sequence

Static File #1 US research, 2026-11-04. Eleven complete original bodies reviewed.
Addresses/offsets hexadecimal. No game/build/replay/attachment/live-memory work.
The actor's original identity is unknown; shared adapters do not establish it.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6ED9C0](../recomp/config/output_ovl/o2/o2_006ED9C0_0x6ed9c0.cpp) | `dispatch_actor_6ed9c0_numeric_command_then_shared_updates_candidate` | High mechanics; probable role | a0 actor; signed byteFCF must unsigned<8, then owned742E60 choosesDAB0,DB10,DB80,DB50,DB70,DB30,DB40,DB60. Invalid values skip command. Always follows with66B850(actor),626190(actor),5BE2D0(actor),6261C0(actor). No direct action-table cardinality guess. |
| [o2 0x6EDAB0](../recomp/config/output_ovl/o2/o2_006EDAB0_0x6edab0.cpp) | `initialize_actor_6ed9c0_record_flags_and_command_one_candidate` | High; full body reviewed | Sets record390210+78*actorFB5 half22 bits9. Clears FD0..3,8..B,FB7/FB8; writesFCF=1 in return delay slot. Does not clearFCC,1155 or arbitrary actor memory. |
| [o2 0x6EDB10](../recomp/config/output_ovl/o2/o2_006EDB10_0x6edb10.cpp) | `enter_actor_6ed9c0_command_two_and_tick_transition_candidate` | High adapter; probable role | SetsFCF=2 and actor1=1, tailcalls6257A0(actor,actor+10A4). The shared helper may further mutate states; no return-value override. |
| [o2 0x6EDB30](../recomp/config/output_ovl/o2/o2_006EDB30_0x6edb30.cpp) | `actor_6ed9c0_restore_saved_transform_adapter_candidate` | High adapter | Literal tailjump625930 with original arguments, zero delay slot. Shared saved-transform contract mapped separately. |
| [o2 0x6EDB40](../recomp/config/output_ovl/o2/o2_006EDB40_0x6edb40.cpp) | `actor_6ed9c0_route_endpoint_transition_adapter_candidate` | High adapter | Literal tailjump625C50, unchanged arguments; zero delay slot. |
| [o2 0x6EDB50](../recomp/config/output_ovl/o2/o2_006EDB50_0x6edb50.cpp) | `actor_6ed9c0_primary_transition_adapter_candidate` | High adapter | Literal tailjump625670, unchanged arguments; zero delay slot. |
| [o2 0x6EDB60](../recomp/config/output_ovl/o2/o2_006EDB60_0x6edb60.cpp) | `actor_6ed9c0_transition_work10a4_adapter_candidate` | High adapter | Tailjump6257A0, a1=actor+10A4 in delay slot. Distinct fromDB10: no localFCF/actor1 writes. |
| [o2 0x6EDB70](../recomp/config/output_ovl/o2/o2_006EDB70_0x6edb70.cpp) | `actor_6ed9c0_command_four_noop_candidate` | Confirmed body; role from owned table | jr ra with zero delay word; no return value assigned or state changes. |
| [o2 0x6EDB80](../recomp/config/output_ovl/o2/o2_006EDB80_0x6edb80.cpp) | `tick_actor_6ed9c0_scenario_work_or_status_transition_candidate` | High mechanics; probable role | 625630(actor)==0 callsDC00(actor) then6257A0(actor,+10A4). Result1 changesFCF=3; other nonzero changesFCF=4, clears half544 and calls6260E0(actorFB5). Both nonzero paths call684810(actor,0). No blocking retry or independent command enum name. |
| [o2 0x6EDC00](../recomp/config/output_ovl/o2/o2_006EDC00_0x6edc00.cpp) | `tick_actor_6ed9c0_auxiliary_sequence_only_in_scenario_1c_candidate` | High adapter; probable role | Checks unsigned3243DA==1C; only thenDC40(actor). Other scenarios return unchanged. |
| [o2 0x6EDC40](../recomp/config/output_ovl/o2/o2_006EDC40_0x6edc40.cpp) | `tick_actor_scenario_1c_repeated_numeric_motion_request_until_flag_candidate` | High mechanics; probable role | FD2 phases0..2. Phase0 writesFD4=64D,1155=1,FCC=1,FB7=FF; unless BA0 bit80000 set, clears8..B/FB8, selectsFB7=8 and actor1=1. AdvancesFD2 to1. Phase1 global4B9C04 bit80 advancesFD2 to2; same invocation then still testsFCC, and if zero repeats64D/FCC/1155/FB7 request and actor-state reset under same BA0 gate. Phase2/other values return. FB7 is overwrittenFF before comparing with8, so comparison is not interpreted as a prior-state preservation guard. No original motion name or failure/timeout claim. |

Owned table742E60 contains branch arms
6ED9F8,6EDA08,6EDA18,6EDA28,6EDA68,6EDA38,6EDA48,6EDA58.
They map commands0..7 respectively to the function targets in the dispatcher row;
the arms themselves are not separate functions. Shared helper contracts are in
[actor command transitions](SYMBOLS_ACTOR_COMMAND_TRANSITIONS.md).

This family ends at6EDD54. The following6EDD60 animation-effect selector and
6EDEC0 update body use a separate actor layout/dispatch family; no identity is
inferred merely from proximity. No measured incident or timing result here.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
