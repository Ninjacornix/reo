# Primary-clip sound crossings in633030

Static File #1 US, 2026-11-05. One complete original o2 body reviewed, including every clip comparison, ordered sound request and delay slot. Frame integers, clip IDs and event IDs below are hexadecimal; f12 is the caller's float step. No execution, build, attachment, live memory, input or timing. Original sound/animation names are unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x633030](../recomp/config/output_ovl/o2/o2_00633030_0x633030.cpp) | `request_sound_crossings_for_fourteen_primary_clip_ids_candidate` | High mechanics; candidate role | Reads unsigned primaryclip1F2, preserves incomingf12 in f20, selects fourteen literal clip cases and issues ordered5A9250(frame,actor,event,width) calls below. No recognizedclip -> return without request. No animation advance, own allocation, clock mutation or local normalization of return value. |

Every request uses actor=a0entry as5A9250's a1, event as a2, width as a3. The helper's full contract in [animation sound](SYMBOLS_ANIMATION_SOUND.md) performs frame crossing and random variant selection only on admitted gates. Width0 does not suppress the base event. Width2 on clip69's first request can consume RNG and choose event8/9; the later request retains fixed8. Incoming f12 is restored before every following request so earlier callee register effects do not change later event-step input.

| Primaryclip1F2 | Ordered (frame,event,width) requests |
| --- | --- |
|69|(6,8,2); (2C,8,0)|
|96|(4,1,0); (21,1,0); (3E,1,0)|
|97|(4,1,0); (E,1,0); (1C,1,0); (26,2,0)|
|FA|(4,0,0); (18,0,0)|
|FB|(0,0,0)|
|FC|(4,0,0)|
|FD|(A,1,0); (26,1,0)|
|12C|(0,6,0)|
|12D|(0,6,0)|
|12E|(0,6,0)|
|130|(2,4,0)|
|132|(26,0,0)|
|15E|(2,A,0); (6,C,0)|
|15F|(4,1,0); (1E,1,0)|

This is a complete literal branch schedule, not sampled audio events or a callback-frequency estimate. Caller admission, step values, clip frequency and performance cost remain unknown. Owned o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full owned-body audit: 175 original words verified; 14 omitted words all zero/NOP. Zero conflicts or omitted nonzero words.
