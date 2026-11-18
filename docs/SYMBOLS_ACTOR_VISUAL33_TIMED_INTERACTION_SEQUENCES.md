# Visual-state33 timed interaction sequences

Static File #1 US, 2026-11-04. Five complete original o2 bodies reviewed with delay slots and fixed dispatch/table evidence. Addresses, offsets, states, and masks are hexadecimal; float/timer values are decimal. No execution, build, attachment, live memory, input, or timing. Action names remain numeric candidates.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x62C2E0](../recomp/config/output_ovl/o2/o2_0062C2E0_0x62c2e0.cpp) | `align_states8e_8f_and_play_visual33_entry_descriptor_candidate` | High mechanics; candidate role | Prefix54A1F; reset base cancellation. Phase0 visual33/D10=1/snapshot/root clear, target saved XZ/currentY/yaw, mode1 alignment twice (first result ignored); later unmatched phases continue mode1, nonzero selects1. Phase1 sets2/flags82; descriptor index=(secondary8E?0:5)+(B9B==2?3:0), base7100F0/start0/blend20/banks. Phase2 signed-byte boundary1 advances3; phase3 selects primary1/secondary90 if8E else91/A=B0, snapshot. |
| [o2 0x62C4F0](../recomp/config/output_ovl/o2/o2_0062C4F0_0x62c4f0.cpp) | `complete_interaction_and_wait_timed_visual33_descriptor_before94_95_candidate` | High mechanics; candidate role | Prefix54A1F; reset base cancellation. Every nonreset call invokes5708C0 before phase dispatch. Phase0 visual33/D10=1/snapshot/root clear, timer C=3600 if clockmode0 else1800, falls into1. Phase1 sets2/flags82, index1 ifsecondary90 else6 at7100F0/start0/blend20/banks. Phase2 decrements signed C only when nonzero, advances animation at1, and requires signed-byte result1 AND newC0 before selecting primary1/secondary94 if90 else95/A=B0/snapshot. |
| [o2 0x62C6D0](../recomp/config/output_ovl/o2/o2_0062C6D0_0x62c6d0.cpp) | `play_visual33_exit_descriptors_for_states92_through95_candidate` | High mechanics; candidate role | Prefix54A1F; reset base cancellation. Phase0 visual33/D10=1/snapshot/root clear falls into1. Phase1 sets2; secondary92/94 chooses index2,93/95 index7, then adds2 ifB9B==2, applies7100F0+8*index/start0/blend20 without local flags82/bank activation.92/93 also emit595F10(self,0) model-node sound and locally controlled AB9!=2C sends37C060(12,0,0). Phase2 signed-byte boundary1 ->FF;FF base cancellation. Other secondaries do not locally initialize the selector. |
| [o2 0x62C970](../recomp/config/output_ovl/o2/o2_0062C970_0x62c970.cpp) | `play_visual34_descriptor16d_then_return_base_candidate` | High mechanics; candidate role | Prefix54A1F; reset restarts0. Phase0 visual34/D10=1/snapshot/root clear falls into1. Phase1 sets2/flags82, descriptor710140/start0/blend20/banks. Phase2 signed-byte animation result exactly1 advances3; phase3 base cancellation. No local BA8 initialization. |
| [o2 0x62CAD0](../recomp/config/output_ovl/o2/o2_0062CAD0_0x62cad0.cpp) | `play_visual34_descriptor16e_then_return_base_candidate` | High mechanics; candidate role | Same complete prefix/reset/phase sequence as62C970, but literal descriptor710148 (motion16E). Phase2 exact signed-byte animation result1 ->3; phase3 base cancellation. Separate original body retained; no assumption of equal runtime use. |

The complete eight-word primary-one dispatch slice712E88..712EA7 maps secondary8E/8F to62C2E0,90/91 to62C4F0,92/93/94/95 to62C6D0. SHA256 `36f03b8d459b3f943450078f762f5d80e2cbc60ec80e29b3210a31f2c13db487`. This provides a concrete ordinary caller domain for62C6D0's local selector, while other direct/resumable entries remain outside the reviewed admission. No reachable uninitialized-selector bug is claimed.

Complete96-byte descriptor window7100F0..71014F has word0=10 and equal halfwords4/6:

| Index from7100F0 | Descriptor | Motion halfwords4/6 |
| --- | --- | --- |
|0|7100F0|36B|
|1|7100F8|36C|
|2|710100|36D|
|3|710108|375|
|4|710110|376|
|5|710118|370|
|6|710120|371|
|7|710128|372|
|8|710130|377|
|9|710138|378|
|A|710140|16D|
|B|710148|16E|

Window SHA256 `608e3c6af39b840d6838f63414fd0ef41058b19f47b470c1fb956105dd98c715`. B9B is tested for exact2; all other values use the alternate branch. The index arithmetic above stays within the ten descriptor family members for admitted secondary states.

62C4F0 differs from nearby sequences by requiring both animation boundary1 and expired timer before exit. Its timer decrements whenever signed C!=0, retaining negative-count behavior; it is neither clamped nor derived from wall time. 3600/1800 original ticks are not converted to a measured duration. Completion dispatch5708C0 executes before every nonreset phase dispatch and can emit its own numeric requests. [Interaction dispatch](SYMBOLS_TASK_FLAGS.md) retains those admission/side effects; [model-node audio](SYMBOLS_ANIMATION_CROSSING_EVENTS.md) establishes595F10's sound role.

Base cancellation clears54F/548 bit0, selects (primary,secondary,phase,B)=(1,0,1,0), snapshots667370, requests2050/start0/blend10 and activates banks. Descriptor playback/snapshot/flags82/bank activation remain separate calls; notably62C6D0 omits the local flags82 and bank activation present in other handlers. See [animation](SYMBOLS_ANIMATION.md), [alignment](SYMBOLS_ACTOR_ACTIONS.md), and [reset/message](SYMBOLS_DISPATCH.md).

Runtime input/action frequencies, original action names, native override admission, and slowdown cost remain unknown. Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full owned-body audit: 555 original words verified; 36 omitted words are zero/NOP. Zero conflicts or omitted nonzero words.
