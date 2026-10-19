# Native networking

Online gameplay is under development. A successful socket test or an open game
window does not demonstrate multiplayer synchronization.

The NTSC-U File #1 build uses SN/ACCESS (SN@P). Its original networking library
calls SNIOPINT service `0x01270110`. The native implementation supplies Winsock
TCP/UDP and name resolution underneath that library, preserving the game's
original protocol. The old `network/snap_client` and `network/dnas` classes are
unfinished scaffolding and are not the native game's transport.

The transport is opt-in through `REO_COOP_HOST`, a numeric IPv4 address. Ordinary
offline launches retain their existing behavior. Known original Outbreak service
names resolve to the selected host; unsupported names and operations fail rather
than reporting a connected session. IOP reboot invalidates the transport's socket
handles. `REO_NET_TRACE=1` enables bounded diagnostics;
`REO_COOP_TRACE_FILE` records RPC results and actual socket bytes. Use disposable
test accounts when capturing authentication traffic.

The development server is [openSNAP](https://github.com/GrenderG/openSNAP), running
as a separate AGPL-3.0 service. It provides UDP bootstrap on 9090, UDP game service
on 9091, and the Capcom application service on TCP 10127. Server sources are not
included in the GPL runtime. `REO_COOP_PLATFORM_AUTH=native` completes the
console-specific platform workflow without using Sony DNAS. It requires the
host-backed link and proceeds to the original openSNAP account authentication;
it does not supply a DNAS certificate or grant server admission. Leaving this
option unset retains the original console path, which is experimental and
currently encounters uncompiled self-decrypting DNAS code.

The launcher's Co-op page saves a server IPv4 address and an existing account
username. Online mode exports these settings only for that launch; passwords
remain in the game's original login screen. `REO_COOP_USERNAME` selects the
account through the original browser result, memory-card save and password
workflow. It does not create an account or grant server admission. The current
openSNAP account policy permits 4–10 ASCII letters, digits and underscores,
without leading, trailing or repeated underscores.

The development server's HTTP account portal is reachable through the native
game's original browser. Four isolated native clients have completed the original
account challenge, game-server handoff and connection test, joined the same room,
and acknowledged the host's scenario-start broadcast. A four-client loopback run
also completed the introduction, rendered the room, and replicated player
movement. Retained input timestamps, peer packet delivery and read-only actor
snapshots provide separate evidence of transport and guest-state progress.
Item sharing, door transitions, reconnects and wider-network behavior remain
unverified. A compatible server must be
running separately; the launcher does not currently install or start one.

The development server's File #1 current-room roster fix is provided separately
in [network/server](../network/server/README.md). It preserves the original
room-ID-zero query convention already supported by the server's File #2 plugin.

Native online mode supplies monotonic host time for the original SDK's Count
clock and accumulated-seconds clock. The latter otherwise reads an unimplemented
HBlank counter that stays zero, preventing the original scenario send deadline
from advancing. Timer resets and accumulated offsets are preserved; account
authentication, packet completion and gameplay synchronization still run through
the original code.

## Development checks

See [connecting with friends](#connecting-with-friends) for hosting requirements.

`tools/snap_iop_check/run.bat` exercises the verified RPC layouts against real
loopback sockets, including failure cases and handle reset. This is transport
validation, not a gameplay test.

`tools/coop_playtest/` prepares isolated native instances with private memory
cards, controller maps, images and logs. It records process identities and owned
socket endpoints. `REO_COOP_TEST_INPUT=1`, together with a private
`REO_LAUNCHER_PAD_MAP`, permits controller-only input while the instance is
unfocused; keyboard input remains restricted to the foreground game.

Acceptance requires genuine native clients to authenticate, join the same room,
start a scenario, and exchange gameplay changes correctly. Two-client and then
four-client results must include actual protocol and guest progress evidence.

## Connecting with friends

The current implementation uses a separate openSNAP server. Creating an in-game
room does not start that server. The launcher currently configures the server
IPv4 address and existing account username; room creation and joining remain in
the original menus. Launcher room forms, server startup and automatic NAT
traversal are planned and not implemented.

For the same LAN, clients use the server PC's LAN address. The server must listen
on a reachable interface and its firewall must allow the required services.
The development fixture binds to `127.0.0.1` and accepts only same-PC clients;
it is not a remotely reachable hosting configuration.

For direct Internet hosting, forward these services to the server PC and allow
them through its firewall:

| Protocol | Default port | Purpose |
| --- | --- | --- |
| UDP | 9090 | Bootstrap login |
| UDP | 9091 | Game and room traffic |
| TCP | 10127 | Capcom application service |
| TCP | 80 | Account/signup pages, when used |

Friends enter the host's public IPv4 address. Configure the bootstrap/game
advertised addresses and `OPENSNAP_GAME_SERVER_MAP` to give clients a reachable
endpoint; forwarding ports alone does not correct an advertised loopback or LAN
address. Joining clients normally do not need router forwarding. The native
hostname mapping uses the selected host, so it does not require exposing a DNS
server. See the [upstream service configuration](https://github.com/GrenderG/openSNAP#services).

A private VPN is another option: bind the server to its VPN interface, advertise
that VPN IPv4 address, and have friends connect to it. Tailscale generally does
not require manual inbound port forwarding; see its [firewall documentation](https://tailscale.com/docs/reference/faq/firewall-ports).
This is a deployment option, not integrated or tested launcher functionality.
Neither Internet hosting nor private-VPN play has been validated by the local
four-client test. Each player still needs an account on the selected server.
