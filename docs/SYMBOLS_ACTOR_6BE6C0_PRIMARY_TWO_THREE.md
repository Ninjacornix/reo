# Actor 6BE6C0 primary-two action and primary-three reaction handlers

Static File #1 US research, 2026-11-04. Five complete original bodies reviewed,
including merged inner bodies6BF700 and6BFD10. Addresses/offsets/selectors
hexadecimal; explicit distances/counts decimal. Original animation names unknown.
No execution, attachment, build or replay.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6BF6E0](../recomp/config/output_ovl/o2/o2_006BF6E0_0x6bf6e0.cpp) | `dispatch_primary_two_and_tick_motion_c_to_selected_action_candidate` | High mechanics | Uncheckedbyte9 indexes72FC10;0merges6BF700. Secondary3 firstsetsCF3=1. AFF clearsA/C36=4A,thenA0->1/motionC;A1stepsratecolumn8 until1F1bit40,thenA2/select72FC50[9],CE8=2,CEC=10/factor,58C780,RNGstream1&7->C37. A2stepsratecolumn8 untilflag40;secondary0setsCEE=360/factor,then6C0470(self,0). OtherAreturns. |
| [o2 0x6BF8D0](../recomp/config/output_ovl/o2/o2_006BF8D0_0x6bf8d0.cpp) | `tick_primary_two_direct_selected_action_motion_candidate` | High mechanics | Secondary3setsCF3=1 onentry. AFF clearsA/C36=4A;A0->1,secondary3setsCF3=2,chooses72FC50[9]. If1F2matches72FE14+6*selector stepsratecolumn8 else6C0400;CE8=2,CEC=10/factor,RNGstream1&7->C37. A1stepsratecolumn8 untilflag40;secondary0CEE=360/factor,then6C0470(self,0). OtherAreturns. |
| [o2 0x6BFAA0](../recomp/config/output_ovl/o2/o2_006BFAA0_0x6bfaa0.cpp) | `tick_primary_two_timed_four_effect_emission_and_cooldown_candidate` | High mechanics | AFF clearsA/C36=4A;A0->1/select72FC50[9],58C780. A1stepsbaserate,unlessframe1E4<50 incrementsA, takes model34->864+30,adds90float to component4/subtracts90 from8,then582720(self,basis50,point,rot90,B,ordinal) four times ordinal0..3;CF2=(CF2+1)&7F. A2steps;positive signed8 result setsCF0=180/factor,primary1,secondary72FC48[RNGstream1&7],AFF/B0. OtherAreturns. |
| [o2 0x6BFCB0](../recomp/config/output_ovl/o2/o2_006BFCB0_0x6bfcb0.cpp) | `mark_emd_reaction_bit_and_dispatch_primary_three_motion_c_candidate` | High mechanics | OR runtime74F295+60*B98 bit10,global7556E0=11C;unchecked9 indexes72FC20. Entriesotherthan2targetmerged6BFD10: A0calls63F5A0(self,byte3);A0/FF selects motionC andA1,FFalsoC36=3E. A1stepsbaserate;nonzero fullreturn6C0470(self,0). OtherAreturns. |
| [o2 0x6BFDD0](../recomp/config/output_ovl/o2/o2_006BFDD0_0x6bfdd0.cpp) | `tick_primary_three_motion_d_and_c2e_threshold_recovery_candidate` | High mechanics | A0calls63F5A0(self,byte3);A0/FF selectsmotionD,A1,FFalsoC36=3E. A1stepsbaserate;flag40 andC2E>=1000 ->A2/motion2/58C780;flag40 andlowerC2E ->6C0470(self,0). A2steps;flag40 ->6C0470(self,0). OtherAreturns. |

Base rate means float728FF0+12*BA1; column8 means728FF8+12*BA1.
The four calls in6BFAA0 are bounded effect construction attempts; no success or
runtime expense is assumed. The point modified by +/-90 belongs to the resolved
model node and is mutated in place. Timing thresholds are animation frame fields,
not wall-clock milliseconds.

Owned tables from `build-function-index/owned-overlays/o2.bin`,base570000,
SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Span | Values / SHA256 |
| --- | --- |
| 72FC10 length10 | [6BF700,6BF8D0,6BFAA0,6BF8D0]. `16fb9d3b47db5a34d0c49f699e8dfb2d0251436d5b86fee7429ed5b4a8427405` |
| 72FC20 length1C | [6BFD10,6BFD10,6BFDD0,6BFD10,6BFD10,6BFD10,6BFD10]. `262d426cc766aedae398faab792a60295519c42a17d434a962eb08ec8bc59014` |
| 72FC50 length4 | bytes[8,9,A,3]. `d9cf686556d900e8058ca115327a8775524ead94cd9c776c7e3a42cab9432fcf` |
| 72FC48 length8 | bytes[0,0,0,0,0,4,4,4]. `23ecb13fb48a8c793ea8309bb34aefec9562c2a455ebfe3969196e2f8734f49d` |

See [callback](SYMBOLS_ACTOR_6BE6C0_CALLBACK.md),
[motion helpers](SYMBOLS_ACTOR_6BE6C0_MOTION_TARGET_SELECTION.md),
[contact admission](SYMBOLS_ACTOR_6BE6C0_CONTACT_REACTIONS.md).

Full-body owned-word audit: 5 rows, 493 verified instruction words,
zero conflicts, 31 omitted zero/NOP words, zero omitted nonzero words.
