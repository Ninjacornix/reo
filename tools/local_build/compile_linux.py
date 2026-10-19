"""Native Linux worker. Requires an audited Linux plan, never Windows archives."""

from concurrent.futures import ThreadPoolExecutor, as_completed
import hashlib
import json
import os
from pathlib import Path
import re
import shlex
import shutil
import subprocess
import sys

from compile_game import digest


def elf64(path):
    with Path(path).open("rb") as stream:
        header = stream.read(20)
    return (len(header) == 20 and header[:7] == b"\x7fELF\x02\x01\x01"
            and int.from_bytes(header[18:20], "little") == 62)


def compile_plan(kit, generated, work, output, jobs):
    if sys.platform != "linux":
        raise RuntimeError("Linux game compilation must run on Linux")
    kit, generated, work, output = (Path(p).resolve() for p in (kit, generated, work, output))
    plan_file = kit / "compile-plan-linux.json"
    plan = json.loads(plan_file.read_text(encoding="utf-8"))
    if plan.get("format") != 1 or plan.get("architecture") != "linux-x64" or not plan.get("runtimeAbi"):
        raise ValueError("An explicit linux-x64 build plan is required")
    values = {"{kit}": str(kit), "{generated}": str(generated), "{work}": str(work),
              "{output}": str(output)}

    def expand(value):
        for key, replacement in values.items():
            value = value.replace(key, replacement)
        if "{" in value or "}" in value:
            raise ValueError("Unknown Linux plan substitution")
        return value

    def local(value):
        path = Path(expand(value)).resolve()
        if not any(path.is_relative_to(root) for root in (kit, generated, work)):
            raise ValueError("Linux build input escapes its private roots")
        if not path.is_file():
            raise FileNotFoundError(path)
        return path

    compiler = local(plan["compiler"])
    archiver = local(plan["archiver"])
    if not elf64(compiler) or not elf64(archiver):
        raise ValueError("The portable compiler and archiver must be native x86-64 ELF tools")
    units = list(plan.get("units", []))
    for group in plan.get("sourceGroups", []):
        parent = Path(expand(group["root"])).resolve()
        if not parent.is_relative_to(generated):
            raise ValueError("Generated source group escapes the private workspace")
        batch, size, index = [], 0, 0
        for source in sorted(parent.glob(group["pattern"])):
            if source.name in group.get("exclude", []):
                continue
            if source.suffix != ".cpp" or not source.is_file():
                raise ValueError("Generated source group contains a non-C++ input")
            if batch and (len(batch) >= group.get("batch", 8) or size + source.stat().st_size > 500000):
                units.append({"id": group["id"] + str(index), "sources": batch,
                              "options": group.get("options", []) + ["-I" + str(parent)]})
                batch, size, index = [], 0, index + 1
            replacement = plan.get("generatedSourceOverrides", {}).get(source.relative_to(generated).as_posix())
            batch.append(expand(replacement) if replacement else str(source))
            size += source.stat().st_size
        if not batch:
            raise ValueError("Generated Linux source group is empty")
        units.append({"id": group["id"] + str(index), "sources": batch,
                      "options": group.get("options", []) + ["-I" + str(parent)]})
    ids = [u["id"] for u in units]
    if not units or len(set(ids)) != len(ids) or any(not re.fullmatch(r"[\w-]+", name) for name in ids):
        raise ValueError("Invalid or duplicate Linux compilation units")
    objects, logs = work / "linux-objects", work / "linux-compile-logs"
    objects.mkdir(parents=True, exist_ok=True)
    logs.mkdir(parents=True, exist_ok=True)
    output.mkdir(parents=True, exist_ok=True)
    headers = hashlib.sha256()
    for root in (kit, generated):
        for path in sorted(root.rglob("*")):
            if path.is_file() and path.suffix in {".h", ".hpp", ".inc", ".inl"}:
                headers.update(str(path.relative_to(root)).encode())
                headers.update(bytes.fromhex(digest(path)))
    base = digest(plan_file) + digest(compiler) + headers.hexdigest()
    common = [expand(v) for v in plan.get("compileOptions", [])]
    if any(flag.startswith(("/D", "/I", "/MD", "/EH", "/std:")) for flag in common):
        raise ValueError("Windows compiler flags are forbidden in a Linux plan")

    def compile_one(unit):
        sources = [local(p) for p in unit["sources"]]
        options = common + [expand(v) for v in unit.get("options", [])]
        signature = hashlib.sha256((base + json.dumps(options) + "".join(str(p) + digest(p) for p in sources)).encode()).hexdigest()
        target = objects / (unit["id"] + ".o")
        receipt = target.with_suffix(".json")
        if target.exists() and receipt.exists():
            record = json.loads(receipt.read_text())
            if record == {"input": signature, "object": digest(target)}:
                return target
        unity = target.with_suffix(".cpp")
        unity.write_text("\n".join("#include " + json.dumps(str(p), ensure_ascii=False) for p in sources), encoding="utf-8")
        pending = target.with_suffix(".pending.o")
        with (logs / (unit["id"] + ".log")).open("wb") as log:
            subprocess.run([str(compiler), "-c", "-O2", "-DNDEBUG", "-std=c++20", "-fexceptions",
                            "-fno-fast-math", "-ffp-contract=off", *options, str(unity), "-o", str(pending)],
                           stdout=log, stderr=subprocess.STDOUT, check=True)
        pending.replace(target)
        temporary = receipt.with_suffix(".pending")
        temporary.write_text(json.dumps({"input": signature, "object": digest(target)}))
        temporary.replace(receipt)
        return target

    compiled = {}
    with ThreadPoolExecutor(max_workers=max(1, min(jobs, 4))) as pool:
        futures = {pool.submit(compile_one, unit): unit for unit in units}
        for future in as_completed(futures):
            compiled[futures[future]["id"]] = future.result()
            print(f"Compiled {len(compiled)}/{len(units)}", flush=True)
    direct, archives = [], {}
    for unit in units:
        if unit.get("archive"):
            name = unit["archive"]
            if not re.fullmatch(r"[\w-]+", name):
                raise ValueError("Invalid Linux archive name")
            archives.setdefault(name, []).append(str(compiled[unit["id"]]))
        else:
            direct.append(str(compiled[unit["id"]]))
    libraries = []
    for name, members in archives.items():
        archive = objects / ("lib" + name + ".a")
        pending = archive.with_suffix(".pending.a")
        if pending.exists():
            pending.unlink()  # Exact prior incomplete archive in the private object directory.
        subprocess.run([str(archiver), "rcs", str(pending), *members], check=True)
        pending.replace(archive)
        libraries.append(str(archive))
    for item in plan.get("independentInputs", []):
        path = local(item["path"])
        if path.suffix == ".lib" or item.get("provenance") not in {"third-party", "authored-runtime"} or digest(path) != item["sha256"]:
            raise ValueError("Invalid independent Linux library")
        libraries.append(str(path))
    response = work / "linux-link.rsp"
    args = [*direct, "-Wl,--start-group", *libraries, "-Wl,--end-group",
            *[expand(v) for v in plan.get("linkOptions", [])], "-o", str(output / "reo_recomp.pending")]
    response.write_text("\n".join(shlex.quote(value) for value in args), encoding="utf-8")
    print("Linking locally generated Linux game", flush=True)
    with (logs / "link.log").open("wb") as log:
        subprocess.run([str(compiler), "@" + str(response)], stdout=log, stderr=subprocess.STDOUT, check=True)
    pending = output / "reo_recomp.pending"
    if not elf64(pending):
        raise ValueError("The linked game is not a native x86-64 ELF executable")
    pending.chmod(0o755)
    pending.replace(output / "reo_recomp")
    for entry in plan.get("copyOutputs", []):
        relative = Path(entry["destination"])
        if relative.is_absolute() or ".." in relative.parts:
            raise ValueError("Linux output copy escapes the build directory")
        target = output / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(local(entry["source"]), target)
