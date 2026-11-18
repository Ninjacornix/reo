# Actor primary animation sound schedules6509A0/651350

Static File #1 US owned o2 review, 2026-11-05. Entire6509A0..65134B and651350..65184B read, including comparison dispatch, every call and delay slot, defaults and returns. [Identity](FUNCTION_INDEX.md). No game execution or performance measurement.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6509A0](../recomp/config/output_ovl/o2/o2_006509A0_0x6509a0.cpp) | `request_actor_6509a0_primary_motion_sound_crossing_schedules_candidate` | High complete dispatch mechanics; original action names unknown | Unsigned motion1F2 selects finite ordered5A9250(frame,actor,event,count,step) requests listed below; default returns. Saves incomingf12 in f20 and restores before subsequent calls. |
| [o2 0x651350](../recomp/config/output_ovl/o2/o2_00651350_0x651350.cpp) | `request_actor_651350_primary_motion_sounds_with_520_admission_candidate` | High complete dispatch mechanics; original action names unknown | Same crossing adapter, independent motion schedule. Motions64/65 require signed520 in{0,1}; motionCA requires signed520==14. Complete schedules below. |

Notation `S(frame,event,count)` means an ordered5A9250 call with entry actor and original incomingf12. All numbers in these schedules are **hexadecimal**. `[a,b,...]:event/count` abbreviates individual ordered S calls for those frames; different event/count assignments are explicitly listed. [Animation sound helper](SYMBOLS_ANIMATION_SOUND.md) first checks primary-track573480 crossing, then conditionally draws a random variant when count>=2 and requests actor-position sound1B9310. Count0 still requests the base event on admitted crossings. These dispatchers neither advance animation nor directly mix sound. Multiple calls retain order and original step even when earlier gates consume RNG.

## 6509A0 complete schedule

| Motion1F2 | Ordered requests |
| --- | --- |
|64|[16,22,32,7C,8E,B6,D0]:0/0|
|69|S(2E,C,0)|
|6A|[24,3E,56,72]:9/2|
|C8|[1C,36,5A,76,96]:0/0; S(46,2,2)|
|C9|[1C,32,40,5A,74]:0/0; S(56,2,2)|
|CA|S(1A,1,0)|
|CB|[A,1A,30,5A,6E]:0/0|
|CC|[22,24]:0/0|
|CD or D2|[4,8,10,1A]:0/0|
|CF|S(28,1,0)|
|D5|S(C,0,0)|
|D6 or D7|S(1E,1,0)|
|D9|[14,30,54]:0/0|
|12C|S(C,8,0)|
|12D|S(E,0,0); S(12,1,0); S(18,0,0); S(22,0,0)|
|130|[30,48,66]:10/0|
|131|S(5A,10,0)|
|134|[10,1A]:0/0|
|135|[14,20]:1/0|
|136|[4E,78]:F/0|
|193|[22,30]:4/0|
|194|[4,C,14,22]:0/0|
|195|[4,E,18]:0/0; S(28,4,0)|
|197|S(2,7,0); S(28,4,0)|
|19A|S(48,4,0)|
|19D|[1E,2C]:4/0|
|19E|S(1E,4,0)|
|19F|[C,14,2E]:0/0; [54,68,74]:4/0|
|1A0|[1E,36]:4/0; [9E,A8]:0/0|
|D0 or D3|S(32,1,0)|
|other|No request.|

## 651350 complete schedule

| Motion1F2 | Admission and ordered requests |
| --- | --- |
|64 or65|Only signed-half520==0 or1: S(5A,8,2); otherwise no request.|
|67 or68|S(70,8,2)|
|96|[24,30,5C,74]:0/2|
|97|[C,18]:0/2|
|98|[10,24,3C]:0/2|
|99|[14,22,36,46]:0/2|
|9A or9B|[12,2A]:0/2|
|9C or9D|[8,E]:0/2|
|9E or9F|[14,2C]:0/2|
|A0 orA1|[14,24,3A,46]:0/2|
|CA|Only signed-half520==14: S(2,2,0); otherwise no request.|
|FA orFB|S(6,A,0)|
|FC orFD|S(20,C,0)|
|134|S(6,4,0)|
|136|S(4,7,0); S(C6,4,0)|
|138|S(14,4,0)|
|13A|S(4,7,0); S(AE,4,0)|
|15E|S(36,D,0)|
|other|No request.|

Neither body writes520, owns a clock, allocates buffers, loops waiting for frames or proves sound playback. Original motion/sound names and runtime reachability remain unknown. Mapping these schedules supplies a contract for eventual animation/audio replacement; it establishes no slowdown bottleneck or fix.
