#!/usr/bin/env python3
"""Verify original o5 transform families and metadata as read-only static data.

No instruction execution or emulation. Compares all original primitive words
against independently reviewed o4 bodies, admitting only the explicit predicate
JAL relocation. Saves original words/hashes and the exact unsorted metadata.
"""
import hashlib
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[2]
BASE = 0x6E0000
O4_SHA = '8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16'
O5_SHA = '97174f5d367cd90bedd5ba397c6492e9fb4bbd0ec7d6021c2be524c49925d38e'
FWD = (0x745AD8,0x745B78,0x745C18,0x745CC8,0x745D78,0x745E50,0x745F10,0x746010)
INV = (0x746200,0x7462A0,0x746340,0x746400,0x7464C0,0x746598,0x746670,0x746780)
FWD_WORDS = (40,40,43,43,53,47,64,69)
INV_WORDS = (40,40,47,47,53,53,67,74)
TABLES = (
    (0x709D08,False,0x6E29B8,(0x6E2B38,0x6E2BD8,0x6E2C78,0x6E2D28,0x6E2DD8,0x6E2EB0,0x6E2F70,0x6E3070)),
    (0x709D28,True, 0x6E29B8,(0x6E3260,0x6E3300,0x6E33A0,0x6E3460,0x6E3520,0x6E35F8,0x6E36D0,0x6E37E0)),
    (0x70B7B0,False,0x700CA8,(0x700E28,0x700EC8,0x700F68,0x701018,0x7010C8,0x7011A0,0x701260,0x701360)),
    (0x70B7D0,True, 0x700CA8,(0x701550,0x7015F0,0x701690,0x701750,0x701810,0x7018E8,0x7019C0,0x701AD0)),
    (0x711220,True, 0x7087E8,(0x6FA178,0x6FA218,0x6FA2B8,0x6FA378,0x6FA438,0x6F9E68,0x6F9F40,0x6FA050)),
    (0x711240,False,0x7087E8,(0x6FD0F0,0x6FD190,0x709468,0x709518,0x7095C8,0x6FCE18,0x6FCED8,0x6FCFD8)),
)
FAMILIES = (
    # dispatcher, lookup, predicate, normalizer, mode0 sequence, mode1 sequence,
    # mode0 table, mode1 table, metadata count table, actual count
    (0x6E2828,0x6E2900,0x6E29B8,0x6E29F8,0x6E3188,0x6E2A60,0x709D28,0x709D08,0x7096A0,18),
    (0x700B18,0x700BF0,0x700CA8,0x700CE8,0x701478,0x700D50,0x70B7D0,0x70B7B0,0x700770,19),
    (0x708E18,0x708EF0,0x7087E8,0x708828,0x708890,0x708FA8,0x711220,0x711240,0x708968,30),
)


