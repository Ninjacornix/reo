# Bound model-slot curve and parent-driven callback tasks

Static File #1 US research, 2026-11-04. Eight complete original bodies
reviewed. Addresses/offsets hex unless marked decimal. These are guest callback
records binding model-slot poses, not host threads. No execution, attachment,
build, replay or engine changes; no timing measurement or defect asserted.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6F96D0](../recomp/config/output_ovl/o2/o2_006F96D0_0x6f96d0.cpp) | `tick_bound_model_slot_horizontal_keyframe_task_and_parent_completion_candidate` | High mechanics; probable role | Task phase8=0 copies slot matrix49FA10+40*byte6 to30..6F,binds5D8280(slot,task30),C/E0,phase1,sound19 at slot translation. Phases1/3 perform original scalar keyframe interpolation from73C720[task4] for byte3243CC+1 substeps, using signed-byte loop counter. Rotates local (0,0,scalar) through saved30 matrix and adds original slot X/Z to task60/68. End sentinel increments phase and parent28->7D when nonnull. Phase2 predecrements12;expiry increments parent7D,sound1A,phase3,C/E0,task4++. Other phase assumes parent28, clears either parent74/78 equal to task,unbinds5D8300 and deletes573740. No host thread/task interpretation. |
| [o2 0x6F99E0](../recomp/config/output_ovl/o2/o2_006F99E0_0x6f99e0.cpp) | `tick_bound_model_slot_rounded_yaw_task_and_commit_pose_candidate` | High mechanics; probable role | Phase0 copies64-byte slot matrix,binds5D8280,sets80=-12,84=-10 decimal,phase1. Phase1 repeats byte3243CC+1 substeps:80+=84,371870 guest-rounds value, unsigned conversion/low16, then yaw=guestConvert(0.5+65536*value/360),370320 and191380 multiply original slot basis into task30 preserving W. Copies original translation/W into task60..6C. Phase2 unbinds, copies final task matrix back into slot, deletes; other phasesreturn. No sinusoidal/trigonometric oscillator assumption or host round substitution. |
| [o2 0x6F9C80](../recomp/config/output_ovl/o2/o2_006F9C80_0x6f9c80.cpp) | `tick_bound_model_slot_selected_vertical_curve_task_and_commit_candidate` | High mechanics; probable role | Phase0 matrix copy/bind,C/E0,phase1. Phase1 interpolates73C7A8[task4] scalar curve for3243CC+1 substeps, outputs original slotX/Z/W unchanged andY+scalar to task64; curve sentinel advances phase. Phase2 unbinds, copies final64-byte task pose into original slot anddeletes. Other phasesreturn. Curve admission for task4 remains caller contract. |
| [o2 0x6F9EB0](../recomp/config/output_ovl/o2/o2_006F9EB0_0x6f9eb0.cpp) | `tick_bound_model_slot_fixed_vertical_curve_with_audio_aa_candidate` | High mechanics; probable role | Same setup, interpolation/substeps, output and final commit lifecycle as9C80, but scalar curve pointer is fixed73C7F8 and setup calls1B8930(0,AA). Phase0C/E0;phase1 sentinel->2;phase2unbind/copy64/delete. Retains independent task body and audio side effect. |
| [o2 0x6FA0E0](../recomp/config/output_ovl/o2/o2_006FA0E0_0x6fa0e0.cpp) | `tick_bound_model_slot_radian_yaw_curve_with_scene_flag_candidate` | High mechanics; probable role | Phase0 setsphase1,C/E0,task4=3,5703E0(86,1),audioA7,copy64/bindslot. Phase1 interpolates fixedcurve pointer73C838 for3243CC+1 substeps,converts radians through191EF0 to low16 yaw,370320,18FDF0 taskmatrix reset then191380 originalslotbasiscomposition;copiesoriginaltranslation/W. Sentinel->phase2. Phase2unbind/copy64/delete. Negative curve values are radians, not original yaw integers. |
| [o2 0x6FA360](../recomp/config/output_ovl/o2/o2_006FA360_0x6fa360.cpp) | `tick_bound_model_slot_fixed_horizontal_x_curve_candidate` | High mechanics; probable role | Phase0task4=3,C/E0,phase1,copy64/bind. Phase1 fixedcurve73C898 with3243CC+1 scalar substeps,outputs originalslotX+scalar to task60 andunchangedY/Z/W;sentinel->2. Phase2unbind/copy64/delete. All signed counters/guestfloat interpolation retained. |
| [o2 0x6FA590](../recomp/config/output_ovl/o2/o2_006FA590_0x6fa590.cpp) | `tick_bound_model_slot_fixed_vertical_curve_with_audio_b2_candidate` | High mechanics; probable role | Phase0task4=3,C/E0,phase1,audioB2,copy64/bind. Phase1 fixedcurve73C8E8 with3243CC+1 substeps,outputs originalslotY+scalar andunchangedX/Z/W;sentinel->2. Phase2unbind/copy64/delete. Different curve and setup event from9EB0. |
| [o2 0x6FA7D0](../recomp/config/output_ovl/o2/o2_006FA7D0_0x6fa7d0.cpp) | `tick_bound_model_slot_parent_driven_yaw_and_height_candidate` | High mechanics; probable role | Caches parent28. Phase0bindsslot,phase1,C0 thenfalls through. Inphase1,iftask4zero and signedparentE=1/2,adds/subtracts100 to signedyawC;otherparentEvaluespreserveyaw.370320(task30) builds yawpose;translationX/Z comesfrom49FA40/48+40*slot,Y=49FA44+40*slot+parent54. ParentE==FF (decimal255,not-1) advancesphase2. Phase2unbind/delete;otherphasesreturn. Parentpointer andslotadmission are not checked here. |

The scalar interpolators read records `(float value, signed int tick)` at
8-byte stride. They evaluate using the old signed-half C, then increment C,
advance E when the new C reaches the next tick, and test the following tick
for a negative sentinel. Owned curve records were decoded through each -1
sentinel; distinct live endpoints and caller-controlled indices remain explicit.

| Pointer site | Owned curve(s) | Observed value/tick endpoints and records |
| --- | --- | --- |
|73C720[0..1]|73C630,73C6A0|0 at5 to-50 at90 (13 keys);-50 at5 to0 at90 (15 keys); each then(0,-1). Two following zero words before other data. |
|73C7A8[0..1]|73C730,73C770|0 at0 to5 at60 (7 keys);0 at0 to4.1095 at60 (6 keys); each sentinel. Next bytes belong to another scalar curve, not extra pointers. |
|73C7F8|73C7B0|0 at0 to45 at50 (8 keys), sentinel. |
|73C838|73C800|0 at0 to-2.1817 radians at60 (6 keys), sentinel. |
|73C898|73C840|0 at0,minimum-31.4226 at57,then-30 at60 (10 keys), sentinel. |
|73C8E8|73C8A0|0 at0,-10 at24/30,0 at40 (8 keys), sentinel. |

All curve tick sequences before the sentinel are strictly increasing. This
checks owned static assets only. The substep loop reads3243CC at every loop
test and uses a signed-byte counter; its ordinary range requires session-state
admission. No invalid range is claimed to occur in gameplay.

[Model-slot binding](SYMBOLS_MODEL_SLOT_STATE.md) defines5D8280/5D8300.
191380 changes XYZ basis components while preserving W, and the commit paths
copy the resulting64-byte pose after unbinding. Original curve/task admission
and the significance of scene flags remain unknown.
