# Network DNAS: version301 method, paired keyed-digest expansion and record crypto flow

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. Eighteen complete clear bodies, method/auxiliary data, all101 alert targets and owned labels were independently read. No target/cipher operation, game, build, replay, attachment, network request or live-memory access occurred.

Version301hex, owned `key expansion`/`master secret`/write-key labels, paired digest methods and explicit0301 record headers support a TLSv1-shaped method family. The connected [keyed-digest implementation](SYMBOLS_NETDNAS_KEYED_DIGEST.md) remains only partly identified with HMAC; no standard vectors, symbolic inverse/security proof, enabled-live-protocol claim or gameplay slowdown attribution follows.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x729CA0](../recomp/config/output_ovl/o4/o4_00729CA0_0x729ca0.cpp) | `select_version_301_client_method_only_for_exact_version` | Confirmed complete literal guard/delegation | a0==301hex calls729CD0,otherwiseNULL. Does not negotiate or mutate a connection itself. |
| [o4 0x729CD0](../recomp/config/output_ovl/o4/o4_00729CD0_0x729cd0.cpp) | `lazily_clone_version_301_method_and_install_client_driver_selector` | Confirmed complete92-byte copy/overrides; runtime synchronization partial | Ownedflag765F48initial1;nonzero clearsflagbefore72AF90, copies5Chexbytes base765FB0toglobal7F1F98 in aligned/unaligned two32-byteiterations+28tail. Overrides14=7208C8,4C=729CA0. Flag0returns existingpointer. No locking, failure rollback or currentdestinationreadback. |
| [o4 0x729E28](../recomp/config/output_ovl/o4/o4_00729E28_0x729e28.cpp) | `expand_keyed_digest_secret_and_seed_with_iterated_a_blocks` | Confirmed complete two-context keyed-digest expansion; HMAC/PRF equivalence partial | a0method,a1secret,a2secretbytes,a3seed,t0seedbytes,t1output,t2requestedbytes. Allocates two705628contexts,initializeskey/method,computesA1=keyeddigest(seed). Eachloopreusescontext,updatesA,clonesstate,updatesseed,emitsdigest-sizedblockorrequestedfinalresidual;clonedstatefinalproducesnextA. Success1/failure0;freescontexts,wipes64scratchbytes. Someupdates/finalstatusesignored;no positive-method-size,negative-length,output-capacity or digest<=scratchadmission. |
| [o4 0x729FF0](../recomp/config/output_ovl/o4/o4_00729FF0_0x729ff0.cpp) | `xor_two_digest_expansions_using_overlapping_secret_halves` | Confirmed complete split/child/XOR flow; standard PRF proof partial | a0/a1digestmethods,a2seed,a3seedbytes,t0secret,t1secretbytes,t2output1,t3output2,stackargumentrequestedbytes. Splitsordinarynonnegative secretlength into ceil(n/2)halves at0andfloor(n/2),overlappingonebytewhenodd. Runs729E28eachhalf,thenXORsrequestedbytesfromoutput2intooutput1. Eitherfailure0;bothsuccess1. NonpositiveoutputcountskipsonlyXORafterchildcalls;negative/overflowsecretlengthadmissionandoutputaliascontractsremainunproven. |
| [o4 0x72A100](../recomp/config/output_ovl/o4/o4_0072A100_0x72a100.cpp) | `derive_key_expansion_from_secret_and_reverse_order_session_randoms` | Confirmed complete77-byte seed/paired expansion adapter | a0session,a1output1,a2output2,a3requestedbytes. Seedis13bytes`key expansion`+private44random32+private64random32. Calls729FF0(parentDC104/108methods,seed77,B0secret14/length10,outputs,count). Returnchildstatus. No seedwipe,secretvalidation or outputcapacityadmission. |
| [o4 0x72A1F8](../recomp/config/output_ovl/o4/o4_0072A1F8_0x72a1f8.cpp) | `install_version_301_direction_keyed_digest_cipher_key_and_iv_material` | Confirmed complete mode/material/export-shaped flow; standard equivalence partial | Modebit0selectssession68/privateCsequence/MACsecret14,else74/private28/MACsecret30;zeros8-bytesequence. Ensurescipher/keyeddigestcontexts,installsdestructor80=7056F8,initializeskeyeddigestmethod190,storesdeclaredsize,resetscipher. Deriveskeylengthfromcipher15Cbyte18or704B30;selectsMAC/key/IVrangesfrom188withmode12/21ordervsopposite,checks184extent,copiesMACsecret. Cipher15Cbit20addsPRFkey expansionwithownedclient/serverwritekeylabeland64/44randoms,plusIVblockPRFwithzerolengthsecretwhenIVpositive. Initializes704288(directionbit1),clearsfouroutputscratchregionsonsuccess;failure0withouttransactionalunwind/fullscrub. |
| [o4 0x72A6A8](../recomp/config/output_ovl/o4/o4_0072A6A8_0x72a6a8.cpp) | `allocate_pair_of_version_301_key_expansion_buffers_and_commit_material` | Confirmed complete resolution/allocation/derivation flow; partial failure ownership retained | Nonzeroprivate184returns1without188validation. Else726FC0resolvesB0->AC,cachescipher18C/digest190,computes2*(key+digest+IV)+1,cleansoldmaterial71B880,allocatestwobuffers. Commits184/188first,then72A100derivesbothoutputs. Successwipes/freessecondbufferandreturns1. Secondallocation/derivationfailuresreturn0withoutlocalfullfirst/secondbuffercleanup;initialnonzerofieldscanremainafterderivationfailure. No allocation-failure reproduction. |
| [o4 0x72A800](../recomp/config/output_ovl/o4/o4_0072A800_0x72a800.cpp) | `transform_version_301_record_and_validate_all_selected_padding_bytes` | Confirmed complete copy/cipher/padding/compatibility flow; security and malformed lengths partial | Nonzeroa1selectsdirection74cipher/privateCC,zero68/privateB4. Missingcache/cipher/methodcopiesrecordsource10todestinationC,aliasesandreturns1. Elseblockwidth704B48:forwardmulti-byteextendsbyblockwidth-remainderandfillsallpaddingbytes,usuallypadlen-1;option200/privateflag8canusepadlen. Calls703FF0butignoresstatus. Reversegetsfinalbyte,usesoption200/initialsequencezero/even-byteheuristictoestablishcompatflag8,derivesremovedcount,requirescount<=recordlength,checksallremovedbytesequalrawpaddingbyte,subtracts. Errorsdiagnostic+alert724470(2,15hex),0. Width0divisionbreak,zerorecordtailread,capacity/constant-time/securityproofremainunresolved. |
| [o4 0x72AAD0](../recomp/config/output_ovl/o4/o4_0072AAD0_0x72aad0.cpp) | `finalize_copied_version_301_transcript_context_to_output` | Confirmed complete context-copy/final/length flow | Copiesoriginala1intosession128with704DE0;failure0. Finalizes702448tooriginala2withstacklengthcell,returnsproducedlength,ignoringfinalstatus. No source-contextretention,outputcapacityorlengthinitializationguaranteeifcallbackfails. |
| [o4 0x72AB28](../recomp/config/output_ovl/o4/o4_0072AB28_0x72ab28.cpp) | `derive_twelve_finished_bytes_from_label_and_two_transcript_digests` | Confirmed complete seed/copy/final/paired-expansion flow | a0session,a1/a2transcriptcontexts,a3label,t0labelbytes,t1output. Copieslabeltostack,clones/finalizesbothcontextsinordertoseed,then729FF0(parentmethods,assembledseed,B0secret,output,16-byteotherscratch,12). Returns12onlyifchildnonzero,otherwise0. No label/digeststackextentadmission,finalstatuschecksorstackwipe. Ownedauxbindsclient/serverfinishedlabelsbelow. |
| [o4 0x72AC40](../recomp/config/output_ovl/o4/o4_0072AC40_0x72ac40.cpp) | `compute_version_301_record_keyed_digest_over_sequence_header_and_payload` | Confirmed complete direction/header/digest/carry flow; authentication proof partial | Nonzeroa2selectsdigest78,private28sequence/CCrecord/30secret;zero6C,C/B4/14. Getskeyeddigestmethodsize,initializeswithMACsecret,hashes8-bytesequence+type/0301/big-endianlengthfive-byteheader+recordsource10bytes,finalizestoa1. Initialization/finalfailure0;updatestatusesignored. Successincrements8-bytesequencebig-endiancarryandreturnsproducedlength. No length/outputcapacity,rolloverorconstant-timeguarantee. |
| [o4 0x72AD98](../recomp/config/output_ovl/o4/o4_0072AD98_0x72ad98.cpp) | `derive_forty_eight_master_secret_bytes_into_cached_session_storage` | Confirmed complete seed/input/output/status adapter; standard proof partial | a0session,originala2premasterbytes,a3length;originala1unused. Seedis13bytes`master secret`+private64random32+private44random32. Calls729FF0(parentmethods,seed77,premaster,length,B0+14output,stacksecondary,48),returns48onchildsuccesselse0. Doesnotcommitsavedsecretlength10orscrubseed/outputscratchhere. |
| [o4 0x72AE98](../recomp/config/output_ovl/o4/o4_0072AE98_0x72ae98.cpp) | `admit_selected_version_301_alert_numeric_codes_or_minus_one` | Confirmed complete101-entry numeric map; original enum partial | Unsignedinput<101selectsowned780800table;outside-1. Admittedvaluesreturnthemselves;allothers-1. Completeadmittedsetandtablehashbelow. All101targetsownedlocalJR/constantpairs. Thisentrydoesnotemitanyalert. |
| [o4 0x72AF88](../recomp/config/output_ovl/o4/o4_0072AF88_0x72af88.cpp) | `return_version_301_method_constant_seven_thousand_two_hundred` | Confirmed complete literal return; units unknown | Returns1C20hex(7200decimal),nootherwork. No time-unit interpretation inferred. |
| [o4 0x72AF90](../recomp/config/output_ovl/o4/o4_0072AF90_0x72af90.cpp) | `get_owned_version_301_base_method_descriptor` | Confirmed complete pointer getter | Returns765FB0;complete23wordmethodversion301andauxiliary765F58readbelow. Doesnotconstructconnectionorchooseclientmethod. |
| [o4 0x72AFA0](../recomp/config/output_ovl/o4/o4_0072AFA0_0x72afa0.cpp) | `allocate_version_301_private_state_then_invoke_selected_method_reset` | Confirmed complete child/status flow | Calls71C160(session);failure0. Successcalls(session8method)+8reset,discardsresetresultandreturns1. Parentallocatoritselfalsoinvokesmethodreset;thiswrapper'sadditionalcalldoesnotproveharmlessorcorrectforarbitrarymethods. |
| [o4 0x72AFE8](../recomp/config/output_ovl/o4/o4_0072AFE8_0x72afe8.cpp) | `destroy_version_301_private_state_through_shared_version_three_destructor` | Confirmed complete tail adapter | Tails71C220withoriginalarguments,retainingdigest/buffer/temporarycleanupcontract. No independentcloneofdestructorsemanticsorruntimewipeproof. |
| [o4 0x72AFF0](../recomp/config/output_ovl/o4/o4_0072AFF0_0x72aff0.cpp) | `reset_shared_private_state_then_install_connection_version_301` | Confirmed complete reset/version-store flow | Calls71C2E0(session),stores301hexinsession0,returnsresidualchildvalue. No explicitBooleanstatusnormalizationorrollback. |

