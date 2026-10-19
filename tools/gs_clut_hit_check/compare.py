"""Compare all VRAM bytes and primitive-scoped CLUT assertions."""
import argparse
from pathlib import Path
import re
import statistics


def log(path):
    text = path.read_text(errors="replace")
    if "FAIL" in text:
        raise SystemExit(f"Independent oracle failed: {path}")
    direct = re.search(r"CLUT_DIRECT checks=(\d+) failures=(\d+)", text)
    summary = re.search(r"cases=(\d+) independent_checks=(\d+) failures=(\d+)", text)
    cases = re.findall(r"^CASE (\d+) (\S+) hash=([0-9a-f]+)", text, re.M)
    bench = re.findall(r"^BENCH round=(\d+) triangles=(\d+) us=(\d+) hash=([0-9a-f]+)", text, re.M)
    if not direct or int(direct[1]) != 208 or int(direct[2]):
        raise SystemExit(f"Missing CLUT direct checks: {path}")
    if not summary or int(summary[1]) != 79 or int(summary[2]) != 129 or int(summary[3]) or len(cases) != 79:
        raise SystemExit(f"Missing complete-VRAM/pixel checks: {path}")
    return direct.groups(), cases, bench


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("directory", type=Path)
    args = parser.parse_args()
    a, b = (log(args.directory / f"{v}.log") for v in ("baseline", "candidate"))
    if a[:2] != b[:2]:
        raise SystemExit("Direct check totals/case sequences/output hashes differ")
    width = 4 * 1024 * 1024
    for v in ("baseline", "candidate"):
        if (args.directory / f"{v}.vram").stat().st_size != width * 79:
            raise SystemExit("Incomplete full-VRAM stream")
    with (args.directory / "baseline.vram").open("rb") as left, (args.directory / "candidate.vram").open("rb") as right:
        for i, name, _ in a[1]:
            x, y = left.read(width), right.read(width)
            if x != y:
                offset = next(j for j, pair in enumerate(zip(x, y)) if pair[0] != pair[1])
                raise SystemExit(f"FAIL case={i} name={name} VRAM[{offset:#x}]")
    print("PASS 79 full 4-MiB VRAM pairs, 129 pixel/depth assertions, 208 direct CLUT lifetime/live-alias assertions")
    if a[2] or b[2]:
        if [(r, n, h) for r, n, _, h in a[2]] != [(r, n, h) for r, n, _, h in b[2]]:
            raise SystemExit("Benchmark rounds/counts/full-VRAM hashes differ")
        medians = [statistics.median(int(t) for _, _, t, _ in rows) for rows in (a[2], b[2])]
        print(f"BENCH rounds={len(a[2])} baseline_median_us={medians[0]:.1f} candidate_median_us={medians[1]:.1f} speedup={medians[0]/medians[1]:.4f}")
        print("Synthetic in-memory triangle result; no native game-speed claim.")


if __name__ == "__main__":
    main()
