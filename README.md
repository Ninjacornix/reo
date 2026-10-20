# RE: Outbreak

An experimental native Windows port of Resident Evil Outbreak, built with static recompilation and a PS2 compatibility runtime.

**v1.0.11 prerelease** | [Downloads](https://github.com/Ninjacornix/reo/releases) | [Requirements](REQUIREMENTS.md)

This is an unofficial fan project. You must provide your own legally obtained game data. Game files and generated game code are not included.

## Status

- **Outbreak: File #1:** boots into menus and gameplay. Rendering, performance and cutscene/audio synchronization are still under development.
- **Outbreak: File #2:** configuration and a launcher entry exist; gameplay is not validated.
- **Launcher:** one-time ISO import without mounting, ISO-derived local build, fullscreen and aspect controls, bilinear/anisotropic filtering, FXAA/SMAA, brightness/gamma, controller remapping, selectable memory cards, cheats, logs and GitHub release updates.
- **Online co-op:** launcher server hosting and automatic account/login integration are in development. Four native clients previously completed local multiplayer checks; see below for current limits.
- **Room management:** room creation and joining use the original game menus.
- **Mods:** placeholder. **Cheats:** built-in health, infection and ammunition options plus a supported subset of PCSX2 data cheats.

GPU rendering is implemented through paraLLEl-GS. VU execution and other PS2 behavior still use compatibility paths; this is not a claim that all game graphics work has moved to the GPU or that original timing is fully preserved.

Already compiled the game? In **Game files**, click **Use existing build** and
choose `reo_recomp.exe` from a completed compatible launcher build. Keep
`local-build.json`, DLLs and `reo-gpu-present` shader folder together. The launcher verifies and caches
that build, skipping compilation; your supported ISO is still required. A lone
EXE or a build from a different kit is not enough.

Game selection works by clicking a game card or using the keyboard; there are no
separate Select buttons. [Build-time findings](https://github.com/Ninjacornix/reo/blob/main/docs/BUILD_PERFORMANCE.md)
explain the current compilation costs and next optimization candidates.

## Windows prerelease

Download **RE-Outbreak-v1.0.11-Windows-x64.zip** from
[GitHub Releases](https://github.com/Ninjacornix/reo/releases). Install the
[requirements](REQUIREMENTS.md), extract the ZIP, and open `Outbreak.Launcher.exe`.
The launcher folder no longer includes the .NET runtime, language folders or a
compiler installation. Hosting source is included under `network-server/`, with
its dependencies listed in `requirements.txt` rather than bundled Python/packages.
Extract all files into one folder; `Outbreak.Launcher.exe` is at its top level.
The v1.0.1, v1.0.2 and v1.0.3 downloads are withdrawn. Extract v1.0.11 into a fresh
folder if upgrading, so old bundled Python/vendor files are left behind. The
single-file startup fix from v1.0.4 is retained. Licence notices are in
`THIRD-PARTY-NOTICES.txt`; source archives are separate developer downloads.

Click **Choose ISO** in **Game files** and select your **Outbreak NTSC-U v2.00 ISO
(SLUS-20765)**. Import starts automatically: the launcher checks the disc, downloads
and prepares the compiler, then builds the game. No manual compiler installation,
environment variable or terminal command is needed. First setup needs Internet and
can take substantial time; progress, cancellation and stage ETAs are shown.
The result and tools are cached in Local AppData,
so later launches reuse it. No game executable or assets are included.

This update speeds up source generation and compilation without lowering the
game's compiler optimization level. See the [measured results](docs/COMPILATION_PERFORMANCE.md).
Its updated build inputs have a new cache identity: games compiled with an older
kit need rebuilding for this version. Keep an older installation if you want to
continue using its completed build meanwhile.

Only **File #1 NTSC-U v2.00 (SLUS-20765)** is supported. Before extraction, the
launcher checks SYSTEM.CNF's boot executable, identifies known game/region serials
and verifies the executable SHA-256. PAL, Japanese, File #2, unknown games and
other/modified executable revisions get a specific error beside the ISO controls.
The ISO filename and SYSTEM.CNF's VER field do not establish the game revision.

This is an **experimental preview**: the reference native compilation succeeded,
but the new external-toolchain setup and launcher-to-gameplay flow have not been rerun. Setup,
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
source is included in the main download. On first hosting, the launcher downloads
Python and installs the required packages into a private Local AppData environment,
then starts the server. Progress and cancellation are available in Co-op. Later
starts reuse the cache; joining friends needs no setup. See
[server setup](network/server/SETUP.md) for details and advanced overrides.

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
