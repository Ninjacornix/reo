"""Seal exact pose projectile production, source proofs and current owner contracts."""
import argparse,hashlib,json,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
GROUPS={'ground-flight':('v7',262144),'timed-projectile':('v4',327680),'forward-projectile':('v3',327680),'surface-follower':('v1',262144),'presets':('v1',131072),'splitting-arc':('v2',262144)}
NATIVE=['pose_ground_flight.hpp','pose_ground_flight.cpp','pose_timed_projectile.hpp','pose_timed_projectile.cpp','pose_timed_projectile_policy.cpp','pose_timed_projectile_tables.inc','pose_forward_projectile.hpp','pose_forward_projectile.cpp','pose_surface_follower.hpp','pose_surface_follower.cpp','pose_presets.hpp','pose_presets.cpp','pose_presets_policy.cpp','pose_splitting_arc.hpp','pose_splitting_arc.cpp','room_pose_projectiles.hpp','room_pose_projectiles.cpp','room_pose_projectiles_contract_tests.cpp','pose_work_state.hpp','pose_callbacks_contract_tests.cpp']
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert out.is_relative_to(ROOT/'tools/native_reconstruction')
 receipts={};coverage={};strict={}
 for cc in ['llvm','gcc']:
  counts={'checks':0,'cases':0}
  for name,(version,cases)in GROUPS.items():
   path=ROOT/'build-native-sjuni'/f'pose-{name}-{cc}-{version}'/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and not r['game_run']and not r['installed_in_game']and not r['stage4_complete'];assert r['observed']['cases']==cases
   assert all(body['conflicts']==0 for body in r['original_word_audits']);assert not r.get('source_drift')and not r.get('owned_source_drift')
   counts['checks']+=r['observed']['checks'];counts['cases']+=cases;receipts[path.relative_to(ROOT).as_posix()]={'sha256':sha(path),'observed':r['observed']}
   for key,digest in r['source_sha256'].items():
    if key.startswith('game/native/gameplay_world/pose_')or key.startswith('tools/native_reconstruction/verify_pose_')or key.startswith('tools/native_reconstruction/pose_'):strict[key]=digest
  assert counts=={'checks':15677003,'cases':1572864};coverage[cc]=counts
  for name,version in [('room-pose-projectiles','v2'),('pose-callbacks-current','v9'),('room-pose-projectiles-current','v1')]:
   path=ROOT/'build-native-sjuni'/f'{name}-{cc}-{version}'/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and not r['game_run']and not r['installed_in_game']and not r['stage4_complete'];assert not r.get('owned_source_drift')and not r.get('source_drift');observed=r.get('observed',r.get('result'));assert observed['owned_banks']==6
   receipts[path.relative_to(ROOT).as_posix()]={'sha256':sha(path),'observed':observed}
   for filename in NATIVE:
    key='game/native/gameplay_world/'+filename
    if key in r['source_sha256']:strict[key]=r['source_sha256'][key]
  path=ROOT/'build-native-sjuni'/f'dialogue-response-parents-{cc}-v1'/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['parent_tests']==30 and not r.get('source_drift')and not r['game_run'];receipts[path.relative_to(ROOT).as_posix()]={'sha256':sha(path),'parent_tests':r['parent_tests']}
 native=['game/native/gameplay_world/'+name for name in NATIVE]
 for key in native:assert key in strict and sha(ROOT/key)==strict[key],key
 # Check all contributed verification inputs, retaining unrelated historical
 # parent source drift only inside the immutable parent receipt, not as success
 # for changed production owned by this seal.
 for key,digest in strict.items():
  if key in native or key.startswith(('tools/native_reconstruction/verify_pose_','tools/native_reconstruction/pose_')):assert sha(ROOT/key)==digest,key
 files=native+['docs/native-gameplay/POSE_PROJECTILES.md',Path(__file__).relative_to(ROOT).as_posix()]
 for name in ['ground_flight','timed_projectile','forward_projectile','surface_follower','presets','splitting_arc']:
  files+=['tools/native_reconstruction/pose_'+name+'_tests.cpp','tools/native_reconstruction/verify_pose_'+name+'.py']
 files+=['tools/native_reconstruction/verify_room_pose_projectiles.py','tools/native_reconstruction/verify_room_pose_projectiles_current.py','tools/native_reconstruction/verify_pose_callbacks_current.py']
 cmake=ROOT/'game/native/gameplay_world/CMakeLists.txt';text=cmake.read_text();block=text[text.index('add_library(reo_native_pose_callbacks '):text.index('add_library(reo_native_dialogue ')];assert 'room_pose_projectiles_contract_tests'in block and 'pose_splitting_arc.cpp'in block and 'reo_native_linked_flight_pose'in block
 record=dict(schema=1,status='passed',game_run=False,installed_in_game=False,stage4_complete=False,coverage=coverage,receipts=receipts,production_and_verification_sha256={n:sha(ROOT/n)for n in sorted(set(files))},cmake={'path':cmake.relative_to(ROOT).as_posix(),'qualified_snapshot_sha256':sha(cmake),'pose_target_block_sha256':hashlib.sha256(block.encode()).hexdigest()},limits=['Optional non-null emitter/special visual/light/actual offset audio/parentCF2 providers remain explicit reached requirements.','Source callback parity plus bounded native room contracts do not establish full native application, installed gameplay or Stage4 acceptance.'])
 out.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps({'status':record['status'],'coverage':coverage,'receipts':len(receipts),'sources':len(record['production_and_verification_sha256']),'seal_sha256':sha(out)}))
if __name__=='__main__':main()
