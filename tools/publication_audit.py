#!/usr/bin/env python3
"""Reject known private/game-derived publication inputs; not legal clearance."""

import argparse
import json
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]
PRIVATE = re.compile(
    r"(?:^recomp/config/output[^/]*(?:/|$)|"
    r"^tools/parallel_gs_backend/resident_geometry/upstream/shaders/|"
    r"^docs/images/|^docs/title_screen\.png$|"
    r"(?:^|/)[Hh][Aa][Nn][Dd][Oo][Ff][Ff][^/]*\.md$|"
    r"\.(?:iso|elf|bin|exe|dll|obj|lib|pdb|dmp|sfd|adx|irx|ps2|db)$)",
    re.IGNORECASE,
)
OPCODE = re.compile(r"(?im)^\+?\s*//\s*(?:0x)?[0-9a-f]{6,8}:\s*(?:0x)?[0-9a-f]{7,8}\b")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--history", action="store_true", help="Also inspect reachable history paths")
    args = parser.parse_args()
    tracked = subprocess.check_output(["git", "ls-files", "-z"], cwd=ROOT).decode().split("\0")
    findings = []
    for name in filter(None, tracked):
        if PRIVATE.search(name):
            findings.append({"path": name, "reason": "excluded publication path"})
        file = ROOT / name
        if file.is_file() and file.suffix in {".cpp", ".h", ".hpp", ".glsl", ".comp", ".patch"}:
            if OPCODE.search(file.read_text(errors="replace")):
                findings.append({"path": name, "reason": "instruction-by-instruction source requires review"})
    if args.history:
        objects = subprocess.check_output(["git", "rev-list", "--objects", "--all"], cwd=ROOT).decode()
        for row in objects.splitlines():
            _, _, path = row.partition(" ")
            if path and PRIVATE.search(path):
                findings.append({"path": path, "reason": "excluded path in reachable history"})
    print(json.dumps({"passed": not findings, "findings": findings}, indent=2))
    return bool(findings)


if __name__ == "__main__":
    raise SystemExit(main())
