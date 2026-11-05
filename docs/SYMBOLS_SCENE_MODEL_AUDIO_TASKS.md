# Scene model sound tasks and bound horizontal curve

Static File #1 US research, 2026-11-04. Eleven complete original bodies
reviewed. Addresses and offsets are hex unless marked decimal. Sound requests
are inferred from previously mapped main sound adapters, not observed playback.
No target execution, build, replay, attachment or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6D54C0](../recomp/config/output_ovl/o2/o2_006D54C0_0x6d54c0.cpp) | `task_request_model_yaw_threshold_sound_with_cooldown_candidate` | High mechanics; probable role | State0 scans linked3B5854 through1C for first signed-active byte0 and unsigned type30 matching half731C68[byte4]; found pointer24,clears C/E,enters1; missing enters2. State1 reads signed model yaw92. E0 triggers yaw>signed731C70[2*variant]; E!=0 triggers yaw<signed731C70[6*variant], preserving distinct indexing. Trigger computes1900E0(matrix1F0)+modelXYZ38, requests1B8930(position,40), sets C=decimal10, toggles Ebit1,enters2. State2 decrements C while nonzero; initial0 enters1 without request. State3 deletes573740; other states return. Missing-model state2 does not delete immediately and this body does not independently revalidate pointer24. |
| [o2 0x6D5690](../recomp/config/output_ovl/o2/o2_006D5690_0x6d5690.cpp) | `task_request_fixed_scene_sound_2e_or_2f_periodically_candidate` | High mechanics; probable role | Copies owned731C80 XYZ to stack. State0 clears C and enters1 in same call. State1 C==0 consumes random-low1, requests1B8930(position,2E if1 else2F), seeds signed C=decimal30; nonzero C decrements. State2 deletes; other states return. No factor scaling or model lookup. |
| [o2 0x6D5770](../recomp/config/output_ovl/o2/o2_006D5770_0x6d5770.cpp) | `task_request_model_type10_sound_when_parameter_nonpositive_candidate` | High mechanics; probable role | State0 finds first active linked model type30==10, caches24,C=8,enters1; missing enters2. State1 computes matrix1F0 translation plus modelXYZ each call. Nonzero C decrements; at0, model float214<=0 requests positional sound44 and sets C=decimal20. State2 deletes. No threshold crossing memory or factor normalization. |
| [o2 0x6D58B0](../recomp/config/output_ovl/o2/o2_006D58B0_0x6d58b0.cpp) | `task_request_variant_model_sound_below_parameter_epsilon_candidate` | High mechanics; probable role | Copies owned731C90 four typehalfwords. State0 special3243DA==23 and3243DC==11 changes variant1 to2; scans active linked models for selected type30, caches24,C=8,enters1,missing->2. State1 computes matrix1F0 translation+modelXYZ. Nonzero C decrements; at0, either model218 or21C<=owned7410A8 (~0.00001) permits random-low1 sound39/3A and C=4. Both greater/NaN comparisons preserve ordered branches. State2 deletes; no one-shot gate. |
| [o2 0x6D5A60](../recomp/config/output_ovl/o2/o2_006D5A60_0x6d5a60.cpp) | `task_request_flag_variant_scene_sounds_then_delete_candidate` | High mechanics; probable role | Copies two owned731CA0 XYZs to stack. Global4B9C00bit40000 requests nonpositional1B8930(null,49); otherwise variant1 calls1B9810(47,0,0,firstXYZ). Independently variant2 plus4B9C40bit80000 calls1B9810(68,0,0,secondXYZ). Always573740(task). The1B9810 role beyond this numeric adapter contract remains unresolved. |
| [o2 0x6D5B30](../recomp/config/output_ovl/o2/o2_006D5B30_0x6d5b30.cpp) | `task_request_fixed_position_bank_one_sound_eight_then_delete_candidate` | High mechanics; probable role | Copies731CB8 XYZ, calls previously mapped1B9360(position,8), then573740(task). No loop or condition. |
| [o2 0x6D5B80](../recomp/config/output_ovl/o2/o2_006D5B80_0x6d5b80.cpp) | `task_call_variant_scene_sound_adapter_then_delete_candidate` | High mechanics; probable role | Copies two XYZs731CD0 and two words731CE8 to stack. Unsigned byte4 selects eventword and12-byte XYZ; calls1B9810(event,0,0,selectedXYZ), then573740. Owned eventwords45/78. No variant bounds guard in original body; adapter semantics not promoted beyond evidence. |
| [o2 0x6D5C10](../recomp/config/output_ovl/o2/o2_006D5C10_0x6d5c10.cpp) | `task_wait_flag100000_then_call_sound_adapter_and_delete_candidate` | High mechanics; probable role | Waits4B9C00 mask100000. Once nonzero calls1B8A10(0,20),then573740(task). Other calls return without state write.1B8A10 effect remains numeric contract here. |
| [o2 0x6D5C60](../recomp/config/output_ovl/o2/o2_006D5C60_0x6d5c60.cpp) | `task_request_variant_model_height_or_parameter_sound_candidate` | High mechanics; probable role | State0 finds active linked model type731D10[variant],caches24,C0,enters1; missing2. State1 computes matrix1F0 translation+modelXYZ. Nonzero C decrements. At0 and variant!=0, worldY<decimal-799 requests random2E/2F, C=30. Variant0 instead requires model21C strictly between owned7410B0(~-0.6) and-0.5, then random2E/2F,C=10. State2 deletes. Conditions are level tests, not retained crossing events. |
| [o2 0x6D5E50](../recomp/config/output_ovl/o2/o2_006D5E50_0x6d5e50.cpp) | `task_request_second_fixed_scene_sound_2e_or_2f_periodically_candidate` | High mechanics; probable role | Independently reviewed full body: same state0 clear/enter1, state1 random2E/2F with decimal30 countdown, state2 delete as5690; its owned XYZ source is731D18. The two vectors happen to match in owned bytes, but this entry retains a distinct table reference/caller identity. |
| [o2 0x6D5F30](../recomp/config/output_ovl/o2/o2_006D5F30_0x6d5f30.cpp) | `task_bind_scene_matrix_run_two_horizontal_curves_and_notify_parent_candidate` | High mechanics; probable role | Scene matrix slot=49EEF0+B20+40*byte6. State0 copies64 bytes to task30,clears C/E,enters1,binds5D8280(slot,task30),requests1B8930(slotTranslation,19). States1/3 perform3243CC+1 interpolation substeps using owned731E20[variant] eight-byte(value,time) keys; signed C increments, E advances at next time, negative following time increments state and optional parent28->byte7D. Transforms local(value,0,0) by copied task30 basis, writes only task matrix translationX60/Z68 from original slot translation plus result; Y64 remains copied. State2 predecrements timer12; expiry notifies parent,requests sound1A,enters3,clears C/E,increments variant. Other states clear matching task pointer from parent's74/78 slots,5D8300(slot),573740(task). Even terminal-key substeps still perform current transform; no new early loop exit. |

