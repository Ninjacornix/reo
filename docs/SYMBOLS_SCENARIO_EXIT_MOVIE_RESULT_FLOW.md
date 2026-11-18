# Scenario exit movies, error presentation and result/card transitions

Static File #1 US, 2026-11-04. Nine complete original o2 bodies, including four large controllers with18/21/9/10 subphases. No execution, build, attachment, live memory, input, network exchange or slowdown reproduction. All phase/field/entry values are hexadecimal; stated timer lengths are counter units, not seconds. Original movie and audio roles are reused only where independently established in [movie flow](SYMBOLS_MOVIE_FLOW.md) and resident stream mappings.

S=4BADD0 is the scenario block, P=S.byte1 signed subphase, T=S.half8 signed timer. Stored pointers70DFE0 and70DFE8 both originally equal4BADD0. Controllers reload those pointers after calls; they are not silently replaced by an immutable host singleton. PrimaryC/D entry routing comes from existing5FE440; [scenario transition services](SYMBOLS_SCENARIO_TRANSITION_SERVICES.md) supplies that complete dispatch context and5FF5D0's state-reset contract.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5FFBB0](../recomp/config/output_ovl/o2/o2_005FFBB0_0x5ffbb0.cpp) | `sequence_scenario_primary_c_exit_movies_and_ending_audio_by_session_mode_candidate` | High mechanics; role probable | 1B0300()==1 delegates600150; otherwise18-phase73F370 routes death/continue/endingSFD plus preparedADX,button skip and bounded timer states,thenprimaryD. Several timer exits require exact0 instead of<=0; preserved below. |
| [o2 0x600150](../recomp/config/output_ovl/o2/o2_00600150_0x600150.cpp) | `sequence_mode_one_scenario_exit_error_texture_movies_and_final_teardown_candidate` | High mechanics; role probable |21-phase73F3C0. Initial network-cursor count gate,scene restore,negative4BAE99 error-image path,otherwisedeath/continue/ending sequencing. PrimaryD normally,primaryF for exacterror-2 aftercleanup. No host-clock timeout or in-engine cutscene simulation here. |
| [o2 0x603310](../recomp/config/output_ovl/o2/o2_00603310_0x603310.cpp) | `load_save_texture_key_twenty_six_hundred_if_registry_lookup_absent_candidate` | Confirmed mechanics; asset role inherited | Looks up2600;absentreads73F760 `save.tm2` into32440C flags1,successfulreadregisters1CCB90(2600,buffer). Does not clear whole registry first,unlikeerror-textureloader5FFA70. |
| [o2 0x603370](../recomp/config/output_ovl/o2/o2_00603370_0x603370.cpp) | `release_save_texture_key_twenty_six_hundred_and_service_heap_candidate` | Confirmed mechanics |1CD080(2600,1),then18DCB0;no other assets or scenario fields directly changed. |
| [o2 0x6033A0](../recomp/config/output_ovl/o2/o2_006033A0_0x6033a0.cpp) | `emit_save_texture_sprite_and_optional_mode_one_font_messages_candidate` | High mechanics; UI role probable | Lookup2600;nonnullconfiguresGSstate,paletteadmission,sprite70DFC0. Mode1 plusflagconditions maydrawtwofixedfontmessages via1B56A0. Font gates and native override boundary kept below. No button handling or asset load. |
| [o2 0x6034D0](../recomp/config/output_ovl/o2/o2_006034D0_0x6034d0.cpp) | `sequence_mode_one_result_workspace_then_save_card_ui_and_teardown_candidate` | High mechanics; role probable | Nine-phase73F780 via70DFE0->S. Resultworkspace600950/controller600A40,one-stepwait,saveimage/fades,cardUI1C2600/1C2940,releaseimage,thenprimaryF. Fullcallorderingbelow;resultcontroller600A40 separatelyrequiresreview. |
| [o2 0x603740](../recomp/config/output_ovl/o2/o2_00603740_0x603740.cpp) | `sequence_primary_d_results_overlay_save_card_ui_and_lobby_selection_candidate` | High mechanics; role probable | Mode1 delegates6034D0;othermodes10-phase73F7B0 via70DFE8->S. Resultoverlay826FE0/8270D0,extra subphase increment,saveimage/cardUI,final37D380/37B950 decision,primaryF. No model animation or room worker updates here. |
| [o2 0x6039F0](../recomp/config/output_ovl/o2/o2_006039F0_0x6039f0.cpp) | `test_category_one_in_mode_selected_roster_or_fixed_actor_prefix_candidate` | Confirmed mechanics; category role unknown | Mode1 scans4 rows815418,stride3,byte0==1. Othersscanunsignedword4BAEA0 fixedactorcount,return1forB98==1. No activity/enable gate or count<=8 clamp;return0ifnomatch. |
| [o2 0x603AB0](../recomp/config/output_ovl/o2/o2_00603AB0_0x603ab0.cpp) | `prepare_scene_and_category_selected_result_stream_candidate` | High mechanics; audio role inherited | Scene1 selects8entryADXbank by localactorB98 andcategory-onepredicate6039F0. Scene1C/23/29 usesfixedtracks;scene2 andothersnooperation.1AE7D0(channel1,0,path,0);categoryboundsnotchecked. Fullownedfilenamebanksbelow. |

