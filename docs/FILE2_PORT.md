# File #2 port (Milestone 6) â€” investigation log

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

- `recomp/config/file2/outbreak_file2_ghidra_functions.csv` â€” 5,716 functions (File #1: 5,658)
- `recomp/config/file2/overlay_maps/ovl<n>.csv` (keyed by File #2 file number)

## File #1 â†’ File #2 address map

`tools/file2_port/match_functions.py` â†’ `recomp/config/file2/file1_to_file2.json`;
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

Observations (confidence: probable â€” consistent run structure, not yet traced):

- SDK/libsif at 0x100000â€“0x1180xx is unchanged: `sub_00117080`, `sub_00117818`,
  `sub_001179E8` are exact matches at identical addresses, so the File #1 skip
  list and libsif HLE bindings apply unchanged.
- libmpeg moved by âˆ’0x1FB20 (File #1 extra entries `0x1431D8..` â†’ `0x1236B8..`).
- Data sections were reordered as whole blocks; each block keeps one delta
  (e.g. File #1 `0x294200..0x29FEE8` â†’ +0xB8F50, 245 constants / 1,195 votes;
  `0x324240..0x3243FF` â†’ âˆ’0x23A80, 127 votes).
- In the id5â€“id7 overlays most "order" pairs are identically shaped; the low
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

2026-10-26 saving (confirmed): Options -> SAVE/LOAD -> SAVE DATA -> "Create the main data? YES" wrote
BASLUS-20984OB2 (icon.sys, icons, game.bin 119544 B, patch.bin 8240 B; [MC2] create/write all
succeeded) and showed "Data has been saved."; a second save found the existing data ("OK to
overwrite"). Launcher: File #2 is selectable and playable from a developer tree; smoke launch
`--smoke-launch <exe> <result.json> --test-file2 <iso>` ran 60 s, GPU movies, exit 0.

2026-10-27 File #1 dev build: `reo_bootstrap.cpp` never compiled through the dev path because
`build-ninja/asset-clang-launcher.py` sent it to MSVC while `overrides/reo_audio.h` uses GCC
atomics and minimal Win32 headers (the release kit uses llvm-mingw). The launcher script (local,
untracked) now compiles it with clang-cl too, and `reo_audio.h` defines `_AMD64_` for the SDK
headers. `reo_recomp.exe` (File #1) builds and boots with GPU movies to the main menu
(`build-ninja/smoke/*-file1-regress`, 0 missing functions); run with `REO_VIF1_GPU_RESIDENT=0`
unless the GPU catalogue assets are next to the exe.

2026-10-27 map gaps: gameplay logged `Function at address 0x144600 not found` x6. A gap scan of the
File #2 map (code between mapped functions, referenced by jal/j/pointers) added 14 spans to
extra_functions.csv (0x10B0D8, 0x1430C0-0x143100, 0x144600, 0x144800, 0x147420, 0x147440, 0x18BF08,
0x18C090, 0x18C100, 0x1D0EF0, 0x1F2540). Same route afterwards: 0 missing functions, no crash.
File #1's map has only 3 unreferenced gaps (0x1B7890 already handled by reo_missing_entries).

2026-10-27 overlay-map continuation (baseline `d253ff8`, branch `file2-port`):
`tools/file2_port/scan_overlay_gaps.py` now records nonzero gaps, incoming mapped
`j`/`jal` instructions, data-region pointer candidates and input hashes. It is
read-only; references are review candidates, not automatic function starts.
Example:

```powershell
python tools/file2_port/scan_overlay_gaps.py --images game_data_file2/ovl --maps recomp/config/file2/overlay_maps --out build-ninja/file2-overlay-gaps-after.json
python -m unittest discover -s tools/file2_port -p test_scan_overlay_gaps.py
```

- `ovl2` (MWo3 id 3, gameplay) has no nonzero uncovered bytes between mapped
  ranges. This does not prove that every indirect entry inside those ranges is
  registered, or that all scenario paths work.
- `ovl3` (MWo3 id 4) had ten unmapped function entries referenced by data at
  `0x627104`, `0x627110`, `0x627120..0x627140` and `0x627DAC`. Added exact,
  non-overlapping ranges to `file2/overlay_maps/ovl3.csv`: `0x5A5450`, `0x5A5480`,
  `0x5A54D0`, `0x5A5500`, `0x5A55F0`, `0x5A5610`, `0x5A5630`, `0x5A5650`,
  `0x5A5C90`, `0x5CA040`. The first, third and ninth are indirect table
  dispatchers; four short handlers increment a state byte. Boundaries include
  return/jump delay slots and exclude trailing alignment padding.
- Regenerated only this overlay with the pinned v1.0.19 recompiler. All mapped
  source ranges passed `validate_mapped_ranges`; 197 instruction annotations in
  the ten added bodies match the original image words. Only ten generated
  bodies, their header and registration changed. Original-image/range hashes
  and incoming references are retained privately in
  `build-ninja/file2-overlay-review/verified-functions.json`.
- Before/after reports: `build-ninja/file2-overlay-gaps-{before,after}.json`.
  `ovl3` now has zero referenced gap targets; two nonzero gaps without these
  reference types remain. Other overlays still need review: `ovl4` has 6,
  `ovl5` 21, `ovl6` 6 and `ovl8` 6 distinct referenced gap targets. Some may be
  internal jump-table labels, so they were not blindly added as functions.
- Five scanner tests pass, covering reference discovery, mapped padding,
  unaligned/overlapping map entries, untrusted instruction-looking gap bytes,
  and malformed dimensions. The scanner does not follow cross-image or
  computed references. Ghidra/REA was unavailable; this pass used original
  image words and the pinned recompiler, not a new decompiler analysis.
  The Ghidra database was not changed; preserve these ten reviewed map rows
  when exporting maps from that database again.
- Build PASS: after `call tools\vcvars64.bat`,
  `cmake --build build-ninja --target reo_recomp_file2 --parallel 10` exited 0.
  Log: `build-ninja/file2-overlay-review/build.log`.
- Smoke PASS: `powershell -NoProfile -ExecutionPolicy Bypass -File
  build-ninja/file2-overlay-review/run-smoke.ps1` used `tools/smoke_test.ps1`
  with File #2, the owned ISO/ELF, GPU GS/presentation/movies, the handoff's fast
  pad sequence and a 100-second limit. Run:
  `build-ninja/smoke/20261027-115243-file2-overlay-map`. It remained running until
  the requested close and exited 0, with zero missing-function warnings and
  zero device-loss messages. Window captures at 45/60/75/90 seconds show
  scenario selection, Training Ground room entry, Kevin moving and a tutorial
  prompt. All 92 CRI audio reports had zero underruns; audio was not listened to.
  Peeked overlay ids were 0/2/3: this verifies startup/gameplay regression only,
  not execution of the newly mapped id-4 handlers or scenario completion.
  Captures, executable SHA-256 and the summary are under
  `build-ninja/file2-overlay-review/{captures,verification.json}`.

2026-10-27 extended progression verification: **FAIL**, not completion-ready.
Private controller session `build-ninja/file2-progression/training2` ran about
2,179 seconds with an isolated memory-card directory and the same executable
SHA-256 recorded above. Visual evidence confirms J's Bar file collection,
key spawn/use, stairwell and Staff Room transitions, Mark shoulder support and
healing, requesting/returning the iron pipe, breaking the locked door, the next
stairwell and Liquor Room load, and taking the handgun from fallen Jim.
The reload lesson started; reload completion and rooftop combat were not reached.

At about 1,906 seconds the runtime began warning that `0x691F20` was missing;
after 8,193 warnings it terminated gameplay with `Called unimplemented function`,
`ra=0x691C64`, `a0=0x4C8010`. Exit code was misleadingly 0. No
`VK_ERROR_DEVICE_LOST` appeared. This is a recompiler dispatch failure, not
confirmation of the separately reported movie/GPU crash.

`ovl2.csv` currently absorbs `0x691F20` into `0x691E90..0x691F28`.
Generated source contains `jr $ra` at `0x691F20`, while `0x691C5C` is a
`jalr $v0` with return address `0x691C64`. The interior entry is not registered
for external dispatch. It requires original-byte/boundary review and an overlay
map split or supported alternate-entry registration, followed by regeneration
and replay. No fix for this new failure was made during verification.

Evidence: `training2/verification.json`, `inputs.jsonl`, `stderr.log`
(first warning line 16937; fatal line 27359), and PNG captures, including
`stairsloaded`, `staff`, `healed`, `received`, `tackled`, `liquorloaded`,
`gunacquired` and `reloadinv`. An earlier harness attempt (`training`) ended
because of a command-file sharing race; it is not a game failure. The harness
was corrected before this longer run. Scenario clear, completion save/load and
other scenarios remain unverified. Next priority is the `0x691F20` dispatch fix.

2026-10-27 `0x691F20` correction (runtime replay pending): original ovl2 SHA-256
`e4a0b06b3b7b1812364d8e9708749faa7e0cf07484c2d32118cf464b558d0cca` confirms
`0x691F20 = 03E00008` (`jr ra`) and `0x691F24 = 00000000` (nop).
The preceding function returns at `0x691F10` with stack restoration in its
`0x691F14` delay slot, followed by alignment padding. The dispatch table at
`0x76E0E0`, indexed by the failing caller at `0x691C5C`, contains the new entry
at indices 0, 4, 6..12. Split the old map row at its actual end `0x691F18`
and added the independent eight-byte `0x691F20..0x691F28` function. This
preserves original instructions; it is not a synthetic bypass.

Regenerated ovl2 with the pinned v1.0.19 recompiler and verified all mapped
bounds. Installed only the two affected bodies, header and new registration,
preserving existing instrumented registrations. Evidence under
`build-ninja/file2-entry-fix/verified.json`. The scanner now reports interior
references separately, including return-only candidates; these remain review
candidates because ordinary switch labels also appear in tables. Eight tests
pass, including the interior return-entry regression and a nontrivial interior
call target. Source correction alone does not establish completion; replay
results follow separately.

The smoke harness now rejects missing-function and device-loss diagnostics even
when the process survives until the requested close. PowerShell parsing passes;
the previous failed trace produces 8,194 failure matches.

2026-10-27 rebuilt regression PASS (bounded): `build-ninja/file2-progression/fixed1/verification.json`. Build exited 0. Replayed J's Bar and Staff Room tasks, then completed Liquor Room handgun/ammo pickup and reloading; the game reported all area tasks cleared. Zero missing-function warnings, fatal dispatch errors or device-loss diagnostics; requested close exited 0. Executable SHA-256 `b84f13bd4a08e7ebedb9381e67105d4fa86d14969df6c575a85c4c2f4a2404a6`. Two timed navigation drifts were corrected manually at visual checkpoints. User redirected work to launcher integration, so rooftop combat, completion save/load and other scenarios remain unverified; extended playtesting was stopped.

### Launcher integration (2026-10-27)

File #2 is now selectable in the WPF launcher on `file2-port`. Disc checking and
import use the pinned SLUS-20984 v1.05 ELF digest, independently of any local
reference ELF. Import removal, existing-build selection, readiness checks and
launching follow the selected game. File #2 co-op was added in the subsequent
work recorded below. Gameplay cheats and randomizer mods were added on
2026-10-28 (see below and `FILE2_RANDOMIZER.md`).

Packaged setup supports a separate `build-kit-file2` directory, or
`build-inputs-file2.zip` with `file2KitSha256` and `file2InputsSha256` distribution
metadata. Existing File #1 kits are never used for File #2. The release exporter
and build worker still need File #2 kit production; no new release was packaged
or published here. Developer builds can launch `reo_recomp_file2.exe` directly.

Validation: Release launcher build passed without warnings; all 470 launcher
self-test checks passed, including File #2 disc rejection/acceptance, separate
kit/cache selection, build receipt isolation and preservation of File #1's ISO
selection. A 60-second launcher smoke used the rebuilt File #2 executable,
imported File #2 disc data and a separate diagnostic memory card. It opened a
2560x1440 game window, closed normally with exit code 0, and emitted no missing
function warnings, fatal dispatch errors or device-loss diagnostics. Artifacts:
`build-ninja/file2-entry-fix/launcher-smoke.json` and `launcher-file2.png`.
This verifies launcher integration, not completion of every scenario.

### Shared launcher graphics settings (2026-10-27)

Both games use `GraphicsOptions.From` for the graphics launch configuration:
output dimensions, aspect/fit, scaling and texture filters, internal resolution,
anisotropy, post AA, brightness/gamma, performance overlay and asynchronous VIF.
Fullscreen and movie-decoder preference are captured alongside those options.
The snapshot is taken before asynchronous setup; subsequent UI edits cannot
change the running launch's window mode, shader requirements or movie preference.
The session log records the effective renderer environment and captured values.
Graphics settings are shared by both editions and apply on the next launch.

Validation: launcher Release build passed with zero warnings/errors; all 549
self-test checks passed. Tests cover saved-settings round trips under Croatian
culture, both game IDs, all internal resolution/fit/AA choices, invalid values
and changes during launch preparation. Four bounded runtime launches passed:
File #1 and File #2 each at 2x/SMAA/16x anisotropy/16:9 fill/125% brightness/
1.25 gamma in a 1280x720 window, then native/AA off/4:3 centered/default color
in a 512x448 window with synchronous VIF and CPU movie decoding selected.
Renderer logs confirmed the requested presentation values; all four exited 0
with no missing-function, fatal dispatch or device-loss diagnostics. This is
settings/startup verification, not a full scenario or movie playback playtest.
Evidence: `build-ninja/launcher-graphics-check/verification.json` and per-run
JSON files referencing session logs. No release was published.

### Shared launcher controls (2026-10-27)

Keyboard, Xbox/XInput and DualSense use the same launcher input mapping and
private XInput adapter for both editions. File #2's existing libpad2 bridge
provides the required 18-byte DualShock 2 report (File #1 uses six data bytes).
The adapter now keeps logical port zero neutral if its private input feed is
inactive or invalid, instead of falling back to an unselected physical pad or
the game's default keyboard mapping. Other physical controller ports are hidden
while launcher input is selected. File #2 no longer reads File #1-only health
addresses for the DualSense light; its light stays neutral blue.

Validation: native adapter and launcher builds passed; 563 self-test checks
passed, including new per-edition tests through the actual adapter DLL for
button remapping, trigger values, dead zones, swapped/inverted sticks,
disconnect/reconnect, disabled input and private-device isolation. Existing tests
also cover DualSense report parsing, keyboard remapping and rumble output.

Live launcher checks sent ordinary Windows keyboard events and read the running
game's pad socket without modifying guest RAM. Both editions passed all 21
checks: 16 PS2 buttons, four right-stick directions and release. The observed
reports had the correct six/File #1 and 18/File #2 data bytes. Evidence is in
`build-ninja/launcher-controls-check/*-input.json`, with launch/session records
and screenshots beside them. These are input delivery checks, not a complete
playthrough. Physical-controller input was simulated in adapter tests; no
hands-on Xbox or DualSense hardware test was performed. Nothing was published.

### Launcher memory-card and backup verification (2026-10-27)

Each edition retains an independent selected memory-card folder, including after
settings serialization. Named cards can deliberately be selected for either
edition; default cards remain separate. The launcher supports new cards,
existing folder-backed cards and ZIP backup. Restore currently means extracting
the archive into a folder and selecting it with Use existing folder. Raw .ps2
images are not supported.

Backup now acquires the same card lock used by game sessions, rejects output
inside the card itself, stages and atomically replaces the destination, and
cleans temporary files on failure. The UI prevents switching cards, launching
or closing during backup, and generated backup names identify the selected game.
Runtime metadata remains in the archive so extraction preserves the whole card.

Validation: launcher Release build passed; 573 self-tests passed, including
per-edition byte-for-byte backup/extract, metadata preservation, separate card
selection persistence, lock rejection and preservation of previous archives on
failure. `tools/memory_card_check/run.bat` passed 33 RPC/storage checks including
write/read, reopen persistence, directory operations, capacity and formatting.
No user saves were modified. Completed-scenario save/load inside File #2 remains
unverified; these storage checks do not establish that gameplay flow. No release
was published.


### File #2 native co-op integration (2026-10-27)

File #2 uses the existing native Winsock transport and original account/lobby
protocol, with edition-specific original menu addresses and overlay hooks.
The launcher selects the `outbreak2` server plugin, separates hosted account
storage by edition, and uses edition-specific LAN discovery. File #1 discovery
remains wire-compatible. File #2 does not enter File #1 randomizer synchronization.
No release was published.

Verified original-image mappings (SLUS-20984 v1.05):

| Purpose | File #2 original address |
| --- | --- |
| Network workflow / title front end | `6E9490` / pointer `5B7D00` |
| Keyboard work / input delay | `64C160` / `64C148` |
| Original account / password polls | `5A53A0` / `598B20` |
| Account / password workflow stages | 48 / 49 |
| Native-platform step / console-only notice | `613B60` / `619390` |
| Lobby root / room records | `6E2ED0` / `6DEAA0` |
| Game-state block / room | `4DB390` / `30095C` |
| Actor array / stride / position offset | `4C5E10` / `1100` / `38` |

These are corroborated by original instruction words and data references, not
an assumed constant relocation. Raw-image digests and instruction proofs are in
`build-ninja/file2-network-research/verified-network-mapping.json` and
`build-ninja/file2-lobby-research/verified-lobby-instructions.json`.
Only the four known console-service notice pages are omitted in native mode;
server-provided pages and original authentication remain intact.

Runtime discovery found and corrected differences from File #1: initial warning
substep 2; a nested fresh-NET-save dialog; account/password stage numbering;
initial title state `030100`; the bootstrap alias
`snap01.capcom.client.sf.yav4.com`; the initial ten-choice difficulty area page;
and a one-frame title/password keyboard warmup. Fresh NET creation is limited
to its identified missing-file prompt, followed by the original successful-save
information page; other save/card error dialogs are left for the player.

Session `build-ninja/file2-coop-login-07` authenticated two native clients and
reached one waiting room with two members and distinct characters. Manual input
bridged difficulty selection and room-title readiness in that discovery run;
the resulting automation corrections have regression coverage. Starting the
scenario then exposed missing callback `607780` (return address `5B5028`). The
44-byte original function is now mapped and generated, with byte proof in
`build-ninja/file2-network-research/entry607780/verified.json`. That failed start
is retained as evidence, not counted as successful gameplay.

Separately, four synthetic clients passed live loopback File #2 APP/bootstrap/
game authentication, room membership and start, and 24 peer-relay deliveries.
This is server/protocol coverage, not four-player native gameplay:
`build-ninja/file2-server-check/four-client-wire-result.json`.


The subsequent launcher test found a shared join bug: room matching read the
joiner's empty creation-title buffer. Both editions now compare the configured
host title against the exact original room-title field at record offset `18`,
so a room whose name merely starts with the requested title is not selected.
Regression fixtures cover both editions with an empty local title buffer.
Loopback diagnostic hosts also bind all four services only to loopback; normal
LAN hosting retains its all-interface listeners. Release build and all 619
launcher self-test checks passed after these corrections.


Fresh launcher validation `launcher-host10` / `launcher-join10` passed automatic
hosted-server startup, separate account provisioning, fresh NET saves, native
login and shared waiting-room entry without manual pad/keyboard assistance.
`build-ninja/launcher-coop10-result.json` records both original lobby states,
member count 2 and host/guest flags; each session has a positioned screenshot.
Both logs contain login submission and no missing-dispatch/device-loss lines.
These sessions were deliberately stopped after lobby validation while the new
native callback build completed (exit status `0xC000013A`, requested stop).
They do not count as scenario-start or clean-exit tests.


The callback-corrected native session 08 reached scenario loading, then exposed
another original hardware dependency. File #2's SDK seconds getter `1F4110`
reads the EE timer through `11E7F0`; both clients returned a constant
`0x01000000` tick and `0.0` elapsed seconds. The outgoing queue filled, so the
original phase-7 peer barrier at `61A7D4` never received readiness messages.
The backend had already acknowledged both scenario-status requests.

File #2 now uses the shared monotonic `ElapsedSecondsClock` at that verified SDK
getter, only in native online mode. It preserves the original initialization
flag at `36DD70`, previous tick snapshot at `36DD80`, accumulated float at
`36DD78`, and float return register. Offline behavior delegates to the original
function. The separate Count getter remains `16F598`. All 24 clock checks pass,
including reset/offset behavior, concurrent readers and the original send-delay
gate. Original instruction proof: `build-ninja/file2-network-research/file2-network-clock.json`.


Session 09 reached Wild Things gameplay on both native clients and demonstrated
reciprocal movement: host movement 82.83 game units, guest movement 69.03 units,
with settled peer position differences below 0.62 units. Both clients reported
room 3 and different local player slots; moving one client left the other
player stationary. Evidence: `build-ninja/file2-coop-gameplay-09/movement-verification.json`.

That run also exposed main entry `1B6418`, an independent original function
absorbed into the existing generated `1B63C0` range. An entry adapter now executes
its original prologue and `1B3C30` call, then resumes the existing generated
`1B642C` continuation. Both original tail-call paths are retained. No synthetic
return or gameplay bypass is used. All 18 original instruction words were
checked against the ELF (`build-ninja/file2-network-research/entry1B6418.json`).


Final replay **PASS**: `build-ninja/file2-coop-gameplay-10/verification.json`.
Both clients automatically signed in and joined one room, started Wild Things,
and reached interactive gameplay in about 18 seconds. Ordinary pad input moved
player 1 by 79.73 units and player 2 by 69.03 units; the other player remained
stationary during each isolated input. Both clients observed these movements,
with settled peer-coordinate differences below 0.62 units. Both reported room
3 with distinct local slots. Screenshots and before/after position captures
are retained in the session. Both exited normally with code 0 after verified
window-close requests; both logs had zero fatal/missing-function/device-loss
findings. Final native executable SHA-256:
`0ab348772b5a0e640ff0d9753e26aa8fef5795884c1b9fe94764c5e0b0c026e8`.

Scope: two native clients through first-room gameplay and reciprocal movement,
plus four synthetic clients for server protocol/relay coverage. Full scenario
completion, saved multiplayer progress, four simultaneous native clients,
and remote Internet/NAT play were not exercised. All temporary native clients,
launcher hosts and local test-server services were stopped. Changes remain
local on `file2-port`; nothing was published.


### D-pad tank controls restored (2026-10-27)

Branch `fix/dpad-tank-controls` removes the shared libpad2 feeder's conversion
of every digital direction into a full left-stick deflection. Both games now
receive D-pad and analog input independently, restoring the original tank
control path for a controller D-pad while retaining camera-relative stick
movement. No gameplay control thresholds or original movement functions were
changed. Keyboard input already supplies its own stick values.

Original gates were checked against 776 instruction words across both games:
File #1 `662288` and File #2 `687688` enter camera-relative processing only when
analog magnitude is at least 16. Evidence:
`build-ninja/file2-network-research/dpad-analog-gates.json`.

Both native builds and the Release launcher built successfully; all 639
launcher checks passed. New adapter checks cover all eight D-pad directions,
independent analog movement, and simultaneous digital/analog input for both
games. Native input/gameplay probes passed in File #1 single-player and File #2
co-op: D-pad left/right changed yaw with zero displacement and zero analog
magnitude; D-pad up travelled approximately 54 units with unchanged yaw; stick
left/right travelled approximately 54 units with nonzero analog magnitude.
Input used private controller reports; guest RAM was read-only. This does not
constitute a physical controller hands-on test. All three clients exited 0
with no fatal/missing-function/device-loss findings; temporary services were
stopped. Verification: `build-ninja/dpad-tank-check/verification.json`.
No release was created.

### Launcher crash: stub entries and async VIF1 (2026-10-28)

A File #2 session launched from the launcher stopped at ~110 s with
`Async VIF1 wait attempted under IO ownership`, after
`Function at address 0x15bcc0 not found` (called from ovl2 `0x58E500`).

- `0x15BC90` is four 16-byte entry stubs (`j 0x15BCD0` with `a0` = 0..3) and a
  shared body; the map merged them into one function, so `0x15BCA0/B0/C0` and the
  body were unregistered. Added to `extra_functions.csv` and regenerated with the
  pinned v1.0.19 recompiler. A scan of the main ELF and all overlays found no
  other stub table of this kind. File #1 merges the same stubs (`0x1D3BA0`) but
  never calls the later entries.
- The async error is separate. Captured stack (WinDbg/cdb, link-time PDB):
  `o0_00396390` (from the per-frame service `0x1EDCB0`) -> `Store8` -> `PS2Memory::write8`
  -> `writeIORegister` -> async VIF1 access check -> `drain` -> throw. File #2 starts GIF
  DMA with a byte store to `D2_CHCR` (`0x1000A000`); File #1 uses 32-bit stores. The
  byte/halfword IO path held the IO lock around `writeIORegister`, so a drain needed
  after the worker picked up new work could not wait. Runtime patch `0108` merges the
  byte/halfword value under the lock and writes it after releasing the lock, exactly
  like a 32-bit store.
- Verified with the launcher's settings (GPU movies, async worker, 16:9, 2x, FXAA):
  17 File #2 runs of 100-140 s from boot into the gameplay overlay with the worker
  active, no errors or missing functions. One early run froze at ~32 s (host loop
  stopped, no error); 12 later runs with a hang catcher (cdb attach on stall) did not
  reproduce it. File #1 with the worker: 2 runs to scenario, clean.

### File #2 gameplay cheats (2026-10-28)

Baseline: Windows x64, `develop` at `9d9e089`, SLUS-20984 NTSC-U v1.05.
The launcher blocked File #2 cheats and bootstrap installed the hook only for
File #1. File #2 now exposes Full health, No infection, Infinite ammunition,
and compatible `.pnach` data writes. Selections and imports are game-specific;
File #1 selection identities are preserved. Cheats require offline play.
Older File #2 executables are rejected when cheats are selected.

The original frame service is retained at `0x1EDCB0`. Original opcode readers
and the live Training Ground RAM establish these File #2 fields:

| Field | Address / actor offset | Evidence |
|---|---|---|
| Gameplay / selected player | `0x4DB390` / `+0x1D` | Matched main data references; live RAM |
| Actor base / stride | `0x4C5E10` / `0x1100` | `0x609F38..0x609F50` |
| Health / maximum | `+0x540` / `+0x542` | `0x59B44C`, live 2300/2300; File #1 offsets differ |
| Infection | `+0xBC4` | `0x684F2C..0x685014` |
| Dead-state guard | `+0xBE8` | `0x6102C0` |
| Inventory handles | `+0xC94`, five slots | `0x5A1318`; live carried/personal slots |
| Item pool / stride | `0x3E1C20` / 60 | `0x5D0450..0x5D0478` |
| Metadata / loaded count | `0x7ACA00` / `0x7ADA20` | `0x5B0640..0x5B066C` |

Validation: both native game targets build; Release launcher builds without
warnings. `cmd /c tools\cheat_check\run.bat` passes 76 File #2 checks, the
55 existing cheat checks and existing mod fixtures. The new checks cover all
four player slots, complete RAM write boundaries, dead/menu guards, firearm
categories, catalogue bounds and independent effects. Launcher `--self-test`
passes 710 checks, including export isolation, master switch and co-op rejection.

A first bounded run exposed the differing health offsets and was corrected.
The rebuilt 90-second controlled run then loaded Training Ground with a private
card. Data cheats continuously set living player health to 1200, infection to
1234 and the personal gun to zero rounds before built-ins ran. Both 65/80-second
RAM snapshots show 2300/2300 HP, zero infection and seven rounds; a separate
`0xCAFEBABE` data write also applied. Native diagnostics report one firearm
slot. Clean close, exit 0; no missing functions or device loss. Private evidence:
`build-ninja/file2-cheats/live-verification.json` and
`build-ninja/smoke/20261028-095634-file2-cheats-controlled/`.
This verifies restoration after controlled writes, not natural enemy damage,
firing cycles, full-scenario coverage or multiplayer cheat replication.

**Unlock everything remains File #1 only.** File #2 progression fields are not
implemented; its native hook rejects that built-in before applying any writes.
No release kit was exported or published.

### File #2 randomizer support (2026-10-28)

The launcher and native target now support the File #2 Randomizer package with
shared item/exclusion/seed rules, protected progression and starting equipment,
scripted enemy-family preservation, canonical host-synchronized spawn plans and
six-family room limits. File #2 has separate mod imports/preferences and a
supported native roster. Global data/models/material aliases are fitted within
each scenario's original capacities; unavailable floor-model definitions cannot
become replacements. See `FILE2_RANDOMIZER.md` for original-code evidence,
format details and the complete validation scope.

Both native targets and the Release launcher build. 634 File #2 randomizer
checks and 707 release launcher checks pass, as do existing File #1 fixtures and cheat
checks. Actual-disc asset generation and native table validation pass all 12
scenario banks. Bounded live runs cover Training Ground and Wild Things;
Wild Things seed 43 with exclusions `[0,309]` changed 89 eligible items and
prepared a 34-record enemy plan, reached a rendered controllable room and
closed cleanly with exit 0. Extended final-build checks also verified normal
pickup/equip/firing of a randomized rocket launcher without cheats and completed
zombie-to-dog native reconstruction, visible attacks, received gunfire and death.
The latter damage test used player health/ammo builtins; enemy health remained
under the original game code. A reproduced mid-frame texture-scratch/UI overlap
was fixed with exclusive loading scratch and restoration of all three native
aliases. Read-only observers confirmed intact UI pointers and no null DMA jobs.
See `FILE2_RANDOMIZER.md` for receipts and scope. Full scenarios, save/resume,
every profile and live co-op combat remain unverified.
