# REO baseline (Milestone 0)

Status key: `DONE` = reproduced here with evidence; `FAIL` = attempted and failed; `BLOCKED` = cannot attempt yet; `IN PROGRESS`.

Recorded: 2026-10-08. Updated as each step completes.

## Checkout

| Item | Value |
|---|---|
| Fork | `git@github.com:Ninjacornix/reo.git`, branch `main` |
| Commit | `73ad3c9f8802b48b811f17dd6bb7d815afb9a727` (= upstream `sp00nznet/reo` HEAD, 2026-04-10) |
| Local-only changes | `CLAUDE.md`, `ROADMAP.md`, `REVERSE_ENGINEERING.md`, this file, `.gitignore` (+`iso/`) |

## Machine / toolchain

| Item | Value |
|---|---|
| OS | Windows 11 Pro 25H2, 10.0.26200 |
| CPU / RAM | AMD Ryzen 5 2600 (6C/12T) / 16 GB |
| Compiler | Visual Studio 2022 Community 17.13.2, MSVC 14.43.34808 (Desktop C++ workload added 2026-10-08) |
| CMake | 3.30.5-msvc23 (bundled with VS; not on PATH) — `C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe` |
| Vulkan SDK | 1.4.321.1 (`C:\VulkanSDK\1.4.321.1`) — found by CMake, but `reo_recomp` does not link Vulkan |
| Python | 3.12.10 |
| Reference emulator | PCSX2 2.2.0 at `C:\Users\Ninjacornix\ps2\pcsx2-qt.exe`; settings in `Documents\PCSX2\inis\PCSX2.ini` (`EnablePINE = false`, `PINESlot = 28011`) |
| RE tools | Ghidra 12.1.4 + ghidra-emotionengine-reloaded v2.1.38 + ghidra-mcp 7.0.0 (JDK 21.0.12) |

## Game data (user-owned, never committed)

| Item | Value |
|---|---|
| ISO | `iso/Resident Evil - Outbreak (v2.00).iso`, SHA-256 `69AE2C48E6F01E2605659FEABB54EB9B82C63A809BDC8A78AD2D160B3C59A4A1` |
| `SYSTEM.CNF` | `BOOT2 = cdrom0:\SLUS_207.65;1`, `VER = 2.00`, `VMODE = NTSC` |
| Boot ELF | `game_data/SLUS_207.65`, 1,417,920 bytes, SHA-256 `06BD5FD7243144CD30CDD0C0023763A369738CB91B177B35E85F6A4782B4CA46` |
| ELF header | e_machine 8 (MIPS), entry `0x00100008`, e_flags `0x20924000` (MIPS III, mach R5900, EABI64) |
| Disc root | `NETBIO00-02.DAT` (~4.2 GB), `IOP/`, `BIN/`, `NTGUI2/`, `*.BIN` |

