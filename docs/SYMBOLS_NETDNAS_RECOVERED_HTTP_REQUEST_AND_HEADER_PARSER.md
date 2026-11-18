# Recovered primary DNAS HTTP request and response-header mechanics

Static File #1 US o4 review, 2026-11-05. Five complete owners were joined from clear entries, reconstructed islands, actual restore calls, clear error paths and return delay slots. This uses the [primary copied-data inventory](STATIC_DNAS_PRIMARY_RECOVERY_INVENTORY.md), not generated edges through encoded bytes. Owned o4/runtime5/base6E0000 SHA-256 `8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16`. Addresses/offsets below are hexadecimal; spelled byte counts are decimal. No game, recovered instructions, callback or network operation was executed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x6E4310](../recomp/config/output_ovl/o4/o4_006E4310_0x6e4310.cpp) | `select_dnas_status_or_connection_request_path_and_copy_to_output` | Confirmed complete recovered control/data flow; original symbol unknown | Inputs selector a0/output a1. Selects one of twenty embedded literal paths from signed status7616E8 and context761638, with normal connection selection using6E05A8(4). Copies the selected NUL-terminated path, optionally appends a two-digit hexadecimal status suffix, restores protection, overwrites two four-byte pointer/flag scratch areas through74AA20 scaling, returns output strlen. Full path table and status side effects below. |
| [o4 0x6E4CF8](../recomp/config/output_ovl/o4/o4_006E4CF8_0x6e4cf8.cpp) | `build_http10_post_header_with_selected_dnas_path_and_decimal_content_length` | Confirmed complete recovered string construction | Inputs path selector a0/body length a1/output a2. Writes POST /, calls6E4310 to append path, then writes HTTP/1.0 request line, User-Agent, Content-Type and Content-Length literals. Formats original a1 using owned %d%s and CRLF, then appends another CRLF. Returns final cursor-output, excluding NUL. Two protected islands belong to this one owner. No output capacity argument/check or request-body copy appears here. |
| [o4 0x6E5FE8](../recomp/config/output_ovl/o4/o4_006E5FE8_0x6e5fe8.cpp) | `match_literal_from_registered_byte_reader_with_optional_preloaded_first_byte` | Confirmed complete recovered matcher mechanics | Inputs destination cursor a0/NUL-terminated expected literal a1/preloaded-first-byte flag a2/shared consumed-count pointer a3. Optionally compares the already-read first byte; otherwise callback7616CC(cursor,1) supplies each byte, bracketed by114640/114670 using761680. Requires callback return1, propagates negative result, returns-107 for another nonnegative result and-106 when signed count+1 is not below1025. On mismatch returns matched prefix length; on full match returns advanced cursor-start. Overwrites four-byte cursor scratch before actual restore. |
| [o4 0x6E6260](../recomp/config/output_ovl/o4/o4_006E6260_0x6e6260.cpp) | `read_character_set_span_through_registered_byte_reader_and_return_first_outside_cursor` | Confirmed complete recovered character-set scan | Inputs destination cursor a0/NUL-terminated accepted-character set a1/consumed-count pointer a2. Reads one byte through the same callback and114640/114670 sequence. Scans the character set from its start for each byte; a match advances cursor and repeats, an absent byte or empty set returns current cursor. Negative callback propagates, signed count limit returns-106. Unlike6E5FE8, every nonnegative callback result increments count by one without checking for exactly1. Overwrites four-byte cursor scratch, then restores protection. |
| [o4 0x6E64E0](../recomp/config/output_ovl/o4/o4_006E64E0_0x6e64e0.cpp) | `read_http10_ok_header_find_content_length_and_return_body_offset` | Confirmed complete recovered parser mechanics; malformed-input behavior retained | Inputs destination/read-buffer a0/content-length output pointer a1. Three protected islands materialize expected HTTP/1.0 200 OK CRLF, Content-Length: and doubled CRLF strings; clear code calls the two readers above to match the status line, search the length header, span decimal digits, parse signed64 base10 and truncate to signed32. Stores length before checking only its upper bound8033. Searches for CRLFCRLF and returns first-body cursor-start. Negative reader errors or header mismatch propagate/return-106 as detailed below. No lower-bound, buffer-capacity or parser-cursor validation is added by this mapping. |

The status/path selector uses the literal spelling **debug_fermat**, not a corrected English spelling. Let G=750FB0. The status word is G+10738=7616E8. Status branches:

| Status | Selected literal suffix after debug_fermat/ |
| --- | --- |
| -101 | ng/busy |
| -102 | ng/before_dnas_service |
| -103 | ng/after_dnas_service |
| -104 | ng/dnas_service_finished |
| -105 | ng/timeout |
| -106, -107 | ng/busy |
| -108 | ng/external_error |
| -109 | ng/different_hdd |
| -110 | ng/all_ok |
| -201 | down_result/not_exist |
| -202 | down_result/before_service |
| -203 | down_result/service_finished |
| -204 | down_result/not_modified |
| -701 | id_result/not_registered |
| -702 | id_result/invalid_category |
| -703 | id_result/not_join_in_this_category |

The download paths require `(LD(761638)&3F00)==2200`; the ID paths require `(LD(761638)&3800)==0800`. Failure of these context conditions chooses a normal connection path without clearing status. For the generic fallback, a status below-805 other than-896 selects debug_fermat/ng/unknown_ng/ and appends `sprintf(out+strlen(out), "%02x", -800-status)` using owned format77C100. Other unhandled statuses, including-896, clear7616E8 to zero and choose a normal path. Normal selection: a0 nonzero ->us-gw/v2.5_others; a0zero and6E05A8(4)==0 ->us-gw/v2.5_i-connect; otherwise us-gw/v2.5_d-connect. The role of6E05A8's numeric selector remains delegated.

