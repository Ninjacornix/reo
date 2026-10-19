#!/usr/bin/env python3
"""Compile private generated sources and link against audited independent inputs.

The plan contains file paths/options, not commercial game instructions. Object
receipts make interrupted builds resumable. Microsoft tools are discovered from
an existing installation; this worker never downloads or installs software.
"""

import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import tempfile


def digest(path):
    with Path(path).open("rb") as f:
        return hashlib.file_digest(f, "sha256").hexdigest()


def msvc_environment():
    vswhere = Path(os.environ.get("ProgramFiles(x86)", r"C:\Program Files (x86)")) / "Microsoft Visual Studio/Installer/vswhere.exe"
    if not vswhere.is_file():
        raise RuntimeError("Microsoft C++ tools are not installed. Compiler provisioning must finish before this step.")
    installation = subprocess.check_output([str(vswhere), "-latest", "-products", "*", "-requires",
        "Microsoft.VisualStudio.Component.VC.Tools.x86.x64", "-version", "[17.13,18.0)",
        "-property", "installationPath"], text=True).strip()
    if not installation:
        raise RuntimeError("No compatible Microsoft C++ toolchain was found")
    vcvars = Path(installation) / "VC/Auxiliary/Build/vcvars64.bat"
    # This command contains only the trusted installer-provided toolchain path;
    # no ISO, generated-source, account or user-selected argument is shell text.
    with tempfile.NamedTemporaryFile(suffix=".cmd", prefix="reo-vc-env-", delete=False) as f:
        batch = Path(f.name)
        f.write(b'@echo off\r\ncall "%~1" >nul\r\nif errorlevel 1 exit /b 1\r\nset\r\n')
    try:
        result = subprocess.check_output(["cmd.exe", "/d", "/c", str(batch), str(vcvars)],
                                         text=True, errors="replace")
    finally:
        batch.unlink()
    env = dict(os.environ)
    for row in result.splitlines():
        if "=" in row and not row.startswith("="):
            key, value = row.split("=", 1)
            env[key] = value
    toolroot = Path(env["VCToolsInstallDir"]) / "bin/Hostx64/x64"
    return env, toolroot / "cl.exe", toolroot / "link.exe"


