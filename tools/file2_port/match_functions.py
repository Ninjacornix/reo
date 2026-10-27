#!/usr/bin/env python3
"""Match File #1 (SLUS_207.65) functions and data addresses to File #2 (SLUS_209.84).

Both games share one engine, so most functions are identical apart from
relocated addresses. Each function is hashed with relocatable fields masked
(jump targets, lui/low-half immediates, gp-relative offsets); hashes unique
in both games become anchors. Anchors are extended through positional call
targets and through link-order runs between anchors. Data addresses are paired
by rebuilding lui/low-half constants inside identically shaped functions.

The main ELF and every code overlay (BIN/<n>.DAT, wrapped by
tools/overlay_extract.py) are matched together so overlay -> main calls also
propagate. Overlays pair by their MWo3 id, not by file number: the discs
number them differently (File #1 5.DAT is id 7, File #2 6.DAT is id 7).

Read-only: reads ELFs and Ghidra function maps, writes one JSON map.

    python tools/file2_port/match_functions.py --out recomp/config/file2/file1_to_file2.json \
        --file1 main=game_data/SLUS_207.65,recomp/config/outbreak_ghidra_functions.csv \
        --file1 ovl=<file1 ovl dir>,recomp/config/overlay_maps \
        --file2 main=game_data_file2/SLUS_209.84,recomp/config/file2/outbreak_file2_ghidra_functions.csv \
        --file2 ovl=game_data_file2/ovl,recomp/config/file2/overlay_maps

`ovl=<dir>,<maps>` reads <dir>/<n>.bin (raw MWo3 image, for the id) plus
<dir>/<n>.elf and <maps>/ovl<n>.csv for every overlay present.

Confidence: "exact" (unique masked hash), "call" (positional call target of an
exact/call pair, agreed by every voter), "order" (same-size slot between
anchors; probable only, verify before relying on it).
"""
import argparse
import collections
import csv
import hashlib
import json
import os
import struct

LOW_HALF_OPS = {0x08, 0x09, 0x0D, 0x18, 0x19, 0x1A, 0x1B, 0x1E, 0x1F} | set(range(0x20, 0x40))
# Opcodes whose rt field receives a GPR result (ALU immediates and GPR loads).
GPR_WRITERS = {0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x18, 0x19, 0x1A, 0x1B, 0x1E,
               0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x37}


