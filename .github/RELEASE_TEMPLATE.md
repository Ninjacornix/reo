# RE: Outbreak 1.0 Alpha (v1.0.14) prerelease

A launcher update. **The game is not built again** if you already built it with v1.0.13;
coming from v1.0.12 or older, the one rebuild from v1.0.13 still applies.

## New

- **Graphics > Movies > Decode movies on the graphics card.** The launcher checks your
  graphics card when it opens. If the card has a hardware MPEG-2 decoder, the box is on
  and you can turn it off to decode movies on the processor instead. Without a decoder
  (for example the AMD Radeon RX 9060 XT) the box is greyed out, the reason is shown, and
  the processor decodes movies.

Everything from v1.0.13 is included: full-speed gameplay (30 game updates per second),
movies on graphics cards without an MPEG-2 decoder, and much faster processor-decoded
movies.

## First setup

1. Install .NET 8 Desktop Runtime x64 if needed, and keep your Vulkan driver current.
2. Extract RE-Outbreak-v1.0.14-Windows-x64.zip into a new folder and open Outbreak.Launcher.exe.
3. Follow the Play page: choose your own **Outbreak File #1 NTSC-U v2.00 ISO (SLUS-20765)**, then **Build game**.

Keep build-inputs.zip and reo-movie-check.exe beside the launcher. The build takes over an
hour on the test PC and needs about 10 GB of free space. PAL, Japanese, File #2 and
unsupported/modified executable revisions are not supported.
