# Run RE: Outbreak

1. Install **.NET 8 Desktop Runtime (x64)** from
   [Microsoft](https://dotnet.microsoft.com/en-us/download/dotnet/8.0), if needed,
   and keep your GPU's Vulkan driver current.
2. Extract the Windows download and open **Outbreak.Launcher.exe**.
3. In **Game files**, click **Choose ISO** and select your own
   **Outbreak File #1 NTSC-U v2.00 ISO (SLUS-20765)**.

Import starts automatically. The launcher checks the disc, downloads/prepares
its build tools, and builds the game. **No compiler installation, environment
variables or terminal commands are required.** When setup finishes, click Play.
PAL, Japanese, File #2 and other executable revisions are currently unsupported.
No PS2 BIOS is needed. Keep the ISO available for game data reads.

## First-time setup

Internet access is needed to download the verified compiler (about 173 MiB).
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

Enable **Host server** to host. Missing Python/server packages are downloaded and
prepared automatically in Local AppData on first use. Later starts reuse the
cache. Joining a friend's server does not require that setup. Internet hosting
still needs reachable addressing and firewall/router rules.

## Advanced and developer information

The exact supported LLVM/MinGW compiler is detected on PATH and in common Tools
folders. An existing compatible installation may also be selected with
REO_LLVM_MINGW; ordinary users should leave it unset. Automatic setup pins the
20251216 UCRT x86-64 official archive and verifies its SHA-256. The details are in
[local builds](docs/LOCAL_BUILDS.md).

Required third-party notices are in THIRD-PARTY-NOTICES.txt. GitHub's source ZIP/TAR
and the separate dependency-source asset are for developers/redistributors;
ordinary players only need the Windows-x64.zip download.

Compilation uses up to four parallel workers, selected from CPU and available memory.
Shared precompiled headers and completed object files are reused, including after
an interrupted build. Progress remains visible on every launcher page; compiler
downloads show transferred MiB, percentage and stage ETA. Python/package setup
shows activity and live status when the installer does not provide a total.
