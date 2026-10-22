# RE: Outbreak 1.0 Alpha (v1.0.15) prerelease

One **Randomizer** mod now randomizes ordinary items, guns, ammunition and supported enemy spawns together. Practice Mode and the overlapping randomizer samples have been removed.

<!-- reo:requires-rebuild -->

**The game rebuilds after this update.** The Randomizer needs updated native runtime files. Runtime headers changed, so all game units compile again; allow over an hour on slower PCs and about 10 GB of free space. Your ISO, imported data and saves are retained by the update.

## Changes

- Import `examples/mods/randomizer.json` on the Mods page, then enable **Randomizer**. Existing sample installations migrate automatically to one entry, preserving combined seeds and enemy profiles. Original sample JSON files remain recoverable under `retired-samples` in the mods folder.
- Randomize supported zombie, Cerberus, licker and hunter encounters. Original scripted entrances finish before species replacement, and choices persist across rooms.
- Hosts publish randomizer seeds, item exclusions and enemy profiles to joining players. An optional native asset bank provides space for the additional enemy resources.
- Keep personal equipment and scenario keys unchanged. Ordinary items retain their original quantities.

**Experimental:** start a fresh File #1 scenario. Full scenario completion, save/resume compatibility and mixed-enemy co-op gameplay remain unverified. Host-to-guest settings transfer is tested separately from native multiplayer gameplay.

## First setup

1. Install .NET 8 Desktop Runtime x64 if needed, and keep your Vulkan driver current.
2. Extract `RE-Outbreak-v1.0.15-Windows-x64.zip` into a new folder and open `Outbreak.Launcher.exe`.
3. Follow the Play page: choose your own **Outbreak File #1 NTSC-U v2.00 ISO (SLUS-20765)**, then **Build game**.

Keep `build-inputs.zip`, `reo-movie-check.exe` and the supplied mod examples beside the launcher. PAL, Japanese, File #2 and unsupported or modified executable revisions are not supported. Game data and precompiled game binaries are not included.

The dependency source download contains the frozen SDK source base; matching additional source patches are included under `notices/source-updates` inside `build-inputs.zip`. Ordinary players need only the Windows x64 download.
