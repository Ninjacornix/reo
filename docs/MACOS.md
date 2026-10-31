# macOS port (RC1)

This branch starts at `v1.0.20-rc1` and targets Apple Silicon. The graphics path
is native ARM64 code → paraLLEl-GS Vulkan compute → MoltenVK → Metal, with a
CAMetalLayer swapchain. It does not use Wine or Rosetta. Raylib still supplies
the host window and audio; gameplay scanout uses the Metal surface directly.

This is a local Apple Silicon build, not a notarized public release. The current
launcher uses the common Avalonia/C# frontend for macOS, Windows and Linux, with
RC1 Windows in this checkout as its design reference. It bundles .NET and native
service tools; no external .NET or Python installation is needed to run the app.
Open `build-macos/common-launcher/RE Outbreak RC1.app` or `StartOutbreakMac.command`.
See [the common launcher implementation and checks](SHARED-LAUNCHER.md).

Build the common app after preparing the native game and server dependencies:

```sh
python3 tools/launcher/package.py
```

The common frontend has passed 571 core checks, 54 headless UI/media checks across
12 pages, four-service registration checks and a source-tree native gameplay run.
Windows/Linux self-contained frontend publishing succeeds on this Mac; native
execution on those OSes remains unverified. Exact pixel parity with WPF is pending
Windows comparison. A subsequent packaged gameplay run was blocked by the Mac's
sleeping display; the launcher and game now detect that state and request waking
the display, instead of entering the window library's crashing path.

File #2, full scenario completion, original in-game save/load, physical controller
behavior and co-op gameplay need separate validation. These checks do not establish
performance parity with a renderer written directly in Metal.

## Earlier Qt launcher

The following describes the earlier Qt implementation retained for reference.
Its app remains at `build-macos/launcher/RE Outbreak RC1.app`. The common launcher
is the current entry point; its supported paths and remaining work are documented
in [SHARED-LAUNCHER.md](SHARED-LAUNCHER.md).


The earlier launcher includes:

- ISO selection, mount-free verified import, source rebuilding and existing-build selection.
- Window size/fullscreen, aspect/camera, internal resolution, filtering, FXAA/SMAA,
  brightness, gamma and FPS/game-update overlay.
- Five live audio buses and live subtitles.
- Keyboard and controller remapping, device selection, deadzone and supported-controller
  CoreHaptics vibration. Physical controller input and rumble remain unverified.
- Persistent, individually locked memory cards; ZIP backup and transactional restore to
  a new card, preserving existing saves.
- Offline built-in and direct-data PNACH cheats; File #1 JSON mods and global item/enemy
  randomizers using the shared Windows asset catalogue code.
- Four managed openSNAP services, SQLite storage, LAN discovery, native network account
  input using macOS Keychain, and protocol-3 shared randomizer configurations.
- Per-session logs, game-clock/frame timing journals and diagnostic archive export.

Create and join rooms through the original game Network menus. Windows automatic lobby
navigation, original-asset 3D launcher previews, a Mac update feed and an automatic Mac
compiler installer are not implemented. Server and protocol tests are not evidence of a
completed multiplayer scenario. Online credentials stay out of settings and command lines;
Keychain access and actual online login have not been exercised with a real user account.

Settings live in `~/Library/Application Support/OutbreakRecomp/launcher/settings.json`.
Saves remain outside the replaceable application in `memory-cards/`; logs go in `sessions/`.
Normal Play clears inherited developer/test switches. Audio/subtitles apply live; other
settings are frozen at Play and apply to that session. The packaged app still needs your
supported ISO. It contains no original disc assets; its locally generated executable is
for your own local use and must not be treated as an independent public game distribution.

## Build and launch

Developer requirements: Apple Silicon macOS, Xcode Command Line Tools, Python
3.11+, CMake, Ninja, and a macOS Vulkan SDK providing MoltenVK,
`glslangValidator` and `spirv-val`. The local M2 graphics checks used MoltenVK
1.2.11 and Vulkan SDK 1.4.304. A standalone `metal` compiler is unnecessary:
MoltenVK compiles the Metal shaders at runtime.

From the repository root:

