"""Qualify complete5EB520/5EB350 against canonical startup and actual owned assets."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
CMAKE=Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
NINJA=CMAKE.parent.parent.parent/'Ninja/ninja.exe'
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()

def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--archive',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';main_read=elf_reader(elf.read_bytes());overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes()
 def read(at,n):return raw[at-0x570000:at-0x570000+n]if at>=0x570000 else main_read(at,n)
 entries={};proof=[]
 for at in [0x5eb520,0x5eb350,0x5eb310,0x5ec3a0,0x66acd0,0x66ac50,0x1b0310,0x1b0300,0x1b02d0,0x1d24f0,0x1d2550,0x1d24b0]:
  bank='o2'if at>=0x570000 else'sub';directory=ROOT/('recomp/config/output_ovl/o2'if bank=='o2'else'recomp/config/output');path=next(directory.glob(f'{bank}_{at:08X}_*'));entries[at]=path
 for at in [0x18dcb0,0x1ba440,0x1af6a0,0x1b0510,0x1d3f60,0x1ac630]:
  path=next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*'));text=path.read_text();begin,end=map(lambda x:int(x,16),re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',text).groups());proof.append(compare_source('audited declared resource boundary or ignored pure getter',path.relative_to(ROOT).as_posix(),begin,end,read))
 for at,path in entries.items():
  begin,end=map(lambda x:int(x,16),re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups());proof.append(compare_source('complete startup body executed in source comparison',path.relative_to(ROOT).as_posix(),begin,end,read))
 record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),original_owned_bodies=proof,owned_elf_sha256=sha(elf),owned_o2_sha256=sha(overlay),game_run=False,stage4_complete=False,limits=['Complete5EB520/5EB350/5EB310/5EC3A0/66ACD0/66AC50 plus real branch/getter/render-mode wrapper bodies execute with declared external resource ports.','Native side composes real canonical World/Update, eight-record66A730 bootstrap, owned ActorAssets, PrimaryActorModels/HumanoidMotionOwner and actual ScenarioArchive NPC/enemy imports; source model and import helpers remain declared independently qualified boundaries.','Voice1BA440, background1AF6A0, stream-stage1B0510, resource-pump18DCB0 and remaining external render/resource consumers require explicit providers. No successful default implementation is supplied.','Native finite network room-row overflow is refused; full original comparison admits only authored four-entry reads. Runtime747400 heights and4BADF0 choice kind are controlled imported producer facts, not claimed owned constants.'])
 try:
  source=out/'source'
  for name in ['game/native','runtime','tools/native_reconstruction','recomp/overrides/native_banks']:shutil.copytree(ROOT/name,source/name,ignore=shutil.ignore_patterns('__pycache__'))
  record['source_sha256']={path.relative_to(source).as_posix():sha(path)for path in source.rglob('*')if path.is_file()}
  record['live_source_sha256']=dict(record['source_sha256'])
  originals=[]
  for path in entries.values():target=source/path.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(path.read_bytes());originals.append(target)
  record['original_source_sha256']={path.relative_to(source).as_posix():sha(path)for path in originals}
  reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n'
  (out/'reference.hpp').write_text(reference);body='\n'.join(path.read_text()for path in originals);actual={path.stem for path in originals};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual));(out/'functions.h').write_text('#pragma once\n'+decl)
  (out/'primary_startup_original.cpp').write_text(body);(out/'primary_startup_reference.inc').write_bytes((ROOT/'tools/native_reconstruction/primary_startup_reference.inc').read_bytes());(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+path.stem+'(memory,context,runtime);return;\n'for at,path in sorted(entries.items())))
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  for name in ['o2_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  table=read(0x70c0c0,0x60);record['owned_room_rows_and_pointers']=dict(address='0x70c0c0',hex=table.hex(),sha256=hashlib.sha256(table).hexdigest());(out/'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* p){const std::uint8_t b[]{'+','.join(map(str,table))+'};std::memcpy(p+0x70c0c0,b,sizeof b);}\n')
  build=out/'build';env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');stamp=a.archive.stat().st_size,a.archive.stat().st_mtime_ns
  commands=[('configure',[str(CMAKE),'-S',str(source/'game/native'),'-B',str(build),'-G','Ninja','-DCMAKE_MAKE_PROGRAM='+str(NINJA),'-DCMAKE_CXX_COMPILER='+str(a.compiler.resolve()),'-DCMAKE_BUILD_TYPE=Release','-DREO_PRIMARY_STARTUP_REFERENCE_DIR='+str(out)]),('build',[str(CMAKE),'--build',str(build),'--parallel','2','--target','primary_roster_startup_tests','primary_actor_records_tests']),('startup',[str(build/'gameplay_world/primary_roster_startup_tests.exe'),str(a.archive.resolve())]),('bootstrap',[str(build/'gameplay_world/primary_actor_records_tests.exe')])];record['commands']=commands
  # Generated original bodies contain labels and ABI arguments that are unused
  # under the direct host oracle; production warning policy remains strict.
  cmake=source/'game/native/gameplay_world/CMakeLists.txt';cmake.write_text(cmake.read_text()+'\nset_source_files_properties("'+str(out/'primary_startup_original.cpp').replace('\\','/')+'" PROPERTIES COMPILE_OPTIONS "-Wno-unused-label;-Wno-unused-parameter;-Wno-unused-variable")\n');record['source_sha256']['game/native/gameplay_world/CMakeLists.txt']=sha(cmake)
  record['observed']={}
  for name,command in commands:
   done=subprocess.run(command,env=env,capture_output=True,timeout=600);(out/(name+'.txt')).write_bytes(done.stdout+done.stderr);assert done.returncode==0,name+' failed: '+(done.stdout+done.stderr).decode(errors='replace')[-1500:]
   if name in ['startup','bootstrap']:record['observed'][name]=json.loads(done.stdout)
  assert (a.archive.stat().st_size,a.archive.stat().st_mtime_ns)==stamp
  record['snapshot_unchanged']=all(sha(source/name)==digest for name,digest in record['source_sha256'].items());assert record['snapshot_unchanged'];record['live_source_drift']=[name for name,digest in record['live_source_sha256'].items()if not(ROOT/name).is_file()or sha(ROOT/name)!=digest];record['status']='passed'
 finally:
  record['output_sha256']={name:sha(out/name)for name in ['configure.txt','build.txt','startup.txt','bootstrap.txt','reference.hpp','primary_startup_original.cpp','primary_startup_reference.inc','owned_constants.hpp']if(out/name).is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'],live_source_drift=record['live_source_drift'])))
if __name__=='__main__':main()
