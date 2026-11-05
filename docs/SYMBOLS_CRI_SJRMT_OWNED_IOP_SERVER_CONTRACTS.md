# SJRMT operations bound to the owned IOP server

Static File #1 US investigation, 2026-11-05. Eight complete resident wrappers, all eleven SJRMT server callbacks, registration, dispatcher, and relevant constructor/vtable contracts inspected. No RPC, game, audio, build or running-process access. Main ELF SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`; addresses/IDs hexadecimal except stated byte/count units.

The stronger evidence is the player's owned ISO member `/IOP/MODULES/DRIVE.DAT`: LBA1212,2048-byte sectors,356544bytes,SHA-256`6ac9f10940514fe0d54139498de87d432a4e84db499aa5f07e53ad5889d92c79`. Its MUU- member9 starts at192576(2F040hex),125201bytes,SHA-256`456f07cb55a5bed66643fd95ca6ef64874265b578630b905a9328346e01aefb7`. The ISO's resident executable was independently matched to the owned ELF hash before examining this member. Extracted private analysis input and identity receipt: [owned module](../build-function-index/owned-iop/cri_adx_driver.irx), [identity](../build-function-index/owned-iop/identity.json), [read-only symbol/word inspector](../build-function-index/owned-iop/inspect_iop.py). Do not distribute the owned binary.

This is a32-bit little-endian MIPS IOP ELF(typeFF80),not a resident EE overlay. Original .symtab names and function sizes survive; server addresses below are module-relative and must not be imported into the resident function namespace. .iopmod identifies CRI_ADX_Driver; owned strings identify SJRMT1.01,IOPRNA1.21,ADXI8.92,July28,2003. Symbol text alone is supplemented with complete handler argument loads, call targets, registration and vtable evidence.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x140AF0](../recomp/config/output/sub_00140AF0_0x140af0.cpp) | `create_remote_SJRBF_over_iop_buffer_capacity_and_extension` | Confirmed owned server binding and full wrapper | Packs3inputwordsat264600,op20,receives1wordat264700,returnsremotehandle. Registered6510loadsall3andcallsSJRBF_Create511C;constructorborrowsbuffer/capacity/extensionandclaimsoneof128IOPrecords. NoEEpayloadcopyorlocalallocationhere;constructorcanreturnNULL. |
| [0x140B48](../recomp/config/output/sub_00140B48_0x140b48.cpp) | `create_remote_SJMEM_over_iop_memory_span` | Confirmed owned server binding and full wrapper | Packs2words,op21,response1/handle. Registered6550callsSJMEM_Create8AA4(buffer,size);constructorclaimsoneof32IOPrecords,storesborrowedspan,initializesvtable/reset. No automatic ownership/freeofcallerpayload. |
| [0x140C20](../recomp/config/output/sub_00140C20_0x140c20.cpp) | `query_remote_SJ_interface_uuid_into_shared_sixteen_byte_copy` | Confirmed complete UUID path | Op24sendsremotehandle,requests4responsewords,copiesall4from264700to2645C0,returnsshared2645C0. Handler6604callsstreamvtable10GetUuidandcopies16bytesintorequest/responsebuffer. ReturnisEEcopiedidentifierbytes,notaremoteobjectpointerornewallocation. |
| [0x140C90](../recomp/config/output/sub_00140C90_0x140c90.cpp) | `reset_remote_SJ_stream_through_rpc_25` | Confirmed complete reset route | Packs1handleword,tails139460(op25,request,1,NULL,0). Handler6674resolvesstreamvtable14Reset. No resultwordrequested;thetransport'sv0canbeoldresponsewordandisnotreset-successproof. |
| [0x140CC0](../recomp/config/output/sub_00140CC0_0x140cc0.cpp) | `acquire_remote_SJ_chunk_and_copy_iop_pointer_length_to_caller` | Confirmed complete GetChunk route | Packs{handle,pool,requestedbytes},op26,requests2words,copiesresponsepointer/lengthtocallera3. Handler66ACcallsvtable18(handle,pool,requested,&span),writesbothspanwords. ReturnedpointerisinIOPaddressdomain;wrapperdoesnotcopypayloadtotheEEormarkplaybackcompletion. |
| [0x140D30](../recomp/config/output/sub_00140D30_0x140d30.cpp) | `return_remote_SJ_chunk_to_original_pool_through_unget_rpc` | Confirmed complete UngetChunk route | Packs{handle,pool,span.pointer,span.length},op27,noresponse. Handler6704constructslocalspanandcallsvtable1CUngetChunk(handle,pool,&span). Doesnottransferthepayloadorfreehostmemory. |
| [0x140D80](../recomp/config/output/sub_00140D80_0x140d80.cpp) | `commit_remote_SJ_chunk_to_selected_pool_through_put_rpc` | Confirmed complete PutChunk route | Same4wordpackingbutop28. Handler6754callsvtable20PutChunk(handle,pool,&span). Commitandungetaredistinctownershipoperations;neitherwrappervalidateshandle/pool/spanextent. |
| [0x140E20](../recomp/config/output/sub_00140E20_0x140e20.cpp) | `query_remote_SJ_chunk_availability_with_truncated_response_count` | Confirmed complete IsGetChunk route and ABI mismatch | Packs{handle,pool,requestedbytes},op2A,requestsONEresponseword. Handler67E8callsvtable28(handle,pool,requested,&available),writes{result,available}tworesponsewords. EEreturns264700[0]butalsocopies264700[1]throughcallera3,although139460doesnotrefreshthatsecondwordforthisrequest. Localavailableoutputcanretainpriorcontents;noactualruntimefailureclaimed. |

