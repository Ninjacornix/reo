"""Seal canonical actor metadata/actualclear producers and matching source contracts."""
import argparse,hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
FILES=['game/native/gameplay_world/world.hpp','game/native/gameplay_world/actor_sound_state.hpp','game/native/gameplay_world/actor_initial_state.hpp','game/native/gameplay_world/linked_models.cpp','game/native/gameplay_world/primary_actor_records_tests.cpp','docs/native-gameplay/ACTOR_SOUND_STATE.md','tools/native_reconstruction/qualify_actor_sound_state.py']
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert out.is_relative_to(ROOT/'tools/native_reconstruction');receipts={}
 for cc in ['llvm','gcc']:
  path=ROOT/'build-native-sjuni'/f'actor-audio-clear-{cc}-v1'/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged']and not r['game_run'];assert r['observed']['checks']==2242399 and r['observed']['complete_source_clears']==64 and r['observed']['lifetimes']==512;receipts[path.relative_to(ROOT).as_posix()]={'sha256':sha(path),'observed':r['observed']}
  for name in ['actor_sound_state.hpp','actor_initial_state.hpp','primary_actor_records_tests.cpp']:
   key='game/native/gameplay_world/'+name;assert r['source_sha256'][key]==sha(ROOT/key),key
  path=ROOT/'build-native-sjuni'/f'dialogue-response-parents-{cc}-v2'/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and not r['source_drift']and r['parent_tests']==30;receipts[path.relative_to(ROOT).as_posix()]={'sha256':sha(path),'parent_tests':30}
  for name in ['actor_sound_state.hpp','actor_initial_state.hpp','linked_models.cpp']:
   key='game/native/gameplay_world/'+name;assert r['source_sha256'][key]==sha(ROOT/key),key
  # Only later no-data friend declarations are allowed outside the actor
  # schema captured by the actual full-clear/currentparent cohorts.
  captured=(ROOT/'build-native-sjuni'/f'dialogue-responses-{cc}-v8-snapshot'/'source/game/native/gameplay_world/world.hpp').read_text();live=(ROOT/'game/native/gameplay_world/world.hpp').read_text()
  normalized=live.replace('class ResourceBootstrap;class SessionResources;','class ResourceBootstrap;').replace('    friend class gameplay_application::SessionResources;\n','');assert normalized==captured,'UnqualifiedWorldheaderchange'
  for line in ['    std::optional<ActorSoundState> sound_state; //554/33; actual full-record producer required','    std::optional<std::uint8_t> projectile_variant; //CF2; ordinary-family producer required']:
   assert line in captured and line in live
 path=ROOT/'build-native-sjuni/linked-model-profile-v1/receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['linked_domain']['capacity']==50 and r['linked_domain']['source_stride']=='0xd90';assert 50*0xd90==0x2a620;assert any(v['start']=='0x6ba260'and not v['conflicts']for v in r['original_owned_bodies']);receipts[path.relative_to(ROOT).as_posix()]={'sha256':sha(path),'linked_domain':r['linked_domain']}
 record=dict(schema=1,status='passed',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256={n:sha(ROOT/n)for n in FILES},receipts=receipts,limits=['Metadata producer/state only. No assertion that nonzero population audio assignment or changingCF2attack producers are complete.','Worldheaderaddsreadonlycontrolleraccess/friendswithoutnewWorldfields. Laterconsumer/app checkpoints must qualify their own coherent layouts and owners.'])
 out.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps({'status':'passed','receipts':len(receipts),'sources':len(FILES),'seal_sha256':sha(out)}))
if __name__=='__main__':main()
