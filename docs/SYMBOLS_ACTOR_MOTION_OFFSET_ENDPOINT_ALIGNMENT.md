# Motion-derived endpoint alignment states13/47 and14/3B

Static File #1 US, 2026-11-05. Two complete original o2 bodies reviewed, including interpolation entry/exit conditions, delay slots and literal descriptors. Addresses, states, masks and offsets are hexadecimal; float limits, durations and event frames are decimal. No execution, build, attachment, live memory, input or timing.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x62FEE0](../recomp/config/output_ovl/o2/o2_0062FEE0_0x62fee0.cpp) | `align_states13_47_and_interpolate_motion_offset_endpoint_candidate` | High mechanics; candidate role | Owned primary-one13/47 entries. Prefix54A F/BA0 mask800000;32FF exceptsecondary47. Consumed reset restarts0. Phase0 visualB/D10=1/snapshot/BA8=1/CE2=0; distance to preexistingC34<=40 setsphase1/clearsroots/flags82, optionally descriptor ifBA4bit2, then returns. Far/unmatched phases alignmode0; nonzero selects1. Phase1 builds motion-derived endpoint and sets2. Phase2 interpolates endpoint/yaw and advancesBA8;47 frame250 gate can select3, positive signed-byte boundary overridesFF. Phase3 writes32FF and advances until positive ->FF. FF flags82 thenbase cancellation/blend10. |
| [o2 0x630350](../recomp/config/output_ovl/o2/o2_00630350_0x630350.cpp) | `align_states14_3b_and_interpolate_motion_offset_endpoint_candidate` | High mechanics; candidate role | Owned primary-one14/3B entries. Same preexisting target/distance/optional motion and endpoint interpolation as62FEE0, with prefix54A F/BA0800000/32FF/553=0 always. Chooses descriptor710270 if14 or710278 if3B. Phase2 positive signed-byte boundary ->FF after optional position/yaw interpolation. No frame250 gate or localphase3 branch; unmatched phases alignmode0. FF flags82 thenbase cancellation/blend10. |

Direct owned primary-one table pointers admit62FEE0 for states13/47 and630350 for14/3B. They use preexisting targetC34/C38/C3C/C4C; phase0 does not copy target from ABC/AC4. True XYZ distance191D10<=40 selectsphase1, root clear/flags82. Only BA4 bit2 permits that early descriptor request; with it absent, phase1 is selected while current motion remains until the next call. Both paths return this tick. Far initialization calls alignmentmode0 once without consuming the result; later unmatched alignment calls consume nonzero and select1.

Phase1 increments2, sets visualB/BA8=1/flags82, selects the appropriate descriptor/start0/blend10. It saves startXYZ intoC40/C44/C48 and signed yaw intoC4E, timer12=20 for clockmode0 or10 otherwise. Main1925C0 evaluates translation difference from start0 toend20 on model34->node824. It rotates that translation by unsigned targetC4C using73FFB8*angle/65536 and191BC0, then adds preexisting targetC34/C38/C3C to store derived endpointABC/AC0/AC4. Root evaluation is not a pure vector subtraction: its [mapped animation contract](SYMBOLS_ANIMATION.md) includes resource resolution and two temporary pose evaluations.

Phase2 with nonzero signedtimer12 decrements first and curve-interpolates ownXYZ fromC40 toward derivedABC, and yawC4E towardC4C. It clears roots, snaps exactly to derived endpoint/yaw on newtimer0, then continues animation. Oldtimer0 skips interpolation but still advances atBA8. Positive signed-byte animation boundary selectsFF independently of whether the timer has completed. No extra requirement that both conditions finish is invented.

62FEE0 secondary47 additionally checks primary track frame250 crossing atstep1 before advancement; admitted crossing incrementsphase3. The subsequent positive animation boundary in the same call can overwrite that phase withFF. In phase3,32 isFF from the live v1 constant at the early compare chain, not the numeric phase3; it advances atBA8 and positive boundary selectsFF. 630350 has no such gate/phase3 case. Direct phase3 therefore follows its unmatched alignment path.

Complete32-byte descriptor window710260..71027F:

| Address | Word0 | Halfword4 | Halfword6 (stored motion520) | State |
| --- | --- | --- | --- | --- |
|710260|8A000010|8222|2222|13|
|710268|10|237|237|47|
|710270|9A000010|9223|223|14|
|710278|10|236|236|3B|

This is the leading32-byte portion of the fully verified48-byte window710260..71028F, SHA256`ace6de8ba1168b371be228c0fd0b1bd5e2426993d98b42239fca2eb81fe67c9d`. High flag bits and differing descriptor halfwords are preserved rather than replaced by a guessed plain animation ID.

PhaseFF calls flags82, then base cancellation: clears54F/548 bit0, selects(1,0,1,0), snapshots, motion2050/start0/blend10, activates banks. PrefixBA0800000 is not locally cleared. Descriptor setup does not locally call bank activation before this final base path. Original full phase bodies are not assumed equivalent simply because large sections match.

[Alignment curves](SYMBOLS_ACTOR_ACTIONS.md), [frame gates](SYMBOLS_TASK_FLAGS.md), and [snapshot/reset helpers](SYMBOLS_DISPATCH.md) retain separate contracts. Runtime target writers, resource validity, phase frequency and timing cost remain unknown. Owned o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full owned-body audit: 517 original words verified; 20 omitted words all zero/NOP. Zero conflicts or omitted nonzero words.
