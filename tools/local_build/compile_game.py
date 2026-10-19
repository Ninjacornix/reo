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


def portable_flags(options):
    result = []
    for option in options:
        if option.startswith(("/D", "/I")):
            result.append("-" + option[1:])
        elif option == "/Od":
            result.append("-O0")
        elif option == "/arch:AVX":
            result.append("-mavx")
        elif option == "/arch:AVX2":
            result.append("-mavx2")
        elif option == "/fp:precise":
            result.extend(["-fno-fast-math", "-ffp-contract=off"])
        else:
            raise ValueError("Unsupported portable compile flag: " + option)
    return result


def response_text(arguments, portable=False):
    if portable:
        return "\n".join(json.dumps(str(arg).replace("\\", "/")) for arg in arguments)
    return "\n".join(subprocess.list2cmdline([str(arg)]) for arg in arguments)


def portable_environment(kit, plan):
    tools = []
    for key in ("compiler", "archiver", "resourceCompiler"):
        relative = plan[key]
        if not relative.startswith("{kit}/"):
            raise ValueError("A portable tool must be bundled in the build kit")
        path = (kit / relative.removeprefix("{kit}/")).resolve()
        if not path.is_relative_to(kit) or not path.is_file():
            raise ValueError("Portable tool escapes its verified build kit")
        tools.append(path)
    env = {k: v for k, v in os.environ.items()
           if k.upper() not in {"INCLUDE", "LIB", "LIBPATH", "CL", "_CL_", "CPATH",
                                "C_INCLUDE_PATH", "CPLUS_INCLUDE_PATH", "LIBRARY_PATH"}}
    system_root = next((v for k, v in env.items() if k.upper() == "SYSTEMROOT"), None)
    if not system_root:
        raise RuntimeError("The Windows system directory is unavailable")
    system = Path(system_root)
    env["PATH"] = os.pathsep.join(map(str, (tools[0].parent, system / "System32", system)))
    return env, tools


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
        capture_env = dict(os.environ)
        capture_env["REO_BUILD_CAPTURE_SCRIPT"] = str(batch)
        capture_env["REO_BUILD_VCVARS_SCRIPT"] = str(vcvars)
        command = 'cmd.exe /d /u /s /c ""%REO_BUILD_CAPTURE_SCRIPT%" "%REO_BUILD_VCVARS_SCRIPT%""'
        result = subprocess.check_output(command,
            executable=str(Path(os.environ["SystemRoot"]) / "System32/cmd.exe"),
            env=capture_env, encoding="utf-16-le", errors="strict")
    finally:
        batch.unlink()
    env = dict(os.environ)
    for row in result.splitlines():
        if "=" in row and not row.startswith("="):
            key, value = row.split("=", 1)
            env[key] = value
    toolroot = Path(env["VCToolsInstallDir"]) / "bin/Hostx64/x64"
    env.pop("REO_BUILD_CAPTURE_SCRIPT", None)
    env.pop("REO_BUILD_VCVARS_SCRIPT", None)
    return env, toolroot / "cl.exe", toolroot / "link.exe"


