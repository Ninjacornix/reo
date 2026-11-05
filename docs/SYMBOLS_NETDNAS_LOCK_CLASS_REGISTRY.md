# Network DNAS: named lock classes and optional hook registration

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request or live-memory read occurred.

Nine bodies were independently read through initial loop tests, guard callbacks, lookup admission, dynamic cleanup and return defaults. All27 owned table764BA0 pointers and every NUL-terminated name were read. Owned77E780 isemptystring;77E7B0 is `ERROR`;77E788 is `./os/lock/../../os/lock/r_lock.c`. Names explain selectors in [library reference hooks](SYMBOLS_NETDNAS_LIBRARY_HOOKS.md), [certificate references](SYMBOLS_NETDNAS_ASN1_REFERENCE_OBJECT.md), [CRL references](SYMBOLS_NETDNAS_ASN1_REVOCATION.md) and [key payload references](SYMBOLS_NETDNAS_KEY_PROVIDER_BRIDGES.md). Names do not establish that a host mutex exists or an operation ran.

| Hex class | Owned name pointer | Exact name |
| --- | --- | --- |
| 0 |77E770 |<<ERROR>> |
| 1 |77E768 |err |
| 2 |77E758 |err_hash |
| 3 |77E750 |x509 |
| 4 |77E740 |x509_info |
| 5 |77E730 |x509_pkey |
| 6 |77E720 |x509_crl |
| 7 |77E710 |x509_req |
| 8 |77E708 |dsa |
| 9 |77E700 |rsa |
| A |77E6F0 |evp_pkey |
| B |77E6E0 |x509_store |
| C |77E6D8 |ssl_ctx |
| D |77E6C8 |ssl_cert |
| E |77E6B8 |ssl_session |
| F |77E6B0 |ssl |
| 10 |77E6A8 |rand |
| 11 |77E698 |debug_malloc |
| 12 |77E690 |BIO |
| 13 |77E678 |bio_gethostbyname |
| 14 |77E668 |<<RESERVED>> |
| 15 |77E650 |debug_malloc_mode |
| 16 |77E640 |RSA_method |
| 17 |77E630 |DH_method |
| 18 |77E620 |app_lock |
| 19 |77E610 |R_CACHE_LOCK |
| 1A |77E600 |GET_MODULE |

Class3/x509 plus full three-child layout/certificate callers strengthens the [732080 object](SYMBOLS_NETDNAS_ASN1_REFERENCE_OBJECT.md) certificate-family identity; exact original symbols remain descriptive labels. No timing, contention measurement or slowdown attribution follows.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x710368](../recomp/config/output_ovl/o4/o4_00710368_0x710368.cpp) | `get_netdnas_lock_class_name_without_guard_or_empty_default` | Confirmed lifecycle/data/control flow; domain limits retained | Signed id<0 returnsowned77E780 emptystring. Id0..1A indexes27wordtable764BA0. Larger ids useoptionalarray764C0C[id-1B] whenindex<count,elseempty. Borrowedpointer;no guard/retain or dynamicarrayconcurrencyproof. |
| [o4 0x7103D0](../recomp/config/output_ovl/o4/o4_007103D0_0x7103d0.cpp) | `get_or_register_netdnas_lock_class_name_under_optional_guard` | Confirmed lifecycle/data/control flow; domain limits retained | Counts710590 first;710700(mode9,class18,path77E788,line74),statusignored. NonNULLrequestedname scansallknown ids through710368/strcmp andreturns existingindex onexactmatch. Elselazily729688 dynamicarray,6FAC88 duplicatesname,729AB0appends;successreturnsnewcount+1A,failedappendfreesduplicate,failures0. CallsmodeAguard exit/statusignored. Registrationrace,duplicatecasefolding andNULLnameallocationsemanticsremainpartial. |
| [o4 0x7104F0](../recomp/config/output_ovl/o4/o4_007104F0_0x7104f0.cpp) | `clear_netdnas_dynamic_lock_class_names_under_optional_guard` | Confirmed lifecycle/data/control flow; domain limits retained | 710700(mode9,class18,path77E788,lineAE),statusignored. Ifarray764C0CnonNULL,initialcounttestthenpop/free allstrings,729C50array,zerosglobal. TailmodeAguard(lineBC),returnsdelegatedresult. Builtin27namesunchanged;borrowednamepointerscanbeinvalidated. |
| [o4 0x710590](../recomp/config/output_ovl/o4/o4_00710590_0x710590.cpp) | `count_netdnas_builtin_and_dynamic_lock_classes` | Confirmed lifecycle/data/control flow; domain limits retained | Callsoptionalguardmode9/class18,lineC4;returns1B plusdynamicarraycountifpresent,thenmodeAlineCA. Guardstatusesignored;resultnotconcurrentsnapshotproof. |
| [o4 0x710600](../recomp/config/output_ovl/o4/o4_00710600_0x710600.cpp) | `get_netdnas_lock_class_name_with_guarded_dynamic_lookup_or_error_string` | Confirmed lifecycle/data/control flow; domain limits retained | Id<0 returnsowned77E7B0 ERROR;0..1Abuiltintablewithoutguard. Largeridmode9/class18,checksarray/indexandreturnsnameorERROR,modeAunlock;statusesignored. Resultborrowednotretained;differentinvaliddefaultfrom710368emptystring. |
| [o4 0x7106C0](../recomp/config/output_ovl/o4/o4_007106C0_0x7106c0.cpp) | `get_netdnas_optional_library_lock_hook` | Confirmed lifecycle/data/control flow; domain limits retained | Returns764B90 pointer;getterdoesnotacquirelock. Bodydistinctfromidentitycallback764B98. |
| [o4 0x7106D0](../recomp/config/output_ovl/o4/o4_007106D0_0x7106d0.cpp) | `get_netdnas_optional_library_reference_arithmetic_hook` | Confirmed lifecycle/data/control flow; domain limits retained | Returns764B94 pointer;usedby710730customreferencearithmeticpath. Noinvocationoratomicityproof. |
| [o4 0x7106E0](../recomp/config/output_ovl/o4/o4_007106E0_0x7106e0.cpp) | `set_netdnas_optional_library_lock_hook_and_return_one` | Confirmed lifecycle/data/control flow; domain limits retained | Storesoriginala0at764B90,returns1. NULL enables710700unconditionaldefaultsuccess,notamuteximplementation. |
| [o4 0x7106F0](../recomp/config/output_ovl/o4/o4_007106F0_0x7106f0.cpp) | `set_netdnas_optional_library_reference_arithmetic_hook_and_return_one` | Confirmed lifecycle/data/control flow; domain limits retained | Storesoriginala0at764B94,returns1. NULL selects710730fallbackguard/add/unlock;nohostatomicoperationintroduced. |
