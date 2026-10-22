# RE: Outbreak

An experimental native Windows port of Resident Evil Outbreak, built with static recompilation and a PS2 compatibility runtime.

**1.0 Alpha prerelease (v1.0.15)** | [Downloads](https://github.com/Ninjacornix/reo/releases) | [Requirements](REQUIREMENTS.md)

This is an unofficial fan project. You must provide your own legally obtained game data. Game files and generated game code are not included.

![The launcher on first start: it asks for your game disc](docs/launcher-screenshots/launcher-play.png)

## Get started

1. Install the [.NET 8 Desktop Runtime (x64)](https://dotnet.microsoft.com/en-us/download/dotnet/8.0) if you don't have it, and keep your graphics driver current (Vulkan is required).
2. Download **RE-Outbreak-v1.0.15-Windows-x64.zip** from [Releases](https://github.com/Ninjacornix/reo/releases), extract it into a new folder and open `Outbreak.Launcher.exe`.
3. The **Play** page tells you the next step. Click **Choose ISO** and pick your own **Outbreak File #1 NTSC-U v2.00 ISO (SLUS-20765)**. The launcher checks it and shows a green ✓ when it is supported.
4. Click **Build game**. This one-time setup imports the disc, prepares the build tools (about 173 MB, reused if the exact compiler is already installed) and compiles the game. It needs Internet and about 10 GB of free space, and can take over an hour. Progress stays visible at the bottom of every page.
5. Click **Play**.

The Play page's **Before you play** checklist shows what is ready (✓) and what is
missing (✗), with a button for each fix: **Get driver** opens your graphics card
maker's driver page, **Free up space** opens Windows storage settings, **Choose ISO**
picks your disc. .NET itself must be installed before the launcher can open;
Windows offers the download link if it is missing.

Later launches reuse the finished build. After a build, the launcher deletes its
temporary generated sources and keeps only a compile cache (about 1.2 GB) so future
updates rebuild only what changed. **Remove game** in **Game files** deletes the
imported disc data, the built game and that cache; your ISO stays, and saves and
build tools are only removed if you tick those options. No compiler installation, environment variable or terminal command is needed. Keep the ISO available; the game reads it directly.

Already compiled the game with a compatible launcher? In **Game files**, click **Use existing build** and choose `reo_recomp.exe` from that build folder. Keep the folder complete (`local-build.json`, DLLs and the `reo-gpu-present` shaders). Your ISO is still required.

## Status

- **Outbreak: File #1:** boots into menus and gameplay. Rendering, performance and cutscene/audio synchronization are still under development.
- **Outbreak: File #2:** a placeholder in the launcher; not playable.
- **Launcher:** guided first-run setup, ISO check before import, local build with cached reuse, display and filtering options, controller remapping, memory cards, cheats, logs, co-op hosting/joining and GitHub release updates.
- **Online co-op:** experimental; see below.
- **Mods:** enable **Randomizer** for File #1 to randomize items, guns, ammunition and enemy spawns together. Original enemy entrances hand off to seeded native species; see [Creating a mod](docs/MODDING.md). **Cheats:** built-in health, infection and ammunition options plus a supported subset of PCSX2 data cheats.

GPU rendering is implemented through paraLLEl-GS. VU execution and other PS2 behavior still use compatibility paths; this is not a claim that all game graphics work has moved to the GPU or that original timing is fully preserved.

Only **File #1 NTSC-U v2.00 (SLUS-20765)** is supported. Before extraction, the
launcher checks SYSTEM.CNF's boot executable, identifies known game/region serials
and verifies the executable SHA-256. PAL, Japanese, File #2, unknown games and
other/modified executable revisions get a specific error beside the ISO controls.
The ISO filename and SYSTEM.CNF's VER field do not establish the game revision.

v1.0.15 ships the Randomizer runtime and new build files, so the game is built
once more after updating. Runtime headers changed, so this update recompiles all
units. Later updates can reuse the compile cache where inputs are unchanged. Generation and compilation were also made faster in v1.0.11 without
changing compiler optimization; see the [measured results](docs/COMPILATION_PERFORMANCE.md).

This is an **experimental preview**. Setup, rendering, performance and audio may
still have problems. The previous v1.0.0 game-binary package remains withdrawn.

For development builds, see [Building on Windows](docs/BUILDING.md). Existing
local executables and generated sources are preserved for development and are
not public release assets.
Maintainers can follow [prerelease preparation](docs/PRERELEASE.md) for the
repository and package requirements. Native Linux support is in development;
no playable Linux package is currently available.

## Online co-op

![The Co-op page with Play alone, Host a game and Join a game](docs/launcher-screenshots/launcher-coop.png)

Open **Co-op**, pick **Host a game** or **Join a game**, and enter a player name.
There is no registration or password: the launcher creates the account on the
host's server for you.

- **Host a game** opens your game for friends right away. Choose the address they
  should use (home network, VPN or internet) and click **Copy address**. The first
  time, the launcher prepares the hosting server: it uses an installed Python 3.12
  if you have one, otherwise it downloads a private copy, then installs the server
  packages into Local AppData. Later starts reuse it.
- **Join a game** lists games hosted on your network, or you can type the host's
  address.
- With **Take me to the waiting room automatically** (on by default), pressing
  **Play** signs in and brings you to the host's room. The host opens a room for
  four players; friends join it. Press any button to take over at any point. The
  host chooses **START SCENARIO**.

Playing over the internet needs the host to be reachable. The easiest way is a VPN
such as Tailscale or ZeroTier. Otherwise forward these ports to the host (the
launcher can ask your router through UPnP):

| Port | Use | Can it change? |
| --- | --- | --- |
| UDP 9090 | Login | No, built into the game |
| TCP 10127 | Game app server | No, built into the game |
| UDP 9091 | Game server | Yes, under **Ports** |
| TCP 10128 | Player sign-up (was TCP 80 before v1.0.12) | Yes, under **Ports** |
| UDP 10129 | Finding the host and sharing session settings | Yes |

If a port is busy, the launcher names the program using it. Internet play cannot
always work behind carrier-grade NAT without a VPN. Hosts' IP addresses are visible
to the players who join them.

What has been checked: hosting, automatic sign-up and the native credential
handshake (isolated tests), and two local game clients reaching the same waiting
room through the launcher's room automation. Not yet validated: the complete
Play-button path from the title screen to the waiting room, internet play,
reconnects, item sharing and room transitions. Co-op remains experimental. See
[server setup](network/server/SETUP.md) for advanced overrides.

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
