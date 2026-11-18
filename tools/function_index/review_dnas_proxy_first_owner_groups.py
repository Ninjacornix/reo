#!/usr/bin/env python3
"""Reproduce the first14 upper and first23 primary connected o4 word reviews.

Static arithmetic and explicit instruction-field listing only; no guest code is
executed or emulated. Requires only the hash-bound owned image, never old receipts.
"""
import hashlib
import json
from pathlib import Path
import sqlite3
import struct

from recover_dnas_zero_upper import BASE, SHA, schedule, transform
from review_dnas_query_adapters import extra_fields
from recover_dnas_zero_upper import REG

ROOT = Path(__file__).resolve().parents[2]
BOUNDS = {
    'first14': (
        (0x7468a8, 0x746924, 0x74697c, 0x7469e8),
        (0x7469e8, 0x746a64, 0x746abc, 0x746b28),
        (0x746b28, 0x746b9c, 0x746bd0, 0x746c38),
        (0x746c38, 0x746cd8, 0x74727c, 0x747308),
        (0x747308, 0x7473ac, 0x747524, 0x7475ac),
        (0x7475b0, 0x747624, 0x747660, 0x7476c8),
        (0x7476c8, 0x74773c, 0x747778, 0x7477e0),
        (0x7477e0, 0x74784c, 0x747864, 0x7478c8),
        (0x7478c8, 0x747934, 0x747948, 0x7479ac),
        (0x7479b0, 0x747a1c, 0x747a30, 0x747a94),
        (0x747a98, 0x747b04, 0x747b1c, 0x747b80),
        (0x747b80, 0x747bec, 0x747c04, 0x747c68),
        (0x747c68, 0x747d00, 0x747d18, 0x747d84),
        (0x747d88, 0x747e30, 0x747e44, 0x747ea8),
    ),
    'first23': (
        (0x6e2a08, 0x6e2a78, 0x6e2aa4, 0x6e2b08),
        (0x6e2b08, 0x6e2b78, 0x6e2ba4, 0x6e2c08),
        (0x6e2c08, 0x6e2c84, 0x6e2ca4, 0x6e2d0c),
        (0x6e2d10, 0x6e2d8c, 0x6e2db4, 0x6e2e1c),
        (0x6e2e20, 0x6e2e90, 0x6e2ebc, 0x6e2f20),
        (0x6e2f20, 0x6e2f90, 0x6e2fbc, 0x6e3020),
        (0x6e3020, 0x6e3090, 0x6e309c, 0x6e3100),
        (0x6e3100, 0x6e3170, 0x6e319c, 0x6e3200),
        (0x6e3200, 0x6e3270, 0x6e327c, 0x6e32e0),
        (0x6e32e0, 0x6e3350, 0x6e335c, 0x6e33c0),
        (0x6e33c0, 0x6e3430, 0x6e343c, 0x6e34a0),
        (0x6e34a0, 0x6e3510, 0x6e353c, 0x6e35a0),
        (0x6e35a0, 0x6e3610, 0x6e3624, 0x6e3688),
        (0x6e3688, 0x6e3700, 0x6e3724, 0x6e378c),
        (0x6e3790, 0x6e3808, 0x6e382c, 0x6e3894),
        (0x6e3898, 0x6e3914, 0x6e3994, 0x6e3a00),
        (0x6e3a00, 0x6e3a78, 0x6e3aac, 0x6e3b14),
        (0x6e3b18, 0x6e3b88, 0x6e3b9c, 0x6e3c00),
        (0x6e3c00, 0x6e3c78, 0x6e3c9c, 0x6e3d04),
        (0x6e3d08, 0x6e3d78, 0x6e3d84, 0x6e3de8),
        (0x6e3de8, 0x6e3e58, 0x6e3e64, 0x6e3ec8),
        (0x6e3ec8, 0x6e3f44, 0x6e3fc4, 0x6e4030),
        (0x6e4030, 0x6e40a8, 0x6e40dc, 0x6e4144),
    ),
}


def fields(pc,w):
    decoded=extra_fields(pc,w)
    op,rs,rt=w>>26,(w>>21)&31,(w>>16)&31
    if 'UNDECODED' in decoded and op in (0x1A,0x1B,0x2C,0x2D):
        imm=w&65535;imm-=65536 if imm&32768 else 0
        return f'{ {0x1A:"ldl",0x1B:"ldr",0x2C:"sdl",0x2D:"sdr"}[op]} ${REG[rt]}, {imm}(${REG[rs]})'
    return decoded


