"""Seal actual shared World surface work and unaffected general/fog consumers."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    sources={};copies={};cohorts={}
    for group,prefix,versions in [('surface','surface-work',{'llvm':'v10','gcc':'v2'}),('regression','effect-work',{'llvm':'v16','gcc':'v3'})]:
        previous=None
        for compiler,version in versions.items():
            p=ROOT/'build-native-sjuni'/f'{prefix}-{compiler}-{version}'/'receipt.json';r=json.loads(p.read_bytes())
            assert r['status']=='passed' and r['source_unchanged'] and not r.get('debug_trace_instrumentation')
            if previous:assert previous['source_sha256']==r['source_sha256'] and previous['observed']==r['observed']
            previous=r
            for n,h in r['source_sha256'].items():
                assert sha(ROOT/n)==h and sha(p.parent/'source'/n)==h,n
                if n in sources:assert sources[n]==h,n
                sources[n]=h;copies[n]={'path':(p.parent/'source'/n).relative_to(ROOT).as_posix(),'sha256':h}
            for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h,n
            cohorts[group+'_'+compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'observed':r['observed']}
    seal=ROOT/'build-native-sjuni/surface-work-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/EFFECT_SURFACE_WORK.md',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    q={'schema':1,'status':'actual native shared-pool factory, World/room surface callback and scaled children qualified on both compilers','game_run':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':sources,'immutable_source_evidence':copies,'cohorts':cohorts,'limits':['Original SDK finite arithmetic profile, not physical exceptional parity.','Native model rebuilds provide controlled external poses; independent model qualification is reused.','Resource allocation/cache and bounded memory are declared test-only surroundings.','Actor generation retirement replaces original pointer-slot retargeting explicitly.','Actual runtime room installer, aggregate room reset, scenario dispatcher installation and game acceptance remain open.'],'preserved_initial_cohorts':[f'build-native-sjuni/surface-work-llvm-v{i}/receipt.json'for i in range(1,10)]+['build-native-sjuni/surface-work-gcc-v1/receipt.json']}
    p=ROOT/'tools/native_reconstruction/native_effect_surface_work_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
