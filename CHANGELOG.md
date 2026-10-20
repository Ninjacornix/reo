# Changelog

## v1.0.3 prerelease — 2026-10-20

- Include the local co-op server and its required Python runtime in the main download.
- Write ZIP entries as relative paths with standard `/` separators and place the
  launcher at the archive root, without an enclosing package-name folder.
- Keep .NET and the compiler external; no separate server download is needed.
- Withdraw v1.0.2 and require the bundled server files during update validation.

## v1.0.2 prerelease — 2026-10-20

- Move local-build verification and cached-output hashing off the launcher UI
  thread so setup does not block rendering or cancellation.
- Document end-user dependencies for a smaller package without automatic
  dependency downloads.
- Publish a framework-dependent single-file launcher, compressed first-run
  inputs, and separate optional hosting/dependency-source assets.
- Add elapsed time and approximate stage ETAs; use sequential ISO reads and
  buffered writes without a forced disk flush after every extracted file.
- Withdraw the oversized v1.0.1 download while replacement packaging is prepared.

## v1.0.1 prerelease — 2026-10-20

- Prepare v1.0.1 metadata and GitHub prerelease update discovery, preserving
  the stable update channel for stable installations.
- Align portable packaging/setup instructions, add a release notes template,
  and preserve existing dependency files during setup.
- Portable first-run build tooling generates game code from the user's ISO.
  All 2,381 units compiled and linked; the package is a build-only preview
  without a repeated packaged setup/gameplay run.
- Launcher-managed local server hosting, account creation and automatic native
  login, with user-scoped credential storage.
- GPU movie decoding enabled for normal launches and co-op playtests.
- Faster isolated login/lobby/scenario drivers; two clients reached the first
  room in the latest local retest. Further network behavior remains experimental.
- Original application icons and immutable per-runtime launcher caches.
- Native Linux launcher and Vulkan portability foundations, not a playable
  Linux release.

## v1.0.0 prerelease — 2026-10-19

Withdrawn: the former downloadable game executable contained game-derived code.
The following describes the historical package, not a currently available download.

- Downloadable Windows x64 package; official cover art and current launcher screenshots.
- Main README includes first-run ISO and co-op joining/hosting instructions.
- One-time ISO import without mounting and self-contained Windows packaging.
- Fullscreen switching, aspect/fit modes, texture and anisotropic filtering,
  FXAA/SMAA, brightness/gamma preview and direct logo skipping to PRESS START.
- Folder-backed PS2 memory-card selection, built-in cheats and compatible PCSX2
  data-cheat imports.
- GitHub release checks and verified package updates with rollback.
- Launcher Co-op server and username settings, native SN/ACCESS transport and
  original account authentication through a separate openSNAP server.
- Four-client local room, scenario and movement verification; original SDK
  clocks now advance using monotonic host time in native online mode.
- A separately licensed openSNAP patch for File #1 current-room roster queries.
- Bounded login/lobby automation and read-only actor snapshots for playtesting.

Room creation remains in-game. Launcher hosting/room management, item sharing,
door transitions, reconnects and LAN/WAN behavior are not validated release
features. File #2 and mods remain placeholders. The full native source build
still needs local game-code generation and matching graphics dependencies.

## v0.1 — 2026-10-19

Developer preview of the launcher and public-source layout.

- Standalone Windows launcher with game selection, settings, input remapping, save backups and logs.
- Original GPLv3 background artwork; no bundled game covers or custom app icons.
- Console-free game launch, smoother submenu transitions and separate game configurations.
- GPLv3 licensing with upstream/dependency notices, contribution guidance and formatting rules.
- Generated game code, private notes and captures excluded from the current source tree.

Gameplay and GPU integration remain experimental. File #2, online co-op, mods, cheats, intro skipping and automatic update installation are not validated release features. Ongoing local gameplay/runtime work is separate from this cleanup commit. Historical commits still require review before publishing a formerly private repository.
