# Network DNAS: expanded RC2-shaped block operations and CBC byte wrapper

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No target/cipher execution, game, build, replay, attachment, network request or live-memory read occurred.

The complete1930-instruction forward core,1796-instruction reverse core and852-instruction CBC wrapper were independently read. Their named caller [RC2 method adapters](SYMBOLS_NETDNAS_CIPHER_METHOD_ADAPTERS.md), [key expansion](SYMBOLS_NETDNAS_RC2_KEY_AND_RC4_STREAM.md), four16-bit state words, rotations, sequential64-word schedule and two indexed mixing stages establish the RC2-shaped family. This does not establish known-answer vectors, standard equivalence/security, active use or gameplay timing.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x711458](../recomp/config/output_ovl/o4/o4_00711458_0x711458.cpp) | `process_rc2_style_cbc_bytes_and_commit_eight_byte_chain` | Confirmed complete ordinary nonnegative-length full/partial/IV flow; malformed inputs and cipher equivalence partial | a0 input,a1 output,a2 byte count,a3 key schedule,t0 IV,t1 direction. Reads eight IV bytes into two low32 halves. Forward full blocks XOR chain, call7121D8 and emit eight bytes; reverse preserves original cipher, calls714000, XORs chain and emits plaintext. Initial count-minus-eight precedes first full-block test. Forward residual reads requested bytes into zero halves and emits full eight-byte cipher; reverse residual reads full eight-byte cipher and emits requested plaintext count. Commits final cipher/IV chain. Clears two-u64 scratch and temporary s0..s5 before restoring caller registers. No capacity, negative-count or overflow admission and no normalized success return. |
| [o4 0x7121D8](../recomp/config/output_ovl/o4/o4_007121D8_0x7121d8.cpp) | `apply_sixteen_forward_rc2_style_mix_rounds_and_two_mash_stages` | Confirmed complete unrolled word/rotation/key flow; mathematical equivalence partial | a0 two u64 slots,a1 schedule64 u16 words. Extracts low/high16 from low32 of each slot to four local words. Sixteen expanded mixing rounds consume schedule words0..63 in ascending order; each round uses16-bit addition, Boolean selection and left rotations1/2/3/5 for words0/1/2/3. After rounds5 and11, four additions index the same schedule by previous evolving word&63. Recombines four words to two low32 values stored as u64 slots, clearing their upper32 by construction. No calls or conditional branches: only finalJR. No schedule/input admission, normalized status or stack-word scrub; tested standard equivalence remains unknown. |
| [o4 0x714000](../recomp/config/output_ovl/o4/o4_00714000_0x714000.cpp) | `apply_reverse_rc2_style_rounds_with_reverse_indexed_unmix_stages` | Confirmed complete independent reverse word/rotation/key flow; inverse/cipher proof partial | Same two-u64 block and64-u16 schedule layout. Processes words3,2,1,0 using right rotations5/3/2/1 and subtraction of schedule words63..0 plus Boolean terms. Two reverse indexed subtraction stages undo the locally connected forward mash-stage order. Independently read complete1796-instruction body; no calls/conditional branches, only finalJR. Writes two recombined low32 u64 values; does not admit null/capacity/schedule/key validity or scrub local word workspace. Role is reverse-family operation, not a tested arbitrary-input inverse claim. |

## Expanded schedule, rounds and indexed stages

Both cores use local u16 variables at stack+A/C/E/10hex; stores enforce16-bit truncation after arithmetic/rotations. Forward has exactly16 occurrences each of left-rotation1,2,3,5, consuming fixed schedule byte offsets0,2,...,7Ehex. Reverse has16 occurrences each of complementary left shifts15,14,13,11 combined with right shifts1,2,3,5, consuming7E,7C,...,0hex. Counts are from complete expanded bodies, not a heuristic based on their instruction totals.

Forward's first indexed stage712B0C..712BB8 follows20 sequential key uses (five rounds), second713644..7136F0 follows44 (eleven rounds). Each adds a schedule word selected by the previous evolving state word&3Fhex, in state order0,1,2,3. Reverse's corresponding stages714890..71493C and715300..7153AC subtract in state order3,2,1,0; they occur after five and eleven reverse rounds respectively. Schedule data is supplied by the caller and cannot be assumed equal to a current live key schedule.

The Boolean mix terms combine adjacent state words with AND and complemented-word AND, then16-bit addition/subtraction and rotate. Their observed pattern supports family naming. No symbolic all-input inverse proof, standard test vectors, constant-time proof or security review was run. Source bulk alone does not establish an engine bottleneck, and these local operations do not count original game updates.

## CBC boundary and scratch ownership

711458 independently implements the CBC byte packing and remainder paths; it is not annotated by byte identity with the DES wrappers. The loop enters through its initial `length-8` test, so ordinary length0 performs no block call or input/output access. It still reads/writes eight IV bytes. Exact multiples have terminal counter-8 and skip the remainder. Counts1..7 after the last full block take a backward-load/store ladder via owned tables below.

For a forward partial block, output capacity must accommodate eight bytes although only the requested residual input bytes are read; missing high bytes of the block start zero. Reverse partial processing reads a complete eight-byte final cipher block but writes only the requested residual bytes. IV receives the complete original final cipher block. Full reverse blocks retain original input halves before output stores, supporting ordinary exact in-place operation; arbitrary overlap has not been proven. Application padding policy and caller allocations remain separate from these local extents.

Malformed negative/overflow counts are not checked at entry. The residual selector range check does not prevent all preceding pointer arithmetic or block work; it cannot justify a safe no-op claim outside the ordinary nonnegative domain. Final register-zeroing is followed by restoration of caller s0..s5, and clearing16 scratch bytes is not a comprehensive secret-erasure claim. The cores themselves leave their local word workspace unscrubbed. No malformed call or fault was reproduced.

## Complete owned residual dispatch data

All16 little-endian u32 entries at77E820..77E860 were read,64 bytes, combined SHA-256 `659ac921e0089aca3d284dc9d1719af5ef17dc92be75dcad3e28aa56c86a7073`. Each destination is an actual instruction in711458's independently reviewed body. These are data entries, not additional mapped functions.

| Owned range | Use | Targets, index0..7 | SHA-256 |
| --- | --- | --- | --- |
|77E820..77E840|forward residual loads|7118B4 711898 71187C 711864 71184C 711830 711814 7117FC|`295c5081cfbc30f26734c189319ae1bf316ad0c6091abc312b46a61983a2f9c7`|
|77E840..77E860|reverse residual stores|712044 712020 711FFC 711FD8 711FB8 711F94 711F70 711F4C|`1f1da99757fdf8fe6769d36814ffc2cb9d6cca4e78ac7e42b47b5ceb2491cc45`|

## Validation

Three independent rows,4578 original instruction comments. Full aligned ownership intervals and comments verified against the hashed owned image, no conflicts or omitted nonzero words. All local links and16 dispatch destinations resolve. The mapping makes no runtime correctness, performance, encryption strength or engine-fix claim.
