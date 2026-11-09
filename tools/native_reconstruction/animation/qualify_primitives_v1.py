"""Seal reached native event primitives and canonical reverse identities."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    cohorts={};sources={};copies={};previous=None
    for compiler in ['llvm','gcc']:
        p=ROOT/'build-native-sjuni'/f'animation-primitives-{compiler}-v5/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed' and r['source_unchanged']
        if previous:assert previous['source_sha256']==r['source_sha256'] and previous['observed']==r['observed']
        previous=r
        for n,h in r['source_sha256'].items():
            assert sha(ROOT/n)==h and sha(p.parent/'source'/n)==h,n
            sources[n]=h;copies[n]={'path':(p.parent/'source'/n).relative_to(ROOT).as_posix(),'sha256':h}
        for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h,n
        cohorts[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'observed':r['observed']}
    seal=ROOT/'build-native-sjuni/animation-primitives-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/ANIMATION_EVENT_PRIMITIVES.md',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    q={'schema':1,'status':'native reached event primitives, real contact attachment and canonical reverse identity qualified on both compilers','game_run':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':sources,'immutable_source_evidence':copies,'cohorts':cohorts,'limits':['Audio is a declared recording seam here; actual bank frontends are qualified separately.','Reached visual/callback/resource-program paths explicitly refuse until their concrete owners are supplied.','No game/performance claim.']}
    p=ROOT/'tools/native_reconstruction/native_animation_event_primitives_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
