# Resource effects, type3200 lifecycle and auxiliary resource lists

Static File #1 US research, 2026-11-04. This continues
[consumption and queries](SYMBOLS_INVENTORY_CONSUMPTION_QUERIES.md) and
[recipe application](SYMBOLS_INVENTORY_USE_RECIPES.md). Original identities are
recorded in [the central index](FUNCTION_INDEX.md). No game, build, replay,
attachment, live-memory inspection or implementation change was performed.

Resource IDs index sixty-byte records at3C5630. Actor signed halfwords544/546
behave as current/maximum health in this family, but template effect flags,
status-bit names and original resource taxonomy remain candidates. Numeric
content IDs are preserved rather than assigned guessed item names.

## Applying owned resource effects

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5B2080](../recomp/config/output_ovl/o2/o2_005B2080_0x5b2080.cpp) | `apply_owned_resource_effect_by_exact_template_mask_candidate` | Probable role; full body reviewed | Low8 a0 ID must active, quantity>0 and owner nonzero; a1 actor/context passed onward. Exact(template flags&4C)==4 dispatches5B2230,==8 dispatches5B26D0,==40 dispatches5B2760; combined masks are not accepted by these equality cases. Signed-byte helper result nonzero with positive quantity reports success1, decrements one only for helper result1, records local37BBC0(content), and if depleted/template flag40000 destroys through5B1AF0 and reports2. Helper result3 overrides final result to3;4 overrides to2. Does not remove actor inventory references or compact them here. |
| [o2 0x5B2230](../recomp/config/output_ovl/o2/o2_005B2230_0x5b2230.cpp) | `apply_resource_health_status_effects_and_local_followups_candidate` | Probable role; full body reviewed | a0 record,a1 actor; null actor or BA0&1E0 returns0. Template unsigned byteA controls effects detailed below. Any admitted effect returns1 and calls5B6610(record,effectMask,actor). Health update adds signed table709C68[content], or12C under BA0 bit8, with halfword arithmetic and cap at signed maximum546. Template effect10/20 admit only when corresponding actor BA0 bit1/2 set; accumulated status response calls6605B0. Special content138 first sets BA4 bit1000 once, reports success, and for local actor calls5F4FD0,665CA0(actor,6), then main text/UI helpers1C1CE0/1B4820 with IDs20/21. No quantity decrement inside. |
| [o2 0x5B2590](../recomp/config/output_ovl/o2/o2_005B2590_0x5b2590.cpp) | `update_resource_quantity_cost_and_classify_use_result_candidate` | Probable role; mechanics verified | a0 record,a1 actor without local null/activity/ownership checks. Mode1B02D0==1 and global4BAE96 bit1 returns2 unchanged. Otherwise template flag02000000 subtracts quantity6 for actor B98=1,2 for4,4 for others, flooring result to1. Quantity<2 plus flag80000 sets0, calls5B4AD0(selfID,actor), and returns3 even if replacement fails. Otherwise template flag01000000 or mask00700000 returns1; remaining cases2. Not the effect dispatcher5B2080 and no direct destruction. |
| [o2 0x5B26D0](../recomp/config/output_ovl/o2/o2_005B26D0_0x5b26d0.cpp) | `deploy_owned_type3201_when_live_type3200_count_below_eleven_candidate` | Probable role; mechanics verified | a0 record must content3201. Signed-byte5B5AF0 count must<B, otherwise0. Calls5B5940(selfID,actor byte3,3,actor XYZ38), then5B5CB0(actor,selfID,actor XYZ38), returns4. No actor null guard, local positive-quantity admission or check that deployment/model creation succeeded. |
| [o2 0x5B2760](../recomp/config/output_ovl/o2/o2_005B2760_0x5b2760.cpp) | `resource_effect_mask40_returns_zero` | Confirmed/static mechanics | Returns0 with no memory write or argument use. Original API role unknown; not a generic successful action. |
| [o2 0x5B2770](../recomp/config/output_ovl/o2/o2_005B2770_0x5b2770.cpp) | `test_owned_resource_use_by_template_flag_priority_candidate` | Probable role; mechanics verified | Active low8 ID, positive quantity and owner nonzero required. Template flag priority4->5B2870,otherwise1->5B2880,otherwise8->5B2890,otherwise40->5B28E0. Returns signed-byte helper result, default0. Unlike5B2080, individual-bit priority accepts several combined masks and this routine performs no effects or decrement. |
| [o2 0x5B2870](../recomp/config/output_ovl/o2/o2_005B2870_0x5b2870.cpp) | `resource_use_flag4_admission_returns_one` | Confirmed/static mechanics | Returns1, no argument or memory use; separate original entry from adjacent flag1/40 stubs. |
| [o2 0x5B2880](../recomp/config/output_ovl/o2/o2_005B2880_0x5b2880.cpp) | `resource_use_flag1_admission_returns_one` | Confirmed/static mechanics | Returns1 with no additional resource or actor validation. Wrapper owns admission. |
| [o2 0x5B2890](../recomp/config/output_ovl/o2/o2_005B2890_0x5b2890.cpp) | `test_type3201_deployment_count_admission_candidate` | Confirmed/static mechanics | Record content other than3201 returns1. Content3201 returns1 only when signed-byte5B5AF0 result<B, else0. No allocation or quantity mutation. |
| [o2 0x5B28E0](../recomp/config/output_ovl/o2/o2_005B28E0_0x5b28e0.cpp) | `resource_use_flag40_admission_returns_one` | Confirmed/static mechanics | Returns1 only; separate from5B2760's effect-path return0. This distinction is preserved. |
| [o2 0x6605B0](../recomp/config/output_ovl/o2/o2_006605B0_0x6605b0.cpp) | `apply_actor_health_status_clear_selector_and_notify_candidate` | Probable role; body and jump table reviewed | Low8 a1 selector0..9 jumps through owned740340.1 restores544=546;2 clears BA0 bit1;3 clears bit2;4 restores and clears both;5 clears both;6 restores and clears bit1;7 restores and clears bit2;9 restores and clears both.0/8 and out-of-range do no listed mutation. Every path tailcalls67E230(actor,E), including selectors with no mutation. No null/activity guard. |
| [o2 0x5B6610](../recomp/config/output_ovl/o2/o2_005B6610_0x5b6610.cpp) | `record_local_owner_resource_effect_event_candidate` | Probable role; full body reviewed | a0 record,a1 effect mask,a2 target actor. Fixed owner-1 array actor must satisfy1B0340; no owner bounds admission inside. If owner-1 differs from target byte3, emits37C060(1F,target B98,0). Same-owner priority:mask8->event4;mask4->event3;mask2 plus content13C/13D->event2;otherwise mask3 nonzero->event1. Event argument1 is resource content, argument2=0. No rendering or audio call inferred from this cooperative-event API. |

