"""Preserve exact independent upstream source trees alongside a build kit."""

import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import zipfile


def export(root, kit, dependency):
    root, kit = Path(root).resolve(), Path(kit).resolve()
    deps = root / "third_party/PS2Recomp/out/build/_deps"
    parents = [("raylib", deps / "raylib-src"), ("fmt", deps / "fmt-src"),
               ("libdwarf", deps / "libdwarf-src"), ("ELFIO", root / "deps/elfio"),
               ("rabbitizer", deps / "rabbitizer-src"), ("toml11", deps / "toml11-src"),
               ("parallel-gs", root / "build-ninja/parallel-gs-source"),
               ("PS2Recomp", Path(dependency).resolve())]
    archive = kit / "notices/independent-sdk-sources.zip"
    archive.parent.mkdir(parents=True, exist_ok=True)
    if archive.exists():
        raise FileExistsError("Independent source archives are immutable")
    records = []
    with zipfile.ZipFile(archive, "w", zipfile.ZIP_DEFLATED, compresslevel=6) as zipped:
        for label, parent in parents:
            if not parent.is_dir():
                raise FileNotFoundError(parent)
            revision = subprocess.run(["git", "-C", str(parent), "rev-parse", "HEAD"],
                                      stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
            top = subprocess.run(["git", "-C", str(parent), "rev-parse", "--show-toplevel"],
                                 stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
            own_repository = top.returncode == 0 and Path(top.stdout.strip()).resolve() == parent.resolve()
            record = {"component": label, "revision": revision.stdout.strip() if own_repository else None,
                      "files": 0}
            for folder, directories, files in os.walk(parent):
                directories[:] = [name for name in directories if name not in
                                   {".git", "__pycache__", "out", "build", "node_modules", ".cache",
                                    "local_source_catalogues", "irq_cpu_original"}]
                for name in files:
                    source = Path(folder) / name
                    if (name == ".git" or source.is_symlink() or source.suffix.lower() in
                        {".iso", ".elf", ".bin", ".obj", ".o", ".a", ".lib", ".exe", ".dll",
                         ".pdb", ".dmp", ".gsdump", ".sfd", ".adx", ".irx", ".ps2", ".db"}):
                        continue
                    zipped.write(source, label + "/" + source.relative_to(parent).as_posix())
                    record["files"] += 1
            records.append(record)
    records.append({"sourceArchiveSha256": hashlib.sha256(archive.read_bytes()).hexdigest()})
    (kit / "notices/independent-sdk-sources.json").write_text(json.dumps(records, indent=2) + "\n")
    print("Preserved independent SDK source and licence trees for " + str(len(parents)) + " components")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[2])
    parser.add_argument("--kit", type=Path, required=True)
    parser.add_argument("--dependency", type=Path, required=True,
                        help="Published patched dependency tree, with no generated game sources")
    args = parser.parse_args()
    export(args.root, args.kit, args.dependency)
