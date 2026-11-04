"""Add portable Python and hash an exported independent local-build kit."""

import argparse
import hashlib
import json
from pathlib import Path
import zipfile
from generate_game import GAMES

PYTHON_SHA256 = "4acbed6dd1c744b0376e3b1cf57ce906f9dc9e95e68824584c8099a63025a3c3"
PYTHON_SOURCE = "https://www.python.org/ftp/python/3.12.10/python-3.12.10-embed-amd64.zip"


def sha(path):
    with Path(path).open("rb") as f:
        return hashlib.file_digest(f, "sha256").hexdigest()


def seal(kit, python_zip):
    kit = Path(kit).resolve()
    if (kit / "build-kit.json").exists():
        raise FileExistsError("Sealed build kits are immutable")
    if sha(python_zip) != PYTHON_SHA256:
        raise ValueError("Use the pinned official Python embeddable package: " + PYTHON_SOURCE)
    plan = json.loads((kit / "compile-plan.json").read_text())
    game = plan.get("game", "file1")
    if game not in GAMES or plan.get("elfSha256", GAMES[game]["sha256"]) != GAMES[game]["sha256"]:
        raise ValueError("Compile plan must identify a supported game and matching ELF")
    python = kit / "tools/python"
    python.mkdir()
    with zipfile.ZipFile(python_zip) as archive:
        for member in archive.infolist():
            path = (python / member.filename).resolve()
            if not path.is_relative_to(python) or member.is_dir():
                raise ValueError("Invalid embeddable Python member")
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(archive.read(member))
    (python / "python312._pth").write_text("python312.zip\n.\n../local_build\n../vu_whole_aot\n..\n")
    (kit / "notices/PYTHON-SOURCE.txt").write_text(PYTHON_SOURCE + "\nsha256 " + PYTHON_SHA256 + "\n")
    outputs = ["reo_recomp.exe", *[item["destination"] for item in plan["copyOutputs"]]]
    if plan.get("copyLocalCrt"):
        outputs += ["msvcp140.dll", "msvcp140_atomic_wait.dll", "vcruntime140.dll", "vcruntime140_1.dll"]
    if any(p.is_dir() for p in kit.rglob("__pycache__")):
        raise ValueError("Export a fresh kit without local Python bytecode caches before sealing")
    files = [{"path": p.relative_to(kit).as_posix(), "sha256": sha(p)}
             for p in sorted(kit.rglob("*")) if p.is_file()]
    if any(p["path"].endswith((".obj", ".elf", ".iso", ".bin")) or
           Path(p["path"]).name.lower() in {"reo_recomp.exe", "reo_recomp_file2.exe", "reo_launcher_game.exe"} for p in files):
        raise ValueError("A private/game-derived binary entered the build kit")
    # .lib files may only be the explicitly declared independent upstream inputs.
    libraries = {item["path"].replace("{kit}/", ""): item["sha256"] for item in plan["independentInputs"]}
    for item in files:
        if item["path"].endswith(".lib") and libraries.get(item["path"]) != item["sha256"]:
            raise ValueError("Undeclared precompiled library in the build kit")
    record = {"format": 1, "runtimeAbi": plan["runtimeAbi"], "architecture": "win-x64",
              "toolchain": plan.get("toolchain", "msvc"), "elfSha256": GAMES[game]["sha256"],
              "files": files, "outputs": outputs, "steps": [{"name": "Generate and compile from your disc",
                  "tool": "tools/python/python.exe", "arguments": ["-B", "-u", "-X", "utf8", "{kit}/tools/local_build/build_game.py",
                      "--kit", "{kit}", "--disc", "{disc}", "--work", "{work}", "--output", "{output}",
                      "--jobs", "{jobs}"]}]}
    (kit / "build-kit.json").write_text(json.dumps(record, indent=2) + "\n")
    print(f"Sealed {len(files)} independent build-kit inputs; final game will be compiled locally")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--kit", type=Path, required=True)
    parser.add_argument("--python-zip", type=Path, required=True)
    args = parser.parse_args()
    seal(args.kit, args.python_zip)