The full request text is constructed sequentially, with each string copy followed by strlen to advance its cursor:

```text
POST /<selected-path> HTTP/1.0\r\n
User-Agent: open sesame asdfjkl\r\n
Content-Type: image/gif\r\n
Content-Length: <signed decimal original a1>\r\n
\r\n
```

Original a0 is a selector forwarded to6E4310, not an input URL pointer. If that delegated call yields a negative signed result,6E4CF8 returns it through its clear epilogue before decoding the second island or running the normal scratch overwrites. Normal completion overwrites SP10[4],SP0[16],SP14[4] after the second restore. These local deterministic LCG overwrites are not described as secure erasure.

Reader details matter for later reconstruction.114640 and114670 are presently labelled SignalSema/PollSema wrappers in the resident index; this note preserves the actual call order and does **not** silently reinterpret it as WaitSema/SignalSema locking. Their return values are ignored. The callback address7616CC and handle761680 are read from writable session context. The shared counter limit uses signed32 ADDIU/SLTI, not a host size_t safety proof.6E5FE8 does not pre-check an empty expected string before attempting its read; a nonzero preloaded flag consumes the existing first character without increasing the callback count.6E6260 does not append a NUL byte; it leaves the first outside character already stored at its returned cursor.

6E64E0 starts its shared counter at SP100=0. Its first matcher must return at least the expected status-line length; zero/partial match returns-106, negative propagates. It searches Content-Length by retrying the literal matcher; zero matches advance cursor by one, positive partial matches advance by the matching length, and the already-read mismatch byte can be reused as the next starting byte. The digit set is owned77C140="0123456789". The returned digit-end cursor is saved without a negative-result guard, then10CB18 parses from the original digit-start with null end pointer and base10. The result is sign-truncated to32bits and stored to caller length output even when above8033; that upper-bound failure returns-106. Negative lengths have no explicit rejection. The parser then searches doubled CRLF with the same retry/preloaded-byte mechanics. Its success cleanup overwrites SP0[256] and then the first four bytes of that same buffer again; SP100 is **not** the second wipe target. Earlier failure branches skip those normal completion wipes. These are static observations, not demonstrated crashes or network failures.

Full owner envelopes, through return delay slots:6E4310..6E4CF4,6E4CF8..6E525C,6E5FE8..6E6260,6E6260..6E64E0,6E64E0..6E6A40. Embedded NUL-terminated literals are skipped by their original unconditional branches and receive no function credit. Protected islands inside one envelope are not separate functions.

Reproduce with `python tools/function_index/recover_dnas_primary_inventory.py`, then `python tools/function_index/review_dnas_primary_middle.py`. The [repository checker](../tools/function_index/review_dnas_primary_middle.py) independently reads the keyed exception metadata, redoes the byte-exact inverse/restore round trips and checks the actual clear call arguments, including reordered loads/interleaved independent setup. Its regenerated [receipt](../build-function-index/dnas-primary-middle-review/receipt.json) retains every candidate word, original/candidate owner and payload hashes, skipped strings and direct branch targets; [word listing](../build-function-index/dnas-primary-middle-review/words.txt) labels skipped data. This static checking does not execute a recovered instruction or validate arbitrary runtime inputs. Companion reviews cover [packed prefixes](SYMBOLS_NETDNAS_RECOVERED_PACKED_REPLY_PREFIX.md) and [reply status dispatch](SYMBOLS_NETDNAS_RECOVERED_PRIMARY_REPLY_STATUS_DISPATCH.md).

Retained candidate identities (span ends exclusive; counts decimal). Each restore-call address was checked against actual descriptor argument loads; a verified call binding does not mean every path reaches it.

| Payload | Words / preserved exceptions | Restore call | Candidate SHA-256 |
| --- | ---: | --- | --- |
|6E43A0..6E4B78|502/61|6E4BD4|`3043c34e52a050bac00fafad07c49f0e79a5e17106cfa8e6df87e8c4999383f7`|
|6E4D8C..6E4DD0|17/4|6E4E18|`e78fb4404b485effdd84d355c0225be189d54a77e884ab46932a1bc466180623`|
|6E4E9C..6E505C|112/25|6E50B8|`3ca02f33319059b3d778a1026a042d0fe2adfb3ac80363e5945ee2984d878f3f`|
|6E6088..6E61DC|85/5|6E6224|`748ad97f6c96418f3e80bd37121226f3a1e139353c3f0c3db6b5c170a31adfcc`|
|6E62F0..6E6464|93/5|6E64AC|`164d34b5677875a9cb548881232558c79e64fc7545a9e34e07e34f72add18a3b`|
|6E6578..6E65C4|19/4|6E660C|`6df48d76f0b7ced02f2d8093394e3f151101bef6ea63d52e59a182ebce98cfd8`|
|6E66AC..6E66F8|19/4|6E6740|`c7df75e2675db8a039fa6cd7ef71dc572264a1dc81210d5ac7f3afb57a10eda5`|
|6E682C..6E6884|22/6|6E68CC|`b26274d9e7365b2c3286312438456aa3b33eae78fbf32b10029a80d4078bdf81`|

Original generated-source word audit: 5 role rows, 244 verified words, 11 omitted zero padding words, zero conflicts and zero omitted nonzero words. This is separate from the joined recovered-owner review.
