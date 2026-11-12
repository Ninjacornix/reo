"""Seal concrete pose cloud/motion/arc policies and actual current owner graph."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    production=['game/native/gameplay_world/'+n for n in ['pose_cloud.hpp','pose_cloud.cpp','pose_cloud_policy.cpp','pose_motion.hpp','pose_motion.cpp','pose_motion_policy.cpp','pose_arcs.hpp','pose_arcs.cpp','pose_arcs_policy.cpp','pose_callbacks_contract_tests.cpp','CMakeLists.txt']]
    tools=['tools/native_reconstruction/'+n for n in ['pose_cloud_tests.cpp','verify_pose_cloud.py','pose_cloud_owner_tests.cpp','verify_pose_cloud_owner.py','pose_motion_tests.cpp','verify_pose_motion.py','pose_arcs_tests.cpp','verify_pose_arcs.py','verify_pose_callbacks_current.py',Path(__file__).name]]
    owned=production+tools+['docs/native-gameplay/POSE_CALLBACKS.md'];record=dict(schema=1,status='passed',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256={n:sha(ROOT/n)for n in owned},cohorts={},limits=['EF02 geometry55 has an unadmitted group255 profile; explicit prefix-preserving refusal is tested.','Actual quantum74F200 producer and578620 trail consumers remain required where reached.','Full frame/session ownership and installed gameplay acceptance remain open.']);observations={}
    for cc in ['llvm','gcc']:
        record['cohorts'][cc]={}
        for label,name in [('cloud_policy',f'pose-cloud-policy-{cc}-v2'),('cloud_owner',f'pose-cloud-owner-{cc}-v5'),('motion',f'pose-motion-policy-{cc}-v1'),('arcs',f'pose-arcs-policy-{cc}-v1'),('current',f'pose-callbacks-current-{cc}-v2')]:
            p=ROOT/'build-native-sjuni'/name/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed',(p,r['status']);assert not r.get('source_drift')and not r.get('owned_source_drift')and not r.get('current_owned_source_drift')
            current=r['source_sha256'];result=r.get('observed',r.get('result'));assert result
            if label in observations:assert observations[label]==result
            observations[label]=result
            if label=='current':
                for n in production:assert current[n]==sha(ROOT/n),(p,n)
                assert result['checks']==1267 and result['owned_banks']==6 and result['cloud_frames']==380 and result['room_cases']==6 and result['profile_refusals']==1
            changes={}
            for n,digest in current.items():
                assert sha(p.parent/'source'/n)==digest,(p,n)
                if sha(ROOT/n)!=digest:changes[n]={'qualified':digest,'current':sha(ROOT/n)}
            record['cohorts'][cc][label]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'observed':result,'compiler_sha256':r['compiler_sha256'],'subsequent_dependency_changes':changes}
    for n in tools[:-1]:
        assert any(json.loads((ROOT/v['path']).read_bytes())['source_sha256'].get(n)==sha(ROOT/n)for v in record['cohorts']['llvm'].values()),n
    target=ROOT/'tools/native_reconstruction/native_pose_callbacks_qualification_v1.json';assert not target.exists();target.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps({'status':'passed','sha256':sha(target),'game_run':False,'stage4_complete':False}))
if __name__=='__main__':main()
