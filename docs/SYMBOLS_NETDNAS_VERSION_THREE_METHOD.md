# Network DNAS: version-three base method, state lifetime and cipher catalogue

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request or live-memory read occurred.

Ten complete clear bodies, all35cipherrecords and names, complete23wordmethod765798 and22wordauxiliary765740 were independently read. Version300hex and shipped cipher labels support an SSLv3-style base method family. This does not establish enabled runtime use, supported network configuration, algorithm correctness, original symbols or security. Connections: [secure lifecycle](SYMBOLS_NETDNAS_SECURE_LIFECYCLE.md), [handshake adapters](SYMBOLS_NETDNAS_HANDSHAKE_MESSAGE_ADAPTERS.md), [digest context lifetime](SYMBOLS_NETDNAS_CIPHER_CONTEXT.md), and [pointer arrays](SYMBOLS_NETDNAS_POINTER_ARRAY.md). No timing or gameplay slowdown cause is claimed.

Partial allocation paths and preserved/reset fields remain explicit. They do not authorize a cleanup fix or claim a leak reproduced during playtesting. Offset-only accessors retain narrow field meaning until more caller evidence is available.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x71B880](../recomp/config/output_ovl/o4/o4_0071B880_0x71b880.cpp) | `wipe_free_and_clear_netdnas_version_three_private_buffer_188` | Confirmed local lifetime/data/control flow; protocol limits retained | Ifprivate54->188nonNULL,wipes184bytes,free710A40,clears188;alwaysclears184. No outer/privateNULLadmission,capacityvalidationor normalizedstatus. |
| [o4 0x71C0E8](../recomp/config/output_ovl/o4/o4_0071C0E8_0x71c0e8.cpp) | `return_netdnas_version_three_method_constant_7200` | Confirmed local lifetime/data/control flow; protocol limits retained | Returns1C20hex(7200decimal); no unit/timeoutcontractassigned. |
| [o4 0x71C0F0](../recomp/config/output_ovl/o4/o4_0071C0F0_0x71c0f0.cpp) | `get_netdnas_version_three_base_method_descriptor_765798` | Confirmed local lifetime/data/control flow; protocol limits retained | Returns765798; complete23wordmethodrecordbelowdeclaresversion300hex andcryptoaux765740. No initialization,sessionallocationorclient/servernegotiation. |
| [o4 0x71C100](../recomp/config/output_ovl/o4/o4_0071C100_0x71c100.cpp) | `return_netdnas_version_three_cipher_descriptor_count_thirty_five` | Confirmed local lifetime/data/control flow; protocol limits retained | Literal23hex(35) return, matching35owned40bytedescriptors. No current runtimecipherenabledclaim. |
| [o4 0x71C108](../recomp/config/output_ovl/o4/o4_0071C108_0x71c108.cpp) | `get_netdnas_version_three_cipher_descriptor_in_reverse_index_order` | Confirmed local lifetime/data/control flow; protocol limits retained | Unsignedindex<35returns7651C8+(34-index)*28hex;elseNULL. All35record/nameintervalsreadbelow;no algorithmexecutionor negotiationvalidation. |
| [o4 0x71C140](../recomp/config/output_ovl/o4/o4_0071C140_0x71c140.cpp) | `get_version_three_buffered_word_b8_unless_session_state_38_is_f1` | Confirmed local lifetime/data/control flow; protocol limits retained | Session38==F1hexreturns0;otherwise(private54)->B8. Branch-likelyloadprivateonlyonnon-F1path. NoNULLsessionadmissionor unprovedpending-byteAPIalias. |
| [o4 0x71C160](../recomp/config/output_ovl/o4/o4_0071C160_0x71c160.cpp) | `allocate_netdnas_version_three_private_state_and_two_digest_contexts` | Confirmed local lifetime/data/control flow; protocol limits retained | Allocates/zeros198hexbytes,allocates704D20contextsF8thenFC. Bothsuccessinstallssession54andcallsmethod8->slot8(session),ignoresresetresult,returns1. Allocation/childfailure reports(14hex,93hex,21hex),returns0withoutlocalpartialouter/firstdigestcleanup. Full callerunwindscopeunresolved. |
| [o4 0x71C220](../recomp/config/output_ovl/o4/o4_0071C220_0x71c220.cpp) | `destroy_netdnas_version_three_private_digests_buffers_and_temporary_state` | Confirmed local lifetime/data/control flow; protocol limits retained | DestroysoptionalF8/FC704D98,frees94/AC/C8,71C410temporarycleanup,wipes198hexprivatebytes,freesprivate,clearssession54. NoprivateNULLadmission;sharednestedpointeralias or fullsecurewipeproofnotestablished. Returnnotnormalized. |
| [o4 0x71C2E0](../recomp/config/output_ovl/o4/o4_0071C2E0_0x71c2e0.cpp) | `reset_netdnas_version_three_private_state_preserving_buffer_and_digest_owners` | Confirmed local lifetime/data/control flow; protocol limits retained | Savesprivate94/98andAC/B0pairs,F8/FCdigestpointers;freesC8andclears,71C410cleansotherownedtemporaries,wipes198hexbytes,restoressixsavedfields,wipesbuffer94for98bytesifnonnull. Calls71F160,dropssession4C,setsprivate114/118/11C/120=0,session0=300hex,privateB8/BC=0. Preservesdigestcontextswithoutreinitializingthemhere;noalias/capacitycontractproof. |
| [o4 0x71C410](../recomp/config/output_ovl/o4/o4_0071C410_0x71c410.cpp) | `release_netdnas_version_three_key_buffer_object_160_and_list_17c` | Confirmed local lifetime/data/control flow; protocol limits retained | Calls71B880;optionalprivate160released701EF0andcleared;optional17Cpointerarrayreleased729C28withelementdestructor6FC878,thencleared. Targetdestructordomainsremainseparate;noouterfreeor completearbitraryaliasproof. |

