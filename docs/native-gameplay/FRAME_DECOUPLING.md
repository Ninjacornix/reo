# Frame-rate decoupling (60+ fps, modern frame pacing)

Goal (user, 2026-11-17): the game should not be bound to the PS2's 30 game updates
per second for what the player sees. It should act like a modern game: frames are
presented as fast as the display allows, motion and camera are smooth at that rate,
and game logic keeps its own correct speed.

Status: **step 0 implemented (presentation warp, first and third person); steps 1–4 are design.**
Plan step 2 in [HYBRID_INTEGRATION_PLAN.md](HYBRID_INTEGRATION_PLAN.md).

## What modern games do

They separate simulation from rendering. Simulation runs at a fixed step (often 30
or 60 Hz); rendering runs once per display frame and draws the world at
`previous + (current - previous) * alpha`, where alpha is how far the display frame
is between two simulation steps. Input that only changes the view (mouse look) is
applied at render rate. Nothing about game speed depends on the display rate.

## Facts about Outbreak in this port

- Game logic runs at 30 updates/s (performance overlay: FPS 60, UPS 30). Timers,
  animation frame counters, AI, physics and scripts all count those updates.
  Running the PS2 logic faster speeds the whole game up; it must stay at 30 Hz.
- Each game update ends in a complete PS2 frame: VU1 programs transform every
  model with that update's matrices, and the GS backend rasterizes the result.
  The presenter shows that image for two 60 Hz scanouts.
- A GS frame is already-projected geometry. It cannot be re-projected or blended
  into an in-between frame without artifacts; an in-between frame has to be
  rendered again with in-between matrices.
- The camera now has a native owner (`recomp/overrides/native_camera/`) that knows
  eye/aim and the view matrix each update, and the modern camera computes them
  from input directly - the camera is the first piece that can be evaluated at
  render rate.

## Step 0 — presentation warp (implemented 2026-11-17)

The presenter already shows every 30 Hz game frame on two 60 Hz scanouts. The
repeated scanout is now drawn rotated by half of the camera's latest per-update
rotation, so camera turning advances on every display frame. This is rotational
reprojection (as in VR time-warp): a pure rotation needs no depth and is exact up to
a sliver of clamped edge pixels.

- Camera: `room_camera_adapter.cpp` publishes its view direction and lens once per
  update (`reo::performance::warp::publish`) and clears it when the game takes the
  camera back (doors, events) or the view is third person.
- Backend: `parallel_backend.cpp` records the scanout's display buffer
  (`DISPFB.FBP`); the presenter treats a present of the same buffer as a repeat.
- Presenter: `resident_dxgi_presenter1c.h` builds the 3x3 warp
  (`warp::compute`/`warp::build` in `runtime/gs/performance.h`) and pushes it to
  `present_native.frag` / `present_smaa_blend.frag` (`warpPicture` in
  `present_layout.glsl`). Cuts (more than 20° per update), stale views (>100 ms),
  menus and new frames get no warp.

Conventions measured on real frames (`tools/hybrid/room_driver.py --warp-probe`,
first person, eye fixed, `tools/hybrid/warp_validate.py`): vertical FOV = camera
lens (fit 1.00), 4:3 picture, screen x = −(up × forward), screen y = +up.

| Check | Error (mean abs, 0–255) |
|---|---|
| Real 8° turn: unwarped vs after-turn frame | 11.30 |
| Real 8° turn: frame warped by measured rotation vs after-turn frame | **1.55** |
| GPU fixed 8° yaw warp vs the same warp in Python (two views) | **0.33 / 0.37** (unwarped 8.7 / 11.0) |
| GPU fixed 6° pitch warp vs Python | **2.1** (opposite sign 14.1; unwarped 10.3) |

Scope and limits:

- Rotation mode alone is exact only for first person; third person uses the depth
  warp (step 0b). `REO_CAMERA_WARP=0` disables the warp.
- Actors and camera translation still move at 30 Hz (steps 1–2).
- HUD text drawn into the game frame rotates with the repeated frame for one
  scanout during turns (the crosshair and overlays are drawn after the warp).
