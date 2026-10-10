# Handoff: REO (Resident Evil Outbreak File #1 → native Windows)

Last updated 2026-10-11, branch `m1/ghidra-regen`. Read `CLAUDE.md`, `ROADMAP.md`, `docs/DIVERGENCES.md` (D28–D44 plus the "Milestone-1 checkpoint" sections) and `HANDOFF_CODEX_M1_VIDEO.md` first.

## Where things stand

- **Boot → main menu works** with real input and no bypasses: memory-card prompt → logos → content warning → title movie → main menu (SINGLE PLAY … HDD INSTALL) → SINGLE PLAY → SCENARIO and back.
- **Video:**
  - The title movie decodes correctly (D36) and plays at full speed (~29.2 fps average; the streams declare 29.97) with the GS worker thread (D37).
  - Logo fades run in real time (D43).
  - Presentation is one frame per vblank, captured after the game's flip (D40, D41, D44).
- **Milestone 1 is NOT closed yet.** User rule: Milestone 1 stays open until the user agrees its problems are solved. In particular **audio must play and be properly synced**. Do not start Milestone 2 before that.

## Open problems (in priority order)

1. **No audio at all (blocker for M1).** Findings so far:
   - CRI audio stack in the EE binary: ADXT/PS2EE 8.92, ADXPS2 2.45, PS2RNA 1.21, SJX 1.05 and DTX 1.04 (version strings at 0x23a2b8, 0x23a488, 0x23d4b0, 0x23dac8, 0x23c920). Upstream emulates only their IOP halves, in `Kernel/Syscalls/RPC.cpp`.
   - Data path: EE → DTX mailboxes (`sceSifSetDma`, 0x880-byte packets; channel 0 = SJX, EE 0x229d40 → IOP 0xdf140; channel 1 = PS2RNA, EE 0x223ec0 → IOP 0xf4040) → SJX chunks → SJRMT ring buffers → PS2RNA output. Upstream's PS2RNA "playback" only discards data, so a host output path is also needed (raylib `InitAudioDevice` is already initialised; `PS2AudioBackend` exists).
   - Observed: 3 PS2RNA streams (2 stereo, 1 mono) and 5 SJX/SJRMT pairs are created, then each DTX mailbox runs only **8 rounds during startup, all with empty packets, and goes silent**. No SJX data or PS2RNA START is ever sent; no CRI errors.
   - Hypothesis: the EE DTX side waits for an IOP→EE response (ticket/receive buffer) that our emulation never provides, which stalls all CRI streaming.
   - EE DTX code: object table `0x21c430` (8 × 0x44: +0xC EE work area, +0x14 uncached footer address, +0x18 IOP address, +0x1C size, +0x20 send callback `0x138ea8`, +0x28 receive callback `0x138ec0`); `DTX_Create` = `FUN_00138f78`, init/bind = `FUN_001392f8`. The DTX server is among `0x138ba8 … 0x139198`; next, decompile it and see what it waits for.
   - After streaming works: play PCM through a host audio stream at the PS2RNA rate (`SETSFREQ`), with proper flow control (consume at playback rate) and A/V sync. Sofdec may use audio time as its clock.
   - Diagnostics: `[PS2RNA-cmd]`, `[SJX-cmd]`, `[PS2RNA]`, `[PS2RNA-rate]` log lines; `REO_DTX_DUMP=1` (packet hex dumps); `REO_CRI_ERRLOG=1`.
2. **Darkened title after Circle (unconfirmed).** Backing out of SCENARIO with Circle shows the title dark (~2 s, brightness ~15 against a normal ~40), then a slow fade-in. During that time the game runs normally: steady GS packets, the movie decoding at 30 fps, no disc reads, one present per vblank. It needs a reference: the user was asked to check the same sequence in PCSX2. If real hardware fades in faster, a likely suspect is the missing audio clock (Sofdec timing).
3. **Scenario select (SINGLE PLAY) lag** reported by the user. Not profiled yet; use the `[perf]` sprite mix and `REO_STACKDUMP_*`.
4. **Recently fixed, awaiting the user's confirmation:** logo freeze (D39), presentation cadence and purple first frame (D40), flashing memory-card text / flicker (D41), rendering while dragging the window (D42), choppy logo fades (D43), transition flicker / hitches (D44).

## Build

| Step | Command |
|---|---|
| Runtime library (PS2Recomp, VS CMake) | `"C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" --build third_party/PS2Recomp/out/build --config Release --target ps2_runtime` |
| Game exe (Ninja, `build-ninja/`) | `cmake --build build-ninja` from a VS x64 dev prompt. Relinking alone is fast; a full rebuild takes about 70 min at 8 jobs. |

- New runtime source files are picked up only after re-running CMake on `third_party/PS2Recomp/out/build` (building only the `ps2_runtime` target skips the glob re-check).
- sccache is on (`REO_USE_SCCACHE`); unity builds use batch 8.
- **Do not touch `ps2_runtime.h` / `ps2_memory.h`** or add target-wide defines: either forces a full rebuild.
- PS2Recomp changes live as patches in `third_party/patches/ps2recomp/0001…0027`. After changing PS2Recomp sources, generate the next patch as a diff against a pristine checkout with 0001–N applied, then verify the chain.
- Extra functions Ghidra merged into neighbours: `recomp/config/extra_functions.csv`; regenerate with `python -I tools/extra_recomp.py <abs ps2_recomp.exe> <abs game_data/SLUS_207.65>` (absolute paths; the tool clears `output_extra/` first).
- Code overlays: `tools/overlay_extract.py`, `tools/overlay_recomp.py`.

