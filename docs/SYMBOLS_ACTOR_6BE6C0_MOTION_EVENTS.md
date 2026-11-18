# Actor numeric motion schedule 6C1610

Static File #1 US research, 2026-11-04. One complete original body reviewed.
Addresses, motion IDs, event frames and selectors hexadecimal. No execution,
attachment, build, replay or engine changes. Original event names unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C1610](../recomp/config/output_ovl/o2/o2_006C1610_0x6c1610.cpp) | `dispatch_motion66_68_6e_6f_c8_c9_ca_d2_d3_d4_crossing_events_candidate` | High mechanics; original action names unknown | Switches half1F2 across ten numeric motions. Preserves incoming f12 animation step in f20, supplies actor to every event helper; complete schedule below. Other motions return. Calls may have gated RNG or model-node mutations inherited from reviewed helper contracts; invocation is not itself an original game update. |

Notation: R(frame,base,count)=5A92E0, S(frame,event)=5A9250 witha3=0;
E(frame,kind,node)=5A9440 witha3=0/t0=node;
F(frame,mode,descriptor)=5A96F0. Actor and original animation step are forwarded.
R count1 uses global parity, not a range of one. E kind4 mutates resolved node
position before effect construction. Every call/conditional path was reviewed.

| Motion | Schedule in original call order |
| --- | --- |
| 66 | Ifsecondary9=6,E(4E,4,10);R(8,0,1),S(52,4). |
| 68 | R(8,0,1). |
| 6E | R(82,0,1),R(C2,0,1). |
| 6F | R(24,0,1),R(56,0,1). |
| C8 | R(4,0,1),R(30,0,1),R(40,9,0),R(4C,0,1),E(42,4,10),E(48,4,10),E(4E,4,10),F(44,0,46),R(72,0,1),R(86,0,1),R(AC,0,1). |
| C9 | F(12,0,8A),R(14,0,1),E(14,1,11),S(1E,2),R(54,0,1),F(4A,0,47). |
| CA | S(32,5). |
| D2 | Ifprimary8=3,S(A,6);R(36,0,1). |
| D3 | R(C,0,1),R(3C,0,1),S(A,7). |
| D4 | S(E,A),S(4A,A),S(90,A),S(DE,A),S(A,10),R(3E,0,1),R(78,0,1),R(9E,0,1),R(EC,0,1),R(11C,0,1),R(152,0,1),S(172,F),E(172,0,11). |

Helper evidence: [audio](SYMBOLS_ANIMATION_SOUND.md),
[crossing side effects](SYMBOLS_ENTITY_CROSSING_EVENTS.md).
Numeric motions overlap the [6BE6C0 family](SYMBOLS_ACTOR_6BE6C0_CALLBACK.md);
the schedule's registration/caller determines actual actor use. This note does
not claim a proven anatomical identity or runtime event frequency.

Full-body owned-word audit: 1 rows, 311 verified instruction words,
zero conflicts, 13 omitted zero/NOP words, zero omitted nonzero words.
