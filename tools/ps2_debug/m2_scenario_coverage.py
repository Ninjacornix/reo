"""Read-only bounded direct-call and original-opcode audit of first-room setup.

Reads the user's owned ELF/ISO and existing generated sources. Reports stay in
ignored build output; this helper does not regenerate or modify guest code.
Indirect calls and runtime overrides require live evidence, not guessed edges.
"""
import argparse
import hashlib
import json
import re
import struct
import sys
from collections import deque
from pathlib import Path

sys.dont_write_bytecode = True
ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))
from overlay_extract import Iso, decompress

ROOTS = [0x603C20, 0x6040A0, 0x68C850, 0x68C660, 0x5F0380,
         0x5FE7C0, 0x5EB6D0, 0x5EB780, 0x5EBE30,
         0x1D1F50, 0x1D0A70, 0x1D0C80, 0x1D25A0]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--depth", type=int, default=3)
    parser.add_argument("--iso", type=Path, default=ROOT / "iso/Resident Evil - Outbreak (v2.00).iso")
    parser.add_argument("--elf", type=Path, default=ROOT / "game_data/SLUS_207.65")
    parser.add_argument("--report", type=Path, default=ROOT / "build-ninja/m2-scenario/first-room-coverage.json")
    args = parser.parse_args()
    original = args.elf.read_bytes()
    if hashlib.sha256(original).hexdigest() != "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46":
        raise ValueError("Unexpected owned main ELF revision")
    segments = []
    phoff = struct.unpack_from("<I", original, 28)[0]
    for i in range(struct.unpack_from("<H", original, 44)[0]):
        typ, off, va, _, size, _, _, _ = struct.unpack_from("<8I", original, phoff + i * 32)
        if typ == 1:
            segments.append((va, original[off:off + size]))
    iso = Iso(str(args.iso))
    try:
        directory = next((l, s) for n, l, s, f in iso.listdir(*iso.root()) if n == "BIN")
        for filename in ("0.DAT", "2.DAT"):
            _, lsn, size, _ = next(e for e in iso.listdir(*directory) if e[0] == filename)
            raw = iso.read(lsn, size)
            img = decompress(raw) if raw[:2] == b"\x02\x00" else raw
            if img[:4] != b"MWo3":
                raise ValueError("Unexpected overlay")
            segments.append((struct.unpack_from("<I", img, 8)[0], img))
    finally:
        iso.f.close()
    files = {}
    registrations = {}
    for group, folder in (("main", "recomp/config/output"), ("o0", "recomp/config/output_ovl/o0"),
                          ("o2", "recomp/config/output_ovl/o2")):
        for path in (ROOT / folder).glob("*_0x*.cpp"):
            match = re.search(r"_0x([0-9a-f]+)\.cpp$", path.name)
            if match:
                files[int(match[1], 16)] = path
        register = ROOT / folder / ("register_functions.cpp" if group == "main" else f"register_{group}.cpp")
        text = register.read_text()
        for address, name in re.findall(r"(0x[0-9a-f]+)u?\s*,\s*(\w+_0x[0-9a-f]+)\s*\)", text, re.I):
            registrations[int(address, 16)] = name

    def original_word(address):
        for base, data in segments:
            if base <= address and address + 4 <= base + len(data):
                return struct.unpack_from("<I", data, address - base)[0]
        return None

    seen = set()
    pending = deque((address, 0) for address in ROOTS)
    rows, holes = [], []
    while pending:
        address, depth = pending.popleft()
        if address in seen:
            continue
        seen.add(address)
        path = files.get(address)
        if path is None:
            holes.append({"address": hex(address), "depth": depth, "kind": "no generated entry file",
                          "registered_target": registrations.get(address)})
            continue
        source = path.read_text()
        words = {int(a, 16): int(w, 16) for a, w in re.findall(r"// (0x[0-9a-f]+): (0x[0-9a-f]+)", source, re.I)}
        extent = re.search(r"// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)", source, re.I)
        start, end = (map(lambda n: int(n, 16), extent.groups()) if extent else (address, address))
        missing = [hex(a) for a in range(start, end, 4) if original_word(a) not in (None, 0) and a not in words]
        changed = [hex(a) for a, word in words.items() if original_word(a) != word]
        edges, indirect = set(), []
        for pc, word in words.items():
            opcode = word >> 26
            if opcode in (2, 3):
                target = ((pc + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)
                if not start <= target < end:
                    edges.add(target)
            elif opcode == 0 and (word & 63) == 9:
                indirect.append(hex(pc))
        row = {"address": hex(address), "depth": depth, "source": str(path.relative_to(ROOT)),
               "registered": address in registrations, "original_extent": [hex(start), hex(end)],
               "word_count": len(words), "missing_nonzero_words": missing, "changed_words": changed,
               "direct_targets": [hex(t) for t in sorted(edges)], "indirect_call_pcs": indirect,
               "todo_stub": "TODO_NAMED" in source}
        rows.append(row)
        if missing or changed or not row["registered"] or row["todo_stub"]:
            holes.append({k: v for k, v in row.items() if k in ("address", "depth", "source", "registered",
                          "missing_nonzero_words", "changed_words", "todo_stub")})
        if depth < args.depth:
            pending.extend((target, depth + 1) for target in sorted(edges))
    report = {"roots": [hex(a) for a in ROOTS], "max_depth": args.depth,
              "scope": "Main ELF plus overlays 0 and 2; direct J/JAL edges only. No live reachability claim.",
              "functions_inspected": len(rows), "holes": holes, "functions": rows}
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps({"functions_inspected": len(rows), "holes": holes, "report": str(args.report)}, indent=2))


if __name__ == "__main__":
    main()
