# File #2 port (Milestone 6) — investigation log

Target: Resident Evil Outbreak File #2, NTSC-U, `SLUS_209.84`
(`SYSTEM.CNF`: `BOOT2 = cdrom0:\SLUS_209.84;1`, `VER = 1.05`), user-owned ISO
`iso/Resident Evil - Outbreak - File #2.iso`.
ELF SHA-256 `5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d`.

## Upstream check (2026-10-25)

`sp00nznet/reo` branches `main`, `perf-ingame`, `pivot-selfexec`: the only
File #2 artifact is `recomp/config/outbreak_file2.toml` (ElfAnalyzer output,
pre-pivot skip list). No decompilation, Ghidra export or File #2 function map
exists upstream, and no separate Outbreak decomp repository is listed under
the author's account. Upstream README: "File #2 (SLUS-20984) | builds; no boot work".

## Disc layout differences

| | File #1 (SLUS_207.65) | File #2 (SLUS_209.84) |
|---|---|---|
| Archives | `NETBIO00..02.DAT` | `NETBIO00..01.DAT` |
| IOP modules | `IOP/` | `MODULES/` |
| Network GUI | `NTGUI2/` | `NTGUIDVD/` |
| Code overlays | `BIN/{0..6,8,9}.DAT`, several LZ-compressed | same numbers, all stored raw |
| Main ELF load | text/data `0x100000+0x159D80`, memsz `0x26F100` | `0x100000+0x169980`, memsz `0x27F280` |

Overlays must be paired by their MWo3 id, not by file number:

| id | File #1 file / base / text | File #2 file / base / text |
|---|---|---|
| 1 | 0.DAT / 0x370000 / 0x0FD40 | 0.DAT / 0x38C400 / 0x10A40 |
| 2 | 1.DAT / 0x570000 / 0x18440 | 1.DAT / 0x58D000 / 0x22540 |
| 3 | 2.DAT / 0x570000 / 0x198540 | 2.DAT / 0x58D000 / 0x1D67C0 |
| 4 | 3.DAT / 0x570000 / 0x9A140 | 3.DAT / 0x58D000 / 0x96440 |
| 5 | 4.DAT / 0x6E0000 / 0x70F40 | 4.DAT / 0x6ED000 / 0x71040 |
| 6 | 6.DAT / 0x6E0000 / 0x54AC0 | 5.DAT / 0x6ED000 / 0x54A40 |
| 7 | 5.DAT / 0x6E0000 / 0x29CC0 | 6.DAT / 0x6ED000 / 0x29CC0 |
| 9 | 9.DAT / 0x810000 / 0x189C0 | 8.DAT / 0x810000 / 0x1C2C0 |
| 10 | 8.DAT / 0x810000 / 0x04740 | 9.DAT / 0x810000 / 0x05140 |

The runtime registers overlay functions by MWo3 id, so this needs no code change.

## Ghidra

