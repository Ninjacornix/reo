#!/usr/bin/env python3
"""List two hash-bound copied-data candidates and connected clear envelopes.

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
BOUNDS = ((0x6EA4C0,0x6EA63C,0x6EA9E0,0x6EAA5C),(0x6EACE0,0x6EADD8,0x6EAE9C,0x6EB320))
INLINE = ((0x6EA644,0x6EA6F8),(0x6EA718,0x6EA770),(0x6EA788,0x6EA7F8),
          (0x6EA810,0x6EA880),(0x6EA898,0x6EA908),(0x6EA920,0x6EA990),
          (0x6EADE0,0x6EADF8),(0x6EAE1C,0x6EAE38),(0x6EAE60,0x6EAE70))


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


def bounded_subjects(receipts, raw):
    words={int(w['address'],16):int(w['word'],16) for w in receipts[0]['words']}
    subjects=[]
    def parse(blob,lo,hi):
        out=[]
        while lo<hi:
            tag=blob[lo];lo+=1;length=blob[lo];lo+=1
            if length&128:
                count=length&127
                assert count and lo+count<=hi
                length=int.from_bytes(blob[lo:lo+count],'big');lo+=count
            end=lo+length;assert end<=hi
            if tag&32:out+=parse(blob,lo,end)
            elif tag in (0x13,0x16):out.append(blob[lo:end].decode('ascii'))
            lo=end
        assert lo==hi
        return out
    for i,a in enumerate((0x6EA64C,0x6EA720,0x6EA790,0x6EA818,0x6EA8A0,0x6EA928)):
        record=0x7616F8+20*i
        n=struct.unpack_from('<I',raw,record+4-BASE)[0]
        blob=b''.join(struct.pack('<I',words[p]) for p in range(a,a+((n+3)//4)*4,4))[:n]
        subjects.append(dict(record=hex(record),address=hex(a),length=n,
            sha256=hashlib.sha256(blob).hexdigest(),bounded_der_string_fields=parse(blob,0,len(blob))))
    return subjects


def main():
    image = ROOT / 'build-function-index/owned-overlays/o4.bin'
    raw = image.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == SHA
    bulk = json.loads((ROOT / 'build-function-index/dnas-primary-recovery-inventory.json').read_text())
    assert bulk['image_sha256'] == SHA
    spans = {int(r['start'], 16): r for r in bulk['spans']}
    def read(address, count):
        return struct.unpack_from('<'+'I'*count, raw, address-BASE)

    # Recheck the owner original entry/restore descriptors and exception
    # selections independently of the bulk receipt's asserted booleans.
    metadata = {}
    assert read(0x70CB48, 1) == (52,)
    for index in range(52):
        key, offset = read(0x70CB4C+index*8, 2)
        record = 0x70CCEC+offset
        relative_base, count = read(record, 2)
        metadata[key >> 1] = (relative_base, read(record+8, count))
    database = sqlite3.connect(f'file:{ROOT / "build-function-index/index.sqlite"}?mode=ro', uri=True)
    labels = {(row[0], row[1]): row[2] for row in database.execute('select image,start,proposed_name from functions')}
    listing, receipts = [], []
    for owner, start, end, tail in BOUNDS:
        span = spans[start]
        assert int(span['end_exclusive'], 16) == end and span['metadata_paired_roundtrip_exact']
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
            0x8C670008, 0x8C65000C, 0x0C1C2E9A, 0x8C660004,
            0x1000000C, 0)
        assert read(end, 2) == (0x1000000B, 0)
        if owner==0x6EA4C0:
            assert read(end+48,8)==(0x3C02006F,0x2442AA00,0x3C04006F,0x2484A9E0,0x8C470004,0x8C450008,0x0C1C2E9A,0x8C460000)
        else:
            assert read(0x6EAECC,6)==(0x3C02006F,0x2442AEBC,0x3C04006F,0x2484AE9C,0x8C470004,0x3C15007F)
            assert read(0x6EAEE4,1)==(0x8C450008,)
            assert read(0x6EAEFC,2)==(0x0C1C2E9A,0x8C460000)
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
                if any(lo<=pc<hi for lo,hi in INLINE):
                    decoded='INLINE DATA '+struct.pack('<I',w).hex()
                if w >> 26 in (2, 3):
                    target = ((pc+4)&0xF0000000) | ((w&0x3FFFFFF)<<2)
                    label = labels.get(('o4', target)) or labels.get(('main', target))
                    if label:
                        decoded += '  [' + label + ']'
                words.append(dict(address=hex(pc), word=f'{w:08X}', origin=('candidate_inline_data' if any(lo<=pc<hi for lo,hi in INLINE) else kind), fields=decoded))
                listing.append(f'{pc:08X} {w:08X} {decoded}')
        receipts.append(dict(owner=hex(owner), end_exclusive=hex(tail), span=span,
                             independent_original_descriptor_and_restore_check=True,
                             complete_original_interval_sha256=hashlib.sha256(raw[owner-BASE:tail-BASE]).hexdigest(),
                             words=words))
        code={int(w['address'],16) for w in words if w['origin']!='candidate_inline_data'}
        branches=[];calls=[]
        for row in words:
            pc,w=int(row['address'],16),int(row['word'],16)
            if pc not in code:continue
            if w>>26 in (1,4,5,6,7,0x14,0x15,0x16,0x17) or (w>>26==0x11 and (w>>21)&31==8):
                imm=w&65535;target=pc+4+(imm-65536 if imm&32768 else imm)*4
                assert target in code,(hex(pc),hex(target))
                branches.append(dict(pc=hex(pc),target=hex(target)))
            if w>>26==3 and (w&0x3FFFFFF)<<2==0x70BA68:calls.append(pc)
        assert calls==([0x6EA600,0x6EAA28] if owner==0x6EA4C0 else [0x6EAD9C,0x6EAEFC])
        receipts[-1]['independently_bound_dispatch_calls']=[hex(pc) for pc in calls]
        receipts[-1]['direct_branch_targets']=branches
        if owner==0x6EACE0:
            table=read(0x77C190,8)
            assert table==(0x6EB270,0x6EB278,0x6EB278,0x6EB278,0x6EB278,0x6EB278,0x6EB298,0x6EB278)
            assert all(pc in code for pc in table)
            receipts[-1]['handshake_switch']=[hex(pc) for pc in table]
    assert hashlib.sha256(image.read_bytes()).hexdigest() == SHA
    out = ROOT / 'build-function-index/dnas-primary-start-connect-review'
    out.mkdir(exist_ok=True)
    (out/'words.txt').write_text('\n'.join(listing)+'\n', encoding='utf-8')
    (out/'receipt.json').write_text(json.dumps(dict(schema=1, image_sha256=SHA, owners=receipts,
                                                     bounded_inline_subjects=bounded_subjects(receipts,raw),
                                                     no_guest_execution=True, owned_image_unchanged=True), indent=2)+'\n', encoding='utf-8')
    unknown = [w for r in receipts for w in r['words'] if 'UNDECODED' in w['fields']]
    print('Listed', len(receipts), 'connected static candidates; unknown word fields', len(unknown))
    for w in unknown:
        print(w)


if __name__ == '__main__':
    main()
