# Bone-offset child work creation and delayed resource callbacks

Static File #1 US research, 2026-11-04. Five complete original bodies reviewed. Fields/addresses/resource IDs hexadecimal, byte counts and float constants explicit decimal. Local mechanics high confidence; model/effect interpretation probable. No target execution, attachment, build, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x57F990](../recomp/config/output_ovl/o2/o2_0057F990_0x57f990.cpp) | `request_actor_bone_offset_child_resource64_with_callback580230_candidate` | High mechanics; role probable | InputworkW24 actor mustnonnull. Select matrix indexE when category/appearance byte at recordtable+5==1,otherwise15; table=word(387E90+8*actor3),appearance=actor.unsignedHalfBBA,stride10. Rotate owned708DF8 vector by model matrix820+4*index,add its translation. Parentbasis is actor yaw;6525D0(parent,point,0,64,0,1A193,580230). No return success test. |
| [o2 0x57FAA0](../recomp/config/output_ovl/o2/o2_0057FAA0_0x57faa0.cpp) | `construct_actor_bone_offset_resource65_with_callback57fd50_candidate` | High mechanics; role probable | Same bone-index lookup as57F990, vector708E08 and child resource65. Allocates652390(65);nullignored.652E20,590760 retrieve child views;setscallback14=57FD50,queue18=373070,3=5,4=0,pos44=(computedX,0,computedZ),copiesyawbasis50,1F0=work50,flags200=1A193;652470 builds children;storesoriginal inputwork into new24. Does not store actor directly at new24. |
| [o2 0x57FC30](../recomp/config/output_ovl/o2/o2_0057FC30_0x57fc30.cpp) | `emit_child_resources66_67_from_work_matrix_and_surface_height_candidate` | High mechanics; role probable | W=a0,parent=W24. CopyW50 matrix,extracttranslation;cleartranslation then place resource66 at(extractedX+W38,extractedY+parent3C,extractedZ+W40),mask0,flags1A193 via6525C0. Identitymatrix,surfacequery616FA0(point,matrix,FF),extractsurfaceXYZ,Y+=3.0,cleartranslation,then6525C0(matrix,surfacepoint,FFFF,67,0,1A193). No parent-null/surface-success/allocation guards. |
| [o2 0x57FD50](../recomp/config/output_ovl/o2/o2_0057FD50_0x57fd50.cpp) | `update_child_resource65_delay_follow_and_detach_work_candidate` | High mechanics; role probable | W=a0,parent=W24. PrimaryW8 state0 initializes,1 processes secondaryW9 modes0..3;other states return. Delayed enable, per-child5903E0/590790 sampling, parent-height/matrix transforms, detached child update, release and clock increments below. Work24 holds original input work from57FAA0; validity/lifetime is not independently established. |
| [o2 0x580230](../recomp/config/output_ovl/o2/o2_00580230_0x580230.cpp) | `update_child_resource64_lifetime_samples_and_release_candidate` | High mechanics; role probable | PrimaryW8 state0 enables W1,ORsflags200 bit8000,savesownerresource18to1F8,copies44XYZto38XYZ,thenfallsstate1. State1 signedhalfE-=2;newnegative optionally652D60 ifflags200 bit2000 then651D00. Else each child calls6526F0(W,child,signedsampleID),storeslow8 result atF4+index,nonzero calls652CE0(W,child,15.0). Advances signedhalf10 by2. State2/other return. |

57F990/57FAA0 inputwork24 is actorA. The table387E90 and appearance-dependent matrix selection are numeric admitted paths; no character enum is assigned. Matrix indexE/15 chosen from unsigned byte5 of record(table+10*A.halfBBA). Both create yaw basis fromA.signedHalf92 using370220.1919D0 rotates fixed XYZ by selected actor model matrix;1900E0 reads that matrix translation, then adds them.57F990 forwards flags exactly1A193 to the common constructor; [resource construction](SYMBOLS_CUTSCENE_RESOURCES.md) documents its additional flag OR.57FAA0 performs its own allocation/setup path and stores exactly1A193 before652470. Allocation success/child completeness are not equivalent between the two paths.

