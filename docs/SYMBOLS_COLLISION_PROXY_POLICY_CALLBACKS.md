# Collision proxy policy, inventory and scene-anchor callbacks

Static File #1 US research, 2026-11-04. Four complete original bodies reviewed; addresses/offsets/IDs hexadecimal, floats explicitly decimal. P=a0 proxy, A=P.word34 actor. Local mechanics confidence high; semantic role candidates remain probable. No execution, attachment, builds, replay or incident diagnosis.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5C3FE0](../recomp/config/output_ovl/o2/o2_005C3FE0_0x5c3fe0.cpp) | `collision_proxy_set_policy_selected_flag_and_optional_event_candidate` | High mechanics; role probable | Class0 actor only. P.word4C chooses actor-ID/B98/authority gate. On admission P.word44 selects primary or per-actor flag write for low9 P40, optionally570120(P.unsignedHalf58,3C,4). Full gates and modes below; no proxy deactivation or actor-pose mutation. |
| [o2 0x5C4230](../recomp/config/output_ovl/o2/o2_005C4230_0x5c4230.cpp) | `collision_proxy_consume_query_or_destroy_inventory_content_and_publish_flag_candidate` | High mechanics; role probable | Class0 actor only. Same numeric gate family at P58/5C/60; operation P4C0..3. Uses inventory content half48 and optional second half54, flag IDlow9 P40, flag bankP64. Consumption/destruction and item-query ordering below;5F4FD0 and optional570100 after selected operations do not prove runtime refresh cost. |
| [o2 0x5C4600](../recomp/config/output_ovl/o2/o2_005C4600_0x5c4600.cpp) | `collision_proxy_request_conditional_counter_indexed_event_and_optional_task_candidate` | High mechanics; role probable | Class0 and1B0340(actor)!=0. Base event unsignedhalfP50, alternativeP54; flag/task conditions encoded in half52, selected-player category maskP59, counter P.signedHalf6C/6A. Can request a task and return early, publish a primary/per-actor flag, request570120 and5BF0F0, then optionally deactivate P3C. Detailed bounded local flow below; no renderer/root-cause inference. |
| [o2 0x5C4940](../recomp/config/output_ovl/o2/o2_005C4940_0x5c4940.cpp) | `collision_proxy_classify_scene_anchor_actor_phase_with_facing_gate_candidate` | High mechanics; role probable | Only actor classes0/1, rejects P.word4C==3. Builds yaw basis fromP48 and scene translation slotP60. Current actor byte54F==1A selects separate phase logic; other paths compute candidate target XYZ from rotated fixed offsets, normalize offset for dot against actor forward, require ordered dot<=0 before publication. Full class/mode table below. No generic pose teleport claim: common writes ABC/AB8/AC8/ABB, not actor38. |

For5C3FE0 let gate=P4C, expected=P50, inequality=P54. For5C4230 those fields are P58/P5C/P60. Both require A.class2==0, and then:

| Gate | Admission |
| --- | --- |
| 0 | Unconditional. |
| 1 | Boolean(A.byte3!=expected)==inequality. |
| 2 | Boolean(A.byteB98!=expected)==inequality. |
| 3 | 1B02D0()!=0 and1B0340(A)==0. |
| 4 | 1B0340(A)!=0. |
| Other | Unconditional, as the default branches enter operation selection. |

5C3FE0 operation P44=0 calls5703E0(ID,1), ID=P40&1FF. Operation1: if1B02D0()==1 calls5705F0(ID,1,A.byte3); else requires1B0340(A)!=0 before5705F0(ID,1,0). Operation2 performs primary flag write then, when P.half58!=FFFF and1B0340(A)!=0,570120(event,3C,4). Operation3 performs the operation1 flag policy, then independently applies that same optional event gate; a skipped flag write does not suppress an eligible event. Other operations do nothing.

5C4230 flag bankP64=0 ->5703E0(ID,1); bank1 ->5705F0(ID,1,A.byte3 if1B02D0()==1 else0); other banks skip flag only. Operations:

| P4C | Effects after outer policy admission |
| --- | --- |
| 0 | Performs selected flag write first. Only1B0340(A)!=0 then calls5B45E0(A,P.half48),5F4FD0(), and if signed P.word68!=-1 requests570100(low16 P68,14,28,3). Item consumption helper can fail independently; flag publication already occurred. |
| 1 | Requires5F2210(A,P.half48)!=0, then flag write. No consumption. |
| 2 | Requires both5F2210(A,P.half48) and5F2210(A,P.half54) nonzero, then flag write. |
| 3 | Performs flag write, then5B47F0(A,P.half48) regardless1B0340. Only if1B0340!=0 calls5F4FD0 and the optional P68 event. |
| Other | No operation. |

Inventory contracts are independently reviewed in [consumption and queries](SYMBOLS_INVENTORY_CONSUMPTION_QUERIES.md) and [inventory recipes](SYMBOLS_INVENTORY_USE_RECIPES.md). The callback never treats5F2210 as a quantity test; it is a resource-ID lookup. It also does not test the result of consumption/destruction before later work.

