"""Static native-gameplay integration cut; no target execution or edits."""
import argparse,collections,hashlib,json,re,struct,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
TARGETS=(0x5735a0,0x573630,0x573740,0x573840,0x573890,0x5738f0,0x5b91b0,0x5b92b0,0x5b93b0,0x68c7b0,0x68e1f0,0x5fee80)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--output',type=Path,required=True);a=parser.parse_args();out=a.output.resolve()
    assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni/native-gameplay/tasks')
    blobs={};identity={}
    for image,expected in [('o0','bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'),
        ('o2','45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'),('o9',None)]:
        path=ROOT/f'build-function-index/owned-overlays/{image}.bin';data=path.read_bytes()
        if expected:assert sha(path)==expected
        identity[path.relative_to(ROOT).as_posix()]=sha(path);blobs[image]=(int.from_bytes(data[8:12],'little'),data)
    pattern='func_('+'|'.join(f'{address:X}'for address in TARGETS)+')'
    found=subprocess.run(['rg','-l','-g','*.cpp',pattern,'recomp/config/output_ovl/o0','recomp/config/output_ovl/o2'],cwd=ROOT,text=True,capture_output=True,check=True).stdout.splitlines()
    callers=[];counts=collections.Counter()
    for name in found:
        path=ROOT/name;image=path.parent.name;base,data=blobs[image];sites=[]
        for pc,word in re.findall(r'// 0x([0-9a-fA-F]+): 0x([0-9a-fA-F]+)',path.read_text()):
            pc,word=int(pc,16),int(word,16);target=(word&0x3ffffff)*4
            if word>>26 not in (2,3)or target not in TARGETS:continue
            assert struct.unpack_from('<I',data,pc-base)[0]==word
            sites.append(dict(pc=hex(pc),target=hex(target),word=hex(word)));counts[hex(target)]+=1
        if sites:callers.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),sites=sites))
    extra=[]
    for image,start in [('o2',0x5a1ef0),('o9',0x8217b0)]:
        path=next((ROOT/f'recomp/config/output_ovl/{image}').glob(f'{image}_{start:08X}_0x{start:x}.cpp'))
        end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',path.read_text())[1],16);base,data=blobs[image]
        extra.append(compare_source('distinct invocation-timer semantics; not migrated',path.relative_to(ROOT).as_posix(),start,end,lambda a,n,d=data,b=base:d[a-b:a-b+n]))
    result=dict(schema=1,status='owned-word direct integration sites and separate timer semantics verified',game_run=False,process_access=False,
        direct_search_scope=['recomp/config/output_ovl/o0/**/*.cpp','recomp/config/output_ovl/o2/**/*.cpp'],
        indirect_callers_complete=False,all_gameplay_callbacks_migrated=False,input_sha256=identity,
        callers=callers,direct_sites_per_target=dict(counts),extra_timer_bodies=extra,
        source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},
        limitations=['Direct call inventory is bounded to scenario/common partitions; other overlays, pointer tables and assets need separate consumer mapping.',
            'Addresses shared by other overlay images are not treated as equivalent function identities.',
            'Original5A1EF0 decrement-then-negative reset and o9 8217B0 already-zero predicate differ from script flag-timer positive-to-zero behavior.'])
    out.mkdir(parents=True);path=out/'audit.json';path.write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(callers=len(callers),sites=sum(counts.values()),counts=dict(counts),sha256=sha(path))))
if __name__=='__main__':main()
