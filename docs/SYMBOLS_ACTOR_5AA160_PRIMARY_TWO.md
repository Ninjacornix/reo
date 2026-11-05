# Actor family5AA160 complete primary-two contact states

Static File #1 US research, 2026-11-04. All eight distinct original owners and
all eight ownedtable slots reviewed, including internalstate0mergedwiththe
dispatcher. No game, build, replay, attachment or live-memory inspection.
Addresses/offsets/IDsarehexadecimal;floatconstantsandexplicitcountsdecimal.
The actor family is address-identified; contact/transition roles remain
candidates,notrecoveredoriginalactororanimationnames.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5AB4F0](../recomp/config/output_ovl/o2/o2_005AB4F0_0x5ab4f0.cpp) | `dispatch_primary_two_and_initialize_state0_height_scaled_contact_candidate` | Probable role; full body reviewed | Uncheckedsubstatebyte9taildispatch709C00. Mergedinternal5AB510isstate0owner,notextrafunction. Requiresrelated24nonnull;BA5=1. A0->1clears115bit1,setsactorYaw=5A9A40(actor,signedrelated3),selectsdescriptorF/f12=0,5DA2C0(actor,4D,1). ComputesC40=min((relatedjoint9Y-sourceY)/200.0,2.5)throughrelated34+844;nolowerclamp. A1ticks1.0,signedresult>0routes5ADB30(actor,1,3). No explicittrackactivationcallinthismergedhandler. |
| [o2 0x5AB610](../recomp/config/output_ovl/o2/o2_005AB610_0x5ab610.cpp) | `primary_two_state1_surface_alignment_and_timed_xyz_transition_candidate` | Probable role; full body reviewed | Related24required,BA5=1. A0->1traces5795E0(sourceXYZ,relatedXYZ,...,-1,0,out),successX/Z=tracepoint+50*normal,groundquery616F20(relatedXYZY+200,FF)thenY=height-170,yawfromnormal. Failure5ADB30(1,3)butstillselectsdescriptor11/f12=0andclearsB1E. A1OR54A5,ticks1;signedresult>0enters2. Otherwiseframein[16,16+owned709C90[clockmode])clears115bit1,5DA2C0(4E,1);elseB1E==1with5AA0C0true->5ADB30(2,2). A2->3,E=10/global74F200,rotates709C98byyaw,dividesXYZdeltasbyE,targetY=184-135,descriptor12. A3ticks1,result>0routes(1,3);thenEpredecrementandaddsD04XYZonlywhileE>0. No localzero-divisorguardsorfailed-traceassumptioninvented. |
| [o2 0x5AB9C0](../recomp/config/output_ovl/o2/o2_005AB9C0_0x5ab9c0.cpp) | `primary_two_state2_two_trace_alignment_and_timed_recovery_candidate` | Probable role; full body reviewed | Related24required;54AORC,BA5=1. A0->1selectsdescriptor11/f12=18,trace(source,related);failure returns. Trace-normal*200+related formssecondendpoint;secondtracefailure returns. SuccessstoresX/Zdelta=(tracepoint+50*firstnormal-current)/5,E=5. A1OR54A1,Epredecrements,movesXZwhileE>=0,ticks1;positiveanimationresult->A2. A2->3,E=10/global,rotates709CA8,deltasdividebyE,Ytarget184-135,descriptor12. A3ticks1;positiveanimresulthealth544>0routes(1,3),else(3,2). EpredecrementsandaddsXYZwhileE>=0 (unlike5AB610strict>0). Bothtracefailurepathsleavealreadyselectedphase1; no reproducedfailureclaim. |
| [o2 0x5ABD10](../recomp/config/output_ovl/o2/o2_005ABD10_0x5abd10.cpp) | `primary_two_state3_contact_descriptor13_and_target_readmission_candidate` | Probable role; full body reviewed | Requiresrelated24,BA5=1. A0->1clears115bit1,descriptor13/f12=0,5DA2C0(68,1),B1E=0. A1ticks1;positiveanimresult->5ADB30(1,3);otherwiseB1E1AND5AA0C0true->(2,4). Afteranyphasework,ifprimaryaction8!=2sethalfC=168/global74F200. No localdivisorguard;allocationnotinbody. |
| [o2 0x5ABE30](../recomp/config/output_ovl/o2/o2_005ABE30_0x5abe30.cpp) | `primary_two_state4_five_phase_related_contact_sequence_candidate` | Probable role; full body reviewed | Requiresrelated24,54AORC. A0->1descriptor14/f12=0,activates;rotates709CB8byyawandsetsownX/Z=relatedX/Z+offset,E=4. A1B1E6->A4descriptor17/f12=10;B1E4ORrelated54FB0->A3descriptor16/f12=0. Otherwisetick1,signedresult2decrementsE;<=0incrementsAto2andrelatedB1E=63. A2->3descriptor15/f12=0. A3positiveanimationresult->(1,3);A4positive->(4,1),via5ADB30. Afterphaseprimary!=2setsC=168/global. DoesnotsetBA5inthisbody;preservesfieldfromupdater/caller. |
| [o2 0x5AC0A0](../recomp/config/output_ovl/o2/o2_005AC0A0_0x5ac0a0.cpp) | `primary_two_state5_contact_descriptor18_and_shorter_return_timer_candidate` | Probable role; full body reviewed | Independently reviewed siblingof5ABD10:relatedrequired,BA5=1. Initdescriptor18,clear115bit1,5DA2C0(69,1),B1E=0. Activeanimationpositive->(1,3),B1E1admission5AA0C0->(2,6). Primaryaction!=2setsC=B4/global74F200 (not168). Nootherlocalstatealias. |
| [o2 0x5AC1C0](../recomp/config/output_ovl/o2/o2_005AC1C0_0x5ac1c0.cpp) | `primary_two_state6_alternate_five_phase_contact_sequence_candidate` | Probable role; full body reviewed | Requiresrelated,54AORC,BA5=1. Initdescriptor19/activate,rotated709CC8offsetrelativeX/Z,E=4. A1B1E6->A4descriptor1C/f12=10;B1E4ORrelated54FB0->A3descriptor1B/f12=0;elsecyclesuntilresult2decrementsE<=0thenA2andrelatedB1E63. A2->3descriptor1A. A3positive->(1,3);A4positive->(4,7). Primary!=2C=B4/global. Separatelyreadallbranches;distinctdescriptor/timerandBA5contractfrom5ABE30. |
| [o2 0x5AC430](../recomp/config/output_ovl/o2/o2_005AC430_0x5ac430.cpp) | `primary_two_state7_descriptor10_contact_until_animation_completion_candidate` | Probable role; full body reviewed | A0->1clears115bit1,selectsdescriptor10/f12=0,5DA2C0(6A,1). A1ticks1,positivesignedresult->5ADB30(actor,1,3). Norelatedpointeradmission,BA5assignmentorreturntimerwritehere,unlikeotherprimarytwohandlers. |

Owned table709C00:

| Substate | Original target / owner |
| --- | --- |
| 0 | 0x5AB510 (internal owner5AB4F0) |
| 1 | 0x5AB610 |
| 2 | 0x5AB9C0 |
| 3 | 0x5ABD10 |
| 4 | 0x5ABE30 |
| 5 | 0x5AC0A0 |
| 6 | 0x5AC1C0 |
| 7 | 0x5AC430 |

Division inputs and failed-trace entry states are documented literally. A static
missing guard is not evidence that zero divisors or stale state were admitted.
Strictpositive versus nonnegative countdown movement differs between5AB610
and5AB9C0 and is retained for anyfuturetranslation. No runtimepatch,game-speed
change or performance/root-cause claim is made.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
