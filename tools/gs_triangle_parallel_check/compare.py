"""Compare every byte of the two complete-VRAM streams and independent checks."""
import argparse
import re
from pathlib import Path


def cases(log: Path):
    text = log.read_text(errors="replace")
    if "FAIL" in text:
        raise SystemExit(f"Independent oracle failed: {log}")
    rows = re.findall(r"^CASE (\d+) (\S+) hash=([0-9a-f]+)", text, re.M)
    final = re.search(r"cases=(\d+) independent_checks=(\d+) failures=(\d+)", text)
    if not final or int(final[3]) or int(final[2]) < 100 or len(rows) != int(final[1]):
        raise SystemExit(f"Missing checks/cases: {log}")
    return rows


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("directory", type=Path)
    args = parser.parse_args()
    serial = cases(args.directory / "serial.log")
    parallel = cases(args.directory / "parallel.log")
    if [(i, n) for i, n, _ in serial] != [(i, n) for i, n, _ in parallel]:
        raise SystemExit("Case sequences differ")
    width = 4 * 1024 * 1024
    expected = width * len(serial)
    a_path, b_path = args.directory / "serial.vram", args.directory / "parallel.vram"
    if a_path.stat().st_size != expected or b_path.stat().st_size != expected:
        raise SystemExit("Incomplete complete-VRAM stream")
    with a_path.open("rb") as a, b_path.open("rb") as b:
        for i, name, _ in serial:
            original, candidate = a.read(width), b.read(width)
            if original != candidate:
                offset = next(j for j, (x, y) in enumerate(zip(original, candidate)) if x != y)
                raise SystemExit(f"FAIL case={i} name={name} VRAM[{offset:#x}] "
                                 f"serial={original[offset]:02x} parallel={candidate[offset]:02x}")
    print(f"PASS {len(serial)} complete VRAM images identical, {expected} bytes per variant")


if __name__ == "__main__":
    main()
