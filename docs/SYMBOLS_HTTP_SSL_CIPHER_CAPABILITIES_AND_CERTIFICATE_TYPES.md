# HTTP overlay credential capability masks and cipher selection

Static owned o6 `nethttp.bin`, runtime ID6/base `6E0000`, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Three entire catalogue intervals reviewed, including every initial cache/pair gate, key-size threshold, masked requirement and list loop. No target execution or cryptographic/network tests. Values are hexadecimal. [Credential installation](SYMBOLS_HTTP_SSL_CREDENTIAL_INSTALLATION.md) clears mask-valid word8 after mutation; [global policy](SYMBOLS_HTTP_SSL_PARENT_CONTEXT_AND_GLOBAL_POLICY.md) supplies feature bits; cipher records are in [lookup tables](SYMBOLS_HTTP_SSL_CIPHER_LOOKUP_TABLES.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x71DD98](../recomp/config/output_ovl/o6/o6_0071DD98_0x71dd98.cpp) | `cache_full_and_size_limited_cipher_capability_masks_from_credential_pairs` | Confirmed complete five-pair and flag derivation | Null container or valid8 nonzero returns without recompute. Derives pair presence and key-size predicates below; stores u64 full mask10, limited mask18 and valid8=1. Complete mask formulas retained below. Only key-size helper728BB8 and policy getter71E818 called; no certificate/key operation test. Key sizes are signed values shifted left3 in a32-bit instruction before signed threshold comparison, so invalid/overflow values are not silently treated as validated bit lengths. |
| [o6 0x71BF58](../recomp/config/output_ovl/o6/o6_0071BF58_0x71bf58.cpp) | `select_first_preferred_cipher_present_in_peer_list_and_admitted_by_credential_mask` | Confirmed complete local-preference loop and mask choice | Chooses connection84 credentials or parentDC->A0, computes71DD98, loads masks10/18. Sets peer list comparator71D658 through728EE0. Walks preferred array arg1 in order: required flags=descriptor u64+10 AND3FF; descriptor bit100000 selects limited mask18, otherwise full10. Requires all required bits present and729218(peerList,descriptor)>=0; returns MATCHED PEER-LIST pointer at returned index, not necessarily local pointer. No match0. Null credential/list admission and callback/sort semantics delegated; no actual negotiation observed. |
| [o6 0x71C078](../recomp/config/output_ovl/o6/o6_0071C078_0x71c078.cpp) | `emit_certificate_request_type_bytes_from_selected_cipher_flags_and_optional_algorithms` | Confirmed complete fixed-byte emission branches | Reads selected pending cipher workspace54->15C flags+10. Policy bit1 enabled andflags12nonzero emits3,4; additionally version300 andflags16nonzero emits5,6. Always emits1. Policy bit2 adds2. Returns emitted count, maximum6 bytes on these branches. No output capacity/null admission and no certificate serialization; exact wire enum names remain numeric. |

Let P0..P4 mean both certificate and key pointers of the five pairs at40/44,48/4C,50/54,58/5C,60/64 are nonnull. R means container20 OR38 nonnull. D0 means policy bit1 enabled and container2C OR3C nonnull; D1 uses30 OR3C. S0_512/S0_1024 mean P0 and signed `(signatureCapacity<<3)<201/<401`; S3_512/S4_512 analogous thresholds201 for pairs3/4.

| Mask bit | Full mask10 condition | Limited mask18 condition |
| --- | --- | --- |
| 1 | P0 OR(R AND P1) | S0_512 OR S0_1024 OR(R AND(P1 OR P0)) |
| 10 | D0 | D1 |
| 2 | P3 | S3_512 |
| 4 | P4 | S4_512 |
| 20 | P0 OR P1 | Same |
| 40 | P2 | Same |
| 100 | Global policy bit8 enabled | Same |

No other bits are added. The apparently redundant pair0 size checks are retained as separate observed predicates. Capability masks describe the implementation's selection rules, not measured algorithm availability, cryptographic strength or verified credential compatibility.

Audit: 301 verified instruction words, zero conflicts, 2 omitted zero words (NOP padding), zero omitted nonzero words.
