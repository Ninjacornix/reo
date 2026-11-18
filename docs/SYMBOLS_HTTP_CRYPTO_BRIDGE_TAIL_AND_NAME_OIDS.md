# HTTP overlay callback-bridge tail and selected X.509 name OIDs

Static owned File #1 o6 `nethttp.bin`, runtime ID6/base6E0000, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Six complete catalogue intervals and43-entry table reviewed. No target execution, build, live process or network activity. Numbers hexadecimal except identifiers. Companion [complete callback bridge](SYMBOLS_HTTP_CRYPTO_CALLBACK_BRIDGE.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x6FDD18](../recomp/config/output_ovl/o6/o6_006FDD18_0x6fdd18.cpp) | `invoke_crypto_bridge_key_release_selector_53_or_error` | Confirmed complete callback/error flow | Selector35 global742304; nonnull callback invoked with unchanged arguments/result. Missing callback tail-calls704230(lib1A,function86,reasonE,0,0), no explicit scalar result. Default initializer binds728DA8; ownership internals delegated. |
| [o6 0x6FDD60](../recomp/config/output_ovl/o6/o6_006FDD60_0x6fdd60.cpp) | `invoke_crypto_bridge_selector_51_or_report_missing_callback` | Confirmed complete dispatch | Selector33 global742308; nonnull callback args/result unchanged. Missing logs1A/6B/E and returns0. Default6FF5E0. |
| [o6 0x6FDDA8](../recomp/config/output_ovl/o6/o6_006FDDA8_0x6fdda8.cpp) | `invoke_crypto_bridge_key_decode_selector_54_or_error` | Confirmed complete dispatch | Selector36 global74230C; nonnull args/result unchanged. Missing logs1A/6C/E and returns0. Default6FC568 [key-container adapter](SYMBOLS_HTTP_X509_DESCRIPTOR_AND_VERIFY_ADAPTERS.md). |
| [o6 0x6FDDF0](../recomp/config/output_ovl/o6/o6_006FDDF0_0x6fddf0.cpp) | `invoke_crypto_bridge_key_reference_selector_55_or_error` | Confirmed complete dispatch/error tail | Selector37 global742310; nonnull args/result unchanged. Missing tail-calls704230(lib1A/function88/reasonE/0/0), no explicit scalar return. Default728D60. |
| [o6 0x6FDE38](../recomp/config/output_ovl/o6/o6_006FDE38_0x6fde38.cpp) | `invoke_crypto_bridge_unregistered_tail_callback_or_report_missing` | Confirmed full slot read and setter exclusion | Reads global742314; nonnull invoked with unchanged args/result; missing logs1A/97/E then0. Reset clears this word but NO valid6FC9E8 setter selector targets it; attempted selector38 in initializer is rejected rather than binding this field. Other direct writers/call reachability unresolved. |
| [o6 0x6FDE80](../recomp/config/output_ovl/o6/o6_006FDE80_0x6fde80.cpp) | `lookup_selected_x509_name_attribute_oid_long_or_short_literal` | Confirmed complete prefix/length/43-entry table | Requires exact byteLength3 and prefix55 04; byte2 in3..2D indexes full43-entry table. Returns long name when third argument0, short name when nonzero; supported literal pairs below. Unsupported/index/outside/prefix/length returns0. Branch-likely admits firstbyte read ONLY after exact length. No input-null guard or general OID decoding. |

All43words at73BD30, SHA-256 `abc798f5ab481e1be418c99b53e01b49161c93ca329004e1187f5a1e61902ba7`. Selected third-byte entries below; EVERY other index3..2D targets null-return6FE044. Outside range also null. Literal pair spellings copied from owned bytes, without replacing S/SN with assumed standard abbreviations.

| Byte2 | Long name | Short name |
| --- | --- | --- |
|3|commonName|CN|
|4|surname|S|
|5|serialNumber|SN|
|6|countryName|C|
|7|localityName|L|
|8|stateOrProvinceName|ST|
|A|organizationName|O|
|B|organizationalUnitName|OU|
|C|title|T|
|D|description|D|
|2A|givenName|G|
|2B|initials|I|
|2D|uniqueIdentifier|UID|

Audit:198 verified instruction words, zero conflicts,7 omitted zero words (NOP padding), zero omitted nonzero words.
