#!/usr/bin/env python3
"""Sample a local game process and the Mac's aggregate GPU counters."""

import argparse
import json
from pathlib import Path
import plistlib
import re
import statistics
import subprocess
import time


def gpu_statistics():
    tree = plistlib.loads(subprocess.check_output(["ioreg", "-a", "-r", "-c", "AGXAccelerator"]))
    def find(node):
        if isinstance(node, dict):
            if "PerformanceStatistics" in node:
                yield node["PerformanceStatistics"]
            for value in node.values():
                yield from find(value)
        elif isinstance(node, list):
            for value in node:
                yield from find(value)
    return list(find(tree))


def process(pid):
    raw = subprocess.check_output(["ps", "-p", str(pid), "-o", "time=", "-o", "rss="], text=True).split()
    clock = raw[0].split(":")
    seconds = 0.0
    for component in clock:
        seconds = seconds * 60 + float(component)
    return seconds, int(raw[1]) * 1024


def memory():
    raw = subprocess.check_output(["vm_stat"], text=True)
    wanted = {"Swapins", "Swapouts", "Pageins", "Pageouts", "Compressions", "Decompressions"}
    return {name: int(value) for name, value in re.findall(r"^([^:\n]+):\s+(\d+)\.", raw, re.M)
            if name in wanted}


def distribution(values):
    values = sorted(values)
    return {"min": values[0], "mean": statistics.mean(values),
            "p95": values[round((len(values) - 1) * 0.95)], "max": values[-1]} if values else None


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--pid", type=int, required=True)
    parser.add_argument("--log", type=Path, required=True)
    parser.add_argument("--out", type=Path, required=True)
    parser.add_argument("--seconds", type=int, default=30)
    parser.add_argument("--wait-for-gameplay", action="store_true")
    args = parser.parse_args()
    if not 1 <= args.seconds <= 600:
        parser.error("--seconds must be between 1 and 600")
    args.out.mkdir(parents=True, exist_ok=False)
    if args.wait_for_gameplay:
        deadline = time.monotonic() + 180
        while "reached gameplay" not in args.log.read_text(errors="replace"):
            process(args.pid)
            if time.monotonic() >= deadline:
                raise RuntimeError("Game did not report the gameplay route within 180 seconds")
            time.sleep(1)
    offset = args.log.stat().st_size
    before = memory()
    rows = []
    previous_cpu, _ = process(args.pid)
    previous_time = start = time.monotonic()
    with (args.out / "samples.jsonl").open("w") as stream:
        for _ in range(args.seconds):
            time.sleep(max(0, 1 - (time.monotonic() - previous_time)))
            cpu, resident = process(args.pid)
            now = time.monotonic()
            row = {"elapsed_seconds": now - start,
                   "process_cpu_percent": (cpu - previous_cpu) * 100 / (now - previous_time),
                   "process_resident_bytes": resident, "gpu_whole_device": gpu_statistics()}
            rows.append(row)
            stream.write(json.dumps(row) + "\n")
            stream.flush()
            previous_cpu, previous_time = cpu, now
    after = memory()
    with args.log.open("rb") as log:
        log.seek(offset)
        log_window = log.read().decode(errors="replace")
    (args.out / "game-window.log").write_text(log_window)
    gpu = [device.get("Device Utilization %", 0) for row in rows for device in row["gpu_whole_device"]]
    readings = re.findall(r"\[PERFORMANCE-OVERLAY\] fps=([\d.]+) frame_ms=([\d.]+) ups=([\d.]+)", log_window)
    stalls = [float(value) / 1000 for value in re.findall(r"Stalled compile.*? - ([\d.]+) us", log_window)]
    report = {"pid": args.pid, "samples": len(rows), "seconds": rows[-1]["elapsed_seconds"],
        "cpu_percent_one_core_is_100": distribution([row["process_cpu_percent"] for row in rows]),
        "resident_mib": distribution([row["process_resident_bytes"] / 1048576 for row in rows]),
        "gpu_whole_device_utilization_percent": distribution(gpu),
        "display_fps": distribution([float(row[0]) for row in readings]),
        "display_frame_ms": distribution([float(row[1]) for row in readings]),
        "original_game_updates_per_second": distribution([float(row[2]) for row in readings]),
        "shader_compilation_stalls_ms": distribution(stalls), "shader_compilation_stall_count": len(stalls),
        "vblank_delays_ms": distribution([int(value) / 1000 for value in re.findall(r"\[vblank-slow\] (\d+) us", log_window)]),
        "system_memory_counter_delta_pages": {key: after[key] - before[key] for key in before},
        "limitations": ["GPU counters cover the whole device, including other apps.",
                        "CPU percentages use process CPU-time deltas; 100% means one core.",
                        "Display FPS is distinct from the game's original update rate."]}
    (args.out / "report.json").write_text(json.dumps(report, indent=2))
    print(json.dumps(report, indent=2))


if __name__ == "__main__":
    main()
