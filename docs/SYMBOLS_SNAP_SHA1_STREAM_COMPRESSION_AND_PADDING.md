# SNAP SHA-1 stream block, compression rounds and final padding

Static File #1 US owned ELF,2026-11-05. Complete original catalogue interval reviewed using control-flow reading plus exact binary grouping of every unrolled round/schedule sequence. [Identity](FUNCTION_INDEX.md). No digest input, guest instruction, game, network or benchmark executed. Algorithm identity is strongly established; a tested host-library replacement is not.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1EB830](../recomp/config/output/sub_001EB830_0x1eb830.cpp) | `consume_snap_sha1_stream_block_or_final_padding_and_compress_eighty_rounds` | Confirmed complete stream/padding and all80 original compression rounds | Inputs context,a1 cursor-pointer,a2 remaining-pointer,a3 finalize. Buffers up to one64-byte block in context24, updates caller cursor/count. Short nonfinal input returns1 after consuming it. Full block adds512 to low bit counter18 with carry14, resets buffered1C and reverses all16 words before compression. Final short input adds original buffered bytes*8, appends80hex once via flag20, zero-pads, stores high/low bit length at5C/60 when resulting padded count<=56, then compresses; otherwise requests a second final block. Exact80 rounds and five-word feed-forward below. Return after compression is paddedLocalCount>=57; no context/pointer/size admission. |

Context0..10 holds five state words initialized by [1EB684](SYMBOLS_SNAP_BLOCK_CIPHER_AND_DIGEST_ADAPTERS.md);14/18 high/low bit counters,1C buffered bytes,20 padding-marker flag,24..160 eighty-word schedule workspace. Partial input copies to context24+buffered. If remaining is less than64-buffered and nonzero, cursor advances by remaining,buffered grows and remaining becomes0. Nonfinal short path returns1 regardless of whether it copied zero bytes; outer feeder stops on remaining==0. Full path consumes exactly64-buffered, subtracts that amount, counts512 bits and emits one compression block. It does not add partial bytes to bit counters until a block or finalization is processed.

Finalization with no input does not dereference the supplied NULL cursor-pointer because the zero remaining copy gate skips it. It saves buffered bytes locally then clears context1C. Before padding it adds savedCount*8 to bit counter18 and carries to14. If flag20 zero, writes80hex at next byte,increments local count and sets flag1. Zeroes bytes through63. Local padded count<57 stores high/low counters as native words at context5C/60 and reverses only the first56bytes; larger count reverses64bytes without length. A requested second final call starts with buffered0 and already-set flag, so adds no length and no second80 marker. The return boolean is localCount>=57, not a general remaining-input or success status. Finalization leaves padding flag set; the public finalizer later clears only context.word0, so reuse requires the separately reviewed initializer.

For each block, working A/B/C/D/E start at context0/4/8/C/10. Rounds0..15 consume the byte-reversed first16words. Rounds16..79 append `W[t]=ROL32(W[t-3]^W[t-8]^W[t-14]^W[t-16],1)` to the workspace. Each round computes modulo32 `T=ROL32(A,5)+F(B,C,D)+E+W[t]+K`, then E=D,D=C,C=ROL32(B,30),B=A,A=T. Boolean/constant groups are:

| Rounds | F and K | Exact original template evidence |
| --- | --- | --- |
|0..15|`((C^D)&B)^D`,5A827999|37words repeated16 times,first1EBB84.|
|16..19|same F/K, newly rotated schedule word|41words repeated4times,first1EC554.|
|20..39|B^C^D,6ED9EBA1|39words repeated20times,first1EC964.|
|40..59|`(B&C)|((B|C)&D)`,8F1BBCDC|43words repeated20times,first1EDD14.|
|60..78|B^C^D,CA62C1D6|39words repeated19times,first1EF204.|
|79|same final F/K, no unused next-word pointer increment|36words,first1F0488.|

The entire4709-word core span is fully accounted for by3173 round words plus1536 schedule-setup words. Schedule setup has one36-word first sequence at1EC4C4 (initial pointers=context58/44/2C/24 for t-3/-8/-14/-16),62 exact24-word repetitions, and one12-word final sequence with no unused pointer increments. No hidden branch/call or unmatched core span remains. After round79, five original context words each add corresponding working word modulo32 before return.

Reproducible read-only [round/template audit](../tools/function_index/static_digest_round_audit.py) checks every emitted original instruction against the pinned ELF, all zero-only omitted words,80 round starts,six exact template groups and all three schedule groups. Core1EBB84..1F0518 SHA-256 `0ffd75db67c2b852e2c2a742ce462d6958a783f6aef829637762740cf61b22ac`. It reads bytes and compares structure; it does not execute or simulate guest compression, claim test-vector agreement or benchmark speed. Full catalogue body4942 verified words /19 omitted NOPs. [Public feeder/finalizer](SYMBOLS_SNAP_BLOCK_CIPHER_AND_DIGEST_ADAPTERS.md) retain their separate pointer/count and output-byte-order contracts. Static code size is not a measured cost or evidence that this networking digest caused a gameplay slowdown.
