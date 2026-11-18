"""Freeze native surface consumers plus native behavior/world regressions."""
import json,hashlib
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 names=['gameplay-surfaces-llvm-v3','gameplay-surfaces-gcc-v2','gameplay-behavior-llvm-v6','gameplay-behavior-gcc-v4','gameplay-world-llvm-v5','gameplay-world-gcc-v3']
 paths=[ROOT/'build-native-sjuni'/n/'receipt.json' for n in names];data=[json.loads(p.read_text()) for p in paths]
 assert all(q['status']=='passed' for q in data[:4])
 assert all(q['status']=='canonical native primary world and direct input match complete originals with explicit remaining providers' and q['source_unchanged'] for q in data[4:])
 for a,b in [(data[0],data[1]),(data[2],data[3]),(data[4],data[5])]:assert a['source_sha256']==b['source_sha256'] and a.get('result',a.get('observed'))==b.get('result',b.get('observed'))
 source={}
 for q in data:
  for n,h in q['source_sha256'].items():
   assert sha(ROOT/n)==h,n
   assert n not in source or source[n]==h
   source[n]=h
 q=dict(schema='reo.native.gameplay.surfaces.qualification.v1',status='qualified_native_floor_actor_behavior_composition',stage4_complete=False,installed_in_game=False,game_launched=False,source_sha256=source,
  receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),result=d.get('result',d.get('observed')),checked_owned_instruction_comments=d.get('checked_owned_instruction_comments')) for p,d in zip(paths,data)],
  documentation_and_tools_sha256={n:sha(ROOT/n) for n in ['docs/native-gameplay/ACTOR_BEHAVIOR.md','docs/native-gameplay/PRIMARY_WORLD.md',Path(__file__).relative_to(ROOT).as_posix()]},
  surface_scope=dict(original_cases=16384,special_surfaces=3129,transform_rollbacks=2331,native_floor_query_is_declared_port=True,synthetic_grids=True),
  limitations=['Complete666580/666450/616ED0/616F20 execute with a declared independently qualified617000 query. Surface type81 filtering is preserved without inventing its gameplay purpose.','Complete original66B500/666D60/666DB0/1B0310 execute in the behavior cohort. Status/zerohealth/hit child calls use declared qualified native fixture ports; this is not their transitive original execution.','Individual action table destinations, progression, control/cooperation and attachments remain explicit providers; supplied native floors retire the two surface effects.','World frame comparisons execute complete669F30 and1B0B80 with declared remaining services. Actor lifetime policy is native.','No game installation, game speed/performance claim, full actor family coverage or Stage4 completion is established.'])
 out=ROOT/'tools/native_reconstruction/native_gameplay_surfaces_qualification_v1.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n',encoding='utf-8');print(out.relative_to(ROOT),sha(out))
if __name__=='__main__':main()
