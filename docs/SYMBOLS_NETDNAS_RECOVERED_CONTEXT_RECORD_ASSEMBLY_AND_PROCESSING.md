# Recovered keyed DNAS context-record assembly and processing

Static File #1 US owned o4/netdnas.bin review,2026-11-05,base6E0000,SHA-256 `8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16`. Two complete logicalowners;455recoveredwords andallclearentrance/restore/epiloguewordsreadasdata. No recoveredinstructions executed,no blocksession/network/game/build/attachmentperformed,no original/generatedinputmodified. Hexadecimaloffsets/addresses;countsexplicitdecimal.

| Guest entry / original source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x746C38](../recomp/config/output_ovl/o4/o4_00746C38_0x746c38.cpp) | `assemble_256_byte_netdnas_context_record_with_mode_specific_fields_wrapped_tail_and_scratch_overwrite_candidate` | Confirmed complete joined control/data/size/status contract; provider algorithms and original format names unknown | Originala0context->S0,a1out->S2. Require767A80==1,else-8.74E728(context,&stackD0)mustnonnegativeandreturnedlow-two-bitmode<2,else-403.7484F8(stack0)and748828(stack30)mustnonnegative,else-401. Mode0requires748D68(stack70),7492B0(stack90),failure-402;mode1uses74E830(context,stack70,stack90),failure-403. Successassemblesout256andthreeblock-sessionstagesbelow;anysessionfailure-401,allsuccess256. AllpathsperformfiveboundedLCGscratchoverwritesbeforeclearrestore/returnthrough747308. Callerbufferextent/aliasinganddelegatedformatsemanticsremainexternal. |
| [o4 0x747308](../recomp/config/output_ovl/o4/o4_00747308_0x747308.cpp) | `process_288_byte_netdnas_record_with_derived_block_parameters_then_publish_result_and_overwrite_scratch_candidate` | Confirmed complete joined argument/status/cleanup contract; original format/provider names unknown | Capturea0/a1inS4/S5,inputa2inS0,outputa3inS2,prefixoutputt0inS3. Require767A80==1,else-8.74BC58(fixed76BD68,key76BD88,stack120,4)then74C1F0(input,stack120,stack130,stack128,stack0,stack138,36),eachmustnonnegative. Finally74D248(originala0,originala1,stack0,originala3,originalt0)mustnonnegative. Anyadmittedstagefailuremaps-401,allsuccess0. EveryexitLCG-overwritesstack0[288decimal]andstack120[32decimal]thenrestoresoriginalprotectedspan/returnsselectedstatus. No callerinputcapacity/NULLguard locally. |

## Full ownership and original-byte evidence

| Owner, logical half-open interval | Recovered span | Recovered / preserved-exception words | Reconstructed SHA-256 | Joined original SHA-256 |
| --- | --- | ---: | --- | --- |
| 746C38..747308 | 746CD8..74727C | 361/29 | `ba68a864914d167619f5e12c9dad05be85e95543af56bfb7ca8732099f5f0360` | `62a4b440fc936b4e31da05428bc6de1d4ce8cc8080bb71030ad96c99dbcb9ec5` |
| 747308..7475AC | 7473AC..747524 | 94/11 | `df7c376ab547ca6846a5c2319b7638e065b9a808ec8ebc2de420d7fbddf27987` | `0dd7367965445d98606c8ea7ed1c30ebb7a8d660622d2799cae7f55aa8cb5786` |

746C38clearentrancesaves320decimal-byteframe,S0..S7/RA,F20..22andzerosstackD0;entryJAL7457C8at746C9C,branch746CA4enters746CD8. Allcandidatepathsjoin74727Cwhoseclearbranchreaches7472AC;actualrestoreJAL7472C4thenreturnsS1andbalancesallregister/frame/FPU-saves.747308saves416decimal-byteframe,S0..S6/RA/F20..22andcapturesfiveoriginalarguments;entryJAL747370,branch747378enters7473AC. Allpathsjoin747524,clearbranch->747554,restoreJAL74756C;returnS1/restoresthrough7475AC,followedbypaddingbefore7475B0. Noassumptionthatcatalogueendsinsidethepayloadarelogicalreturnboundaries.

[Privatefullword-fieldreceipt](../build-function-index/proxy-dnas-first14-review.json) retainsall581candidate/529clearwordsforthefirst14owners,includingthese455candidatewords,withnounrecognizedfields.[Independentgenericreview](SYMBOLS_NETDNAS_RECOVERED_KEYED_INITIALIZATION_AND_TEARDOWN.md) establishedexceptionaddressing,actualoppositemodesandrestoresetups.[Inventory](STATIC_DNAS_UPPER_RECOVERY_INVENTORY.md) retainsbothdescriptors/keys,49originalmetadatarecordsandcandidatearrays. Encodedgeneratedsource/grapharenotrewritten;insidefragments/one-byteintervals/skippedmetadatagetnoextraownercredit.

## 746C38 mode gates and 256-byte layout

Allerrorpathssetupvalidlocalbufferpointersbeforejoiningcleanup. Thetwo-bitquery74E728alwayswritesmaskedbytewhenitreturnsnormally;thiscalleralsorechecksmode<2. Itrequestsstack0size40decimalthrough7484F8,stack30size56through748828,mode0stack70size32through748D68andstack90size40through7492B0. Mode1passesstack70/stack90to74E830instead. [Querypayload/fileadapters](SYMBOLS_NETDNAS_RECOVERED_QUERY_PAYLOAD_AND_FILE_ADAPTERS.md) independentlyconfirmthesecapacityrequestsandthefive-/nine-bytequery/filepayloads.Namesofthebuiltfieldformat/terminatorvalidityremaincalleecontracts.