5C4600 chooses actor task-owner index=A.byte3 only when1B02D0()==1, otherwise0; task state publication uses strideAA0 at3B6DB0/3B6DB4. Selected-player category for optional event override is byte4A67C8+10E0*byte4BADED, not necessarily the passed actor category. Let H=P.half52:

| H condition | Work / selected event |
| --- | --- |
| FFFF | Keep base half50, proceed to category/counter work. |
| bit8000 set | Test570A10(H&3FFF); nonzero selects alternative half54; zero calls5709E0(H&3FFF) then proceeds with base. bit4000 is not separately considered on this branch. |
| bit8000 clear, bit4000 set | Requires byte4B9D19<8; requests5B92B0(8,8,word70A1A0,A3), publishes H&3FFF and P pointer at owner task-state words; returns early. |
| Both bits clear | If5709B0(H)!=0 selects alternative half54; else requests5B92B0(8,7,word70A19C,A3), publishes H and selected event, calls570970(H), returns early. |

If P.byte59!=0 it must contain bit selectedCategory, then event becomes P.half(5A+2*selectedCategory); otherwise stop. Optional flag block: P.word74!=-1 and signed P.half6C>=signed P.half6A. Mode74=0 calls5703E0(P70,1); mode1 calls5705F0(P70,1,A3 if1B02D0()==1 else0). Other modes skip flag. If signed half6A!=0, adds the old unsigned half6C to event (low16), then increments signed counter if less than limit or clamps it to limit otherwise. Calls570120(event,3C,2) if H!=FFFF, else570120(event,3C,4). If P.byte58!=FF also5BF0F0(P58,P.half56); if P.byte6E!=0 clears P3C. These are local per-callback counters; no duration/frame-time meaning is asserted.

5C4940 common setup extracts scene matrix49FA10+40*P60 translation B and yaw basisP48. Let mode=P.word4C, special=(A.byte54F==1A). P4C==3 exits before setup. It admits only actor classes0/1.

| Actor / path | Classification and publication |
| --- | --- |
| Class0 special, mode4 | If1B0340(A)!=0 publish byte4BAE07=4,4BAE05=low8(P5C|80),half3243E0=3243DA,3243E2=P58. In either case AB9=F,ABA=1,AB8=1, early exit; no ABC/AC8/ABB writes. |
| Class0 special, mode5 | Same room publication except4BAE05=P5C; then AB9=10,ABA=1,AB8=1 and early exit. |
| Class0 special, mode2/6 | No state publication. |
| Class0 special, other | AB9=E,ABC=B then override ABC.Y=float(signed P20), common publication below. |
| Class1 special, mode4/5 | AB9=F/10 andAB8=1, early exit; no room globals or ABA. |
| Class1 special, mode2 | No state publication. |
| Class1 special, other | AB9=E,ABC=B with Y=float(signed P20), common publication. This includes mode6, unlike class0. |
| Either class nonspecial, mode4 | No state publication. |
| Class0 nonspecial | Rotate fixed XYZ70B238 for mode2,70B250 for mode6, otherwise70B220 by P48 basis; target=B+rotatedOffset. Normalize rotatedOffset; compare dot with forward70A760 rotated by A.half92. Only ordered dot<=0 publishes targetABC, AB9=D for mode2,16 for mode6,otherwiseB; common publication. |
| Class1 nonspecial | Same mechanics, but only mode2 uses70B238; all other admitted modes including6 use70B220. AB9=D for mode2,otherwiseB. |

Common publication is AB8=1,AC8=P48,ABB=low8 P60. It does not write current actor XYZ or half92. Normalization has no local zero-vector guard; ordered dot<=0 rejects NaN, unlike the5C5A30 comparison in [contact callbacks](SYMBOLS_COLLISION_PROXY_CONTACT_CALLBACKS.md).

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. The following independent fixed float32 XYZ reads are exact consumed spans, not table size claims:

| Physical span | XYZ decimal | SHA256 |
| --- | --- | --- |
| 70A760..70A76B | (0.0, 0.0, 1.0) | `caccb9a8fbd2401135207066c4b53d6e88467839318ea2f1e8bfadf8fef6844e` |
| 70B220..70B22B | (0.0, 0.0, -40.0) | `f348fb462698e289f80b0110399693bc039e624e535484223dbccf7c4d2aae1c` |
| 70B238..70B243 | (0.0, 0.0, -50.0) | `04e202e7db390fc84b05ca6d6186e0caba4415badb2d163d6dcdf288dde77544` |
| 70B250..70B25B | (0.0, 0.0, -100.0) | `cedd1ea8bfce3fb5bc3ed993ea361473d202f99946bb133f44a3cebcdec4e928` |

[Linked query tables](SYMBOLS_LINKED_INTERACTION_PROXY_QUERIES.md) establish callback target ownership, not frequency or incident responsibility. All other callees retain independently documented contracts or numeric identities; no original actor-action enums, successful sound/task delivery, renderer bottleneck or controlled-fix result is claimed.

Owned-word audit:4 rows,762 distinct instruction words verified,108 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
