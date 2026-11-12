"""Compose new pose callbacks with the exact current native graph and owned rooms."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 parent=ROOT/'build-native-sjuni'/f'pose-callbacks-current-{a.compiler}-v8';prior=json.loads((parent/'receipt.json').read_bytes());assert prior['status']=='passed'
 units=['game/native/gameplay_world/room_pose_projectiles.cpp','game/native/gameplay_world/pose_splitting_arc.cpp','game/native/gameplay_world/packed_actor_audio.cpp'];fixture='game/native/gameplay_world/room_pose_projectiles_contract_tests.cpp';owned={*units,fixture,Path(__file__).relative_to(ROOT).as_posix()};frozen={}
 for name,digest in prior['source_sha256'].items():assert sha(parent/'source'/name)==digest;frozen[name]=(parent/'source'/name).read_bytes()
 pending=list(owned)
 for name in pending:
  if name not in frozen or name in owned:frozen[name]=(ROOT/name).read_bytes()
  if name.startswith('game/native/'):
   for include in re.findall(r'^\s*#include "([^"\n]+)"',frozen[name].decode(),re.M):
    path=((ROOT/name).parent/include).resolve();path=path if path.is_file()else(ROOT/include).resolve();assert path.is_file()and path.is_relative_to(ROOT);key=path.relative_to(ROOT).as_posix()
    if key not in pending:pending.append(key)
 out.mkdir(parents=True)
 for name,data in frozen.items():
  target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(data)
 libraries=[]
 for name,digest in prior['native_library_sha256'].items():
  source=parent/'libraries'/name;assert sha(source)==digest;target=out/'libraries'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,target);libraries.append(str(target))
 assets=[]
 for name in ['contact-content-v1.bin','owned_effect_geometry.bin','owned_flight_walls.bin','owned_flight_floors.bin']:
  source=parent/name;digest=prior['output_sha256'][name];assert sha(source)==digest;shutil.copyfile(source,out/name);assets.append(out/name)
 compiler=COMPILERS[a.compiler];binary=out/'checks.exe';command=[str(compiler),'-std=c++20','-O2','-msse4.1','-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/fixture),'-Wl,--gc-sections','-Wl,--start-group',*libraries,'-Wl,--end-group','-o',str(binary)];env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''));record=dict(schema=1,status='failed',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256={n:hashlib.sha256(v).hexdigest()for n,v in frozen.items()},compiler_sha256=sha(compiler),native_parent={'path':str(parent/'receipt.json'),'sha256':sha(parent/'receipt.json')},native_library_sha256=prior['native_library_sha256'],owned_assets={p.name:sha(p)for p in assets},command=command,limits=['Actual World/PoseWorkPool/Rooms/Catalog/Packets/Trails/Preset owners compose; optional source audio/visual/light providers remain explicit reached refusals.','Eight-frame kind12 initial flight is exercised in all6ownedbanks. Impact audio must be supplied before actualfour-child spawning can complete.','No installed game, device, renderer, full frame service, Stage4 acceptance or power action.'])
 try:
  for label,cmd in [('compile',command),('run',[str(binary),*[str(p)for p in assets]])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=300);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see logs'
   if label=='run':record['observed']=json.loads(result.stdout);assert record['observed']['owned_banks']==6
  owned|={n for n in pending if n not in prior['source_sha256']};record['owned_source_drift']={n:sha(ROOT/n)for n in owned if(ROOT/n).read_bytes()!=frozen[n]};assert not record['owned_source_drift'];record['subsequent_parent_changes']={n:sha(ROOT/n)for n in pending if n in prior['source_sha256']and n not in owned and(ROOT/n).read_bytes()!=frozen[n]};record.update(status='passed',binary_sha256=sha(binary))
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['observed']))
if __name__=='__main__':main()
