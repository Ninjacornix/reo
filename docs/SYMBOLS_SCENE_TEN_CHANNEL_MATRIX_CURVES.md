# Ten-channel scene matrix curve task

Static File #1 US research, 2026-11-04. One complete large original body reviewed.
Addresses/offsets/constantshex; channelcountten andscalarvaluesdecimal.
No targetexecution,profilingorfixes. Curvebankformatrolecandidate.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B7000](../recomp/config/output_ovl/o2/o2_006B7000_0x6b7000.cpp) | `tick_ten_channel_scene_curve_matrix_task_and_release_bound_slot_candidate` | High mechanics; probable role | task8phases0/1/2;boundslotbyte6,matrix49EEF0+B20+40*slot. Phase0predec10,signednegativeclearsC/E/10,8++,copies64-byteslotmatrixtotask30,fallsphase1. Phase1reads10channeloffsetsstride8fromtask24;nonzerochannelusesRDT324424+8000+offset,interpolatesvaluebetween(floatvalue,signedframetime)8-bytekeysuntilnexttime>taskCorterminalnexttime-1. Zeropointercountsfinishedwithvalue0;terminalkeycountsfinishedanduseslastvalue. IncrementstaskC,builds190670matrixfromchannels0/1/2,composeswithboundmatrixintotask30;channels3/4/5addboundtranslationintotask60XYZ,Wfrombounds. Channel9exactkeytime==Cplays1B8930(task60,intvalue). All10finishedsets8=2. Phase2task24word4nonzerocopies64bytestask30backtobounds,then5D8300(slot),573740(task). |

Thefullten-channelkeywalkwasreviewed,includingterminal-1checksandframe
incrementafteraudio. Channel6/7/8areevaluatedbutnototherwiseconsumedinthis
body. Actor/matrixidentity,curveclockrate,keycount/offsetboundsandrecorder
frequencyremainunknown. No implicitclamponequalkeytimesorloopcapadded.
Task24andRDTcurvebytesareoutsideownedo2staticdata;nonewereinspectedlive.
Related[modelcurvetasks](SYMBOLS_BOUND_MODEL_CURVE_TASKS.md)and
[sceneauxiliarywork](SYMBOLS_SCENE_AUXILIARY_WORK_POOLS.md).