Allresidentwrapperpackinguses264600request/264700response;transport139460copiesinputwordsinto2623C0andreturnedwordsfrom2624C0. It requestsRPCfunction400+op,mode0andignoresCallRpcstatus. IOP dtx_rpc_id9FE4 is90000200,matchingtheEEservice;dtx_rpc_func610subtracts400,admitsindices<40,loadscallbackAEA0+4*index/contextADA0+4*index,andcalls(context,buffer,receivedbytes/4),returningthesamebuffer. DTX_SetUrpcCbfCA0populatesthesetables. Thus registrationindex20reallymatchesEEop20;noassumptionfromnearbyfunctionorderingisneeded.

SJRMT_InitSvr6838registers20..2Ainorder:rbf_create6510,mem_create6550,uni_create658C,destroy65CC,get_uuid6604,reset6674,get_chunk66AC,unget6704,put6754,get_num_data67A4,is_get_chunk67E8. Existing140B98(SJUNIcreate),140BF0(destroy),140DD0(bytecount)gainserverconfirmationbutarenotduplicatecredit. Handlersuseuncheckedremoteobject/vtablepointers;analysisdoesnotinvokethem.

| IOP evidence interval | Bytes | SHA-256 |
| --- | --- | --- |
|SJRMT_InitSvr6838|280|863daee969d8edf5a4e8a1a72ade0f030004a19d43a9fe9f40ffc8680f54af72|
|dtx_rpc_func610|212|849da9e42bce03beb34ad1acd67ce865f91d4b83a1c88254e7803fc728024a82|
|DTX_SetUrpcCbfCA0|36|9c62e38ec269a8c05bd81f485520d8430248bb270fb14aca40eb1841327904a3|
|sjrmt_rbf_create6510|64|3d1860088b6587459c22670e43f2bc16ff5188757203352a36f4a07886462f3b|
|sjrmt_mem_create6550|60|2818343061fd29c5f7af73bc007e83c7e52c20f97cc3ed62b68b08a2680d36c3|
|sjrmt_get_uuid6604|112|c183554f06b6f9fa02f143315009c926d83f1c83d2087ea06d95726e55b169bc|
|sjrmt_reset6674|56|c3ba79e2d51db665e30eef9414965fc7db3f2c70cb185a9a3c8951369801e586|
|sjrmt_get_chunk66AC|88|b4013f5758dab9c80a01a8ddcc64dd557b7764392eb834d276c54f576445dbda|
|sjrmt_unget_chunk6704|80|47151553acbf0ea925870b5824e100ece0a3a1ee2d87d6cb7e778e24779e5794|
|sjrmt_put_chunk6754|80|a442cf5ac3156a7a3068386e37638e0b867c9e6f502b0dd98e4f9963b03dc06d|
|sjrmt_is_get_chunk67E8|80|eee95e0dc26656adc16019154eed06d5e03f8eb772e5dc484b7a08a4bee45ddc|

OwnedIOPvtableA154(SJRBF),A190(SJUNI),A3F0(SJMEM)areeach12words;slotsC/10/14/18/1C/20/24/28areDestroy/GetUuid/Reset/GetChunk/UngetChunk/PutChunk/GetNumData/IsGetChunk,independentlymatchingthehandlercalls. Constructorcapaci?tyandsemanticsareIOP-specific;thelocalEEimplementationmustnotbesubstitutedblindly.

[Earlier bridge/RPC notebook](SYMBOLS_CRI_SJX_BRIDGE_AND_RPC_BOUNDARIES.md)retainsinitialunknowns;thisownedserverevidencesupersedesthoseeightopaqueoperationrows. [LocalSJUNI](SYMBOLS_CRI_SJUNI_LINKED_CHUNK_POOLS.md)and[SJRB](SYMBOLS_CRI_SJRB_POOL_AND_CHUNK_OWNERSHIP.md)remainseparateimplementations. No game-speedchange,nativeport,recordedslowdownorperformancefixisclaimed.
