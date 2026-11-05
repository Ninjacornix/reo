# Actor numeric D9..DF motion phase sequences

Static File #1 US research, 2026-11-04. Seven complete original bodies reviewed. Fields/addresses/state IDs hexadecimal; XYZ distance40, float blends10/4 and interpolation durations10/20 decimal. High confidence in local mechanics, probable semantic roles; original authored action names unknown. No execution, replay, builds, attachment or game-speed changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x57EAD0](../recomp/config/output_ovl/o2/o2_0057EAD0_0x57ead0.cpp) | `actor_phase_sequence_motion02fc_with_track_activation_candidate` | High mechanics; role probable | OR54A1F,clear553;6673C0 nonzero resetsphaseA0. Phase0 sets54F25,D10=1,saves transform,zeroes4E4..4EC,phase1 then immediately executes phase1. Phase1 ->phase2,flags82,motion descriptor708DA0(f12=0,f13=10),activate58C7B0. Phase2 only58C300(actor,1),no completion transition here. Other phases no work. |
| [o2 0x57EBC0](../recomp/config/output_ovl/o2/o2_0057EBC0_0x57ebc0.cpp) | `actor_phase_sequence_motion02fd_with_track_activation_candidate` | High mechanics; role probable | Same local state machine as57EAD0 but descriptor708DA8. All actual body instructions reviewed; distinct descriptor address prevents exact-body alias. |
| [o2 0x57ECB0](../recomp/config/output_ovl/o2/o2_0057ECB0_0x57ecb0.cpp) | `actor_motion02fe_phase_sequence_and_return_base_candidate` | High mechanics; role probable | OR54A1F,byte32FF,resetflag clearsphase0. Phase0 sets54F25,D10=1,saves,zeroes root;falls phase1. Phase1 ->2,flags82,descriptor708DB0(0,10),activatebanks. Phase2 signed low8 animation result==1 ->phase3. Phase3 common base reset below. Other phases no work. |
| [o2 0x57EE20](../recomp/config/output_ovl/o2/o2_0057EE20_0x57ee20.cpp) | `actor_align_target_then_motion02ff_and_return_base_candidate` | High mechanics; role probable | OR54A1F,32FF,resetflag phase0. Phase0 saves targetABC.X/Z with currentY,yawAC8,54F25,D10=1,root0;distance<=40 ->phase1 else66DD50(actor,0). Other unmatched phases also call alignment until nonzero ->1. Phase1 prepares motion708DB8 and root-adjusted target, optional AD6 flag;phase2 curves XYZ/yaw over10/20 ticks and advances animation; positive signed low8 boundary ->3;phase3 base reset. Detailed state timing below. |
| [o2 0x57F1A0](../recomp/config/output_ovl/o2/o2_0057F1A0_0x57f1a0.cpp) | `actor_motion02f8_zero_blend_phase_sequence_and_return_base_candidate` | High mechanics; role probable | OR54A1F,32FF,resetflag phase0. Phase0 sets54F26,D10=1,saves,root0 thenfallsphase1. Phase1 ->2,flags82,descriptor708DC0(f12/f13 both0),activatebanks. Phase2 any full-word nonzero58C300(actor,1) ->3. Phase3 base reset; distinct from exact signed-byte1 gate in57ECB0. |
| [o2 0x57F300](../recomp/config/output_ovl/o2/o2_0057F300_0x57f300.cpp) | `actor_align_target_then_motion0352_zero_blend_and_return_base_candidate` | High mechanics; role probable | OR54A1F,32FF,resetflag phase0. Phase0 sets54F35,D10=1,saves,root0,targetABC.X/Z currentY,yawAC8. Calls66DD50(actor,0) twice on initial path, second result can setphase1; default unmatched phases alignment once. Phase1 ->2,flags82,descriptor708DC8(0,0),activatebanks. Phase2 any fullword nonzero animationresult ->3, then base reset. |
| [o2 0x57F490](../recomp/config/output_ovl/o2/o2_0057F490_0x57f490.cpp) | `actor_align_multimotion_counter_sequence_and_return_base_candidate` | High mechanics; role probable | OR54A1D,32FF. Consumedreset nonzero immediately performs base reset andreturns. Otherwise phases0..9/FF drive alignment,motion708DD0,interpolation,motion708DE0,timerwait,motion708DF0;full ordered branch table below. No actor-action taxonomy or real-time timeout claim. |

Common base reset, where stated:byte54F=0,half548&=FFFE,action8=1,substate9=0,phaseA=1,B=0;667370 saves currentXYZ/yaw;5D4CF0(actor,2050,f12=0,f13=10),58C7B0 activates banks. This is not a generic call to a host animation reset.58C7F0 ORs primary track flags82;58C7B0 activates track banks;58C300 advances animation. [Animation contracts](SYMBOLS_ANIMATION.md) define those operations. Consumed reset6673C0 also clears motion520 and changes BA4; it is not a pure status getter.

