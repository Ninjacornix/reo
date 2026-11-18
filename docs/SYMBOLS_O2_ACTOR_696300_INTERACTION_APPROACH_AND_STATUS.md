# Actor interaction approach and status branches

Static File #1 US owned o2 analysis, 2026-11-05. Five complete catalogue bodies, including the interior dispatcher/initializer at6A5E40/60; [identity](FUNCTION_INDEX.md). No target execution or live data. Offsets/IDs hexadecimal; distances, step sizes and timer numerators decimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6A5E20](../recomp/config/output_ovl/o2/o2_006A5E20_0x6a5e20.cpp) | `dispatch_actor_primary_seven_secondary_and_interaction_approach_phases` | High complete local mechanics | Tail dispatch718C10[byte9]. Included6A5E40 dispatch719750[byteA]. Included6A5E60 incrementsA,setsC82=1,clip5/0,activates58C7B0,andclearsC37. Neither dispatcher locally bounds index; owned pointer windows below do not prove admission. |
| [o2 0x6A5EB0](../recomp/config/output_ovl/o2/o2_006A5EB0_0x6a5eb0.cpp) | `turn_toward_interaction_yaw_and_step_toward_goal_independently` | High complete local mechanics | 54A4/C82=1; signedlow16(AC8-yaw92) turn6AC130(step80hex),completedturn incrementsA regardless distance. HorizontalD48/D50 distance<=5 skipsmovement;otherwise adds5*sin/cos(goalbearing) toXZ. Alwaystick1. NoYmove,snap or overshootclamp. Goal arrival alone does not advance phase. |
| [o2 0x6A5FC0](../recomp/config/output_ovl/o2/o2_006A5FC0_0x6a5fc0.cpp) | `probe_forward_interaction_choose_wait_or_clip_and_continue_goal_step` | High complete local mechanics; narrative roles unknown | C82=1/54A4; rotate local(0,0,70),addXYZ,clearAB8/9,query5DC570(point,actor,4,radius50). AB8/AB9 plus581DC0(AD0) choose branches below. All ordinary branches then stepXZ5 towardD48 goal when distance>5. AB9zero state7/3 branch exits beforemovement. No58C300 tick inthisbody. |
| [o2 0x6A63C0](../recomp/config/output_ovl/o2/o2_006A63C0_0x6a63c0.cpp) | `advance_interaction_wait_then_unpack_endpoint_and_route_transition` | High complete local mechanics | 54AF,32FF,C94OR201,tick1;predecrementE,positive return. Expiry581B60(AD0,&kind,&node,&third):failure6AA3C0(7,2);success/kind0 calls6A9490;success/kind!=0 calls6AC040(actor,node,AD0). Third byte unused. No local reseeding ofE. |
| [o2 0x6A6480](../recomp/config/output_ovl/o2/o2_006A6480_0x6a6480.cpp) | `advance_motion_then_route_interaction_status_to_bound_wait_or_flag_delay` | High complete local mechanics | 54AC,tick1;581DC0(AD0). Status1/6 setsA3,D7A1,E=120/74F200,32FF,clip8/activate,6B5920(actor,AD0). Status4 setsA5,D7A1,E30,32FF,570260(actor,ABB),clip0/activate. All other values,including5,return. No approach movement here. |

6A5FC0 decision tree after the side-effecting point query:

| Query outputs/status | Transition |
| --- | --- |
|AB8!=0,AB9=0|6AA3C0(actor,7,3),usinglivea1=7/a2=3;exitbeforegoalstep.|
|AB8!=0,AB9=7|A3,D7A1,E=120/unsigned74F200,32FF,clip8/0,activate,6B5920(actor,AD0).|
|AB8!=0,AB9=1A/29,status1/6|Samephase3setup.|
|AB8!=0,AB9=1A/29,status4|A5,D7A1,E30,32FF,570260(actor,ABB),clip0/0,activate.|
|AB8!=0,AB9=1A/29,status5|A4,clip0/0,activate;noD7A/Ewrite.|
|AB8!=0,AB9=1A/29,otherstatus|A6,clip57/0;noactivationandnoD7A/Ewrite.|
|AB8!=0,AB9in1..6,27,28|A6,clip57/0;noactivation.|
|AB8!=0,otherAB9|Noactionchange.|
|AB8==0|581DC0(AD0)status1/6takesphase3setup;otherstatusnoactionchange.|

The goal step can occur in the same call as a new clip/phase selection. Radius/offset geometry does not make5DC570read-only: it publishes selected proxy state and dispatches callbacks.581DC0 numeric values derive from room masks and scene slots, not a guessed interaction enum.581B60 success withkind0 can leave other outputbytes untouched, but6A63C0 does not consume those bytes on that branch.6B5920 selects/binds a scene matrix program; no audio/event name inferred.

Owned pointer windows:718C10[8]={6A5E40,6A6AD0,6A6F60,6A7060,6A7210,6A7BE0,6A7F30,0},SHA-256`59ec24b6265589d84d8b63a16e1cf8adc6f0e2e8bcfc464df6303a6565a3665b`;719750[8]={6A5E60,6A5EB0,6A5FC0,6A63C0,6A6480,6A65A0,6A6640,6A66C0},hash`cf981576f24ae3c0880bafb1f95db3611e9229965fad82eb455c96fd318756ce`. These are explicitly bounded windows, not proven whole allocation extents. No bound appears in localdispatch.

Connected contracts: [proxy selection/status](SYMBOLS_LINKED_INTERACTION_PROXY_QUERIES.md), [scene program binding](SYMBOLS_SCENE_MATRIX_PROGRAM_SELECTION.md), [motion and route publication](SYMBOLS_ACTOR_MOTION_RESPONSE_INCLINE.md), [state initialization](SYMBOLS_ACTOR_ACTION_STATE_INITIALIZATION.md), and [later related interaction bank](SYMBOLS_ACTOR_INTERACTION_PHASE_ROUTING.md). All timer/divisor arithmetic retains original signed halfword narrowing and lack of local zero guard. No observed incident or fix claimed.
