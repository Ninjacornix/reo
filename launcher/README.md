# Launcher

The v1.0.0 through v1.0.3 downloads are withdrawn. v1.0.4 uses a smaller
framework-dependent launcher and separately installed requirements. See
[requirements](../REQUIREMENTS.md). Revised setup/gameplay have not been rerun.
The extracted single-file launcher is checked separately for window startup;
its icon is an embedded WPF resource, with a separate copy for the game window.

The replacement package contains independent tools and runtime inputs. Select your
own NTSC-U v2.00 / SLUS-20765 ISO under **Game files**. The launcher imports game
files without mounting, generates native sources locally, then compiles and caches
the game. Other executable revisions are rejected before import. A Vulkan-capable
GPU driver is required. File #2 remains a placeholder.

The application is portable; system dependencies are installed separately.
Install .NET 8 Desktop Runtime and the pinned LLVM/MinGW compiler, then select an
ISO. Required generation inputs are bundled compressed and unpack into the user
cache. The full compiler and .NET runtime are not inside the launcher folder.
The local server and its Python runtime are bundled under `network-server/`.
Legacy development kits require existing Microsoft C++ tools and a Windows SDK.
The launcher does not install system tools. The first compilation takes time;
later launches reuse verified completed outputs.
The final game executable, extracted assets and generated instruction code stay
in Local AppData. Keep the ISO available for direct sector reads.

Developers can build the launcher with .NET 8 SDK and Visual Studio C++ tools:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File launcher/build.ps1
```

Open `StartLauncher.cmd` in a source checkout. **Developer options** in Game files
allows selecting an existing local native build; it is hidden in packaged installs.
The ordinary package script rejects precompiled-game distribution. Maintainer
build-kit instructions are in [local builds](../docs/LOCAL_BUILDS.md).

## Pages

- **Play:** select File #1 or File #2 and inspect local game files, saves, GPU and input device. Choose your ISO; the verified local game build is selected automatically. File #2 gameplay is not included in the current package.
- **Graphics:** window resolution, borderless fullscreen, image scaling, 3D texture filtering, anisotropic filtering (Off/2Ã—/4Ã—/8Ã—/16Ã—), FXAA or SMAA, brightness, gamma, async geometry and experimental GPU movie decoding. Changes apply next launch.
- **Controls:** choose keyboard, DualSense or Xbox/XInput; remap buttons and keys; adjust dead zones and stick options. USB DualSense is physically tested; Xbox and Bluetooth have parser/simulated coverage. Rumble and adaptive triggers are unsupported.
- **Save games:** open the selected game's memory-card folder or create a ZIP backup while the game is closed. Save/load itself remains in the game.
- **Log:** read session debug/output logs, with optional follow mode.
- **Co-op:** username, server address, automatic account/login plumbing, server hosting and a copyable address for friends. The new game-to-lobby flow is still being validated.
- **Cheats:** built-in gameplay toggles and optional compatible PCSX2 data cheats.
- **Mods:** placeholder.

Check for updates uses [GitHub Releases](https://github.com/Ninjacornix/reo/releases). Packaged installations can download, verify and install newer releases; source checkouts open the release page. See [Updates](#updates).

## Co-op

Use the ordinary **Play** button for both offline and network play. In **Co-op**,
enter a server IPv4 address and a username (4-10 letters, numbers or single inner
underscores). Press Enter or leave the username field to create or reuse the
account on the selected server. The status below confirms readiness. Login uses
that saved account when the native game enters Network. There is no separate
online launch mode, and incomplete network settings do not prevent offline play.

The launcher generates a server-specific password, saves it with Windows DPAPI
for the current Windows user before registration, and uses the server's existing
signup/login endpoint. It does not claim existing names or override server
admission. An already-owned username requires choosing another name. Passwords
are not settings, process arguments, environment variables or game-log entries.
The original password editor receives a bounded, generation-checked native
credential handoff, removed after acknowledgement. Pending private session files
are removed when the game closes.
Keep launcher account data if you want to reuse the same account in future.

Enable **Host server** to start the four required services without a terminal or
Python installation. Choose the LAN/VPN/public address to advertise before
starting. Once the services are listening, **Friends connect to** shows a copyable
address. Changing that field requires stopping the server first. Stopping hosting
or closing the launcher stops only its owned server processes; existing services
on occupied ports are refused and preserved. Persistent server data is separate
from the portable application under Local AppData.

The portable server component includes pinned openSNAP source, the current-room
patch, its AGPL licence, Python and dependencies. The native game/runtime remains
a separate process.

Helping friends reach you (all optional; nothing happens without a click):

- **Pick one of your addresses** lists this PC's addresses, labelled *home network*
  (friends in the same house), *VPN* (Tailscale, ZeroTier, Hamachi — works over the
  internet without port forwarding) or *internet*. Virtual-machine/WSL adapters are
  hidden because friends cannot reach them.
- **Find my internet address** asks `api.ipify.org` for the address the internet sees.
- **Ports friends need** lists the four fixed ports: TCP 80 (account sign-up),
  TCP 10127 (game app server), UDP 9090 (login), UDP 9091 (game server). For internet
  play without a VPN, forward them to this PC in your router.
- **Open these ports on my router automatically (UPnP)** asks the router to forward
  them while the server runs and removes the forwarding when hosting stops or the
  launcher closes. Many routers have UPnP off; the launcher then says so. If the
  router itself reports a private internet address, your provider uses carrier-grade
  NAT and forwarding cannot work: use a VPN address instead.
- **Allow through Windows Firewall** adds two inbound rules for exactly these ports
  ("RE Outbreak Recomp server (TCP)/(UDP)") after Windows' administrator prompt.

Some providers block incoming port 80, which account sign-up needs.

These new controls require the updated native account hooks. Portable server
startup, real signup/login checks and the native credential handshake have passed
isolated integration checks. An automated native game run also authenticated and
reached server selection without manual credential entry. Previous four-client
gameplay checks used the manual account flow; the new flow has not repeated them. Room creation/joining and scenario choices still use the original game menus.

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
