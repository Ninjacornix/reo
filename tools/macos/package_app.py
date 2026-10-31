"""Make a local development .app around an already compiled ARM64 game."""

from pathlib import Path
import platform
import plistlib
import shlex
import shutil
import os
import tempfile


def replace_copy(source, destination):
    source, destination = Path(source), Path(destination)
    if destination.exists() and source.resolve() == destination.resolve():
        return
    descriptor, temporary = tempfile.mkstemp(prefix=destination.name + ".", dir=destination.parent)
    os.close(descriptor)
    temporary = Path(temporary)
    try:
        shutil.copy2(source, temporary)
        temporary.replace(destination)
    finally:
        temporary.unlink(missing_ok=True)


def package_app(build, record, driver):
    build = Path(build)
    app = build / "RE Outbreak RC1 Game.app"
    contents = app / "Contents"
    macos = contents / "MacOS"
    frameworks = contents / "Frameworks"
    resources = contents / "Resources"
    for folder in (macos, frameworks, resources):
        folder.mkdir(parents=True, exist_ok=True)
    executable = Path(record["executable"])
    replace_copy(executable, macos / "reo_recomp")
    shutil.copytree(executable.parent / "reo-gpu-present", macos / "reo-gpu-present", dirs_exist_ok=True)
    replace_copy(driver, frameworks / "libMoltenVK.dylib")
    root = Path(__file__).resolve().parents[2]
    replace_copy(root / "LICENSE", resources / "COPYING")
    for name in ("LICENSE", "LICENSE.txt"):
        license_file = Path(driver).resolve().parent.parent / name
        if license_file.is_file():
            replace_copy(license_file, resources / "MoltenVK-LICENSE.txt")
            break
    data = Path(record["data"])
    defaults = {
        "REO_ISO": record["iso"], "REO_MC1_ROOT": ":none:", "REO_NATURAL": "1",
        "REO_TURBO": "1", "REO_GS_BACKEND": "parallel", "REO_GS_THREAD": "1",
        "REO_GS_GPU_PRESENT": "1", "REO_GS_DISPATCH_PACE": "2",
        "REO_GS_SPRITE_DEPTH_PARALLEL": "1", "REO_VIF1_GPU_RESIDENT": "0",
        "REO_VIF1_ASYNC": "1", "REO_INTERNAL_RESOLUTION": "1", "REO_DEBUG_PANEL": "0",
        "REO_POST_AA": "none", "REO_GPU_MOVIE": "0",
    }
    script = '#!/bin/zsh\nset -eu\nreo_app_contents="$(cd "$(dirname "$0")/.." && pwd)"\n'
    script += 'reo_user_data="$HOME/Library/Application Support/OutbreakRecomp"\n'
    script += 'mkdir -p "$reo_user_data/memory-cards/default/data"\ncd "$reo_user_data"\n'
    script += 'export GRANITE_VULKAN_LIBRARY="$reo_app_contents/Frameworks/libMoltenVK.dylib"\n'
    script += 'export REO_MC0_ROOT="${REO_MC0_ROOT:-$reo_user_data/memory-cards/default/data}"\n'
    for key, value in defaults.items():
        script += f'if [[ -z "${{{key}:-}}" ]]; then export {key}={shlex.quote(value)}; fi\n'
    script += ('exec "$reo_app_contents/MacOS/reo_recomp" --game file1 --elf ' +
               shlex.quote(str(data / "SLUS_207.65")) + ' --data ' + shlex.quote(str(data)) + '\n')
    launcher = macos / "Outbreak"
    launcher.write_text(script)
    launcher.chmod(0o755)
    with (contents / "Info.plist").open("wb") as stream:
        plistlib.dump({"CFBundleIdentifier": "net.ninjacornix.reo.rc1",
            "CFBundleName": "RE Outbreak RC1", "CFBundleDisplayName": "RE Outbreak RC1",
            "CFBundleExecutable": "Outbreak", "CFBundlePackageType": "APPL",
            "CFBundleShortVersionString": "1.0.20", "CFBundleVersion": "1",
            "LSMinimumSystemVersion": platform.mac_ver()[0],
            "NSHighResolutionCapable": True}, stream)
    (resources / "LOCAL-BUILD.txt").write_text(
        "Local RC1 macOS development build. Requires the original local ISO and imported data.\n"
        "Not a validated public release or a redistributable game package.\n")
    return app
