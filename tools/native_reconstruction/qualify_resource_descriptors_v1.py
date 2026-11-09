"""Seal descriptor allocation and actual owned item-template selection."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    sources={};copies={};cohorts={};originals={}
    for kind,versions in [('frames',[('llvm',15),('gcc',10)]),('descriptors-scene',[('llvm',2),('gcc',2)])]:
        previous=None
        for compiler,version in versions:
            p=ROOT/'build-native-sjuni'/f'resource-{kind}-{compiler}-v{version}/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'
            result=r.get('results',r.get('result'))
            if kind=='frames':assert not r['source_drift'] and len(r['template_assets'])==5
            if previous:assert r['source_sha256']==previous['source_sha256'] and result==previous.get('results',previous.get('result'))
            previous=r
            for n,h in r['source_sha256'].items():
                frozen=p.parent/'source'/n
                if not frozen.is_file():frozen=p.parent/Path(n).name
                assert sha(ROOT/n)==h and sha(frozen)==h,n;sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
            for n,h in r.get('original_sources_sha256',{}).items():assert sha(ROOT/n)==h,n;originals[n]=h
            for n,h in r.get('output_sha256',{}).items():assert sha(p.parent/n)==h,n
            cohorts[kind+'-'+compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'result':result,'template_assets':r.get('template_assets'),
                'output_sha256':{f.relative_to(p.parent).as_posix():sha(f) for f in p.parent.rglob('*') if f.is_file() and f!=p}}
    seal=ROOT/'build-native-sjuni/resource-descriptors-seal-v1';assert not seal.exists();seal.mkdir()
    for n in [*originals,'docs/native-gameplay/RESOURCE_DESCRIPTOR_ALLOCATION.md','game/native/gameplay_world/CMakeLists.txt',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    parent={}
    for compiler in ['llvm','gcc']:
        for kind in ['v2','tests-v1']:
            p=ROOT/'build-native-sjuni'/f'stage4-resource-descriptors-parent-{compiler}-{kind}.txt';text=p.read_text(encoding='utf-16');assert 'FAILED:'not in text
            if kind.startswith('tests'):assert '100% tests passed, 0 tests failed out of 4'in text
            parent[p.relative_to(ROOT).as_posix()]=sha(p)
    q=dict(schema=1,status='native descriptor allocation and owned item-template selection qualified on both compilers',game_run=False,installed_in_game=False,stage4_complete=False,
        source_sha256=sources,immutable_source_evidence=copies,cohorts=cohorts,parent_checks=parent,
        limits=['First-inactive allocation is slots1..255, preserving slot0 and the255-active limit; source counter/table consistency is admitted.',
                'Typed fields and capability clearing compare; unprojected geometry/instance construction and actual game acceptance remain open.',
                'Native descriptor IDs do not preserve raw source pointer aliases across slot reuse.'],
        preserved_failures=['build-native-sjuni/resource-frames-llvm-v14/receipt.json','build-native-sjuni/resource-frames-gcc-v9/receipt.json'])
    p=ROOT/'tools/native_reconstruction/native_resource_descriptors_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
