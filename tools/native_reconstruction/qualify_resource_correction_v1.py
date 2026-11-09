"""Seal shared weapon-part/attachment correction identity and actual consumers."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    sources={};copies={};cohorts={}
    for kind,versions in [('frames',[('llvm',16),('gcc',11)]),('correction-attachments',[('llvm',1),('gcc',1)])]:
        previous=None
        for compiler,version in versions:
            p=ROOT/'build-native-sjuni'/f'resource-{kind}-{compiler}-v{version}/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'
            if kind=='frames':assert not r['source_drift'];result=r['results']
            else:assert r['source_unchanged'];result=r['observed']
            if previous:assert r['source_sha256']==previous['source_sha256'] and result==previous.get('results',previous.get('observed'))
            previous=r
            for n,h in r['source_sha256'].items():
                frozen=p.parent/'source'/n;assert sha(ROOT/n)==h and sha(frozen)==h,n;sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
            for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h,n
            cohorts[kind+'-'+compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'results':result}
    seal=ROOT/'build-native-sjuni/resource-correction-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/RESOURCE_CORRECTION_MATRIX.md','game/native/gameplay_world/CMakeLists.txt',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    parent={}
    for compiler in ['llvm','gcc']:
        p=ROOT/'build-native-sjuni'/f'stage4-resource-correction-parent-{compiler}-v1.txt';assert 'FAILED:'not in p.read_text(encoding='utf-16');parent[p.relative_to(ROOT).as_posix()]=sha(p)
    q=dict(schema=1,status='one canonical matrix for WMD part5 and attachment correction qualified on both compilers',game_run=False,installed_in_game=False,stage4_complete=False,
        source_sha256=sources,immutable_source_evidence=copies,cohorts=cohorts,parent_builds=parent,
        limits=['Fixes a native state-sharing error before game installation; no live incident cause or speedup is established.',
                'New category/draw-tag state prepares construction; actual factory, renderer and complete gameplay acceptance remain open.'])
    p=ROOT/'tools/native_reconstruction/native_resource_correction_matrix_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
