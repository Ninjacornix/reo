"""Stage the repository SDK audio files and apply only the canonical volume patch.

The SDK checkout is read-only. REO_AUDIO_TEST_SDK_ROOT can select another SDK
checkout with the same unpatched audio sources.
"""
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

root = Path(__file__).resolve().parents[2]
source = Path(os.environ.get("REO_AUDIO_TEST_SDK_ROOT", root / "third_party/PS2Recomp")).resolve()
stage = root / "build-ninja/audio_mixer_check/sdk"
relative = Path("ps2xRuntime/src/lib/Kernel/Syscalls/Helpers")
patch = root / "third_party/patches/ps2recomp/0103-audio-volume-controls.patch"
files = ("CriAudio.cpp", "CriAudio.h", "ReoSoundBanks.cpp", "ReoSoundBanks.h")

for name in files:
    target = stage / relative / name
    target.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(source / relative / name, target)

command = ["git", "apply", "--directory=" + stage.relative_to(root).as_posix()]
subprocess.run(command + ["--check", str(patch)], cwd=root, check=True)
subprocess.run(command + [str(patch)], cwd=root, check=True)
shutil.copyfile(Path(__file__).with_name("vblank_music_diag.h"),
                stage / "ps2xRuntime/src/lib/vblank_music_diag.h")

receipt = {
    "sdk_source": str(source),
    "patch": str(patch.relative_to(root)),
    "patch_sha256": hashlib.sha256(patch.read_bytes()).hexdigest(),
    "staged_sources": {
        name: hashlib.sha256((stage / relative / name).read_bytes()).hexdigest()
        for name in files
    },
}
(stage.parent / "prepared-sources.json").write_text(json.dumps(receipt, indent=2))
print("Staged four SDK audio files; canonical audio patch check/apply passed.")
