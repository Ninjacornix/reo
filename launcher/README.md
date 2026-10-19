# Launcher

A standalone WPF launcher for Windows x64. Build with .NET 8 SDK and Visual Studio 2022 C++ tools:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File launcher/build.ps1
```

Open `StartLauncher.cmd`. The launcher builds independently of the game.

## Pages

- **Play:** select File #1 or File #2 and inspect local game files, saves, GPU and input device. Configure a matching native executable, ISO and ELF for each game. File #2 gameplay is not validated.
- **Graphics:** window size, borderless fullscreen, image filtering, async geometry and experimental GPU movie decoding. Changes apply next launch. Window size does not change internal rendering resolution.
- **Controls:** choose keyboard, DualSense or Xbox/XInput; remap buttons and keys; adjust dead zones and stick options. USB DualSense is physically tested; Xbox and Bluetooth have parser/simulated coverage. Rumble and adaptive triggers are unsupported.
- **Save games:** open the selected game's memory-card folder or create a ZIP backup while the game is closed. Save/load itself remains in the game.
- **Log:** read session debug/output logs, with optional follow mode.
- **Mods, Cheats and P2P co-op:** placeholders. Skip intros is also unavailable in the current game build.

Check for updates opens [GitHub Releases](https://github.com/Ninjacornix/reo/releases). Downloading and installation are not implemented.

## Files and input

Settings, private executable copies and session logs are under `%LOCALAPPDATA%\OutbreakRecomp\launcher`. Memory cards stay in `build-ninja/play/saves` and `build-ninja/play-file2/saves`.

Keep the launcher open while playing. It minimizes if closed during a game, preserving the input connection. Only the selected input source controls player 1. Keyboard input is accepted while the launcher or its game is in the foreground. Device changes and bindings apply live; graphics settings apply next launch.

The launcher copies and verifies the selected executable in its own cache, installs its input adapter beside that copy, and leaves the source build untouched. The game opens without a console; stdout/stderr go to session logs. No custom app or game-window icons are supplied.

The selected ISO is mounted read-only if necessary and left mounted for other processes. The chosen ELF is checked against the disc before launch. Required presentation shaders are copied from the selected native build. GPU-resident VU ownership is disabled in this launcher configuration because it conflicts with the async worker.

## Artwork and validation

Backgrounds and game-card illustrations are original procedural graphics under GPL-3.0-only. See [asset provenance](Assets/PROVENANCE.md). Regenerate them with `tools/New-Artwork.ps1`. The app fetches no artwork online and respects Windows reduced-motion settings.

```powershell
& ./launcher/bin/Release/net8.0-windows/Outbreak.Launcher.exe --self-test
```

The checks cover input parsing, mapping, device selection, configuration/save isolation, log reading and the native adapter. Passing them is not a gameplay, audio or performance certification.
