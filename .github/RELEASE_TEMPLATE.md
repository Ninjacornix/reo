# RE: Outbreak 1.0 Alpha (v1.0.13) prerelease

<!-- reo:requires-rebuild -->

**The game is built once more after updating** (the launcher asks first; about an hour,
like the first setup).

## Fixes

- **Gameplay runs at full speed.** Builds from v1.0.12 rendered smoothly but the game
  itself advanced only about 9 times per second instead of 30, so everything moved in
  slow motion. Measured now: 29.6 game updates per second.
- **Movies play on graphics cards without an MPEG-2 decoder.** Some cards (for example
  the AMD Radeon RX 9060 XT) have no hardware MPEG-2 video decoder, and the game closed at
  the first movie. Before each launch the launcher now checks the card: movies decode on
  the graphics card when it can, otherwise on the processor. The status line shows which
  one is used.
- **Processor-decoded movies are much faster:** from 4-5 to 27-31 frames per second on a
  Ryzen 5 2600 (2018); the heaviest title-movie scene dips to 23-25. Newer processors
  should keep the full 30.

Tested on a Radeon RX 570 + Ryzen 5 2600 PC: the game built from this release reaches the
title screen and the first room with no errors, with movies decoded on the graphics card
and, forced, on the processor. Not yet tested on a PC without an MPEG-2 decoder.

## First setup

1. Install .NET 8 Desktop Runtime x64 if needed, and keep your Vulkan driver current.
2. Extract RE-Outbreak-v1.0.13-Windows-x64.zip into a new folder and open Outbreak.Launcher.exe.
3. Follow the Play page: choose your own **Outbreak File #1 NTSC-U v2.00 ISO (SLUS-20765)**, then **Build game**.

Keep build-inputs.zip and reo-movie-check.exe beside the launcher. The build takes over an
hour on the test PC and needs about 10 GB of free space. PAL, Japanese, File #2 and
unsupported/modified executable revisions are not supported.
