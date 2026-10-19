# Building on Windows

Use a short checkout path, such as `C:\dev\reo`. Full recompilation is expensive; updating the launcher does not require rebuilding the game.

## Launcher

Requirements: Windows x64, .NET 8 SDK, Visual Studio 2022 with Desktop development with C++.

```powershell
git clone --recurse-submodules https://github.com/Ninjacornix/reo.git
cd reo
powershell -NoProfile -ExecutionPolicy Bypass -File launcher/build.ps1
```

Open `StartLauncher.cmd`. In Play, select a game and configure its native executable, ISO, and matching extracted ELF. An ISO alone is not a native build. Configure each game separately; File #2 is not validated.

```powershell
& ./launcher/bin/Release/net8.0-windows/Outbreak.Launcher.exe --self-test
```

The application requires the .NET 8 Desktop Runtime when the SDK is absent. Keep the output directory together: it includes the input adapter, mount helper, icon, and license notices.

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
