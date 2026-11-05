# Network DNAS: cipher catalogue comparison, named method caches and descriptor queries

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. Eight complete clear bodies, all named lookup strings and initial cache slots were read; no game, build, replay, target execution, attachment, network request or live-memory read occurred.

The resolver supplies cipher/digest methods to [legacy client setup](SYMBOLS_NETDNAS_VERSION_TWO_CLIENT_HANDSHAKE.md) and [version-three crypto flow](SYMBOLS_NETDNAS_VERSION_THREE_CRYPTO_FLOW.md). Descriptor flags and literal shipped names establish local selection rules. They do not establish that a cached method exists at runtime, an algorithm is secure/correct or that it affects gameplay speed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x726ED8](../recomp/config/output_ovl/o4/o4_00726ED8_0x726ed8.cpp) | `compare_cipher_pointer_entries_by_low_twenty_four_identifier_bits` | Confirmed complete unsigned comparison | Dereferences both pointer entries, loads descriptor u64+8, masks00FFFFFFhex and returns-1/0/+1 by unsigned order. Protocol tag upper byte is ignored. No NULL/type admission or tie-break for equal low IDs. |
| [o4 0x726F18](../recomp/config/output_ovl/o4/o4_00726F18_0x726f18.cpp) | `refresh_named_cipher_and_digest_method_caches_without_individual_failure_checks` | Confirmed complete lookup/store flow | Clears765ED0, looks up DES-CBC,DES-EDE3-CBC,RC4,RC2-CBC,IDEA-CBC through704F98 into7658E0 slots0..4, and MD5/SHA1 through704FB8 into765900 slots0..1. Does not fill other slots, check results or lock refresh. Return is not normalized to an all-methods-present status. All names/initial slots inventoried below. |
| [o4 0x726FC0](../recomp/config/output_ovl/o4/o4_00726FC0_0x726fc0.cpp) | `resolve_cipher_descriptor_flags_to_cached_cipher_and_digest_methods` | Confirmed complete flag/cache/output/status flow | NULLdescriptor returns0 without output writes. Other descriptors mask flags+10 by1FC00hex:400/800/1000/2000/4000 map cipher cache slots0/1/2/3/4;10000 calls702E58 null-cipher factory; unsupported patterns storeNULLcipher. Digest mask60000hex:20000=>MD5slot0,40000=>SHA1slot1, othersNULL. Writes both output cells and returnsBoolean bothnonnull. No implicit refresh, NULLoutput admission or protection against stale caches. |
| [o4 0x728268](../recomp/config/output_ovl/o4/o4_00728268_0x728268.cpp) | `get_cipher_identifier_low_twenty_four_bits_or_minus_one` | Confirmed complete NULL/field/mask flow | NULLreturns-1; otherwise descriptor u64+8&00FFFFFFhex. Branch-likely load executes only for nonNULL. No ownership or enabled-cipher admission. |
| [o4 0x728288](../recomp/config/output_ovl/o4/o4_00728288_0x728288.cpp) | `describe_cipher_protocol_tag_with_owned_version_name_or_unknown` | Confirmed complete literal/field branching | NULLreturns `(NONE)` at780730. NonNULL shifts identifier u64+8 left8 then arithmetic-right32; result3 returns `TLSv1/SSLv3` at780738, result2 returns `SSLv2` at7804F8, otherwise `unknown` at7806A0. This exact full64-bit shift is retained; tag naming assumes ordinary zero upper32 descriptor IDs. No negotiated-live-version claim. |
| [o4 0x7282D8](../recomp/config/output_ovl/o4/o4_007282D8_0x7282d8.cpp) | `get_cipher_descriptor_name_pointer_or_owned_none_label` | Confirmed complete pointer getter | NonNULLdescriptor returns word+4, NULLreturns780730 `(NONE)`. Does not copy, validate lifetime or calculate algorithm properties. |
| [o4 0x7282F0](../recomp/config/output_ovl/o4/o4_007282F0_0x7282f0.cpp) | `get_cipher_descriptor_enabled_word_without_null_admission` | Confirmed complete scalar getter | Returns signed word0 through JR delay; no NULL admission or Boolean normalization. Independently distinct from protocol/name getters. |
| [o4 0x7282F8](../recomp/config/output_ovl/o4/o4_007282F8_0x7282f8.cpp) | `report_descriptor_effective_and_method_key_bits_with_des_style_adjustment` | Confirmed complete resolver/size/optional-output flow | NULLdescriptor returns0 and writes0 to optional a1 bit-count cell. Successful726FC0 gets method key bytes704B30, multiplies8; flagsC00hex adjust to7 bits per byte. Returns descriptor byte18*8 when nonzero, otherwise adjusted method count; optional a1 receives adjusted method count. Resolver failure returns0 without writing optional cell. Names describe declared fields, not measured entropy/strength or enforced key size. |

## Cache initialization and complete owned names

Initial7658E0..765900 contains eight zero u32 slots, SHA-256 `66687aadf862bd776c8fc18b8e9f8e20089714856ee233b3902a591d0d5f2925`. Initial765900..76590C contains three zero slots, SHA-256 `15ec7bf0b50732b49f8228e07d24365338f9e3ab994b00af08e5a3bffe55fd8b`. Initial765ED0 flag is1, SHA-256 `67abdd721024f0ff4e0b3f4c2fc13bc5bad42d0b7851d456d88d203d15aaa450`. The resolver itself does not inspect that flag or call refresh; ordinary non-null cached selection needs another setup path. These are shipped initial bytes, not current runtime values.

All following complete strings including NUL were read. Adjacent names/data are excluded from each digest.

| Owned start | Text | SHA-256 including NUL |
| --- | --- | --- |
|7805F0|DES-CBC|`760c750d3c1e50bb887d1f1b7f2380a3484b9825d2dbe2170455711b78fb1f33`|
|7805F8|DES-EDE3-CBC|`da3fd4820f723a50608a84d72b8afba18787daedbe8c81356830a502be540179`|
|780568|RC4|`e0259a1f36e424290245fe49b33b63b4dedc955565f872e2e5a40729ea41e0f6`|
|780608|RC2-CBC|`12457968feb44a80221adaab2ba41d1fff0e4a9be97c214ff3c4de39e8a04a01`|
|780610|IDEA-CBC|`e460f3b3c9c0b894a7f821f4e856e5d0832c13d773c2bdd80035a8977233cfd5`|
|780540|MD5|`532e926da6c510683b7c5ed720fd655b98ccfdb45fc4b7ada4b17a9d26ec4e5b`|
|780538|SHA1|`c6756a628e48b968a0be712fb66a65505714b46ce7bf17aa67ba97e0fda1acec`|
|780730|(NONE)|`fa0cbadd30252a8f232cce5e8706b4d7a5a96bd0eb509798d3f339d4dfb3ec99`|
|780738|TLSv1/SSLv3|`988e61b85d198649d8eb23b067cbf531cdeddb97fbc8115a3cc8b7e6773707aa`|
|7804F8|SSLv2|`5e1fed389aac63c432f38bf2ae4faab452a8551bb339c054b7a60a78cc67c1ff`|
|7806A0|unknown|`4c5b832482cb7cfb6ee1586012d5aa48a335bc1b00bffae8b63c59f058fe0dda`|

## Validation

Eight independent rows,230 original instruction comments; full aligned ownership intervals matched owned bytes, no conflicts or omitted nonzero words. All local links resolve. Cache slots and strings are data and add no function credit. No runtime, engine or launcher changes were made.
