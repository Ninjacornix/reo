# Recovered primary DNAS packed prefix construction and validation

Static File #1 US o4, 2026-11-05. Four complete clear-entry/recovered-payload/restore/epilogue owners, based on the [primary copied-data inventory](STATIC_DNAS_PRIMARY_RECOVERY_INVENTORY.md). Owned o4/runtime5/base6E0000 SHA-256 `8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16`. Hexadecimal addresses/offsets, decimal spelled byte counts. No recovered instructions, game or target process was executed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x6E5260](../recomp/config/output_ovl/o4/o4_006E5260_0x6e5260.cpp) | `initialize_packed_prefix_operation_nibble_and_boolean_bit` | Confirmed complete recovered bitfield writes | Inputs operation a0/flag a1/prefix a2. Zeros bytes+2/+3, sets halfword+2 bit80 iff a1nonzero, then sets bitsF00 from low4(a0)<<8. Preserves no other bits because the halfword was first zeroed. Restores protection and returns without assigning a defined semantic result. Clear caller6E5388 combines this with two-byte761638 prefix and32-byte7614F4 state and returns40. |
| [o4 0x6E6A40](../recomp/config/output_ovl/o4/o4_006E6A40_0x6e6a40.cpp) | `compare_reply_first_two_bytes_with_mutable_session_prefix` | Confirmed complete recovered comparison wrapper | Calls6E5F90(input,761638,2); result0 ->0, other result ->-1. Saves result through actual paired protection restore and complete epilogue.761638 is writable context, initially two zero bytes in the owned image; not an immutable magic value. |
| [o4 0x6E6B30](../recomp/config/output_ovl/o4/o4_006E6B30_0x6e6b30.cpp) | `classify_reply_status_marker_or_compare_operation_and_boolean_prefix_halfword` | Confirmed complete recovered classification | Inputs operation a0/boolean a1/prefix a2. If LHU(prefix+2)&F00 equals400, returns0 immediately through restore. Otherwise if a1&~1 nonzero returns-1. Builds two local bytes containing low4(a0)<<8 | (a1&1)<<7 and compares exactly two bytes with prefix+2 through6E5F90; equal ->1, mismatch ->-1. Unlike the constructor, arbitrary nonzero a1 is rejected here. |
| [o4 0x6E6C90](../recomp/config/output_ovl/o4/o4_006E6C90_0x6e6c90.cpp) | `compare_reply_prefix_bytes_four_through_thirty_five_with_mutable_session_field` | Confirmed complete recovered comparison wrapper | Calls6E5F90(input+4,7614F4,32), returning0 for equality and-1 otherwise through restore.7614F4 is a mutable32-byte session comparison field, initially all zero in the owned image. Clear request construction6E5388 writes this same slice via6E2E20. Its concrete higher-level/security meaning is not invented. |

The connected clear6E6D80 validates a forty-byte reply prefix:6E6A40 must succeed;6E6B30 negative ->-106, zero sets caller status-marker word1. Operation5 calls6E2F20 on prefix+4, other operations require6E6C90 success. Then6E7B20 reverses prefix word24 and stores caller length output; success returns40. This supplies meaningful request/reply ownership but does not independently identify an original protocol or authentication field.

6E5F90 is the already-reviewed unsigned-byte lexicographic comparator returning-1/0/1, with a zero-count bypass. For these fixed two/32-byte counts, the wrappers use only equality. Shared state may change at runtime; the owned zero initialization does not establish any live value. No host memcmp rewrite or unrestricted pointer/alias validation follows from this mapping.

Full envelopes end immediately after return delay slots:6E5260..6E5384,6E6A40..6E6B30,6E6B30..6E6C8C,6E6C90..6E6D80. Their payloads are6E52E8..6E5318(12 words),6E6AB0..6E6ACC(7),6E6BB4..6E6C1C(26),6E6D00..6E6D1C(7). All use actual paired restore calls at6E5360,6E6B14,6E6C64,6E6D64. Original skipped descriptors/interior catalogue cuts gain no function row.

Reproduce with `python tools/function_index/recover_dnas_primary_inventory.py`, then `python tools/function_index/review_dnas_primary_middle.py`. The [repository checker](../tools/function_index/review_dnas_primary_middle.py) and regenerated [receipt](../build-function-index/dnas-primary-middle-review/receipt.json) bind all13 reviewed primary-middle owners/16 spans/1,038 recovered words to original and candidate hashes, verify all actual restore argument loads, preserve metadata exceptions and check direct branch/delay positions with zero unknown admitted fields. This is static field/identity checking; the semantic review is above. See [HTTP mechanics](SYMBOLS_NETDNAS_RECOVERED_HTTP_REQUEST_AND_HEADER_PARSER.md) and [reply dispatch](SYMBOLS_NETDNAS_RECOVERED_PRIMARY_REPLY_STATUS_DISPATCH.md).

Retained candidate identities (span ends exclusive; counts decimal). Each restore-call address was checked against actual descriptor argument loads; a verified call binding does not mean every path reaches it.

| Payload | Words / preserved exceptions | Restore call | Candidate SHA-256 |
| --- | ---: | --- | --- |
|6E52E8..6E5318|12/0|6E5360|`d0c1a42d71458d23b8607252658078e1b62f22e68040bcb4334d558146aed204`|
|6E6AB0..6E6ACC|7/3|6E6B14|`a9cbd5ab08268f2610c3a928123aeb87e15f7dbe7ee64aa6d9b4ae1da73ff478`|
|6E6BB4..6E6C1C|26/1|6E6C64|`85a8356fdaffad2cbf90dddea7e2a5e66042dd1a2ad6ff85b526205064f489f8`|
|6E6D00..6E6D1C|7/3|6E6D64|`f7d934e9eaff6c43f2549cf4eb9be9662a7a6894636748739d15cdec0a52a3d1`|

Original generated-source word audit: 4 role rows, 108 verified words, 9 omitted zero padding words, zero conflicts and zero omitted nonzero words. This is separate from the joined recovered-owner review.
