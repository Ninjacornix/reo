# Vertical sync (issue #85)

Based on stable `v1.0.20`, commit `9851873a2e3e7a8cdf1ef7eeecffceabaf9e4947`.
The display-control request is part of
[issue #85](https://github.com/Ninjacornix/reo/issues/85). Its forklift/collision
report is a separate gameplay problem and is not resolved by this change.

Graphics now offers **Vertical sync: On / Off / Adaptive**, saved for both games
and applied on the next launch. Existing and invalid preferences default to On.
The launcher captures `REO_VSYNC=on|off|adaptive` before asynchronous setup.
Direct native launches use the same environment variable.

The Windows resident GPU presenter previously always requested DXGI interval 0.
It now requests interval 1 for On and interval 0 for Off. Adaptive chooses between
them using presentation cadence and the current monitor's refresh rate; it
rechecks monitor settings once per second and after a monitor change. A small
hysteresis tolerates scheduling jitter and 59.94 Hz NTSC presentation on a 60 Hz
display. Unknown refresh falls back to On. Granite retains ownership of tearing
capability checks and the `DXGI_PRESENT_ALLOW_TEARING` flag.

The OpenGL route sets GLFW swap interval 1, 0 or -1. Negative intervals require
`WGL_EXT_swap_control_tear` or `GLX_EXT_swap_control_tear`; otherwise Adaptive
falls back to On. Linux/macOS Vulkan presentation uses FIFO for On, immediate
(then mailbox, then FIFO fallback) for Off, and relaxed FIFO for Adaptive when
supported, with FIFO fallback. `[DISPLAY-SYNC]` logs record the requested mode
and selected interval/present mode.

These settings affect host presentation only. Guest VBlank, gameplay updates,
audio timing and raylib's disabled FPS limiter retain their existing behavior.
This does not add an unlocked simulation rate or establish a cause for the
collision report. Driver/compositor policies can still constrain presentation.

Both game build kits need regeneration from the changed source before packaging.
Replacing only the launcher cannot change an existing game executable's display
behavior. The exporter includes the new headers even in development exports.
No existing GitHub release assets or tags have been replaced.

## Verification on Windows, 2026-11-05

- `dotnet run --project launcher/cross-tests/Reo.Launcher.CrossTests.csproj -c Release`:
  1,621 checks passed, including saved preferences, invalid/null values and the
  captured launch environment for both games. Used the installed user .NET 10 SDK.
- `dotnet build launcher/desktop/Reo.Launcher.Desktop.csproj -c Release`:
  passed with existing warnings.
- `launcher/build.ps1 -OutputDirectory build-vsync/launcher`: passed, including
  native controller/movie helpers and the self-contained Windows launcher.
- Launcher `--headless-check build-vsync/ui`: 261 checks passed across 12 pages,
  including all three choices, persistence and rendered layout. Inspected
  `build-vsync/ui/Graphics.png`.
- `python tools/launcher/check_reference.py`: passed with the updated UI contract.
- `tools/display_sync_check/run.bat`: 213 synthetic display-policy checks passed
  with MSVC; the same fixture also passed with clang++. Requires Vulkan headers,
  but no Vulkan loader, GPU or game data. It is included in Windows CI and is
  available as the CMake target `reo_display_sync_check` when Vulkan is found.
- Compiled the changed native GPU backend and both File #1/File #2 bootstrap
  variants with MSVC using the existing local dependency headers/build flags.
- Local synthetic hardware smoke harnesses under ignored `build-vsync/`, on a
  Radeon RX 570 with a 60 Hz display: each mode completed 24 real DXGI presents,
  resize, GPU fence waits and exact center-pixel readback. On selected interval 1;
  Off selected 0; Adaptive exercised both. OpenGL's `wglGetSwapIntervalEXT` returned
  1, 0 and -1 for On, Off and Adaptive respectively. No game data was used.
- `git diff --check` and `python tools/check_repository.py`: passed.
- Local build-kit slim export and sealing regression suites: 7 tests passed.

Full scenario playthroughs, visible tearing assessment, Nvidia hardware,
multi-monitor transitions and native Linux/macOS presentation remain untested.
The local hardware checks validate API selection and GPU completion, not those
broader claims. A rebuilt game should next be checked in a moving scene with
each mode, including borderless fullscreen and a slower rendering workload.

API references: [GLFW swap intervals](https://www.glfw.org/docs/latest/window_guide.html#buffer_swap),
[DXGI Present](https://learn.microsoft.com/en-us/windows/win32/api/dxgi/nf-dxgi-idxgiswapchain-present),
[DXGI tearing flags](https://learn.microsoft.com/en-us/windows/win32/direct3ddxgi/dxgi-present).