Runtime data paths (`recomp/reo_bootstrap.cpp:125-133`): `cdRoot = hostRoot = --data` (default `game_data`), memory card → `./saves` (CWD, gitignored). Mounting the ISO and passing `--data <drive>:\` avoids copying 4.2 GB.

## Licensing

| Component | License | Notes |
|---|---|---|
| REO (upstream and this fork) | **none** — no LICENSE file; GitHub reports no SPDX license | All rights reserved by default. Redistribution of source or binaries is not established. |
| PS2Recomp (`ran-j`, pinned fork `sp00nznet`) | GPL-3.0 | `ps2_runtime.lib` is statically linked into `reo_recomp`; distributing that binary implies GPL-3.0 obligations for the combined work. |
| ELFIO | MIT | |
| fmt | MIT-style | |
| rabbitizer | MIT | |
| toml11 | MIT | |
| raylib (+GLFW) | zlib | |
| libdwarf | LGPL-2.1 (per COPYING; not fully reviewed) | |
| Generated `recomp/config/output*` | derived from Capcom's copyrighted ELF | Upstream commits it; legal status for redistribution unclear. Do not add more proprietary payloads. |

**Conclusion (2026-10-08):** the fork owner has discussed use with the original authors; this fork is for local testing only and is not redistributed. Licensing is not a blocker for development. Revisit only if builds or sources are ever published.

## Repository vs README

The README tree is aspirational. Missing: `tools/vu_disasm`, `recomp/patches`, `recomp/config/output_file2` (so the File #2 target is skipped at configure time), `network/server`, `game/scripts`, `game/ui`, `third_party/{parallel-gs,SDL3,volk}`. `network/dnas/dnas_bypass.*` exists; it is out of scope under `CLAUDE.md` (no auth bypass) and must not be on the account-free P2P path.

Real targets: `reo_recomp` (File #1 game), `reo_recomp_file2` (skipped), `reo` (scaffold `src/main.cpp`), runtime/network/media/game libraries, tools `reo-extract`, `elf_analyze`, `gs_dump_replay`.

Committed generated code: `recomp/config/output/` 3,834 files (3,832 `.cpp`); `recomp/config/output_overlay/` 97 files (96 `.cpp`, overlay code at `0x370000+` dumped from PCSX2).

## PS2Recomp dependency

- `third_party/PS2Recomp` is a **gitlink without `.gitmodules`** pinned at `5a778f7103445eb92554dd1a3315cd40861dde1c` ("Port REO hardware bridge callbacks to upstream runtime", 2026-04-07). That commit exists only in `https://github.com/sp00nznet/PS2Recomp` (not `ran-j/PS2Recomp` `main`). The README's `git clone ran-j/PS2Recomp` gets the **wrong** revision.
- Reproduce:
  ```sh
  git clone https://github.com/sp00nznet/PS2Recomp.git third_party/PS2Recomp
  git -C third_party/PS2Recomp checkout 5a778f7103445eb92554dd1a3315cd40861dde1c
  git clone https://github.com/serge1/ELFIO.git deps/elfio
  git -C deps/elfio checkout 7d30a22fc5aac06adfe7887ae57f3701b6b5f913
  cmake -S third_party/PS2Recomp -B third_party/PS2Recomp/out/build -G "Visual Studio 17 2022" -A x64 \
        -DFETCHCONTENT_SOURCE_DIR_ELFIO=<abs path>/deps/elfio
  cmake --build third_party/PS2Recomp/out/build --config Release --target ps2_runtime ps2_recomp ps2_analyzer
  ```
- **Defect:** PS2Recomp pins ELFIO by commit with `GIT_SHALLOW TRUE`, which fails (`fatal: unable to read tree (7d30a22…)`). Worked around with `FETCHCONTENT_SOURCE_DIR_ELFIO` (no source edit).
- **Unpinned deps:** `toml11` (`master`), ImGui family (`docking`/`master`/`main`, Studio only). Resolved here: toml11 `b389bbc`, fmt `407c905e` (12.1.0), libdwarf `2e088b9` (v2.2.0), rabbitizer `d5804fa` (1.14.3), raylib `c1ab645c` (5.5).
- Result: **DONE** — `ps2_runtime.lib`, `ps2_recomp.exe`, `ps2_analyzer.exe` built in 190 s, no errors.

## Generated-code reproducibility — FAIL

Regenerating File #1 with the pinned `ps2_recomp.exe` and `recomp/config/outbreak.toml` (output redirected to a scratch dir; 14 s):

| Metric | Committed | Regenerated |
|---|---:|---:|
| Files | 3,834 | 3,464 |
| Files only in this set | 370 (369 `entry_*`, `sub_001AC640`) | 0 |
| Byte-identical common files | 1 / 3,464 | |
| Files containing `printf(` | 29 | 0 |

