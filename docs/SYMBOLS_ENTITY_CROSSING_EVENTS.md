# Entity callback dispatch and crossing-gated event adapters

Static File #1 US research, 2026-11-04. All named bodies reviewed in full,
including callback routing, side effects and branch delay slots. No game, build,
replay, attachment or live-memory inspection. Numbers are hexadecimal except
explicit counts and scale vectors. Existing573480 crossing semantics from
[task flags](SYMBOLS_TASK_FLAGS.md) are reused: these are original animation
window tests, not global-update counts or wall-clock comparisons.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5A8FD0](../recomp/config/output_ovl/o2/o2_005A8FD0_0x5a8fd0.cpp) | `dispatch_twenty_three_active_entity_category_callbacks_candidate` | Probable role; full body reviewed | Requires signedentitybyte1!=0. Unsignedcategory3 routes23explicitvalues;fulltablebelow. Unknowncategoriesreturnwithoutwork. Category0allowed;activebyte0notchecked. Callerv0notnormalizedtoBoolean andnoadditionalstatewrites. Category-specific mechanics remain ineachcallee. |
| [o2 0x5A92E0](../recomp/config/output_ovl/o2/o2_005A92E0_0x5a92e0.cpp) | `crossing_gated_actor_audio_variant_with_global_parity_or_rng_candidate` | Probable role; full body reviewed | a0 integerframe,a1 actor,a2 baseaudio,a3 variantcount,f12 animationstep. Convertsframef12,originalstepf13;573480(actor,bank0,targetFrame,step) gatesallwork. Variantcount0 usesbase;1 adds4BADE8&1;otherfullcount addsRNG(1)low16%count.1B9310(actor,id,0). Count1isparitycase,notrangeofone. |
| [o2 0x5A93A0](../recomp/config/output_ovl/o2/o2_005A93A0_0x5a93a0.cpp) | `crossing_gated_actor_audio_by_predicate_and_global_bit_candidate` | Probable role; full body reviewed | Sameframe/actor/stepcontract. On573480bank0crossing,1B9090(actor)nonzerochoosesoriginala2,zerooriginala3. t0nonzero additionally4BADE8 bit2adds1. Calls1B9310(actor,id,0). Doesnotadvanceanimationorinspectcallbackfrequency. |
| [o2 0x5A9440](../recomp/config/output_ovl/o2/o2_005A9440_0x5a9440.cpp) | `crossing_gated_five_kind_node_surface_effect_router_candidate` | Probable role; full body reviewed | a0 frame,a1 actor,a2 kind,t0 node;originala3unused. 573480bank0gate. Kind0 nodeMatrixTranslation->5DF820.1/2->5EA0D0(nodeXYZ,scale(3,3,3),selector0/1).3->5EA180(actor,node,0,scale3,0,1).4 uses scale2,selector1,cyclesactorC37low3 throughowned8 signedjitterbytes709BA0;before5EA0D0 overwritesnodeXYZ.X=actorX+jitter anddoesnotrestoreit. Otherkindsnoop. Surfacehelperallocationcontracts preserved; routingdoesnotproveeffectsuccess. |
| [o2 0x5A9620](../recomp/config/output_ovl/o2/o2_005A9620_0x5a9620.cpp) | `crossing_gated_spawn_from_actor_pose_and_fixed_local_offset_candidate` | Probable role; full body reviewed | On573480bank0crossing copies64-byte actor50matrix,transformsowned7290B0 vector(0,100,90) via1919D0,addsactorXYZ,andcalls582720(actor,matrix,worldXYZ,actorAngles90,0,0). No newslotbindingorpersistentmatrixwrites. Effect/objectsemanticof582720remainscandidate. |
| [o2 0x5A96F0](../recomp/config/output_ovl/o2/o2_005A96F0_0x5a96f0.cpp) | `crossing_gated_collision_flag_and_descriptor_update_candidate` | Probable role; full body reviewed | Oncrossing interprets signedlow8(originala2). Mode0clearsENTIREactor115byte,calls5DA2C0(actor,unsignedlowa3,1),returns1. Mode2ORs115bit1butreturns0. Othermodes/missedcrossingreturn0. Returnisnotgenericcrossingsuccessflag; twoadmittedmodesdiffer. |
| [o2 0x5A97A0](../recomp/config/output_ovl/o2/o2_005A97A0_0x5a97a0.cpp) | `crossing_gated_actor_action_from_saved_abb_byte_candidate` | Probable role; full body reviewed | Same573480bank0frame/stepgate;success570260(actor,unsignedbyteABB). NoRNG,nodequeryorlocalactionwriteoutsidecallee. |
| [o2 0x5A97F0](../recomp/config/output_ovl/o2/o2_005A97F0_0x5a97f0.cpp) | `crossing_gated_descriptor_update_excluding_actions3_and4_candidate` | Probable role; full body reviewed | On573480bank0crossing, actoraction8in3/4rejects;others5DA2C0(actor,unsignedlowa2,1). Doesnotclear115likemode0of5A96F0. |
| [o2 0x5A9860](../recomp/config/output_ovl/o2/o2_005A9860_0x5a9860.cpp) | `crossing_gated_position_audio_with_optional_random_range_candidate` | Probable role; full body reviewed | a0 frame,a1 actorforcrossing,a2 explicitposition,a3 baseaudio,t0 count,f12 step. On573480bank0crossing, signedfullcount<2usesbase;>=2addsRNG(1)low16%count.1B8930(explicitposition,id). Positionisoriginala2,notimplicitlyactorXYZ. |

Owned/static dispatcher5A8FD0 branches:

| Category | Target |
| --- | --- |
| 0 | 0x651350 |
| 1 | 0x685530 |
| 2 | 0x6509A0 |
| 4 | 0x6C4550 |
| 5 | 0x633030 |
| 6 | 0x6CBF60 |
| 7 | 0x6D3E80 |
| 9 | 0x615C30 |
| A | 0x5AF340 |
| 12 | 0x67D440 |
| 13 | 0x6C1610 |
| 14 | 0x61C130 |
| 16 | 0x60B600 |
| 17 | 0x619A70 |
| 1A | 0x6CE420 |
| 1B | 0x6C3280 |
| 1D | 0x67CE70 |
| 1E | 0x624EF0 |
| 24 | 0x65DCB0 |
| 29 | 0x5E07F0 |
| 2B | 0x6F8900 |
| 37 | 0x61BD70 |
| 3B | 0x6EDD60 |

Node-coordinate overwrite in5A9440 kind4 is an observed original-instruction side effect,
not a proved visual defect. Effect failures and surface admission remain callee
contracts. No claim that any callback caused a recorded slowdown.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