5FFBB0 non-mode1 phases, all state invocations with no internal blocking wait:

| P | Observed full branch contract |
| --- | --- |
|0|1AFBF0. BothSA6/SA7nonzero ->1AF9C0,P3. Else3166A1==0sets324489=3;1AF9C0;scene23->P6 and1AE1E0,scene29->PA and1AE1E0,otherP9/T1E. |
|1|Wait1BB8D0nonzero,then1AF6A0(0),P++. |
|2|1ACF70,1AE1E0,3719E0,primaryD. |
|3|4BAE0B=1,37AD80 deathSFD/ADX,T96,P++. |
|4|T--;37A9B0 status2 orT<=0 ->1ADF50(1),1BC2B0,T0,P++. |
|5|37AA10==0 ->37A4E0,T1E,P9. Otherwise324300bit8000 calls1AE1E0 then37A4E0,sameT/P. |
|6|37AE90 continueSFD/ADX,T96,1BC2B0,P++. |
|7|T--;movie status2 orT<=0 ->1ADF50(1),T0,P++. |
|8|Inactive movie stops/destroys,T1E,P++. Button8000 also1AE1E0/3243FC=0 beforedestroy;otherwisewait. |
|9|T--;onlywhenT<=0:1ACF70,1AE1E0,3719E0,1AFBF0,primaryD. |
|A|Preparestream1with73F330 `demo/s413900a.adx`,T96,P++;**fallintophaseBsameinvocation**. |
|B|T--;1AE910(1)nonzero orT==0 ->37ABD0(0) firstendingSFD,T96,P++. Exactzero timer,notnonpositive. |
|C|T--;movie status2 orT==0 ->1AE9A0(1),P++. |
|D|Inactive movie orbutton8000 clears3243FC,destroysmovie,T0A,P++. Buttonadditionally1AE1E0. |
|E|T--;exact0 preparesstream1with73F350 `demo/s414000a.adx`,T96,P++. |
|F|T--;1AE910(1)==1 orT==0 ->37ABD0(1) secondendingSFD,T96,P++. DiffersfromphaseB'sanynonzeroreadiness. |
|10|T--;movie status2 orT==0 ->1AE9A0(1),P++. |
|11|Inactive movie orbutton8000 clears3243FC,destroysmovie,T1E,P9. Buttondoesnotcall1AE1E0here. |

T values96/1E/0A are150/30/10 decimal counter units. 37A9B0 returns2 for developer override or absent decoder handle as well as a real saved status2; the controllers do not prove a decoder completed. 37AA10 requires a context and checks nonzero status with handle; it is not an engine-progress detector. No frame-rate or codec-stall conclusion is inferred from these branches.

600150 mode1 initialP0: if signed4BAE99>=0 and1C7C10()!=0,return without reset;the lower1C7C10 is the sum of two network-cursor remaining counts except state7. Otherwise1AFBF0,copybyte316683 toscene3243DA even whenerrornegative. NegativeSC9==-2 ->1AF9C0,P3;nonnegativecalls814720(2). BothSA6/SA7nonzeroalsoP3 after1AF9C0. Otherwise1AF9C0,scene23->P6,scene29->PD,otherPB/T1E. Scene-specificbranchescall1AE1E0.

Remaining600150 phases:

