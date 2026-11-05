# Actor 703300 response dispatch and motion events

Static File #1 US research, 2026-11-04. Five complete original bodies reviewed.
Addresses and offsets are hex unless marked decimal. Actor identity, original
response names and timer units remain unknown. No target execution or engine
changes; no measured bottleneck or slowdown cause is claimed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x7047D0](../recomp/config/output_ovl/o2/o2_007047D0_0x7047d0.cpp) | `dispatch_actor_703300_primary_five_after_action_admission_candidate` | High routing |635640(actor,FA) nonzero calls707310 and returns. Otherwise ORs115bit1, dispatches73D990[byte9](actor); both owned slots are704840. No bounds check in this wrapper. |
| [o2 0x706A80](../recomp/config/output_ovl/o2/o2_00706A80_0x706a80.cpp) | `dispatch_actor_703300_primary_three_contact_response_candidate` | High routing | ORs bit10 at byte74F295+60*unsigned B98, caches actor11C at75A4F0, then tail-dispatches73D9D0[byte9](actor). Four owned slots all706AE0. The first write is a separate indexed state table, not an actor C94 write. |
| [o2 0x706AE0](../recomp/config/output_ovl/o2/o2_00706AE0_0x706ae0.cpp) | `advance_actor_703300_directional_contact_response_candidate` | High mechanics; probable role | Phase0 calls63F5A0(actor,byte3); phaseFF skips it. If current motion is owned73DCF0 (decimal204) and frame>=40, subtracts8000 from yaw, resets node34->824 basis, and selects descriptor73DA20[B1F&7]/blend decimal10; this path does not write phaseA. Other motion/frame path selects73DA18[B1F&7]/blend decimal20, phase1, and FF additionally C36=3E. Phase1 advances to completion, C94bit20 then C36=58, resets707110. Other phases return. The phase-preserving special branch is recorded literally, not labeled an infinite loop. |
| [o2 0x706C80](../recomp/config/output_ovl/o2/o2_00706C80_0x706c80.cpp) | `advance_actor_703300_primary_four_two_motion_response_candidate` | High mechanics; probable role | Every call sets32FF,115bit1,C94mask201 and caches11C at75A4F0. Phase0 calls63F5A0(actor,byte3),666D00(contact); FF skips those calls and setsC36=46. Both enter1, optionally reverse yaw/reset node basis for motion204 frame>=40, then descriptor16/frame0/blend10. Phase1 completion enters2, timerC=decimal90/factor,descriptor1C/blend10. Phase2 advances and predecrements C; expiry enters3 and signals5703E0(99,1) only when byte4==0. Other phases simply advance58C300; no cleanup/despawn in this body. |
| [o2 0x707E90](../recomp/config/output_ovl/o2/o2_00707E90_0x707e90.cpp) | `dispatch_actor_703300_motion_frame_audio_and_event_crossings_candidate` | High mechanics; probable role | a0 actor,f12 advance amount. Switches motion1F2 across fifteen literals D2,D3,CB,136,137,140,141,190..196,199; default no callback. Calls5A92E0 audio crossing or5A96F0 event crossing with exact frame/resource/mode arguments detailed below. Preserves supplied f12 in f20; successive calls reload it. It does not advance animation itself or count global updates. |

Owned directional descriptor bytes73DA18 are decimal15,14,11,12,12,13,16,15;
73DA20 decimal12,13,13,15,15,14,11,12. Actor B1F is masked7 before lookup.

The707E90 crossing table below uses hex numbers. A means5A92E0(frame,actor,
audio,count), E means5A96F0(frame,actor,mode,event). Their existing mapped
contracts determine crossing behavior; this wrapper supplies these parameters:

| Motion | Ordered crossings |
| --- | --- |
| D2 | A(38,0,1),A(60,0,1) |
| D3 | A(18,0,1),A(2A,0,1) |
| CB | E(14,0,6E),A(16,7,0) |
| 136 | A(24,3,0),E(3C,0,83) |
| 137 | A(0,2,0),E(8,2,0) |
| 140 | A(0,33,1),E(32,0,7A),E(32,0,7E),A(38,8,0),A(46,0,1),E(48,2,0),E(5E,0,7A),E(5E,0,7E),A(6C,8,0),A(70,0,1),E(7C,2,0) |
| 141 | A(0,33,1),A(2E,8,0),E(5E,0,7C),A(6C,C,0) |
| 190 /191 /192 /193 /194 /195 /196 | A(frame,30,1), frame respectively A,6,6,A,8,4,6 |
| 199 | A(0,32,0),A(4A,5,0),A(FE,4,0) |

The first event call on each selected branch uses the original incoming f12;
following calls restore it from f20. No assumption that repeated callback
invocations represent distinct original game ticks is introduced.

Related [bootstrap](SYMBOLS_ACTOR_703300_BOOTSTRAP.md),
[primary two](SYMBOLS_ACTOR_703300_PRIMARY_TWO.md), and
[shared controls](SYMBOLS_ACTOR_703300_SHARED_CONTROLS.md).
