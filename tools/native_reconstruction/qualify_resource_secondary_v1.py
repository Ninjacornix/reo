"""Seal shared resource retirement and all directly affected consumer regressions."""
import hashlib,json,re
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    sources={};copies={};cohorts={};seal=ROOT/'build-native-sjuni/resource-secondary-seal-v1';assert not seal.exists()
    pending_originals={}
    for kind,versions in [('frames',[('llvm',11),('gcc',6)]),('pulses',[('llvm',4),('gcc',3)]),('secondary-scene',[('llvm',1),('gcc',1)]),('secondary-vm',[('llvm',1),('gcc',1)])]:
        previous=None
        for compiler,version in versions:
            p=ROOT/'build-native-sjuni'/f'resource-{kind}-{compiler}-v{version}/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'
            if kind=='frames':assert not r['source_drift'];result=r['results']
            elif kind=='pulses':assert r['source_unchanged'];result=r['observed']
            else:result=r['result']
            if kind=='secondary-vm':assert not r['pinned_shared_sources']
            if previous:assert r['source_sha256']==previous['source_sha256'] and result==previous.get('results',previous.get('observed',previous.get('result')))
            previous=r
            for n,h in r['source_sha256'].items():
                frozen=p.parent/'source'/n
                if not frozen.is_file():frozen=p.parent/Path(n).name
                assert sha(ROOT/n)==h and sha(frozen)==h,n
                sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
            for n,h in r.get('original_sources_sha256',{}).items():assert sha(ROOT/n)==h,n;pending_originals[n]=h
            for n,h in r.get('output_sha256',{}).items():assert sha(p.parent/n)==h,n
            cohorts[kind+'-'+compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'result':result,
                'output_sha256':{f.relative_to(p.parent).as_posix():sha(f) for f in p.parent.rglob('*') if f.is_file() and f!=p}}
    raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';static=[]
    for at in [0x591be0,0x5b43f0,0x592770]:
        n=f'recomp/config/output_ovl/o2/o2_{at:08X}_0x{at:x}.cpp';source=ROOT/n;end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',source.read_text())[1],16)
        static.append(compare_source('static retirement/deactivation authority; required592770 action remains open',n,at,end,lambda pos,size:raw[pos-0x570000:pos-0x570000+size]));pending_originals[n]=sha(source)
    seal.mkdir()
    for n in [*pending_originals,'docs/native-gameplay/RESOURCE_SECONDARY_RELEASE.md','game/native/gameplay_world/CMakeLists.txt',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    parent={}
    for compiler in ['llvm','gcc']:
        for kind in ['v1','tests-v1']:
            p=ROOT/'build-native-sjuni'/f'stage4-resource-secondary-parent-{compiler}-{kind}.txt';text=p.read_text(encoding='utf-16');assert 'FAILED:'not in text
            if kind.startswith('tests'):assert '100% tests passed, 0 tests failed out of 4'in text
            parent[p.relative_to(ROOT).as_posix()]=sha(p)
    q=dict(schema=1,status='resource primary/shared128 secondary retirement qualified with current native consumers',game_run=False,installed_in_game=False,stage4_complete=False,
        source_sha256=sources,immutable_source_evidence=copies,cohorts=cohorts,parent_checks=parent,static_next_boundary_authority=static,
        limits=['Secondary attachments reference the actual shared scene/control/collision record domain, with no extra logical record.',
                'Preflight refusals for unsupported foreign/stale capabilities are native safety extensions, not source raw-pointer parity.',
                'Required592770 deactivation branch, extended actors, asset construction/loading, native game installation and acceptance remain open.'])
    p=ROOT/'tools/native_reconstruction/native_resource_secondary_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
