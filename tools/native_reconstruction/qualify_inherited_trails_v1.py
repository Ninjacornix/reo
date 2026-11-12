"""Seal actual five-work inherited trails with callback/owner/current graph checks."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 production=['game/native/gameplay_effects/'+n for n in ['inherited_trail.hpp','inherited_trail.cpp','inherited_trail_owner.hpp','periodic_visuals.hpp','periodic_visuals.cpp','CMakeLists.txt']]+['game/native/gameplay_world/'+n for n in ['positioned_pose_trails.hpp','inherited_pose_trails.hpp','inherited_pose_trails.cpp','pose_trail_effects.cpp','pose_callbacks_contract_tests.cpp','CMakeLists.txt']]
 fixtures=['inherited_trail_tests.cpp','verify_inherited_trail.py','inherited_trail_owner_tests.cpp','verify_inherited_trail_owner.py','verify_pose_callbacks_current.py','verify_particle_parameters.py','verify_pose_trail_effect_owners.py','gameplay_update_sources.py','effect_work_sources.py']
 tools=['tools/native_reconstruction/'+n for n in fixtures]+[Path(__file__).relative_to(ROOT).as_posix()]
 from gameplay_update_sources import UPDATE_UNITS
 from effect_work_sources import SURFACE_WORLD_UNITS
 unit='game/native/gameplay_effects/inherited_trail.cpp';assert UPDATE_UNITS.count(unit)==1 and SURFACE_WORLD_UNITS.count(unit)==1
 record=dict(schema=1,status='passed',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256={n:sha(ROOT/n)for n in production+tools+['docs/native-gameplay/INHERITED_POSE_TRAILS.md']},cohorts={},limits=['Required654D40 sound and5783A0 particle burst consumers are explicit reached refusals until concrete actions and source metadata are adopted.','Source33/554 sound producers include enemy population6BB040 and58EE50 copy; no guessed metadata is used.','Original callbacks execute complete math and work-state transitions;652880 child sampling is an explicit observation boundary independently qualified by generic sampling proofs.','Owner floors are controlled native imports; current CMake contract additionally uses owned stock room data.','Full frame/session installation, remaining callbacks/actions and installed gameplay acceptance remain open.'])
 observations={}
 for cc in ['llvm','gcc']:
  record['cohorts'][cc]={}
  for label,name in [('policy',f'inherited-trail-policy-{cc}-v10'),('owner',f'inherited-trail-owner-{cc}-v5'),('parameters_regression',f'particle-parameters-{cc}-v2'),('mapped_regression',f'pose-trail-effect-owners-{cc}-v2'),('current',f'pose-callbacks-current-{cc}-v4')]:
   p=ROOT/'build-native-sjuni'/name/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed';assert not r.get('source_drift')and not r.get('owned_source_drift');result=r.get('observed',r.get('result'));assert result
   if label in observations:assert observations[label]==result
   observations[label]=result
   for n,digest in r['source_sha256'].items():assert sha(p.parent/'source'/n)==digest,(p,n)
   if label=='current':
    for n in production:assert r['source_sha256'][n]==sha(ROOT/n),(p,n)
    assert result['checks']==1393 and result['owned_banks']==6
   changes={n:{'qualified':digest,'current':sha(ROOT/n)}for n,digest in r['source_sha256'].items()if sha(ROOT/n)!=digest}
   record['cohorts'][cc][label]=dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),observed=result,compiler_sha256=r['compiler_sha256'],subsequent_dependency_changes=changes)
 for n in tools[:-3]:assert any(json.loads((ROOT/v['path']).read_bytes())['source_sha256'].get(n)==sha(ROOT/n)for v in record['cohorts']['llvm'].values()),n
 target=ROOT/'tools/native_reconstruction/native_inherited_trails_qualification_v1.json';assert not target.exists();target.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',sha256=sha(target),stage4_complete=False)))
if __name__=='__main__':main()
