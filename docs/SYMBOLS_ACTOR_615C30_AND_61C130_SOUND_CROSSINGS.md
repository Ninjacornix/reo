# Two actor motion sound-crossing schedule dispatchers

Static File #1 US,2026-11-04. Two complete o2 bodies; mechanics verified, original motion/event names unknown. No execution/build/attachment/live memory/input/timing. All numeric arguments below hexadecimal. [Sound gate contract](SYMBOLS_ANIMATION_SOUND.md), [actor60F710 root](SYMBOLS_ACTOR_60F710_ROOT_PRIMARY_ONE_AND_AIM.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x615C30](../recomp/config/output_ovl/o2/o2_00615C30_0x615c30.cpp) | `dispatch_actor_60f710_motion_primary_track_sound_crossings_candidate` | High mechanics; candidate role | a0 actor/f12 step; unsigned motion1F2 switch recognizes28 literal keys, finite ordered5A9250 calls below, default returns. Original step savedf20 and forwarded after each call. No animation advancement, global clock read, direct RNG, or sound mixing. |
| [o2 0x61C130](../recomp/config/output_ovl/o2/o2_0061C130_0x61c130.cpp) | `dispatch_actor_61c3e0_motion_primary_track_sound_crossings_candidate` | High mechanics; candidate role | a0 actor/f12 step; unsigned motion1F2 switch recognizes12 literal keys, ordered5A9250 calls below, default no action. Preservesf20; event variant width2/3 retained rather than treating a3 as sound bank. |

Notation S(frame,baseEvent,variantCount)=5A9250(frame,actor,baseEvent,variantCount,original step). The mapped helper first checks primary-track crossing573480. Only admitted calls with count>=2 draw a random variant; otherwise event is baseEvent. These tables are requests at crossings, not unconditional sound emissions or counts of audio mixer work.

|615C30 motion1F2 keys|Ordered requests|
| --- | --- |
|69,6B|S(24,0,0)|
|6A|S(4,0,0);S(1A,2,0)|
|6E|S(4,0,0);S(10,0,0);S(1C,0,0);S(28,0,0);S(34,0,0)|
|C8|S(4,0,0);S(10,0,0);S(1C,0,0);S(28,0,0);S(34,0,0);S(40,0,0)|
|C9|S(4,0,0);S(10,0,0);S(1C,0,0);S(28,0,0);S(34,0,0);S(40,0,0);S(4C,0,0)|
|12C,12D,131,132|S(4,6,0)|
|12F,130|S(16,0,0)|
|136,137,138|S(4,6,0);S(8,0,0);S(14,0,0);S(20,0,0);S(2C,0,0)|
|139,13A,13B|S(4,6,0);S(A,0,0);S(16,0,0);S(22,0,0);S(2E,0,0)|
|13C,13D,13E,13F,140,141|S(4,6,0);S(C,0,0);S(18,0,0);S(24,0,0);S(30,0,0)|
|142,143,144|S(4,6,0);S(10,0,0);S(1C,0,0)|
|14A|S(4,7,0);S(3C,4,0)|

|61C130 motion1F2 keys|Ordered requests|
| --- | --- |
|64|S(32,8,2);S(B4,8,2)|
|FA,FB|S(10,C,0)|
|FC|S(0,5,0)|
|FD|S(28,A,0);S(2E,A,0);S(38,A,0);S(44,A,0)|
|FE|S(A,A,0)|
|131|S(2,4,0);S(12,4,0);S(20,4,0)|
|133|S(0,7,0)|
|135|S(8,0,3);S(1C,0,3);S(32,0,3);S(9E,4,0)|
|15E|S(10,C,0)|
|15F|S(32,D,0)|
|160|S(20,C,0)|

The same numeric motion key can have different schedules in different dispatchers. It does not establish one global authored meaning for that number. Tail/body delay slots were reviewed: keys142..144 enter616150/154 with frame4; 13C..141 enter6160D0/0D4 with frame4, and6A enters615D98 with a0=4 from its branch delay slot. No event or count is inferred from a decompiler default register.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. No data tables are dereferenced by these schedules beyond actor state and helper internals; all schedule literals reside in audited instructions. Runtime call rate/admission, actor identity, actual audio playback, and cost attribution remain unknown.

Owned-word audit: two complete bodies,503 original instruction words verified,31 omitted zero/NOP words,zero conflicts and zero omitted nonzero words. Full ordered28-key and12-key schedules preserved. No shared index mutation.