```sh
python3 tools/macos/build.py --iso "iso/Resident Evil - Outbreak (v2.00).iso" --jobs 6
./StartOutbreakMac.command
```

The game builder also creates `build-macos/RE Outbreak RC1 Game.app`, a direct-game
development app containing the native executable, shaders and MoltenVK. It still references
your local imported data and ISO. It is not a portable public release package.

The builder checks out pinned independent dependencies, applies the published
runtime and renderer patches, verifies the File #1 executable hash, generates
game/overlay/VU sources locally, and builds `build-macos/game/recomp/reo_recomp`.
It runs the GPU drawing controls and a Metal swapchain/resize check. Existing
dependency edits and incomplete generation directories are preserved rather
than reset. A first build downloads and compiles dependencies and game code;
later builds reuse completed objects.

`build-macos/macos-build.json` records the local ISO, extracted data and
executable paths after a successful build. Keep the ISO available. Neither the
disc nor generated game code belongs in a distributed source/package archive.
The generated include-directory symlinks under `recomp/config/` are local and
ignored. Preserve the whole build directory; an executable alone is insufficient.

The direct development script looks for MoltenVK in `VULKAN_SDK/lib`, `/opt/homebrew/lib`, then
`/usr/local/lib`. An explicit `GRANITE_VULKAN_LIBRARY` path takes precedence.
Saves use `~/Library/Application Support/OutbreakRecomp/memory-cards/default/data`.

Keyboard defaults are WASD for the D-pad, Space for Cross, E for Circle, Q for
Square, R for Triangle, Return for Start, Delete for Select, 1–4 for L1/R1/L2/R2,
Z/X for L3/R3, and arrow keys for the right stick. Native GameController input
maps standard gamepads to the same PS2 buttons. Input snapshots are captured
on the AppKit thread and copied to the pad worker; background focus clears them.
The Mac launcher supplies remapping/device/deadzone settings to this native adapter.
Vibration uses GameController/CoreHaptics where supported by the connected hardware.

Runtime graphics settings can be passed through the existing `REO_*` environment
variables. The initial Mac defaults use native internal resolution, no post AA,
the CPU movie decoder and the normal RC1 scheduling mode. For example:

```sh
REO_INTERNAL_RESOLUTION=2 REO_POST_AA=fxaa python3 tools/macos/play.py
```

To show measured display FPS, present interval and original game updates/sec:

```sh
REO_PERFORMANCE_OVERLAY=1 REO_PERFORMANCE_DIAG=1 python3 tools/macos/play.py
```

Closing the window or sending SIGINT/SIGTERM requests the runtime's joined
shutdown, exporting enabled diagnostics and saving the pipeline cache. An optional
`REO_MACOS_RUN_SECONDS` stops a diagnostic run after that many seconds of guest
execution (shader preparation occurs first).


## Building the desktop application

After the native game build, prepare the pinned server and the packaging environment:

```sh
uv venv --python /opt/homebrew/bin/python3.12 build-macos/launcher-env
uv pip install --python build-macos/launcher-env/bin/python -r launcher/macos/requirements.txt
git clone https://github.com/GrenderG/openSNAP.git build-macos/opensnap-source
git -C build-macos/opensnap-source checkout f9af55491718a043923225a0895fe60eab76fd7c
git -C build-macos/opensnap-source apply "$PWD/network/server/patches/0001-outbreak-current-room-query.patch"
python3 tools/macos/build_launcher.py
```

Existing server source is preserved by the packager. The asset helper builds with
.NET SDK 10 as a self-contained ARM64 executable; only building requires that SDK. PyInstaller
bundles the launcher, Qt, Python, server dependencies, game, shaders, driver and licenses,
then ad-hoc signs and verifies the application. Its build record refers back to the source
checkout for optional recompilation. Current binaries were tested on an M2 running macOS
27.0.1; older macOS versions and Intel Macs are not validated.

The game-only app is separate from the desktop launcher so rebuilding the game does not
overwrite the launcher. Repackage after a game rebuild to update its bundled executable.
The GUI is about 300 MiB; the local disc import and source/build trees are separate.

