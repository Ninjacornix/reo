# REO reverse-engineering playbook (Claude + Ghidra + PCSX2)

## Objective

Turn unknown PS2 behavior into **verifiable code changes** in the existing REO static-recompilation runtime. Never accept decompiler output, a model's interpretation, or a screenshot match as sufficient proof on its own.

## Tool stack / roles

| Tool | Purpose | Caution |
|---|---|---|
| Ghidra + Emotion Engine extension | ELF disassembly, xrefs, call graphs, data types, overlays | Verify architecture plugin/version and address spaces |
| Ghidra MCP bridge (optional) | Query functions/xrefs/disassembly from Claude Code | Bridges differ; discover actual exposed tools, use read-only by default |
| PCSX2 debugger + Pine IPC | Reference execution, memory, registers, tasks and GS dumps | Match exact game region/revision and emulator settings |
| `tools/ps2_debug` in REO | Project-specific IPC/scripts (as available) | Inspect current script arguments instead of guessing |
| `REO_TRACE=1` (if implemented) | Native DMA/GIF/VU/GS event traces | Verify trace format; throttle noisy logging |
| REO GS dump replay | Graphics differential testing | Rendering equality does not imply game-state equality |
| PS2Recomp | Deterministic instruction translation and hooks | Trace problematic codegen instead of manually editing generated files |
| Wireshark | Authorized multiplayer protocol inspection | Capture only traffic you own or have permission to analyze |

Useful references: https://github.com/chaoticgd/ghidra-emotionengine-reloaded ; https://github.com/PCSX2/pcsx2 ; https://github.com/ran-j/PS2Recomp ; https://outbreak-research.github.io/Documentation/

## Establish an exact executable identity

Before analyzing any address:

1. Identify File #1 ELF filename, version, serial, region and hash (SHA-256).
2. Record load base/address map, sections, overlays and any dynamically loaded code.
3. Configure Ghidra with the correct MIPS/EE language/extension; verify disassembly at entry.
4. Maintain `docs/SYMBOLS.md` with original address, original symbol, proposed name, confidence, evidence link and any overlay mapping.
5. Do **not** assume File #1 U.S. (`SLUS-20765`) addresses match File #2 or Japanese revisions.

Suggested symbols table:

```markdown
| Game SHA-256 | EE address | Proposed name | Confidence | Evidence | Notes |
|---|---:|---|---|---|---|
| `<hash>` | `0x001D3DC0` | `scene_render_candidate` | speculative | upstream README; inspect xrefs | address may vary by revision |
```

## Ghidra agent workflow

For a target function, acquire the following as a compact bundle:

- address and size; raw MIPS instructions including delay slots
- pseudocode and compiler-lifted data types
- callers/callees and xrefs (including global variables and string references)
- related switch/jump tables, import calls, virtual dispatch and overlays
- evidence that the function executes at the failing game checkpoint

Then ask Claude to produce:

1. **Observed behavior** only (register reads/writes, addresses, calls, conditions).
2. **Semantic hypotheses** ranked by confidence, including alternative interpretations.
3. **Potential recompilation/HAL mismatch** and which side controls it.
4. **A falsifiable test:** breakpoint, watchpoint, trace field, memory diff or GS dump.
5. **Small patch location**, avoiding generated output, with regression criterion.

Review against raw assembly before accepting C++ pseudocode. Verify signed/unsigned operations, pointer widths, tail calls, MIPS branch delay slots, masked VU register writes and weird EE/VU instructions.

### MCP contract (implementation agnostic)

If you install a Ghidra MCP server, prefer minimal **read-only** capabilities:

- list programs; describe sections and load map
- get disassembly and decompilation by exact program/address
- list function xrefs, callers/callees and global references
- retrieve memory bytes and known symbols

Allow symbol renaming, datatype changes, or patch operations only with explicit review and logging. Never assume a specific MCP server/tool name is installed. If none is configured, export the same bundle with Ghidra scripts/UI and provide it as local text/JSON to Claude.

## Differential-debugging workflow

### 1. Build comparable checkpoints

Use the same original game build, input sequence, region, scenario, emulator timing settings and reset state on both sides. For non-deterministic events, align on *semantic boundaries* (function entry, IOP RPC completion, DMA submission, menu state transition), not wall-clock time.

Suggested initial checkpoints:

1. ELF entry and subsystem initialization
2. task scheduler initialized
3. first successful disc read
4. first title-screen GS submission
5. game receives Start input
6. menu transition requested
7. scenario load begins
8. first 3D scene submitted

### 2. Capture the narrowest relevant state

