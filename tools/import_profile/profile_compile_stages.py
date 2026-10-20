"""Profile one recorded real compile without changing optimization settings."""
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
    parser.add_argument("--unit", required=True)
    args = parser.parse_args()
    repo = Path(__file__).resolve().parents[2]
    output = args.output.resolve()
    if not output.is_relative_to(repo / "build-ninja") or output.exists():
        raise ValueError("Use a fresh directory under build-ninja")
    reference = repo / "build-ninja/compile-full-20261020/old"
    events = [json.loads(line) for line in (reference / "commands.jsonl").read_text().splitlines()]
    matches = [row["command"] for row in events if row["event"] == "begin"
               and row["stage"] == "compile" and Path(row["command"][-1]).stem == args.unit]
    if len(matches) != 1:
        raise ValueError("Expected exactly one reference command")
    command = matches[0][:]
    paths = json.loads((repo / "build-ninja/import-profile-20261020/paths.json").read_text())
    os.environ["REO_LLVM_MINGW"] = paths["compiler"]
    kit = repo / "build-ninja/import-optimized-20261020/kit"
    worker = load("profile_reference_worker", kit / "tools/local_build/compile_game.py")
    env, _ = worker.portable_environment(kit, json.loads((kit / "compile-plan.json").read_text()))
    output.mkdir(parents=True)
    obj, trace = output / (args.unit + ".obj"), output / "trace.json"
    command[command.index("-o") + 1] = str(obj)
    command.insert(1, "-ftime-trace=" + str(trace))
    started = time.perf_counter()
    with (output / "compile.log").open("wb") as log:
        subprocess.run(command, env=env, stdout=log, stderr=subprocess.STDOUT, check=True)
    elapsed = time.perf_counter() - started
    totals = sorted(
        [{"name": row["name"].removeprefix("Total "), "seconds": row["dur"] / 1e6,
          "count": row.get("args", {}).get("count")}
         for row in json.loads(trace.read_text())["traceEvents"]
         if row["name"].startswith("Total ")], key=lambda row: -row["seconds"])
    result = {"unit": args.unit, "seconds": elapsed, "backgroundFullBuild": True,
              "command": command, "totalsOverlap": True, "totals": totals,
              "objectByteIdentical": worker.digest(obj) == worker.digest(
                  reference / "objects" / (args.unit + ".obj"))}
    (output / "results.json").write_text(json.dumps(result, indent=2))
    print(json.dumps({**result, "command": None, "totals": totals[:20]}, indent=2))


if __name__ == "__main__":
    main()
