"""Queue a cold complete batched build after the existing full comparison.

Only output directories and the private plan are substituted. Source/compiler
settings are unchanged. Completed reference files may be NTFS-compressed, never
deleted, to leave room for another executable.
"""
import argparse
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import threading
import time
import traceback

from benchmark_compilation import load
from benchmark_full_compilation import digest, redirected_worker


def main():
    parser = argparse.ArgumentParser(__doc__)
    parser.add_argument("output", type=Path)
    parser.add_argument("--after", type=Path, required=True)
    parser.add_argument("--resume-wait", action="store_true",
                        help="Resume a stopped waiter that has not started any compilation")
    args = parser.parse_args()
    repo = Path(__file__).resolve().parents[2]
    output, reference = args.output.resolve(), args.after.resolve()
    if (not output.is_relative_to(repo / "build-ninja")
            or not reference.is_relative_to(repo / "build-ninja")):
        raise ValueError("Use a fresh output and existing reference under build-ninja")
    prior = None
    if output.exists():
        state = json.loads((output / "results.json").read_text())
        if (not args.resume_wait or state.get("status") not in {"waiting-for-reference", "failed"}
                or state.get("reference") != str(reference)
                or {p.name for p in output.iterdir()} != {"results.json"}):
            raise ValueError("Only an untouched stopped waiter can resume")
        prior = state
    else:
        output.mkdir(parents=True)
    sys.path.insert(0, str(repo / "tools/local_build"))
    from compilation_batches import with_generated_batches
    report = {"status": "waiting-for-reference", "gameRun": False,
              "fullGameCompile": True, "objectCachesInitiallyEmpty": True,
              "reference": str(reference), "osCachesFlushed": False}
    if prior is not None:
        report["priorWaitResult"] = prior

    def save():
        pending = output / "results.pending.json"
        pending.write_text(json.dumps(report, indent=2))
        pending.replace(output / "results.json")

    save()
    try:
        print("Waiting for the current old/new complete build comparison.", flush=True)
        deadline = time.monotonic() + 4 * 60 * 60
        while True:
            state = json.loads((reference / "results.json").read_text())
            if state["status"] == "complete":
                break
            if state["status"] != "running" or time.monotonic() > deadline:
                raise RuntimeError("Reference failed or did not finish within four hours")
            time.sleep(5)
        subprocess.run([sys.executable, str(Path(__file__).with_name("compare_compiled_outputs.py")),
                        str(reference)], check=True)
        report["referenceSeconds"] = {row["variant"]: row["seconds"] for row in state["rows"]}
        report["status"] = "preparing-storage"
        save()
        # Reversible storage compression on finished artifacts, outside timing.
        if shutil.disk_usage(repo).free < 3 * 1024**3:
            if os.name != "nt":
                raise RuntimeError("Less than 3 GiB free for the cold batched build")
            with (output / "storage-compression.log").open("wb") as log:
                for variant in ("old", "new"):
                    folder = (reference / variant / "objects").resolve()
                    assert folder.is_relative_to(reference)
                    subprocess.run(["compact.exe", "/C", "/I", "/Q", "/EXE:LZX",
                                    f"/S:{folder}", "*.obj"],
                                   cwd=folder, stdout=log, stderr=subprocess.STDOUT, check=True)
                    exe = reference / variant / "output/reo_recomp.exe"
                    subprocess.run(["compact.exe", "/C", "/I", "/Q", "/EXE:LZX", str(exe)],
                                   stdout=log, stderr=subprocess.STDOUT, check=True)
            report["referenceStorageCompression"] = "NTFS/WOF LZX, content preserved"
        if shutil.disk_usage(repo).free < 2500 * 1024**2:
            raise RuntimeError("Insufficient disk space; reference artifacts preserved")
        kit = repo / "build-ninja/import-optimized-20261020/kit"
        work = repo / "build-ninja/import-optimized-20261020/worker-benchmark/work"
        plan = output / "compile-plan.json"
        original = json.loads((kit / "compile-plan.json").read_text())
        plan.write_text(json.dumps(with_generated_batches(original, batch_size=64), indent=2))
        paths = json.loads((repo / "build-ninja/import-profile-20261020/paths.json").read_text())
        os.environ["REO_LLVM_MINGW"] = paths["compiler"]
        module = load("batched_full_worker", repo / "tools/local_build/compile_game.py")
        report.update(status="running", sourceSha256=digest(Path(module.__file__)),
                      schedulerSha256=digest(repo / "tools/local_build/build_scheduler.py"),
                      planSha256=digest(plan), remainingDiskBytes=shutil.disk_usage(repo).free)
        save()
        started = time.perf_counter()
        lock = threading.Lock()
        active = maximum = 0
        phase = {}
        with (output / "commands.jsonl").open("w", encoding="utf-8") as events:
            def observe(stage, event, now, command, code=None, begin=None):
                nonlocal active, maximum
                with lock:
                    if stage == "compile":
                        active += 1 if event == "begin" else -1
                        maximum = max(maximum, active)
                    row = {"stage": stage, "event": event, "elapsedSeconds": now-started,
                           "command": list(map(str, command)), "returncode": code}
                    if begin is not None:
                        row["durationSeconds"] = now-begin
                    events.write(json.dumps(row) + "\n")
                    events.flush()
                    bucket = phase.setdefault(stage, {"completed": 0, "sumProcessWallSeconds": 0})
                    if event == "end":
                        bucket["completed"] += 1
                        bucket["sumProcessWallSeconds"] += now-begin
            worker = redirected_worker(module, output, observe)
            worker(kit, work / "project/recomp/config", work, output / "output", 7,
                   plan_name=str(plan))
        report.update(seconds=time.perf_counter()-started, phases=phase,
                      maximumConcurrentCompilerProcesses=maximum)
        hashes = {p.stem: digest(p) for p in sorted((output / "objects").glob("*.obj"))}
        (output / "object-hashes.json").write_text(json.dumps(hashes, indent=2))
        report.update(status="checking-output", objectCount=len(hashes),
                      exeSha256=digest(output / "output/reo_recomp.exe"),
                      remainingDiskBytes=shutil.disk_usage(repo).free)
        save()
        subprocess.run([sys.executable, str(Path(__file__).with_name("compare_batched_outputs.py")),
                        str(reference / "old"), str(output)], check=True)
        report.update(status="complete", batchParityFile=str(output / "batch-parity.json"))
        save()
        print("COMPLETE", json.dumps(report), flush=True)
    except BaseException:
        report.update(status="failed", error=traceback.format_exc())
        save()
        raise


if __name__ == "__main__":
    main()
