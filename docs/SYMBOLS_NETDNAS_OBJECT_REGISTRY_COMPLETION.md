# Network DNAS: object-name lookup, dynamic OID creation and complete static tables

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request or live-memory read occurred.

Ten complete clear bodies were independently read, plus every word of all140static object records, all referenced terminated names and encoded payload bytes, and every pointer of the short-name100/long-name127/encoded101 search tables. This closes connected roles in the [name/object registry](SYMBOLS_NETDNAS_NAME_OBJECT_REGISTRY.md), [OID/stream primitive codecs](SYMBOLS_NETDNAS_INTEGER_AND_STREAM_CODEC.md), [text OID encoder](SYMBOLS_NETDNAS_GROUPED_NAME_CODEC.md) and [generic binary search](SYMBOLS_NETDNAS_VERSION_TWO_METHOD.md). Exact original symbols, OID grammar/standards, mutation atomicity, memory admission and thread safety remain partial. No algorithm implementation, live lookup or timing was tested.

Full helper7089B8 and caller708858 establish that6EF378 constructs an owned object-identifier descriptor; its earlier diagnostic-packaging interpretation has been corrected in the owned notebook. Stack flagD means descriptor/name/data ownership bits. This is an evidence correction, not a runtime code change.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x7076C0](../recomp/config/output_ovl/o4/o4_007076C0_0x7076c0.cpp) | `allocate_netdnas_name_registry_type_index_with_optional_callbacks` | Confirmed callback-vector/index/control flow; failure bounds partial | Lazilycreatespointerarrays76351C(hash),763518(compare),763520(destructor). Initialcount763514=5;returnsoldcountandincrementsitbeforegrowth. Extendsthreevectorstoincrementedcountwithdefault10AE78compare/706808hash/NULLdestructor,thenoverwritesrequestednonnullcallbacksoriginala0/a1/a2atreturnedindex. AnyvectorNULLreturns0;appendresultsignored,partialglobalallocations/countchangesnotrolledback. No lockingor callbacksignature/admittedindexdomainproof. |
| [o4 0x708418](../recomp/config/output_ovl/o4/o4_00708418_0x708418.cpp) | `resolve_netdnas_long_object_name_to_numeric_identifier` | Confirmed dynamic/static lookup; complete owned table | Buildsobjectlongname4key,dynamicmap7649F0tag2first;matchedobjectid8returned. Else708560searches127pointers764658with708990longnamecomparator;returnsobjectid8ormissing0. Complete table/name ownership and sorted order checked. NoNULLnameor arbitrarydynamicrecordadmission. |
| [o4 0x7084A0](../recomp/config/output_ovl/o4/o4_007084A0_0x7084a0.cpp) | `resolve_netdnas_short_object_name_to_numeric_identifier` | Confirmed dynamic/static lookup; complete owned table | Buildsobjectshortname0key,dynamicmaptag1first;fallback100pointers7644C8/708968shortnamecompare. Returnsmatchedid8else0. Staticlistfullyread/sorted;case-sensitivebytecomparison,noUnicodeoraliasnormalizationhere. |
| [o4 0x708520](../recomp/config/output_ovl/o4/o4_00708520_0x708520.cpp) | `compare_netdnas_object_pointer_cells_by_encoded_length_then_bytes` | Confirmed comparator/control flow; overflow domain partial | Dereferencesbothobjectpointercells,subtractslengthC32bit;nonzerodifferencereturned,elsememcmp107A18(data10,data10,length). No total-orderguaranteeforoverflowinglengthdifferenceorNULLpayload/negativecount. |
| [o4 0x708638](../recomp/config/output_ovl/o4/o4_00708638_0x708638.cpp) | `register_netdnas_oid_and_optional_names_from_stream_text_lines_candidate` | Confirmed line/token/register flow; input grammar partial | Repeated6F3830(stream,stack512,512);positivecountforcezeroslastreturnedbyte. Firstcharclass&7mustnonzeroelsehalts. Scansnumeric/dotOIDtoken,whitespace-separatedshorttokenandoptionallongremainderinplaceusingresident237769signed-byteclassification;calls708858(oid,short,long). Countincrementspernonnullcreatedid,firsterror/empty/nonalnumlineendsandreturnscount. No skipped-comment/blanklinebehavior,guaranteedNUL/inputboundedcount/high-bitgrammarorline-endingassumption. |
| [o4 0x708858](../recomp/config/output_ovl/o4/o4_00708858_0x708858.cpp) | `create_and_register_netdnas_dynamic_oid_from_text_and_optional_names` | Confirmed measure/encode/construct/register/cleanup flow; grammar partial | Measures6EEC20(NULL,0,text,-1),positiveallocatesencodedbytes,encodesagainwithoutrequiringequalmeasure. Allocatesnumericid707FC8(1),constructsownedobject6EF378(id,encoded,length,short,long),registers707FE0ifnonnull,then6EF2D0temporaryand710A40encodedbuffer. Returnsregisteredidelse0. Failedconstructioncanconsumeid;registeringisnotatomicacrosskeys;no schema/overflow/thread guarantees. |
| [o4 0x708968](../recomp/config/output_ovl/o4/o4_00708968_0x708968.cpp) | `compare_netdnas_object_pointer_cells_by_short_name` | Confirmed comparator/data flow; pointer admission partial | Dereferencesbothcellsandobject0shortname,strcmp10AE78. NoNULLorlocale/casefoldingadmission. |
| [o4 0x708990](../recomp/config/output_ovl/o4/o4_00708990_0x708990.cpp) | `compare_netdnas_object_pointer_cells_by_long_name` | Confirmed comparator/data flow; pointer admission partial | Samepointer-cellrouting,object4longnameandstrcmp10AE78. Complete staticlongnamesbelowareowned;dynamicpointercontractsseparate. |
| [o4 0x7089B8](../recomp/config/output_ovl/o4/o4_007089B8_0x7089b8.cpp) | `copy_owned_netdnas_object_identifier_or_borrow_static_descriptor` | Confirmed ownership/copy/cleanup flow; zero-size/admission partial | NULLreturnsNULL;sourceflags14bit1clearreturnsoriginalpointerwithoutcopy. Ownedsourceallocatesempty6EF268,allocates/copiesencodedlengthC,data10,optionalNULterminatedlong4andshort0,setsnumericid8andflags(sourceflags|D),returnsnewdescriptor. Failure reports(8,65hex,21hex),freesadmittedpartiallong/data/outer. Zero-lengthallocation,sourcepointerlengthconsistencyandarbitraryaliasownershipremainpartial. |
| [o4 0x708B40](../recomp/config/output_ovl/o4/o4_00708B40_0x708b40.cpp) | `compare_netdnas_direct_object_descriptors_by_encoded_length_then_bytes` | Confirmed comparator/data flow; overflow domain partial | Directobjectargumentsratherthanpointercells. SubtractsC32bitthenmemcmp(data10,data10,length)ifequal. NoNULL/negative/overflowtotal-orderguarantee. |

