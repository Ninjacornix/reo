"""Build an immutable native source snapshot and test canonical66A3A0 adoption."""
import argparse,hashlib,json,os,shutil,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
CMAKE=Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
NINJA=CMAKE.parent.parent.parent/'Ninja/ninja.exe'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
 record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),game_run=False,stage4_complete=False,limits=['Canonical Update Owner and32 ordinary worker traversals execute the actual PrimaryActorPostprocess.','Unrelated remaining phases are explicit test surroundings. Weapon attacks and floor classifications retain the limits of the complete outer-body qualification.'])
 try:
  source=out/'source'
  for directory in ['game/native','recomp/overrides/native_banks','runtime','tools/native_reconstruction']:
   shutil.copytree(ROOT/directory,source/directory,ignore=shutil.ignore_patterns('__pycache__'))
  files=sorted(path for path in source.rglob('*')if path.is_file());record['source_sha256']={path.relative_to(source).as_posix():sha(path)for path in files}
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');build=out/'build';commands=[('configure',[str(CMAKE),'-S',str(source/'game/native'),'-B',str(build),'-G','Ninja','-DCMAKE_MAKE_PROGRAM='+str(NINJA),'-DCMAKE_CXX_COMPILER='+str(a.compiler.resolve()),'-DCMAKE_BUILD_TYPE=Release']),('build',[str(CMAKE),'--build',str(build),'--parallel','2','--target','actor_postprocess_workers_tests']),('run',[str(build/'gameplay_update/actor_postprocess_workers_tests.exe')])];record['commands']=commands
  for name,command in commands:
   result=subprocess.run(command,capture_output=True,env=env,timeout=600);(out/(name+'.txt')).write_bytes(result.stdout+result.stderr);assert result.returncode==0,name+' failed'
   if name=='run':record['observed']=json.loads(result.stdout)
  record['snapshot_unchanged']=all(sha(source/name)==digest for name,digest in record['source_sha256'].items());assert record['snapshot_unchanged'];record['live_source_drift']=[name for name,digest in record['source_sha256'].items()if not(ROOT/name).is_file()or sha(ROOT/name)!=digest];record['status']='passed'
 finally:
  record['output_sha256']={name:sha(out/name)for name in ['configure.txt','build.txt','run.txt']if(out/name).is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'],live_source_drift=record['live_source_drift'])))
if __name__=='__main__':main()
