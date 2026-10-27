> The precompiled prerelease has been withdrawn. Legacy native packaging is
> disabled while the portable local-build package is completed. Generated game code,
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

Development MSVC kits require existing Visual Studio C++ tools. The portable
release path instead bundles a pinned LLVM/MinGW toolchain and independent
headers/libraries; it does not install system tools. The first compilation takes
substantially longer than later cached launches. Generated game objects are
never distributed.

See [local build kits](LOCAL_BUILDS.md) for the maintainer workflow.

```powershell
& ./launcher/bin/Release/net8.0-windows/Outbreak.Launcher.exe --self-test
```

An unbundled source build requires the .NET 8 Desktop Runtime when the SDK is
absent. Keep its output directory together, including the input adapter,
shaders and license notices. ISO mounting is not needed. Launcher and game-window
icons are original project artwork.

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

Use the launcher for normal interactive play. Its settings are under `data/` beside the launcher by default, and its default save folders are `data/memory-cards/default/file1/data` and `data/memory-cards/default/file2/data`. Change the shared storage folder under **Game files > Storage**.

The launcher can start the separately licensed portable openSNAP component using
**Host server**. Source developers must first export that component; see
[local builds](LOCAL_BUILDS.md) and [networking](NETWORKING.md). Account creation
and credential entry are handled by the launcher, while authentication and room
management retain the original game protocol and menus.

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
Prerelease installations also discover newer GitHub prereleases; stable
installations remain on stable releases. Tags use numeric versions such as
`v1.0.1`, with GitHub's prerelease flag indicating preview status.
