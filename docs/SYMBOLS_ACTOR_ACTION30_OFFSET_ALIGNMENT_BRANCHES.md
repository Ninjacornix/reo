# Action30 offset alignment and frame130 branch policies

Static File #1 US owned o2 analysis, 2026-11-05. Complete 5898B0 original body, [identity](FUNCTION_INDEX.md). Offsets/states hexadecimal; lengths/timings decimal. No game execution.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5898B0](../recomp/config/output_ovl/o2/o2_005898B0_0x5898b0.cpp) | `align_action30_to_offset_goal_then_choose_c1_bf_or_c0_at_frame130` | Confirmed complete five-phase and delegated-alignment flow | Everycall54A OR1F,byte32=FF.6673C0 consumedflag immediatelyclears54F/548bit1,sets1/0/A1/B0,savepose,defaultmotion2050/blend10,activate,return. Normalphase0sets54F30,D10=1,savepose,zero4E4XYZ;goalC34=(ABC,currentY,AC4),goalyawC4C=lowAC8. Rotateslocal(10,0,0)byunsignedgoalyaw usingowned2pi/65536,addsgoaloffset. XYZdistance191D10(goal,current)<=40 setsA1;else66DD50(actor,0),ignoringinitialresult. Unrecognizedphasesdelegate66DD50,nonzeroresultsetsA1 andC=300. Phase1enters2,flags82,selects709280/f12=0/blend10,cachesstartXYZC40/yawC4E,timer12=20 if3243CC0 else10.1925C0 onmodel34->824 evaluatesmotiontranslationdifference start0/end20,rotatesbygoalyaw,andaddsgoal. Phases2/3/4 applysamecurvedXYZ/yawtimerlogicbelowthenframebranchbelow. No localparent/modelbounds or generalcompletionboolean. |

The three full alignment blocks at phases2/3/4 preserve the same explicit steps:oldtimer12!=0 storesdecrement,usescurrentclockduration20/10 andelapsed=duration-newtimer in665E60/665FC0,zeroes4E4XYZ,newtimer0snapstoXYZ/yawgoal. Oldtimer0skipsinterpolationandsnap;negativeoldtimerisnotrejected. These are cubic helpers withguestnormalization/wrap behavior, not assumed host lerp. Clockmodeisread eachcall;changing it midsequence isnotlocallyprevented.

Afteralignment:

| Phase | Original frame predicate and resulting work |
| --- | --- |
|2|Frame1E4<130 skipsstatechange;otherwise(includingunordered)enters1/C1,A/B0,savepose. BOTHpaths then58C300(step1),soanewstatecanalreadybeinstalledbeforethetick. No67E230here.|
|3|Frame<130ticks1.Otherwiseenters1/BF,A/B0,savepose,67E230(actor,1),returnWITHOUTtick.|
|4|Frame<130ticks1.Otherwiseenters1/C0,A/B0,savepose,67E230(actor,1),returnWITHOUTtick.|

The body doesnotitselfselectphase3/4fromphase2;connected [probability/frame-window chooser](SYMBOLS_ACTOR_METRIC_ROSTER_WAIT_AND_TIMING_WINDOWS.md) maysetthosephases. Alignment delegation can also use its own phases;theunrecognizedcaseisnotempty. TimerC=300 ondelegatedcompletionisnotdecrementedbythisbody.

Owned709280[8] bytes`1000000079037903`,motionhalf6=0379, SHA-256 `2c7f5f40219c5b16d86647aee200e2b441ce0d824e5d0354d30d7c590bc887ab`. Shared2piat73E068 hasSHA-256 `12d85026b5109a3119231704608d5991a63d8d397d2867a9fc522305810ddb76`. [Connected curved motion/event completion](SYMBOLS_ACTOR_ACTION30_EVENT_COMPLETION_AND_CURVED_ALIGNMENT.md) establisheshelpercontractsandtheindependentstaticcase. No reproducedstateorderingdefectorperformancegainisclaimed.
