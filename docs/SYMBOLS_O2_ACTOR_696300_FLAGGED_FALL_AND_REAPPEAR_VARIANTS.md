# Actor flagged falling and reappearance variants

Static File #1 US owned o2 analysis, 2026-11-05. Six complete original bodies and two bounded switch tables; [identity](FUNCTION_INDEX.md). No game, flag, floor query or animation execution. Offsets/masks/IDs hexadecimal; marked numerators/counts/frame values decimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6A4D00](../recomp/config/output_ovl/o2/o2_006A4D00_0x6a4d00.cpp) | `hide_until_trigger_delay_then_timed_motion_a_and_authority_reset` | High complete local mechanics | Common54A5,32FF,C94OR201,withoutBA5write. A0hiddenwaitstrigger74F27E;nonzeroA1/E=60*74F291/74F200,6AC7D0(actor,0). A1predecrementE;<=0A2,E=60 decimal*BB1/74F200,byte1=1,clipA/activate. A2tick1,predecrementE<=0 6A8DA0. Unlike6A3900,timerforclipAisservicebased,notfourresult1cycles. |
| [o2 0x6A4EA0](../recomp/config/output_ovl/o2/o2_006A4EA0_0x6a4ea0.cpp) | `wait_trigger_and_flag_then_play_motion_24_fall_land_and_hide` | High complete local mechanics | Common54A5,32FF,C94OR209;A<8table740A70. Fullcasechainbelow. BA5setonlybyfall/landingcases,notcommonheader. |
| [o2 0x6A51E0](../recomp/config/output_ovl/o2/o2_006A51E0_0x6a51e0.cpp) | `wait_trigger_delay_then_choose_timed_motion_or_special_scene_clip_chain` | High complete local mechanics | Common54A5,BA51,32FF,C94OR209;A<6table740A90. A0hidden/triggerwait,nonzeroA1/E=60*74F291/74F200,6AC7D0(actor,0). A1predecrementE;<=0visible1. If3243DA/DC/DEall==1 setsA3/clip36(noactivation). OtherwiseA2/E=60*BB1/74F200,6AB600(8,0),activate. A2tick1/predecrementE<=0 6A8DA0. A3tick1,positiveA4/clip8;A4tick1,positiveA5/clip68;A5tick1,positive(4,C). Noactivationforlatterclipchanges. |
| [o2 0x6A54A0](../recomp/config/output_ovl/o2/o2_006A54A0_0x6a54a0.cpp) | `hide_motion_24_start_frame_fifty_until_trigger_delay_then_action_two_a` | High complete local mechanics | Common54AD,BA51,32FF,C94OR209. A0->1,6AB500(24,0,start50 decimal),fallsimmediatelyintoA1hiddenwait. TriggernonzeroA2/E=60*74F291/74F200,6AC7D0(actor,1). A2predecrementE;<=0byte1=1,6AA3C0(actor,2,A),usinglivea1=2fromfunctionentry. Noanimationtickinthisbodybeyondmotionselection. |
| [o2 0x6A5600](../recomp/config/output_ovl/o2/o2_006A5600_0x6a5600.cpp) | `wait_hidden_for_trigger_delay_then_direct_state_two_b` | High complete local mechanics | Common54AD,BA51,32FF,C94OR209. A0->1andfallsintohiddenwait. TriggernonzeroA2/E=60*74F291/74F200,6AC7D0(actor,1). A2predecrementE<=0visible1,direct8=2,9=B,A=B=0usinglivea1=2;no6AA530initializer. Noanimationselectionorticklocally. |
| [o2 0x6A5740](../recomp/config/output_ovl/o2/o2_006A5740_0x6a5740.cpp) | `play_random_motion_58_until_triggered_delay_set_flag_and_motion_59_exit` | High complete local mechanics | Common54AD,BA51,32FF,C94OR209. A0->1,byte1=1;BB1nonzero/setflagsetsA3,clip0/0,6AC7D0(actor,1),returns. Otherwiseclip58start(RNG1low16%80),activate. A1tick1;triggernonzeroA2/E=60*74F291/74F200(no6AC7D0here). A2tick1/predecrementE<=0A3;BB1nonzero/unsetflag5703E0(BB1,1),then6AC7D0(actor,1),clip59/0withoutactivation. A3tick1,positive(1,1). |

6A4EA0 casechain:

| A | Local behavior |
| --- | --- |
|0|byte1=0;BB1flagincluding0alreadysetA7,return. Elsetrigger74F27EnonzeroA1/byte1=1/clip0/activate.|
|1|Tick1;BB1flagsetA2/E=60 decimal*BB2/74F200,clip8/activate.|
|2|Tick1,predecrementE;<=0A3/clip24withoutactivation.|
|3|BA51,tick1;frame>=40 decimalA4,D0=-12.|
|4|BA51;tick1onlyifframe<50 decimal,queryfloorFF,Y+=D0. NewY<=height:A5/Ysnap. AlwaysD0-=4.5/clamp<=-300,includinglandingcall.|
|5|BA50,tick1;positiveA6/clip33/activate.|
|6|Tick1only;noautomaticphaseadvanceorhide.|
|7|byte1=0only.|

Owned740A70[8]={6A4F00,6A4F94,6A5030,6A5080,6A50C8,6A515C,6A51A8,6A51C0},SHA-256`d814415b988ccea1716c9a0dfbf1d796d45ccd2e631e74b16d127e8d0a4254aa`;740A90[6]={6A5248,6A52DC,6A5398,6A53D4,6A5418,6A545C},hash`8c1bdbdb1c2479aa38b4d3f4516a1031f3df2b2a4016507fd588300f1617cc13`. Out-of-rangeAreturnsaftercommonflags. Allrosterfieldsuse96 decimal-byte stride;timerstoresretain16-bitnarrowingandunsigned74F200divisorwithoutlocalzeroguard.

[Triggeredduration](SYMBOLS_O2_ACTOR_696300_ROSTER_TRIGGERED_HOLD_AND_INTERACTION.md), [flaggeddescent](SYMBOLS_O2_ACTOR_696300_FLAG_EXIT_ROUTE_AND_DESCENT.md), [action/requesthelper](SYMBOLS_ACTOR_ACTION_ADMISSION_TURN.md), [scenarioflagnotification](SYMBOLS_TASK_FLAGS.md) establishconnectedcontracts. State/registervaluesarepreservedinstead ofguessedfromnearbyconstants. Noautomaticblank-screenorhangdiagnosisandnotestedfixclaimed.
