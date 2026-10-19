#!/usr/bin/env python3
"""Format the project's handwritten core C/C++ and launcher adapter."""

from pathlib import Path
import argparse
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[1]
SCOPES = ("src", "runtime", "game", "media", "network", "launcher/native")
EXCLUDED = {ROOT / "runtime/gs/stb_image_write.h"}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--write", action="store_true", help="Apply formatting; default is check-only")
    args = parser.parse_args()
    formatter = shutil.which("clang-format")
    if not formatter:
        parser.error("clang-format is required (the current style is validated with LLVM 21)")
    files = sorted(
        path
        for scope in SCOPES
        for path in (ROOT / scope).rglob("*")
        if path.suffix in {".c", ".cpp", ".h", ".hpp"} and path not in EXCLUDED
    )
    options = ["-i"] if args.write else ["--dry-run", "--Werror"]
    result = subprocess.run([formatter, "--style=file", *options, *map(str, files)], cwd=ROOT)
    print(f"{'Formatted' if args.write else 'Checked'} {len(files)} handwritten C/C++ files")
    return result.returncode


if __name__ == "__main__":
    raise SystemExit(main())
