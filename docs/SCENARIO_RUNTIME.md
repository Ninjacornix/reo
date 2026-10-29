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

## Below Freezing Point: separate slowdown investigation

The reporter's second log shows 60 VBlanks/presentations per second but only
15 original game updates per second near its end. Main-thread samples concentrate
at `0x0018D678`, reached from `0x0019F6C0` with return address `0x0019F6D8`.

This is the game's frame queue busy-count loop, waiting on
`0x0029F704 + 4 * (1 - RAM[0x0029FDB4])`. The original VIF1 DMA callback
`0x0018D160` decrements that count at `0x0018D224` after checking completion.
The log has matching raised/handled VIF1 interrupt counts. Its aggregate worker
processing time does not distinguish expensive room-specific VU work from delayed
completion delivery. The Hellfire map change does not establish a slowdown fix.

The next measurement is a repeated affected-room run with VIF kick timing, VU
program census, IRQ timings and game-clock recording, comparing asynchronous VIF1
on and off. Keep the same room, settings and warm shader cache. Do not clear the
busy count or speed up the clock: that would bypass original synchronization.
