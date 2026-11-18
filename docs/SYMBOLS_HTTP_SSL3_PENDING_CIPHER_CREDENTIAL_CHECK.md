# HTTP overlay pending-cipher credential admission

Static owned o6 `nethttp.bin`, runtime ID6/base `6E0000`, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Full original2C0-byte interval reviewed,including all export/normal slot choices, requirement masks and error exits. No target execution, cryptographic or network tests. All values hexadecimal. [Key capability composition](SYMBOLS_HTTP_SSL_KEY_CLASSIFICATION_AND_ALERTS.md) defines728DB0's numerical result; [credential masks](SYMBOLS_HTTP_SSL_CIPHER_CAPABILITIES_AND_CERTIFICATE_TYPES.md) are a separate mechanism.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x722778](../recomp/config/output_ovl/o6/o6_00722778_0x722778.cpp) | `admit_pending_cipher_against_peer_certificate_capability_bits_and_temporary_key_limits` | Confirmed complete slot/mask/limit checks | Requires cached peer credential90 elseerror0. Pending cipher15C flags300 immediately admit1. Otherwise chooses temporary RSA20/DH2C normally; exportflag100000 chooses RSA28 when descriptor18 highbyte400 andnonnull,else24,andDH30. Selects peer certificate using credential classification0 into five-pair array,gets bridge key6FD010 and certificate type6FCEF0,composes capabilities728DB0. Exact mask requirements below. Nonexport success1. Export additionally accepts caps1000,else requires corresponding temporary key and compares RAW byte capacity715DF0(RSA)/702960(DH) <=(descriptor18 AND FF00),without shifting that field. Any failure logs14/82/reason,sends fatalalert28,returns0. No key/certificate null admission before these child calls or general classification range gate. |

| Pending cipher flags | Required capability admission |
| --- | --- |
| 20 | `(caps AND11)==11` |
| 40 | `(caps AND12)==12` |
| 1 | `(caps AND21)==21` OR selected temporaryRSA nonnull |
| 10 | `(caps AND44)==44` OR selected temporaryDH nonnull |
| 2 | `(caps AND104)==104` |
| 4 | `(caps AND204)==204` |

All active requirements apply sequentially,except the flags300 early admission. The raw export-limit comparison and capability flags remain literal implementation rules; they do not establish key strength, trust or protocol conformance. The client driver invokes this after parsing optional server parameters.

Audit: 176 verified instruction words, zero conflicts, 0 omitted zero words (NOP padding), zero omitted nonzero words.
