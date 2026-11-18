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

# The entry script can fit below MAX_PATH while a longer-named sibling module
# does not. Normalize the import directory before loading any build helpers.
from long_paths import extended, native
_import_paths = sys.path[:]
sys.path.insert(0, str(extended(Path(__file__).parent)))
try:
    from compile_game import compile_plan, msvc_environment
    from generate_game import generate, GAMES, plain_generation_path, checked_staging_parent
    from reconstruct_vu import reconstruct
    from source_recipes import apply_plan
    from generate_queue_control import generate as generate_queue_control
finally:
    sys.path[:] = _import_paths
del _import_paths


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


def game_profile(kit, requested=None):
    """Bind worker inputs to the selected kit, never to a File #1 default ELF."""
    plan = json.loads((Path(kit) / "compile-plan.json").read_text())
    game = plan.get("game", "file1")
    if game not in GAMES or (requested is not None and requested != game):
        raise ValueError("Requested game differs from this build kit")
    profile = GAMES[game]
    if plan.get("elfSha256", profile["sha256"]) != profile["sha256"]:
        raise ValueError("Build kit game and ELF revision disagree")
    return game, profile


def generation_staging_parent(kit, generated, work, output, *, compiler_environment=None):
    """Prove the new staging location is outside compiler/header search roots.

    Existing unleased staging is never relocated. This controls only where the
    current invocation will create a fresh unique directory.
    """
    kit, generated, work, output = map(plain_generation_path, (kit, generated, work, output))
    parent = work / "generation-staging"
    if generated == work or not generated.is_relative_to(work):
        raise ValueError("Canonical generation escaped the owned work directory")
    plan = json.loads(extended(kit / "compile-plan.json").read_text())
    values = {"{kit}": str(kit), "{generated}": str(generated), "{work}": str(work),
              "{output}": str(output)}
    if plan.get("toolchain") == "llvm-mingw":
        from compile_game import portable_root
        values["{kit}/toolchain"] = str(portable_root(kit, plan))
    def expand(value):
        for key in sorted(values, key=len, reverse=True):
            value = value.replace(key, values[key])
        if "{" in value or "}" in value:
            raise ValueError("Cannot prove generation staging against an unknown include substitution")
        return Path(native(Path(os.path.abspath(native(value))).resolve()))
    roots = {expand(str(kit)), expand(str(generated)), expand(str(generated.parent.parent))}
    if plan.get("toolchain") == "llvm-mingw":
        roots.add(expand(values["{kit}/toolchain"]))
    environment = dict(os.environ)
    if compiler_environment is not None:
        environment.update(compiler_environment)
    for name in ("INCLUDE", "CPATH", "CPLUS_INCLUDE_PATH", "C_INCLUDE_PATH", "OBJC_INCLUDE_PATH"):
        if name in environment:
            roots.update(expand(part or os.curdir) for part in environment[name].split(os.pathsep))
    options = list(plan.get("compileOptions", []))
    for unit in plan.get("units", []):
        options.extend(unit.get("options", []))
        roots.update(expand(source).parent for source in unit.get("sources", []))
    for group in plan.get("sourceGroups", []):
        options.extend(group.get("options", []))
        roots.add(expand(group["root"]))
    i = 0
    while i < len(options):
        option = options[i]
        # Include-directory spellings and forced includes have path semantics.
        # Account for joined and split arguments without parsing shell text.
        prefix = next((p for p in ("/external:I", "-include-pch", "-idirafter", "-isystem", "-imacros", "-iquote", "-include", "/FI", "/I", "-I")
                       if option.startswith(p)), None)
        if prefix:
            location = option[len(prefix):]
            if not location:
                i += 1
                if i >= len(options):
                    raise ValueError("Incomplete compile-plan include option")
                location = options[i]
            root = expand(location)
            roots.add(root.parent if prefix in ("-include-pch", "-imacros", "-include", "/FI") else root)
        i += 1
    resolved_parent = parent.resolve()
    if any(resolved_parent.is_relative_to(root) or root.is_relative_to(resolved_parent) for root in roots):
        raise ValueError("Generation staging overlaps a compiler/header input root; no directory was moved")
    parent = checked_staging_parent(generated, parent, owned_work=work)
    record = {"schema": 1, "policy": "fresh-staging-outside-input-roots", "legacyMoved": False,
              "stagingParent": str(plain_generation_path(parent)), "canonicalDestination": str(generated),
              "inputRoots": sorted(str(root) for root in roots)}
    receipt = plain_generation_path(work / "generation-staging-policy.json")
    extended(receipt).write_text(json.dumps(record, indent=2) + "\n")
    return parent


