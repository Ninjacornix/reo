> The precompiled prerelease has been withdrawn. Legacy native packaging is
> disabled while the local-build installer is implemented. Generated game code,
> instruction-derived GPU shader outputs and game captures stay local.

# Building on Windows

Use a short checkout path, such as `C:\dev\reo`. Full recompilation is expensive; updating the launcher does not require rebuilding the game.

## Launcher

Requirements: Windows x64, .NET 8 SDK, Visual Studio 2022 with Desktop development with C++.

```powershell
git clone --recurse-submodules https://github.com/Ninjacornix/reo.git
cd reo
powershell -NoProfile -ExecutionPolicy Bypass -File launcher/build.ps1
```

Open `StartLauncher.cmd`. The source checkout needs an already-built native executable. In **Game files**, choose your ISO; the launcher extracts its ELF and assets automatically without mounting. The native executable override is under **Developer options**. File #2 is not validated.

Public game executables are no longer packaged. The replacement build kit generates
and compiles game code locally from each player's ISO, with a resumable cache.
The exporter and compiler are under `tools/local_build/`; validation is still in
progress. Do not publish a kit before a clean first-run build and room route pass.

Compiler tools are discovered locally. On PCs without them, the launcher offers
Microsoft's signed Build Tools installer; users review its terms and installation
choices. The first compilation takes substantially longer than later cached launches.
No compiler, SDK libraries or generated game objects are distributed.

See [local build kits](LOCAL_BUILDS.md) for the maintainer workflow.

```powershell
& ./launcher/bin/Release/net8.0-windows/Outbreak.Launcher.exe --self-test
```

An unbundled source build requires the .NET 8 Desktop Runtime when the SDK is
absent. Keep its output directory together, including the input adapter,
shaders and license notices. There is no ISO mount helper or custom app icon.

## Native game

Requirements: Visual Studio 2022 C++ tools, CMake, Ninja, Python 3, the pinned PS2Recomp submodule, and your own NTSC-U game data. GPU builds additionally need Vulkan tooling and matching paraLLEl-GS libraries.

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File tools/setup_deps.ps1
cmake --build build-ninja --target reo-extract
./build-ninja/tools/iso_extract/reo-extract.exe '<your ISO>' game_data
./third_party/PS2Recomp/out/build/ps2xRecomp/Release/ps2_recomp.exe recomp/config/outbreak.toml
cmake --build build-ninja --target reo_recomp --parallel 6
```

The setup script fetches pinned dependencies and applies the local runtime patch series. Inspect it before running in an existing modified dependency checkout. Recompilation configurations, function maps, and overlay-generation tools are under `recomp/config/` and `tools/`. Additional overlay generation may be needed for the selected build; generated outputs are intentionally excluded from Git.

The ordinary target is `reo_recomp`; `reo` is the older scaffold. Experimental GPU builds depend on additional local source/library paths declared in `recomp/CMakeLists.txt`. They are not a turnkey clean-clone release pipeline. Do not reuse a private link script or mix objects compiled against different runtime interfaces.

Use the launcher for normal interactive play. Its settings are under `%LOCALAPPDATA%\OutbreakRecomp\launcher`, and its save folders are `build-ninja/play/saves` and `build-ninja/play-file2/saves`.

Online development additionally uses a separately installed openSNAP server;
see [networking](NETWORKING.md) and the [server patch](../network/server/README.md).
The launcher does not install or start this server. Game authentication and
room management still use the original game protocol and menus.

### Formatting and documentation captures

Run `python tools/format_code.py --write` to apply the repository's clang-format
style to project-owned C/C++ and C#. Use it without `--write` to check. It
respects `.clang-format-ignore`: dependencies and generated game code retain
their original formatting. Shader assets and hash-pinned catalogues are kept
unchanged; Python, PowerShell, Markdown and XAML are not clang-format inputs.

Documentation screenshots must use the launcher's plain background and must not
include publisher artwork or game captures. Private screenshot paths stay ignored.

### Updater-compatible Windows releases

Updates use distribution format 2 (`installMode: local-build`) and carry the
independent build kit rather than a game executable. Old format-1 packages are
refused by the updater. Source archives are not installable updates. Publication
remains disabled until a complete kit has passed first-run and gameplay validation.