Interpretation:
1. Committed output comes from an **older codegen**: separate `entry_*` files for mid-function entries, while the pinned recompiler emits a `switch (ctx->pc)` resume table inside the parent function. The regenerated `register_functions.cpp` still registers e.g. `0x13f058`.
2. At least **29 generated files are hand-edited** (debug `printf` instrumentation, e.g. `sub_001D3DC0_0x1d3dc0.cpp` prints `[D3DC0] entered …`). Other manual semantic edits may exist and are not separately recorded.
3. Therefore **do not regenerate `recomp/config/output/`** until the manual edits are inventoried and moved to overrides. This violates the `CLAUDE.md` rule to keep generated code separate from patches; track it as tech debt.
4. **The committed output predates codegen fixes that reo itself says are applied.** Commit `f481ed2` lists "EE sign-tested branches use 64-bit GPR comparison" among the PS2Recomp fixes. The committed files still emit 32-bit compares. Normalized diff of `sub_001DFDA8` (labels, comments, casts and S32/U32 naming stripped): 2,724 differing lines, including:

   | MIPS | committed (old codegen) | pinned `ps2_recomp` | R5900 |
   |---|---|---|---|
   | `beq`/`bne` | `GPR_U32(a) == GPR_U32(b)` | `GPR_U64(a) == GPR_U64(b)` | 64-bit compare |
   | `andi`/`ori` | `SET_GPR_U32(AND32(GPR_U32, imm))` (sign-extends 32-bit result) | `SET_GPR_U64(GPR_U64 & (uint16_t)imm)` | 64-bit, zero-extended imm |
   | `lw` | `SET_GPR_U32(READ32)` | `SET_GPR_S32((int32_t)READ32)` | equivalent: both macros sign-extend via `(int64_t)(int32_t)` |

   These are equivalent while every GPR holds a sign-extended 32-bit value, but not after true 64-bit producers (`ld`, `dadd*`, `dsll*`, `pmfhi`, …). **Candidate cause of divergences for Milestone 1.**

### Exception: `sub_001DFDA8` regenerated (2026-10-09)

`sub_001DFDA8` (`0x1dfda8`–`0x1e1b3c`, ~1,893 instructions) was 147,008 lines in the committed output. Each of its 72 indirect jumps emitted a `switch` over all 1,893 labels, 136,296 `case` lines in total. MSVC could not compile it on this 16 GB machine: the front end alone exceeded 12 GB, at `/O2` and at `/Od`. The file is **replaced with the pinned `ps2_recomp.exe` output** (23,337 lines, 14,948 cases). It compiles at `/O2` in 18 s. It is not one of the `printf`-instrumented files. This is the only generated file that differs from upstream; `git checkout recomp/config/output/sub_001DFDA8_0x1dfda8.cpp` restores the original. Its semantics follow the newer codegen (64-bit branch compares; see the table above). Validation status: compiles; behaviour **unverified**.

Same treatment for `sub_001401F8` (`0x1401f8`–`0x1407e0`, 378 labels): 15 indirect-jump switches, 5,670 cases and about 5,800 `goto`s in 8,104 lines. Memory was fine (about 1 GB), but `/O2` ran for more than 42 CPU-minutes without finishing. It is replaced with the pinned output (2,682 lines), which compiles in seconds. Not `printf`-instrumented. Normalized diff: 971 lines.

**Root cause, both files:** the old codegen emitted a full all-labels `switch` at every `jr`. Any other generated function with many labels and many `jr` sites has the same compile-time and code-size problem. These two were the only ones that blocked the build.

## REO build — DONE (2026-10-09 01:20)

```powershell
cmake -B build -G "Visual Studio 17 2022" -A x64      # PASS (4.1 s); File #2 target skipped: no sources
cmake --build build --config Release --target reo_recomp
```

`/MP4` (hard-coded in `recomp/CMakeLists.txt`) is memory-bound on 16 GB: 4 `cl.exe` processes use 600–750 MB each, leaving about 2 GB free. Measured rate is about 16 TU/min (≈4 h for 3,942 TUs).

**MSBuild restart defect:** when the build was killed at 1,529/3,942 (Claude Code low-memory reaper), the restarted MSBuild rebuilt *every* file. The interrupted run left change-tracking `.tlog`s inconsistent, plus 0-byte `.obj`s.

### Faster, resumable build (adopted)

Measurements (exact Ninja command line, idle machine, `sub_0015D1D0` = 1,811 lines; small = `sub_0012C890`, 44 lines):

| Variant | small file | 1,811-line file |
|---|---:|---:|
| no PCH, `/O2` | 2.7 s (≈ header parse) | — |
| PCH, `/O2` / `/O2 /Ob1` / `/O1` / `/O1 /Ob1` | 1.1 s | 42.5–43.7 s |
| PCH, `/Od` | — | 6.9 s |

File-size distribution of `output/`: 2,872 files < 300 lines; 739 in 300–1k; 168 in 1k–3k; 38 in 3k–10k; 15 > 10k (largest `sub_001DFDA8`, 147,008 lines). Total 1.54 M lines.

