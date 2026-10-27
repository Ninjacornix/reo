#!/usr/bin/env python3
"""Report unmapped overlay bytes and incoming references; never edit maps.

Usage: python tools/file2_port/scan_overlay_gaps.py --images game_data_file2/ovl \
    --maps recomp/config/file2/overlay_maps --out build-ninja/file2-overlay-gaps.json

Inputs are raw MWo3 <number>.bin images from overlay_extract.py. References
are evidence for review, not automatic function boundaries: data pointers can
be jump-table labels and nonzero gaps can be embedded data. Only mapped,
aligned instructions contribute direct j/jal references. Pointer candidates
come from the overlay data region. Cross-overlay/main references, computed
addresses are not covered. Interior references are reported separately: they
may be ordinary jump-table labels, not missing functions. Never split them
without checking the instructions and callers.
"""
import argparse
import bisect
import csv
import hashlib
import json
from pathlib import Path
import struct


def scan(raw, rows):
    if len(raw) < 64 or raw[:4] != b"MWo3":
        raise ValueError("Expected a raw MWo3 overlay")
    ident, base, text_size, data_size = struct.unpack_from("<4I", raw, 4)
    text_end = base + 64 + text_size
    data_end = text_end + data_size
    if base % 4 or text_size % 4 or data_end - base > len(raw) or text_size < 64:
        raise ValueError("Invalid overlay dimensions")
    # Match generate_game.py's exclusion of the header/entry metadata.
    ranges = sorted((int(r["start"], 16), int(r["end"], 16)) for r in rows
                    if int(r["start"], 16) >= base + 0x80
                    and int(r["start"], 16) % 4 == 0)
    merged = []
    for start, end in ranges:
        if end <= start or start >= text_end or end > text_end:
            raise ValueError(f"Mapped range outside text: {start:#x}..{end:#x}")
        if merged and start <= merged[-1][1]:
            merged[-1] = (merged[-1][0], max(end, merged[-1][1]))
        else:
            merged.append((start, end))
    gaps = []
    cursor = base + 0x80
    for start, end in [*merged, (text_end, text_end)]:
        if start > cursor and any(raw[cursor - base:start - base]):
            gaps.append({"start": cursor, "end": start, "references": []})
        cursor = end
    starts = [g["start"] for g in gaps]
    entries = {start for start, _ in ranges}
    range_starts = [start for start, _ in merged]
    mapped_starts = [start for start, _ in ranges]
    interior = {}

    def reference(source, target, kind):
        index = bisect.bisect_right(starts, target) - 1
        if index >= 0 and target < gaps[index]["end"]:
            gaps[index]["references"].append(
                {"source": source, "target": target, "kind": kind})
        if target in entries:
            return
        owner = bisect.bisect_right(range_starts, target) - 1
        if owner >= 0 and target < merged[owner][1]:
            mapped = bisect.bisect_right(mapped_starts, target) - 1
            while ranges[mapped][1] <= target:
                mapped -= 1  # Handle overlapping input maps, too.
            containing = ranges[mapped]
            # Same-range jumps are already handled by generated local labels.
            if kind == "j" and containing[0] <= source < containing[1]:
                return
            item = interior.setdefault(target, {"target": target,
                "containing_range": list(containing), "references": [],
                "return_only": target + 8 <= text_end and
                    raw[target - base:target - base + 8] == b"\x08\x00\xe0\x03\0\0\0\0"})
            item["references"].append({"source": source, "kind": kind})

    for start, end in merged:
        for pc in range((start + 3) & ~3, end - 3, 4):
            word = struct.unpack_from("<I", raw, pc - base)[0]
            if word >> 26 in (2, 3):
                target = ((pc + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)
                reference(pc, target, "jal" if word >> 26 == 3 else "j")
    for pc in range(text_end, data_end - 3, 4):
        word = struct.unpack_from("<I", raw, pc - base)[0]
        if word % 4 == 0:
            reference(pc, word, "data-pointer")
    return {"id": ident, "base": base, "text_end": text_end,
            "image_sha256": hashlib.sha256(raw).hexdigest(),
            "nonzero_gaps": gaps,
            "interior_references": [interior[k] for k in sorted(interior)]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--images", type=Path, required=True)
    parser.add_argument("--maps", type=Path, required=True)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    reports = {}
    maps = sorted(args.maps.glob("ovl*.csv"))
    if not maps:
        parser.error("No overlay maps found")
    for mapping in maps:
        image = args.images / (mapping.stem.removeprefix("ovl") + ".bin")
        with mapping.open(newline="") as source:
            report = scan(image.read_bytes(), list(csv.DictReader(source)))
        report["map_sha256"] = hashlib.sha256(mapping.read_bytes()).hexdigest()
        reports[mapping.stem] = report
        gaps = report["nonzero_gaps"]
        targets = {r["target"] for g in gaps for r in g["references"]}
        print(f"{mapping.stem}: {len(gaps)} nonzero gaps, {len(targets)} referenced targets, "
              f"{len(report['interior_references'])} interior targets")
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(reports, indent=2) + "\n")


if __name__ == "__main__":
    main()
