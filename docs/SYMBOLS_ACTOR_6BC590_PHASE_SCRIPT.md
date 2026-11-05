# Actor 6BC590 fixed-position phase script

Static File #1 US research, 2026-11-04. Four complete original bodies reviewed.
Addresses, offsets and state values hexadecimal; distances and vector coordinates
are decimal. No execution, attachment, build, replay or engine changes. Original
scenario, actor and animation names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6BC590](../recomp/config/output_ovl/o2/o2_006BC590_0x6bc590.cpp) | `tick_actor_sixteen_phase_fixed_position_command_script_candidate` | High mechanics; scenario identity unresolved | Dispatches unsigned word1150<10 through owned740DD0; all sixteen cases and delay slots reviewed below. Progress is explicit6BCB00 calls, not a global game clock. Invalid phase returns. Phases combine target following, fixed positions, FCC completion and scenario flag predicates; final phase only selects idle motion. No measured duration or runtime stall established. |
| [o2 0x6BCA80](../recomp/config/output_ovl/o2/o2_006BCA80_0x6bca80.cpp) | `test_active_roster_record_id_one_in_same_room_without_ba0_1f0_candidate` | High mechanics | Scans 4BAEA0 roster entries from4A5C30 stride10E0. Returns1 for first signed byte0 nonzero, B98=1, half1E2 matching a0, BA0&1F0=0; returns0 if none. No writes. Capacity is the runtime global, not a local fixed four-entry bound. |
| [o2 0x6BCB00](../recomp/config/output_ovl/o2/o2_006BCB00_0x6bcb00.cpp) | `advance_actor_phase_1150_and_clear_fd0_fd2_fd3` | High mechanics | Clears FD0, increments word1150, clears FD2/FD3. Leaves FD1 unchanged. |
| [o2 0x6BCB20](../recomp/config/output_ovl/o2/o2_006BCB20_0x6bcb20.cpp) | `test_actor_distance_below_170_to_indexed_script_position_candidate` | High mechanics | Copies three XYZ vectors from72F9A0 to stack and selects a1*12 decimal. Calls665DC0(actor,position); returns0 when170<=distance, otherwise1, preserving ordered floating comparison. No index guard in this body. |

The reusable idle reset below means: unless BA0 bit80000, clear8..B/FB8 when
FB7 differs from0, then set FB7=0 and byte1=1. A call to advance means6BCB00.

| Phase | Complete branch behavior |
| --- | --- |
| 0 | 6BCBA0; advance if6BCB20(actor,0). |
| 1 | 6BCBA0; advance if6BCD70. |
| 2 | 6BCED0(actor,0); advance if6BCE20, otherwise if6BCE90(actor,0). |
| 3 | 6BCFA0(actor,0); advance if6BCE20, otherwise if6BCDD0. |
| 4 | Idle reset; advance if6BCDE0. |
| 5 | 6BD150 (tail6BCBA0); advance if6BD0C0. |
| 6 | 6BCED0(actor,1); when4B9E5C bit8 clear, publish684810(actor,1) and advance; otherwise advance if6BCE90(actor,1). |
| 7 | 6BCFA0(actor,1); same global bit clear publishes and advances. Otherwise, FCC completion through6BCDD0 calls5703E0(3E,1) then advances. |
| 8 | Idle reset; advance when4B9E5C bit8 clear. |
| 9 | 6BCBA0; advance if6BCB20(actor,1). |
| A | 6BCED0(actor,2); advance when4B9C00 bit2000 set, otherwise if6BCE90(actor,2). |
| B | 6BCFA0(actor,2); advance when4B9C00 bit2000 set, otherwise if6BCDD0. |
| C | Idle reset; advance when4B9C00 bit2000 set. |
| D | 6BCBA0; advance if6BCB20(actor,2). |
| E | Idle reset; if6BCA80 succeeds,5703E0(35,1), zero health544,626160(actor,4), then advance. |
| F | Idle reset only; no further increment or terminal task deletion in this body. |

Owned740DD0 sixteen internal targets, in phase order:
`[6BC5C8,6BC5F4,6BC61C,6BC664,6BC6AC,6BC710,6BC738,6BC790,6BC7F0,6BC854,6BC880,6BC8CC,6BC918,6BC97C,6BC9A8,6BCA24]`.
SHA256 of its40-byte-hex span:
`3ace284d500d2e6b28dcec608299f77fc5985552b1682cf5663b4dfc5e6adaeb`.
Owned72F9A0 length24 contains XYZ vectors
`(9470,500,13160),(7960,900,13120),(8730,1500,12530)`;
SHA256`73338715a30cdeb12cbb4fe6ff054f63295c3420ca50037ff3a7de3ae07e1f1b`.
Owned image: `build-function-index/owned-overlays/o2.bin`, base570000,
SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

See [command dispatch](SYMBOLS_ACTOR_6BC270_COMMAND_DISPATCH.md) for callers,
[position/completion helpers](SYMBOLS_ACTOR_SCRIPT_POSITION_COMPLETION.md) and
[target following](SYMBOLS_ACTOR_SCRIPT_TARGET_FOLLOWING.md) for every helper used.

Full-body owned-word audit: four rows, 322 verified instruction words,
zero conflicts, 60 omitted zero/NOP words, zero omitted nonzero words.
