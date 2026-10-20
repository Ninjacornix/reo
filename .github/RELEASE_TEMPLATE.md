# RE: Outbreak v1.0.4 prerelease

Windows x64 launcher with the local co-op server included. Replaces the withdrawn
v1.0.3 download. The compiler and .NET runtime remain separately installed requirements.

## Startup fix

Fixes the error **System.Windows.Baml2006.TypeConverterMarkupExtension** when
opening the single-file launcher. The icon is now loaded from the embedded
resource without conflicting external WPF content metadata. The extracted
release was opened and rendered from a different working directory.

## Install

1. Install **.NET 8 Desktop Runtime (x64)** and your GPU vendor's Vulkan driver.
2. Extract **LLVM/MinGW UCRT 20251216 x86-64** and set **REO_LLVM_MINGW** to its
   folder. See REQUIREMENTS.md in the ZIP or repository for links and commands.
3. Download **RE-Outbreak-v1.0.4-Windows-x64.zip** and extract **all files** into
   a fresh folder. Open **Outbreak.Launcher.exe** directly inside that folder.
4. Select your own **NTSC-U v2.00 ISO (SLUS-20765)**. First local compilation takes
   substantial time; elapsed time and a current-stage ETA are shown. Later
   launches reuse the completed cache. Keep your ISO available.

The archive uses relative paths with standard ZIP separators. The launcher is
at the top level, with its required subfolders alongside it. Extract the ZIP;
do not run the launcher from the archive viewer or flatten its folders.

## Co-op

The **network-server** folder is included in the main download, with its Python
runtime and dependencies. Enable **Host server** in Co-op to host. No additional
server download or Python installation is needed. Joining another host uses the
same launcher. Internet hosting still needs a reachable address and the documented
firewall/router rules.

## Other downloads

**Dependency-Sources.zip** contains corresponding dependency sources for developers
and redistributors. Ordinary players only need the **Windows-x64.zip** download.
SHA-256 checksum files accompany the ZIPs. No compiler or .NET runtime is bundled.

## Upgrading

Download this release manually and extract into a fresh folder when upgrading from
v1.0.1, v1.0.2 or v1.0.3. Saves and settings in Local AppData are preserved. Previous binary
downloads remain withdrawn.

Experimental: frontend compilation and archive extraction/integrity checks passed.
The reference game build compiled all 2,381 units; the revised external-toolchain
first setup and gameplay have not had a full rerun. Rendering, performance, audio
and networking still have limitations. File #2 and native Linux are not release
targets. No game executable, BIOS or game assets are included.
