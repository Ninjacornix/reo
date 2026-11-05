# Interaction pose bank resolution and actor placement

Static File #1 US research, 2026-11-04. Seven complete original bodies reviewed. Addresses, field offsets, IDs, masks and enum values are hexadecimal; physical counts and explicitly written float values are decimal. This is static evidence, not a recorded slowdown, reproduction or confirmed fault. Mechanics confidence is high; interaction names are candidates and original category names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x581250](../recomp/config/output_ovl/o2/o2_00581250_0x581250.cpp) | `resolve_last_kind_zero_or_two_interaction_pose_from_scene_matrix_candidate` | High mechanics; role probable | a0 ID, a1 actor, a2 output XYZ, a3 output yaw word, t0 subselector. Last matching kind0/2 descriptor wins; extracts scene matrix translation before actor class admission. Selected offset table is rotated and added; accepted class/category contracts and partial-output paths below. |
| [o2 0x5815F0](../recomp/config/output_ovl/o2/o2_005815F0_0x5815f0.cpp) | `resolve_last_kind_one_fixed_interaction_pose_for_actor_category_candidate` | High mechanics; role probable | a0 low8 ID, a1 actor, a2 XYZ, a3 yaw. Last kind1 descriptor with matching word40. Only actor class2 category1/16/29/2B writes fixed XYZ at descriptor4C and yaw=(word58-8000)&FFFF. Other classes/categories return1 without writing outputs; disabled/missing descriptor returns0. |
| [o2 0x580380](../recomp/config/output_ovl/o2/o2_00580380_0x580380.cpp) | `place_actor_from_kind_zero_interaction_matrix_and_classify_phase_candidate` | High mechanics; role probable | a0 mode, a1 low8 ID, a2 actor. Last kind0 word40 match. Writes matrix translation to actor38 before class admission; class/category-dependent table offsets, room-mask publication and AB9/ACC classification below. Final accepted path copies XYZ to ABC, yaw word58 to AC8/92, sets AB8=1. |
| [o2 0x580A10](../recomp/config/output_ovl/o2/o2_00580A10_0x580a10.cpp) | `place_actor_from_kind_one_fixed_pose_and_selector_offset_candidate` | High mechanics; role probable | a0 low8 ID, a1 actor. Last kind1 word40 match. Class0 writes AB9 from70A750[descriptor6C] before checking selector<8, then dispatches eight-case table73DF10. Class1/2 only selectors0/7 write XYZ/yaw; other paths can still set AB8=1. Detailed case effects below. |
| [o2 0x580E70](../recomp/config/output_ovl/o2/o2_00580E70_0x580e70.cpp) | `place_actor_from_kind_six_banked_interaction_anchor_candidate` | High mechanics; role probable | a0 low8 ID, a1 actor. Last kind6 node with word54==(ID&7F), word4C=4 when ID high80 clear or5 when set. Yaw word48 rotates70B270[actorB99], then scene-slot word60 translation is added; Y replaced by signed descriptor20 converted to float. Copies XYZ to ABC, writes AC8/92, ACC=200.0, ABB=low8 slot, AB8=1; AB9 untouched. |
| [o2 0x5C1100](../recomp/config/output_ovl/o2/o2_005C1100_0x5c1100.cpp) | `publish_interaction_control_byte_and_clear_companion_candidate` | High mechanics; role probable | Stores low8 a0 at3DDDD5 and clears byte3DDDB2, including the return delay slot. No actor argument, queueing, Boolean result or notification proof. Called with2 by several kind0 class0 classification paths. |
| [o2 0x570CC0](../recomp/config/output_ovl/o2/o2_00570CC0_0x570cc0.cpp) | `publish_actor_pending_interaction_code_candidate` | High mechanics; role probable | a0 actor, a1 code: byteAD4=1, byteAD5=low8 code in return delay slot. No immediate dispatch or clearing of AB8. Kind1 selector6 calls with codeB. |

All five descriptor consumers first reject signed half3B5150==80. They traverse head3B5160 with next28 and keep the **last** matching node; this differs from the first-match getters5819C0/581AF0 in [linked queries](SYMBOLS_LINKED_INTERACTION_PROXY_QUERIES.md). There is no local list-count/cycle limit or output-pointer/index validation. These observations alone do not prove malformed lists or indices occur.

