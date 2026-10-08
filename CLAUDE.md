# REO — Claude Code project instructions

> Place this file in the root of your fork of https://github.com/sp00nznet/reo.
> Read `ROADMAP.md` and `REVERSE_ENGINEERING.md` before changing runtime or recompilation code.

## Mandatory networking product requirement — account-free P2P co-op

- **Non-negotiable:** Players must be able to host and join co-op with **no registration, login, external community server account, OBSRV account, or mandatory central server**. Default experience: **Host Game → share invitation code/address → Join Game**.
- Prefer direct host/client networking (one player operates the authoritative listen-server within their game process). No separately installed dedicated server should be required. This is *peer-hosted multiplayer*, not a promise of fully distributed deterministic lockstep.
- Support LAN discovery and direct IP/port joining as a guaranteed fallback. For internet connections, implement NAT traversal (e.g. ICE/STUN or equivalent) if viable; allow manual port forwarding where necessary. Optional TURN/relay may improve connectivity, but must be explicitly optional and must not require accounts; document that internet P2P cannot always succeed behind restrictive NAT/CGNAT without relaying.
- Invitation codes must not silently depend on a centralized account service. If a rendezvous service is introduced for convenience, it must be optional, documented, and self-hostable, with direct IP/LAN join still working when it is offline.
- Do **not** make OBSRV compatibility the default success criterion. Study the original protocol and reuse gameplay synchronization where practical, but design an independent account-free host/join path. Do not require community-server credentials or attempt to bypass their authentication.
- Build network security into the plan: validate every incoming packet, bound payload sizes, authenticate peers for a session with an ephemeral join secret, prevent unauthenticated game-state modification, handle disconnects/timeouts, and disclose host IP exposure for direct connections.
- Do not implement networking before demonstrably playable offline gameplay, but preserve this requirement in all architecture decisions and tests.

## Mission

Continue the existing **Resident Evil Outbreak (PS2) → native Windows** static-recompilation project. Reach *reproducible playable single-player in Outbreak File #1* before attempting File #2, online co-op, graphical enhancement, or optimization. Preserve original game behavior and make progress through small, measured fixes.

**Do not claim that the README's milestones are independently verified.** The upstream README reports working title-screen textures, GS replay, game-loop execution, and controller input as of April 2025, but we must rebuild and reproduce each claim in this checkout.

## Ground truth / orientation

Repository root has (per upstream): `CMakeLists.txt`, `docs/`, `game/`, `media/`, `network/`, `recomp/`, `runtime/`, `src/`, `third_party/`, `tools/`. Verify actual files, versions and targets locally. Potentially important areas:

- `recomp/config/outbreak.toml`: File #1 static recompilation configuration.
- `recomp/overrides/`, `recomp/patches/`: game-specific intervention points.
- `runtime/core/`, `runtime/vu/`, `runtime/gs/`, `runtime/iop/`, `runtime/input/`, `runtime/cdvd/`, `runtime/timer/`: PS2 compatibility/HAL layers.
- `tools/ps2_debug/`: PCSX2 Pine IPC diagnostic scripts.
- `tools/gs_dump_replay/`: GS replay tests; verify target naming.
- `game/`, `media/`, `network/`: parsing, playback and eventual networking; do not assume these are complete.

Versions, build paths and exact tool names are **discoverable facts, not assumptions**. Upstream README lists Visual Studio 2022, CMake >=3.20, Vulkan SDK, and the `PS2Recomp` tree under `third_party/`.

## Priorities (in order)

1. Audit source/build, dependencies, licensing, and current runtime behavior.
2. Reproduce title-screen/renderer claims and make a reliable logging/test harness.
3. Investigate a **single blocked game transition** (start → menu → scenario).
4. Enable one room of File #1 with stable camera, character state and input.
5. Save/load, audio, further gameplay; only then networking and File #2.

Do not swap the rendering architecture, add Steam integration, write a new engine, implement a mandatory centralized server, or mass-rewrite generated code without hard evidence that it is on the critical path.

## Standard agent loop

**For every substantial task:**

