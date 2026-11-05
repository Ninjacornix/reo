#!/usr/bin/env python3
"""Joined static word receipts for five o5 service owners; no guest execution."""
import hashlib
import json
from pathlib import Path
import struct

from recover_dnas_o5_family_inventory import SHA,BASE
from review_dnas_proxy_first_owner_groups import fields
from recover_dnas_zero_upper import schedule,transform

ROOT=Path(__file__).resolve().parents[2]
BOUNDS=((0x6FA558,0x6FAE98),(0x6FAE98,0x6FCE18),
        (0x6FD230,0x6FDC1C),(0x6FDC20,0x6FF5B0),(0x6FF5B0,0x7005F8))


def main():
    image=ROOT/'build-function-index/owned-overlays/o5.bin'
    raw=image.read_bytes()
    assert hashlib.sha256(raw).hexdigest()==SHA
    inventory=json.loads((ROOT/'build-function-index/dnas-o5-family-recovery-inventory.json').read_text())
    assert inventory['image_sha256']==SHA
    read=lambda a:struct.unpack_from('<I',raw,a-BASE)[0]
    reads=lambda a,n:struct.unpack_from('<'+'I'*n,raw,a-BASE)
    lui=lambda r,a:0x3C000000|(r<<16)|((a+0x8000)>>16)
    addiu=lambda r,a:0x24000000|(r<<21)|(r<<16)|(a&65535)
    allcases=[]
    for owner,tail in BOUNDS:
        spans=[s for s in inventory['spans'] if owner<=int(s['start'],16)<tail]
        for s in spans:
            a,z=int(s['start'],16),int(s['end_exclusive'],16)
            header,restore=reads(a-20,5),reads(z+32,4)
            assert header==tuple(int(w,16) for w in s['header'])
            assert restore==tuple(int(w,16) for w in s['restore_header'])
            assert header[1]^header[3]==restore[0]^restore[2]==z-a
            meta=s['metadata'];relative=meta['relative_base'];excluded=set(meta['exception_offsets'])
            if meta['record_address']:
                record=int(meta['record_address'],16)
                assert reads(record,2)==(relative,len(excluded))
                assert list(reads(record+8,len(excluded)))==meta['exception_offsets']
            original=list(reads(a,(z-a)//4));candidate=list(original)
            eligible=[(relative+4*i)&0xFFFFFFFF not in excluded for i in range(len(candidate))]
            for slot in schedule(header[1]):
                candidate=[transform(w,slot,True) if eligible[i] else w for i,w in enumerate(candidate)]
            assert candidate==[int(w,16) for w in s['candidate_words']]
            for slot in schedule(restore[0]):
                candidate=[transform(w,slot,False) if eligible[i] else w for i,w in enumerate(candidate)]
            assert candidate==original
        # Literal clear setup checks for the five noncanonical restore bindings.
        # No symbolic execution: compare owned instruction words to reviewed fields.
        noncanonical={
            0x6FA94C:(0x6FAC74,[lui(2,0x6FAC64),addiu(2,0x6FAC64),lui(4,0x6FAC44),addiu(4,0x6FAC44),
                0x0000882D,0x8C470004,0x8C450008,0x0C1C2386,0x8C460000]),
            0x6FC4FC:(0x6FC560,[lui(2,0x6FC550),addiu(2,0x6FC550),lui(4,0x6FC530),addiu(4,0x6FC530),
                0x8C450008,0x8C460000,0x0C1C2386,0x8C470004]),
            0x6FD344:(0x6FD4B8,[lui(2,0x6FD4A8),addiu(2,0x6FD4A8),lui(4,0x6FD488),addiu(4,0x6FD488),
                0x8C470004,0x0000802D,0x8C450008,0x3C118000,0x3C014EFF,0x3421FFFF,
                0x4481B000,0x3C014380,0x4481A800,0x0C1C2386,0x8C460000]),
            0x6FD5B4:(0x6FD840,[lui(2,0x6FD830),addiu(2,0x6FD830),lui(4,0x6FD810),addiu(4,0x6FD810),
                0x8C450008,0x8C460000,0x0C1C2386,0x8C470004]),
            0x6FD988:(0x6FDA14,[lui(2,0x6FDA04),addiu(2,0x6FDA04),lui(4,0x6FD9E4),addiu(4,0x6FD9E4),
                0x1000006A,0x8C470004]),
        }
        for s in spans:
            start=int(s['start'],16)
            if s['canonical_clear_restore_setup_verified']:
                z=int(s['end_exclusive'],16)
                assert reads(z+48,8)==(lui(2,z+32),addiu(2,z+32),lui(4,z),addiu(4,z),
                    0x8C470004,0x8C450008,0x0C1C2386,0x8C460000)
            else:
                a,expected=noncanonical[start]
                assert reads(a,len(expected))==tuple(expected)
                if start==0x6FD988:
                    assert reads(0x6FDBD0,3)==(0x8C450008,0x0C1C2386,0x8C460000)
        candidates={int(s['start'],16)+4*i:int(w,16) for s in spans for i,w in enumerate(s['candidate_words'])}
        skipped=set()
        for s in spans:
            a,z=int(s['start'],16),int(s['end_exclusive'],16)
            skipped.update(range(a-44,a,4));skipped.update(range(z+8,z+48,4))
        words=[]
        for a in range(owner,tail,4):
            w=candidates.get(a,read(a))
            words.append(dict(pc=f'{a:08X}',original_word=f'{read(a):08X}',
                candidate_word=f'{w:08X}',kind='skipped envelope data' if a in skipped else
                'reconstructed' if a in candidates else 'clear',
                fields='SKIPPED ENVELOPE DATA' if a in skipped else fields(a,w)))
        admitted={int(w['pc'],16) for w in words if w['kind']!='skipped envelope data'}
        assert not any('UNDECODED' in w['fields'] for w in words)
        branches=[]
        for item in words:
            if item['kind']=='skipped envelope data':continue
            a,w=int(item['pc'],16),int(item['candidate_word'],16);op=w>>26
            if op in (1,4,5,6,7,0x14,0x15) or (op==0x11 and (w>>21)&31==8):
                imm=w&65535;imm-=65536 if imm&32768 else 0
                target=a+4+4*imm
                assert target in admitted and a+4 in admitted,(hex(a),hex(target))
                branches.append(dict(pc=hex(a),target=hex(target),delay_slot=hex(a+4)))
        allcases.append(dict(owner=hex(owner),logical_end_exclusive=hex(tail),
            original_joined_sha256=hashlib.sha256(raw[owner-BASE:tail-BASE]).hexdigest(),
            payload_starts=[s['start'] for s in spans],words=words,
            candidate_words=len(candidates),skipped_envelope_words=len(skipped),
            direct_branches_checked=branches,all_actual_restore_bindings_verified=True,
            unknown_words=[w for w in words if 'UNDECODED' in w['fields']]))
        (ROOT/'build-function-index'/f'proxy-o5-owner-{owner:x}.txt').write_text(
            '\n'.join(f"{w['pc']} {w['candidate_word']} {w['fields']}" for w in words)+'\n',encoding='utf-8')
    dependency=[dict(pc=f'{a:08X}',original_word=f'{read(a):08X}',fields=fields(a,read(a)))
                for a in range(0x7091D0,0x70922C,4)]
    assert not any('UNDECODED' in w['fields'] for w in dependency)
    out=ROOT/'build-function-index/proxy-dnas-o5-large-owner-review.json'
    out.write_text(json.dumps(dict(schema=1,image='o5',image_sha256=SHA,cases=allcases,
        uncredited_clear_dependency=dict(start='0x7091d0',end_exclusive='0x70922c',words=dependency,
            original_sha256=hashlib.sha256(raw[0x7091D0-BASE:0x70922C-BASE]).hexdigest()),
        total_candidate_words=sum(c['candidate_words'] for c in allcases),
        total_clear_instruction_words=sum(sum(w['kind']=='clear' for w in c['words']) for c in allcases),
        total_branch_targets=sum(len(c['direct_branches_checked']) for c in allcases),
        limitation='Static copied-data and clear word-field review only. All five connected owners and actual restore bindings individually reviewed. '
        'No guest execution, malformed-input safety proof, universal restore guarantee or extra fragment/dependency mapping credit.'),indent=2)+'\n',encoding='utf-8')
    print([(c['owner'],len(c['payload_starts']),c['candidate_words'],len(c['unknown_words'])) for c in allcases])
    assert hashlib.sha256(image.read_bytes()).hexdigest()==SHA


if __name__=='__main__':
    main()
