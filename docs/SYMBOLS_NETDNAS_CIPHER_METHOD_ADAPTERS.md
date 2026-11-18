# Network DNAS: numeric cipher methods, key/vector setup and copy adapter

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request, live-memory read or target cipher operation occurred.

Thirteen complete clear bodies were independently read, including optionalkey/vectorpaths, exactcopyextent,tailarguments and alias branchdelay. Complete nine methoddescriptors below connect [context layouts/accessors](SYMBOLS_NETDNAS_CIPHER_CONTEXT.md), [owned numeric-name registry](SYMBOLS_NETDNAS_OBJECT_REGISTRY_COMPLETION.md), and [DES-shaped key schedule](SYMBOLS_NETDNAS_DES_KEY_SETUP.md). Numeric-name identity supports family labels; unreviewed7015C0/711458/715C10/715E78 retain separate primitive/mode limits. Existing exact-body aliases for adjacent getters/simpleadapters are not duplicated. No originalsymbol,standard/vector/securityproof or gameplaytimingcause isclaimed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x702B48](../recomp/config/output_ovl/o4/o4_00702B48_0x702b48.cpp) | `get_des_ede_cbc_numeric_cipher_method` | Confirmed complete local method/argument/data flow; cipher correctness partial | Returns762CE0,ownedmethodid2Bhex/nameDES-EDE-CBC fromindependentobjectregistry. Getteronly; nooperation. |
| [o4 0x702B68](../recomp/config/output_ovl/o4/o4_00702B68_0x702b68.cpp) | `initialize_two_des_keys_and_copy_first_schedule_for_ede_workspace` | Confirmed complete local method/argument/data flow; cipher correctness partial | OptionalIVa2copies8bytes tocontextC;alwayscopiesC->2C. Ifkeya1nonnull,724BA8(key,private78),724BA8(key+8,private+180hex),then copies180hexbytes firstworkspace->+300hex via twelve32byteiterations. Schedulebuilderwrites100hexbytes,so copiedspanincludes80hexworkspacepadding; contents notinferred. Setupstatusesignored;NULLkey skipskeywork withunnormalizedreturn. |
| [o4 0x702C20](../recomp/config/output_ovl/o4/o4_00702C20_0x702c20.cpp) | `initialize_three_des_keys_and_current_vector` | Confirmed complete local method/argument/data flow; cipher correctness partial | Same independently readoptionalIV/C->2Csetup; nonNULLkeycalls724BA8 onoffset0/8/10hex into private0/180/300hex. Tailreturnlastsetup; precedingstatusesignored. No key/vectorcapacityorvalidityproof. |
| [o4 0x702CA8](../recomp/config/output_ovl/o4/o4_00702CA8_0x702ca8.cpp) | `adapt_three_schedule_des_ede_cbc_buffer_operation` | Confirmed complete local method/argument/data flow; cipher correctness partial | Tail7015C0(originala2 input,originala1 output,zeroextendedlow32originala3length,private78,private+180,+300,context2C,directioncontext4). Lowerblockmodebody remainsseparatereview; no callbacksuccessorlengthadmissionclaim. |
| [o4 0x702D50](../recomp/config/output_ovl/o4/o4_00702D50_0x702d50.cpp) | `get_numeric_rc2_40_cbc_method_with_eight_byte_key_length_field` | Confirmed complete local method/argument/data flow; cipher correctness partial | Returns762DA0: id62hex/nameRC2-40-CBC,methodkeylength8. Nameidentitynotanassertionthateffectivebits40isenforcedbythisgetter. |
| [o4 0x702D60](../recomp/config/output_ovl/o4/o4_00702D60_0x702d60.cpp) | `get_numeric_rc2_40_cbc_method_with_five_byte_key_length_field` | Confirmed complete local method/argument/data flow; cipher correctness partial | Returns762DD0,independently sameid62hex/namebutkeylength5. Distinctdescriptor/callerkept;no inferredaliasoralgorithmfix. |
| [o4 0x702D70](../recomp/config/output_ovl/o4/o4_00702D70_0x702d70.cpp) | `initialize_rc2_family_key_workspace_using_optional_effective_bits_value` | Confirmed complete local method/argument/data flow; cipher correctness partial | OptionalIV8bytes->C;alwaysC->2C. NonNULLkeyqueries704B80 applicationu64;zero substitutes704B58 keybytes*8. Thenquerieskeybytesagain,tails715C10(private78,keybytes,key,signedlow32effectivevalue). Returnunmodified; no localbitrange,keycapacityorfullRC2proof. |
| [o4 0x702E38](../recomp/config/output_ovl/o4/o4_00702E38_0x702e38.cpp) | `adapt_rc2_family_cbc_buffer_operation` | Confirmed complete local method/argument/data flow; cipher correctness partial | Tail711458(originala2 input,originala1 output,zeroextendedlow32originala3length,private78,context2C,directioncontext4). Lowermode/primitivebodyunreviewedhere; no capacity/statusnormalization. |
| [o4 0x702E58](../recomp/config/output_ovl/o4/o4_00702E58_0x702e58.cpp) | `get_null_copy_cipher_method` | Confirmed complete local method/argument/data flow; cipher correctness partial | Returns762E00:id0,blockwidth1,keysize0,vector0,init702E68,operation702E78,privatesize0. Identityfromcompleteownedtable; no cryptographictransformation. |
| [o4 0x702E68](../recomp/config/output_ovl/o4/o4_00702E68_0x702e68.cpp) | `clear_null_cipher_private_size_and_pointer_without_release` | Confirmed complete local method/argument/data flow; cipher correctness partial | Storeszero context74/78,leavesotherfields. No free/wipe or normalizedreturn; usednullmethodinitializer. |
| [o4 0x702E78](../recomp/config/output_ovl/o4/o4_00702E78_0x702e78.cpp) | `copy_null_cipher_input_to_output_unless_exact_alias` | Confirmed complete local method/argument/data flow; cipher correctness partial | Ignorescontexta0; comparesoriginala1destinationtooriginala2source. Differenttail107AB0(destination,source,originala3count),samepointerreturnwithoutcopy. No capacity/negativecount/partialoverlapcheck; returnnotnormalized. |
| [o4 0x702E98](../recomp/config/output_ovl/o4/o4_00702E98_0x702e98.cpp) | `cache_raw_stream_key_and_initialize_state_after_key_prefix` | Confirmed complete local method/argument/data flow; cipher correctness partial | Private78; optionalnonNULLkeycopiedfor704B58 keylengthintoprivatebase. Alwaysquerieskeylengththen715E78(private+10hex,keylength,privatebase). RC4familyidentityfromownedmethodids5/61hex; lowerkeypermutationunreviewedhere. Overridekeylength>prefixsize isnotlocallyrejected; no fullvalidity/securityclaim. |
| [o4 0x702F38](../recomp/config/output_ovl/o4/o4_00702F38_0x702f38.cpp) | `get_rc4_40_five_byte_key_method` | Confirmed complete local method/argument/data flow; cipher correctness partial | Returns762E60:id61hex/nameRC4-40,keylength5,initializer702E98,operation702F08(existingexactbodyannotation),workspace418hex. No enforcementofkeyentropy/currentruntimealgorithmchoice. |

