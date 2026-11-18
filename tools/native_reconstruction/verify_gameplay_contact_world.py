"""Qualify the canonical World/model/room contact adapter with real native owners.

No original bodies, live game, network, audio or renderer are invoked here.
The separately retained shape/impact/population cohorts qualify source policy;
this cohort checks the actual canonical reference/identity/lifetime composition.
"""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
UNITS={
 'gameplay_contact_world':['contacts','tests'],
 'gameplay_world':['world','model_poses'],
 'animation':['model','model_math','curves'],
 'transform_math':['transform_math'],
 'gameplay_actors':['entity','input','health'],
 'gameplay_session':['session'],
 'gameplay_scenario':['scene_controls','scene_models','scene_model_bindings','flags','content','scene_matrix_programs','scene_matrix_tables'],
 'gameplay_collision':['collision','response','actors','ownership','sweep','room_objects','hit_regions','spatial','directed','radius','trace','delivery','contact_scan','contact_content','contact_packets','packet_service','packet_shapes','impact_policy','impact_populations']}
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',required=True,type=Path);a=p.parse_args();out=a.output.resolve()
 if out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni')or out==ROOT/'build-native-sjuni':raise ValueError('Fresh private output required')
 units=[ROOT/'game/native'/group/(name+'.cpp')for group,names in UNITS.items()for name in names]
 pending=units.copy();closure=set(units)
 while pending:
  source=pending.pop()
  for name in re.findall(r'^\s*#include "([^"\n]+)"',source.read_text(),re.M):
   target=next((path.resolve()for path in [source.parent/name,ROOT/name]if path.is_file()),None)
   if not target or not target.is_relative_to(ROOT/'game/native'):raise ValueError('Unknown native include '+name)
   if target not in closure:closure.add(target);pending.append(target)
 closure.add(Path(__file__).resolve());closure.add(ROOT/'game/native/gameplay_contact_world/CMakeLists.txt')
 before={source.relative_to(ROOT).as_posix():source.read_bytes()for source in sorted(closure)}
 out.mkdir()
 for name,data in before.items():
  target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(data)
 references={}
 for name in ['packet_shapes_qualification_v2','impact_policy_qualification_v1','impact_populations_qualification_v2','packet_service_qualification_v1']:
  path=ROOT/'tools/native_reconstruction'/('native_gameplay_'+name+'.json');references[path.relative_to(ROOT).as_posix()]=sha(path)
 cc=COMPILERS[a.compiler];exe=out/'world-contact.exe';env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','')
 command=[str(cc),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-ffp-contract=off','-fno-fast-math','-I'+str(out/'source'),*[str(out/'source'/source.relative_to(ROOT))for source in units],'-o',str(exe)]
 record=dict(schema=1,status='failed',source_sha256={name:hashlib.sha256(data).hexdigest()for name,data in before.items()},compiler_sha256=sha(cc),policy_evidence_sha256=references,original_bodies_executed=False,game_launched=False,installed_in_game=False,whole_stage4_complete=False,checks=[])
 try:
  for label,cmd in [('compile',command),('test',[str(exe)])]:
   result=subprocess.run(cmd,env=env,capture_output=True,timeout=180);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append(dict(label=label,command=cmd,exit=result.returncode))
   if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-4000:])
   if label=='test':record['results']=json.loads(result.stdout)
  for name,data in before.items():
   if (ROOT/name).read_bytes()!=data:raise ValueError('Source changed during frozen cohort: '+name)
  record['status']='canonical World contact reference, generation, pose, matrix-channel and service composition passed'
 finally:
  record['output_sha256']={source.relative_to(out).as_posix():sha(source)for source in out.rglob('*')if source.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['results']))
if __name__=='__main__':main()
