# RE: Outbreak v1.0.7 prerelease

First-time server setup is now automatic. The application download remains small:
server source and requirements.txt are included, but Python/packages are downloaded
into a private Local AppData environment only when hosting is first used.

## ISO compatibility checks

Only **Outbreak File #1 NTSC-U v2.00 (SLUS-20765)** is supported. The launcher now
checks the actual BOOT2 executable from SYSTEM.CNF and its SHA-256 before creating
import files. It shows the detected serial/region and specific rejection reason
beside the ISO controls. PAL, Japanese, File #2, unknown games, missing boot files
and unsupported/modified executables get clear messages. This does not add PAL
or other-region support. Renaming an ISO or changing its VER metadata cannot
establish a supported executable revision.
## Download and run

Download **RE-Outbreak-v1.0.7-Windows-x64.zip**, extract into a fresh folder and run
**Outbreak.Launcher.exe**. Install .NET 8 Desktop Runtime x64, your Vulkan GPU driver
and the pinned LLVM/MinGW compiler described in REQUIREMENTS.md. These game-build
requirements are separate from automatic server setup.

Provide your own NTSC-U v2.00 / SLUS-20765 ISO. The launcher generates/compiles locally
on first import; progress, elapsed time and a stage ETA are shown. Keep your ISO and
build-inputs.zip available. The ZIP contains required independent generation inputs,
compressed to avoid thousands of loose files; it unpacks into Local AppData.

## Hosting

Enable **Co-op > Host server**. Missing Python and server packages are prepared
automatically, then the services start. No manual pip command or administrator
installer is needed. First setup requires Internet access. Progress is shown and
the button becomes **Cancel** while setup runs. Later starts reuse the cached
installation, including offline. Joining friends needs no Python setup.

Downloads use a pinned, SHA-256-verified uv setup tool, managed Python 3.12 and PyPI
packages. Files stay in Local AppData; the application folder, system PATH and
other Python installations are not modified. See network-server/README.md for
cache/log locations and advanced overrides. Normal firewall/router rules still
apply for hosting over the Internet.

## Downloads and notices

Players only need **Windows-x64.zip**. Required third-party licence texts remain
in THIRD-PARTY-NOTICES.txt. Corresponding dependency sources are a separate developer
asset. The duplicate Project-Source.tar download is removed: use GitHub's built-in
**Source code (zip/tar.gz)** for this tag instead. No source archives, compiler,
Python installation, server wheels or vendor packages are inside the application ZIP.

## Validation and limits

Synthetic ISO validation/import checks and a read-only check of the supported reference ISO passed.
Previously verified automatic Python/dependency setup, isolated server/account checks and a
cached restart passed. Final package extraction and launcher window startup passed.
No multiplayer game or complete external-toolchain first setup was rerun. The
reference compilation built all 2,381 units. Rendering, audio, performance and
networking remain experimental. File #2 and Linux are not release targets.
No game executable, BIOS or game assets are included.
