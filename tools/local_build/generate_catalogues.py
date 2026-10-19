#!/usr/bin/env python3
"""Read instruction witnesses from a user-owned ELF; no opcodes are distributed."""

import argparse
import hashlib
import json
from pathlib import Path
import struct


def generate(elf_path, manifest_path, output):
    data = Path(elf_path).read_bytes()
    manifest = json.loads(Path(manifest_path).read_text())
    if manifest.get("format") != 1 or hashlib.sha256(data).hexdigest() != manifest["elfSha256"]:
        raise ValueError("Unsupported ELF revision; no instruction catalogues were generated")
    if data[:7] != b"\x7fELF\x01\x01\x01":
        raise ValueError("Expected a little-endian ELF32 executable")
    phoff = struct.unpack_from("<I", data, 28)[0]
    phsize, phcount = struct.unpack_from("<HH", data, 42)
    segments = [struct.unpack_from("<8I", data, phoff + i * phsize) for i in range(phcount)]

    def instruction(pc):
        if pc & 3:
            raise ValueError("Unaligned instruction address")
        for kind, offset, address, _, size, *_ in segments:
            if kind == 1 and address <= pc and pc + 4 <= address + size:
                return struct.unpack_from("<I", data, offset + pc - address)[0]
        raise ValueError(f"Instruction address is not file-backed: {pc:#x}")

    out = Path(output)
    out.mkdir(parents=True, exist_ok=True)
    total = 0
    for name, catalogue in manifest["catalogues"].items():
        if Path(name).name != name or not name.endswith(".inc"):
            raise ValueError("Invalid generated catalogue filename")
        lines = ["// Generated locally from the user's verified ELF. Do not distribute."]
        for row in catalogue["fields"]:
            pc = row[catalogue["instructionPcField"]]
            values = [instruction(pc) if field == "instruction" else field for field in row]
            lines.append("{" + ",".join(f"0x{field:x}u" for field in values) + "},")
            total += 1
        target = out / name
        temporary = target.with_suffix(".tmp")
        temporary.write_text("\n".join(lines) + "\n")
        temporary.replace(target)
    return total


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--elf", required=True, type=Path)
    parser.add_argument("--manifest", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()
    print(f"Generated {generate(args.elf, args.manifest, args.output)} local instruction witnesses")


if __name__ == "__main__":
    main()
