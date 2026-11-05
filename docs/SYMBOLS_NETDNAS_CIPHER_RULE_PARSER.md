# Network DNAS: cipher-list rule parser, list reordering and descriptor formatter

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. Three complete clear bodies, all37 alias records/names, all16 formatting targets and owned default/format strings were independently read. No target execution, game, build, replay, attachment, network request or live-memory inspection occurred.

The parser connects method44/48 cipher enumeration, [method availability caches](SYMBOLS_NETDNAS_CIPHER_METHOD_RESOLUTION.md) and [pointer arrays](SYMBOLS_NETDNAS_POINTER_ARRAY.md). It is static configuration processing, not a currently enabled cipher list or a security recommendation. No live configuration, gameplay timing or slowdown cause was measured.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x727158](../recomp/config/output_ovl/o4/o4_00727158_0x727158.cpp) | `move_cipher_rule_node_to_tail_unless_already_last` | Confirmed complete next/previous/head/tail flow | a0 headcell,a1node,a2tailcell. Ifnode==*tailreturnsunchanged;elserepairshead/neighborsusingnodeCnext/10previous,linksaftercurrenttail,setsnodeCNULL,node10oldtail,*tail=node. Requiresvalidnonnulltailwhenmoving;no membership/cycle/partial-link admission or normalized return. |
| [o4 0x7271C0](../recomp/config/output_ovl/o4/o4_007271C0_0x7271c0.cpp) | `parse_named_or_hex_cipher_rules_and_construct_selected_and_sorted_lists` | Confirmed complete parser/list/cache/cleanup flow; edge-case configuration semantics partial | a0method,a1optionalprimaryoutputcell,a2optionalsortedoutputcell,a3rules. NULLrulesNULL. DEFAULTseven-byteprefix expands owneddefaultpluscolon+suffix. Refreshes method cachesifflag765ED0,buildsunavailablebitmaskfromprovider/cipher/digestavailability,enumeratesenabledmethod44/48descriptorsand37aliases,builds20-bytecandidate nodes and40-byteparsedrules. Supportsseparatorscolon/space/semicolon/comma,leadingnormal/!/ -/+operations,plusjoinedfilters,namesoroptional0xhexIDs. Appliesliteralmask/name/idpredicate,activates/deactivates/removes/movesnodes,collectsactivepointers,optionallyreplacesoutputsandsortedclone. ReturnselectedlistorNULLwithcommontemporarycleanup. Edgecases below prevent a blanket standard-compatible rule-language claim. |
| [o4 0x727E48](../recomp/config/output_ovl/o4/o4_00727E48_0x727e48.cpp) | `format_cipher_descriptor_protocol_key_exchange_auth_cipher_mac_and_export_labels` | Confirmed complete flag/string/buffer/format flow; bounded formatting partial | a0descriptor,a1optionaloutput,a2declaredcapacity. Reads flags10/strength18;choosesownedprotocol,Kx,Au,cipher/declaredbits,MAC,exportlabels. Sixteen-targetdispatchhandleskeyexchangebits1..16;explicitbranchfamilieshandleauth/encryption/digestflags. NULLoutputallocates128bytes;nonnullrequirescapacity>=128. Uses10A830formattingwithglobal765ED4format;returnsbufferorNULL. No NULLdescriptoradmission,actualformatted-lengthbound,caller-buffertruthfulnessorrealstrengthproof. |

## Parser entry, tokens, rule application and ownership

Before parsing,7271C0 refreshes the named caches when their initialflag remains set, then combines unavailable provider/method bits with a baseline exclusion mask. It asks method44 for count, method48 for each descriptor and filters descriptorword0/flags10. The candidate-node allocation uses literal `(count*20)|1`, not a checked multiplication. Names are searched with existing exact-body comparator726EB0 and numeric IDs with726ED8; aliases, sorted pointer arrays and actual candidate nodes remain distinct objects.

DEFAULT is a seven-byte prefix test, so the suffix need not begin with a separator. Expansion allocates original rule length+49, copies the48-byte owned default storage, appends ownedcolon and originalsuffix+7. Tokens accept ASCIIletters,digits,hyphen up to38bytes before termination; malformed or unknown components can be skipped rather than failing the whole call. Optional0x numeric tokens accumulate64-bithex without overflow checks and then search by the comparator's low24-bit policy. A plus inside a rule joins matched descriptor filters; this is distinct from leadingplus operation4.

Leading normal operation1 activates inactive matches and moves them to tail; leading`!`operation2 unlinks matching nodes permanently; leading`-`operation3 clears active flags; leading`+`operation4 moves already-active matches to tail. Matching uses the exact predicate `v = ruleMask & descriptorFlags; v != 0 && (v & ruleRequired) == v`, plus optional exact name/fullidentifier checks. It must not be silently replaced with a conventional all-required-bits predicate. Alias accumulation ORs masks before that test.

Initial application skips the per-node body when head==tail; a single-candidate list therefore differs from a multiple-candidate list in that entry path. For a multiple-node list the later loop processes the tail before stopping: branch conditions inspect the current node while the delay slot advances to the saved next pointer. This distinction follows actual control flow, not list length guesses. No rule-language execution or edge-case input was tested.

Final active-entry appends through729AB0 do not check each append result. Existing caller output lists can be freed/replaced before a later sorted clone allocation fails, so NULLreturn does not imply unchanged caller outputs. Common cleanup frees temporary strings/rules/nodes/search arrays and untransferred selected list, not the borrowed descriptor records. Full configuration correctness, allocation-failure safety and arbitrary caller-pointer aliasing remain unproven.

