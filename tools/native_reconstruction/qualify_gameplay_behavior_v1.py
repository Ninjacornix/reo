"""Freeze native behavior composition plus canonical world regressions."""
import json,hashlib
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 names=['gameplay-behavior-llvm-v4','gameplay-behavior-gcc-v2','gameplay-world-llvm-v4','gameplay-world-gcc-v2']
 paths=[ROOT/'build-native-sjuni'/n/'receipt.json' for n in names];data=[json.loads(p.read_text()) for p in paths]
 assert all(q['status']=='passed' for q in data[:2])
 assert all(q['status']=='canonical native primary world and direct input match complete originals with explicit remaining providers' and q['source_unchanged'] for q in data[2:])
 for a,b in [(data[0],data[1]),(data[2],data[3])]:assert a['source_sha256']==b['source_sha256'] and a.get('result',a.get('observed'))==b.get('result',b.get('observed'))
 source={}
 for q in data:
  for n,h in q['source_sha256'].items():
   assert sha(ROOT/n)==h,n
   assert n not in source or source[n]==h
   source[n]=h
 q=dict(schema='reo.native.gameplay.behavior.qualification.v1',status='qualified_native_primary_world_behavior_composition',stage4_complete=False,installed_in_game=False,game_launched=False,source_sha256=source,
  receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),result=d.get('result',d.get('observed')),checked_owned_instruction_comments=d.get('checked_owned_instruction_comments')) for p,d in zip(paths,data)],
  documentation_and_tools_sha256={n:sha(ROOT/n) for n in ['docs/native-gameplay/ACTOR_BEHAVIOR.md','docs/native-gameplay/PRIMARY_WORLD.md',Path(__file__).relative_to(ROOT).as_posix()]},
  limitations=['Complete original66B500/666D60/666DB0/1B0310 execute in the behavior cohort. Status/zerohealth/hit child calls use declared qualified native fixture ports; this is not their transitive original execution.','Individual action table destinations, surfaces, progression, control/cooperation and attachments remain explicit providers.','World frame comparisons execute complete669F30 and1B0B80 with declared remaining services. Actor lifetime policy is native.','No game installation, game speed/performance claim, full actor family coverage or Stage4 completion is established.'])
 out=ROOT/'tools/native_reconstruction/native_gameplay_behavior_qualification_v1.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n',encoding='utf-8');print(out.relative_to(ROOT),sha(out))
if __name__=='__main__':main()
