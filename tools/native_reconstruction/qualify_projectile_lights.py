"""Seal actual projectile light sources and paired retained proof receipts."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 names=['game/native/gameplay_lighting/transient_lights.hpp','game/native/gameplay_lighting/transient_lights.cpp','game/native/gameplay_world/projectile_pose_lights.hpp','game/native/gameplay_world/projectile_pose_lights.cpp','game/native/gameplay_lighting/projectile_lights_contract_tests.cpp','tools/native_reconstruction/transient_light_policy_tests.cpp','tools/native_reconstruction/projectile_lights_owner_tests.inc','tools/native_reconstruction/verify_projectile_lights.py','tools/native_reconstruction/verify_projectile_lights_current.py','docs/native-gameplay/PROJECTILE_LIGHTS.md',Path(__file__).relative_to(ROOT).as_posix()]
 receipts={}
 for cc in ['llvm','gcc']:
  for folder in [f'projectile-lights-{cc}-v4',f'projectile-lights-current-{cc}-v2']:
   p=ROOT/'build-native-sjuni'/folder/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'and not r['game_run']and not r['installed_in_game']and not r['stage4_complete'];assert not r.get('source_drift',{})and not r.get('owned_source_drift',{})
   if 'observed'in r:assert r['observed']['checks']==7447301 and r['observed']['projectile_cases']==201
   else:assert r['parent_tests']==32
   for n in names:
    if n in r.get('source_sha256',{}):assert sha(ROOT/n)==r['source_sha256'][n],n
   receipts[p.relative_to(ROOT).as_posix()]={'sha256':sha(p),'observed':r.get('observed'),'parent_tests':r.get('parent_tests')}
 result=dict(schema=1,status='passed',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256={n:sha(ROOT/n)for n in names},receipts=receipts,cmake_required=['add_library(reo_native_projectile_light_effects STATIC projectile_pose_lights.cpp)','add_test(NAME native_projectile_lights_contract COMMAND projectile_lights_contract_tests)'])
 cmake=(ROOT/'game/native/gameplay_world/CMakeLists.txt').read_text();assert all(n in cmake for n in result['cmake_required'])
 out=ROOT/'tools/native_reconstruction/native_projectile_lights_qualification_v1.json';out.write_text(json.dumps(result,indent=2)+'\n');print(sha(out))
if __name__=='__main__':main()
