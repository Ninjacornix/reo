# HTTP overlay SSL key classification, policy adapters and verification alerts

Static owned o6 `nethttp.bin`, runtime ID6/base `6E0000`, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Seven complete catalogue intervals and all 49 alert-table words reviewed. No target execution, certificate test or network exchange. Numeric values are hexadecimal. [Peer credential parsing](SYMBOLS_HTTP_SSL_PEER_CREDENTIALS.md) binds classification to five-pair storage; [global policy](SYMBOLS_HTTP_SSL_PARENT_CONTEXT_AND_GLOBAL_POLICY.md) defines the optional bit2 gate. Generic key internals remain in [DSA key wrappers](SYMBOLS_HTTP_DSA_KEY_DECODERS_AND_PROVIDER.md) and [size/parameter adapters](SYMBOLS_HTTP_KEY_SIZES_PARAMETERS_AND_SIGN.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x71A438](../recomp/config/output_ovl/o6/o6_0071A438_0x71a438.cpp) | `classify_peer_certificate_or_supplied_key_into_bounded_credential_pair_index` | Confirmed complete finite return set | Args(certificate,optional key). Missing key extracted through6FD010(certificate). Null extraction returns-1. Key type6->0;74->2;1C with null certificate->4. Type1C with certificate asks6FCEF0(certificate):result6->3,74->4, other->-1. All other key types->-1. Thus accepted outputs are exactly0/2/3/4, within the five-pair container; index1 is not produced here. External key/certificate contents not validated. |
| [o6 0x71A4E0](../recomp/config/output_ovl/o6/o6_0071A4E0_0x71a4e0.cpp) | `translate_certificate_verification_reason_to_owned_ssl_alert_number` | Confirmed full 49-entry jump table and default | Unsigned reason-2<31 selects table73D710; otherwise returns2E. Table maps reasons below to numeric alert return constants. Caller720F20 uses this after failed verification to select fatal alert; no live certificate reason or standards guarantee inferred. |
| [o6 0x728BB8](../recomp/config/output_ovl/o6/o6_00728BB8_0x728bb8.cpp) | `get_ssl_key_signature_capacity_subject_to_optional_dsa_policy` | Confirmed complete null/type/policy gates | Null key0. Key type74 returns0 when policy bit2 is clear; otherwise invokes70B180(key), which delegates RSA/DSA signature-size calculation. Other types also delegate. No normalization of negative child status. |
| [o6 0x728CB0](../recomp/config/output_ovl/o6/o6_00728CB0_0x728cb0.cpp) | `test_ssl_key_missing_parameters_only_when_optional_dsa_policy_enabled` | Confirmed complete policy branch and delegated predicate | Policy bit2 clear returns0 without reading key. Enabled invokes70B340(key): type74 missing any payloadC/10/14 parameter pointer returns1, complete or non74 returns0. Certificate parser rejects nonzero result; this is a missing-parameter test, not key signature verification. |
| [o6 0x728D88](../recomp/config/output_ovl/o6/o6_00728D88_0x728d88.cpp) | `get_ssl_generic_key_canonical_type_through_shared_key_wrapper` | Confirmed complete wrapper | Calls70B520 with original key and returns canonical type result. No extra null admission or algorithm translation. |
| [o6 0x728DA8](../recomp/config/output_ovl/o6/o6_00728DA8_0x728da8.cpp) | `release_ssl_generic_key_through_reference_counted_key_destructor` | Confirmed complete tail and bridge binding | Tail-jumps70B638 with original pointer; installed external bridge selector35 uses this as default key-release callback. Destructor handles null and delegated reference policy. |
| [o6 0x728DB0](../recomp/config/output_ovl/o6/o6_00728DB0_0x728db0.cpp) | `compose_ssl_key_type_query_and_small_signature_capacity_bits` | Confirmed all type/query/capacity branches | Null key0. Canonical type6 sets base31,1C->44,74->12, other0. Query arg0==6 ORs100;==200 ORs200; other query values add neither. Gets signature capacity728BB8; if signed capacity<=200 ORs1000, otherwise leaves base/query bits. A zero or negative delegated capacity also enters that <=200 branch. Bit meanings beyond this literal construction remain partial; not an algorithm/security-strength proof. |

Owned alert jump table `73D710..73D7D4`, 49 little-endian words, SHA-256 `46469a29bd8a20b98dccc6c0b052d0c65ef8e73ec8adcee8ca561812d1655d74`:

| Verification reasons | Returned alert |
| --- | --- |
| 2,3,12,13,14,15,16 | 30 |
| 4,5,6,9,B,D,E,F,10 | 2A |
| 7,8 | 33 |
| A,C | 2D |
| 11 | 50 |
| 17 | 2C |
| 32 | 28 |
| 18..31 and outside2..32 | 2E |

The finite classifier closes the local credential-pair index bound for the parser. It does not prove that a bridge-generated key is structurally valid, trusted or usable for the selected protocol.

Audit: 160 verified instruction words, zero conflicts, 7 omitted zero words (NOP padding), zero omitted nonzero words.
