# Live slowdown recording

Implemented on `fix/launcher-progress-overlay`. This is a Windows x64 first
implementation. Synthetic transport and incident checks do not establish that a
real game slowdown has been reproduced or fixed.

## Playing with the recorder

1. Build the launcher with `launcher/build.ps1` and rebuild the native game from
   these sources. Rebuilding only the launcher cannot instrument an old game EXE.
2. Open `StartLauncher.cmd`, choose **Developer → Record slowdowns**, and launch
   normally. The option defaults to off and applies to the next launch.
3. Check the Developer status. **recording** requires a verified native handshake
   and both clock and frame capabilities. **limited recording** lists unavailable
   evidence. File #2 currently has frame timing and process health only. An old
   native executable supplies process health only. **unavailable** describes an
   initialization, transport, identity, monitor, or storage failure.
4. Play normally. An incident saves up to 30 seconds of history and 5 seconds of
   follow-up. **Mark problem** also captures a brief hitch or interaction issue.
   It uses a launcher action; there is no global keyboard hook.
5. Use **Open performance reports** or **Export report**. Reports live in
   `data/sessions/<session>/performance/<incident>/`, or the equivalent sessions
   directory in the chosen launcher storage folder. Reports remain local.

The monitor runs in a separate process even while the launcher is minimized or
its UI is busy. Notifications are driven by saved incident IDs, not samples.
Manual marks and automatic symptoms during follow-up share one incident. A
sustained symptom is latched until ten seconds without that symptom. A session
admits at most twenty reports and stops admitting reports after its evidence files
reach 128 MiB; the Developer status explains the limit. Export failures are shown
as errors. Neither recording nor export failures terminate the game.

Recording adds only the two `REO_SLOWDOWN_*` launch variables. It does not select
experimental rendering, resident VU, scheduling, time warp, routes, test inputs, or
the old bounded CSV recordings. Original calls still execute exactly once.

## Sensitive detection for short drops

Enable **Developer → Sensitive detection** alongside Record slowdowns. It applies
to the next launch and is off by default. It checks individual timing records
rather than relying on the displayed, averaged FPS value:

- One visible frame scope or gap between visible scope completions of at least
  40 ms, including menus and in-engine cutscenes without an eligible actor clock.
- One original update interval longer than 1.5 times its verified quantum (50 ms
  at 30 updates/s; 25 ms at 60 updates/s). Duplicate actor callbacks do not reset
  that interval. Epoch changes and loss still break the comparison.
- Original-clock speed below 90% over one second, or two seconds of missing
  observations. Missing observations remain unknown-cause gaps, not proven hangs.

Sensitive mode also records `continuous.csv`, `continuous-health.csv`, and
`continuous-metadata.json` in the session's performance directory. This preserves
observations outside incident triggers, so a missed threshold can be investigated
after play. The combined CSV budget is 128 MiB; reaching it keeps existing data
and continues incident detection, with limited coverage shown in the status.
The monitor flushes every 500 ms; a hard monitor crash may lose the last buffered
observations. A partial final CSV row is ignored during analysis. The incident
budget increases to 100 reports, still subject to the 128 MiB report admission
budget. Symptoms remain coalesced rather than producing a notification for every
late frame.

After a normal exit, `continuous-analysis.json` summarizes the entire trace.
It can also be regenerated with:

```powershell
Outbreak.Launcher.exe --analyze-slowdown-trace <session-performance-directory>
```

Sensitive report exports include these trace files in a `session/` subdirectory.
An export during play copies a bounded prefix and remains partial according to
its metadata. These are host timing observations, not GPU display timestamps or
a guarantee that every perceived problem has been detected. **Mark problem**
remains useful for interactions or visual faults without a timing spike.

## Components and packaging

- `runtime/diagnostics/slowdown_recorder.h`: native transport, configured at
  bootstrap before runtime workers. The verified File #1 actor hook emits clock
  state; the existing capture scope emits frame phases; shader warmup emits its
  begin/end boundaries. CSV recording remains independently opt-in.
- `launcher/SlowdownTransport.cs`: transport reader and owned-process checks.
- `launcher/SlowdownMonitor.cs`: independent monitor entry point, rolling history,
  health sampling, incident persistence, and export.
- `launcher/SlowdownAnalysis.cs`: clock interpretation, detection, and offline
  human/structured findings. It requires no live process.

