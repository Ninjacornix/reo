# Transient scene light constructors, surface tags and ownership

Static File #1 US owned o2 analysis, 2026-11-05. Five complete bodies and owned52-byte payloads. [Identity](FUNCTION_INDEX.md). Offsets hexadecimal. No lighting, allocations, game or process executed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B24F0](../recomp/config/output_ovl/o2/o2_006B24F0_0x6b24f0.cpp) | `construct_positioned_dual_pool_transient_light_using_actor_surface_candidate` | Confirmed full constructor and callback binding; asset names unknown | a0actor,a1XYZ. Copy52B720240tostack,overwritepayload20XYZ.573890(NULL,5D83D0) failurestops. Successallocates6B3090(payload,actor175,0)->task28 then6B2CC0(payload,actor175)->task24,independentlyincludingNULL. Taskcallbackownsboundedfades/releases;nochildallocationrollbackorstaterecordedsuccessstatus. |
| [o2 0x6B25B0](../recomp/config/output_ovl/o2/o2_006B25B0_0x6b25b0.cpp) | `construct_dual_pool_white_transient_light_from_point_surface_query_candidate` | Confirmed full constructor and callback binding; asset names unknown | a0XYZ. Copy52B720280,overwrite20XYZ,allocate573890(NULL,5D83D0). Success616F60(XYZ,&surface,FF),heightreturnunused;independent6B3090(payload,surface,0)->28 and6B2CC0(payload,surface)->24. SurfaceFFisnotrejected;nochildsuccessgate. Separatebody/payloadaddressfrom6B24F0evenwhentemplatebytesmatch. |
| [o2 0x6B2680](../recomp/config/output_ovl/o2/o2_006B2680_0x6b2680.cpp) | `construct_action_two_substate_b_bound_orange_primary_light_candidate` | Confirmed full constructor and callback binding; asset names unknown | a0owner,a1XYZ. Copy52B7202C0. NONNULLowner requiresstate8==2AND9==B,elsestop. NULLpassesadmission. Allocate573890(NULL,5D85E0) afteroverwriting20XYZ;successreadsowner175withoutanotherNULLguard,allocates6B3090(payload,tag,0)->28,storesowner->24. Thus permittedNULLadmissiondoesnotestablishaNULLsafeconstructor;nosuccessfulNULLcaseorcrashwasobserved. Callback5D85E0retainsconditionalownerlifetimerules. |
| [o2 0x6B2760](../recomp/config/output_ovl/o2/o2_006B2760_0x6b2760.cpp) | `construct_actor_surface_tagged_orange_primary_light_with_ungated_curve_callback_candidate` | Confirmed full constructor and callback binding; asset names unknown | a0owner,a1XYZ. Copy52B720300,overwrite20XYZ,573890(NULL,5D8620);success6B3090(payload,owner175,0)->28,owner->24. NoownerNULL,stateoractivitygate.5D8620tails5D8630withoutcheckingownerstate,distinctfrom6B2680despitematchingtemplatebytes. |
| [o2 0x6B2810](../recomp/config/output_ovl/o2/o2_006B2810_0x6b2810.cpp) | `construct_dual_pool_blue_tinted_transient_light_from_surface_query_candidate` | Confirmed full constructor and callback binding; asset names unknown | a0XYZ. Copy52B720340,overwrite20XYZ,allocate573890(NULL,5D83D0). Successqueries616F60(XYZ,&surface,FF),thenprimary6B3090(...,surface,0)->28,auxiliary6B2CC0(...,surface)->24independently. No surface/admission,childfailurecleanuporGPUcompletiontest. |

Owned52B templates allhavezero fieldsC..28 beforecallerXYZoverwrite20. Theknownfloattriples0/4/8,floats2C/30 are:

| Owned addresses | RGB-like coefficients | 2C | 30 | SHA-256 |
| --- | --- | --- | --- | --- |
|720240,720280|(1,1,1)|.001|700|`1507c6c62bd7ef8d60a82b03413edc2598b593d854dc7b1e359474be46cc9b49`|
|7202C0,720300|(1,.5,0)|.05|150|`03e9cda8ccd43b532c8a36c5335c2301758af65b531424c740c03a8d1d78b962`|
|720340|(.7,.7,1)|.001|700|`f4e91f3dfca7deb1c923d44c5c6c95f88f9b6f14aba755216a22d03035e22122`|

Actualbinary32valuesarepreservedinownedbytes. TheseareLIG-linkedlightworkcoefficients,notparticlevelocity. 2Cisusedasdistanceattenuationfactorby6B3100;30hasfurtherconsumersemanticsoutsidejustthisconstructor.

[Light pool allocation](SYMBOLS_LIG_FOG_CONSUMERS_AND_WORK.md), [dual-pool fade and release](SYMBOLS_MODEL_SLOT_STATE.md), [owner-gated versus direct curve callbacks](SYMBOLS_MOTION_TIME_REMAP_AND_TRANSIENT_STYLE_CURVES.md), [actor resource use](SYMBOLS_ACTOR_POSE_QUEUE_RESOURCE_USE_AND_TERMINAL_HELPERS.md) and [type14 effect cloud](SYMBOLS_ACTOR_VARIANT_E_UPDATE.md) establish connecteduse. White/orange/blue names describeexplicitcoefficienttriplesonly. Allocation is bounded by existingpools, but noactivecount,rendercostorfrequencywasmeasured.
