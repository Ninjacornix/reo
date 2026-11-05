#!/usr/bin/env python3
"""Reproduce sixteen original kernel/DECI2 wrapper and registration reviews.

No target execution, emulator, process attachment, build or shared-index writes.
Optional reference retrieval only fetches fixed public PS2SDK source revisions.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct
import urllib.request

from index import Elf,ELF_SHA
from review_dnas_proxy_first_owner_groups import fields as ordinary_fields
from recover_dnas_zero_upper import REG

ROOT=Path(__file__).resolve().parents[2]
OLD='af212628b7a3b4f7197675c7236d6bec849c883b'
DECI='e1d1c084fd21a8ac69941f16e2000c2b919d3b1f'
REFERENCES=(
    (OLD,'ee/kernel/include/syscallnr.h','573f0c3276eaae064f0da04990126133b434259b3b235e53ed8f013694300edc'),
    (OLD,'ee/kernel/src/kernel.S','81e16f24d565ce07060f3211b33c8e006e8907dffac585190a95af1ebea012ab'),
    (OLD,'ee/kernel/include/kernel.h','c44a1ca9281e491f3ac4ed5b408382cd96c68dd5ae391cd145314d393c5df4b5'),
    (OLD,'ee/kernel/src/alarm.c','685b7f11502eb08f42f2955e33e9388dd814b17981c49ccaae7b79cf4b744136'),
    (OLD,'ee/kernel/src/srcfile/src/srcfile.c','8d1add6a6ba8574da83a87424444f2d89e79f9184fb5dd739037befe9216d9c6'),
    (DECI,'ee/kernel/src/deci2.c','64fbda73ad8617c5f3ce60ca80ea013f2e0f0291e970bf56e792fde408003a5d'),
    (DECI,'ee/kernel/include/deci2.h','fb30f073d9cbfc37eca1401f082f6348c1de141edd441773475ad857b5d5a09e'),
)
KERNEL={0x114200:0,0x114230:3,0x114290:9,0x1143B0:0xFD,0x114400:-0xFE,
        0x1145D0:0x3B,0x114610:0x3F,0x1146B0:0x49,0x114750:-0x53,0x1147C0:-0x5A}
DECI2={0x1157B8:2,0x115838:0x20,0x115868:0x21,0x115900:-7,0x115930:-8,0x115958:-9}
SUPPORTED={0x1143B0,0x114400,0x1146B0,0x114750,0x1147C0,0x1157B8,0x115900,0x115930,0x115958}


def fields(pc,w):
    text=ordinary_fields(pc,w)
    if 'UNDECODED' not in text:return text
    op,rs,rt,rd,fn=w>>26,(w>>21)&31,(w>>16)&31,(w>>11)&31,w&63
    if op==0 and fn==0xF:return f'sync type{(w>>6)&31}'
    if op==0 and fn in (0x14,0x16):return f'{"dsllv" if fn==0x14 else "dsrlv"} ${REG[rd]}, ${REG[rt]}, ${REG[rs]}'
    if op==0 and fn==0x27:return f'nor ${REG[rd]}, ${REG[rs]}, ${REG[rt]}'
    if w==0xC:return 'syscall 0'
    return text


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--fetch-references',action='store_true')
    args=parser.parse_args()
    directory=ROOT/'build-function-index/references/proxy-kernel-purpose'
    directory.mkdir(parents=True,exist_ok=True)
    references=[];sources={}
    for revision,path,expected in REFERENCES:
        filename=directory/path.replace('/','__')
        url=f'https://raw.githubusercontent.com/ps2dev/ps2sdk/{revision}/{path}'
        if args.fetch_references:
            candidate=urllib.request.urlopen(url,timeout=30).read()
            assert hashlib.sha256(candidate).hexdigest()==expected
            filename.write_bytes(candidate)
        if not filename.exists() and path.endswith('/syscallnr.h'):
            filename=ROOT/'build-function-index/references/syscallnr.h'
        data=filename.read_bytes()
        assert hashlib.sha256(data).hexdigest()==expected,(path,'reference hash mismatch')
        sources[path]=data.decode('utf-8')
        references.append(dict(revision=revision,path=path,url=url,sha256=expected))
    deci=sources['ee/kernel/src/deci2.c']
    for name,operation in [('sceDeci2Close',2),('sceDeci2ExReqSend',-7),('sceDeci2ExLock',-8),('sceDeci2ExUnLock',-9)]:
        body=re.search(r'int '+name+r'\([^)]*\)\s*\{(.*?)\}',deci,re.S)[1]
        assert f'Deci2Call({operation}, args)' in body
    assert 'Deci2Call(32,' not in deci and 'Deci2Call(33,' not in deci
    kernel=sources['ee/kernel/src/kernel.S']
    assert all(word in kernel for word in ('subu        $26, $0, $3','movn        $3, $26, $2','sll         $3, $3, 2'))
    elf=Elf(ROOT/'game_data/SLUS_207.65')
    read=lambda a,n:struct.unpack('<'+'I'*n,elf.read(a,4*n))
    db=sqlite3.connect('file:'+(ROOT/'build-function-index/index.sqlite').as_posix()+'?mode=ro',uri=True)
    db.row_factory=sqlite3.Row
    cases=[];verified=omitted=0
    for address in sorted(set(KERNEL)|set(DECI2)):
        row=db.execute('select * from functions where image=? and start=?',('main',address)).fetchone()
        assert row is not None
        words=read(address,(row['end']-address)//4)
        comments={int(m[1],16):int(m[2],16) for m in re.finditer(r'// 0x([0-9a-f]+): 0x([0-9a-f]+)\s',(ROOT/row['source']).read_text(),re.I)
                  if address<=int(m[1],16)<row['end']}
        for i,w in enumerate(words):
            pc=address+4*i
            if pc in comments:assert comments[pc]==w;verified+=1
            else:assert w==0;omitted+=1
        if address in KERNEL:
            assert words==(0x24030000|(KERNEL[address]&65535),0xC,0x03E00008,0)
        else:
            assert words.count(0x0C000000|(0x114A50>>2))==1
            assert (0x24040000|(DECI2[address]&65535)) in words
            assert words[-3] in (0xDFBF0010,0xDFBF0020) and words[-2]==0x03E00008
        text=[dict(pc=hex(address+4*i),word=f'{w:08X}',fields=fields(address+4*i,w)) for i,w in enumerate(words)]
        assert not any('UNDECODED' in w['fields'] for w in text)
        cases.append(dict(entry=hex(address),end_exclusive=hex(row['end']),source=row['source'],
            selector=KERNEL.get(address,DECI2.get(address)),supported_purpose_candidate=address in SUPPORTED,
            original_sha256=hashlib.sha256(elf.read(address,row['end']-address)).hexdigest(),words=text,
            indexed_callers=[dict(e) for e in db.execute('select caller,site,kind from edges where target=?',(address,))]))
    assert read(0x114A50,4)==(0x2403007C,0xC,0x03E00008,0)
    # The original copied payload has an older alarm selector ordering than SDK.
    pairs=[read(0x20B350+8*i,2) for i in range(6)]
    assert pairs==[(0xFC,0x80076440),(0xFE,0x80076440),(0xFD,0x800762A0),
                   (0xFF,0x800762A0),(0x12C,0x80076488),(8,0x800766C0)]
    assert read(0x20AC40,3)==(0x3C028007,0x0000282D,0x24436710)
    assert read(0x20B080,8)==(0x27BDFFF0,0xFFBF0000,0x0C01D858,0x3084FFFF,0xF,0xDFBF0000,0x03E00008,0x27BD0010)
    dependencies=[]
    for start,end in ((0x20AC40,0x20AC78),(0x20ADA0,0x20AEE0),(0x20AEE0,0x20B080),(0x20B080,0x20B0A0)):
        words=[dict(pc=hex(a),word=f'{read(a,1)[0]:08X}',fields=fields(a,read(a,1)[0])) for a in range(start,end,4)]
        assert not any('UNDECODED' in w['fields'] for w in words)
        dependencies.append(dict(start=hex(start),end_exclusive=hex(end),
            original_sha256=hashlib.sha256(elf.read(start,end-start)).hexdigest(),words=words,
            no_additional_mapping_credit=True))
    # Raw pointer and direct J/JAL patterns, explicitly not inferred execution.
    chunks=[('main',base,elf.data[offset:offset+size]) for base,offset,size in elf.segments]
    identities=json.loads((ROOT/'tools/function_index/overlay_identities.json').read_text())['images']
    for ident in identities:
        data=(ROOT/f'build-function-index/owned-overlays/{ident["image"]}.bin').read_bytes()
        assert hashlib.sha256(data).hexdigest()==ident['imageSha256']
        chunks.append((ident['image'],ident['base'],data))
    wanted={}
    for a in sorted(set(KERNEL)|set(DECI2)):
        for pattern,kind in ((a,'literal pointer pattern'),(0x08000000|(a>>2),'J pattern'),(0x0C000000|(a>>2),'JAL pattern')):
            wanted[pattern]=(a,kind)
    hits=[]
    for image,base,data in chunks:
        for offset in range(0,len(data)-3,4):
            w=struct.unpack_from('<I',data,offset)[0]
            if w in wanted:
                target,kind=wanted[w]
                hits.append(dict(image=image,address=hex(base+offset),target=hex(target),kind=kind))
    out=ROOT/'build-function-index/proxy-main-kernel-deci2-purpose-review.json'
    out.write_text(json.dumps(dict(schema=1,image_sha256=ELF_SHA,cases=cases,references=references,
        verified_source_comment_words=verified,omitted_zero_words=omitted,owned_alarm_dispatch_pairs=pairs,
        dependencies=dependencies,unfiltered_raw_pointer_and_jump_patterns=hits,
        limitation='Original wrappers and registration evidence only. Signed variants retain sign. '
        'External API identities are qualified; unknown RFU/DECI2 extension purposes receive no semantic credit. '
        'No execution, process attachment, build, original/generated mutation or shared-index writes.'),indent=2)+'\n',encoding='utf-8')
    db.close()
    assert hashlib.sha256((ROOT/'game_data/SLUS_207.65').read_bytes()).hexdigest()==ELF_SHA
    print(dict(entries=len(cases),supported_purpose_candidates=len(SUPPORTED),unresolved=16-len(SUPPORTED),
        verified_source_comment_words=verified,omitted_zero_words=omitted,raw_patterns=len(hits)))


if __name__=='__main__':main()
