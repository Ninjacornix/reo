# Actor 6C primary-track sound schedules

Static File #1 US research, 2026-11-04. One complete large original dispatcher
reviewed through every literal branch and delay slot. Addresses and numeric
arguments are hex. No game execution, sound playback, engine edits or cost claim.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6CBF60](../recomp/config/output_ovl/o2/o2_006CBF60_0x6cbf60.cpp) | `dispatch_actor_6c_motion_primary_track_sound_schedules_candidate` | High mechanics; probable role | a0 actor,f12 animationstep. Fifteen literal motion1F2 cases call5A9250(frame,actor,baseEvent,variantCount,original step),default no call. Step preservedf20. Motion134 chooses firstevent6 when signed544>0,7 otherwise. MotionC8 deliberately retains two identical frame6C/event0/count2 calls;motion131 retains distinct frame2C calls. No animation advancement,global clock reads or diagnosis. |

Each A(frame,event,count) below is an ordered5A9250 call. The existing adapter
uses its own crossing gate;count>=2 selects a random variant only after gate
acceptance. Numeric schedules are kept in source order,including duplicates:

| Motion | Ordered calls |
| --- | --- |
| A0 | A(14,0,2),A(1A,0,2),A(26,0,2),A(30,0,2),A(38,0,2),A(40,0,2),A(48,0,2) |
| A1 | A(8,0,2),A(14,0,2),A(1C,0,2),A(28,0,2) |
| A2 | A(2,0,2),A(A,0,2),A(12,0,2),A(1A,0,2),A(22,0,2),A(E,2,0),A(1C,2,0) |
| A3 | A(2,0,2),A(E,0,2),A(16,0,2),A(1E,0,2),A(10,2,0) |
| C8 | A(54,0,2),A(5C,0,2),A(64,0,2),A(6C,0,2),A(74,0,2),A(7C,0,2),A(6C,0,2) |
| FA | A(2,0,2),A(A,0,2),A(12,0,2),A(1A,0,2) |
| FB | A(2,0,2),A(A,0,2),A(12,0,2),A(1A,0,2),A(22,0,2),A(2A,0,2),A(32,0,2),A(3A,0,2),A(42,0,2),A(4A,0,2),A(52,0,2),A(5A,0,2),A(18,3,0) |
| FC | A(4,0,2),A(C,0,2),A(14,0,2) |
| 12C | A(2,6,0),A(6,0,2),A(E,0,2),A(16,0,2),A(1E,0,2),A(26,0,2),A(2E,0,2),A(36,0,2) |
| 12E | A(2,7,0),A(6,0,2),A(E,0,2),A(16,0,2) |
| 12F | A(2,4,0) |
| 131 | A(2C,2,0),A(8,0,2),A(12,0,2),A(1C,0,2),A(24,0,2),A(2C,0,2) |
| 132 | A(2,9,0),A(2,5,0) |
| 133 | A(2,7,0),A(6,0,2),A(10,0,2) |
| 134 | A(2,544>0?6:7,0),A(8,0,2),A(10,0,2) |

These schedules are original measured-by-static-inspection arguments,not
runtime evidence that sounds played or duplicated audibly. Deduplicating or
sorting them could change shared random state and original event behavior;
this notebook makes no such implementation change.

Related [sound adapters](SYMBOLS_ANIMATION_SOUND.md) and
[motion controls](SYMBOLS_ACTOR_6C_MOTION_CONTROLS.md).
