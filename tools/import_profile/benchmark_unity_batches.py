"""Measure larger bounded batches of unchanged real sources and compiler flags."""
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
    parser.add_argument("--units", nargs="+", default=[f"main{i}" for i in range(5, 14)])
    parser.add_argument("--batch-size", type=int, default=32)
    parser.add_argument("--reference-batch-size", type=int, default=8)
    parser.add_argument("--max-bytes", type=int, default=500000)
    args = parser.parse_args()
    if not 8 <= args.batch_size <= 128:
        raise ValueError("Use a bounded batch size between 8 and 128")
    if not 8 <= args.reference_batch_size <= args.batch_size:
        raise ValueError("Reference batch size must be between 8 and the candidate size")
    if not 500000 <= args.max_bytes <= 2000000:
        raise ValueError("Use a source-byte limit between 500000 and 2000000")
    repo = Path(__file__).resolve().parents[2]
    out = args.output.resolve()
    if not out.is_relative_to(repo / "build-ninja") or out.exists():
        raise ValueError("Use a fresh directory under build-ninja")
    events = [json.loads(line) for line in
              (repo / "build-ninja/compile-full-20261020/old/commands.jsonl").read_text().splitlines()]
    units = {Path(row["command"][-1]).stem: row["command"] for row in events
             if row["stage"] == "compile" and row["event"] == "begin"}
    paths = json.loads((repo / "build-ninja/import-profile-20261020/paths.json").read_text())
    os.environ["REO_LLVM_MINGW"] = paths["compiler"]
    kit = repo / "build-ninja/import-optimized-20261020/kit"
    worker = load("unity_reference_worker", kit / "tools/local_build/compile_game.py")
    env, _ = worker.portable_environment(kit, json.loads((kit / "compile-plan.json").read_text()))

    def options(command):
        result = command[:-1]
        i = result.index("-o")
        del result[i:i+2]
        return result

    common = options(units[args.units[0]])
    source_counts = {}
    for name in args.units:
        command = units[name]
        if options(command) != common:
            raise ValueError("Cannot combine units with different flags/PCH")
        sources = [Path(json.loads(line[len("#include "):])) for line in
                   Path(command[-1]).read_text().splitlines() if line.startswith("#include ")]
        source_counts[name] = (len(sources), sum(path.stat().st_size for path in sources))

    def group(limit, byte_limit):
        batches, pending, count, size = [], [], 0, 0
        for name in args.units:
            length, total = source_counts[name]
            if pending and (count + length > limit or size + total > byte_limit):
                batches.append(pending)
                pending, count, size = [], 0, 0
            pending.append(name)
            count += length
            size += total
        if pending:
            batches.append(pending)
        return batches

    batches = group(args.batch_size, args.max_bytes)
    reference_batches = ([[name] for name in args.units] if args.reference_batch_size == 8
                         else group(args.reference_batch_size, 500000))
    out.mkdir(parents=True)
    report = {"acceptedForRelease": False, "gameExecuted": False,
              "backgroundFullBuild": True, "batchSize": args.batch_size,
              "referenceBatchSize": args.reference_batch_size,
              "referenceBatches": reference_batches,
              "maxBytes": args.max_bytes, "batches": batches, "rows": []}
    for variant in ("old", "merged", "merged", "old"):
        trial = out / f"{len(report['rows'])}-{variant}"
        trial.mkdir()
        items = reference_batches if variant == "old" else batches
        start = time.perf_counter()
        entries = []
        for index, names in enumerate(items):
            source = Path(units[names[0]][-1])
            if len(names) > 1:
                source = trial / f"batch{index}.cpp"
                source.write_text("".join("#include " + json.dumps(
                    Path(units[name][-1]).as_posix()) + "\n" for name in names))
            command = [*common, "-o", str(trial / f"batch{index}.obj"), str(source)]
            before = time.perf_counter()
            with (trial / f"batch{index}.log").open("wb") as log:
                result = subprocess.run(command, env=env, stdout=log, stderr=subprocess.STDOUT)
            entries.append({"units": names, "seconds": time.perf_counter()-before,
                            "exit": result.returncode, "command": command})
            if result.returncode:
                report["failed"] = entries[-1]
                (out / "results.json").write_text(json.dumps(report, indent=2))
                raise RuntimeError(f"Compilation failed; see {trial}")
        row = {"variant": variant, "seconds": time.perf_counter()-start, "compilations": entries}
        report["rows"].append(row)
        (out / "results.json").write_text(json.dumps(report, indent=2))
        print(variant, f"{row['seconds']:.3f}s", f"{len(items)} processes", flush=True)


if __name__ == "__main__":
    main()
