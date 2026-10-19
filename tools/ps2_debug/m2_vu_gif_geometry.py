#!/usr/bin/env python3
"""Inspect complete exported VU GIF callback packets, without inventing GS state.

Usage: python m2_vu_gif_geometry.py EXPORT_DIR [--report report.json]
Optional --state-trace accepts JSONL actual GS register writes, in execution order:
  {"register":"0x18", "value":"0x80008000", "source":"actual capture ..."}
  {"before_packet":1, "register":"PRMODECONT", "value":1, "source":"..."}
Omitted before_packet means before packet 0. These writes must precede the named
manifest index, not the manifest's potentially unrelated guest packet counter.
State/vertex attributes carry across callback files in manifest order. A callback
export omits intervening PATH2/PATH3 writes: supply their actual trace when known.
Unknown inherited state stays unknown; no reset snapshot is synthesized.

ADC-eligible means a primitive assembly kick requests drawing, not that any pixel
survives scissor, depth, alpha, fog, or texture sampling. Raw encoded Q is retained,
including zero/NaN; emulator Q normalization is deliberately not applied. PACKED
temporary Q starts at 1 for each nonempty tag and RGBA latches it (GIF semantics).
PRIM writes reset history to match the production assembler being diagnosed.
References: PCS X2 GS/GSRegs.h and GS/GSState.cpp (v2.2.0), particularly Transfer,
GIFPackedRegHandlerSTQ/RGBA, ApplyPRIM, and VertexKick.
https://github.com/PCSX2/pcsx2/blob/v2.2.0/pcsx2/GS/GSState.cpp
"""

import argparse
from collections import Counter
import json
import math
from pathlib import Path
import struct
import sys


REGS = {
    0x00: "PRIM", 0x01: "RGBAQ", 0x02: "ST", 0x03: "UV",
    0x04: "XYZF2", 0x05: "XYZ2", 0x06: "TEX0_1", 0x07: "TEX0_2",
    0x08: "CLAMP_1", 0x09: "CLAMP_2", 0x0A: "FOG",
    0x0C: "XYZF3", 0x0D: "XYZ3", 0x14: "TEX1_1", 0x15: "TEX1_2",
    0x18: "XYOFFSET_1", 0x19: "XYOFFSET_2", 0x1A: "PRMODECONT",
    0x1B: "PRMODE", 0x1C: "TEXCLUT", 0x34: "TEXFLUSH",
    0x35: "MIPTBP1_1", 0x36: "MIPTBP1_2", 0x37: "MIPTBP2_1",
    0x38: "MIPTBP2_2", 0x3B: "TEXA", 0x3D: "FOGCOL",
    0x40: "SCISSOR_1", 0x41: "SCISSOR_2", 0x42: "ALPHA_1",
    0x43: "ALPHA_2", 0x44: "DIMX", 0x45: "DTHE", 0x46: "COLCLAMP",
    0x47: "TEST_1", 0x48: "TEST_2", 0x49: "PABE", 0x4A: "FBA_1",
    0x4B: "FBA_2", 0x4C: "FRAME_1", 0x4D: "FRAME_2",
    0x4E: "ZBUF_1", 0x4F: "ZBUF_2",
}
NAMES = {name: reg for reg, name in REGS.items()}
CONTEXT_KEYS = ("XYOFFSET", "SCISSOR", "TEST", "ZBUF", "FRAME", "TEX0",
                "TEX1", "CLAMP", "ALPHA", "FBA")
PRIM_NAMES = ("point", "line", "line_strip", "triangle", "triangle_strip",
              "triangle_fan", "sprite", "reserved")


def number(value):
    return int(value, 0) if isinstance(value, str) else int(value)


def f32(bits):
    return struct.unpack("<f", struct.pack("<I", bits & 0xFFFFFFFF))[0]


def safe_float(value):
    if isinstance(value, float) and not math.isfinite(value):
        return "nan" if math.isnan(value) else ("+inf" if value > 0 else "-inf")
    return value


