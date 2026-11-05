# DNAS overlay: residual header and protected-fragment classification

Static File #1 US research, 2026-11-04. Catalogue **o5**, runtime id **7**, base **0x6E0000**, owned `insdnas.bin`, SHA-256 **97174f5d367cd90bedd5ba397c6492e9fb4bbd0ec7d6021c2be524c49925d38e**. No game, build, replay, network request, live-memory read or attachment occurred.

This is a classification inventory, **not additional recovered function names**. The catalogue has837 intervals:686 generated bodies and151 intervals without generated source. Of the686 generated intervals,19 are interior continuations now covered by [complete logical-owner reviews](STATIC_DNAS_O5_OWNER_RECONCILIATION.md); their independent callability remains unproved. The other667 have role annotations, with the earlier protected-prefix rows now refined through copied-data recovery.667/686 remains97.2% interval annotation coverage, not a native-translation or runtime-equivalence percentage. The151 source-less intervals comprise9 header partitions and142 one-byte partitions inside protected continuations. These should not inflate a function denominator or a translation count.

Owned header: bytes0..3 `MWo3`; little-endian words+4=7,+8=6E0000,+C=29CC0 text span,+10=7E00 data span,+14=6FB00,+18=711B00,+1C=711B00. Name at+20 is `insdnas.bin`. Header field interpretation beyond established image identity remains separate from a callable entry.

Catalogue boundaries split transformed payloads, clear prefixes, missing delay-slot words and tiny byte intervals. For example6FAF7C is the delay-slot address following protected payload's apparent704478 call; its four one-byte catalogue rows do not establish four functions. No raw pseudo-instruction after a protected boundary is promoted to a runtime call or VU/rendering operation. See [protected entry evidence](SYMBOLS_DNAS_PROTECTED_ENTRIES.md) and [allocator boundaries](SYMBOLS_DNAS_MEMORY.md).

## Generated continuation fragments

Each row links the exact generated catalogue interval and gives its original words. Every listed word was matched against the owned image. The containing operations are now reviewed, while independent callability remains unproved; a clear `lui`/counter address does not establish a separate API. Original encoded words below are interval identity evidence, not decoded instruction listings.

