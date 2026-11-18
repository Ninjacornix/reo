"""Seal the read-only pose timing bridge to the existing actual linked pass."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    production=['game/native/gameplay_world/linked_pose_timing.hpp','game/native/gameplay_world/pose_callbacks_contract_tests.cpp']
    tools=['tools/native_reconstruction/linked_pose_timing_tests.cpp','tools/native_reconstruction/verify_linked_pose_timing.py',Path(__file__).relative_to(ROOT).as_posix()]
    record=dict(schema=1,status='passed',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256={n:sha(ROOT/n)for n in production+tools+['docs/native-gameplay/POSE_TIMING.md']},cohorts={},limits=['The original linked-pass comparison has an empty population and unchanged simulation seconds.','6409C0/6409D0 renderer boundaries remain explicit observations.','Actual full frame installation and gameplay acceptance remain open.']);observations={}
    for cc in ['llvm','gcc']:
        record['cohorts'][cc]={}
        for label,name in [('producer',f'linked-pose-timing-{cc}-v3'),('current',f'pose-callbacks-current-{cc}-v5')]:
            p=ROOT/'build-native-sjuni'/name/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'and not r.get('source_drift')and not r.get('owned_source_drift');result=r.get('observed',r.get('result'));assert result
            if label in observations:assert observations[label]==result
            observations[label]=result
            for n,digest in r['source_sha256'].items():assert sha(p.parent/'source'/n)==digest,(p,n)
            for n in production if label=='current'else production[:1]:assert r['source_sha256'][n]==sha(ROOT/n),(p,n)
            changes={n:{'qualified':digest,'current':sha(ROOT/n)}for n,digest in r['source_sha256'].items()if sha(ROOT/n)!=digest}
            record['cohorts'][cc][label]=dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),observed=result,compiler_sha256=r['compiler_sha256'],subsequent_dependency_changes=changes)
    for n in tools[:-1]:assert any(json.loads((ROOT/v['path']).read_bytes())['source_sha256'].get(n)==sha(ROOT/n)for v in record['cohorts']['llvm'].values()),n
    target=ROOT/'tools/native_reconstruction/native_linked_pose_timing_qualification_v1.json';assert not target.exists();target.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',sha256=sha(target),stage4_complete=False)))
if __name__=='__main__':main()
