# HTTP overlay lock class names, optional lock callbacks and reference adjustments

Static owned File #1 o6 `nethttp.bin`,runtime ID6/base6E0000,SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Thirteen complete catalogue intervals reviewed, including initial dynamic-count loops, deduplication, callback-null defaults, counter store/error order and full27pointername table. No target execution/threads/locks tested/network/live attachment/build. Lock roles independently supported byownedpath73D398 `./os/lock/../../os/lock/r_lock.c` andnamedlockclasses; installedcallbacksandphysicalmutexbehaviorremainunknown. Hexadecimal evidenceunlessexplicit. [Erroridentity/queue](SYMBOLS_HTTP_CRYPTO_ERROR_STATE_AND_RING.md), [generic key reference users](SYMBOLS_HTTP_TYPED_NAME_AND_OBJECT_ACCESSORS.md), [string allocation](SYMBOLS_HTTP_GROWABLE_BYTE_BUFFERS.md). No unconditional thread-safety claim.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x70F8D0](../recomp/config/output_ovl/o6/o6_0070F8D0_0x70f8d0.cpp) | `lookup_crypto_lock_class_name_without_dynamic_locking` | Confirmed fullsignedbuiltin/dynamicrangebranches andownednames | Negativeclass=>owned73D390emptystring. IDs0..1Aindex27pointertable738410;higherrequiresdynamicvector73847C and(id-1B)<count,thenreturnsdata4[id-1B],elseemptystring. No lock heldornamecopy; no concurrency/negativecount admission. |
| [o6 0x70F938](../recomp/config/output_ovl/o6/o6_0070F938_0x70f938.cpp) | `find_or_register_crypto_lock_class_by_name` | Confirmed fulldedup/allocate/push/error/unlockflow | Snapshots70FAF8count,invokeslock70FC68(mode9,class18,file73D398,line74),IGNORESreturn. Nonnullnamecomparesallbuiltin/dynamicnames70F8D0/strcmp;equalreturnsID. Elselazily728F90vector,6FB670duplicatesname;7293B8pushreturnnewcount=>IDnewcount+1A. Push0freesduplicatednameandreturns0;otherallocationfail0. UnlockmodeA/class18invokedignoringresult; no actuallockavailability/atomicityproven. Countsnapshotprecedeslock. |
| [o6 0x70FA58](../recomp/config/output_ovl/o6/o6_0070FA58_0x70fa58.cpp) | `clear_registered_dynamic_crypto_lock_class_names` | Confirmed fullinitialcountgate/pop/free/vectorcleanup | Callslock9/class18 ignoringstatus. Nonnullvector73847C whilecount0nonzero729428popslastand70FFA8freesname;729558freesvector,clearsglobal. UnlockmodeA/class18tail. Count==0skipsloop; negative/corruptcountterminationnotguaranteed. Builtinnamesunchanged. |
| [o6 0x70FAF8](../recomp/config/output_ovl/o6/o6_0070FAF8_0x70faf8.cpp) | `count_builtin_and_dynamic_crypto_lock_classes` | Confirmed complete callback/countflow | Lock9/class18;returns1Bplusnonnullvectorcount0,else1B;unlockA/class18. Bothcallbackresultsignored,namesnotcopied. Countcanbeinvalidifexternalvectorcorrupted;no snapshotatomicityclaim. |
| [o6 0x70FB68](../recomp/config/output_ovl/o6/o6_0070FB68_0x70fb68.cpp) | `get_crypto_lock_class_name_with_dynamic_domain_lock_callbacks` | Confirmed fullbuiltin/negative/dynamicgates | Negativeorbadextendedclass=>owned73D3C0 ERROR;builtins0..1Areturn738410[id]withoutcallback. Extendedclasslock9/class18,rangechecks73847Ccount,returnsborrowednamepointerthenunlockA/class18. Namecanoutliveguard;callbacksnotrequiredforsuccess; no concurrentlifetimeguarantee. |
| [o6 0x70FC28](../recomp/config/output_ovl/o6/o6_0070FC28_0x70fc28.cpp) | `get_crypto_lock_operation_callback` | Confirmed completeglobalgetter | Returns738400callbackword,noadjustment/validation. |
| [o6 0x70FC38](../recomp/config/output_ovl/o6/o6_0070FC38_0x70fc38.cpp) | `get_crypto_reference_adjustment_callback` | Confirmed completeglobalgetter | Returns738404callbackword,noadjustment/validation. |
| [o6 0x70FC48](../recomp/config/output_ovl/o6/o6_0070FC48_0x70fc48.cpp) | `set_crypto_lock_operation_callback` | Confirmed completesetterandstatus | Storesa0to738400,returns1. No signature/installation/threadvalidation. |
| [o6 0x70FC58](../recomp/config/output_ovl/o6/o6_0070FC58_0x70fc58.cpp) | `set_crypto_reference_adjustment_callback` | Confirmed completesetterandstatus | Storesa0to738404,returns1. No signature/installation/threadvalidation. |
| [o6 0x70FC68](../recomp/config/output_ovl/o6/o6_0070FC68_0x70fc68.cpp) | `invoke_crypto_lock_callback_or_accept_without_callback` | Confirmed completeoptionalcallbackbranch | Nonnull738400receivesoriginala0..a3 anditsresultpropagates;nullcallbackreturns1withoutlocking. Registryusesmode9/A,class18,ownedr_lock.cpath;othercallerssupplydifferentclass/location. No physicalmutex/service/runtimeevidence. |
| [o6 0x70FC98](../recomp/config/output_ovl/o6/o6_0070FC98_0x70fc98.cpp) | `adjust_crypto_reference_count_through_override_or_lock_guarded_fallback` | Confirmed full override/fallback/errorafterstoreflow | Args(i32countcell,delta,class,file,line). Nonnull738404overridegetsoriginalargs,resultpropagated. Else70FC68(mode9,class,file,line)mustnonzero;failure-1withoutstore. Storesold+delta32,thenunlockmodeA;unlock0returns-1AFTERstorewithoutrollback,elsenewcount. Nullcallbackmakesbothguards1andplainunsynchronizedadd; no hardwareatomic/positivecountguarantee. |
| [o6 0x70FD50](../recomp/config/output_ovl/o6/o6_0070FD50_0x70fd50.cpp) | `get_crypto_error_identity_callback` | Confirmed completeglobalgetter andlinkedconsumer | Returns738408usedby70FD70defaultidentitydispatch. No current-threadlookup performedbygetter. |
| [o6 0x70FD60](../recomp/config/output_ovl/o6/o6_0070FD60_0x70fd60.cpp) | `set_crypto_error_identity_callback` | Confirmed completesetterandstatus | Storesa0to738408,returns1. Default70FD70fallbackmain114DF0constant1alreadydocumented; arbitrarycallbackidentity/lifetimecontractsunknown. |