- Diagnostics: `REO_CAMERA_WARP_LOG=1` (applied warps), `=2` (every present);
  `REO_CAMERA_WARP_TEST=<yaw>,<pitch>` applies a fixed warp to every present.


### Step 0b — depth warp for the orbiting third-person camera (2026-11-17)

At each flip the GS Z buffer of the shown frame is de-swizzled into a linear buffer
(`camera_depth.comp`, context-1 `ZBUF`, here PSMZ32 512x448). On the repeated scanout
`present_warp.glsl` reprojects every pixel with its depth into the in-between
camera (rotation and translation, four fixed-point iterations of a backward warp).

| Measurement | Result | Tool |
|---|---|---|
| Depth mapping | Z = 2^24 / forward distance (ten floor fits: a ~ 0, b 16.67–16.76 M) | `tools/hybrid/depth_calibrate.py`, dumps via `REO_CAMERA_DEPTH_DUMP` |
| Pose lag | 2 camera updates (view switches at serial 121/211/302 reached the scanout at flip 123/213/304) | `REO_CAMERA_WARP_PROBE=1` |
| In-between frames while turning (16 repeats) | background shift median 0.50 of the real frame-to-frame shift; player region stays halfway (still when the player is still) | `REO_CAMERA_WARP_SHOT`, `tools/hybrid/warp_shots.py` |

With lag 2 the next camera pose is already known when the repeat is shown, so the
in-between frame is an exact interpolation, not an extrapolation. Defaults: depth
mapping on, lag 2 (`REO_CAMERA_WARP_DEPTH=off` returns to rotation-only for first
person). Disocclusions (background revealed behind the player during a turn) reuse
the nearest rendered pixel. Actors still move at 30 Hz (step 2).


## Plan, in order

1. **Camera at display rate (first, biggest win for mouse look).** Keep the last
   two game frames' camera poses; at each scanout between updates, rebuild the
   view matrix from the interpolated pose plus mouse/stick input received since
   the last update, and re-render the last frame's geometry with it. Re-rendering
   needs the frame's VU1/GS work to be replayable with a substituted view matrix:
   record the VIF1/GIF command lists of one game frame (the GS replay tooling in
   `tools/gs_dump_replay` already reads such streams) and re-run the VU1 programs
   for that list with the new matrix. Actors stay at 30 Hz in this step.
2. **Actor transforms at display rate.** Keep previous/current root and bone
   matrices per actor (the Stage 4 native World/animation owners have them) and
   substitute interpolated matrices in the replay. Teleports and room changes
   reset the history (no interpolation across them).
3. **Present at any display rate.** Pacing then follows the display (VSync on,
   off, adaptive, 120/144 Hz), with alpha from the steady clock, not the 60 Hz
   scanout count.
4. **Native rendering.** In the long run the native renderer draws from native
   state, and the replay layer disappears together with the PS2 runtime.

## Acceptance

- Same game speed at 30, 60, 120 and 144 Hz display (UPS stays 30.0, game clock
  matches PS2 timing).
- Mouse look updates every display frame (measured: view matrix changes per
  present, not per update).
- No visual artifact on cuts, room changes, cutscenes and teleports (history reset).
- Shadow comparison: the replayed frame with alpha=1 is pixel-identical to the
  original frame.

## Route B, first result: the engine's own 60 Hz step (2026-11-19, File #1)

The game logic itself can run at 60 Hz without speeding up: the engine already scales
its timing by a frame step.

- **Step byte `0x3243CC`** = log2(vblanks counted per update). Option defaults
  (`1BAC20`) set 1 (two vblanks, 30 Hz). About 216 functions read it: timers count
  down by `1 << step` (`1BA920`), durations are divided by `2^step` (`1BB5C0`,
  `1BB650`), and the game clock `0x4BAE00` (h:m:s:frames, base 60) advances by the
  step.
