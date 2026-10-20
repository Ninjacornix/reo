"""Compare COFF guest instruction bytes after masking linker relocations.

This reports instruction-body equivalence only. It does not certify relocation
targets, exception tables, linking, or gameplay.
"""
import hashlib
from bisect import bisect_left
import json
from pathlib import Path
import re
import struct
import sys


def bodies(path):
    data = path.read_bytes()
    machine, count, _, sympos, symcount, optional, _ = struct.unpack_from("<HHIIIHH", data)
    if machine != 0x8664:
        raise ValueError("Expected ordinary AMD64 COFF")
    strings = data[sympos + symcount * 18:]
    symbols, index = {}, 0
    while index < symcount:
        record = data[sympos + index * 18:sympos + (index + 1) * 18]
        name = (strings[struct.unpack_from("<I", record, 4)[0]:].split(b"\0", 1)[0]
                if record[:4] == b"\0" * 4 else record[:8].split(b"\0", 1)[0])
        value, section, kind = struct.unpack_from("<IhH", record, 8)
        symbols[index] = (name.decode(errors="strict"), value, section, kind)
        index += 1 + record[17]
    sections = {}
    for i in range(count):
        offset = 20 + optional + i * 40
        name = data[offset:offset+8].rstrip(b"\0").decode()
        if name.startswith("/"):
            name = strings[int(name[1:]):].split(b"\0", 1)[0].decode()
        size, raw, reloc = struct.unpack_from("<III", data, offset + 16)
        nreloc = struct.unpack_from("<H", data, offset + 32)[0]
        flags = struct.unpack_from("<I", data, offset + 36)[0]
        if flags & 0x01000000:
            # LLVM COFFObjectFile::getNumberOfRelocations excludes this sentinel.
            # https://llvm.org/doxygen/COFFObjectFile_8cpp_source.html
            if nreloc != 65535:
                raise ValueError("Invalid extended relocation marker")
            nreloc = struct.unpack_from("<I", data, reloc)[0] - 1
            reloc += 10
        if nreloc < 0 or reloc + nreloc * 10 > len(data):
            raise ValueError("Relocations exceed object file")
        relocations = [struct.unpack_from("<IIH", data, reloc + n * 10) for n in range(nreloc)]
        sections[i + 1] = (name, data[raw:raw + size], relocations)
    ranges = {}
    for name, raw, relocs in sections.values():
        if name != ".pdata":
            continue
        relocmap = {offset: symbol for offset, symbol, _ in relocs}
        for offset in range(0, len(raw), 12):
            if offset not in relocmap or offset + 4 not in relocmap:
                continue
            start, end = struct.unpack_from("<II", raw, offset)
            a, b = symbols[relocmap[offset]], symbols[relocmap[offset + 4]]
            if a[2] != b[2]:
                raise ValueError("Unexpected cross-section unwind range")
            ranges[(a[2], a[1] + start)] = b[1] + end
    result = {}
    by_section = {number: sorted(section[2]) for number, section in sections.items()}
    positions = {number: [row[0] for row in rows] for number, rows in by_section.items()}
    for name, start, section, kind in symbols.values():
        if kind != 0x20 or not re.match(r"^_Z\d+(?:sub_|o\d+_|x_)", name):
            continue
        end = ranges.get((section, start))
        if end is None:
            raise ValueError("No unwind range for " + name)
        _, raw, relocs = sections[section]
        code = bytearray(raw[start:end])
        named, local_count = [], 0
        lo, hi = bisect_left(positions[section], start), bisect_left(positions[section], end)
        for offset, target, relocation in by_section[section][lo:hi]:
            if relocation not in range(1, 12):
                raise ValueError("Unsupported AMD64 relocation: " + str(relocation))
            width = 8 if relocation == 1 else 2 if relocation == 10 else 4
            if offset + width > end:
                raise ValueError("Relocation crosses function boundary")
            target_name = symbols[target][0]
            addend = code[offset-start:offset-start+width].hex()
            if target_name.startswith("."):
                local_count += 1
            else:
                named.append((offset-start, relocation, target_name, addend))
            code[offset-start:offset-start+width] = b"\0" * width
        result[name] = {"bytes": len(code), "sha256": hashlib.sha256(code).hexdigest(),
                        "namedRelocationsSha256": hashlib.sha256(
                            json.dumps(named).encode()).hexdigest(),
                        "namedRelocations": len(named), "unresolvedLocalRelocations": local_count}
    return result


def main():
    root = Path(sys.argv[1]).resolve()
    report = json.loads((root / "results.json").read_text())
    versions = []
    for row in report["rows"]:
        items = {}
        for compilation in row["compilations"]:
            command = compilation["command"]
            current = bodies(Path(command[command.index("-o") + 1]))
            if items.keys() & current.keys():
                raise ValueError("Duplicate guest function in batch plan")
            items.update(current)
        versions.append((row["variant"], items))
    reference = versions[0][1]
    comparisons = []
    for name, current in versions[1:]:
        if reference.keys() != current.keys():
            raise ValueError("Batching changed the guest function set")
        different = [key for key in reference if
                     (reference[key]["bytes"], reference[key]["sha256"]) !=
                     (current[key]["bytes"], current[key]["sha256"])]
        references_differ = [key for key in reference if
                            reference[key]["namedRelocationsSha256"] !=
                            current[key]["namedRelocationsSha256"]]
        comparisons.append({"variant": name, "compared": len(reference),
                            "instructionBodiesEqual": len(reference) - len(different),
                            "different": different, "namedReferencesDiffer": references_differ,
                            "unresolvedLocalReferences": sum(
                                item["unresolvedLocalRelocations"] for item in current.values())})
    result = {"relocationsMasked": True, "relocationTargetsVerified": False,
              "exceptionTablesVerified": False, "gameExecuted": False,
              "comparisons": comparisons}
    (root / "instruction-comparison.json").write_text(json.dumps(result, indent=2))
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