57FD50 state0 writesW8=1,W1=0,W1F8=word(pointerW1F4+18),signedhalfC=5,half12=A, then enters secondary state processing. P=W24, K=child index, child pointer=word(W134+4*K), signed sampleID=half(W114+2*K). Primary state1 secondary modes:

| W9 | Local work |
| --- | --- |
| 0 | Decrement signedhalfC;new>=0 returns. Newnegative ->C=0,W1=1,incrementW9 (normally1),copy44XYZ to38XYZ,thenfallsmode1. |
| 1 | Decrement signedhalf12;newnegative incrementsW9 (normally2),thencontinues shared sampled-child update in the same callback. |
| 2 | If signed P.byte0==0:incrementW9 to3,W.D0=0,W.DC=0,call57FC30(W),then shared sampled-child update. Else follow-parent child update branch below. |
| 3 | If signedhalfE<0 calls652D60(W),651D00(W),returns. Otherwise shared sampled-child update. |
| Other | Return. |

Shared sampled-child update first decrements signedhalfE even for modes1/2, then iterates exactly unsigned W.byte31 children. Initializes sampled positionXYZ0,scaleXYZ1,three signedhalf rotation components0;calls5903E0(W,sampleOutputs,W.half206,sampleID-1) and590790(W,child). IfW1F0nonnull, input sampledX+=WD8,sampledY=P3C,sampledZ+=WE0 androtatesbyW1F0;otherwise output=(sampledX+WD8,sampledY+WDC,sampledZ+WE0). Childposition24/28/2C=W44XYZ+output, with extraY+40.0 in this branch. Copies four halfwords from sampled rotation area including a fourth word not explicitly initialized locally, sampledscaleXYZtochild38/3C/40;childC/10/14=1.0,1C/20=0. SignedW.half10+=2 after loop. The code checks nonnull W+114 in this branch, not the selected child pointer; no independent child-null admission is established.

Follow-parent branch in mode2 when P.byte0nonzero uses the same sample/590790/transform preparation per child and publishes childposition=W44XYZ+output, **without** extra40Y or sampledrotation/scalecopies;calls652CE0(W,child,15.0). Advances signedW.half10 by2. It does not decrement signedE on this branch. W1F0nonnull still substitutes P3C before rotation; parent here is the original input work, not the actor directly. Mode3 release can therefore depend on counters produced by independent resource setup. No owned heap or missing child is observed.

580230 does not share57FD50's secondary-mode machinery. It subtracts2 from lifetimeE before child loop and releases immediately if the stored signed result is negative. Otherwise child sampling returns are low8-tested and saved; clock10+=2. Initial primary0 immediately falls through to state1 and can release in that same invocation. It does not initialize lifetimeE itself.

57FC30 ignores616FA0's return before extracting the resulting matrix translation, so its resource67 point depends on that callee's documented output contract. The temporary matrix first starts identity; it does not reuse the resource66 basis. Resource66 Y uses parent3C while X/Z use W38/W40, an explicit mixed source retained from instructions.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Physical span | Exact float32 XYZ / SHA256 |
| --- | --- |
| 708DF8..708E03 | (0.0, -10.0, 20.0); `3fb3b5f2e144a7582ba9f93ffa60ece19d567c60f7cd9b474ea99927cbcd3c7c` |
| 708E08..708E13 | (0.0, -10.0, 25.0); `32d031ac4c5447f35c72f371f72c486fc8b1539a988a2fb58f6b176d373f3ff4` |

No visible effect name, callback frequency, renderer cost, matrix validity, release timing in seconds or slowdown causality is inferred. [Numeric actor handlers](SYMBOLS_ACTOR_NUMERIC_D9_DF_MOTION_PHASES.md) and [anchor matrix tasks](SYMBOLS_ANCHOR_MATRIX_COPY_TASKS.md) cover neighboring code without claiming these constructors are all invoked by those bodies.

Owned-word audit:5 rows,615 distinct instruction words verified,15 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