class Image:
    def __init__(self, tag, path, function_map):
        self.tag = tag
        self.data = open(path, "rb").read()
        phoff, = struct.unpack_from("<I", self.data, 28)
        phnum, = struct.unpack_from("<H", self.data, 44)
        self.segments = []
        for i in range(phnum):
            kind, offset, vaddr, _, filesz, _, _, _ = struct.unpack_from("<8I", self.data, phoff + i * 32)
            if kind == 1 and filesz:
                self.segments.append((vaddr, offset, filesz))
        self.functions = []
        with open(function_map, newline="") as stream:
            for row in csv.DictReader(stream):
                start, end = int(row["start"], 16), int(row["end"], 16)
                if end > start:
                    self.functions.append((start, end))
        self.functions.sort()
        self.low = min(v for v, _, _ in self.segments)
        self.high = max(v + s for v, _, s in self.segments)

    def words(self, start, end):
        for vaddr, offset, size in self.segments:
            if vaddr <= start and end <= vaddr + size:
                base = offset + start - vaddr
                return list(struct.unpack_from("<%dI" % ((end - start) // 4), self.data, base))
        return None


def load_images(specs):
    images = []
    for spec in specs:
        kind, value = spec.split("=", 1)
        path, maps = value.split(",", 1)
        if kind == "main":
            images.append(Image("main", path, maps))
            continue
        for name in sorted(os.listdir(path)):
            number, ext = os.path.splitext(name)
            mapped = os.path.join(maps, "ovl" + number + ".csv")
            if ext != ".bin" or not number.isdecimal() or not os.path.exists(mapped):
                continue
            ident, = struct.unpack_from("<I", open(os.path.join(path, name), "rb").read(8), 4)
            images.append(Image("id%d" % ident, os.path.join(path, number + ".elf"), mapped))
    return images


def normalize(word):
    op = word >> 26
    if op in (2, 3):
        return word & 0xFC000000
    if op == 0x0F:
        return word & 0xFFFF0000
    if op in LOW_HALF_OPS and ((word >> 21) & 31) != 29:  # keep stack offsets
        return word & 0xFFFF0000
    return word


def shape(words):
    return hashlib.sha1(struct.pack("<%dI" % len(words), *map(normalize, words))).hexdigest()


def call_targets(start, words):
    return [((w & 0x03FFFFFF) << 2) | ((start + 4 * i) & 0xF0000000)
            for i, w in enumerate(words) if (w >> 26) == 3]


def constants(words):
    """Yield (instruction index, address) rebuilt from lui + low-half pairs."""
    high = {}
    for i, w in enumerate(words):
        op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        if op == 0x0F:
            high[rt] = (w & 0xFFFF) << 16
            continue
        if op in LOW_HALF_OPS and rs in high:
            low = w & 0xFFFF
            value = high[rs] | low if op == 0x0D else (high[rs] + (low - 0x10000 if low & 0x8000 else low)) & 0xFFFFFFFF
            yield i, value
        # Drop a tracked high half once its register is overwritten.
        if op in GPR_WRITERS:
            high.pop(rt, None)
        elif op == 0:
            high.pop((w >> 11) & 31, None)
        elif op in (2, 3) or (op == 1 and rt in (0x10, 0x11)):
            high.pop(31, None)


class Game:
    def __init__(self, images):
        self.images = {image.tag: image for image in images}
        self.words, self.shapes, self.order = {}, {}, {}
        for image in images:
            keys = []
            for start, end in image.functions:
                w = image.words(start, end)
                if w:
                    key = (image.tag, start)
                    self.words[key] = w
                    self.shapes[key] = shape(w)
                    keys.append(key)
            self.order[image.tag] = keys

    def resolve(self, tag, address):
        """Function key for a call target made from image `tag`."""
        if tag != "main" and (tag, address) in self.words:
            return tag, address
        if ("main", address) in self.words:
            return "main", address
        return None


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--file1", action="append", required=True)
    ap.add_argument("--file2", action="append", required=True)
    ap.add_argument("--out", required=True)
    args = ap.parse_args()
    one, two = Game(load_images(args.file1)), Game(load_images(args.file2))

    by1, by2 = collections.defaultdict(list), collections.defaultdict(list)
    for key, h in one.shapes.items():
        by1[h].append(key)
    for key, h in two.shapes.items():
        by2[h].append(key)

    match, method = {}, {}
    for h, keys in by1.items():
        if len(keys) == 1 and len(by2.get(h, ())) == 1 and keys[0][0] == by2[h][0][0]:
            match[keys[0]] = by2[h][0]
            method[keys[0]] = "exact"

    # Positional call-target propagation: identical shapes imply identical call order.
    for _ in range(8):
        votes = collections.defaultdict(collections.Counter)
        for a, b in match.items():
            if one.shapes[a] != two.shapes[b]:
                continue
            for t1, t2 in zip(call_targets(a[1], one.words[a]), call_targets(b[1], two.words[b])):
                k1, k2 = one.resolve(a[0], t1), two.resolve(b[0], t2)
                if k1 and k2 and k1[0] == k2[0]:
                    votes[k1][k2] += 1
        used = set(match.values())
        added = 0
        for k1, counter in votes.items():
            if k1 in match or len(counter) != 1:
                continue
            k2 = next(iter(counter))
            if k2 not in used and len(one.words[k1]) == len(two.words[k2]):
                match[k1], method[k1] = k2, "call"
                used.add(k2)
                added += 1
        if not added:
            break

    # Link-order runs between anchors with identical slot counts and similar sizes.
    used = set(match.values())
    for tag, order1 in one.order.items():
        order2 = two.order.get(tag, [])
        pos2 = {key: i for i, key in enumerate(order2)}
        anchors = [(-1, -1)] + [(i, pos2[match[a]]) for i, a in enumerate(order1) if a in match] + \
                  [(len(order1), len(order2))]
        for (i0, j0), (i1, j1) in zip(anchors, anchors[1:]):
            gap1, gap2 = order1[i0 + 1:i1], order2[j0 + 1:j1]
            if not gap1 or len(gap1) != len(gap2):
                continue
            for a, b in zip(gap1, gap2):
                n1, n2 = len(one.words[a]), len(two.words[b])
                if a not in match and b not in used and abs(n1 - n2) <= max(2, n1 // 10):
                    match[a], method[a] = b, "order"
                    used.add(b)

    # Data addresses from lui/low-half constants in identically shaped pairs.
    data_votes = collections.defaultdict(collections.Counter)
    for a, b in match.items():
        if one.shapes[a] != two.shapes[b]:
            continue
        c1, c2 = dict(constants(one.words[a])), dict(constants(two.words[b]))
        for i, v1 in c1.items():
            if i in c2:
                data_votes[(a[0], v1)][c2[i]] += 1
    data = collections.defaultdict(dict)
    for (tag, v1), counter in data_votes.items():
        (v2, n), = counter.most_common(1)
        if n == sum(counter.values()):
            data[tag]["0x%08X" % v1] = {"file2": "0x%08X" % v2, "votes": n}

    images = {}
    for tag in sorted(set(one.images) | set(two.images)):
        i1, i2 = one.images.get(tag), two.images.get(tag)
        keys = [k for k in match if k[0] == tag]
        images[tag] = {
            "file1Range": [hex(i1.low), hex(i1.high)] if i1 else None,
            "file2Range": [hex(i2.low), hex(i2.high)] if i2 else None,
            "file1Functions": len(one.order.get(tag, [])), "file2Functions": len(two.order.get(tag, [])),
            "matched": len(keys), "byMethod": dict(collections.Counter(method[k] for k in keys)),
            "functions": {"0x%08X" % k[1]: {"file2": "0x%08X" % match[k][1], "method": method[k],
                                             "size1": 4 * len(one.words[k]), "size2": 4 * len(two.words[match[k]])}
                          for k in sorted(keys)},
            "data": dict(sorted(data.get(tag, {}).items())),
        }
    with open(args.out, "w") as stream:
        json.dump({"format": 2, "images": images}, stream, indent=1)
    for tag, record in images.items():
        print("%-5s %5d/%5d matched %s data=%d" % (tag, record["matched"], record["file1Functions"],
                                                     record["byMethod"], len(record["data"])))


if __name__ == "__main__":
    main()
