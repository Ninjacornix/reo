# Modern camera (File #1)

An over-the-shoulder third-person camera for Resident Evil Outbreak File #1,
built on the native room camera (see
[native-gameplay/HYBRID_INTEGRATION_PLAN.md](native-gameplay/HYBRID_INTEGRATION_PLAN.md),
steps 1 and 1b). It replaces the fixed camera angles during ordinary play and
works with a controller and with keyboard and mouse.

## Turning it on

Launcher: **Controls > Modern camera**, switch on **Third-person camera**. The
tab says whether the installed File #1 build contains the native camera; builds
without it keep the original camera. Settings apply on the next launch.

| Setting | Effect |
|---|---|
| Mouse look | Mouse turns the camera (cursor hidden and kept in the window) |
| Invert vertical look | Up/down reversed for stick and mouse |
| Mouse sensitivity | 10–400 % of 0.12° per mouse count |
| Stick look speed | 10–400 % of 4°/3° per frame (horizontal/vertical) at full tilt |
| Distance | Camera distance behind the character (120–600) |
| Shoulder offset | Sideways offset; negative values put the camera over the left shoulder |

## Controls

| Action | Controller | Keyboard and mouse |
|---|---|---|
| Look | Right stick | Mouse |
| Walk (relative to the camera) | Left stick | Movement keys (WASD by default) |
| Aim (turns the character to the camera) | R1 | Right mouse button (or the R1 key) |
| Fire / action | Cross while aiming | Left mouse button (or the Cross key) |
| Recentre behind the character | R3 | R3 key (X by default) |
| Zoom | — | Mouse wheel |
| Free / capture the cursor | — | C / click in the window |

Arrow keys still turn the camera like the right stick. While the camera runs,
the game does not see the right stick, so right-stick ad-libs are off.

## How it works

- The native room camera (`recomp/overrides/native_camera/`) replaces o2
  `0x5BED30`. The third-person mode replaces its eye/aim after the native
  camera has selected the room camera record, then publishes the view through
  the game's own renderer command (`0x1AF780`).
- Walking uses the game's own analog movement (`0x6621F0`), which moves
  relative to the published camera; the launcher sends movement keys as the
  left stick while the camera runs.
- Walls: the game's segment test against room geometry (o2 `0x5795E0`) pulls
  the camera in front of walls.
- Room culling still follows the room camera record nearest the character, so
  the game draws what that fixed angle needs.
- Door and event cameras (scripted selections) keep the original angle; the
  camera returns when ordinary play resumes. Cutscenes are unaffected.
- Mouse: SDK patch `0132-mouse-look-capture.patch` adds raw mouse input and
  cursor capture to the game window.

Game switches (set by the launcher): `REO_NATIVE_ROOM_CAMERA=1`,
`REO_CAMERA_MOD=tps`, `REO_CAMERA_MOUSE=0|1`,
`REO_CAMERA_TPS=distance=…,side=…,mouse_sens=…,yaw_speed=…,pitch_speed=…,invert_y=…`
(also `pivot`, `pitch`, `aim_distance`, `aim_side`, `aim_pivot`, `smoothing`,
`pitch_min`, `pitch_max`, `zoom_step`, `turn_sign`).

## Limits

- No crosshair yet; aiming turns the character but the gun keeps the game's
  own three heights.
- Geometry that no fixed camera ever showed can pop in or show room edges.
- NPCs and props can come between the camera and the character (collision is
  against room walls only).
- File #2 and other disc versions are not supported.
- Online play: the camera only changes the local view, but it has not been
  tested in co-op.