- **Flip interval `0x29FA08`/`0x29FA04`.** The vblank handler `19F600` flips when
  the vblanks since the last update (`0x29FA0C`, reset by `19F6C0`) exceed the
  interval and the frame is ready (`0x29FA10`, set by `1A9070`). Game init `1BAEC0`
  requests interval 1 through `1A0CF0`. The frame end `1A90B0` waits (vsync loop
  `1133F0`) until the flip clears the ready flag.

`REO_GAME_RATE=60` (`recomp/reo_bootstrap.cpp`, opt-in, File #1) wraps the per-update
service `19F6C0`. It sets interval 0 (flip on the next vblank) and chooses the step
per update from the vblanks the previous update took (`0x294170`): one vblank
gives step 0, two or more give step 1. Game time stays real time when an update
misses a vblank.

| Run (Below Freezing Point, analog exploration, build `file1-ready-v48`) | Updates/s | Game clock units/s | Movement |
|---|---|---|---|
| default | 30.00 | 60.00 | 951 units, exit 0 |
| step byte 0 only | 27.7 | 27.7 (half speed) | — |
| step 0 + interval 0, fixed | 29.6 | 29.6 (half speed) | — |
| `REO_GAME_RATE=60`, adaptive | **50.6** | **60.00** | 948 units, exit 0 |

Where the remaining time goes (gameplay, `[GAME-RATE-STATS]` per 300 updates):
about 8 ms of game work, then 8–12 ms waiting in `18D650` for the previous frame's
DMA (the PS2 VIF1/VU1/GS path) to finish. About 15% of updates therefore miss the
vblank and take the 30 Hz step. In light scenes, 300 updates take exactly 300
vblanks.

Not covered yet: co-op (peers would run at different rates), cutscenes, movies,
File #2, a person playing. Above 60 Hz the engine cannot step finer than one
vblank, so 120/144 Hz still needs presentation interpolation (steps 1–3 above) on
top of this.

Next: make the graphics path (VIF1/VU1/GS on the host) finish a gameplay frame
within one vblank, so every update takes step 0.

### Graphics path: the busiest VU1 program now runs fully compiled (2026-11-19)

Per-kick VU1 profiling (`REO_VIF_KICK_TIMING_AT`, `REO_VU_COST_ATTRIBUTION=1`) of
Below Freezing Point gameplay at 60 Hz: a frame's VIF1 kick took about 10.2 ms on the
async VIF1 worker, 9.3 ms of it VU1. Image `5273fa3e9893` (entries 0, 88, 296, 1320)
had about 4.5 ms per frame: it is a validated default whole program in
`local_vu_images.json`, but File #1 consulted whole programs only for images
**without** a specialized table, and this image has one (one block at 608). So it ran
as partial native kernels plus interpreted pairs (about 7 ns per pair). The two
"unknown" entries `0x640`/`0xB80` already run compiled: they cost 22.4 ms per frame
with `REO_VU_WHOLE=0` and 4.2 ms by default (cost attribution reports whole
programs with a null key).

SDK patch `0134-file1-vu-whole-program-first-switch.patch`: `REO_VU_WHOLE_FIRST=1`
(File #1) runs a validated default whole program before the specialized blocks and
native kernels of the same image. Without a selected whole program nothing changes.

| Build `file1-ready-v49`, `REO_GAME_RATE=60` | Before | `REO_VU_WHOLE_FIRST=1` |
|---|---|---|
| VU1 per gameplay frame | 9.3 ms | 6.6 ms |
| updates taking one vblank (late window) | about 85% | 95–97% |
| vblanks per 300 updates | 345–368 | 310–316 |
| game clock units/s | 60.00 | 59.98 |
| movement, exit | 948 units, 0 | 977 units, 0 |

Replay oracle (`tools/vu_whole_aot/run-check.bat … --default`, work-folder runtime,
`REO_VU_WHOLE_FIRST=1`): 512 gameplay launches of `5273fa` captured with
`REO_VU1_DUMP_CODE_IMAGE`: **PASS**, 512 of 512 selected the default whole program,
identical 632-byte state, 16 KiB data and 820 GIF packets (865,648 bytes); replay
26.9 ms interpreted path vs 6.1 ms compiled. Captures and generated code stay in
ignored `build-ninja/hybrid/`.
