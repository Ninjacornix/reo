# Recovered primary DNAS reply status and operation dispatch

Static File #1 US o4, 2026-11-05. Four full owners reviewed across original clear and reconstructed protected words using the [primary copied-data inventory](STATIC_DNAS_PRIMARY_RECOVERY_INVENTORY.md). Owned o4/runtime5/base6E0000 SHA-256 `8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16`. Addresses/offsets are hexadecimal; spelled byte counts decimal. No runtime, recovered instruction, network or callback was executed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x6E4148](../recomp/config/output_ovl/o4/o4_006E4148_0x6e4148.cpp) | `decode_one_reply_status_byte_and_latch_first_different_hdd_result` | Confirmed complete recovered status mechanics; labels from connected literal selector | Inputs byte source a0/status output word a1. Copies exactly one byte to local scratch, maps0->-108,1->-101,2->-102,3->-103,4->-104,5->-105,9->-110. Byte60hex first occurrence writes-109 and sets mask0001 in761668; repeated60hex and all other unmapped bytes write-800-byte. Restores protection and returns1 consumed byte. |
| [o4 0x6E6FE8](../recomp/config/output_ovl/o4/o4_006E6FE8_0x6e6fe8.cpp) | `parse_download_reply_fields_or_publish_download_status_and_require_exact_size` | Confirmed complete recovered reply mechanics | Inputs input a0/expected size a1/descriptor a2/status output a3.6E33C0 consumes/stores status761649. Nonzero status1/2/3/4 writes-201/-202/-203/-204, other nonzero leaves status output unchanged; all bypass ordinary descriptor parsing. Zero status invokes6E3790 six-byte descriptor field,6E3898 indirect BE32 length and6E3A00 payload copy. Negative length-parser result propagates; otherwise returns total consumed iff exactly expected size, else-106. |
| [o4 0x6E71B0](../recomp/config/output_ovl/o4/o4_006E71B0_0x6e71b0.cpp) | `parse_id_reply_mode_and_payload_or_publish_id_status_and_require_exact_size` | Confirmed complete recovered reply mechanics | Inputs input a0/expected size a1/descriptor a2/status output a3.6E3D08 consumes/stores mode/status76164A. Values2/3/4 write-701/-702/-703; larger values leave status output unchanged and skip ordinary body. Values0/1 store descriptor+C=1/2 then call6E3EC8 indirect BE32 length and6E4030 payload copy. Negative length-parser result propagates; otherwise exact total-size comparison returns total or-106. |
| [o4 0x6E74D0](../recomp/config/output_ovl/o4/o4_006E74D0_0x6e74d0.cpp) | `validate_session_reply_prefix_and_dispatch_operation_or_status_body` | Confirmed complete recovered dispatch including early restore-bypass exits | Inputs operation a0/whole size a1/descriptor a2/prefix boolean a3/status output t0. Reads reply pointer761654, calls6E6D80 to validate40-byte prefix/extract body length/status marker, requires remaining size equal parsed body length. Marker>0 preserves selected preexisting global errors via direct epilogue branches, otherwise delegates one-byte6E7490 status body; ordinary marker uses owned nine-slot operation table. Returns total consumed or propagated negative/-106. Full table and bypass paths below. |

6E4148's local copy is a one-iteration loop: index starts0, increments to1, and only repeats if it equals zero. Its output for unknown bytes is signed32 `-800-LBU(input)`, including repeated96decimal ->-896. The special first96 path branches past the generic subtraction/store after publishing-109, sets mask0001 in761668, and then follows common restore. This is the same mask cleared by the already-reviewed6E6ED8 context-update reply. The different_hdd label is connected to6E4310's original literal, not an independent hardware diagnosis. There is no reported live HDD error or slowdown here.

For6E6FE8, six-byte fields and indirect length/payload details are established by the connected [primary field adapters](SYMBOLS_NETDNAS_PRIMARY_RECOVERED_DESCRIPTOR_LENGTHS_AND_PAYLOADS.md): descriptor+10 is length pointer,+C payload pointer; for6E71B0 the corresponding fields are+8/+4, with direct mode word+C. These are consumer-local contracts, not complete application types. Both routines can publish a status or mutate descriptor memory before final size validation. They do not rollback writes on-106. Unknown nonzero statuses still return1 if expected size1 and leave the caller error word untouched. Both status-only paths run their actual paired restores; ordinary body paths never enter those protected islands.

