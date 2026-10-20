"""Measure LLVM inlining budgets against unchanged, real generated game units.

Experimental only: objects are isolated and never used by the release builder.
Compilation timing does not establish gameplay performance.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time

from benchmark_compilation import load


def main():
    parser = argparse.ArgumentParser(__doc__)
    parser.add_argument("output", type=Path)
    parser.add_argument("--units", nargs="+", default=["main31"])
    parser.add_argument("--thresholds", nargs="+", default=["default", "75"])
    args = parser.parse_args()
    repo = Path(__file__).resolve().parents[2]
    out = args.output.resolve()
    if not out.is_relative_to(repo / "build-ninja") or out.exists():
        raise ValueError("Use a fresh directory under build-ninja")
    full = repo / "build-ninja/compile-full-20261020"
    events = [json.loads(line) for line in
              (full / "old/commands.jsonl").read_text().splitlines()]
    commands = {Path(row["command"][-1]).stem: row["command"] for row in events
                if row["stage"] == "compile" and row["event"] == "begin"}
    if not set(args.units).issubset(commands):
        raise ValueError("A requested unit has no recorded reference command")
    for threshold in args.thresholds:
        if threshold not in ("default", "no-auto") and not threshold.isdigit():
            raise ValueError("Thresholds must be default, no-auto, or nonnegative integers")
    paths = json.loads((repo / "build-ninja/import-profile-20261020/paths.json").read_text())
    os.environ["REO_LLVM_MINGW"] = paths["compiler"]
    kit = repo / "build-ninja/import-optimized-20261020/kit"
    worker = load("inlining_reference_worker", kit / "tools/local_build/compile_game.py")
    env, _ = worker.portable_environment(kit, json.loads((kit / "compile-plan.json").read_text()))
    out.mkdir(parents=True)
    report = {"acceptedForRelease": False, "gameExecuted": False,
              "sameSourceAndPch": True, "backgroundFullBuild": True, "rows": []}
    for unit in args.units:
        for sequence, threshold in enumerate(args.thresholds):
            name = f"{unit}-{sequence}-{threshold}"
            obj = out / (name + ".obj")
            command = commands[unit][:]
            command[command.index("-o") + 1] = str(obj)
            if threshold == "no-auto":
                command[1:1] = ["-fno-inline-functions"]
            elif threshold != "default":
                command[1:1] = ["-mllvm", f"-inline-threshold={threshold}",
                                "-mllvm", f"-inlinehint-threshold={threshold}"]
            print(f"Starting {name}", flush=True)
            started = time.perf_counter()
            with (out / (name + ".log")).open("wb") as log:
                process = subprocess.run(command, env=env, stdout=log, stderr=subprocess.STDOUT)
            row = {"unit": unit, "threshold": threshold, "seconds": time.perf_counter() - started,
                   "exit": process.returncode, "command": command}
            if obj.is_file():
                row.update(bytes=obj.stat().st_size, sha256=hashlib.sha256(obj.read_bytes()).hexdigest())
            report["rows"].append(row)
            (out / "results.json").write_text(json.dumps(report, indent=2))
            print(f"{name}: {row['seconds']:.3f}s, exit={process.returncode}", flush=True)
            if process.returncode:
                raise RuntimeError(f"Compilation failed; see {out / (name + '.log')}")


if __name__ == "__main__":
    main()
