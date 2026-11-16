# Hybrid native integration plan

Date: 2026-11-16. Base: branch `native/hybrid`, from snapshot `9a6dba6c`
(`native/stage4-wip`, which preserves the previously uncommitted Stage 4 batch).

## Decision

The all-native Stage 4 route ([STAGE4_COMPLETION_PLAN.md](STAGE4_COMPLETION_PLAN.md))
is **paused**. In 11 days it produced ~125k lines under `game/native/` and
hundreds of qualified original comparisons, but no native frame has run in a
real room. Its Milestone 1 forbids falling back to recompiled gameplay, so
nothing reaches players until the whole frame is native.

Instead, native components replace recompiled functions **one at a time inside
the shipping recompiled game**, each behind a build flag and a runtime switch.
The recompiled game stays playable throughout, and every swap is tested in real
play rather than only in fixtures.

Stage 4 work is not discarded: its components and comparison harnesses are the
supply for swaps. New isolated components are written only when a chosen swap
needs them.

## End goal

A native PC game with **no PS2 runtime**: no guest RAM, no R5900 context, no
PS2Recomp runtime or recompiled code. Gameplay, rooms, actors, camera, input,
saves, audio, movies and rendering are native code over native data structures.
The purpose is modification: removing or adding content, and modes the PS2 game
never had (third-person/modern camera, new movement and control schemes, other
complex modes). The hybrid swaps are the migration path to that, not the
destination.

Swaps move through three ownership phases per subsystem:

1. **Native logic, guest state.** The native function replaces the recompiled
   one but reads and writes the original guest structures (this plan's rules
   below). Safe because recompiled callers still see the same memory.
2. **Native state, guest mirror.** Once a subsystem's main writers are native,
   its state lives in native structures; a projection writes the fields that
   remaining recompiled readers (and saves/co-op) still need back to guest RAM.
   The Stage 4 owners (`World`, `Update`, `NativeSession`, …) are the intended
   native state; their comparison harnesses stay useful here.
3. **Native only.** When no recompiled reader remains, the mirror is deleted.
   The runtime is removed when the last subsystem reaches this phase.

Order of subsystems follows what modding needs first: camera → player
control/movement → actors and rooms → content tables (items, enemies, scenario
scripts) → rendering/presentation. A TPS camera needs native camera ownership
plus native player control; adding/removing content needs native actor, room and
script ownership. Saves, RNG and media are already partly native and finish
along the way.

## The pattern already exists

`recomp/overrides/native_gameplay/` swaps nine save/session entries for native
code today:

| Piece | Where |
|---|---|
| Entry list `X(address, recompiled symbol, kind)` | `recomp/overrides/native_gameplay/entries.inc` |
| Guest-memory ↔ native projection and hooks | `recomp/overrides/native_gameplay/save_session.cpp` |
| Compile gate | `REO_BUILD_NATIVE_GAMEPLAY_SAVE` |
| Runtime switch and install at boot | `REO_NATIVE_GAMEPLAY_SAVE=1`, `recomp/reo_bootstrap.cpp` (~line 1561) |

Stage 3 media (`recomp/overrides/native_adxt`, `native_audio`, `native_host_movie`, …)
uses the same idea. Whether the save/session swap currently builds and runs in
game has **not** been re-verified on this branch; doing so is step 0.

## Rules for every swap

1. **In phase 1, guest memory stays the source of truth.** (Phases 2–3 move it
   to native structures, subsystem by subsystem.) The adapter reads the guest
   structures the original function reads, calls the native component, and
   writes back exactly what the original writes. A native component must not
   keep state between calls unless every change is written through to guest
   memory in the same call. This keeps the remaining recompiled code, saves and
   co-op consistent.
2. **Default off, explicit switch.** One `REO_BUILD_NATIVE_<AREA>` compile flag
   and one `REO_NATIVE_<AREA>=1` runtime switch per swap area. Installation
   fails loudly if the build or executable identity doesn't match (as the
   save/session install does).
3. **Refusal falls back to the original, and is counted.** If the adapter meets
   an input the native code does not support, it calls the original recompiled
   function and increments a refusal counter that is logged at exit. A swap with
   nonzero refusals in a test session is not ready for default-on.
4. **Smallest boundary.** Swap the highest function whose whole body (including
   callees) is native-qualified, not a whole subsystem at once.

## Acceptance ladder for a swap

| Level | Evidence | Meaning |
|---|---|---|
| A. Qualified | Existing Stage 4 original comparison passes on current sources | Native matches original in fixtures |
| B. Wired | Builds into `reo_recomp` with the flag; install log line appears; zero crashes in a smoke run | Adapter compiles and installs |
| C. Equivalent | Shadow mode (below): zero native/original mismatches in return values and declared writes over a scripted session in each listed room | Matches in real play |
| D. Played | A person completes the relevant scenario section with the switch on; refusal count 0 | Usable |
| E. Default-on | Shipped in a release with the switch defaulting to on and an off switch kept | Delivered |

