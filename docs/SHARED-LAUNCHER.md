# Common RC1 desktop launcher

The new desktop frontend is `launcher/desktop/Reo.Launcher.Desktop.csproj` (Avalonia,
.NET 10). Windows, macOS and Linux compile the same view and C# handlers.
`launcher/shared/Reo.Launcher.Core.csproj` links the original RC1 services, import,
settings, graphics contracts, saves, mods, cheats and asset parsers. OS adapters
handle window messages, controllers, credentials, Trash and native processes.
The game remains native code: Vulkan on Windows/Linux and MoltenVK → Metal on Mac.

## Design reference

The reference is **RC1 Windows in this checkout**, `launcher/Shell.xaml` and
`launcher/Theme.xaml`. The old WPF view remains available for comparison.
`launcher/desktop/Views/Shell.axaml` and `Theme.axaml` are the common editable views.
Do not rerun the one-time migration scripts over these files: subsequent fixes and
platform adaptations live in the common files.

The source check preserves 304 named RC1 controls, all 12 pages, page copy/order,
120 event sources and reference SHA-256 hashes. The game font, pinned artwork,
controller diagram and preview models come from the existing RC1 code and the
user's disc. The case geometry, camera, lighting, texture quantization, ground
projection and drag behavior use the Windows reference calculations.

This is **not yet certified pixel-identical to WPF**. The renderer changed, disc
shading and soft shadows can differ, and video transitions still need comparison.
The source checks currently pass 571 assertions; headless UI/media checks pass
54 assertions. Headless captures check the common UI and interactions; they do not establish
visual equality to the old Windows application. Native window decorations also
follow each OS. Compare actual WPF and Avalonia captures on Windows before calling
the migration visually complete.

## Run and verify

```sh
dotnet run --project launcher/desktop
python3 tools/launcher/check_reference.py
dotnet run --project launcher/cross-tests
dotnet run --project launcher/desktop -- --headless-check build-launcher/captures
```

`--headless-check` uses an isolated data folder, disables background movies and
renders inside Avalonia's headless platform. It exercises graphics/audio settings,
fullscreen dependencies, navigation, synchronized case/disc selection, settings
round-trip, page visibility and finite bounds. Captures are local artifacts.

The opt-in integration checks use isolated save/account databases and actual native
processes. They must run on the target OS with its native game/server payload:

```sh
dotnet run --project launcher/desktop -- --service-check build-launcher/server-check
dotnet run --project launcher/desktop -- --runtime-check build-launcher/game-check
```

The service check registers a temporary account against its own four workers,
repeats registration and rejects a wrong credential. It does not access Keychain.
The game check imports the owned ISO, follows the diagnostic route to gameplay,
checks logs, and joins shutdown. It does not use existing saves.

## Packaging

On the prepared Apple Silicon checkout:

```sh
python3 tools/launcher/package.py
```

Result: `build-macos/common-launcher/RE Outbreak RC1.app`. The app bundles the .NET
runtime, native game, MoltenVK, controller/Keychain adapters, FFmpeg and a separate
UI-free Python server worker. Original disc files remain outside the app. Signing
is local ad-hoc, not notarization. `--reuse-services` is only for an unchanged
previously frozen service worker. See [Mac prerequisites](MACOS.md).

The same frontend publishes for Windows and Linux:

```sh
python3 tools/launcher/package.py --runtime win-x64 --publish-only
python3 tools/launcher/package.py --runtime linux-x64 --publish-only
```

These outputs are frontend builds, not complete game distributions. Windows still
needs the original controller proxy, native game/shaders and build/server kit;
Linux needs its native game, SDL bridge and server payload. The new CI matrix
runs each OS's common-core and UI checks and publishes review artifacts. This
workflow has been added locally; no remote CI result is claimed.

## Remaining release validation

Windows/Linux runtime execution and side-by-side WPF image comparison require
those platforms. File #2, physical pads/rumble, co-op gameplay, Mac audio-output
selection, automatic lobby navigation, background-video transitions and update
installation need further integration work. Update checking only reports matching
platform packages. Router automation uses the Windows adapter; Mac/Linux hosts
need manual router/firewall setup. Existing WPF and earlier Qt sources are retained
for reference and regression checks.
