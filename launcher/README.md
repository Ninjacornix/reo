> The precompiled v1.0.0 download has been withdrawn. The local-build installer
> is in development; packaging a compiled game executable is disabled. The
> packaged-install instructions below describe the earlier development package,
> not a currently available public release.

# Launcher

The Windows package includes the prebuilt game, controller adapter, shaders and
.NET runtime. Open `Outbreak.Launcher.exe`, select **Game files**, and choose your
own ISO. No compiler, SDK, separate ELF, mounted drive or .NET installation is
needed. File #1 currently supports **NTSC-U v2.00 / SLUS-20765**; other executable
revisions are rejected before import. A Vulkan-capable GPU driver is required.

The first import extracts files to `%LOCALAPPDATA%\OutbreakRecomp\launcher\imports`.
It shows progress, supports cancellation, and publishes the cache only after all
files have been written. The tested disc imports 85 files / 4.27 GB. Later starts
reuse the cache; missing/truncated files and changed ELF data trigger repair.
Keep the ISO at the selected location: sector-based reads still use it directly.
A `.pak` replacement for sector reads is not part of this implementation.

Developers can build the launcher with .NET 8 SDK and Visual Studio C++ tools:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File launcher/build.ps1
```

Open `StartLauncher.cmd` in a source checkout. **Developer options** in Game files
allows selecting an alternate native build; it is hidden in packaged installs.
To create a self-contained package from an already-built native executable:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File launcher/package.ps1 -Zip
```

The packaging command is for maintainers. It never rebuilds the native game,
imports a disc, uploads a release, or includes local ISO/cache/save data. It bundles
app-local Microsoft C++ runtime DLLs and records the source revision, dirty state
and file hashes. Publish the matching source and required dependency notices with
release builds. The normal launcher never invokes build tools.

## Pages

- **Play:** select File #1 or File #2 and inspect local game files, saves, GPU and input device. Choose your ISO; the installed native build is selected automatically. File #2 gameplay is not included in the current package.
- **Graphics:** window resolution, borderless fullscreen, image scaling, 3D texture filtering, anisotropic filtering (Off/2×/4×/8×/16×), FXAA or SMAA, brightness, gamma, async geometry and experimental GPU movie decoding. Changes apply next launch.
- **Controls:** choose keyboard, DualSense or Xbox/XInput; remap buttons and keys; adjust dead zones and stick options. USB DualSense is physically tested; Xbox and Bluetooth have parser/simulated coverage. Rumble and adaptive triggers are unsupported.
- **Save games:** open the selected game's memory-card folder or create a ZIP backup while the game is closed. Save/load itself remains in the game.
- **Log:** read session debug/output logs, with optional follow mode.
- **Co-op:** configure a numeric IPv4 server address and existing account username, then opt in to online launch. This uses the original game's server/login path, not account-free peer-to-peer networking.
- **Cheats:** built-in gameplay toggles and optional compatible PCSX2 data cheats.
- **Mods:** placeholder.