Only C and above count as "works in game". Report each level with the exact
command, build and rooms used.

## Order

### Step 0 — make the hybrid branch buildable and prove the existing swap

- `native/hybrid` is 78 commits behind `origin/develop` (released v1.0.21-rc0
  work) and ~590 ahead. Merge `origin/develop` into `native/hybrid` and build
  `reo_recomp` for File #1 with the shipping LLVM toolchain.
- Build with `REO_BUILD_NATIVE_GAMEPLAY_SAVE=ON`, run with
  `REO_NATIVE_GAMEPLAY_SAVE=1`, save and load at a typewriter, and record the
  result at level B/C/D. This is the template every later swap follows.
- Add a small shared harness for level C (see "Shadow mode" below).

Step 0 findings (2026-11-16):

- Merge done (`3aefe37d`): 14 files / 28 conflict hunks. Native-branch versions won
  where they deliberately superseded develop (CRI observer without PC sampling, native
  CD/resource adapters); develop's OpenGL probe, VSync/display sync, DS4 docs and
  launcher exit diagnostics were kept alongside the native window/media code.
- SDK patches: develop's `0120-audio-paused-voice-drains-only-accepted-pcm.patch`
  did not apply after native `0121`–`0130`. It is rebased as `0131-…` onto the
  legacy host-mixer path behind the native backend dispatch (`9aae455a`). All 132
  patches apply in order to PS2Recomp `c46d1c7`.
- No CMake target builds the save swap; it exists only in kits. Build route used:
  seed kit `build-native-sjuni/candidate-inputs-v39` (its SDK already equals the
  native series, and it compiles `REO_BUILD_NATIVE_GAMEPLAY_SAVE=1` plus the native
  media adapters, all runtime-off by default) refreshed with
  `tools/local_build/refresh_inputs.py`: 165 updated sources, 12 added headers,
  `--source-patch …/0131-…`. Output `build-ninja/hybrid/file1-inputs-v1`, built with
  `build_game.py --jobs 3` into `build-ninja/hybrid/file1-ready`.
- Smoke driver: copy of `build-ninja/rc2/file1_room_driver.py` with `--env KEY=VALUE`
  (the original strips all `REO_*` variables).

Step 0 result — save/session swap at **level B** (2026-11-16, Windows 11, build
`build-ninja/hybrid/file1-ready/reo_recomp.exe` from `9aae455a`, kit sha
`076a6f40…`, SLUS-20765 ELF sha `06bd5fd7…`; cold build 2,420 units, 23 min, 3 jobs):

| Run | Arrived | Exit | Movement | UPS | Save swap |
|---|---|---|---|---|---|
| `smoke-off` | 55.4 s | 0 | 164.8 | 30.0 | not installed |
| `smoke-save-on` (`REO_NATIVE_GAMEPLAY_SAVE=1`) | 54.3 s | 0 | 168.0 | 30.0 | installed; 0 failed / 0 rejected |

Entries exercised with the swap on: `1C55C0` restore ×2, `1AEC50` seed ×1,
`1AEC80` random ×4,947, `1AED60` defaults ×1, `1AEE40` sanitize ×2. Not reached by
this route: `1C5410` capture, `1C5630` clear-second, `1AEDB0` capture-options,
`1BADF0` restore-options (need a typewriter save and the options menu). Both runs
end with the usual "PS2 Thread Exit" after the requested window close.
Shadow run (`REO_NATIVE_GAMEPLAY_SAVE=shadow`, build `file1-ready-v2`, kit sha
`aa4ce595…`, same route): arrived 55.3 s, exit 0, movement 164.8.

| Entry | Compared | Mismatched | Pass-through (provider entry) |
|---|---|---|---|
| `1AEC80` random | 5,140 | 0 | — |
| `1AEE40` sanitize | 2 | 0 | — |
| `1AEC50` seed | 1 | 0 | — |
| `1C55C0` restore | — | — | 2 |
| `1AED60` defaults | — | — | 1 |
| `1C5410`, `1C5630`, `1AEDB0`, `1BADF0` | 0 | 0 | 0 (not reached) |

So random, seed and sanitize are at **level C** on this route. Clear-second and
capture-options are shadow-capable but were not reached. The four provider
entries (capture, restore, defaults, restore-options) call original guest code,
which the runtime's source instrumentation ties to real guest RAM, so they cannot
be shadowed on scratch; their evidence is Codex's fixture comparisons plus a
level D save → quit → load playthrough, which is still open. The two
"Thread does not exist in thread manager" errors appear in all three runs
(off, on, shadow), so they predate this work.

