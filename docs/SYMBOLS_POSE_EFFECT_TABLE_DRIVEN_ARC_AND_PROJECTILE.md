# Table-driven pose arc and fixed-step projectile work

Static File #1 US owned o2 analysis, 2026-11-05. Two full original bodies, including all phase exits, table loops and shared math calls; [identity](FUNCTION_INDEX.md). No runtime measurement. Offsets, masks, table keys and phases are hexadecimal; ordinary counts marked decimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x583730](../recomp/config/output_ovl/o2/o2_00583730_0x583730.cpp) | `run_variant_table_pose_arc_then_ground_trails_and_delayed_cleanup` | Confirmed full four-phase arc and table selection; effect name unknown | Copies shared294E00 matrix each call. Phase0 enters1,clearsB,selects velocity/acceleration from variant5 or owner28 byteCF2 if variantFF, clearsCC,clearsangles90/92/94. NonFF attaches bank1 descriptor50; FF starts timerC=30 decimal/unsigned74F200 without descriptor replacement here. Emits578620 mode0 only for variant0/FF,mode1 always; sets vectors1AC/1BC=(0,0,0,50). Returns without integration. Phase1 nonzero116 immediately setsphase3,B=2,115 bit1 and skips movement. Otherwise FF timer predecrements;<=0 attaches descriptor50/bank1 and clearsvariant5, then normal motion continues.5833B0 adds rotated velocity, thenC0+=CC,C4+=D0,C8+=D4. Only when updatedC4<=0, queries floor atY+200 first mask81, thenFF unless returned81. Strict Y<floor enters2,snapsY,timerC=180 decimal/74F200,emitsmode2; returned81 additionally setsB=1 and emitsmode3. Phase2 decrementsC,negative sets115 bit1 and releases582DE0. Phase3 releases immediately. Other phases return. No render1 enable, nonzero divisor guard or finite-vector admission locally. |
| [o2 0x584250](../recomp/config/output_ovl/o2/o2_00584250_0x584250.cpp) | `advance_fifty_unit_pose_projectile_then_select_contact_replacement_and_release` | Confirmed full contact lookup and deferred cleanup | Zeroes12-byte stack vector each call. Phase0 setsF0=50 decimal,copiesXYZ tosaved44,timerC=60 decimal,enters1,spawns5DEF90(work),returns. Phase1 savesXYZ,rotates local(0,0,F0) in place by matrix50 through191A40,adds displacement toXYZ,then decrements timerC. Timer<=0 setsphase3/115 bit1 before any contact processing. Otherwise nonzero116 scans six triples708F10 bywork5. For match: all117..11A==FF,188==0 and116 in{1,2} request sound1BA5E0. Replacement descriptor>=64 enters2,clears115 bit1,attachesbank0;descriptor6B additionally6B25B0(XYZ). Smaller descriptor,including0,or no match enters3 and sets115 bit1. Phase2 enters3 and setsstop bit;phase3/otherphase calls582DE0. Contact116 is not cleared locally. Movement and timer decrement happen before contact lookup. No sweep/collision calculation or child success handling here. |

The arc uses byte values (unsigned reads; apparent negative-modulo repair branches are unreachable from those loads). For nonFF variantv:

| Field | Owned float table | Index |
| --- | --- | --- |
|C0|708E20|v%4|
|C4|708E40|v%4|
|C8|708E60|v%6|
|D0|708E90|v%5|
|D4|708EC0|v%6|

For FF use owner28 byteCF2 asv, with tables708E30,708E50,708E78,708EA4,708ED8 respectively. Original table values retained as binary32; no conversion to per-second acceleration. Owned708E20[D0 hex bytes] SHA-256 `325327e3901cfd17dac2ad516d8b5fc67eac62d39779d3e11d0bb886e0bbf4f0` contains all ten spans, including intervening padding.

Projectile triples `(class, descriptor, sound)` at708F10:

| Class | Descriptor | Sound |
| --- | --- | --- |
|14|6B|0C|
|16|64|0C|
|17|65|0D|
|18|0|0F|
|19|0|0E|
|1A|68|0C|

Owned18-byte table hex `146b0c16640c17650d18000f19000e1a680c`, SHA-256 `3a3ac76d11e4c131823508b1c094b6f29906d76ee9971e91396ba2d09ac33350`. A missing class leaves scan index6, which is below64 and follows the stop path; it does not use descriptor6.

[Pool/dispatch](SYMBOLS_SCENE_POSE_WORK_POOL_AND_CALLBACK_SERVICE.md), [arc integration](SYMBOLS_POSE_EFFECT_ARCS_TIMERS_AND_FOLLOW_WORK.md), [trail modes](SYMBOLS_SCENE_PARTICLE_TRAILS_AND_IMPACTS.md), [effect child](SYMBOLS_EFFECT_BURST_CONSTRUCTION.md) and [descriptor attachment](SYMBOLS_LINKED_VISUAL_DESCRIPTOR_POOL_AND_ATTACHMENT.md) establish connected ownership. State transitions, outer lifetime12 and inner timerC remain separate. Static branches do not establish that these effects execute in a reported slowdown or that replacing them would improve frame rate.