The helper is the bundled launcher in worker mode, dispatched **before** any
Avalonia application, window, single-instance mutex, or storage lease is created:

```powershell
Outbreak.Launcher.exe --slowdown-monitor <session>/performance/plan.json
Outbreak.Launcher.exe --analyze-slowdown <incident-directory>
```

Players need no Python, debugger installation, administrator account, or service.
The native recorder is currently Windows-only. Other platforms show unavailable
without preventing the normal launch. Development build-kit export explicitly
includes the new authored header; an existing sealed kit is not updated in place.
No dependency source or patch series was modified for this implementation.

## Transport schema 1

Windows x64, little endian. The mapping name is
`Local\REO-slowdown-<random-32-hex-session>`, created exclusively by the launcher
before starting the child. A second creation with the same name fails. The
native process accepts the mapping only with the expected version, session token,
and an unpublished handshake. The monitor verifies the launched process's creation
FILETIME, retained process handle, user token, full executable path, and SHA-256.
It holds the executable open against writes/deletion and rejects native identity
or QPC-frequency mismatches. It never searches by process name or retries a PID
against another process. The identity includes the launcher's private EXE copy.

The 4096-byte header uses these byte offsets:

| Offset | Field |
| --- | --- |
| 0, 4 | u32 schema, atomic u32 handshake ready |
| 8, 12 | u32 PID, atomic u32 capabilities |
| 16, 24 | u64 process creation FILETIME, u64 QPC frequency |
| 32 | 32 ASCII session bytes |
| 64 | 96 bytes native build ID, zero-terminated UTF-8 |
| 160 | 1024 bytes executable path, zero-terminated UTF-8 |

Capabilities: `1` transport, `2` verified original clock, `4` frame scope actually
entered, `8` warmup boundaries, `0x80000000` producer-registration overflow.
The exact executable SHA-256 supplements the native compile-date/time build ID.

Eight 65600-byte producer rings follow. A thread claims one ring for its entire
lifetime. Rings are never reassigned, including when a thread exits. Each ring
has u32 thread ID at offset 0, atomic u64 write/read/drop counts at offsets
8/16/24, and 1024 64-byte records beginning at offset 64. There are no runtime
dependency header or private build-directory assumptions in this protocol.

A producer reads the consumer index with acquire ordering, copies into a free
slot, then publishes write with release ordering. The monitor acquires write,
copies the complete committed record, then releases read. Producers never change
read or overwrite an unread slot. A full ring drops that observation and increments
its counter immediately; an exhausted producer pool records a capability loss.
There are no producer waits, file writes, locks, stack walks, or per-sample heap
allocations. Initial mapping setup can fail; gameplay then continues without it.

Each record contains `Time:u64` (QPC), `Sequence:u64` (ring-local), `Kind:u32`,
`Flags:u32`, and five u64 payloads `A` through `E`:

| Kind | Payload |
| --- | --- |
| 1 clock | A=clock units (60 per game second), B=room counter, C=packed state, D=packed extra state, E=actor address |
| 2 frame | A=whole capture duration, B=begin→scanout, C=scanout→presentation return, D=presentation return→capture end, E=display tick; durations are QPC ticks |
| 3 warmup | A=1 beginning, 0 finished |
| 4 invalid clock | state could not be interpreted; breaks continuity |

Clock C packs room at bit 0 (16 bits), step at 16, phase at 24, pause at 32,
request at 40, cached room at 48, cached scenario at 56 (each remaining field
8 bits). D packs cache variant at bit 0, subphase at 8, destination at 16.
Frame Flags bits 0/1 indicate whether scanout/presentation boundaries were reached.
Missing boundaries are censored, not zero-duration proof of completed work.

The native producer timestamp, monitor timestamps, and health timestamps share
the verified QPC domain. Evidence stores the producer thread/ring, a bundle-local
ID, and a loss epoch. Ring drops and invalid clocks break clock continuity;
producer overflow means coverage is limited. A quiet stream is not proof of a
quiet worker. Recording overhead on real gameplay still needs measurement.

## Detection and evidence limits

Clock interpretation follows `tools/analyze_game_clock.py`: eligible gameplay
requires phase 2, no pause/request, matching room/cache room, and quantum 1 or 2.
Within one room/step/scenario/cache variant epoch, only unchanged clock/counter or
one quantum with counter +1 continues the sequence. Duplicate actor callbacks
do not count as updates. Invalid records, loss, nonmonotonic times, clock resets,
mode changes and non-eligible samples break continuity. The live observer remains
available beyond the old ten-minute CSV window and beyond its fixed capacity.