Afteralladmissions,zerocallerout[256decimal],thencopy:

| Output range, hex | Source / exact byte count |
| --- | --- |
|00..27|stack00,40decimalbytes|
|28..5F|stack30,56decimalbytes|
|60..87|stack90,40decimalbytes|
|88..A7|stack70,32decimalbytes|
|A8..E7|retaininitialzero64decimalbytes|
|E8..F7|16locallyLCG-derivedbytes|
|F8..FF|owned76BC60[8]|

The16derivedbytesuseone74AA20callperbyteandtheexplicitguestfloatsequencebelow. Threeexistingblock-sessionstagesfollow;input/outputargumentsandcountsarepreservedwithoutassuminganalgorithmname:

1.74BD68(out,out+E8,out,out+F0,29decimal):updatecount<<3means232decimalbytes00..E7;E8/F0supplythetwo8-byteparameterblocks.
2.74BC58(76BD50,76BD60,stackC0,2)produces16byteparameters,then74BD68(out+E8,stackC0,out+E8,stackC8,2)transforms16byteE8..F7inplace.
3.74BC58(76BC68,76BC78,stackC0,2),then74BD68(out+E8,stackC0,out+E8,stackC8,3)transforms24byteE8..FFinplace(includingtheowned8-bytetail).

Thefinalnonnegativeproviderresultselectsreturn256decimalviaMOVZ;failurespreserve-401. Earliercontext/header/mode-specificfailurespreservetheirseparate-403/-401/-402codes.Thecalleroutputisnotpromisedunchangedoncezerocopy/providerstagesbegin. Providerconstructor/update/finishfailurecleanupandciphersemanticsarenotexpandedbythiscallerreview.

Allpaths,including767A80!=1,overwritefiveLOCALscratchrangesviafreshLCG-derivedbytes:stack70[32],stack00[40],stack30[56],stack90[40],stackC0[16],total184localdraws. Successfulinitialassemblyadds16drawsforoutE8..F7beforeproviderstages. OthercalleesmayadvancethesameLCG;thisisnotacompleteglobaldrawcount.No cryptographicunpredictabilityorsecure-erasureguaranteeisinferredfromtheoverwrite.

## 747308 processing and publication

Thefixedfirststage74BC58uses32ownedbytes76BD68and8-byteparameter76BD88,blockcount4,andwritesstack120[32]. The7-argument74C1F0passesparameterpiecesinstack120,stack130,stack128,stack138tothree-parameterconstructor74B9B0,inthatorder,thenupdates36eight-byteblocksfromORIGINALa2inputintostack0[288]. Neitherlengthcomesfromacallerlengthargumenthere.

Thethirdstage74D248receives(originala0,originala1,stack0,originala3,originalt0). Its[separatestatic144-byterecordreview](SYMBOLS_NETDNAS_RECOVERED_144_BYTE_RECORD_ORCHESTRATION.md)establishesoriginala0/a1assourceblocks(64KiB/256bytes)anddirectsuccesspublication:zero144decimalbytesat originala3,copy16byteprefixfromitslocalscratch,appenditsreportedproducedbytesatoutput+16,andcopythesame16byteprefixthroughoriginalt0. Thiscalleracceptsanynonnegativechildresultandreturns0;itdoesnotindependentlyboundthatchild-producedlengthorcheckoutputcapacity. Onfailureitreturns-401afterlocalcleanup. Allpaths,includinginitialglobalfailure,overwrite288+32localbyteswith320calls to74AA20.

## Exact LCG-to-byte arithmetic and called boundaries

Eachoverwriteiterationtakes74AA20'shigh31-bitnonnegativeresultR,guestCVT.S.WtoF,dividesbybinary32bitpattern4EFFFFFF(float2147483520),multipliesby256(float43800000),convertsusingguestCVT.W.Sandtheexplicitunsigned2^31branch(4F000000),andstoreslow8bits. Theconvertcanroundtonear256beforebytewrap;thisisnotanassertionofuniformbytegeneration. Theloopsarefixed-count,withoriginalbranch-delaystoresretained. The [LCGandblock-sessioncontracts](SYMBOLS_NETDNAS_OPAQUE_BLOCK_SESSIONS.md) establish74AA20/74BC58/74BD68/74C1F0andtheir8-bytecountadaptation. The [two-bitquery](SYMBOLS_NETDNAS_RECOVERED_TWO_BIT_FIELD_QUERY.md) establishestheFCA0mask/acceptancecontract.

UnknownsincludeoriginalAPI/recordnames,provideralgorithmattribution,allcallerpointerextents/aliases,runtimeheader/concurrency/cacheadmissionandactualonline-libraryreachability. Exactroundtripandstaticfieldflowdonotdemonstrateauthentication,deliveryorperformanceimprovement.No candidatefix,nativeimplementationorinputpatchwascreated.

Reproduce the complete joined original/candidate word evidence with the repository [first-owner-group checker](../tools/function_index/review_dnas_proxy_first_owner_groups.py): python tools/function_index/review_dnas_proxy_first_owner_groups.py. It reads the fixed owned-image hash and embedded owner bounds, independently rereads exception metadata and both descriptors, verifies actual entry/restore argument setups, reconstructs every candidate and exact original-byte restore, and regenerates both linked private receipts without requiring either old receipt. Direct branches and delay slots are checked against the admitted connected instruction regions. No guest instruction is executed.