def main():
    paths = [ROOT/'build-function-index/owned-overlays'/name for name in ('o4.bin','o5.bin')]
    reference, raw = [p.read_bytes() for p in paths]
    sha = lambda b:hashlib.sha256(b).hexdigest()
    assert sha(reference)==O4_SHA and sha(raw)==O5_SHA
    def read(a,n,image=raw):
        assert BASE<=a and a-BASE+4*n<=len(image)
        return struct.unpack_from('<'+'I'*n,image,a-BASE)
    pack = lambda words:struct.pack('<'+'I'*len(words),*words)
    jal = lambda a:0x0C000000|(a>>2)
    lui = lambda reg,a:0x3C000000|(reg<<16)|((a+0x8000)>>16)
    addiu = lambda dest,src,a:0x24000000|(src<<21)|(dest<<16)|(a&65535)
    primitive_receipts=[]
    for table,inverse,predicate,targets in TABLES:
        assert read(table,8)==targets
        for slot,(target,ref,n) in enumerate(zip(targets,INV if inverse else FWD,INV_WORDS if inverse else FWD_WORDS)):
            words, ref_words=read(target,n),read(ref,n,reference)
            differences=[i for i,(a,b) in enumerate(zip(words,ref_words)) if a!=b]
            assert len(differences)==1
            i=differences[0]
            assert words[i]==jal(predicate) and ref_words[i]==jal(0x745958)
            primitive_receipts.append(dict(table=hex(table),inverseWordOperation=inverse,slot=slot,
                                           entry=hex(target),endExclusive=hex(target+4*n),words=n,
                                           sha256=sha(pack(words)),referenceO4Entry=hex(ref),
                                           soleRelocatedCall=hex(target+4*i),predicate=hex(predicate),
                                           allOtherWordsExactlyEqual=True,originalWords=[f'{w:08X}' for w in words]))
    family_receipts=[]
    first=FAMILIES[0]
    ref_dispatch=read(first[0],54)
    ref_lookup=read(first[1],46)
    ref_predicate=read(first[2],16)
    ref_normalizer=read(first[3],26)
    ref_sequence=read(first[4],54)
    for dispatcher,lookup,predicate,normalizer,mode0,mode1,table0,table1,metadata,count in FAMILIES:
        expected=list(ref_dispatch)
        for i,target in ((22,lookup),(30,mode0),(34,lookup),(42,mode1)):
            expected[i]=jal(target)
        assert read(dispatcher,54)==tuple(expected)
        expected=list(ref_lookup);expected[2]=lui(3,metadata);expected[3]=addiu(3,3,metadata)
        assert read(lookup,46)==tuple(expected)
        assert read(predicate,16)==ref_predicate
        assert read(normalizer,26)==ref_normalizer
        for entry,table in ((mode0,table0),(mode1,table1)):
            expected=list(ref_sequence);expected[17]=jal(normalizer)
            expected[23]=lui(2,table);expected[24]=addiu(30,2,table)
            assert read(entry,54)==tuple(expected)
        assert read(metadata,1)==(count,)
        record_base=metadata+4+8*count
        records=[];seen=set()
        for i in range(count):
            key,offset=read(metadata+4+8*i,2)
            assert key>>1 not in seen and offset<0x80000000
            seen.add(key>>1)
            address=record_base+offset
            relative,n=read(address,2)
            values=read(address+8,n)
            records.append(dict(index=i,packedKey=hex(key),keyAfterShift=hex(key>>1),offset=hex(offset),
                                address=hex(address),relativeBase=hex(relative),count=n,
                                exceptionOffsets=[hex(w) for w in values],sha256=sha(pack((relative,n,*values)))))
        support=[]
        for role,entry,n in (('dispatcher',dispatcher,54),('lookup',lookup,46),('predicate',predicate,16),
                             ('normalizer',normalizer,26),('mode0Sequence',mode0,54),('mode1Sequence',mode1,54)):
            words=read(entry,n)
            support.append(dict(role=role,entry=hex(entry),words=n,sha256=sha(pack(words)),originalWords=[f'{w:08X}' for w in words]))
        family_receipts.append(dict(dispatcher=hex(dispatcher),mode0Table=hex(table0),mode1Table=hex(table1),
                                    mode0IsInverse=True,mode1IsInverse=False,metadataTable=hex(metadata),
                                    metadataCount=count,metadataRecordBase=hex(record_base),records=records,
                                    supportFunctions=support))
    assert [sha(p.read_bytes()) for p in paths]==[O4_SHA,O5_SHA]
    out=ROOT/'build-function-index/dnas-o5-family-support-review.json'
    out.write_text(json.dumps(dict(image='o5',imageSha256=O5_SHA,referenceImageSha256=O4_SHA,
                                  primitiveCount=len(primitive_receipts),primitiveWords=sum(p['words'] for p in primitive_receipts),
                                  primitives=primitive_receipts,families=family_receipts,
                                  noGuestExecutionOrEmulation=True,ownedInputsUnchanged=True,
                                  limitations='Original word comparison and metadata reading only. Per-span entry/restore binding, recovered full-owner semantics, concurrency and runtime reachability require separate review.'),indent=2)+'\n',encoding='utf-8')
    print(f'{len(primitive_receipts)} original primitive bodies / {sum(p["words"] for p in primitive_receipts)} words; 3 complete dispatcher/lookup/predicate/normalizer/sequence families; 67 metadata records; owned inputs unchanged; no execution.')


if __name__=='__main__':
    main()