def fnv(data):
    value = 0xCBF29CE484222325
    for byte in data:
        value = ((value ^ byte) * 0x100000001B3) & 0xFFFFFFFFFFFFFFFF
    return f"{value:016x}"


def decode_state(name, v):
    def bits(shift, mask):
        return (v >> shift) & mask
    if name in ("PRIM", "PRMODE"):
        result = {key: bits(i, 1) for key, i in
                  (("iip", 3), ("tme", 4), ("fge", 5), ("abe", 6),
                   ("aa1", 7), ("fst", 8), ("ctxt", 9), ("fix", 10))}
        if name == "PRIM":
            result.update(type=bits(0, 7), type_name=PRIM_NAMES[bits(0, 7)])
        return result
    base = name.rsplit("_", 1)[0]
    if base == "TEST":
        return {"ate": bits(0, 1), "atst": bits(1, 7), "aref": bits(4, 255),
                "afail": bits(12, 3), "date": bits(14, 1), "datm": bits(15, 1),
                "zte": bits(16, 1), "ztst": bits(17, 3)}
    if base == "FRAME":
        return {"fbp": bits(0, 0x1FF), "fbw": bits(16, 63),
                "psm": bits(24, 63), "fbmsk": bits(32, 0xFFFFFFFF)}
    if base == "ZBUF":
        return {"zbp": bits(0, 0x1FF), "psm": bits(24, 15), "zmsk": bits(32, 1)}
    if base == "XYOFFSET":
        return {"ofx": bits(0, 0xFFFF), "ofy": bits(32, 0xFFFF)}
    if base == "SCISSOR":
        return {"x0": bits(0, 0x7FF), "x1": bits(16, 0x7FF),
                "y0": bits(32, 0x7FF), "y1": bits(48, 0x7FF)}
    if base == "TEX0":
        return {"tbp0": bits(0, 0x3FFF), "tbw": bits(14, 63), "psm": bits(20, 63),
                "tw": bits(26, 15), "th": bits(30, 15), "tcc": bits(34, 1),
                "tfx": bits(35, 3), "cbp": bits(37, 0x3FFF), "cpsm": bits(51, 15),
                "csm": bits(55, 1), "csa": bits(56, 31), "cld": bits(61, 7)}
    if base == "TEX1":
        return {"lcm": bits(0, 1), "mxl": bits(2, 7), "mmag": bits(5, 1),
                "mmin": bits(6, 7), "mtba": bits(9, 1), "l": bits(19, 3),
                "k_raw": bits(32, 0xFFF)}
    if base == "CLAMP":
        return {"wms": bits(0, 3), "wmt": bits(2, 3), "minu": bits(4, 0x3FF),
                "maxu": bits(14, 0x3FF), "minv": bits(24, 0x3FF), "maxv": bits(34, 0x3FF)}
    if name == "TEXCLUT":
        return {"cbw": bits(0, 63), "cou": bits(6, 63), "cov": bits(12, 0x3FF)}
    if name == "PRMODECONT":
        return {"ac": bits(0, 1)}
    return None


class Ranges:
    def __init__(self):
        self.values = {}

    def add(self, name, value):
        s = self.values.setdefault(name, {"known": 0, "unknown": 0,
                                         "nonfinite": 0, "zero": 0, "negative": 0,
                                         "min": None, "max": None})
        if value is None:
            s["unknown"] += 1
        elif isinstance(value, float) and not math.isfinite(value):
            s["nonfinite"] += 1
        else:
            s["known"] += 1
            s["zero"] += value == 0
            s["negative"] += value < 0
            s["min"] = value if s["min"] is None else min(value, s["min"])
            s["max"] = value if s["max"] is None else max(value, s["max"])


