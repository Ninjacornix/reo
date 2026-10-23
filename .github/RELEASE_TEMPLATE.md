# RE: Outbreak 1.0 Alpha (v1.0.16) prerelease

Seeded global item pools, corrected pickup models, expanded experimental enemies, multiplayer randomizer fixes and working cheat options.

<!-- reo:requires-rebuild -->

**The game rebuilds after this update.** Updated runtime headers and original enemy continuation mappings require a new game build. Keep about 10 GB free for the build. Your ISO, imported data and saves are retained.

## Changes

- One **Randomizer** with separate seeded weapon, ammunition and common-item pools across all five File #1 scenarios. Keys, Daylight, the lighter and starting/personal equipment stay fixed.
- Correct pickup model hierarchy and material handling, addressing invisible items and corrupted character/window textures.
- Expand the editable enemy pool to 56 profiles across 19 families. Preserve original scripted families and per-room animation limits; correct crow/wasp flight, G embryo activation and specific large-enemy continuations.
- Joiners adopt the host's seeds, complete pool and exclusions. Build the same enemy plan in spawn-ID order, independent of actor loading order. Keep scripted enemy maximum health consistent when network reconstruction clears an entrance behavior.
- Fix infinite ammunition for ordinary/randomized guns. Add **Unlock everything** for scenarios, difficulties, costumes, NPC characters and collection extras. Saving can keep unlocks.
- Restore controller input for both supported native build toolchains. Show player health on DualSense lights: green, yellow or red, with blue outside gameplay.
- Keep disabled game cards dark and show the running game clearly.

**Verification and limits:** native fixtures, 375 launcher assertions, 60 local-build tests (one skip) and 49 co-op harness tests (one skip) pass. Offline tests covered pickup/equip/firing, health/infection/ammunition cheats, unlock menus and fullscreen bounds. Two native clients connected to a private loopback server shared movement, pickups, ammunition and enemy maximum health. A randomized rocket pickup/equip/fire test also matched the enemy collapse and scripted recovery on both clients. Combat updates can still arrive late during grabs. Later-room mixed-species combat, separate-PC/WAN play, reconnects, save/resume and full scenario completion remain unverified. Randomizer and co-op remain experimental; start a fresh scenario.

## First setup

1. Install .NET 8 Desktop Runtime x64 if needed, and update your Vulkan graphics driver.
2. Extract `RE-Outbreak-v1.0.16-Windows-x64.zip` into a new folder and open `Outbreak.Launcher.exe`.
3. Choose your own **Outbreak File #1 NTSC-U v2.00 ISO (SLUS-20765)**, then **Build game**.

Keep `build-inputs.zip`, `reo-movie-check.exe` and the supplied mod examples beside the launcher. PAL, Japanese, File #2 and unsupported or modified executable revisions are not supported. Game data and precompiled game binaries are not included.

The dependency source download contains the frozen SDK source base; matching additional source patches are under `notices/source-updates` inside `build-inputs.zip`. Players need only the Windows x64 download.
