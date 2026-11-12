"""Seal canonical actor sound consumers and the shared projectile visual controller."""
import argparse,hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
NATIVE=['game/native/gameplay_world/'+n for n in ['actor_offset_sound_policy.hpp','actor_offset_sound_policy.cpp','canonical_actor_sounds.hpp','canonical_actor_sounds.cpp','forward_pose_visuals.hpp','forward_pose_visuals.cpp']]+['game/native/gameplay_effects/'+n for n in ['periodic_visuals.hpp','periodic_visuals.cpp','projectile_trail.hpp','projectile_trail.cpp','projectile_trail_owner_tests.cpp']]
TOOLS=['actor_offset_sound_policy_tests.cpp','verify_actor_offset_sound_policy.py','actor_sound_ownership_tests.cpp','verify_actor_sound_ownership.py','projectile_trail_tests.cpp','verify_projectile_trail.py','verify_projectile_trail_owner.py','verify_projectile_trail_owner_current.py','qualify_actor_audio_projectiles.py']
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert out.is_relative_to(ROOT/'tools/native_reconstruction');receipts={};native_seen={}
 groups=[('actor-offset-sound-policy','v1',262144),('actor-sound-ownership','v5',65792),('projectile-trail','v2',262144),('projectile-trail-owner-current','v1',None),('projectile-trail-owner','v1',None)]
 for cc in ['llvm','gcc']:
  for name,version,cases in groups:
   path=ROOT/'build-native-sjuni'/f'{name}-{cc}-{version}'/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and not r['game_run']and not r['installed_in_game']and not r['stage4_complete'];assert not r.get('source_drift')and not r.get('owned_source_drift');observed=r.get('observed',r.get('result'))
   if cases is not None:assert observed['cases']==cases
   if name=='actor-sound-ownership':assert observed['owned_banks']==6 and observed['signal_samples']==52842 and observed['split_passes']==78
   if name.startswith('projectile-trail-owner'):assert observed['owned_banks']==6 and observed['constructors']==846 and observed['frames']==20 and observed['budget_cases']==5 and observed['identity_cases']==5
   for body in r.get('original_owned_bodies',r.get('original_word_audits',[])):assert body['conflicts']==0
   for key,digest in r['source_sha256'].items():
    if key in NATIVE:native_seen[key]=digest;assert sha(ROOT/key)==digest,key
   receipts[path.relative_to(ROOT).as_posix()]={'sha256':sha(path),'observed':observed}
  path=ROOT/'build-native-sjuni'/f'session-resources-parents-{cc}-v1'/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and not r['source_drift']and r['parent_tests']==31;receipts[path.relative_to(ROOT).as_posix()]={'sha256':sha(path),'parent_tests':31}
  for key in NATIVE:assert r['source_sha256'][key]==sha(ROOT/key),key
 for key in NATIVE:assert key in native_seen,key
 metadata=ROOT/'tools/native_reconstruction/native_actor_sound_state_qualification_v1.json';assert sha(metadata)=='0fa1b8adb9e7178eba9398fcf832cfe8eaa01702655ecaf96b616317e52b7b2c'
 files=NATIVE+['tools/native_reconstruction/'+n for n in TOOLS]+['docs/native-gameplay/ACTOR_SOUND_CONSUMERS.md','docs/native-gameplay/PROJECTILE_TRAIL_CONTROLLER.md'];cmake={}
 for name,needles in {'game/native/gameplay_effects/CMakeLists.txt':['target_sources(reo_native_gameplay_effects PRIVATE projectile_trail.cpp)','add_executable(projectile_trail_owner_tests projectile_trail_owner_tests.cpp)'],'game/native/gameplay_world/CMakeLists.txt':['target_sources(reo_native_linked_flight_pose PRIVATE actor_offset_sound_policy.cpp canonical_actor_sounds.cpp)','target_sources(reo_native_pose_callbacks PRIVATE forward_pose_visuals.cpp)']}.items():
  text=(ROOT/name).read_text();assert all(line in text for line in needles);cmake[name]={'qualified_snapshot_sha256':sha(ROOT/name),'required_registration':needles}
 record=dict(schema=1,status='passed',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256={n:sha(ROOT/n)for n in files},cmake=cmake,metadata_producer_seal={'path':metadata.relative_to(ROOT).as_posix(),'sha256':sha(metadata)},receipts=receipts,limits=['Audio uses canonical metadata,actualbank/spatial/RNG/PCM owners; nonzero population/attackmetadata producers and appaudiohost remain separate.','Controller sharesactual168work/256childpools; immutable renderrecipe is aStage5handoff,notpixelparity orinstalledgameplay.','Specialground/light/follower constructors,terminalframe/physics/behavior,fullstartup/EVBadmissionandendtoendStage4acceptance remainopen.'])
 out.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps({'status':'passed','receipts':len(receipts),'sources':len(files),'seal_sha256':sha(out)}))
if __name__=='__main__':main()
