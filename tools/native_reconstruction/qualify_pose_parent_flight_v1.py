"""Seal complete parent pose flight policy and real current pool/room composition."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    production=['game/native/gameplay_world/'+n for n in ['pose_parent_flight.hpp','pose_parent_flight.cpp','pose_parent_flight_policy.cpp','pose_callbacks_contract_tests.cpp','CMakeLists.txt']]
    tools=['tools/native_reconstruction/'+n for n in ['pose_parent_flight_tests.cpp','verify_pose_parent_flight.py','verify_pose_callbacks_current.py',Path(__file__).name]]
    record=dict(schema=1,status='passed',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256={n:sha(ROOT/n)for n in production+tools+['docs/native-gameplay/PARENT_POSE_FLIGHT.md']},cohorts={},limits=['Actual1B9310 offset sound needs source33/554 construction metadata and concrete consumer.','Pure floor/trail/sound/retirement calls are observations; actual room/pool/trail composition is separately exercised by current CMake contracts.','Whole frame/session installation, remaining callbacks and gameplay acceptance remain open.']);observations={}
    for cc in ['llvm','gcc']:
        record['cohorts'][cc]={}
        for label,name in [('policy',f'pose-parent-flight-{cc}-v1'),('current',f'pose-callbacks-current-{cc}-v6')]:
            p=ROOT/'build-native-sjuni'/name/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'and not r.get('source_drift')and not r.get('owned_source_drift');result=r.get('observed',r.get('result'));assert result
            if label in observations:assert observations[label]==result
            observations[label]=result
            for n,digest in r['source_sha256'].items():assert sha(p.parent/'source'/n)==digest,(p,n)
            if label=='current':
                for n in production[:-1]:assert r['source_sha256'][n]==sha(ROOT/n),(p,n)
                cmake=production[-1]
                def pose_target(text):return text.split('add_library(reo_native_pose_callbacks ',1)[1].split('add_library(reo_native_dialogue ',1)[0]
                assert pose_target((p.parent/'source'/cmake).read_text())==pose_target((ROOT/cmake).read_text())
                assert result['checks']==1615
            changes={n:{'qualified':digest,'current':sha(ROOT/n)}for n,digest in r['source_sha256'].items()if sha(ROOT/n)!=digest}
            record['cohorts'][cc][label]=dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),observed=result,compiler_sha256=r['compiler_sha256'],subsequent_dependency_changes=changes)
    for n in tools[:-1]:assert any(json.loads((ROOT/v['path']).read_bytes())['source_sha256'].get(n)==sha(ROOT/n)for v in record['cohorts']['llvm'].values()),n
    target=ROOT/'tools/native_reconstruction/native_pose_parent_flight_qualification_v1.json';assert not target.exists();target.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',sha256=sha(target),stage4_complete=False)))
if __name__=='__main__':main()
