# Native co-op playtest harness

This harness isolates up to four native game processes. A single instance can be used for online-menu discovery. Starting windows or observing sockets **does not demonstrate working co-op**. The current script intentionally records `coopVerdict: not-tested`; the network implementation must supply protocol/lobby/gameplay evidence separately.

Requirements: Windows, Python 3.11+, an existing launcher ISO import, the supported NTSC-U v2.00 ISO, a built native executable, its five `reo-gpu-present` SPIR-V files, and the launcher `XINPUT1_4.dll`. No ISO mount, BIOS, compiler, or shared launcher cache is used during tests.

Prepare a fresh session (copies executables/dependencies, validates the imported file sizes and ELF hash, does not run the game):

```powershell
python tools/coop_playtest/coop_playtest.py prepare --players 2 --session build-ninja/coop-playtest/run001
```

Optional paths: `--exe`, `--iso`, `--import-root`, `--adapter`, `--root`. The default import is discovered from the launcher settings/cache. Game assets and ISO are shared read-only inputs; each player gets a private working directory, empty folder-backed memory card, controller map, executable/dependencies and stdout/stderr files. Existing user saves are never copied or modified. Prepared sessions cannot be overwritten or rerun.

Run the prepared copies for a bounded duration:

```powershell
python tools/coop_playtest/coop_playtest.py run --session build-ninja/coop-playtest/run001 --seconds 180
```

Remove `--seconds` to run until exit or Ctrl+C. Optional `--route main-menu` uses the native build's existing menu test route and stops its automation there. Current native builds also support diagnostic `--route network-connect`, `--route network-account` and `--route network-login`: these steer ordinary pad input through the original network profile/account/login menus. They are not a proof of authentication or connected multiplayer. The supervisor publishes independent neutral controllers even when windows are unfocused; it never injects keyboard events into the desktop. Input can be supplied from another terminal:

```powershell
python tools/coop_playtest/coop_playtest.py input --session build-ninja/coop-playtest/run001 --player 1 --buttons cross --hold 0.2
python tools/coop_playtest/coop_playtest.py status --session build-ninja/coop-playtest/run001
python tools/coop_playtest/coop_playtest.py capture --session build-ninja/coop-playtest/run001 --player 1 --output captures/menu.png
python tools/coop_playtest/coop_playtest.py stop --session build-ninja/coop-playtest/run001
```

`capture` validates executable path, PID creation time and HWND ownership before/after reading the desktop client rectangle. It writes PNG plus a JSON receipt inside the session. Occluding windows can appear in desktop captures. Optional `--foreground` requests focus, and `--position 40 40` moves only the owned game window to avoid an overlapping dialog; neither sends controller/keyboard input. Minimized windows are refused. Capture never relaxes another tool's process whitelist.

For the original game's USB-keyboard login UI, newly prepared sessions have a private keyboard queue and `REO_COOP_KEYBOARD_FILE` environment binding. The native service must support this hook; old immutable sessions remain usable without it. Use dummy test credentials:

```powershell
python tools/coop_playtest/coop_playtest.py text --session build-ninja/coop-playtest/run001 --player 1 --text reo01
```

The optional `--enter` appends an Enter down/up pair. Empty text with `--enter` sends only Enter; empty text without it is rejected. Text is otherwise limited to 1..255 printable ASCII characters and converted to US-layout USB boot-keyboard reports (down then release for every character). It never injects OS keyboard events. Binary format: little-endian `u32 magic=0x52454F4B`, `u32 sequence`, `u32 reportCount`, then 8 bytes per report, at most 512 reports. Each queue is atomically replaced only after `<keyboard.bin>.ack` contains the previous decimal sequence. The service writes that acknowledgement only after consuming every report; even the initial sequence-0 empty queue needs service acknowledgement before text can be sent. CLI output says queued, not delivered. Pending reports cannot be overwritten; writers are serialized with an exclusive private lock file. Queue files contain dummy typed text as USB reports, so do not use real account passwords in captured test sessions.

Shifted characters use separate modifier edges: Shift-only, Shift+key, Shift-only key release, then neutral. The original EE keyboard driver suppresses simultaneous modifier/key changes, so the simpler two-report form loses uppercase letters. Mixed-case passwords and shifted symbols use the four-report form; lowercase is unchanged. The 512-report queue bound still applies, so an all-uppercase batch with Enter can contain at most 127 characters. This does not bypass the original text field's own character restrictions.

