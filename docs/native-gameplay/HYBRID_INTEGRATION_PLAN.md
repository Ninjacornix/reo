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

1. **Guest memory stays the source of truth.** The adapter reads the guest
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
| C. Equivalent | Same recorded input, swap off vs on: per-frame hash of the guest state the function writes is identical for N frames (N ≥ 3,000) in each listed room | Matches in real play |
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
- Add a small shared harness for level C: record input, run twice (swap off/on),
  hash named guest ranges per frame, report the first differing frame.

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
