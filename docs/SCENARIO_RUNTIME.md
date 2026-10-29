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
  with `REO_TEST_RECOMPILER` set to the existing patched tool: two tests. The
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