| P | Observed full branch contract |
| --- | --- |
|1/2|Fade-readyadvance;then1ACF70/1AE1E0/3719E0/primaryD,matchingnon-mode1shape. |
|3|Negative4BAE99 loadsError.tm2 through5FFA70,T96,P9,fadeprofileA. Nonnegative4BAE0B=1,deathmovie37AD80,T96,P4. |
|4/5|Deathstatus2 orT<=0 releases1ADF50(1),1BC2B0,T0,P5. Inactivemovie orbutton8000 destroys,T1E,PB;buttonalso1AE1E0 andclear3243FC. |
|6/7/8|Continue37AE90,T96. Status2 orT<=0 releases1ADF50(1),T0,P8. Inactiveorbuttondestroys,T1E,PB;buttonalso1AE1E0 andclear3243FC. |
|9|IfT!=0,decrement. WhenT<1Fand(input324300&FFF0 nonzero orT==0),P++,fadeprofile9,T0A. Alwaysdrawerrorimage5FFB00onthisinvocation. |
|A|T--;exact0 releaseserrorimage5FFAD0andP++,otherwisekeepsdrawing. |
|B|T--;T<=0 clearschannels1ACF70/1AE1E0,3719E0,T0,P++. |
|C|Exact4BAE99==-2 resetsfade/renderstateand1CC9B0registry,primaryF. OthererrorsandnormalcaseprimaryD. |
|D/E|PreparefirstendingADXchannel1,T96,P++;fallthroughT--/readiness. Any1AE910(1)nonzero orT==0 startsfirstending37ABD0(0),T96,P++. |
|F|T--;movie status2 orT==0 releasesstreamwait1AE9A0(1),P++. |
|10|Inactiveorbutton clears3243FC/destroys,T0A,P++;buttonadds1AE1E0. |
|11|T--;exact0 preparessecondADXchannel1,T96,P++. |
|12|T--;**exact0startssecondending37ABD0(1)without1AE910 readinessquery**,T96,P++. |
|13|T--;movie status2 orT==0 ->1AE9A0(1),P++. |
|14|Inactiveorbuttondestroys/clearsmode,T1E,PB. Buttondoesnotreleaseadditionalchannelhere. |

The exact-zero andnonpositive tests are literal. They do not by themselves establish an underflow bug: the documented entry paths initialize positive timers, and caller/state mutation admission is not proven outside this scope. Per-call fallthrough was verified before interpreting counters.

Result/save controllers use separate storedpointerloads but original70DFE0/DFE8 both4BADD0. LetQ=thatpointedblock'ssignedbyte1,W=byte2:

| Controller | Complete phases |
| --- | --- |
|6034D0,Q0..8|0 resetsfadefunctions1BB8B0/1BC2B0/1BBB10(0)/1BBAD0(1,1),releasesregistry1CC9B0,Q1.1 initializesresultworkspace600950,Q2,**fallsintoQ2controller600A40sameinvocation**.2 calls600A40;nonzeroresultincrementsQ3/W1.3 waitsWpredecrement==0,thenQ4/W1.4 nextWzero loadssaveimage,fadeprofileA,W0A,Q5.5 countdown;Wzero starts1C2600(2,1),Q6;alwaysdrawsaveimage.6 ticks1C2940;zeroQ7,fadeprofile9,W0A;alwaysdraw.7 Wcountdownzero ->1BC2B0,releaseimage,Q8/W0A;waitingdraw.8 immediatelyprimaryF,withoutwaitingthejustsetWtimer. |
|603740,Q0..9|0 samefade/registryreset,Q1.1 resultoverlay826FE0,Q2,**fallthroughQ2service8270D0sameinvocation**.2 calls8270D0;nonzeroQ3.3 directlyincrementsQ4,thenfallsintoQ4'sincrement/W1,soQ5onthatinvocation.4 enteredindependentlyincrementsQ5/W1.5 Wpredecrementzero ->loadsaveimage/fadeA,W0A,Q6.6 countdownzero ->1BC2B0,1C2600(2,1),Q7;drawimage.7 cardtickzero ->Q8/fade9/W0A;draw.8 countdownzero ->1BC2B0,releaseimage,Q9/W0A;waitingdraw.9 result37D380==0clears324489,37B950(0)storedlow8to32448B;nonzero32448B=low8scene. ThenprimaryFwithoutwaitingtheWtimer. |

The owned word tables below were used to bind each phase to its body before following fallthrough. Result/UIcontroller600A40 and external overlay entry8270D0 remain separate proof boundaries; this notebook maps their callers without inferring their internals.

