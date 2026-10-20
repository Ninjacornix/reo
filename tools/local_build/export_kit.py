"""Maintainer exporter for an ISO-derived local build kit (never a game binary).

Uses the working build graph to preserve compile definitions and dependency
versions. Runtime/backend sources that can embed local instruction witnesses
are compiled on the user's machine, together with generated game sources.
"""

import argparse
import ctypes
import hashlib
import json
from pathlib import Path
import re
import shutil
import subprocess

from compilation_batches import GENERATED_BATCH_SIZE


def sha(path):
    with Path(path).open("rb") as f:
        return hashlib.file_digest(f, "sha256").hexdigest()


def arguments(command):
    count = ctypes.c_int()
    parse = ctypes.windll.shell32.CommandLineToArgvW
    parse.argtypes = [ctypes.c_wchar_p, ctypes.POINTER(ctypes.c_int)]
    parse.restype = ctypes.POINTER(ctypes.c_wchar_p)
    values = parse(command, ctypes.byref(count))
    try:
        return [values[i] for i in range(count.value)]
    finally:
        ctypes.windll.kernel32.LocalFree(ctypes.cast(values, ctypes.c_void_p))


def export(root, build, dependency, destination, recompiler, recipe_plan=None):
    root, build, dependency, destination = [Path(p).resolve() for p in (root, build, dependency, destination)]
    if destination.exists():
        raise FileExistsError("Build kit outputs are immutable; choose a fresh directory")
    destination.mkdir(parents=True)
    source_root = destination / "source"

    def copy(source, relative):
        source = Path(source)
        target = destination / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(source, target)
        return target

    # Root checkout's generated/copied files are ignored by git; only tracked
    # headers are eligible here. The dependency proof has the published patches.
    tracked = subprocess.check_output(["git", "ls-files", "-z"], cwd=root).decode().split("\0")
    for name in filter(None, tracked):
        if Path(name).suffix in {".h", ".hpp", ".inl", ".inc"}:
            if "resident_geometry/upstream/shaders/" not in name and not name.endswith("/queue_control_body.inc"):
                copy(root / name, "source/" + name)
    # New authored account plumbing is also needed in development exports before commit.
    copy(root / "network/native/automatic_account.h", "source/network/native/automatic_account.h")
    for part in ["ps2xRuntime", "ps2xRecomp/include"]:
        for file in (dependency / part).rglob("*"):
            if file.is_file() and file.suffix in {".h", ".hpp", ".inl", ".inc"} and "local_source_catalogues" not in file.parts:
                copy(file, "source/third_party/PS2Recomp/" + file.relative_to(dependency).as_posix())
    third_party_headers = [build / "parallel-gs-source",
                          root / "third_party/PS2Recomp/out/build/_deps/fmt-src/include",
                          root / "third_party/PS2Recomp/out/build/_deps/raylib-src/src",
                          root / "third_party/PS2Recomp/out/build/_deps/elfio-src/include"]
    for parent in third_party_headers:
        for file in parent.rglob("*"):
            if file.is_file() and file.suffix in {".h", ".hpp", ".inl", ".inc"}:
                copy(file, "source/" + file.relative_to(root).as_posix())
    for file in (root / "deps/elfio/elfio").rglob("*.hpp"):
        copy(file, "source/third_party/PS2Recomp/out/build/_deps/elfio-src/include/elfio/" +
             file.relative_to(root / "deps/elfio/elfio").as_posix())
    # Generic upstream-derived sampler shader, compiled independently of game
    # instructions; the backend's include directory points here in the graph.
    for file in (build / "recomp/anisotropic-shaders").glob("*.hpp"):
        copy(file, "source/" + file.relative_to(root).as_posix())

    def relocate(path):
        absolute = Path(path).resolve()
        try:
            return "{work}/project/" + absolute.relative_to(root).as_posix()
        except ValueError:
            raise ValueError("Build references an unexported external path: " + str(path))

    def options(command):
        args = arguments(command)
        flags = []
        i = 0
        while i < len(args):
            arg = args[i]
            if arg in {"/D", "-D", "/I", "-I"}:
                arg += args[i + 1]
                i += 1
            if arg.startswith(("/I", "-I")):
                flags.append("/I" + relocate(arg[2:]))
            elif arg.startswith(("/D", "-D")):
                if "CMAKE_INTDIR" not in arg:
                    flags.append("/D" + arg[2:])
            elif arg in {"/Od", "/fp:precise", "/arch:AVX", "/arch:AVX2"}:
                flags.append(arg)
            i += 1
        return flags

    compdb = json.loads((build / "public-safety/compdb.json").read_text())
    records = {str(Path(row["file"]).resolve()).lower(): row for row in compdb
               if str(row["file"]).endswith((".cpp", ".cxx"))}
    inventory = json.loads((build / "public-safety/source-unit-inventory.json").read_text())
    copied = set()
    units = []
    for record in inventory:
        if "generated-vu-or-local" in record["kinds"]:
            continue
        for file, kind in zip(record["sources"], record["kinds"]):
            if kind == "main/overlay-generated":
                continue
            source = Path(file).resolve()
            row = records.get(str(source).lower())
            if row is None:
                # A unity member inherits the flags of its owning translation unit.
                row = next(r for r in compdb if record["object"].replace("/", "\\") in r["command"])
            relative = source.relative_to(root).as_posix()
            if kind != "copied-body":
                copy(source, "source/" + relative)
                copied.add(relative)
            units.append({"id": "authored" + str(len(units)), "sources": [relocate(source)],
                          "options": options(row["command"])})
    # Both backend libraries are rebuilt locally to avoid embedded witnesses and
    # to keep their C++ ABI exactly aligned with the runtime headers.
    for row in compdb:
        if not str(row["file"]).endswith(".cpp"):
            continue
        if not any(name in row["command"] for name in ("reo_parallel_backend_native.dir", "reo_parallel_gs_resident_native.dir")):
            continue
        path = Path(row["file"]).resolve()
        copy(path, "source/" + path.relative_to(root).as_posix())
        units.append({"id": "backend" + str(len(units)), "sources": [relocate(path)],
                      "archive": "resident" if "reo_parallel_gs_resident_native.dir" in row["command"] else "backend",
                      "options": options(row["command"])})
    tlog = root / "third_party/PS2Recomp/out/build/ps2xRuntime/ps2_runtime.dir/Release/ps2_runtime.tlog/CL.command.1.tlog"
    lines = tlog.read_text(encoding="utf-16").splitlines()
    for n in range(0, len(lines), 2):
        path = Path(lines[n].removeprefix("^")).resolve()
        if path.suffix.lower() != ".cpp":
            raise ValueError("Unexpected runtime compilation record")
        relative = path.relative_to(root / "third_party/PS2Recomp").as_posix()
        copy(dependency / relative, "source/third_party/PS2Recomp/" + relative)
        units.append({"id": "runtime" + str(len(units)), "sources": [relocate(path)], "archive": "runtime",
                      "options": options(lines[n + 1])})

    sample = next(r for r in compdb if "unity_0_cxx.cxx" in r["file"] and "reo_recomp.dir" in r["command"])
    generated_options = options(sample["command"])
    for folder, name in [("vu/specialized", "reo_vu_specialized_generated.cpp"),
                         ("vu/whole", "reo_vu_whole_registered_generated.cpp")]:
        original = next(r for r in compdb if str(r["file"]).endswith(name))
        unit_options = options(original["command"])
        # Replace developer-only generated include directories with private ones.
        unit_options = [o for o in unit_options if "m2-vu-" not in o]
        unit_options += ["/I{generated}/vu/specialized", "/I{generated}/vu/whole"]
        units.append({"id": name.removesuffix(".cpp"), "sources": ["{generated}/" + folder + "/" + name],
                      "options": unit_options})
    groups = [{"id": name, "root": "{generated}/" + folder, "pattern": pattern,
               "batch": batch, "options": generated_options}
              for name, folder, pattern, batch in [("main", "output", "*.cpp", GENERATED_BATCH_SIZE),
                  ("overlay", "output_ovl", "**/*.cpp", GENERATED_BATCH_SIZE),
                  ("extra", "output_extra", "*.cpp", GENERATED_BATCH_SIZE),
                  ("legacy", "output_overlay", "*.cpp", 1)]]
    cache = (build / "CMakeCache.txt").read_text()
    match = re.search(r"(?m)^REO_RECOMP_OD_SOURCES:STRING=(.*)$", cache)
    od_names = match[1].split(";") if match and match[1] else []
    if od_names:
        for group in groups:
            group["exclude"] = od_names
        old_generated = json.loads((build / "public-safety/current-generated-sources.json").read_text())
        for n, name in enumerate(od_names):
            paths = [Path(p) for p in old_generated if Path(p).name == name]
            if len(paths) != 1:
                raise ValueError("Per-function compiler exception cannot be mapped exactly")
            relative = paths[0].relative_to(root / "recomp/config").as_posix()
            units.append({"id": "originalOd" + str(n), "sources": ["{generated}/" + relative],
                          "options": generated_options + ["/Od"]})
    # Link only independent upstream libraries; Microsoft SDK libs are resolved
    # from the user's toolchain and never copied into the distribution.
    ninja = (build / "build.ninja").read_text()
    start = ninja.index("build recomp\\reo_recomp.exe:")
    variables = ninja[start:ninja.index("\nbuild ", start + 6)]
    libs = re.search(r"(?m)^  LINK_LIBRARIES = (.*)$", variables)[1].split()
    independent, system = [], []
    for value in libs:
        if value in {"recomp\\reo_parallel_backend_native.lib", "recomp\\reo_parallel_gs_resident_native.lib"} or value.endswith("ps2_runtime.lib"):
            continue
        if ":" in value or "\\" in value or "/" in value:
            source = Path(value)
            if not source.is_absolute():
                source = build / source
            filename = source.name
            target = copy(source, "libraries/" + filename)
            independent.append({"path": "{kit}/libraries/" + filename, "sha256": sha(target), "provenance": "third-party"})
        elif value not in system:
            system.append(value)
    shaders = []
    for source in (build / "recomp/reo_recomp-present-shaders").glob("*.spv"):
        copy(source, "shaders/" + source.name)
        shaders.append({"source": "{kit}/shaders/" + source.name,
                        "destination": "reo-gpu-present/" + source.name})
    plan = {"format": 1, "runtimeAbi": "outbreak-local-1", "units": units, "sourceGroups": groups,
            "compileOptions": ["/I{work}/project/tools/vu_whole_aot", "/I{generated}/output", "/I{generated}/output_overlay",
                               "/I{work}/project/third_party/PS2Recomp/ps2xRuntime/src/lib",
                               "/I{generated}/vu/specialized", "/I{generated}/vu/whole"],
            "independentInputs": independent,
            "linkOptions": ["/MACHINE:X64", "/SUBSYSTEM:CONSOLE", "/MANIFEST:EMBED",
                            "/MANIFESTINPUT:{kit}/tools/native.manifest", *system],
            "copyOutputs": shaders, "copyLocalCrt": True}
    source_recipes = json.loads(Path(recipe_plan or root / "recomp/config/local_source_recipes.json").read_text())
    plan["generatedSourceOverrides"] = {
        row["source"]: "{work}/project/" + row["destination"] for row in source_recipes["recipes"]
        if row["destination"].startswith("generated-overrides/")}
    (destination / "compile-plan.json").write_text(json.dumps(plan, indent=2) + "\n")
    for source in (root / "recomp/config").glob("*.json"):
        if source.name.startswith("local_"):
            copy(source, "metadata/" + source.name)
    (destination / "metadata/local_source_recipes.json").write_text(json.dumps(source_recipes, indent=2))
    for source in [root / "recomp/config/outbreak_ghidra_functions.csv", root / "recomp/config/extra_functions.csv",
                   root / "recomp/config/outbreak.toml"]:
        copy(source, "metadata/" + source.name)
    for source in (root / "recomp/config/overlay_maps").glob("*.csv"):
        copy(source, "metadata/overlay_maps/" + source.name)
    for parent in [root / "tools/local_build", root / "tools/vu_whole_aot"]:
        for source in parent.glob("*.py"):
            copy(source, "tools/" + parent.name + "/" + source.name)
    copy(root / "tools/overlay_extract.py", "tools/overlay_extract.py")
    copy(root / "launcher/native.manifest", "tools/native.manifest")
    for source, name in [(root / "launcher/Assets/game-icon.rc", "game-icon.rc"),
                         (root / "launcher/Assets/app-icon.ico", "app-icon.ico"),
                         (root / "launcher/native.manifest", "native.manifest")]:
        copy(source, "resources/" + name)
    copy(root / "tools/vu_whole_aot/vu_math_helpers.h", "source/tools/vu_whole_aot/vu_math_helpers.h")
    copy(root / "tools/vu_whole_aot/vu_math_helpers.h", "tools/vu_whole_aot/vu_math_helpers.h")
    copy(root / "tools/vu_whole_aot/vu_specialized_helpers.h", "source/tools/vu_whole_aot/vu_specialized_helpers.h")
    copy(recompiler, "tools/ps2_recomp.exe")
    for source in [root / "LICENSE", root / "NOTICE.md", root / "THIRD_PARTY_NOTICES.md"]:
        if source.exists():
            copy(source, "notices/" + source.name)
    for source in (root / "LICENSES").rglob("*"):
        if source.is_file():
            copy(source, "notices/LICENSES/" + source.relative_to(root / "LICENSES").as_posix())
    for parent in [root / "third_party/PS2Recomp", *third_party_headers]:
        # Preserve the licence of each included dependency, including Granite's
        # vendored Vulkan/volk/math components. No object files enter this path.
        for source in parent.rglob("*"):
            if source.is_file() and source.name.lower().startswith(("license", "licence", "copying", "copyright")):
                if "out" not in source.relative_to(parent).parts and ".git" not in source.parts:
                    relative = source.relative_to(root).as_posix()
                    copy(source, "notices/upstream/" + relative)
    print(f"Exported {len(units)} authored/local runtime units plus generated source groups; no game objects/executable")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[2])
    parser.add_argument("--build", type=Path, required=True)
    parser.add_argument("--dependency", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--recompiler", type=Path, required=True,
                        help="Fresh independent compiler built from the exported patched dependency revision")
    parser.add_argument("--recipe-plan", type=Path,
                        help="Instrumentation recipes verified against this recompiler's fresh output")
    args = parser.parse_args()
    export(args.root, args.build, args.dependency, args.output, args.recompiler, args.recipe_plan)