For581250, kind0 requires descriptor40==low8 ID and uses scene slot4C, offset index54, yaw=(word58-8000)&FFFF. Kind2 additionally requires descriptor50==low8 t0, and uses slot44, offset index48, yaw=unsigned half4C. Matrix M=49FA10+40*slot:1900E0 writes its translation to output XYZ, then1919D0 rotates an indexed XYZ vector by M and370500 adds it. Class1 uses70B070; class2 categories1/16/29 use70B0D0; class2 category2B uses70B160. Non1/2 classes return0 after the base translation write. Class2 with another category branches581460->5815BC, reaches final vector addition with no local initialization of stack offset50 and no yaw write, then returns1. Caller category admission and stack contents remain unknown; no observed corruption or slowdown is asserted.

For580380 let D be the last matching descriptor and let L mean actor byte3==byte4BADED. It immediately writes translation of M=49FA10+40*D.word4C to actor XYZ. Class0 with byte4BAE34 nonzero rotates70B070[D.word54] and skips ABB/AB9/ACC and room-mask updates. Other class0 paths write ABB=low8 D.word4C; if L, OR room half4B9E22+12*currentRoom with low16(1<<(D.word40&1F)). Selector D.word60 then controls:

| Class0 selector | AB9 / ACC / additional work |
| --- | --- |
| 0 | Calls570700(currentRoom,D40,3) and570700(D44,D48,3). If room half4B9E24+12*room contains the D40 bit, or low8 mode==5 and L, set ACC=168.0 and AB9=70B190[D50]+1F. Otherwise AB9=map+1 and call5C1100(2); ACC retained. |
| 1 | ACC=168.0; mode5 and L ->AB9=2F; otherwise AB9=1A and5C1100(2). |
| 3 | ACC=168.0; mode5 and L ->AB9=30; otherwise AB9=29 and5C1100(2). |
| 2 or other | Keep prior AB9/ACC. |

After classification class0 uses70B0A0[D50] if AB9==1A/29, otherwise70B070[D50], rotated by M. Class1 writes ABB, AB9=70B190[D50]+1 and rotates70B070[D50], retaining ACC. Class2 admits only categories1/16/29/2B; others exit after the initial XYZ write. Accepted class2 writes ABB and classifies D60: selector0 ->AB9=7/ACC168.0 if byte4A3621+60*D40 nonzero, mode5, or room4B9E24 bit set; otherwise AB9=map+1 with ACC retained. Selector1 ->AB9=1A/ACC168.0; selector3 ->AB9=29/ACC168.0; other selectors retain both. Category2B with AB9==1A/29 uses70B0A0[D50]; all other accepted class2 paths use70B130[D50]. Every final path adds the rotated offset, copies XYZ to ABC, writes original D58 to full AC8 and half92, and sets AB8=1. Other actor classes branch580440->5809B8 and use the locally uninitialized stack offset40; valid caller categories remain an admission question.

580A10 class0 first publishes AB9=70A750[D6C], before unsigned selector<8. Owned73DF10 selects:

| Selector | Placement / additional effects |
| --- | --- |
| 0,7 | XYZ and ABC=D4C XYZ; AC8/92=D58; ACC=float(unsigned D70). |
| 1 | AC8=D58-8000 without full-word mask, half92 same; rotate70B1A0[actorB99] by yaw, add D4C XYZ, copy ABC; ACC=0; ABB=low8 D78. |
| 2,4 | AC8/92=D58; rotate70B200[actorB99], add D4C, copy ABC; ACC=float(unsigned D70). |
| 3,5 | Same placement contract as2/4 through a separate physical instruction branch. |
| 6 | Fixed XYZ/ABC and yaw D58;570CC0(actor,B), early return skips common AB8=1. ACC retained. |
| >=8 | No case placement after AB9 lookup; falls through AB8=1. |

Class1/2 selectors0/7 copy fixed XYZ/ABC and yaw only, retaining ACC; other selectors leave pose untouched. Other classes also leave pose untouched. All those paths set AB8=1. Disabled or absent descriptor paths do not set it. These handlers do not promise Boolean return values.

Owned offset vectors and dispatch/phase bytes are recorded in [pose offset data](SYMBOLS_INTERACTION_POSE_OFFSETS.md). Physical table spans are not proof of valid authored index ranges. The previously mapped570700 is [clear strided room flag and notify](SYMBOLS_TASK_FLAGS.md), not a pose calculation. Forwarding5816F0/581730 is covered by the linked-query notebook; this notebook closes their five lower pose callees. Original/native override boundaries remain separate from original guest-body semantics.

Owned-word audit:7 rows,1030 distinct instruction words verified,70 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned intervals include each original delay slot.
