"""Seal the common resource XZY/scale consumer with current weapon regressions."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    sources={};copies={};cohorts={};previous=None
    for compiler,version in [('llvm',8),('gcc',3)]:
        p=ROOT/'build-native-sjuni'/f'resource-frames-{compiler}-v{version}/receipt.json';r=json.loads(p.read_bytes())
        assert r['status']=='passed' and not r['source_drift']
        if previous:assert r['source_sha256']==previous['source_sha256'] and r['results']==previous['results'] and r['weapon_assets']==previous['weapon_assets']
        previous=r
        for n,h in r['source_sha256'].items():
            frozen=p.parent/'source'/n;assert sha(ROOT/n)==h and sha(frozen)==h,n
            sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
        for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h,n
        cohorts[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'results':r['results']}
    seal=ROOT/'build-native-sjuni/resource-poses-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/RESOURCE_POSES.md','game/native/gameplay_world/CMakeLists.txt',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes())
        sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    parent={}
    for compiler in ['llvm','gcc']:
        for kind in ['v1','tests-v1']:
            p=ROOT/'build-native-sjuni'/f'stage4-resource-poses-parent-{compiler}-{kind}.txt';text=p.read_text(encoding='utf-16');assert 'FAILED:'not in text
            if kind.startswith('tests'):assert '100% tests passed, 0 tests failed out of 4'in text
            parent[p.relative_to(ROOT).as_posix()]=sha(p)
    prior=ROOT/'tools/native_reconstruction/native_resource_frames_qualification_v1.json'
    q=dict(schema=2,status='native nonattached resource XZY/scale and current weapon callbacks qualified on both compilers',game_run=False,installed_in_game=False,stage4_complete=False,
        source_sha256=sources,immutable_source_evidence=copies,cohorts=cohorts,parent_checks=parent,
        prior_qualification=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),
        limits=['Extended actors, room pulse, required rebuild and secondary release remain explicit unavailable consumers.',
                'NBD static pose input remains a controlled asset-identified set; actual asset/factory loading and game installation are open.',
                'Bitwise pose comparisons include XYZ, all W and the entire retained translation; no new performance claim.'])
    p=ROOT/'tools/native_reconstruction/native_resource_frames_qualification_v2.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
