# RE: Outbreak

An experimental native Windows port of Resident Evil Outbreak, built with static recompilation and a PS2 compatibility runtime.

**v0.1 developer preview** · [Changelog](CHANGELOG.md)

This is an unofficial fan project. You must provide your own legally obtained game data. Game files, generated game code and proprietary artwork are not included.

## Status

- **Outbreak: File #1:** boots into menus and gameplay. Rendering, performance and cutscene/audio synchronization are still under development.
- **Outbreak: File #2:** configuration and a launcher entry exist; gameplay is not validated.
- **Launcher:** game selection, graphics settings, keyboard/controller bindings, save backups and debug logs.
- **Online co-op, mods and cheats:** not available. Planned co-op uses direct host/join without mandatory accounts.

GPU rendering is implemented through paraLLEl-GS. VU execution and other PS2 behavior still use compatibility paths; this is not a claim that all game graphics work has moved to the GPU or that original timing is fully preserved.

## Getting started

See [Building on Windows](docs/BUILDING.md) for dependencies, native game generation and build commands.

To build the standalone launcher with the .NET 8 SDK and Visual Studio C++ tools:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File launcher/build.ps1
```

Open `StartLauncher.cmd`, choose a game, and configure its matching native executable, disc image and ELF in **Game files**. Keep the launcher open while playing so its input adapter remains connected.

See the [launcher guide](launcher/README.md) for settings and save locations. Games launched through it do not open a terminal window; debug output remains available in **Log**.

## Source layout

| Directory | Purpose |
| --- | --- |
| `launcher/` | Windows launcher and input adapter |
| `recomp/` | Recompilation configuration and game-specific overrides |
| `runtime/`, `src/` | Original runtime/scaffold components |
| `tools/parallel_gs_backend/` | Graphics backend and movie/geometry integration |
| `tools/` | Extraction, generation, diagnostics and regression checks |
| `third_party/` | Pinned PS2Recomp submodule and local dependency patches |
| `game/`, `media/`, `network/` | Format, media and network components at varying implementation stages |

Generated sources, captures, saves, build outputs and private handoffs remain local. See [developer tools](tools/README.md) and [CONTRIBUTING.md](CONTRIBUTING.md).

## License

This fork's original contributions are GPL-3.0-only. Inherited upstream and third-party components retain their licenses and attribution; see [LICENSE](LICENSE) and [NOTICE.md](NOTICE.md).

Resident Evil and Outbreak are trademarks of their respective owners. This project is not affiliated with or endorsed by Capcom or Sony.
