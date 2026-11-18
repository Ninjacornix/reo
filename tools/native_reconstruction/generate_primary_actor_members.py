"""Extract exact primary appearance aliases from the owned File 1 executable."""
import argparse,hashlib,json,re,struct
from pathlib import Path
from audit_retail_effect_descriptors import elf_reader,compare_source
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());rows=[]
    source=ROOT/'recomp/config/output/sub_001AA740_0x1aa740.cpp';proof=compare_source('complete primary model appearance loader',source.relative_to(ROOT).as_posix(),0x1aa740,0x1aaad0,read)
    for ordinal in range(1342):
        at=struct.unpack('<I',read(0x2322c0+4*ordinal,4))[0];raw=bytearray()
        for index in range(256):
            value=read(at+index,1)[0]
            if not value:break
            raw.append(value^255)
        else:raise ValueError('Unbounded ROM alias')
        alias=raw.decode('ascii');match=re.fullmatch(r'COMMON_PL_((EP|P)(\d+)_(\d+)|HP(\d+))_NBD',alias)
        if match:
            hp=match[5]is not None
            rows.append(dict(name=match[1]+'.NBD',member=ordinal,alias=alias,character=int(match[5]if hp else match[3]),appearance=0 if hp else int(match[4]),model_class=1 if hp else 0 if match[2]=='P'else 2))
    assert len(rows)==46 and len({row['name']for row in rows})==46 and all(row['character']<8 and row['appearance']<3 for row in rows)
    text='// Exact File1 primary appearance aliases from the executable ROM table.\nstruct PrimaryActorMember {std::string_view name;std::uint16_t ordinal;};\nconstexpr std::array<PrimaryActorMember,46> primary_actor_members{{\n'+''.join('    {"'+row['name']+'",'+str(row['member'])+'},\n'for row in rows)+'}};\n'
    target=ROOT/'game/native/gameplay_world/primary_actor_members.inc'
    if target.exists():assert target.read_text()==text
    else:target.write_text(text)
    out.mkdir();(out/'receipt.json').write_text(json.dumps(dict(schema=1,status='passed',source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},elf_sha256=sha(elf),original_owned_body=proof,rows=rows,output_sha256=sha(target),game_run=False),indent=2)+'\n');print(json.dumps(dict(status='passed',members=len(rows),output_sha256=sha(target))))
if __name__=='__main__':main()
