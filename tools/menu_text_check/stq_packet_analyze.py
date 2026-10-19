"""Inspect a known original VU staging address for packed STQ/RGBA/XYZF2.

The address must come from trace review. This does not search payload words for
tags, execute the microprogram, or prove that a snapshot is a visible primitive.
"""
import argparse
import json
import math
import struct
from pathlib import Path


def inspect(directory, address):
    rows = []
    for file in sorted(directory.glob("vu1-run-*.data.bin")):
        data = file.read_bytes()
        if address + 16 > len(data):
            continue
        lo, hi = struct.unpack_from("<QQ", data, address)
        nloop, nreg, flg = lo & 32767, (lo >> 60) & 15 or 16, (lo >> 58) & 3
        if flg != 0 or nreg != 3 or hi != 0x412 or not 1 <= nloop <= 256:
            continue
        end = address + 16 + nloop * 48
        if end > len(data):
            continue
        q_values, visible_q = [], []
        for index in range(nloop):
            offset = address + 16 + index * 48
            s, t, q = struct.unpack_from("<fff", data, offset)
            x, y, z, flags = struct.unpack_from("<IIII", data, offset + 32)
            if not all(math.isfinite(value) for value in (s, t, q)):
                continue
            q_values.append(q)
            if not flags & (1 << 15):
                visible_q.append(q)
        if not q_values:
            continue
        packet = data[address:end]
        hash_value = 14695981039346656037
        for byte in packet:
            hash_value = ((hash_value ^ byte) * 1099511628211) & ((1 << 64) - 1)
        rows.append({"file": file.name, "address": address, "packet_bytes": len(packet),
            "packet_fnv1a64": f"{hash_value:016x}", "tag": f"{lo:016x}",
            "vertices": nloop, "q_range": [min(q_values), max(q_values)],
            "distinct_q": len(set(q_values)), "adc_false_vertices": len(visible_q),
            "adc_false_q": sorted(set(visible_q))})
    return {"directory": str(directory), "address": address, "packets": rows,
        "limitation": "Input VU snapshots of a known staging address, not final GS replay. ADCfalse counts do not establish visible triangles."}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("directory", type=Path)
    parser.add_argument("--address", type=lambda value: int(value, 0), required=True)
    parser.add_argument("--report", type=Path)
    args = parser.parse_args()
    result = inspect(args.directory, args.address)
    encoded = json.dumps(result, indent=2)
    if args.report:
        args.report.write_text(encoded + "\n")
    print(f"inspected={len(result['packets'])} varying_q={sum(row['distinct_q'] > 1 for row in result['packets'])}")
