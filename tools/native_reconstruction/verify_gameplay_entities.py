"""Seal and test native entity lifetime policy without a game/runtime dependency."""
import argparse,hashlib,json,os,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
 assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
 files=['game/native/gameplay_actors/'+n for n in ('entity.hpp','entity.cpp','entity_tests.cpp')]+['tools/native_reconstruction/verify_gameplay_entities.py'];before={n:sha(ROOT/n) for n in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),source_sha256=before,original_body_comparison=False,game_run=False,stage4_complete=False)
 try:
  core=out/'source';core.mkdir()
  for n in ('entity.hpp','entity.cpp','entity_tests.cpp'):(core/n).write_bytes((ROOT/'game/native/gameplay_actors'/n).read_bytes())
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'entities.exe'
  command=[str(a.compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror',str(core/'entity.cpp'),str(core/'entity_tests.cpp'),'-o',str(binary)];record['command']=command
  c=subprocess.run(command,env=env,capture_output=True,text=True,timeout=120);(out/'compile.txt').write_text(c.stdout+c.stderr,encoding='utf8',newline='\n');assert c.returncode==0,'entity compilation'
  c=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=30);(out/'run.txt').write_text(c.stdout+c.stderr,encoding='utf8',newline='\n');assert c.returncode==0,'entity ownership'
  result=json.loads(c.stdout);assert result['status']=='passed' and result['checks']>1000
  assert all(sha(ROOT/n)==h for n,h in before.items());record.update(status='native entity lifetime policy passes',observed=result,source_unchanged=True,binary_sha256=sha(binary),limits=['New native lifetime policy, not an emulation of legacy allocation.','Payload is typed native Entity; concrete full actor-family state and real consumers remain to migrate.','Single simulation-owner thread; this does not qualify concurrent actor access.'])
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p) for p in out.rglob('*') if p.is_file() and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8',newline='\n')
 print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
