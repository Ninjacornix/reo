# Complete actor655560 update and initialization

Static File #1 US owned o2 analysis, 2026-11-05. Entire655560..6558B3 and6558C0..655D3B reviewed including all branches, indirecttable, delay slots and returns. [Identity](FUNCTION_INDEX.md). No runtime/build/measurements. Numericstates/offsets/flagshexadecimal;floatvaluesdecimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x655560](../recomp/config/output_ovl/o2/o2_00655560_0x655560.cpp) | `update_actor_655560_full_state_root_motion_contact_surface_and_model_pipeline_candidate` | High complete local update contract; original actor name unknown | Posehistory/reset,relatedmetrics,contactresponse,primarytable012345,rootmotion,visibility/pitch,queuedwork,jointslots,surfaceadmission,posecommitandconditional1.3nodescaling. Allorderedgatesbelow. |
| [o2 0x6558C0](../recomp/config/output_ovl/o2/o2_006558C0_0x6558c0.cpp) | `initialize_actor_655560_variant_resources_bounds_support_and_entry_state_candidate` | High complete initialization; original variant names unknown | BBA0/1/otherselectthreepointer/payloadgroups;scene1room12overridesbounds;BA3supportadmission;C2B/runtimeflag/basestatepriority;ends65D5A0. Completefieldsbelow. |

## Fullupdate655560

1. D28=170;saveXYZto44XYZandfouranglehalves90..96toA0..A6. Set54A=10,clearBA5/C82/32/C36,C94clearbit100. Nonnullrelated24:5A9F80(actor,related)resultBD4,then65DA50(actor,relatedXYZ)-ownyaw->BD8lowhalf. NullrelatedretainsoldBD4/BD8.640210ticksC2Eunderitsglobaltickgate.
2. Pending13F:65AED0. Lowbyte0skipsfollowup;1calls65AC40then5A6B20(actor,2);othernonzeroonly5A6B20(actor,2). Thusreactionreturn2doesnotreseed65AC40.
3. Health<=0orC37!=0:C94OR301. OtherwiseC94clear201. SaveBA3toC29. Dispatchword7124E0+4*unsignedprimary8(actor),withoutlocalbound. Reviewedprefixsixcallbacks:0=6558C0,1=655D40,2=6577A0,3=658530,4=658DA0,5=659380. Theircompletefamilynotesarelinkedbelow;higherindexadmissionunknown.
4. C82==0calls65B250roottransform;nonzeroclearsC0XYZ. Set553=(C37==0).65C780pitch,65CA00visibilitytimer. BA3==1sets54Abit4;6347D0conditionalqueue.5A7D00(actor,7125D0,actorCD8)ticksjointresponseslots. BA3nonzerosetsBA5=1.
5. Onlyprimary1,secondary in{2,6,7,A,B,10},A!=0:BA3==0calls65B560forwardflaggedsurface;BA3==1calls65B8B0supporttransition;otherBA3skips. Thesechildrencanchangeprimary/secondary/phase,whicharefreshlyreadnext.
6. SecondaryFskipsnextposecommitregardlessofprimary. OtherwiseBA3==2alsoskips. BA3==1clampsYupwardonlywhenY<D28+50*BC,thencalls65B460;otherBA3calls65B460withoutthisfloorclamp. Noadditionalroottransformhere.
7. Always5A6B20(actor,signedbyteC36). Ifscene3243DA!=6,health>0,BBA==0:18FFB0(modelnode8C4.matrix40,owned1.3),then18FFB0(node8C8.matrix40,same). Allothercasesreturn. No nodeNULLguardsorindependentanimationtickinthisroot.

Completechildcontracts:[base/initialmotion](SYMBOLS_ACTOR_655D40_BASE_STATES_AND_MOTION_TRANSITIONS.md), [route/chase](SYMBOLS_ACTOR_655D40_ROUTE_CHASE_TURN_AND_RETREAT.md), [remainingbasephases](SYMBOLS_ACTOR_655D40_RECOVERY_ALIGNMENT_AND_OBSTACLE_HEADING.md), [primary2/3dispatch](SYMBOLS_ACTOR_6577A0_AND_658530_DISPATCH.md), [recovery4](SYMBOLS_ACTOR_658DA0_RECOVERY_STATUS_AND_TIMED_FADE.md), [reentry5](SYMBOLS_ACTOR_659380_SURFACE_REENTRY_AND_RELOCATION.md), [contact/rootmotion/surface](SYMBOLS_ACTOR_65A_CONTACT_REACTION_ROOT_MOTION_AND_SURFACE_ADMISSION.md), [three-tracesupport](SYMBOLS_ACTOR_SUPPORT_TRANSITION_THREE_SEGMENT_REFINEMENT_65B8B0.md), [pitch/visibility](SYMBOLS_ACTOR_FORWARD_PITCH_VISIBILITY_TIMER_AND_LATERAL_PROBES.md). 5A7D00slotsemanticsand18FFB0basis-onlyscalingare[alreadyreviewed](SYMBOLS_ACTOR_MODEL_STATE_HELPERS.md)and[render-mathreviewed](SYMBOLS_RENDER_MATH.md).

