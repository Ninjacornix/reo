"""Generate supplemental entries and legacy dispatch adapters in private storage."""

import csv
import json
from pathlib import Path
import struct
import re


def generate_support(staging, metadata, invoke):
    staging, metadata = Path(staging), Path(metadata)
    plan = json.loads((metadata / "local_supplemental_functions.json").read_text())
    if plan.get("format") != 1:
        raise ValueError("Unsupported supplemental function metadata")
    for number, group in enumerate(plan["groups"]):
        name = f"supplemental{number}"
        image = bytearray((staging / f'inputs/o{group["overlay"]}.elf').read_bytes())
        struct.pack_into("<I", image, 24, int(group["functions"][0]["start"], 16))
        elf = staging / "inputs" / (name + ".elf")
        elf.write_bytes(image)
        function_map = staging / "inputs" / (name + ".csv")
        with function_map.open("w", newline="") as f:
            writer = csv.DictWriter(f, fieldnames=["name", "start", "end", "size"])
            writer.writeheader()
            writer.writerows(group["functions"])
        output = staging / "inputs" / name
        invoke(name, elf, function_map, output)
        target = staging / "output_extra" / group["destination"]
        if not target.resolve().is_relative_to((staging / "output_extra").resolve()):
            raise ValueError("Supplemental output escapes its private directory")
        target.parent.mkdir(parents=True, exist_ok=True)
        header, stubs = name + "_functions.h", name + "_stubs.h"
        (target.parent / header).write_text((output / "ps2_recompiled_functions.h").read_text().replace(
            "PS2_RECOMPILED_FUNCTIONS_H", name.upper() + "_FUNCTIONS_H"))
        stub_input = output / "ps2_recompiled_stubs.h"
        (target.parent / stubs).write_text((stub_input.read_text() if stub_input.exists() else "#pragma once\n").replace(
            "PS2_RECOMPILED_STUBS_H", name.upper() + "_STUBS_H"))
        bodies = []
        for function in group["functions"]:
            files = list(output.glob(function["name"] + "_0x*.cpp"))
            if len(files) != 1:
                raise ValueError("Supplemental function generation was incomplete")
            bodies.append(files[0].read_text().replace('"ps2_recompiled_functions.h"', '"' + header + '"')
                          .replace('"ps2_recompiled_stubs.h"', '"' + stubs + '"'))
        if group.get("registrationNamespace"):
            registrations = (output / "register_functions.cpp").read_text()
            known = {f['name'] + f"_0x{int(f['start'], 16):x}" for f in group["functions"]}
            calls = re.findall(r"runtime\.registerFunction\((0x[\da-fA-F]+), (\w+)\);", registrations)
            magic, ident, base = struct.unpack_from("<3I", image, 128)
            if magic != 0x336f574d:
                raise ValueError("Supplemental overlay identity is invalid")
            body = "\n".join(f"runtime.registerOverlayFunction(0x{base:x}u,0x{magic:x}u,4u,{ident}u,{pc}u,{fn});"
                             for pc, fn in calls if fn in known)
            if not body:
                raise ValueError("Supplemental resumable registration was not generated")
            bodies.append("namespace " + group["registrationNamespace"] +
                          " { inline void install(PS2Runtime& runtime) {\n" + body + "\n} }\n")
        target.write_text("\n".join(bodies))
        # The tool also emits unrelated discovered entries. They are not build
        # inputs; remove only these freshly generated files after retaining the
        # selected functions and complete compiler log.
        for unused in output.glob("*.cpp"):
            if not unused.resolve().is_relative_to(staging.resolve()):
                raise ValueError("Temporary generation output escaped its workspace")
            unused.unlink()

    legacy = json.loads((metadata / "local_legacy_entries.json").read_text())
    if legacy.get("format") != 1:
        raise ValueError("Unsupported legacy entry metadata")
    output = staging / "output_overlay"
    output.mkdir(exist_ok=True)
    header = '#pragma once\n#include "ps2_runtime.h"\n'
    source = ['#include "ps2_overlay_functions.h"', '#include <stdexcept>']
    for entry in legacy["entries"]:
        name, pc = entry["name"], entry["pc"]
        signature = f"void {name}(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime)"
        header += signature + ";\n"
        source += [signature + " {", f"auto function = runtime->lookupFunction(0x{pc:x}u);",
                   f'if (!function || function == &{name}) throw std::runtime_error("Unloaded legacy overlay entry");',
                   "function(rdram, ctx, runtime);", "}"]
    # Actual MWo3-scoped registrations select the disc's active overlay; adapters
    # satisfy older authored direct calls without embedding a captured overlay.
    source += ["void registerOverlayFunctions(PS2Runtime&) {}"]
    (output / "ps2_overlay_functions.h").write_text(header)
    (output / "legacy_adapters.cpp").write_text("\n".join(source) + "\n")
