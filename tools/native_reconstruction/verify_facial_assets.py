"""Verify the complete owned File1 facial catalogue and actual sector reads."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 inventory=ROOT/'build-native-sjuni/facial-resource-inventory-v2/receipt.json';data=json.loads(inventory.read_bytes());assert data['status']=='passed'
 units=['game/native/gameplay_scenario/facial_assets.cpp','game/native/animation/facial_curves.cpp','game/native/transform_math/transform_math.cpp'];fixture='tools/native_reconstruction/facial_assets_tests.cpp';files={*units,fixture,Path(__file__).relative_to(ROOT).as_posix()};pending=list(files)
 while pending:
  name=pending.pop()
  for include in re.findall(r'^#include "([^\"]+)"',(ROOT/name).read_text(),re.M):
   target=((ROOT/name).parent/include).resolve();target=target if target.is_file()else(ROOT/include).resolve();assert target.is_file()and target.is_relative_to(ROOT);relative=target.relative_to(ROOT).as_posix()
   if relative not in files:files.add(relative);pending.append(relative)
 before={name:sha(ROOT/name)for name in sorted(files)};out.mkdir()
 for name in files:
  target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
 manifest=[]
 for row in data['matrix_assets']:
  actor=re.fullmatch(r'MOTION_FACE_(HP\d{2}|HN\d{2,3})_MAT',row['key'])[1];manifest.append([0 if actor.startswith('HP')else 1,int(actor[2:]),0,0,0,0,row['archive_offset'],row['logical_bytes'],row['storage_bytes']])
 for row in data['lip_assets']:manifest.append([2,0,*row['identity'],row['archive_offset'],row['logical_bytes'],row['storage_bytes']])
 (out/'assets.txt').write_text('\n'.join(' '.join(map(str,row))for row in manifest)+'\n')
 prior=json.loads((ROOT/'build-native-sjuni/primary-scene-scope-llvm-v4/receipt.json').read_bytes());archive=Path(prior['commands'][2]['command'][1]);stamp=archive.stat().st_size,archive.stat().st_mtime_ns;assert data['archive_identity']==dict(size=stamp[0],mtime_ns=stamp[1])
 compiler=COMPILERS[a.compiler];env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''));exe=out/'checks.exe';command=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/fixture),'-o',str(exe)]
 record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(compiler),inventory=dict(path=inventory.relative_to(ROOT).as_posix(),sha256=sha(inventory)),command=command,game_run=False,stage4_complete=False,limits=['Actual Source/AFS parsing and all51 sector payloads execute; expected bytes are independent positioned reads from the retained original archive. Static compiled-key/source authority comes from the pinned full facial resource inventory. This does not re-execute the SDK lookup/scheduler source chain, or establish actor playback lifetime.'])
 try:
  result=subprocess.run(command,env=env,capture_output=True,timeout=240);(out/'compile.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'compile failed'
  record['run_command']=[str(exe),str(archive),str(out/'assets.txt')];result=subprocess.run(record['run_command'],env=env,capture_output=True,timeout=180);(out/'run.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'asset comparison failed';assert stamp==(archive.stat().st_size,archive.stat().st_mtime_ns)
  record.update(status='passed',observed=json.loads(result.stdout),source_drift={name:sha(ROOT/name)for name,digest in before.items()if sha(ROOT/name)!=digest});assert not record['source_drift']
 finally:
  record['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.rglob('*')if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['observed']))
if __name__=='__main__':main()