6E74D0 calls6E6D80(operation, originala3, &SP0, replyPointer, &SP4); negative propagates. It subtracts returned prefix size from original size, advances pointer, and compares remaining bytes with SP0; mismatch-106. If SP4>0, the recovered21-word island checks current signed status7616E8. Values-401,-403,-402,-107,-106 return unchanged through direct branches to the clear epilogue, **bypassing the paired restore**. Other values reach the actual restore6E7658, then call6E7490(bodyPointer,remaining,statusOutput), which decodes one status byte and enforces its exact size. This static bypass is preserved honestly; metadata-paired arithmetic does not prove every runtime path restores its protected span.

With SP4<=0, `(operation-5)` must be unsigned below9. Owned77C150 table contains exact targets:

| Operation | Target / delegated body |
| --- | --- |
|5|6E76A0 ->6E6E50 optional platform section|
|6|6E76B8 ->6E6ED8 fixed-tail/context update|
|7|6E76D0 ->6E6FE8 download body|
|8,9,10,11|6E7738 ->-106|
|12|6E7710 ->6E7388 one-byte status/empty-protection-marker body|
|13|6E76F0 ->6E71B0 ID body|

Any negative delegated result propagates after the original cursor advance in its branch delay slot; nonnegative result adds to current cursor and returns cursor minus current761654. The function reloads that global base at completion, not a guaranteed immutable snapshot. Clear caller6E7778 owns receive/cleanup; this routine does not itself receive from the network.

Full envelopes through return delay slots:6E4148..6E4310,6E6FE8..6E71B0,6E71B0..6E7388,6E74D0..6E7778. Payload/actual restore pairs:6E41C0..6E42A8 ->6E42F0;6E709C..6E70F0 ->6E7138;6E7268..6E72AC ->6E72F4;6E75BC..6E7610 ->6E7658. Descriptor/interior cuts receive no new mapping credit.

Reproduce with `python tools/function_index/recover_dnas_primary_inventory.py`, then `python tools/function_index/review_dnas_primary_middle.py`. The [repository checker](../tools/function_index/review_dnas_primary_middle.py) rechecks actual restore argument loading as well as keyed exceptions, candidate hashes and exact byte restores. Its regenerated [receipt](../build-function-index/dnas-primary-middle-review/receipt.json) retains all candidate words and whole-owner hashes; [listing](../build-function-index/dnas-primary-middle-review/words.txt) separates skipped data from reviewed instructions. Static checking does not replace the complete human review above or prove arbitrary malformed inputs safe. Connected [HTTP request/header mechanics](SYMBOLS_NETDNAS_RECOVERED_HTTP_REQUEST_AND_HEADER_PARSER.md) and [packed prefix](SYMBOLS_NETDNAS_RECOVERED_PACKED_REPLY_PREFIX.md) reviews cover the direct dependencies.

Retained candidate identities (span ends exclusive; counts decimal). Each restore-call address was checked against actual descriptor argument loads; a verified call binding does not mean every path reaches it.

| Payload | Words / preserved exceptions | Restore call | Candidate SHA-256 |
| --- | ---: | --- | --- |
|6E41C0..6E42A8|58/2|6E42F0|`ea331744f40cdaeebaa838eed58a767e91b2afa7b2b762b415a4ea5a5180ea75`|
|6E709C..6E70F0|21/0|6E7138|`bdddcd2a14355f7deb15cbc6e62d9175011f194a63703c02e60fe3b709479033`|
|6E7268..6E72AC|17/0|6E72F4|`e4deb2df9fa8138be2275f192867b6348493e9bd9df74e1f8a16357fc1344f1f`|
|6E75BC..6E7610|21/0|6E7658|`595921da6fcfe2c05092ee2f7b78489a3a3c933f198a618665e4705c71032e9d`|

Original generated-source word audit: 4 role rows, 419 verified words, 14 omitted zero padding words, zero conflicts and zero omitted nonzero words. This is separate from the joined recovered-owner review.
