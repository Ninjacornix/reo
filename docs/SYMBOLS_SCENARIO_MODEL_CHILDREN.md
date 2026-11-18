# Scenario model-animation children and room gates

Static File #1 US research, 2026-11-04. This closes the direct model-animation
children of [scenario event tasks](SYMBOLS_SCENARIO_EVENT_TASKS.md). Each named
original body was reviewed in full, including signed comparisons, initial loop
admission and branch delay slots. No game, build, replay, attachment or live
memory inspection was performed. Offsets/addresses/IDs are hexadecimal; explicitly
decimal float values and counts retain that interpretation.

Mapped model slot6 identifies base64-byte pose at49FA10+40*slot. Child task30
contains a saved/working pose and task60..6C its translation row. Existing
5D8280/5D8300 manage the original slot binding;573740 frees a guest callback
task. This is not operating-system threading or native renderer optimization.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6040A0](../recomp/config/output_ovl/o2/o2_006040A0_0x6040a0.cpp) | `refresh_room_selection_and_four_actor_room_ids_candidate` | Probable role; full body reviewed | Calls5D7D60,651850 and5EB520 first. When signed global324200==0, selected actor3-byte entry4B9D01+3*4BADED nonzero becomes room half3243DC; writes per-actor room half1E2 for slots3..0 from corresponding table bytes. If selected byte zero copies existing3243DC into those four actors instead. Always sets room variant half3243DE from byte4B9D20+room. No upper checks or continuous polling. |
| [o2 0x6041B0](../recomp/config/output_ovl/o2/o2_006041B0_0x6041b0.cpp) | `advance_three_phase_control_gate_and_session_notification_candidate` | Probable role; full body reviewed | Runs only signed324200==0. Shared state signed byte4BAE7A:0 waits4BAE77 then increments and falls through phase1;1 calls1BC1D0(5),1AE3F0(0,0,A)/(1,0,A), increments phase and timer4BAE7B=50. Phase2 decrements signed timer; when<=0 sets4BAE76=1. If main1B0310 true sends six-byte1AFDD0(6,{4,6,0,0,selected,0},0); otherwise ORs selected bit into4BAE86. It does not reset phase2 on completion; broader lifecycle unresolved. |
| [o2 0x604340](../recomp/config/output_ovl/o2/o2_00604340_0x604340.cpp) | `animate_z_translation_child_through_three_parent_acknowledgements_candidate` | Probable role; full body reviewed | Task phase unsigned byte8. Init0->1,halfC/E=0, copies64-byte pose49FA10+40*slot6 totask30 and binds5D8280. Phases1/3 run keyframe interpolation through pointer table70E270[uncheckedbyte4]; each substep increments signed halfC, advances knot E at next-time boundary, negative next sentinel increments phase8 and optional parent28 byte89 (parent work29). Writes translationXYZW task60..6C with Z=baseZ+interpolated scalar, other axes unchanged. Substeps pretested against unsigned clockmode3243CC+1. Phase2 signed lifetime12 decrements;<=0 acknowledges parent again, enters3, clears C/E and adds2 to selector4. Phase4 releases mapped slot5D8300 and task573740. Phase changes inside interpolation do not locally break the remaining substep loop. |
| [o2 0x6045C0](../recomp/config/output_ovl/o2/o2_006045C0_0x6045c0.cpp) | `animate_x_rotation_child_with_terminal_ack_flag_candidate` | Probable role; full body reviewed | Phases0/1/2 atbyte8. Init binds slot6 pose, clears C/E and forces selector4=3 (idle). Phase1 repeats clockmode+1 substeps; selector4<3 selects70E390[selector], interpolates signed-time float knots. Sentinel: selector1 entersphase2 and audio18; others resetphase0/selector3. Both clear byteB on completion. Scalar191EF0 -> unsigned angle,370320 X rotation, identity18FDF0 then191380 combines with base pose; restores base translation. Phase2 releases slot, copies saved task30 pose back to base, frees task. Caller5A1060 controls selector/B and parent countdown; no parent29 increment in this child. |
| [o2 0x604890](../recomp/config/output_ovl/o2/o2_00604890_0x604890.cpp) | `repeat_entity_audio5_until_linked_target_inactive_or_terminal_state_candidate` | Probable role; full body reviewed | Init clears C/E and selector4=0, searches active list3B59F0 via1C for BB4==signed half70E3A0 (owned121), then stores target24/entersphase1; no match remainsphase0 for future scans. Phase1 inactive target or signed targetFCF4/7 entersphase2. Otherwise signedhalfC decrements; negative resets78 and1B8B70(target,5). Phase2 frees task. Does not locally validate saved target identity after reuse. |
| [o2 0x6049B0](../recomp/config/output_ovl/o2/o2_006049B0_0x6049b0.cpp) | `emit_random_position_audio_below_height_threshold_candidate` | Probable role; full body reviewed | Init searches active list3B5854 via1C, target type byte30 must match unsignedhalf70E3A8+2*selector4 (owned16/17). No target entersphase2; match stores24,clearsC,entersphase1 in same call. Computes1900E0(target1F0)+targetXYZ38; if halfC==0 and resultingY<-199.0, random bit selects audio2E/2F at position and setsC=1E. NonzeroC decrements. Phase2 frees; target-active state is not retested in phase1. |
| [o2 0x604B30](../recomp/config/output_ovl/o2/o2_00604B30_0x604b30.cpp) | `animate_z_rotation_child_on_parent_halfword_signal_candidate` | Probable role; full body reviewed | Init binds slot6 pose, clears C/E,phase8=1. Activephase1 requires signed half10==1; pointer70E418[uncheckedselector4], scalar linear knots,clockmode+1 substeps. Sentinel clears half10 and phase8=0; otherwise advances knot on next-time.191EF0 produces low16 angle used as Z rotation370320(0,angle,0), combined with base pose; restores translation. Phase2 releases slot, copies task30 pose back to base and frees. Parent5A3310 signals half10; completion does not decrement parent byte6 here. |
| [o2 0x604DC0](../recomp/config/output_ovl/o2/o2_00604DC0_0x604dc0.cpp) | `animate_x_rotation_child_and_clear_two_parent_signal_halfwords_candidate` | Probable role; full body reviewed | Independently reviewed shape similar604B30, but pointer table70E450[selector4] (owned index0->70E420,index1=0), X rotation370320(angle,0,0). Init binds pose. Phase1 requires half10==1 and runs clockmode+1 interpolation; terminal sentinel clears half10 AND half12 plus phase8=0. Phase2 releases/copies saved pose back/frees. Parent5A13D0 initializes selector4=0 and signals10/12; no assertion other selector values are admitted. |
| [o2 0x605050](../recomp/config/output_ovl/o2/o2_00605050_0x605050.cpp) | `sequence_position_audio73_74_around_local_flag2_candidate` | Probable role; full body reviewed | Copies XYZ from70E458 tostack. Phase0 if4B9C00 bit2clear emits73 and incrementsphase8, then falls into flag2check. Existing bit2 or phase1 with bit2 emits74 and frees task; clearbit inphase1 waits. Other phasesreturn. No model or timer writes. |
| [o2 0x605100](../recomp/config/output_ovl/o2/o2_00605100_0x605100.cpp) | `animate_z_rotation_child_using_split_curve_and_time_tables_candidate` | Probable role; full body reviewed | Init binds slot6 pose/clearsC/E/phase1. Phase1 signal half10==1 runsclockmode+1 interpolation. Values and denominator endpoints use *70E4E8 (70E470), but boundary/sentinel checks use *70E4EC (70E4B0) at same knot index. Literal split-table mechanics retained, without asserting the curves are equivalent. Terminal clears half10 and phase8=0. Converts scalar with191EF0, applies Z rotation, restores translation. Phase2 releases slot/copies saved pose back/frees. Parent5A4110 supplies half10 signals. |
| [o2 0x605380](../recomp/config/output_ovl/o2/o2_00605380_0x605380.cpp) | `animate_y_translation_child_and_set_selector_scenario_flag_candidate` | Probable role; full body reviewed | Init binds pose/clearsC/E/phase1. Phase1 requires signedhalf10==1, repeatsclockmode+1 steps through pointer*70E570 (70E4F0), interpolation changes onlyY=baseY-scalar. Terminal incrementsphase8 to2, sets scenario flag unsignedbyte4 through5703E0(id,1), audio82; no local break from remaining substeps. Phase2 releases slot,copies saved pose back to base,frees. Parent5A4380 may put flag7D/7F inchild4; selector here is flagID, not curve index. |

