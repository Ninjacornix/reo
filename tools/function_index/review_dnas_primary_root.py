#!/usr/bin/env python3
"""Static review receipt for four primary owners, excluding inline data.

Never executes recovered code. Verifies owned clear words, reconstructed hashes,
explicit noncanonical restore setups, branch bounds and original interval hashes.
"""
import hashlib
import json
from pathlib import Path
import struct

from index import control
from recover_dnas_zero_upper import BASE, SHA, REG
from review_dnas_upper_root import describe

ROOT = Path(__file__).resolve().parents[2]
CASES = (
    dict(owner=0x6E1100,end=0x6E190C,start=0x6E1590,
         sha='977a971b40013476605dd5a4f946b0f50e3534b57b44616505fc67e74eee709a',
         code=((0x6E1590,0x6E1598),(0x6E15C0,0x6E15D4),(0x6E1600,0x6E163C)),
         restore_at=0x6E166C,restore_words=(0x3C02006E,0x2442165C,0x3C04006E,0x2484163C,
                    0x2411FF95,0x8C470004,0x26500FB0,0x8C450008,0x0C1C2E9A,0x8C460000)),
    dict(owner=0x6EB9C8,end=0x6EBF20,start=0x6EBA6C,
         sha='788b3fb7b3ad3d51dcbadcf0bf9cdf2b6776114ec3e929c86a748192aade1a0a',
         code=((0x6EBA6C,0x6EBA74),(0x6EBA88,0x6EBAA0)),
         restore_at=0x6EBAD0,restore_words=(0x3C02006F,0x2442BAC0,0x3C04006F,0x2484BAA0,
                    0x8C470004,0x0000802D,0x8C450008,0x2413FDA6,0x0C1C2E9A,0x8C460000)),
    dict(owner=0x6ECA08,end=0x6ECD1C,start=0x6ECB40,
         sha='ebdf43707ee40df1a3e0001928728827379468c1242f6cf4f332777f6f9b4864',
         code=((0x6ECB40,0x6ECB48),(0x6ECB70,0x6ECB8C)),
         restore_at=0x6ECBBC,restore_words=(0x3C02006F,0x2442CBAC,0x3C04006F,0x2484CB8C,
                    0x8C450008,0x0000A02D,0x8C470004,0x0C1C2E9A,0x8C460000)),
    dict(owner=0x6ECD20,end=0x6ED490,start=0x6ECDBC,
         sha='f205b2e8172ba0741e6929bd4251d81c7224ff3e025b669d2e3586e436e7ea15',
         code=((0x6ECDBC,0x6ECDC4),(0x6ECEF8,0x6ECF18),(0x6ECF80,0x6ECF98),
               (0x6ED048,0x6ED060),(0x6ED110,0x6ED128),(0x6ED1D8,0x6ED1F0),(0x6ED298,0x6ED40C)),
         restore_at=0x6ED43C,restore_words=(0x3C02006F,0x2442D42C,0x3C04006F,0x2484D40C,
                    0x8C470004,0x8C450008,0x0C1C2E9A,0x8C460000)),
)


def main():
    image = ROOT/'build-function-index/owned-overlays/o4.bin'
    raw = image.read_bytes()
    assert hashlib.sha256(raw).hexdigest()==SHA
    data = json.loads((ROOT/'build-function-index/dnas-primary-recovery-inventory.json').read_text(encoding='utf-8'))
    assert data['image_sha256']==SHA
    spans = {int(r['start'],16):r for r in data['spans']}
    owners, lines = [], []
    for case in CASES:
        owner,start,owner_end = case['owner'],case['start'],case['end']
        span = spans[start]
        end = int(span['end_exclusive'],16)
        candidate = [int(w,16) for w in span['candidate_words']]
        assert hashlib.sha256(struct.pack('<'+'I'*len(candidate),*candidate)).hexdigest()==case['sha']
        actual = struct.unpack_from('<'+'I'*len(case['restore_words']),raw,case['restore_at']-BASE)
        assert actual==case['restore_words']
        pcs = {}
        regions = [(owner,start-0x2C,'owned_clear'),(end,end+8,'owned_clear'),(end+0x30,owner_end,'owned_clear')]
        regions += [(lo,hi,'reconstructed_code') for lo,hi in case['code']]
        for lo,hi,kind in regions:
            for pc in range(lo,hi,4):
                word = candidate[(pc-start)//4] if kind=='reconstructed_code' else struct.unpack_from('<I',raw,pc-BASE)[0]
                decoded = describe(pc,word)
                if word>>26 in (22,23):
                    offset = word&65535; offset = offset-65536 if offset&32768 else offset
                    decoded = f'{"blezl" if word>>26==22 else "bgtzl"} ${REG[(word>>21)&31]},0x{pc+4+offset*4:X}'
                assert 'UNDECODED' not in decoded,(hex(pc),hex(word))
                assert pc not in pcs
                pcs[pc] = dict(pc=hex(pc),word=f'{word:08X}',origin=kind,fields=decoded)
        branches = []
        for pc,row in pcs.items():
            word = int(row['word'],16)
            is_control,target = control(pc,word)
            if target is not None and word>>26!=3:
                assert is_control and target in pcs,(hex(owner),hex(pc),hex(target))
                branches.append(dict(pc=hex(pc),target=hex(target)))
        returns = [pc for pc,row in pcs.items() if row['word']=='03E00008']
        assert len(returns)==1 and returns[0]+8==owner_end
        rows = [pcs[pc] for pc in sorted(pcs)]
        code_count = sum((hi-lo)//4 for lo,hi in case['code'])
        owners.append(dict(owner=f'o4:0x{owner:08X}',end_exclusive=hex(owner_end),
                           original_joined_sha256=hashlib.sha256(raw[owner-BASE:owner_end-BASE]).hexdigest(),
                           payload=hex(start),payload_end_exclusive=hex(end),candidate_sha256=case['sha'],
                           candidate_words=len(candidate),reconstructed_code_words=code_count,
                           skipped_inline_words=len(candidate)-code_count,clear_words=len(rows)-code_count,
                           actual_restore_setup=hex(case['restore_at']),branches=branches,words=rows))
        lines += [f'OWNER {owner:08X}..{owner_end:08X}']+[f'{r["pc"]} {r["word"]} {r["origin"]} {r["fields"]}' for r in rows]
    assert hashlib.sha256(image.read_bytes()).hexdigest()==SHA
    result = dict(schema=1,image_sha256=SHA,owners=owners,no_guest_execution=True,
                  limitation='Static admitted code and inline-data boundaries; no callback implementation, runtime, '
                  'network, certificate-security, provider-correctness or performance claim.')
    out = ROOT/'build-function-index/dnas-primary-root-review'
    out.mkdir(exist_ok=True)
    (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    (out/'words.txt').write_text('\n'.join(lines)+'\n',encoding='utf-8')
    print(f'Reviewed4 primary owners: {sum(r["candidate_words"] for r in owners)} candidate words '
          f'({sum(r["skipped_inline_words"] for r in owners)} inline data/padding), '
          f'{sum(r["clear_words"] for r in owners)} clear words, '
          f'{sum(len(r["branches"]) for r in owners)} bounded branches; no execution.')


if __name__=='__main__':
    main()
