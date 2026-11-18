# Actor pose, queue, resource-use and terminal helpers

Static File #1 US owned o2 review, 2026-11-05. Every instruction/branch/delay slot/exit in the nine listed bodies was reviewed. [Identity](FUNCTION_INDEX.md). No runtime activity, build or measurements. Addresses, offsets, flags and numeric IDs are hexadecimal; table strides are stated explicitly.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x65E4A0](../recomp/config/output_ovl/o2/o2_0065E4A0_0x65e4a0.cpp) | `integrate_actor_local_and_world_displacement_rebuild_pose_and_surface_blend_candidate` | High complete mechanics; pose role probable | Rebuilds50matrix, yaw-only forwardA8, full orientation90/92/94, transforms localD8XYZ and adds worldE4XYZ to position, consumes both deltas,6657B0surface-orientation update, commits matrix translation. Full order below. |
| [o2 0x65E5C0](../recomp/config/output_ovl/o2/o2_0065E5C0_0x65e5c0.cpp) | `enqueue_actor_tag1_with_class_and_locality_selected_tag0_or3_candidate` | High complete queue admission; consumer unknown | Signed4BADF8==1 or54Abit4 skips. Otherwise selects5DA620(actor,1,0/3) by session/locality/class policy below. Does not allocate an effect itself. |
| [o2 0x65E670](../recomp/config/output_ovl/o2/o2_0065E670_0x65e670.cpp) | `snapshot_actor_four_component_parameter_and_advance_cb2_blend_candidate` | High complete mechanics; parameter meaning unknown | Copies1AC..1B8 to1BC..1C8 everycall. NonzeroCB2 decrements; remaining nonzero addsCC8XYZ to first three components; reachingzero copies allfour fromCB8pointer. No pointer check. |
| [o2 0x65E750](../recomp/config/output_ovl/o2/o2_0065E750_0x65e750.cpp) | `apply_resource_quantity_policy_refresh_depletion_and_mark_local_use_candidate` | High complete mechanics; resource taxonomy partial | Low8IDzero returns0. Calls5B1F30(ID,actor), preserves signedlow8 result; authority counters and result0/2/3 handling below. |
| [o2 0x65E880](../recomp/config/output_ovl/o2/o2_0065E880_0x65e880.cpp) | `dispatch_actor_selected_resource_use_transform_effect_and_action_variants_candidate` | High complete branch/call contract; effect names partial | Class-tablebit10 and active instance required. Builds instance-relative position/two matrices, branches on action8==5 versus ordinary use; resource flags20000/800 govern effects and callbacks. Full sequence below. |
| [o2 0x65EC40](../recomp/config/output_ovl/o2/o2_0065EC40_0x65ec40.cpp) | `dispatch_current_resource_use_by_actor_class_locality_and_eligibility_candidate` | High complete mechanics | ClearsBA0bit80000000; zeroC7C returns. Localclass0,remoteclass0,class1 andotherclass dispatch preserve distinct eligibility/quantity/effect ordering below. |
| [o2 0x65FBA0](../recomp/config/output_ovl/o2/o2_0065FBA0_0x65fba0.cpp) | `select_terminal_or_recovery_action_from_ba0_and_actor143_flags_candidate` | High complete mechanics; original flags unknown | a0actor,a1requestedphase. BA0bit800 or143bit8 chooses action4/0/phase/0 and cleanup; otherwise action1/60/phase/0 with status masks. Publishes both; doesnotitselfsethealthzero. |
| [o2 0x666620](../recomp/config/output_ovl/o2/o2_00666620_0x666620.cpp) | `clear_actor_ba0_bit_80000` | Confirmed complete narrow field operation; bit meaning unknown | BA0 &= FFF7FFFF, including delay-slot store. No conditions, callbacks or normalized return. This is a specific field operation, not a generic unknown no-op. |
| [o2 0x666D90](../recomp/config/output_ovl/o2/o2_00666D90_0x666d90.cpp) | `clear_nonnull_class_zero_actor_d28_word` | Confirmed complete narrow field operation; D28 meaning unknown | Nullactor returns; nonzero byte2 returns; otherwise D28=0. Both branch exits reviewed; does not clear other actor classes. |

## Pose and queue contracts

65E4A0 calls18FDF0(actor50) and18FDF0(localmatrix),370320(0,yaw92,0,localmatrix), then1919D0(actorA8,(0,0,1),localmatrix). Calls370220(pitch90,yaw92,roll94,actor50), transforms actorD8XYZ through1919D0 into localdelta, and computes position componentwise as `oldPosition + (transformedLocalDelta + worldE4Delta)` preserving addition order. ZerosD8/DC/E0 andE4/E8/EC, calls6657B0, then writes currentXYZ into matrix50 translation30/34/38. It does not consume root4E4XYZ or multiply by wall time. [Surface blend contract](SYMBOLS_ACTOR_REMOTE_TARGET_SURFACE_ORIENTATION.md) establishes6657B0's conditional floor sampling and orientation blend.

65E5C0 skips when signed4BADF8==1 or half54Abit4. If1B02D0()==0 and class0 and own3 != local4BADED, enqueue(actor,tag1,tag0) and return. Otherwise class1 enqueues tag1/tag0; everyotherclass enqueues tag1/tag3. [Tagged queue](SYMBOLS_MODEL_WORK_INITIALIZATION_AND_TAGGED_QUEUE.md) establishes5DA620's bounded32-record append; queue-full behavior and possible stale return are inherited. No renderer/effect consumer is inferred from these numeric tags.

