"""Seal mapped trail emissions, actual particle edits and current owner checks."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 production=['game/native/gameplay_world/'+n for n in ['pose_trail_admission.hpp','pose_trail_admission.cpp','pose_trail_effects.hpp','pose_trail_effects.cpp','pose_callbacks_contract_tests.cpp','CMakeLists.txt']]+['game/native/gameplay_effects/'+n for n in ['particle_work.hpp','periodic_visuals.hpp','periodic_visuals.cpp']]
 fixtures=['pose_trail_admission_tests.cpp','verify_pose_trail_admission.py','particle_parameters_tests.cpp','verify_particle_parameters.py','pose_trail_effects_tests.cpp','verify_pose_trail_effects.py','pose_trail_effect_owners.inc','verify_pose_trail_effect_owners.py','verify_pose_callbacks_current.py']
 tools=['tools/native_reconstruction/'+n for n in fixtures]+[Path(__file__).relative_to(ROOT).as_posix()]
 record=dict(schema=1,status='passed',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256={n:sha(ROOT/n)for n in production+tools+['docs/native-gameplay/POSE_TRAILS.md']},cohorts={},limits=['Distinct five-work5789C0 mode1 lifecycles are not supplied by this checkpoint.','Explicit-position/nonzero-delay mode1 inputs require a wider concrete consumer.','Original constructors are independent native-owner observation boundaries; full original visual updates are not claimed by this cohort.','Current contract uses owned room geometry; private policy/owner floor grids are controlled native imports.','Full frame/session installation and gameplay acceptance remain open.'])
 observations={}
 for cc in ['llvm','gcc']:
  record['cohorts'][cc]={}
  for label,name in [('admission',f'pose-trail-admission-{cc}-v2'),('parameters',f'particle-parameters-{cc}-v1'),('policy',f'pose-trail-effects-{cc}-v2'),('owner',f'pose-trail-effect-owners-{cc}-v1'),('current',f'pose-callbacks-current-{cc}-v3')]:
   p=ROOT/'build-native-sjuni'/name/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed';assert not r.get('source_drift')and not r.get('owned_source_drift');result=r.get('observed',r.get('result'));assert result
   if label in observations:assert observations[label]==result
   observations[label]=result
   for n,digest in r['source_sha256'].items():assert sha(p.parent/'source'/n)==digest,(p,n)
   if label=='current':
    for n in production:assert r['source_sha256'][n]==sha(ROOT/n),(p,n)
    assert result['checks']==1312 and result['owned_banks']==6
   changes={n:{'qualified':digest,'current':sha(ROOT/n)}for n,digest in r['source_sha256'].items()if sha(ROOT/n)!=digest}
   record['cohorts'][cc][label]=dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),observed=result,compiler_sha256=r['compiler_sha256'],subsequent_dependency_changes=changes)
 for n in tools[:-1]:assert any(json.loads((ROOT/v['path']).read_bytes())['source_sha256'].get(n)==sha(ROOT/n)for v in record['cohorts']['llvm'].values()),n
 target=ROOT/'tools/native_reconstruction/native_pose_trails_qualification_v1.json';assert not target.exists();target.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',sha256=sha(target),stage4_complete=False)))
if __name__=='__main__':main()