## Run / test

- **Play interactively:** `powershell -ExecutionPolicy Bypass -File tools\play.ps1 [-SkipIntro]`. Logs go to `build-ninja\play\`. Keys: WASD d-pad, Space ✕, E ○, Q □, R △, Enter Start, Backspace Select, 1–4 L1/R1/L2/R2, arrows right stick.
- **Automated runs:**
  ```
  tools\smoke_test.ps1 -Iso "iso\Resident Evil - Outbreak (v2.00).iso" -Seconds 100 -Label X -Env 'REO_NATURAL=1;REO_PAD_SCRIPT=21:LEFT:2,24:CROSS:2,60:START:0.3,64:START:0.3;REO_SHOT_AT=60,85'
  ```
  Output goes to `build-ninja/smoke/<time>-X/`.
  - Menu flow with that script: Start at 60 s shows the main menu; Start at 64 s enters SINGLE PLAY → SCENARIO; Circle backs out.
  - If the ISO mounts without a drive letter, run `Dismount-DiskImage` and retry.
  - Never commit game data.
- **Self-tests:** `tools/ipu_selftest/run.bat` (all pass), `tools/runtime_selftest/run.bat` (26/26), `tools/gs_fastpath_check/run.bat` (fast vs generic GS output must be identical).

## Reference tools

- **Ghidra:** MCP at `127.0.0.1:8089`, program `/ps2/SLUS_207.65`, overlays `/ovl/ovl<n>.elf`. Launch with the batch file that runs `support\launch.bat ... < nul` (see memory notes). Verify against raw disassembly: the decompiler has hidden calls before (e.g. the `SleepThread` in the D34 worker loop).
- **PCSX2:** `C:\Users\Ninjacornix\ps2\pcsx2-qt.exe`, PINE on slot 28011.
  - Use `tools/ps2_debug/pine_client.py`; kernel RAM is readable at `0x8000xxxx`.
  - EE thread control blocks are spaced 0x4C apart near `0x80017424`.
  - `tools/ps2_debug/pcsx2_sfd_probe.py` logs CRI/Sofdec fields during the title movie.
- **Profiling:** `REO_STACKDUMP_AT=<s>` with `REO_STACKDUMP_N=<n>` (samples 20 ms apart). Symbolize with a fresh `/MAP` link of the same objects (relink, then link the map; a stale map gives nonsense names).

## Key facts learned

- **Threads:** main is thread 1 (priority 24). CRI threads are 4 (helper `0x12aba0`), 5 (`0x12ac90`, prio 16), 6 (`0x12ad70`, 18) and 7 (`0x12ae50`, 25, the Sofdec server). EE semantics: no time-slicing.
- **D34:** `WakeupThread` on a WAITSUSPEND sleeper must release the sleep. Do not enable `REO_SPIN_ROTATE` (it breaks CRI's lock).
- **Sofdec:** player `0x22DEC0`; global `0x22DE58` (`+0x24` decode gate); decoder handle table `0x22F18C` (`+0x44` request pending, `+0x48` state); server group 6 pass counter `0x22A610`.
- **GS/presentation:**
  - The GS runs on a worker thread, paced to at most ~2 frames behind (D39, D44).
  - Present uses a display snapshot taken after the VBLANK handler's flip (D41) and wakes on a condition variable each vblank (D44).
  - The vblank handler at `FUN_0019f600` → `FUN_001a0350` flips DISPFB.

## Switches

- **Video and test:**
  - `REO_TURBO=<2..16>`, `REO_TURBO_UNTIL=<guest addr>`: test-only vblank fast-forward (e.g. `0x22F18C` = until the title movie).
  - `REO_GS_THREAD=0`: synchronous GS. `REO_GS_NO_FASTPATH=1` / `REO_GS_NO_PARALLEL=1`: generic / single-threaded sprite drawing.
  - `REO_DEINTERLACE=1`: blend consecutive fields (off by default; it greyed text).
  - `REO_BLACK_FRAME_FALLBACK=1`: upstream's black-frame substitution (off; caused flashes).
- **Diagnostics:**
  - `REO_PRESENT_LOG=<from>,<to>`: one line per present (seq, swap µs, tick, buffers, brightness, hash) plus `[present-gs]` GS packets per present.
  - `REO_PRESENT_DUMP_AT=<s>`: dump 4 consecutive presented frames.
  - `REO_SFD_DIAG`, `REO_IPU_LOG`, `REO_SPR_LOG`, `REO_MPEG_PIC_LOG` (Codex), `REO_THREAD_LOG`, `REO_CRI_ERRLOG`, `REO_DTX_DUMP`, `REO_PEEK=addr,...`, `REO_HW_WATCH`, `REO_CD_LOG`.
  - `[perf]`, `[hot]`, `[vblank-slow]` heartbeat lines in stderr.
