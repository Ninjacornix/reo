#!/usr/bin/env python3
"""Format project-owned C/C++ and C# sources, respecting local exclusions."""

from pathlib import Path
import argparse
import fnmatch
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[1]
EXTENSIONS = {".c", ".cc", ".cpp", ".cxx", ".h", ".hh", ".hpp", ".hxx", ".inl", ".inc", ".cs"}


def source_files():
    paths = subprocess.check_output(
        ["git", "ls-files", "--cached", "--others", "--exclude-standard", "-z"], cwd=ROOT
    ).decode().split("\0")
    patterns = [line.strip() for line in (ROOT / ".clang-format-ignore").read_text().splitlines()
                if line.strip() and not line.lstrip().startswith("#")]
    return sorted(ROOT / name for name in set(paths)
                  if name and (ROOT / name).is_file() and Path(name).suffix in EXTENSIONS
                  and not any(fnmatch.fnmatchcase(name, pattern) for pattern in patterns))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--write", action="store_true", help="Apply formatting; default is check-only")
    args = parser.parse_args()
    formatter = shutil.which("clang-format")
    if not formatter:
        parser.error("clang-format is required (the current style is validated with LLVM 21)")
    files = source_files()
    options = ["-i"] if args.write else ["--dry-run", "--Werror"]
    status = 0
    # Keep each invocation comfortably below Windows' command-line length limit.
    for offset in range(0, len(files), 25):
        result = subprocess.run([formatter, "--style=file", *options,
                                 *map(str, files[offset:offset + 25])], cwd=ROOT)
        status = status or result.returncode
    print(f"{'Formatted' if args.write else 'Checked'} {len(files)} project-owned C/C++ and C# files")
    return status


if __name__ == "__main__":
    raise SystemExit(main())
