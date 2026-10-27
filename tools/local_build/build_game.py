"""First-run worker: derive and compile a private game from its ISO import."""

import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys
import os

from compile_game import compile_plan, msvc_environment
from generate_game import generate
from reconstruct_vu import reconstruct
from source_recipes import apply_plan
from generate_queue_control import generate as generate_queue_control


def sha(path):
    with Path(path).open("rb") as f:
        return hashlib.file_digest(f, "sha256").hexdigest()


def stage(work, name, inputs, action, outputs, jobs=1):
    receipt = work / (name + ".json")
    expected = {str(p): sha(p) for p in inputs}
    if receipt.exists():
        record = json.loads(receipt.read_text())
        recorded_inputs = record.get("inputs", {})
        if all(recorded_inputs.get(p) == digest for p, digest in expected.items()) and record.get("outputs"):
            def matches(item):
                path, digest = item
                return Path(path).is_file() and sha(path) == digest
            with ThreadPoolExecutor(max_workers=max(1, min(jobs, 4))) as pool:
                valid = all(pool.map(matches, record["outputs"].items()))
            if valid:
                print("Reusing " + name, flush=True)
                return
    # Never overlay a failed generation with a new one or delete its diagnostics.
    action()
    paths = list(outputs())
    with ThreadPoolExecutor(max_workers=max(1, min(jobs, 4))) as pool:
        hashes = list(pool.map(sha, paths))
    record = {"inputs": expected, "outputs": {str(p): digest for p, digest in zip(paths, hashes)}}
    if not record["outputs"]:
        raise ValueError("Build stage produced no verified output")
    temporary = receipt.with_suffix(".pending")
    temporary.write_text(json.dumps(record, indent=2))
    temporary.replace(receipt)


def extended(path):
    """Windows path without the 260-character limit (kit sources nest deeply)."""
    text = str(Path(path).resolve())
    if sys.platform != "win32" or text.startswith("\\\\?\\"):
        return Path(text)
    return Path("\\\\?\\UNC\\" + text[2:] if text.startswith("\\\\") else "\\\\?\\" + text)


def build(kit, disc, work, output, jobs):
    kit, disc, work, output = [Path(p).resolve() for p in (kit, disc, work, output)]
    work.mkdir(parents=True, exist_ok=True)
    if sys.platform == "linux":
        from compile_linux import compile_plan as compile_native
        recompiler = kit / "tools/ps2_recomp"
    elif sys.platform == "win32":
        compile_native = compile_plan
        recompiler = kit / "tools/ps2_recomp.exe"
        plan = json.loads((kit / "compile-plan.json").read_text())
        if plan.get("toolchain") == "llvm-mingw":
            from compile_game import portable_environment
            env, _ = portable_environment(kit, plan)
            os.environ["PATH"] = str(recompiler.parent) + os.pathsep + env["PATH"]
        else:
            env, _, _ = msvc_environment()
            crt = Path(env["VCToolsRedistDir"]) / "x64/Microsoft.VC143.CRT"
            os.environ["PATH"] = str(crt) + os.pathsep + os.environ.get("PATH", "")
    else:
        raise RuntimeError("No native build worker for this operating system")
    project = work / "project"
    project.mkdir(exist_ok=True)
    print("Preparing independent runtime sources", flush=True)
    shutil.copytree(extended(kit / "source"), extended(project), dirs_exist_ok=True)
    metadata = kit / "metadata"
    generated = project / "recomp/config"
    elf = disc / "SLUS_207.65"
    script = Path(__file__).parent
    metadata_files = [p for p in sorted(metadata.rglob("*")) if p.is_file() and p.name not in
                      {"local_queue_control.json", "local_source_recipes.json", "local_vu_images.json"}]

    def game_generation():
        if generated.exists():
            # This happens only after interruption/corruption of a previous
            # stage. Keep its files under an unused diagnostic name.
            n = 0
            while generated.with_name("config.interrupted" + str(n)).exists():
                n += 1
            generated.rename(generated.with_name("config.interrupted" + str(n)))
        generate(recompiler, disc, metadata, generated, jobs=jobs)

    stage(work, "generate", [elf, recompiler, script / "generate_game.py",
                            script / "generate_support.py", script / "registration_chunks.py",
                            *metadata_files], game_generation,
          lambda: [p for folder in ["output", "output_ovl", "output_extra", "output_overlay", "local_source_catalogues", "audit_sources"]
                   for p in (generated / folder).rglob("*") if p.is_file()], jobs=jobs)
    print("Reconstructing local instrumentation and VU optimizations", flush=True)
    apply_plan(elf, generated, metadata / "local_source_recipes.json", project)
    generate_queue_control(elf, metadata / "local_queue_control.json",
                           project / "tools/parallel_gs_backend/resident_geometry/upstream/queue_control_body.inc")
    catalogue_target = project / "third_party/PS2Recomp/ps2xRuntime/src/lib/local_source_catalogues"
    shutil.copytree(generated / "local_source_catalogues", catalogue_target, dirs_exist_ok=True)
    vu = generated / "vu"

    def generate_vu():
        if vu.exists():
            n = 0
            while vu.with_name("vu.interrupted" + str(n)).exists():
                n += 1
            vu.rename(vu.with_name("vu.interrupted" + str(n)))
        reconstruct(elf, metadata / "local_vu_images.json", vu)
        subprocess.run([sys.executable, str(kit / "tools/vu_whole_aot/generate.py"),
                        "--collection", str(vu), "--out", str(vu / "whole")], check=True)

    stage(work, "vu", [elf, metadata / "local_vu_images.json", script / "reconstruct_vu.py",
                       kit / "tools/vu_whole_aot/generate.py", kit / "tools/vu_whole_aot/decode.py"],
          generate_vu, lambda: [p for p in vu.rglob("*") if p.is_file()], jobs=jobs)
    print("Compiling the game locally (the first build can take a while)", flush=True)
    compile_native(kit, generated, work, output, jobs)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ["kit", "disc", "work", "output"]:
        parser.add_argument("--" + name, type=Path, required=True)
    parser.add_argument("--jobs", type=int, default=2)
    args = parser.parse_args()
    build(args.kit, args.disc, args.work, args.output, args.jobs)
