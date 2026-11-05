# Actor 6CC7C0 entry, contact and height sequences

Static File #1 US research, 2026-11-04. Five complete original catalog bodies
reviewed. Addresses/offsets hex unless marked decimal. Original actor/action
identities unconfirmed. No target execution, engine fixes or measured lag claim.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6CD290](../recomp/config/output_ovl/o2/o2_006CD290_0x6cd290.cpp) | `dispatch_actor_6cc7c0_primary_two_and_entry_height_sequence_candidate` | High mechanics; probable role | SetsBA51,54Abit4,tail-dispatches730910[byte9]. MergedCD2D0 phaseFF resetsA0,C3641. Phase0->1,B0,byte1=1,5DF9F0(actor,1),Y=decimal-1380,descriptor0/blendA unless alreadymotion100. Phase1 advances;X>500 ->2,32FF,B2,Y=-1280,descriptor5/blendA. Phase2 positive signed animation result ->3,descriptor2+(4BADE8&1),blendA,58C780. Phase3 positive result ->4,yaw XOR8000,descriptor0/blend0. Phase4 advances and X-=1;X<250 ->5,CDC=-6,D0=0. Phase5 advances,Y+=CDC,C4+=D0;Y<=-1380 resets0C0,CE4=120/factor+(random-low16&3F). Independent B0->1,CDC=10,D0=0;B1 addsCDC toY,C4+=D0 untilY>=-1280,thenB2 andclamp. B2/other values skip that independent rise. Arithmetic is preserved rather than rewritten as an assumed acceleration integrator. |
| [o2 0x6CD650](../recomp/config/output_ovl/o2/o2_006CD650_0x6cd650.cpp) | `advance_actor_6cc7c0_peer_relative_contact_and_node_effect_sequence_candidate` | High mechanics; probable role | PhaseFF->0,C3641;phase0->1,B0,B1E0,descriptor6/frame0/blendA,shared729018->word0 color toC70/1AC/1BC. Phase1 positive animation result computes376EF0 from cached peer toward owned numeric point(decimal1700,-1280,6800),rotates local(0,0,400) with634E70,places actorX/Z at peer+result,faces peer,enters2/descriptor7. Phase2 positive result:B1E1 ->3,32FF,descriptor8/blend0,writes62 to actorB24->B1E,58C780;otherwise4,descriptor9/blendA,58C780. Phase3 positive result ->4/descriptor9;phase4 positive result reset0C0. Independent B0 waitsB1E1,setsB1,calls5AA0C0;nonzero ->B2,CE81. B2 writesCE81 each call. No original interaction-name inference or contact-pointer null guard. |
| [o2 0x6CDCF0](../recomp/config/output_ovl/o2/o2_006CDCF0_0x6cdcf0.cpp) | `dispatch_actor_6cc7c0_primary_three_indexed_status_candidate` | High routing | ORs10 at byte74F295+60*unsignedB98,then tail-dispatches730928[byte9]. Three populated pointersCDD40;followingword0. No contact query/animation in wrapper. |
| [o2 0x6CDD40](../recomp/config/output_ovl/o2/o2_006CDD40_0x6cdd40.cpp) | `advance_actor_6cc7c0_directional_response_motion_candidate` | High mechanics; probable role | Phase0 calls63F5A0(actor,byte3),phaseFF skipsit and C363E. Bothenter1,9A=signed730940[unsignedB1F],descriptorC forsecondary0/1,D for2,frame0/blendA. Othersecondaryvalues have no locally assigned descriptor register in this body,but populated dispatch bank onlyadmits0..2. Phase1 advances at1;any nonzero completion reset0C0. Does not add9A to yaw in this body. |
| [o2 0x6CDE50](../recomp/config/output_ovl/o2/o2_006CDE50_0x6cde50.cpp) | `advance_actor_6cc7c0_negative_health_motion_and_delayed_height_hold_candidate` | High mechanics; probable role | Everycall32FF,C94mask201. Phase0 calls63F5A0(actor,byte3),666D00(cached755718);FF skipsthose and C3646. Enters1/B1,544=-1,half74F26C+60*B98=-1,C=decimal50,1A8null,descriptorE/frame0/blendA. Phase1 advances at owned741018(~0.4);nonzero ->A63,descriptorF/frame0/blendA. Otherphasesadvance at1. Independent B1 predecrementsC;post<=0 ->B2,CC=owned741010(~0.3),D0=741008(~-0.08),D4=currentY+20. B2 setsBA51,Y+=CC,C4+=D0;Y>=D4 ->B3,clampsY=D4. OthernonzeroB alsoBA51,B0noheightwork. CC is not updated byD0 here;the fields' distinct arithmetic is retained. No task deletion. |

Owned730910 slotsCD2D0,CD650,CD650 then0;730928 slotsCDD40 three times,
then0. InternalCD2D0 is reviewed inside catalog6CD290 and is not counted as
a separate mapped function. Owned730940 signed halves are decimal-119,-62,
-119,-91. The caller's B1F quarter-turn quantization is documented in
[shared contact controls](SYMBOLS_ACTOR_6CE_SHARED_CONTROLS.md).

All populated destinations of both identical six-entry primary banks7308C0/
7308E0 and their secondary tables have now been reviewed. Their timer and
height arithmetic remain original; no gameplay-speed or rendering changes.
Related [bootstrap](SYMBOLS_ACTOR_6CC7C0_BOOTSTRAP.md) and
[routes](SYMBOLS_ACTOR_6CC7C0_ROUTES.md).
