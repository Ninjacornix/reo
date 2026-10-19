# RE: Outbreak

An experimental native Windows port of Resident Evil Outbreak, built with static recompilation and a PS2 compatibility runtime.

**Developer preview** · [Changelog](CHANGELOG.md)

This is an unofficial fan project. You must provide your own legally obtained game data. Game files, generated game code and proprietary artwork are not included.

![RE: Outbreak launcher](docs/images/launcher.png)

The screenshot uses the launcher's original fallback artwork. Publisher covers
are downloaded separately for local use and are not included in the repository.

## Status

- **Outbreak: File #1:** boots into menus and gameplay. Rendering, performance and cutscene/audio synchronization are still under development.
- **Outbreak: File #2:** configuration and a launcher entry exist; gameplay is not validated.
- **Launcher:** one-time ISO import without mounting, packaged native game, fullscreen and aspect controls, bilinear/anisotropic filtering, FXAA/SMAA, brightness/gamma, intro skipping, controller remapping, selectable memory cards, cheats, logs and GitHub release updates.
- **Online co-op:** four native clients have authenticated, joined one room, reached gameplay and replicated movement through a separate openSNAP server. The launcher saves the server address and existing account username; passwords remain in-game. This is local validation, not a completed Internet-play certification. See [networking](docs/NETWORKING.md).
- **Room management and hosting:** room creation/joining still use the original game menus. Launcher room settings, automatic server hosting and NAT traversal are not implemented.
- **Mods:** placeholder. **Cheats:** built-in health, infection and ammunition options plus a supported subset of PCSX2 data cheats.

GPU rendering is implemented through paraLLEl-GS. VU execution and other PS2 behavior still use compatibility paths; this is not a claim that all game graphics work has moved to the GPU or that original timing is fully preserved.

## Getting started

For a Windows runtime package, extract the archive and open
`Outbreak.Launcher.exe`. In **Game files**, choose your own ISO. The launcher
validates the disc version, imports it once, and runs the included native game.
Users do not need a compiler, SDK, separate ELF, mounted drive or .NET installation.
Keep the ISO available for direct sector reads. File #1 currently supports the
NTSC-U v2.00 disc (SLUS-20765); File #2 is not included in the runtime package.

For source builds, see [Building on Windows](docs/BUILDING.md). Open
`StartLauncher.cmd` after building. Maintainers can create a self-contained local
package with `launcher/package.ps1 -Zip`; this does not publish a GitHub release.
Keep the launcher open while playing so its input adapter remains connected.

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