## Initializer6558C0

370320(actor90,92,94,actor50);render1=1,553=1,F0=1.0,C80=0,520=-1. Variantindexv=(BBA==0?0:BBA==1?1:2). actor1A8=word7127D8[4*v],1D8=word712890[4*v]. P=word7128D0[4*v];copyfourfloatstoC70..C7C,thento1AC..1B8,thento1BC..1C8. Thesearefamily-specificfourcomponentpayloadcopies;C7Cisnotinterpretedhereasaselecteditem.

C94OR4thenOR201;190=20FFFF,194=0,551=3,552=19,CE8=0,CFC=0,BBC=180.0,BC0=700.0;zero4bytesBE8and8bytesC..13,C38=0;timer12=600/unsignedbyte74F200(noguard). Ifscene3243DA==1androom3243DC==12:replacefourcomponentpayloadfromword7128DC,repeatallthreecopies,C94clearC0,C39=1. ElseC94ORC0,C39=0. BDA=16C,BDC=2D8.

BA3==1:65C500(actor,&D00,&D0C)successcalls5A82A0(D18,D00,signedBA3),setsXYZ=D0C+D00. FailureclearsBA3but**doesnotlocallyresetD00**. BA3!=1setsD00=(0,1,0). Always616F20(XYZ,&type,FF)->D28;returnedtypeignored.

Entrypriority:

- C2B!=0:action5/(C2B-1)/0/0,render1=0.
- Elsebyte74F295+96decimal*B98mask3nonzero:clearbyte74F270+96*B98,BA3=0,action4/3/5/0. Originalflag74F295retained.
- Elseaction1/0/0/0;health<=0restoreshealth544=maximum546;65AC40(actor),C36=7.

Allthreebranchesfinally65D5A0(actor),thenreturn. No667370snapshotor67E230publicationinthisinitializer.

Owned7124E0[24]callbackprefixSHA-256 `5d6fb0ca660d7f5a8f095fa32de79d0fea2d91c3b56c73b4d899d9fefe46cb97`.7125D0[16]raw`7017a60e060090e85af1060000000000`,SHA-256 `9177fe8cff63ad2b79be5af6d22e2950bfe8e4d796b6744d79bb3e61408a2c6d`;5A7D00usesthefirsttwosix-byteparameterrecords,remainingbytesnotinventedasanarraybound.7127D8[12]pointers{712720,712760,7127A0},SHA-256 `98b68654ca27a9e353f03284e9b764f595882e3265bd2d9a012c1609e8ed6560`;712890[12]{7127F0,7127F0,712840},SHA-256 `137ff62f1c8b10ec4973b16fc30efe84b9acfdaa5ddbd5da1a96042112ad1ca1`;7128D0[16]{7128A0,7128A0,7128B0,7128C0},SHA-256 `1530f91bed80451a1a10d8bd899a8076d633ee1956eab1a273f3fca4a69a454a`.

Ownedpayload7128A0[16]=(0,90,0,85),SHA-256 `82a674b1b3f000b82ea0df0364e569555c10a36d54261e89810fa584439a688e`;7128B0=(0,100,0,95),SHA-256 `ab7853c4067ca6e43a53ce98f55cf799cdf8dd1f6577485b2f2913af886af6ef`;7128C0=(0,0,20,65),SHA-256 `89c96b36c321d48cf964be20ab126158121c69dfa848de64ce3f824ad75b63a0`.740338[4]=`6666a63f`,binary32(1.2999999523162842),SHA-256 `ffcd594324296033e35bb6b3ea4a3d6e9b3b4db169f4e1968861c5746a9bf958`.

Originalactorname,payloadfieldmeanings,globalcallfrequencyandcostremainunknown. CompleteupdateorderingdoesnotprovetheactorcausesmeasuredslowdownsorjustifyremovingPS2behaviorwithoutretest.
