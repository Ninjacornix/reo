# Graphics preview

Graphics keeps its settings in a scrolling column on the left and an animated
Kevin scene in a narrow column on the right. Its full-height crop keeps Kevin
centered while cropping the room's sides. Scrolling to brightness, gamma or additional options
does not move the preview. Picture changes render immediately; the same settings
are saved for the next game launch. Session options such as geometry workers and
movie decoding continue to apply to the game rather than changing a still scene.
All tabs use the same 300 ms foreground fade when Windows animations are enabled.
The native preview receives the current WPF opacity in its final GPU shader pass,
blending against the launcher background so Kevin fades with the surrounding controls.
Navigation captures no outgoing page snapshots and production still performs no GPU readbacks.

`GamePreviewAssets.LoadShared` loads one Kevin scene for the launcher from either
owned edition, preferring File #1 when available. Game selection does not clear
the scene, restart its clock or replace its GPU resources. The source key contains
both import paths and the storage home, not the selected edition. There is no
File #1/#2 label in Graphics because the preview is shared.

The loader first reads the edition's existing indexed
`asset-exports/<game>/<export>/single/original-assets.pak`. It reads only the
index, Kevin model, motion banks and handgun object bank without unpacking the complete archive. A supported game
import supplies the same members if no usable export exists. Kevin is
`NETBIO00.DAT/0/491` in File #1 and `NETBIO00.DAT/0/508` in File #2. Both supported
editions contain the same 400,768-byte `P00_00.nbd` payload, SHA-256
`964daa4c3ce1cf724e62b0e9cda79a88a4761c4899d159d0090ae5ba539b4baf`.
No game model, texture, skeleton, animation bank or generated mesh ships with the launcher.

The decoder reads four AMO parts, their material batches, 3,910 triangles, two
256×256 TIM2 textures, AHI joint transforms and skin weights. `GamePreviewAnimation`
reads Kevin's original `PL00_pc_000.bin`: member 1047 in File #1 or 873 in File #2.
It checks the edition's bank SHA-256, decodes paired upper/lower body channels and
evaluates their original Hermite keyframes. The preview samples the 120-frame
idle at 30 frames per second; the bank itself stores frame units, not a frame rate.
Packed translations and scales use four fractional bits, and packed
angles use π/8192 radians. The animated hierarchy compensates the parent's local
scale, as in the original `0x193260` routine, instead of compounding it through
the spine and head. Packed keys store value, frame, incoming tangent, outgoing
tangent; their interpolation follows `0x18E710` and `0x18F260`. Model-only packs
without the original motion bank leave the preview unavailable; no procedural
idle is substituted. The tiled utility room is launcher-authored.
See [artwork provenance](../launcher/Assets/PROVENANCE.md).

