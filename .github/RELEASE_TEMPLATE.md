# RE: Outbreak v1.0.1 prerelease

Experimental Windows x64 preview for **Resident Evil Outbreak NTSC-U v2.00
(SLUS-20765)**. File #2 and native Linux gameplay are not supported release
targets yet.

**Build-only preview:** all 2,381 portable compilation units and linking
completed successfully. The sealed package's first-run launcher flow and
gameplay were not rerun. This is an experimental preview, not a stability claim.

## Setup

1. Download the Windows x64 ZIP and extract the entire folder.
2. Open `Outbreak.Launcher.exe` and select your own ISO in **Game files**.
3. Allow the one-time local generation and compilation to finish. Progress is
   shown in the launcher; later launches reuse the cache.
4. Keep the ISO available for later launches. No BIOS, ISO mounting, Windows
   installer or system compiler installation is required.

Use a Vulkan-capable GPU driver. Do not download a source-code archive expecting
a ready-to-run launcher. The ZIP has a separate SHA-256 checksum asset.

## Included

- Portable launcher and independent local-build tools; no game executable or
  game assets are distributed.
- Display, filtering and antialiasing controls, controller configuration,
  memory-card selection, supported cheats, logs and package updates.
- Experimental native networking with launcher server hosting and account setup.
- Corresponding project/dependency sources and licence notices.

## Known limitations

Rendering, performance and movie/audio synchronization remain experimental.
Networking is still under development; reconnects, transitions and Internet
hosting are not established as fully supported. Room creation remains in-game.
Each player must provide their own supported ISO. There is no built-in VPN.

User settings, imported game data, generated code, saves and local caches remain
outside the portable installation. Report issues with the version, GPU/driver
and relevant redacted launcher logs; do not upload game files or credentials.
