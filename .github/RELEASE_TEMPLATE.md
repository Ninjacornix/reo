# RE: Outbreak v1.0.5 prerelease

Source-only server packaging. Python, installed server packages, wheels and server
dependency source archives are removed from the application download. The v1.0.4
single-file launcher startup fix is retained.

## Download and run

Download **RE-Outbreak-v1.0.5-Windows-x64.zip**, extract all files into a **fresh
folder**, and open **Outbreak.Launcher.exe**. Do not copy it over an older release:
that would leave the old Python/vendor files behind. Saves/settings in Local
AppData remain available.

Install **.NET 8 Desktop Runtime (x64)**, a Vulkan-capable GPU driver and the pinned
**LLVM/MinGW UCRT 20251216 x86-64** compiler. Set **REO_LLVM_MINGW** as described in
REQUIREMENTS.md. Provide your own **NTSC-U v2.00 ISO (SLUS-20765)**; first local
compilation takes substantial time and shows progress, elapsed time and a stage
ETA. Later launches use the completed cache. Keep the ISO available.

**build-inputs.zip is required:** it contains independent generation tools and
runtime inputs for compiling your ISO locally. Compression avoids thousands of
loose setup files beside the launcher. It unpacks into Local AppData when needed;
leave the ZIP beside the launcher. It contains no game executable or game assets.

## Hosting requirements

The network-server folder contains server source, setup instructions, its licence,
requirements.txt and a verification manifest. **Python and pip packages are not
bundled.** Only the host needs to install Python 3.12 x64 and run the commands in
network-server/README.md to create the external environment and install
requirements.txt. Then use **Co-op > Host server** normally. Joining friends does
not require Python. The launcher does not install dependencies automatically.

## Notices and developer downloads

There is no top-level LICENSES folder; required third-party licence texts are
combined in **THIRD-PARTY-NOTICES.txt**. Project and dependency source archives are
separate release assets for developers/redistributors, outside the Windows ZIP.
**Players only need the Windows-x64.zip asset.** Checksum files accompany downloads.

## Validation and limits

The launcher compiled without warnings/errors; the extracted single-file package
opened and rendered successfully. The source-only server passed isolated hosting,
account registration and cleanup checks using an externally installed Python
interpreter. This was not a multiplayer game run.

The reference game compilation built all 2,381 units. Complete external-toolchain
first setup and gameplay were not rerun. Rendering, performance, audio and
networking remain experimental. File #2 and Linux are not release targets.
No game executable, BIOS or game assets are included.
