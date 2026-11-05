# Actor 6C fade, relocation and alignment resume handlers

Static File #1 US research, 2026-11-04. Nine complete original bodies reviewed.
Addresses/offsets/states hex; duration multipliers explicitly decimal60.
Actor identity, original state names and record availability semantics unknown.
No target execution, attachment, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C9180](../recomp/config/output_ovl/o2/o2_006C9180_0x6c9180.cpp) | `play_actor_6c_motion_15_then_choose_variant_action_candidate` | High mechanics; probable role | PhaseA0->1,selectmotion15throughA610(f12=0);phase1advances58C300step1,positive signedbyte return->9990 variantactionselection. Otherphases noaction. |
| [o2 0x6C9200](../recomp/config/output_ovl/o2/o2_006C9200_0x6c9200.cpp) | `fade_actor_6c_then_wait_for_record_relocation_and_restore_health_candidate` | High mechanics; probable role | Always54A=4,C94|=209,32=FF. A0->1,E=14,6367C0,selectmotion14step0. Phase1predecrementsE,post<=0 advancesA,animationstep0. Phase2CCC>=8subtracts8;otherwiseA++,byte1=0,CCC=FF;copiesCCCtoCCD/CCE/CCF,step0. Phase3adds54Abit1,byte1=0;requires3B5050[B98]==FF and6344C0(1E2,byte4B9D20[1E2],BB5)nonzero. Writesrecord74F295+60*B98=0,74F293+60*B98=resultbyte1;copiesintXYZandhalfheadingfromresult exceptscenario29/room3E,restores544=546,BA5=1,9ED0(actor,A,resultbyte0). A5->3,selectmotion14step0,activate58C7B0banks. |
| [o2 0x6C9460](../recomp/config/output_ovl/o2/o2_006C9460_0x6c9460.cpp) | `dispatch_actor_6c_secondary_restore_handler_then_mark_flag100_candidate` | High mechanics; probable role | Calls7305B0[unsigned9](actor),thenC94|=100. Ownedfivepointerentries B0,B0,F0,9610,9760;noindexguard. |
| [o2 0x6C94B0](../recomp/config/output_ovl/o2/o2_006C94B0_0x6c94b0.cpp) | `hide_actor_6c_and_set_restore_flags_candidate` | High mechanics; probable role | Byte1=0,54A=1F,32=FF,BA5=1,C94|=209. No timer,animation or statewrite. |
| [o2 0x6C94F0](../recomp/config/output_ovl/o2/o2_006C94F0_0x6c94f0.cpp) | `resume_actor_6c_mode_three_from_available_record_candidate` | High mechanics; probable role | Always54A5,32FF,C94|201,BA5=1. OnlyA0:byte1=0,BA3=3;record74F27E+60*B98 nonzero ->8/9=1/9,A/B0,E=60*record74F291/factor74F200,C2B0;6338C0(XYZ,-1),633870(C44,returnlowbyte),5A6B20(actor,1E). A remains0onmissingrecord. |
| [o2 0x6C9610](../recomp/config/output_ovl/o2/o2_006C9610_0x6c9610.cpp) | `resume_actor_6c_mode_one_from_nearest_surface_or_reset_alignment_candidate` | High mechanics; probable role | Always54A5,32FF,C94|201,BA5=1. A0:byte1=0,BA3=1;record74F27E+60*B98 nonzero ->byte1=1,E=60*record74F291/factor;B6D0(actor,D00,D0C). Nonzeroheadingdelta->8/9=1/A,A/B0,quaternionD18via5A82A0,XYZ=D0C+D00. Zero->8/9=1/0,A/B0,BA3=0. C2B0,5A6B20(actor,32). Straight-aheadvalidsurfacealsotakeszerobranch. |
| [o2 0x6C9760](../recomp/config/output_ovl/o2/o2_006C9760_0x6c9760.cpp) | `delay_actor_6c_mode_one_resume_until_record_timer_expires_candidate` | High mechanics; probable role | Always54A5,32FF,BA5=1,C94|209. A0->1,BA3=1,byte1=0,thenphase1samecall. Waitsrecord74F27E nonzero,advancesA,E=60*record74F291/factor. Phase2predecE<=0 setsbyte1=1,B6D0(D00,D0C);nonzero->8/9=1/C,A/B0,quaternion,XYZ=D0C+D00;zero->1/0,A/B0,BA3=0. C2B0,5A6B20(actor,32). |
| [o2 0x6C9900](../recomp/config/output_ovl/o2/o2_006C9900_0x6c9900.cpp) | `tail_dispatch_actor_6c_single_restore_secondary_table_candidate` | High mechanics; probable role | Unsigned9indextailcall730648. Ownedfirstentry9920,nextword0;callerindexcontractretained,notexpandedintoarbitrarycallbacks. |
| [o2 0x6C9920](../recomp/config/output_ovl/o2/o2_006C9920_0x6c9920.cpp) | `resume_actor_6c_mode_three_at_fixed_point_height_plus_400_candidate` | High mechanics; probable role | 54A5,BA5=1,32FF,C94|209,byte1=1,BA3=3,CCC/CCD/CCE/CCFFF,Y=owned7305E4+decimal400=-2800,8/9=1/D,A/B0. X/Zunchanged,noanimationadvance. |

Owned7305B0 fivecallbackwords:6C94B0 twice,6C94F0,6C9610,6C9760,
thenzero7305C4;730648singleword6C9920thenzero. These zeros are not admitted
valid table entries.7305E4 holds-3200. Record addresses74F27E/291/293/295
and3B5050 were not read from a live process. Timer division uses unsigned
bytefactor; no new zero-divisor handling inferred.

The nearest-surface queryB6D0 returns0 both for nohit and alignedhit.
9610/9760 explicitly consume that numeric result as a branch condition;this
is an observed static contract,not a proven player-visible defect.
Related [collisionhelpers](SYMBOLS_ACTOR_6C_ALIGNMENT_COLLISION.md) and
[relocationqueries](SYMBOLS_RECORD_ROOM_RELOCATION.md).
