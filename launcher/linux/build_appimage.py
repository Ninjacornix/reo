"""Build an AppImage on Linux. Release packaging requires exact-kit gameplay proof."""

import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys


def build(output, appimagetool, kit=None, validation=None, launcher_only=False):
    if sys.platform != "linux":
        raise RuntimeError("Build the AppImage on Linux; cross-packaging Windows libraries is unsafe")
    here = Path(__file__).resolve().parent
    root = here.parents[1]
    output = Path(output).resolve()
    if output.exists():
        raise FileExistsError("Choose a new output directory")
    if not launcher_only:
        from core import verify_kit
        if kit is None or validation is None:
            raise ValueError("Release packaging requires --kit and --validation")
        manifest, identity = verify_kit(kit)
        proof = json.loads(Path(validation).read_text())
        required = ("localBuildPassed", "roomRoutePassed", "gpuPresentationPassed", "gpuMoviePassed",
                    "audioPassed", "saveLoadPassed", "controllerPassed", "windowsParityPassed")
        if proof.get("format") != 1 or proof.get("kitSha256") != identity or not all(proof.get(key) is True for key in required):
            raise ValueError("A native Linux gameplay/parity report for this exact kit is required")
    output.mkdir(parents=True)
    appdir = output / "RE-Outbreak.AppDir"
    payload = appdir / "usr/bin"
    payload.mkdir(parents=True)
    subprocess.run([sys.executable, "-m", "PyInstaller", "--noconfirm", "--clean", "--onedir",
                    "--windowed", "--name", "outbreak", "--paths", str(root / "tools/local_build"),
                    "--paths", str(root / "tools"), "--distpath", str(payload),
                    "--add-data", str(root / "launcher/Assets/app-icon.png") + ":assets",
                    "--workpath", str(output / "pyinstaller-work"), "--specpath", str(output),
                    str(here / "main.py")], check=True)
    binary_root = payload / "outbreak"
    if not launcher_only:
        destination = binary_root / "build-kit"
        destination.mkdir()
        for item in manifest["files"]:
            target = destination / item["path"]
            target.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(Path(kit) / item["path"], target)
        shutil.copy2(Path(kit) / "build-kit.json", destination)
    notices = binary_root / "notices"
    notices.mkdir()
    for name in ("LICENSE", "NOTICE.md", "THIRD_PARTY_NOTICES.md"):
        source = root / name
        if source.exists():
            shutil.copy2(source, notices / name)
    # Include launcher sources and licence material for the dynamically linked Qt/Python bundle.
    shutil.copytree(here, notices / "launcher-source", ignore=shutil.ignore_patterns("__pycache__"))
    app_run = appdir / "AppRun"
    app_run.write_text('#!/bin/sh\nAPPDIR="$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)"\n'
                       'exec "$APPDIR/usr/bin/outbreak/outbreak" "$@"\n', encoding="utf-8")
    app_run.chmod(0o755)
    (appdir / "outbreak.desktop").write_text("[Desktop Entry]\nType=Application\nName=RE: Outbreak\n"
        "Exec=outbreak\nIcon=outbreak\nCategories=Game;\nTerminal=false\n", encoding="utf-8")
    shutil.copy2(root / "launcher/Assets/app-icon.svg", appdir / "outbreak.svg")
    name = "RE-Outbreak-launcher-preview-x86_64.AppImage" if launcher_only else "RE-Outbreak-x86_64.AppImage"
    target = output / name
    environment = dict(os.environ, ARCH="x86_64", APPIMAGE_EXTRACT_AND_RUN="1")
    subprocess.run([str(Path(appimagetool).resolve()), str(appdir), str(target)], env=environment, check=True)
    (output / (name + ".sha256")).write_text(hashlib.sha256(target.read_bytes()).hexdigest() + "  " + name + "\n")
    print(target)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--appimagetool", type=Path, required=True)
    parser.add_argument("--kit", type=Path)
    parser.add_argument("--validation", type=Path)
    parser.add_argument("--launcher-only", action="store_true", help="Non-playable development preview; never a game release")
    args = parser.parse_args()
    build(args.output, args.appimagetool, args.kit, args.validation, args.launcher_only)