Check for updates uses [GitHub Releases](https://github.com/Ninjacornix/reo/releases). Packaged installations can download, verify and install newer releases; source checkouts open the release page. See [Updates](#updates).

## Online settings

Online launch is off by default. In **Co-op**, enter the compatible openSNAP server's numeric IPv4 address and your existing account username, then enable **Launch in online mode**. The global play button changes to **Play online**. Invalid settings prevent an online launch; incomplete online fields do not affect offline play. Settings apply to the next launch and are disabled while the launcher owns a running game.

The username follows the current server's registration rules: 4–10 ASCII letters, digits or underscores, with no leading, trailing or consecutive underscores. Choose **Edit Account** in the game to apply the launcher username through the original account flow; an older stored ID is not silently replaced by choosing Go Online. Account selection does not authenticate the user. Enter the password in the game's own login screen; passwords are neither stored nor exported by the launcher. The session receipt records online/offline mode, server and account username without claiming a connection succeeded.

Online mode exports `REO_COOP_HOST`, `REO_COOP_PLATFORM_AUTH=native` and `REO_COOP_USERNAME`. Offline mode exports none of them. No server is bundled or started by this page. A separately running compatible server and registered account are required. Four native clients have completed local authentication, room entry, the scenario introduction and movement replication. Item sharing, door transitions, reconnects and LAN/WAN behavior remain unverified.

Room names, passwords, scenario rules and joining are still handled in the
original game menus. Launcher Create/Join room forms and automatic server
hosting are planned, not available controls. See [connection and hosting
requirements](../docs/NETWORKING.md#connecting-with-friends), including which
ports a host needs and the private-VPN alternative.

On an online launch, while holding the selected memory-card lease, the launcher creates `BWNETCNF/BWNETDCNF` only when `BWNETCNF` does not already exist. It contains the original project text `REO native host profile provider v1`, allowing the original profile browser to discover the native host-profile provider. It contains no Sony network-configuration bytes. Existing profile directories/files are preserved, write failures prevent launch with an explicit error, and offline launches do not add this marker. Failed creation removes only its newly created directory if it is still empty; an already-existing empty profile folder is preserved and reported as unusable. The original game remains responsible for its normal `BASLUSNET` save flow.

## Display and startup

Developer checkouts need a current native build for these settings. Packaged installs already include it.

Window resolutions range from 1024 x 768 to 3840 x 2160. Borderless fullscreen uses the monitor's desktop resolution. The original 4:3 picture is preserved with black borders when needed; these output sizes do not increase internal rendering resolution or texture detail.

Image scaling chooses nearest or bilinear sampling of the final image. The separate 3D texture-filter option enables bilinear sampling for triangles while preserving the game's sprite and framebuffer-feedback sampling. Anti-aliasing offers Off, FXAA and SMAA 1x High. SMAA uses the upstream edge-detection, blend-weight and neighbourhood passes with matching lookup textures, after scaling; it has no temporal history. Brightness and gamma are applied once after AA. All options run on the GPU and apply on the next launch.

Anisotropic filtering improves perspective 3D textures viewed at oblique angles. Choose Off, 2×, 4×, 8× or 16×; 8× is a useful starting point. It includes bilinear texture filtering for eligible draws, independently of the Original/Bilinear option. Sprites, fixed-UV triangles, GS region/cropped textures, render-target arrays and framebuffer-feedback sampling retain their original paths. Filtering uses Vulkan hardware samplers with explicit GPU texture gradients; levels are capped to the device limit, with bilinear fallback on unsupported hardware. Higher settings cost more GPU time. Existing settings default to Off.

Brightness (50-150%) and gamma (0.50-2.00) use the same adjustment curve in the immediate GPU preview and the game's GPU presentation pass. Reset restores 100% / 1.00. Settings apply to the game on its next launch; neutral values preserve the original image. The room preview is a local screenshot at `%LOCALAPPDATA%\OutbreakRecomp\launcher\room-preview.png`, not a bundled game asset. It is outside the repository and release resources.

For File #1, **Skip intros** bypasses the logo display and lets the original frontend run its cleanup before opening the title video with PRESS START. It does not press Start, bypass memory-card decisions, or remove game initialization. File #2 intro skipping is not implemented.

## Files and input

Settings, private executable copies and session logs are under `%LOCALAPPDATA%\OutbreakRecomp\launcher`. Default memory cards stay in `build-ninja/play/saves` and `build-ninja/play-file2/saves`. In **Save games**, select a card for the selected game, create a named card, or select an existing folder-backed card. New cards live under `%LOCALAPPDATA%\OutbreakRecomp\launcher\memory-cards`; selections are stored independently for each game. Existing saves are preserved. Cards hold PS2 save files, not save states or raw PCSX2 `.ps2` images. Save and load from the original game menus. Card selection and backups are disabled during play, and the launcher locks the selected card against concurrent launcher sessions.

Press **Ctrl+Enter** in the game to toggle borderless fullscreen. **Alt+F4** closes the game; Esc does not close it. The fullscreen shortcut does not send the game's Start button.

Keep the launcher open while playing. It minimizes if closed during a game, preserving the input connection. Only the selected input source controls player 1. Keyboard input is accepted while the launcher or its game is in the foreground. Device changes and bindings apply live; graphics settings apply next launch.

The launcher copies and verifies the selected executable in its own cache, installs its input adapter beside that copy, and leaves the source build untouched. The game opens without a console; stdout/stderr go to session logs. No custom app or game-window icons are supplied.

The selected ISO is imported once without mounting. The original ISO stays available for direct sector reads; the supported ELF identity is checked before import. Required presentation shaders are copied from the selected native build. GPU-resident VU ownership is disabled in this launcher configuration because it conflicts with the async worker.

## Artwork and validation

Game cards and faded backgrounds are plain by default. Users can optionally
provide their own local cover images; the launcher no longer downloads them.
These local files are neither embedded in the launcher nor distributed with the
source. See [asset provenance](Assets/PROVENANCE.md).
