# EMD record expansion and scenario actor callback installation

Static File #1 US research, 2026-11-04. Two complete large original bodies
reviewed. Addresses/offsets/IDshex; scalar capacities/countsdecimal.
Ownedfilenameandcallbackdatareviewed. Originalenemynamesandspawnenums
unresolved. Noexecution,build,replay,networkoperationorenginechanges.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6BAA40](../recomp/config/output_ovl/o2/o2_006BAA40_0x6baa40.cpp) | `load_scenario_emd_records_and_expand_selected_spawn_group_candidate` | High mechanics; filename identity verified | Clears74F250size6000,256bytes3B5050=FF,pathbuffer0. Sessionmode1usesownedsgl_e%03d.emd,otherse%03d.emd,scenario3243DA;read1CC8F0flags10001totemp32440C,nonzeroadmitted. Advancesinputby4*trunc(headerword0/4),zeros128bytes755250/7552D0. RNGstream0&7seedrotation;stream2&3group,mode1overridesgroup=4BAE8A&3. Sequential60-byteinputrecordsendsbyte2FF;filtersbyte1Egroupand49bit(1<<4BAE8A). Emits60-byteruntime74F250recordswithoutlocalcapacitybound,fieldsbelow;publishescountbyte4BAE8E,1B2D80. Noactorsconstructedhere. |
| [o2 0x6BB040](../recomp/config/output_ovl/o2/o2_006BB040_0x6bb040.cpp) | `instantiate_current_room_and_admitted_remote_emd_actor_nodes_and_sound_set_candidate` | High mechanics; filename identity verified | Global4BADF8nonzeroreturns. Clears74F240byte;currentroomuses7552D0[room]startindexand755250[room]countinto74F250;zeros256soundclassbytesstack70. Firstloopcurrentroomrecordswithbyte26zeroandeligibility;secondloopallcount4BAE8Erecordswith26nonzero,allowedclass4BA820/A822,flagbitsand1B32F0admission. BothA300(1)nodes,allocationfailureendsearly;constructionbelow. CompressesnonzerosoundIDsbyclassintoeight-bytearrayspecialclass1routing,calls1D3D40. Nocompleteallassets/successaggregation. |

AA40 runtimeR/inputS fieldconversion afterfilters:

| Source | Destination |
| --- | --- |
| outputordinal | R0/R27(initialgroupordinaloverwrittenbyoutputindex) |
| byte2 | byte2class |
| signedwords10/14/18 viafloatconversionandback | signedwords10/14/18XYZ |
| words8/C | words8/Crotation |
| bytes3/22/4/1C/1F/20/5/21 | bytes3/4/5/22/29/2A/2B/3A |
| bytes23/24/25/26 | bytes2D/41/43/44 |
| bytes27..30 (tenbytes) | bytes2F..38 |
| byte33<8 | half1C/1E=healthtable[class][difficulty&3][selector33] |
| byte33>=8 | half1C/1E=7FFF |
| byte44 | half3C |
| bytes3A/1D/31/32 | bytes20/26/46/47 |
| bytes34..40 | bytes48..53 |
| bytes42/43 | bytes55/56 |
| bytes45/46/47 | bytes57/58/59;nonzeroeach+=31 |
| byte48/49 | bytes5A/5B |
| byte4A | byte5C=owned72F820[index] |
| byte4B | byte5D |

R45cleared0. GroupbyS1C:7552D0[group]=firstoutputindexonchange,
755250[group]++foreachadmittedrecord;sourceorderingisacaller/assetcontract.
IfR26nonzero,6812B0(2,index),6BC210(R). R42isrotatingRNGseed0..7.
Healthnormalbase729270,mode1base72A1F0,stride40perclass,10perdifficulty,
2perselector. Ownedfirstclassfourrows(decimal):normal
[500,550,600,650,700,750,800,850]/[800,850,900,950,1000,1050,1100,1150]/
[900,950,1000,1050,1100,1150,1200,1250]/[1000,1150,1200,1300,1400,1500,1600,1700];
mode1firstrow[600,650,700,750,800,850,900,950],otherfirstclassrowsmatch.
Owned72F820firstfourbytes[1,4,8,10hex];remainingindexedextentunknown.

BB040 commonnodeinitialization NfromR:

- N0=1,N2=2,N3=R2,callback14=70AB20[signedhalf70AA50[N3]],render18=371EF0,
  slot31=sequentialconstructedindex,model34=459120+1468*slot.
- R1=N.poolindex6;NCCC..CCF=FF,NCA0/CA1=FF;
  6BBDA0(N,R),6BB9F0(N),N1E2=currentroom.
