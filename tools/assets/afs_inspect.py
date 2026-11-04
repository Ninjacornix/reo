#!/usr/bin/env python3
"""List the nested AFS archives of an imported Outbreak disc (read-only).

Usage: afs_inspect.py <imported disc data folder> [--entries N] [--check]

Prints each NETBIO*.DAT / DUMMY.DAT archive, its entries and names, and the entries of
nested .afs archives. --check verifies the layout facts docs/ASSET_PAKS.md relies on:
0x800-aligned entries, entries inside the archive, and name-record size copies.
Reads the player's own files; writes nothing.
"""
import argparse
import struct
from pathlib import Path

SECTOR = 0x800
NAME_RECORD = 48


def read_toc(f, base):
    """AFS: 'AFS\\0', u32 count, count x (u32 offset, u32 size), then (u32 name table
    offset, u32 name table size). Offsets are relative to the archive start."""
    f.seek(base)
    head = f.read(8)
    if len(head) < 8 or head[:4] != b"AFS\0":
        return None
    count = struct.unpack_from("<I", head, 4)[0]
    raw = f.read(count * 8 + 8)
    entries = [struct.unpack_from("<II", raw, i * 8) for i in range(count)]
    name_offset, name_size = struct.unpack_from("<II", raw, count * 8)
    names = []
    if name_offset and name_size:
        f.seek(base + name_offset)
        table = f.read(name_size)
        for i in range(count):
            record = table[i * NAME_RECORD:(i + 1) * NAME_RECORD]
            if len(record) < NAME_RECORD:
                break
            name = record[:32].split(b"\0")[0].decode("ascii", "replace")
            names.append((name, struct.unpack_from("<I", record, 44)[0]))
    return entries, (name_offset, name_size), names


def inspect(path, limit, check, problems):
    with open(path, "rb") as f:
        total = path.stat().st_size

        def walk(base, size, label, depth):
            toc = read_toc(f, base)
            if toc is None:
                return
            entries, (noff, nsize), names = toc
            pad = "  " * depth
            print(f"{pad}{label}: {len(entries)} entries, name table "
                  f"{'none' if not nsize else f'at {noff:#x} ({nsize} bytes)'}")
            for i, (offset, length) in enumerate(entries):
                name = names[i][0] if i < len(names) else f"#{i}"
                f.seek(base + offset)
                magic = f.read(4)
                if i < limit:
                    print(f"{pad}  [{i:4}] {name:24} off={offset:#010x} size={length:#010x} head={magic!r}")
                if check:
                    if offset % SECTOR:
                        problems.append(f"{label}[{i}] offset {offset:#x} not 0x800-aligned")
                    if offset + length > size:
                        problems.append(f"{label}[{i}] extends past its archive")
                    if i < len(names) and names[i][1] != length:
                        problems.append(f"{label}[{i}] name-record size {names[i][1]:#x} != {length:#x}")
                if magic == b"AFS\0" and depth == 0:
                    walk(base + offset, length, f"{label}/{name}", depth + 1)
            if len(entries) > limit:
                print(f"{pad}  ... {len(entries) - limit} more")

        walk(0, total, path.name, 0)


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("disc", type=Path)
    parser.add_argument("--entries", type=int, default=6)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    problems = []
    for path in sorted(args.disc.glob("*.DAT")):
        inspect(path, args.entries, args.check, problems)
        print()
    if args.check:
        print("check:", "OK" if not problems else f"{len(problems)} problems")
        for problem in problems[:40]:
            print("  " + problem)


if __name__ == "__main__":
    main()
