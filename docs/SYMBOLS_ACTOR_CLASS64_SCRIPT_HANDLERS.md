# Actor class64 script movement and FCC action handlers

Static File #1 US research, 2026-11-04. Seven complete original bodies reviewed.
Addresses, offsets and state values hexadecimal; coordinates, distances and RNG
range descriptions decimal. Original animation and scenario names are unresolved.
No execution, attachment, build, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6BDE40](../recomp/config/output_ovl/o2/o2_006BDE40_0x6bde40.cpp) | `select_motion_nine_and_advance_class64_phase_near_target_candidate` | High mechanics | FD2=0 selectsFB7=9/byte1=1, on change writes8=2 and clears9..B/FB8; FCD8,FD2++. Same-call fallthrough and FD2=1:625230; if1024 target nonnull and unless300<=distance,684810(actor,1),6BDE20. OtherFD2 returns. Motion writes are not guarded by80000 here. |
| [o2 0x6BDF10](../recomp/config/output_ovl/o2/o2_006BDF10_0x6bdf10.cpp) | `steer_motion_seven_to_indexed_class64_script_position_and_advance_candidate` | High mechanics | Copies five XYZ vectors72FB60, selects a1*12 decimal without local bounds check, writes1124/28/2C,6BD270. UnlessBA0 bit80000 selectsFB7=7/byte1=1, clears8..B/FB8 on change. Unless100<=distance to1124,684810(actor,1),6BDE20. |
| [o2 0x6BE020](../recomp/config/output_ovl/o2/o2_006BE020_0x6be020.cpp) | `start_random_motion_c_variant_then_advance_phase_on_fcc_zero_candidate` | High mechanics | FD2=0 calls625230;nonnull1024 copies targetXYZ toFDC. RNGstream1 low2bits+1 ->113C (1..4 decimal). SelectsFB7=C/byte1=1, on change8=2/clear9..B/FB8, setsFD2=2/FCC1 and returns. FD2=1 selects same motion, incrementsFD2/FCC1, falls into completion check. FD2=2 signedFCC=0 publishes684810(actor,1),6BDE20. OtherFD2 returns. Incoming a1 index unused. |
| [o2 0x6BE150](../recomp/config/output_ovl/o2/o2_006BE150_0x6be150.cpp) | `repeat_motion_c_variant_one_after_nearby_target_fcc_completion_candidate` | High mechanics | FD2=0 selectsmotion9/FCD8,625230;nonnull1024 target within ordered300 test copiesXYZ,113C=1,selectsmotionC with8=2 on change,FD2=2/FCC1,returns. Withoutnearbytarget remainsFD2=0. FD2=1 selectsC thenincrements2/FCC1. FD2=2 FCC0 publishesselector1 and resetsFD2=0, without phase increment. |
| [o2 0x6BE2D0](../recomp/config/output_ovl/o2/o2_006BE2D0_0x6be2d0.cpp) | `steer_motion_two_to_fixed_script_position_and_advance_candidate` | High mechanics | OR byte1 with1, copy72FBA0 XYZ into1124/28/2C,6BD270. Unless BA0 bit80000 selectsFB7=2/byte1=1 and clears8..B/FB8 on change. Unless100<=distance, publish684810(actor,1),6BDE20. |
| [o2 0x6BE3C0](../recomp/config/output_ovl/o2/o2_006BE3C0_0x6be3c0.cpp) | `recompute_near_fixed_position_motion_e_state_and_stage_second_point_candidate` | High mechanics; intended persistence unknown | Every call copies72FBB0/72FBC0 points, writes1124firstpoint, computesdistance and unconditionally resetsFD2=0; if not50<=distance setsFD2=1. FD2=0 selectsmotion2 unless80000 and6BD270(firstpoint). FD2=1 increments2,FCC1,selectsmotionE with8=2 on change, then stages secondpointFDC. ReloadedFB7 equals just-writtenE, skipping publish at6BE524. Subsequent FCC check sees just-written1, skipping6BE554. No local path retains incomingFD2=2 across the initial reset. Original state mechanics recorded, without a reproduced failure claim. |
| [o2 0x6BE580](../recomp/config/output_ovl/o2/o2_006BE580_0x6be580.cpp) | `start_motion_eight_when_114c_enabled_then_idle_after_fcc_completion_candidate` | High mechanics | FD2=0 with114C nonzero setsFD2=1,FD4=640,1155=1,FCC1,selectsFB7=8/byte1=1 unless80000, publishes684810(actor,1),returns.114C zero only idles unless80000 and remainsFD2=0. FD2=1 waitsFCC0, incrementsFD2=2, thenidlesunless80000. OtherFD2returns. No phaseadvance. |

Motion changes clear8..B/FB8 as stated; exceptions setting8=2 are explicit.
The predicates use ordered floating comparisons exactly as in the original;
NaN admission behavior is not replaced with an assumed ordinary distance check.
684810 routing alone does not establish actual message delivery.

Owned72FB60 length3C five XYZ vectors:
`(10190,0,14150),(10560,0,13930),(10710,0,13980),(10990,0,14042),(11310,0,14090)`;
SHA256`d5b4b3b1086e434facbbb6372d1a466a1b135d4771f240993b679df7d223a9ab`.
Owned72FBA0 and72FBB0 each lengthC contain identicalXYZ(11498,95,11264), each
SHA256`1a6bbb88c40cb1f84155239b5ba04b12cfac0b0b9cd0b7b7ee1f85e7a0b7b8de`.
Owned72FBC0 lengthC containsXYZ(11550,268,11105),
SHA256`33eb2ed21fc09201a4cb08dac4ce0a4e1ea856739ce4412daf5205dcfb71d819`.
Numeric locations do not identify an original room by themselves. Owned image
`build-function-index/owned-overlays/o2.bin`, base570000,
SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Parent [class64 script](SYMBOLS_ACTOR_6BDA50_COMMAND_FAMILY.md);
route helper6BD270 [review](SYMBOLS_ACTOR_SCRIPT_POSITION_COMPLETION.md).

Full-body owned-word audit: seven rows, 510 verified instruction words,
zero conflicts, 25 omitted zero/NOP words, zero omitted nonzero words.
