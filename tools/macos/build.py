#!/usr/bin/env python3
"""Build File #1 natively on Apple Silicon from an owned ISO (development only)."""

import argparse
import hashlib
import json
import os
from pathlib import Path
import platform
import shutil
import subprocess
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools/local_build"))
from import_iso import import_iso
from generate_game import generate
from generate_queue_control import generate as generate_queue
from reconstruct_vu import reconstruct
from source_recipes import apply_plan
from play import molten_library
from package_app import package_app

PS2_PIN = "c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f"
GS_PIN = "cc6184af7e0c03da603045ca371ffa5dae9b0655"
ELFIO_PIN = "7d30a22fc5aac06adfe7887ae57f3701b6b5f913"
TOML11_PIN = "b389bbc4ebf90fa2fe7651de3046fb19f661ba3c"


def run(*args, cwd=ROOT, **kwargs):
    print("+", " ".join(map(str, args)), flush=True)
    return subprocess.run(list(map(str, args)), cwd=cwd, check=True, **kwargs)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def source_state(path, patches):
    # Include added files, which git diff does not see before staging.
    paths = sorted({line[6:] for patch in patches for line in patch.read_text().splitlines()
                    if line.startswith("+++ b/")})
    return sha(subprocess.check_output(["git", "diff", "--binary"], cwd=path) +
               b"".join(name.encode() + ((path / name).read_bytes() if (path / name).is_file()
                                         else b"<deleted>") for name in paths))


