# HTTP overlay certificate-info ASN1 codec and lifetime

Static owned o6 `nethttp.bin`, runtime ID 6/base `6E0000`, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Four complete original catalogue intervals reviewed, including optional version/UID/extensions, decoder reuse, source tag restoration and constructor exits. Values are hexadecimal. No target execution, certificate round-trip or ASN1 conformance tests. [Signature verifier](SYMBOLS_HTTP_X509_CHAIN_BUILD_AND_VERIFY.md) supplies72F7E8 as the signed-info encoder; [ASN1 primitives](SYMBOLS_HTTP_ASN1_CONSTRUCTED_STREAMS.md) implement child framing.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x72F7E8](../recomp/config/output_ovl/o6/o6_0072F7E8_0x72f7e8.cpp) | `encode_x509_certificate_info_sequence_with_explicit_version_uids_and_extensions` | Confirmed complete size/write/optional fields | Null info returns0. Measures each child, optional version in context-specific constructed tag0, serial integer, algorithm, issuer, validity, subject, public-key-info; optional issuer/subject UID bit strings; nonempty extension vector encoded as sequence under explicit tag3. Wraps universal sequence10. Null output-cursor argument returns measured total. Writing repeats child encoders, overrides UID first tag bytes to81/82 preserving constructed bit20, emits extension wrapper, publishes advanced cursor and returns measured total. Does not admit negative child lengths, output capacity or size/write consistency. |
| [o6 0x72FA90](../recomp/config/output_ovl/o6/o6_0072FA90_0x72fa90.cpp) | `decode_x509_certificate_info_sequence_reusing_children_and_version_gating_optional_fields` | Confirmed complete framing/child/reuse/cleanup mechanics; conformance partial | Reuses*out or creates730028. Parses sequence through6F0300; optional leadingA0 wrapper decodes version integer, otherwise frees/clears prior version. Version discriminator is first byte of version payload when nonnull, not a general integer conversion. Sequentially decodes serial,algorithm,issuer,validity,subject,public key, updating remaining span. If version>0 clears old UIDs and recognizes81/82 (constructed bit ignored), temporarily retags input as bit string3 and decodes6EDAE8, restoring original byte only after success. If version>=2 empties old extension vector then optionally parsesA3 wrapper with extension decoder731330/free731610 through6F1118. Completes6F0280, commits input cursor/output cell only success. Failure logs/offset-reports and frees only newly owned info; reused info may remain partly changed. |
| [o6 0x730028](../recomp/config/output_ovl/o6/o6_00730028_0x730028.cpp) | `allocate_x509_certificate_info_and_required_asn1_child_objects` | Confirmed complete ordered construction and literal failure exits | Allocates28-byte info, version0=null; creates serial type2, algorithm72F738, issuer6F0DF0, validity732310, subject6F0DF0, public key731910. Success clears optional1C/20/24 and returns info. Any required child failure returns null immediately without releasing earlier children/outer allocation; later optional fields are not initialized before all required children succeed. Outer allocation failure logsD/CC/21. |
| [o6 0x7300F0](../recomp/config/output_ovl/o6/o6_007300F0_0x7300f0.cpp) | `release_x509_certificate_info_children_extension_vector_and_outer` | Confirmed complete null guard and child sequence | Null returns. Frees version0/serial4 via6F0540; algorithm8 via72F7A0; issuerC/subject14 via6F0E88; validity10 via732390; publickey18 via731990; optionalUID1C/20 via6F0540; extension vector24 through729530 with731610; tail-frees outer70FFA8. No pointer clearing or alias admission. |

| Info offset | Encoded role | Encoder / decoder |
| --- | --- | --- |
| 0 | Optional version INTEGER in explicit context tag0 | 6EEA38 /6EEBE8 |
| 4 | Serial-number INTEGER | 6EEA38 /6EEBE8 |
| 8 | Signature algorithm identifier | 72F470 /72F540 |
| C | Issuer name | 6F08F0 /6F0B38 |
| 10 | Not-before/not-after validity pair | 732090 /732158 |
| 14 | Subject name | 6F08F0 /6F0B38 |
| 18 | Subject public-key info | 731678 /731740 |
| 1C/20 | Issuer/subject unique bit-string IDs, implicit tags1/2 | 6ED9D8 /6EDAE8 |
| 24 | Extension vector, explicit tag3 | 6F0FF0(731238) /6F1118(731330,731610) |

The decoder writes source tag bytes in place on UID paths. Failed UID decoding can leave the source retagged because restoration occurs only after child success. Reused version0 info does not enter UID clearing; reused version<2 does not enter extension clearing. Those optional children can therefore persist from a prior object. These are literal mutation/cleanup boundaries; input mutability, malformed-input reachability and resulting consequences remain untested.

Audit: 602 verified instruction words, zero conflicts, 12 omitted zero words (NOP padding), zero omitted nonzero words.
