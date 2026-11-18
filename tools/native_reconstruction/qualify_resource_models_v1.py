"""Seal the64-primary-resource owner without claiming callback migration."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    sources={};copies={};cohorts={};previous=None
    for compiler in ['llvm','gcc']:
        p=ROOT/'build-native-sjuni'/f'resource-model-owner-{compiler}-v1/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'and not r['source_drift']
        if previous:assert r['source_sha256']==previous['source_sha256']and r['results']==previous['results']
        previous=r
        for n,h in r['source_sha256'].items():
            frozen=p.parent/'source'/n;assert sha(ROOT/n)==h and sha(frozen)==h,n;sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
        for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h,n
        cohorts[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'results':r['results']}
    seal=ROOT/'build-native-sjuni/resource-model-owner-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/RESOURCE_MODELS.md','game/native/gameplay_world/CMakeLists.txt','game/native/gameplay_world/model_attachments.cpp','game/native/gameplay_world/resource_programs.cpp',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    checks={}
    for compiler in ['llvm','gcc']:
        p=ROOT/'build-native-sjuni'/f'stage4-resource-model-parent-{compiler}-v1.txt';assert 'FAILED:'not in p.read_text(encoding='utf-16');checks[p.relative_to(ROOT).as_posix()]=sha(p)
    q={'schema':1,'status':'canonical64-primary-resource allocation/list/update ownership qualified on both compilers','game_run':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':sources,'immutable_source_evidence':copies,'cohorts':cohorts,'parent_builds':checks,'limits':['Complete original owner bodies execute with controlled callback and refresh seams; actual game callback migration remains open.','Missing work, bounded traversal and same-callback current-slot reuse are explicit native refusals.','Actual construction, release composition, visual updates and coherent gameplay acceptance remain open.']}
    p=ROOT/'tools/native_reconstruction/native_resource_models_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