| Catalogue interval / source | Owning boundary context | Owned words, little-endian u32 values | Classification |
| --- | --- | --- | --- |
| Classified [o5 0x6E0920](../recomp/config/output_ovl/o5/o5_006E0920_0x6e0920.cpp) to6E0924 exclusive | 6E0838: descriptor6E0904/payload6E0918 | 3C030071 | Resolved owned branch-delay LUI inside complete resize owner6E0838; no independent function. See [first-family recovery](SYMBOLS_DNAS_RECOVERED_FIRST_FAMILY_ALLOCATOR.md). |
| Classified [o5 0x6E1F5C](../recomp/config/output_ovl/o5/o5_006E1F5C_0x6e1f5c.cpp) to6E1F74 exclusive | 6E1ED0 protected semaphore/counter continuation | 3C030071, 24631B70, 7D2C8CC5, 67AC8CC7, 7F2C8CC5, 64ACAC03 | Resolved owned allocation-counter increment and inline-data skip branch inside6E1ED0; no independent function. See [first-family recovery](SYMBOLS_DNAS_RECOVERED_FIRST_FAMILY_ALLOCATOR.md). |
| Classified [o5 0x6E228C](../recomp/config/output_ovl/o5/o5_006E228C_0x6e228c.cpp) to6E229C exclusive | 6E2208: descriptor6E226C/payload6E2280 | 3C030071, 24631B78, 2E104883, BA101883 | Resolved owned release-counter update prefix inside6E2208; no independent function. See [first-family recovery](SYMBOLS_DNAS_RECOVERED_FIRST_FAMILY_ALLOCATOR.md). |
| Classified [o5 0x6E243C](../recomp/config/output_ovl/o5/o5_006E243C_0x6e243c.cpp) to6E2444 exclusive | 6E23A8 protected semaphore/counter continuation | 3C030071, 24631B74 | Resolved owned resize-counter address setup inside6E23A8; no independent function. See [first-family recovery](SYMBOLS_DNAS_RECOVERED_FIRST_FAMILY_ALLOCATOR.md). |
| Classified [o5 0x6FAF80](../recomp/config/output_ovl/o5/o5_006FAF80_0x6faf80.cpp) to6FAF88 exclusive | 6FAE98/internal6FAEC0: descriptor6FAF64/payload6FAF78 | 6D85E693, 6D91E69B | Covered by connected owner review; independent entry not established. |
| Classified [o5 0x701C64](../recomp/config/output_ovl/o5/o5_00701C64_0x701c64.cpp) to701C7C exclusive | 701BF8 branch skips this span toward701C90; follows clear boundary | 244D7118, DF95DC67, 8C90744D, FD3579FA, 0C512E85, A3C234F9 | Covered by connected owner review; independent entry not established. |
| Classified [o5 0x701D74](../recomp/config/output_ovl/o5/o5_00701D74_0x701d74.cpp) to701D8C exclusive | 701D18 branch skips this span toward701DA0; follows clear boundary | FE9DCBFA, 2454F408, FD8EA3C2, A0DCCA69, 8D5478C5, 26082160 | Covered by connected owner review; independent entry not established. |
| Classified [o5 0x702150](../recomp/config/output_ovl/o5/o5_00702150_0x702150.cpp) to702158 exclusive | 7020B8: protected payload702144 | BAF830FD, 09F807CD | Covered by connected owner review; independent entry not established. |
| Classified [o5 0x702608](../recomp/config/output_ovl/o5/o5_00702608_0x702608.cpp) to70260C exclusive | 702578: protected payload7025EC | 82FDA71F | Covered by connected owner review; independent entry not established. |
| Classified [o5 0x7028E4](../recomp/config/output_ovl/o5/o5_007028E4_0x7028e4.cpp) to7028FC exclusive | 7027A8: protected payload7028C4 | 2B58F189, F99C7197, ABF8E561, ABF8E507, 2BF8E521, 2BF8E543 | Covered by connected owner review; independent entry not established. |
| Classified [o5 0x702F7C](../recomp/config/output_ovl/o5/o5_00702F7C_0x702f7c.cpp) to702F90 exclusive | 702EF0: protected payload702F74 | 30FA5D9C, 30FADD7C, B6B241FC, B0615DFC, B6B1C5FC | Covered by connected owner review; independent entry not established. |
| Classified [o5 0x703074](../recomp/config/output_ovl/o5/o5_00703074_0x703074.cpp) to70308C exclusive | 703028 branch skips this span toward7030A0; follows clear boundary | DD0DD437, 259A96B8, FFD0745A, A3B313E9, A1C98501, 0210D020 | Covered by connected owner review; independent entry not established. |
| Classified [o5 0x703228](../recomp/config/output_ovl/o5/o5_00703228_0x703228.cpp) to70322C exclusive | 703198: protected payload703220 | 0C046E0A | Covered by connected owner review; independent entry not established. |
| Classified [o5 0x7035F8](../recomp/config/output_ovl/o5/o5_007035F8_0x7035f8.cpp) to703610 exclusive | 7035B8 branch skips this span toward703624; follows clear boundary | 0C2B405E, 00AAB820, 87A28313, DDA922BF, 8CA2664D, 8514461B | Covered by connected owner review; independent entry not established. |
| Classified [o5 0x70375C](../recomp/config/output_ovl/o5/o5_0070375C_0x70375c.cpp) to703764 exclusive | 7036C8: protected payload703750 | 36C6DB83, 5495DEC3 | Covered by connected owner review; independent entry not established. |
| Classified [o5 0x703E1C](../recomp/config/output_ovl/o5/o5_00703E1C_0x703e1c.cpp) to703E2C exclusive | 703D70: protected payload703E14 | 723B1068, B6BB306A, 8826F38B, 46271188 | Covered by connected owner review; independent entry not established. |
| Classified [o5 0x7078F4](../recomp/config/output_ovl/o5/o5_007078F4_0x7078f4.cpp) to7078F8 exclusive | 707850: protected payload7078CC | 69201FB8 | Covered by connected owner review; independent entry not established. |
| Classified [o5 0x707A3C](../recomp/config/output_ovl/o5/o5_00707A3C_0x707a3c.cpp) to707A54 exclusive | 707998: protected payload707A34 | 9F8E0081, A24E781E, DDBEFCE1, DDAAF4E1, DDAAF4E1, DDAAF4E1 | Covered by connected owner review; independent entry not established. |
| Classified [o5 0x707FA0](../recomp/config/output_ovl/o5/o5_00707FA0_0x707fa0.cpp) to707FB8 exclusive | 707F38 branch skips this span toward707FCC; follows clear boundary | A13793E1, 26A651B0, 0043C020, A37212C9, FFC4044A, DC77171F | Covered by connected owner review; independent entry not established. |

## Source-less catalogue intervals

Consecutive source-less partitions are grouped below; **count** is the number of catalogue rows, and the shown hex is the complete owned byte span. Ranges are half-open and gaps are retained. The first9 catalogue rows partition the header; all later142 rows are one-byte catalogue cuts associated with the protected regions above. Link targets are the canonical [o5 catalogue](../recomp/config/overlay_maps/ovl5.csv).

