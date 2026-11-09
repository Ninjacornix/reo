"""Seal source-derived primary static poses from actual owned NBD forests."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    sources={};copies={};cohorts={};previous=None
    for compiler in ['llvm','gcc']:
        p=ROOT/'build-native-sjuni'/f'resource-static-{compiler}-v1/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed' and r['source_unchanged'] and len(r['static_assets'])==16
        if previous:assert r['source_sha256']==previous['source_sha256'] and r['observed']==previous['observed'] and r['static_assets']==previous['static_assets']
        previous=r
        for n,h in r['source_sha256'].items():
            frozen=p.parent/'source'/n;assert sha(ROOT/n)==h and sha(frozen)==h,n;sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
        for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h,n
        cohorts[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'observed':r['observed'],'static_assets':r['static_assets']}
    seal=ROOT/'build-native-sjuni/resource-static-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/RESOURCE_STATIC_ASSETS.md','game/native/gameplay_world/CMakeLists.txt',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    audit=ROOT/'build-native-sjuni/resource-static-asset-audit-v1.json';assert sha(audit)==previous['static_asset_audit_sha256'];target=seal/audit.name;target.write_bytes(audit.read_bytes())
    parent={}
    for compiler in ['llvm','gcc']:
        p=ROOT/'build-native-sjuni'/f'stage4-resource-static-parent-{compiler}-v1.txt';assert 'FAILED:'not in p.read_text(encoding='utf-16');parent[p.relative_to(ROOT).as_posix()]=sha(p)
    q=dict(schema=1,status='owned NBD static primary poses and signed content lookup qualified on both compilers',game_run=False,installed_in_game=False,stage4_complete=False,
        source_sha256=sources,immutable_source_evidence=copies,cohorts=cohorts,parent_builds=parent,input_selection=dict(path=target.relative_to(ROOT).as_posix(),sha256=sha(target)),
        limits=['Complete1D3100 executes; native comparisons cover root IDs/counts and admitted primary matrices, not its second bind-matrix bank.',
                'Two known roots exceed the six-part primary contract and remain explicit unavailable cells; at most96 roots are admitted.',
                'Actual construction/loading callers, larger-part consumers, renderer handoff and complete gameplay acceptance remain open.'])
    p=ROOT/'tools/native_reconstruction/native_resource_static_assets_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
