# Packed scene parameter spans and eighteen-channel key interpolation

Static File #1 US owned o2 analysis, 2026-11-05. Two complete original bodies and owned selector table. [Identity](FUNCTION_INDEX.md). Offsets hexadecimal; no runtime work.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x58FEC0](../recomp/config/output_ovl/o2/o2_0058FEC0_0x58fec0.cpp) | `copy_packed_three_span_scene_parameter_data_and_rebase_views_candidate` | Confirmed full body; authored parameter names partial | Inputs a0header,a1views,a2destination. Savewordcounts0/4;copyheader+C to destination using107AB0 length8*count0+8*count1+4*wordcount2 with guest32-bit shifts/adds. views8=destination,C=destination+8*count0,10=previous+8*count1. Doesnotcopynumericcountsintoviews,allocateorcheckextents/overlap/overflow. |
| [o2 0x58FF50](../recomp/config/output_ovl/o2/o2_0058FF50_0x58ff50.cpp) | `interpolate_one_of_eighteen_work_parameters_and_wrap_its_independent_key_clock_candidate` | Confirmed full body; authored parameter names partial | Inputsworka0,viewsa1,unsignedparama2,keycounta3,firstkeyoffsett0. Cursor=signedhalfworkF0+2*param;keys=viewsword10+4*t0. Calls590B10(keys,cursor,keycount) BEFOREunsignedparam<18decimalcheck. Validparamusesownedjump table towritefieldbelow,thenincrementcursorsigned16;lastkeyindex=keycount-1ifnonzeroelse0,compare newcursor againstsignedkeytimehalf2;new>=end resetscursor0. Noendtime>=0,nonzerokeycountorselectorbound beforeinitialcursorread/interpolation. Noloopmodulo or elapsedrealclock. |

58FF50 selector table73E0C0[72], SHA-256 `e93c40b516cfbeae5b9b709a7a4b13cccb3d0476805eaf49dfefb2cc5ea4c09f`; selector decimal, interpolated scalar v:

| Selector | Target | Written value |
| --- | --- | --- |
|0,1,2|58FFCC,58FFEC,59000C|B4/B8/BC=v/16decimal (XYZscale fields).|
|3|59002C|214=v/255decimal.|
|4,5,6|5900AC,590144,5901DC|half90/92/94=degree-to-turn conversion below.|
|7,8,9|590274,590294,5902B4|38/3C/40=44/48/4C+v/16decimal.|
|10,11,12,13|5902D4,5902F4,590314,590334|218/21C/220/224=v/16decimal.|
|14|590354|230=(v/16decimal)*owned73E138.|
|15,16,17|59004C,59006C,59008C|208/20C/210=v/255decimal.|

Angleconversion: if v<0 add360decimal ONCE; compute65536*v/360 +.5, then original guestunsigned32 CVT branch (subtract2^31/OR80000000 when >=2^31), storelow16. This doesnotnormalizearbitrarymultiturn inputs. Owned73E138 float0.01745329238474369, SHA-256 `f9a3caf896d870d48527cae33ef20457ed504c174374500772bb36edf4e502a5`. Outofrangeparam stillperformsinterpolation, thenreturnswithoutcursoradvance orfieldwrite. Thejumpdefault590378 isnotoneof18ownedtargets.

[Scene interpolation helpers](SYMBOLS_SCENE_KEYFRAME_TRACKS_AND_PIECE_CHANNELS.md) establish590B10 key semantics; the zero-count key[-4] admission limitation remains external, not repaired by this wrapper. [Resource child work](SYMBOLS_CUTSCENE_RESOURCES.md) supplies current/base position and scale field context. No implicit relation between per-call clock increment and original global update count is inferred.
