"""Seal actual surface-follower lifetime, ownership and current parent evidence."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 names=['game/native/gameplay_effects/surface_follower_visual.hpp','game/native/gameplay_effects/surface_follower_visual.cpp','game/native/gameplay_effects/periodic_visuals.hpp','game/native/gameplay_effects/periodic_visuals.cpp','game/native/gameplay_world/forward_pose_visuals.hpp','game/native/gameplay_world/forward_pose_visuals.cpp','game/native/gameplay_effects/surface_follower_owner_tests.cpp','tools/native_reconstruction/surface_follower_visual_tests.cpp','tools/native_reconstruction/verify_surface_follower_visual.py','tools/native_reconstruction/verify_surface_follower_owner.py','tools/native_reconstruction/verify_surface_follower_owner_current.py','tools/native_reconstruction/verify_surface_follower_parents.py','docs/native-gameplay/SURFACE_FOLLOWER_VISUAL.md',Path(__file__).relative_to(ROOT).as_posix()]
 receipts={}
 for cc in ['llvm','gcc']:
  for folder in [f'surface-follower-visual-{cc}-v2',f'surface-follower-owner-current-{cc}-v1',f'surface-follower-owner-{cc}-v1',f'surface-follower-parents-{cc}-v2']:
   p=ROOT/'build-native-sjuni'/folder/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'and not r['game_run']and not r['installed_in_game']and not r['stage4_complete'];assert not r.get('source_drift',{})and not r.get('owned_source_drift',{})
   observed=r.get('observed',r.get('result'))
   if 'visual-'in folder:assert observed['checks']==38535168 and observed['cases']==2621440
   elif 'parents-'in folder:assert r['parent_tests']==34 and 'passed55checks'in r['session_dialogue'].replace(' ','')
   else:assert observed['owned_banks']==6 and observed['frames']==480
   for n in names:
    if n in r.get('source_sha256',{}):assert sha(ROOT/n)==r['source_sha256'][n],n
   receipts[p.relative_to(ROOT).as_posix()]={'sha256':sha(p),'observed':observed,'parent_tests':r.get('parent_tests')}
 result=dict(schema=1,status='passed',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256={n:sha(ROOT/n)for n in names},receipts=receipts,cmake_required=['target_sources(reo_native_gameplay_effects PRIVATE surface_follower_visual.cpp)','add_test(NAME native_surface_follower_owner COMMAND surface_follower_owner_tests)'])
 cmake=(ROOT/'game/native/gameplay_effects/CMakeLists.txt').read_text();assert all(n in cmake for n in result['cmake_required'])
 out=ROOT/'tools/native_reconstruction/native_surface_follower_visual_qualification_v1.json';out.write_text(json.dumps(result,indent=2)+'\n');print(sha(out))
if __name__=='__main__':main()
