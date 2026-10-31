# Scenario runtime investigation: issue #26

[Issue #26](https://github.com/Ninjacornix/reo/issues/26) reports two symptoms in
v1.0.20-rc0: slow motion in Below Freezing Point and a crash on Hellfire's building
ledge. They require separate validation. Investigation started on Windows x64
from `develop` commit `9d9e089`, in an isolated worktree, on 2026-10-29.

## Hellfire: missing actor callback

The reporter's crash log ends with an unimplemented call to `0x005D8620`, with
return address `0x00573864`. The latter is the return site of the actor callback
dispatch in `0x00573840`. Repeated missing-function warnings precede the crash.

The supported File #1 NTSC-U v2.00 ELF is SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The locally extracted `BIN/2.DAT` image has load base `0x00570000`, overlay ID 3
and decompressed SHA-256
`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Instruction inspection establishes three callable entries inside one old map row:

| Entry | Exclusive end | Behavior |
| --- | --- | --- |
| `0x005D85E0` | `0x005D861C` | Checks a related actor, may change state, then tail-calls the shared body |
| `0x005D8620` | `0x005D8628` | Tail-calls the shared body without running the preceding checks |
| `0x005D8630` | `0x005D8850` | Executes the shared state handler and restores its own stack frame |

`recomp/config/overlay_maps/ovl2.csv` now describes these separately. This makes
both overlay generators emit distinct functions and ID-gated registrations.
Registering `0x005D8620` as an alias of the old generated function would execute
the wrong prelude, because that function does not resume at this entry.

## Validation

- PASS: `python -m unittest discover -s tools/local_build -p test_overlay_entries.py -v`
  with `REO_TEST_RECOMPILER` set to the existing patched tool: four tests. The
  synthetic integration fixture checks registration, exact bounds and tail-call
  separation without using game data. The map test fails against the old row.
- PASS: `python -m unittest discover -s tools/file2_port -p test_scan_overlay_gaps.py -v`:
  eight scanner tests.
- PASS: `python tools/overlay_recomp.py <private-overlay-directory> <patched-recompiler>
  --maps recomp/config/overlay_maps 2` against the locally extracted owned overlay.
  The generated registry includes all three entries; the shared body's generated
  resume entries remain registered.
- PASS: a private MSVC fixture compiled the three regenerated functions and
  dispatched them through the existing runtime's overlay lookup. Nine checks
  cover callback lookup, original return PC/stack restoration, skipping the
  unrelated prelude, retaining that prelude's state transition, and rejecting
  a different loaded overlay ID. Two downstream cleanup functions were test
  doubles; this was not a full actor or scenario simulation.

The complete Hellfire ledge route still needs a gameplay retest. Existing builds
must regenerate and recompile the overlay; editing the map does not patch an
already-built RC0 executable. Generated sources and owned assets remain local.

### Common helper reached during the opening retest

The Hellfire opening then exposed repeated missing-function warnings at
`0x00370080`. This is the first code entry in the common `BIN/0.DAT` overlay
(load base `0x00370000`, overlay ID 1), immediately after its 0x80-byte header.
The old `ovl0.csv` started its real code map at `0x003700C0`, omitting this entry.

Instruction inspection shows a complete 64-byte function at
`0x00370080..0x003700C0`: mask the input to eight bits, convert to float, multiply
by the original scale at `0x0038B298`, and tail-call `0x00192190`. The adjacent
`0x003700C0` entry handles a different input width, so it is not an alias.

`ovl0.csv` now includes the missing range. The synthetic overlay regression checks
that the first code entry is registered with the correct loaded-overlay identity
while header rows remain excluded. A private native fixture also executes the
actual regenerated helper for all 256 eight-bit inputs and three wider inputs,
checking the float argument, original return address, unchanged stack and rejection
under a different overlay ID. The downstream math target is a test double in this
fixture; the opening retest exercises the real target. The final Hellfire retest
removed all 710 missing-helper warnings seen in the preceding run.

## Below Freezing Point: missing compiled VU variants

The reporter's second log shows 60 VBlanks/presentations per second but only
15 original game updates per second near its end. Main-thread samples concentrate
at `0x0018D678`, reached from `0x0019F6C0` with return address `0x0019F6D8`.

This is the game's frame queue busy-count loop, waiting on
`0x0029F704 + 4 * (1 - RAM[0x0029FDB4])`. The original VIF1 DMA callback
`0x0018D160` decrements that count at `0x0018D224` after checking completion.
The log has matching raised/handled VIF1 interrupt counts. Its aggregate worker
processing time alone does not distinguish expensive room-specific VU work from
delayed completion delivery.

An isolated local run reproduced the slowdown in the subway starting room on a
Ryzen 5 2600 / RX 570. The route used Kevin, Normal difficulty, default partners,
native internal resolution, 640 x 480 output and no post AA. Only scenario unlocks
were enabled, with copied saves; health, ammunition and gameplay timing stayed
unchanged. The owned ISO was mounted read-only for the test.

VIF timing and actual program collection identified three uncatalogued VU images.
The dominant image used the interpreter for every instruction and accounted for
77.9% of VU time in the diagnostic window. VIF batches spent about 60 ms executing
VU programs while measured GS queue waits were only tens of microseconds.
Each new image was independently reconstructed byte-for-byte from ordered uploads
and file offsets in the supported ELF:

| SHA-256 prefix | Observed entry PCs (bytes) |
| --- | --- |
| `85e7a8fbc584` | 0, 128, 536, 1720 |
| `c5e55542acbe` | 0, 128, 544, 1600, 2944 |
| `e6181d374c50` | 0, 120, 320, 1048 |

`local_vu_images.json` now includes these exact identities, copy ranges and entry
keys. The local generator emits a separate default table for marked images and
entry keys. Runtime registration uses that table automatically; `REO_VU_WHOLE=0`
disables it and `REO_VU_WHOLE=1` admits the full experimental table. Older metadata,
raw diagnostic captures and older generated factories retain their opt-in behavior.
The existing specialized/native routes continue to take precedence.

Validation:

- PASS: all 11 catalogued images reconstruct to their expected SHA-256, including
  exact byte equality with all four launched images from the captured route.
- PASS: seven synthetic default-policy tests and eight existing local-generation
  tests. Mixed raw captures cannot broaden the entry keys admitted by default.
- PASS: twelve native registration checks exercise default admission, explicit
  opt-in/out, the master switch, and backward compatibility with an older factory.
- PASS: the reusable `tools/vu_whole_aot/run-check.bat` oracle replays 512 captured
  `c5e55542acbe` invocations plus 64 each for `85e7a8fbc584` and `e6181d374c50`,
  covering every observed entry of all three variants. Compiled execution matches
  the interpreter for every byte of the 632-byte VU state, 16 KiB VU data and
  604 GIF packets (1,085,440 bytes).
- PASS: the final default build restores normal game updates and clock advancement
  without any `REO_VU_WHOLE` override. Startup confirms exactly three default
  programs registered; both runs exit normally with no dropped or invalid clock
  observations.

| Measurement, room seconds 3 through 13 | Baseline | Final default build |
| --- | ---: | ---: |
| Game updates/s | 14.975 | 29.993 |
| Game clock units/s | 29.949 | 59.987 |
| Median update interval | 66.634 ms | 33.282 ms |
| p99 update interval | 68.209 ms | 35.657 ms |

The timing comparison uses selected-player, unpaused phase-2 updates with identical
settings and warmed shaders. VU census, program collection and kick profiling were
disabled for timing: census hashing itself slows this workload. Presentation stayed
at 60 Hz in both builds. The candidate replaces the generated VU table and its
registration hook; the preceding eight-image factory matches the current
generator's old-plan output. Full scenario completion and other frozen areas
remain untested. Test processes were closed and the task-mounted ISO dismounted;
original saves and the separate dirty checkout were preserved.

## All five chapter openings

At the owner's request, the opening of every File #1 chapter was checked with
`builtin unlock` and a fresh private copy of the saves for each run. Kevin, Normal
difficulty, default partners and the same native-resolution graphics settings
were used. The driver selected each chapter through ordinary controller input,
confirmed its actual menu cursor and captured the opening visually. Boot-only
fast-forward ended before the menu; gameplay and the measured window ran at
normal speed.

Each opening ran for 25 seconds, with a 28-second Below Freezing Point follow-up
to check movement before its next cutscene. Update rates use unpaused selected
player observations in opening seconds 3 through 13. Movement required position
changes during ordinary pad input while staying in the same room and unpaused
gameplay, rather than counting a cutscene relocation.

| Chapter | Initial gameplay room | Updates/s | Movement | Crash / missing functions |
| --- | ---: | ---: | --- | --- |
| Outbreak | 1 | 29.998 | Verified | None |
| Below Freezing Point | 1 | 29.999 | Verified | None |
| The Hive | 8 | 29.998 | Verified | None |
| Hellfire | 27 | 29.998 | Verified | None |
| Decisions, Decisions | 80 | 30.002 | Verified | None |

All accepted runs exited normally with game-clock advancement near 60 units/s.
Two logs contain `PS2 Thread Exit` cancellation messages only after the test
requested window closure; these are retained separately from gameplay errors.
The first Hellfire run exposed the common helper gap described above. Hellfire
and Below Freezing Point were repeated after adding that entry; the other three
runs already had both original issue fixes and never called the missing helper.

Private evidence is under `build-ninja/issue26/chapter-opening/summary.json`, with
per-chapter screenshots, input histories, launch identities and clock recordings.
The final helper build is SHA-256
`73bd0ee8dc4e750e29e1c70101a11d031e123769bb78190edb25d7901e2cfef8`;
the preceding build differs only by the added common-helper function and
registration. No test processes remain and the task-mounted ISO was detached.
Original saves were preserved. These checks cover beginnings, not full chapters
or the Hellfire ledge traversal.

## RC1 follow-up: ice and smoke effects (issue #26)

The [latest report on 2026-10-31](https://github.com/Ninjacornix/reo/issues/26#issuecomment-6547642583)
confirms that RC1 fixes the Hellfire crash, but reports slow motion in Below
Freezing Point's frozen areas and Hellfire's smoke areas. It does not include a
new RC1 log, exact room names, or a save at the slow room. The earlier tables
above cover chapter openings only. They do not establish that this remaining
report is fixed, nor that GPU utilization is its cause.

Branch `fix/issue-26-rc1-effects-performance` adds a File #1 diagnostic chapter
selector to the existing automatic input route:

```
REO_TEST_ROUTE=gameplay
REO_TEST_SCENARIO=1
```

Chapter indices are 0 Outbreak, 1 Below Freezing Point, 2 The Hive, 3 Hellfire,
and 4 Decisions, Decisions. Use a private memory-card directory and unlock all
five chapters there; a temporary `REO-CHEATS-2` manifest with `builtin unlock`
can provide availability. The route observes the original list count and
cursor and sends ordinary pad input. It also confirms the extra unlocked-mode
screen before difficulty selection, retaining the default choice. Missing or
empty `REO_TEST_SCENARIO` retains the existing route. Invalid arguments,
explicit File #2 selection and incomplete lists stop automatic input. No guest
state is patched by the selector. Fixture instructions are in
`tools/scenario_route_check/README.md`.

For reproduction, retain `runtime.log`, a game-clock journal, chapter/room and
player movement details. Record an ordinary warmed run with VU collection and
profiling disabled before collecting a separate diagnostic pass. The existing
`REO_VU_PROGRAM_LOG=1` / `REO_VU_PROGRAM_DIR` observer can identify uploaded and
launched images, but its full-image hashing and disk writes perturb timing.
A collector limit can stop observation before the affected room; check its
termination record. Compare actual launched image/entry identities against
`recomp/config/local_vu_images.json`; matching the catalogue alone does not prove
that an optimized executor ran or that its output is correct.

The default remains the three previously verified VU images. Do not treat
`REO_VU_WHOLE=1` as a released fix: the additional experimental images require
replay and visible-room verification. Also, the current whole-program branch
of the dependency reports zero matched pairs to kick/cost attribution despite
updating its census count. Its generic/unknown pair totals cannot, on their
own, establish interpreter fallback; inspect actual admission or replay first.

Local follow-up uses the Mac native build as an offscreen diagnostic rig.
It cannot establish Windows RTX 3060 utilization, visible effects correctness,
or MoltenVK/native-Metal performance equivalence. RC1 slow-room verification
remains open pending a precise reproduction and a visible Windows run.

Follow-up checks on Apple M2 / MoltenVK, native resolution, offscreen:

- The C++ fixture passes 68 checks; the native File #1 bridge compiles and links.
- Below Freezing Point selects cursor 1 of 5, confirms the unlocked-mode screen
  and reaches room 1. The journal contains 1,353 actor observations, 450 ordinary
  updates over 15.00085 host seconds (29.998 updates/s), with zero dropped,
  invalid or unpublished records. This is an instrumented diagnostic window,
  not a benchmark of the reporter's slow room.
- Hellfire selects cursor 3 of 5 and passes the same menu confirmations. The
  80-second run exits normally but produces zero active-actor journal rows.
  The route's early `reached gameplay` message alone is insufficient evidence
  of interactive gameplay; this run does not validate Hellfire performance.
- Both VU collectors stop at their 64 MiB byte limit: 339,745 launches for
  Below Freezing Point and 341,471 for Hellfire. No unknown image appears in
  the collected portion. Later execution is unobserved. The Below Freezing
  Point portion includes all three already-approved default images, so simply
  adding those images again would not address this report.

Private evidence is under `build-ninja/issue26/chapter-1-confirmed`,
`chapter-3-confirmed` and `follow-up-summary.json`. The local candidate reuses
Mac build objects, replacing only `pad2TestRoute` plus its new header. It is
not a rebuilt or tested Windows RC1 executable. Raw VU images, game data,
private cards and binaries remain ignored and are not part of this branch.
