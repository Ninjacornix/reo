# Scripted actor node blending, motion and reaction control

Static File #1 US owned o2 analysis, 2026-11-05. Seven full original bodies. [Identity](FUNCTION_INDEX.md). No game execution, builds, attachment or live reads. Fields/masks/states hexadecimal. Scripted interpretation follows the B3C request fields and selected callback; original scene/action names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x67BC90](../recomp/config/output_ovl/o2/o2_0067BC90_0x67bc90.cpp) | `consume_scripted_motion_request_sequence_node_offsets_and_apply_counted_local_displacement` | Confirmed complete flags/timer/motion composition | B3Cbit2 setssecondary9=23,clearsbit2,B42/A/B0. SignedB41==0 ORs54A8. Servicesfirstnonzero signedtimerB64,B66,B68 only:5D6D00(actor,oldtimer,mode0/1/2),timer--;newexact0 setsC50=nexttimer or0afterlast. ThennonzeroB78 rotateslocal(0,0,B70)withanglesB6C/B6E/roll0,addsXYZ,yaw+=B74,B78--;new0clearswordB74,halvesB6C/B6E,floatB70=0. Negativecountersarenotpositivelyboundedlocally. No animationadvance,matrixcommit,gameclockornewmodelallocation. |
| [o2 0x67BE60](../recomp/config/output_ovl/o2/o2_0067BE60_0x67be60.cpp) | `service_scripted_motion_callback_only_for_secondary23` | Confirmed complete dispatch adapter | Unsignedsecondary9==23calls67BFF0(actor);othersecondaryreturns. No primary/class/activitygate. |
| [o2 0x67BF90](../recomp/config/output_ovl/o2/o2_0067BF90_0x67bf90.cpp) | `select_scripted_animation_tick_factor_one_or_half_from_b40` | Confirmed complete numeric selection and callsite role | SignedB40==0returnsfloat1,anynonzero returns.5. No mutation.67BFF0passesresultf12to5D2240motionadvance. |
| [o2 0x67BFC0](../recomp/config/output_ovl/o2/o2_0067BFC0_0x67bfc0.cpp) | `select_scripted_blend_duration_factor_one_or_two_from_b40` | Confirmed numeric selection; corrected downstream role | SignedB40==0returnsfloat1,anynonzero returns2.67BFF0multipliesblenddurationB44byresultbefore5D1F20configuration.5D1F20savesincomingf12asdurationandstartsselectedmotionatframe0. Doesnotitselfselectresourcepoolorchangegamespeed. |
| [o2 0x67BFF0](../recomp/config/output_ovl/o2/o2_0067BFF0_0x67bff0.cpp) | `initialize_or_advance_scripted_actor_motion_and_apply_pending_track_two_motion` | Confirmed full phase/resource/frame/track policy | Everycall54AOR17. A0->1,54F=14,BA8=float1,resource514=4BC810onlyif signedB40==1else4E8970;clearsroot4E4XYZ.5D1F20(actor,signedB43,f12=B44*67BFC0factor,f13inherited),activate. A1advances5D2240at67BF90factor;otherphasesnoanimationwork. IndependentlysignedB7C!=0and54D!=1 calls58B9A0(actor,resource4BBB80,motionB7C,track2,start0,blend0),thenclearsB7C. No uppertrackcount/nullguardorB40normalization;resourcechoice==1differsfromfactorchoice!=0. |
| [o2 0x67C100](../recomp/config/output_ovl/o2/o2_0067C100_0x67c100.cpp) | `consume_scripted_reaction_request_or_cache_model_node_turn_angles` | Confirmed full request/pending-state and angle conversion;6613A0policyseparate | B3Cbit4clearedonadmission. B48==2calls6613A0(actor,0)andreturns. OtherwiseB60==0clearsBD1/BD2,setsB60=-1,calls6613A0(actor,4),returns. CommonB60nonzero: -1calls6613A0(actor,4);othervalueclearsBD1/BD2,calls6613A0(actor,4),thenB60=-1. B60zero derivesBD8/BDA=low16(guestcvt.w.s(.5+65536*nodefloat110/114/owned2pi)),node=actor34->874. No healthdeltaor6613A0internalmeaninginferredhere. |
| [o2 0x67CE00](../recomp/config/output_ovl/o2/o2_0067CE00_0x67ce00.cpp) | `refresh_scripted_actor_up_alignment_and_commit_local_world_motion` | Confirmed complete alignment/delta wrapper | Primary1/secondaryFfirstcopiesXYZtomatrixtranslation80/84/88. Always5A82A0(outD18,inputD00,signedBA3),then67CD00consumeslocal/worlddeltasandcommitsmatrix. No animationtick,collisiontraceortimerupdate. Fullbodyreviewedseparatelyfromsimilar65DB40. |

[Nodeoffsetinterpolation](SYMBOLS_CUTSCENE_RESOURCES.md), [motionconfiguration](SYMBOLS_CUTSCENE_RESOURCES.md), [VU/vectorcontracts](SYMBOLS_RENDER_MATH.md), [up-alignment](SYMBOLS_ACTOR_MODEL_STATE_HELPERS.md) and [matrixcommit](SYMBOLS_SHARED_BODIES.md) connectchildroles.5D6D00interpolatespairedmodel-nodeYoffsetswhenits54D/globalmodegatesadmit;itdoesnotchangetheglobalgameclock.5D2240advancesmotionswithtemporarynode-trackIDs,notarenderpresentcounter. Owned740630[4]2pi=`db0fc940`,SHA-256 `12d85026b5109a3119231704608d5991a63d8d397d2867a9fc522305810ddb76`.

The earlier initial-frame label for B44 was wrong. Full downstream5D1F20
stores incoming f12 in f20 at5D1F68, writes zero to f12 at5D1FB4/5D20B4/
5D214C, and passes f20 as f13 blend duration at5D1FBC/5D20C4/5D215C.
Its BA4 mask2 branch forces that duration to zero. The caller's inherited f13
does not establish a separate input to this configuration wrapper.

Blend-duration and tick factors retain the original scripted motion policy.
This mapping does not establish actual script frequency, scene identity or
rendering cost.