- Classes1/11/25use1B92B0tochooseN554=2+counterandcounter++or21+counter,
  then1B92E0actorvoicebyte33. OtherclassesN5540,reusevoicebyteperclassorquery
  once1B92E0. Class1writesitsvoiceIDbacktoperclasslist.
- A790(descriptor54D,slot31,class3,variantBBA,t0=bit709AC0[class]);clears
  model1460/1464,377560(N,2,class)optional3777B0(N,slot+4),partflagsF4+i=1.
- N54E=class;animationbankindexbyte4BAEB0[class],N51C=4BEC30+C84*index,
  N514=4BD4A0+3EC*index,N524=byte1atN51C.

Currentroomeligibility:flag4BAA30 indexedR4mustset;class3Dalso4BAE96bit1
mustclear. When1B82A0(46)==0,classesA/29/1D/13requireR2F!=FF.
RemoteR26nonzeroeligibilityshareslatterclassgate,requiresR2classmatching
4BA820or4BA822,flag4BAA30and1B32F0(R)nonzero. CurrentroomsetsR6=1;
otherroomcalls5A8CF0(N). Noentrymaybedeclaredloadedfromitsallocatednodealone.

Soundset:perclassnonzeroIDscollected;class1substitutes2whenanyID59,
else3whenanyIDoutside{0,2,3,59},else4. OtherclassIDsretained.
Then1D3D40(stack178). Originalarraycapacity8andinputclassboundsremainasset
contracts;nooversizedinput/runtimefailurewasobserved.

Owned104halfwords70AA50..70AB1Fcontaincallbackindices0..29;30wordtable70AB20
readinfull. Thisphysicalspanisnotanassertionthatanybyteclassisvalid.

| Handler index | Numeric classes in physical104-halfword span | Callback PC |
| --- | --- | --- |
| 0 | 3, 8, B, C, D, E, F, 10, 12, 15, 18, 19, 1C, 1F, 20, 21, 22, 23, 27, 28, 29, 2A, 2C, 2D, 2E, 2F, 30, 31, 32, 33, 35, 36, 39, 3E, 3F, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 4A, 4B, 4C, 4D, 4E, 4F, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 5A, 5B, 5C, 5D, 5E, 5F, 60, 61, 62, 63, 64, 65, 66, 67 | 0x6334F0 |
| 1 | 0 | 0x61C3E0 |
| 2 | 1 | 0x696300 |
| 3 | 2 | 0x6055E0 |
| 4 | 4 | 0x6C3FB0 |
| 5 | 5 | 0x5E0880 |
| 6 | 6 | 0x6C5690 |
| 7 | 7 | 0x6CF0C0 |
| 8 | 9 | 0x5FA100 |
| 9 | A | 0x5D2330 |
| A | 11 | 0x694EC0 |
| B | 13 | 0x6BE6C0 |
| C | 14 | 0x5AF4B0 |
| D | 16 | 0x60F710 |
| E | 17 | 0x5AA160 |
| F | 1A | 0x6CC7C0 |
| 10 | 1B | 0x5CB710 |
| 11 | 1D | 0x6877D0 |
| 12 | 1E | 0x60BD20 |
| 13 | 24 | 0x655560 |
| 14 | 25 | 0x6957C0 |
| 15 | 26 | 0x5870E0 |
| 16 | 2B | 0x6F18A0 |
| 17 | 34 | 0x5A55B0 |
| 18 | 37 | 0x5E56E0 |
| 19 | 38 | 0x58ED80 |
| 1A | 3A | 0x6D75D0 |
| 1B | 3B | 0x6EDEC0 |
| 1C | 3C | 0x6FFCA0 |
| 1D | 3D | 0x633330 |

OwnedspanSHA256audits:70AA50lengthD0
`8b5d48bb2000f0c94467756f2d811a89f007cfa6bba45f3a419b08dbf759bb8b`;
70AB20length78`d91641538b64e51c6278e5c91f35e230fd748e9de385e9d04bbd3c2a7a3f32a9`.
Audited62-classHPspanslengthF80each:729270
`cf1b5ae418aef83ae42b9b3b0da8e01b12397d8bb5d51d98c901d4869182fe8b`,
72A1F0`c9d4f7b54bbe153a7ffa59850ac81b106adcfeb75a8fff9c538a0dc986cfaf09`;
allhalfvalues0..9900decimalinreviewedspans. Nounseenclassboundsinferred.
Thesearefile-backedstaticdataaudits,notlivehealthoractiveactorreadings.

Related[nodepool/factory](SYMBOLS_SCENARIO_ACTOR_NODE_POOL_AND_FACTORY.md),
[modelconstruction](SYMBOLS_ROOM_AND_EFFECT_MODEL_LOADING.md),and
[soundloading](SYMBOLS_SOUND_BANK_INSTALL_AND_SYNC.md).