Optional `--replace` on `text` or `drive-login` sends End followed by 15 Backspace down/up pairs before typing. Use it only in the initialized original password editor (maximum 15 characters); it is not a general clear-field command. Queue acknowledgement means the USB reports were consumed, not that the editor accepted them. The original editor ignores input during its eight-update initialization delay; native `password-input-ready` must observe that delay begin and finish before the driver queues anything. A timer or simply reaching step 46/substep 11 is insufficient.

Buttons: up/down/left/right, cross/circle/square/triangle, start/select, l1/r1/l3/r3. Analog input is also available by atomically replacing the player's `input.json`: `buttons` list, `lx/ly/rx/ry` integers -32767..32767, `lt/rt` 0..255, and optional `expiresUnix`. The supervisor republishes at about 60 Hz. Expired or malformed commands produce neutral input. Control maps have distinct names per player/session; they follow the launcher's existing 32-byte ABI. A stalled supervisor causes the bridge to neutralize input after 500 ms.

The native pad feeder normally requires the game to own the foreground window. Current network builds support `REO_COOP_TEST_INPUT=1` with an existing private controller map for background test instances. This uses the controller-only path and retains the foreground restriction for global keyboard polling. Older builds without this opt-in require foreground focus.

Optional `run --config config.json` supplies the current native network bridge configuration. For two clients of a separately running local compatible openSNAP server:

```json
{
  "environment": {
    "REO_COOP_HOST": "127.0.0.1",
    "REO_COOP_PLATFORM_AUTH": "native",
    "REO_COOP_TEST_INPUT": "1"
  },
  "players": [
    {"environment": {"REO_COOP_USERNAME": "reo01"}},
    {"environment": {"REO_COOP_USERNAME": "reo02"}}
  ]
}
```

Both players are game clients; this harness does not implement a peer-to-peer host or start a server. Use registered test accounts and the original password UI. Username selection through the native account provider is not server authentication. Native transport/RPC support and original HTTP account cleanup are still under active development, so an address/username configuration or successful HTTP response does not imply a working lobby or synchronized gameplay. Optional per-player `REO_COOP_TRACE_FILE` paths can capture the native bridge's protocol diagnostics under each private log directory. Core ISO/card/controller/keyboard paths are protected. All inherited `REO_*` variables are stripped, then known launcher-equivalent normal-speed/GPU settings are set. No diagnostic route is forced unless `--route` or `REO_TEST_ROUTE` is explicitly supplied.

## Original login automation

For a future prepared session, start the native `network-login` route in the supervisor and run the driver from another terminal:

```powershell
python tools/coop_playtest/coop_playtest.py run --session build-ninja/coop-playtest/run001 --config config.json --route network-login --seconds 300
python tools/coop_playtest/coop_playtest.py drive-login --session build-ninja/coop-playtest/run001 --password DISPOSABLE_TEST_PASSWORD --timeout 240
```

The password must be 4–15 printable ASCII characters and belong to disposable local test accounts. It is supplied on the command line, so it can appear in shell history/process arguments; never use a real password. Alternatively, `--password-file private-test-passwords.json` reads a JSON object mapping player numbers to disposable passwords (`"1"`, `"2"`, etc.). That file is not copied into receipts. Repeat `--player 1 --player 2` to select clients; otherwise all launched players, at most four, are driven.

The driver waits for each original route's `[TEST-ROUTE] password-input-ready` line, verifies the native process's executable/PID/creation identity, and queues the private USB password plus Enter exactly once. It retries acknowledgement backpressure without overwriting pending reports. Native route automation submits original Entry only after the original password store is populated, then emits `[TEST-ROUTE] login-submitted` and disables itself. The driver records queued/acknowledged/submitted states in a new `drive-login.json`; **submission is not authentication**, and `coopVerdict` remains `not-tested`.

Readiness timeout, exited/replaced processes, fatal native diagnostics and queue failures stop input for that player. The timeout is bounded to 1–900 seconds. If submission was already logged before the driver queued anything, no password is typed. One driver receipt is permitted per immutable session; reruns refuse possible credential replay after an interrupted or completed driver. No plaintext password is written to the driver receipt or output. Mock tests exercise four clients, exactly-once accepted queues, identity checks, acknowledgement backpressure and failure/timeout paths without running a game.

Receipts:

