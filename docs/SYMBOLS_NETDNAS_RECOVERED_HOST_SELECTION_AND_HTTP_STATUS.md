# Recovered initialization host selection and HTTP status parser

Static File #1 US, 2026-11-05. Owned o4/runtime5/base6E0000, SHA-256
`8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16`.
The [primary inventory](STATIC_DNAS_PRIMARY_RECOVERY_INVENTORY.md) reconstructs
these copied-data spans and reproduces their original encoded bytes. Actual
noncanonical restore bindings and full clear caller/return paths were then read
individually. Inline strings are classified as data, not instructions/functions.
No recovered instructions, game, network, build, runtime or process attachment
was used; original images and generated sources remain unchanged.

| Guest entry / original source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x6EB9C8](../recomp/config/output_ovl/o4/o4_006EB9C8_0x6eb9c8.cpp) | `parse_http_prefix_three_digit_status_and_consume_headers_through_two_crlf_pairs` | Confirmed complete reconstructed prefix and clear parser; transport admission partial | Recovered span initializes a5-byte HTTP/ prefix in stack0, branching over its inline data. Clear path restores that span, then receives one byte at a time via1D9DA0. Requires five prefix bytes, skips version text to owned ctype whitespace, reads three decimal digits into status, then for positive status consumes input until the original CR/LF counter reaches2 or an error/NUL condition. Transport errors map through6EB868; protocol mismatch gives-602. Receive result0 is not locally rejected. Always performs11 scaled-LCG cleanup stores and returns status/error. No strict whole-HTTP grammar, timeout, EOF correctness or live connection result claimed. |

## Initialization selection: refinement of an existing owner

The existing [initialization role at6E1100](SYMBOLS_NETDNAS_WORKER.md) already
covers the complete clear semaphore/thread setup and error cleanup. Its43-word
protected island6E1590..6E163C adds two inline strings and conditional host
copying, not a hidden worker or a new callable function.

The recovered first branch at6E1590 skips to6E15C0, avoiding inline bytes
6E15A0..6E15BC. Those bytes contain `gate1.us.dnas.playstation.org` plus NUL.
It materializes that string's address, then another branch at6E15CC skips the
second inline string at6E15DC, `ts01.us.dnas.playstation.org` plus NUL.
Neither string was resolved, contacted or sent anywhere during this review.

The reached block6E1600 loads signed word G+10734, where G=750FB0.
Positive values select the second string; zero/negative values select the first.
Both paths invoke10B5F8(G,selectedString,512). Its separately reviewed bounded
string-copy contract applies. This records the actual numeric condition without
inventing a geographic/protocol enum or caller meaning for10734.

The clear branch6E163C skips restore metadata to6E166C. At6E168C the actual
primary dispatcher receives anchor6E163C and metadata6E165C, including its
mode1/key and paired operands. The load ordering interleaves S0/result setup,
which is why the bulk canonical-pattern flag is false. It still calls the
paired restore on this admitted path. The remaining clear worker setup and
cleanup were read through the return delay slot at6E1908. The existing row is
refined in place; no data/interior catalogue cut gains credit.

## HTTP parser control and byte classification

The13-word island6EBA6C..6EBAA0 first branches over inline `HTTP/` bytes at
6EBA7C. Its reached instructions call10B5F8(stack0,thatString,5). Restore
metadata at6EBAC0 is explicitly bound by clear loads and call6EBAF0 to70BA68
with anchor6EBAA0. The intervening register setup initializes counters and-602;
it does not alter the metadata operands or schedule direction.

The parser stores a pointer to its one-byte receive cell atSP14. Five calls
to1D9DA0(handle,cell,1,0) compare that cell to stack0[index]. Negative receive
results read the error location through1D96E0 and map the value with6EB868.
Nonnegative results, including0, continue to byte comparison. No successful
one-byte-read guarantee is inferred merely from a nonnegative response.

Next it scans to ctype whitespace, then reads exactly three ctype decimal
digits. The owned resident table at237769 was read directly: flag8 ASCII
members are TAB/LF/VT/FF/CR/space; flag4 members are0..9. The table is indexed
by the original signed byte, so arbitrary high-byte input admission is not
rewritten as an unsigned host ctype call. Decimal accumulation is10*status+
byte-48. Invalid prefix/digit yields-602. Status<=0 skips later header scanning;
the literal three-digit000 route can therefore return0.

For positive status, the header scan saves the prior byte, reads a new byte,
counts LF preceded by CR, keeps the counter across CR and resets it for other
bytes. Two counted CR/LF endings terminate the scan. A received NUL selects
-602. This is the original counter/state behavior, not a claim of strict RFC
parsing or rejection of every malformed header. There is no local byte/time
bound on the scan; transport and caller policies remain external.

Cleanup overwrites the current byte once, previous byte once, five prefix
bytes and the4-byte receive-pointer cell through74AA20-derived scaled bytes.
The postincrement tests in the first two loops perform exactly one store each.
It preserves the parsed status/error in S1 through cleanup and restores the
integer/F20..F22 frame before returning at6EBF18. No receive, polling loop or
cleanup operation was run for this investigation.

| Reconstructed span | Word count, including inline data | SHA-256 |
| --- | ---: | --- |
| 6E1590..6E163C | 43 | `977a971b40013476605dd5a4f946b0f50e3534b57b44616505fc67e74eee709a` |
| 6EBA6C..6EBAA0 | 13 | `788b3fb7b3ad3d51dcbadcf0bf9cdf2b6776114ec3e929c86a748192aade1a0a` |

Reproduce copied-word candidates with
`python tools/function_index/recover_dnas_primary_inventory.py`. The static
generated graph remains unchanged; calls guessed from encoded/skipped string
words are not evidence. Original API identity, runtime code-cache/concurrency
admission and performance remain unverified. No native replacement or slowdown
fix is claimed.

The [portable connected-word checker](../tools/function_index/review_dnas_primary_root.py) rebuilds the full admitted word listing, original joined-interval hashes and bounded branch targets; inline data is excluded from instruction decoding. Its private receipt is data evidence, not a guest execution or semantic-equivalence test.
