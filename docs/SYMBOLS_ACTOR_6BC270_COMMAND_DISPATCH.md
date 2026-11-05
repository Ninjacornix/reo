# Actor 6BC270 command dispatch and transition adapters

Static File #1 US research, 2026-11-04. Nine complete original bodies reviewed.
Addresses, offsets and state values hexadecimal. Original command names remain
unknown. No game execution, attachment, build, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6BC270](../recomp/config/output_ovl/o2/o2_006BC270_0x6bc270.cpp) | `dispatch_actor_eight_command_states_and_run_common_post_steps_candidate` | High mechanics | Signed byteFCF cast unsigned must be <8 to dispatch owned740DB0 table. States0..7 invoke360/400/510/4E0/500/4C0/4D0/4F0 respectively. Invalid state skips dispatch. All paths then call66B850,626190,5BE2D0,6261C0 with actor. Original command labels unresolved. |
| [o2 0x6BC360](../recomp/config/output_ovl/o2/o2_006BC360_0x6bc360.cpp) | `initialize_actor_command_state_one_and_mark_slot_record_candidate` | High mechanics | R=390210+78*unsignedFB5; ORs halfR22 with1. Clears FD3..FD0, bytes8..B, FB8/FB7; sets FCF1. If BA0 bit80000 clear, the newly cleared FB7 admits the branch that sets byte1=1. Clears word1150 on all paths. No original action identity inferred. |
| [o2 0x6BC400](../recomp/config/output_ovl/o2/o2_006BC400_0x6bc400.cpp) | `admit_and_publish_actor_command_state_two_then_route_motion_candidate` | High mechanics; delivery unknown | 1B0310 mode1 requires681970(1,FB5) nonzero before clearing FD0..3/8..B, setting FCF2/byte1=1 and calling684810(actor,0). Other modes perform reset locally without publish. Admission failure skips reset and publish. Always6257A0(actor,actor10A4). Transport routing alone does not establish delivery. |
| [o2 0x6BC4C0](../recomp/config/output_ovl/o2/o2_006BC4C0_0x6bc4c0.cpp) | `set_actor_selector_32_ff_and_tail_enter_command_625930_candidate` | High mechanics | Writes byte32=FF then tail-jumps625930 with actor. |
| [o2 0x6BC4D0](../recomp/config/output_ovl/o2/o2_006BC4D0_0x6bc4d0.cpp) | `tail_enter_actor_command_625c50_candidate` | High mechanics | Tail-jumps625C50; argument registers otherwise preserved. |
| [o2 0x6BC4E0](../recomp/config/output_ovl/o2/o2_006BC4E0_0x6bc4e0.cpp) | `tail_enter_actor_command_625670_candidate` | High mechanics | Tail-jumps625670; argument registers otherwise preserved. |
| [o2 0x6BC4F0](../recomp/config/output_ovl/o2/o2_006BC4F0_0x6bc4f0.cpp) | `tail_route_actor_motion_from_field_10a4_candidate` | High mechanics | Tail-jumps6257A0(actor,actor10A4). |
| [o2 0x6BC500](../recomp/config/output_ovl/o2/o2_006BC500_0x6bc500.cpp) | `actor_command_state_four_noop` | High mechanics | jr ra with NOP delay slot; does not assign a return value. |
| [o2 0x6BC510](../recomp/config/output_ovl/o2/o2_006BC510_0x6bc510.cpp) | `classify_actor_command_admission_or_tick_6bc590_candidate` | High mechanics | 625630(actor)=0 runs6BC590 then6257A0(actor,10A4). Result1 sets FCF3; other nonzero result sets FCF4, health544=0 and calls6260E0(FB5). Both nonzero paths684810(actor,0). Does not establish original action or network delivery. |

Owned 740DB0 eight-word internal dispatch table:
`[6BC2A8,6BC2B8,6BC2C8,6BC2D8,6BC318,6BC2E8,6BC2F8,6BC308]`.
Each internal target and its actual call was reviewed; these internal labels
are not separate generated function entries. Owned blob identity:
`build-function-index/owned-overlays/o2.bin`, base570000, SHA256
`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

See [shared command transitions](SYMBOLS_ACTOR_COMMAND_TRANSITIONS.md) for625630,
625670,6257A0,625930,625C50 and6260E0, and
[transition message packing](SYMBOLS_ACTOR_TRANSITION_MESSAGE_PACKING.md) for684810.
6BC590 is reviewed separately in the
[sixteen-phase script notebook](SYMBOLS_ACTOR_6BC590_PHASE_SCRIPT.md).

Full-body owned-word audit: nine rows, 162 verified instruction words,
zero conflicts, 24 omitted zero/NOP words, zero omitted nonzero words.
