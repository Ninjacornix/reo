"""Windows long-path handling for the local build.

Without the system-wide long-path setting, Python opens files through the classic
259-character Win32 limit. The build nests up to ~180 characters below the launcher's
data folder, and kit sources nest ~250, so a data folder over ~80 characters failed.
Python therefore works on extended (\\\\?\\) paths, while native tools (LLVM and the
patched recompiler, which handle long ordinary paths themselves) receive ordinary ones.
Extended paths do not treat "/" as a separator: build them only through pathlib.
"""

import re
import sys
from pathlib import Path

_EXTENDED = re.compile(r"\\\\\?\\(UNC\\)?")


def extended(path):
    """An absolute Windows path without the 260-character limit; unchanged elsewhere."""
    text = str(Path(path).resolve())
    if sys.platform != "win32" or text.startswith("\\\\?\\"):
        return Path(text)
    return Path("\\\\?\\UNC\\" + text[2:] if text.startswith("\\\\") else "\\\\?\\" + text)


def native(value):
    """A path or argument for a native tool, with any extended prefix made ordinary.

    Prefixes are replaced wherever they occur, so "-I\\\\?\\C:\\x" and "@\\\\?\\C:\\y.rsp"
    become "-IC:\\x" and "@C:\\y.rsp"."""
    return _EXTENDED.sub(lambda match: "\\\\" if match[1] else "", str(value))
