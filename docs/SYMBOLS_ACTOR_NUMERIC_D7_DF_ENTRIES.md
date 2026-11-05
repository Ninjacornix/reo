# Actor numeric D7..DF transition entries and CDD metric helpers

Static File #1 US research, 2026-11-04. Eleven complete original bodies reviewed. Hexadecimal addresses/fields/action codes; constants explicitly labeled decimal when used as physical counts. Proposed state names retain numeric action IDs. Local mechanics confidence high; gameplay roles probable. No game execution, attachment, build or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x57E7E0](../recomp/config/output_ovl/o2/o2_0057E7E0_0x57e7e0.cpp) | `enter_actor_action_one_d7_and_initialize_cdd_timer_candidate` | High mechanics; role probable | ActorCDD=7F;6606D0(actor,1);signed halfC=3C;action8=1,substate9=D7,phasesA/B=0;667370 saves transform. No original action-name or wall-time claim. |
| [o2 0x57E840](../recomp/config/output_ovl/o2/o2_0057E840_0x57e840.cpp) | `enter_actor_action_one_d9_and_save_transform` | High mechanics; role probable | action8=1,substate9=D9,phasesA/B=0,tail667370 preserving actor argument. No animation request. |
| [o2 0x57E860](../recomp/config/output_ovl/o2/o2_0057E860_0x57e860.cpp) | `enter_actor_action_one_da_save_and_serialize_candidate` | High mechanics; role probable | action1/substateDA/phasesA/B0;667370 then67E230(actor,3). Serialization/authority gates remain in independent callee; not guaranteed delivery. |
| [o2 0x57E8B0](../recomp/config/output_ovl/o2/o2_0057E8B0_0x57e8b0.cpp) | `enter_actor_action_one_db_and_save_transform` | High mechanics; role probable | action1/substateDB/phasesA/B0,tail667370. No additional animation or message call. |
| [o2 0x57E8D0](../recomp/config/output_ovl/o2/o2_0057E8D0_0x57e8d0.cpp) | `enter_actor_action_one_dc_save_and_serialize_candidate` | High mechanics; role probable | action1/substateDC/phasesA/B0;667370 then67E230(actor,3). |
| [o2 0x57E920](../recomp/config/output_ovl/o2/o2_0057E920_0x57e920.cpp) | `enter_actor_action_one_df_save_and_serialize_candidate` | High mechanics; role probable | action1/substateDF/phasesA/B0;667370 then67E230(actor,3). |
| [o2 0x57E970](../recomp/config/output_ovl/o2/o2_0057E970_0x57e970.cpp) | `tick_actor_cdd_metric_and_enter_d8_when_metric_changes_candidate` | High mechanics; role probable | Save unsignedCDD. Signed halfC!=0 decrements; at exact0 call665CA0(actor,6),reload3C.662A60 mutatesCDD, signed low8 return compared with original unsignedCDD. Difference ->action1/substateD8/phases0,save transform. Always returns0. InputCDD high bit can force inequality even when low7 metric unchanged. |
| [o2 0x57EA00](../recomp/config/output_ovl/o2/o2_0057EA00_0x57ea00.cpp) | `tick_actor_cdd_metric_and_enter_d9_after_track_flag40_candidate` | High mechanics; role probable | Same C timer trigger as57E970.662A60 signed low8<=0 and actor1F1 bit40 ->5705F0(F,0,actor3),action1/substateD9/phases0,save transform. Positive result or missing bit leaves action. Always0. |
| [o2 0x6606D0](../recomp/config/output_ovl/o2/o2_006606D0_0x6606d0.cpp) | `set_actor_ba0_state_bit_and_initialize_mode_two_random_counters_candidate` | High mechanics; role probable | a1 mode1 ORsBA0 bit1 only. Mode2 whenBA0 bit2 absent sets it, initializes C58 and randomizedC5A,5DF790(actor),67E230(actor,E). Existing bit2 or other mode no work. Exact original-clock mode constants below; no generic timer interpretation. |
| [o2 0x662A60](../recomp/config/output_ovl/o2/o2_00662A60_0x662a60.cpp) | `reduce_actor_cdd_low_seven_bit_metric_preserving_high_bit_candidate` | High mechanics; role probable | Calls662890(actor),reads currentCDD. multiplier1 when high80 clear else2;delta=signed8(signed8 6629C0(actor,CDD&7F)*multiplier);remaining=signed8(low7-delta),clamp<=0 to0. Preserve latest high80 on CDD store;return low7. Helpers can mutate actor; this is not a read-only status query. |
| [o2 0x665CA0](../recomp/config/output_ovl/o2/o2_00665CA0_0x665ca0.cpp) | `request_authority_actor_controller_vibration_pattern_from_selector_or_resource_candidate` | High mechanics; role probable | Requires1B0340(actor)!=0 andlow8 selector3..8. Owned6-entry7403F0 routes pattern selection andcalls main1BA9F0; exactcases below. Resident port-zero vibration request is now independently mapped in [controller vibration patterns](SYMBOLS_CONTROLLER_VIBRATION_PATTERNS.md); saved-option/connection gates can suppress output. |