Initial thresholds are deliberately explicit, not calibrated promises:

- Original-clock progress below 75% over at least 2 seconds of eligible evidence.
- Visible frame capture wall time of at least 150 ms, or a visible presentation
  gap of at least 250 ms. File #1 also requires recent eligible gameplay.
- Five seconds without an actor observation after the last observed eligible
  gameplay sample: **gameplay observation gap**, with loading/transition,
  instrumentation gaps and blocked workers all unresolved possibilities.
- File #2 without clock coverage: five seconds without a frame scope after the
  last visible presentation is a **presentation observation gap**, with window
  suspension, transitions and blocked work unresolved. Nonzero process exits
  preserve remaining history as partial incidents even without a prior trigger.

Warmup suppresses hitch detection. Retired scanouts and frames without a visible
presentation cannot trigger a presentation hitch. Frame scopes measure host wall
time including CPU, driver calls and waits; they do not measure GPU execution.
The monitor samples CPU time, working set and thread count every 500 ms without
suspending threads. `Responding` is deliberately unknown rather than relying on a
potentially blocking window-message probe.

History is bounded by both time and 16000 records; an incident admits at most
25000 records and 1000 health observations. Extremely high sample rates can
truncate coverage. Follow-up checkpoints are written atomically every second;
the first checkpoint preserves prehistory immediately. A hard monitor failure
can lose up to a second of follow-up. `incident.partial.json` remains analyzable.
Only after writing evidence, `findings.json`, and `report.md` does the saved count
advance. Export copies only these four allowlisted evidence/report filenames.
Paths in process identity are included; account files, logs, saves, executable
bytes, disc assets and guest RAM are excluded.

The existing suspension-based `ext_sampler` is **not** automatically invoked or
claimed to be hardened. This version has no automatic stack sampling, detailed
VU/wait attribution, GPU timestamp capture, actor-memory capture, or deterministic
input replay. These missing capabilities are reported explicitly. A long measured
frame phase can narrow the source investigation, but does not by itself identify
the responsible function or establish a root cause.

## Developer / AI investigation

1. Read `report.md` and `findings.json`, then follow evidence IDs into the raw
   incident records. Verify completeness, capabilities, loss epochs and identity.
2. Keep **measured symptom**, **measured bottleneck**, **suspected cause**, and
   **controlled fix/retest confirmed cause** distinct. The analyzer produces the
   first two, limitations, and an explicit unknown root cause.
3. Locate the cited clock/capture sources. Correlate measured host phases with
   independently collected VU, wait, pipeline or GPU evidence when needed. Prior
   `SCENARIO_RUNTIME.md` measurements are examples, not evidence for this case.
4. Make a focused candidate fix. Runtime dependency changes require the published
   patch workflow and matching rebuilt libraries. VU compilation changes still
   require exact-program admission and interpreter/compiled replay verification.
5. Retest the same game/build configuration, room and interaction. Record baseline
   and candidate under comparable conditions, including diagnostics off to measure
   observer overhead. Preserve both bundles and describe reproducibility and
   unknowns. A report alone cannot replay or prove a fix.

## Checks

Run the dedicated check with Visual Studio C++ tools and the .NET 10 SDK:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File tools/slowdown_check/check.ps1
```

The synthetic native fixture exercises the real shared mapping, identity
handshake, full rings, producer limits, cross-process concurrent acquire/release,
frame phases, worker entry point, manual capture, partial exit, offline analyzer,
and export. Pure checks cover actor deduplication, quantum/reset/room/mode/loss
boundaries, pause/warmup suppression, and incident coalescing. These checks contain
no game assets and do not claim a real gameplay capture or controlled fix/retest.

Local verification on 2026-11-03: both native game targets and the self-contained
Windows launcher built successfully; 42 dedicated checks (including an optional
rebuilt-native `--help` handshake) and 66 headless launcher checks passed. Both
rebuilt editions published the native recorder handshake. No real gameplay
incident, diagnostics overhead comparison, or controlled fix/retest was recorded.
To include the native executable smoke check, set `REO_SLOWDOWN_NATIVE` to its
path before running the dedicated check. This invokes `--help`, not gameplay.
