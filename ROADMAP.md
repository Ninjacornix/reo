# REO continuation roadmap — evidence-first

**Target:** Native Windows, playable Resident Evil Outbreak File #1 → account-free peer-hosted online cooperative play → File #2.  
**Branch strategy:** keep upstream baseline and separate narrow feature/fix branches; periodically merge upstream selectively.  
**Status key:** `UNVERIFIED` = upstream claims only; `TODO` = not demonstrated here; `DONE` = reproduced with logs/tests recorded.

## Current upstream claims to verify

Upstream README (https://github.com/sp00nznet/reo) claims, as of the April 7, 2025 milestone: File #1 static recompilation and runtime build, main loop, visible title/textures, XInput input, GIF→GS software rendering, GS dump replay, NBD/AMO parsing, NETBIO archives, TEX decompression, ~95 overlay functions and a number of HLE overrides. It describes File #2 recompilation as building but not booting. **These are not independently validated in your fork.** Start by recording a new baseline.

## Milestone 0 — Licensing, reproducibility and instrumentation — `DONE` (2026-10-09)

Evidence: `docs/BASELINE.md`. Baseline branch `baseline/pivot-selfexec` (upstream `pivot-selfexec` + local fixes); `main` audited separately (its title screen was a PCSX2-snapshot "puppet").

**Tasks**

- [x] Record fork commit, OS, compiler/toolchain versions, CMake options, SDK and dependency revisions.
- [x] Verify README file tree against source and inventory actual CMake targets and tooling.
- [x] Build from clean checkout; document failing commands and missing pieces. *(`tools/setup_deps.ps1` on a fresh clone; keep the path short (MAX_PATH).)*
- [x] Reproduce File #1 run using *user-owned* data; capture logs, screenshot/recording, timing. *(`tools/smoke_test.ps1`; logs + `[hot]` heartbeat + framebuffer dump under `build-ninja/smoke/`.)*
- [x] Confirm whether `REO_TRACE=1`, PCSX2 Pine utilities and GS replay work as described. *(Trace was empty and GS replay failed to link/parse; both fixed and verified. PINE verified against the running game.)*
- [x] Add reproducible smoke-test command or script that never requires committing ISO content.
- [x] Create `docs/BASELINE.md` with machine, game revision/hash, latest build status, observed behavior and evidence links.

**Exit:** another developer can build the same revision and reproduce the same observable failure/success. If game data is unavailable, mark run tests `BLOCKED` rather than pretending they pass. — **Met (2026-10-09):** a clean checkout reproduces the pinned deps + patches; observable state: boots under self-execution, passes `SifIopSync` (D1), then loops in SIF RPC; no title screen yet.

## Milestone 1 — First divergent game state — `DONE` (2026-10-10)

Evidence: `docs/DIVERGENCES.md` → "Milestone-1 checkpoint — main menu reached" (runs `m1-a`, `m1-b`, `rs-a`, `rs-b`, `rs-noswitch`). D28–D35 record the divergences fixed along the way.

- [x] Establish a deterministic PCSX2 comparison point: startup, title input, menu transition. *(PINE probes of CRI/Sofdec state at the title-movie start; PCSX2 at `C:/Users/Ninjacornix/ps2`.)*
- [x] Capture REO trace and PCSX2 equivalent task/memory/register state for the same checkpoint. *(`REO_SFD_DIAG`/`REO_THREAD_LOG`/`REO_PEEK` vs. the PCSX2 probe of decoder `0xDE6E20`, gate, handshake flag and pass counter.)*
- [x] Record *first* divergence, not just last visible symptom, in `docs/DIVERGENCES.md`. *(D34: `WakeupThread` on a WAITSUSPEND sleeper.)*
- [x] Categorize fault. *(Scheduler/kernel HLE: D34, D35. Interrupt delivery: GS FINISH/SIGNAL. Recompilation: D32 merged functions. IPU: D30.)*
- [x] Propose one minimal correction and re-run both sides. *(Patch 0019, A/B run `rs-noswitch`.)* A unit-level regression fixture for the thread state machine is still TODO; the smoke checkpoint is the regression test for now.
- [x] Repeat until menu input causes the correct state transition without synthetic bypasses. *(Real Start presses through the libpad2 path. No bypasses: `REO_NATURAL=1`, no pad/state pokes.)*

**Exit:** observed menu transition and stable task progression after pressing Start, with a repeatable trace/checkpoint. — **Met (2026-10-10):** Start on the title screen reaches the main menu (SINGLE PLAY … HDD INSTALL) in 5 of 5 runs, frame hash `2cf69504`, with the frame loop alive through 125 s.

**Known gaps carried into M2:**
- The title movie decodes correctly (D36) but plays at ~17–23 fps; the streams declare 29.97 fps (MPEG sequence headers on the disc, 512×448 title movies and 512×320 cutscenes). Full-speed FMV is a Milestone 3 item; see D37 and `HANDOFF.md`.
- Menu selection input is untested.

## Milestone 2 — Reach one scenario room (vertical slice)

- [ ] Pick ONE File #1 scenario and one playable character as a golden test case.
- [ ] Validate menu selection, load sequence, disc reads, overlays and asset decompression.
- [ ] Ensure in-game camera, level geometry, textures, characters and animation are visible.
- [ ] Validate collision/movement/interaction using replayable pad-input sequence.
- [ ] Ensure stable execution through a room transition and return to menu.
- [ ] Record PCSX2/native comparison checkpoints (state, camera, inputs, geometry, texture captures).

**Exit:** controlled character can enter, move around and interact in one room repeatedly without crash/hang. **This is the first meaningful “playable” proof.**

## Milestone 3 — Complete single-player scenario

- [ ] Fix event scripting, AI partner behavior, item interactions, door transitions, combat, state persistence and failure/restart.
- [ ] Add SPU2/audio only to degree required for correct presentation and pacing; test timing interactions.
- [ ] Validate save/load and memory-card mapping; protect save files from corruption.
- [ ] Confirm FMV/cutscene playback and skip behavior, if on required route.
- [ ] Test one scenario end-to-end with comparable PCSX2 outcomes.
- [ ] Build automated smoke runs for startup, gameplay, loading and exit.

**Exit:** complete one File #1 scenario offline, including loading, audio, input and persistence where applicable.

## Milestone 4 — Full File #1 parity

- [ ] Test all scenarios, characters, weapons, puzzles, AI actions, cinematics, save/load and unusual transitions.
- [ ] Establish performance and deterministic behavior baselines; measure rather than prematurely optimize.
- [ ] Replace temporary HLE workarounds with justified, tested behavior.
- [ ] Restore consistent graphics and audio on representative scenes.
- [ ] Test supported Windows machines/controllers, focus changes and device hot-plugging.

**Exit:** documented compatibility matrix with major game content playable offline; known defects triaged.

## Milestone 5 — Account-free peer-hosted online co-op (REQUIRED)

**Acceptance requirement:** Two or more users can play online without registering anywhere, logging in, installing a dedicated server, or depending on OBSRV or any mandatory centralized service. One player clicks **Host**, another clicks **Join**. **LAN and direct IP/port joining must always remain available** even without third-party infrastructure.

**Do only after robust offline gameplay.** First investigate original Outbreak multiplayer state replication and adapt its semantics where technically sound; do not assume the original client/server protocol directly supports peer hosting.

- [ ] Inventory existing `network/` code, PS2 IOP socket/RPC calls, online gameplay-state handling, and region-specific behavior.
- [ ] Document architecture in `docs/P2P_DESIGN.md`: listen-server host authority, join/handshake, transport, player slots, sync/update cadence, event ordering, loading barriers, disconnects, host exit, and optional migration (not required for MVP).
- [ ] Implement **Host Game**, **Join by IP:port**, and **LAN discovery**. Provide copyable connection instructions; no login or account screens.
- [ ] Test LAN co-op between two native clients; verify spawn, movement, inventory, enemies, pickups, doors, and scenario progress.
- [ ] Add internet connectivity through direct UDP or selected transport and documented port forwarding fallback; evaluate optional STUN/ICE hole punching and optional relay for restrictive NAT/CGNAT. Do not assert universal direct P2P reachability.
- [ ] If shareable invite codes or matchmaking/rendezvous are offered, ensure they are optional, self-hostable, and do not break direct-IP mode when the service is down. Do not make user accounts mandatory.
- [ ] Ensure host-owned authoritative state where necessary, with input/state validation, bounded packets, session join secret, replay/duplicate handling, version/build compatibility checks, and safe error reporting.
- [ ] Run simulated latency/jitter/packet loss tests, plus disconnect, timeout, wrong-version, spoofed-packet and host-loss tests.
- [ ] Complete one full scenario with two native PC players across **different internet connections** without any community-server account; expand toward supported player count.
- [ ] Document IP exposure, port-forwarding considerations, optional relay privacy/cost, and known NAT failure cases.

**Exit:** host and remote friend complete a File #1 scenario on native clients, with **zero required accounts or mandatory central services**, and LAN/direct-IP mode functional. An optional relay does not count as direct P2P; accurately label the transport used.

## Milestone 6 — File #2

- [ ] Re-establish separate File #2 recompilation build, game revision and execution baseline.
- [ ] Reuse shared HAL fixes carefully; keep region/game-specific patches isolated.
- [ ] Repeat earlier vertical-slice, scenario, and online tests.

**Exit:** File #2 reaches comparable compatibility and has its own test matrix.

## Milestone 7 — Optional PC enhancements

- [ ] Controller remapping, multiple input APIs, keyboard/mouse where feasible, accessible configuration.
- [ ] Resolution scaling/widescreen and modern graphics backend **without regressions**.
- [ ] Frame rate improvements only after checking timing-dependent game logic and animation.
- [ ] Packaging and user-owned asset detection (do not distribute copyrighted game data).

## Short-term backlog selection rule

Always choose next task by **reproducibility × impact × confidence × size**. Prefer the first wrong game-state transition over a visual polish issue. Avoid parallel efforts that edit core memory, DMA and scheduler code simultaneously.

## Task card template

```markdown
### [ID] Title
Status: TODO / IN PROGRESS / BLOCKED / DONE
Area: recomp | EE | VU | GS | IOP | CDVD | input | network | assets
Baseline: commit, build, game revision, exact reproduction steps
Expected (PCSX2): observable behavior + evidence
Actual (REO): behavior + trace/screenshot
Hypothesis: ...
Candidate functions/addresses: ...
Proposed smallest experiment: ...
Test commands: ...
Result: PASS / FAIL / SKIPPED and attached evidence
Risk/regression: ...
```

## First instruction to Claude

> Read `CLAUDE.md`, `ROADMAP.md`, `REVERSE_ENGINEERING.md` and the upstream README. Inventory the checked-out source and toolchain, validate build commands, identify what is actually runnable, and write `docs/BASELINE.md`. If you can reproduce a run, identify the earliest objectively testable divergence from PCSX2 in File #1. Do not start networking, renderer replacement, or File #2 work yet.
