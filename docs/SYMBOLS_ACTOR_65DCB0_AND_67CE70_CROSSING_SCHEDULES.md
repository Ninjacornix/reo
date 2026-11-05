# Primary motion crossing schedules65DCB0/67CE70

Static File #1 US owned o2 analysis, 2026-11-05. Entire65DCB0..65E39F and67CE70..67D43B read, including comparison dispatch, every call/delay slot and exits. [Identity](FUNCTION_INDEX.md). No runtimeactivity or measurements. Every schedule number is hexadecimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x65DCB0](../recomp/config/output_ovl/o2/o2_0065DCB0_0x65dcb0.cpp) | `request_actor_65dcb0_primary_motion_sound_crossing_schedules_candidate` | High complete dispatch mechanics; original motion names unknown | Unsignedmotion1F2 selects finiteordered5A9250requestsbelow;originalstepf12savedf20andforwardedbeforefollowingcalls. Defaultreturns. |
| [o2 0x67CE70](../recomp/config/output_ovl/o2/o2_0067CE70_0x67ce70.cpp) | `dispatch_actor_67ce70_primary_motion_sound_variant_and_collision_crossings_candidate` | High complete dispatch mechanics; original action names unknown | Unsignedmotion1F2 selects sound5A9250/parity5A92E0/predicate5A93A0/collision5A96F0requests. Motion64usesownyaw92lowbit;highmotiongroupuses148==2. Fullorderedcallsbelow. |

All calls use originalactor and preservedoriginalstep. Notation:

- S(frame,event,count)=5A9250, [primarycrossingsound](SYMBOLS_ANIMATION_SOUND.md);count>=2RNGvariants,count0/1fixedbase.
- R(frame,event,count)=5A92E0;count0fixedbase,count1global4BADE8bit0parity,othercountsRNG.
- P(frame,a2,a3,t0)=5A93A0;admittedcrossinguses1B9090(actor) tochoosea2ifnonzeroelsea3;t0nonzeroaddsglobal4BADE8bit2.
- C(frame,mode,descriptor)=5A96F0;admittedmode0clearsentire115byteandattachesdescriptorwith5DA2C0,mode2ORs115bit1.

[Variant/collisionhelpers](SYMBOLS_ENTITY_CROSSING_EVENTS.md) establishthosegatecontracts. Calls below are orderedrequests, not unconditional soundplayback/collisionchanges. No animationadvance orwaitloops.

## 65DCB0

`[frames]:event/count` abbreviates orderedindividualS calls.

| Motion1F2 | Complete ordered schedule |
| --- | --- |
|65|S(46,8,2)|
|8C or96|[12,24,40,50,6A,7A]:0/2|
|8D or97|[A,12,20,28,36,3C]:0/2|
|8E,8F,90,91,92,93,98,99,9A,9B,9C,9D|[E,18,2C,3A,4A,66]:0/2|
|94,95,9E,9F|[1C,2A,34]:0/2|
|C8|[12,1E,30,3C,50,6E,84,98,AA,BA,CE,DA,E8,FC,118]:0/2|
|CA|S(1E,10,0)|
|CB|S(48,10,0)|
|FA|S(4,A,0)|
|135|S(4,4,0)|
|136|S(2,7,0);[10,20,2E,40,62,A0]:8/2|
|15F|S(0,E,0)|
|160|S(4,2,0)|
|163|[14,4A,64,78,A4,B4]:C/0|
|other|No request.|

## 67CE70

| Motion1F2 | Complete ordered schedule |
| --- | --- |
|64|Ifsignedhalfownyaw92bit0set:S(2C,33,0),S(C8,34,0);clear:S(30,33,0),S(C8,34,0). Thisisownyawparity,not4BADE8parity.|
|65|R(4,30,1)|
|69|S(32,33,0);S(C8,34,0)|
|6E|P(18,0,F,1);P(72,0,F,1);P(B8,0,F,1);P(112,0,F,1);P(170,0,F,1);P(1D2,0,F,1)|
|73|P(5C,0,F,1);P(96,0,F,1)|
|C8|R(A,33,1);S(36,A,0);C(2C,0,1D);C(56,2,0);S(64,9,0);C(6A,0,1E);C(8A,2,0)|
|C9|R(A,33,0);S(36,A,0);P(50,0,F,1);S(64,9,0);P(94,0,F,1);S(B4,A,0);P(DA,0,F,1);P(116,0,F,1);C(2A,0,1D);C(48,2,0);C(68,0,1E);C(80,2,0);C(B2,0,1D);C(CC,2,0)|
|12C,12D,12E,12F,130,131,132,133|If148==2:R(4,32,0);elseR(4,30,1). ThenP(18,4,11,0).|
|136|If148==2:R(4,32,0);elseR(4,30,1). ThenP(50,4,11,0).|
|13D or13E|If148==2:R(4,32,0);elseR(4,30,1). ThenP(50,4,11,0).|
|other|No request.|

The unsortedcallorderinginC8/C9isintentional: earlieraudiohelpercallsmayconsumeglobalRNGorinspectpredicatesbeforelatercollisiongates. No globalframes-per-secondassumption,timingrewrite,soundnameorperformancebottleneckisaddedfromthesestaticcontracts.