def note_legacy_generation_staging(work, generated):
    """Retain unleased historical directories, including potentially live ones."""
    work, generated = map(plain_generation_path, (work, generated))
    if not generated.is_relative_to(work):
        raise ValueError("Canonical generation escaped the owned work directory")
    if not extended(generated.parent).is_dir():
        return
    names = sorted(path.name for path in extended(generated.parent).iterdir()
                   if path.name.startswith(generated.name + ".generating-"))
    if not names:
        return
    record = {"schema": 1, "moved": False, "names": names,
              "parent": str(generated.parent),
              "reason": "Legacy staging has no producer lease; inactivity cannot be proved. Files remain in place and in the ordinary header fingerprint."}
    receipt = plain_generation_path(work / "generation-legacy-staging.json")
    extended(receipt).write_text(json.dumps(record, indent=2) + "\n")
    print("Preserving unleased legacy generation staging in place (" + str(len(names)) +
          "); inactivity cannot be proved", flush=True)


def build(kit, disc, work, output, jobs, game=None, preflight=False):
    plain_generation_path(work)
    kit, disc, work, output = map(extended, (kit, disc, work, output))
    game, profile = game_profile(kit, game)
    if preflight and sys.platform != "win32":
        raise ValueError("The authored-unit preflight is currently supported by the Windows compile worker")
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
    plain_generation_path(project)
    plain_generation_path(project / "recomp/config")
    project.mkdir(exist_ok=True)
    print("Preparing independent runtime sources", flush=True)
    shutil.copytree(extended(kit / "source"), extended(project), dirs_exist_ok=True)
    metadata = kit / "metadata"
    generated = project / "recomp/config"
    elf = disc / profile["elf"]
    script = extended(Path(__file__).parent)
    metadata_files = [p for p in sorted(metadata.rglob("*")) if p.is_file() and p.name not in
                      {"local_queue_control.json", "local_vu_images.json"}]
    note_legacy_generation_staging(work, generated)

    def game_generation():
        staging_parent = generation_staging_parent(kit, generated, work, output,
            compiler_environment=env if sys.platform == "win32" else os.environ)
        if generated.exists():
            # This happens only after interruption/corruption of a previous
            # stage. Keep its files under an unused diagnostic name.
            n = 0
            while generated.with_name("config.interrupted" + str(n)).exists():
                n += 1
            generated.rename(generated.with_name("config.interrupted" + str(n)))
        generate(recompiler, disc, metadata, generated, jobs=jobs, game=game,
                 staging_parent=staging_parent)

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
    if preflight:
        print("Checking authored/runtime compilation units before generated game compilation", flush=True)
        compile_native(kit, generated, work, output, jobs, preflight=True)
    else:
        print("Compiling the game locally (the first build can take a while)", flush=True)
        compile_native(kit, generated, work, output, jobs)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ["kit", "disc", "work", "output"]:
        parser.add_argument("--" + name, type=Path, required=True)
    parser.add_argument("--jobs", type=int, default=2)
    parser.add_argument("--game", choices=sorted(GAMES), help="Must match the verified build kit")
    parser.add_argument("--preflight", action="store_true",
                        help="Compile authored/runtime units only; do not compile generated game groups or link")
    args = parser.parse_args()
    build(args.kit, args.disc, args.work, args.output, args.jobs, args.game, args.preflight)