def compile_plan(kit, generated, work, output, jobs, plan_name="compile-plan.json"):
    kit, generated, work, output = map(lambda p: Path(p).resolve(), (kit, generated, work, output))
    plan = json.loads((kit / plan_name).read_text())
    if plan.get("format") != 1 or not plan.get("runtimeAbi") or not (plan.get("units") or plan.get("sourceGroups")):
        raise ValueError("Invalid local compilation plan")
    env, compiler, linker = msvc_environment()
    values = {"{kit}": str(kit), "{generated}": str(generated), "{work}": str(work),
              "{output}": str(output)}

    def expand(value):
        for name, replacement in values.items():
            value = value.replace(name, replacement)
        if "{" in value or "}" in value:
            raise ValueError("Unknown compile-plan substitution")
        return value

    def source_file(value):
        path = Path(expand(value)).resolve()
        if not any(path.is_relative_to(parent) for parent in (kit, generated, work)):
            raise ValueError("Source input escapes the build kit/private workspace")
        if not path.is_file():
            raise FileNotFoundError(path)
        return path

    units = list(plan.get("units", []))
    for group in plan.get("sourceGroups", []):
        parent = Path(expand(group["root"])).resolve()
        if not parent.is_relative_to(generated):
            raise ValueError("Generated source group escapes the private generation directory")
        batch, size, index = [], 0, 0
        for file in sorted(parent.glob(group["pattern"])):
            if not file.is_file() or file.suffix != ".cpp":
                continue
            if batch and (len(batch) >= group.get("batch", 8) or size + file.stat().st_size > 500000):
                units.append({"id": group["id"] + str(index), "sources": batch,
                              "options": group.get("options", [])})
                batch, size, index = [], 0, index + 1
            batch.append(str(file))
            size += file.stat().st_size
        if batch:
            units.append({"id": group["id"] + str(index), "sources": batch,
                          "options": group.get("options", [])})
        if not batch and index == 0:
            raise ValueError("Generated source group is empty")

    work.mkdir(parents=True, exist_ok=True)
    output.mkdir(parents=True, exist_ok=True)
    objects, logs = work / "objects", work / "compile-logs"
    objects.mkdir(exist_ok=True)
    logs.mkdir(exist_ok=True)
    # Header changes must invalidate users of inline runtime/ISA operations.
    header_hash = hashlib.sha256()
    for parent in (kit, generated):
        for p in sorted(parent.rglob("*")):
            if p.is_file() and p.suffix in {".h", ".hpp", ".inl", ".inc"}:
                header_hash.update(str(p.relative_to(parent)).encode())
                header_hash.update(bytes.fromhex(digest(p)))
    base = json.dumps({"abi": plan["runtimeAbi"], "compiler": digest(compiler),
                       "headers": header_hash.hexdigest(), "plan": digest(kit / plan_name)}, sort_keys=True)
    common = [expand(flag) for flag in plan.get("compileOptions", [])]
    names = set()
    for unit in units:
        if not re.fullmatch(r"[A-Za-z0-9_-]+", unit["id"]) or unit["id"] in names:
            raise ValueError("Invalid or duplicate compile-unit identity")
        names.add(unit["id"])
        if not unit.get("sources"):
            raise ValueError("Empty compile unit")

    def compile_unit(unit):
        name = unit["id"]
        sources = [source_file(p) for p in unit["sources"]]
        options = common + [expand(o) for o in unit.get("options", [])]
        signature = hashlib.sha256((base + json.dumps(options) +
            "".join(str(p) + digest(p) for p in sources)).encode()).hexdigest()
        obj, receipt = objects / (name + ".obj"), objects / (name + ".json")
        if obj.exists() and receipt.exists():
            saved = json.loads(receipt.read_text())
            if saved.get("input") == signature and saved.get("object") == digest(obj):
                return obj, True
        source = objects / (name + ".cpp")
        # Includes preserve each generated function's original header search base.
        source.write_text("\n".join('#include ' + json.dumps(str(p).replace("\\", "/"))
                                     for p in sources) + "\n")
        pending = objects / (name + ".pending.obj")
        command = [str(compiler), "/nologo", "/c", "/TP", "/O2", "/Ob2", "/MD",
                   "/DNDEBUG", "/EHsc", "/std:c++20", "/bigobj", "/fp:precise",
                   *options, "/Fo" + str(pending), str(source)]
        with (logs / (name + ".log")).open("wb") as log:
            result = subprocess.run(command, env=env, stdout=log, stderr=subprocess.STDOUT)
        if result.returncode:
            raise RuntimeError(f"Compile unit {name} failed (exit {result.returncode}); see {logs / (name + '.log')}")
        pending.replace(obj)
        temporary = receipt.with_suffix(".tmp")
        temporary.write_text(json.dumps({"input": signature, "object": digest(obj)}))
        temporary.replace(receipt)
        return obj, False

    completed, reused = {}, 0
    jobs = max(1, min(jobs, 4))
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        futures = {pool.submit(compile_unit, unit): unit for unit in units}
        try:
            for future in as_completed(futures):
                obj, cached = future.result()
                completed[futures[future]["id"]] = obj
                reused += cached
                print(f"Compiled {len(completed)}/{len(futures)} ({reused} cached)", flush=True)
        except BaseException:
            for future in futures:
                future.cancel()
            raise
    link_inputs = []
    for item in plan.get("independentInputs", []):
        path = source_file(item["path"])
        if item.get("provenance") not in {"authored-runtime", "third-party"} or digest(path) != item["sha256"]:
            raise ValueError("An independent runtime input failed provenance/integrity verification")
        link_inputs.append(str(path))
    archives = {}
    for unit in units:
        if unit.get("archive"):
            if not re.fullmatch(r"[A-Za-z0-9_-]+", unit["archive"]):
                raise ValueError("Invalid local archive identity")
            archives.setdefault(unit["archive"], []).append(completed[unit["id"]])
    archive_inputs = []
    for name, members in archives.items():
        target = objects / (name + ".lib")
        response = objects / (name + ".rsp")
        response.write_text("\n".join(subprocess.list2cmdline([str(p)]) for p in members))
        with (logs / (name + "-archive.log")).open("wb") as log:
            subprocess.run([str(linker.parent / "lib.exe"), "/NOLOGO", "/OUT:" + str(target), "@" + str(response)],
                           env=env, stdout=log, stderr=subprocess.STDOUT, check=True)
        archive_inputs.append(str(target))
    args = [str(completed[u["id"]]) for u in units if not u.get("archive")] + archive_inputs + link_inputs
    args += [expand(arg) for arg in plan.get("linkOptions", [])]
    args += ["/NOLOGO", "/INCREMENTAL:NO", "/OUT:" + str(output / "reo_recomp.exe")]
    response = work / "local-game-link.rsp"
    response.write_text("\n".join(subprocess.list2cmdline([arg]) for arg in args), encoding="utf-8")
    print("Linking locally generated game", flush=True)
    with (logs / "link.log").open("wb") as log:
        subprocess.run([str(linker), "@" + str(response)], env=env, stdout=log,
                       stderr=subprocess.STDOUT, check=True)
    for entry in plan.get("copyOutputs", []):
        source = source_file(entry["source"])
        relative = Path(entry["destination"])
        if relative.is_absolute() or ".." in relative.parts or ":" in str(relative):
            raise ValueError("Output copy escapes the private game build")
        target = output / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(source, target)
    if plan.get("copyLocalCrt"):
        crt = Path(env["VCToolsRedistDir"]) / "x64/Microsoft.VC143.CRT"
        for name in ["msvcp140.dll", "msvcp140_atomic_wait.dll", "vcruntime140.dll", "vcruntime140_1.dll"]:
            shutil.copyfile(crt / name, output / name)
    print(f"Local game compiled: {len(completed)} units, {reused} reused", flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--kit", required=True, type=Path)
    parser.add_argument("--generated", required=True, type=Path)
    parser.add_argument("--work", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--jobs", type=int, default=2)
    args = parser.parse_args()
    compile_plan(args.kit, args.generated, args.work, args.output, args.jobs)


if __name__ == "__main__":
    main()