Complete owned35record interval7651C8..76573F SHA-256: **07e77069970bf5bee3457343f6642f581c862c746af48b6ef3e11e785fdcf955**. Names are shipped labels, not tested implementations.

| Record | Ten u32 words | Name / owned address |
| --- | --- | --- |
| `7651C8` | `00000001 0077F048 03000001 00000000 00A30021 00000000 00000000 00000000 0037FFFF 00000000` | `NULL-MD5` / `77F048` |
| `7651F0` | `00000001 0077F038 03000002 00000000 00A50021 00000000 00000000 00000000 0037FFFF 00000000` | `NULL-SHA` / `77F038` |
| `765218` | `00000001 0077F028 03000017 00000000 00921110 00000000 00000205 00000000 0037FFFF 00000000` | `EXP-ADH-RC4-MD5` / `77F028` |
| `765240` | `00000001 0077F018 03000018 00000000 00A21110 00000000 00000000 00000000 0037FFFF 00000000` | `ADH-RC4-MD5` / `77F018` |
| `765268` | `00000001 0077F000 03000019 00000000 00940510 00000000 00000205 00000000 0037FFFF 00000000` | `EXP-ADH-DES-CBC-SHA` / `77F000` |
| `765290` | `00000001 0077EFF0 0300001A 00000000 00A40510 00000000 00000000 00000000 0037FFFF 00000000` | `ADH-DES-CBC-SHA` / `77EFF0` |
| `7652B8` | `00000001 0077EFD8 0300001B 00000000 00A40910 00000000 00000000 00000000 0037FFFF 00000000` | `ADH-DES-CBC3-SHA` / `77EFD8` |
| `7652E0` | `00000001 0077EFC8 03000003 00000000 00921021 00000000 00000205 00000000 0037FFFF 00000000` | `EXP-RC4-MD5` / `77EFC8` |
| `765308` | `00000001 0077EFC0 03000004 00000000 02A21021 00000000 00000000 00000000 0037FFFF 00000000` | `RC4-MD5` / `77EFC0` |
| `765330` | `00000001 0077EFB8 03000005 00000000 02A41021 00000000 00000000 00000000 0037FFFF 00000000` | `RC4-SHA` / `77EFB8` |
| `765358` | `00000001 0077EFA8 03000006 00000000 00922021 00000000 00000205 00000000 0037FFFF 00000000` | `EXP-RC2-CBC-MD5` / `77EFA8` |
| `765380` | `00000001 0077EF98 03000007 00000000 02A44021 00000000 00000000 00000000 0037FFFF 00000000` | `IDEA-CBC-SHA` / `77EF98` |
| `7653A8` | `00000001 0077EF88 03000008 00000000 00940421 00000000 00000205 00000000 0037FFFF 00000000` | `EXP-DES-CBC-SHA` / `77EF88` |
| `7653D0` | `00000001 0077EF78 03000009 00000000 01A40421 00000000 00000000 00000000 0037FFFF 00000000` | `DES-CBC-SHA` / `77EF78` |
| `7653F8` | `00000001 0077EF68 0300000A 00000000 04A40821 00000000 00000000 00000000 0037FFFF 00000000` | `DES-CBC3-SHA` / `77EF68` |
| `765420` | `00000000 0077EF50 0300000B 00000000 00940604 00000000 00000205 00000000 0037FFFF 00000000` | `EXP-DH-DSS-DES-CBC-SHA` / `77EF50` |
| `765448` | `00000000 0077EF38 0300000C 00000000 01A40604 00000000 00000000 00000000 0037FFFF 00000000` | `DH-DSS-DES-CBC-SHA` / `77EF38` |
| `765470` | `00000000 0077EF20 0300000D 00000000 04A40A04 00000000 00000000 00000000 0037FFFF 00000000` | `DH-DSS-DES-CBC3-SHA` / `77EF20` |
| `765498` | `00000000 0077EF08 0300000E 00000000 00940602 00000000 00000205 00000000 0037FFFF 00000000` | `EXP-DH-RSA-DES-CBC-SHA` / `77EF08` |
| `7654C0` | `00000000 0077EEF0 0300000F 00000000 01A40602 00000000 00000000 00000000 0037FFFF 00000000` | `DH-RSA-DES-CBC-SHA` / `77EEF0` |
| `7654E8` | `00000000 0077EED8 03000010 00000000 04A40A02 00000000 00000000 00000000 0037FFFF 00000000` | `DH-RSA-DES-CBC3-SHA` / `77EED8` |
| `765510` | `00000001 0077EEC0 03000011 00000000 00940450 00000000 00000205 00000000 0037FFFF 00000000` | `EXP-EDH-DSS-DES-CBC-SHA` / `77EEC0` |
| `765538` | `00000001 0077EEA8 03000012 00000000 01A40450 00000000 00000000 00000000 0037FFFF 00000000` | `EDH-DSS-DES-CBC-SHA` / `77EEA8` |
| `765560` | `00000001 0077EE90 03000013 00000000 04A40850 00000000 00000000 00000000 0037FFFF 00000000` | `EDH-DSS-DES-CBC3-SHA` / `77EE90` |
| `765588` | `00000001 0077EE78 03000014 00000000 00940430 00000000 00000205 00000000 0037FFFF 00000000` | `EXP-EDH-RSA-DES-CBC-SHA` / `77EE78` |
| `7655B0` | `00000001 0077EE60 03000015 00000000 01A40430 00000000 00000000 00000000 0037FFFF 00000000` | `EDH-RSA-DES-CBC-SHA` / `77EE60` |
| `7655D8` | `00000001 0077EE48 03000016 00000000 04A40830 00000000 00000000 00000000 0037FFFF 00000000` | `EDH-RSA-DES-CBC3-SHA` / `77EE48` |
| `765600` | `00000000 0077EE38 0300001C 00000000 00A50088 00000000 00000000 00000000 0037FFFF 00000000` | `FZA-NULL-SHA` / `77EE38` |
| `765628` | `00000000 0077EE28 0300001D 00000000 00A48088 00000000 00000000 00000000 0037FFFF 00000000` | `FZA-FZA-CBC-SHA` / `77EE28` |
| `765650` | `00000000 0077EE18 0300001E 00000000 00A41088 00000000 00000000 00000000 0037FFFF 00000000` | `FZA-RC4-SHA` / `77EE18` |
| `765678` | `00000001 0077EE08 03000064 00000000 00941021 00000000 00000407 00000000 0037FFFF 00000000` | `EXP-RC4-56-SHA` / `77EE08` |
| `7656A0` | `00000001 0077EDF8 03000062 00000000 00940421 00000000 00000408 00000000 0037FFFF 00000000` | `EXP-DES-56-SHA` / `77EDF8` |
| `7656C8` | `00000001 0077EDE8 03000066 00000000 00841050 00000000 00000000 00000000 0037FFFF 00000000` | `EDH-DSS-RC4-SHA` / `77EDE8` |
| `7656F0` | `00000001 0077EDD0 03000065 00000000 00941050 00000000 00000407 00000000 0037FFFF 00000000` | `EXP-EDH-DSS-RC4-56-SHA` / `77EDD0` |
| `765718` | `00000001 0077EDB8 03000063 00000000 00940450 00000000 00000408 00000000 0037FFFF 00000000` | `EXP-EDH-DSS-DES-56-SHA` / `77EDB8` |

Auxiliary record/data765740..765797,complete22words:

`0071B8D8 0071BC70 0071B770 0071BE40 0071B408 0071BAB0 00000024 0071BA88 544E4C43 00000000 00000000 00000000 00000000 00000004 52565253 00000000 00000000 00000000 00000000 00000004 0071BFA0 00000000`

Base method765798..7657F3,complete23words:

`00000300 0071C160 0071C2E0 0071C220 0071EEF0 0071EEF0 0071CE90 0071CF70 0071CD38 0071CBF0 0071D050 0071D090 0071C478 0071C688 0071C8A8 0071C9B0 0071C140 0071C100 0071C108 0071EF20 0071C0E8 00765740 00000000`

Auxiliaryword18hex=24hex(36decimal) is the expected handshake comparison length used by71A6E0; callback14hex binds71BAB0. Embeddedlittle-endianASCIIwordsat765760/765778spellCLNT/SRVR. These are owned-data/callbackbindings;the specificdigest/ciphercallbacksretainindependentreviewboundaries.
