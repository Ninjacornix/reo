"""Read-only original-opcode audit of generated low-VI CTC2 occurrences."""
import hashlib
import json
from pathlib import Path
import re
import struct

ROOT=Path(__file__).resolve().parents[2]
CANONICAL={**{0x102200+8*n:'sub_00102130_0x102130.cpp' for n in range(16)},
           0x1022F0:'sub_001022C8_0x1022c8.cpp',0x1022F8:'sub_001022C8_0x1022c8.cpp',
           0x102318:'sub_00102308_0x102308.cpp',0x102324:'sub_00102308_0x102308.cpp',
           0x18F37C:'sub_0018F340_0x18f340.cpp',0x18F4AC:'sub_0018F470_0x18f470.cpp',
           0x18F5B0:'sub_0018F570_0x18f570.cpp'}


def main():
    elf=(ROOT/'game_data/SLUS_207.65').read_bytes()
    elf_hash=hashlib.sha256(elf).hexdigest()
    assert elf_hash=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    phoff=struct.unpack_from('<I',elf,28)[0]
    phnum=struct.unpack_from('<H',elf,44)[0]
    segments=[struct.unpack_from('<8I',elf,phoff+n*32) for n in range(phnum)]
    def original(pc):
        for typ,off,va,_,size,_,_,_ in segments:
            if typ==1 and va<=pc<va+size:
                return struct.unpack_from('<I',elf,off+pc-va)[0]
        raise RuntimeError('Original PC outside ELF: '+hex(pc))
    rows={}
    regex=re.compile(r'// 0x([0-9a-f]+): 0x([0-9a-f]+)\s+ctc2[^\n]*\n\s*ctx->pc[^\n]*\n\s*([^\n]*)')
    for path in sorted((ROOT/'recomp/config/output').glob('sub_*.cpp')):
        source=path.read_text()
        for match in regex.finditer(source):
            pc,word=int(match[1],16),int(match[2],16)
            if (word>>11)&31>=16:continue
            assert original(pc)==word
            assert word>>26==0x12 and (word>>21)&31==6
            row=rows.setdefault(pc,{'pc':hex(pc),'word':hex(word),'source_rt':(word>>16)&31,
                                   'destination_vi':(word>>11)&31,'canonical_file':CANONICAL[pc],
                                   'occurrences':[]})
            row['occurrences'].append({'file':path.name,'expression':match[3].strip(),
                                      'canonical':path.name==CANONICAL[pc],
                                      'source_sha256':hashlib.sha256(path.read_bytes()).hexdigest()})
    assert len(rows)==23
    hermite_words=[original(pc) for pc in range(0x18F260,0x18F340,4)]
    assert not any(w>>26==0x12 and (w>>21)&31==6 for w in hermite_words)
    result={'owned_elf_sha256':elf_hash,'unique_low_vi_ctc2':len(rows),
            'generated_occurrences':sum(len(r['occurrences']) for r in rows.values()),
            'hermite':{'range':'0x18F260..0x18F340','ctc2_count':0,'return_pc':'0x18F338',
                       'original_range_sha256':hashlib.sha256(struct.pack('<56I',*hermite_words)).hexdigest()},
            'rows':list(rows.values())}
    output=ROOT/'build-ninja/m2-scenario/low-vi-audit-current.json'
    output.write_text(json.dumps(result,indent=2))
    print(json.dumps({k:v for k,v in result.items() if k!='rows'},indent=2))
    print('Report: '+str(output))


if __name__=='__main__':main()
