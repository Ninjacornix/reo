# RE: Outbreak

An experimental native Windows port of Resident Evil Outbreak, built with static recompilation and a PS2 compatibility runtime.

**Smaller prerelease in preparation** | [Requirements](REQUIREMENTS.md) | [Changelog](CHANGELOG.md)

This is an unofficial fan project. You must provide your own legally obtained game data. Game files and generated game code are not included.

## Status

- **Outbreak: File #1:** boots into menus and gameplay. Rendering, performance and cutscene/audio synchronization are still under development.
- **Outbreak: File #2:** configuration and a launcher entry exist; gameplay is not validated.
- **Launcher:** one-time ISO import without mounting, ISO-derived local build, fullscreen and aspect controls, bilinear/anisotropic filtering, FXAA/SMAA, brightness/gamma, controller remapping, selectable memory cards, cheats, logs and GitHub release updates.
- **Online co-op:** launcher server hosting and automatic account/login integration are in development. Four native clients previously completed local multiplayer checks; see below for current limits.
- **Room management:** room creation and joining use the original game menus.
- **Mods:** placeholder. **Cheats:** built-in health, infection and ammunition options plus a supported subset of PCSX2 data cheats.

GPU rendering is implemented through paraLLEl-GS. VU execution and other PS2 behavior still use compatibility paths; this is not a claim that all game graphics work has moved to the GPU or that original timing is fully preserved.

## Windows prerelease

The bulky **v1.0.1** download has been withdrawn while packaging is simplified
and an import/setup UI freeze is fixed. A replacement download is not published
yet. The smaller package will list dependencies for users to install rather
than include the full .NET runtime and compiler in the launcher folder. See
[end-user requirements](REQUIREMENTS.md).

Select your **Outbreak NTSC-U v2.00 ISO (SLUS-20765)** in **Game files**, then
allow the first local generation and compilation to finish. This can take a long
time; progress appears in the launcher. The result is cached in Local AppData,
so later launches reuse it. No game executable or assets are included.

This is a **build-only preview**: the complete portable compilation succeeded,
but the sealed package's launcher-to-gameplay flow has not been rerun. Setup,
rendering, performance and audio may still have problems. The previous v1.0.0
game-binary package remains withdrawn.

Keep your ISO anywhere on your PC; no special filename or folder is required.
The launcher already imports game data without mounting the ISO. Keep the ISO
available afterward because the game still performs direct sector reads.

For development builds, see [Building on Windows](docs/BUILDING.md). Existing
local executables and generated sources are preserved for development and are
not public release assets. File #2 remains unsupported.
Maintainers can follow [prerelease preparation](docs/PRERELEASE.md) for the
repository and package requirements. Native Linux support is in development;
no playable Linux package is currently available.

## Online co-op

In **Co-op**, enter a server IPv4 address and choose a username. Press Enter or
leave the username field to create the account; its status appears below. Use
**Play** as usual, then choose **Network** in the game. The launcher enters the
saved credentials automatically;
there is no separate online launch mode. If the name already belongs to someone
else, choose another username. Automatic provisioning and native login have
been checked separately. The latest two-client retest also reached the first
room through the ordinary login route with disposable test accounts.

To host, enable **Host server**. The launcher starts the services and displays
**Friends connect to** with a copy button once they are listening. Use the
suggested LAN address for the same network, or enter a reachable VPN/public IPv4
before starting. Friends enter that address in their own launchers. The server
component is included in the portable package; there is no manual Python
installation step for players.

Internet hosting still requires a reachable server and firewall/router rules:
UDP **9090/9091** and TCP **10127/80**. Optional UPnP and Windows Firewall helpers
are implemented but have not been validated for Internet play. A built-in VPN
is not provided. A LAN address is not an Internet address.

Create or join rooms and choose the scenario inside the game. Up to four native
clients have authenticated, entered a room and replicated movement in local
checks. The new automatic account/hosting flow, reconnects, item sharing, room
transitions and LAN/Internet play are not yet fully validated. Co-op remains
experimental.

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
