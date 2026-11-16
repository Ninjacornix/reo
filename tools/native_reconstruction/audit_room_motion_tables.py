"""Audit owned room-motion selection bodies and all five authored EVB maps.

This is instruction/content provenance, not original execution or game acceptance.
"""
import argparse, hashlib, json, re, struct, sys
from pathlib import Path
from audit_retail_effect_descriptors import compare_source, elf_reader
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc

def sha(data):return hashlib.sha256(data).hexdigest()

def main():
    parser=argparse.ArgumentParser();parser.add_argument('--archive',type=Path,required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    assert not args.output.exists()
    elf=(ROOT/'game_data/SLUS_207.65').read_bytes();overlay=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    audits=[]
    # The1B1E20 and1B2CE0 generated files coalesce subsequent functions.
    # Audit precisely the entry body being used, not those unrelated tails.
    for entry,end in [(0x1b2d00,0x1b2d7c),(0x1b1e20,0x1b1e44),(0x1b2ce0,0x1b2cf4),(0x1d1b10,None)]:
        name=f'recomp/config/output/sub_{entry:08X}_0x{entry:x}.cpp'
        if end is None:end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',(ROOT/name).read_text())[1],16)
        audits.append(compare_source('room-motion source body',name,entry,end,elf_reader(elf)))
    name='recomp/config/output_ovl/o2/o2_0068C410_0x68c410.cpp'
    end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',(ROOT/name).read_text())[1],16)
    audits.append(compare_source('EVB configuration importer',name,0x68c410,end,lambda at,n:overlay[at-0x570000:at-0x570000+n]))
    inventory_path=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';inventory_raw=inventory_path.read_bytes()
    assert sha(inventory_raw)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
    inventory={tuple(n.lower()for n in x['names']):x for x in json.loads(inventory_raw)}
    profile_path=ROOT/'game/native/gameplay_world/humanoid_motion_members.inc';profile=profile_path.read_text()
    common={int(x)for x in re.findall(r'\{(\d+),255,',profile)}
    tables=[];stamp=(args.archive.stat().st_size,args.archive.stat().st_mtime_ns)
    with args.archive.open('rb')as stream:
        root=read_toc(stream,0)
        for scenario in (1,2,28,35,41):
            parent=f'r{scenario:03}.afs';child=f'r{scenario:03}.evb'
            index=next(i for i,x in enumerate(root[2])if x[0].lower()==parent)
            base,_=root[0][index];inner=read_toc(stream,base)
            index=next(i for i,x in enumerate(inner[2])if x[0].lower()==child)
            offset,size=inner[0][index];stream.seek(base+offset);data=stream.read(size)
            expected=inventory[(parent,child)];assert len(data)==expected['bytes']and sha(data)==expected['sha256']
            at=struct.unpack_from('<I',data,32)[0];assert at>=128
            rows=[]
            while True:
                value=struct.unpack_from('<H',data,at+len(rows)*2)[0]
                if value==255:break
                assert len(rows)<128 and value in common
                rows.append(value)
            tables.append(dict(scenario=scenario,member=expected['member'],sha256=sha(data),table_offset=at,rows=rows,selectors=sorted(set(rows))))
    assert stamp==(args.archive.stat().st_size,args.archive.stat().st_mtime_ns)
    receipt=dict(status='passed',source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__).read_bytes()),profile_path.relative_to(ROOT).as_posix():sha(profile_path.read_bytes())},original_word_audits=audits,tables=tables,entries=sum(len(x['rows'])for x in tables),original_execution=False,game_run=False,stage4_complete=False)
    args.output.mkdir(parents=True);(args.output/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status='passed',scenarios=len(tables),entries=receipt['entries'],original_execution=False)))

if __name__=='__main__':main()
