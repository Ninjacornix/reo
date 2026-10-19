"""Seal an audited Linux-native toolchain kit, with no game objects or binaries."""

import argparse
import json
from pathlib import Path
import sys

from compile_game import digest
from compile_linux import elf64
from generate_game import ELF_SHA256


def seal(kit):
    kit = Path(kit).resolve()
    manifest = kit / "build-kit.json"
    if manifest.exists():
        raise FileExistsError("Sealed Linux build kits are immutable")
    plan = json.loads((kit / "compile-plan-linux.json").read_text(encoding="utf-8"))
    if plan.get("format") != 1 or plan.get("architecture") != "linux-x64" or not plan.get("runtimeAbi"):
        raise ValueError("An explicit native Linux compilation plan is required")
    for name in ("tools/python/bin/python3", "tools/ps2_recomp"):
        if not elf64(kit / name):
            raise ValueError("A native Linux tool is required: " + name)
    for key in ("compiler", "archiver"):
        value = plan[key]
        if not value.startswith("{kit}/"):
            raise ValueError("The Linux compiler must be bundled, not a system dependency")
        path = (kit / value.removeprefix("{kit}/")).resolve()
        if not path.is_relative_to(kit) or not elf64(path):
            raise ValueError("The bundled compiler/archiver must be native x86-64 ELF")
    if not (kit / "notices/independent-sdk-sources.zip").is_file():
        raise ValueError("Include exact dependency/toolchain source and licence material")
    declared = {item["path"].removeprefix("{kit}/"): item["sha256"]
                for item in plan.get("independentInputs", [])}
    files = []
    for path in sorted(kit.rglob("*")):
        if not path.resolve().is_relative_to(kit):
            raise ValueError("A Linux kit symlink escapes its root")
        if not path.is_file():
            continue
        relative = path.relative_to(kit).as_posix()
        toolchain_object = relative.startswith("toolchain/") and path.suffix == ".o"
        if "__pycache__" in path.parts or (path.suffix.lower() in {".exe", ".dll", ".lib", ".iso", ".elf", ".bin", ".obj", ".o"} and not toolchain_object) or path.name == "reo_recomp":
            raise ValueError("Private/Windows inputs or local caches entered the Linux kit: " + relative)
        value = digest(path)
        # The compiler's own runtime libraries are audited as part of the toolchain inventory.
        if (path.suffix == ".a" or ".so" in path.suffixes) and not relative.startswith(("toolchain/", "tools/python/")) and declared.get(relative) != value:
            raise ValueError("Undeclared precompiled Linux dependency: " + relative)
        files.append({"path": relative, "sha256": value})
    outputs = ["reo_recomp", *[entry["destination"] for entry in plan.get("copyOutputs", [])]]
    if len(outputs) != len(set(outputs)):
        raise ValueError("Duplicate Linux output names")
    record = {"format": 1, "architecture": "linux-x64", "toolchain": "portable-clang",
              "runtimeAbi": plan["runtimeAbi"], "elfSha256": ELF_SHA256, "files": files, "outputs": outputs}
    manifest.write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
    print(f"Sealed {len(files)} independent Linux inputs; no game binary is distributed")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--kit", type=Path, required=True)
    seal(parser.parse_args().kit)