class Decoder:
    def __init__(self, limit):
        self.limit = limit
        self.regs = {}
        self.attr = {k: None for k in ("s", "t", "q", "u", "v", "fog", "rgba")}
        self.temp_q = None
        self.history = []
        self.counts = Counter()
        self.all_ranges = Ranges()
        self.eligible_ranges = Ranges()
        self.samples = []
        self.writes = Counter()
        self.unknown_active = Counter()

    def state(self):
        prim = self.regs.get("PRIM")
        ac = self.regs.get("PRMODECONT")
        active = None
        if ac is not None:
            source = prim if ac["decoded"]["ac"] else self.regs.get("PRMODE")
            if source is not None:
                active = dict(source["decoded"])
                active["type"] = prim["decoded"]["type"] if prim else None
        ctxt = active.get("ctxt") if active else None
        context = {key: self.regs.get(f"{key}_{ctxt + 1}") if ctxt is not None else None
                   for key in CONTEXT_KEYS}
        return {"prim": prim, "prmodecont": ac, "prmode": self.regs.get("PRMODE"),
                "active_primitive": active, "context": context,
                "globals": {k: self.regs.get(k) for k in ("TEXA", "TEXCLUT", "FOGCOL")}}

    def register(self, reg, value, source):
        name = REGS.get(reg, f"REG_{reg:02X}")
        self.writes[name] += 1
        self.regs[name] = {"raw": f"0x{value:016x}", "decoded": decode_state(name, value),
                           "source": source}
        if reg == 0:
            self.history.clear()
        elif reg == 1:
            self.attr["rgba"] = [(value >> shift) & 255 for shift in (0, 8, 16, 24)]
            self.attr["q"] = f32(value >> 32)
        elif reg == 2:
            self.attr.update(s=f32(value), t=f32(value >> 32))
        elif reg == 3:
            self.attr.update(u=value & 0x3FFF, v=(value >> 16) & 0x3FFF)
        elif reg == 0x0A:
            self.attr["fog"] = (value >> 56) & 255
        elif reg in (4, 5, 12, 13):
            fog = (value >> 56) & 255 if reg in (4, 12) else self.attr["fog"]
            z = (value >> 32) & (0xFFFFFF if reg in (4, 12) else 0xFFFFFFFF)
            self.vertex(value & 0xFFFF, (value >> 16) & 0xFFFF, z, fog,
                        reg in (12, 13), source)

    def packed(self, reg, lo, hi, source):
        if reg == 0:
            self.register(0, lo & 0x7FF, source)
        elif reg == 1:
            self.attr["rgba"] = [lo & 255, (lo >> 32) & 255, hi & 255, (hi >> 32) & 255]
            self.attr["q"] = self.temp_q
        elif reg == 2:
            self.attr.update(s=f32(lo), t=f32(lo >> 32))
            self.temp_q = f32(hi)
        elif reg == 3:
            self.attr.update(u=lo & 0x3FFF, v=(lo >> 32) & 0x3FFF)
        elif reg in (4, 5, 12, 13):
            z = (hi >> 4) & 0xFFFFFF if reg in (4, 12) else hi & 0xFFFFFFFF
            fog = (hi >> 36) & 255 if reg in (4, 12) else self.attr["fog"]
            self.vertex(lo & 0xFFFF, (lo >> 32) & 0xFFFF, z, fog,
                        reg in (12, 13) or bool((hi >> 47) & 1), source)
        elif reg == 10:
            self.attr["fog"] = (hi >> 36) & 255
        elif reg == 14:
            self.register(hi & 255, lo, source)
        elif reg == 15:
            pass
        elif reg in (6, 7, 8, 9):
            self.register(reg, lo, source)
        else:
            self.counts["unsupported_packed_registers"] += 1

    def measure(self, v, ranges):
        for key in ("z", "q", "s", "t", "u", "v", "fog", "x_raw", "y_raw"):
            ranges.add(key, v[key])
        rgba = v["rgba"]
        ranges.add("rgb_all_zero", None if rgba is None else int(not any(rgba[:3])))
        for channel, index in (("red", 0), ("green", 1), ("blue", 2), ("alpha", 3)):
            ranges.add(channel, None if rgba is None else rgba[index])

    def vertex(self, x, y, z, fog, adc, source):
        self.counts["vertices"] += 1
        self.counts["adc_vertices" if adc else "drawing_vertices"] += 1
        v = dict(self.attr, x_raw=x, y_raw=y, z=z, fog=fog, adc=adc, source=source)
        self.measure(v, self.all_ranges)
        if v["rgba"] is None:
            self.counts["vertices_unknown_rgb"] += 1
        elif not any(v["rgba"][:3]):
            self.counts["vertices_black_rgb"] += 1
        prim = self.regs.get("PRIM")
        if prim is None:
            self.counts["vertices_unknown_primitive"] += 1
            self.history.clear()
            return
        typ = prim["decoded"]["type"]
        if typ == 7:
            self.counts["vertices_reserved_primitive"] += 1
            self.history.clear()
            return
        self.history.append(v)
        needed = (1, 2, 2, 3, 3, 3, 2)[typ]
        if len(self.history) < needed:
            return
        self.counts[f"assembled_{PRIM_NAMES[typ]}"] += 1
        if typ in (3, 4, 5):
            self.triangle(self.history[:3], adc)
        elif not adc:
            self.counts["adc_eligible_nontriangle_primitives"] += 1
        else:
            self.counts["adc_suppressed_nontriangle_primitives"] += 1
        if typ in (0, 1, 3, 6):
            self.history.clear()
        elif typ == 2:
            self.history = self.history[-1:]
        elif typ == 4:
            self.history = self.history[-2:]
        elif typ == 5:
            self.history = [self.history[0], self.history[-1]]

    def triangle(self, vertices, adc):
        self.counts["triangles"] += 1
        a, b, c = vertices
        area = ((b["x_raw"] - a["x_raw"]) * (c["y_raw"] - a["y_raw"])
                - (b["y_raw"] - a["y_raw"]) * (c["x_raw"] - a["x_raw"]))
        degenerate = area == 0
        self.counts["adc_suppressed_triangles" if adc else "adc_eligible_triangles"] += 1
        if degenerate:
            self.counts["degenerate_triangles"] += 1
        state = self.state()
        screen = None
        clip = None
        if not adc:
            for vertex in vertices:
                self.measure(vertex, self.eligible_ranges)
                if vertex["rgba"] is None:
                    self.counts["adc_eligible_triangle_vertex_instances_unknown_rgb"] += 1
                elif not any(vertex["rgba"][:3]):
                    self.counts["adc_eligible_triangle_vertex_instances_black_rgb"] += 1
        if not adc and not degenerate:
            self.counts["adc_eligible_nondegenerate_triangles"] += 1
            for key, value in state["context"].items():
                if value is None:
                    self.unknown_active[key] += 1
            if state["active_primitive"] is None:
                self.unknown_active["active_primitive"] += 1
            offset = state["context"]["XYOFFSET"]
            scissor = state["context"]["SCISSOR"]
            if offset:
                of = offset["decoded"]
                xs = [(v["x_raw"] - of["ofx"]) / 16 for v in vertices]
                ys = [(v["y_raw"] - of["ofy"]) / 16 for v in vertices]
                screen = [min(xs), min(ys), max(xs), max(ys)]
                if scissor:
                    sc = scissor["decoded"]
                    # Conservative candidate pixel bounds, not a coverage count.
                    x0, y0 = max(math.floor(screen[0]), sc["x0"]), max(math.floor(screen[1]), sc["y0"])
                    x1, y1 = min(math.ceil(screen[2]), sc["x1"] + 1), min(math.ceil(screen[3]), sc["y1"] + 1)
                    clip = max(0, x1 - x0) * max(0, y1 - y0)
                    self.counts["scissor_bbox_candidate_pixels"] += clip
                    self.counts["triangles_with_proven_screen_scissor"] += 1
                    if clip == 0:
                        self.counts["scissor_bbox_outside_triangles"] += 1
        if len(self.samples) < self.limit:
            self.samples.append({"adc_suppressed": adc, "degenerate": degenerate,
                                 "signed_area_fixed_squared": area,
                                 "vertices": [{k: safe_float(val) for k, val in v.items()} for v in vertices],
                                 "screen_bbox": screen, "scissor_bbox_candidate_pixels": clip,
                                 "gs_state": state})

    def packet(self, data, packet_index):
        offset = 0
        tags = []
        eop = False
        while offset < len(data):
            start = offset
            if len(data) - offset < 16:
                raise ValueError(f"truncated GIF tag at {offset}")
            lo, hi = struct.unpack_from("<QQ", data, offset)
            offset += 16
            loops, last = lo & 0x7FFF, bool((lo >> 15) & 1)
            pre, prim = bool((lo >> 46) & 1), (lo >> 47) & 0x7FF
            fmt, nreg = (lo >> 58) & 3, (lo >> 60) & 15 or 16
            regs = [(hi >> (4 * i)) & 15 for i in range(nreg)]
            count = loops * nreg
            length = count * 16 if fmt == 0 else ((count + 1) // 2) * 16 if fmt == 1 else loops * 16
            if length > len(data) - offset:
                raise ValueError(f"truncated tag payload at {start}: need {length}, have {len(data) - offset}")
            tag = {"offset": start, "nloop": loops, "eop": last, "pre": pre,
                   "prim": f"0x{prim:x}", "format": ("PACKED", "REGLIST", "IMAGE", "IMAGE2")[fmt],
                   "registers": regs, "payload_bytes": length}
            tags.append(tag)
            if loops:
                self.temp_q = 1.0
                if pre and fmt == 0:
                    self.register(0, prim, {"packet_index": packet_index, "byte_offset": start, "kind": "PRE"})
            if fmt in (0, 1):
                for i in range(count):
                    pos = offset + i * (16 if fmt == 0 else 8)
                    source = {"packet_index": packet_index, "byte_offset": pos,
                              "kind": "PACKED" if fmt == 0 else "REGLIST"}
                    if fmt == 0:
                        a, b = struct.unpack_from("<QQ", data, pos)
                        self.packed(regs[i % nreg], a, b, source)
                    elif regs[i % nreg] != 15:
                        reg = regs[i % nreg]
                        if reg == 14:
                            self.counts["unsupported_reglist_ad"] += 1
                        elif reg == 11:
                            self.counts["unsupported_reglist_registers"] += 1
                        else:
                            self.register(reg, struct.unpack_from("<Q", data, pos)[0], source)
            else:
                self.counts["image_payload_bytes"] += length
            offset += length
            if last:
                eop = True
                if offset != len(data):
                    raise ValueError(f"{len(data) - offset} trailing bytes after EOP at {start}")
                break
        return {"tags": tags, "computed_complete_eop": eop, "consumed_bytes": offset}


def json_lines(path):
    for line_no, line in enumerate(path.read_text(encoding="utf-8-sig").splitlines(), 1):
        if line.strip():
            try:
                yield json.loads(line)
            except ValueError as error:
                raise ValueError(f"{path}:{line_no}: {error}") from error


def analyze(args):
    directory = args.directory.resolve()
    manifest = args.manifest or directory / "vu_gif_packets.jsonl"
    rows = list(json_lines(manifest))
    if len(rows) > args.packet_limit:
        raise ValueError(f"manifest exceeds --packet-limit {args.packet_limit}; no partial report")
    decoder = Decoder(args.sample_limit)
    trace = {}
    if args.state_trace:
        for write in json_lines(args.state_trace):
            index = number(write.get("before_packet", 0))
            if not 0 <= index < len(rows):
                raise ValueError("state trace before_packet outside manifest")
            if not write.get("source"):
                raise ValueError("state trace writes require explicit source provenance")
            trace.setdefault(index, []).append(write)
    packets, total = [], 0
    for index, row in enumerate(rows):
        for write in trace.get(index, []):
            reg = write["register"]
            decoder.register(NAMES[reg.upper()] if isinstance(reg, str) and reg.upper() in NAMES else number(reg),
                             number(write["value"]), {"state_trace": str(args.state_trace), "source": write["source"],
                                                       "before_packet": index})
        path = (directory / row["file"]).resolve()
        if not path.is_relative_to(directory):
            raise ValueError("manifest file escapes export directory")
        size = path.stat().st_size
        total += size
        if total > args.byte_limit:
            raise ValueError(f"export exceeds --byte-limit {args.byte_limit}; no partial report")
        data = path.read_bytes()
        if row.get("bytes") != len(data):
            raise ValueError(f"{path.name}: manifest byte count differs from actual")
        digest = fnv(data)
        if row.get("fnv") != digest:
            raise ValueError(f"{path.name}: manifest FNV differs from actual {digest}")
        before = decoder.counts.copy()
        parsed = decoder.packet(data, index)
        if row.get("complete_eop") != parsed["computed_complete_eop"]:
            raise ValueError(f"{path.name}: EOP result differs from manifest")
        packets.append({"manifest_index": index, "manifest": row, "actual_fnv": digest,
                        **parsed, "geometry_counts": dict(decoder.counts - before)})
    return {"tool": "m2_vu_gif_geometry", "directory": str(directory), "manifest": str(manifest),
            "bytes": total, "packet_count": len(packets), "packets": packets,
            "counts": dict(decoder.counts), "all_vertex_ranges": decoder.all_ranges.values,
            "adc_eligible_triangle_vertex_ranges": decoder.eligible_ranges.values,
            "unknown_state_for_adc_eligible_nondegenerate_triangles": dict(decoder.unknown_active),
            "register_write_counts": dict(decoder.writes), "final_known_registers": decoder.regs,
            "final_observed_state": decoder.state(),
            "triangle_samples": decoder.samples, "triangle_sample_limit": args.sample_limit,
            "semantic_model": {"geometry_history": "Production GS assembler: each PRIM write resets history; ADC consumes list/strip/fan history.",
                               "packed_q": "Wire values with hardware temporary-Q/tag/RGBA latch semantics, without emulator zero/NaN normalization.",
                               "production_q_difference": "Current production packed STQ writes m_curQ immediately and normalizes zero to1; packed RGBA does not separately latch Q. Nonstandard STQ/RGBA order may therefore differ from this wire analysis.",
                               "context_selection": "PRMODECONT and its selected PRIM/PRMODE must be observed; otherwise active context is unknown even when raw PRIM.CTXT is known."},
            "limitations": ["Callback order is manifest order; omitted PATH2/PATH3 writes are unknown unless supplied in state trace.",
                            "Initial attributes/context are unknown; known writes persist across packets.",
                            "Raw Q is not normalized by an emulator; packed temporary Q follows GIF tag/RGBA semantics.",
                            "ADC-eligible geometry is not proven visible. No texture, depth, alpha or fog evaluation.",
                            "Scissor candidate areas are conservative bounding boxes, not rasterized pixels.",
                            "Clipped/ADC-suppressed black vertex colors do not establish a visible black-polygon cause."]}


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("directory", type=Path)
    parser.add_argument("--manifest", type=Path)
    parser.add_argument("--state-trace", type=Path)
    parser.add_argument("--report", type=Path)
    parser.add_argument("--sample-limit", type=int, default=24)
    parser.add_argument("--packet-limit", type=int, default=512)
    parser.add_argument("--byte-limit", type=int, default=64 * 1024 * 1024)
    args = parser.parse_args()
    if not 0 <= args.sample_limit <= 256 or not 1 <= args.packet_limit <= 65536 or args.byte_limit <= 0:
        parser.error("invalid bounded report limits")
    try:
        report = analyze(args)
        rendered = json.dumps(report, indent=2, allow_nan=False) + "\n"
        if args.report:
            # Evidence is immutable: never silently overwrite a prior report.
            with args.report.open("x", encoding="utf-8") as output:
                output.write(rendered)
            print(json.dumps({"report": str(args.report), "packet_count": report["packet_count"],
                              "bytes": report["bytes"], "counts": report["counts"]}, indent=2))
        else:
            sys.stdout.write(rendered)
    except (ValueError, OSError, KeyError, TypeError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 2
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
