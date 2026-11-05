# CVFS composed 64-bit file byte-size query routes

Static File #1 US original resident ELF, 2026-11-05. Owned SLUS_207.65 SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Two complete previously unresolved bodies, full connected disc/host optional dispatchers and size accessors, and both26-word owned interfaces reviewed. No game, file request, RPC, build or process accessed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x137138](../recomp/config/output/sub_00137138_0x137138.cpp) | `query_cvfs_file_byte_size_from_optional_high_low_selectors_ca_cb` | High complete mechanics; size role proved for owned disc/host interfaces | Splits originalnamea0 with135AD0 into stackdevice/path,135888 resolves interface. DoesnotguardNULLresolutionbeforeloadingmethod60. Ifmethodnonnull invokesit twice(originalname,CA,resolvedpath,0),then(originalname,CB,resolvedpath,0). Returns(low32(first)<<32)+unsignedlow32(second),ormethodmissing0. Onbothownedinterfaces these selectors are high/low filename byte-size queries. Other dynamically registered interfaces may differ. |
| [0x1371F0](../recomp/config/output/sub_001371F0_0x1371f0.cpp) | `query_cvfs_file_byte_size_cc_cd_after_uninitialized_device_name_lookup` | High complete mechanics; intended admission and public name unresolved | Allocates290hexstackbytes,then135560(stackbase)readsdevice-nameinput BEFORE any store tothatbufferor135AD0 split. Nullinterfacereturn0. Otherwise splitsoriginala0,requiresinterface60,andinvokesit(originalname,CC,resolvedpath,originala1)thenCDwithsameargs;combinesfirsthigh32/secondunsignedlow32. Owneddisc/hostCC/CDarefilename byte-size halves;backend dispatchers retain originala0 andignoreextraa2/a3 along thisroute. No successful device selection is assumed. |

This closes two semantic roles by connecting selector consumers to actual interface implementations, rather than guessing from numeric selector adjacency. It does not establish original exported API names. The earlier residual ledger correctly retained them as unknown before this connection; no numerical operation label alone earns this credit.

Disc interface21CBF8[26] has method60=13A180,method44=NULL; host21DA88[26] has method60=13BCF0,method44=NULL. Their104-owned-byte SHA-256 values are `110e07237b9879134ef9aa44289116e0a63f2ff0392b117f842bebb325692d8a` and `40df6d55908bd06ecee4d4c144c3a30a7a3b2aed1f0afcd9202dd43ffd3f2a00` respectively. These tables bind behavior only when selected registry entry is oneoftheseinterfaces.

| Selector | Disc13A180 | Host13BCF0 | Proven unit |
| --- | --- | --- | --- |
|CA/CC|13A160returns0highhalf|13BCA0 ->13BC38 ->13B330,arithmetichigh32|File byte-size high32|
|CB/CD|13A168 ->13A088,metadataword4|13BCC0 ->13BC38 ->13B330,low32|File byte-size low32|
|12B|Returns1|Returns1|Capability/status distinctfromsize halves|

Exact correction to the prior [backend notebook](SYMBOLS_CRI_BACKENDS.md): CD branches13A1D0->13A220 and13BD40->13BD90 take low-size accessors. It does **not** share the constant1 branches13A230/13BDA0 usedby12B. Four existing role rationales were corrected:13A168,13A180,13BCC0,13BCF0. Disc metadataword4isindependentlyusedbydvCiGetFileSize; host13B330 opens/resolvesfilename,seeksendthrough1383E8,closes,andreturnsendposition. Thus byte-size naming is grounded. No assumption that the two separately executed halfqueries are an atomic snapshot.

1371F0's stack/device lookup order is an observed source/owned instruction sequence, not a reproduced failure. It leaves newly allocated stack bytes as the input NUL-terminated string before a local initialization. No direct indexed caller or aligned literal pointer occurrence was found in the owned main ELF for either newly mapped entry; this does not prove unreachability from dynamic imports or computed calls.137138'sNULLdevice dereference and1371F0'suninitializedinput must remain visible in any later rewrite or test plan; this pass makes no native changes.

[CVFS split/lookup](SYMBOLS_CRI.md), [typed backend implementations](SYMBOLS_CRI_BACKENDS.md), and [earlier residual inventory](STATIC_MAIN_122700_13FFFF_REMAINING_CONTRACTS.md) preserve surrounding contracts. No new runtime incident or performance result is claimed.