- EE: PC, RA, SP, relevant GPRs, HI/LO, exception status
- VU: microprogram hash, PC, vector registers and masks when applicable
- IOP/SIF: RPC call ID, arguments, reply status, ordering
- CDVD: requested file/sector, offsets, byte count, completion timing
- DMA/GIF: channel, tag sequence, source address, QWC, GS register writes
- Game: current scene ID, task state, menu state and critical pointers (after verified addresses)

Avoid comparing entire memory dumps without segmentation and normalization: allocations and pointer values can legitimately differ. Record hashes of meaningful regions and selected fields.

### 3. Find the *first* divergence

Use an event stream with a normalized schema:

```json
{"seq":421,"checkpoint":"start_pressed","subsystem":"PAD","ee_pc":"0x...","event":"pad_read","buttons":"0x...","frame":135}
```

Align traces by event identity and execution context, then binary-search or refine the first differing segment. Label expected nondeterminism separately. Do not assume the latest visible symptom is the cause.

### 4. Patch and prove

Create a targeted test or replay fixture that failed before and passes after. Validate no regression at earlier checkpoints, then run the original gameplay reproduction. Describe observed behavior and remaining uncertainty.

## High-risk pitfalls in REO

- **Overzealous HLE shortcuts:** returning success without proper memory state, callbacks, DMA or scheduling later breaks gameplay.
- **Runtime overlays:** mid-function branches and code loaded at runtime require exact registration and memory semantics.
- **GS success masking EE bugs:** rendering a prerecorded GS dump says little about whether the live scene logic is correct.
- **VU0 vs VU1 confusion:** distinguish macro mode, microcode, transfer and DMA interactions.
- **Frame timing:** a stable 60 Hz render loop does not establish 60 FPS-safe simulation or correct timer behavior.
- **Region assumptions:** community servers may use Japanese protocol/game revisions unlike REO's NTSC-U binary.
- **Recompiler codegen regressions:** isolate instruction-level test cases; upstream fixes to PS2Recomp instead of patching emitted C++ arbitrarily.

## Investigation note template

```markdown
# REO investigation: <short name>
Date / investigator:
Commit / game SHA-256 / environment:
Observed failure (repro steps):
Expected result (PCSX2 evidence):
Current result (REO evidence):
First divergent checkpoint:
Affected registers, memory, task, subsystem:
Ghidra function address + disassembly snippet:
Hypothesis A / B, confidence and tests:
Patch path and reasoning:
Test results: PASS / FAIL / SKIPPED
Follow-ups / unresolved risks:
```

## First three experiments (after baseline)

**Experiment A — Start button propagation**: prove physical keyboard/gamepad state → REO virtual DS2 buffer → recompiled pad read → game menu state. Compare the first mismatching state with PCSX2. An input buffer getting updated is not enough to prove the game consumed it.

**Experiment B — Scene load pipeline**: from a known menu selection, follow game state → CDVD request → callback/completion → archive load/decompress → scene ID/geometry state. Check lengths, offsets, ownership and scheduling.

**Experiment C — Live GS submission**: compare a live title or scenario frame against a matching PCSX2 GS dump. Separate wrong game-state generation from incorrect GIF/GS rasterization, and verify any change against synthetic replay fixtures.

## What not to do

- Don't invent Ghidra function names, exact build steps, trace outputs or addresses.
- Don't rewrite all translated functions into “clean modern C++”.
- Don't treat a crash suppression hack as completion.
- Don't claim all of Outbreak is reverse-engineered because functions were machine-translated.
- Don't start multiplayer rewrites before a functioning offline scenario.
- Don't publish proprietary game binaries/assets or unauthorized packet captures.

## Account-free peer-hosted networking research requirements

The fork's product requirement is native co-op without OBSRV accounts or a mandatory central server. Do **not** assume the original server protocol can simply be pointed at another player; examine the original division of server/client responsibilities.

1. Locate PS2 networking entry points, socket/RPC wrappers, packet framing, player state replication, and lobby/scenario transitions; record Ghidra symbols, addresses and evidence.
2. Determine which state the original server authoritatively owns (if applicable) and design a **local listen-server host** to provide those responsibilities within the host's game process. Preserve original game sync semantics where safe.
3. Build isolated, permissioned test harnesses for packet serialization/deserialization. Compare packets from known-good emulator sessions only where authorized. Never use account bypasses or production server probing.
4. First test two processes on localhost, then two PCs on LAN, then direct internet IP/port, then optional NAT traversal/relay. Keep LAN/direct-IP functional offline from discovery infrastructure.
5. Test corrupt, oversized, reordered, duplicated, delayed and forged packets. Record reproducible fixtures, transport logs and version compatibility in `docs/P2P_TESTS.md`.
6. Clearly distinguish **direct peer-hosted traffic** from an optional relay; no external server or login may be mandatory for basic host/join. Document practical limitations caused by CGNAT and restrictive firewalls.
