# RE: Outbreak v1.0.9 prerelease

## Changes

- Reuse the exact supported LLVM/MinGW compiler if found on PATH, in common Tools folders, through REO_LLVM_MINGW, or in the launcher's private cache. Incompatible/incomplete toolchains are skipped; missing tools are downloaded automatically.
- Game setup now has a persistent progress panel on every launcher page. Downloads show MiB and percentage; extraction/compilation show counts, stage ETA and cancellation.
- Co-op hosting shows download progress and live Python/package preparation status. An activity bar is used when the installer does not provide an exact total.
- Compilation selects up to four workers based on CPU and available memory. A four-thread PC can use three instead of two when memory allows. Lower concurrency under memory pressure helps avoid paging; no fixed speedup is promised.

## Setup

1. Install .NET 8 Desktop Runtime x64 if needed, and keep your Vulkan graphics driver current.
2. Extract RE-Outbreak-v1.0.9-Windows-x64.zip and open Outbreak.Launcher.exe.
3. Click Game files > Choose ISO and select your own Outbreak File #1 NTSC-U v2.00 ISO (SLUS-20765).
4. Setup runs automatically. Click Play when the build is ready.

No manual compiler installation or environment variable is required. First setup needs Internet access if tools are missing. The compiler download is about 173 MiB, prepared tools use about 446 MiB, and the full game compilation still takes substantial time and several GB of working space. Keep your ISO and build-inputs.zip available.

The unchanged v1.0.6 generation kit preserves completed game caches. Shared precompiled headers and object receipts already reduce repeated work; cancelled builds can reuse completed units. This release does not change game optimization flags or runtime behavior.

Only File #1 NTSC-U v2.00 is supported. PAL, Japanese, File #2 and modified/unsupported executable revisions are rejected with specific ISO errors.

Enable Host server to prepare private Python/packages automatically when needed. Joining friends needs no Python setup. Firewall/router access rules still apply.

## Downloads and validation

Players only need Windows-x64.zip. Required notices are in THIRD-PARTY-NOTICES.txt; optional dependency sources are a separate asset. Project sources use GitHub's source archives. No game executable, BIOS or game assets are included.

Existing compiler discovery/rejection/cancellation checks and launcher self-tests passed. Progress panels were rendered at the minimum window size; final package extraction/integrity and launcher startup were verified. No full game compilation, gameplay or co-op session was rerun; a faster complete game build has not been benchmarked. Rendering, audio, performance and networking remain experimental. Linux and File #2 are not release targets.
