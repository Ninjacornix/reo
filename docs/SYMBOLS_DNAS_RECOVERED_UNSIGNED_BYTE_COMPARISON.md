# DNAS: recovered bounded unsigned-byte comparison

Static File #1 US review, 2026-11-05. The existing `o5:0x702EF0` partial entry can now be refined to **complete local static mechanics**: it compares unsigned bytes lexicographically, returning exactly -1, 0 or +1, between its original decode/restore operations. This refines one existing owner annotation. It adds no function identity or independent role for the catalogue fragment `0x702F7C`.

The protected bytes were reconstructed by pure offline byte arithmetic and restored byte-for-byte, as documented in [the single-interval proof](STATIC_DNAS_O5_SINGLE_INTERVAL_ROUNDTRIP.md). No recovered instructions were executed or emulated, and no runtime/generated source was changed. The original exported name and live use remain unknown.

## Complete ownership and evidence

The connected original owner occupies `[0x702EF0,0x703028)`, 312 bytes /78 words, in owned `o5.bin`, SHA-256 `97174f5d367cd90bedd5ba397c6492e9fb4bbd0ec7d6021c2be524c49925d38e`. The original catalogue interval at `0x702EF0` ends at `0x702F78`; that partition cuts the protected payload and is not the complete logical function boundary. The independently reviewed clear epilogue ends at `0x703028`, where the next separately catalogued entry begins.

| Connected region | Role |
| --- | --- |
| `702EF0..702F48` | Clear prologue, descriptor check, conditional decode call and branch delay slots |
| `702F48..702F60` | Bytes skipped by the entry branch |
| `702F60..702F74` | Decode descriptor data |
| `702F74..702FB8` | All17 reconstructed comparison instructions |
| `702FB8..702FC0` | Clear unconditional branch and NOP delay slot |
| `702FC0..702FD8` | Bytes skipped by that branch |
| `702FD8..702FE8` | Restore metadata and unused zero word |
| `702FE8..703028` | Clear paired restore call, result transfer, register restore and return |

The [repository full-owner evidence helper](../tools/function_index/review_dnas_o5_byte_compare.py) saves all78 owned/candidate word pairs, region classifications, static branch-target checks and hashes. It uses the output of [the repository byte-transform helper](../tools/function_index/recover_dnas_o5_byte_compare.py). Scratch [owner proof](../build-function-index/dnas-offline-o5-702f74/owner-evidence/owner-proof.json) and [word listing](../build-function-index/dnas-offline-o5-702f74/owner-evidence/all-owner-words.tsv) are conveniences; the repository helpers, hashes, metadata and all17 payload words in the methodology note preserve reproduction after scratch cleanup.

Original/restored whole-owner SHA-256 is `4d1db7da74eba612e26a675a126e0a28253fc8a9a271686e249ce5bebd417c48`. Candidate owner, including the active descriptor self-pointer, is `2de21e5225d5060736f7ed752cc6cbada6a66c2eafb66a74ea9ffa47ced1d3c9`. Candidate payload is `e507066b82b2fdcae2e125652cd50fee53febe455dcd130cdb380c25b1544da9`. The whole312-byte owner also round-trips exactly; no extra protected island lies on its reviewed instruction paths.

The independently recovered o4 comparison payloads at749584 and74E22C in [the separate o4 review](SYMBOLS_NETDNAS_THREE_ZERO_KEY_RECOVERED_LOCAL_ROLES.md) have the identical17-word candidate hash. This confirms byte identity across those payload copies; their enclosing owners and literal metadata remain separately reviewed.

## Static comparison contract

The prologue saves original `a0` in `s3` (first byte source), original `a1` in `s2` (second source), and original `a2` in `s1` (count register). It preserves caller `s0..s3` and `ra` in a30hex-byte frame. If descriptor word `702F60` is zero, it requests the independently validated decode; otherwise it enters the already-marked candidate region. No source-pointer or readable-extent validation occurs locally.

`702F74` tests the saved count against zero before any source byte read. Its delay slot clears index `a1`; zero count branches to `702FB4`, which sets result `s0=0`.

For nonzero count, the loop forms first-source and second-source addresses using `ADDU`, loads each byte with `LBU`, increments the index with `ADDIU`, and computes both unsigned byte orderings with `SLTU`. It compares the first source's byte against the second source's byte:

| Condition | Branch and mandatory delay-slot result | Return after common restore |
| --- | --- | --- |
| first byte < second byte | `702F9C ->702FB8`; delay `702FA0` sets `s0=-1` | -1 |
| first byte > second byte | First branch falls through; `702FA4 ->702FB8`; delay `702FA8` sets `s0=1` | +1 |
| bytes equal and index still below saved count | `702FAC ->702F80`; delay `702FB0` forms the next first-source pointer | Continue |
| bytes equal and count exhausted | Loop falls through to `702FB4`, sets `s0=0` | 0 |

The loop branch targets `702F80`, not `702F7C`: the first-source pointer is prepared in the backedge's delay slot. Both mismatch branches execute their result-setting delay slots. Ignoring those slots changes the sign or loop dataflow. NUL bytes do not terminate the comparison; the explicit count and first difference determine progress.

Every comparison exit reaches `702FB8`, then the clear branch to `702FE8`. The restore call at `703000` uses the actual paired selector/order described in the byte proof and clears the original descriptor flag. `703008` copies saved comparison result `s0` to `v0`; the epilogue restores caller registers and returns. Thus the wrapper does not return the transform helper's status in place of the comparison result.

## Width and admission limits

This is not unrestricted host `memcmp(size_t)` equivalence. `DADDU` preserves the saved count register; index increment uses32-bit `ADDIU` with sign extension, the continuation test uses register-width unsigned `SLTU`, and source address formation uses32-bit `ADDU` wrapping. For ordinary nonnegative counts through `0x7FFFFFFF`, with appropriately readable sources and address admission, the comparison has the bounded lexicographic behavior above. Larger, negative/sign-extended, or otherwise malformed count registers retain the literal guest-width behavior; no local guard normalizes them into a host unsigned length.

The role is therefore `compare_unsigned_bytes_lexicographically_with_dnas_decode_restore`, with complete static mechanics and the stated caller preconditions. It does not establish the original API spelling, safe native replacement for all inputs, thread-safe self-transformation, network authentication behavior, runtime cost or a gameplay fix.

The primary annotation remains in [protected entry notes](SYMBOLS_DNAS_PROTECTED_ENTRIES.md), refined using this evidence rather than duplicated here. The old19 residual fragment identities remain catalogue partitions; reconstructing their owner's bytes does not make them19 independent functions.