57EE20 phase1:phaseA becomes2,54F10,BA8=1;flags82;descriptor708DB8(0,10). If unsignedhalfAD6<200 and(actor3==4BADED or1B02D0()==1),5703E0(AD6,1). Saves currentXYZ intoC40 and yaw92 intoC4E. Signedhalf12=decimal20 when byte3243CC zero,otherwise10.1925C0(outVector,model34->824,f12=0,f13=20) samples a root translation;rotate by2pi*unsigned C4C/65536,add into targetC34. Phase2 if timer12!=0 decrements it, interpolates actorXYZ665E60 fromC40 toC34 and yaw665FC0 fromC4E toC4C using elapsed=duration-newtimer,duration chosen20/10 from the current global byte. Clears root4E4..4EC. Exactly newtimer0 copies targetXYZ/yaw directly. Regardless timer state,58C300(actor,BA8);only positive signed low8 advancesphase3. The duration selector is read again while ticking; no stable wall-time duration or bounded handling for initially negative timer is inferred.

57F490 phase table after its immediate consumed-reset exit:

| PhaseA | Work / next phase |
| --- | --- |
| 0 |54F10,D10=1,savedtransform,root0,targetABC.X/Z+currentY,yawAC8. Distance<=40 ->phase2 andreturn;else66DD50(actor,0) once,return. |
| 1 or other unmatched exceptFF |66DD50(actor,0),nonzero ->phase2. |
| 2 |phase3,54F10,BA8=1,flags82,motion708DD0(0,10). SaveXYZ/yaw,timer12=20/10,and add rotated1925C0(model824,0,20) root vector to target, same calculation as57EE20 but **no AD6 flag here**. |
| 3 | Same timer-based XYZ/yaw interpolation and direct snap at0;58C300(actor,BA8),positive signed low8 ->phase4. |
| 4 |phase5,flags82,motion708DE0(0,4),activatebanks. IfAD6<200 andactor3==4BADED,5705F0(AD6,1,actor3). SignedhalfC=1B2 when byte3243CC zero,otherwiseD9. |
| 5 |58C300(actor,1);reads **old** signedhalfC,storesC-1 in branch delay slot on everypath. OldC==0 ->phase6;other values retainphase5. This is not a<=0 countdown. |
| 6 |58C300(actor,1);any fullword nonzero ->phase7. |
| 7 |phase8,flags82,motion708DF0(0,4). Does not call58C7B0 here. |
| 8 |58C300(actor,1);any fullword nonzero ->phaseFF. |
| 9 orFF | Common base reset. |

Phase branches operate one callback at a time except explicit fallthroughs noted above.57F300 initialphase0 calls66DD50 twice in the same invocation; this is measured static call count, not a performance sample. Several handlers preserve existing BA8 or motion flags on branches and rely on caller state; numeric phase labels are retained.

Owned descriptor table blocks from o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`; each8-byte physical descriptor is four little-endian unsigned halfwords. Addresses708DD0/708DE0 have adjacent second descriptors, included as bytes rather than assumed runtime selection proof:

| Physical span | Unsigned halfwords hexadecimal | SHA256 |
| --- | --- | --- |
| 708DA0..708DA7 | 10,0,2FC,2FC | `a341960218a73dd2177e2fa931dd65e27f842113bf1193d78fe86d54a908d037` |
| 708DA8..708DAF | 10,0,2FD,2FD | `354912f8dd4f121394bdece730914afca228f99d57ee3ac3cacbde5bef8549d5` |
| 708DB0..708DB7 | 10,0,2FE,2FE | `87ee5e0ec10f7bae63ee33a556eae19173ec8524e3637f779501e96430685447` |
| 708DB8..708DBF | 10,0,2FF,2FF | `ef07666a8f79666b2e22dd15771c4b4c29ac96fb29d05827e81c8a91f2e3e192` |
| 708DC0..708DC7 | 10,0,2F8,2F8 | `06e307e8544dd575e7b996e27d8796f4947d1dce92afbc012f10abe3c6d7791e` |
| 708DC8..708DCF | 10,0,352,352 | `df233670c7ebd0526ce40f697915ad046089fc0ab9a98749aedcd237a50b5c5e` |
| 708DD0..708DDF | 10,0,393,393,10,0,394,394 | `158d46eb59e065a2abad070e67a3aeb592b98c8b86c5d1f2a212cb52544399ba` |
| 708DE0..708DEF | 10,0,395,395,10,0,396,396 | `719fa826a88f0148980c225ac91dde2776a755848a23df678eacb334b2d79e52` |
| 708DF0..708DF7 | 10,0,397,397 | `435f03edf8c7be734787cc5b22e242196e0876a4e57119e874965bd6ab3e988c` |

Owned73DF00..73DF03=float32 6.2831854820251465, SHA256 `12d85026b5109a3119231704608d5991a63d8d397d2867a9fc522305810ddb76`. [Numeric transition entries](SYMBOLS_ACTOR_NUMERIC_D7_DF_ENTRIES.md) cover neighboring setup/tick wrappers. The handled motion codes do not identify original human-readable animations by themselves. No root-cause, frequency, successful gameplay interaction or rendering cost claim follows from this mapping.

Owned-word audit:7 rows,885 distinct instruction words verified,41 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
