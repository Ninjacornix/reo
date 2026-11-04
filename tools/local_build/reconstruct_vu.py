#!/usr/bin/env python3
"""Reconstruct VU images from user ELF copy ranges, then emit local block sources.

Published metadata has offsets, lengths, entry points and hashes only. Neither
microcode bytes nor game-specific translated instruction bodies are bundled.
"""

import argparse
import hashlib
import json
from pathlib import Path
import re
import struct


def reconstruct(elf, plan, output):
    source = Path(elf).read_bytes()
    recipe = json.loads(Path(plan).read_text())
    if recipe.get("format") != 1 or hashlib.sha256(source).hexdigest() != recipe["elfSha256"]:
        raise ValueError("Unsupported source ELF")
    output = Path(output)
    if output.exists():
        raise FileExistsError("Choose a fresh private VU output directory")
    images = {}
    for image in recipe["images"]:
        if type(image.get("enabledByDefault", False)) is not bool:
            raise ValueError("Invalid VU default policy")
        expected = image["sha256"]
        if not re.fullmatch(r"[0-9a-f]{64}", expected) or image["bytes"] != 16384 or expected in images:
            raise ValueError("Invalid VU image identity")
        code = bytearray(image["bytes"])
        occupied = bytearray(len(code))
        for start, destination, count in image["copies"]:
            if any(type(v) is not int for v in (start, destination, count)) or min(start, destination) < 0 or count <= 0:
                raise ValueError("Invalid VU copy range")
            if start + count > len(source) or destination + count > len(code) or any(occupied[destination:destination + count]):
                raise ValueError("Overlapping/out-of-bounds VU copy range")
            code[destination:destination + count] = source[start:start + count]
            occupied[destination:destination + count] = b"\x01" * count
        if hashlib.sha256(code).hexdigest() != expected:
            raise ValueError("Reconstructed VU image does not match its expected identity")
        starts = image["entryPcs"]
        if not starts or any(type(pc) is not int or pc & 7 or not 0 <= pc < 16384 for pc in starts):
            raise ValueError("Invalid VU entry metadata")
        images[expected] = bytes(code)
    output.mkdir(parents=True)
    events = []
    for n, image in enumerate(recipe["images"]):
        expected = image["sha256"]
        filename = "image-" + expected + ".bin"
        (output / filename).write_bytes(images[expected])
        event = {"event": "image", "image": n, "file": filename, "bytes": 16384,
                 "sha256": expected}
        if image.get("enabledByDefault", False):
            event["enabled_by_default"] = True
        events.append(event)
        for pc in image["entryPcs"]:
            events.append({"event": "launch", "image": n, "sha256": expected, "start_pc": pc})
    (output / "events.jsonl").write_text("\n".join(json.dumps(row) for row in events) + "\n")
    emit_specialized(recipe, images, output / "specialized")
    return len(images)


def emit_specialized(recipe, images, output):
    output.mkdir()
    source = ['// Generated locally from a verified user-owned ELF; do not distribute.',
              '#include "reo_vu_specialized_generated.h"', '#include "vu_specialized_route.h"',
              '#include "vu_specialized_helpers.h"', '#include <array>', 'namespace {']
    programs = []
    for n, program in enumerate(recipe["specialized"]):
        code = images[program["sha256"]]
        source.append(f"static constexpr uint8_t image{n}[] = {{")
        for i in range(0, len(code), 24):
            source.append(",".join(f"0x{v:02x}" for v in code[i:i + 24]) + ",")
        source.append("};")
        entries = []
        for b, (start, count) in enumerate(program["blocks"]):
            if start & 7 or count <= 0 or start + count * 8 > len(code):
                raise ValueError("Invalid specialized block extent")
            name = f"block{n}_{b}"
            source += [f"uint32_t run_{name}(vu_specialized::Invocation& in) {{",
                       "auto& s=in.state; auto* data=in.data; auto& gs=in.gs; auto* memory=in.memory;",
                       "auto& pending=in.branchPending; auto& target=in.branchTarget;",
                       "vu_specialized::GenericFallback fallback{in};"]
            for pc in range(start, start + count * 8, 8):
                lo, hi = struct.unpack_from("<II", code, pc)
                literal = bool(hi & 0x80000000)
                op = (lo >> 25) & 127
                branch = not literal and op in {0x20, 0x21, 0x24, 0x25, 0x28, 0x29, 0x2c, 0x2d, 0x2e, 0x2f}
                kick = not literal and op == 0x40 and lo & 2047 == 0x6fc
                if hi & 0x40000000 or kick or branch and pc != start + (count - 2) * 8:
                    raise ValueError("Specialized block contains an unsupported scheduling boundary")
                lower, upper = f"0x{lo:08X}u", f"0x{hi:08X}u"
                source += ["{", f"const bool upperSafe=vuBlockUpperSafe<{upper}>(s);",
                    f"if(upperSafe) {{ if constexpr(({upper}&0x7ffu)!=0x2ffu) vuBlockUpper<{upper}>(s); }}",
                    f"else fallback({lower},{upper},true);",
                    f"const bool lowerSafe=vuBlockLowerSafe<{lower},{upper}>(s);",
                    f"if constexpr({upper}&0x80000000u) {{ constexpr uint32_t bits={lower}; std::memcpy(&s.i,&bits,4); }}",
                    f"else if constexpr({lower}!=0x8000033cu) {{ if(lowerSafe) vuBlockLower<{lower}>(s,data,16384u,gs,memory); else fallback({lower},{upper},false); }}",
                    "const bool newBranch=(s.pc&0x80000000u)!=0; const uint32_t newTarget=s.pc&0x3fffu;",
                    "s.vf[0][0]=0; s.vf[0][1]=0; s.vf[0][2]=0; s.vf[0][3]=1; s.vi[0]=0;",
                    f"s.pc=pending?target:0x{pc:x}u+8u; if(s.pc>=16384u)s.pc=0;",
                    "pending=newBranch; target=newTarget;", "}"]
            source += [f"return {count};", "}",
                       f"const vu_specialized::Block {name}{{{count},run_{name}}};"]
            entries.append((start, name))
        source += [f"constexpr auto entries{n}=[] {{ std::array<const vu_specialized::Block*,2048> result{{}};"]
        source += [f"result[0x{pc:x}/8]=&{name};" for pc, name in entries]
        source += ["return result; }();"]
        programs.append(f"{{image{n},16384,16384,entries{n}.data()}}")
    source += ["const vu_specialized::Program programs[]={" + ",".join(programs) + "};",
               "const vu_specialized::ProgramTable table{programs," + str(len(programs)) + "};", "}",
               "namespace reo_vu_specialized_generated {",
               "const vu_specialized::ProgramTable* programTable() noexcept {return &table;}", "}"]
    (output / "reo_vu_specialized_generated.cpp").write_text("\n".join(source) + "\n")
    (output / "reo_vu_specialized_generated.h").write_text(
        "#pragma once\nnamespace vu_specialized {struct ProgramTable;}\n" +
        "namespace reo_vu_specialized_generated {const vu_specialized::ProgramTable* programTable() noexcept;}\n")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--elf", required=True, type=Path)
    parser.add_argument("--plan", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()
    print(f"Reconstructed {reconstruct(args.elf, args.plan, args.output)} VU images locally")


if __name__ == "__main__":
    main()
