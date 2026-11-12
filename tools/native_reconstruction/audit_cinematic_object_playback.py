"""Exercise actual object/model/bank pairings; report unavailable data honestly."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True)
 for name in ['build','cmake','archive','output']:p.add_argument('--'+name,type=Path,required=True)
 a=p.parse_args();compiler=COMPILERS[a.compiler];build=a.build.resolve();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');assert Path(re.search(r'^CMAKE_CXX_COMPILER:[^=]+=([^\n]+)',(build/'CMakeCache.txt').read_text(),re.M)[1].strip()).resolve()==compiler.resolve()
 data=ROOT/'build-native-sjuni/cinematic-object-construction-llvm-v3';r=json.loads((data/'receipt.json').read_bytes());assert r['status']=='passed'
 for name in ['owned_descriptors.bin','requests.txt']:assert sha(data/name)==r['output_sha256'][name]
 assert sha(data/'owned_descriptors.bin')=='047d14cca0b28ad1f4335660db09389a525679c313f1841bfda1779c2c49629c'
 files=[x.relative_to(ROOT).as_posix()for x in(ROOT/'game/native').rglob('*')if x.is_file()and(x.suffix in ['.cpp','.hpp','.h','.inc']or x.name=='CMakeLists.txt')]+['tools/native_reconstruction/cinematic_object_playback_audit.cpp','tools/native_reconstruction/audit_cinematic_object_playback.py','runtime/assets/virtual_afs.h'];before={name:sha(ROOT/name)for name in files};stamp=a.archive.stat().st_size,a.archive.stat().st_mtime_ns;out.mkdir();record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(compiler),game_run=False,installed_in_game=False,stage4_complete=False,input_data=dict(receipt=(data/'receipt.json').relative_to(ROOT).as_posix(),receipt_sha256=sha(data/'receipt.json'),data_only=True,descriptors_sha256=sha(data/'owned_descriptors.bin'),requests_sha256=sha(data/'requests.txt')),commands=[],limits=['Native construction plus real bank and authored motion-key pair admission audit. This does not assert independent complete-original scene behavior.','Each unique authored object motion key is activated separately, at controlled scene-pose frame0, for17 updates under clock modes0 and1. Other objects remain inactive. Actual scene timing/order and actor parents are not projected.','Unavailable models/banks/slots/curve or skeleton profiles are recorded as unresolved evidence; an audit_complete receipt does not mean every case is admitted.','No game, renderer, audio, input, launcher, device or power action. Whole Step4 remains incomplete.'])
 try:
  for name in files:
   target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
  env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');binary=build/'gameplay_world/cinematic_object_playback_audit.exe';cmds=[('configure',[str(a.cmake),'-S',str(ROOT/'game/native'),'-B',str(build),'-DREO_CINEMATIC_OBJECT_PLAYBACK_AUDIT=ON']),('build',[str(a.cmake),'--build',str(build),'--parallel','4','--target','cinematic_object_playback_audit']),('audit',[str(binary),str(a.archive.resolve()),str(data/'owned_descriptors.bin'),str(data/'requests.txt'),str(out/'pairings.tsv')])]
  for label,cmd in cmds:
   done=subprocess.run(cmd,env=env,capture_output=True,timeout=240);(out/(label+'.stdout.txt')).write_bytes(done.stdout);(out/(label+'.stderr.txt')).write_bytes(done.stderr);record['commands'].append(dict(command=cmd,exit_code=done.returncode));assert done.returncode==0,label+' '+(done.stdout+done.stderr).decode(errors='replace')[-2200:]
   if label=='audit':record['observed']=json.loads(done.stdout)
  assert all(sha(ROOT/name)==h for name,h in before.items())and(a.archive.stat().st_size,a.archive.stat().st_mtime_ns)==stamp;record.update(status='audit_complete',source_unchanged=True,binary_sha256=sha(binary))
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