## Complete owned alias catalogue

765908..765ED0 contains37records of40bytes, SHA-256 `1a30d0bcd6a94d406ec0b084874df03823023a1fb4bcab4b4df0d45d739c76c8`. All ten u32words in every record were read. Layout below completely represents initial records: word0=0,word1=namepointer,words2/3=0,word4=flagslow,word5=0,word6=extra18,word7=0,word8=masklow,word9=0. Extra18 is0 in every record except finalRC4-64-MD5=408hex. Values are raw hex, not claims of active choices or tested cryptographic strength. The parser mutates ALL's flags10 to the complement of its unavailable mask at runtime; the table records initial bytes.

| Record | Owned name pointer / complete text | Flagslow | Masklow |
| --- | --- | --- | --- |
|765908|7805E8 ALL|FFFFFFFF|FFFFFFFF|
|765930|7805E0 kRSA|00000001|0000001F|
|765958|7805D8 kDHr|00000002|0000001F|
|765980|7805D0 kDHd|00000004|0000001F|
|7659A8|7805C8 kEDH|00000010|0000001F|
|7659D0|7805C0 kFZA|00000008|0000001F|
|7659F8|7805B8 DH|00000016|0000001F|
|765A20|7805B0 EDH|000002F0|000003FF|
|765A48|7805A8 aRSA|00000020|000003E0|
|765A70|7805A0 aDSS|00000040|000003E0|
|765A98|780598 aFZA|00000080|000003E0|
|765AC0|780590 aNULL|00000100|000003E0|
|765AE8|780588 aDH|00000200|000003E0|
|765B10|780580 DSS|00000040|000003E0|
|765B38|780578 DES|00000400|0001FC00|
|765B60|780570 3DES|00000800|0001FC00|
|765B88|780568 RC4|00001000|0001FC00|
|765BB0|780560 RC2|00002000|0001FC00|
|765BD8|780558 IDEA|00004000|0001FC00|
|765C00|780550 eNULL|00010000|0001FC00|
|765C28|780548 eFZA|00008000|0001FC00|
|765C50|780540 MD5|00020000|00060000|
|765C78|780538 SHA1|00040000|00060000|
|765CA0|780530 SHA|00040000|00060000|
|765CC8|780528 NULL|00010000|0001FC00|
|765CF0|780520 RSA|00000021|000003FF|
|765D18|780518 ADH|00000110|000003FF|
|765D40|780510 FZA|00008088|0001FFFF|
|765D68|780508 EXP|00100000|00300000|
|765D90|780500 EXPORT|00100000|00300000|
|765DB8|7804F8 SSLv2|00400000|00C00000|
|765DE0|7804F0 SSLv3|00800000|00C00000|
|765E08|7804E8 TLSv1|00800000|00C00000|
|765E30|7804E0 LOW|01000000|07000000|
|765E58|7804D8 MEDIUM|02000000|07000000|
|765E80|7804D0 HIGH|04000000|07000000|
|765EA8|7804C0 RC4-64-MD5|01521021|0037FFFF|

## Owned default, formatting strings and complete dispatch

780620 holdsNUL-terminated`DEFAULT`, SHA-256 `b6915b6affc29027435d4f0ccc1bd91661cf5ace2ae10c6106ae7eb378ccb627`. 780628 holdscomplete`ALL:!ADH:RC4+RSA:+HIGH:+MEDIUM:+LOW:+SSLv2:+EXP`includingNUL, SHA-256 `ee611058799e22f8b81ca1608598b905a92c4028683457bfd6cf013ed5d5c8af`. Owned780658colon+NULhash `7648eb81c4e9fef7b51879c6fcd6fb4b8863eea0cb2a978c508711dc52c80041`.

Global765ED4points780660,completeformat `%-23s %s Kx=%-8s Au=%-4s Enc=%-9s Mac=%-4s%s`includingNUL, SHA-256 `09f271f04094efd2568b625e39a801b061869f4aa46ef0d487315ef4084e5a7b`. Allreferencedformatlabels/stringswereindependentlyread:protocolSSLv2/SSLv3/unknown;KxRSA/RSA(%d)/DH-RSA/DH-DSS/Fortezza/DSA(%d)/DH;AuRSA/DSS/DH/None;cipherDES/3DES/RC4/RC2/IDEA/Fortezza/None/unknown;MACMD5/SHA1/unknown;optional` export`. OwnedspellingfortheDHlabelsis`DH/RSA`,`DH/DSS`;theplainwordsdescribeformatroleswithoutinventingnewenumvalues.

7806F0..780730,16little-endianu32targets, SHA-256 `95d635616e888d3e4fd5e0000881a1d9e1d6cd94b9707109a707c5007c659ea7`,alltargetsverifiedasactualinstructionswithin727E48:

```text
727F1C 727F40 727F9C 727F4C 727F9C 727F9C 727F9C 727F58
727F9C 727F9C 727F9C 727F9C 727F9C 727F9C 727F9C 727F64
```

Descriptor formatting chooses declared bit counts from strength18lowbyte*8 or defaults56/168/128 for selected algorithms. That is presentation metadata, not a security audit. No formatter output or allocation was generated by this investigation.

## Validation

Three independent rows,1075 original instruction comments; complete aligned intervals matched owned bytes, no conflicts or omitted nonzero words. All local links resolve. Data records, strings and existing comparator aliases do not add function credit. No runtime configuration or engine/launcher source was changed.
