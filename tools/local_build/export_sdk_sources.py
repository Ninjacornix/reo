"""Preserve exact independent upstream source trees alongside a build kit."""

import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import zipfile


def export(root, kit):
    root, kit = Path(root).resolve(), Path(kit).resolve()
    deps = root / "third_party/PS2Recomp/out/build/_deps"
    parents = [("raylib", deps / "raylib-src"), ("fmt", deps / "fmt-src"),
               ("libdwarf", deps / "libdwarf-src"), ("ELFIO", deps / "elfio-src"),
               ("rabbitizer", deps / "rabbitizer-src"), ("toml11", deps / "toml11-src"),
               ("parallel-gs", root / "build-ninja/parallel-gs-source")]
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
            record = {"component": label, "revision": revision.stdout.strip(), "files": 0}
            for folder, directories, files in os.walk(parent):
                directories[:] = [name for name in directories if name not in
                                   {".git", "__pycache__", "out", "build", "node_modules", ".cache"}]
                for name in files:
                    source = Path(folder) / name
                    if name == ".git" or source.is_symlink():
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
    args = parser.parse_args()
    export(args.root, args.kit)
