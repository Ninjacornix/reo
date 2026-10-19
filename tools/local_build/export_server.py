"""Build a separate portable openSNAP component, with its AGPL source and notices."""
import argparse
import hashlib
import io
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tarfile
import urllib.request
import zipfile

from seal_kit import PYTHON_SHA256, PYTHON_SOURCE, sha

REVISION = "f9af55491718a043923225a0895fe60eab76fd7c"


def fetch(url, destination, expected):
    with urllib.request.urlopen(url, timeout=60) as response, destination.open("wb") as output:
        shutil.copyfileobj(response, output)
    if sha(destination) != expected:
        raise ValueError("Source download digest mismatch: " + destination.name)


def export(checkout, python_zip, output):
    if sys.platform != "win32" or sys.version_info[:2] != (3, 12):
        raise RuntimeError("Build this Windows component using native x64 Python 3.12")
    root = Path(__file__).resolve().parents[2]
    checkout, python_zip, output = map(lambda p: Path(p).resolve(), (checkout, python_zip, output))
    if output.exists():
        raise FileExistsError("Use a new output directory")
    if subprocess.check_output(["git", "-C", str(checkout), "rev-parse", "HEAD"], text=True).strip() != REVISION:
        raise ValueError("Use the pinned openSNAP source revision")
    if sha(python_zip) != PYTHON_SHA256:
        raise ValueError("Use the pinned official Python embeddable ZIP")
    output.mkdir(parents=True)
    source = output / "source"
    source.mkdir()
    archive = subprocess.check_output(["git", "-C", str(checkout), "archive", REVISION])
    with tarfile.open(fileobj=io.BytesIO(archive)) as package:
        package.extractall(source, filter="data")
    patch = root / "network/server/patches/0001-outbreak-current-room-query.patch"
    # Apply to the exported source, never modify the developer's running server.
    subprocess.run(["git", "apply", "--no-index", str(patch)], cwd=source, check=True)
    python = output / "python"
    python.mkdir()
    with zipfile.ZipFile(python_zip) as package:
        for name in package.namelist():
            target = (python / name).resolve()
            if not target.is_relative_to(python):
                raise ValueError("Unsafe Python ZIP path")
        package.extractall(python)
    (python / "python312._pth").write_text("python312.zip\n.\n../source\n../source/vendor\n", encoding="utf-8")
    notices = output / "notices"
    notices.mkdir()
    shutil.copyfile(source / "LICENSE", notices / "openSNAP-AGPL-3.0.txt")
    shutil.copyfile(root / "network/server/requirements-portable.txt", notices / "requirements-portable.txt")
    wheels = output / "wheels"
    subprocess.run([sys.executable, "-m", "pip", "download", "--only-binary=:all:", "--no-deps",
        "--dest", str(wheels), "-r", str(notices / "requirements-portable.txt")], check=True)
    vendor = source / "vendor"
    subprocess.run([sys.executable, "-m", "pip", "install", "--no-compile", "--no-deps", "--no-index",
        "--find-links", str(wheels), "--target", str(vendor), "-r", str(notices / "requirements-portable.txt")], check=True)
    sdists = output / "dependency-sources"
    sdists.mkdir()
    provenance = []
    for line in (notices / "requirements-portable.txt").read_text().splitlines():
        name, version = line.split("==")
        with urllib.request.urlopen(f"https://pypi.org/pypi/{name}/{version}/json", timeout=30) as response:
            metadata = json.load(response)
        releases = metadata["urls"]
        for wheel in wheels.glob("*.whl"):
            item = next((item for item in releases if item["filename"] == wheel.name), None)
            if item and sha(wheel) != item["digests"]["sha256"]:
                raise ValueError("Wheel digest mismatch: " + wheel.name)
        item = next(item for item in releases if item["packagetype"] == "sdist")
        fetch(item["url"], sdists / item["filename"], item["digests"]["sha256"])
        provenance.append({"name": name, "version": version, "source": item["url"],
            "sha256": item["digests"]["sha256"]})
    provenance.append({"name": "Python", "version": "3.12.10", "runtime": PYTHON_SOURCE,
        "sha256": PYTHON_SHA256, "source": "https://www.python.org/ftp/python/3.12.10/Python-3.12.10.tar.xz"})
    (notices / "provenance.json").write_text(json.dumps(provenance, indent=2) + "\n")
    (notices / "SERVER-SOURCE.txt").write_text(
        "openSNAP is a separately executed AGPL-3.0 service.\n"
        f"https://github.com/GrenderG/openSNAP revision {REVISION}\n"
        "The complete patched server source is in ../source (except vendor dependencies).\n"
        "Dependency source archives are in ../dependency-sources; licence files remain in vendor.\n"
        "No accounts, databases, game assets or credentials are included.\n")
    checks = subprocess.run([str(python / "python.exe"), "-B", "-c",
        "import sqlite3, flask, cryptography, dnslib; from opensnap_web.signup import SignupService; print('portable server imports passed')"],
        cwd=output, check=True, capture_output=True, text=True)
    print(checks.stdout.strip())
    # Wheels and their corresponding sources are preserved as part of the inventory.
    files = [{"path": file.relative_to(output).as_posix(), "sha256": sha(file)}
        for file in sorted(output.rglob("*")) if file.is_file()]
    record = {"format": 1, "architecture": "win-x64", "revision": REVISION,
        "python": "python/python.exe", "source": "source", "files": files}
    (output / "server-manifest.json").write_text(json.dumps(record, indent=2) + "\n")
    print(f"Sealed portable server component: {len(files)} files")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--checkout", type=Path, required=True)
    parser.add_argument("--python-zip", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    export(args.checkout, args.python_zip, args.output)
