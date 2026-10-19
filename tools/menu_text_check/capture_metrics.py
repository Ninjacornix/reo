"""Report presentation provenance and movie/audio progress over one capture burst.

Uses only capture sidecars and bounded diagnostics. No process launch or assets.
"""

import argparse
import json
import re
from collections import Counter
from pathlib import Path


def measure(directory, first=None):
    rows = [json.loads(line) for line in
            (directory / "present_dump.jsonl").read_text().splitlines()]
    if first is not None:
        rows = rows[:first]
    if len(rows) < 2:
        raise ValueError("at least two captured presents required")
    lo, hi = rows[0]["ns"], rows[-1]["ns"]
    duration = (hi - lo) / 1e9
    result = {
        "directory": str(directory), "presents": len(rows),
        "seconds": duration, "host_presents_per_second": (len(rows) - 1) / duration,
        "elapsed_range": [rows[0]["elapsed"], rows[-1]["elapsed"]],
        "fbp_counts": dict(Counter(row["fbp"] for row in rows)),
    }
    if all("frame_tick" in row for row in rows):
        ticks = [row["frame_tick"] for row in rows]
        deltas = [b - a for a, b in zip(ticks, ticks[1:])]
        ages = [row["tick"] - row["frame_tick"] for row in rows]
        result["immutable_frames"] = {
            "unique_captured_ticks": len(set(ticks)),
            "observed_new_frames_per_second": sum(d > 0 for d in deltas) / duration,
            "repeated_present_count": sum(d == 0 for d in deltas),
            "regressed_tick_count": sum(d < 0 for d in deltas),
            "tick_delta_counts": dict(sorted(Counter(deltas).items())),
            "age_ticks_min": min(ages), "age_ticks_max": max(ages),
            "age_ticks_mean": sum(ages) / len(ages),
            "note": "A new capture tick proves another completed scanout, not necessarily a new movie image.",
        }
    else:
        result["immutable_frames"] = None

    movie, audio = [], []
    pending_audio = None
    for line in (directory / "stderr.log").read_text(errors="replace").splitlines():
        found = re.search(r"\[CRI-AUDIO\] frames=(\d+) signal=(\d+) underrun=(\d+) queuedSamples=(\d+)", line)
        if found:
            pending_audio = dict(zip(("frames", "signal", "underrun", "queued_samples"),
                                     map(int, found.groups())))
        found = re.search(r"\[CRI-SYNC\] position .* ns=(\d+)", line)
        if found and pending_audio is not None:
            pending_audio["ns"] = int(found[1])
            audio.append(pending_audio)
            pending_audio = None
        found = re.search(r"\[CRI-SYNC\] movie ns=(\d+).*decoded=(\d+)/(\d+)", line)
        if found:
            movie.append(tuple(map(int, found.groups())))
    movie = [entry for entry in movie if lo <= entry[0] <= hi]
    audio = [entry for entry in audio if lo <= entry["ns"] <= hi]
    result["movie"] = {"log_samples": len(movie)}
    if len(movie) >= 2 and movie[0][2] == movie[-1][2] and movie[-1][1] >= movie[0][1]:
        wall = (movie[-1][0] - movie[0][0]) / 1e9
        # CRI's decoded timestamp advances by 1000 units per movie frame.
        decoded = (movie[-1][1] - movie[0][1]) / 1000
        result["movie"].update(decoded_frames=decoded, wall_seconds=wall,
                               decoded_frames_per_second=decoded / wall)
    result["audio"] = {
        "log_samples": len(audio),
        "underrun_frames_sum": sum(entry["underrun"] for entry in audio),
        "underrun_frames_max_window": max((entry["underrun"] for entry in audio), default=None),
        "note": "Audio diagnostics aggregate preceding windows; capture endpoints can include partial-window overlap.",
    }
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("directory", type=Path)
    parser.add_argument("--first", type=int, help="limit to the first N presents before a known selection change")
    parser.add_argument("--report", type=Path)
    args = parser.parse_args()
    if args.first is not None and args.first < 2:
        parser.error("--first must be at least two")
    result = measure(args.directory, args.first)
    output = json.dumps(result, indent=2)
    print(output)
    if args.report:
        args.report.write_text(output + "\n")


if __name__ == "__main__":
    main()
