"""Build/test the combined native project from committed source snapshots only."""
import argparse,hashlib,json,os,re,subprocess,sys
from pathlib import Path
from prepare_native_candidate import Commit
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--revision',required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--cmake',type=Path,required=True);p.add_argument('--ninja',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
 assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
 commit=Commit(ROOT,a.revision);parent='tools/native_reconstruction/native_resident_audio_manifest_v1.json';manifest=json.loads(commit.read(parent));names=set(manifest['files'])
 names.update(n for n in commit.entries if n.startswith('game/native/gameplay_'))
 names.update('tools/native_reconstruction/'+n for n in ('compare_adx_control.py','adx_phase_oracle.py','sjuni_oracle.py'))
 names.add('tools/function_index/index.py')
 commit.preload(names);out.mkdir(parents=True);source=out/'source';hashes={}
 for n in sorted(names):
  b=commit.read(n);target=source/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(b);hashes[n]=sha(target)
 owned=ROOT/'game_data/SLUS_207.65';owned_hash='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';assert sha(owned)==owned_hash
 target=source/'game_data/SLUS_207.65';target.parent.mkdir(parents=True);target.write_bytes(owned.read_bytes());assert sha(target)==owned_hash
 record=dict(schema=1,status='failed',root_revision=commit.revision,runner_sha256=sha(Path(__file__)),parent_manifest=parent,parent_manifest_sha256=hashlib.sha256(commit.read(parent)).hexdigest(),source_sha256=hashes,owned_elf_sha256=owned_hash,owned_elf_role='identity fixture and existing ADX scalar original-word oracle only; no game run',compiler_sha256=sha(a.compiler),cmake_sha256=sha(a.cmake),ninja_sha256=sha(a.ninja),checks=[],game_run=False,stage4_complete=False)
 env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
 def run(label,command):
  print(label,flush=True);child=subprocess.run(list(map(str,command)),env=env,capture_output=True,text=True,timeout=600);(out/(label+'.txt')).write_text(child.stdout+child.stderr,encoding='utf8',newline='\n');record['checks'].append(dict(label=label,command=list(map(str,command)),exit_code=child.returncode));assert child.returncode==0,label;return child.stdout
 try:
  build=source/'build-native-sjuni/combined-build';run('configure',[a.cmake,'-S',source/'game/native','-B',build,'-G','Ninja','-DCMAKE_BUILD_TYPE=Release','-DCMAKE_MAKE_PROGRAM='+str(a.ninja),'-DCMAKE_CXX_COMPILER='+str(a.compiler)])
  run('build',[a.cmake,'--build',build,'--parallel','6'])
  ctest=a.cmake.parent/'ctest.exe';body=run('tests',[ctest,'--test-dir',build,'--output-on-failure']);match=re.search(r'100% tests passed, 0 tests failed out of (\d+)',body);assert match and int(match[1])>=82,'combined suite count'
  assert all(sha(source/n)==h for n,h in hashes.items()) and sha(target)==owned_hash and sha(owned)==owned_hash,'source snapshot drift'
  record.update(status='combined native project build and tests pass',test_count=int(match[1]),source_unchanged=True,archives_sha256={f.relative_to(out).as_posix():sha(f) for f in build.rglob('*.a')},limits=['Library/test cohort only; actual game acceptance and unported gameplay providers remain open.','The selected revision is immutable; ongoing working-tree changes are excluded.'])
 finally:
  record['outputs_sha256']={p.name:sha(p) for p in out.glob('*.txt')};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8',newline='\n')
 print(json.dumps(dict(status=record['status'],tests=record.get('test_count'),receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
