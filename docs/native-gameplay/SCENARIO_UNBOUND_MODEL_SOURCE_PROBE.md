# Authored FF model references: original-only probe

Status: completed offline original-code probe, not an installed native repair or a recorded game test.

The bounded File1 room inventory contains five relevant FF model references across `r0010100.rdt` (two type2 controls), `r0012200.rdt` (one type0), and `r0417300.rdt` (two type0). The original initializer uses the byte as an unchecked physical model index. These cases were previously refused by the native room installer.

The complete owned `5C1390` initializer and its real model/helper dependencies were executed against each room's verified sectionA and script maps. Both compiler cohorts passed 3,656 checks and 656 original calls. Exact images, word audits, source copies, binaries and receipts are linked by [the qualification](../../tools/native_reconstruction/native_gameplay_unbound_scene_alias_probe_qualification_v1.json).

The measured effects are:

| Original access | Actual result in the controlled initialized fixture |
| --- | --- |
| Sound map `4A1D70 + FF` | Changes the high byte of room2/counter15 at `4A1E6E`; seed `1234` becomes `0034`, `0034`, or `0134`, respectively. |
| Pose `49FA10 + 64*FF` | Reads 64 zero bytes at `4A39D0`, spanning channel9 translation and channel10 metadata/first matrix column. |
| `5D8280(FF,target)` | Copies that zero pose to the target, sets bit31 of the word overlapping real pointer slot3 (`4A1B7C`), and writes the guest target pointer into room7/counters22–23 (`4A1F6C`). |
| `5D8300(FF)` | Clears the aliased mask bit and pointer/counter pair. |
| Four generated FF helpers | Zero-area geometry; full original `370960` and native containment both reject all 161 sampled points per helper. |

The earlier hypothesis that zero inverse input would produce NaN/INT_MIN bounds was wrong. Actual `191430` uses the observed VRSQRT saturation behavior and produces finite zero results. The failed LLVM-v1 expectation is retained; LLVM-v2 and GCC-v1 measure the corrected result.

Room initialization first relocates script references (`68C570`), then invokes `5C1390`. Neither that relocation nor the subsequent grid/route/timer initialization proves a later reset of these accidental writes. `5D7CF0` counter reset belongs to the earlier EVB setup path. A syntactic counter-consumer search is only a candidate inventory, not proof that every indirect consumer is unreachable.

The affected room maps cannot select channel9/10 through the first-match model-to-channel lookup, and their type0/2 route IDs are0–3. That bounds the immediate tested selector path. It does not prove that later authored scripts, replacement controls, or the remaining ten-channel outer playback/task path can never change the aliased region.

The source behavior cannot be a fully native contract because it stores guest pointer values into unrelated counters. A separate, explicitly admitted NoModel modernization candidate must preserve authored absence and useful sound metadata without reproducing those aliases. That candidate needs its own deviation ledger, lifecycle/consumer tests and eventual affected-room game acceptance. This probe grants none of those claims.
