#!/usr/bin/env python3
"""Extract SLUS-20765 code overlays (BIN/*.DAT) from a user-supplied ISO.

The game loads each overlay straight to its link address and, when the file starts with
the 16-bit word 0x0002 (the first control word of the stream: 14 literals, one copy, one
literal -- the fixed shape of the MWo3 header), decompresses it in place. Compressed stream (derived by comparing
BIN/0.DAT with the decompressed image in EE RAM; verify with --check):
  - a little-endian 16-bit control word, consumed MSB first, precedes every 16 items;
  - control bit 0: copy one literal halfword;
  - control bit 1: little-endian token T; copy (T >> 11) halfwords from (T & 0x7FF)
    halfwords back (overlapping copies allowed). If T >> 11 is 0, the count is the
    next little-endian halfword (it does not use a control bit). Distance 0 ends the stream.
Overlay image header ("MWo3"): 0x40 bytes; +4 id, +8 load base,
+0xC text size, +0x10 data size. Text/data sizes exclude the header.

Usage: overlay_extract.py <iso> <out_dir> [--check <eeram.bin>]
Outputs <out_dir>/<n>.bin (raw image) and <out_dir>/<n>.elf (the image wrapped as an EE
ELF: R+X segment [base, base+text), R+W segment for data) for Ghidra and ps2xRecomp, and
prints base/size. Game data stays local.
"""
import os
import struct
import sys

SECTOR = 2048


class Iso:
    def __init__(self, path):
        self.f = open(path, 'rb')

    def read(self, lsn, n):
        self.f.seek(lsn * SECTOR)
        return self.f.read(n)

    def listdir(self, lsn, size):
        data = self.read(lsn, size)
        i = 0
        while i < len(data):
            ln = data[i]
            if ln == 0:
                i = (i // SECTOR + 1) * SECTOR
                continue
            e = data[i:i + ln]
            name = e[33:33 + e[32]].decode('latin1')
            if name not in ('\x00', '\x01'):
                yield name.split(';')[0], struct.unpack_from('<I', e, 2)[0], struct.unpack_from('<I', e, 10)[0], e[25]
            i += ln

    def root(self):
        r = self.read(16, SECTOR)[156:190]
        return struct.unpack_from('<I', r, 2)[0], struct.unpack_from('<I', r, 10)[0]


def decompress(src, out_size=None):
    out = bytearray()
    p = 0
    n = len(src)
    while p + 2 <= n:
        ctrl = struct.unpack_from('<H', src, p)[0]
        p += 2
        for bit in range(15, -1, -1):
            if p + 2 > n or (out_size is not None and len(out) >= out_size):
                return bytes(out)
            if ctrl & (1 << bit):
                tok = struct.unpack_from('<H', src, p)[0]
                p += 2
                dist = (tok & 0x7FF) * 2
                count = (tok >> 11) * 2
                if count == 0:
                    count = struct.unpack_from('<H', src, p)[0] * 2
                    p += 2
                if dist == 0:
                    return bytes(out)  # end of stream
                if dist > len(out):
                    raise ValueError('bad back-reference at src 0x%x (dist %d, out %d)' % (p - 2, dist, len(out)))
                for _ in range(count):
                    out.append(out[-dist])
            else:
                out += src[p:p + 2]
                p += 2
    return bytes(out)


def wrap_elf(img, base, text):
    """Minimal ELF32 LE MIPS executable with two PT_LOAD segments (no section headers)."""
    ehsize, phentsize, phnum = 52, 32, 2
    data_off = ehsize + phentsize * phnum
    data_off = (data_off + 0xF) & ~0xF
    eh = struct.pack('<4sBBBB8xHHIIIIIHHHHHH', b'\x7fELF', 1, 1, 1, 0, 2, 8, 1, base, ehsize, 0,
                     0x20924000, ehsize, phentsize, phnum, 0, 0, 0)
    text = min(text, len(img))
    ph_text = struct.pack('<8I', 1, data_off, base, base, text, text, 5, 0x10)
    ph_data = struct.pack('<8I', 1, data_off + text, base + text, base + text, len(img) - text,
                          len(img) - text, 6, 0x10)
    hdr = eh + ph_text + ph_data
    return hdr + b'\0' * (data_off - len(hdr)) + img


def main():
    iso = Iso(sys.argv[1])
    out_dir = sys.argv[2]
    check = sys.argv[sys.argv.index('--check') + 1] if '--check' in sys.argv else None
    os.makedirs(out_dir, exist_ok=True)
    rlsn, rsize = iso.root()
    bin_dir = next((l, s) for n, l, s, fl in iso.listdir(rlsn, rsize) if n == 'BIN')
    for name, lsn, size, fl in sorted(iso.listdir(*bin_dir)):
        raw = iso.read(lsn, size)
        compressed = raw[:2] == b'\x02\x00'
        img = decompress(raw) if compressed else raw
        if img[:4] != b'MWo3':
            print('%-6s skipped (no MWo3 header)' % name)
            continue
        ident, base, text, data = struct.unpack_from('<4I', img, 4)
        stem = name.split('.')[0]
        open(os.path.join(out_dir, stem + '.bin'), 'wb').write(img)
        open(os.path.join(out_dir, stem + '.elf'), 'wb').write(wrap_elf(img, base, text + 0x40))
        print('%-6s id=%-2d base=0x%06x text=0x%05x data=0x%05x image=%d %s' %
              (name, ident, base, text, data, len(img), 'lz' if compressed else 'raw'))
        if check and base == 0x370000:
            ram = open(check, 'rb').read()[base:base + text]
            same = sum(1 for a, b in zip(ram, img[:text]) if a == b)
            print('   check vs EE RAM text: %d/%d bytes equal' % (same, text))


if __name__ == '__main__':
    main()
