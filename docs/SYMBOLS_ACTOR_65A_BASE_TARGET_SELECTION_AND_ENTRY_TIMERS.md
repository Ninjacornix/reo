# Actor65A base/target selection and state-entry timers

Static File #1 US owned o2 analysis, 2026-11-05. Seven complete original bodies and their owned timer jump table. [Identity](FUNCTION_INDEX.md). No game execution, live reads, attachment or implementation change. Offsets, masks and states are hexadecimal; distances and timer quantities are decimal unless marked otherwise.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x65A170](../recomp/config/output_ovl/o2/o2_0065A170_0x65a170.cpp) | `select_actor_base_state_with_scene_override_random_idle_and_previous_state_restore_phase` | Confirmed full state-selection tree; original behavior name partial | Scenario1/room12 first calls65D980; nonzero signedlow8 result returns unchanged afterward. Otherwise saves8/9 toBE8/BE9,clearsA/B. Priorprimary1/secondary<4 chooses RNG1 nibble:0->base0,1->1,2->3,others->2; stores only byteBA0. Otherpriorstates storebyteBA0=0. Setsprimary1,secondary=byteBA0; saved(1,5) setsA=A.65AC40 initializes entry timer/variant,C36=7. Upperbytes of wordBA0 remain intact. |
| [o2 0x65A2B0](../recomp/config/output_ovl/o2/o2_0065A2B0_0x65a2b0.cpp) | `select_actor_target_response_then_adjust_approach_turn_and_restore_phase` | Confirmed full score/response/postselection policy | Nullrelated24 returns. Saves8/9,clearsA/B. SignedscoreBF8+20 decimal*C25+2*C26<250 calls65A170 and returns. Otherwise65A6B0; negative signedlow8 result returns. New(2,0) forces(1,5,A=5) unless saved(1,5). New(1,5) withBD8 outside inclusive[-800hex,800hex] becomes(1,8,A0,B=oldsecondary5); inside interval goes directly entry setup. Remaining branch saved(1,5),newprimary1,newsecondary!=5 setsA=A.65AC40 thenC36=7. No score-pool/index bounds or normalization of child state. |
| [o2 0x65A440](../recomp/config/output_ovl/o2/o2_0065A440_0x65a440.cpp) | `choose_actor_approach_or_attack_state_from_target_distance_bearing_and_alignment_mode` | Confirmed complete geometric decision tree | Requiresrelated24. TargetBA0 bit2000000 selectsprimary1/secondary5 whenBD4<=BBC,else4,without recomputingBBC. OtherwiseBBC=191D10(actorXYZ,ownmodel34->884.translation)+180. BA3=0:BD4<=BBC ->(2,0); otherwiseBD4<=700,BD8 strictly inside(-800hex,800hex),abs(targetY-ownY)<20 ->(2,1); remainingBD4<=700 ->(1,6),greater/unordered ->(1,7). BA3=1 buildsP=XYZ+(0,-100,0),bearing65DA50(actor,P),signed16bearing-yaw. Within[-2000hex,2000hex],BD4 in[200,500],and200<Y-D28<500 selects(2,2). Otherwiseprimary1,random1lowbit choosessecondary6 if1 else4. OtherBA3 values select(1,4). Does not initializeA/B/timers itself. |
| [o2 0x65A6B0](../recomp/config/output_ovl/o2/o2_0065A6B0_0x65a6b0.cpp) | `map_interaction_response_code_to_actor_approach_attack_or_base_state` | Confirmed complete response mapping | Missingrelated24 returns0 without state writes. Otherwise clearsA/B and calls5A62D0(actor,2AA8,19,f12=BC0), signedlow8codeR. R1 chooses(1,6) ifrand1nibble<10 else(1,7). R2 ->(1,9). R3:randnibble<10,targetBA0bit2000000clear,savedBE8!=2 invokes65A440; otherwiseBD4<=BBC ->(1,5),else(1,4). R4 invokes65A440. Othercodes,includingnegative,select(1,4). Returns original signedR, not chosenstate. No entry timer initialization here. |
| [o2 0x65A9E0](../recomp/config/output_ovl/o2/o2_0065A9E0_0x65a9e0.cpp) | `save_actor_state_set_primary_secondary_and_initialize_entry_policy` | Confirmed complete transition adapter | Saves8/9 toBE8/BE9; writeslow8a1/a2 to8/9,clearsA/B,65AC40,C36=7. No validation, state publication or animation selection directly. |
| [o2 0x65AA30](../recomp/config/output_ovl/o2/o2_0065AA30_0x65aa30.cpp) | `choose_actor_entry_variant_from_state_motion_bearing_distance_and_rng` | Confirmed full variant-only policy | ModifiesbyteB only for listedstatecases below. Allrandomdraws use1AEC80(stream1),low16 masking before modulus. Otherstates retainB; no primary/secondary/phase changes. |
| [o2 0x65AC40](../recomp/config/output_ovl/o2/o2_0065AC40_0x65ac40.cpp) | `initialize_actor_state_entry_timer_then_choose_variant` | Confirmed complete table/arithmetic policy | SetsE=0 then state-specific timer below. Primary1secondary<13hex usesowned19-target jump table740260;otherprimary1 keeps0. Primary2secondary1/2 E=(rand1%90)/unsigned74F200. Primary4secondary0/3:health544>0 E=634880(actor,C2A),else-1. Primary5secondary6 E=634880(actor,C2A). Others0. Always65AA30 afterward. Alltimerstoreslow16; no global divisor-zero guard. |

65AA30 variant selection:

| Primary / secondary | B assignment |
| --- | --- |
|1/0|rand%3|
|1/3|rand&1|
|1/4|rand%3|
|1/5|Only if signedcurrentmotion520 in3..5:rand%3;otherwise retainB|
|1/9|BD8>0 ->1,else0|
|2/1|BD4<=300 ->0,else1|
|3/0|currentmotion520 in3..5 ->2+(rand&1),else rand&1|
|4/3|rand&7|
|others|RetainB|

Primary1 entry timers in65AC40, using unsignedglobalG=74F200 andR=rand1low16:

| Secondary | E |
| --- | --- |
|0|634AB0(actor), preserving its returnedlow16|
|2,4,6,A,B,11|(120+R%180)/G|
|3,5,7,8|(60+R%60)/G|
|9|(30+R%30)/G|
|12|(300+R%300)/G|
|1,C..10|0|

All secondary values in this table are hexadecimal.19-entry740260[76] SHA-256 `cea90b167477134d8cd44463e5997d106c463105c7ac6f655d6709bb6bdd1664`; targets0..12:65ACB0,65AEAC,65ACC0,65AD00,65ACC0,65AD00,65ACC0,65AD00,65AD00,65AD40,65ACC0,65ACC0,65AEAC,65AEAC,65AEAC,65AEAC,65AEAC,65AD80,65ADC0. Owned712648[12] vector(0,-100,0),SHA-256 `553a99ba38959fb15635005537467fdb04d6906bc901e95e1ac7520e18f893a2`.

[Interaction classification](SYMBOLS_ACTOR_RESPONSE_RECORD_EVENTS.md), [score admission](SYMBOLS_ACTOR_TARGET_SCORE_ADMISSION.md), [difficulty timers](SYMBOLS_ACTOR_RESPONSE_TIMERS_AUTHORITY.md) and [base-state consumers](SYMBOLS_ACTOR_655D40_BASE_STATES_AND_MOTION_TRANSITIONS.md) supply connected roles. Random branch frequencies, complete actor taxonomy and observed state progression remain unmeasured; no player-input or original game-speed change is proposed.
