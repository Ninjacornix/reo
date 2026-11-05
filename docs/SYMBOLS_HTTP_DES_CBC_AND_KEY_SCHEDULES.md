# HTTP overlay DES/triple DES rounds, CBC adapters and key schedules

Static owned File #1 o6 `nethttp.bin`, runtime ID6/base6E0000, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Seventeen complete catalogue intervals reviewed with full original bounds, loop-entry tests and allbranch/delayslots. Alltruncatedtoolrangeswere reread beforeclaimingfullbodycoverage. Noexecution, cipher/keytestvectors, network/liveattachment or build. Hexadecimalnumbers throughout evidence. DES/tripleDESfamily supportedbyowned [providerrecords](SYMBOLS_HTTP_CRYPTO_PROVIDER_OPERATION_ADAPTERS.md) plus independentcall/key/roundshape; no originalsymbol or standards-equivalenceproof.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x6FFF90](../recomp/config/output_ovl/o6/o6_006FFF90_0x6fff90.cpp) | `transform_des_block_with_initial_final_permutations_and_direction` | Confirmed full16round/control/table flow; testvector conformance untested | Reads two64-bit slots fromstate0/8 holding32-bit halves. Initial bit-exchange permutation, rotateleft3/maskFFFFFFFF, then16 Feistel rounds. Directionnonnull uses16-byte roundkeypairs ascending0..F0,zero descendingF0..0. Eachround XORs eight bounded64-entry tables atprovider+240..1040. Four unrolledrounds periteration; initialcounter18 decrement8 beforetest gives16rounds. Reversecounter1E decrement8 andbgtz also16. Finalrotate/permutation swaps/storeshalves; no pointer/capacity checks or scalarstatus. |
| [o6 0x700AA0](../recomp/config/output_ovl/o6/o6_00700AA0_0x700aa0.cpp) | `transform_des_round_core_without_outer_permutations` | Confirmed complete16roundforward/reverse flow | Samekeypair/table Feistel mechanism as6FFF90, butnoouterinitial/finalpermutation. Readsstate8/0 intooppositeinternalhalves, rotates/masks32bits,16rounds eachdirection, rotatesback/masks andstoresstate8/0. Usedbetweenonepair ofpermutations fortripleDES. Full4xunrolledloopbranch/delaycounts reviewed; no scalarstatus. |
| [o6 0x701480](../recomp/config/output_ovl/o6/o6_00701480_0x701480.cpp) | `transform_triple_des_block_encrypt_decrypt_encrypt` | Confirmed full threecorecalls and permutations | Performsinitialpermutation once, calls700AA0(block,key1,1),then(key2,0),then(key3,1), appliesfinalpermutation once. In-place16-byteinternalslotbuffer, threeindependentschedules; no scalarstatus, keyvalidation or byteserializerhere. |
| [o6 0x701630](../recomp/config/output_ovl/o6/o6_00701630_0x701630.cpp) | `transform_triple_des_block_decrypt_encrypt_decrypt_reverse_keys` | Confirmed full threecorecalls and permutations | Initialpermutation;700AA0(block,key3,0),then(key2,1),then(key1,0), finalpermutation. Reverseskeyorder/directionfrom701480; nooriginalalgorithmnameor testvectorequivalenceassertion. |
| [o6 0x7017E8](../recomp/config/output_ovl/o6/o6_007017E8_0x7017e8.cpp) | `transform_des_cbc_bytes_with_partial_tail_and_updated_iv` | Confirmed fullbothdirections/initialtests/fourtailtables | Args(input,output,bytecount,keySchedule,iv8,direction). Nonzero encrypt:little-endian32halves, XORIV,6FFF90direction1,write8bytes andchain; final1..7inputbyteszero-fillblock thenwriteFULL8cipherbytes. Zero decrypt:readFULL8cipherbytes evenfortail,6FFF90direction0,XORpreviousIV,writeonlyrequestedtailbytes;chainIVbecomessavedciphertext. Zero countskipsblockwork butreads/writesIV. No negativecount/outputcapacity/padding-validationguards. Preservesinputcipherbeforeoutput, allowingexactin-placefullblocks; arbitraryoverlapnotchecked. Clears16-bytestackblockbeforeexit. |
| [o6 0x701FA8](../recomp/config/output_ovl/o6/o6_00701FA8_0x701fa8.cpp) | `transform_triple_des_cbc_bytes_with_partial_tail_and_updated_iv` | Confirmed fullbothdirections/initialtests/tailtables | Args(input,output,bytecount,key1,key2,key3,iv8,direction). Samefull/partial CBCcontract as7017E8, but encryptcalls701480 anddecrypt701630. Encryptionpartialzero-fillsandemits8;decryptpartialreads8andemitsrequestedprefix. Loads/stores8-byteIVevenzerocount; no signedcount/capacity/PKCSpaddinggate. Savescipherbeforewriteandclearsstackblock. Alloriginalintervalwordsreviewed. |
| [o6 0x703530](../recomp/config/output_ovl/o6/o6_00703530_0x703530.cpp) | `get_two_key_triple_des_cbc_cipher_method_record` | Confirmed getter/ownedfullrecord | Returns736588:words2B/8/10/8,init703550,CBC703690,0,workspace480,thenfourzero. Two8-bytekeys corroborated by703550 schedulecopy. |
| [o6 0x703540](../recomp/config/output_ovl/o6/o6_00703540_0x703540.cpp) | `get_three_key_triple_des_cbc_cipher_method_record` | Confirmed getter/ownedfullrecord | Returns7365B8:2C/8/18/8,init703608,CBC703690,0,workspace480,thenfourzero. Owned3DES_CBC_EDEprovider factorybinds703540. |
| [o6 0x7036B8](../recomp/config/output_ovl/o6/o6_007036B8_0x7036b8.cpp) | `get_single_des_cbc_cipher_method_record` | Confirmed getter/ownedfullrecord | Returns7365E8:1F/8/8/8,init7036C8,CBC703708,0,workspace180,thenfourzero. Owned DES_CBCprovider factorybinds7036B8. |
| [o6 0x703550](../recomp/config/output_ovl/o6/o6_00703550_0x703550.cpp) | `initialize_two_key_triple_des_schedules_copying_first_into_third` | Confirmed fullkey/IV/schedulecopyloop | OptionalIVcopies8bytes intoctx+C;alwayscopiesoriginalIVctx+C toworkingIV2C. Nonnullkey calls7244B0(key,schedule78),then(key+8,schedule+180), ignoresresults. Copies180bytesfirstscheduleinto+300 with20-bytechunks (initialentryexecutescopythenendcompare). Nullkeyskipskeywork. No scalarstatuscontract or buffer/overlapvalidation. |
| [o6 0x703608](../recomp/config/output_ovl/o6/o6_00703608_0x703608.cpp) | `initialize_three_independent_triple_des_schedules` | Confirmed complete optionalkey/IV flow | SameIVhandlingas703550. Nonnullkey initializes scheduleatctx78 fromkey0,+180 fromkey8,+300 fromkey10;last7244B0 tailcalled. No resultcheckforfirsttwocalls; returnsdependonlastcallwhenkeynonnull. No prior-schedulecleanup. |
| [o6 0x7036C8](../recomp/config/output_ovl/o6/o6_007036C8_0x7036c8.cpp) | `initialize_single_des_schedule_and_reset_working_iv` | Confirmed fulltailwrapper | OptionalIV8->ctx+C,alwaysctx+C->2C;nonnullkeytailcalls7244B0(key,ctx78). Nullkeyreturnswithoutkeywork. No explicituniformscalarstatus or key/IVlengthparameters. |
| [o6 0x703690](../recomp/config/output_ovl/o6/o6_00703690_0x703690.cpp) | `invoke_triple_des_cbc_using_context_schedules_iv_and_direction` | Confirmed complete argumentpacking | Tail701FA8(originalinputa2,originaloutputa1,unsignedLOW32originalcounta3,ctx78,ctx78+180,ctx78+300,ctx2C,ctx4). Highcountbitsdiscarded. No processing/capacitycheckinwrapper. |
| [o6 0x703708](../recomp/config/output_ovl/o6/o6_00703708_0x703708.cpp) | `invoke_single_des_cbc_using_context_schedule_iv_and_direction` | Confirmed complete argumentpacking | Tail7017E8(originalinputa2,originaloutputa1,unsignedLOW32originalcounta3,ctx78,ctx2C,ctx4). No key/state/sizegate or outputcountreturnedlocally. |
| [o6 0x7243F8](../recomp/config/output_ovl/o6/o6_007243F8_0x7243f8.cpp) | `check_all_eight_des_key_bytes_have_owned_odd_parity` | Confirmed fullboundedloopandall256tablevalues | Fori0..7 requiresparityTable73EFA0[keybyte]==keybyte;firstmismatch0,allpass1. All256ownedvaluesverifiedequaloddparitynormalization x whenpopcountodd elsex XOR1. No keynullguard or paritymutation. |
| [o6 0x724440](../recomp/config/output_ovl/o6/o6_00724440_0x724440.cpp) | `check_des_key_matches_one_of_sixteen_owned_weak_key_patterns` | Confirmed complete16comparisons/table | memcmp8 against16patterns739080 inforwardorder;anyexactmatch1,none0. Allpatternbytespreservedbelow. No paritynormalizationbeforecomparison. |
| [o6 0x7244B0](../recomp/config/output_ovl/o6/o6_007244B0_0x7244b0.cpp) | `expand_des_key_into_sixteen_round_key_pairs_with_optional_checks` | Confirmed fullchecks/permutations16roundloop/tables | Ifprovider+1Cnonzero,requires7243F8 parityelse-1, rejects724440 weakpatternwith-2. Otherwisechecks skipped. Loadskey8little-endian, permutesinto28-bithalves;16iterations use739100 rotateflags(one/two right28-bitrotations), eight64-entrySKBtables73DFA0..73EDA0, pack/mask32bits andstoretwo64-bitwordsperround toschedule0..FF. Returns0; no outputcapacity/keynullguard. Scheduleworkspace180inmethods islargerthanthis100-bytewrite. |

