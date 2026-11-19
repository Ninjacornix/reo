"""Walk captured VIF1 stream chunks (REO_VIF1_DUMP: vif1_NNNN.bin + vif1_buffers.jsonl) and list
the UNPACK uploads of each frame, to find per-object transform matrices for interpolation.

usage: vif1_unpacks.py CAPTURE_DIR [--frames N]

For each chunk (one frame's VIF1 transfer) it records every UNPACK as
(ordinal, VU qword address, format, element count, payload). Matrix candidates are V4-32
uploads of exactly 4 qwords whose 4th row is (0,0,0,1) or whose values are finite floats.
Across consecutive frames it pairs uploads by (ordinal among same-address uploads, address)
and reports how many pair up and how much they change. No game data is written.
"""
import argparse, json, math, struct
from collections import Counter, defaultdict
from pathlib import Path

ELEMENT_BITS = lambda vn, vl: (32 >> vl) * (vn + 1)  # bits per element


def walk(data, regs):
    """Yield (kind, info) for each VIF code in a stream chunk."""
    words = len(data) // 4
    i = 0
    cl, wl = 1, 1
    cycle = regs.get('cycle', 0x0101)
    cl, wl = cycle & 0xFF, (cycle >> 8) & 0xFF
    tops = regs.get('tops', 0)
    while i < words:
        code = struct.unpack_from('<I', data, i * 4)[0]
        i += 1
        cmd = (code >> 24) & 0x7F
        imm = code & 0xFFFF
        num = (code >> 16) & 0xFF
        if cmd == 0x01:
            cl, wl = imm & 0xFF, (imm >> 8) & 0xFF
        elif cmd == 0x20:
            i += 1
        elif cmd in (0x30, 0x31):
            i += 4
        elif cmd == 0x4A:
            i += (num or 256) * 2
        elif cmd in (0x50, 0x51):
            i += (imm or 65536) * 4
        elif cmd in (0x14, 0x15, 0x17):
            yield 'kick', {'cmd': cmd, 'addr': imm}
        elif cmd >= 0x60:
            vn, vl = (cmd >> 2) & 3, cmd & 3
            count = num or 256
            # With CL >= WL every element is transferred; with CL < WL only CL of every WL.
            transferred = count if (wl == 0 or cl >= wl) else (count // wl) * cl + min(count % wl, cl)
            bits = ELEMENT_BITS(vn, vl) * transferred
            nwords = (bits + 31) // 32
            payload = data[i * 4:(i + nwords) * 4]
            addr = imm & 0x3FF
            if imm & 0x8000:
                addr = (addr + tops) & 0x3FF
            yield 'unpack', {'vn': vn, 'vl': vl, 'addr': addr, 'num': count, 'usn': bool(imm & 0x4000),
                             'payload': payload}
            i += nwords
        # other codes (NOP, OFFSET, BASE, ITOP, STMOD, MSKPATH3, MARK, FLUSH*) carry no payload


def floats(payload):
    return struct.unpack('<%df' % (len(payload) // 4), payload[: len(payload) // 4 * 4])


def is_matrix(u):
    if u['vn'] != 3 or u['vl'] != 0 or u['num'] != 4 or len(u['payload']) != 64:
        return False
    f = floats(u['payload'])
    if not all(math.isfinite(x) and abs(x) < 1e7 for x in f):
        return False
    last = f[12:16]
    affine_w = abs(f[3]) < 1e-4 and abs(f[7]) < 1e-4 and abs(f[11]) < 1e-4 and abs(f[15] - 1) < 1e-4
    return affine_w or abs(last[3] - 1) < 1e-4


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('capture', type=Path)
    ap.add_argument('--frames', type=int, default=40)
    a = ap.parse_args()
    meta = {}
    for line in (a.capture / 'vif1_buffers.jsonl').read_text().splitlines():
        d = json.loads(line)
        meta[d['index']] = d
    frames = []
    for idx in sorted(meta)[: a.frames]:
        f = a.capture / ('vif1_%04u.bin' % idx)
        if not f.exists():
            continue
        data = f.read_bytes()
        unpacks, kicks = [], 0
        for kind, info in walk(data, meta[idx].get('before', {})):
            if kind == 'kick':
                kicks += 1
            else:
                unpacks.append(info)
        frames.append((idx, unpacks, kicks))
    print('frames', len(frames))
    for idx, unpacks, kicks in frames[:3]:
        formats = Counter((u['vn'], u['vl'], u['num'] if u['num'] <= 8 else '>8') for u in unpacks)
        print('frame', idx, 'unpacks', len(unpacks), 'kicks', kicks, 'matrices', sum(is_matrix(u) for u in unpacks),
              'top formats', formats.most_common(6))

    def keyed(unpacks):
        seen = defaultdict(int)
        out = {}
        for u in unpacks:
            if not is_matrix(u):
                continue
            k = (u['addr'], seen[u['addr']])
            seen[u['addr']] += 1
            out[k] = floats(u['payload'])
        return out

    stats = []
    for (ia, ua, _), (ib, ub, _) in zip(frames, frames[1:]):
        ka, kb = keyed(ua), keyed(ub)
        common = set(ka) & set(kb)
        changed = [max(abs(x - y) for x, y in zip(ka[k], kb[k])) for k in common]
        stats.append((ia, ib, len(ka), len(kb), len(common), sum(c > 1e-4 for c in changed),
                      max(changed) if changed else 0))
    print('pairs: frameA frameB matricesA matricesB paired changed maxdelta')
    for s in stats[:12]:
        print('  ', s[0], s[1], s[2], s[3], s[4], s[5], '%.3f' % s[6])


if __name__ == '__main__':
    main()
