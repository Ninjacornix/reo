# Changelog

## Unreleased

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
