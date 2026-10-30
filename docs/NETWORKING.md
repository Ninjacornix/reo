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

The Co-op page uses a shared connection-mode selector with player and waiting-room
settings on the left and host or join controls on the right. Hosting keeps invite
addresses, firewall status, internet access and port settings together. Discovered
games show their waiting-room state; selecting one preserves its advertised sign-up
port. Manual addresses remain available for games outside local discovery.
The hosting invite dropdown fetches the internet address once, retains it alongside
local addresses. The dropdown contains addresses only. Lookup never changes
the selected invite address. Forwarding and editable ports are shown directly on the page. Joining runs one
initial local-game search per edition; further searches require Search again.

With automatic waiting-room entry enabled, hosts can choose a room name (up to
15 letters, digits or underscores), 2–4 players, and a waiting time of 5, 10, 15
or 30 minutes. File #2 also offers 3 minutes. Blank names use the player name.
These preferences drive the original creation menus through ordinary pad and
USB-keyboard input. The driver reads live choice labels, editability and active
bounds; unsupported area rules return control to the game menus. Discovery
includes the custom room title so updated joining launchers can select it.

UPnP requests router port mappings only while hosting and when enabled. The
router must support and permit UPnP; accepted mappings do not prove public
reachability. The launcher reports the request result separately from its saved
preference and leaves router configuration untouched when the preference is off.

The launcher has one Play action. Valid Co-op settings export the configured
server/username plus `REO_COOP_AUTO_ACCOUNT=1`; incomplete settings leave offline
play available. Confirming the username with Enter or leaving the field provisions
the account before game launch. The runtime revalidates the same saved credential
when entering Network. Setup uses the existing `/reweb/signup/create_id.html`
form and requires the exact server success markers for the requested username. HTTP 200
alone is not success, and an existing name with a different password is refused.

On Windows, a random password is persisted with user-scoped DPAPI before sending
the request. Server address and username bind the credential identity. Credentials
never appear in environment variables or arguments. Per-attempt, non-secret
status files gate original account selection and a bounded native credential
handoff to the original editor. Generation checks, acknowledgement and the original
editor's initialization gate prevent premature or repeated login submission.
The server still performs its normal challenge/admission. The previous manual account flow remains available to
non-launcher diagnostic sessions without the automatic-account environment.

The account provider/server integration passes isolated real-service checks.
A native automatic-login run authenticated and reached server selection without
manual credential entry. A subsequent two-client retest with disposable accounts
authenticated, joined the same two-member waiting room and reached the first
room on both clients. That retest used the original USB-password test driver;
it does not establish end-to-end launcher-created-account multiplayer.

The 2026-10-19 retest used GPU movies and the faster lobby/cutscene drivers.
Login submission took 70.2 seconds from driver start, the waiting-room driver
took 13.5 seconds, and the two clients entered gameplay 19.3 and 20.0 seconds
after the scenario-start driver began. Both subsequently exited with code 0
after window-close requests, with no fatal native diagnostics. Movement samples
were not obtained in this retest; the earlier movement evidence below remains
separate. A follow-up run was interrupted and is not counted as a pass.

The development server's HTTP account portal is reachable through the native
game's original browser. Four isolated native clients have completed the original
account challenge, game-server handoff and connection test, joined the same room,
and acknowledged the host's scenario-start broadcast. A four-client loopback run
also completed the introduction, rendered the room, and replicated player
movement. Retained input timestamps, peer packet delivery and read-only actor
snapshots provide separate evidence of transport and guest-state progress.
Item sharing, door transitions, reconnects and wider-network behavior remain
unverified. A compatible server must be
running separately; the launcher can start its bundled component with Host server.

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

The launcher's Developer page groups opt-in recordings: packet timing
(`REO_COOP_TRACE_FILE`), the transport log (`REO_NET_TRACE`), the first 64 SN@P packets
(`REO_SNAP_TRACE`), frame timing (`REO_FRAME_PACING_FILE`, about 9 minutes) and the File #1
game clock/player position observer (`REO_GAME_CLOCK_*`, 600 s from the first room).
Network items apply only to online launches; `launch.json` records which were on.
Packet timing sets `REO_COOP_TRACE_FILE` for an online launch. When the game exits, the launcher rewrites the trace as `coop-trace.jsonl`
in the session folder, keeping each packet's timestamp, direction, peer, length and first
16 bytes, and deletes the full-payload file. `coop-trace-clock.json` maps the game's
steady-clock timestamps to UTC for alignment with the server log. If the launcher closes
before the game, the full-payload `coop-trace.raw.jsonl` remains; do not share that file.
Frame rate per second is already in every session's `stderr.log` (`[perf]` lines).

