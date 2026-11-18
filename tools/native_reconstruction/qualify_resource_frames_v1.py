"""Seal actual common/weapon frame consumers and current canonical owners."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    sources={};copies={};cohorts={};previous=None
    for compiler,version in [('llvm',7),('gcc',2)]:
        p=ROOT/'build-native-sjuni'/f'resource-frames-{compiler}-v{version}/receipt.json';r=json.loads(p.read_bytes())
        assert r['status']=='passed' and not r['source_drift']
        if previous:assert r['source_sha256']==previous['source_sha256'] and r['results']==previous['results'] and r['weapon_assets']==previous['weapon_assets']
        previous=r
        for n,h in r['source_sha256'].items():
            frozen=p.parent/'source'/n;assert sha(ROOT/n)==h and sha(frozen)==h,n
            sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
        for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h,n
        cohorts[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'results':r['results']}
    seal=ROOT/'build-native-sjuni/resource-frames-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/RESOURCE_FRAMES.md','game/native/gameplay_world/CMakeLists.txt',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes())
        sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    parent={}
    for compiler,version in [('llvm',2),('gcc',1)]:
        for kind in ['v1',f'tests-v{version}']:
            p=ROOT/'build-native-sjuni'/f'stage4-resource-frames-parent-{compiler}-{kind}.txt';text=p.read_text(encoding='utf-16')
            assert 'FAILED:'not in text
            if kind.startswith('tests'):assert '100% tests passed, 0 tests failed out of 4'in text
            parent[p.relative_to(ROOT).as_posix()]=sha(p)
    q=dict(schema=1,status='canonical common/resource weapon callbacks qualified on both compilers',game_run=False,installed_in_game=False,stage4_complete=False,
        source_sha256=sources,immutable_source_evidence=copies,cohorts=cohorts,parent_checks=parent,
        limits=['Common5932F0 is bounded to primary owners and admitted no-action gates; extended actors, room pulse, required rebuild and nonattached1904A0 remain explicit refusals.',
                'Complete6B45C0 playback uses actual owned WMD assets and controlled asset-identified static part poses, not a migrated NBD loader.',
                'Actual canonical primary descriptor release executes; secondary shared128 retirement remains unavailable.',
                'Original unit-axis initialization and static pose tables are declared oracle surroundings. No new game installation or performance claim.'],
        preserved_unsuccessful_cohorts=[f'build-native-sjuni/resource-frames-llvm-v{i}/receipt.json'for i in range(1,5)]+['build-native-sjuni/resource-frames-gcc-v1/receipt.json','build-native-sjuni/stage4-resource-frames-parent-llvm-tests-v1.txt'])
    p=ROOT/'tools/native_reconstruction/native_resource_frames_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