## Complete method and auxiliary data

Owned765FB0..76600C,23 little-endian words, SHA-256 `d9c06a79d0fadb43ecc377679260a4a4f9e1676b3f30b5b34094d23a636f59ff`:

```text
00000301 0072AFA0 0072AFF0 0072AFE8 0071EEF0 0071EEF0
0071CE90 0071CF70 0071CD38 0071CBF0 0071D050 0071D090
0071C478 0071C688 0071C8A8 0071C9B0 0071C140 0071C100
0071C108 0071EF20 0072AF88 00765F58 00000000
```

Owned765F58..765FB0,22words, SHA-256 `04db877fdd4766cf9bf1c70dc59d93bc6e4edfe64ce10b23982d045f9e3615a2`:

```text
0072A800 0072AC40 0072A6A8 0072AD98 0072A1F8 0072AB28
0000000C 0072AAD0 65696C63 6620746E 73696E69 00646568
00000000 0000000F 76726573 66207265 73696E69 00646568
00000000 0000000F 0072AE98 00000000
```

This is mixed pointers, scalar fields and inline text: `client finished` and `server finished`, not22additionalfunctions. Initial765F48flagword1 has SHA-256 `67abdd721024f0ff4e0b3f4c2fc13bc5bad42d0b7851d456d88d203d15aaa450`. Runtimeclone7F1F98isoutsideownedfileandwasnotread.