Project `reoiso` (see memory note): `/ps2/SLUS_209.84` (language
`r5900:LE:32:default`, ELF loader, entry 0x100008) and `/ovl2/ovl<n>.elf`
(File #2 `BIN/<n>.DAT` wrapped by `tools/overlay_extract.py`). Function maps
exported with `tools/ghidra_export_functions.py` and gap-filled with
`tools/ghidra_fill_gaps.py`, exactly as for File #1:

- `recomp/config/file2/outbreak_file2_ghidra_functions.csv` — 5,716 functions (File #1: 5,658)
- `recomp/config/file2/overlay_maps/ovl<n>.csv` (keyed by File #2 file number)

## File #1 → File #2 address map

`tools/file2_port/match_functions.py` → `recomp/config/file2/file1_to_file2.json`;
`tools/file2_port/translate.py` queries it. Method: hash each function with
relocatable fields masked (j/jal targets, lui and low-half immediates except
`$sp`-relative); unique hashes are `exact`; positional call targets of
identically shaped pairs are `call`; same-count link-order slots between
anchors are `order` (probable only). Data addresses come from rebuilt
lui/low-half constants in identically shaped pairs, accepted only when every
vote agrees.

| image | matched / File #1 functions | exact | call | order | data constants |
|---|---|---|---|---|---|
| main | 5263 / 5633 | 3348 | 1011 | 904 | 3536 |
| id3 (2.DAT) | 2702 / 4426 | 1717 | 182 | 803 | 1537 |
| id4 (3.DAT) | 1664 / 2225 | 1155 | 188 | 321 | 1299 |
| id5 | 1041 / 2053 | 127 | 153 | 761 | 602 |
| id6 | 1452 / 1544 | 197 | 381 | 874 | 900 |
| id7 | 369 / 688 | 46 | 63 | 260 | 325 |
| id1, id2, id9, id10 | 137/191, 37/177, 233/330, 50/71 | | | | |

Observations (confidence: probable — consistent run structure, not yet traced):

- SDK/libsif at 0x100000–0x1180xx is unchanged: `sub_00117080`, `sub_00117818`,
  `sub_001179E8` are exact matches at identical addresses, so the File #1 skip
  list and libsif HLE bindings apply unchanged.
- libmpeg moved by −0x1FB20 (File #1 extra entries `0x1431D8..` → `0x1236B8..`).
- Data sections were reordered as whole blocks; each block keeps one delta
  (e.g. File #1 `0x294200..0x29FEE8` → +0xB8F50, 245 constants / 1,195 votes;
  `0x324240..0x3243FF` → −0x23A80, 127 votes).
- In the id5–id7 overlays most "order" pairs are identically shaped; the low
  exact count reflects duplicate small functions and differing Ghidra splits.

Override literal coverage (`translate.py --scan recomp/overrides/*.cpp *.h reo_bootstrap.cpp`):
213 function starts, 400 inside matched functions, 123 data, 129 unmapped
(mostly heap/runtime structures, MMIO-like constants and a few unmatched
functions such as File #1 `0x1F73B0`, `0x1B0B80`). Every translated address
is a candidate until checked against disassembly.

## Build setup

- `tools/local_build/generate_game.py --game file2 --metadata recomp/config/file2`
  generates `recomp/config/output_file2/{output,output_extra,output_ovl,output_overlay}`.
  Requires the patched recompiler (`build-ninja/release-v119/inputs-final/tools/ps2_recomp.exe`,
  SHA-256 prefix `fd044198644d`); `third_party/PS2Recomp/out/build/.../ps2_recomp.exe`
  is stale and ignores mapped bounds.
- `recomp/config/file2/outbreak_file2.toml`: upstream ElfAnalyzer MMIO/jump tables with
  the 42 "self-modifying code" NOPs removed, as for File #1 (D20).
- `recomp/CMakeLists.txt`: generated sibling dirs resolve next to the target's
  main output dir, so `reo_recomp_file2` no longer picks up File #1 overlays.
- `tools/play.ps1 -Game file2` mounts the File #2 ISO and runs `reo_recomp_file2.exe`.
- `applyFile2Overrides` applies the self-execution core only (hardware bridge + libsif HLE).

## Status / checkpoints

2026-10-25 (paused; details and next steps in `HANDOFF_FILE2.md`): File #2 natural-mode
smoke run `20261025-163126-file2-boot9` runs 120 s without a crash with GS traffic
(gsPkts=568972, prims=189435). Fixed on the way: missing CRI DTX layout (stall after
"Now Loading") and a clang-cl/MSVC `__m128i` return ABI mismatch in `PS2Runtime::Load128`.
Visual state, input and PCSX2 comparison: not yet checked.

2026-10-26: scripted input (`REO_PAD_SCRIPT`, LEFT+CROSS on the memory-card prompt, then
START/CROSS) reaches the title screen, the File #2 main menu, Single Play -> New Game and
Character Select with 3D models (`build-ninja/smoke/20261026-202458-file2-text`).
- Garbled menu/character text (`hhh`, `MUU-'`) was 14 language-table accessors at
  `0x14E040..0x14E220` (32-byte `lbu v1,0x97D(0x300000); return table[v1]` stubs) that
  Ghidra never made functions; the runtime logged 1,694 `Function ... not found` and the
  game used a stale pointer. Added to `recomp/config/file2/extra_functions.csv`; warnings 0,
  text correct (confirmed).
- Intro movie plays at ~4 decoded frames/s (CPU IPU path, `csc` in `[perf]`); START skips
  it. The GPU movie route is File #1-only: ~1,175 address references, 38 unmapped.
- No memory-card HLE for File #2 yet: the game asks to start without saving.

2026-10-26 VU geometry: the ELF microcode region (`0xFB000..0x100F00` in File #1, same layout in
File #2, ~24 KB) is byte-identical between the games, so File #1's specialized/native VU1
programs are now built for File #2 as well (CMake and `reo_vu_specialized.cpp` gates widened to
`REO_GAME_FILE[12]`; the runtime still compares the live bank, `[VU-CODE-COVERAGE]
compared_bytes=3888`). A/B on the same exe and scripted route (scenario room behind the pause
menu, 160-210 s): main thread 134 ms vs 275 ms CPU per 1 s sample with `REO_VU_SPECIALIZED=0`.
Gameplay movement not yet measured. The dev submodule lacked patch 0104 (CRLF); applied with
`git apply --ignore-whitespace`, then `ps2_runtime.lib` rebuilt.

2026-10-26 pad state: libpad2 `0x12B280` (exact match of File #1) falls back to dbcman RPC
`0x8000131A` command `0x0101800C` when the record counter has not advanced. The bridge zeroed
the reply count, so `0x134518` copied nothing and the caller returned an uninitialized stack
byte as the port state; `0x33D050` flapped 2/1 around scenario load (`REO_PEEK`). The bridge now
answers count 1, state 1 (`runtime/input/pad2_rumble.h` `isStateQuery`). After the fix the port
state stays 0x101. In scripted runs the in-game pause menu still opens on scenario entry and
EXIT does not close it; cause not found (not the pad state, not the automation helpers).
Hot loop while paused: `FUN_001ddd10` (callers include `FUN_001edcb0` <- `FUN_00146340`).

2026-10-26 GPU movies (confirmed visually): the native movie route now builds for File #2.
- Handwritten movie sources name guest addresses through `REO_MA(0x...)`/`REO_MS_<addr>`;
  `recomp/overrides/movie_addresses/{file1,file2}/reo_movie_game_addresses.h` (generated by
  `tools/file2_port/port_movie.py headers`) supply them. File #1's header is the identity.
- The 11 copied functions (original_transport_*, movie caller/observers) are translated by
  `port_movie.py copies` into `recomp/config/output_file2/movie_copies`. All copied ranges moved
  by 0x53C70; the only non-call difference is the `0x240918 -> 0x267878` lui/addiu pair at
  0x171960/0x171974 (MPEG end-code block, same bytes), checked against both ELFs.
- 47 dependent functions all matched (39 exact). `0x16AFC4` is the alignment word -> 0x1BEC34.
- Bootstrap installs movie entry/join/native movie for the target game's serial
  (`REO_MOVIE_SERIAL`). Window captures with `REO_GPU_MOVIE=1` show the opening credits advancing
  every 4 s (previously ~4 decoded frames/s on the CPU route, stuck on "CAPCOM Presents").
- `REO_SHOT_AT` produces nothing with the GPU presenter; window captures were used instead.
- Release note: the wrapped File #1 sources change their SHA-256, so the build kit's
  native-source equivalence inputs must be regenerated for the next release.

2026-10-26 pause menu at scenario start (fixed, confirmed by window capture): ovl2 0x619740 sets the
pause request 0x4DB454 every frame while main 0x13CB90 reports the pad as unusable; it requires pad
mode 's' (0x73, DUALSHOCK 2 analog) with mode word 1. libpad2 0x1E8510 only selects 0x73 when the
profile has bits in 0xFFF00000; the bridge advertised 0x000FFFFF (mode 0x60). File #2 builds now
report 18 data bytes (buttons, sticks, 12 pressure bytes) and profile 0x3FFFFFFF. File #1 is unchanged
(it has no such check). Pause chain: 0x6198F0 -> 0x710670(4) -> menu 0x71C6A0 (EXIT = index 10).

2026-10-26 memory card: File #2 links a different libmc2 build (no matcher hits). Workers located via
its dispatcher FUN_0012CA58 (request types 2-15, same argument lists as File #1 FUN_00181A28);
`reo::mc2::install(runtime, File2Workers)`. Type 14 goes through wrapper 0x12FF88, whose library
state checks fail without the original workers, so the wrapper is replaced as a whole (`statWrapper`).
Boot no longer shows "memory card cannot be found".

2026-10-26 movies: `REO_GPU_MOVIE_STATS=1` prints frames shown/discarded per second; File #2 intro
and credits measured 30-31 shown/s in 102 of 107 one-second windows (others are movie start/end).