def main():
    image = ROOT/'build-function-index/owned-overlays/o4.bin'
    raw = image.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == SHA
    def read(a,n):
        assert BASE <= a <= a+4*n <= BASE+len(raw)
        return struct.unpack_from('<'+'I'*n,raw,a-BASE)
    def digest(a,z):
        return hashlib.sha256(raw[a-BASE:z-BASE]).hexdigest()
    pack = lambda w:struct.pack('<'+'I'*len(w),*w)
    lui = lambda r,a:0x3C000000|(r<<16)|((a+0x8000)>>16)
    addiu = lambda r,a:0x24000000|(r<<21)|(r<<16)|(a&65535)
    database=sqlite3.connect('file:'+(ROOT/'build-function-index/index.sqlite').as_posix()+'?mode=ro',uri=True)
    for group,bounds in BOUNDS.items():
        upper = group=='first14'
        dispatcher,table,count = (0x7457C8,0x744F28,49) if upper else (0x70BA68,0x70CB48,52)
        assert read(table,1)==(count,)
        metadata={}
        for index in range(count):
            key,offset=read(table+4+8*index,2)
            assert offset<0x80000000
            address=table+4+count*8+offset
            relative,n=read(address,2)
            assert n<0x10000 and key>>1 not in metadata
            metadata[key>>1]=(relative,set(read(address+8,n)))
        cases=[]
        for owner,start,end,tail in bounds:
            header,restore=read(start-20,5),read(end+32,4)
            assert header[0]==header[4]==restore[3]==0
            assert header[2]&1==0 and restore[1]==header[2]+1
            assert header[1]^header[3]==restore[0]^restore[2]==end-start
            relative,exceptions=metadata.get(header[2]>>1,(0,set()))
            assert header[2]==0 or header[2]>>1 in metadata
            entryslots,restoreslots=schedule(header[1]),schedule(restore[0])
            original=list(read(start,(end-start)//4));candidate=list(original)
            eligible=[(relative+4*i)&0xFFFFFFFF not in exceptions for i in range(len(original))]
            for slot in entryslots:
                candidate=[transform(w,slot,True) if eligible[i] else w for i,w in enumerate(candidate)]
            restored=list(candidate)
            for slot in restoreslots:
                restored=[transform(w,slot,False) if eligible[i] else w for i,w in enumerate(restored)]
            assert restored==original
            call=start-60
            assert read(call-16,6)==(lui(4,start),addiu(4,start),0x8C670008,0x8C65000C,
                                    0x0C000000|(dispatcher>>2),0x8C660004)
            expected=(lui(2,end+32),addiu(2,end+32),lui(4,end),addiu(4,end),
                      0x8C470004,0x8C450008,0x0C000000|(dispatcher>>2),0x8C460000)
            assert read(end+48,8)==expected
            clearpcs=list(range(owner,start-44,4))+list(range(end,end+8,4))+list(range(end+48,tail,4))
            clearwords=[dict(pc=f'{a:08X}',original_word=f'{read(a,1)[0]:08X}',fields=fields(a,read(a,1)[0])) for a in clearpcs]
            candidatewords=[dict(pc=f'{start+4*i:08X}',original_word=f'{original[i]:08X}',
                candidate_word=f'{w:08X}',fields=fields(start+4*i,w)) for i,w in enumerate(candidate)]
            unknown=[w for w in clearwords+candidatewords if 'UNDECODED' in w['fields']]
            assert not unknown,unknown
            admitted=set(clearpcs)|set(range(start,end,4))
            branches=[]
            for w in clearwords+candidatewords:
                a=int(w['pc'],16);v=int(w.get('candidate_word',w['original_word']),16)
                op=v>>26
                if op in (1,4,5,6,7,0x14,0x15) or (op==0x11 and (v>>21)&31==8):
                    imm=v&65535;imm-=65536 if imm&32768 else 0
                    target=a+4+4*imm
                    assert target in admitted and a+4 in admitted,(hex(a),hex(target))
                    branches.append(dict(pc=hex(a),target=hex(target),delay_slot=hex(a+4)))
            fragments=[f'{a:08X}' for a, in database.execute('select start from functions where image=? and start>? and start<? order by start',('o4',owner,tail))]
            case=dict(owner=hex(owner),logical_end_exclusive=hex(tail),payload_start=hex(start),
                payload_end_exclusive=hex(end),candidate_sha256=hashlib.sha256(pack(candidate)).hexdigest(),
                clear_words=clearwords,candidate_words=candidatewords,catalogue_fragments_uncredited=fragments,
                preserved_exception_words=len(original)-sum(eligible),entry_call=hex(call),restore_call=hex(end+72),
                direct_branches_checked=branches,metadata_paired_roundtrip_exact=True)
            case['original_joined_sha256' if upper else 'joined_original_sha256']=digest(owner,tail)
            cases.append(case)
        receipt=dict(schema=1,image='o4',image_sha256=SHA,cases=cases,
            limitation='Static copied-data word-field review only. No guest execution or input mutation. Internal fragments remain uncredited.')
        out=ROOT/'build-function-index'/('proxy-dnas-first14-review.json' if upper else 'proxy-dnas-primary-first23-review.json')
        out.write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
        print(group,len(cases),'owners',sum(len(c['candidate_words']) for c in cases),'candidate words',
              sum(len(c['clear_words']) for c in cases),'clear words')
    database.close()
    assert hashlib.sha256(image.read_bytes()).hexdigest()==SHA


if __name__=='__main__':
    main()
