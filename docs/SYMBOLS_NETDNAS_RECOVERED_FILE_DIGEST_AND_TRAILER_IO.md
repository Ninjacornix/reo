# Recovered fixed-block file digest fold and trailer I/O

Static File #1 US, 2026-11-05. Owned o4/runtime5/base6E0000,
SHA-256 `8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16`.
Two full logical bodies were read through their clear envelopes,215 reconstructed
words and restore/return paths. The [copied-data inventory](STATIC_DNAS_UPPER_RECOVERY_INVENTORY.md)
retains exact original-byte restores using actual metadata/exception lists.
No files were opened through the guest, and no game, network, runtime, build,
attachment or owned/generated-input mutation occurred.

| Guest entry / original source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x74F960](../recomp/config/output_ovl/o4/o4_0074F960_0x74f960.cpp) | `xor_twenty_byte_digests_of_exact_256_byte_file_blocks_and_zero_padded_tail` | Confirmed complete reconstructed I/O/digest/control flow; exact digest standard inherited | Args path,requestedByteCount,out20. Zeroes caller20 bytes and local20 before open118A70(path,1). For admitted nonnegative signed32 counts, reads floor(count/256) exact256-byte blocks, invokes74C6C8 on each256 bytes, XORs each20-byte digest into caller output. Positive remainder is read exactly into zeroed256 scratch, then the FULL256 padded bytes are digested/folded. Close success returns0; open/read/close error-1, partial fold retained. Always overwrites256+20 scratch bytes through localLCG. Handle still nonnegative is closed after cleanup, including retry after an earlier close error; cleanup close result ignored. No standard streaming-hash identity. |
| [o4 0x74FF00](../recomp/config/output_ovl/o4/o4_0074FF00_0x74ff00.cpp) | `read_exact_thirty_two_and_128_byte_file_trailer_parts_with_close_cleanup` | Confirmed complete reconstructed I/O and error flow; file/provider admission partial | Args path,out32,out128. Queries length via74F818; negative result fails. Opens path again with flags1; seeks length-160/start and reads exactly32 to out32, seeks length-128/start and reads exactly128 to out128. Each seek requires only nonnegative result, not exact returned offset. Successful close maps0 and clears local fd to-1. Any other failure returns-1, closing an admitted handle; a negative first close can cause another close. No minimum160 file length, stable-file identity, output capacity or rollback admission. |

The [resident file RPC](SYMBOLS_FILE_RPC.md) establishes the actual open/read/
seek/close adapters. The [length helper](SYMBOLS_NETDNAS_RECOVERED_PREFIX_DIGEST_AND_FILE_SIZE.md)
itself opens/seeks/closes, so the trailer reader performs a subsequent open.
These static call relationships do not prove that a file remained unchanged
between those operations or that a particular filesystem/device was used.

## Digest fold, remainder and failure details

74F960 sets all20 caller output bytes to zero before attempting open, even on
an open-failure path. Its full-block loop tests the block count before reading.
For ordinary nonnegative signed32 values the count is requestedBytes>>8.
Each successful read must return exactly256; otherwise it joins cleanup with-1.
The digest helper's status is not used because it does not provide a normalized
success result. The output accumulates XORs of independently computed20-byte
digest values, not a continued digest state or a hash of concatenated hashes.

When a positive remainder exists, all256 scratch bytes are cleared first.
Only the remainder is read, but the helper is called with count256. Therefore
the final contribution includes zero padding to256 bytes. There is no extra
contribution for an exact multiple of256, and zero requested bytes return the
all-zero output if open and close succeed.

The original signed quotient uses `(count<0 ? count+255 : count)` followed by
arithmetic right shift8; subtraction recovers its remainder. For ordinary
negative signed32 inputs the loops perform no file reads and a successful
open/close also leaves output zero with result0. This is a literal boundary
contract, not an invented negative-count rejection.32-bit guest counter/address
operations and wider register admission are not translated to unrestricted host
size types.

Successful close marks the local descriptor-1 before the overwrite loops.
On a negative close it keeps the descriptor and result-1, performs276 scaled-LCG
scratch stores, then tries close again. A read error also retains any digest
fold already published. No failure-path output rollback exists. The original
code restore runs after that cleanup. The local-LCG overwrite uses the same
reviewed float/CVT.W.S sequence; it proves neither secure erasure nor a measured
cost. Exact digest-standard parity remains limited by the separately recorded
[padding/compression contract](SYMBOLS_NETDNAS_UPPER_DIGEST_AND_PADDED_OPERATION.md).

## Trailer reader and connected validation

74FF00's first32 output bytes remain written if the later seek/read/close
fails. The second output may also be partially modified by a short read.
Offsets length-160 and length-128 are the original32-bit ADDIU operations;
no minimum-length guard or overflow repair is introduced here. Read response
counts must equal32/128, while seek responses need only be nonnegative.

The connected [trailer/digest/length check](SYMBOLS_NETDNAS_RECOVERED_FILE_TRAILER_CAPTURE_AND_LENGTH_CHECK.md)
uses these raw bytes after the
[in-place32-byte provider operation](SYMBOLS_NETDNAS_RECOVERED_RECORD_BUILDER_AND_IN_PLACE_BLOCK.md).
This connects the call graph without calling the file trailer a verified
signature format, identifying an original API, or asserting successful runtime I/O.

| Reconstructed payload, end exclusive | Words | SHA-256 |
| --- | ---: | --- |
| 74F9FC..74FCAC | 172 | `e8c1016a434d6bf66ab64ea344197c7e876b6cc25f274bf65d87bff13ed5367c` |
| 74FF94..750040 | 43 | `f30cc921b99f62f649d3e0cce63a1849c217ba13e6d02c640ce55d4ce63023c7` |

Reproduce copied words, exceptions and schedules with
`python tools/function_index/recover_dnas_upper_inventory.py`. Source-prefix
audits remain distinct from joined-body review; interior fragments/skipped
metadata receive no function credit. Pointer/alias admission, remote I/O effects,
code-cache/thread behavior and active-build reachability remain unverified.
No native replacement, slowdown diagnosis or controlled fix/retest is claimed.

The [portable connected-word checker](../tools/function_index/review_dnas_upper_root.py) rebuilds the full admitted word listing, original joined-interval hashes and bounded branch targets; inline data is excluded from instruction decoding. Its private receipt is data evidence, not a guest execution or semantic-equivalence test.