6606D0 mode2 tests BA0 bit2 first, so repeated calls while set do not rerandomize. If byte3243CC nonzero:halfC58=1E,baseC5A=4B0,range=1194-4B0. If zero:halfC58=3C,baseC5A=960,range=2328-960. Calls1AEC80(1),uses low16 result modulo low16 range,adds base andstores halfC5A. All ranges are hexadecimal original constants; no actual seconds, wall time or change in game speed is inferred.5DF790 and serialized selectorE are additional side effects, not optional pure observations.

662A60 first calls662890 before reading CDD, and later6629C0 before preserving the high flag from a fresh CDD read. Arithmetic narrows both delta product and remaining difference to signed8 before<=0 clamp. Thus this is not mathematically identical to a host max(0,low7-fullWidthDelta).57E970 compares the low7 return to the **original full unsignedCDD**, so original high80 can affect action transition even if reduced magnitude equals original low7.

665CA0 selector cases, after authority gate:

| Low8 selector | Event passed to main1BA9F0 |
| --- | --- |
| 3 | Signed actor word138<C9 ->1;else<2BC ->2;else3. |
| 4 |4. |
| 5 | ResourceID=low16 5F1F70(actor);kind=byte719A68+44*ResourceID. kind0 ->no call;else event=byte712BA8[kind]. No ID/kind bounds check. |
| 6 |1. |
| 7 |2. |
| 8 |3. |

No event-output semantics are assigned to main1BA9F0 without its own body. Owned7403F0..740407 six jump words665CEC,665D24,665D34,665D80,665D90,665DA0; SHA256 `7dca7b9d349e73e2d26f9c0e75a9ef789f341e1c5e7cd7bdbc027997e41b609e`. Owned byte prefix712BA8..712BAF=6,6,6,7,6,7,8,6; SHA256 `a9704c8f00a6dd10e75e9712a8bba1949e43f5111e5b69cd6b4e989da2c99b85`. This eight-byte prefix does not establish complete authored kind range. All spans from owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Three adjacent entries57EAA0/57EAB0/57EAC0 are exactly JR ra with return0 in the delay slot; their8 bytes match previously reviewed5733B0. Kept as plain cross-references without adding aliases as semantic work. [Dispatch contracts](SYMBOLS_DISPATCH.md) define save transform667370, consumed reset6673C0 and serialized selector67E230; none are animation evaluation. [Animation phase handlers](SYMBOLS_ACTOR_NUMERIC_D9_DF_MOTION_PHASES.md) document the connected larger bodies separately. No slowdown mechanism or valid CDD input distribution is established.

Owned-word audit:11 rows,332 distinct instruction words verified,12 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
