"""Attach a pinned LLVM/MinGW toolchain and matching independent libraries to a kit."""

import argparse
import json
from pathlib import Path
import shutil
import zipfile

from compile_game import digest

ARCHIVE_SHA256 = "2d96a4b758f7f8deaec5065833fe025aa53cfc5f704d0524002510984da0ccf4"
RELEASE = "20251216"


def portable_bootstrap(kit):
    source = Path(kit) / "source/recomp/reo_bootstrap.cpp"
    text = source.read_text(encoding="utf-8")
    if '#define Rectangle ReoWin32Rectangle' not in text:
        text = text.replace('#define ShowCursor ReoWin32ShowCursor\n#include <windows.h>',
                            '#define ShowCursor ReoWin32ShowCursor\n#define Rectangle ReoWin32Rectangle\n#include <windows.h>')
        text = text.replace('#undef ShowCursor\n', '#undef ShowCursor\n#undef Rectangle\n')
    text = text.replace('g.serial == "SLUS-20765"', 'std::strcmp(g.serial, "SLUS-20765") == 0')
    source.write_text(text, encoding="utf-8")


def export(kit, archive, libraries, recompiler):
    kit, archive, libraries, recompiler = map(lambda p: Path(p).resolve(),
                                             (kit, archive, libraries, recompiler))
    if (kit / "build-kit.json").exists() or (kit / "toolchain").exists():
        raise FileExistsError("Choose an unsealed kit without a toolchain")
    if digest(archive) != ARCHIVE_SHA256:
        raise ValueError("Use the pinned official llvm-mingw UCRT x86-64 archive")
    executables = {"clang.exe", "clang++.exe", "clang-21.exe", "ld.lld.exe", "llvm-ar.exe",
                   "llvm-rc.exe", "llvm-cvtres.exe", "llvm-windres.exe",
                   "x86_64-w64-mingw32-clang.exe", "x86_64-w64-mingw32-clang++.exe",
                   "x86_64-w64-mingw32-windres.exe"}
    with zipfile.ZipFile(archive) as zipped:
        for member in zipped.infolist():
            relative = Path(*Path(member.filename).parts[1:])
            if not relative.parts or member.is_dir():
                continue
            wanted = (relative.parts[0] in {"include", "lib", "share", "x86_64-w64-mingw32"}
                      or relative.parent == Path(".")
                      or (relative.parent == Path("bin") and
                          (relative.suffix in {".dll", ".cfg"} or relative.name in executables)))
            if not wanted:
                continue
            target = (kit / "toolchain" / relative).resolve()
            if not target.is_relative_to(kit / "toolchain"):
                raise ValueError("Toolchain archive escapes its destination")
            target.parent.mkdir(parents=True, exist_ok=True)
            with zipped.open(member) as source, target.open("wb") as output:
                shutil.copyfileobj(source, output)
    plan_file = kit / "compile-plan.json"
    plan = json.loads(plan_file.read_text())
    preserved = kit.parent / (kit.name + "-original-msvc-libraries")
    preserved.mkdir(exist_ok=False)
    for library in (kit / "libraries").glob("*.lib"):
        library.rename(preserved / library.name)
    independent = []
    for name in ("raylib", "fmt", "dwarf", "granite-vulkan", "granite-volk", "granite-util", "granite-math"):
        matches = list(libraries.rglob("lib" + name + ".a"))
        if len(matches) != 1:
            raise ValueError("Supply exactly one matching LLVM library: " + name)
        target = kit / "libraries" / matches[0].name
        shutil.copyfile(matches[0], target)
        independent.append({"path": "{kit}/libraries/" + target.name,
                            "sha256": digest(target), "provenance": "third-party"})
    plan.update(toolchain="llvm-mingw", compiler="{kit}/toolchain/bin/x86_64-w64-mingw32-clang++.exe",
                archiver="{kit}/toolchain/bin/llvm-ar.exe",
                resourceCompiler="{kit}/toolchain/bin/x86_64-w64-mingw32-windres.exe",
                independentInputs=independent, copyLocalCrt=False,
                resources=["{kit}/resources/game-icon.rc"])
    for option in ("/D_WIN32_WINNT=0x0A00", "/DWINVER=0x0A00"):
        if option not in plan["compileOptions"]:
            plan["compileOptions"].append(option)
    for name in ("libc++.dll", "libunwind.dll", "libwinpthread-1.dll"):
        relative = "toolchain/x86_64-w64-mingw32/bin/" + name
        if not (kit / relative).is_file():
            raise FileNotFoundError(relative)
        plan["copyOutputs"].append({"source": "{kit}/" + relative, "destination": name})
        shutil.copyfile(kit / relative, kit / "tools" / name)
    shutil.copyfile(recompiler, kit / "tools/ps2_recomp.exe")
    (kit / "notices/LLVM-MINGW.json").write_text(json.dumps({
        "release": RELEASE, "archiveSha256": ARCHIVE_SHA256,
        "url": "https://github.com/mstorsjo/llvm-mingw/releases/download/" + RELEASE + "/" + archive.name,
        "licences": "../toolchain/share and toolchain root licence files",
    }, indent=2))
    plan_file.write_text(json.dumps(plan, indent=2))
    portable_bootstrap(kit)
    print("Portable LLVM kit prepared; no system compiler is used")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ("kit", "archive", "libraries", "recompiler"):
        parser.add_argument("--" + name, type=Path, required=True)
    args = parser.parse_args()
    export(args.kit, args.archive, args.libraries, args.recompiler)