| Template effect byteA | Mutation / admission | Effect mask passed to5B6610 |
| --- | --- | --- |
| 01 | Only current544<maximum546: add/cap health | 01 |
| 02/04/08 | If any E bits: priority02 sets BA4 bit20,04 sets bit8,08 sets bit10 | 02 |
| 10 | Only BA0 bit1 present: request status accumulator2 | 04 |
| 20 | Only BA0 bit2 present: request status accumulator4 | 08 |

The status accumulator in `0x5B2230` is initialized0 and only ORed with2/4.
Its reachable nonzero values2/4/6 select `0x6605B0` modes2/3/5, respectively.
The original body also contains dispatch branches for accumulator1/3/5/7/8/F;
these have been reviewed but are not claimed reachable through the local writes.
The mask passed to the event helper is a separate accumulator and can combine
the health, BA4 and status responses.

## Type3200/3201 deployment and linked-instance queries

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5B5AF0](../recomp/config/output_ovl/o2/o2_005B5AF0_0x5b5af0.cpp) | `count_active_type3200_instances_with_active_resource_records_candidate` | Confirmed/static mechanics | Walks linked head3B5710 through1C. Requires node signed bytes0/1 nonzero, unsigned content36==3200 and active resource indexed by node byte240. Counts each qualifying node, narrowing signed8 after every increment. No uniqueness, owner or room test. Count wrap can affect caller's signed<B test. |
| [o2 0x5B5B70](../recomp/config/output_ovl/o2/o2_005B5B70_0x5b5b70.cpp) | `find_nearest_live_type3200_resource_and_copy_position_candidate` | Probable role; mechanics verified | a0 XYZ,a1 output XYZ. Same linked-node/content/resource admission as5B5AF0. Ordered abs(Y-inputY)<100, then full XYZ distance191D10 strictly below current bound initially10000; nearest node wins, ties keep earlier. On match copies node200..208 to output and returns node byte240 resource ID. No match returns0 and leaves output untouched; matched ID0 is ambiguous. No owner or room filtering. |
| [o2 0x5B5CB0](../recomp/config/output_ovl/o2/o2_005B5CB0_0x5b5cb0.cpp) | `convert_type3201_to_unowned_type3200_at_position_candidate` | Probable role; full body reviewed | a0 actor,a1 low16 resource ID,a2 XYZ. Content must3201; no local activity or owner check. Directly replaces content3200, owner0, flags18 OR200000 and clear800; record byte1=low8 actor half1E2, XYZ copied with Y+2, angles14/16 and half4 cleared. If global room3243DC equals record byte1, creates591230(content,1); successful object receives XYZ200,flags23C,selfID240, is stored in record1C, then616F60(position,&object byte241,FF). Failed/off-room creation leaves prior pointer1C unchanged by this body; no initial release. |
| [o2 0x5B5DE0](../recomp/config/output_ovl/o2/o2_005B5DE0_0x5b5de0.cpp) | `remove_type3200_and_route_operation_four_candidate` | Confirmed/static mechanics | Calls5B5E20(low8 a0), then5B58C0(low8 ID,0,4) regardless whether content was3200 or removal happened. No positive-quantity or room admission. |
| [o2 0x5B5E20](../recomp/config/output_ovl/o2/o2_005B5E20_0x5b5e20.cpp) | `release_and_destroy_resource_when_content3200_candidate` | Confirmed/static mechanics | Reads content using low16 a0 ID without activity check. If3200, calls5B1850(low8 ID), then591BE0(low8 ID). No actor reference removal or compaction. Distinguishes16-bit lookup from8-bit cleanup arguments. |
| [o2 0x5B5E80](../recomp/config/output_ovl/o2/o2_005B5E80_0x5b5e80.cpp) | `find_unowned_flagged_resource_id_by_group_and_content_candidate` | Confirmed/static mechanics | a0 low8 group,a1 low16 unsigned content. Scans256 records; requires active,owner0,flags18 bit1,byte1 group and content6 match. First matching array index low8 returned, else0; index0/no-match ambiguous. Owner0 is redundantly retested near return; no positive-quantity check. |

