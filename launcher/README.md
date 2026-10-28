# Launcher

The v1.0.20-rc0 Windows download includes the .NET runtime. Extract the complete
folder and open **Outbreak.Launcher.exe**; players do not need to install .NET,
Visual Studio or a compiler separately. See [requirements](../REQUIREMENTS.md).

Choose your own supported NTSC-U disc: File #1 v2.00 / SLUS-20765 or File #2
v1.05 / SLUS-20984. The launcher verifies the disc, imports its files without
mounting, generates native sources locally, then compiles and caches the game.
Other executable revisions are rejected. A Vulkan-capable GPU driver is required.
File #2 and its Randomizer are experimental; see
[the verified paths and remaining limits](../docs/FILE2_RANDOMIZER.md).

On first build the launcher downloads and prepares the pinned LLVM/MinGW x64
compiler automatically. Keep **build-inputs.zip** and **build-inputs-file2.zip**
beside the launcher. No terminal commands or environment variables are required.
The compiler is shared between games; later launches reuse verified completed
builds. Nothing is installed system-wide or added to PATH.

Portable data stays in **data/** beside the launcher unless a different storage
folder is selected. Imported files, generated code, completed games, saves and
build caches remain private. Keep the ISO available for direct sector reads.
The **network-server/** folder contains server source; on first hosting the
launcher prepares Python and its packages in the selected data folder. Joining
an existing host does not need those hosting tools. Dependency-source archives
are separate developer downloads.

Developers can build the launcher with .NET 8 SDK and Visual Studio C++ tools:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File launcher/build.ps1
```

Open `StartLauncher.cmd` in a source checkout. **Developer options** in Game files
allows selecting an existing local native build; it is hidden in packaged installs.
The ordinary package script rejects precompiled-game distribution. Maintainer
build-kit instructions are in [local builds](../docs/LOCAL_BUILDS.md).

## Pages

- **Play:** select File #1 or File #2. The next-step box guides disc selection, setup and Play. The readiness checklist shows the launcher runtime (bundled in RC0), Vulkan driver, free disk space and supported disc. Required first-build tools are prepared automatically.
- **Game files:** choosing an ISO runs a quick read-only check; a green ✓ enables Import, a red ✗ explains the problem. **Use existing build** imports a completed compatible build. **Remove game** deletes the imported disc data, the built game and its compile cache (optionally also saves and the shared build/hosting tools) after a confirmation; the ISO stays. Import/build progress stays visible at the bottom of every page.
- **Graphics:** window resolution, borderless fullscreen, image scaling, 3D texture filtering, anisotropic filtering (Off/2×/4×/8×/16×), FXAA or SMAA, brightness, gamma and async geometry. Changes apply next launch.
- **Movies:** before each launch `reo-movie-check.exe` (beside the launcher) asks whether the GPU the game renders with has a hardware MPEG-2 decoder. CPU decoding is the default. If the decoder check passes, **Graphics > Movies > Decode movies on the graphics card** becomes available; enable it to use the verified GPU decoder. Without a decoder (the AMD Radeon RX 9060 XT, for example) the box is greyed out and the game's original CPU decoder plays movies. The choice is shown in the status line and saved as `movieDecoder` in the session's `launch.json`.
- **Controls:** choose keyboard, DualSense or Xbox/XInput; remap buttons and keys; adjust dead zones and stick options. USB DualSense is physically tested; Xbox and Bluetooth have parser/simulated coverage. Rumble and adaptive triggers are unsupported.
- **Save games:** open the selected game's memory-card folder or create a ZIP backup while the game is closed. Save/load itself remains in the game.
- **Log:** read session debug/output logs, with optional follow mode.
- **Co-op:** Play alone, Host a game or Join a game; player name; hosting address, ports and firewall; games found on the local network; optional automatic waiting room. See [Co-op](#co-op).
- **Cheats:** built-in gameplay toggles and optional compatible PCSX2 data cheats.
- **Mods:** import and enable packages separately for each game. The bundled File #1 and File #2 Randomizer examples use a fresh seed per solo/host launch; joiners use the host settings.

Check for updates uses [GitHub Releases](https://github.com/Ninjacornix/reo/releases). Packaged installations can download, verify and install newer releases; source checkouts open the release page. See [Updates](#updates).

## Co-op

Use the ordinary **Play** button for both single-player and network play. In
**Co-op**, choose **Play alone**, **Host a game** or **Join a game**, and enter a
player name (4-10 letters, numbers or single inner underscores). There is no
Create account step: when you press Play, the launcher creates or reuses the
account on the chosen server and reports problems (name taken, host unreachable)
before the game starts. Login is automatic when the game enters Network.

The launcher generates a server-specific password, saves it with Windows DPAPI
for the current Windows user before registration, and uses the server's existing
signup/login endpoint. It does not claim existing names or override server
admission. An already-owned username requires choosing another name. Passwords
are not settings, process arguments, environment variables or game-log entries.
The original password editor receives a bounded, generation-checked native
credential handoff, removed after acknowledgement. Pending private session files
are removed when the game closes.
Keep launcher account data if you want to reuse the same account in future.

### Hosting

**Host a game** starts the four server services without a terminal. The first
time, a private Python 3.12 environment is prepared in Local AppData: an installed
Python 3.12 is used when present, otherwise uv downloads one; the pinned server
packages are then installed. Later starts reuse the cached environment.

Choose the address friends use (home network, VPN or internet; **Find my internet
address** adds the public one) and click **Copy address**. Changing the address
restarts the server. Stopping hosting or closing the launcher stops only its own
server processes. Persistent server data is separate from the portable application
under Local AppData. **Allow friends through Windows Firewall** adds two inbound
rules for exactly the hosting ports after Windows' administrator prompt.

**Ports** lets the host change the player sign-up port (TCP, default 10128) and
the game server port (UDP, default 9091). Login (UDP 9090) and the game app server
(TCP 10127) are built into the game and fixed. If a port is busy, the error names
the program and process using it. **Playing over the internet** explains VPN use,
optional UPnP router forwarding and the full port list. If the router itself
reports a private internet address, the provider uses carrier-grade NAT and
forwarding cannot work: use a VPN address instead.

### Joining

**Join a game** lists games announced by hosting launchers on the local network
(UDP 10129 broadcast; no central service) or accepts a typed IPv4 address. The
host's launcher also tells joining launchers its sign-up port; if it cannot be
asked, the launcher tries 10128 and then 80 for servers hosted by older launchers.

### Automatic waiting room

**Take me to the waiting room automatically** is on by default. After Play, the
native `network-auto` route presses Start at the title, selects Network and hands
over to automatic login. The launcher then reads the original lobby state from the
game's memory (read-only) and answers known menu gates with ordinary pad presses:
the host selects the free-mode server, creates a four-player room titled with the
host's player name; guests wait until the host's room exists and join it. Any
button press by the player ends the automation; unknown states only wait. The host
still chooses START SCENARIO. A two-client local test reached the shared waiting
room this way; the complete title-to-room path from the Play button has not been
validated yet.

## Display and startup

Developer checkouts need a current native build for these settings. Packaged installs generate it locally from the supported disc.

Window resolutions range from 1024 x 768 to 3840 x 2160. Borderless fullscreen uses the monitor's desktop resolution. The original 4:3 picture is preserved with black borders when needed; these output sizes do not increase internal rendering resolution or texture detail.

Image scaling chooses nearest or bilinear sampling of the final image. The separate 3D texture-filter option enables bilinear sampling for triangles while preserving the game's sprite and framebuffer-feedback sampling. Anti-aliasing offers Off, FXAA and SMAA 1x High. SMAA uses the upstream edge-detection, blend-weight and neighbourhood passes with matching lookup textures, after scaling; it has no temporal history. Brightness and gamma are applied once after AA. All options run on the GPU and apply on the next launch.

Anisotropic filtering improves perspective 3D textures viewed at oblique angles. Choose Off, 2Ã—, 4Ã—, 8Ã— or 16Ã—; 8Ã— is a useful starting point. It includes bilinear texture filtering for eligible draws, independently of the Original/Bilinear option. Sprites, fixed-UV triangles, GS region/cropped textures, render-target arrays and framebuffer-feedback sampling retain their original paths. Filtering uses Vulkan hardware samplers with explicit GPU texture gradients; levels are capped to the device limit, with bilinear fallback on unsupported hardware. Higher settings cost more GPU time. Existing settings default to Off.

Brightness (50-150%) and gamma (0.50-2.00) use the same adjustment curve in the immediate GPU preview and the game's GPU presentation pass. Reset restores 100% / 1.00. Settings apply to the game on its next launch; neutral values preserve the original image. The room preview is a local screenshot at `%LOCALAPPDATA%\OutbreakRecomp\launcher\room-preview.png`, not a bundled game asset. It is outside the repository and release resources.

## Files and input

Settings, private executable copies and session logs are under `%LOCALAPPDATA%\OutbreakRecomp\launcher`. Default memory cards stay in `build-ninja/play/saves` and `build-ninja/play-file2/saves`. In **Save games**, select a card for the selected game, create a named card, or select an existing folder-backed card. New cards live under `%LOCALAPPDATA%\OutbreakRecomp\launcher\memory-cards`; selections are stored independently for each game. Existing saves are preserved. Cards hold PS2 save files, not save states or raw PCSX2 `.ps2` images. Save and load from the original game menus. Card selection and backups are disabled during play, and the launcher locks the selected card against concurrent launcher sessions.

Press **Ctrl+Enter** in the game to toggle borderless fullscreen. **Alt+F4** closes the game; Esc does not close it. The fullscreen shortcut does not send the game's Start button.

Keep the launcher open while playing. It minimizes if closed during a game, preserving the input connection. Only the selected input source controls player 1. Keyboard input is accepted while the launcher or its game is in the foreground. Device changes and bindings apply live; graphics settings apply next launch.

The launcher copies and verifies the selected executable and dependencies in an immutable cache, installs its input adapter beside that copy, and leaves the source build untouched. The game opens without a console; stdout/stderr go to session logs. Original project icons identify the launcher and game window.

The selected ISO is imported once without mounting. The original ISO stays available for direct sector reads; the supported ELF identity is checked before import. Required presentation shaders are copied from the selected native build. GPU-resident VU ownership is disabled in this launcher configuration because it conflicts with the async worker.

## Artwork and validation

Game cards and faded backgrounds are plain by default. Users can optionally
provide their own local cover images; the launcher no longer downloads them.
These local files are neither embedded in the launcher nor distributed with the
source. See [asset provenance](Assets/PROVENANCE.md).