Owned738410..73847C complete27pointertable SHA-256 `1465d367b70f1af5d610f5b0667b507e6a97b06c07fbb3c9dcea19bd22455abc`. EverypointedNUL-terminatednamewasread,hexclassindexorder:

| Class | Owned name |
| --- | --- |
|0|<<ERROR>> |
|1|err |
|2|err_hash |
|3|x509 |
|4|x509_info |
|5|x509_pkey |
|6|x509_crl |
|7|x509_req |
|8|dsa |
|9|rsa |
|A|evp_pkey |
|B|x509_store |
|C|ssl_ctx |
|D|ssl_cert |
|E|ssl_session |
|F|ssl |
|10|rand |
|11|debug_malloc |
|12|BIO |
|13|bio_gethostbyname |
|14|<<RESERVED>> |
|15|debug_malloc_mode |
|16|RSA_method |
|17|DH_method |
|18|app_lock |
|19|R_CACHE_LOCK |
|1A|GET_MODULE |

Owned738400/404/408callbackwordsand73847Cdynamicvectorstart0. Dynamicvectorcount0/data4 and append7293B8->729030returnNEWCOUNT,sofirstnewclass1B;pop729428->729190returnsremovedpointer. These helperbodieswereindependentlyread for the caller contract,withoutnewduplicate rows. Lookupfallbacks73D390emptystringand73D3C0 ERROR are distinctfrombuiltintableclass0 <<ERROR>>. Callbackinstallationsdo notproveactualsynchronization: fallbacklockdispatchacceptswithoutcallback,andreferencefallbackisplainload/add/store. Registryignoreslockfailureandreturnsborrowednameafterunlock; runtimeinstallation/concurrencyneedsseparateevidence.

Audit:285 verified instruction words, zero conflicts,5 omitted zero words (NOP padding), zero omitted nonzero words.
