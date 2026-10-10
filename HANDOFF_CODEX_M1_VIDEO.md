# Codex handoff: milestone 1 and the green title movie

Updated 2026-10-10. Branch: `m1/ghidra-regen`; starting commit: `990d9c1`. Read this alongside `HANDOFF.md`, `CLAUDE.md`, `ROADMAP.md`, and `docs/DIVERGENCES.md`.

## Current result

The native game reaches the main menu through real controller input with `REO_NATURAL=1`. The green background is fixed: the 100-second capture from `build-ninja/smoke/20261010-212753-codex-m1-isolated-b/shot_100.bmp` shows SINGLE PLAY / NETWORK PLAY / COLLECTION / CHARACTER LOG / OPTIONS / HDD INSTALL over actual movie imagery. The 130-second run is completing its final stability captures; see its `summary.txt` when finished.

**Video playback remains slow.** The user reports only a few FPS. No isolated FPS benchmark has been recorded yet. Restoring visible frames is not evidence of full MPEG accuracy, audio synchronization, or normal playback speed. These remain follow-up work.

## What actually caused the green screen

1. The original ELF and Ghidra contain four `0x00FF00FF` words at EE address `0x00143F70`: a vector of 255-valued halfwords used by the libmpeg packing routine.
2. IPU BDEC produces nonzero 16-bit macroblock samples in scratchpad (DMA3 destinations `0x80001800` / `0x80003300`). This part was already working.
3. The CPU packs those samples into byte picture buffers using signed `PMINH` with the clamp vector, `PMAXH` with zero, and `PPACB`. The runtime had cleared the clamp vector to zero, forcing every packed sample to zero. CSC converts all-zero YCbCr to green.
4. A hardware write watchpoint on `0x143F70` caught the first corruption during sound RPC initialization, caller guest PC `0x1179E8`. The writer's host stack included `rpcZeroRdram`.
5. `Kernel/Syscalls/RPC.cpp::checkSoundDriverMemoryUnlocked` allocated synthetic sound state/storage at `0x120000..0x17D000` **in EE RAM** and zeroed it. That overlaps the game's executable and embedded constants. These RPC addresses represent IOP memory and must not overwrite EE memory at the same numeric addresses.
6. PCSX2 PINE reference sampling on the same SLUS-20765 retained all four clamp words and showed nonzero, changing picture-buffer hashes over 40 seconds. Reference log: `build-ninja/pcsx2-movie-reference-20261010.jsonl`.

The logged SPR transfers were CRI scratchpad save/restore operations, not the missing movie write-back. Adding SPR DMA was useful runtime work, but did not resolve the green screen by itself.

## Fixes in the working tree

- `third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp`: sound initialization, address table, status updates, and status reads now use `runtime.memory().getIOPRAM()`. The existing synthetic IOP addresses are preserved. RPC command/reply buffers and compatibility checksum tables continue to use EE memory.
- Private `RPC.h` exposes `resolveSoundDriverIopTransfer`. It checks ownership and the complete sound arena bounds. An overlapping invalid transfer must be rejected instead of falling back to EE memory. Known sound pointers remain IOP-backed across repeated `SifInitRpc` calls before reinitialization.
- `Kernel/Stubs/SIF.cpp`: `sceSifGetOtherData` reads known sound sources from IOP memory; `sceSifSetDma` writes known sound destinations to IOP memory. The EE source of an upload is still resolved as EE memory. Other transfers retain the existing fallback.
- `lib/ps2_memory.cpp`: retained Claude's channels 8/9 SPR implementation and corrected `CHCR.TAG` extraction to use tag bits 31:16 from the lower word, without shifting by 16 first. The tested paths are normal transfers, scratchpad wrap, END source chain, and IRQ/TIE completion. Do not assume all interleave/TTE/chain variants are complete.
- `lib/ipu/ps2_ipu.cpp`: corrected the same DMA4 tag extraction; BDEC now publishes coded-block pattern in IPU_CTRL bits 13:8 and reset clears it. These are hardware conformance fixes found during investigation, distinct from the sound-memory root cause.
- `recomp/overrides/reo_override.cpp`: opt-in `REO_MPEG_PIC_LOG` traces the libmpeg source, destination, clamp, and packed output without changing guest state. An additional `REO_SFD_DIAG` write-back trace was already present during continuation; preserve it when reviewing the diff.
- `tools/smoke_test.ps1`: optional `-ExePath` selects an isolated executable; helper process starts hidden. Default executable selection is retained.