## Complete owned method descriptors

Eachdescriptor is30hexbytes/twelvelittle-endianwords. Observedfields: id0,blockwidth4,keybytes8,vectorbytesC,initializer10,operation14,optional18,privatesize1C; finalfourwords retainedliterally. Repeatednumericidsarenotcollapsed; allninefullintervalsread.

762CE0..762D10,SHA-256 `adbdf7a28b9fb60920607470112c27c0469ee9d5adf426be7af6d520e107d102`:

```text
0000002B 00000008 00000010 00000008 00702B68 00702CA8 00000000 00000480 00000000 00000000 00000000 00000000
```

762D10..762D40,SHA-256 `63274dd5f748ba4d2c96b4502aaaf078bacb15d322dd731ef60c3488947e6e85`:

```text
0000002C 00000008 00000018 00000008 00702C20 00702CA8 00000000 00000480 00000000 00000000 00000000 00000000
```

762D40..762D70,SHA-256 `c006feaf1cfb6cdc7ed5593117b7012b43e02302ae28f85a1e83c74278995e8a`:

```text
0000001F 00000008 00000008 00000008 00702CE0 00702D20 00000000 00000180 00000000 00000000 00000000 00000000
```

762D70..762DA0,SHA-256 `1839b587d1984e8255df482a99a8645e1211dc71544462dc62f4950b8c20c16f`:

```text
00000025 00000008 00000010 00000008 00702D70 00702E38 00000000 00000080 00000000 00000000 00000000 00000000
```

762DA0..762DD0,SHA-256 `c504ed8eae67a0a11ea2540d6a7e124105f98985abd16bdc3d8936ad10282575`:

```text
00000062 00000008 00000008 00000008 00702D70 00702E38 00000000 00000080 00000000 00000000 00000000 00000000
```

762DD0..762E00,SHA-256 `45a682dbd33228b631d8782efc91032ca39bf47bed46f60e58b9e1426f48eff8`:

```text
00000062 00000008 00000005 00000008 00702D70 00702E38 00000000 00000080 00000000 00000000 00000000 00000000
```

762E00..762E30,SHA-256 `56d32c95a7305284f3cff9796b9ae8afe485c3f0f90765ce1d1b08b278eaa4e5`:

```text
00000000 00000001 00000000 00000000 00702E68 00702E78 00000000 00000000 00000000 00000000 00000000 00000000
```

762E30..762E60,SHA-256 `c6dd2870d13f135b467e6a082da275be134ae94d589bdec320b93440311f0db9`:

```text
00000005 00000001 00000010 00000000 00702E98 00702F08 00000000 00000418 00000000 00000000 00000000 00000000
```

762E60..762E90,SHA-256 `1bf2845628662ff84a1ed5b77fa3ce2d3a6b68a6fa575376499f1959d5ec562d`:

```text
00000061 00000001 00000005 00000000 00702E98 00702F08 00000000 00000418 00000000 00000000 00000000 00000000
```

Themethodnames are compiledregistrylabels, not evidenceoflivecipherselection or successfulkeypreparation. Zeroing/reset and borrowedworkspaceadmission remain as observed, withoutanenginechange.