The standard handgun uses root 0 in `NETBIO00.DAT/1/1093` (File #1) or
`NETBIO00.DAT/1/1391` (File #2). Its 467 vertices and two material batches are
rigidly transformed by hand joint 32 after the character's skeleton is evaluated.
`GamePreviewWeapon` converts the original grip into that hand's coordinates;
the gun moves and rotates with the hand.

The preview uses the complete original relaxed idle100: its matching lower and
upper body entries play their authored 120-frame loop, with the arms lowered.
The extracted handgun remains rigidly attached to its hand. No two-handed ready
pose, substitute torso/head curves, fixed head angle or generated motion is added.
The decoder also supports the original 100/400 handgun-ready composition for
owned-data verification, but the shared Graphics preview uses the relaxed pose.
This separate preview does not run the game's complete controller or look-target
system.

`GraphicsPreviewHost` hosts a native child window. `GpuScenePreview` submits the
original textured meshes to `native/graphics_preview.cpp`, an isolated Direct3D 11
hardware renderer. Texture sampling, depth, lighting, filtering, anti-aliasing,
picture framing, brightness and gamma run on the GPU. Skeleton evaluation and
animated vertex updates still run on the CPU. Production frames present directly
through a flip-model swap chain, without copying image pixels back to WPF.
`GameScenePreviewRenderer` supplies the authored environment and remains available
for offline reference rendering; it does not rasterize the live preview.

Internal resolution changes the actual render target's sampling density, using
448 vertical samples at native resolution and 896/1792 at 2×/4×. Only the visible
frustum is rendered. FXAA follows the directional edge filter; the SMAA preview
uses GPU analytic morphological coverage
instead of the game's GPU lookup tables. It illustrates the setting but is not
a pixel-exact reproduction of gameplay. Window size and fullscreen determine a
virtual output; aspect, widened camera, stretch, fit, fill and centered modes
change its framing. The panel crops the active picture to fill its visible area,
removing artificial black bars. Consequently some differences between whole-window
letterboxing modes are hidden by the preview crop.

Dragging Kevin rotates the character and attached handgun directly. Releasing
the mouse preserves that angle with no momentum or automatic return. Rotation
uses only the vertical axis; vertical mouse movement cannot tilt the body or lift
the feet. The mouse wheel zooms from 0.65× to 2.5×; Home resets both orientation
and zoom. Animation continues while rotated or zoomed. The native child window
uses SS_NOTIFY so Windows delivers mouse input to the rendered surface.
Its native paint handler fills the launcher background before the first GPU
presentation, preventing the STATIC control's default white loading flash.

Rendering runs serially on a background worker. A nonblocking DXGI frame-latency
waitable object gates animation and mesh updates, avoiding work when presentation
is pending. WPF composition pulses and a dispatcher timer drive readiness checks;
there is no former 30 FPS cap. Presentation follows display/compositor availability.
A version check rejects stale managed frame metadata after settings or edition
changes. The preview stops on page exit, minimization, game launch and launcher
shutdown. Missing assets or GPU initialization failure leave settings usable and
show an unavailable message. Hardware rendering is required; there is no silent
software-renderer fallback.

The preview header shows successful presentations per second as a simple FPS
readout. It measures only this launcher scene and does not predict full-game
performance. The separate FPS counter setting controls the in-game overlay.
Diagnostics also measure GPU render time through asynchronous Direct3D timestamp
queries; CPU work and display waiting are excluded from that GPU duration.
Timings depend on hardware, display, quality and other running applications.

Normal builds use `native/GraphicsPreview.targets` and
`native/build_graphics_preview.ps1` to compile `Reo.GraphicsPreview.dll` with the
installed Visual Studio C++ tools and Windows SDK. Directory publishes copy the
DLL; single-file publishes embed it for extraction. The native library contains
renderer code and shaders, with no owned game assets.

## Verification

`--self-test` includes bounded missing/invalid/unsafe asset-pack checks.
`--test-graphics-ui <output>` requires an isolated `--data-home` with owned asset
packs for both editions. It checks image pixel changes for each picture option,
animation over time, persisted settings, reset, independent scrolling at minimum
size, edition changes, native hit testing, mouse capture/release, direct rotation,
wheel zoom, disabled launcher tooltips and rendering
suspension. It verifies hardware GPU selection and measures production performance
with diagnostic readback disabled. Screenshots explicitly read pixels back from
the GPU because WPF's capture omits native child windows; that diagnostic path
adds overhead and is not used for the production FPS measurement. The test writes
screenshots and a JSON receipt, then restores the settings file. No OS input is
injected or game session
started. Owned asset checks separately verify textures, mesh references, finite
animation output, grounded feet and absence of accumulated pose drift.

Fresh-install resource verification on 2026-10-31 passed 26 owned-data checks
using separate empty caches for File #1 and File #2, with no exported PAKs.
Each edition alone supplied Kevin's model, original textures and complete idle
animation directly from its imported `NETBIO00.DAT`. The full loop stayed finite,
grounded and repeatable. The same check generated and loaded the game font in WPF
and extracted and reused the edition's verified controller image. These resources
need no manual export or additional download after importing either supported
game. A Release publish also included `Reo.GraphicsPreview.dll` with the exact
hash of the built renderer. Cover/DVD artwork and background-video tooling have
their own optional downloads; see [background preparation](LAUNCHER_BACKGROUND_VIDEOS.md).
