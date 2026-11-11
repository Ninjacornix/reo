"""Extract resident auxiliary NPC model aliases, independently of primary substitution."""
import argparse,hashlib,json,re,struct
from pathlib import Path
from audit_retail_effect_descriptors import elf_reader,compare_source
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());rows=[]
    proofs=[]
    for start,end in [(0x1d0800,0x1d0914),(0x1cf300,0x1cf320),(0x1cf090,0x1cf300),(0x1cf320,0x1cf560),(0x1cd710,0x1cdda0),(0x1cd340,0x1cd3f0)]:
        source=ROOT/f'recomp/config/output/sub_{start:08X}_0x{start:x}.cpp'
        proofs.append(compare_source('complete resident NPC model routing body',source.relative_to(ROOT).as_posix(),start,end,read))
    for ordinal in range(1342):
        at=struct.unpack('<I',read(0x2322c0+4*ordinal,4))[0];raw=bytearray()
        for n in range(256):
            value=read(at+n,1)[0]
            if not value:break
            raw.append(value^255)
        else:raise ValueError('Unbounded ROM alias')
        alias=raw.decode('ascii');match=re.fullmatch(r'COMMON_NPC_((HN|N)(\d+))_NBD',alias)
        if match:rows.append(dict(name=match[1]+'.NBD',member=ordinal,alias=alias,id=int(match[3]),model_class=1 if match[2]=='HN' else 0))
    assert len(rows)==233 and len({r['name']for r in rows})==233
    assert all(r['id']<256 for r in rows)
    text='// Exact resident File1 auxiliary NPC model aliases; raw low-byte identities.\n'
    text+='struct AuxiliaryActorMember {std::string_view name;std::uint16_t ordinal;};\nconstexpr std::array<AuxiliaryActorMember,233> auxiliary_actor_members{{\n'+''.join('    {"'+r['name']+'",'+str(r['member'])+'},\n'for r in rows)+'}};\n'
    target=ROOT/'game/native/gameplay_world/auxiliary_actor_members.inc'
    if target.exists():assert target.read_text()==text
    else:target.write_text(text)
    out.mkdir();receipt=dict(schema=1,status='passed',source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},elf_sha256=sha(elf),original_owned_bodies=proofs,rows=rows,output_sha256=sha(target),game_run=False)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',members=len(rows),output_sha256=sha(target))))
if __name__=='__main__':main()
