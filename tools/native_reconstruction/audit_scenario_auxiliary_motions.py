"""Pin1D1C50's actual File1 ROM aliases, bytes and complete source bodies."""
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
    elf=(ROOT/'game_data/SLUS_207.65').read_bytes()
    assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read=elf_reader(elf);template=b'data\\rom\\motion\\rn%02d_tbl.bin';assert read(0x256410,len(template))==template
    proof=[]
    for at in (0x1d1c50,0x1d1940,0x1d16c0,0x1b2150):
        path=ROOT/f'recomp/config/output/sub_{at:08X}_0x{at:x}.cpp'
        end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',path.read_text())[1],16)
        proof.append(compare_source('scenario auxiliary motion loader',path.relative_to(ROOT).as_posix(),at,end,read))
    aliases=[]
    for ordinal in range(1342):
        pointer=struct.unpack('<I',read(0x2322c0+4*ordinal,4))[0];encoded=bytearray()
        for index in range(256):
            value=read(pointer+index,1)[0]
            if not value:break
            encoded.append(value^255)
        else:raise AssertionError('ROM alias has no terminator')
        alias=encoded.decode('ascii');match=re.fullmatch(r'MOTION_RN(\d+)_TBL_BIN',alias)
        if match:aliases.append((ordinal,int(match[1]),alias))
    assert len(aliases)==20
    inventory=json.loads((ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json').read_text())
    inventory={row['member']:row for row in inventory};rows=[]
    with args.archive.open('rb') as stream:
        entries,_,names=read_toc(stream,0)
        candidates=[i for i,value in enumerate(names) if value[0].lower()=='romdata_usa.afs'];assert len(candidates)==1
        parent=candidates[0];base=entries[parent][0]
        entries,_,names=read_toc(stream,base);assert len(entries)==1342
        for ordinal,scenario,alias in aliases:
            expected=f'rn{scenario:02d}_tbl.bin';assert names[ordinal][0].lower()==expected
            offset,size=entries[ordinal];stream.seek(base+offset);data=stream.read(size)
            recorded=inventory[f'NETBIO00.DAT/{parent}/{ordinal}'];assert len(data)==size==recorded['bytes'] and sha(data)==recorded['sha256']
            rows.append(dict(scenario=scenario,ordinal=ordinal,name=expected,alias=alias,bytes=size,sha256=sha(data),header=struct.unpack_from('<4I',data)))
    args.output.parent.mkdir(parents=True,exist_ok=True)
    receipt=dict(status='passed',source_audits=proof,rows=rows,elf_sha256=sha(elf),script_sha256=sha(Path(__file__).read_bytes()),game_run=False,
                 scope='Source and owned asset identity audit. MotionBank mode2 behavior uses its existing original qualification; final caller/publication tests remain separate.')
    args.output.write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',tables=len(rows))))
if __name__=='__main__':main()
