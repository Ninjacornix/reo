#!/usr/bin/env python3
"""Rebuild twelve reviewed upper envelopes as static word listings only.

No instructions are executed or emulated. Writes private receipts, never owned
inputs, generated sources, runtime code or shared annotations.
"""
import hashlib
import json
from pathlib import Path
import struct

from index import control
from recover_dnas_zero_upper import BASE, SHA, REG, fields

ROOT = Path(__file__).resolve().parents[2]
CASES = (
    (0x74DB58,0x74DBE4,0x74DDC8,'7fdc92b79dbbc5a005de1e8941e1c95d2d2d8418924a2ca2e85bc0ec3ec4a696'),
    (0x74DDC8,0x74DE68,0x74E164,'13d5e784ca9ad452635d9eb766fd1d03857d3a50d24bf1114fc4c20e1435e31c'),
    (0x74E2E0,0x74E370,0x74E618,'68d70dda4811d44893bb4603549afa2d00c4cf9d9d57a1b1139870e162d1c38e'),
    (0x74E618,0x74E68C,0x74E728,'fd00abef117f4d4f2cbc546342d35de1ef15f9baadcc9d84c47e622e2b7beea9'),
    (0x74E830,0x74E8C8,0x74EBC8,'269069cfc68526966f7eccd48a606ac7dce7741f279d49d4fdc1fe256b5e823b'),
    (0x74EBC8,0x74EC5C,0x74EEE4,'d9cb0af075402e41026549b548ecd7d97aa5d23501eea5da081104c3a3489a92'),
    (0x74EF18,0x74EFD4,0x74F19C,'8e24c12db13dc2f563e77a3be07df0ef0d7fa486c2c4dc6e98d1c630800ed3a8'),
    (0x74F1D0,0x74F2B0,0x74F7AC,'3c8d3d54c3b975a4392e74082fddb5bcc3d9857016d3ea5807ff0d0811d65e17'),
    (0x74F818,0x74F894,0x74F95C,'518ceeb37d515a30960c91cc3ba282e5388fb80dee6f687df4521593cd56d4be'),
    (0x74F960,0x74F9FC,0x74FD34,'e8c1016a434d6bf66ab64ea344197c7e876b6cc25f274bf65d87bff13ed5367c'),
    (0x74FD38,0x74FDC4,0x74FF00,'0fa2b0c49c82b51eadb14e9a8b55939296151d7c32591b324d319943a970c8e1'),
    (0x74FF00,0x74FF94,0x7500B8,'f30cc921b99f62f649d3e0cce63a1849c217ba13e6d02c640ce55d4ce63023c7'),
)


def describe(pc, word):
    op,rs,rt,fs,fd,fn = word>>26,(word>>21)&31,(word>>16)&31,(word>>11)&31,(word>>6)&31,word&63
    offset = word&65535
    signed = offset-65536 if offset&32768 else offset
    if op in (0x31,0x39):
        return f'{"lwc1" if op==0x31 else "swc1"} $f{rt},{signed}(${REG[rs]})'
    if op==0x11:
        if rs in (0,4):
            return f'{"mfc1" if rs==0 else "mtc1"} ${REG[rt]},$f{fs}'
        if rs==8 and rt in (0,1,2,3):
            return f'{ {0:"bc1f",1:"bc1t",2:"bc1fl",3:"bc1tl"}[rt]} 0x{pc+4+signed*4:X}'
        if rs==20 and fn==32:
            return f'cvt.s.w $f{fd},$f{fs}'
        if rs==16:
            if fn in (0,1,2,3):
                return f'{ {0:"add.s",1:"sub.s",2:"mul.s",3:"div.s"}[fn]} $f{fd},$f{fs},$f{rt}'
            if fn==36:
                return f'cvt.w.s $f{fd},$f{fs}'
            if fn in (50,52,54):
                return f'{ {50:"c.eq.s",52:"c.lt.s",54:"c.le.s"}[fn]} $f{fs},$f{rt}'
    return fields(pc,word)


def main():
    image = ROOT/'build-function-index/owned-overlays/o4.bin'
    raw = image.read_bytes()
    assert hashlib.sha256(raw).hexdigest()==SHA
    inventory = json.loads((ROOT/'build-function-index/dnas-upper-recovery-inventory.json').read_text(encoding='utf-8'))
    assert inventory['image_sha256']==SHA
    spans = {int(r['start'],16):r for r in inventory['spans']}
    owners, listing = [], []
    for owner,start,owner_end,expected in CASES:
        span = spans[start]
        end = int(span['end_exclusive'],16)
        candidate = [int(w,16) for w in span['candidate_words']]
        assert hashlib.sha256(struct.pack('<'+'I'*len(candidate),*candidate)).hexdigest()==expected==span['candidate_sha256']
        pcs = {}
        for lo,hi,kind in ((owner,start-0x2C,'owned_clear'),(start,end,'reconstructed'),
                           (end,end+8,'owned_clear'),(end+0x30,owner_end,'owned_clear')):
            for pc in range(lo,hi,4):
                word = candidate[(pc-start)//4] if kind=='reconstructed' else struct.unpack_from('<I',raw,pc-BASE)[0]
                decoded = describe(pc,word)
                assert 'UNDECODED' not in decoded,(hex(pc),hex(word))
                assert pc not in pcs
                pcs[pc] = dict(pc=hex(pc),word=f'{word:08X}',origin=kind,fields=decoded)
        branches = []
        for pc,row in pcs.items():
            word = int(row['word'],16)
            is_control,target = control(pc,word)
            if target is not None and word>>26!=3:
                assert is_control and target in pcs,(hex(owner),hex(pc),hex(target))
                branches.append(dict(pc=hex(pc),target=hex(target),kind='branch_or_jump'))
        returns = [pc for pc,row in pcs.items() if row['word']=='03E00008']
        assert len(returns)==1
        assert all(row['word']=='00000000' for pc,row in pcs.items() if pc>returns[0]+4)
        rows = [pcs[pc] for pc in sorted(pcs)]
        owners.append(dict(owner=f'o4:0x{owner:08X}',end_exclusive=hex(owner_end),
                           complete_original_interval_sha256=hashlib.sha256(raw[owner-BASE:owner_end-BASE]).hexdigest(),
                           payload=hex(start),payload_end_exclusive=hex(end),candidate_payload_sha256=expected,
                           reconstructed_words=len(candidate),clear_words=len(rows)-len(candidate),
                           checked_branches=branches,words=rows))
        listing += [f'OWNER {owner:08X}..{owner_end:08X}']+[f'{r["pc"]} {r["word"]} {r["origin"]} {r["fields"]}' for r in rows]
    assert hashlib.sha256(image.read_bytes()).hexdigest()==SHA
    receipt = dict(schema=1,image_sha256=SHA,owners=owners,no_guest_execution=True,owned_image_unchanged=True,
                   limitations='Full static word listings and branch bounds only. Semantics require linked notebooks; '
                   'no runtime admission, provider equivalence, cryptographic correctness or performance conclusion.')
    out = ROOT/'build-function-index/dnas-upper-root-review'
    out.mkdir(exist_ok=True)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    (out/'words.txt').write_text('\n'.join(listing)+'\n',encoding='utf-8')
    print(f'Reviewed12 upper owners: {sum(x["reconstructed_words"] for x in owners)} recovered + '
          f'{sum(x["clear_words"] for x in owners)} clear words; '
          f'{sum(len(x["checked_branches"]) for x in owners)} bounded branches; input unchanged, no execution.')


if __name__=='__main__':
    main()
