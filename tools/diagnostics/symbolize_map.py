#!/usr/bin/env python3
"""Resolve `[CRASH] stack (module+rva)` entries with an MSVC linker map.

    python tools/diagnostics/symbolize_map.py build-ninja/recomp/reo_recomp_file2.map <stderr.log>

Reads the map's "Publics by Value" table (Rva+Base column), so static
functions resolve to the nearest preceding public symbol. Build the map by
relinking with /MAP; the exe that crashed must come from the same link.
"""
import bisect
import re
import sys


def load(map_path):
    base, symbols = None, []
    with open(map_path, errors="replace") as stream:
        for line in stream:
            if base is None:
                m = re.search(r"Preferred load address is ([0-9a-fA-F]+)", line)
                if m:
                    base = int(m.group(1), 16)
                continue
            m = re.match(r"\s*[0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{16})\s", line)
            if m:
                symbols.append((int(m.group(2), 16) - base, m.group(1)))
    symbols.sort()
    return [rva for rva, _ in symbols], [name for _, name in symbols]


def main():
    rvas, names = load(sys.argv[1])
    module = sys.argv[3] if len(sys.argv) > 3 else None
    text = open(sys.argv[2], errors="replace").read()
    for line in text.splitlines():
        if "[CRASH]" not in line:
            continue
        print(line[:160])
        for exe, rva in re.findall(r"([\w.]+\.exe)\+0x([0-9A-Fa-f]+)", line):
            if module and exe != module:
                continue
            value = int(rva, 16)
            i = bisect.bisect_right(rvas, value) - 1
            name = names[i] if i >= 0 else "?"
            print("   %s+0x%X  %s+0x%X" % (exe, value, name, value - rvas[i] if i >= 0 else 0))


if __name__ == "__main__":
    main()