### Shadow mode (level C harness)

Whole-run off/on replays are not frame-exact even with the swap off: the existing
drivers time input by wall clock, and GS/VIF/CD work runs on other threads. Compare
inside one process instead:

- `REO_NATIVE_<AREA>=shadow`: the original recompiled function stays authoritative.
  The hook snapshots the guest ranges the function may read/write, runs the native
  implementation on the snapshot, runs the original on real memory, then compares
  return registers and the declared write ranges. Mismatches are counted with the
  first few call sites and offsets, and printed at exit.
- Level C = zero mismatches over a scripted session covering the listed rooms. The
  write-range declaration per entry is part of the adapter and is reviewed against
  the original's stores (Ghidra/generated source).

### Step 1 — ordinary room camera (`5BED30` lower path)

- **Why first:** the best-qualified component (all 166 rooms / 1,001 camera
  records, 1.26M checks in `room-camera-llvm-v6`). Owning the camera natively
  is the prerequisite for a modern/TPS camera mod (#8) and for camera
  interpolation (#41).
- Native: `game/native/gameplay_scenario/room_camera.hpp` (`RoomCamera::evaluate`).
  It works on native `SequenceControl` / `CameraParameters`, so the adapter
  must project the camera header (including the one-shot byte `3DDDB4`) and
  write back the display publication.
- Higher camera modes (`5BE9A0`, `Worker::camera_modes`) stay recompiled until
  their prepared batch is qualified (level A).

Step 1 result (2026-11-16) — adapter `recomp/overrides/native_camera/`, build flag
`REO_BUILD_NATIVE_ROOM_CAMERA`, switch `REO_NATIVE_ROOM_CAMERA=1|shadow|shadow-writes`.
Hooks o2 `5BED30` and `5BE3E0` (records import) through
`registerOverlayFunction(0x570000, …, id 3)`; links the Stage 4 native archives
from `build-native-sjuni/gameplay-native-llvm-v1` (57 archives, +0.3 MB exe).
Kit v3 = v2 + adapter unit (template: save adapter unit) + 54 native headers +
archives as `authored-runtime` independent inputs.

| Run (Outbreak opening, room 1) | Calls | Result |
|---|---|---|
| `shadow` | 757 | 756 compared, **0 mismatched**, 1 refused |
| `shadow-writes` (byte-precise, renderer-attributed) | 485 | 483 compared, 0 mismatched; see below |
| native (`=1`) | 752 | 751 native, 1 fallback; same movement profile as off/shadow runs |

- The one refusal is the first call of the room: no camera chosen yet
  (condition 255, selection 0); native returns `unavailable`, original runs.
- Original writes outside the declared outputs, after excluding writes made inside
  `0x1AF780`: `0x323EDC–0x323EE6` and `0x324050–51` once (first call only, which
  native refuses anyway), and 2-byte fields at `0x2B081C/87C/89C/8FC`. The
  `0x2B0800` block also changed between camera calls in 388/484 checks, so it has
  another (concurrent) writer and is not a camera output.
- Movement totals differ run to run (164.8 / 806.6 / 758.7) because the driver
  times input by wall clock; per-step movement is identical across runs.
- Coverage is one room. Level C for the camera needs shadow runs across room
  transitions, cinematic hand-offs and the other camera record types (the
  fixture test covers all 166 rooms, the game run does not yet).

### Step 2 — frame cadence investigation (60 fps / interpolation, #11, #41)

- Not a swap. Identify where the 30 Hz game update and the presentation are
  separated today (`recomp/overrides/reo_game_clock_observer.h`,
  `runtime/gs/frame_pacing.h`) and which state an interpolated frame needs
  (camera from step 1, actor root transforms, maybe bone poses).
- Output: a short doc stating whether interpolation can render between two
  guest snapshots without changing game timing, and what it needs natively.
  No implementation until that is answered.

### Step 3 — host analog input (`6621F0`)

- Unlocks remapping, mouse camera control and modern movement on top of step 1.
- Blocked at level A: the ledger reports a selector/input-mask mismatch and an
  unqualified head-target helper, and contradicts itself about whether analog is
  already wired. Fix and re-qualify first.

### After step 3

Choose further swaps only from a concrete user-visible need (a bug, a requested
feature, a performance hotspot), not from coverage. Candidates with existing
qualification include idle actions (`66B960`/`66B990`), timed scene text, and
scenario commands `169`, `1A8`, `1A4`, `5A`.

## Not doing

- No further Stage 4 "seal a cohort" batches, multi-lane integrator schedule, or
  new components without a swap that needs them.
- No editing of generated recompiled code; swaps go through overrides only.
- No default-on swap without level D.
