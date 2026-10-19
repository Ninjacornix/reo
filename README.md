# RE: Outbreak

An experimental native Windows port of Resident Evil Outbreak, built with static recompilation and a PS2 compatibility runtime.

**Source preview - local-build installer in development** Â· [Changelog](CHANGELOG.md)

This is an unofficial fan project. You must provide your own legally obtained game data. Game files and generated game code are not included.

## Status

- **Outbreak: File #1:** boots into menus and gameplay. Rendering, performance and cutscene/audio synchronization are still under development.
- **Outbreak: File #2:** configuration and a launcher entry exist; gameplay is not validated.
- **Launcher:** one-time ISO import without mounting, ISO-derived local build, fullscreen and aspect controls, bilinear/anisotropic filtering, FXAA/SMAA, brightness/gamma, intro skipping, controller remapping, selectable memory cards, cheats, logs and GitHub release updates.
- **Online co-op:** four native clients have authenticated, joined one room, reached gameplay and replicated movement through a separate openSNAP server. The launcher saves the server address and existing account username; passwords remain in-game. This is local validation; Internet play is not yet validated. Setup is below.
- **Room management and hosting:** room creation/joining still use the original game menus. Launcher room settings, automatic server hosting and NAT traversal are not implemented.
- **Mods:** placeholder. **Cheats:** built-in health, infection and ammunition options plus a supported subset of PCSX2 data cheats.

GPU rendering is implemented through paraLLEl-GS. VU execution and other PS2 behavior still use compatibility paths; this is not a claim that all game graphics work has moved to the GPU or that original timing is fully preserved.

## Installation status

The precompiled v1.0.0 prerelease has been withdrawn. There is currently no public
playable Windows download. The previous executable included game-derived code;
we are changing installation so that this code is generated locally from each
user's ISO rather than distributed by this project.

The intended setup is: download the independent launcher/runtime and build tools,
select your **Outbreak NTSC-U v2.00 ISO (SLUS-20765)** in **Game files**, then wait
for local generation and compilation. The result will be cached in Local AppData;
later launches will reuse it. This installation path is under implementation and
must not be described as ready until a clean first-run build passes.

Keep your ISO anywhere on your PC; no special filename or folder is required.
The launcher already imports game data without mounting the ISO. Keep the ISO
available afterward because the game still performs direct sector reads.

For development builds, see [Building on Windows](docs/BUILDING.md). Existing
local executables and generated sources are preserved for development and are
not public release assets. File #2 remains unsupported.

## Online co-op

Co-op is experimental. Four native clients have authenticated, joined one room,
started a scenario and replicated movement on a local server. Item sharing,
door/room transitions, reconnects and LAN/Internet play are not fully validated.
Do not treat this prerelease as finished online support.

### Join a server and play with friends

1. Get the **IPv4 address** of a compatible openSNAP server and create an account
   on that server. The launcher does not create accounts or start a server.
2. In the launcher's **Co-op** page, enter the server IPv4 address and your existing
   account username, then enable **Launch in online mode**. Usernames use 4â€“10
   ASCII letters, digits or underscores; avoid leading, trailing or repeated underscores.
3. Launch File #1 and use the game's original online/account menus. Choose
   **Edit Account** to apply the launcher username and enter your password in-game.
   An account already saved on the memory card is not silently replaced by the launcher.
4. Meet in the same area/room. One player creates the room and selects the
   scenario/settings in-game; the others join it. The host starts the scenario
   when everyone is ready. Up to **four players** can join.

There is no automatic matchmaking, launcher Create/Join form, integrated VPN,
server hosting or automatic port forwarding yet. Creating an in-game room does
not host the separate network server. Each player needs their own game data
and an account on the same server.

### Host your own server

The server is **openSNAP**, a separate Python project licensed under AGPL-3.0.
It is not bundled in the Windows download. For the tested revision and this
project's File #1 current-room fix, run from a source checkout:

```powershell
git clone https://github.com/GrenderG/openSNAP.git build/server/openSNAP
git -C build/server/openSNAP checkout --detach f9af55491718a043923225a0895fe60eab76fd7c
$outbreakPatch = (Resolve-Path 'network/server/patches/0001-outbreak-current-room-query.patch').Path
git -C build/server/openSNAP apply --check $outbreakPatch
git -C build/server/openSNAP apply $outbreakPatch
Push-Location build/server/openSNAP
python -m venv .venv
& .venv/Scripts/python.exe -m pip install -r requirements.txt
& .venv/Scripts/python.exe -m unittest tests.test_outbreak_plugin tests.test_outbreak2_plugin
Pop-Location
```

Use Python 3.11 or newer. In the cloned server folder, copy `.env.dist` to `.env`
and set the following values, replacing `192.168.1.50` with the address clients
will use (LAN IPv4 for LAN play, public IPv4 for Internet hosting):

```dotenv
OPENSNAP_GAME_PLUGIN=outbreak
OPENSNAP_WEB_GAME_PLUGIN=outbreak
OPENSNAP_BOOTSTRAP_HOST=0.0.0.0
OPENSNAP_GAME_HOST=0.0.0.0
OPENSNAP_CAPCOM_APP_HOST=0.0.0.0
OPENSNAP_WEB_HOST=0.0.0.0
OPENSNAP_BOOTSTRAP_ADVERTISE_HOST=192.168.1.50
OPENSNAP_GAME_ADVERTISE_HOST=192.168.1.50
OPENSNAP_GAME_SERVER_MAP={"outbreak":"192.168.1.50:9091"}
OPENSNAP_STORAGE_BACKEND=sqlite
OPENSNAP_SQLITE_PATH=opensnap.db
```

Run these commands in **four separate terminals**, all opened in the same
server folder so they share `.env` and the SQLite account database:

```powershell
& .venv/Scripts/python.exe run.py bootstrap
& .venv/Scripts/python.exe run.py game
& .venv/Scripts/python.exe run.py app capcom
& .venv/Scripts/python.exe run.py web
```

Leave all four services running. Create accounts through the game's original
registration/account portal. The native launcher maps the original service
hostnames to your chosen IPv4, so a separate DNS service or Sony DNAS setup
is not required for this native build. Keep the database private and use
passwords unique to this test server.

`OPENSNAP_GAME_SERVER_MAP` must advertise an endpoint clients can reach.
An advertised `127.0.0.1` works only for clients on that same PC. This project's
development server is loopback-only, not a ready-made Internet configuration.

| Service | Default port to allow on the server |
| --- | --- |
| Bootstrap login | UDP 9090 |
| Game and room traffic | UDP 9091 |
| Capcom application service | TCP 10127 |
| Account/signup pages, when used | TCP 80 |

**Same LAN:** bind the server to a reachable interface, allow the services in
Windows Firewall, advertise the server PC's LAN IPv4 address and have everyone
enter that address in the launcher. Router port forwarding is unnecessary on
the same LAN.

**Internet:** forward the ports above from your router to the server PC and
advertise your reachable public IPv4 address. Friends enter that public address;
joining clients normally do not need to forward ports. Forwarding alone does
not fix an incorrect advertised address. Behind carrier-grade NAT, ordinary
port forwarding may not be available; a reachable hosted server or a shared
private VPN is an alternative. For a VPN, bind/advertise the server's VPN IPv4
address and have friends connect to it. Neither WAN nor VPN deployment has been
validated by this project's local four-player test. No public server is supplied.

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