def prepare(path, url, pin, patch_directory=None):
    patches = sorted(patch_directory.glob("*.patch")) if patch_directory else []
    if not (path / ".git").exists():
        if path.exists() and any(path.iterdir()):
            raise RuntimeError(f"Dependency directory is not empty: {path}")
        run("git", "clone", "--no-checkout", url, path)
        run("git", "checkout", "--detach", pin, cwd=path)
    actual = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=path).decode().strip()
    if actual != pin:
        raise RuntimeError(f"Preserve {path}; expected revision {pin}, found {actual}")
    if not patches:
        return
    git_directory = Path(subprocess.check_output(
        ["git", "rev-parse", "--absolute-git-dir"], cwd=path).decode().strip())
    receipt = git_directory / "reo-macos-patches.json"
    identity = sha(b"".join(p.name.encode() + p.read_bytes() for p in patches))
    if receipt.exists():
        saved = json.loads(receipt.read_text())
        if saved == {"patches": identity, "source": source_state(path, patches)}:
            return
        raise RuntimeError(f"Dependency patches or sources changed in {path}; preserve it before preparing a fresh checkout")
    if subprocess.check_output(["git", "status", "--porcelain"], cwd=path).strip():
        raise RuntimeError(f"Dependency has existing changes; preserved: {path}")
    for patch in patches:
        # Some release patches have CRLF; git apply on Darwin needs LF.
        payload = patch.read_bytes().replace(b"\r\n", b"\n")
        run("git", "apply", "--check", "-", cwd=path, input=payload)
        run("git", "apply", "-", cwd=path, input=payload)
    receipt.write_text(json.dumps({"patches": identity, "source": source_state(path, patches)}, indent=2))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--iso", type=Path, required=True)
    parser.add_argument("--jobs", type=int, default=4)
    parser.add_argument("--build", type=Path, default=ROOT / "build-macos")
    args = parser.parse_args()
    if sys.platform != "darwin" or platform.machine() != "arm64":
        parser.error("Run natively on an Apple Silicon Mac")
    if sys.version_info < (3, 11):
        parser.error("The developer build requires Python 3.11 or newer")
    if args.jobs < 1:
        parser.error("--jobs must be positive")
    for command in ("git", "cmake", "ninja", "clang", "glslangValidator", "spirv-val"):
        if not shutil.which(command):
            parser.error(f"Missing developer tool: {command}")
    metal_driver = molten_library()
    build = args.build.resolve()
    build.mkdir(parents=True, exist_ok=True)
    ps2 = ROOT / "third_party/PS2Recomp"
    gs = build / "parallel-gs-source"
    elfio = build / "elfio-source"
    prepare(ps2, "https://github.com/sp00nznet/PS2Recomp.git", PS2_PIN,
            ROOT / "third_party/patches/ps2recomp")
    prepare(gs, "https://github.com/Arntzen-Software/parallel-gs.git", GS_PIN,
            ROOT / "third_party/patches/parallel-gs")
    run("git", "submodule", "update", "--init", "Granite", cwd=gs)
    granite = gs / "Granite"
    prepare(granite, "https://github.com/Themaister/Granite.git",
            "16e7395f6a4858c1783dbf6f521f90b9d5f82ac5", ROOT / "third_party/patches/granite")
    run("git", "submodule", "update", "--init", "third_party/khronos/vulkan-headers",
        "third_party/volk", "third_party/rapidjson", "third_party/stb/stb", cwd=granite)
    prepare(elfio, "https://github.com/serge1/ELFIO.git", ELFIO_PIN)
    toml11 = build / "ps2recomp/_deps/toml11-src"
    prepare(toml11, "https://github.com/ToruNiina/toml11.git", TOML11_PIN)
    disc = import_iso(args.iso, build / "imports")
    elf = disc / "SLUS_207.65"
    metadata = ROOT / "recomp/config"
    run(sys.executable, ROOT / "tools/local_build/generate_catalogues.py", "--elf", elf,
        "--manifest", metadata / "local_source_catalogues.json", "--output",
        ps2 / "ps2xRuntime/src/lib/local_source_catalogues")
    run("cmake", "-S", ps2, "-B", build / "ps2recomp", "-G", "Ninja",
        "-DCMAKE_BUILD_TYPE=Release", "-DPS2X_MACOS_METAL_PRESENT=ON",
        "-DPS2X_BUILD_RECOMP=ON", "-DPS2X_BUILD_RUNTIME=ON",
        "-DPS2X_BUILD_ANALYZER=OFF", "-DPS2X_BUILD_TEST=OFF", "-DPS2X_BUILD_STUDIO=OFF",
        "-DFETCHCONTENT_UPDATES_DISCONNECTED=ON", f"-DFETCHCONTENT_SOURCE_DIR_ELFIO={elfio}",
        f"-DFETCHCONTENT_SOURCE_DIR_TOML11={toml11}")
    run("cmake", "--build", build / "ps2recomp", "--target", "ps2_recomp", "ps2_runtime",
        "--parallel", args.jobs)
    run("cmake", "-S", ROOT / "tools/parallel_gs_check", "-B", build / "graphics", "-G", "Ninja",
        "-DCMAKE_BUILD_TYPE=Release", f"-DPARALLEL_GS_SOURCE={gs}")
    run("cmake", "--build", build / "graphics", "--target", "parallel_gs_check", "--parallel", args.jobs)
    controls = Path(tempfile.mkdtemp(prefix="moltenvk-controls-", dir=build))
    check_environment = dict(os.environ, GRANITE_VULKAN_LIBRARY=str(metal_driver),
                             REO_PARALLEL_GS_DESCRIPTOR_BUFFER="0")
    run(build / "graphics/parallel_gs_check", controls, env=check_environment)
    generated = build / "generated"
    if not generated.exists():
        generate(build / "ps2recomp/ps2xRecomp/ps2_recomp", disc, metadata, generated, args.jobs)
    else:
        record = json.loads((generated / "generation.json").read_text())
        if (record["elfSha256"] != sha(elf.read_bytes()) or
                record["recompilerSha256"] != sha((build / "ps2recomp/ps2xRecomp/ps2_recomp").read_bytes())):
            raise RuntimeError("Generated sources belong to a different disc or recompiler; preserve them and use a fresh build directory")
        for item in record["files"]:
            if sha((generated / item["path"]).read_bytes()) != item["sha256"]:
                raise RuntimeError("Generated source changed: " + item["path"])
    apply_plan(elf, generated, metadata / "local_source_recipes.json", ROOT)
    # Authored instrumentation retains its reviewed relative include paths.
    for name in ("output", "output_extra", "output_overlay", "output_ovl"):
        link = metadata / name
        target = generated / name
        if link.exists() or link.is_symlink():
            if not link.is_symlink() or link.resolve() != target:
                raise RuntimeError(f"Existing generated directory preserved: {link}")
        else:
            link.symlink_to(target, target_is_directory=True)
    generate_queue(elf, metadata / "local_queue_control.json",
                   ROOT / "tools/parallel_gs_backend/resident_geometry/upstream/queue_control_body.inc")
    vu = build / "vu"
    if not vu.exists():
        reconstruct(elf, metadata / "local_vu_images.json", vu)
    whole = vu / "whole-registered"
    if not whole.exists():
        run(sys.executable, ROOT / "tools/vu_whole_aot/generate.py", "--collection", vu, "--out", whole)
    run("cmake", "-S", ROOT, "-B", build / "game", "-G", "Ninja", "-DCMAKE_BUILD_TYPE=Release",
        f"-DPS2RECOMP_BUILD={build / 'ps2recomp'}", f"-DREO_RECOMP_CONFIG_ROOT={generated}",
        "-DREO_BUILD_GPU_GS=ON", f"-DREO_PARALLEL_GS_SOURCE={gs}",
        f"-DREO_PARALLEL_GS_BUILD={build / 'graphics'}", "-DREO_RECOMP_PCH=ON",
        "-DREO_VULKAN_SDK_MIN=1.4.304",
        f"-DREO_VU_SPECIALIZED_SOURCE={vu / 'specialized/reo_vu_specialized_generated.cpp'}",
        f"-DREO_VU_WHOLE_SOURCE={whole / 'reo_vu_whole_registered_generated.cpp'}")
    run("cmake", "--build", build / "game", "--target", "reo_recomp", "--parallel", args.jobs)
    run("cmake", "--build", build / "graphics", "--target", "macos_present_check", "--parallel", args.jobs)
    run(build / "graphics/macos_present_check", build / "game/recomp/reo-gpu-present", env=check_environment)
    record = {
        "format": 1, "iso": str(args.iso.resolve()), "data": str(disc),
        "executable": str(build / "game/recomp/reo_recomp"),
        "gameplayValidated": False, "performanceMeasured": False}
    (build / "macos-build.json").write_text(json.dumps(record, indent=2))
    print("Local application:", package_app(build, record, metal_driver))
    print("Native build complete. Gameplay and performance still require validation.")


if __name__ == "__main__":
    main()
