# Collision proxy room-mask contact and pending-mode dispatchers

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed, including branch entry/delay targets. Hexadecimal addresses, fields, selectors and masks; float168.0 and explicit counts decimal. P is proxy a0; A=P34. These labels describe observed original-body mechanics, not original enum names or live incident causes. No execution, attachment, build or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5C1780](../recomp/config/output_ovl/o2/o2_005C1780_0x5c1780.cpp) | `collision_proxy_classify_kind_zero_room_mask_contact_and_publish_target_candidate` | High mechanics; role probable | P=a0,A=P34; class0/1/2 split, scene slot state, current-room masks, queryclassP3E, selectorP60, item content and signed counterP64 determine AB9/AB8/ABA, optional flags/events and transition globals. Successful target construction writes ABC,AC8=(P58-8000)&FFFF,ABB=P4C; no actor38 or half92 write. Full numeric branch family below; unsupported caller classes/categories have locally uninitialized target-offset paths. |
| [o2 0x5C3000](../recomp/config/output_ovl/o2/o2_005C3000_0x5c3000.cpp) | `collision_proxy_classify_kind_two_room_mask_contact_and_publish_target_candidate` | High mechanics; role probable | P=a0,A=P34. Related but distinct physical body with selectorP58, matrix slotP44, pose indexP48,yawP4C,AD1=P50. Class0 contact/flags/counter and class1/2 mask logic below. Common target publication always AB8=1, including after positive-counter branch temporarily stored0. No direct room-transition globals like5C1780. |
| [o2 0x5C4DE0](../recomp/config/output_ovl/o2/o2_005C4DE0_0x5c4de0.cpp) | `collision_proxy_dispatch_class_zero_pending_interaction_or_task_mode_candidate` | High mechanics; role probable | Only class0. Mode=P.word4C dispatches pose/facing, task allocation, flag-pair or pending-code paths. Scene translation slotP78 and yawP48 prepared even for later ignored modes. Recognized non-task paths end570CC0(actor,low8 mode); modes3/4 instead clear and publish owner/task-slot state, request task, return. Complete cases below. |

The two mask dispatchers share several mechanisms but are not byte-equivalent. Define R=unsigned half3243DC, B=1<<(P40&1F), S=byte4A3621+60*P40. Room mask Hn=unsigned half(4B9E20+12*R+n); n0/2/4/6/A are distinct physical fields. Define F=byte70B190[index], where index=P54 for5C1780, P48 for5C3000. Selector T=P60 for1780, P58 for3000. Q=P.byte3E. U means1B0340(A)!=0; L meansA3==byte4BADED. A flag publication mentioned below ORs H2 with low16 B only if U unless explicitly stated otherwise.

Class0 admission: if T==2 reject only S==1; otherwise require S==0 and H4&B==0. On passing, AD0=low8 P40 is written **before** later query gates.

| Class0 path | Phase/state and side effects |
| --- | --- |
| Q5 | Requires L,T0,S0,H6&B==0. AB8=1,AB9=F+18; AD1=FF for1780 orP50 for3000. If HA lacks B,5706B0(R,P40,3);1780 also5706B0(P44,P48,3). Byte4A5C25+selectedID=1; if U publish H2. Continue pose without common classification finalization. |
| Q!=5,H0 hit,T!=0 | AB9=0;ABA=0; pose. |
| Q2,H0 hit,T0,item content19E..1A1 | AB9=F+21,AB8=1,signed P64=C8; if U publishH2;5F4FD0();ABA=0; pose. Content is half3C5636+3C*A.C82. |
| Q2,H0 hit,T0,other content | If wordP6C!=content ->AB9=0,ABA=0,pose. Match ->if U:5C1100(1),5700A0(2,28,3C),publishH2. AB9=F+3,AB8=1;570700(R,P40,0),5B4460(A,P.half6C),5F4FD0,ABA=0,pose.1780 additionally clears linked endpoint570700(P44,P48,0) iff P72!=0. |
| Q6,H0 hit,T0 | If signedP64==0 justABA=0,pose. Otherwise subtract signed low16 result570F40(P.signedHalf66,A.C82) unless HA&B. Remaining<=0 ->AB9=F+25,AB8=1,clear570700(R,P40,0); optional U event5700A0(2,28,3C) for1780 versus(2,1E,28) for3000.1780 can also clear linked endpoint iffP72. Positive ->AB9=F+23,AB8=0,1B8A10(pointer(actor34)->85C+30,570ED0(low8 slot,1)), with slotP4C for1780/P44 for3000. All setABA=0 then pose. |
| Other Q,H0 hit,T0 | If U5C1100(1) andpublishH2. If P.word6C==-2:AB9=F+9, optional U5700A0(2,28,3C),clear570700(R,P40,0),AB8=1;1780 additionally linked clear iffP72. OtherwiseAB9=F+5; ifU optional570100(P.half68,14,28,3) unlessFFFF,5C1100(1),publishH2;AB8=1. ThenABA=0,pose. |
| H0 clear,Q2/6 | Return after earlier AD0 write, no pose. |
| H0 clear,otherQ,T0 | IfU5C1100(1),publishH2. H6&B ->AB9=F+27 and optionalU5700A0(1,28,3C); otherwiseAB9=F+1,570700(R,P40,3), and1780 also linked clear(P44,P48,3).1780 setsABA=1 on latter branch only ifL.3000 marks local one-shot admission in either H6 branch. Then common classification finalization. |
| H0 clear,otherQ,T1/3 | IfU5C1100(1),publishH2;ACC=168.0;AB9=1A/29.1780ABA=1;3000 local one-shot admission=1. Common finalization. |
| H0 clear,otherQ,T2 | Toggle scenario entry through681010(low8 R,low8P40,value),570E10(low8R,low8P40,value),value1 whenS0,0 otherwise;AB9=1D/1E.1780 additionally calls681010(low8P44,low8P48,samevalue); its first681010 onS0 path inherits a2 rather than explicitly setting1. Common finalization. |
| H0 clear,otherQ,otherT | Return. |

