# Resident render-program descriptor selection

Static File #1 US research, 2026-11-04. Main **SLUS_207.65**, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Full selector and all27 owned descriptor headers reviewed. No game, VU replay, native build or program execution was performed. These are descriptor outcomes, not27 newly mapped CPU functions or a count of interpreted programs.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x198C80](../recomp/config/output/sub_00198C80_0x198c80.cpp) | `select_render_program_descriptor_from_exact_geometry_format_keys_candidate` | Confirmed full decision tree and owned descriptor pointers | Initializes object+48=-1,+4C=NULL. Nonzero high8 of object+C returns with those failure fields. Otherwise F=word+C &00FFFFFFhex,A=word+4 OR word+8. Exact pairs below set numeric id+48 and descriptor+4C. Unsupported pairs retain failure; no fallback, allocation, wait or VU execution. CPU return value is not assigned. Format bit meanings remain candidate; IDs are not native AOT admission IDs. |

All numbers below are hexadecimal except descriptor IDs. Key group **A**={00121035,00021035}, **B**={00221135,00321135}, **C**={00121025,00021025}. Each descriptor row records owned word+0,word+C,word+10; these are respectively a program/upload-data pointer candidate, a size-like value and a CPU callback pointer. The interpretation of+C is intentionally left narrower than a proven byte length. Callback labels require independent body review.

| F | Key group | ID | Descriptor | Owned +0 | Owned +C | Callback +10 |
| --- | --- | --- | --- | --- | --- | --- |
| 020080 | A | 0 | 2301F0 | 1F7580 | CC0 | 19A960 |
| 008802 | A | 1 | 230220 | 1F8280 | 5B0 | 19AAE0 |
| 008802 | B | 2 | 230260 | 1F8850 | B20 | 19ACF0 |
| 000002 | A | 3 | 230290 | 1F9390 | 308 | 199D50 |
| 000002 | C | 4 | 2302C0 | 1F96B0 | 2E8 | 199D50 |
| 020000 | A | 5 | 2302F0 | 1F99B0 | 2D0 | 19A370 |
| 020000 | C | 6 | 230320 | 1F9CA0 | 298 | 19A370 |
| 004202 | A | 7 | 230350 | 207550 | 390 | 199E70 |
| 004002 | A | 8 | 230380 | 1F9F50 | 320 | 19A040 |
| 004000 | A | 9 | 2303B0 | 1FA290 | 2D8 | 19A040 |
| 024000 | A | 10 | 2303E0 | 1FA580 | 2E8 | 19A4C0 |
| 00C202 | A | 11 | 230410 | 207150 | 3E0 | 19A160 |
| 00C202 | B | 12 | 230450 | 206620 | B10 | 19C2B0 |
| 02C000 | A | 13 | 230480 | 1FA880 | 348 | 19A610 |
| 02C080 | A | 14 | 2304B0 | 201830 | E20 | 19A7A0 |
| 008882 | A | 15 | 2304E0 | 203E00 | 1100 | 19AF80 |
| 008882 | B | 16 | 230520 | 202690 | 1728 | 19B1C0 |
| 00C802 | B | 17 | 230560 | 200D00 | B08 | 19C4C0 |
| 02C822 | A | 18 | 230590 | 1FABE0 | 688 | 19B980 |
| 02C822 | B | 19 | 2305D0 | 1FB280 | C58 | 19BBD0 |
| 02C802 | A | 20 | 230600 | 1FBF00 | 5D0 | 19B980 |
| 02C802 | B | 21 | 230640 | 1FC4F0 | B90 | 19BBD0 |
| 028802 | A | 22 | 230670 | 1FD0A0 | 550 | 19B480 |
| 028802 | B | 23 | 2306B0 | 1FD610 | B98 | 19B6C0 |
| 02C380 | A | 24 | 2306E0 | 1FE1D0 | F30 | 19BEA0 |
| 024380 | A | 25 | 230710 | 1FF140 | E20 | 19C0C0 |
| 024080 | A | 26 | 230740 | 1FFFA0 | D20 | 19C760 |

For example,1F7580 begins words600000CF,0,0,4A000000,01E10002,000002FF;1F9390 begins60000031,0,0,4A610000,01E10001,000002FF. This supports embedded transfer/program data, but does not alone identify lighting/skinning semantics or exact microprogram boundaries. Descriptor+24 contains43000000 (128.0) for most rows; IDs4/6 instead437F0000 (255.0). Preserve this distinction when connecting color preparation to the selected program.

Next evidence needed is the consuming upload path, exact microprogram extraction and original-versus-compiled replay for each admitted program. [Matrix/light packet constructors](SYMBOLS_RENDER_MATRIX_LIGHT_PACKETS.md) independently maps several callbacks. Program selection here is static and exact; execution frequency, interpreter percentage and performance remain unmeasured.

The consuming path is now statically tied down in [18C170 render preparation](SYMBOLS_RESOURCE_RELOCATION.md): it invokes descriptor+10 **on every admitted call**, after cached/frame-local material handling, passing a1=(descriptor+4 - descriptor+8)>>3 and a2=the material-chain pointer. The callback returns the new parameter chain. When selected descriptor ID differs from cached29FD9C,18C170 allocates64 bytes and queues a DMA CALL-shaped tag50000001 whose target is descriptor+0, followed by its return/continuation block. It then queues the parameter chain with50000000 OR low28(pointer),and the material-chain continuation. Thus parameter construction and program-upload switching have separate admission conditions.

This is static call/control-flow evidence, not proof of a particular program being executed in a captured slowdown. The owned descriptor table starts with+4/+8 both0; initialization or relocation of those fields requires separate review before treating them as fixed VU entry addresses. Exact extraction, interpreter-versus-compiled replay, and incident-frequency attribution remain outstanding. [All22 selected CPU callbacks](SYMBOLS_RENDER_PALETTE_PACKET_VARIANTS.md) are independently documented, including32-entry matrix preparation; they are not automatically translated microprograms.
