#!/usr/bin/env python3
"""List eleven hash-bound copied-data candidates and connected clear envelopes.

No execution/emulation: decode explicit word fields and retain unknown words.
Input images and the bulk recovery inventory are read-only.
"""
import hashlib
import json
from pathlib import Path
import sqlite3
import struct

from recover_dnas_zero_upper import BASE, SHA, fields, REG, transform, schedule

ROOT = Path(__file__).resolve().parents[2]
BOUNDS = (
    (0x747EA8, 0x747F30, 0x747FFC, 0x748078),
    (0x748078, 0x748100, 0x7481CC, 0x748248),
    (0x748248, 0x7482D4, 0x748474, 0x7484F4),
    (0x7484F8, 0x748584, 0x748694, 0x748710),
    (0x748710, 0x748784, 0x7487C0, 0x748828),
    (0x748828, 0x7488B4, 0x7489C4, 0x748A40),
    (0x748A40, 0x748AC8, 0x748B94, 0x748C10),
    (0x748C10, 0x748C84, 0x748CFC, 0x748D64),
    (0x748D68, 0x748DF4, 0x748F04, 0x748F80),
    (0x748F80, 0x74900C, 0x749234, 0x7492AC),
    (0x7492B0, 0x74933C, 0x74944C, 0x7494C8),
)


def extra_fields(pc, w):
    decoded = fields(pc, w)
    if 'UNDECODED' not in decoded:
        return decoded
    op, rs, rt, rd, sh, fn = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31, (w >> 6) & 31, w & 63
    r = lambda n: '$' + REG[n]
    if op in (0x31, 0x39):
        imm = w & 65535
        signed = imm - 65536 if imm & 32768 else imm
        return f'{"lwc1" if op == 0x31 else "swc1"} $f{rt}, {signed}({r(rs)})'
    if op == 0x11:
        if rs in (0, 4):
            return f'{"mfc1" if rs == 0 else "mtc1"} {r(rt)}, $f{rd}'
        if rs == 8:
            imm = w & 65535
            signed = imm - 65536 if imm & 32768 else imm
            return f'{ {0:"bc1f",1:"bc1t",2:"bc1fl",3:"bc1tl"}[rt & 3]} 0x{pc+4+signed*4:08X}'
        if rs == 16:
            if fn in (0, 1, 2, 3):
                return f'{ {0:"add.s",1:"sub.s",2:"mul.s",3:"div.s"}[fn]} $f{sh}, $f{rd}, $f{rt}'
            if fn == 0x24:
                return f'cvt.w.s $f{sh}, $f{rd}'
            if fn == 0x36:
                return f'c.le.s $f{rd}, $f{rt}'
        if rs == 20 and fn == 0x20:
            return f'cvt.s.w $f{sh}, $f{rd}'
    if op == 0:
        if fn in (0x10, 0x12):
            return f'{"mfhi" if fn == 0x10 else "mflo"} {r(rd)}'
        if fn in (0x18, 0x19, 0x1A, 0x1B):
            return f'{ {0x18:"mult",0x19:"multu",0x1A:"div",0x1B:"divu"}[fn]} {r(rs)}, {r(rt)}'
        if fn in (4, 6, 7):
            return f'{ {4:"sllv",6:"srlv",7:"srav"}[fn]} {r(rd)}, {r(rt)}, {r(rs)}'
        if fn in (0x2F, 0x3C, 0x3E, 0x3F):
            return (f'dsubu {r(rd)}, {r(rs)}, {r(rt)}' if fn == 0x2F else
                    f'{ {0x3C:"dsll32",0x3E:"dsrl32",0x3F:"dsra32"}[fn]} {r(rd)}, {r(rt)}, {sh}')
    return decoded


