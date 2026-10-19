"""Classify complete captured DIRECT payloads and GIF IMAGE continuation.

This requires an independently classified, nonfragmented VIF stream. It follows
command lengths rather than interpreting arbitrary texture bytes as VIFcodes.
"""
import argparse
import json
import struct
from pathlib import Path
from analyze import analyze


def inspect(directory):
    classified = analyze(directory, include_unfinished=True)
    if not classified["complete_contiguous"] or classified["fragmented_commands"]:
        raise ValueError("complete unfragmented input required")
    if classified["remaining_payload"] or classified["remaining_command_bytes"]:
        raise ValueError("incomplete final command")
    first_record = json.loads((directory / "vif1_buffers.jsonl").read_text().splitlines()[0])
    cycle = first_record["before"]["cycle"]
    gif = bytearray()
    gif_remaining = 0
    gif_kind = None
    image_crossings = []
    pending_crossing = None
    direct_count = 0
    tags = 0
    for index in range(classified["buffers"]):
        data = (directory / f"vif1_{index:04d}.bin").read_bytes()
        pos = 0
        while pos < len(data):
            offset = pos
            word, = struct.unpack_from("<I", data, pos)
            pos += 4
            op, num, imm = (word >> 24) & 127, (word >> 16) & 255, word & 65535
            size = 0
            if op == 1:
                cycle = imm
            elif op == 32:
                size = 4
            elif op in (48, 49):
                size = 16
            elif op == 74:
                size = (num or 256) * 8
            elif op in (80, 81):
                size = (imm or 65536) * 16
            elif op & 0x60 == 0x60:
                vn, vl = (op >> 2) & 3, op & 3
                vector_size = 2 if vn == 3 and vl == 3 else (vn + 1) * (4 if vl == 0 else 2 if vl in (1, 3) else 1)
                cl, wl = cycle & 255, (cycle >> 8) & 255 or 256
                writes = num or 256
                sources = writes if cl >= wl else (writes // wl) * cl + min(writes % wl, cl)
                size = (sources * vector_size + 3) & ~3
            if pos + size > len(data):
                raise ValueError(f"fragment at buffer {index} offset {offset}")
            if op in (80, 81):
                direct_count += 1
                if pending_crossing is not None:
                    pending_crossing["next_direct"] = {"buffer": index, "offset": offset, "qwc": size // 16}
                    image_crossings.append(pending_crossing)
                    pending_crossing = None
                gif.extend(data[pos:pos + size])
                while True:
                    if gif_remaining:
                        consumed = min(gif_remaining, len(gif))
                        del gif[:consumed]
                        gif_remaining -= consumed
                        if gif_remaining:
                            break
                    if len(gif) < 16:
                        break
                    tag, = struct.unpack_from("<Q", gif)
                    del gif[:16]
                    nloop, flg, nreg = tag & 32767, (tag >> 58) & 3, (tag >> 60) & 15 or 16
                    tags += 1
                    gif_kind = flg
                    gif_remaining = nloop * nreg * 16 if flg == 0 else ((nloop * nreg + 1) // 2) * 16 if flg == 1 else nloop * 16
                if gif_remaining and gif_kind in (2, 3):
                    pending_crossing = {"direct": {"buffer": index, "offset": offset, "qwc": size // 16},
                        "image_qwc_remaining": gif_remaining // 16, "intervening_vifcodes": []}
            elif pending_crossing is not None:
                if len(pending_crossing["intervening_vifcodes"]) < 16:
                    pending_crossing["intervening_vifcodes"].append(f"{word:08x}")
            pos += size
    return {"directory": str(directory), "direct_commands": direct_count, "gif_tags": tags,
        "image_continuation_pairs": len(image_crossings), "examples": image_crossings[:16],
        "final_gif_payload_bytes": gif_remaining, "final_gif_header_bytes": len(gif),
        "limitation": "Classifies complete captured PATH2 bytes; does not execute GS or prove pixels."}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("directory", type=Path)
    parser.add_argument("--report", type=Path)
    args = parser.parse_args()
    result = inspect(args.directory)
    encoded = json.dumps(result, indent=2)
    if args.report:
        args.report.write_text(encoded + "\n")
    print(encoded)
