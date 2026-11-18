"""Capture the actual current CMake dialogue worker and canonical parent contracts."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def sources(build,targets):
 rules={}
 for line in (build/'build.ninja').read_text().splitlines():
  match=re.match(r'^build ([^:]+): \S+\s*(.*)',line)
  if match:
   for output in match[1].split():rules[output]=match[2].split()
 pending=[]
 for target in targets:
  found=[name for name in rules if name.endswith('/'+target+'.exe')];assert len(found)==1,(target,found);pending+=found
 visited=set();found=set()
 while pending:
  node=pending.pop()
  if node in visited:continue
  visited.add(node)
  for dependency in rules.get(node,[]):
   if dependency.endswith(('.a','.obj')):pending.append(dependency)
   elif dependency.endswith('.cpp'):
    path=Path(dependency.replace('$:',':')).resolve();assert path.is_file()and path.is_relative_to(ROOT);found.add(path)
 pending=list(found)
 while pending:
  path=pending.pop()
  for name in re.findall(r'#\s*include\s*"([^\"]+)"',path.read_text()):
   item=next((value.resolve()for value in(path.parent/name,ROOT/name)if value.is_file()),None)
   if item and item.is_relative_to(ROOT)and item not in found:found.add(item);pending.append(item)
 found.add(Path(__file__).resolve());found.add(ROOT/'game/native/CMakeLists.txt')
 for path in tuple(found):
  if(path.parent/'CMakeLists.txt').is_file():found.add(path.parent/'CMakeLists.txt')
 return sorted(found)
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--cmake',type=Path,required=True);p.add_argument('--build',type=Path,required=True);p.add_argument('--baseline',type=Path,required=True);p.add_argument('--archive',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
 out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir();base=json.loads(a.baseline.read_text());assert base['status']=='passed'and base['parent_tests']==28
 targets=base['commands'][0][4:-2]+['dialogue_workers_tests','room_pose_projectiles_contract_tests'];assert len(targets)==30 and len(set(targets))==30
 pattern=base['commands'][1][-1];pattern=pattern[:-2]+'|dialogue_workers|room_pose_projectiles_contract)$'
 record=dict(schema=1,status='failed',game_run=False,stage4_complete=False,audio_device_opened=False,compiler_sha256=sha(a.compiler),source_sha256={},commands=[],parent_tests=len(targets),source_drift={})
 env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
 def run(command,label):
  done=subprocess.run(list(map(str,command)),capture_output=True,env=env,timeout=600);(out/(label+'.log')).write_bytes(done.stdout+done.stderr);record['commands'].append(list(map(str,command)));assert done.returncode==0,label+': '+(done.stdout+done.stderr).decode(errors='replace')[-3000:];return done.stdout.decode(errors='replace')
 try:
  run([a.cmake,'-S',ROOT/'game/native','-B',a.build],'configure')
  record['source_sha256']={path.relative_to(ROOT).as_posix():sha(path)for path in sources(a.build,targets)}
  run([a.cmake,'--build',a.build,'--target',*targets,'--parallel','2'],'build')
  result=run([a.cmake.parent/'ctest.exe','--test-dir',a.build,'--output-on-failure','-R',pattern],'tests');assert '100% tests passed, 0 tests failed out of 30'in result
  before=(a.archive.stat().st_size,a.archive.stat().st_mtime_ns);record['owned_worker_output']=run([a.build/'gameplay_application/dialogue_workers_tests.exe',a.archive],'owned-dialogue-worker').strip();assert before==(a.archive.stat().st_size,a.archive.stat().st_mtime_ns);record['owned_archive_identity']=dict(size=before[0],mtime_ns=before[1])
  record['source_drift']={name:sha(ROOT/name)for name,digest in record['source_sha256'].items()if not(ROOT/name).is_file()or sha(ROOT/name)!=digest};assert not record['source_drift'];record['status']='passed'
 finally:
  record['output_sha256']={path.name:sha(path)for path in out.iterdir()if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],parent_tests=record['parent_tests'],owned_worker=record.get('owned_worker_output'))))
if __name__=='__main__':main()
