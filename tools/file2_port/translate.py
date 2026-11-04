#!/usr/bin/env python3
"""Translate File #1 guest addresses to File #2 using match_functions.py output.

    python tools/file2_port/translate.py 0x1F73B0 0x231050
    python tools/file2_port/translate.py --scan recomp/overrides/reo_override.cpp
    python tools/file2_port/translate.py --image id3 0x617000

An address in the main ELF window resolves through `main`; one in an overlay
window is tried against every overlay loaded there (or only --image). It
resolves as a function start, as an offset inside an identically sized
matched function, or as an exactly voted data constant (or within 0x40 bytes
after one, sharing its delta). Anything else is UNMAPPED and must be located
by hand (Ghidra xrefs, string or pattern search). Results are candidates, not
proof; check each one in Ghidra before using it.
"""
import argparse
import bisect
import json
import re

ADDRESS = re.compile(r"\b0x(00)?([1-9A-Fa-f][0-9A-Fa-f]{4,5})u?\b")
DEFAULT_MAP = "recomp/config/file2/file1_to_file2.json"


class ImageMap:
    def __init__(self, record):
        self.low, self.high = (int(x, 16) for x in record["file1Range"])
        self.functions = {int(k, 16): (int(v["file2"], 16), v["method"], v["size1"], v["size2"])
                          for k, v in record["functions"].items()}
        self.starts = sorted(self.functions)
        self.data = {int(k, 16): int(v["file2"], 16) for k, v in record["data"].items()}
        self.data_keys = sorted(self.data)

    def __call__(self, address):
        if address in self.functions:
            return self.functions[address][0], "function/" + self.functions[address][1]
        i = bisect.bisect_right(self.starts, address) - 1
        if i >= 0:
            start = self.starts[i]
            b, method, s1, s2 = self.functions[start]
            if address < start + s1 and s1 == s2:
                return b + address - start, "inside/" + method
        if address in self.data:
            return self.data[address], "data"
        j = bisect.bisect_right(self.data_keys, address) - 1
        if j >= 0 and address - self.data_keys[j] <= 0x40:
            base = self.data_keys[j]
            return self.data[base] + address - base, "data+0x%X" % (address - base)
        return None, "unmapped"


class Translator:
    def __init__(self, path=DEFAULT_MAP):
        self.images = {tag: ImageMap(r) for tag, r in json.load(open(path))["images"].items()
                       if r["file1Range"]}

    def candidates(self, address, image=None):
        tags = [image] if image else ["main"] + sorted(t for t in self.images if t != "main")
        out = []
        for tag in tags:
            m = self.images[tag]
            if tag == "main" or m.low <= address < m.high:
                b, how = m(address)
                if b is not None:
                    out.append((tag, b, how))
                if tag == "main" and m.low <= address < m.high and b is not None:
                    break
        return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--map", default=DEFAULT_MAP)
    ap.add_argument("--image")
    ap.add_argument("--scan", nargs="*", default=[])
    ap.add_argument("addresses", nargs="*")
    args = ap.parse_args()
    t = Translator(args.map)
    values = [int(a, 16) for a in args.addresses]
    for path in args.scan:
        values += [int(m.group(2), 16) for m in ADDRESS.finditer(open(path, encoding="utf-8", errors="replace").read())]
    summary = {}
    for value in sorted(set(v for v in values if 0x100000 <= v < 0x2000000)):
        found = t.candidates(value, args.image)
        kind = found[0][2].split("/")[0].split("+")[0] if found else "unmapped"
        summary[kind] = summary.get(kind, 0) + 1
        text = "  ".join("%s:0x%08X(%s)" % c for c in found) or "?"
        print("0x%08X -> %s" % (value, text))
    print("summary:", summary)


if __name__ == "__main__":
    main()