def compile_plan(kit, generated, work, output, jobs, plan_name="compile-plan.json", preflight=False):
    kit, generated, work, output = map(lambda p: Path(p).resolve(), (kit, generated, work, output))
    plan = json.loads((kit / plan_name).read_text())
    if plan.get("format") != 1 or not plan.get("runtimeAbi") or not (plan.get("units") or plan.get("sourceGroups")):
        raise ValueError("Invalid local compilation plan")
    portable = plan.get("toolchain") == "llvm-mingw"
    if portable:
        env, (compiler, archiver, resource_compiler) = portable_environment(kit, plan)
        linker = compiler
    else:
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
    for group in ([] if preflight else plan.get("sourceGroups", [])):
        parent = Path(expand(group["root"])).resolve()
        if not parent.is_relative_to(generated):
            raise ValueError("Generated source group escapes the private generation directory")
        batch, size, index, includes = [], 0, 0, []
        replacements = plan.get("generatedSourceOverrides", {})
        for file in sorted(parent.glob(group["pattern"])):
            if not file.is_file() or file.suffix != ".cpp" or file.name in group.get("exclude", []):
                continue
            if batch and (len(batch) >= group.get("batch", 8) or size + file.stat().st_size > 500000):
                units.append({"id": group["id"] + str(index), "sources": batch,
                              "options": group.get("options", []) + includes, "generated": True})
                batch, size, index, includes = [], 0, index + 1, []
            replacement = replacements.get(file.relative_to(generated).as_posix())
            batch.append(expand(replacement) if replacement else str(file))
            if replacement:
                flag = "/I" + str(file.parent)
                if flag not in includes:
                    includes.append(flag)
            size += file.stat().st_size
        if batch:
            units.append({"id": group["id"] + str(index), "sources": batch,
                          "options": group.get("options", []) + includes, "generated": True})
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
    base = json.dumps({"abi": plan["runtimeAbi"], "compiler": digest(compiler), "worker": digest(Path(__file__)),
                       "headers": header_hash.hexdigest(), "plan": digest(kit / plan_name)}, sort_keys=True)
    common = [expand(flag) for flag in plan.get("compileOptions", [])]
    names = set()
    for unit in units:
        if not re.fullmatch(r"[A-Za-z0-9_-]+", unit["id"]) or unit["id"] in names:
            raise ValueError("Invalid or duplicate compile-unit identity")
        names.add(unit["id"])
        if not unit.get("sources"):
            raise ValueError("Empty compile unit")

    portable_defaults = ["-O2", "-DNDEBUG", "-std=c++20", "-msse4.1", "-fms-extensions",
                         "-fno-fast-math", "-ffp-contract=off", "-fno-strict-aliasing", "-fwrapv"]
    precompiled = {}
    if portable and not preflight:
        pch_root = work / "precompiled-headers"
        pch_root.mkdir(exist_ok=True)
        preamble = '#include "ps2_runtime_macros.h"\n#include "ps2_runtime.h"\n#include "source_instruction_access.hpp"\n'
        for unit in units:
            if not unit.get("generated"):
                continue
            options = common + [expand(o) for o in unit.get("options", [])]
            key = hashlib.sha256((base + json.dumps(options) + preamble).encode()).hexdigest()
            unit["pch"] = key
            if key in precompiled:
                continue
            header, pch, receipt = (pch_root / (key + suffix) for suffix in (".hpp", ".pch", ".json"))
            valid = False
            if pch.is_file() and receipt.is_file():
                try:
                    valid = json.loads(receipt.read_text()).get("sha256") == digest(pch)
                except (OSError, ValueError):
                    pass
            if not valid:
                header.write_text(preamble, encoding="utf-8")
                pending = pch.with_suffix(".pending.pch")
                print("Precompiling shared guest headers", flush=True)
                with (logs / (key + "-pch.log")).open("wb") as log:
                    subprocess.run([str(compiler), *portable_defaults, *portable_flags(options),
                                    "-x", "c++-header", str(header), "-o", str(pending)], env=env,
                                   stdout=log, stderr=subprocess.STDOUT, check=True)
                pending.replace(pch)
                receipt.write_text(json.dumps({"sha256": digest(pch)}))
            precompiled[key] = pch

    def compile_unit(unit):
        name = unit["id"]
        sources = [source_file(p) for p in unit["sources"]]
        options = common + [expand(o) for o in unit.get("options", [])]
        signature = hashlib.sha256((base + json.dumps(options) + unit.get("pch", "") +
            "".join(str(p) + digest(p) for p in sources)).encode()).hexdigest()
        obj, receipt = objects / (name + ".obj"), objects / (name + ".json")
        if obj.exists() and receipt.exists():
            saved = json.loads(receipt.read_text())
            if saved.get("input") == signature and saved.get("object") == digest(obj):
                return obj, True
        source = objects / (name + ".cpp")
        # Includes preserve each generated function's original header search base.
        source.write_text("\n".join('#include ' + json.dumps(str(p).replace("\\", "/"), ensure_ascii=False)
                                     for p in sources) + "\n", encoding="utf-8")
        pending = objects / (name + ".pending.obj")
        command = [str(compiler), "/nologo", "/c", "/TP", "/O2", "/Ob2", "/MD",
                   "/DNDEBUG", "/EHsc", "/std:c++20", "/bigobj", "/fp:precise", "/utf-8",
                   *options, "/Fo" + str(pending), str(source)]
        if portable:
            pch = ["-include-pch", str(precompiled[unit["pch"]])] if unit.get("pch") else []
            command = [str(compiler), "-c", *portable_defaults,
                       *portable_flags(options), *pch, "-o", str(pending), str(source)]
        with (logs / (name + ".log")).open("wb") as log:
            result = subprocess.run(command, env=env, stdout=log, stderr=subprocess.STDOUT)
        if result.returncode:
            raise RuntimeError(f"Compile unit {name} failed (exit {result.returncode}); see {logs / (name + '.log')}")
        pending.replace(obj)
        temporary = receipt.with_suffix(".tmp")
        temporary.write_text(json.dumps({"input": signature, "object": digest(obj)}))
        temporary.replace(receipt)
        return obj, False

    completed, reused, failures = {}, 0, []
    jobs = max(1, min(jobs, 4))
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        futures = {pool.submit(compile_unit, unit): unit for unit in units}
        try:
            for future in as_completed(futures):
                try:
                    obj, cached = future.result()
                except Exception as error:
                    if not preflight:
                        raise
                    failures.append(str(error))
                    print(str(error), flush=True)
                    continue
                completed[futures[future]["id"]] = obj
                reused += cached
                print(f"Compiled {len(completed)}/{len(futures)} ({reused} cached)", flush=True)
        except BaseException:
            for future in futures:
                future.cancel()
            raise
    if preflight:
        if failures:
            raise RuntimeError(f"Portable preflight failed in {len(failures)} units; see {logs}")
        print(f"Preflight compiled {len(completed)} runtime units; no game was linked", flush=True)
        return
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
        response.write_text(response_text(members, portable),
                            encoding="utf-8" if portable else "utf-16")
        with (logs / (name + "-archive.log")).open("wb") as log:
            command = ([str(archiver), "rcs", str(target), "@" + str(response)] if portable else
                       [str(linker.parent / "lib.exe"), "/NOLOGO", "/OUT:" + str(target), "@" + str(response)])
            subprocess.run(command,
                           env=env, stdout=log, stderr=subprocess.STDOUT, check=True)
        archive_inputs.append(str(target))
    args = [str(completed[u["id"]]) for u in units if not u.get("archive")] + archive_inputs + link_inputs
    args += [expand(arg) for arg in plan.get("linkOptions", [])]
    args += ["/NOLOGO", "/INCREMENTAL:NO", "/OUT:" + str(output / "reo_recomp.exe")]
    if portable:
        libraries = []
        for value in plan.get("linkOptions", []):
            if value.lower().endswith(".lib") and "/" not in value and "\\" not in value:
                libraries.append("-l" + value[:-4].lower())
            elif value not in {"/MACHINE:X64", "/SUBSYSTEM:CONSOLE"} and not value.startswith("/MANIFEST"):
                raise ValueError("Unsupported portable linker option: " + value)
        resources = []
        for n, entry in enumerate(plan.get("resources", [])):
            resource = source_file(entry)
            target = objects / ("resource" + str(n) + ".obj")
            with (logs / ("resource" + str(n) + ".log")).open("wb") as log:
                subprocess.run([str(resource_compiler), "-I", str(resource.parent), "-i", str(resource),
                                "-O", "coff", "-o", str(target)], env=env, stdout=log,
                               stderr=subprocess.STDOUT, check=True)
            resources.append(str(target))
        args = [str(completed[u["id"]]) for u in units if not u.get("archive")]
        args += resources + ["-Wl,--start-group", *archive_inputs, *link_inputs,
                             *libraries, "-Wl,--end-group", "-mwindows", "-o", str(output / "reo_recomp.exe")]
    response = work / "local-game-link.rsp"
    response.write_text(response_text(args, portable),
                        encoding="utf-8" if portable else "utf-16")
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
    if plan.get("copyLocalCrt") and not portable:
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
    parser.add_argument("--preflight", action="store_true", help="Check all runtime units without compiling game groups or linking")
    args = parser.parse_args()
    compile_plan(args.kit, args.generated, args.work, args.output, args.jobs, preflight=args.preflight)


if __name__ == "__main__":
    main()