1780 common classification finalization setsAB8=1,AD1=FF. If retained/new ABA!=0 andU, publishes byte4BAE05=P48,byte4BAE07=1,half3243E0=3243DA,half3243E2=P44.3000 instead setsAB8=1,ABA=0,AD0=P40,AD1=P50 and has no equivalent room globals. Other paths can skip these finalization blocks; the table does not imply all exits write each field.

Class0 target construction:1780 uses base translation matrix49FA10+40*P4C; offset70B0A0[P54] ifAB9==1A/29 else70B070[P54], rotated by that matrix.3000 uses slotP44/indexP48 with same phase-dependent table choice.1780 signed P73==1 andABA==1 clearsP73=FF then5C3F40((P74&F000)>>12,P74&1FF).3000 instead uses local one-shot admission and signedP72==1, clearsP72=FF andsameP74 helper. The one-shot gates differ materially.

Class1:1780 first rejects S!=0, thenAD0=P40,AD1=FF. H0&B ->AB9=F+5,ABA=0; elseAB9=F+1,102D=P48,115C=P44,ABA=1. Computes target through same1780 phase-dependent slotP4C/indexP54 and setsAB8=1.3000 has no S rejection or102D/115C publication: alwaysABA=0,AD0=P40,AD1=P50,AB9=F+5 whenH0 hit otherwiseF+1, target slotP44/indexP48. Common3000 setsAB8=1.

Class2: S1 returns; S2 ->AB9=7,AB8=1,base translation from own matrix slot(P4C/P44). ForS0: H0 hit ->AB9=F+27; otherwiseT0 selectsAB9=7 whenH4 hit, elseF+27 whenH6 hit,elseF+1;T1/3 ->AB9=1A/29,ACC168.0;T2 retainsAB9;otherTreturns. Base translation then extracted from own matrix slot. Categories1/16/29 in1780 (plus1B in3000) initialize rotated offsets; forS0 they use matrix slotP44/indexP48 and70B100 whenAB9==27/28 else70B0D0. ForS2 they use own matrix slot, own index(P54/P48),70B0D0. Other class2 categories reach target addition without locally initializing offset stack. S outside0/1/2 reaches shared addition without locally initialized base or offset. Non0/1/2 actor classes also reach shared addition with uninitialized locals. These are caller/data admission gaps only, not evidence those inputs occur or cause faults.

1780 shared addition writes ABC=base+offset,AC8=(P58-8000)&FFFF,ABB=P4C.3000 writes ABC=base+offset,AC8=P4C,AB8=1,ABB=P44; its unconditional finalAB8=1 overrides the positive-counter temporary0. Neither copies target into actor38 nor writes half92.

5C4DE0 admits only class0, calculates owner index=A3 when1B02D0()==1 else0, builds yaw basisP48 and translation B from scene matrix slotP78 before mode dispatch. Mode=P.word4C:

