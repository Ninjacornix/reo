"""Qualify canonical NativeSession adoption and rerun complete original startup."""
import argparse,hashlib,json,os,shutil,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc
CMAKE=Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
NINJA=CMAKE.parent.parent.parent/'Ninja/ninja.exe'
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser()
 for name in ['compiler','archive','startup-reference','output']:p.add_argument('--'+name,type=Path,required=True)
 a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
 reference=a.startup_reference.resolve();receipt_path=reference/'receipt.json';parent=json.loads(receipt_path.read_bytes());assert parent['status']=='passed'and parent['snapshot_unchanged']
 asset_path=ROOT/'build-native-sjuni/primary-roster-startup-assets-v2/receipt.json';asset_parent=json.loads(asset_path.read_bytes());assert asset_parent['status']=='passed'
 result=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),original_startup_receipt=dict(path=receipt_path.relative_to(ROOT).as_posix(),sha256=sha(receipt_path)),owned_elf_sha256=parent['owned_elf_sha256'],owned_o2_sha256=parent['owned_o2_sha256'],original_owned_bodies=parent['original_owned_bodies'],game_run=False,stage4_complete=False,limits=['Application adoption borrows one real NativeSession World/Update/Archive/RoomState, owns one exclusive actual model/motion capability set and requires explicitly supplied initial banks.','External voice/render/resource operations are controlled declared test surroundings. Production has no successful default provider. No game frame, audio device or renderer is started.','The complete original5EB520/5EB350 source suite is rerun against this current immutable application closure; selected model/import source helpers retain the declared separately qualified boundaries.','Installed r0417300 plus roster kind0 is an explicit finite owner-composition fixture. It does not assert an authored full launch flow or actor placement in that room.'])
 try:
  source=out/'source'
  for name in ['game/native','runtime','tools/native_reconstruction','recomp/overrides/native_banks']:shutil.copytree(ROOT/name,source/name,ignore=shutil.ignore_patterns('__pycache__'))
  result['source_sha256']={path.relative_to(source).as_posix():sha(path)for path in source.rglob('*')if path.is_file()};result['live_source_sha256']=dict(result['source_sha256'])
  inherited=out/'original';inherited.mkdir()
  for name in ['reference.hpp','functions.h','original_dispatch.hpp','owned_constants.hpp','primary_startup_reference.inc','primary_startup_original.cpp','ps2_runtime.h','ps2_runtime_macros.h','o2_functions.h','ps2_recompiled_functions.h','ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:
   if name in parent['output_sha256']:assert sha(reference/name)==parent['output_sha256'][name]
   shutil.copyfile(reference/name,inherited/name)
  result['original_reference_sha256']={path.name:sha(path)for path in inherited.iterdir()}
  cmake=source/'game/native/gameplay_world/CMakeLists.txt';cmake.write_text(cmake.read_text()+'\nset_source_files_properties("'+str(inherited/'primary_startup_original.cpp').replace('\\','/')+'" PROPERTIES COMPILE_OPTIONS "-Wno-unused-label;-Wno-unused-parameter;-Wno-unused-variable")\n');result['source_sha256']['game/native/gameplay_world/CMakeLists.txt']=sha(cmake)
  inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';members=json.loads(inventory.read_bytes());selected={row['member']:row for row in asset_parent['assets']}
  for basename in ['r041.npc','e041.emd','sgl_e041.emd','r0417300.rdt']:
   rows=[row for row in members if [name.lower()for name in row['names']]==['r041.afs',basename]];assert len(rows)==1;selected[rows[0]['member']]=rows[0]
  stamp=a.archive.stat().st_size,a.archive.stat().st_mtime_ns;tables={};result['owned_assets']=[]
  with a.archive.open('rb')as stream:
   for key,row in selected.items():
    base=0;names=[]
    for ordinal in map(int,key.split('/')[1:]):
     if base not in tables:tables[base]=read_toc(stream,base)
     table=tables[base];offset,size=table[0][ordinal];names.append(table[2][ordinal][0]);base+=offset
    stream.seek(base);data=stream.read(size);assert len(data)==size==row['bytes']and hashlib.sha256(data).hexdigest()==row['sha256']and [name.lower()for name in names]==[name.lower()for name in row['names']];result['owned_assets'].append(dict(member=key,names=names,offset=base,bytes=size,sha256=row['sha256']))
  build=out/'build';env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
  commands=[('configure',[str(CMAKE),'-S',str(source/'game/native'),'-B',str(build),'-G','Ninja','-DCMAKE_MAKE_PROGRAM='+str(NINJA),'-DCMAKE_CXX_COMPILER='+str(a.compiler.resolve()),'-DCMAKE_BUILD_TYPE=Release','-DREO_PRIMARY_STARTUP_REFERENCE_DIR='+str(inherited)]),('build',[str(CMAKE),'--build',str(build),'--parallel','2','--target','session_startup_tests','primary_roster_startup_tests','native_session_tests']),('fixtures',[str(build/'gameplay_application/session_startup_tests.exe')]),('owned',[str(build/'gameplay_application/session_startup_tests.exe'),str(a.archive.resolve())]),('original_startup',[str(build/'gameplay_world/primary_roster_startup_tests.exe'),str(a.archive.resolve())]),('host_regression',[str(build/'gameplay_application/native_session_tests.exe'),str(a.archive.resolve())])];result['commands']=commands;result['observed']={}
  for name,command in commands:
   done=subprocess.run(command,capture_output=True,env=env,timeout=1200 if name=='build'else 600);(out/(name+'.txt')).write_bytes(done.stdout+done.stderr);assert done.returncode==0,name+' failed: '+(done.stdout+done.stderr).decode(errors='replace')[-1200:]
   if name not in ['configure','build']:result['observed'][name]=json.loads(done.stdout)
  assert stamp==(a.archive.stat().st_size,a.archive.stat().st_mtime_ns)
  result['snapshot_unchanged']=all(sha(source/name)==digest for name,digest in result['source_sha256'].items());assert result['snapshot_unchanged'];result['live_source_drift']=[name for name,digest in result['live_source_sha256'].items()if not(ROOT/name).is_file()or sha(ROOT/name)!=digest];result['status']='passed'
 finally:
  result['output_sha256']={name:sha(out/name)for name in ['configure.txt','build.txt','fixtures.txt','owned.txt','original_startup.txt','host_regression.txt']if(out/name).is_file()};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps(dict(status=result['status'],observed=result['observed'],live_source_drift=result['live_source_drift'])))
if __name__=='__main__':main()
