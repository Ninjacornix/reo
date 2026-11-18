# Network DNAS: odd parity, weak patterns and DES-shaped key setup

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request, live-memory read or target key operation occurred.

Five complete clear bodies were independently read, including full16-round entry/termination control. Static odd-parity mapping, sixteen key patterns and28-bit rotating half/table schedule support the **DES-shaped key setup** family. Proposed roles do not establish original symbol names, known-answer vectors, cryptographic security or runtime use. Provider-global getter6FD668 is independently mapped in [method factories](SYMBOLS_NETDNAS_METHOD_FACTORIES.md). No timing or gameplay slowdown finding follows.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x724AB8](../recomp/config/output_ovl/o4/o4_00724AB8_0x724ab8.cpp) | `set_odd_parity_in_eight_key_bytes_via_complete_lookup_table` | Confirmed byte/table/control flow; DES equivalence partial | Loops exactly eight bytes, replacing each byte with table780390[input]. Full256 entries read and verified against odd-parity mapping below; preserves upper seven bits and sets low bit. No key security or buffer admission check. |
| [o4 0x724AF0](../recomp/config/output_ovl/o4/o4_00724AF0_0x724af0.cpp) | `test_odd_parity_in_all_eight_key_bytes` | Confirmed byte/table/control flow; DES equivalence partial | Compares each of eight input bytes to780390 mapping; first mismatch0, all equal1. Initial body runs at byte0; branch delay increments index before terminal check. No mutation. |
| [o4 0x724B38](../recomp/config/output_ovl/o4/o4_00724B38_0x724b38.cpp) | `test_eight_byte_key_against_sixteen_weak_key_patterns` | Confirmed byte/table/control flow; DES equivalence partial | Compares eight bytes through107A18 against sixteen consecutive patterns765810..765890, first equality1 else0. No parity normalization before comparison; full table below. DES weak/semiweak interpretation follows parity, patterns and connected schedule, not test-vector proof. |
| [o4 0x724BA8](../recomp/config/output_ovl/o4/o4_00724BA8_0x724ba8.cpp) | `expand_eight_byte_key_to_sixteen_des_style_round_subkey_pairs` | Confirmed byte/table/control flow; DES equivalence partial | Provider-global6FD668()->1C enables parity test724AF0 (-1 on failure) then weak-pattern test724B38 (-2 on match); disabled skips both. Packs eight bytes as two little-endian words, applies fixed swaps/masks to28-bit halves. Each of16 rounds rotates halves by1 or2 according to765890; extracts eight six-bit indices into eight64xu64 tables77F390..780390, combines/permutates and writes two masked32-bit values in u64 slots at output+16*round/+8. Starts round countdown15 and decrements after body, BGEZ admits exactly16 rounds. Success0; full table invariants below. Exact DES standard equivalence, vectors, security, pointer capacity and current check flag remain partial. |
| [o4 0x724F90](../recomp/config/output_ovl/o4/o4_00724F90_0x724f90.cpp) | `forward_to_des_style_round_key_expansion` | Confirmed byte/table/control flow; DES equivalence partial | Calls724BA8 with unchanged arguments and returns its status. No distinct validation or transformation. |

## Complete owned tables

Odd-parity table: 780390..780490, 256 bytes, SHA-256 `ba347f0da6d742f7fdcc4710305b97ea02ab6ff39d89fb93be853b03a82757ff`.

All256 entries independently checked: `table[i]=(i&0xFE)|((popcount(i&0xFE)+1)&1)`. This finite identity covers the complete table, including paired even/odd inputs.

Sixteen eight-byte weak-key patterns: 765810..765890, 128 bytes, SHA-256 `1bca82a07c85d0987ba52d64109d69ec5a26e3075fe48798105662ee47093094`.

```text
765810: 0101010101010101
765818: fefefefefefefefe
765820: 1f1f1f1f0e0e0e0e
765828: e0e0e0e0f1f1f1f1
765830: 01fe01fe01fe01fe
765838: fe01fe01fe01fe01
765840: 1fe01fe00ef10ef1
765848: e01fe01ff10ef10e
765850: 01e001e001f101f1
765858: e001e001f101f101
765860: 1ffe1ffe0efe0efe
765868: fe1ffe1ffe0efe0e
765870: 011f011f010e010e
765878: 1f011f010e010e01
765880: e0fee0fef1fef1fe
765888: fee0fee0fef1fef1
```

Round rotation selector: 765890..7658D0, 64 bytes, SHA-256 `791b133a2ef1cc2f06dd89cb3824a247ba86e6eb38c678dfdeecc3d9d6161b07`.

```text
0 0 1 1 1 1 1 1 0 1 1 1 1 1 1 0
```

Zero means one-bit rotation; nonzero means two-bit rotation.

Eight six-bit permutation tables: 77F390..780390, 4096 bytes, SHA-256 `75ba70231caca860a98abc4d15f5f2223e08177228d3ecee63da62790901cfef`.

All512 u64 entries read; each upper32 bits zero. In each64-entry table, entry0=0 and six basis entries are pairwise bit-disjoint. Every entry equals OR (equivalently sum) of the basis for set bits of its six-bit index; checked for every entry. The six bases below therefore specify every table value exactly, without assuming a cryptographic standard.

```text
77F390: 00000010 20000000 00010000 00000800 00000020 00080000
77F590: 02000000 00002000 00200000 00000004 00000400 10000000
77F790: 00000001 00040000 01000000 00000002 00000200 08000000
77F990: 00100000 00000100 00000008 00001000 04000000 00020000
77FB90: 10000000 00010000 00000004 20000000 00100000 00001000
77FD90: 08000000 00000008 00000400 00020000 00000001 02000000
77FF90: 00000100 00080000 01000000 00000010 00200000 00000200
780190: 04000000 00040000 00000002 00002000 00000020 00000800
```

No encoded payload was decoded, and no table boundary is promoted to a function entry. Block encryption/decryption routines remain their own review boundaries.

Owned provider-global flag761A9C (761A80+1C) initial bytes `00 00 00 00`: the shipped initial state disables these optional parity/weak-pattern checks. This does not establish current runtime flag value or what callers validate elsewhere.

The independently reviewed [sixteen-round block core](SYMBOLS_NETDNAS_DES_BLOCK_CORE.md) now closes the schedule consumer and complete eight substitution-table ranges. This strengthens the DES-shaped family interpretation without adding vectors/security/runtime claims.
