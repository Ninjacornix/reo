"""Decode a GS input dump (REO_GIF_DUMP_AT, see tools/parallel_gs_backend/parallel_backend.cpp)
into drawn vertices with the register state that applies to each.

usage: gif_inspect.py gif_N.bin [--summary]

Each vertex: pixel x/y (XYOFFSET removed), z, RGBA, ST/Q or UV, PRIM, TEX0, ALPHA, FOGCOL use.
Only what tools/native_render needs: PACKED/REGLIST data and A+D register writes.
"""
import argparse, struct
from collections import Counter
from pathlib import Path

PRIM, RGBAQ, ST, UV, XYZF2, XYZ2, TEX0_1, TEX0_2, CLAMP_1, CLAMP_2, FOG = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA
XYZF3, XYZ3, AD, NOP = 0xC, 0xD, 0xE, 0xF
XYOFFSET_1, XYOFFSET_2, PRMODECONT, PRMODE = 0x18, 0x19, 0x1A, 0x1B
ALPHA_1, ALPHA_2, TEST_1, TEST_2, FOGCOL = 0x42, 0x43, 0x47, 0x48, 0x3D


def items(path):
    b = Path(path).read_bytes()
    at = 0
    while at < len(b):
        kind, addr, _, n, value = struct.unpack_from('<BBHIQ', b, at)
        at += 16
        yield kind, addr, value, b[at:at + n]
        at += n


class State:
    def __init__(self):
        self.r = {}
        self.rgbaq = (128, 128, 128, 128, 1.0)
        self.st = (0.0, 0.0)
        self.uv = (0, 0)
        self.vertices = []
        self.draw_index = 0

    def write(self, reg, value):
        self.r[reg] = value
        if reg == RGBAQ:
            q = struct.unpack('<f', struct.pack('<I', value >> 32))[0]
            self.rgbaq = (value & 255, (value >> 8) & 255, (value >> 16) & 255, (value >> 24) & 255, q)
        elif reg == ST:
            self.st = struct.unpack('<ff', struct.pack('<Q', value))
        elif reg == UV:
            self.uv = (value & 0x3FFF, (value >> 16) & 0x3FFF)
        elif reg in (XYZ2, XYZF2, XYZ3, XYZF3):
            fog = reg in (XYZF2, XYZF3)
            x, y = value & 0xFFFF, (value >> 16) & 0xFFFF
            z = (value >> 32) & (0xFFFFFF if fog else 0xFFFFFFFF)
            self.vertex(x, y, z, (value >> 56) if fog else None, kick=reg in (XYZ2, XYZF2))
        elif reg == PRIM:
            self.draw_index += 1

    def vertex(self, x, y, z, f, kick):
        prim = self.r.get(PRIM, 0)
        ctxt = (prim >> 9) & 1
        off = self.r.get(XYOFFSET_2 if ctxt else XYOFFSET_1, 0)
        ox, oy = (off & 0xFFFF) / 16.0, ((off >> 32) & 0xFFFF) / 16.0
        self.vertices.append({
            'x': x / 16.0 - ox, 'y': y / 16.0 - oy, 'z': z, 'fog': f, 'rgbaq': self.rgbaq, 'st': self.st,
            'uv': self.uv, 'prim': prim, 'tex0': self.r.get(TEX0_2 if ctxt else TEX0_1, 0),
            'alpha': self.r.get(ALPHA_2 if ctxt else ALPHA_1, 0), 'test': self.r.get(TEST_2 if ctxt else TEST_1, 0),
            'fogcol': self.r.get(FOGCOL, 0), 'draw': self.draw_index, 'kick': kick})


def run_gif(state, data):
    q = len(data) // 8
    words = struct.unpack('<%dQ' % q, data[:q * 8])
    i = 0
    while i + 2 <= len(words):
        lo, hi = words[i], words[i + 1]
        i += 2
        nloop, pre, prim_word = lo & 0x7FFF, (lo >> 46) & 1, (lo >> 47) & 0x7FF
        flg, nreg = (lo >> 58) & 3, ((lo >> 60) & 15) or 16
        if pre:
            state.write(PRIM, prim_word)
        regs = [(hi >> (4 * k)) & 15 for k in range(nreg)]
        if flg == 0:
            for _ in range(nloop):
                for reg in regs:
                    if i + 2 > len(words):
                        return
                    a, b = words[i], words[i + 1]
                    i += 2
                    if reg == AD:
                        state.write(b & 0xFF, a)
                    elif reg == RGBAQ:
                        state.rgbaq = (a & 255, (a >> 32) & 255, b & 255, (b >> 32) & 255, state.rgbaq[4])
                    elif reg == ST:
                        s, t = struct.unpack('<ff', struct.pack('<Q', a))
                        qv = struct.unpack('<f', struct.pack('<I', b & 0xFFFFFFFF))[0]
                        state.st = (s, t)
                        state.rgbaq = state.rgbaq[:4] + (qv,)
                    elif reg == UV:
                        state.uv = (a & 0x3FFF, (a >> 32) & 0x3FFF)
                    elif reg in (XYZF2, XYZF3):
                        x, y = a & 0xFFFF, (a >> 32) & 0xFFFF
                        z, f = (b >> 4) & 0xFFFFFF, (b >> 36) & 0xFF
                        disable = (b >> 47) & 1
                        state.vertex(x, y, z, f, kick=not disable and reg == XYZF2)
                    elif reg in (XYZ2, XYZ3):
                        x, y = a & 0xFFFF, (a >> 32) & 0xFFFF
                        disable = (b >> 47) & 1
                        state.vertex(x, y, b & 0xFFFFFFFF, None, kick=not disable and reg == XYZ2)
                    elif reg == PRIM:
                        state.write(PRIM, a & 0x7FF)
                    elif reg == FOG:
                        pass
                    elif reg != NOP:
                        state.write(reg, a)
        elif flg == 1:
            count = nloop * nreg
            for k in range(count):
                if i + k < len(words):
                    state.write(regs[k % nreg], words[i + k])
            i += count + (count & 1)
        else:
            i += nloop * 2


def decode(path):
    state = State()
    for kind, addr, value, data in items(path):
        if kind == 0:
            state.write(addr, value)
        elif kind in (1, 2, 3):
            run_gif(state, data)
    return state.vertices


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('dump', type=Path)
    a = ap.parse_args()
    v = decode(a.dump)
    print('vertices', len(v))
    print('prim types', Counter(x['prim'] & 7 for x in v).most_common())
    print('tex0 (tbp, psm, tw, th) top', Counter(((x['tex0'] & 0x3FFF), (x['tex0'] >> 20) & 63,
                                                  1 << ((x['tex0'] >> 26) & 15), 1 << ((x['tex0'] >> 30) & 15))
                                                 for x in v).most_common(8))
    print('alpha regs top', Counter(hex(x['alpha']) for x in v).most_common(6))
    print('rgba top', Counter(x['rgbaq'][:4] for x in v).most_common(8))


if __name__ == '__main__':
    main()
