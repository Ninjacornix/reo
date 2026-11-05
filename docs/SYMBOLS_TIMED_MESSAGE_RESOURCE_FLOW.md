# Item/load message resources and timed text overlay

Static File #1 US research, 2026-11-04. Ten complete original bodies reviewed,
including alternate archive/language paths and both text drawing modes.
Addresses/offsets hexadecimal; explicit counts decimal. No game/build/replay,
attachment or live-memory inspection. Text/font roles follow owned filenames,
strings and main-font call contracts; original UI state names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6DDD70](../recomp/config/output_ovl/o2/o2_006DDD70_0x6ddd70.cpp) | `load_item_or_map_ui_message_resources_by_requested_mode_candidate` | Probable role; full body reviewed | Global signed4BADF8nonzeroexits. a0=0/2/3clearsmapcacheflag4BAE7D;1clearsitemflag4BAE7C;-1chooses0/1frompriorflags,clearsE7C/D/Ethenre-entersnumericdispatch. Mode1conditionally8E30(755768),thenunconditionallyclearswork2C/2E,requires755760. Loadsitem_msg/itmsg[e].datandscenarioitmsg%03d[e].datinto324440arena,choosingnamed/current-scenarioreadsby3243D7;stores755778/5780onlyonsuccessandadvancesbyreturnedsize. Thenloadsspitem.dat,stores755798onsuccess,marksE7D=1. OthermodesifE7Calreadysetjust82B0;elseloadscommon/scenarioitmsgandspitem,then82B0->755760. Noaggregatearenaextentcheckorrollback;everybranchread. |
| [o2 0x6DE220](../recomp/config/output_ovl/o2/o2_006DE220_0x6de220.cpp) | `decode_ff_xor_message_string_to_destination` | High; full body reviewed | a0encodednullterminatedsource,a1destination. Callsstrlen,loopsuptolengthandstopsonearlysource0,storeslow8(sourcebyte XOR FF),then0terminator. Noexplicitdestinationcapacityorallocation. Source/destinationoverlapcontractnotestablished. |
| [o2 0x6DE290](../recomp/config/output_ovl/o2/o2_006DE290_0x6de290.cpp) | `decode_special_item_record_short_text_candidate` | Probable role; full body reviewed | Null755798returns0;elsedecodedsource=base+100*a0+4into755A40viaE220,returnsthatstaticbuffer. Noindexbound;sharedscratchlifetime. |
| [o2 0x6DE2E0](../recomp/config/output_ovl/o2/o2_006DE2E0_0x6de2e0.cpp) | `decode_special_item_record_long_text_candidate` | Probable role; full body reviewed | Independentlyreviewedadapter:source=755798+100*a0+2E,destination755960;nullbase0. Distinctsourceoffset/scratchfromE290,nofilewrite. |
| [o2 0x6DE330](../recomp/config/output_ovl/o2/o2_006DE330_0x6de330.cpp) | `initialize_timed_message_work_and_load_source_table_candidate` | Probable role; full body reviewed | Globalhalf324200==1returnswithoutchanges. Clears755C90[E8],sets755790=324408+236000. Modea0==0reads load_msg/dlmsg%03d.dat(orcurrentscenariodlmsg%03d.dat)into324408+214000;requires0<size<=2000tostore755788,else0. Nonzeromodeuses32440Cdestinationand8D40mapread,clears755788onfailure. Nofontbindorflushhere. |
| [o2 0x6DE480](../recomp/config/output_ovl/o2/o2_006DE480_0x6de480.cpp) | `clear_timed_message_work_and_visibility_flags` | High; full body reviewed | Clears755790/755788,755C90[E8],3243EA/3243FE;callsoriginalnoop6D80F0. Doesnotfreearena,changeactivefontorreconfiguregamespeed. |
| [o2 0x6DE4D0](../recomp/config/output_ovl/o2/o2_006DE4D0_0x6de4d0.cpp) | `decode_timed_message_and_strip_matching_local_meanwhile_prefix_candidate` | Probable role; full body reviewed | a0messagework,a1encodedtext. E220decodesintostackbuffer. Ifbyte4BAA50[word38ECE0]==local4BADED+1,firstlineisexactowned"Meanwhile...",andnewlineexists,copiesonlytextafternewlineintowork28. Otherwisecopieswholedecodedtext. Nooutputboundorformattingbyoriginalcharactername. |
| [o2 0x6DE590](../recomp/config/output_ovl/o2/o2_006DE590_0x6de590.cpp) | `prepare_timed_load_or_map_message_and_prebuild_font_glyphs_candidate` | Probable role; full body reviewed | a0key0,a1key1,a3mode;mode!=2clears755790/5788first,mode1rejectssigned4BADF8nonzero. E330(mode),requiresbothpointers. Setswork0=1,lifetime8=17;1B5540(6,324408+216000)return->work20. Mode0parsescountandparallelkeyarraysplus40bytetextrecords,findslow8(a0/a1),E4D0decodeswork28,1B5920(text,cursor)prebuilds. Othermodessearch58bytemaprecordsbyroomIDwith127-entrylimit,clearswork28[40]/68[80],decodestextrecord28,prebuildsandsets8=80. Onacceptedcase1BAAF0(1),3243FE=1. Prebuildfailure/latekeymisscanleaveinitializedworkstate;noerrorcauseinferred. |
| [o2 0x6DE800](../recomp/config/output_ovl/o2/o2_006DE800_0x6de800.cpp) | `tick_and_append_fading_timed_message_text_candidate` | Probable role; full body reviewed | Requireswork755C90word0. Lifetime8==0calls80F0noop,clears3243EA/3243FE,returns. Otherwisepredecrements8;3243EA==0sets8=0/returns. Setsfontdepth1B5610(-2),size55D0(18),5640(0),RGBA5650full80808080whenremaining>=21decimal,elseremaining*6low8alpha\|808080. Centersfirststring28with12*strlenin640widthatY150;firstnewlineproduceslinesat150/168. Secondary68drawsat(552,64). Global3243C3!=2calls1B7530(text,work20cursor,mode0/1),usingreturnedcursorbetweenlines;mode2calls1B56A0(text). Noactive-fontbinding,cacheflush,enqueueoractivefontrestoreinside;inheritsparentcaller'sfont. |
| [o2 0x6D80F0](../recomp/config/output_ovl/o2/o2_006D80F0_0x6d80f0.cpp) | `timed_message_expiry_cleanup_original_noop` | High; original words verified | Originaljrraandzero/NOPdelayslot;calledonmessageexpiry/clear. Doesnotstopgame,freefontorresetworkword0itself. |

The main-font caller owns selection and flushing. E800 mutates inherited font
parameters and appends text only; it does not restore those settings. Its initial
lifetime check precedes decrement, so initial zero takes cleanup. With3243EAremainingnonzero,positiveN
permits exactlyN decrement attempts before the next-call cleanup;thevisibility
gatecanendthecountdownearlier. This
is original guest countdown behavior, not a measured game-speed adjustment.

Owned paths: item_msg/itmsg.dat,itmsge.dat,itmsg%03d.dat,itmsg%03de.dat,
spitem.dat;load_msg/dlmsg%03d.dat. Resource identities distinguish timed load/map
text from any inferred scene-world renderer work or captured slowdown cause.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
