# HTTP overlay ASN.1 ANY ownership and encoded-object signature verification

Static owned File #1 o6 `nethttp.bin`, runtime ID6/base6E0000, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Eight full original catalogue intervals and all29 jump-table entries reviewed. No decode/signature test, build, endpoint traffic, or target execution. Companion [ANY encoder and collections](SYMBOLS_HTTP_X509_NAMES_AND_ASN1_COLLECTIONS.md), [primitive codecs](SYMBOLS_HTTP_ASN1_PRIMITIVES.md), and [integer/OID codecs](SYMBOLS_HTTP_ASN1_INTEGER_OBJECT_IDS.md). Algorithms behind digest/key vtables remain delegated.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x6F15E0](../recomp/config/output_ovl/o6/o6_006F15E0_0x6f15e0.cpp) | `decode_asn1_any_union_by_owned_tag_table_after_releasing_previous_value` | Confirmed complete dispatcher/table/ownership mechanics | Reuses optional union or allocates6F1908. Parses header, then releases old arm6F1A10 BEFORE tag admission or child decoding. Owned table handles integer2,bit3,octet4,NULL5,OID6,raw full-encoding sequence10/set11,strings13/14/16/1B/1C/1E,time17; unsupported tags error libD/function85/reason6A. NULL5 commits HEADER-end cursor with payload0 without requiring declared content length0. Sequence/set create typed string and copy header+declared-content verbatim; extent check compares declared CONTENT length to total available from ORIGINAL header start, before adding header span. Publishes union tag and caller cursor only on success; reused union old value may already be lost on failure. Parsed class/constructed bits do not gate dispatch. |
| [o6 0x6F1908](../recomp/config/output_ovl/o6/o6_006F1908_0x6f1908.cpp) | `allocate_empty_asn1_any_union_with_type_minus_one` | Confirmed full body | Allocates8 bytes, type+0=-1, arm+4=0. Failure reports libD/function77/reason21 and returns0. No arm allocation. |
| [o6 0x6F1960](../recomp/config/output_ovl/o6/o6_006F1960_0x6f1960.cpp) | `release_asn1_any_union_arm_then_free_header` | Confirmed complete destructor | Null returns. Otherwise calls6F1A10 then tail-frees union. Uses arm type ownership rules below; does not independently validate them. |
| [o6 0x6F19A0](../recomp/config/output_ovl/o6/o6_006F19A0_0x6f19a0.cpp) | `get_asn1_any_type_only_when_union_arm_nonnull` | Confirmed complete getter | Returns type+0 if arm+4 nonnull, else0. No null-union guard; NULL-tag union with null arm also reports0. |
| [o6 0x6F19C0](../recomp/config/output_ovl/o6/o6_006F19C0_0x6f19c0.cpp) | `replace_asn1_any_type_and_transfer_supplied_arm_pointer` | Confirmed full setter | Releases old arm through6F1A10 only if nonnull, then stores supplied pointer+4 and type+0. No deep copy, retain operation, self-alias guard, or type validation. Ownership transfer inferred from connected destructor. |
| [o6 0x6F1A10](../recomp/config/output_ovl/o6/o6_006F1A10_0x6f1a10.cpp) | `clear_asn1_any_arm_using_type_selected_destructors` | Confirmed full condition tree | Null union or null arm returns immediately (null arm leaves type unchanged). Nonnull type6 usesOID6EF7E8; types2..4,10..1C,1E,102 use typed-string6F0540. Other types drop pointer without a destructor. Then clears arm and type to0. It neither recursively parses raw sequence/set nor treats every integer type as supported. |
| [o6 0x6F1AB8](../recomp/config/output_ovl/o6/o6_006F1AB8_0x6f1ab8.cpp) | `encode_object_hash_bytes_and_verify_supplied_signature_with_key` | Confirmed full orchestration and tri-state return; algorithms delegated | Resolves digest method705AC0 from algorithm descriptor's firstword, allocates digest context, calls supplied encoder for size then bytes, initializes digest and updates encoded bytes. Wipes temporary encoded bytes before invoking70B8E0(context,signature.data+8,signature.length+0,key). Positive verify->1, nonpositive->0 with libD/function79/reason806; setup/allocation/init failure->-1. Encoder result/size agreement and digest-update status unchecked locally. Always frees allocated buffer/context; signature bits flags and algorithm strength not established by this wrapper. |
| [o6 0x70B8E0](../recomp/config/output_ovl/o6/o6_0070B8E0_0x70b8e0.cpp) | `verify_finalized_digest_using_compatible_key_type_and_method_callback` | Confirmed complete compatible-type loop and finalization dispatch | Digest method=context+0. Requires key type+0 match one of up to FOUR nonzero method words+20..2C; mismatch reports lib6/function7B/reason7A. Allocates second digest context, copies original7057C8, finalizes into stack digest/length702E30, then frees copied context and invokes method+1C `(method.id,digest,digestLen,signature,signatureLen,key.payload+C)`. Missing callback reason77; allocation/copy/mismatch failures return-1. Callback return preserved; no assumption about exact public-key algorithm or success domain beyond caller handling. |

Owned jump table `73B130`, index=`tag-2`, all29 words:

```
02 6F16B0   03 6F16CC   04 6F16E8   05 6F16A0   06 6F1704
07 6F1884   08 6F1884   09 6F1884   0A 6F1884   0B 6F1884
0C 6F1884   0D 6F1884   0E 6F1884   0F 6F1884   10 6F1804
11 6F1804   12 6F1884   13 6F1720   14 6F173C   15 6F1884
16 6F175C   17 6F17DC   18 6F1884   19 6F1884   1A 6F1884
1B 6F177C   1C 6F179C   1D 6F1884   1E 6F17BC
```

Raw sequence/set preservation is different from recursively validating contents. Literal bounds, tag omission, and destructive failure behavior are recorded without claiming malformed-input runtime reachability, security impact, or an observed gameplay bottleneck.

Audit: 474 verified instruction words, zero conflicts, 19 omitted zero words (NOP padding), zero omitted nonzero words.
