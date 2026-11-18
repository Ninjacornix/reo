#!/usr/bin/env python3
"""Read owned static words for media-purpose evidence; never execute a target.

Literal/J/JAL matches are candidates only, including possible encoded/data hits.
This deliberately does not infer missing indirect registrations from no matches.
"""
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct

from index import Elf

ROOT=Path(__file__).resolve().parents[2]
SHA='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
TARGETS=(0x122E40,0x122E90,0x122FF0,0x1230B0,0x12CC50,0x132FF8,
         0x124F08,0x12D850,0x124F68,0x12D9B8,0x132890,0x136578)
PRODUCERS=(0x12CBC0,0x134BC0,0x1249E8,0x126AC8,0x126D28,0x12FC28,
           0x12F090,0x12F9C0,0x12FBA8,0x135488,0x136F98,0x131088,0x131338,
           0x13A180,0x13BCF0)


def main():
    elf=Elf(ROOT/'game_data/SLUS_207.65')
    assert elf.sha256==SHA
    sha=lambda b:hashlib.sha256(b).hexdigest()
    db=sqlite3.connect(f'file:{ROOT / "build-function-index/index.sqlite"}?mode=ro',uri=True)
    records=[]
    for entry in (*TARGETS,*PRODUCERS):
        end,source=db.execute("select end,source from functions where image='main' and start=?",(entry,)).fetchone()
        original=elf.read(entry,end-entry)
        assert original is not None
        comment_words={int(a,16):int(w,16) for a,w in re.findall(r'// 0x([0-9a-f]+): 0x([0-9a-f]+)\s+',
            (ROOT/source).read_text(encoding='utf-8'),re.I) if entry<=int(a,16)<end}
        for pc,w in comment_words.items():assert elf.read(pc,4)==struct.pack('<I',w)
        omitted=[pc for pc in range(entry,end,4) if pc not in comment_words]
        assert all(elf.read(pc,4)==b'\0'*4 for pc in omitted)
        records.append(dict(entry=hex(entry),endExclusive=hex(end),source=source,
            originalSha256=sha(original),verifiedCommentWords=len(comment_words),omittedZeroWords=len(omitted)))
    callbacks=(0x20B718,0x20B71C,0x20B720,0x20B728,0x20B72C,0x20B730,0x20B734)
    callback_values={hex(a):hex(struct.unpack('<I',elf.read(a,4))[0]) for a in callbacks}
    assert set(callback_values.values())=={'0x0'}
    interfaces=[]
    for a in (0x21CBF8,0x21DA88):
        raw=elf.read(a,104);words=struct.unpack('<26I',raw)
        assert words[0x44//4]==0
        interfaces.append(dict(address=hex(a),sha256=sha(raw),method44=hex(words[17]),method60=hex(words[24]),
            all26Words=[f'{w:08X}'for w in words]))
    # Original disc-owned IOP module container. Read one bounded member, never
    # load or execute a module. Keep every module identity and debug-type hit.
    iso=ROOT/'iso/Resident Evil - Outbreak (v2.00).iso'
    with iso.open('rb')as stream:
        stream.seek(1212*2048);container=stream.read(356544)
    assert sha(container)=='6ac9f10940514fe0d54139498de87d432a4e84db499aa5f07e53ad5889d92c79'
    assert container[:8]==b'MUU-\x0b\0\0\0'
    modules=[]
    for i in range(11):
        off,size=struct.unpack_from('<2I',container,8+8*i);module=container[off:off+size]
        assert len(module)==size and module[:4]==b'\x7fELF'
        h=struct.unpack_from('<HHIIIIIHHHHHH',module,16)
        sections=[struct.unpack_from('<10I',module,h[5]+j*h[10])for j in range(h[11])]
        modinfo=[];symbols=[]
        for s in sections:
            if s[1]==0x70000080:modinfo.append(module[s[4]:s[4]+s[5]].hex())
            if s[1]!=2:continue
            st=sections[s[6]];strings=module[st[4]:st[4]+st[5]]
            for p in range(s[4],s[4]+s[5],16):
                no,value,n,info,other,index=struct.unpack_from('<IIIBBH',module,p)
                name=strings[no:].split(b'\0')[0].decode('ascii','replace')
                if name:symbols.append(name)
        strings=[s.decode('ascii')for s in re.findall(rb'[ -~]{5,}',module)]
        pattern=re.compile(r'cvfs|CVDV|CVHT|GetNumFiles|GetFileList',re.I)
        modules.append(dict(index=i,offset=hex(off),bytes=size,sha256=sha(module),moduleInfoHex=modinfo,
            symbolCount=len(symbols),cvfsSymbolOrTypeMatches=[s for s in (*symbols,*strings)if pattern.search(s)],
            loaderFileCallbackTypes=[s for s in strings if s.startswith('_ldfilefunc:')]))
    assert all(not m['cvfsSymbolOrTypeMatches']for m in modules)
    images=[]
    for base,off,size in elf.segments:images.append(('main',base,elf.data[off:off+size]))
    identities=json.loads((ROOT/'tools/function_index/overlay_identities.json').read_text(encoding='utf-8'))
    for item in identities['images']:
        raw=(ROOT/f'build-function-index/owned-overlays/{item["image"]}.bin').read_bytes()
        assert sha(raw)==item['imageSha256']
        images.append((item['image'],item['base'],raw))
    matches=[];image_receipts=[]
    target_set=set(TARGETS)
    for name,base,raw in images:
        image_receipts.append(dict(image=name,base=hex(base),bytes=len(raw),sha256=sha(raw)))
        for i in range(0,len(raw)-3,4):
            w=struct.unpack_from('<I',raw,i)[0];pc=base+i
            if w in target_set:matches.append(dict(image=name,site=hex(pc),target=hex(w),kind='aligned literal candidate'))
            if w>>26 in (2,3):
                target=((pc+4)&0xF0000000)|((w&0x3FFFFFF)<<2)
                if target in target_set:matches.append(dict(image=name,site=hex(pc),target=hex(target),kind='original J/JAL field candidate'))
    recovered=[]
    for filename in ('dnas-primary-recovery-inventory.json','dnas-upper-recovery-inventory.json','dnas-o5-family-recovery-inventory.json'):
        path=ROOT/'build-function-index'/filename
        if not path.exists():continue
        inv=json.loads(path.read_text(encoding='utf-8'));count=0
        for span in inv['spans']:
            base=int(span['start'],16)
            for i,text in enumerate(span['candidate_words']):
                w=int(text,16);pc=base+4*i;count+=1
                if w in target_set:matches.append(dict(image=inv['image'],site=hex(pc),target=hex(w),kind='reconstructed literal candidate',inventory=filename))
                if w>>26 in (2,3):
                    target=((pc+4)&0xF0000000)|((w&0x3FFFFFF)<<2)
                    if target in target_set:matches.append(dict(image=inv['image'],site=hex(pc),target=hex(target),kind='reconstructed J/JAL field candidate',inventory=filename))
        recovered.append(dict(inventory=filename,inventorySha256=sha(path.read_bytes()),candidateWordsScanned=count))
    assert sha((ROOT/'game_data/SLUS_207.65').read_bytes())==SHA
    out=ROOT/'build-function-index/main-media-purpose-evidence.json'
    out.write_text(json.dumps(dict(elfSha256=SHA,targets=[hex(a)for a in TARGETS],completeOriginalBodies=records,
        callbackInitialWords=callback_values,ownedCvfsInterfaces=interfaces,ownedImages=image_receipts,
        iopContainer=dict(isoMember='/IOP/MODULES/DRIVE.DAT',lba=1212,bytes=len(container),sha256=sha(container),modules=modules),
        recoveredInventories=recovered,referenceCandidates=matches,noGuestExecution=True,
        limitations='Aligned literals and raw J/JAL fields are candidates, not proven live edges. No-match results do not rule out computed callbacks, relocation, unowned plugins or runtime registration. CVFS method44/selector4 still needs a concrete implementing provider.'),indent=2)+'\n',encoding='utf-8')
    print(f'{len(records)} complete original bodies verified; {len(images)} owned image ranges and {sum(r["candidateWordsScanned"]for r in recovered)} reconstructed words scanned; {len(matches)} reference candidates; no target activity.')


if __name__=='__main__':main()
