# Related-actor reciprocal command policy 627770

Static File #1 US, 2026-11-04. One complete 3,048-byte catalog body contains reciprocal-link admission, eleven literal current-state cases, and one eleven-target interior table. Mechanics have high confidence; original cooperative action and direction names remain unknown. This is static evidence only, with no execution, build, attachment, live memory, input, or timing. Addresses, IDs, flags, and field offsets are hexadecimal. See [related-ID resolver and control gates](SYMBOLS_ACTOR_ACTIONS.md), [neighboring preemption](SYMBOLS_ACTOR_COMMAND_PREEMPTION_AND_EDGE_POLICIES.md), and [state snapshot/message](SYMBOLS_DISPATCH.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x627770](../recomp/config/output_ovl/o2/o2_00627770_0x627770.cpp) | `route_reciprocal_related_actor_control_states98_througha1_b5_dd_candidate` | High mechanics; candidate role | Resolves related actor with 666AF0(self), checks partner primary/secondary and reciprocal link; common recovery selects (1,A2,AFF/B0), snapshots, and returns 1. Category 0 except secondary DD polls 64F110. States 98..A1/B5/DD then consume F78/F80 masks with the ordered transitions below; unknown secondary returns 0. A1 with valid partner A3..AD indexes eleven identical return-0 targets; another partner state clears BA0 bit 80000 and recovers. B5 phase 3 calls 64F2D0; DD phase 3 sets AB8=1, calls 64EF10, and may send 67E230 selector 3. |

Every selected state in the matrix sets primary byte 8 to 1 and B to 0, calls 667370 (snapshot XYZ/yaw), and returns 1. Phase A is 0 unless annotated 2 or FF. Ordinary hold returns 0. This body does not request animation motions, advance the game clock, allocate, or contain a blocking wait. Native override and runtime caller admission remain separate from this original guest body.

Entry admission, in order:

1. Resolve p=666AF0(self). If p is null and self secondary is not DD/B5/A2, select recovery A2/AFF. DD/B5/A2 skip this recovery and reach the partner byte-8 read at 6277E4 without a local null guard. The resolved-link invariant and caller admission are unknown; this is not a reproduced crash or performance cause.
2. Partner primary !=1 or partner secondary AD selects the same recovery unless self secondary is DD/B5/A2. Those exception states continue.
3. Resolve 666AF0(p) and compare with self. A mismatch selects recovery unless self secondary is A2. Thus DD/B5 skip the first two admissions, but not the reciprocal mismatch admission.
4. Unless self secondary is DD, category byte 2 ==0 calls 64F110; nonzero returns handled=1 before the current-state switch. Actor fields are reread after that call.

Current state 98 first checks B9B==2 -> A2/A0; then category 0, 1B02D0()==1, and nonzero FF0 -> A2/A0. Next F78 bit 20 selects B5/A0, and bit 10 selects A2/A0. Each other state 99..A0 first checks F78 bit 10 -> A2/A0. Remaining F80 priorities are ordered left to right:

| Current secondary | Ordered F80 tests -> selected secondary/phase | Otherwise |
| --- | --- | --- |
|98|bit1 ->9B/0; bit2 ->9E/0; bit8 ->99/0; bit4 ->9A/0|hold|
|99|bit1 ->9B/0; bit2 ->9E/0; bit8 clear ->98/0|hold|
|9A|bit1 ->9B/0; bit2 ->9E/0; bit4 clear ->98/0|hold|
|9B|bit1 clear ->98/0; bit8 ->9C/2; bit4 ->9D/2|hold|
|9C|bit1 clear ->98/0; bit2 ->9E/0; bit8 clear ->9B/2|hold|
|9D|bit1 clear ->98/0; bit2 ->9E/0; bit4 clear ->9B/2|hold|
|9E|bit2 clear ->98/0; bit8 ->9F/2; bit4 ->A0/2|hold|
|9F|bit2 clear ->98/0; bit1 ->9B/0; bit8 clear ->9E/2|hold|
|A0|bit2 clear ->98/0; bit1 ->9B/0; bit4 clear ->9E/2|hold|

Register liveness was reviewed explicitly at branch entries: 9C/9D's bit-2 path stores 9E from v0 loaded at 627910; 9B's bit-8/4 paths use a2=9C and a3=9D; 9E uses a1=9F and a2=A0. These constants are not callback results or unknown register values. All branches and delay-slot stores were reviewed, including the initially truncated 627CA8..627E80 span.

A1 only acts when unsigned phase A>=2. If partner primary !=1, it clears own BA0 bit 80000 and selects recovery (1,A2,AFF/B0). Partner primary 1 and secondary A3..AD index owned table 73FDA0: all eleven entries target 628340, returning 0. Any other partner secondary clears the bit and recovers. Locally repeated validation retains original order; dynamic mutation and entry reachability were not observed.

B5 only calls 64F2D0(self) in phase A=3; nonzero returns 1, otherwise 0. DD only acts in phase A=3: it sets AB8=1, calls 64EF10(self,0), and on nonzero calls 67E230(self,3) and returns 1. Otherwise it returns 0 with AB8 already changed. Neither zero result is assumed side-effect-free. Secondary A2 passes earlier exceptions but is not a switch case, and returns 0 after entry/control-request checks.

Owned o2 base 570000 has SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Full table 73FDA0..73FDCB contains eleven targets `628340`, SHA256 `4c9bdf5534bc6023a9f4bb6cc2293963659860d61c3b44664a108dece23d0fc5`. External assets are unnecessary for this literal state graph. Runtime actor identity/link validity, input frequencies, and performance root causes remain unknown.

Full owned-body audit: 699 original instruction words verified; 63 omitted words are zero/NOP. No conflicting comments or omitted nonzero words.
