# AB9 paired descriptor and interaction sequences

Static File #1 US, 2026-11-04. Six complete original o2 bodies reviewed with all branch targets and delay slots. Five use a closed two-family descriptor selection; the adjacent sixth uses a literal descriptor. Addresses, states, masks, IDs, and field offsets are hexadecimal. Floats and timer lengths are decimal. No execution, build, attachment, live memory, input, or timing.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x62B7F0](../recomp/config/output_ovl/o2/o2_0062B7F0_0x62b7f0.cpp) | `align_and_interpolate_ab9_pair_entry_motion_then_enter_state89_candidate` | High mechanics; candidate role | AB9=18 selects descriptor family base0, all others5. Prefix54A1F; reset immediately base cancellation. Phase0 visual32/D10=1/snapshot/root clear, target saved XZ/currentY/yaw; XYZ distance<=40 selects phase1 directly, otherwise mode0 alignment once without using result. Unmatched phases continue alignment, nonzero ->1. Phase1 sets2/flags82, descriptor710090+8*base/start0/blend20, saves currentXYZ/yaw and timer12=20 if clock mode0 else10. Phase2 may interpolate and advances animation; exact signed-byte boundary1 advances3 independently of timer. Phase3 selects (1,89,0,0)/snapshot; phase4 base cancellation. |
| [o2 0x62BB50](../recomp/config/output_ovl/o2/o2_0062BB50_0x62bb50.cpp) | `finish_interaction_then_loop_ab9_pair_descriptor_plus_one_candidate` | High mechanics; candidate role | AB9 family selection same0/5. Prefix54A1F; reset base cancellation. Every nonreset call first invokes5708B0(self), before phase dispatch. Phase0 visual32/D10=1/snapshot/root clear falls into1. Phase1 sets2/flags82, descriptor710090+8*(base+1)/start0/blend20, bank activation. Phase2 advances at1, ignores boundary; no local completion exit. |
| [o2 0x62BCD0](../recomp/config/output_ovl/o2/o2_0062BCD0_0x62bcd0.cpp) | `clear_interaction_flags_play_ab9_pair_descriptor_plus_two_and_return_candidate` | High mechanics; candidate role | AB9 family0/5, prefix54A1F; reset restarts0. Phase0 visual32/D10=1/snapshot/root clear, increments and clears interaction flags570750(self), falls into1. Phase1 sets2/flags82, descriptor710090+8*(base+2)/start0/blend20, banks. Phase2 signed-byte boundary1 ->FF; phaseFF base cancellation. Unlike62BB50, interaction cleanup occurs only on phase0. |
| [o2 0x62BE70](../recomp/config/output_ovl/o2/o2_0062BE70_0x62be70.cpp) | `loop_ab9_pair_descriptor_plus_three_candidate` | High mechanics; candidate role | AB9 family0/5, prefix54A1F; reset base cancellation. Phase0 visual32/D10=1/snapshot/root clear falls into1. Phase1 sets2/flags82, descriptor710090+8*(base+3)/start0/blend20/banks. Phase2 advances at1 ignoring result. No570750/5708B0 interaction cleanup in this body. |
| [o2 0x62BFE0](../recomp/config/output_ovl/o2/o2_0062BFE0_0x62bfe0.cpp) | `play_ab9_pair_descriptor_plus_four_then_return_base_candidate` | High mechanics; candidate role | AB9 family0/5, prefix54A1C; reset restarts0. Phase0 visual32/D10=1/snapshot/root clear falls into1. Phase1 sets2/flags82, descriptor710090+8*(base+4)/start0/blend20/banks. Phase2 signed-byte boundary1 advances3; phase3 base cancellation. Original prefix differs from1F in other family handlers. |
| [o2 0x62C180](../recomp/config/output_ovl/o2/o2_0062C180_0x62c180.cpp) | `play_visual1d_descriptor7100e0_then_return_base_candidate` | High mechanics; candidate role | No54A/32/553 prefix stores. Consumed reset restarts0. Phase0 visual1D/D10=1/snapshot/root clear falls into1. Phase1 sets2/flags82, literal descriptor7100E0/start0/blend20/banks. Phase2 signed-byte boundary1 advances3; phase3 base cancellation. Original descriptor bytes are owned and listed below. |

The AB9 test is literal18 versus all other unsigned bytes; it does not locally admit a larger descriptor index. Full80-byte window710090..7100DF contains ten records with word0=10 and equal halfwords4/6:

| Offset in family | AB9==18 | Other AB9 |
| --- | --- | --- |
|0|710090:160|7100B8:165|
|1|710098:163|7100C0:168|
|2|7100A0:162|7100C8:167|
|3|7100A8:161|7100D0:166|
|4|7100B0:164|7100D8:169|

SHA256 `11a5be649f48e48e780a09d8fa96759743f9277718b67b87ee8c69957ba4d068`. Motion/resource names are not established by the numeric pair selection. No mapping to character or item names is claimed.

## Interpolation and phase completion

62B7F0 measures true XYZ distance through main191D10; target Y is initialized from current Y, making this local initial test equivalent to horizontal distance. It admits distance<=40 to phase1. When phase2's signed timer12 is nonzero, it decrements first, then invokes665E60 on XYZ and665FC0 on wrapped yaw with elapsed=T-newTimer and durationT, T=20 for clock mode0 or10 otherwise. It clears root deltas and snaps to exact target XYZ/yaw on newTimer0. With oldTimer0 it skips interpolation. Signed nonzero admission also preserves negative-timer behavior rather than clamping it.

Animation58C300 at1 is called whether or not interpolation ran. Its signed-byte result exactly1 advances phase3 even if the timer has not reached zero; the code does not locally require both completions. Phase3 enters89; phase4 exists as a distinct base-return branch but has no internal predecessor in this reviewed body. Caller/external phase writers remain unknown. See [distance](SYMBOLS_RENDER_MATH.md), [curve interpolation and alignment](SYMBOLS_ACTOR_ACTIONS.md), and [animation](SYMBOLS_ANIMATION.md).

## Cleanup frequency and base return

5708B0 is a tail adapter to guarded interaction completion5707E0; it is called by62BB50 before every nonreset phase dispatch. 62BCD0 instead calls570750 only during phase0 initialization, clearing interaction/room flags through that helper's selected-actor-aware contract. These are distinct operations and frequencies. See [interaction flag helpers](SYMBOLS_TASK_FLAGS.md).

Base cancellation clears54F and halfword548 bit0; selects (primary,secondary,phase,B)=(1,0,1,0), snapshots, motion2050/start0/blend10, bank activation. Prefix flags remain as written unless another helper changes them. None of these bodies initializes BA8 or changes the original game clock. Return registers are not normalized completion booleans. Runtime behavior, asset names, external phase admission, and slowdown cost remain unknown.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Literal descriptor7100E0: bytes`1000000064016401`, word/halfwords`(16, 356, 356)`, SHA256`18f274a5e60dc747d81caea9ce810f06c525ce8aa874f345dfb6a0fe653192c4`.

Full owned-body audit: 656 original instruction words verified; 31 omitted words all zero/NOP. Zero conflicts or omitted nonzero words.
