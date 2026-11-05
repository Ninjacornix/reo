# LIG/FOG consumers and scene lighting work pools

Static File #1 US research, 2026-11-04. Nine complete original bodies reviewed.
Addresses/offsets/sizeshex; countsandpayloadbytecountsmarkeddecimal.
Filenameidentityconfirmedby[main1D4870](SYMBOLS_SCENARIO_AUXILIARY_RESOURCE_LOADING.md).
Internalparameternames/rendererusagepartial. Noexecution,liveattachmentsorfixes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B1DC0](../recomp/config/output_ovl/o2/o2_006B1DC0_0x6b1dc0.cpp) | `reset_scene_lighting_work_pools_and_cached_selection_candidate` | High mechanics; candidate field semantics | Zeros747530word,3240BE=FF,7474B0size80,748350sizeE00,748340byte,747540sizeE00,747538byte,3240BD=FF;zeros324090size8,32409Csize8,3240B0sizeC,3240A4sizeC;32decimalwords747430zero,747420zero. DoesnotclearloadedLIG/FOGbanks. |
| [o2 0x6B1EC0](../recomp/config/output_ovl/o2/o2_006B1EC0_0x6b1ec0.cpp) | `decode_version_four_lig_banks_into_fixed_scene_bank_storage_candidate` | High mechanics; candidate field semantics | Alwaysclears3DC1E0size1BD0. Headerword0must4;word4signedbankcount,offsets8+4*i. Eachrecordcopiesword0/4lowhalvestodestination0/2,copies34bytesinput8->dest4,38bytesinput3C->dest38,thenhalfcountdest2entries34bytesinput74+34*j->dest70+34*j. Destbankstride6F4. Validversioncalls1DC0evenifcount<=0;invalidversionleavesclearedbankswithoutworkreset. No bank/entrycountboundscheck. |
| [o2 0x6B2200](../recomp/config/output_ovl/o2/o2_006B2200_0x6b2200.cpp) | `apply_selected_fog_record_to_scene_color_vector_and_parameter_globals_candidate` | High mechanics; candidate field semantics | a0lowbyteindex;cachedsigned3240BD==indexreturns. Otherwiseindex<16decimalandrecord3DBBE0+60*indexword0nonzeroappliesfieldsbelow;invalid/emptyrecordstillpublishesindex3240BD. Ownedforward(0,0,-1)720228rotatedthroughEuler(recordhalves1C,20,0)to3240C0. No interpolationorframewait. |
| [o2 0x6B23E0](../recomp/config/output_ovl/o2/o2_006B23E0_0x6b23e0.cpp) | `decode_version_two_fog_records_and_publish_tail_color_candidate` | High mechanics; candidate field semantics | Clears3DBBE0size600. Headerword0must2;word4signedcount,zero->return. Positivecountcopies60bytesfromrelativeoffsets8+4*iinto60-bytecontiguousrecords. Copies4-bytetailfromcurrentoffsetcursor+60*count;forpositiveNthisisinputbase+8+64*N. Colorwordbits16/8/0->32407C/7D/7E,calls2200(0). Negativecounttakesnoentriesbutstilltailpathwithoutcursoradvance. No count/fileextentbounds. |
| [o2 0x6B2BD0](../recomp/config/output_ovl/o2/o2_006B2BD0_0x6b2bd0.cpp) | `allocate_first_free_scene_lighting_auxiliary_56_byte_record_candidate` | High mechanics; candidate field semantics | Signedbyte748340>=64decimalreturns0;otherwisescans64records748350+38*i,firstbyte0zero->byte0=1,count++,returnptr. Noentirerecordclear;fullscanreturns0. Signedcountsemanticsretained. |
| [o2 0x6B2CC0](../recomp/config/output_ovl/o2/o2_006B2CC0_0x6b2cc0.cpp) | `allocate_lighting_auxiliary_record_and_optionally_copy_52_byte_payload_candidate` | High mechanics; candidate field semantics | Calls2BD0;nonnullandinputa0nonnullcopies34bytesintorecord4,setsrecordbyte1=originala1,returnspointer. Nullreturns0. Noboundlengthorownershipverification. |
| [o2 0x6B2FA0](../recomp/config/output_ovl/o2/o2_006B2FA0_0x6b2fa0.cpp) | `allocate_first_free_scene_lighting_primary_56_byte_record_candidate` | High mechanics; candidate field semantics | Signedbyte747538>=64decimalreturns0;otherwisescans64records747540+38*i,firstbyte0zero->byte0=1,count++,returnptr. Noentirerecordclear,fullscan0. Separatepoolfrom2BD0. |
| [o2 0x6B3090](../recomp/config/output_ovl/o2/o2_006B3090_0x6b3090.cpp) | `allocate_lighting_primary_record_with_optional_payload_and_two_tags_candidate` | High mechanics; candidate field semantics | Calls2FA0;nonnulloptionaloriginala0copies34bytesintorecord4;setsbytes1/2fromoriginala1/a2,returnspointer. No nullinputcopyorGPUsubmission. |
| [o2 0x6B3830](../recomp/config/output_ovl/o2/o2_006B3830_0x6b3830.cpp) | `instantiate_default_lighting_handles_and_select_fog_zero_candidate` | High mechanics; candidate field semantics | Callsexisting1FE0(0),2020(i)for32decimalindices,2200(0). Then32times3090(0,0,3),storesresults747430[i],including0failures. Finally2CC0(0,0),stores747420. No resultfailuregateorrollback. CalledafterbothmainLIG/FOGloadattempts. |

2200 full validrecordfieldpublication,recordR=3DBBE0+60*index:

| Record fields | Global writes |
| --- | --- |
| float4/8 | float324010/324014 |
| wordC bytes16/8/0 | bytes324018/19/1A |
| word10bytes16/8/0 | bytes32408C/8D/8E,alpha32408F=FF |
| word14bytes16/8/0 | bytes324098/99/9A,alpha32409B=FF |
| word18 lowbyte,word18>>16 | halves3240CC/CE |
| halves1C/20 | Eulerpitch/yaw,roll0,rotatesowned(0,0,-1)to3240C0 |
| blocks24/34/44size10 | blocks323EDC/323EFC/323EECrespectively |
| words54/58 | words32404C/324050 |
| word5Clowbyte | byte3240BF |

ActualFOGfieldnamesbeyondcolorpackinganddirectionremainunresolved.
The6B1FE0bankselector/6B2020entrycreatorarealreadyreviewedanchorsandreceive
noduplicaterows. Existinggeneric`effect`labelsarenotproofthatLIGcontains
particleeffects;filename/fieldconsumercontextisretainedseparately.

Workpoolcapacity64*38hex=E00hexbytes. LIGstorage1BD0=4*6F4,entriesbegin70
withstride34andterminalword6F0;originalcopycountsremainunboundedbythese
capacitiesintheconsumerbody. FOGstorage600=16*60hex. Loadedbankcontents,
activecountsandglobalswerenotreadlive;nooversizedfileorallocationfailure
wasreproduced. Themainloaderreusesatemporarybufferandfinalizesregardless
success,asitsownnotebookrecords.