Changes in `recomp/CMakeLists.txt` (upstream default behavior preserved):
- `REO_RECOMP_PCH` (default ON): precompiles the six runtime headers that every generated file includes. Hand-written sources skip the PCH.
- `REO_RECOMP_OPT` (default `/O2`): optimization flag for generated/overlay sources only; hand-written sources stay `/O2`. `/O1` showed no compile-time gain; `/Od` is about 6× faster to compile but untested for runtime speed.
- `/MP4` only applies to Visual Studio generators.

Ninja build (resumable: only in-flight files are lost on kill):
```bat
call "%VSINSTALL%\VC\Auxiliary\Build\vcvars64.bat"
cmake -S . -B build-ninja -G Ninja -DCMAKE_BUILD_TYPE=Release -DREO_RECOMP_OPT=/O2 -DREO_RECOMP_PCH=ON ^
      -DCMAKE_MAKE_PROGRAM="%VSINSTALL%\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja\ninja.exe"
ninja -C build-ninja -j 6 reo_recomp
```
At `-j 6`, 6 `cl.exe` use about 1.4 GB total, and about 5.5 GB stays free (Ghidra open). Rate is about 91 TU/min, 5–6× the MSBuild rate.

## Run — FAIL (crash at boot, cause identified)

```powershell
powershell -ExecutionPolicy Bypass -File tools\smoke_test.ps1 -Iso "iso\Resident Evil - Outbreak (v2.00).iso" -Seconds 60
```

Run `build-ninja\smoke\20261009-012044` (2026-10-09 01:20, commit `73ad3c9` + changes in this file):

| Checkpoint | Result |
|---|---|
| raylib/OpenGL init | OK: RX 570, GL 3.3 core, window 640x448 |
| ELF load, 3,829 functions + 96 overlays registered, overrides applied twice | OK |
| Entry `0x00100008` | reached |
| First GS/GIF activity | **none**: `gif_packets=0 vif1_dmas=0 vu0_runs=0 vu1_runs=0 gs_reg_writes=0` |
| Exit | after **1.6 s**: `Unimplemented PS2 stub called: sub_0011D6D0` (PC=0x11d6d0, RA=0x11d918, a0=0x8aa380, a1=0xffffffff, a2=0x10000) |

Root cause (confirmed from source):
1. `0x11D6D0` (`sceGsResetGraph`) is in the `skip` list, so the generated stub body calls `ps2_stubs::TODO_NAMED("sub_0011D6D0", …)`. The caller `sub_0011D908` reaches it by a direct C++ call.
2. reo's `bind()` registers both `runtime.registerFunction` and `ps2_stubs::registerStubOverride`. In the pinned PS2Recomp `5a778f7`, `registerStubOverride` writes `s_stubOverrides`, but **nothing reads it**: `TODO_NAMED` always throws. So none of reo's 93 bindings work for direct calls into skipped functions.
3. Upstream fixed this in sp00nznet/PS2Recomp `7d1da29` (2026-07-11, "TODO_NAMED dispatches to registered stub overrides"). That fix is only referenced from upstream reo branch `pivot-selfexec`, not `main`.

Secondary observation: `[CDVD] Mapped 1 files from …\game_data` means the reo CDVD bridge maps the ELF directory, not `--data`. Disc files would not be visible even after the crash is fixed.

**The README's title-screen claim does not reproduce on `main` at its pinned dependencies.**

## Upstream state beyond `main`

`sp00nznet/reo` branch `pivot-selfexec` (`92a9bc3`, 2026-07-15) is 13 commits ahead of `main`. It recompiles 100% of the game (1 stub), un-skips 105 SIMD functions, fixes SIF RPC/boot-status gates, and pins PS2Recomp `c46d1c7` (includes `7d1da29`). Per the ROADMAP branch strategy ("merge upstream selectively"), it is evaluated as the new baseline on branch `baseline/pivot-selfexec`; see that branch's copy of this file.

## Open items

- [ ] Finish build; record warnings/errors and time.
- [ ] Smoke run; record boot log, first visible frame, hang/crash point.
- [ ] Verify `REO_TRACE`, `gs_dump_replay`, and PCSX2 PINE scripts (`tools/ps2_debug`, PINE must be enabled in PCSX2).
- [ ] Inventory hand-edits in `recomp/config/output/` (diff against regenerated output at the old codegen revision if recoverable).
