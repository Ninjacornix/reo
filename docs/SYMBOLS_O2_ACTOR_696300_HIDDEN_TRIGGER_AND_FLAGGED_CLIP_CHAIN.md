# Actor hidden trigger waits and flagged clip chain

Static File #1 US owned o2 analysis, 2026-11-05. Six full original bodies and bounded seven-entry switch; [identity](FUNCTION_INDEX.md). No runtime, game, flag mutation or timing test. Offsets/masks/IDs hexadecimal; explicitly marked numerators and counts decimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6A3900](../recomp/config/output_ovl/o2/o2_006A3900_0x6a3900.cpp) | `hide_until_roster_trigger_delay_then_play_four_motion_a_cycles` | High complete local mechanics | Common54A5,32FF,C94OR201,BA51. A0forcesbyte1=0,waitstrigger74F27E;nonzeroA1,E=60 decimal*unsigned74F291/unsigned74F200,6AC7D0(actor,0). A1predecrementsE;<=0A2,E4,byte1=1,clipA/0,activate. A2tick1;onlysigned8result1 decrementsE,<=0(4,C). Noanimationtickintriggerorinitialdelayphases. |
| [o2 0x6A3AA0](../recomp/config/output_ovl/o2/o2_006A3AA0_0x6a3aa0.cpp) | `force_hidden_actor_until_triggered_delay_then_reenable_and_authority_reset` | High complete local mechanics | Everycallbyte1=0,54A5,32FF,BA51,C94OR209. A0triggernonzeroA1/E=60*74F291/74F200,6AC7D0(actor,0). A1predecrementsE;<=0setsbyte1=1then6A8DA0. Noanimationselection/tickhere;latercallbackcommonhiddenwritecanoverridevisibilityunlessstatechanges. |
| [o2 0x6A3BC0](../recomp/config/output_ovl/o2/o2_006A3BC0_0x6a3bc0.cpp) | `hide_for_triggered_delay_then_motion_36_and_68_to_state_four_c` | High complete local mechanics | Common54A5,BA51,32FF,C94OR209. A0byte1=0/triggerwait;nonzeroA1/E=60*74F291/74F200,6AC7D0(actor,0). A1predecrementE<=0A2,byte1=1,clip36/activate. A2tick1,result1A3/clip68/activate. A3tick1,result1(4,C). Noanimationsampledinthefirsttwophases. |
| [o2 0x6A3DA0](../recomp/config/output_ovl/o2/o2_006A3DA0_0x6a3da0.cpp) | `run_triggered_motion_36_8_57_58_chain_then_publish_flag_and_exit` | High complete local mechanics | Common54A5,BA51,32FF,C94OR209,A<7table740A50. Fullcasechainbelow. FinaleventusesBB1evenwhen0,unlike6A2950zero-skip. |
| [o2 0x6A40E0](../recomp/config/output_ovl/o2/o2_006A40E0_0x6a40e0.cpp) | `publish_action_request_then_directly_select_state_one_b_without_initializer` | High complete local mechanics | Sets54A5,BA51,32FF,C94OR201,6AC7D0(actor,0),then8=1,9=B,A=B=0directwrites. No6AA530stateinitializationcalled. |
| [o2 0x6A4150](../recomp/config/output_ovl/o2/o2_006A4150_0x6a4150.cpp) | `show_motion_eight_then_hold_control_override_with_continuous_animation` | High complete local mechanics | Common54A5,BA51,32FF,C94OR209. A0->1,byte1=1,clip8/0,activate. A1C82=1,tick1;noresult/timerexit. Otherphasesonlycommonflags. DoesnotitselfwaitonUIorblockathread. |

6A3DA0 casechain (allnumbershexunlessmarked):

| A | Local behavior |
| --- | --- |
|0|byte1=0,C370;trigger74F27EnonzeroA1,E=60 decimal*74F291/74F200. No6AC7D0publicationatthistransition.|
|1|PredecrementE;<=0A2,byte1=1,clip36/0,activate.|
|2|Tick1;result1A3/clip8,withoutactivation.|
|3|Tick1;positivesigned8resultA4/clip57,activate.|
|4|Tick1;result1A5,E=60 decimal*unsignedBB2/74F200,clip58,activate.|
|5|Tick1,predecrementE;<=0A6,test4B9C00[BB1]evenBB1zero,ifunset5703E0(BB1,1),clip68,activate.|
|6|ClearC94bit8,tick1;result1 6AC7D0(actor,0),then(4,C). Parentcommon8canbeoverriddenonlyhere.|

Owned740A50[7]={6A3E08,6A3E98,6A3EE0,6A3F28,6A3F74,6A3FF0,6A4084},SHA-256`e00ebe5e9acc3e078511f9db8404066112f43ca3a8816124c3214462385ce8f3`. A>=7returnsaftercommonflags;clippoliciesretaina2=0. Allrosteraccessesuse96 decimal-byte stride;zerofactor74F200notlocallyguarded.

[Trigger/interactionreplay](SYMBOLS_O2_ACTOR_696300_ROSTER_TRIGGERED_HOLD_AND_INTERACTION.md), [earlierflaggedclipchain](SYMBOLS_O2_ACTOR_696300_TRIGGERED_CLIP_FINISH_VARIANTS.md), [actionrequest](SYMBOLS_ACTOR_ACTION_ADMISSION_TURN.md), [scenarioflagnotification](SYMBOLS_TASK_FLAGS.md) providechildcontracts. Hiddenvisibilityandrepeatedcallbackmotionaremeasuredonlyasstaticwrites;noobservedblank-screenincidentorrootcauseattributionclaimed.
