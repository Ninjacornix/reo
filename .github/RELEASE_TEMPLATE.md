# RE: Outbreak v1.0.2 prerelease

Smaller Windows x64 launcher package. The oversized v1.0.1 bundle is withdrawn.

## Install

1. Install **.NET 8 Desktop Runtime (x64)** and your GPU vendor's Vulkan driver.
2. Install/extract the exact **LLVM/MinGW UCRT 20251216 x86-64** toolchain and set
   **REO_LLVM_MINGW** to its folder. See REQUIREMENTS.md in the ZIP or repository.
3. Download **RE-Outbreak-v1.0.2-Windows-x64.zip**, extract, and run Outbreak.Launcher.exe.
4. Select your own **NTSC-U v2.00 ISO (SLUS-20765)**. The first local compilation
   is substantial; elapsed time and an approximate current-stage ETA are shown.
   Later launches reuse the completed cache. Keep the ISO available.

The launcher does not download or install system dependencies. No BIOS is needed.

## Other downloads

- **Server.zip**: optional, only for hosting. Extract beside the launcher to get
  the network-server folder. Joining another host does not require it.
- **Dependency-Sources.zip**: corresponding dependency sources for developers and
  redistribution; ordinary players do not need this asset.
- SHA-256 checksum files accompany the ZIPs.

## Changes

- Framework-dependent single-file launcher: no bundled .NET runtime or language folders.
- No compiler installation inside the application. Required build inputs remain
  compressed until first setup and are extracted into Local AppData.
- Setup verification runs off the UI thread. Sequential ISO reads and buffered
  writes remove per-file forced disk flushes.
- Elapsed time, approximate stage ETA, and cancellable setup progress.

Experimental: the reference game build compiled all 2,381 units successfully;
this revised external-toolchain setup has not had a full game rebuild or gameplay
rerun. Rendering, performance, audio and networking still have limitations.
File #2 and native Linux are not release targets yet. No game executable or
assets are included; game code is generated locally from the user's ISO.
