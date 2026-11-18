#!/usr/bin/env python3
"""Review twenty joined o5 service owners as copied bytes, never guest execution."""
import hashlib
import json
from pathlib import Path
import struct

from recover_dnas_zero_upper import transform,schedule,REG
from review_dnas_query_adapters import extra_fields

ROOT=Path(__file__).resolve().parents[2]
BASE=0x6E0000
SHA='97174f5d367cd90bedd5ba397c6492e9fb4bbd0ec7d6021c2be524c49925d38e'
OWNERS=(
    (0x701BF8,0x701C90,0x701D14),(0x701D18,0x701DA0,0x701EE8),
    (0x701EE8,0x701F70,0x7020B8),(0x7020B8,0x702144,0x70234C),
    (0x702350,0x7023F0,0x702574),(0x702578,0x7025EC,0x702698),
    (0x702698,0x70270C,0x7027A8),(0x7027A8,0x7028C4,0x702EF0),
    (0x703028,0x7030A0,0x703194),(0x703198,0x703220,0x703340),
    (0x703340,0x7033CC,0x7035B8),(0x7035B8,0x703624,0x7036C8),
    (0x7036C8,0x703750,0x7038D0),(0x703D70,0x703E14,0x70429C),
    (0x7042A0,0x704314,0x7043F4),(0x707850,0x7078CC,0x707994),
    (0x707998,0x707A34,0x707D6C),(0x707D70,0x707DFC,0x707F38),
    (0x707F38,0x707FCC,0x7080F0),(0x7080F0,0x708194,0x708664))


def decoded(pc,w):
    result=extra_fields(pc,w)
    if 'UNDECODED' not in result:return result
    op,rs,rt,rd,fn=w>>26,(w>>21)&31,(w>>16)&31,(w>>11)&31,w&63
    if op in (0x1A,0x1B,0x2C,0x2D):
        imm=w&65535;imm=imm-65536 if imm&32768 else imm
        return f'{ {0x1A:"ldl",0x1B:"ldr",0x2C:"sdl",0x2D:"sdr"}[op]} ${REG[rt]}, {imm}(${REG[rs]})'
    if op==0 and fn==0x27:return f'nor ${REG[rd]}, ${REG[rs]}, ${REG[rt]}'
    return result