Every static record below has flags0, so7089B8 returns the original static pointer for these records. Static names are labels and aliases, not evidence that any cryptographic implementation was called or correct. Decimal indices remain distinct from hexadecimal stored ids; reserved records may storeid0.

Complete static record interval7637A8..7644C7 SHA-256: **8a16f6cd5d774b7a4172c5cf6ef2a0e993860a06a0698c7738ef49ba9085257a**. Allsixwordsperrowareretained,alongwithindependentlyreadname/payloadbytes.

| Decimal index | Owned record | Six u32 words: short,long,id,length,data,flags | Short label | Long label | Encoded bytes |
| --- | --- | --- | --- | --- | --- |
| 0 | `7637A8` | `0077E3A8 0077E398 00000000 00000001 00763528 00000000` | `UNDEF` | `undefined` | `00` |
| 1 | `7637C0` | `0077E390 0077E390 00000001 00000006 00763529 00000000` | `rsadsi` | `rsadsi` | `2A 86 48 86 F7 0D` |
| 2 | `7637D8` | `0077E388 0077E388 00000002 00000007 0076352F 00000000` | `pkcs` | `pkcs` | `2A 86 48 86 F7 0D 01` |
| 3 | `7637F0` | `0077E380 0077E378 00000003 00000008 00763536 00000000` | `MD2` | `md2` | `2A 86 48 86 F7 0D 02 02` |
| 4 | `763808` | `0077E370 0077E368 00000004 00000008 0076353E 00000000` | `MD5` | `md5` | `2A 86 48 86 F7 0D 02 05` |
| 5 | `763820` | `0077E360 0077E358 00000005 00000008 00763546 00000000` | `RC4` | `rc4` | `2A 86 48 86 F7 0D 03 04` |
| 6 | `763838` | `0077E348 0077E348 00000006 00000009 0076354E 00000000` | `rsaEncryption` | `rsaEncryption` | `2A 86 48 86 F7 0D 01 01 01` |
| 7 | `763850` | `0077E340 0077E328 00000007 00000009 00763557 00000000` | `RSA-MD2` | `md2WithRSAEncryption` | `2A 86 48 86 F7 0D 01 01 02` |
| 8 | `763868` | `0077E320 0077E308 00000008 00000009 00763560 00000000` | `RSA-MD5` | `md5WithRSAEncryption` | `2A 86 48 86 F7 0D 01 01 04` |
| 9 | `763880` | `0077E2F0 0077E2F0 00000009 00000009 00763569 00000000` | `pbeWithMD2AndDES-CBC` | `pbeWithMD2AndDES-CBC` | `2A 86 48 86 F7 0D 01 05 01` |
| 10 | `763898` | `0077E2D8 0077E2D8 0000000A 00000009 00763572 00000000` | `pbeWithMD5AndDES-CBC` | `pbeWithMD5AndDES-CBC` | `2A 86 48 86 F7 0D 01 05 03` |
| 11 | `7638B0` | `0077E2D0 0077E2D0 0000000B 00000001 0076357B 00000000` | `X500` | `X500` | `55` |
| 12 | `7638C8` | `0077E2C8 0077E2C8 0000000C 00000002 0076357C 00000000` | `X509` | `X509` | `55 04` |
| 13 | `7638E0` | `0077E2C0 0077E2B0 0000000D 00000003 0076357E 00000000` | `CN` | `commonName` | `55 04 03` |
| 14 | `7638F8` | `0077E2A8 0077E298 0000000E 00000003 00763581 00000000` | `C` | `countryName` | `55 04 06` |
| 15 | `763910` | `0077E290 0077E280 0000000F 00000003 00763584 00000000` | `L` | `localityName` | `55 04 07` |
| 16 | `763928` | `0077E278 0077E260 00000010 00000003 00763587 00000000` | `ST` | `stateOrProvinceName` | `55 04 08` |
| 17 | `763940` | `0077E258 0077E240 00000011 00000003 0076358A 00000000` | `O` | `organizationName` | `55 04 0A` |
| 18 | `763958` | `0077E238 0077E220 00000012 00000003 0076358D 00000000` | `OU` | `organizationalUnitName` | `55 04 0B` |
| 19 | `763970` | `0077E218 0077E210 00000013 00000004 00763590 00000000` | `RSA` | `rsa` | `55 08 01 01` |
| 20 | `763988` | `0077E208 0077E208 00000014 00000008 00763594 00000000` | `pkcs7` | `pkcs7` | `2A 86 48 86 F7 0D 01 07` |
| 21 | `7639A0` | `0077E1F8 0077E1F8 00000015 00000009 0076359C 00000000` | `pkcs7-data` | `pkcs7-data` | `2A 86 48 86 F7 0D 01 07 01` |
| 22 | `7639B8` | `0077E1E0 0077E1E0 00000016 00000009 007635A5 00000000` | `pkcs7-signedData` | `pkcs7-signedData` | `2A 86 48 86 F7 0D 01 07 02` |
| 23 | `7639D0` | `0077E1C8 0077E1C8 00000017 00000009 007635AE 00000000` | `pkcs7-envelopedData` | `pkcs7-envelopedData` | `2A 86 48 86 F7 0D 01 07 03` |
| 24 | `7639E8` | `0077E1A8 0077E1A8 00000018 00000009 007635B7 00000000` | `pkcs7-signedAndEnvelopedData` | `pkcs7-signedAndEnvelopedData` | `2A 86 48 86 F7 0D 01 07 04` |
| 25 | `763A00` | `0077E190 0077E190 00000019 00000009 007635C0 00000000` | `pkcs7-digestData` | `pkcs7-digestData` | `2A 86 48 86 F7 0D 01 07 05` |
| 26 | `763A18` | `0077E178 0077E178 0000001A 00000009 007635C9 00000000` | `pkcs7-encryptedData` | `pkcs7-encryptedData` | `2A 86 48 86 F7 0D 01 07 06` |
| 27 | `763A30` | `0077E170 0077E170 0000001B 00000008 007635D2 00000000` | `pkcs3` | `pkcs3` | `2A 86 48 86 F7 0D 01 03` |
| 28 | `763A48` | `0077E160 0077E160 0000001C 00000009 007635DA 00000000` | `dhKeyAgreement` | `dhKeyAgreement` | `2A 86 48 86 F7 0D 01 03 01` |
| 29 | `763A60` | `0077E158 0077E150 0000001D 00000005 007635E3 00000000` | `DES-ECB` | `des-ecb` | `2B 0E 03 02 06` |
| 30 | `763A78` | `0077E148 0077E140 0000001E 00000005 007635E8 00000000` | `DES-CFB` | `des-cfb` | `2B 0E 03 02 09` |
| 31 | `763A90` | `0077E138 0077E130 0000001F 00000005 007635ED 00000000` | `DES-CBC` | `des-cbc` | `2B 0E 03 02 07` |
| 32 | `763AA8` | `0077E128 0077E120 00000020 00000005 007635F2 00000000` | `DES-EDE` | `des-ede` | `2B 0E 03 02 11` |
| 33 | `763AC0` | `0077E110 0077E100 00000021 00000000 00000000 00000000` | `DES-EDE3` | `des-ede3` | `empty` |
| 34 | `763AD8` | `0077E0F0 0077E0E0 00000022 00000000 00000000 00000000` | `IDEA-CBC` | `idea-cbc` | `empty` |
| 35 | `763AF0` | `0077E0D0 0077E0C0 00000023 00000000 00000000 00000000` | `IDEA-CFB` | `idea-cfb` | `empty` |
| 36 | `763B08` | `0077E0B0 0077E0A0 00000024 00000000 00000000 00000000` | `IDEA-ECB` | `idea-ecb` | `empty` |
| 37 | `763B20` | `0077E098 0077E090 00000025 00000008 007635F7 00000000` | `RC2-CBC` | `rc2-cbc` | `2A 86 48 86 F7 0D 03 02` |
| 38 | `763B38` | `0077E088 0077E080 00000026 00000000 00000000 00000000` | `RC2-ECB` | `rc2-ecb` | `empty` |
| 39 | `763B50` | `0077E078 0077E070 00000027 00000000 00000000 00000000` | `RC2-CFB` | `rc2-cfb` | `empty` |
| 40 | `763B68` | `0077E068 0077E060 00000028 00000000 00000000 00000000` | `RC2-OFB` | `rc2-ofb` | `empty` |
| 41 | `763B80` | `0077E058 0077E050 00000029 00000005 007635FF 00000000` | `SHA` | `sha` | `2B 0E 03 02 12` |
| 42 | `763B98` | `0077E048 0077E030 0000002A 00000005 00763604 00000000` | `RSA-SHA` | `shaWithRSAEncryption` | `2B 0E 03 02 0F` |
| 43 | `763BB0` | `0077E020 0077E010 0000002B 00000000 00000000 00000000` | `DES-EDE-CBC` | `des-ede-cbc` | `empty` |
| 44 | `763BC8` | `0077E000 0077DFF0 0000002C 00000008 00763609 00000000` | `DES-EDE3-CBC` | `des-ede3-cbc` | `2A 86 48 86 F7 0D 03 07` |
| 45 | `763BE0` | `0077DFE8 0077DFE0 0000002D 00000005 00763611 00000000` | `DES-OFB` | `des-ofb` | `2B 0E 03 02 08` |
| 46 | `763BF8` | `0077DFD0 0077DFC0 0000002E 00000000 00000000 00000000` | `IDEA-OFB` | `idea-ofb` | `empty` |
| 47 | `763C10` | `0077DFB8 0077DFB8 0000002F 00000008 00763616 00000000` | `pkcs9` | `pkcs9` | `2A 86 48 86 F7 0D 01 09` |
| 48 | `763C28` | `0077DFB0 0077DFA0 00000030 00000009 0076361E 00000000` | `Email` | `emailAddress` | `2A 86 48 86 F7 0D 01 09 01` |
| 49 | `763C40` | `0077DF88 0077DF88 00000031 00000009 00763627 00000000` | `unstructuredName` | `unstructuredName` | `2A 86 48 86 F7 0D 01 09 02` |
| 50 | `763C58` | `0077DF78 0077DF78 00000032 00000009 00763630 00000000` | `contentType` | `contentType` | `2A 86 48 86 F7 0D 01 09 03` |
| 51 | `763C70` | `0077DF68 0077DF68 00000033 00000009 00763639 00000000` | `messageDigest` | `messageDigest` | `2A 86 48 86 F7 0D 01 09 04` |
| 52 | `763C88` | `0077DF58 0077DF58 00000034 00000009 00763642 00000000` | `signingTime` | `signingTime` | `2A 86 48 86 F7 0D 01 09 05` |
| 53 | `763CA0` | `0077DF40 0077DF40 00000035 00000009 0076364B 00000000` | `countersignature` | `countersignature` | `2A 86 48 86 F7 0D 01 09 06` |
| 54 | `763CB8` | `0077DF28 0077DF28 00000036 00000009 00763654 00000000` | `challengePassword` | `challengePassword` | `2A 86 48 86 F7 0D 01 09 07` |
| 55 | `763CD0` | `0077DF10 0077DF10 00000037 00000009 0076365D 00000000` | `unstructuredAddress` | `unstructuredAddress` | `2A 86 48 86 F7 0D 01 09 08` |
| 56 | `763CE8` | `0077DEF0 0077DEF0 00000038 00000009 00763666 00000000` | `extendedCertificateAttributes` | `extendedCertificateAttributes` | `2A 86 48 86 F7 0D 01 09 09` |
| 57 | `763D00` | `0077DEE0 0077DEC0 00000039 00000007 0076366F 00000000` | `Netscape` | `Netscape Communications Corp.` | `60 86 48 01 86 F8 42` |
| 58 | `763D18` | `0077DEB0 0077DE90 0000003A 00000008 00763676 00000000` | `nsCertExt` | `Netscape Certificate Extension` | `60 86 48 01 86 F8 42 01` |
| 59 | `763D30` | `0077DE80 0077DE68 0000003B 00000008 0076367E 00000000` | `nsDataType` | `Netscape Data Type` | `60 86 48 01 86 F8 42 02` |
| 60 | `763D48` | `0077DE58 0077DE48 0000003C 00000000 00000000 00000000` | `DES-EDE-CFB` | `des-ede-cfb` | `empty` |
| 61 | `763D60` | `0077DE38 0077DE28 0000003D 00000000 00000000 00000000` | `DES-EDE3-CFB` | `des-ede3-cfb` | `empty` |
| 62 | `763D78` | `0077DE18 0077DE08 0000003E 00000000 00000000 00000000` | `DES-EDE-OFB` | `des-ede-ofb` | `empty` |
| 63 | `763D90` | `0077DDF8 0077DDE8 0000003F 00000000 00000000 00000000` | `DES-EDE3-OFB` | `des-ede3-ofb` | `empty` |
| 64 | `763DA8` | `0077DDE0 0077DDD8 00000040 00000005 00763686 00000000` | `SHA1` | `sha1` | `2B 0E 03 02 1A` |
| 65 | `763DC0` | `0077DDC8 0077DDB0 00000041 00000009 0076368B 00000000` | `RSA-SHA1` | `sha1WithRSAEncryption` | `2A 86 48 86 F7 0D 01 01 05` |
| 66 | `763DD8` | `0077DDA8 0077DD98 00000042 00000005 00763694 00000000` | `DSA-SHA` | `dsaWithSHA` | `2B 0E 03 02 0D` |
| 67 | `763DF0` | `0077DD90 0077DD78 00000043 00000005 00763699 00000000` | `DSA-old` | `dsaEncryption-old` | `2B 0E 03 02 0C` |
| 68 | `763E08` | `0077DD60 0077DD60 00000044 00000009 0076369E 00000000` | `pbeWithSHA1AndRC2-CBC` | `pbeWithSHA1AndRC2-CBC` | `2A 86 48 86 F7 0D 01 05 0B` |
| 69 | `763E20` | `0077DD48 0077DD48 00000045 00000009 007636A7 00000000` | `pbeWithSHA1AndRC4` | `pbeWithSHA1AndRC4` | `2A 86 48 86 F7 0D 01 05 0C` |
| 70 | `763E38` | `0077DD38 0077DD28 00000046 00000005 007636B0 00000000` | `DSA-SHA1-old` | `dsaWithSHA1-old` | `2B 0E 03 02 1B` |
| 71 | `763E50` | `0077DD18 0077DD00 00000047 00000009 007636B5 00000000` | `nsCertType` | `Netscape Cert Type` | `60 86 48 01 86 F8 42 01 01` |
| 72 | `763E68` | `0077DCF0 0077DCD8 00000048 00000009 007636BE 00000000` | `nsBaseUrl` | `Netscape Base Url` | `60 86 48 01 86 F8 42 01 02` |
| 73 | `763E80` | `0077DCC8 0077DCB0 00000049 00000009 007636C7 00000000` | `nsRevocationUrl` | `Netscape Revocation Url` | `60 86 48 01 86 F8 42 01 03` |
| 74 | `763E98` | `0077DC98 0077DC78 0000004A 00000009 007636D0 00000000` | `nsCaRevocationUrl` | `Netscape CA Revocation Url` | `60 86 48 01 86 F8 42 01 04` |
| 75 | `763EB0` | `0077DC68 0077DC50 0000004B 00000009 007636D9 00000000` | `nsRenewalUrl` | `Netscape Renewal Url` | `60 86 48 01 86 F8 42 01 07` |
| 76 | `763EC8` | `0077DC40 0077DC28 0000004C 00000009 007636E2 00000000` | `nsCaPolicyUrl` | `Netscape CA Policy Url` | `60 86 48 01 86 F8 42 01 08` |
| 77 | `763EE0` | `0077DC18 0077DBF8 0000004D 00000009 007636EB 00000000` | `nsSslServerName` | `Netscape SSL Server Name` | `60 86 48 01 86 F8 42 01 0C` |
| 78 | `763EF8` | `0077DBE8 0077DBD0 0000004E 00000009 007636F4 00000000` | `nsComment` | `Netscape Comment` | `60 86 48 01 86 F8 42 01 0D` |
| 79 | `763F10` | `0077DBC0 0077DBA0 0000004F 00000009 007636FD 00000000` | `nsCertSequence` | `Netscape Certificate Sequence` | `60 86 48 01 86 F8 42 02 05` |
| 80 | `763F28` | `0077DB90 0077DB80 00000050 00000000 00000000 00000000` | `DESX-CBC` | `desx-cbc` | `empty` |
| 81 | `763F40` | `0077DB78 0077DB78 00000051 00000002 00763706 00000000` | `ld-ce` | `ld-ce` | `55 1D` |
| 82 | `763F58` | `0077DB60 0077DB40 00000052 00000003 00763708 00000000` | `subjectKeyIdentifier` | `X509v3 Subject Key Identifier` | `55 1D 0E` |
| 83 | `763F70` | `0077DB30 0077DB18 00000053 00000003 0076370B 00000000` | `keyUsage` | `X509v3 Key Usage` | `55 1D 0F` |
| 84 | `763F88` | `0077DB00 0077DAE0 00000054 00000003 0076370E 00000000` | `privateKeyUsagePeriod` | `X509v3 Private Key Usage Period` | `55 1D 10` |
| 85 | `763FA0` | `0077DAD0 0077DAB0 00000055 00000003 00763711 00000000` | `subjectAltName` | `X509v3 Subject Alternative Name` | `55 1D 11` |
| 86 | `763FB8` | `0077DAA0 0077DA80 00000056 00000003 00763714 00000000` | `issuerAltName` | `X509v3 Issuer Alternative Name` | `55 1D 12` |
| 87 | `763FD0` | `0077DA68 0077DA48 00000057 00000003 00763717 00000000` | `basicConstraints` | `X509v3 Basic Constraints` | `55 1D 13` |
| 88 | `763FE8` | `0077DA38 0077DA20 00000058 00000003 0076371A 00000000` | `crlNumber` | `X509v3 CRL Number` | `55 1D 14` |
| 89 | `764000` | `0077DA08 0077D9E8 00000059 00000003 0076371D 00000000` | `certificatePolicies` | `X509v3 Certificate Policies` | `55 1D 20` |
| 90 | `764018` | `0077D9D0 0077D9B0 0000005A 00000003 00763720 00000000` | `authorityKeyIdentifier` | `X509v3 Authority Key Identifier` | `55 1D 23` |
| 91 | `764030` | `0077D9A8 0077D9A0 0000005B 00000000 00000000 00000000` | `BF-CBC` | `bf-cbc` | `empty` |
| 92 | `764048` | `0077D998 0077D990 0000005C 00000000 00000000 00000000` | `BF-ECB` | `bf-ecb` | `empty` |
| 93 | `764060` | `0077D988 0077D980 0000005D 00000000 00000000 00000000` | `BF-CFB` | `bf-cfb` | `empty` |
| 94 | `764078` | `0077D978 0077D970 0000005E 00000000 00000000 00000000` | `BF-OFB` | `bf-ofb` | `empty` |
| 95 | `764090` | `0077D968 0077D960 0000005F 00000004 00763723 00000000` | `MDC2` | `mdc2` | `55 08 03 65` |
| 96 | `7640A8` | `0077D950 0077D940 00000060 00000004 00763727 00000000` | `RSA-MDC2` | `mdc2withRSA` | `55 08 03 64` |
| 97 | `7640C0` | `0077D938 0077D930 00000061 00000000 00000000 00000000` | `RC4-40` | `rc4-40` | `empty` |
| 98 | `7640D8` | `0077D920 0077D910 00000062 00000000 00000000 00000000` | `RC2-40-CBC` | `rc2-40-cbc` | `empty` |
| 99 | `7640F0` | `0077D908 0077D8F8 00000063 00000003 0076372B 00000000` | `G` | `givenName` | `55 04 2A` |
| 100 | `764108` | `0077D8F0 0077D8E8 00000064 00000003 0076372E 00000000` | `S` | `surname` | `55 04 04` |
| 101 | `764120` | `0077D8E0 0077D8D0 00000065 00000003 00763731 00000000` | `I` | `initials` | `55 04 2B` |
| 102 | `764138` | `0077D8C8 0077D8B0 00000066 00000003 00763734 00000000` | `UID` | `uniqueIdentifier` | `55 04 2D` |
| 103 | `764150` | `0077D898 0077D878 00000067 00000003 00763737 00000000` | `crlDistributionPoints` | `X509v3 CRL Distribution Points` | `55 1D 1F` |
| 104 | `764168` | `0077D868 0077D858 00000068 00000005 0076373A 00000000` | `RSA-NP-MD5` | `md5WithRSA` | `2B 0E 03 02 03` |
| 105 | `764180` | `0077D850 0077D840 00000069 00000003 0076373F 00000000` | `SN` | `serialNumber` | `55 04 05` |
| 106 | `764198` | `0077D838 0077D830 0000006A 00000003 00763742 00000000` | `T` | `title` | `55 04 0C` |
| 107 | `7641B0` | `0077D828 0077D818 0000006B 00000003 00763745 00000000` | `D` | `description` | `55 04 0D` |
| 108 | `7641C8` | `0077D808 0077D7F8 0000006C 00000009 00763748 00000000` | `CAST5-CBC` | `cast5-cbc` | `2A 86 48 86 F6 7D 07 42 0A` |
| 109 | `7641E0` | `0077D7E8 0077D7D8 0000006D 00000000 00000000 00000000` | `CAST5-ECB` | `cast5-ecb` | `empty` |
| 110 | `7641F8` | `0077D7C8 0077D7B8 0000006E 00000000 00000000 00000000` | `CAST5-CFB` | `cast5-cfb` | `empty` |
| 111 | `764210` | `0077D7A8 0077D798 0000006F 00000000 00000000 00000000` | `CAST5-OFB` | `cast5-ofb` | `empty` |
| 112 | `764228` | `0077D780 0077D780 00000070 00000009 00763751 00000000` | `pbeWithMD5AndCast5CBC` | `pbeWithMD5AndCast5CBC` | `2A 86 48 86 F6 7D 07 42 0C` |
| 113 | `764240` | `0077D770 0077D760 00000071 00000007 0076375A 00000000` | `DSA-SHA1` | `dsaWithSHA1` | `2A 86 48 CE 38 04 03` |
| 114 | `764258` | `0077D750 0077D740 00000072 00000000 00000000 00000000` | `MD5-SHA1` | `md5-sha1` | `empty` |
| 115 | `764270` | `0077D730 0077D720 00000073 00000005 00763761 00000000` | `RSA-SHA1-2` | `sha1WithRSA` | `2B 0E 03 02 1D` |
| 116 | `764288` | `0077D718 0077D708 00000074 00000007 00763766 00000000` | `DSA` | `dsaEncryption` | `2A 86 48 CE 38 04 01` |
| 117 | `7642A0` | `0077D6F8 0077D6E8 00000075 00000005 0076376D 00000000` | `RIPEMD160` | `ripemd160` | `2B 24 03 02 01` |
| 118 | `7642B8` | `00000000 00000000 00000000 00000000 00000000 00000000` | `NULL` | `NULL` | `empty` |
| 119 | `7642D0` | `0077D6D8 0077D6C0 00000077 00000006 00763772 00000000` | `RSA-RIPEMD160` | `ripemd160WithRSA` | `2B 24 03 03 01 02` |
| 120 | `7642E8` | `0077D6B8 0077D6B0 00000078 00000008 00763778 00000000` | `RC5-CBC` | `rc5-cbc` | `2A 86 48 86 F7 0D 03 08` |
| 121 | `764300` | `0077D6A8 0077D6A0 00000079 00000000 00000000 00000000` | `RC5-ECB` | `rc5-ecb` | `empty` |
| 122 | `764318` | `0077D698 0077D690 0000007A 00000000 00000000 00000000` | `RC5-CFB` | `rc5-cfb` | `empty` |
| 123 | `764330` | `0077D688 0077D680 0000007B 00000000 00000000 00000000` | `RC5-OFB` | `rc5-ofb` | `empty` |
| 124 | `764348` | `0077D678 0077D660 0000007C 00000005 00763780 00000000` | `RLE` | `run length compression` | `29 01 01 85 1A` |
| 125 | `764360` | `0077D658 0077D640 0000007D 00000005 00763785 00000000` | `ZLIB` | `zlib compression` | `29 01 01 85 1A` |
| 126 | `764378` | `0077D628 0077D608 0000007E 00000003 0076378A 00000000` | `extendedKeyUsage` | `X509v3 Extended Key Usage` | `55 1D 25` |
| 127 | `764390` | `00000000 00000000 00000000 00000000 00000000 00000000` | `NULL` | `NULL` | `empty` |
| 128 | `7643A8` | `00000000 00000000 00000000 00000000 00000000 00000000` | `NULL` | `NULL` | `empty` |
| 129 | `7643C0` | `00000000 00000000 00000000 00000000 00000000 00000000` | `NULL` | `NULL` | `empty` |
| 130 | `7643D8` | `00000000 00000000 00000000 00000000 00000000 00000000` | `NULL` | `NULL` | `empty` |
| 131 | `7643F0` | `00000000 00000000 00000000 00000000 00000000 00000000` | `NULL` | `NULL` | `empty` |
| 132 | `764408` | `00000000 00000000 00000000 00000000 00000000 00000000` | `NULL` | `NULL` | `empty` |
| 133 | `764420` | `00000000 00000000 00000000 00000000 00000000 00000000` | `NULL` | `NULL` | `empty` |
| 134 | `764438` | `00000000 00000000 00000000 00000000 00000000 00000000` | `NULL` | `NULL` | `empty` |
| 135 | `764450` | `00000000 00000000 00000000 00000000 00000000 00000000` | `NULL` | `NULL` | `empty` |
| 136 | `764468` | `00000000 00000000 00000000 00000000 00000000 00000000` | `NULL` | `NULL` | `empty` |
| 137 | `764480` | `0077D600 0077D5E0 00000089 0000000A 0076378D 00000000` | `msSGC` | `Microsoft Server Gated Crypto` | `2B 06 01 04 01 82 37 0A 03 03` |
| 138 | `764498` | `00000000 00000000 00000000 00000000 00000000 00000000` | `NULL` | `NULL` | `empty` |
| 139 | `7644B0` | `0077D5D8 0077D5B8 0000008B 00000009 00763797 00000000` | `nsSGC` | `Netscape Server Gated Crypto` | `60 86 48 01 86 F8 42 04 01` |

