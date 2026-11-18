"""Seal current unpinned World/scenario/effect composition and actual A8 calls."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    sources={};copies={};cohorts={};previous=None
    for compiler in ['llvm','gcc']:
        p=ROOT/'build-native-sjuni'/f'gameplay-scenario-current-surface-{compiler}-v1/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed' and not r['pinned_shared_sources']
        if previous:assert r['source_sha256']==previous['source_sha256'] and r['result']==previous['result']
        previous=r
        for n,h in r['source_sha256'].items():
            frozen=p.parent/'source'/n;assert sha(ROOT/n)==h and sha(frozen)==h,n
            sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
        for n,h in r['original_sources_sha256'].items():assert sha(ROOT/n)==h,n
        cohorts[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'result':r['result'],'checked_owned_instruction_comments':r['checked_owned_instruction_comments'],'output_sha256':{f.relative_to(p.parent).as_posix():sha(f) for f in p.parent.rglob('*') if f.is_file() and f!=p}}
    seal=ROOT/'build-native-sjuni/surface-vm-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/SCENARIO_SURFACE_EFFECTS.md',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    dependency=ROOT/'tools/native_reconstruction/native_effect_surface_work_qualification_v1.json'
    q={'schema':1,'status':'current unpinned World/scenario/shared effects and A8 command qualified on both compilers','game_run':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':sources,'immutable_source_evidence':copies,'cohorts':cohorts,'shared_factory_callback_dependency':{'path':dependency.relative_to(ROOT).as_posix(),'sha256':sha(dependency)},'limits':['Original651A30 allocation is a declared bounded oracle seam; actual allocator/factory/callback closure is an independent dependency.','Required stock opcodes and native game/resource/room installation remain incomplete.','No game/performance claim; opcode counts include no-ops.']}
    p=ROOT/'tools/native_reconstruction/native_scenario_surface_effects_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
