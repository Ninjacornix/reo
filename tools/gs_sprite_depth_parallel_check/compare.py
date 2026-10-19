"""Exact complete-VRAM parity plus independent row-cancellation assertions."""
import argparse
from pathlib import Path
import re
import statistics


def read(path):
    text = path.read_text(errors="replace")
    summary = re.search(r"SUMMARY cases=(\d+) independent_checks=(\d+) failures=(\d+)", text)
    cases = re.findall(r"^CASE (\d+) (\S+) hash=([0-9a-f]+) calls=(\d+) scissor=(\d+) alpha=(\d+) oracle=(\d+)", text, re.M)
    stops = re.findall(r"^STOP iteration=(\d+) rows=(\d+) calls=(\d+) hash=([0-9a-f]+)", text, re.M)
    bench = re.findall(r"^BENCH round=(\d+) sprites=(\d+) us=(\d+) hash=([0-9a-f]+)", text, re.M)
    if "FAIL" in text or not summary or int(summary[3]) or len(cases) != int(summary[1]) or len(stops) != 3:
        raise SystemExit(f"Missing or failed independent oracle: {path}")
    return summary, cases, bench


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("directory", type=Path)
    args = parser.parse_args()
    a, b = (read(args.directory / f"{v}.log") for v in ("baseline", "candidate"))
    if a[1] != b[1]:
        raise SystemExit("Cases, full-image hashes, or exact counter triples differ")
    if int(b[0][2]) != int(a[0][2]) + len(a[1]) + 7:
        raise SystemExit("Candidate eligibility assertions missing")
    width = 4 * 1024 * 1024
    for v in ("baseline", "candidate"):
        if (args.directory / f"{v}.vram").stat().st_size != width * len(a[1]):
            raise SystemExit("Incomplete full-VRAM stream")
    with (args.directory / "baseline.vram").open("rb") as left, (args.directory / "candidate.vram").open("rb") as right:
        for index, name, *_ in a[1]:
            x, y = left.read(width), right.read(width)
            if x != y:
                offset = next(i for i, pair in enumerate(zip(x, y)) if pair[0] != pair[1])
                raise SystemExit(f"FAIL case={index} name={name} VRAM[{offset:#x}]")
    print(f"PASS {len(a[1])} full 4-MiB VRAM pairs and exact diagnostic triples; "
          f"baseline {a[0][2]} / candidate {b[0][2]} independent assertions; "
          "3 partial-stop full-VRAM oracles each")
    if a[2] or b[2]:
        if [(r, n, h) for r, n, _, h in a[2]] != [(r, n, h) for r, n, _, h in b[2]]:
            raise SystemExit("Benchmark rounds/counts/full-image hashes differ")
        medians = [statistics.median(int(t) for _, _, t, _ in rows) for rows in (a[2], b[2])]
        print(f"BENCH rounds={len(a[2])} baseline_median_us={medians[0]:.1f} "
              f"candidate_median_us={medians[1]:.1f} speedup={medians[0]/medians[1]:.4f}")
        print("Synthetic untextured depth-writing sprite result; no native gain claim.")


if __name__ == "__main__":
    main()
