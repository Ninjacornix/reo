"""Prototype shared PCH code generation with unchanged source and O2 flags.

The shared object must accompany consumers when linking. No production plan is
changed by this experiment.
"""
import argparse
import json
import os
from pathlib import Path
import subprocess
import time

from benchmark_compilation import load


def main():
    parser = argparse.ArgumentParser(__doc__)
    parser.add_argument("output", type=Path)
    parser.add_argument("--units", nargs="+", default=["main5", "main31"])
    args = parser.parse_args()
    repo = Path(__file__).resolve().parents[2]
    out = args.output.resolve()
    if not out.is_relative_to(repo / "build-ninja") or out.exists():
        raise ValueError("Use a fresh output under build-ninja")
    events = [json.loads(line) for line in
              (repo / "build-ninja/compile-full-20261020/old/commands.jsonl").read_text().splitlines()]
    units = {Path(row["command"][-1]).stem: row["command"] for row in events
             if row["stage"] == "compile" and row["event"] == "begin"}
    original_pch = next(row["command"] for row in events
                        if row["stage"] == "pch" and row["event"] == "begin")
    paths = json.loads((repo / "build-ninja/import-profile-20261020/paths.json").read_text())
    os.environ["REO_LLVM_MINGW"] = paths["compiler"]
    kit = repo / "build-ninja/import-optimized-20261020/kit"
    worker = load("shared_pch_worker", kit / "tools/local_build/compile_game.py")
    env, _ = worker.portable_environment(kit, json.loads((kit / "compile-plan.json").read_text()))
    out.mkdir(parents=True)
    header, pch = out / "shared.hpp", out / "shared.pch"
    header.write_bytes(Path(original_pch[original_pch.index("c++-header") + 1]).read_bytes())
    report = {"acceptedForRelease": False, "gameExecuted": False,
              "backgroundFullBuild": True, "rows": []}

    def run(name, command):
        print("Starting " + name, flush=True)
        started = time.perf_counter()
        with (out / (name + ".log")).open("wb") as log:
            result = subprocess.run(command, env=env, stdout=log, stderr=subprocess.STDOUT)
        row = {"name": name, "seconds": time.perf_counter() - started,
               "exit": result.returncode, "command": command}
        report["rows"].append(row)
        (out / "results.json").write_text(json.dumps(report, indent=2))
        print(f"{name}: {row['seconds']:.3f}s, exit={result.returncode}", flush=True)
        if result.returncode:
            raise RuntimeError(f"Experiment failed; see {out / (name + '.log')}")

    command = original_pch[:]
    command[command.index("c++-header") + 1] = str(header)
    command[command.index("-o") + 1] = str(pch)
    command[1:1] = ["-fpch-codegen", "-fpch-instantiate-templates"]
    run("pch", command)
    # Compile the PCH itself into its companion object, using the same options.
    options = original_pch[1:original_pch.index("-x")]
    run("shared-object", [original_pch[0], *options, "-c", str(pch),
                          "-o", str(out / "shared.obj")])
    for unit in args.units:
        command = units[unit][:]
        command[command.index("-include-pch") + 1] = str(pch)
        command[command.index("-o") + 1] = str(out / (unit + ".obj"))
        run(unit, command)


if __name__ == "__main__":
    main()
