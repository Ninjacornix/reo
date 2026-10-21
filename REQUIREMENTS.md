# Run RE: Outbreak

1. Install **.NET 8 Desktop Runtime (x64)** from
   [Microsoft](https://dotnet.microsoft.com/en-us/download/dotnet/8.0), if needed,
   and keep your GPU's Vulkan driver current.
2. Extract the Windows download and open **Outbreak.Launcher.exe**.
3. Follow the **Play** page: click **Choose ISO** and select your own
   **Outbreak File #1 NTSC-U v2.00 ISO (SLUS-20765)**. A green ✓ confirms it.
4. Click **Build game**, wait for the one-time setup, then click **Play**.

The launcher checks the disc, prepares its build tools and builds the game.
**No compiler installation, environment variables or terminal commands are
required.** The Play page also checks for a Vulkan graphics driver and about
10 GB of free disk space.
PAL, Japanese, File #2 and other executable revisions are currently unsupported.
No PS2 BIOS is needed. Keep the ISO available for game data reads.

## First-time setup

Internet access is needed to download the verified compiler (about 173 MiB),
unless the exact supported compiler is already installed (see below).
The launcher keeps only the Windows x64 tools needed for the game, about 446 MiB,
in Local AppData. Nothing is installed system-wide or added to PATH.
Allow about 1 GB of temporary compiler setup space plus several GB for game data
and compilation. The download, preparation and build show progress and stage
ETAs; setup can be cancelled and retried.

**First compilation still takes substantial time.** Automatic setup removes the
manual steps; it does not eliminate compilation. Completed builds and tools are
cached, so ordinary later launches do not download or compile them again.

Keep build-inputs.zip beside the launcher. It contains required independent
setup inputs and is unpacked automatically; users do not need to open it.

## Co-op

Choose **Host a game** in **Co-op** to host. On first use the launcher prepares a
private server environment in Local AppData: it uses an installed Python 3.12 if
present (otherwise it downloads one) and installs the server packages. Later
starts reuse it. Joining a friend's game needs no setup. Internet hosting still
needs a VPN or forwarded ports; see the README's co-op section.

## Advanced and developer information

The exact supported LLVM/MinGW compiler is detected on PATH and in common Tools
folders. An existing compatible installation may also be selected with
REO_LLVM_MINGW; ordinary users should leave it unset. Automatic setup pins the
20251216 UCRT x86-64 official archive and verifies its SHA-256. The details are in
[local builds](docs/LOCAL_BUILDS.md).

Required third-party notices are in THIRD-PARTY-NOTICES.txt. GitHub's source ZIP/TAR
and the separate dependency-source asset are for developers/redistributors;
ordinary players only need the Windows-x64.zip download.

Compilation adapts parallel work to your CPU and available memory (up to 32 workers
on machines with enough resources). Large source files reserve more memory.
Shared precompiled headers and completed object files are reused, including after
an interrupted build. Progress remains visible on every launcher page; compiler
downloads show transferred MiB, percentage and stage ETA. Python/package setup
shows activity and live status when the installer does not provide a total.

If you already have a compatible completed launcher build, use **Game files > Use
existing build** and choose its reo_recomp.exe. Keep the entire build folder, including local-build.json, DLLs and
the reo-gpu-present shader folder. This skips compiler download and game compilation.
The ISO is still required for game data. A bare EXE, a different game or a build
from an incompatible kit is rejected. Existing local game caches are reused
automatically without needing this button.