def main():
    image = ROOT / 'build-function-index/owned-overlays/o4.bin'
    raw = image.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == SHA
    bulk = json.loads((ROOT / 'build-function-index/dnas-upper-recovery-inventory.json').read_text())
    assert bulk['image_sha256'] == SHA and bulk['owned_image_unchanged']
    spans = {int(r['start'], 16): r for r in bulk['spans']}
    def read(address, count):
        return struct.unpack_from('<'+'I'*count, raw, address-BASE)

    # Recheck the owner original entry/restore descriptors and exception
    # selections independently of the bulk receipt's asserted booleans.
    metadata = {}
    assert read(0x744F28, 1) == (49,)
    for index in range(49):
        key, offset = read(0x744F2C+index*8, 2)
        record = 0x7450B4+offset
        relative_base, count = read(record, 2)
        metadata[key >> 1] = (relative_base, read(record+8, count))
    database = sqlite3.connect(f'file:{ROOT / "build-function-index/index.sqlite"}?mode=ro', uri=True)
    labels = {(row[0], row[1]): row[2] for row in database.execute('select image,start,proposed_name from functions')}
    listing, receipts = [], []
    for owner, start, end, tail in BOUNDS:
        span = spans[start]
        assert int(span['end_exclusive'], 16) == end and span['payload_roundtrip_exact']
        candidate = [int(w, 16) for w in span['candidate_words']]
        packed = struct.pack('<' + 'I' * len(candidate), *candidate)
        assert hashlib.sha256(packed).hexdigest() == span['candidate_sha256']
        header, restore = read(start-20, 5), read(end+32, 4)
        assert list(header) == [int(w, 16) for w in span['header']]
        assert list(restore) == [int(w, 16) for w in span['restore_header']]
        assert header[2] & 1 == 0 and restore[1] & 1 == 1
        assert header[1] ^ header[3] == restore[0] ^ restore[2] == end-start
        assert metadata[header[2] >> 1] == metadata[restore[1] >> 1]
        relative_base, exceptions = metadata[header[2] >> 1]
        assert relative_base == span['metadata']['relative_base']
        assert list(exceptions) == span['metadata']['exception_offsets']
        entry_slots, restore_slots = schedule(header[1]), schedule(restore[0])
        assert list(entry_slots) == span['entry_slots']
        assert list(restore_slots) == span['restore_slots']
        original = read(start, (end-start)//4)
        eligible = [relative_base+4*i not in exceptions for i in range(len(original))]
        independent = list(original)
        for slot in entry_slots:
            independent = [transform(w, slot, True) if eligible[i] else w
                           for i, w in enumerate(independent)]
        assert independent == candidate
        for slot in restore_slots:
            independent = [transform(w, slot, False) if eligible[i] else w
                           for i, w in enumerate(independent)]
        assert independent == list(original)
        assert read(start-76, 8) == (
            0x3C040000 | ((start+0x8000)>>16), 0x24840000 | (start&65535),
            0x8C670008, 0x8C65000C, 0x0C1D15F2, 0x8C660004,
            0x1000000C, 0)
        assert read(end, 2) == (0x1000000B, 0)
        assert read(end+48, 8) == (
            0x3C020000 | ((end+32+0x8000)>>16), 0x24420000 | ((end+32)&65535),
            0x3C040000 | ((end+0x8000)>>16), 0x24840000 | (end&65535),
            0x8C470004, 0x8C450008, 0x0C1D15F2, 0x8C460000)
        sections = ((owner, start - 44, 'owned_clear'), (start, end, 'candidate'),
                    (end, end + 8, 'owned_clear'), (end + 48, tail, 'owned_clear'))
        words = []
        listing.append(f'OWNER {owner:08X}..{tail:08X} SPAN {start:08X}..{end:08X}')
        for lo, hi, kind in sections:
            assert (hi-lo) % 4 == 0 and lo <= hi
            values = candidate if kind == 'candidate' else struct.unpack_from('<'+'I'*((hi-lo)//4), raw, lo-BASE)
            listing.append(f'  {kind} {lo:08X}..{hi:08X}')
            for i, w in enumerate(values):
                pc = lo + i * 4
                decoded = extra_fields(pc, w)
                if w >> 26 in (2, 3):
                    target = ((pc+4)&0xF0000000) | ((w&0x3FFFFFF)<<2)
                    label = labels.get(('o4', target)) or labels.get(('main', target))
                    if label:
                        decoded += '  [' + label + ']'
                words.append(dict(address=hex(pc), word=f'{w:08X}', origin=kind, fields=decoded))
                listing.append(f'{pc:08X} {w:08X} {decoded}')
        receipts.append(dict(owner=hex(owner), end_exclusive=hex(tail), span=span,
                             independent_original_descriptor_and_restore_check=True,
                             complete_original_interval_sha256=hashlib.sha256(raw[owner-BASE:tail-BASE]).hexdigest(),
                             words=words))
    assert hashlib.sha256(image.read_bytes()).hexdigest() == SHA
    out = ROOT / 'build-function-index/dnas-query-adapters-review'
    out.mkdir(exist_ok=True)
    (out/'words.txt').write_text('\n'.join(listing)+'\n', encoding='utf-8')
    (out/'receipt.json').write_text(json.dumps(dict(schema=1, image_sha256=SHA, owners=receipts,
                                                     no_guest_execution=True, owned_image_unchanged=True), indent=2)+'\n', encoding='utf-8')
    unknown = [w for r in receipts for w in r['words'] if 'UNDECODED' in w['fields']]
    print('Listed', len(receipts), 'connected static candidates; unknown word fields', len(unknown))
    for w in unknown:
        print(w)


if __name__ == '__main__':
    main()
