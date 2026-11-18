"""Seal native592770/591BE0 against complete owned bodies and canonical owners."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    sources={};copies={};cohorts={};previous=None
    for compiler,version in [('llvm',13),('gcc',8)]:
        p=ROOT/'build-native-sjuni'/f'resource-frames-{compiler}-v{version}/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed' and not r['source_drift']
        if previous:assert r['source_sha256']==previous['source_sha256'] and r['results']==previous['results']
        previous=r
        for n,h in r['source_sha256'].items():
            frozen=p.parent/'source'/n;assert sha(ROOT/n)==h and sha(frozen)==h,n;sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
        for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h,n
        cohorts[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'results':r['results']}
    seal=ROOT/'build-native-sjuni/resource-deactivation-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/RESOURCE_DEACTIVATION.md','game/native/gameplay_world/CMakeLists.txt',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    parent={}
    for compiler in ['llvm','gcc']:
        for kind in ['v1','tests-v1']:
            p=ROOT/'build-native-sjuni'/f'stage4-resource-deactivation-parent-{compiler}-{kind}.txt';text=p.read_text(encoding='utf-16');assert 'FAILED:'not in text
            if kind.startswith('tests'):assert '100% tests passed, 0 tests failed out of 4'in text
            parent[p.relative_to(ROOT).as_posix()]=sha(p)
    q=dict(schema=1,status='native conditional resource retirement/deactivation qualified on both compilers',game_run=False,installed_in_game=False,stage4_complete=False,
        source_sha256=sources,immutable_source_evidence=copies,cohorts=cohorts,parent_checks=parent,
        limits=['Active count is derived from the canonical descriptors; source counter/table consistency is an admitted oracle precondition.',
                'Controlled version3 asset records compare full template flag queries;129..254 are explicit unavailable indices.',
                'Extended actors, actual asset/resource construction, real game callers and gameplay acceptance remain open.'],preserved_compile_failure='build-native-sjuni/resource-frames-gcc-v7/receipt.json')
    p=ROOT/'tools/native_reconstruction/native_resource_deactivation_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
