# Actor interaction requests and direction replay

Static File #1 US owned o2 analysis, 2026-11-05. Five complete original intervals and owned switch/duration tables; [identity](FUNCTION_INDEX.md). No interactions, game calls or runtime inspection executed. Offsets, IDs and flags hexadecimal; counts/durationtable values decimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6A2C90](../recomp/config/output_ovl/o2/o2_006A2C90_0x6a2c90.cpp) | `hold_motion_32_then_publish_pending_code_c_until_state_one_nine` | High complete local mechanics | Common54A5,BA51,32FF,C94OR209. A0->1,BA31,clip32/0. A1ifrostertrigger74F27E:A2,E=60*unsigned74F291/unsigned74F200,C2B=C,5A6B20(actor,32);always tick0aftertrigger/wait. A2tick0,predecrementE,<=0(1,9). DirectpendingC2B differsfrom6AC7D0whichclearsit. |
| [o2 0x6A2E00](../recomp/config/output_ovl/o2/o2_006A2E00_0x6a2e00.cpp) | `select_motion_33_then_directly_handoff_to_state_one_1e_with_retained_wait_paths` | High complete local mechanics | Samecommonflagsas6A2C90. A0firstincrementsA/BA31/clip33,thenoverwrites8=1,9=1E,A=B=0andreturns,withoutstateinitializer. SeparatelyadmittedA1usestrigger/E/C2BC/request32/tick0as6A2C90;A2tick0/predecrementE<=0enters(2,5). These pathsremainlocalcontracts,notassertedreachableafteritsordinaryA0handoff. |
| [o2 0x6A2F80](../recomp/config/output_ovl/o2/o2_006A2F80_0x6a2f80.cpp) | `hide_motion_one_until_triggered_delay_then_timed_motion_eight_and_authority_route` | High complete local mechanics | Common54A5,BA51,32FF,C94OR209. A0->1,byte1=0,6AB0E0(clip1,a2=0),usinglivea1=1fromcommonsetup. A1triggernonzero:A2,byte1=1,E=60*74F291/74F200,6AC7D0(actor,0);noanimationtickinthisphase. A2predecrementE;<=0A3,E=10 decimal*unsignedBB1,clip8/0,activate. A3tick1,predecrementE,<=0 6A9490. |
| [o2 0x6A3140](../recomp/config/output_ovl/o2/o2_006A3140_0x6a3140.cpp) | `replay_roster_interaction_class_into_motion_wait_or_three_clip_chain` | High complete local mechanics | Common54AF,32FF,C94OR201;A<8uses740A30. Fullcasecontractsbelow. Interactionsetupcopiesoutputswithoutsuccesscheck;unsupportedclasses/AB8zeroarenotimplicitinitializationfailuresornewroutes. |
| [o2 0x6A35C0](../recomp/config/output_ovl/o2/o2_006A35C0_0x6a35c0.cpp) | `delay_hidden_interaction_restore_then_replay_directional_walk_until_duration_expiry` | High complete local mechanics | Common54AF,32FF. A0incrementsEeachcall;newE<300 decimalreturns. At>=300:A1,byte1=0,581730(mode2,low8(roster74F274-10),actor),unconditionallycopiesAC8yaw/ABCXYZ. A1->2,byte1=1,32FF;D45=1setsD7C1/clipC,-1D7C2/clipE,otherD7C0/clip8;activate,E=signed719700[signedrosterhalf74F28E]. A2 overrides54AC,tick1,predecrementE;<=0clear32/6A8DA0. PositiveEmaintainsD7C/D45motionmatrixbelow. Otherphasesonlycommonflags. |

6A3140 full A-case contract:

| A | Local behavior |
| --- | --- |
|0|Override54A1F,byte1=1,A1,clearAB8/AB9;581730(mode1,roster74F274,actor),copyAC8yaw/ABCXYZunconditionally. AB8zeroorAB9zeroreturn. AB9=7setsA2,D7A1,E=719700[signedroster74F28E],clip8/0/activate. AB9=1A/29setsA3,D7A1,E30 decimal,570260(actor,ABB),clip0/activate. AB9=1..6/27/28setsA5,clip57/activate. Othernonzeroclassesselectnothing. EveryadmittednonzeroAB8/nonzeroAB9paththenfallsintocase1tick;Achangeisnotanearlyreturn.|
|1|Tick1;positivesigned8resultpredecrementsE. NewE<=0 6A8DA0;positiveE6AB500(clip5,a2=0,f12=0)restarts/advancesusingoriginalhelperpolicy.|
|2|Tick1,predecrementEeverycall;<=0 6A8DA0.|
|3|Tick1,predecrementE;<=0A4,E60 decimal,clip8/activate.|
|4|Tick1,predecrementE;<=0 6A8DA0.|
|5|Tick1;positiveresultA++/clip58,withoutactivation.|
|6|Tick1;positiveresultA++/clip59,withoutactivation.|
|7|Tick1;positiveresultA2,E=719700[signedroster74F28E],clip8/activate.|

6A35C0 positive-duration direction matrix: D7C0 withD45+1 ->D7C1/clipC,with-1 ->D7C2/clipE. D7C1 withD450 ->D7C0/clip8,with-1 ->D7C2/clipE. D7C2 withD450 ->D7C0/clip8,with+1 ->D7C1/clipC. Everylistedchangeactivates58C7B0;otherpairsreturnwithoutclipchange. No positionintegrationorrotationchangeinthismatrix.

Owned740A30[8]={6A3194,6A336C,6A33D4,6A3410,6A3470,6A34AC,6A34F0,6A3534},SHA-256`f22a0f6c7fe5e6d89252a85df586dad1db4357c3cebda20919fed379a6c91ca7`. Owned719700[8signedhalves]={60,55,50,45,70,70,75,80},hash`424edea7f65b420dd9b5556eeaeee1189474da9df8136830bd596bbace78a52a`. Callers use a signedrosterhalfwithoutlocalbounds;theeight-valueownedspanisnotanall-inputguarantee.

[Interactionadapter](SYMBOLS_LINKED_INTERACTION_PROXY_QUERIES.md), [rostertriggerfamily](SYMBOLS_O2_ACTOR_696300_ROSTER_TRIGGERED_HOLD_AND_INTERACTION.md), [authoritybanks](SYMBOLS_ACTOR_DEFAULT_AUTHORITY_BANKS.md), [motionpolicy](SYMBOLS_ACTOR_MOTION_RESPONSE_INCLINE.md) establishchildcontracts. Retainedrawstateassignments,helperfailurebehaviorandfallthroughsareevidenceforlaterreconstruction,notobserveddefectsorlatency.
