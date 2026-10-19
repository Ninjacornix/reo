#!/usr/bin/env python3
"""Check the current Git index for ignored files and publication essentials."""

from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[1]
REQUIRED = ("README.md", "LICENSE", "NOTICE.md", "CONTRIBUTING.md", ".gitignore", ".clang-format")


def main():
    ignored = subprocess.check_output(
        ["git", "ls-files", "-ci", "--exclude-standard", "-z"], cwd=ROOT
    ).decode().split("\0")
    problems = [f"Ignored file still tracked: {path}" for path in ignored if path]
    problems += [f"Missing publication file: {name}" for name in REQUIRED if not (ROOT / name).is_file()]
    for problem in problems:
        print(problem)
    if problems:
        return 1
    print("Repository index checks passed (history and licensing require separate review)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