def main():
    path=ROOT/'build-function-index/owned-overlays/o5.bin'
    raw=path.read_bytes();sha=lambda b:hashlib.sha256(b).hexdigest()
    assert sha(raw)==SHA
    inv=json.loads((ROOT/'build-function-index/dnas-o5-family-recovery-inventory.json').read_text())
    assert inv['image_sha256']==SHA
    spans={int(r['start'],16):r for r in inv['spans']}
    read=lambda a,n:struct.unpack_from('<'+'I'*n,raw,a-BASE)
    pack=lambda ws:struct.pack('<'+'I'*len(ws),*ws)
    jal=lambda a:0x0C000000|(a>>2)
    lui=lambda reg,a:0x3C000000|(reg<<16)|((a+0x8000)>>16)
    addiu=lambda reg,a:0x24000000|(reg<<21)|(reg<<16)|(a&65535)
    assert read(0x700770,1)==(19,)
    metadata={}
    for i in range(19):
        key,offset=read(0x700774+8*i,2);relative,count=read(0x70080C+offset,2)
        metadata[key>>1]=(relative,set(read(0x700814+offset,count)))
    receipts=[];listing=[]
    for owner,start,owner_end in OWNERS:
        r=spans[start];end=int(r['end_exclusive'],16)
        assert r['dispatcher']=='0x700b18'
        h,rest=read(start-20,5),read(end+32,4)
        assert h[0]==h[4]==rest[3]==0 and h[2]&1==0 and rest[1]==h[2]+1
        assert h[1]^h[3]==rest[0]^rest[2]==end-start
        assert read(start-96,13)==(lui(3,start-20),addiu(3,start-20),0x8C620000,0x14400007,0,
            lui(4,start),addiu(4,start),0x8C670008,0x8C65000C,jal(0x700B18),0x8C660004,0x1000000C,0)
        assert read(end+48,8)==(lui(2,end+32),addiu(2,end+32),lui(4,end),addiu(4,end),
            0x8C470004,0x8C450008,jal(0x700B18),0x8C460000)
        relative,exceptions=metadata[h[2]>>1] if h[2]>>1 else (0,set())
        source=list(read(start,(end-start)//4));eligible=[(relative+4*i)&0xFFFFFFFF not in exceptions for i in range(len(source))]
        words=list(source)
        for slot in schedule(h[1]):words=[transform(w,slot,True) if eligible[i] else w for i,w in enumerate(words)]
        assert [f'{w:08X}'for w in words]==r['candidate_words']
        assert sha(pack(source))==r['original_sha256'] and sha(pack(words))==r['candidate_sha256']
        restored=list(words)
        assert schedule(rest[0])==tuple(reversed(schedule(h[1])))
        for slot in schedule(rest[0]):restored=[transform(w,slot,False) if eligible[i] else w for i,w in enumerate(restored)]
        assert restored==source
        original=raw[owner-BASE:owner_end-BASE];candidate=bytearray(original)
        candidate[start-owner:end-owner]=pack(words)
        word=lambda pc:struct.unpack_from('<I',candidate,pc-owner)[0]
        excluded=set(range(start-44,start,4))|set(range(end+8,end+48,4))
        literals=[]
        if owner in (0x7035B8,0x7042A0):
            assert word(start)==0x10000008 and word(start+4)==0
            excluded.update(range(start+8,start+36,4))
            literals.append(dict(address=hex(start+16),text=bytes(candidate[start+16-owner:start+36-owner]).rstrip(b'\0').decode()))
        allowed=set(range(owner,owner_end,4))-excluded
        branches=[];unknown=[];calls=[]
        for pc in sorted(allowed):
            w=word(pc);op,rs=w>>26,(w>>21)&31
            text=decoded(pc,w)
            if 'UNDECODED' in text:unknown.append((hex(pc),hex(w)))
            if op in (1,4,5,6,7,20,21,22,23) or (op==17 and rs==8):
                imm=w&65535;imm=imm-65536 if imm&32768 else imm
                target=pc+4+4*imm
                assert target in allowed and pc+4 in allowed,(hex(owner),hex(pc),hex(target))
                branches.append(dict(pc=hex(pc),target=hex(target),delayWord=f'{word(pc+4):08X}'))
            if op==3:
                assert pc+4 in allowed
                calls.append(dict(pc=hex(pc),target=hex(((pc+4)&0xF0000000)|((w&0x3FFFFFF)<<2)),delayWord=f'{word(pc+4):08X}'))
        assert not unknown,unknown
        if owner==0x702350:
            targets=read(0x711890,8)
            assert targets==(0x702418,0x70243C,0x70243C,0x70243C,0x702494,0x702470,0x702494,0x702494)
            assert set(targets)<=allowed
        assert word(owner_end-8)==0x03E00008 and word(owner_end-4)>>16==0x27BD
        listing.append(f'\nOWNER {owner:08X}..{owner_end:08X}')
        listing.extend(f'{pc:08X}: {word(pc):08X} '+('SKIPPED DATA / DESCRIPTOR' if pc in excluded else decoded(pc,word(pc)))for pc in range(owner,owner_end,4))
        receipts.append(dict(owner=hex(owner),endExclusive=hex(owner_end),payload=hex(start),payloadEndExclusive=hex(end),
            originalOwnerSha256=sha(original),candidateOwnerSha256=sha(candidate),
            originalPayloadSha256=r['original_sha256'],candidatePayloadSha256=r['candidate_sha256'],
            candidateWords=r['candidate_words'],preservedExceptions=sum(not x for x in eligible),
            entryCall=hex(start-60),restoreCall=hex(end+72),actualEntryAndRestoreArgumentsVerified=True,
            metadataPairedRestoreExact=True,literals=literals,branches=branches,calls=calls,
            admittedInstructionWords=len(allowed),unrecognizedInstructionFields=unknown))
    assert sha(path.read_bytes())==SHA
    out=ROOT/'build-function-index/dnas-o5-services-review';out.mkdir(exist_ok=True)
    result=dict(image='o5',imageSha256=SHA,owners=receipts,totalOwners=len(receipts),
        payloadWords=sum(len(r['candidateWords'])for r in receipts),preservedExceptions=sum(r['preservedExceptions']for r in receipts),
        admittedInstructionWords=sum(r['admittedInstructionWords']for r in receipts),checkedDirectBranches=sum(len(r['branches'])for r in receipts),
        noGuestExecutionOrEmulation=True,ownedInputUnchanged=True,
        limitation='Static data/branch/entry/restore binding only; semantic interpretation is the separate human connected-body review. A paired restore need not be reached on every early exit.')
    (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    (out/'words.txt').write_text('\n'.join(listing)+'\n',encoding='utf-8')
    print({k:result[k]for k in ('totalOwners','payloadWords','preservedExceptions','admittedInstructionWords','checkedDirectBranches')})


if __name__=='__main__':main()