No shared runtime headers or target-wide defines were changed for this fix; avoid them because they force a roughly 70-minute game rebuild.

## Validation and reproduction

Build the runtime, then relink the game from a VS x64 development prompt:

```powershell
& 'C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe' --build third_party/PS2Recomp/out/build --config Release --target ps2_runtime
# From a VS x64 development prompt:
ninja -C build-ninja -j 2 reo_recomp
```

Focused retained checks:

```text
tools\ipu_selftest\run.bat
tools\runtime_selftest\run.bat
```

IPU checks pass with zero failures: BDEC intra/non-intra, FDEC/VDEC, CSC, scratchpad output, CBP, tag extraction, and IRQ/TIE completion. The runtime runner passes **26/26** SIF and SPR cases, including synthetic EE code/clamp sentinels, status/table reads, sound upload/readback, rejection at both arena boundaries, and stale pointers after `SifInitRpc`. Logs: `build-ninja/runtime_selftest/` and `build-ninja/ipu_selftest/`. Full `ps2x_tests` compilation previously hit an MSVC internal exception; the focused runner compiles and runs the relevant suites without that large target.

Latest native command (only normal LEFT/CROSS/START button input):

```powershell
tools\smoke_test.ps1 -Iso 'build-ninja\m1-validation.iso' -ExePath 'build-ninja\recomp\reo_recomp-m1.exe' -Seconds 130 -Label codex-m1-isolated-b -Env 'REO_NATURAL=1;REO_PAD_SCRIPT=21:LEFT:2,24:CROSS:2,30:CROSS:1,36:CROSS:1,42:CROSS:1,85:START:1,89:START:1,93:START:1,97:START:1,101:START:1,105:START:1,109:START:1,113:START:1;REO_SHOT_AT=55,65,80,100,115,125;REO_PEEK=0x143F70,0xAA55C0,0xAF95C0,0xB4D5C0;REO_MPEG_PIC_LOG=1'
```

The isolated ISO and executable are ignored local copies. Another session was running smoke tests in the same checkout and repeatedly unmounting the original ISO; isolation avoids that collision. Use the original owned ISO and default executable for ordinary single-session runs. A 0.5-second CROSS pulse missed confirmation in one loaded run, so the current check uses longer/repeated button presses. No game state or frame buffers are injected.

ISO SHA256: `69ae2c48e6f01e2605659feabb54eb9b82c63a809bdc8a78ad2d160b3c59a4a1`.
ELF SHA256: `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.

## Tools and next work

Ghidra MCP connected to `127.0.0.1:8089`, project `reoiso`, program `/ps2/SLUS_207.65`; specify the program explicitly because several programs are open. PCSX2 executable: `C:/Users/Ninjacornix/ps2/pcsx2-qt.exe`, PINE slot 28011. The reference process launched for sampling has exited; do not stop unrelated user processes.

Authoritative web references checked: [PCSX2 SPR.cpp](https://github.com/PCSX2/pcsx2/blob/master/pcsx2/SPR.cpp), [Dmac.h](https://github.com/PCSX2/pcsx2/blob/master/pcsx2/Dmac.h), and [IPU_MultiISA.cpp](https://github.com/PCSX2/pcsx2/blob/master/pcsx2/IPU/IPU_MultiISA.cpp). No game-specific green-FMV workaround was found. Diagnosis rests on ELF, native write-watch, and live PCSX2 evidence.

Next: measure movie frame delivery and decoding cost in one native process; keep correctness and performance separate. Compare a few decoded macroblocks and frame checkpoints with PCSX2 before optimizing. Then follow ROADMAP milestone 2: SINGLE PLAY selection, scenario loading, and a first room. Keep `REO_SPIN_ROTATE` disabled: earlier evidence says it breaks CRI's lock. Do not reintroduce sound storage into EE memory or reseed the clamp constant as a workaround.

PS2Recomp patch packaging is being finalized as `0020-sound-iop-isolation-spr-ipu-registers.patch`, diffed against a pristine pinned checkout with 0001..0019 applied. Prior chain has passed; final 0020 verification will be recorded here once completed. Game assets, copied ISO, screenshots, and raw probes must remain uncommitted.
