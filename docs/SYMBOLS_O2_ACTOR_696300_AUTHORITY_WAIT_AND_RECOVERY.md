# Actor authority-gated waits and recovery transitions

Static File #1 US owned o2 image, 2026-11-05. Four complete catalogue intervals, including large switch bodies and dispatch binding, checked against [identity](FUNCTION_INDEX.md). No gameplay/authority changes, process inspection, timing or native replacement. Offsets and masks hexadecimal; constants explicitly decimal where appropriate.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6A0260](../recomp/config/output_ovl/o2/o2_006A0260_0x6a0260.cpp) | `dispatch_primary_four_states_and_run_motion_32_authority_wait_recovery` | High complete local mechanics | Entrytaildispatch718AF0[unsigned9]. Included6A0280 setsC94OR201,54A4;health544<=0sets32FF;roster74F295[96 decimal*B98]clears8. UnsignedA<7admits7409B0switch. Fullcasecontractsbelow. No secondary/B98bound;highAreturnsaftercommonflags. |
| [o2 0x6A0630](../recomp/config/output_ovl/o2/o2_006A0630_0x6a0630.cpp) | `play_motion_37_then_clear_pose_mode_and_return_to_primary_one` | High complete local mechanics | Everycall54A4. A0->1,BA3=2,6AB600(37,0),ownerbyte3B5050[B98]=FF,C2E=0;returns. A1tick1,positiveclearsBA3andenters(1,0). OtherwisenonzeroD45/frame1E4>50 decimal calls6ABFB0inclinedecay. No bankactivationonentry. |
| [o2 0x6A0720](../recomp/config/output_ovl/o2/o2_006A0720_0x6a0720.cpp) | `run_motion_33_authority_wait_and_recover_to_state_four_three` | High complete local mechanics | SamecommonC94/54A/health32/rosterflagsas6A0280;unsignedA<7uses7409D0. Sharedseven-casepolicybelowwithclip33,BA3=1,recoverystate(4,3). Importantcase2authority-exitexplicitlytick0after6AA3C0;32variantreturnswithouttickthere. |
| [o2 0x6A0AD0](../recomp/config/output_ovl/o2/o2_006A0AD0_0x6a0ad0.cpp) | `play_motion_36_with_initial_held_tick_then_clear_pose_mode_and_return` | High complete local mechanics |54A4. A0->1,BA3=1,6AB600(36,0),immediatetick58C300(0),owner3B5050[B98]=FF,C2E0,return. A1tick1,positiveBA3=0/(1,0),elsenonzeroD45/frame>50calls6ABFB0. Initialheldtickisadditionalto6AB600selection. |

For6A0280 useclip32,poseBA3=2,recoverysubstate1;for6A0720 useclip33,poseBA3=1,recoverysubstate3. CasesareoriginalAindices:

| A | Complete local contract |
| --- | --- |
|0|A=1,posemode,6367C0clearsroute-scores/holdtimer. Bnonzero6AB0E0(clip,0),Bzero6AB600(clip,0);activate58C7B0. Health<=0overridesA=3afterselection;noanimationtickhere.|
|1|IfE>=0decrementE;negativeEretained.640640authoritynonzero andE<0clearrosterstatusbyteentirely,6AA3C0(4,recoverysubstate). Otherwisepredecrement/narrowC;negativeCsetsA2. Boththetransitionandwaitpaththen58C300(0).|
|2|IfE>=0decrementE. Authority/E<0clearrosterstatusand6AA3C0(4,recoverysubstate);32variantreturns,33variantaddstick0. Otherpathstick1;onlysigned8result1setsA1,C=((RNGmode1low16%120 decimal)+60 decimal)/unsigned74F200.|
|3|Authority640640 ANDowner3B5050[B98]==FF:clearrosterstatusbyte,restorehealth544fromsigned74F26E[96*B98],save8/9toBE8/BE9,set8=4,9=recoverysubstate,A0;6AA530initializescounters,6AC640(selector3). Bothadmittedanddeniedpathstick0afterward.|
|4|Noopaftercommonflags.|
|5|A3,6AB0E0(clip,0),posemode;noactivation/tick.|
|6|A1,E=634880(actor,C2A),C=((RNG1low16%120)+60)/74F200,6AB0E0(clip,0),posemode;noactivation/tick.|

Alltimerstoresnarrow16bits;Eisdecrementedonlywhileitsoldvalue>=0,Cmayunderflow/wraponrepeatedphase1calls. Zero74F200 is not guarded here. Phase2motionboundaryandphase1timeradvancearedistinctconditions;theyarenotcounts ofglobalgameupdates.

Owned7409B0[7]={6A0304,6A036C,6A0408,6A04D0,6A0614,6A0588,6A05AC}, SHA-256 `9bcb81d1e018e42cb03bff2b8746e6ee4beca69bf69dfb4e8452e54555397b4d`;7409D0[7]={6A07A4,6A080C,6A08A8,6A097C,6A0AC0,6A0A34,6A0A58},hash`2724da0ca18355916e93ecdfb530e8fd79fd8fbe84e5a453e1bb72c4e11bac83`.718AF0starts13nonnullstates{6A0280,6A0630,6A0720,6A0AD0,6A0BC0,6A0C60,6A0D10,6A0DC0,6A0F70,6A1120,6A12B0,6A1570,6A1650},then3NULLwords. No dispatcherboundchecks.

[Stateparameterinitialization](SYMBOLS_ACTOR_ACTION_STATE_INITIALIZATION.md), [timerscale](SYMBOLS_ACTOR_RESPONSE_TIMERS_AUTHORITY.md), [scores](SYMBOLS_ACTOR_ROUTE_SCORE_UTILITIES.md), [inclinedecay](SYMBOLS_ACTOR_MOTION_RESPONSE_INCLINE.md), [eventselector](SYMBOLS_ACTOR_ACTION_ADMISSION_TURN.md) providechildcontracts. Numericrecovery/healthstatesdonotestablishoriginalactionnamesorareproducedhang.