2026-10-25 two-player internet session (host log plus openSNAP server logs only):
host held 60 vsyncs per second for the hour; scenario results recorded 54,147 ticks
for the host and 53,321 for the joining player; each client sent roughly one gameplay
packet per second through the game service, the host's mostly on a 1.0 s cadence. The
players reported enemies missing or in different positions on one screen. Whether the
original game also sends at this rate is unverified (needs a PCSX2 reference capture).

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

## File #1 update cadence and movement correction (2026-10-27)

Original SLUS-20765 code has separate outbound queues. The reliable batch
pump at `1C72F0` uses the float at `235F60`, whose shipped value is `1.0`
seconds. The second queue at `1C7400` uses `32AF20`, initially zero (no
interval delay on that pump). Thus there is no single full-world snapshot
frequency: message production, queue batching, events and simulation are
separate. The earlier Internet trace's roughly one gameplay packet per second
agrees with the reliable queue's default. File #2's roughly half-second batch
must not be substituted for the File #1 value.

The original tuning parser `1F5E30` can replace the interval fields with
nonzero supplied values. Lowering the reliable batching interval is possible,
but the resulting fresh movement-update rate still depends on the producers,
queue capacity, acknowledgements and packet delivery. A 100 ms experiment
would target ten batch opportunities per second; it has not been implemented
or validated as a desync fix here. The parser is registered for APP command
`6210`; the current File #1 APP service has no tuning handler or exposed
settings option for it. Adding a supported rate control therefore needs
integration and multiplayer checks. Original cadence proof (640 verified
instructions and ELF literals):
`build-ninja/file2-lobby-research/cadence-comparison.json`.

The server forwards gameplay relay payloads and sender identity; it does not
simulate the world or send authoritative world-state repairs.

File #1 already has conditional linear movement correction. Receiver `67ED50`
can set a target via `6647B0` and request 15 update steps. `6647F0` applies the
correction through `663BB0`/`663990`: each step adds `(target-current)/remaining`
and decrements the counter, ending exactly at the target. `663990` snaps when
the separation exceeds 500 game units. Some actor/animation/room branches use
immediate corrections, and the smoothing path is gated by actor state. These
facts were checked against 1,480 original overlay instruction words; evidence
is in `build-ninja/file2-network-research/file1-interpolation-proof.json`.

An extra unconditional LERP would alter these existing behaviors. A focused
movement-jump investigation should align both clients' packet timestamps and
clock/position recordings, identify long packet gaps or growing reliable
queues, and observe which correction path fires. Higher batching frequency
and visual smoothing are candidates for testing; neither establishes that
missing or stale gameplay state has been repaired. The initial investigation made no runtime changes; the subsequent native
batching change is recorded below.

## Faster native File #1 batching (2026-10-27)

Native online File #1 now uses a 0.5-second reliable batching interval, matching
File #2, in place of the original 1.0-second default. The wrapper at original
pump `1C72F0` changes only the exact default float at `235F60` when both a
co-op host and native platform mode are configured. Other server-supplied
intervals are retained. The original queue pump still handles batching,
acknowledgements, retries and completion. Simulation timing, the other outbound
queue and existing interpolation are unchanged.

Validation PASS: `build-ninja/file1-cadence-check/players01/verification.json`.
Two native clients automatically authenticated, joined one room and started
the Outbreak scenario. Both original interval fields read 0.5 seconds; observed
reliable gameplay packet median spacing was approximately 0.52 seconds on each
client (29 datagrams each in the final 15-second sample). Reciprocal movement
travelled 82.64 and 65.39 game units, with matching settled peer coordinates;
the uninstructed player stayed stationary during each input. Both clients
exited normally with code 0 and no fatal/missing-function/device-loss findings.
An isolated offline launch retained the original 1.0-second field. Temporary
clients and server services were stopped. This is bounded loopback coverage;
Internet jitter/loss and long-session desync reproduction remain untested.
Final File #1 executable SHA-256:
`607980bfd8a7eeadcd073e0f59e386091209676cab542aeb48ac9da7c9e2e923`.
No release was published.

## Connecting with friends

The current implementation uses a separate openSNAP server. Creating an in-game
room does not start that server. The launcher currently configures the server
IPv4 address and username; the automatic provider creates its server account. Room creation and joining remain in
the original menus. Launcher room forms and automatic NAT
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
| TCP | 10128 | Account sign-up (launcher-hosted web service) |
| UDP | 10129 | Host launcher: game discovery and shared randomizer settings |

A joining launcher reads the host's randomizer settings over UDP 10129 before it starts
the game; without that forward it stops with "Could not read the host's randomizer settings".

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
four-client test. Each player has a server account; the new provider creates it automatically.
