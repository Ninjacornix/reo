# End-user requirements

For the smaller, dependency-based Windows package:

- **Windows 10 or 11, 64-bit.**
- **.NET 8 Desktop Runtime, x64** — install the Windows Desktop Runtime from
  [Microsoft](https://dotnet.microsoft.com/en-us/download/dotnet/8.0).
  The SDK and ASP.NET runtime are not required to run the launcher.
- **A Vulkan-capable graphics card and its current vendor driver.**
- **Your own Outbreak NTSC-U v2.00 ISO (SLUS-20765).** Keep it available after import.
- **LLVM/MinGW UCRT 20251216, x86-64**, for the one-time local game compilation:
  [official toolchain](https://github.com/mstorsjo/llvm-mingw/releases/tag/20251216).
  This is a compiler and includes its own headers and libraries; it is not a
  graphics driver or a small Visual C++ runtime redistributable.

No PS2 BIOS is required. Ordinary offline play and joining another player's
server do not require a Python installation or a local server.

Hosting requires a compatible openSNAP server. Its dependencies are separate
from normal play and are only needed by the host.

The slim package is being prepared. The withdrawn v1.0.1 archive bundled these
tools and a self-contained .NET runtime; this document does not make those files
optional inside that old archive. Installation of the compiler alone also does
not replace the project's required local generation inputs.