## Owned labels, alert dispatch and boundaries

| Owned start | Complete string including NUL | SHA-256 |
| --- | --- | --- |
|780780|key expansion|`7e85b976bf69cf074d2065d405889b29b67c7282269ab7e2e632a63446a4ba38`|
|780790|client write key|`8a95178033c2283f7c611c06f02dc2aa4a55652ea4387cda2bd142e294118d27`|
|7807A8|server write key|`419a4680d327bea3dc2e87e657bacf18167f9cc3b9db2bc48b502555b5cb4186`|
|7807C0|IV block|`2fbb51331ca992ba20b6ea2f69c14888efb56700e9c4682208a5ac08216b539b`|
|7807D0|empty string|`6e340b9cffb37a989ca544e6bb780a2c78901d3fb33738768511a30617afa01d`|
|7807E8|master secret|`bcaf079e59524384a00c12e8dfa8412dada6d29fa4fcf35779569fffe165b992`|

7807D8..7807E0 is eight zero bytes used for initial-sequence comparison, SHA-256 `af5570f5a1810b7af78caf4bc70a660f0df51e42baf91d4de5b2328de0e83dfc`. The seed copies use explicit lengths, often excluding NUL:13-byte expansion/master labels,16-byte write-key labels and8-byte IV label.

780800..780994 contains101little-endianu32 alert targets, SHA-256 `56cf80ad90bcf3ccb9e474aa30159fc8437644b551bd801835986d67da7a848c`. All targets and target-delay constants were checked. Complete admitted decimal set:0,10,20,21,22,30,40,42,43,44,45,46,47,48,49,50,51,60,70,71,80,90,100. Each returns itself; every other input returns-1. This is deliberately different from the collapsing [older numeric maps](SYMBOLS_NETDNAS_SPARSE_ALERT_CODE_MAPS.md).

Record padding compatibility branches, ignored transform/update results and material commits are local facts. No record was decrypted, no TLS vector was run and no malformed input was submitted. In particular zero-length records still reach tail-byte reads in multi-byte reverse paths; no local capacity/length guard has been inferred from adjacent caller code. Keyed-digest output sizes and callback returns require independent admission before any correctness or security claim.

## Validation

Eighteen independent entries,1222 original instruction comments; complete aligned intervals matched owned bytes, no conflicting or omitted nonzero words. All local links resolve. Original denominator and protected/source-less classifications are unchanged. No runtime, engine, launcher or network configuration was modified.
