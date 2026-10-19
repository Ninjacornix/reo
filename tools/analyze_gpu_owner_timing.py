"""Summarize bounded owner wall scopes and device timestamps from a closed log.

Wall scopes are nested, and GPU timestamps can overlap host waits. Neither is
a game-frame counter. Preserve the original game-clock evidence separately.
"""
import argparse
import json
from pathlib import Path
import re
import statistics


def records(lines, marker):
    return [dict((key, float(value)) for key, value in
                 re.findall(r"(\w+)=([0-9]+(?:\.[0-9]+)?)(?=\s|$)", line))
            for line in lines if marker in line]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("log", type=Path)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    if args.out.exists():
        parser.error("preserve the existing report; choose a new output path")
    lines = args.log.read_text(encoding="utf-8", errors="replace").splitlines()
    wall = records(lines, "[GPU-OWNER-TIMING]")
    gpu = records(lines, "[GPU-STAGE-TIMING]")
    vif = records(lines, "[VIF-KICK-TIMING] ")
    scopes = {}
    for key in sorted({key for row in wall for key in row if key.endswith("_us")}):
        count = sum(row.get(key[:-3] + "_n", 0) for row in wall)
        total = sum(row.get(key, 0) for row in wall)
        scopes[key[:-3]] = {"calls": count, "total_wall_us": total,
                            "mean_wall_us": total / count if count else None}
    stages = {key: {"samples": len(values), "median_us": statistics.median(values),
                    "maximum_us": max(values)}
              for key in sorted({key for row in gpu for key in row if key.endswith("_us")})
              if (values := [row[key] for row in gpu if key in row])}
    output = {
        "classification": "nested_host_scopes_and_GPU_device_timestamps_not_FPS",
        "log": str(args.log), "wall_reports": len(wall), "scopes": scopes,
        "routes": {key: sum(row.get(key, 0) for row in wall) for key in
                   ("route_unknown", "route_fast", "route_completeC", "route_prefix")},
        "device_stages": stages,
        "vif_samples": vif,
        "median_vif_wall_us": statistics.median(row["duration_us"] for row in vif) if vif else None,
        "limitations": ["Nested scopes overlap; do not add them together.",
                        "Fence wait includes earlier queue work, not only the current launch.",
                        "Device timestamps add synchronization and are a bounded diagnostic.",
                        "A successful present does not establish a new gameplay update."],
    }
    args.out.write_text(json.dumps(output, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({key: output[key] for key in ("wall_reports", "routes", "median_vif_wall_us", "device_stages")}))


if __name__ == "__main__":
    main()