| Mode | Work after setup |
| --- | --- |
| 1,5,6,7,8,9,A,B,C,F,10 |570CC0(A,low8mode) only after setup. No AB8 set by this helper. |
| 2 | AC8=P48,ABB=P78 before admission; offset70B290+12*A.B99 rotated by yawP48, target=B+offset; normalizeoffset,dot against actor forward70A770 rotated by half92. Only ordered dot<=0 copies ABC then pending mode2. Failed comparison retains earlier AC8/ABB writes. |
| 3 | Task-slot=P54; zero110 bytes at3B64D0+AA0*owner+110*slot.5B92B0(low8slot,4,word70A190,A3); publish P50/P pointer at3B6530/6534+sameoffset, return without pending code. |
| 4 | Same clear/publication as3, task subtype3 andcallbackword70A18C. |
| D/E | AC8=P48,ABB=P78,AB9=13; ABC=B+rotated fixed70B2E0/70B2C0 by yawP48. Apply two optional flag pairs (P50,P54),(P58,P5C), then pending mode. |
| 1A/1B | AC8=P48,ABB=P78; index=A.B99+2*(mode-1A), offset70B300+12*index rotated by **scene matrix** slotP78, ABC=B+offset; pending originalmode. |
| 1F | AC8=P48,ABB=P78; fixed70B330 rotated by scene matrix slotP78,ABC=B+offset; pending1F. |
| 21 | AC8=P48,ABB=P78,AB9=2E; recompute B, rotate70B070[P44] by scene matrixP78,ABC=B+offset; apply both flag pairs; pending21. |
| 22 | AC8=P48,ABB=P78 before facing test. Fixed70B340 rotated by scene matrixP78, target=B+offset; normalizeoffset,dot against actor forward, ordered dot<=0 required to copyABC, apply both flag pairs and pending22. |
| Other | Return after setup without pending code. |

A flag pair(mode,ID) in this handler calls5703E0(ID,1) for mode1;5705F0(ID,1,A3 if1B02D0()==1 else0) for mode2; other modes skip that pair. No pending mode branch here sets AB8, moves actor38, or normalizes return. Matrix/offset index bounds and task request success are not locally checked.3B task state strideAA0 andslot stride110 are hexadecimal, not array counts.

The [linked query tables](SYMBOLS_LINKED_INTERACTION_PROXY_QUERIES.md) establish these three callback targets. [Pose banks](SYMBOLS_INTERACTION_POSE_BANKS.md) document570CC0 pending-code publication. [Transition callbacks](SYMBOLS_COLLISION_PROXY_TRANSITIONS.md) document5C3F40 one-shot flag work. Offset bytes and exact consumed prefixes are preserved below; none establish dynamic authored bounds.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Physical span | Exact float32 XYZ triples (decimal rendering) | SHA256 |
| --- | --- | --- |
| 70A770..70A77B | (0.0, 0.0, 1.0) | `caccb9a8fbd2401135207066c4b53d6e88467839318ea2f1e8bfadf8fef6844e` |
| 70B290..70B2BF | (0.0, 0.0, -72.5);(0.0, 0.0, -72.5);(0.0, 0.0, -100.0);(0.0, 0.0, 0.0) | `fb3df28233c8b8f4ac642360fd11bf1ddc3b70b6efd16cbb6c3dced28e7ced4b` |
| 70B2C0..70B2CB | (-45.0, 0.0, -50.0) | `f368093d7d9d1fe2aa547bae597d5d947263a5e728a6dece18299bdb7aa1f605` |
| 70B2E0..70B2EB | (0.0, 0.0, -50.0) | `04e202e7db390fc84b05ca6d6186e0caba4415badb2d163d6dcdf288dde77544` |
| 70B300..70B32F | (-70.0, 0.0, 50.0);(-70.0, 0.0, 50.0);(70.0, 0.0, 50.0);(70.0, 0.0, 50.0) | `8c0c21492749b7cc12228eb0efab608837d1a35a18bcf287c29f52233633b3f0` |
| 70B330..70B33B | (-60.0, 0.0, 25.0) | `5268ca68e0dfd3e9e877098c3b0a44ab4fb9abd009e88aa0f4c01dbe99a93e6a` |
| 70B340..70B34B | (0.0, 0.0, 60.0) | `51242bd32bf2089b021329a27cdd2f543bf24e5804b6e2b7b74d03ad2116d429` |
| 70B100..70B12F | (42.70000076293945, 0.0, 93.0);(-42.70000076293945, 0.0, 93.0);(42.70000076293945, 0.0, -93.0);(-42.70000076293945, 0.0, -93.0) | `9ccc7e7fc4bdf64f2638f1248b30bdd40cbf4cd4df476627da2fcda2b3574bcd` |

Physical prefixes/adjacencies are not valid actorB99 range proofs. Broader containing pose arrays are in [pose offset data](SYMBOLS_INTERACTION_POSE_OFFSETS.md). Numeric helpers without independently reviewed names remain explicit. No task frequency, CPU timing, renderer/VU pressure or slowdown responsibility is established.

Owned-word audit:3 rows,2364 distinct instruction words verified,225 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