## Owned keyframe records

Each8-byte knot is `(float scalar, signed time)`, ending in `(0,-1)`. Linear
interpolation uses old signed halfwordC for the value, then incrementsC before
testing the next key boundary. It does not clamp the initial value to the first
key time. These are original update counters; no wall-time assumption.

| Pointer table | Selector / curve address | Owned endpoint and timing evidence |
| --- | --- | --- |
| 70E270 | 0->70E070 |13 nonterminal knots: scalar0 at time5 through-50 at90; sentinel next. |
| 70E270 | 1->70E0E0 |15 knots:0 at0 through-100 at90. |
| 70E270 | 2->70E160 |15 knots:-50 at5 through0 at90. |
| 70E270 | 3->70E1E0 |16 knots:-100 at0 through0 at90. |
| 70E390 | 0->70E280 |6 knots, times0/1/2/5/6/8, scalar returns0. |
| 70E390 | 1->70E2C0 |15 knots, time0..35, final scalar1.570796 (approximatelypi/2). |
| 70E390 | 2->70E340 |9 knots, times0/8/15/23/30/38/45/52/60, final0. |
| 70E418 | 0->70E3B0 |5 knots, times0/5/8/11/15, final0. |
| 70E418 | 1->70E3E0 |6 knots, times0/4/6/9/11/15, final0. |
| 70E450 | 0->70E420 |5 knots, times0/1/2/3/6, final0. Adjacent word+4 is0; caller initializes selector0. |
| 70E4E8 | * ->70E470 |6 knots, times0/1/4/6/8/15, final0. Used for scalar endpoints by605100. |
| 70E4EC | * ->70E4B0 |6 knots, times0/2/5/6/9/15, final0. Used for boundary/sentinel by605100. |
| 70E570 | * ->70E4F0 |15 knots, times0/2/4/6/8/10/12/13/14/16/18/19/20/22/23, scalar0..300. |

The shape/table differences are observed mechanics, not defects proven by
controlled retesting. Exact expected update order, model identity and allocator
initialization remain external contracts. No callback count is presented as a
measured slowdown or bottleneck.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Instruction words verified against owned file-backed o2, virtual base570000.