Allthreeownedsearchpointertableswereindependentlyread. Eachpointeris24bytealignedwithin7637A8..7644C7. ShortandlongtablesaremonotonicallysortedbytheownedunsignedASCIIlabels;encodedtablebysigned-positiveadmittedlengththenbytes. Theordereddecimalrecordindicesbelowpreserveeverypointerwithoutclaiminganotherfunctionrole.

short table `7644C8` / 100 pointers / SHA-256 **50e1d38f711d34c4323c275a1903030cbcf5f6b39b25acb8c1f0d053ce176763**:

`91 93 92 94 14 108 110 109 111 13 107 31 30 29 32 43 60 62 33 44 61 63 45 80 116 66 113 70 67 48 99 101 34 35 36 46 15 3 4 114 95 57 17 18 98 37 39 38 40 5 97 120 122 121 123 117 124 19 7 8 96 104 119 42 65 115 100 41 64 105 16 106 102 0 125 90 87 89 103 88 126 86 83 81 137 72 76 74 58 79 71 78 59 75 73 139 77 84 85 82`

long table `764658` / 127 pointers / SHA-256 **1567e5bff0e11027639d639818f319df44e64a2c150b2d99436f6955fa04fc01**:

`137 72 76 74 71 58 79 78 57 59 75 73 77 139 11 12 90 87 103 88 89 126 86 83 84 85 82 91 93 92 94 108 110 109 111 54 13 50 53 14 31 30 29 32 43 60 62 33 44 61 63 45 107 80 28 116 67 66 113 70 48 56 99 34 35 36 46 101 15 3 7 4 114 104 8 95 96 51 17 18 9 112 10 68 69 2 27 20 21 25 26 23 24 22 47 98 37 39 38 40 5 97 120 122 121 123 117 119 19 6 1 124 105 41 64 115 65 42 52 16 100 106 0 102 55 49 125`

encoded table `764858` / 101 pointers / SHA-256 **801a5334a379e8068046d4a28ef252ea4893d02e8ca1c190277b5beb0021795e**:

`0 11 12 81 13 100 105 14 15 16 17 18 106 107 99 101 102 82 83 84 85 86 87 88 103 89 90 126 19 96 95 124 125 104 29 31 45 30 67 66 42 32 41 64 70 115 117 1 119 2 116 113 57 27 20 47 3 4 37 5 44 120 58 59 108 112 6 7 8 65 28 9 10 68 69 21 22 23 24 25 26 48 49 50 51 52 53 54 55 56 71 72 73 74 75 76 77 78 79 139 137`

Thetext-loaderASCIIclassificationbytes237769..2377E8wereindependentlyreadfromoriginalmainELF(SHA-25606bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46). Masks1/2classifyASCIIupper/lowerletters,4digits,8whitespace. Thefullsigned-byteindexwindow2376E9..2377E8hashes **d1b7cfe6e9c03d00302bfcf5949e510a4560f39a09ec78eff80401b1cbb15a85**. Negativeindicesreachprecedingowneddata,includingunrelatedtext;high-bitinputisnotprovedadmittedASCIIoraconformingctypeextension. Noextra residentfunctionroleisclaimed.
