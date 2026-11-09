"""Seal native selector schedules, complete dispatch and paired offline extraction."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 sources={};copies={};cohorts={}
 for group,prefix,version in [('schedule','animation-player-events','v3'),('extraction','player-event-schedule-extract','v2')]:
  previous=None
  for compiler in ['llvm','gcc']:
   p=ROOT/'build-native-sjuni'/f'{prefix}-{compiler}-{version}'/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed' and r['source_unchanged']
   if previous is not None:
    assert previous['source_sha256']==r['source_sha256']
    if group=='schedule':assert previous['observed']==r['observed']
    else:assert previous['groups']==r['groups']and previous['rows']==r['rows']
   previous=r
   for n,h in r['source_sha256'].items():
    assert sha(ROOT/n)==h and sha(p.parent/'source'/n)==h
    if n in sources:assert sources[n]==h
    sources[n]=h;copies[n]={'path':(p.parent/'source'/n).relative_to(ROOT).as_posix(),'sha256':h}
   for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h
   if group=='extraction':assert (p.parent/'player_event_schedule.inc').read_bytes()==(ROOT/'game/native/gameplay_world/player_event_schedule.inc').read_bytes()
   cohorts[group+'_'+compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'original_owned_bodies':[{k:v for k,v in x.items()if k!='comparisons'}for x in r['original_owned_bodies']]}
   for k in ['observed','rows','groups']:
    if k in r:cohorts[group+'_'+compiler][k]=r[k]
 raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();begin=0x719a60-0x570000;rows=[(struct.unpack_from('<I',raw,begin+68*i)[0],raw[begin+68*i+6])for i in range(64)];expected='// File1 action table: owned immutable metadata, 64 records.\nconstexpr std::array<ActionMetadata,64> metadata{{\n'+''.join('    {0x%xu, %du},\n'%x for x in rows)+'}};\n';assert (ROOT/'game/native/gameplay_world/animation_event_metadata.inc').read_text()==expected
 seal=ROOT/'build-native-sjuni/animation-player-events-seal-v1';assert not seal.exists();seal.mkdir()
 for n in ['docs/native-gameplay/ANIMATION_PLAYER_EVENTS.md',Path(__file__).relative_to(ROOT).as_posix()]:
  p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
 q=dict(schema=1,status='complete normal player schedules and family dispatch qualified; concrete event effects remain explicit consumer boundary',game_run=False,installed_in_game=False,stage4_complete=False,concrete_effect_consumer_complete=False,source_sha256=sources,immutable_source_evidence=copies,cohorts=cohorts,metadata={'owned_image':'build-function-index/owned-overlays/o2.bin','sha256':sha(ROOT/'build-function-index/owned-overlays/o2.bin'),'address':'0x719a60','count':64,'stride':68,'selected_bytes_sha256':hashlib.sha256(raw[begin:begin+64*68]).hexdigest()},preserved_fixture_failures=['build-native-sjuni/animation-player-events-llvm-v1/receipt.json','build-native-sjuni/animation-player-events-gcc-v1/receipt.json'],limits=['Complete original schedule/dispatch routing and declared recording-consumer oracle only; actual audio/contact/visual/task/resource-program implementation is not supplied by the recording sink.','Other real selected event families explicitly refuse; known no-work branches are admitted.','No game/performance/Stage4 completion claim.'])
 out=ROOT/'tools/native_reconstruction/native_animation_player_events_qualification_v1.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps({'path':out.relative_to(ROOT).as_posix(),'sha256':sha(out)}))
if __name__=='__main__':main()