- `session.json`: source executable hash, copied dependency hashes, all player paths and unique map names.
- `run.json`: actual PID/creation-time/image identity, arguments, effective `REO_*` environment, elapsed wall time, exit codes and errors. A private run is never claimed to be connected multiplayer.
- `nativeResults` in new run receipts classifies explicit fatal guest-function/crash/graphics-backend/account-provider diagnostics independently of process exit code. Account-provider `Cannot`, `Invalid` and `Original account helper did not return` failures count even when the process exits 0; a normal `Launcher account selected` message is not fatal and does not prove authentication. A clean exit is only `exited-no-fatal-diagnostic`, never proof of co-op. Duration/interrupt cleanup records `supervisor-stopped` separately from natural exits. Already-exited processes are detected before querying their image and are not cleanup failures.
- `playerN/logs/stdout.log` and `stderr.log`: direct file output, so UI/pipe backpressure cannot block native threads.
- `endpoints.jsonl`: every two seconds, Windows IP Helper TCP connections/listeners and UDP bound endpoints for these PIDs only, IPv4 and IPv6. This is endpoint observation, **not packet payload capture or bandwidth measurement**. No global capture driver, firewall change or unrelated process capture is performed.

Stop verifies both executable path and creation time on the same OS handle used to terminate. Reused PIDs/different executables are refused. Only the harness's own processes are stopped. Stop is forced rather than a save/quit route; test cards are disposable private folders and no save continuity is claimed. All sessions/artifacts should be placed under ignored `build-ninja/`; the script never removes them.

After `network-login` has submitted through the original UI, the bounded lobby driver can steer the verified menu gates:

```powershell
python tools/coop_playtest/coop_playtest.py drive-lobby --session build-ninja/coop-playtest/run001 --goal shared-area --timeout 240
python tools/coop_playtest/coop_playtest.py drive-lobby --session build-ninja/coop-playtest/run001 --goal waiting-room --timeout 300 --press-limit 100
```

`shared-area` stops on the original area-01 room list. `waiting-room` creates the dummy room `cooptest` with four places, holds guests outside the area until the host room exists, and selects the native-tested Mark/Jim/George options for players 2–4. It reads RAM through a read-only handle with ELF signature and process identity checks; input is ordinary private pad/USB reports. Unknown UI states wait until the bounded timeout, ambiguous room/server records are refused, and existing title text is preserved. The title keyboard must expose its real initialization delay before typing. Each goal writes a new exclusive receipt; an interrupted goal is not silently replayed.

The driver never presses host Start. UI member counts alone do not prove server membership: receipts explicitly retain `serverMembershipVerified=false`, `hostStartSent=false` and `coopVerdict=not-tested`. Actual fresh server roster/query receipts must be checked separately before starting gameplay. This driver has mock/source tests; no live automation run is implied by those checks.

`stop` records a separately owned stop request after checking the identity on the terminating handle. The supervisor recognizes only confirmed termination with the same PID, image, creation time and requested exit code as `operator-stopped`; a different crash code or any fatal native diagnostic remains a failure. Previous immutable run receipts are not rewritten to change historical classification.

During native gameplay, capture the original four actor slots without sending input:

```powershell
python tools/coop_playtest/coop_playtest.py snapshot-actors --session build-ninja/coop-playtest/run001 --label before-move
python tools/coop_playtest/coop_playtest.py snapshot-actors --session build-ninja/coop-playtest/run001 --label after-move
```

This reuses the owned PID/image/creation checks and ELF-signature RAM locator with a read-only process handle. Each player receipt records the original local slot, four actor headers, active/state bytes, XYZ, yaw and animation frame from the verified NTSC-U layout. Labels are bounded ASCII filenames; `actors-<label>.json` is exclusively created and never replaced, including failed captures. Non-finite actor fields or invalid local indices fail visibly. Reads across processes are sequential observations, not an atomic simulation snapshot or a multiplayer verdict. Compare them with fresh protocol/server evidence; this command never moves a player, starts a session or forces synchronization.

To inspect an older immutable run without rewriting its receipt:

```powershell
python tools/coop_playtest/coop_playtest.py diagnostics --session build-ninja/coop-playtest/run001
```

Script-only validation (no native game launched):

```powershell
python -m unittest discover -s tools/coop_playtest -p 'test_*.py' -v
```

Tests cover independent mapped controller state/ABI, PID reuse protection using an owned temporary Python child, IPv4/IPv6 endpoint attribution using owned test sockets, path confinement, atomic input files and environment isolation. These tests are infrastructure checks, not a co-op test.

Optional capture integration: set `REO_COOP_CAPTURE_TEST_SESSION` to a live session before running the tests. It captures only that session's first validated owned game window without moving/focusing it and verifies PNG dimensions, chunk CRCs and decoded pixel length. This leaves screenshot receipts under the session's `captures/` folder. Without that environment variable, the integration case is skipped.
