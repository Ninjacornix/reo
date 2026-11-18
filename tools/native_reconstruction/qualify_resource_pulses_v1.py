"""Seal actual resource pulse/visual composition and current frame regression."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    sources={};copies={};cohorts={};previous=None;relations=[]
    for kind,versions in [('pulses',[('llvm',3),('gcc',2)]),('frames',[('llvm',9),('gcc',4)])]:
        previous=None
        for compiler,version in versions:
            p=ROOT/'build-native-sjuni'/f'resource-{kind}-{compiler}-v{version}/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'
            if kind=='pulses':assert r['source_unchanged'];results=r['observed']
            else:assert not r['source_drift'];results=r['results']
            if previous:assert r['source_sha256']==previous['source_sha256'] and results==previous.get('observed',previous.get('results'))
            previous=r
            for n,h in r['source_sha256'].items():
                frozen=p.parent/'source'/n;assert sha(frozen)==h,n
                if sha(ROOT/n)!=h:
                    assert kind=='frames' and n=='game/native/gameplay_world/resource_frames.hpp'
                    assert frozen.read_bytes().replace(b'extended actors/pulse/rebuild paths',b'extended actors/rebuild paths')==(ROOT/n).read_bytes()
                    relations.append(dict(cohort=kind+'-'+compiler,path=n,frozen_sha256=h,current_sha256=sha(ROOT/n),change='one line comment only; exact byte replacement checked'))
                else:sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
            for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h,n
            cohorts[kind+'-'+compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'results':results}
    seal=ROOT/'build-native-sjuni/resource-pulses-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/RESOURCE_PULSES.md','game/native/gameplay_world/CMakeLists.txt',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    parent={}
    for compiler in ['llvm','gcc']:
        for kind in ['v1','tests-v1']:
            p=ROOT/'build-native-sjuni'/f'stage4-resource-pulses-parent-{compiler}-{kind}.txt';text=p.read_text(encoding='utf-16');assert 'FAILED:'not in text
            if kind.startswith('tests'):assert '100% tests passed, 0 tests failed out of 4'in text
            parent[p.relative_to(ROOT).as_posix()]=sha(p)
    q=dict(schema=1,status='canonical resource periodic visuals and current frame consumers qualified on both compilers',game_run=False,installed_in_game=False,stage4_complete=False,
        source_sha256=sources,immutable_source_evidence=copies,cohorts=cohorts,parent_checks=parent,regression_header_relation=relations,
        limits=['Real six-bank visual ownership, RNG, capacity, state and output composition execute; resource game caller/factory installation remains open.',
                '65,536 paired yaw/pitch patterns do not exhaust all angle combinations. Finite SDK131 comparison does not establish physical PS2 exceptional parity.',
                'Shared secondary retirement, extended actors, required reconstruction and actual native gameplay acceptance remain open.'],
        preserved_failures=['build-native-sjuni/resource-pulses-llvm-v1/receipt.json','build-native-sjuni/resource-pulses-llvm-v2/receipt.json','build-native-sjuni/resource-pulses-gcc-v1/receipt.json'])
    p=ROOT/'tools/native_reconstruction/native_resource_pulses_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
