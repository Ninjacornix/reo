# RE: Outbreak v1.0.8 prerelease

**Compiler setup is automatic.** Open the launcher and choose your supported ISO;
there is no manual LLVM download, compiler extraction, environment variable or
terminal command to run.

## Start playing

1. Install .NET 8 Desktop Runtime x64 if the launcher asks for it, and keep your
   GPU's Vulkan driver current.
2. Download RE-Outbreak-v1.0.8-Windows-x64.zip and extract it into a fresh folder.
3. Open Outbreak.Launcher.exe and click **Game files > Choose ISO**.
4. Select your own **Outbreak File #1 NTSC-U v2.00 ISO (SLUS-20765)**. Import and
   first-time setup start automatically. Click **Play** when the build is ready.

The launcher validates the disc before extraction, downloads the verified compiler
when needed, prepares the Windows x64 tools in Local AppData, and builds the game.
Progress, approximate stage ETAs and cancellation are available. First setup needs
Internet access. The compiler download is about 173 MiB and uses about 446 MiB
once prepared. Allow about 1 GB for temporary tool setup plus several GB for game
files and compilation.

**First game compilation still takes substantial time.** Automatic setup removes
manual steps, not the compilation itself. Completed games and tools are reused;
this release retains the unchanged v1.0.6 build kit so compatible existing game
builds do not need to be recompiled for this launcher update.

Keep your ISO and build-inputs.zip available. The ZIP is unpacked automatically;
users do not need to open it. No compiler is installed system-wide or added to PATH.
Existing compatible REO_LLVM_MINGW configurations remain an advanced optional override.

## Compatibility and co-op

Only File #1 NTSC-U v2.00 is supported. PAL, Japanese, File #2, unrelated games and
unsupported/modified executable revisions receive specific errors beside the ISO
controls. Renaming the ISO does not change compatibility.

Enable **Host server** for local co-op hosting. Missing Python/packages are prepared
automatically in Local AppData on first hosting; cached starts work offline.
Joining friends needs no Python setup. Normal firewall/router rules still apply.

## Downloads and notices

Players only need Windows-x64.zip. Required notices are consolidated in
THIRD-PARTY-NOTICES.txt. Developer source downloads remain separate; use GitHub's
source archives for this tag and the dependency-source asset when needed.
The application ZIP contains no game executable, BIOS or game assets.

## Validation and limits

A clean compiler download, SHA-256 verification, selective extraction, real Windows
C++ compile/resource/archive/link/execute checks, cached reuse and cancellation
passed. Final package startup and extraction/integrity checks passed. The previously
verified ISO checks and automatic server setup are retained.

The complete new ISO-to-gameplay flow and a full game compilation were not rerun.
The earlier reference native build compiled all 2,381 units. Rendering, performance,
audio and networking remain experimental. File #2 and Linux are not release targets.
