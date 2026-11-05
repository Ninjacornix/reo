# Actor numeric motion audio schedule 6C3280

Static File #1 US research, 2026-11-04. Two complete original bodies reviewed.
Addresses, motion IDs, event frames and selectors hexadecimal. No execution,
attachment, build, replay or engine changes. Original actor/sound names unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C3280](../recomp/config/output_ovl/o2/o2_006C3280_0x6c3280.cpp) | `dispatch_thirty_seven_motion_audio_schedules_and_periodic_event11_candidate` | High mechanics | Before checking motion,half3244C0 modulo30decimal=0 requests1B9310(self,11,0). Then compares1F2 against37 numeric motions;fullschedule below. Saves incominganimationstepf12 and forwards it. Other motions return after periodic request. Does not deduplicate repeated callbacks at same counter or prove runtime frequency. |
| [o2 0x6C3EE0](../recomp/config/output_ovl/o2/o2_006C3EE0_0x6c3ee0.cpp) | `crossing_gated_surface_audio_and_bank_one_variant_candidate` | High mechanics | a0frame,a1actor,a2kind,f12step;573480(actor,0,floatframe,step) gatesallwork. UnlessBBA=9,1B8D70(actor,kind4?2:signedlow8kind). Then kind4 requestsbank1audio9,kind2audio4,otherkindRNGstream1&1+2. Always1B9310(actor,id,0) ongateadmission. Gatesmissedconsume no RNG inhelper. |

Notation S(frame,event,count)=5A9250(frame,self,event,count,step);
T(frame,kind)=6C3EE0. Entries are in original call order, not sorted by frame.
Count6 means helper performs gated RNG modulo6, not six requests. All valueshex.

| Motion | Complete scheduled calls |
| --- | --- |
| 64 | S(14,13,6),S(A8,13,6). |
| 65 | S(18,13,0),S(78,13,0),T(C,3),T(CC,3). |
| 78 | S(70,13,6),S(FA,13,6),S(1AE,13,6),T(50,3),T(84,3),T(BE,3),T(106,3),T(15A,3),T(1B0,3). |
| 79 | S(12,13,6),S(48,13,6),S(AC,13,6),T(22,1),T(3E,1),T(54,1),T(76,1),T(92,1),T(B4,1),T(CE,1),T(EC,1). |
| 7A | S(0,13,0),S(34,13,6),T(20,1),T(4A,1),T(60,1). |
| 7B | S(50,13,6),T(7A,0). |
| 7C | S(28,13,6). |
| 7D | S(12,13,6),T(18,3). |
| 7E | S(12,13,6),T(3C,3). |
| 7F | S(C,13,6),T(18,0). |
| 80 | S(38,8,0). |
| 81 | T(8,0),S(16,13,6). |
| 82 | S(0,13,6),T(18,3). |
| 83 | S(3C,13,6),T(18,3),T(D8,3). |
| C8,C9 | S(20,B,0),T(2C,0),T(4C,0). |
| CA | T(C,0),T(14,0). |
| CB | S(E,13,6),T(1C,0),T(36,0),T(4A,0). |
| CC | S(18,D,0). |
| CD | S(28,D,0). |
| CE | S(A,6,0),T(16,0),T(2E,0),T(4E,0). |
| CF | T(16,0),T(20,0). |
| D0 | S(22,D,0). |
| D1 | S(16,D,0). |
| D2 | S(32,6,0),T(40,0),T(5A,0),T(78,0),T(D0,0). |
| 12C | S(A,5,0),S(4E,13,6),S(90,13,6),T(7E,3),T(9C,3). |
| 12D | S(A,5,0),S(4C,13,6),S(8C,13,6),T(46,0),T(60,0). |
| 12E | T(C,0),T(20,0),T(46,0),T(74,0),S(86,13,6). |
| 12F | S(28,13,6),T(24,0),T(3A,0),T(6C,0). |
| 130 | S(0,7,0),S(10,13,6),T(1C,0),T(36,0),T(4E,0),T(80,2),T(86,2). |
| 131 | S(0,7,0),S(19,13,6),T(18,0),T(2E,0),T(6A,4),T(84,2). |
| 132,133 | S(0,7,0),S(74,13,6),T(22,4),T(50,2). |
| 134 | S(2,12,0),S(44,12,0). |
| 135 | S(16,12,0),S(52,12,0). |
| 136,137 | S(A,5,0),S(4A,13,6). |

The schedule and helper fully describe conditional calls, not original sound
content or measured audio workload. See[frame sound helper](SYMBOLS_ANIMATION_SOUND.md).

Full-body owned-word audit: 2 rows, 802 verified instruction words,
zero conflicts, 39 omitted zero/NOP words, zero omitted nonzero words.