Round lookup range735568..736568 is1000bytes/51264-bitwords (eight64entrytables), SHA-256 `c3100a23d4a819ed5714cdda9924b11a00735a05bd3ab30c4ac5368722b51e38`. Data extent and boundedindexing reviewed; complete cryptographic table correctness was not formally tested.

Keytable evidence:

| Owned region | Meaning / exact data | SHA-256 |
| --- | --- | --- |
|739080,80bytes|16eight-byte weak-pattern comparisons below|`1bca82a07c85d0987ba52d64109d69ec5a26e3075fe48798105662ee47093094`|
|739100,40bytes|16words:0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0|`791b133a2ef1cc2f06dd89cb3824a247ba86e6eb38c678dfdeecc3d9d6161b07`|
|73DFA0,1000bytes|eight64entry64-bitSKBselectiontables|`75ba70231caca860a98abc4d15f5f2223e08177228d3ecee63da62790901cfef`|
|73EFA0,100bytes|all256odd-paritynormalizationbytes independentlychecked|`ba347f0da6d742f7fdcc4710305b97ea02ab6ff39d89fb93be853b03a82757ff`|

```
0101010101010101 fefefefefefefefe 1f1f1f1f0e0e0e0e e0e0e0e0f1f1f1f1
01fe01fe01fe01fe fe01fe01fe01fe01 1fe01fe00ef10ef1 e01fe01ff10ef10e
01e001e001f101f1 e001e001f101f101 1ffe1ffe0efe0efe fe1ffe1ffe0efe0e
011f011f010e010e 1f011f010e010e01 e0fee0fef1fef1fe fee0fee0fef1fef1
```

Complete8-entrytailjump-tables (index0..7 correspondsfallthroughtail1..8):

```
73BE90:701A70 701A60 701A50 701A44 701A38 701A28 701A18 701A0C
73BEB0:701EC4 701EB0 701E9C 701E88 701E78 701E64 701E50 701E3C
73BED0:70223C 70222C 70221C 702210 702204 7021F4 7021E4 7021D8
73BEF0:70269C 702688 702674 702660 702650 70263C 702628 702614
```

The methods describe eight-byte external blocks but16-byte internal buffers containing two64-bit slots with32-bit halves. The distinction prevents incorrectly labelingthecipher as128-bitblock. Positive full/partial lengths were traced statically; arbitrarysignedcountadmission and overlapremainunproved. Zero-filledfinalencryptionblocks and truncateddecryptionoutput are literalCBCtailmechanics, not an assertion of a complete padding protocol or runtime safety defect.

Audit:2962 verified instruction words, zero conflicts,6 omitted zero words (NOP padding), zero omitted nonzero words.
