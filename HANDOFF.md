# Handoff: REO (Resident Evil Outbreak File #1 → native Windows)

Last updated 2026-10-10, branch `m1/ghidra-regen`. Read `CLAUDE.md`, `ROADMAP.md`, and `docs/DIVERGENCES.md` (D28–D40 plus the "Milestone-1 checkpoint" sections) and `HANDOFF_CODEX_M1_VIDEO.md` first.

## Where things stand

- **Milestone 1 is done.** With real Start presses and no bypasses, the game goes: memory-card prompt → logos → content warning → title movie → **main menu** (SINGLE PLAY … HDD INSTALL). This held in 5 of 5 runs (frame hash `2cf69504`). The checkpoint table and exact command are in `docs/DIVERGENCES.md`.
- **The title movie plays with real images** and the main menu shows over it. The green was D36: sound-driver HLE zeroed EE RAM over the game's code (fixed by Codex, patch 0020).
- **The movie runs at full speed (~29.2 fps average; the streams declare 29.97)** with the GS worker thread (D37, patch 0021). The stray `ResetEE` calls are fixed (D38). The `[perf]` heartbeat line shows frames/s and per-thread CPU time.
- **User rule:** do not start Milestone 2 until the user agrees that the M1-era problems are solved.
- **Next milestone (M2):** menu selection input (untested), then load one File #1 scenario.

## Build

| Step | Command |
|---|---|
| Runtime library (PS2Recomp, VS CMake) | `"C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" --build third_party/PS2Recomp/out/build --config Release --target ps2_runtime` |
| Game exe (Ninja, `build-ninja/`) | `cmake --build build-ninja` from a VS x64 dev prompt. Relinking alone is fast; a full rebuild takes about 70 min at 8 jobs. |

- sccache is on (`REO_USE_SCCACHE`), and unity builds use batch 8.
- **Do not touch `ps2_runtime.h` / `ps2_memory.h`** or add target-wide defines: either forces a full rebuild.
- PS2Recomp changes live as patches in `third_party/patches/ps2recomp/0001…0019`. After changing PS2Recomp sources, regenerate the next patch as a diff against a pristine checkout with 0001–N applied, then verify the chain.
- Extra functions that Ghidra merged into neighbours are listed in `recomp/config/extra_functions.csv`.
  - Regenerate them with `python -I tools/extra_recomp.py <abs path ps2_recomp.exe> <abs path game_data/SLUS_207.65>`.
  - Use absolute paths: the tool clears `output_extra/` before it runs.
- Code overlays: `tools/overlay_extract.py`, `tools/overlay_recomp.py`.

## Run / test

```
tools\smoke_test.ps1 -Iso "iso\Resident Evil - Outbreak (v2.00).iso" -Seconds 130 -Label X -Env 'REO_NATURAL=1;REO_PAD_SCRIPT=21:LEFT:0.5,24:CROSS:0.5,85:START:0.3,88:START:0.3,...;REO_SHOT_AT=60,100,125'
```

- Output goes to `build-ninja/smoke/<time>-X/`: `stderr.log`, `stdout.log`, and `shot_*.bmp`. Convert the shots with the PNG helper (any BMP→PNG script).
- If a run fails to mount the ISO, run `Dismount-DiskImage` first.
- The ISO is owned and local; never commit game data.
- Useful env switches:
  - Diagnostics: `REO_SFD_DIAG`, `REO_THREAD_LOG`, `REO_CRI_ERRLOG`, `REO_PEEK=addr,...`, `REO_STACKDUMP_AT=s`, `REO_HW_WATCH`, `REO_IPU_LOG`, `REO_CD_LOG`.
  - Panel: `REO_DEBUG_PANEL`.
- The heartbeat `[hot]` line samples **only the main thread's** PC. `pc5/6/7` show the CRI threads.

## Reference tools