65E670 snapshot precedes decrement/add/copy. CB2==0 performs only the snapshot. CB2==1 copies four target components immediately after decrement; CB2>1 adds only the firstthree, leaving1B8 unchanged until the final target copy. No interpolation fraction or clock scaling is computed here; setup/cadence and the four components' meaning remain separate questions.

## Quantity and dispatch contracts

65E750 tests low8 suppliedID but forwards the original a1 as5B1F30's first argument. Captures signedlow8 resultR. If1B0340(actor)==1 andR!=0: byte3B84F5=1; resource action-class record719A60+68decimal*unsignedhalfCA8 word0bit10 increments word3B84BC. These writes precede R-specific cleanup and are not proof that a visual/audio effect completed. R3 returns3 immediately. R0 calls1B8C70(actor,1), returns0. R2 calls5F2120(actor,currentC7C), clearsC7C, calls5F1F70(actor)->CA8, then5F2330(actor), returns2. R1 and other nonzero signed results returnR without this depletion cleanup.

65EC40 first clearsBA0bit80000000 even whenC7C==0. With nonzeroID:

- Class0 with own3==local4BADED:65E750(actor,ID); nonzero invokes65E880(actor,originalID),zero returns.
- Otherclass0: check word3C5648+60decimal*ID bit40; set requests1B8C70(actor,1) andreturns; clear invokes65E880 directly, without local5B1F30 quantity operation.
- Class1: signedlow8 5B2770(ID,actor)==0 requests1B8C70(actor,1); result1 invokes65E750 then65E880 only if nonzero; otherresults invoke65E880 directly.
- Otherclasses:65E880 directly.

OriginalID remains the value passed to65E880 even when65E750 clearedC7C. [Quantity policy](SYMBOLS_INVENTORY_REQUEST_APPLICATION.md) establishes5B1F30's ownership/quantity/depletion classifications; [eligibility](SYMBOLS_RESOURCE_EFFECTS_AUX_LISTS.md) establishes5B2770's priority checks. No result is recast as a universal success Boolean.

## Complete65E880 effect/action path

Let C=unsignedhalfCA8, classrecordK=719A60+68decimal*C, ID=low8supplieda1, instanceP=word(3C564C+60decimal*ID). Zero a 12-byte stack vector. K.word0bit10clear or Pnull returns immediately. Call665CA0(actor,5). PositionQ=1919D0(K+38,P+1C0)+P.translation200/204/208. Build matrixM:identity,1901A0(M,binary32constant740488),190100(M,740480),1913E0(M,P+1C0). Build matrixN:identity then191500(N,M). SaveQ into workingR. This states exact helper order and inputs; it doesnotassertcommutativity or a guessed camera convention.

Action8==5: Czero or K.bit800clear returns **after** preparation/665CA0. Otherwise1B8C70(actor,0); ifK.bit20000clear call6B24F0(actor,P+200),5DD270(actor,M,Q,K.byte7),58E6D0(actor,P+1C0,C-1), inthatorder. Always6B4420(actor,0) afterward,includingbit20000set. No ordinary5823E0 call here.

Action8!=5: load distance from binary32 table71AE80+32decimal*K.byte5+4*actorB98; zero vector with only Z=distance, transformbyN using191A40, addtoR. Call5823E0(actor,N,R,**originalsupplieda1**,nottruncatedID), then1B8C70(actor,0). IfK.bit20000set skip directlyto6B4420(actor,0). Otherwise6B24F0(actor,P+200); unless C==0C(hex),58E6D0(actor,P+1C0,C-1). Only whenaction8==2 andsecondary9 in{2,C} andB==0 additionally5DD270(actor,M,Q,K.byte7). Finally6B4420(actor,0).

The function rereadsCA8/record fields after callbacks at the original sites; K notation abbreviates address calculation and doesnotasserta cached immutable snapshot. Neither CA8 nor actorB98/tablebyte5 are locally bounded. Pmatrix/translation lifetime is assumed after the nonnull check. Numeric child calls retain unresolved effect names rather than supplying invented weapon/projectile labels.

Owned740488[4]=`db0fc9bf`,binary32 -1.5707963705062866,SHA-256 `cfa13f564435274e8f7b199d047d4555d36b5e6f462504e133ec3c98fef7fc4f`;740480[4]=`db0fc93f`,binary32 1.5707963705062866,SHA-256 `ffe8a9dbe92ed9fa0338c87ae9707c16511c68059475793054e2d246bddead75`. Dynamic record/table indexes are recorded above; their global admission ranges are not inferred from a bounded literal sample.

## Terminal/recovery selector65FBA0

BA0bit800 set or actor143bit8 set: BA0 OR40000800,5F6800(actor,0),54F=A0,action4/0/low8a1/0,snapshot667370,publish67E230(actor,1),then5F6800(actor,0) **again**. Both cleanup calls are retained. Otherwise BA0 &= FFFFFF57,thenOR18;action1/60/low8a1/0,snapshot,publish. The requested phase is captured before any childcall. No health544write, game-clock advance or return normalization is present. [Paired terminal caller](SYMBOLS_ACTOR_PAIRED_INTERPOLATED_POSITION_YAW_AND_HEALTH_VARIANTS.md) supplies one caller context; original flag/phase names remain unknown.

These complete static contracts are mapping evidence, not observed actions or performance diagnoses. Exact original names, total call frequency and hot-path costs remain unmeasured.