1. `git status`, branch/commit, environment and reproduction details.
2. Locate symbols and the narrowest relevant code path using `rg`, call graphs, Ghidra and runtime logs.
3. State an explicit hypothesis, competing hypotheses, an observable prediction and a test.
4. Establish a reference: PCSX2 behavior/trace, known-good GS dump, existing unit test, or hardware specification.
5. Implement the **smallest reversible patch** in source/overrides/HAL rather than editing thousands of generated files.
6. Build the smallest affected targets; run unit/trace/replay tests, then the game smoke test if game data is locally available.
7. Report actual outcomes. Never say 'fixed', 'playable', 'pixel perfect' or 'online works' without observing it.
8. Update `ROADMAP.md` only when exit criteria are met. Record investigation notes in `docs/` or an appropriately named new file.

Prefer evidence-driven progress over broad refactoring. One verified fix is better than many speculative stubs.

## C++ and PS2 correctness rules

- Match PS2 R5900 semantics exactly: 32/64/128-bit registers, sign/zero extension, overflow/wrapping, branches/delay slots, HI/LO, endianness, misaligned accesses, and unaligned load/store behavior.
- Respect EE memory aliases, scratchpad, DMA/GIF paths, GS state, SIF/IOP RPC and Vector Unit behavior. Do not erase hardware side effects for convenience.
- Preserve PS2 floating-point behavior where relevant; use bitwise and register-level traces before asserting equivalence.
- Do not treat a function stub that makes execution proceed as proof it is correct. Document every HLE stub with expected side effects and validation status.
- Keep upstream/generated code separate from patches; avoid nondeterministic code generation and large formatting-only diffs.
- Guard allocations, bounds, offsets and file parsing. Keep logging configurable to avoid changing timing excessively.
- Never make compatibility changes just to match one screenshot if the underlying state diverges.

## Ghidra / MCP operating rules

Use Ghidra (optionally `ghidra-emotionengine-reloaded` and a vetted Ghidra MCP bridge) to **inspect and annotate**, not as an oracle. Before accepting AI-generated names or types:

- Capture executable ID, game revision, file checksum, address, raw disassembly, decompiler pseudocode, xrefs and callers/callees.
- Keep original addresses in notes: e.g. `sub_001D3DC0` → candidate scene renderer (upstream report; verify).
- Label hypotheses with confidence: `confirmed` (trace/callsite/protocol evidence), `probable`, `speculative`.
- Validate switch tables, jump targets, overlays and mid-function entry points before making recompilation changes.
- Double-check MIPS delay slots and compiler artifacts against assembly, not just decompiler C.
- Do not bulk-rename symbols or commit a whole Ghidra export from one AI pass.
- If a Ghidra MCP is unavailable, use local Ghidra UI/headless script exports; never fabricate MCP commands.

See `REVERSE_ENGINEERING.md` for the detailed process and recommended tool interface.

## Testing and reporting contract

In the response for each implemented change, include:

- **Observed baseline** (exact command, platform, commit, inputs/ISO revision if used)
- **Hypothesis and evidence** (function addresses, logs, trace/dump locations)
- **Changes** (paths and what each fix does)
- **Tests** (exact commands and PASS/FAIL/SKIPPED; never invent results)
- **Remaining uncertainty / next smallest experiment**

Use a concrete checkpoint table where useful: frame number, PC/return address, task, DMA/GIF packet counts, GS registers, memory hashes and visible screen.

## Build environment and data

Check the README commands against this fork; possible upstream commands include:

```powershell
cmake -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release
# After supplying owned File #1 data and setting up PS2Recomp as documented:
# ./build/recomp/Release/reo_recomp.exe --game file1
```

Do not automatically run extraction or game launch if the required owned ISO/ELF is absent. Ask for the user's local file paths when essential; never download or bundle copyrighted game executables, ISOs, or assets. Do not commit game data, traces containing substantial proprietary payloads, secrets, or auth credentials.

## Legal / licensing / security

Check whether upstream has an explicit license and whether each dependency's license permits the contemplated fork/distribution. Public GitHub source without a license is **not** automatically open source. Keep user's game assets external. Never implement credential theft or attacks on community multiplayer infrastructure; test on locally controlled instances or with permission.

## When receiving an open-ended request such as “continue the port”

**Do not begin a sprawling rewrite.** First:

1. Audit repository status and build.
2. Summarize reproducible behavior and missing dependencies.
3. Identify the next specific blocking failure with evidence.
4. Propose **one** testable patch; implement it if sufficiently grounded.
5. Update the checkpoint log and roadmap.

Keep `ROADMAP.md` authoritative for current milestone and exit criteria.
