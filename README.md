# REO - Resident Evil Outbreak: Recompiled

**A static recompilation of Resident Evil Outbreak (File #1 + File #2) for modern Windows.**

No emulator. No compromises. Just Raccoon City, running natively on your PC — alone or online.

> **Fan project.** Not affiliated with Capcom, Sony, or obsrv.org. You need legally owned copies of the games.

---

## What Is This?

REO takes the original PS2 binaries of both Resident Evil Outbreak games and translates them — instruction by instruction — into native x86-64 code that runs directly on Windows 11. This is **static recompilation**, the same technique behind projects like [Zelda 64: Recompiled](https://github.com/N64Recomp/N64Recomp).

| Game | Serial | Functions | Recompiled |
|------|--------|-----------|------------|
| RE Outbreak | SLUS-20765 | 3,461 | 3,209 functions → 3,829 C++ files |
| RE Outbreak: File #2 | SLUS-20984 | 3,525 | 3,525 functions → 3,892 C++ files |

Both games share the same engine and build against the same runtime HAL.

The PS2 was a wild machine. The Emotion Engine, two Vector Units, a fixed-function Graphics Synthesizer, a sound chip with its own CPU, and a network stack built for 2003-era Japanese broadband. Every piece of that hardware gets replaced with modern equivalents:

| PS2 Hardware | REO Replacement |
|---|---|
| Emotion Engine (R5900 MIPS) | Static recompilation → native x86-64 |
| Vector Units (VU0/VU1) | SSE/AVX SIMD + custom microcode translator |
| Graphics Synthesizer | Vulkan renderer (via paraLLEl-GS or custom) |
| SPU2 Sound | Software mixer → Windows audio (WASAPI) |
| IOP (I/O Processor) | High-level emulation of IRX modules |
| PS2 Network Adapter | Native Winsock, compatible with obsrv.org |
| DNAS Authentication | Bypassed (servers are long dead) |
| DualShock 2 | XInput / DirectInput / keyboard+mouse |

## Online Play

The original RE Outbreak was one of the first PS2 games with online multiplayer — and it was *great*. When Capcom shut down the servers, the community at [obsrv.org](https://obsrv.org) brought them back.

REO connects to those same community servers. Play with friends, matchmake with strangers, survive together — just like 2004, but at 1080p+ and 60fps.

- **Connect to obsrv.org** — join the existing community
- **Self-host** — run your own server for LAN parties or private games
- **Offline** — full single-player with AI partners, no internet required

## How It Works

### The Pipeline

```
┌─────────────┐     ┌──────────────┐     ┌───────────────┐     ┌──────────────┐
│  Outbreak    │     │ ps2xAnalyzer │     │  ps2xRecomp   │     │  REO Runtime │
│  ISO/ELF    │────▶│  (analysis)  │────▶│  (MIPS→C++)   │────▶│  (HAL+game)  │
│  SLUS_207.65│     │  TOML config │     │  native code  │     │  reo.exe     │
└─────────────┘     └──────────────┘     └───────────────┘     └──────────────┘
                                                                       │
                                              ┌────────────────────────┤
                                              ▼                        ▼
                                         ┌─────────┐           ┌────────────┐
                                         │ Vulkan  │           │  Network   │
                                         │Renderer │           │  Stack     │
                                         │ (GS)    │           │ (obsrv.org)│
                                         └─────────┘           └────────────┘
```

1. **Extract** the ELF binary from your legal game disc/ISO (File #1 or File #2)
2. **Analyze** it with ps2xAnalyzer to map functions, relocations, and symbols
3. **Recompile** MIPS R5900 instructions to C++ with ps2xRecomp
4. **Link** against the REO runtime — our replacement for all PS2 hardware
5. **Play** natively on Windows — choose which game with `--game file1` or `--game file2`

### The Runtime (Hardware Abstraction Layer)

The recompiled game code thinks it's talking to PS2 hardware. The REO runtime intercepts every hardware access and translates it:

- **Memory** — 32MB unified address space with scratchpad, MMIO regions, and TLB support
- **Graphics** — GS register writes are captured and rendered via Vulkan compute shaders
- **Audio** — SPU2 ADPCM voices mixed in software, output via WASAPI
- **Input** — DualShock 2 reads mapped to modern controllers and keyboard
- **Network** — IOP network module calls translated to native TCP/IP sockets
- **Filesystem** — CD/DVD reads redirected to extracted game data on disk
- **Video** — Sofdec/SFD cutscenes decoded via FFmpeg
- **Timing** — EE/IOP cycle counting replaced with high-resolution Windows timers

## Project Structure

```
reo/
├── CMakeLists.txt           # Top-level build
├── README.md                # You are here
│
├── game_data/               # Extracted File #1 data (SLUS_207.65 + assets)
├── game_data_file2/         # Extracted File #2 data (SLUS_209.84 + assets)
│
├── tools/                   # Build-time and debug tools
│   ├── iso_extract/         # Extract game files from ISO/BIN
│   ├── elf_analyze/         # ELF analysis and symbol extraction
│   ├── vu_disasm/           # VU microcode disassembler
│   ├── gs_dump_replay/      # GS dump replay tool (validates renderer)
│   └── ps2_debug/           # PCSX2 Pine IPC scripts (overlay dump, GS capture)
│
├── recomp/                  # Static recompilation layer
│   ├── config/
│   │   ├── outbreak.toml        # PS2Recomp config — File #1
│   │   ├── outbreak_file2.toml  # PS2Recomp config — File #2
│   │   ├── output/              # 3,830 recompiled C++ files (File #1)
│   │   ├── output_file2/        # 3,892 recompiled C++ files (File #2)
│   │   └── output_overlay/      # 95 runtime overlay functions (0x370000+)
│   ├── overrides/           # Game-specific overrides + hardware bridge
│   └── patches/             # Binary patches and fixups
│
├── runtime/                 # Hardware Abstraction Layer
│   ├── core/                # CPU context, memory map, syscalls
│   ├── gs/                  # Graphics Synthesizer → Vulkan
│   ├── spu2/                # Sound processing → WASAPI
│   ├── vu/                  # Vector Unit microcode execution
│   ├── iop/                 # I/O Processor HLE
│   ├── input/               # Controller/keyboard mapping
│   ├── cdvd/                # Disc I/O → file system
│   └── timer/               # Timing and vsync
│
├── network/                 # Online play
│   ├── snap_client/         # SN@P protocol implementation
│   ├── dnas/                # DNAS auth bypass
│   ├── lobby/               # Lobby browser and matchmaking
│   └── server/              # Optional local server
│
├── media/                   # Media decoders
│   ├── adx/                 # CRI ADX audio decoder
│   ├── sofdec/              # CRI Sofdec video decoder
│   └── tim2/                # TIM2 texture converter
│
├── game/                    # Game-specific code
│   ├── formats/             # NBD, AMO, RDT, etc. file parsers
│   ├── scripts/             # Game script interpreter
│   └── ui/                  # Menu and HUD reimplementation
│
└── third_party/             # External dependencies
    ├── PS2Recomp/           # Static recompilation toolchain
    ├── parallel-gs/         # Vulkan GS renderer
    ├── SDL3/                # Window/input management
    └── volk/                # Vulkan loader
```

## Building

> **Prerequisites:** Visual Studio 2022, CMake 3.20+, Vulkan SDK, legally owned RE Outbreak NTSC-U ISO(s)

```bash
# Clone
git clone https://github.com/sp00nznet/reo.git
cd reo

# Clone PS2Recomp (recompilation toolchain)
git clone https://github.com/ran-j/PS2Recomp.git third_party/PS2Recomp

# Build PS2Recomp tools
cd third_party/PS2Recomp
cmake -S . -B out/build -G "Visual Studio 17 2022" -A x64
cmake --build out/build --config Release
cd ../..

# Build REO tools
cmake -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release

# ── File #1 (SLUS-20765) ──
./build/tools/iso_extract/Release/reo-extract.exe "Outbreak.iso" game_data
./third_party/PS2Recomp/out/build/ps2xAnalyzer/Release/ps2_analyzer.exe \
    game_data/SLUS_207.65 recomp/config/outbreak.toml
./third_party/PS2Recomp/out/build/ps2xRecomp/Release/ps2_recomp.exe \
    recomp/config/outbreak.toml

# ── File #2 (SLUS-20984) ──
./build/tools/iso_extract/Release/reo-extract.exe "OutbreakFile2.iso" game_data_file2
./third_party/PS2Recomp/out/build/ps2xAnalyzer/Release/ps2_analyzer.exe \
    game_data_file2/SLUS_209.84 recomp/config/outbreak_file2.toml
./third_party/PS2Recomp/out/build/ps2xRecomp/Release/ps2_recomp.exe \
    recomp/config/outbreak_file2.toml

# Rebuild with recompiled code
cmake --build build --config Release

# Run (choose game)
./build/recomp/Release/reo_recomp.exe --game file1
./build/recomp/Release/reo_recomp_file2.exe --game file2
```

### Current Status

The recompilation pipeline is **working for both games**. File #1 boots to its main loop with the full rendering pipeline active, hardware bridge connecting recompiled code to native subsystems, live controller input, and disc I/O infrastructure wired.

| | File #1 | File #2 |
|---|---|---|
| ISO extraction | all files extracted | all files extracted |
| ELF analysis | 3,461 functions | 3,525 functions |
| MIPS → C++ | 3,209 → 3,830 files (66 MB) | 3,525 → 3,892 files (68 MB) |
| Runtime overlays | 95 functions (0x370000+) | pending |
| Build | compiles clean (3,923 files) | compiles clean (3,892 files) |
| Boot | main loop running, GIF pipeline active | pending |

**File #1 boot progress:**
- ELF loads, entry point executes, main loop enters and runs continuously at 60fps
- 82+ function overrides bound (GS, pad, network, audio, VSync, threads, DMA, SIF)
- Hardware bridge wired: DMA GIF/VIF → GSRenderer, GS register writes, VU0/VU1 microcode, SIF RPC → CDVD/PADMAN/MCSERV/LIBSD, Input polling, CDVD filesystem
- **Live controller input** — XInput controllers and keyboard (WASD/Enter/Space) wired to game's pad buffer via reo::Input, polled each frame
- **SIF RPC bridge** — PS2Recomp's SifCallRpc dispatches unhandled RPCs to REO's CDVD, PADMAN, MCSERV, and LIBSD handlers via onSifRpc callback in HwBridgeVtable
- **CDVD filesystem** — 85 game files mapped from extracted game_data/ directory, handles cdReadFile/cdSearchFile/cdGetDiskType
- **SIF module loading** — SifLoadModule returns success for IOP address loads; SifDmaStat check fixed to enable IOP init
- **GIF DMA pipeline fully operational** — display list double-buffering, tag array commit/reset, DMA source chain traversal all working
- GIF data reaches GSRenderer via submit_path3() every frame
- 95 runtime overlay functions captured from PCSX2 and integrated
- 13 core rendering functions un-stubbed
- Binary trace logger + PCSX2 Pine IPC debug tools

**Resolved issues:**
- SIF DMA status check (sub_0011D9C8) returning 0 — skipped all SifLoadModule calls; overridden to return 1
- SifLoadModule (sub_0011D970) returning -1 for IOP address loads — now HLE'd to return success
- Memcpy counter wrap in sub_001AF5D0 (0 → 0xFFFFFFFF infinite loop) — safety check added
- IOP task completion wait (sub_001CD080) infinite busy-loop — bypassed for single-threaded recomp
- Infinite DMA slot busy-wait (sub_001AF7A0) — PS2 waits for hardware; HLE clears slots
- Infinite GIF tag processing loop (sub_001071D8) — bypassed via caller override
- 6MB memset at address 0 (sub_001AF710) — uninitialized heap; replaced with bump allocator
- Runtime overlay dispatch failures — 95 functions captured via PCSX2 Pine IPC and recompiled
- Tag array 8-byte shift per frame (sub_0018DD40) — entry_count/write_idx not reset on buffer reuse
- GIF DMA chain traversal failures — REFE sentinel handling, address masking, tag ID parsing

**Current blocker — disc I/O data delivery:**
The game's file loading pipeline requires IOP-driven async data delivery through indirect function dispatch (function pointer tables populated by IOP callbacks). Since the IOP never runs in static recompilation, the callbacks never fire and the game's data loading handler (entry_1d2280) is never triggered through normal code flow. The SIF RPC bridge is wired but the game never calls SifBindRpc/SifCallRpc because the IOP callback system doesn't populate the indirect dispatch table. PCSX2 state snapshot injection shows the game CAN process injected data (task table populates, GIF DMA activity increases), confirming the rendering pipeline works — the gap is in the data delivery mechanism.

**Debug tools:**
- `reo-gs-replay` — replays PCSX2 GS dumps through REO's GS renderer
- `reo-gs-gen-test` — generates synthetic GS test dumps
- Binary trace logger — records DMA/GIF/VU/GS events (`REO_TRACE=1`)
- PCSX2 Pine IPC scripts — dump overlays, capture GS state, dump task tables (`dump_task_table.py`)

**Proof of life achieved (2025-03-13):** Debug overlay renders on live GS framebuffer. Full pipeline confirmed: recompiled MIPS → GIF DMA → GS software rasterizer → raylib window.

## Roadmap

### Phase 1 — Foundation (Current)
- [x] Project structure and build system
- [x] ISO extraction and ELF analysis tooling (working for both games)
- [x] PS2Recomp integration — **File #1: 3,461 functions, File #2: 3,525 functions**
- [x] Dual-game build system (reo_recomp + reo_recomp_file2)
- [x] Game selection via --game flag and auto-detected data paths
- [x] Basic memory map and CPU context runtime (32MB RAM, MMIO, scratchpad)
- [x] Bridge recompiled code to REO runtime (82+ override bindings)
- [x] Boot to main loop (game update function executing)
- [x] Runtime overlay capture — 95 functions from PCSX2 Pine IPC
- [x] Hardware bridge (DMA/GIF/VU/GS interception layer)
- [x] Un-stub rendering pipeline (13 core functions)
- [x] Debug tooling (GS dump replay, binary trace logger, PCSX2 IPC scripts)
- [x] GIF DMA pipeline flowing (display list → tag commit → DMA chain → GSRenderer)
- [x] Render first frame (proof of life — debug overlay on live GS framebuffer)

### Phase 2 — See Something (Current)
- [x] Input system — XInput controllers + keyboard mapped to DualShock 2
- [x] SIF RPC bridge — PS2Recomp dispatches to CDVD/PADMAN/MCSERV/LIBSD handlers
- [x] CDVD filesystem — game files mapped from extracted data
- [x] SIF module loading — SifLoadModule HLE for IOP address loads
- [ ] Disc I/O data delivery — connect IOP async pipeline to CDVD reads (current blocker)
- [ ] GS renderer (Vulkan) — upgrade from software rasterizer
- [ ] VU microcode translation for geometry
- [ ] Texture loading (TIM2/SLD)
- [ ] SPU2 audio mixer — hear the first sound

### Phase 3 — Play Something
- [ ] Full game boot to main menu
- [ ] Sofdec FMV playback
- [ ] Save/load system (memory card → local files)
- [ ] Single-player gameplay loop

### Phase 4 — Connect
- [ ] SN@P network protocol client
- [ ] DNAS bypass for obsrv.org connectivity
- [ ] Lobby browser and matchmaking
- [ ] Online multiplayer gameplay
- [ ] Optional local server bundling

### Phase 5 — Polish
- [ ] 60fps support (original was 30fps locked)
- [ ] Resolution scaling and widescreen
- [ ] Modern graphics enhancements
- [ ] Keyboard+mouse controls
- [ ] Steam Deck / Linux support (stretch goal)

## Technical References

- [PS2Recomp](https://github.com/ran-j/PS2Recomp) — Static recompilation toolchain for PS2
- [paraLLEl-GS](https://github.com/Arntzen-Software/parallel-gs) — Vulkan compute GS renderer
- [obsrv.org](https://obsrv.org/) — Community Outbreak servers
- [obsrv-pack](https://github.com/adrianopteodoro/obsrv-pack) — Open source server bundle
- [Outbreak Research](https://outbreak-research.github.io/Documentation/) — File format documentation
- [REOF2](https://github.com/caprado/REOF2) — RE Outbreak File #2 decompilation (reference)
- [ghidra-emotionengine-reloaded](https://github.com/chaoticgd/ghidra-emotionengine-reloaded) — PS2 Ghidra plugin
- [PS2Tek](https://psi-rockin.github.io/ps2tek/) — PS2 hardware documentation
- [Copetti PS2 Architecture](https://www.copetti.org/writings/consoles/playstation-2/) — Architecture deep-dive

## Legal

This project contains **no copyrighted game code or assets**. You must provide your own legally obtained copies of Resident Evil Outbreak (SLUS-20765) and/or RE Outbreak: File #2 (SLUS-20984).

Resident Evil is a trademark of Capcom. PlayStation is a trademark of Sony. This is an independent fan project created for preservation and educational purposes.

## Contributing

This is a massive undertaking and help is welcome. If you know PS2 internals, MIPS assembly, Vulkan, or just really love Outbreak — open an issue or PR.

*Don't let the memory of Raccoon City die.*
