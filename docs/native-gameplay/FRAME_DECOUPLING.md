# Frame-rate decoupling (60+ fps, modern frame pacing)

Goal (user, 2026-11-17): the game should not be bound to the PS2's 30 game updates
per second for what the player sees. It should act like a modern game: frames are
presented as fast as the display allows, motion and camera are smooth at that rate,
and game logic keeps its own correct speed.

Status: **design; not implemented.** This records the facts established so far and
the order of work. Plan step 2 in [HYBRID_INTEGRATION_PLAN.md](HYBRID_INTEGRATION_PLAN.md).

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
