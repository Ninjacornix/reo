# RE: Outbreak v1.0.10 prerelease

Select a game by clicking anywhere on its card, or using the keyboard. Separate
Select buttons have been removed; Game files remains a separate action.

## Already have a completed build?

In Game files, click **Use existing build** and choose **reo_recomp.exe** from a
compatible completed launcher build. Keep its **entire folder**, including
**local-build.json**, DLLs and the **reo-gpu-present** shader folder. The launcher validates the exact build kit,
game identity, architecture and file hashes before copying it into the local
cache. Compilation is skipped. Source files and the previous ready build are
preserved on failure/cancellation. The selected EXE is not run during validation.

Your supported ISO is still required for game data. A lone EXE or a build from an
incompatible kit is rejected. Existing completed local caches continue to be reused
automatically; you do not need to import them again.

## First setup

1. Install .NET 8 Desktop Runtime x64 if needed, and keep your Vulkan driver current.
2. Extract RE-Outbreak-v1.0.10-Windows-x64.zip and open Outbreak.Launcher.exe.
3. Choose your own **Outbreak File #1 NTSC-U v2.00 ISO (SLUS-20765)** in Game files.
4. Import prepares missing tools and builds automatically. Click Play when ready.

Keep build-inputs.zip beside the launcher. No environment variables or manual
compiler installation are required. Compiler download is about 173 MiB and its
cache uses about 446 MiB. First compilation still needs substantial time and
several GB of working space. PAL, Japanese, File #2 and unsupported/modified
executable revisions are not supported.

Hosting source is bundled; Host server automatically prepares private Python and
packages if missing. Joining needs no Python setup. Normal router/firewall rules
still apply. Game and hosting setup progress/cancellation remain visible.

## Build performance and validation

The unchanged v1.0.6 build kit preserves existing native caches. No game optimization
flags were changed. Two reference compilation units were profiled, not the whole
game: they took 8.750 s and 1.891 s; one spent 4.559 s in register allocation.
Broader generated-code and parallelism changes need separate measurements. See
[build performance](https://github.com/Ninjacornix/reo/blob/v1.0.10/docs/BUILD_PERFORMANCE.md).

Launcher checks include existing-build import/rejection/cancellation and reuse
without invoking a compiler. Play/Game files layouts were rendered. Final ZIP
extraction, hashes and packaged launcher startup passed. No complete game
compilation, gameplay or co-op test was rerun.

Players only need Windows-x64.zip. Dependency sources are a separate optional
asset; project sources use GitHub's source archives. Required notices are in
THIRD-PARTY-NOTICES.txt. No game executable, game assets or BIOS are bundled.
Rendering, performance, audio and networking remain experimental. File #2 and
Linux are not release targets.
