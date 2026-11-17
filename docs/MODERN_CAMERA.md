# Modern camera (File #1 and File #2)

An over-the-shoulder third-person camera and a first-person view for Resident
Evil Outbreak File #1 and File #2, built on the native room camera (see
[native-gameplay/HYBRID_INTEGRATION_PLAN.md](native-gameplay/HYBRID_INTEGRATION_PLAN.md),
steps 1–1e). It replaces the fixed camera angles during ordinary play and works
with a controller and with keyboard and mouse.

## Turning it on

Launcher: **Controls > Modern camera**, switch it on. It applies to the selected
game when its installed build contains the native camera (otherwise a line in the
tab says so and the original camera is used). Settings apply on the next launch.

| Setting | Effect |
|---|---|
| Starting view | Third person (over the shoulder) or first person |
| Mouse look | Mouse turns the camera. Fullscreen captures the cursor at once; in a window, click into the game first |
| Invert vertical look | Up/down reversed for stick and mouse |
| Mouse sensitivity | 10–400 % of 0.06° per mouse count |
| Stick look speed | 10–400 % of 4°/3° per frame (horizontal/vertical) at full tilt |
| Distance | Camera distance behind the character (60–600, default 170) |
| Shoulder offset | Starting sideways offset (default 45); negative values start on the other shoulder |
| Show crosshair | Crosshair while aiming and in first person (default on) |
| R3 switches shoulder | R3 moves the camera to the other shoulder; off: R3 recentres the camera behind the character |

## Controls

| Action | Controller | Keyboard and mouse |
|---|---|---|
| Look | Right stick | Mouse |
| Walk forward / sideways / back (the character always faces where the camera points) | Left stick | Movement keys (WASD by default) |
| Aim: the camera moves closer, a crosshair appears, the character and gun turn to it | Hold R1 | Hold right mouse button (or the R1 key) |
| Move while aiming (no walk animation) | Left stick | Movement keys |
| Fire / action | Cross | Left mouse button (or the Cross key) |
| Switch third / first person | L3 | L3 key (Z by default) |
| Switch shoulder (or recentre, see settings) | R3 | R3 key (X by default) |
| Zoom | — | Mouse wheel |
| Free / capture the cursor | — | C / click in the window |

Arrow keys still turn the camera like the right stick. While the camera runs, the
game does not see the right stick, so right-stick ad-libs are off.

## Smooth camera motion (60 fps)

The game updates 30 times per second. Camera motion is also shown on the in-between
display frame: the repeated frame is reprojected with the frame's depth buffer into
the camera halfway to the next update, in first and third person
([native-gameplay/FRAME_DECOUPLING.md](native-gameplay/FRAME_DECOUPLING.md)).
Characters still move at 30 Hz. `REO_CAMERA_WARP=0` turns it off.

## Modern TPS facing

The character turns toward the crosshair point every frame (rate-limited, `turn_rate`
degrees per frame), not only while aiming. Forward input walks or runs with the game's own
animation straight ahead; sideways and backward input moves the character relative to the
camera (wall-checked) while it keeps facing the camera, so it slides without a walk cycle.
`face=0` restores the original behaviour (the character turns toward its walking direction).

A frame the native camera refuses no longer shows the room's fixed angle: the original
camera still evaluates it, then the modern view is published again. Scripted camera
selections (doors, events) hand the camera back to the game only after they last
`yield_delay` frames (default 20).

## How it works

- The native room camera (`recomp/overrides/native_camera/`) replaces the room
  camera (File #1 o2 `0x5BED30`, File #2 o2 `0x5DF720`). The modern camera
  replaces its eye/aim after the native camera has selected the room camera
  record, then publishes the view through the game's own renderer command.
- Walking uses the game's own analog movement, which moves relative to the
  published camera; the launcher sends movement keys as the left stick.
- Aiming: after the game's aim update (File #1 `0x586AA0`, File #2 `0x5A2020`) the
  character's yaw and gun elevation (`+0xBC8` / `+0xBE0`) point at the crosshair
  point (the screen-centre ray hit-tested against the room), measured from the gun.
- Walls: the game's segment test against room geometry pulls the camera in front
  of walls and stops movement while aiming.
- Room culling still follows the room camera record nearest the character.
- Door and event cameras keep the original angle; the camera returns when
  ordinary play resumes. Cutscenes are unaffected.
- Mouse: SDK patch `0132-mouse-look-capture.patch` adds raw mouse input and
  cursor capture; the crosshair is drawn by the present shader.
- Co-op: the camera writes the local player's yaw, aim elevation and strafing
  position; the game's own actor sync sends them to the other players (verified
  with two File #2 clients: identical values on both after settling).

Game switches (set by the launcher): `REO_NATIVE_ROOM_CAMERA=1`,
`REO_CAMERA_MOD=tps`, `REO_CAMERA_MOUSE=0|1`, `REO_CAMERA_VIEW=third|first`,
`REO_CAMERA_TPS=distance=…,side=…,mouse_sens=…,yaw_speed=…,pitch_speed=…,invert_y=…`
(also `crosshair`, `r3`, `pivot`, `pitch`, `aim_distance`, `aim_side`, `aim_pivot`, `gun_height`,
`smoothing`, `pitch_min`, `pitch_max`, `zoom_step`, `turn_sign`, `eye_height`,
`eye_ahead`, `aim_up`, `aim_down`, `strafe`, `strafe_speed`, `body_radius`, `face`, `turn_rate`,
`yield_delay`).

## Limits

- Moving while aiming slides the character in the aim pose (the engine has no
  separate upper/lower body animation).
- Geometry that no fixed camera ever showed can pop in or show room edges.
- NPCs and props can come between the camera and the character (collision is
  against room walls only).
- Other disc versions are not supported.
