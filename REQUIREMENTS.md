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

The main download includes compatible openSNAP **source only** under
`network-server/`. Hosting requires a separate **Python 3.12 x64** installation
and the packages in `network-server/requirements.txt`. Follow
[server setup](network/server/SETUP.md), or `network-server/README.md` in the ZIP.
It creates a Python environment under Local AppData; nothing is installed into
the application folder. The launcher checks dependencies before starting services.
Joining a friend's server does not require this setup.

## Compiler setup

Download `llvm-mingw-20251216-ucrt-x86_64.zip` from the official toolchain link
above and extract it once, for example under `C:\Tools`. Set the user environment
variable **REO_LLVM_MINGW** to the extracted folder containing `bin` and
`x86_64-w64-mingw32`. You can use Windows' **Edit environment variables for your
account** dialog, or PowerShell:

```powershell
[Environment]::SetEnvironmentVariable('REO_LLVM_MINGW', 'C:\Tools\llvm-mingw-20251216-ucrt-x86_64', 'User')
```

Adjust that path to your extraction folder. Use this exact toolchain version;
the regular LLVM Windows installer and Visual C++ Redistributable do not replace
its MinGW headers/libraries. Its ZIP SHA-256 is
`2d96a4b758f7f8deaec5065833fe025aa53cfc5f704d0524002510984da0ccf4`.

The compiler is needed for first-time generation and later game-code updates;
completed game builds run from the local cache. First compilation can take a long
time and needs several GB of working space. Extraction and compilation display
separate progress and approximate stage ETAs. Neither the launcher nor the build
worker downloads or installs these system dependencies automatically.

The launcher contains `build-inputs.zip`: required independent generation inputs,
not game data or a compiler installation. It keeps thousands of setup files
compressed instead of cluttering the launcher folder, and unpacks into Local
AppData when needed. Keep it beside the launcher. It is still needed even though
the compiler is installed separately. Project and dependency source archives are
separate release assets for developers and redistributors; players only need the
Windows ZIP. Required third-party licence texts are consolidated into
`THIRD-PARTY-NOTICES.txt` instead of a top-level LICENSES folder.
