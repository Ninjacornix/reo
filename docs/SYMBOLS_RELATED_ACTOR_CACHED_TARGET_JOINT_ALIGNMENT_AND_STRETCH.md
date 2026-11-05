# Related actor cached target joint alignment and triangular stretch

Static File #1 US owned o2 analysis, 2026-11-05. One complete240-word body, including its original tail past5B0000. [Identity](FUNCTION_INDEX.md). Scope ownership follows function start5AFCF0. Offsets hexadecimal; no pose/game execution, model inspection or performance measurement.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5AFCF0](../recomp/config/output_ovl/o2/o2_005AFCF0_0x5afcf0.cpp) | `animate_related_actor_toward_cached_target_joint_with_yaw_local_quaternion_and_frame_stretch_candidate` | Confirmed full initialization, quaternion path, target decisions and scale curve | Target24nonnullrequired. PhaseA0->1 selectsrelatedmotion5/frame0,58C7B0. Cachetargetjointmodel34->870translation intoC44/C48/C4C. SetvelocityC0=(selfX-cachedX)/38decimal*globalunsigned74F200,C4=0,C8=(selfZ-cachedZ)/38*74F200. Measureownmodeljoint858translationJ;distanceD=191D10(J,cachedTarget). KeepD iforderedD<=300decimal,elseD=300. C40=D/(J.Y-cachedTarget.Y),unguarded. B1E=0,clear115bit1,attachcontactdescriptor3F/bank1,return. Phase1 advancesmotion,mayselectfollowup,thenupdatesjointorientationandscaleasbelow. Otherphasesreturn. No original authored animation/actor name inferred. |

Phase1 animationstep=float7290F8[12decimal*BA1]. Signedlow8 58C300 result>0 calls5B0B00 thencontinues. Otherwise ifB1E==1 and5AA0C0(actor)!=0, calls5B0CD0(actor,2,2) thencontinues. The target variableS1 is captured atentry but phase1 uses cachedC44 forjointalignment; a successful5AA0C0 canreplace24 without refreshingcachedpoint. This is explicit cache behavior,not proof of faultytargeting.

Readcurrentownjoint858 worldtranslationJ. VectorV=C44XYZ-J through370420. IfallXYZexactzero, skiporientation;else rotateV inXZ by ((-signedyaw92)&FFFF)*owned2pi/65536,normalize191D80,then5A8220(ownedDown,V,quaternion),192250(quaternion,matrix),1913E0(ownjoint858+40,matrix). Basiscomposition preservesoriginal localmatrixW/translation accordingtohelper; no zero-vector division occurs after the exactzerogate on finitevectors, but otherdegenerate/nonfiniteadmission remains unproved.

Afterorientation, if currentmotionframe1E4 is notordered<40decimal, cachedC44XYZ+=velocityC0XYZ. Thus frame40 startsdriftingthecachedtarget oncepercall, notperelapsedframecount; step-scaledanimation and cachemotion are distinctoperations. OwnworldXYZ38 is notwrittenbythisbody.

IfC40 exactly1, skipstretch. Else letF=currentframe1E4,S=C40. FororderedF<=36decimal, Zscale=1+(S-1)*F/36;otherwiseZscale=S-(S-1)*(F-36)/36. DivideZscale byownscaleBC,then18FFE0(ownmodeljoint890+40,1,1,Zscale). No clampofF orresult, nozeroheight/BCguard, and noassumptionthatanimationneveradvancesbeyond72. Scaleappliesafterfollowupstatechanges, preservingoriginalsequencing.

Owned709EA0[12] downvector(0,-1,0), SHA-256 `8ba4ff0e2bc29c816d60e0bb02875011798578207f6cbf661c1438c6159f1324`. Owned73E4E0 float6.2831854820251465, SHA-256 `12d85026b5109a3119231704608d5991a63d8d397d2867a9fc522305810ddb76`.

[Related actor transitions/pitch helper](SYMBOLS_RELATED_ACTOR_REACTIONS.md), [target-admission behavior](SYMBOLS_ACTOR_5AA160_PRIMARY_ONE.md), [quaternion construction](SYMBOLS_ACTOR_MODEL_STATE_HELPERS.md), [matrix/quaternion math](SYMBOLS_RENDER_MATH.md), [vector subtraction](SYMBOLS_OVERLAY_MATH.md) and [contact packet attachment](SYMBOLS_LINKED_VISUAL_DESCRIPTOR_POOL_AND_ATTACHMENT.md) establish connectedmechanics. Runtimejointnames, resourceadmission andperformancecostremainunknown. No enginefix ornativebehaviorchangehasbeenmade.