- **Ghidra:** MCP at `127.0.0.1:8089`, program `/ps2/SLUS_207.65`, overlays `/ovl/ovl<n>.elf`. Launch with the batch file that runs `support\launch.bat ... < nul` (see memory notes). Verify everything against raw disassembly: the decompiler hid the `SleepThread` in the D34 worker loop.
- **PCSX2:** `C:\Users\Ninjacornix\ps2\pcsx2-qt.exe`, with PINE enabled on slot 28011.
  - Use `tools/ps2_debug/pine_client.py`; kernel RAM is readable at `0x8000xxxx`.
  - EE thread control blocks are spaced 0x4C apart near `0x80017424`. Careful: the offsets I first assumed were off by one block.
  - `tools/ps2_debug/pcsx2_sfd_probe.py` (D34 reference probe) launches PCSX2 on the ISO and logs CRI/Sofdec field changes.

## Key facts learned

- **Threads:** main is thread 1 (priority 24). CRI threads are 4 (helper `0x12aba0`), 5 (`0x12ac90`, prio 16), 6 (`0x12ad70`, 18) and 7 (`0x12ae50`, 25, the Sofdec server). EE semantics: no time-slicing.
- **D34:** `WakeupThread` on a WAITSUSPEND sleeper must release the sleep, not queue a wakeup.
  - The opt-ins `REO_IMMEDIATE_SWITCH=1` (immediate higher-priority switch) and `REO_SPIN_ROTATE=1` (an equal-priority rotation heuristic) are not needed.
  - Do not enable `REO_SPIN_ROTATE`: it breaks CRI's lock.
- **Sofdec:**
  - Player `0x22DEC0`; global `0x22DE58` (`+0x24` decode gate).
  - Decoder handle table `0x22F18C`. Decoder fields: `+0x44` request pending, `+0x48` state.
  - Server group 6 pass counter: `0x22A610`.

## Suggested next steps

User-reported problems still open (user rule: no Milestone 2 until they are solved):
1. **Movie/menu audio is silent** (demonstration video has no music). Not investigated yet: check the IOP sound driver HLE / SPU2 / audio backend.
2. **Dragging the window stops rendering** until released; the game keeps running underneath. The raylib/GLFW window loop is blocked in the Win32 modal move loop. Fix: render from a timer during WM_ENTERSIZEMOVE…WM_EXITSIZEMOVE, or move rendering to its own thread.
3. **Logo fades still run below real time** (D39: ~2.5 s worst heartbeat). Remaining cost: per-pixel swizzle addressing in fills and the scaled-bilinear path.
4. **Scenario select (SINGLE PLAY) lags.** Not profiled yet; use the `[perf]` sprite mix plus `REO_STACKDUMP_*`.
5. Done in patch 0022: logo freeze (D39), movie stutter / presentation cadence and purple first frame (D40). Confirm with the user.

## New switches (2026-10-10)

- `REO_TURBO=<2..16>`, `REO_TURBO_UNTIL=<guest addr>`: test-only vblank fast-forward (boot logos); returns to normal speed when the word becomes nonzero.
- `REO_GS_NO_FASTPATH=1`: disables the D37 sprite fast paths (A/B checks).
- `REO_GS_THREAD=0`: runs the GS synchronously instead of on the worker thread (default on).
- `REO_GS_NO_PARALLEL=1`: no row-band parallel sprite drawing. `tools/gs_fastpath_check/run.bat` verifies fast vs generic GS output.
- `REO_PRESENT_DUMP_AT=<s>`: dump 4 consecutive presented frames (present_N.bmp).
- `REO_STACKDUMP_AT=<s>` with `REO_STACKDUMP_N=<n>`: n host stack samples 20 ms apart. Symbolize them with a `/MAP` link of the same objects.
- `REO_SPR_LOG=1`, `REO_IPU_LOG=1`, `REO_MPEG_PIC_LOG=1` (Codex), `REO_SFD_DIAG=1`: movie path diagnostics.
- Self-tests: `tools/ipu_selftest/run.bat` (all pass), `tools/runtime_selftest/run.bat` (26/26).
un.bat` (all pass), `tools
untime_selftest
un.bat` (26/26).
