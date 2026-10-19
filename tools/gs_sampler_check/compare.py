"""Exact complete-VRAM and direct channel output oracle; summarize measured time."""
import argparse
from pathlib import Path
import re
import statistics


def read_log(path):
    text = path.read_text(errors="replace")
    if "FAIL" in text:
        raise SystemExit(f"Independent oracle failed: {path}")
    numeric = re.search(r"NUMERIC checks=(\d+) failures=(\d+) hash=([0-9a-f]+)", text)
    summary = re.search(r"cases=(\d+) independent_checks=(\d+) failures=(\d+)", text)
    rows = re.findall(r"^CASE (\d+) (\S+) hash=([0-9a-f]+)", text, re.M)
    bench = re.findall(r"^BENCH round=(\d+) triangles=(\d+) us=(\d+) hash=([0-9a-f]+)", text, re.M)
    if not numeric or int(numeric[2]) or int(numeric[1]) < 37000:
        raise SystemExit(f"Missing numeric checks: {path}")
    if not summary or int(summary[3]) or int(summary[2]) < 129 or len(rows) != 79:
        raise SystemExit(f"Missing complete-VRAM checks: {path}")
    return numeric, rows, bench


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("directory", type=Path)
    args = parser.parse_args()
    a, b = (read_log(args.directory / f"{v}.log") for v in ("baseline", "candidate"))
    if tuple(a[0].groups()) != tuple(b[0].groups()) or a[1] != b[1]:
        raise SystemExit("Numeric/case sequences or output hashes differ")
    width = 4 * 1024 * 1024
    for variant in ("baseline", "candidate"):
        if (args.directory / f"{variant}.vram").stat().st_size != width * len(a[1]):
            raise SystemExit("Incomplete full-VRAM stream")
    with (args.directory / "baseline.vram").open("rb") as left, (args.directory / "candidate.vram").open("rb") as right:
        for i, name, _ in a[1]:
            x, y = left.read(width), right.read(width)
            if x != y:
                offset = next(j for j, pair in enumerate(zip(x, y)) if pair[0] != pair[1])
                raise SystemExit(f"FAIL VRAM case={i} name={name} offset={offset:#x}")
    x = (args.directory / "baseline.vram.numeric").read_bytes()
    y = (args.directory / "candidate.vram.numeric").read_bytes()
    if len(x) != 4 * int(a[0][1]) or x != y:
        raise SystemExit("Direct channel output stream differs/incomplete")
    xf = (args.directory / "baseline.vram.mxcsr").read_bytes()
    yf = (args.directory / "candidate.vram.mxcsr").read_bytes()
    if len(xf) != len(x) or xf != yf:
        raise SystemExit("Per-input host MXCSR stream differs/incomplete")
    print(f"PASS {len(a[1])} full 4-MiB VRAM pairs, 129 independent pixel/depth assertions, {len(x)} direct channel outputs, {len(xf)//4} exact MXCSR pairs")
    if a[2] or b[2]:
        if [(r, n, h) for r, n, _, h in a[2]] != [(r, n, h) for r, n, _, h in b[2]]:
            raise SystemExit("Benchmark ordered rounds/counts/full-VRAM hashes differ")
        medians = [statistics.median(int(t) for _, _, t, _ in rows) for rows in (a[2], b[2])]
        print(f"BENCH rounds={len(a[2])} baseline_median_us={medians[0]:.1f} candidate_median_us={medians[1]:.1f} speedup={medians[0]/medians[1]:.4f}")
        print("Synthetic in-memory triangle result; no native game-speed claim.")


if __name__ == "__main__":
    main()
