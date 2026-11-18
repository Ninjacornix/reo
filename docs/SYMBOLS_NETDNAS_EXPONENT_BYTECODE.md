# Network DNAS: compact exponent run/window bytecode

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request, live-memory read or target arithmetic operation occurred.

Two complete clear bodies were independently read through limb transitions, pair emission, initial admission and terminal byte copying. These operate on [u64 magnitude storage](SYMBOLS_NETDNAS_MULTIPRECISION_STORAGE.md); their compact zero-run/odd-window structure supports an exponent-bytecode candidate. Unlike the [private u32 window format](SYMBOLS_NETDNAS_WINDOWED_POWER_AND_CRT.md), these records use bytes and a two-byte prefix. Exact evaluator equivalence, bounds, original names, cryptographic standard and runtime usage remain partial. No timing or gameplay slowdown finding follows.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x6F7C48](../recomp/config/output_ovl/o4/o4_006F7C48_0x6f7c48.cpp) | `select_or_build_compact_exponent_window_bytecode_in_current_pool_slot` | Confirmed complete selection/allocation/header flow; exponent semantics partial | Uses current scratch index0 to choose20-byte slot, without pushing index. Magnitude top0 returns0 and does not filloutpointer. One-limb literal3/11hex/10001hex returns borrowed10-byte constants77C8B0/C0/D0; otherone-limb width1,metadata1. General top*64 thresholds>=256 choosewidth5/meta16/multiplier13,>=128 width4/meta8/multiplier16,elsewidth3/meta4/multiplier22. Estimatescapacity fromtop*multiplier, optionally6F4F60 butignoresresult.6F7DD0 writes at buffer+4; stores prefix big-endian helperlength+2,width,metadata; returns helperlength+4,or10forconstants; setscallerpointer. No count/size overflow,allocation success or evaluator correctness proof. |
| [o4 0x6F7DD0](../recomp/config/output_ovl/o4/o4_006F7DD0_0x6f7dd0.cpp) | `encode_magnitude_as_zero_run_and_odd_window_byte_pairs` | Confirmed complete limb/window/run/copy flow; format-domain validity partial | Caps signedwidth at6 with no lowerbound; divides(top*64+width-1)/width, guest-breakif0, reserves backwards temporary span and00terminator. Immediatelyloads firstlimb, optionallysecond; consumes lowwidth bits and complete trailing-zero lookup. Nonzero digit emits accumulatedrun anddigit whilebuildingbackwards; zeroruns>=256 splitvia lowbyte/zero pairs. Moveslimbs whenbitoffset>=64 with guarded nextlimbload,thencompacts nonzero-leading bytepairs tooutput and writes00end; returnsbytesincludingterminator. No top>0,width>=1,outcapacity or temp-overlap admission in this directentry. Entryloads and zero-run tests, rather than callback counts, define progress. |

## Complete owned constants and lookup data

Literal3 encoding, 77C8B0..77C8BA, SHA-256 `6c1f96cf032868936b767595f68b68998d777f67ce4c5012ffb498b639576d20`:

```text
00 08 01 01 01 01 01 00 00 00
```

Literal11hex encoding, 77C8C0..77C8CA, SHA-256 `1c09bb56b442c5137053b5bed018f6f649081eacec2b381585db7372333bdd2a`:

```text
00 08 01 01 01 04 01 00 00 00
```

Literal10001hex encoding, 77C8D0..77C8DA, SHA-256 `d97554a7a8dd09a5226177f80208cab7dd1e381e496540a67078a0ff4cd08001`:

```text
00 08 01 01 01 10 01 00 00 00
```

Seven width lookup pointers, 761930..76194C, SHA-256 `139491c576e1c783f7f93e43f507302d0b6b50e5ff76846263f7614e2fc466b5`:

```text
1f c9 77 00 1e c9 77 00 1c c9 77 00 18 c9 77 00 10 c9 77 00 00 c9 77 00 e0 c8 77 00
```

Complete width-six trailing-zero table, 77C8E0..77C920, SHA-256 `98629d2738602db95b14701214f66e021bff32cb3642c546f527e01662b3c1bb`:

```text
06 00 01 00 02 00 01 00 03 00 01 00 02 00 01 00 04 00 01 00 02 00 01 00 03 00 01 00 02 00 01 00 05 00 01 00 02 00 01 00 03 00 01 00 02 00 01 00 04 00 01 00 02 00 01 00 03 00 01 00 02 00 01 00
```

Width0..6 pointers are `77C91F 77C91E 77C91C 77C918 77C910 77C900 77C8E0`. Each width-w slice has2^w entries; all127 addressed entries were read and checked: `table[0]=w`, otherwise `table[i]=ctz(i)`. Slices share tails of the64-byte maximum table. This complete finite identity is a data observation, not a claim that arbitrary direct width input is admitted.
