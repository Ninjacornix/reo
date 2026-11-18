# Offline recovery of a protected two-bit field query

Static File #1 US review, 2026-11-05. Owned o4 `netdnas.bin`, runtime ID5,
base6E0000, SHA-256 `8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16`.
One bounded protected span was reconstructed **as data**, then reviewed together
with the entire original clear entrance, branch and epilogue. No recovered
instructions were executed. No game, build, network, process attachment or
runtime modification occurred. Owned input and generated source are unchanged.

| Guest entry / original source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x74E728](../recomp/config/output_ovl/o4/o4_0074E728_0x74e728.cpp) | `read_netdnas_context_fca0_low_two_bits_and_accept_values_zero_or_one` | Confirmed bounded offline reconstruction and complete static control flow; field meaning unresolved | Original entrance saves a0/a1 in S1/S2 and initializes resultS0=-1. Descriptor74E794 guards inverse transform of exactly74E7A8..74E7C4, with no exception list. Recovered seven words read unsignedbyte(context+FCA0), mask3, always store byte to originala1, and change result to0 iff maskedvalue<2. Clear branch skips restore metadata to74E7F4, which applies actual paired forward schedule, then returnsS0 while restoring saved registers/SP. No context/output null or length guard; pointer/field meaning and runtime admission remain unresolved. The decoded block is not seven independent catalogue functions. |

The generated C++ still contains the original encoded words at this address.
The proposed role refers to the reconstructed original operation; it does not
claim that a current native build executes this operation correctly. No indexed
direct caller was found. Indirect use and online-library reachability are unknown.

## Exact original metadata and reconstruction

The [clear dispatcher](SYMBOLS_NETDNAS_PROTECTED_DISPATCH.md) supplies direction,
range, exception and cache-publication semantics. The reviewed
[word primitives](SYMBOLS_O4_WORD_TRANSFORMS.md) supply the arithmetic.
Addresses and words below are hexadecimal; the payload contains7 words/28 bytes.

| Evidence | Owned value |
| --- | --- |
| Complete original catalogue interval | 74E728..74E830, 264bytes, SHA-256 `34910085462d8266838fb3f08eb595e2bc3ca27282d520ddca1f5af58add56df` |
| Entry descriptor at74E794 | `00000000 5DB33B87 00000000 5DB33B9B 00000000` |
| Entry call at74E76C | anchor74E7A8, span=5DB33B87 XOR5DB33B9B=1C, mode0/key0 |
| Entry operation | Inverse table, normalized low-to-high slots7,0,3,3,3 |
| Restore metadata at74E7E4 | `5DB78B33 00000001 5DB78B2F 00000000` |
| Restore call at74E80C | anchor74E7C4, same span1C, mode1/key0 |
| Restore operation | Forward table, actual normalized slots3,3,3,0,7 |
| Original payload SHA-256 | `333d28887795a61690c2765fb8dc48754a54a4396263aeaf7dff3ab46110a216` |
| Reconstructed payload SHA-256 | `f74cfcb674d483ad4ca99b5a1be0dbdfeb79b96303f3bdfd8de4185ab2e57faf` |
| Actual restore result | All28 bytes exactly equal the original payload; original whole image hash unchanged |

For inverse slot7, first XOR09F8ED17, rotate right8 then13, then apply byte
permutationQ=[b2,b0,b3,b1] (least significant byte first). Slot0 XORs09F8ED17;
slot3 rotates right8. Restore slot3 rotates left8; slot7 applies permutationP,
rotates left13 then8, then XORs09F8ED17. The restore order is read from its own
metadata, rather than chosen merely to invert a proposed decode.

The whole catalogue interval's61 generated instruction comments match original
owned words; its5 omitted aligned words are zero. Encoded comments remain
evidence of original bytes, not decoded instruction semantics. The clear
74E774 branch skips the preceding opaque/descriptor bytes; the recovered block
falls to74E7C4, whose branch skips the next opaque/restore metadata region.
Those skipped bytes receive no additional function-role credit.
The existing static graph still comes from the original generated source;
apparent edges decoded from encoded/skipped words are not validated call evidence.
This notebook does not silently replace that source snapshot or its graph.

## Reconstructed instructions and connected contract

| PC | Original encoded word | Reconstructed word | Static interpretation |
| --- | --- | --- | --- |
| 74E7A8 | 14006FF6 | 3C020001 | lui v0,1 |
| 74E7AC | 1E67EDF2 | 00511021 | addu v0,v0,s1 |
| 74E7B0 | 3C15F062 | 9042FCA0 | lbu v0,-0x360(v0), giving original context+FCA0 with original 32-bit ADDU address formation |
| 74E7B4 | 5C01EFF6 | 30420003 | andi v0,v0,3 |
| 74E7B8 | 7C226FF6 | 2C430002 | sltiu v1,v0,2 |
| 74E7BC | 3C13AFF6 | A2420000 | sb v0,0(s2), always publishing the masked value |
| 74E7C0 | 5427FFF7 | 0003800B | movn s0,zero,v1, selecting successful result0 only for values0/1 |

The clear entrance at74E728..74E744 saves S0/S1/S2/RA, sets S0=-1,
S1=input context and S2=output pointer. At74E748..74E770 it checks descriptor
word0 and calls7457C8 only when zero. The entry dispatcher marks that descriptor
active. The clear unconditional branch74E774 enters the reconstructed block.
After the store and conditional move,74E7C4 branches to74E7F4;74E7C8 is a NOP
delay slot. The restore call uses its actual anchor74E7C4 and clears the original
entry descriptor through the reviewed mode1 path. Then74E814 copies S0 toV0,
restores the frame and returns. No assumption about the contents of skipped
metadata is needed to follow this complete admitted path.

The arithmetic can be reproduced with
`python tools/function_index/recover_dnas_example.py`. It verifies both metadata
records against the hash-bound original image, checks the three used primitive
inverse pairs on zero/all-one/single-bit words, reconstructs this copied span and
applies the **actual** opposite-mode schedule. It writes a JSON receipt to
`build-function-index/dnas-recovery-example.json`, never an executable patch.

A reversible transformation by itself is insufficient to establish correct
decoded semantics: the direction/table/order, owned metadata, complete clear
control path and independently inspected instruction decoding are also required.
This result establishes that bounded recovery is possible. It does not recover
every protected span, identify the field's original enum, validate concurrent
self-modification, prove runtime equivalence or demonstrate a slowdown fix.
An independent second static review reproduced both hashes and decoded all seven
words from the original primitive/table instructions. Pointer bounds, output
alias admission and external mutation of the payload remain unknown; an output
pointer aliasing code or descriptor storage is not covered by the isolated
round-trip receipt.
