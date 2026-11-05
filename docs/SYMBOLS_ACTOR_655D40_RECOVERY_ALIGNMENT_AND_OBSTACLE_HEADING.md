# Actor655D40 recovery, alignment transitions and obstacle heading

Static File #1 US owned o2 analysis, 2026-11-05. Four full original bodies; [identity](FUNCTION_INDEX.md). No runtime work. Fields/states/masks hexadecimal; explicit distances and durations decimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x656DD0](../recomp/config/output_ovl/o2/o2_00656DD0_0x656dd0.cpp) | `run_motion2f_recovery_clear_route_scores_and_transition_to_base_route_state` | Confirmed complete flagged recovery sequence | Everycall32=FF,54AORC. A0->1,C37=1,65D410(motion2F),12=600/unsigned74F200,6367C0clearsroute-scorehalves/C30;noactivationhere. A1tick1,positive signedlow8calls65A9E0(actor,1,2). A2->3,motion6withoutactivation;A3tick1positiveclearsA0. A=AclearsA0;otherphasesreturn.12isinitializedbutnotdecrementedlocally. |
| [o2 0x656F00](../recomp/config/output_ovl/o2/o2_00656F00_0x656f00.cpp) | `restore_actor_health_and_lower_y_then_play_motion2e_before_base_selection` | Confirmed complete recovery/reset ordering | EverycallBA5=1,32=FF,54AORC. A0->1,C37=0,render1=1,Y=D28-150,health544=maximum546,65D410(motion2E),12=600/unsigned74F200;noactivation. A1tick1positive65A170. A=AclearsA0. Otherphasesreturn. DoesnotclearBA5again;12notdecrementedhere. |
| [o2 0x656FF0](../recomp/config/output_ovl/o2/o2_00656FF0_0x656ff0.cpp) | `run_alignment_transition_motion_then_restore_secondary_and_toggle_alignment_mode_when_selected` | Confirmed complete phase/motion table and return paths | EverycallBA5=1,54AOR5,32=FF. Initialphasesselectmotions/nextphasebelowandC82=1. Phase4tick1positivepreservesBA3,phase5tick1positivetogglesBA3==1to0else1. Bothsave8/9toBE8/9,secondary9=B,A=1,B=0,C82=1,65D680(signednewsecondary),5A82A0(D18,D00,signedBA3),clearanimationrootXYZ4E4[12bytes],C36=7. Onlyphase4also65D1F0supporttrace/savedpositionrefresh. Allpaths,includingunknownphaseandnonpositiveanimationresult,copyXYZtomatrixtranslation80/84/88. No explicitactivationafterinitialmotionselection;65D680activatesreturnedmotion. |
| [o2 0x65C200](../recomp/config/output_ovl/o2/o2_0065C200_0x65c200.cpp) | `probe_motion_direction_against_surfaces_and_steer_yaw_around_admitted_normals` | Confirmed full trace and angle-sector logic | ReturnsifC39==1,C37!=0,orlength(C0XYZ)<=0. RadiusR=2*101*BC;tentativeQ=XYZ+(R/length)*C0. Buildsbiasedstart/currentandend/QwithXZminus20*(D00.X,D08.Z),Yunchanged. BA3==1andQ.Y<D28bypassesrays:Q=currentXYZ,Q.Y-=R,marksadmitted. Otherwisefirst5795E0(currentXYZ,Q,...,mask-1,mode0)withflags1AND100000setsQ=currentXYZ-R*hitnormal. Ifnotadmitted,reversebiasedtrace(end,start)withsameflagssetsQ=currentXYZ+R*normal. Onlyadmittedcasecomputes65DA50(actor,Q),signed16delta=heading-yaw,sectoradjusts/clampsbelowandaddyaw. DoesnotwriteXYZ,velocity,traceflagsorcallerroutegoal. No finite/radiuspositive/localnormalizationguard. |

656FF0 initialization table (all state/motion values hexadecimal):

| InitialA | Selectedmotion | NextA |
| --- | --- | --- |
|0|A|4|
|1|B|4|
|2|A|5|
|A|D|4|
|B|F|4|
|C|D|5|
|14|C|4|
|15|E|4|
|16|C|5|

65C200 yaw policy for signed16delta: inclusive[-1000,1000] clampsdelta bysignedBDA;delta in[-3FFF,-1001] clampssigned16(delta+2000);delta in[1001,3FFF] clampssigned16(delta-2000). Otherdeltasleaveyawunchanged. Boundshexadecimal. Child634B20hasownnegative-magnitude/narrowingsemantics;conventionalsymmetricclampisconditionalonvalidmagnitude. All trace requests happen before any yawwrite. NaNlengthisnotcaughtbyordered<=0; no host-normalization replacement is assumed.

The [full655D40dispatcher](SYMBOLS_ACTOR_655D40_BASE_STATES_AND_MOTION_TRANSITIONS.md) now has all16ownedtabletargets reviewed across this note and [route/chase/turnstates](SYMBOLS_ACTOR_655D40_ROUTE_CHASE_TURN_AND_RETREAT.md). This closes those specific targets, not every possible unsignedsecondary index. [Alignmentcontracts](SYMBOLS_ACTOR_SCENE_ONE_ROOM12_PROBES_AND_ALIGNMENT.md), [sharedsupporttrace](SYMBOLS_SHARED_BODIES.md), [route-scoreclear](SYMBOLS_ACTOR_ROUTE_SCORE_UTILITIES.md) and [signedclamp](SYMBOLS_RELATED_ACTOR_REACTIONS.md) connectthechildren. No observed actorrecovery, rayresult, game-speedchange or performancecause is claimed.
