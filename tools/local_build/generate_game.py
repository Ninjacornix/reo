#!/usr/bin/env python3
"""Generate main/overlay AOT sources from a verified local disc import.

No generated game code is read from a template or downloaded. Output stays in
the explicitly supplied private work directory. Requires the independent
ps2_recomp tool and address metadata shipped with the build kit.
"""

import argparse
import csv
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from overlay_extract import decompress, wrap_elf
from generate_catalogues import generate as generate_catalogues
from generate_support import generate_support

ELF_SHA256 = "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46"
MAGIC = 0x336F574D


def sha(path):
    with Path(path).open("rb") as source:
        return hashlib.file_digest(source, "sha256").hexdigest()


def generate(recompiler, disc, metadata, destination):
    recompiler, disc, metadata, destination = map(Path, (recompiler, disc, metadata, destination))
    elf = disc / "SLUS_207.65"
    if sha(elf) != ELF_SHA256:
        raise ValueError("Unsupported ELF revision; local recompilation was not started")
    bin_dir = next((p for p in disc.iterdir() if p.is_dir() and p.name.upper() == "BIN"), None)
    if bin_dir is None:
        raise ValueError("The imported disc has no BIN overlay directory")
    if destination.exists():
        raise FileExistsError("Choose a fresh generation directory; existing outputs are preserved")
    destination.parent.mkdir(parents=True, exist_ok=True)
    staging = Path(tempfile.mkdtemp(prefix=destination.name + ".generating-", dir=destination.parent))
    logs = staging / "logs"
    logs.mkdir()
    work = staging / "inputs"
    work.mkdir()

    def invoke(name, image, function_map, output, skip=()):
        # TOML strings are escaped using JSON's compatible basic-string syntax.
        quote = lambda p: json.dumps(str(Path(p).resolve()).replace("\\", "/"))
        config = work / (name + ".toml")
        config.write_text("[general]\ninput = " + quote(image) + "\nghidra_output = " +
                          quote(function_map) + "\noutput = " + quote(output) +
                          "\nsingle_file_output = false\npatch_syscalls = false\n" +
                          "patch_cop0 = true\npatch_cache = true\nstubs = []\nskip = " +
                          json.dumps(list(skip)) + "\n")
        print("Generating " + name, flush=True)
        with (logs / (name + ".log")).open("wb") as log:
            subprocess.run([str(recompiler.resolve()), str(config)], check=True,
                           stdout=log, stderr=subprocess.STDOUT)

    main = staging / "output"
    invoke("main", elf, metadata / "outbreak_ghidra_functions.csv", main,
           ("sub_00117080", "sub_00117818", "sub_001179E8"))

    with (metadata / "extra_functions.csv").open(newline="") as f:
        extra_rows = list(csv.DictReader(f))
    for row in extra_rows:
        row["name"] = "x_" + re.sub(r"^(sub|FUN)_", "", row["name"])
    extra_map = work / "extra.csv"
    with extra_map.open("w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=["name", "start", "end", "size"])
        writer.writeheader()
        writer.writerows(extra_rows)
    extra_image = bytearray(elf.read_bytes())
    struct.pack_into("<I", extra_image, 24, int(extra_rows[0]["start"], 16))
    extra_elf = work / "extra.elf"
    extra_elf.write_bytes(extra_image)
    all_extra = work / "extra_all"
    invoke("extra", extra_elf, extra_map, all_extra)
    extra = staging / "output_extra"
    extra.mkdir()
    ranges = [(int(row["start"], 16), int(row["end"], 16)) for row in extra_rows]
    inside_extra = lambda address: any(start <= address < end for start, end in ranges)
    registrations = re.findall(r"runtime\.registerFunction\((0x[\da-fA-F]+), (\w+)\);",
                                (all_extra / "register_functions.cpp").read_text())
    kept = {name for address, name in registrations if inside_extra(int(address, 16))}
    (extra / "extra_functions.h").write_text((all_extra / "ps2_recompiled_functions.h").read_text()
        .replace("PS2_RECOMPILED_FUNCTIONS_H", "REO_EXTRA_FUNCTIONS_H"))
    (extra / "ps2_recompiled_stubs.h").write_text((all_extra / "ps2_recompiled_stubs.h").read_text())
    for file in all_extra.glob("*.cpp"):
        if file.name == "register_functions.cpp":
            continue
        if any(file.name.startswith(name.rsplit("_0x", 1)[0]) for name in kept):
            (extra / file.name).write_text(file.read_text().replace('"ps2_recompiled_functions.h"',
                                                                  '"extra_functions.h"'))
    (extra / "register_extra.cpp").write_text(
        '#include "ps2_runtime.h"\n#include "extra_functions.h"\n' +
        "void reoRegisterExtraFunctions(PS2Runtime& runtime) {\n" +
        "\n".join(f"    runtime.registerFunction({pc}u, {name});" for pc, name in registrations
                   if inside_extra(int(pc, 16))) + "\n}\n")

    overlays = staging / "output_ovl"
    overlays.mkdir()
    tags = []
    for function_map in sorted((metadata / "overlay_maps").glob("ovl*.csv")):
        number = function_map.stem.removeprefix("ovl")
        if not number.isdecimal():
            raise ValueError("Invalid overlay map name")
        asset = bin_dir / (number + ".DAT")
        raw = asset.read_bytes()
        image = decompress(raw, out_size=32 * 1024 * 1024) if raw[:2] == b"\x02\x00" else raw
        if len(image) < 64 or image[:4] != b"MWo3":
            raise ValueError("Invalid overlay image: " + asset.name)
        ident, base, text_size, data_size = struct.unpack_from("<4I", image, 4)
        if base >= 32 * 1024 * 1024 or text_size + 64 > len(image) or len(image) > 32 * 1024 * 1024:
            raise ValueError("Overlay dimensions are outside supported memory")
        with function_map.open(newline="") as f:
            rows = [r for r in csv.DictReader(f)
                    if int(r["start"], 16) >= base + 0x80 and int(r["start"], 16) % 4 == 0]
        if not rows:
            raise ValueError("Empty overlay function map: " + function_map.name)
        rows.sort(key=lambda r: int(r["start"], 16))
        tag = "o" + number
        for row in rows:
            row["name"] = re.sub(r"^(sub|FUN)_", tag + "_", row["name"])
        mapped = work / (tag + ".csv")
        with mapped.open("w", newline="") as f:
            writer = csv.DictWriter(f, fieldnames=["name", "start", "end", "size"])
            writer.writeheader()
            writer.writerows(rows)
        wrapped = bytearray(wrap_elf(image, base, text_size + 0x40))
        struct.pack_into("<I", wrapped, 24, int(rows[0]["start"], 16))
        overlay_elf = work / (tag + ".elf")
        overlay_elf.write_bytes(wrapped)
        out = overlays / tag
        invoke(tag, overlay_elf, mapped, out)
        header = out / "ps2_recompiled_functions.h"
        private_header = tag + "_functions.h"
        (out / private_header).write_text(header.read_text().replace(
            "PS2_RECOMPILED_FUNCTIONS_H", tag.upper() + "_RECOMPILED_FUNCTIONS_H"))
        header.unlink()
        for source in out.glob("*.cpp"):
            source.write_text(source.read_text().replace('"ps2_recompiled_functions.h"',
                                                        '"' + private_header + '"'))
        registry = out / "register_functions.cpp"
        calls = re.findall(r"runtime\.registerFunction\((0x[\da-fA-F]+), (\w+)\);", registry.read_text())
        registry.unlink()
        entries = [f"    runtime.registerOverlayFunction(0x{base:X}u, 0x{MAGIC:X}u, 4u, {ident}u, {pc}u, {fn});"
                   for pc, fn in calls if int(pc, 16) >= base + 0x80]
        (out / ("register_" + tag + ".cpp")).write_text(
            '#include "ps2_runtime.h"\n#include "' + private_header + '"\n' +
            f"void reoRegisterOverlay_{tag}(PS2Runtime& runtime) {{\n" + "\n".join(entries) + "\n}\n")
        tags.append(tag)
    (overlays / "register_overlays.cpp").write_text(
        '#include "ps2_runtime.h"\n' +
        "\n".join(f"void reoRegisterOverlay_{tag}(PS2Runtime&);" for tag in tags) +
        "\nvoid reoRegisterOverlays(PS2Runtime& runtime) {\n" +
        "\n".join(f"    reoRegisterOverlay_{tag}(runtime);" for tag in tags) + "\n}\n")
    generate_support(staging, metadata, invoke)
    catalogue_count = generate_catalogues(elf, metadata / "local_source_catalogues.json",
                                          staging / "local_source_catalogues")
    sources = list(staging.rglob("*.cpp"))
    record = {"format": 1, "elfSha256": ELF_SHA256, "recompilerSha256": sha(recompiler),
              "overlays": tags, "instructionWitnesses": catalogue_count,
              "sourceFiles": len(sources),
              "files": [{"path": str(p.relative_to(staging)).replace("\\", "/"), "sha256": sha(p)}
                        for p in sources]}
    (staging / "generation.json").write_text(json.dumps(record, indent=2))
    staging.rename(destination)
    return record


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--recompiler", required=True, type=Path)
    parser.add_argument("--disc", required=True, type=Path)
    parser.add_argument("--metadata", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()
    result = generate(args.recompiler, args.disc, args.metadata, args.output)
    print(json.dumps({k: v for k, v in result.items() if k != "files"}, indent=2))


if __name__ == "__main__":
    main()
