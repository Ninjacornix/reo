# Actor 6BE6C0 terminal motion and effect sequence

Static File #1 US research, 2026-11-04. One complete large original body reviewed.
Addresses/offsets/state values hexadecimal; frames, positions and timers decimal.
Original effect and animation names remain unknown. No execution, attachment,
build, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6BFF30](../recomp/config/output_ovl/o2/o2_006BFF30_0x6bff30.cpp) | `tick_actor_terminal_motion_d_e_relocation_and_effect_window_candidate` | High mechanics; terminal role probable | Always32=FF,C94|201,global7556E0=11C. Primary4 body dispatches A0/FF/1/2/3 and independent B substate, then gated frame effects. Sets health544 and runtime mirrored health to-1 on initialization; later deactivates byte1. Full cases below. No local actor node unlink or task deletion. |

| A | Complete sequence behavior |
| --- | --- |
| 0 | 63F5A0(self,byte3),666D00(event7556E0),then falls into FF initialization. |
| FF | C36=46 only for incomingFF. A=1,B=0,C39=0,health544=-1 and mirrored74F26C+60*B98=-1. HalfC=90/unsigned74F200;C38=RNGstream1&7,half12=1.6C0400(self,D,0,0,0float),58C780. |
| 1 | Predecrement halfC. Completion boolean ifpost<=0 or58C300(rate0.8) fullreturn nonzero. Oncompletion A++,selectmotionE with blendA,58C780,575890(13,0),6F16A0(0),B=1,C=1. |
| 2 | Stepanimation0.8;unlessframe1E4<334,A++,54A|7. |
| 3 | 54A|7,stepanimation0.8;nonzero setsA=63,575890(13,1),byte1=0,6F16A0(0). |
| other | 54A|7. |

B processing follows the selected A case in the same call. B0 does nothing;
B1 predecrements halfC,post>=0 leaves position. Post<0 incrementsB,54A|7,
sets XYZ=(5800,-950,4525) and copiesXYZ toprevious44/48/4C.
Other nonzeroB only54A|7. Therefore setting B1/C1 first decrements to0 in that
same call and relocation waits for a later call. Callback post-work may further
change position; the local body is the claim here.

Final effect path requires motion1F2=owned72FE68 (D4). Atframe<160 it skips
construction and calls63F760;atframe>340 it also skipsconstruction. Within the
ordered[160,340] window it decrements half12;post<=0 resets to10+(RNGstream1&7),
chooses one of eight signed X/Z offsets72FC60 usingC38&7,position=(actorX+dx,
actorY+100,actorZ+dz),scale=(2,2,2). Calls5EA0D0(position,scale,1) then kind4,
plays1B9310(self,RNGstream1&1,0). C38 increments;newvalue>=7 rerandomizes&7.
The path finally63F760(self);nonzero result setsC36=59. Other motions skip this
entire finalpath. Construction success and runtime cost are not established.

Owned data from `build-function-index/owned-overlays/o2.bin`,base570000,
SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Span | Values / SHA256 |
| --- | --- |
| 740EA8 length4 | Float0.800000011920929. `030a1a64b337c633d995221728d15e8b0d086cc0dcf4557205111b089b04464d` |
| 72FE68 length2 | SignedhalfD4. `0149b725fa0360de824113f183950218e968157367ab586e1c972e21f829607c` |
| 72FC60 length20 | Eight signed pairs(decimal)[(30,-170),(-25,-150),(40,-130),(-28,-160),(-42,-180),(37,-175),(-30,-190),(28,-245)]. `949eebb771d4831f8df5a3ad5ff05ba93c3d35e7a793e483c9b9ffe7eb55784e` |

See [callback](SYMBOLS_ACTOR_6BE6C0_CALLBACK.md) and
[motion selector](SYMBOLS_ACTOR_6BE6C0_MOTION_TARGET_SELECTION.md).

Full-body owned-word audit: 1 rows, 292 verified instruction words,
zero conflicts, 15 omitted zero/NOP words, zero omitted nonzero words.