```sh
build-macos/launcher-env/bin/python -m unittest discover -s launcher/macos -p 'test_*.py' -v
QT_QPA_PLATFORM=offscreen 'build-macos/launcher/RE Outbreak RC1.app/Contents/MacOS/RE Outbreak RC1' \
  --verify-bundle "$PWD/build-macos/launcher-bundle-check.json" --server --game
```

The explicit developer bundle check uses isolated settings/cards and the original menu
route to gameplay, then joined shutdown. Twelve launcher tests cover settings, backup/restore,
locks, unsafe archives, live control-file format, cheats, cancellation, host discovery and
shared randomizer validation, plus registration/private credential input with an isolated
fixture provider (without touching Keychain). The native transport suite with the hosted server passes
130 checks, including real TCP/UDP and the Capcom app protocol. The memory-card RPC backend
passes 33 native checks on Mac, and `tools/macos/host_controls_check.cpp` verifies live mixer
and subtitle updates across the actual native polling bridge. These checks do not replace
a real in-game save/load or physical-controller test.

## Graphics verification

The standalone checker asserts triangle rasterization (both windings), sprite
drawing, packed GIF geometry and exact host-to-VRAM transfer bytes. The Metal
presenter check submits eight real swapchain frames, resizes once and waits on
GPU fences. It does not compare on-screen pixels or run a game scenario.

```sh
GRANITE_VULKAN_LIBRARY=/opt/homebrew/lib/libMoltenVK.dylib \
  REO_PARALLEL_GS_DESCRIPTOR_BUFFER=0 \
  build-macos/graphics/parallel_gs_check build-macos/fresh-controls
GRANITE_VULKAN_LIBRARY=/opt/homebrew/lib/libMoltenVK.dylib \
  build-macos/graphics/macos_present_check build-macos/game/recomp/reo-gpu-present
```

Use a fresh output directory for each graphics-control run. For an optional
input-only automated game route, use `python3 tools/macos/play.py --route gameplay`.
This drives the original guest menus; reaching a room still needs visual,
audio and timing checks. The native POSIX transport also has an isolated
loopback test; it does not prove co-op gameplay:

```sh
clang++ -std=c++20 -O2 -pthread tools/snap_iop_check/main.cpp \
  network/native/snap_iop_transport.cpp -o build-macos/snap_iop_check
build-macos/snap_iop_check --loopback-only
```

## Local M2 performance evidence

A clean cached run through the original menus into the first Outbreak room,
followed by 65 seconds of automated movement, measured 60.01 displayed FPS and
29.83 original game updates/sec (target 30; one-second readings 28.7–30.6).
Process CPU averaged 156% where one core is 100%, and resident memory averaged
491 MiB. The whole-device GPU counter averaged 63.6% and peaked at 73%; that
counter includes other applications and is not per-process GPU utilization.
No synchronous shader compilation stalls were logged during that movement window.
The independent original guest-clock journal measured 29.965 updates/sec over
70.05 seconds of active room gameplay: 99.88% of the intended game speed, with
no dropped, invalid or unpublished clock records.

An earlier run overlapped a developer build and measured lower update rates
(including 24.9 UPS). Its active guest-clock segment averaged 28.89 UPS. Keep
those results separate from the clean run. First-use logs also contained shader
compilation hitches, including a 57 ms compile; a fresh driver's pre-game shader
preparation took about 20 seconds, versus about 0.14 seconds in the cached run.
These are bounded room tests, not proof of all-scenario performance or parity
with an independently implemented Metal renderer.

The log's calibrated-timestamp message means Granite could not select a supported
host time domain; GPU calibrated timings are unavailable. The initial thread-index
message comes from querying Granite before the adapter registers its serialized
thread index. Neither message was accompanied by device loss in these runs.
Frame-trace submission timings are host measurements, not calibrated GPU times.

For repeatable device/process sampling, run this against an owned game PID:

```sh
python3 tools/macos/profile.py --pid PID --log build-macos/game.log \
  --out build-macos/new-performance-sample --seconds 30
```

The profiler writes raw JSONL samples, the corresponding game-log window and
`report.json`. Use `--wait-for-gameplay` with an automated gameplay route to
exclude startup. Menu/pause/death periods can legitimately report zero UPS;
the original guest-clock journal distinguishes those from active gameplay.
