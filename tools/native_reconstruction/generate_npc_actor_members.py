"""Extract exact File1 NPC/HP ROM ordinals; display basenames may collide."""
import argparse,hashlib,json,re,struct
from pathlib import Path
from audit_retail_effect_descriptors import elf_reader
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());aliases=[];rows=[]
    for ordinal in range(1342):
        at=struct.unpack('<I',read(0x2322c0+4*ordinal,4))[0];raw=bytearray()
        for n in range(256):
            value=read(at+n,1)[0]
            if not value:break
            raw.append(value^255)
        else:raise ValueError('Unbounded ROM alias')
        alias=raw.decode('ascii');aliases.append(alias);match=re.fullmatch(r'COMMON_(NPC_(N\d+)|PL_(HP\d+))_NBD',alias)
        if match:rows.append(dict(name=(match[2]or match[3])+'.NBD',member=ordinal,alias=alias))
    assert len(set(aliases))==1342 and len(rows)==133 and len({r['name']for r in rows})==133
    text='// Exact owned File1 ROM aliases; duplicate display names are not identities.\n'
    text+='struct NpcActorMember {std::string_view name;std::uint16_t ordinal;};\nconstexpr std::array<NpcActorMember,133> npc_actor_members{{\n'+''.join('    {"'+r['name']+'",'+str(r['member'])+'},\n'for r in rows)+'}};\n'
    target=ROOT/'game/native/gameplay_world/npc_actor_members.inc'
    if target.exists():assert target.read_text()==text
    else:target.write_text(text)
    out.mkdir();receipt=dict(schema=1,status='passed',source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},elf_sha256=sha(elf),rows=rows,aliases_sha256=hashlib.sha256('\n'.join(aliases).encode()).hexdigest(),output_sha256=sha(target),game_run=False)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',members=len(rows),output_sha256=sha(target))))
if __name__=='__main__':main()
