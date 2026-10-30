Run `tools\gs_register_check\run.bat` from a Visual Studio C++ development machine.
It uses the raylib source fetched by the standard SDK build. Alternatively, pass
the raylib source folder as the first argument, including one extracted from the
release dependency-source ZIP.

This checks the actual headless software renderer: CSR initialization, registers
in both privileged address blocks, the highest decoded slot, and all 4 MiB of
VRAM remaining untouched by initialization and register writes. The PNG writer
is the real stb implementation from raylib. No ISO, game code or window is needed.
