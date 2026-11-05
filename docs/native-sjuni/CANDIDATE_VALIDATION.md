# Separate SJUNI candidate validation

2026-11-05. Status: isolated checks, separate cold game build and four controlled
integration smoke runs passed their stated checks. This is not full-game,
frame/waveform equivalence or performance validation.

The user authorized a separate build and controlled game tests after the isolated
checks. Player build outputs, saves and launcher settings remain separate.

## Build identity

The candidate starts from the sealed File #1 input SDK, verified against all
4,053 manifest members. Base manifest SHA-256:
`68ff54ffbd35553c2dd48be1f1ab2b9aaa32f7aa2037e763c5f82df177a871a9`.
Its public dependency source proof is based on PS2Recomp revision
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f` plus the SDK's recorded patch series.
This frozen baseline is older than the current player build. Compare original
and native modes using the **same candidate executable**, rather than attributing
differences from a different executable to SJUNI.

[Preparation](../../tools/native_reconstruction/prepare_sjuni_candidate.py)
copies the sealed SDK, adds eight explicitly hashed authored source/header files,
injects registration before the natural-mode early return and adds the three
native compilation units. No dependency source is edited. Prepared manifest:
`bf5a89f4fc6a75bb2a735260f57676c9dc5396f9308593d2b29a66b76fb4e7f1`.
Frozen adapter source:
`fd3162c2dfdf42c14da99e1a05791587c6040b1e96b495bd87416bb12e9143dd`.

[Build driver](../../tools/native_reconstruction/build_sjuni_candidate.py)
verifies the whole installed LLVM/MinGW UCRT 20251216 compiler/sysroot receipt
(5,601 files), with archive SHA-256
`2d96a4b758f7f8deaec5065833fe025aa53cfc5f704d0524002510984da0ccf4`.
It invokes the SDK's ordinary build worker, rebuilding runtime, backend and game
together. No precompiled private PS2 runtime library is used. Owned imported disc
data is read in place; the supported ELF hash is
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.

Local outputs and detailed receipts stay below ignored `build-native-sjuni/`:

- `candidate-inputs-v1/`: sealed candidate SDK and source delta notice.
- `candidate-work-v1/candidate-build-inputs.json`: source/compiler input identity.
- `candidate-work-v1/candidate-build.log`: complete build log.
- `candidate-work-v1/candidate-build-result.json`: final build status/output hashes,
  written on build completion.
- `candidate-game-v1/`: separate executable/dependencies.

The completed build compiled **2,347 units with zero cached units** and linked
successfully. Executable SHA-256:
`ce6a3768d215b8ee9e5ef83e0e5abb775476fd22e1f0a87a69b2336db36b23c1`.
Runtime dependencies and helper shaders have individual hashes in the build
receipt. The native resource core is a separate isolated target and is not part
of this SJUNI candidate.

## Isolated evidence

`verify_sjuni.py` passes the 22 Python oracle/continuation tests, 11 core and 10
bridge groups, 253 native calls/225 callback images, three hybrid continuation
cases and the seeded 512-operation comparison. Its source/compiler-bound receipt
is `build-native-sjuni/verified/receipt.json`. Error callback ordering is excluded
from the fuzz probe's native error paths, as described in the main inventory.

The actual runtime adapter passes 13 host-only scenarios and compiles against
the current real runtime headers. These checks use mocked dispatch/scheduling
services, not live audio, DMA, IOP or scheduler behavior.

## Controlled test requirements

Use the existing owned-process playtest harness, a fresh private session/card,
copied executable/dependencies and read-only shared game assets. Record the actual
PID, creation identity and copied executable hash. Never attach by process name.

Compare `REO_NATIVE_SJUNI=0` with `REO_NATIVE_SJUNI=1`,
`REO_NATIVE_SJUNI_GUARDED=1`, `REO_NATIVE_SJUNI_TRACE=1`. Keep other behavior
settings identical, including normal speed and existing rendering/VU defaults.
Observe movie and audio output/progress, gameplay/resource transitions,
pause/resume, repeated loading and shutdown before calling the pilot complete.

An install line alone does not prove migration. Bounded native-body proof lines
count successful committed bodies; logged powers of two provide lower bounds,
not exact totals. Guarded-body proof precedes original leave/epilogue and therefore
does not independently prove completion. Initial missing-binding refusal during
the early load phase may be followed by a successful post-registration install.

Visual captures prove only the captured owned window/scene. Audio diagnostics
prove producer/output progress within their scope, not subjective sound quality.
A supervisor duration-limit termination is not a clean shutdown test. Record
any unexercised consumer or lifecycle transition as pending. No performance
improvement or full native conversion follows from a passing pilot.

## Recorded controlled results

The [structured receipt](controlled-test-receipt.json) retains build, executable,
adapter, session, run and log hashes plus capture hashes and scoped counts. Full
logs, owned-window captures, launch environment and process creation identities
remain under `build-native-sjuni/playtests/`. No original executable bytes or
asset payloads are included in this committed receipt.

All four tests used the executable hash above. They ran one at a time, at normal
speed with the same existing rendering/VU settings. Each received an ordinary
`WM_CLOSE` on its identity-checked private window, exited with **code 0** and
logged execution end, audio device/stream closure, input shutdown and renderer
shutdown. The supervisor classified no fatal diagnostics and did not terminate
any of them. Generic thread-manager warnings and unhandled optional SIF log lines
occurred in the reference as well; this smoke result does not resolve those.

| Private session | Wall duration | Observed route | Nonzero host audio report windows | Reported audio underrun frames |
| --- | --- | --- | --- | --- |
| `original-title-v1` | 86.063 s | Boot to title/media sequence; visible title capture. | 18 / 80 | 0 |
| `native-title-v1` | 94.704 s | Boot to title/media and demonstration movie; visible captures. | 18 / 92 | 0 |
| `original-gameplay-v1` | 229.797 s | Outbreak bar, inventory, pause/resume, Quit Game/results, return to main menu. | 139 / 224 | 0 |
| `native-gameplay-v1` | 280.141 s | Same initial gameplay/menu path, then a second scenario load, opening movies/cutscene and bar gameplay in the same process. | 178 / 276 | 0 |

Movie timing records advanced and captures showed changing title/demo/movie
images. The gameplay route reported original mode 2/modal 0 at 49.477 seconds
in the reference and 49.584 seconds enabled. Those single route times are
observations, **not a speed benchmark**. Actor snapshots and owned-window captures
support actual bar gameplay; the title demonstration alone is not gameplay
proof. In the enabled pause check, local actor frame 20 stayed unchanged across
two samples roughly two seconds apart, then became 32 after resume. This is a
bounded observation of that actor, not a complete scheduler-state comparison.

The enabled title run proves at least **32,768 guarded Get, 1,024 guarded Put,
16 guarded Unget and 32 canonical byte-count bodies**. The enabled gameplay/
reload run proves at least **131,072 guarded Get, 8,192 guarded Put, 128 guarded
Unget and 32,768 canonical byte-count bodies**. These are separately counted
lower bounds; many Gets are polling empty queues. No native proof appeared in
the disabled runs. The enabled runs logged successful known-hook installation
after the expected early missing-binding refusal, and no adapter-disable line.
Availability and both node-count queries were covered only by isolated tests;
these sessions produced no live proof for them.

The same-process second gameplay load was exercised only in native mode; the
reference returned to its main menu and then closed. Inputs and test durations
were not identical after the common initial route. No waveform comparison,
frame-exact comparison, later-room progression, save/load, co-op, File #2,
long-session soak or stress cancellation test is claimed. The independent native
body is reachable in real selected consumers and passed these smoke observations;
the adapter remains opt-in while wider consumer/lifetime coverage is outstanding.
