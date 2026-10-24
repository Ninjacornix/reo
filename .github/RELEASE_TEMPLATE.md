# RE: Outbreak 1.0 Alpha (v1.0.17) prerelease

Sharper rendering, an optional performance counter, audio controls, controller rumble and randomizer fixes.

<!-- reo:requires-rebuild -->

**The game rebuilds after this update.** Updated runtime inputs require a new game build. Keep about 10 GB free for the build. Your ISO, imported data and saves are retained.

## Changes

- Add **Native / 2× internal resolution** in Graphics. File #1 renders at 1024×896 at 2×, independently of the fullscreen/window resolution. Retain GPU command checkpoints as an RX 570 stability workaround.
- Add **Show performance counter** in Graphics: display FPS, average frame time and game updates/sec appear in the top-right corner. The saved toggle applies on the next launch. Original 30 Hz gameplay and 60 Hz display pacing remain unchanged.
- Add saved **Master, Music, Sound effects, Voice and UI volume** sliders, with live updates and a reset button. Cinematic sound follows Master volume.
- Add native game-driven **controller rumble**, including DualSense support, and a saved on/off switch in Controls.
- Hide the mouse over the focused fullscreen game and restore it when switching apps or returning to a window.
- Roll a fresh 32-bit randomizer seed on every solo/host launch. Joining players continue to adopt the host's seed and pools. Progression items remain fixed; weapons, ammunition and common items use separate pools.
- Load missing randomized weapon motions, fixing grenade launcher ready poses and shots that consumed ammunition without completing.
- Remove the extra Mods introduction and cheat descriptions. Keep the first four readiness checks on Play.

**Verification and limits:** 445 launcher assertions, 14 performance-meter cases and 465 actual audio-mixing cases pass. Local tests cover startup and the first Outbreak room, 2×/Native, fullscreen, SMAA/direct presentation, counter on/off, live volume controls, cursor hiding and randomized grenade launcher firing. Active fullscreen 2× gameplay measured about 29.98 updates/sec. Changed native code was compiled against verified frozen inputs while unchanged game/SDK objects were reused; a complete cold first-run compilation was not repeated. The RX 570 fix is a tested compatibility workaround, with the underlying driver/ordering issue unresolved. This release does not add new multiplayer validation: the previous loopback results and limitations still apply. Separate-PC/WAN play, later-room mixed-species combat, reconnects, save/resume and full scenario completion remain unverified. Start a fresh scenario for the randomizer.

## First setup

1. Install .NET 8 Desktop Runtime x64 if needed, and update your Vulkan graphics driver.
2. Extract `RE-Outbreak-v1.0.17-Windows-x64.zip` into a new folder and open `Outbreak.Launcher.exe`.
3. Choose your own **Outbreak File #1 NTSC-U v2.00 ISO (SLUS-20765)**, then **Build game**.

Keep `build-inputs.zip`, `reo-movie-check.exe` and the supplied mod examples beside the launcher. PAL, Japanese, File #2 and unsupported or modified executable revisions are not supported. Game data and precompiled game binaries are not included.

The dependency source download contains the frozen SDK source base; matching additional source patches are under `notices/source-updates` inside `build-inputs.zip`. Players need only the Windows x64 download.