## Routed resource-operation messages

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5B5940](../recomp/config/output_ovl/o2/o2_005B5940_0x5b5940.cpp) | `route_resource_operation_message_with_xyz_candidate` | Probable role; mechanics verified | a0 ID,a1 actor index,a2 operation,a3 XYZ. Requires mapped1B0310 submode predicate. Creates stack message bytes0/1=9/14,half4=ID,bytes6/7=actor/operation,XYZ8..13 copied from pointer; calls1AFDD0(5,message,0,4). Header bytes2..3 not initialized locally. No local resource mutation or proof of immediate socket delivery. |
| [o2 0x5B59E0](../recomp/config/output_ovl/o2/o2_005B59E0_0x5b59e0.cpp) | `dispatch_routed_resource_operation_to_actor_candidate` | Probable role; body and jump table reviewed | a0 resource ID,a1 actor index,a2 operation,a3 optional XYZ. Requires1B0310. Low8 actor index0..3 fixed array,>=4 resolves682F80(index-4); no dispatcher-level null check. Low8 operation0..5 via73E570:0->5B4550(actor,ID),1->5B46A0,2->5B4900,3->5B5CB0(actor,ID,XYZ),4->5B5E20(ID),5->5B4990(actor,ID). Unmatched operations do nothing. Resolution occurs even for operation4 which then ignores actor. |

