#!/usr/bin/env python3
"""Launch the local ARM64 development build through MoltenVK/Metal."""

import argparse
import json
import os
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]


def molten_library():
    override = os.environ.get("GRANITE_VULKAN_LIBRARY")
    candidates = [Path(override)] if override else []
    sdk = os.environ.get("VULKAN_SDK")
    if sdk:
        candidates.append(Path(sdk) / "lib/libMoltenVK.dylib")
    candidates += [Path("/opt/homebrew/lib/libMoltenVK.dylib"), Path("/usr/local/lib/libMoltenVK.dylib")]
    for candidate in candidates:
        if candidate.is_file():
            return candidate.resolve()
    raise RuntimeError("MoltenVK not found; install the macOS Vulkan SDK or set GRANITE_VULKAN_LIBRARY")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--build", type=Path, default=ROOT / "build-macos")
    parser.add_argument("--route", choices=("title", "main-menu", "scenario", "character", "gameplay"),
                        help="Optional development-only automatic controller route")
    args = parser.parse_args()
    if sys.platform != "darwin":
        parser.error("This launcher requires macOS")
    record = json.loads((args.build.resolve() / "macos-build.json").read_text())
    executable, disc, iso = (Path(record[key]) for key in ("executable", "data", "iso"))
    for path in (executable, disc / "SLUS_207.65", iso):
        if not path.is_file():
            raise FileNotFoundError(path)
    home = Path.home() / "Library/Application Support/OutbreakRecomp"
    home.mkdir(parents=True, exist_ok=True)
    card = home / "memory-cards/default/data"
    card.mkdir(parents=True, exist_ok=True)
    environment = dict(os.environ)
    defaults = {
        "GRANITE_VULKAN_LIBRARY": str(molten_library()), "REO_ISO": str(iso),
        "REO_MC0_ROOT": str(card), "REO_MC1_ROOT": ":none:",
        "REO_NATURAL": "1", "REO_TURBO": "1", "REO_GS_BACKEND": "parallel",
        "REO_GS_THREAD": "1", "REO_GS_GPU_PRESENT": "1", "REO_GS_DISPATCH_PACE": "2",
        "REO_GS_SPRITE_DEPTH_PARALLEL": "1", "REO_VIF1_GPU_RESIDENT": "0",
        "REO_VIF1_ASYNC": "1", "REO_INTERNAL_RESOLUTION": "1", "REO_DEBUG_PANEL": "0",
        "REO_PARALLEL_GS_DESCRIPTOR_BUFFER": "0", "REO_POST_AA": "none",
        "REO_GPU_MOVIE": "0",
    }
    for key, value in defaults.items():
        environment.setdefault(key, value)
    if args.route:
        environment["REO_TEST_ROUTE"] = args.route
    # Saves and runtime output are outside the replaceable build directory.
    return subprocess.call([str(executable), "--game", "file1", "--elf", str(disc / "SLUS_207.65"),
                            "--data", str(disc)], cwd=home, env=environment)


if __name__ == "__main__":
    raise SystemExit(main())
