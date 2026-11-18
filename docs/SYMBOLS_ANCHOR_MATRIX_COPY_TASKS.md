# Anchor matrix copy tasks with motion-window scaling

Static File #1 US research, 2026-11-04. Two complete original task bodies reviewed. Hexadecimal addresses, field offsets and motion codes; frame-coordinate thresholds/float scales and copy byte counts decimal. Mechanics confidence high; visual/attachment interpretation probable. No execution, attachment, build or slowdown attribution.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x57E0B0](../recomp/config/output_ovl/o2/o2_0057E0B0_0x57e0b0.cpp) | `task_copy_anchor_matrices_and_apply_motion_window_scale_for_f7_candidate` | High mechanics; role probable | TaskT=a0,A=T28,anchor=T24 (refreshed fromA24 on state0). Requires motion unsignedhalfA1F2 in15E/15F else sets state8=FF. State0 setsF7=1/state1; state1 copies anchor model870 matrix to actor model820 slotT3, applies piecewise scale fromA1E4, copies to81C slot and offsets its translation by yaw-rotated owned vector times anchor B4/B8/BC. Other task states setD32=1,clearF7,573740(T). Active paths D32!=0 markFF for cleanup next callback. |
| [o2 0x57E430](../recomp/config/output_ovl/o2/o2_0057E430_0x57e430.cpp) | `task_copy_anchor_matrices_and_delay_offset_for_f6_motion_windows_candidate` | High mechanics; role probable | Same actor/anchor/matrix slots as57E0B0, admitted motions15F/160, owned vector708D88. State0 setsF6=1,halfTC=10 if byte3243CC==0 else8, state1. Each active callback copies/scales820 matrix; decrements signed halfTC and only when new value<0 copies/offsets81C. Other task states setD32=1,clearF6,573740(T). Motion-scale windows differ below. |

T.byte8 is task state, T.byte3 selects matrix pointer index; A=T28. State0 refreshes anchor=T24=A24, sets actor F7/F6 respectively and enters state1 in the same callback. Non0/1 state enters release path immediately: actorD32=1 (in branch delay slot), actorF7/F6=0,573740(T). Merely assigning stateFF due to motion/timing/D32 inside an active branch can defer release until the next callback. There is no local null/activity/model-pointer/index validation. ActorD32 is a control byte, not an observed completion timestamp.

Both active paths copy **64 decimal bytes** in eight two-word iterations from pointer(anchor34)->870 into pointer(actor34)->(820+4*T3). They preserve all64 bytes before scaling. Let t=A.float1E4 and scale initially1.0:

| Task / motion | Ordered scale/exit cases |
| --- | --- |
| 57E0B0 /15E | t<18:stateFF,return;18<=t<=22:0.375*(t-18);22<t<24:1.5-0.25*(t-22);t>=24:1.0. |
| 57E0B0 /15F | t<=4:1.0;4<t<=6:1+0.25*(t-4);6<t<=10:1.5-0.375*(t-6);t>10:stateFF,return. |
| 57E430 /15F | t<10:stateFF,return;10<=t<=14:0.375*(t-10);14<t<16:1.5-0.25*(t-14);t>=16:1.0. |
| 57E430 /160 | t<=28:1.0;28<t<=30:1+0.25*(t-28);30<t<=34:1.5-0.375*(t-30);t>34:stateFF,return. |

These are actor motion-coordinate windows; no elapsed wall time or game-speed meaning is assumed. NaN follows original ordered comparisons:15E in57E0B0 and15F in57E430 retain default1 through their outer less-than false path; their second motion cases reach stateFF after failed ordered<=tests. If scale differs exactly from1,18FFB0 scales XYZ basis of destination820 matrix and leaves its translation/W lanes; see [render math](SYMBOLS_RENDER_MATH.md).

57E0B0 then always copies another64 bytes from anchor model870 into pointer(actor34)->(81C+4*T3).57E430 first decrements signed halfTC and performs this second copy only when sign-extended stored result<0. Initial TC is hexadecimal10/8 (decimal16/8), selected by byte3243CC; no countdown decrement occurs on earlier timing-return paths. Once negative, it is not reset here. The tasks do not measure or adapt to actual frame rate.

The second destination translation is adjusted by vector V=(0,7.5,-7.5), first rotated in X/Z by angle=owned2pi*unsigned half(anchor92)/65536 through191BC0. Then add componentwise(V.x*anchorB4,V.y*anchorB8,V.z*anchorBC) at matrix+30/+34/+38. The actor model and anchor model pointers are not named as complete skeleton types:820/81C are pointer-field expressions indexed by4*T3, and no independent array length is established. Original renderer/upload invocation is absent from these two bodies.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Physical span | Exact data / SHA256 |
| --- | --- |
| 708D78..708D83 | float32(0.0, 7.5, -7.5); `c8dac81c6d59766f3265866faf265fc2e521f6488244df8fc2c4c7e09958c11c` |
| 708D88..708D93 | float32(0.0, 7.5, -7.5); `c8dac81c6d59766f3265866faf265fc2e521f6488244df8fc2c4c7e09958c11c` |
| 73DEF8..73DEFB | float32(6.2831854820251465,); `12d85026b5109a3119231704608d5991a63d8d397d2867a9fc522305810ddb76` |

The two vectors are separately owned identical bytes, not proof the task bodies are equivalent. Their state fields, motion windows and delayed second-copy behavior differ. [Segment/grid queries](SYMBOLS_SEGMENT_GRID_CONTACT_QUERIES.md) cover the adjacent code family separately. No matrix copy frequency, runtime cost, dropped frame, root cause or candidate engine change is claimed.

Owned-word audit:2 rows,441 distinct instruction words verified,16 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