| Catalogue span | Count | Owned bytes | Classification |
| --- | --- | --- | --- |
| Classified [o5 0x6E0000](../recomp/config/overlay_maps/ovl5.csv) to6E001B exclusive | 9 | 4D 57 6F 33 07 00 00 00 00 00 6E 00 C0 9C 02 00 00 7E 00 00 00 FB 06 00 00 1B 71 | Image-header partitions; no executable entry. |
| Classified [o5 0x6E091C](../recomp/config/overlay_maps/ovl5.csv) to6E0920 exclusive | 4 | E2 B0 46 5C | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x6E0924](../recomp/config/overlay_maps/ovl5.csv) to6E0927 exclusive | 3 | E3 34 46 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x6E1F74](../recomp/config/overlay_maps/ovl5.csv) to6E1F7B exclusive | 7 | 83 AC AC 75 83 AC AC | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x6E229C](../recomp/config/overlay_maps/ovl5.csv) to6E229E exclusive | 2 | 83 48 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x6E2444](../recomp/config/overlay_maps/ovl5.csv) to6E244B exclusive | 7 | 1F 8A 81 F1 3F 22 80 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x6FA644](../recomp/config/overlay_maps/ovl5.csv) to6FA648 exclusive | 4 | 44 CB 51 F5 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x6FAF7C](../recomp/config/overlay_maps/ovl5.csv) to6FAF80 exclusive | 4 | 17 F8 09 ED | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x6FAF88](../recomp/config/overlay_maps/ovl5.csv) to6FAF8B exclusive | 3 | 96 E8 41 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x6FDAA4](../recomp/config/overlay_maps/ovl5.csv) to6FDAA8 exclusive | 4 | 24 E2 28 C3 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x701F78](../recomp/config/overlay_maps/ovl5.csv) to701F79 exclusive | 1 | 05 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x70214C](../recomp/config/overlay_maps/ovl5.csv) to702150 exclusive | 4 | E9 03 F8 49 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x702158](../recomp/config/overlay_maps/ovl5.csv) to70215B exclusive | 3 | 82 33 06 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x7023F4](../recomp/config/overlay_maps/ovl5.csv) to7023FC exclusive | 8 | 51 28 A9 C3 51 20 8B ED | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x702604](../recomp/config/overlay_maps/ovl5.csv) to702608 exclusive | 4 | 3F A1 FD 02 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x70260C](../recomp/config/overlay_maps/ovl5.csv) to70260F exclusive | 3 | 3F A1 FD | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x702714](../recomp/config/overlay_maps/ovl5.csv) to70271C exclusive | 8 | 8B 00 85 D3 0B 03 85 06 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x7028E0](../recomp/config/overlay_maps/ovl5.csv) to7028E4 exclusive | 4 | 97 71 98 F7 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x7028FC](../recomp/config/overlay_maps/ovl5.csv) to7028FF exclusive | 3 | 99 61 58 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x702F78](../recomp/config/overlay_maps/ovl5.csv) to702F7C exclusive | 4 | 5C C9 F3 00 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x702F90](../recomp/config/overlay_maps/ovl5.csv) to702F93 exclusive | 3 | 3C 0D F1 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x703224](../recomp/config/overlay_maps/ovl5.csv) to703228 exclusive | 4 | 1D 2C C5 3C | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x70322C](../recomp/config/overlay_maps/ovl5.csv) to70322F exclusive | 3 | 1D 88 C0 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x7033D4](../recomp/config/overlay_maps/ovl5.csv) to7033D7 exclusive | 3 | 88 B0 E2 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x703758](../recomp/config/overlay_maps/ovl5.csv) to70375C exclusive | 4 | 43 DB C6 D0 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x703764](../recomp/config/overlay_maps/ovl5.csv) to703767 exclusive | 3 | 87 DB C6 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x703E18](../recomp/config/overlay_maps/ovl5.csv) to703E1C exclusive | 4 | 45 67 E7 48 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x703E2C](../recomp/config/overlay_maps/ovl5.csv) to703E2F exclusive | 3 | 8B F3 26 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x704328](../recomp/config/overlay_maps/ovl5.csv) to704330 exclusive | 8 | 3B 79 31 74 1B 52 14 74 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x7078F0](../recomp/config/overlay_maps/ovl5.csv) to7078F4 exclusive | 4 | AC 1D 00 C8 | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x707A38](../recomp/config/overlay_maps/ovl5.csv) to707A3C exclusive | 4 | E1 02 8E 1D | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x707A54](../recomp/config/overlay_maps/ovl5.csv) to707A57 exclusive | 3 | BE 78 4A | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x707E0C](../recomp/config/overlay_maps/ovl5.csv) to707E14 exclusive | 8 | 20 FA 67 3E 24 7A 05 3E | Protected-continuation catalogue byte partitions; no independent function evidence. |
| Classified [o5 0x708198](../recomp/config/overlay_maps/ovl5.csv) to7081A0 exclusive | 8 | 57 67 DF 05 1F 72 DF 05 | Protected-continuation catalogue byte partitions; no independent function evidence. |

Validation:19 generated fragment intervals /73 distinct instruction-comment words matched owned bytes;151 source-less intervals /169 owned bytes covered by34 contiguous groups. All links resolve locally. The body-role count includes the separately reviewed native reset gate7077E8 and excludes these19 fragments.
