# Actor script positions, completion and collision route adapters

Static File #1 US research, 2026-11-04. Ten complete original bodies reviewed.
Addresses and offsets hexadecimal; distances/coordinates decimal. Original action
names remain unknown. No execution, attachment, build, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6BCD70](../recomp/config/output_ovl/o2/o2_006BCD70_0x6bcd70.cpp) | `test_script_position_or_global_flag8_without_flag20000_candidate` | High mechanics | Returns1 if6BCE20. Otherwise returns1 exactly when4B9C00 bit8 set and bit20000 clear; else0. |
| [o2 0x6BCDD0](../recomp/config/output_ovl/o2/o2_006BCDD0_0x6bcdd0.cpp) | `test_actor_signed_fcc_equals_zero` | High mechanics | Signed byteFCC then unsigned nonzero test inverted; returns1 only for zero, including negative bytes as nonzero. |
| [o2 0x6BCDE0](../recomp/config/output_ovl/o2/o2_006BCDE0_0x6bcde0.cpp) | `test_script_position_or_global_flag20000_candidate` | High mechanics | Returns1 if6BCE20, otherwise boolean4B9C00 bit20000. |
| [o2 0x6BCE20](../recomp/config/output_ovl/o2/o2_006BCE20_0x6bce20.cpp) | `test_script_position_below_100_or_global_bit8_clear_candidate` | High mechanics | Distance to owned72F9C8 XYZ(9180,500,13060). Returns1 unless100<=distance; when100<=distance returns1 if4B9E5C bit8 clear, otherwise0. Ordered comparison preserved. |
| [o2 0x6BCE90](../recomp/config/output_ovl/o2/o2_006BCE90_0x6bce90.cpp) | `test_actor_within_20_of_script_position_1124_candidate` | High mechanics | 665DC0(actor,actor+1124), returns1 for distance<20, else0. a1 input is overwritten and unused. |
| [o2 0x6BCED0](../recomp/config/output_ovl/o2/o2_006BCED0_0x6bced0.cpp) | `steer_actor_toward_indexed_fixed_script_position_candidate` | High mechanics | Copies three owned72F9E0 XYZ vectors to stack, chooses a1*12 decimal with no local index check, copies to1124/28/2C, calls6BD270(actor,&selectedXYZ). Unless BA0 bit80000, selects FB7=1/byte1=1, clearing8..B/FB8 on change. |
| [o2 0x6BCFA0](../recomp/config/output_ovl/o2/o2_006BCFA0_0x6bcfa0.cpp) | `start_fcc_script_motion_and_idle_when_finished_candidate` | High mechanics | FD2=0 chooses FF4=0/4000/9000 for a1=0/1/2, leaves FF4 for other values, sets FCC=1, selects FB7=D/byte1=1 unless BA0 bit80000, calls626180(actor,1), setsFD2=1. Falls through same call: when signedFCC=0 and flag80000 clear, selects idleFB7=0. FD2=1 only tests completion; other FD2 returns. |
| [o2 0x6BD0C0](../recomp/config/output_ovl/o2/o2_006BD0C0_0x6bd0c0.cpp) | `complete_script_phase_near_fixed_position_or_publish_when_bit8_clear_candidate` | High mechanics | Distance to72FA08 XYZ(8390,500,13020). Unless250<=distance,626180(actor,1) and return1. Otherwise4B9E5C bit8 set returns0; clear publishes684810(actor,1), returns1. |
| [o2 0x6BD160](../recomp/config/output_ovl/o2/o2_006BD160_0x6bd160.cpp) | `refresh_actor_target_route_point_after_collision_candidate` | High mechanics; path meaning provisional | FD3=0 copies target a1 XYZ+38 intoFDC/FE0/FE4, calls579980(actorXYZ,destination,4FFFF,0,&work). Return1 or actor16C bit1 admits FD3=1 and634040(destination,destination,actorXYZ); otherwise returns. Same-call fallthrough and FD3=1 retest collision; collision1 or bit1 clearsFD3. Distance<100 also clearsFD3. Other FD3 does nothing. |
| [o2 0x6BD270](../recomp/config/output_ovl/o2/o2_006BD270_0x6bd270.cpp) | `refresh_explicit_script_route_point_after_collision_candidate` | High mechanics; path meaning provisional | Same FD3 state protocol and4FFFF collision call as6BD160, but a1 points directly toXYZ; route634040 receives original a1 and proximity threshold is50. Records destinationFDC/FE0/FE4. Initial collision admission falls through to second collision test in the same call. |

Owned fixed vectors, all floats:

| Owned span | XYZ values / SHA256 |
| --- | --- |
| 72F9C8 lengthC | (9180,500,13060). `6962019b76ef7cd1b6044b64992e7f3b4e5bac8c9fe0ddc37598bb110c5734c6` |
| 72F9E0 length24 | (9510,500,12880),(8280,500,13110),(8410,900,13410). `441a8300f73a6634c7ff2e777e121428b155acbf9816930a200f9d8c46b983f0` |
| 72FA08 lengthC | (8390,500,13020). `42d468a48e4b487ec0b802677759881e7e6ca250ad801f7bf692ffa678c8d0c3` |

Image: `build-function-index/owned-overlays/o2.bin`, base570000,
SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.
These constants locate script positions numerically; room/scenario labels have
not been established. Parent script: [6BC590](SYMBOLS_ACTOR_6BC590_PHASE_SCRIPT.md).

Full-body owned-word audit: ten rows, 352 verified instruction words,
zero conflicts, 21 omitted zero/NOP words, zero omitted nonzero words.
