"""Reproduce exact File1 common/character base motion aliases and loader authority."""
import argparse,hashlib,json,re,struct
from pathlib import Path
from audit_retail_effect_descriptors import elf_reader,compare_source
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());rows=[];proof=[]
    for start in [0x1d1a80,0x1d1b10,0x1d19d0,0x1d1940]:
        source=ROOT/f'recomp/config/output/sub_{start:08X}_0x{start:x}.cpp';begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',source.read_text()).groups()]
        proof.append(compare_source('complete source body containing common/character motion loader',source.relative_to(ROOT).as_posix(),begin,end,read))
    for ordinal in range(1342):
        at=struct.unpack('<I',read(0x2322c0+4*ordinal,4))[0];raw=bytearray()
        for n in range(256):
            value=read(at+n,1)[0]
            if not value:break
            raw.append(value^255)
        else:raise ValueError('Unbounded ROM alias')
        alias=raw.decode('ascii');match=re.fullmatch(r'MOTION_PLAYER_(PC_(\d+)|PL(\d+)_PC_000)_BIN',alias)
        if match:
            character=int(match[3])if match[3]else 255;index=int(match[2])if match[2]else 0
            rows.append(dict(name=alias.removeprefix('MOTION_PLAYER_').removesuffix('_BIN')+'.BIN',member=ordinal,alias=alias,index=index,character=character))
    assert len(rows)==98 and sum(row['character']==255 for row in rows)==90 and {row['character']for row in rows if row['character']!=255}==set(range(8))
    text='// Exact owned File1 common and character-base motion ROM ordinals.\n'
    text+='constexpr std::array<HumanoidMotionMember,98> humanoid_motion_members{{\n'+''.join('    {'+str(r['index'])+','+str(r['character'])+','+str(r['member'])+',"'+r['name']+'"},\n'for r in rows)+'}};\n'
    target=ROOT/'game/native/gameplay_world/humanoid_motion_members.inc'
    if target.exists():assert target.read_text()==text
    else:target.write_text(text)
    out.mkdir();receipt=dict(schema=1,status='passed',source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},elf_sha256=sha(elf),original_owned_bodies=proof,rows=rows,output_sha256=sha(target),game_run=False)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',members=len(rows),output_sha256=sha(target))))
if __name__=='__main__':main()