The eight-byte operation sender was mapped separately at `0x5B58C0`. Here the
XYZ sender and the six-way consumer establish an operation contract; they do not
prove that every message sent is delivered or that every callee succeeds.

## Auxiliary per-actor resource lists

These are eight-byte lists at `0x4BAC52 + 8 * signedByteActorIndex`, separate
from the actor's C84/C88 inventory banks. Template byte15 groups records into four
categories for rebuilding in descending group order3,2,1,0. The bodies do not
check that template byte15 is below4 before indexing temporary stack arrays.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5B5F10](../recomp/config/output_ovl/o2/o2_005B5F10_0x5b5f10.cpp) | `append_eligible_owned_resources_and_regroup_auxiliary_list_candidate` | Probable role; full body reviewed | a0 signed low8 actor index,a1 input ID array,a2 signed full count. Groups existing8 nonzero active IDs by template byte15, retaining within-group order without owner checks. Then admits each nonzero active input unless template flag40 or owner!=(index+1); each group count must<8. Clears admitted record byte2A, appends without deduplication and counts signed8. If admitted count>0, clears destination8 bytes, writes grouped IDs up to total8, returns admitted count. Accepted inputs can exceed emitted capacity; side effects and return count include accepted entries later truncated. Existing-group fill has no independent count bound. |
| [o2 0x5B6180](../recomp/config/output_ovl/o2/o2_005B6180_0x5b6180.cpp) | `remove_resource_id_and_regroup_auxiliary_list_candidate` | Confirmed/static mechanics | a0 signed low8 actor index,a1 low8 ID. Scans existing8 entries, removes all matching nonzero IDs even if inactive, groups other active entries by template byte15. If match absent returns0 and does not rebuild, so inactive entries remain. If any removed, clears8 destination bytes then emits grouped IDs with code limitC, returns1. At most7 survivors arise from this local eight-entry input when a nonzero ID was removed; the larger emission limit is preserved as written. No resource destruction. |
| [o2 0x5B6300](../recomp/config/output_ovl/o2/o2_005B6300_0x5b6300.cpp) | `regroup_active_auxiliary_resource_list_and_return_count_candidate` | Confirmed/static mechanics | a0 signed low8 actor index. Groups8 existing nonzero active IDs by template byte15, clears8 destination bytes, writes groups3..0 with code limitC and returns emitted count signed8. Local valid-category input contains at most8 entries. No owner admission, duplicate removal, quantity test or destruction. |
| [o2 0x5B6450](../recomp/config/output_ovl/o2/o2_005B6450_0x5b6450.cpp) | `tick_room29_type3717_inventory_quantities_and_transform_at_zero_candidate` | Probable role; full body reviewed | Nonnull actor and global room3243DA==29 required. Scans four C84 and, for B98==6, all32 C88 slots. Nonzero IDs with content3717: negative quantities remain; nonnegative quantities decrement, so initial0 becomes-1 and does not transform. Exact post-decrement0 calls5B4990(actor,ID); nonzero signed-byte success emits5B58C0(ID,actor byte3,5), sets overall return1. Returns0 absent successful transformation, even if counters decremented. No activity check before content/quantity reads and no local deduplication across slots. |

The room29 counter is invoked from an actor auxiliary tick, not a measured
wall-clock timer. Its per-call decrement, duplicate references and original
clock-mode behavior must be preserved until a controlled runtime investigation
establishes a safe change.

## Verification and limits

All24 named entries were reviewed within their indexed ownership ranges.
Instruction-comment words were checked against owned file-backed o2 bytes; both
indirect selector tables were decoded from that blob. Candidate labels describe
static roles and do not claim original symbol recovery, timing measurements,
slowdown reproduction or a verified optimization.
