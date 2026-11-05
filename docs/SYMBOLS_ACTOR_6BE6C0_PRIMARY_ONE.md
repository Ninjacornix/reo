# Actor 6BE6C0 primary-one motion and pursuit actions

Static File #1 US research, 2026-11-04. Six complete original bodies reviewed,
including the merged6BECD0 inner body owned by6BECB0. Addresses/offsets/selectors
hexadecimal; distances/timers described in decimal where explicit. Original
animation names remain unresolved. No execution, attachment, build or replay.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6BECB0](../recomp/config/output_ovl/o2/o2_006BECB0_0x6becb0.cpp) | `dispatch_primary_one_and_tick_timed_motion_variant_candidate` | High mechanics | Byte9 unchecked indexes72FBF0. Entries0/1 target merged6BECD0: A0/FF initializesA1,FFalsoC36=3D,CE8=3,CEC=10/factor,RNGstream1 selectsE timer72FCA0/factor, motionselector72FC40[9]. Mismatch1F2 against72FE14+6*selector calls6C0400(selector,A,0,0float),returns; match12=1 thenstepsanimation. A1 decrementsE,expired6C0470; then635640(FA) and634C00(self,target7556E8,2AA8,0,1100float) may6C0BD0 and skip animation. OtherAonlyanimation. |
| [o2 0x6BEEB0](../recomp/config/output_ovl/o2/o2_006BEEB0_0x6beeb0.cpp) | `tick_primary_one_motion_two_to_three_and_target_gate_candidate` | High mechanics | A0/FF->1,FFC36=3D; if1F2!=66 selectmotion2 and58C780,elseanimationstep. A1 steps; positive signed8 step result->A2,motion3. A2steps,1F1bit40 may6C0470(self,0),thenshared635640/634C00 gate may6C0BD0. OtherAreturns. |
| [o2 0x6BF070](../recomp/config/output_ovl/o2/o2_006BF070_0x6bf070.cpp) | `tick_primary_one_motion_six_with_selected_counter_threshold_candidate` | High mechanics | SignedhalfBF8[byteC26]<250 calls6C0470(self,1),returns. Otherwise A0/FF->1,FFC36=40,CE8=3,CEC=10/factor; if1F2!=owned72FE38 selectmotion6. A1stepsrate728FF4+12*BA1,thenshared635640/634C00 gate may6C0BD0. |
| [o2 0x6BF1C0](../recomp/config/output_ovl/o2/o2_006BF1C0_0x6bf1c0.cpp) | `tick_primary_one_motion_two_three_and_retarget_tuple_five_candidate` | High mechanics | Secondary9=6 usesrate1.5float and zerosC2E oninit;othersbase rate. A0/FF maps1F2=66->A1,67->A2,elseA1/motion2/58C780;FFC36=40. A1steps;1F1bit40 uses6C0AD0(1100):positive otherthanFF enters(1,5,FF,0),otherwiseA2/motion3. A2steps and samepositive search enters tuple5,otherwise635640/634C00 may6C0BD0. A3stepsbase rate;otherAreturn. |
| [o2 0x6BF460](../recomp/config/output_ovl/o2/o2_006BF460_0x6bf460.cpp) | `tick_primary_one_motion_seven_entry_and_priority_action_reselection_candidate` | High mechanics | A0/FF:1F2=66steps;positive signedstep->A2/motion7/58C7B0,elseA1.1F2=67selectsA2/motion7;70setsA2andsteps;otherA1/motion2/58C780. FF C36=40. A1steps;1F1bit40 incrementsA/selectsmotion7/58C7B0. A2steps,635640,then6C0880;successreturns,otherwise6C0AD0(1100)=0 enters(1,4,FF,0). OtherAreturns. |
| [o2 0x6BF6D0](../recomp/config/output_ovl/o2/o2_006BF6D0_0x6bf6d0.cpp) | `clear_actor_selector32_then_tail_primary_one_secondary_six_candidate` | High mechanics | Setsbyte32=FF in tailjump delay to6BF1C0. No other local work. |

Common animation rates are float728FF0+12*BA1 unless a row specifies column4 or
another value. Motion selection calls6C0400(self,selector,A,0,0float), with
transition methods58C780/58C7B0 only where stated. The shared target gate is
635640(self,FA) then634C00(self,global7556E8,2AA8,0,1100float), each nonzero.
It is not presumed to imply an original attack action or successful damage.
Unsigned factor74F200 is initialized to1/2 by6BBBA0; divisions are retained.

Owned72FBF0 length1C seven targets:
`[6BECD0,6BECD0,6BEEB0,6BF070,6BF1C0,6BF460,6BF6D0]`;
SHA256`fa71a59cde40e495180018422a5378b11bf58c4de1aa84b8bb3ca9ce213b3475`.
Owned72FC40 length8 bytes`[0,1,0,0,0,0,0,0]`,
SHA256`2e22fd435060cd5d3cf5e3ef39f79e198b35bd2c4af31974db36601b3a2f4c91`.
Owned72FE14 length30 eight triples ofsignedhalves:
`[(64,0,0),(65,0,0),(66,0,0),(67,0,0),(68,0,0),(6E,0,0),(6F,0,0),(70,0,0)]`;
SHA256`331f584f72537666060069edffe6f02f59eebdc444e3f992a97997a6fd51f469`.
The numeric triples are motion IDs/fields mechanically; original names unknown.
Owned image `build-function-index/owned-overlays/o2.bin`,base570000,
SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

See [callback](SYMBOLS_ACTOR_6BE6C0_CALLBACK.md) and
[motion helpers](SYMBOLS_ACTOR_6BE6C0_MOTION_TARGET_SELECTION.md).

Full-body owned-word audit: 6 rows, 591 verified instruction words,
zero conflicts, 50 omitted zero/NOP words, zero omitted nonzero words.