Owned data values below are decimal; no live model memory was inspected:

| Address | Contents |
| --- | --- |
| 731C68 | typehalfwords6,7,8,0 |
| 731C70 | signed halves10752,3328,10752,-7168,-10752,-7168,0,0 |
| 731C80 /731D18 | XYZ5527,-2308,4024 |
| 731C90 | typehalfwords3,4,7,8 |
| 731CA0 | XYZ4367,-877,2480;2634,-962,775 |
| 731CB8 | XYZ2710,-2890,2030 |
| 731CD0 | XYZ5893,-3238,9128;4922,-3445,9125 |
| 731CE8 | eventwords69,120 |
| 731D10 | typehalfwords7,23,29,0 |
| 731E20 | pointers731D30,731DA0 only; following words are unrelated float data |

Both owned curves were decoded through(value0,time-1) sentinels:731D30 has
13 real keys, from(value0,time5) through(-50,90);731DA0 has15, from(-50,5)
through(-0,90). Exact intermediate floats were checked in the owned blob.
Interpolation increments C before comparing next time but uses the preincrement
C in its fraction. State2 timer12 is supplied externally, not initialized here.
The substep count follows3243CC+1, not the presentation frame rate or global
game-clock observer callbacks.

Related [bound model curves](SYMBOLS_BOUND_MODEL_CURVE_TASKS.md),
[scenario sound adapter](SYMBOLS_SCENARIO_SOUND_REMAP.md), and
[target-cache rebuild](SYMBOLS_TARGET_CACHE_REBUILD.md).