6033A0 saveimage path configuresregistersD=0,5F=5,60/63/6C=0,paletteadmission19D720(1,&handle),register4=handle,1AF1E0(4,5),sprite70DFC0. Optionalfontmessagesonlywhen1B0300()==1 and((4BAE76==0)or(4BAE77==0)) andsigned8AA2B3==0. Uses1B55D0(14),1B5640(0),1B55F0(46,168),1B5650(80008000),1B56A0(pointer70DFD8),1B56A0(pointer70DFDC). These are originalfontcontracts; [font override boundary](SYMBOLS_FONT_OVERRIDE_BOUNDARY.md) explains whyoriginalguestbodiesarenotautomaticallycurrentnativeexecutionevidence.

6039F0'smode1roster815418ispotentiallyexternaloverlay/runtime data,notownedo2filedata. Othermodesscanunsignedword4BAEA0ratherthanthebyteusedbyothercontrollers. Category1isjustthenumericB98comparison;nocharacternamewasassigned.603AB0scene1useslocalactorB98withoutaboundcheck;category-onepresentchooses70E010else70DFF0. Botharecomplete8-pointerownedbanks:

| Indexdecimal | 70DFF0 (no category1) | 70E010 (category1 present) |
| --- | --- | --- |
|0|demo/s010101a.adx|demo/s010100a.adx|
|1|demo/s010100b.adx|demo/s010100b.adx|
|2|demo/s010101c.adx|demo/s010100c.adx|
|3|demo/s010101d.adx|demo/s010100d.adx|
|4|demo/s010101e.adx|demo/s010100e.adx|
|5|demo/s010101f.adx|demo/s010100f.adx|
|6|demo/s010101g.adx|demo/s010100g.adx|
|7|demo/s010101h.adx|demo/s010100h.adx|

Scene1C uses73F9C0 `demo/s280001a.adx`;23uses73F9E0 `demo/s350100a.adx`;29uses73FA00 `demo/s410000a.adx`. Scene2returnswithoutplaying;othersalsoreturn. Call1AE7D0(1,0,path,0) preparesanarmedstreamstart,notanunconditionalimmediateaudibleplay.

Owneddata:o2base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Pointerbank70DFF0..E00F SHA256 `30c4a96d650671434ad8e4ebf15615a514f7a2749468f0b7bf90ad834b0816d5`,70E010..E02F `33f379eefc57bb04fc772718426a6fa6ef2f982658d6a433acb81609c296335f`. Everypointedfilenamewasdecodedfromownedbytes;pointeridentitiesarepreservedabove. Allfourcontrollers'completetargetspans:

| Table | Original word targets in phase order | SHA256 |
| --- | --- | --- |
|73F370,18words|5FFC0C 5FFCB8 5FFCE0 5FFD08 5FFD2C 5FFD78 5FFDD8 5FFDFC 5FFE40 5FFEAC 5FFEF8 5FFF20 5FFF68 5FFFA8 600018 60005C 6000A4 6000E4|e89bd946fa6bd4eca2bf47bd12a77d28cfca10794785f6b7a6e16eb44cf2094c|
|73F3C0,21words|600190 600290 6002B8 6002E0 60033C 600388 6003EC 600410 600454 6004B8 600520 600564 6005AC 60060C 600638 600680 6006C0 600730 600778 6007B4 6007F4|fe9bd3dcd06b2df4278ebbb3dd784f13eb52fe588a1981796a25e0f6d528e22d|
|73F780,9words|603508 60354C 603568 60359C 6035DC 603630 603678 6036C0 603724|3376bf03d133e68ba5b7baceb363dce864f0fea5d10652a113a16c3a4c98f010|
|73F7B0,10words|60379C 6037E0 6037FC 603820 603828 603850 6038A4 6038F8 603940 6039A4|28a40ead056866659b8088a78b4c129cf990c57db412225b39ec9368a43540ac|

Asset73F760exactpath `data\\rom\\scene\\pit_tex\\save.tm2`. NoSFDorADXwasdecodedorrun,andnoreportclaimsadecodercausefortheuser'sin-enginecutscenelag. Remainingresultworkspacecontroller600A40andrenderhelpersareseparatescopes;theouterphasecontractdoesnotfillthosegaps.

Owned-word audit: nine complete new rows, 1,210 original instruction words verified, 170 omitted zero/NOP words, zero conflicts and zero omitted nonzero words. All four complete phase tables, both eight-pointer audio banks and each pointed filename were checked against owned bytes. Source links/live notebook IDs/current annotations clean; no shared index mutation.
