# Separate SJUNI candidate validation

2026-11-05. Status: isolated checks passed; separate cold game build in progress.
No live playback result is recorded yet.

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
