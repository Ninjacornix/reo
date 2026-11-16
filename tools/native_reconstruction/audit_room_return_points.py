"""Record actual File1 RTP contents and their complete producer/query bodies."""
import argparse,hashlib,json,re,struct,sys
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc
def sha(b):return hashlib.sha256(b).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--archive',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    assert not a.output.exists();a.output.mkdir(parents=True)
    elf=(ROOT/'game_data/SLUS_207.65').read_bytes();overlay=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    proof=[]
    for address in (0x1d4570,0x5fdf10,0x5fe150,0x5fe160,0x63f590):
        source=ROOT/(f'recomp/config/output/sub_{address:08X}_0x{address:x}.cpp' if address<0x570000 else f'recomp/config/output_ovl/o2/o2_{address:08X}_0x{address:x}.cpp')
        end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',source.read_text())[1],16)
        read=elf_reader(elf) if address<0x570000 else lambda at,n:overlay[at-0x570000:at-0x570000+n]
        proof.append(compare_source('RTP producer/query or actual empty startup function',source.relative_to(ROOT).as_posix(),address,end,read))
    rows=[];inventory=json.loads((ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json').read_text());inventory={x['member']:x for x in inventory}
    with a.archive.open('rb') as f:
        top=read_toc(f,0)
        for scenario,parent in ((1,1),(2,3),(28,5),(35,7),(41,9)):
            base=top[0][parent][0];toc=read_toc(f,base);matches=[i for i,x in enumerate(toc[2]) if x[0].lower()==f'r{scenario:02d}.rtp']
            if not matches:
                assert scenario==28;rows.append(dict(scenario=scenario,missing=True));continue
            assert len(matches)==1;i=matches[0];off,n=toc[0][i];f.seek(base+off);b=f.read(n)
            item=inventory[f'NETBIO00.DAT/{parent}/{i}'];assert len(b)==n==item['bytes'] and sha(b)==item['sha256']
            count=struct.unpack_from('<I',b)[0];keys=struct.unpack_from('<'+'H'*count,b,4);offsets=struct.unpack_from('<'+'H'*count,b,4+2*count);rooms=[]
            for key,offset in zip(keys,offsets):
                at=4+4*count+offset;pn,gn=struct.unpack_from('<II',b,at);ptrs=struct.unpack_from('<'+'I'*(pn+gn),b,at+8)
                points=[struct.unpack_from('<fff',b,at+x) for x in ptrs[:pn]];groups=[]
                for x in ptrs[pn:]:
                    start=at+x;kind,mode,total=struct.unpack_from('<bbb',b,start);assert total>=0
                    indices=list(struct.unpack_from('<'+'b'*total,b,start+3));assert all(0<=v<pn for v in indices)
                    groups.append(dict(kind=kind,mode=mode,indices=indices))
                rooms.append(dict(key=key,points=points,groups=groups))
            (a.output/f'r{scenario:02d}.rtp').write_bytes(b)
            rows.append(dict(scenario=scenario,parent=parent,ordinal=i,bytes=n,sha256=sha(b),rooms=rooms))
    receipt=dict(status='passed',assets=rows,source_audits=proof,elf_sha256=sha(elf),overlay_sha256=sha(overlay),script_sha256=sha(Path(__file__).read_bytes()),game_run=False,
        scope='Actual typed-content/source identity audit only; independent executable comparison follows the native implementation. Scenario28 has no RTP member and must preserve any prior buffer.')
    (a.output/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',tables=sum(not row.get('missing') for row in rows),rooms=sum(len(row.get('rooms',[])) for row in rows))))
if __name__=='__main__':main()
