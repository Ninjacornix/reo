# Multiplayer: optional OBSRV community server

Branch `feature/multiplayer-obsrv`. The launcher's Co-op page is renamed **Multiplayer**.
Besides Play alone, Host a game and Join a game (account-free, unchanged and still the
default), a fourth mode **OBSRV server** connects the game to the OBSRV community server.

## What the mode does

- The player enters the OBSRV server address (IPv4 or host name). A host name is resolved
  to IPv4 at launch (`OnlineOptions.ResolveServer`).
- Launch environment: `REO_COOP_HOST=<address>`, `REO_COOP_PLATFORM_AUTH=native`,
  `REO_NETCODE=auto`. Nothing else: no `REO_COOP_AUTO_ACCOUNT`, no player name, no password,
  no local server.
- The player signs in at the game's own network screens with their own OBSRV account,
  registered on OBSRV's website. The launcher never asks for, stores or sends OBSRV
  credentials, and nothing bypasses OBSRV's authentication.
- Online rules apply as for Host/Join (no asset packs, online cheat checks); game logic
  stays at 30 Hz.

## Verified (2026-11-19)

- Launcher regression tests: 2032 passed, including 21 OBSRV checks (address validation,
  host-name resolution to IPv4, the exact launch environment, no credentials exported,
  30 Hz online).
- Headless UI check: 285 checks on 12 pages passed, including selecting OBSRV mode (only
  its panel shows) and entering an address (saved, mode configured).
- Game side (File #1 build `file1-ready-v50`, local openSNAP server standing in for the
  community server, OBSRV launch environment): Network Game opens the game's original
  screens. "Starting a network game…" notice, then on a fresh card "No NET file has been
  found… your login name… Will you create new file?", that is, the original sign-in flow
  rather than the launcher's automatic account. Captures in ignored
  `build-ninja/hybrid/obsrv-signin4`, `obsrv-signin5`.

## Not verified

- Signing in to the real OBSRV server. OBSRV is operated by its community and its guides
  target the Japanese editions; whether its server accepts these US editions (SLUS-20765,
  SLUS-20984) is unknown. No OBSRV account was created and the live server was not
  contacted. The Multiplayer page states this.
