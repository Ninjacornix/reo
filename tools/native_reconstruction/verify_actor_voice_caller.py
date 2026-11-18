"""Compare complete ordinary voice caller and reached stream bodies in a native session."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
CMAKE=Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
NINJA=CMAKE.parent.parent.parent/'Ninja/ninja.exe'
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()

def main():
 p=argparse.ArgumentParser()
 for name in ['compiler','archive','audio-archive','output']:p.add_argument('--'+name,type=Path,required=True)
 a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes())
 entries={};proof=[]
 for at in [0x1ba250,0x1ba170,0x1ada20,0x1adfd0,0x1adf50,0x1ae2e0,0x1ae3f0]:
  path=next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*'));begin,end=[int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];proof.append(compare_source('complete ordinary voice caller or reached stream body executed',path.relative_to(ROOT).as_posix(),begin,end,read));entries[at]=path
 parents=[ROOT/'tools/native_reconstruction/native_gameplay_audio_qualification_v1.json',ROOT/'build-native-sjuni/actor-voice-archives-gcc-v2/receipt.json',ROOT/'build-native-sjuni/actor-voice-archives-llvm-v2/receipt.json',ROOT/'build-native-sjuni/primary-roster-startup-assets-v2/receipt.json']
 result=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),owned_elf_sha256=sha(elf),original_owned_bodies=proof,parents=[dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path))for path in parents],game_run=False,audio_device_opened=False,stage4_complete=False,limits=['Complete1BA250/1BA170 and reached stream bodies execute against actual native World actors, one caller-owned StreamChannels and the real archive capability. NativeSession has no existing stream-channel owner; no duplicate authoritative owner is installed.','SDK stream output primitives and feature flags disabled are controlled test surroundings. Native archives and startup bridge use three real StreamInstances, while the additional real consumer advances one owned decoder source without a device.','1B94B0 is a separately qualified spatial boundary with fixed source-known gains. Native requests run actual locate(); this suite does not re-execute that helper body.','NPC/common archive slot5 is unavailable. Successful startup includes explicit controlled remaining render/resource operations; it is not a full authored game launch.'])
 try:
  source=out/'source'
  for name in ['game/native','runtime','tools/native_reconstruction','recomp/overrides/native_banks']:shutil.copytree(ROOT/name,source/name,ignore=shutil.ignore_patterns('__pycache__'))
  result['source_sha256']={path.relative_to(source).as_posix():sha(path)for path in source.rglob('*')if path.is_file()};result['live_source_sha256']=dict(result['source_sha256'])
  reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n';(out/'reference.hpp').write_text(reference);shutil.copyfile(ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',out/'ps2_fpu_convert.h')
  body='\n'.join(path.read_text()for path in entries.values());actual={path.stem for path in entries.values()};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+path.stem+'(memory,context,runtime);return;\n'for at,path in entries.items()));shutil.copyfile(ROOT/'tools/native_reconstruction/actor_voice_caller_reference.inc',out/'actor_voice_caller_reference.inc')
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  constants=[]
  for at,size in [(0x234060,512),(0x234bf4,4),(0x234890,68)]:
   data=read(at,size);constants.append('{const std::uint8_t b[]{'+','.join(map(str,data))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}')
  (out/'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* p){\n'+'\n'.join(constants)+'\n}\n')
  cmake=source/'game/native/gameplay_application/CMakeLists.txt';cmake.write_text(cmake.read_text()+'\nset_source_files_properties("'+str(out/'original.cpp').replace('\\','/')+'" PROPERTIES COMPILE_OPTIONS "-Wno-unused-label;-Wno-unused-parameter;-Wno-unused-variable")\n');result['source_sha256'][cmake.relative_to(source).as_posix()]=sha(cmake)
  build=out/'build';env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');stamps=[(path.stat().st_size,path.stat().st_mtime_ns)for path in [a.archive,a.audio_archive]]
  commands=[('configure',[str(CMAKE),'-S',str(source/'game/native'),'-B',str(build),'-G','Ninja','-DCMAKE_MAKE_PROGRAM='+str(NINJA),'-DCMAKE_CXX_COMPILER='+str(a.compiler.resolve()),'-DCMAKE_BUILD_TYPE=Release','-DREO_ACTOR_VOICE_CALLER_REFERENCE_DIR='+str(out)]),('build',[str(CMAKE),'--build',str(build),'--parallel','2','--target','actor_voice_tests']),('run',[str(build/'gameplay_application/actor_voice_tests.exe'),str(a.archive.resolve()),str(a.audio_archive.resolve())])];result['commands']=commands
  for name,command in commands:
   done=subprocess.run(command,capture_output=True,env=env,timeout=1500);(out/(name+'.txt')).write_bytes(done.stdout+done.stderr);assert done.returncode==0,name+' failed: '+(done.stdout+done.stderr).decode(errors='replace')[-2000:]
   if name=='run':result['observed']=json.loads(done.stdout)
  assert stamps==[(path.stat().st_size,path.stat().st_mtime_ns)for path in [a.archive,a.audio_archive]];result['snapshot_unchanged']=all(sha(source/name)==digest for name,digest in result['source_sha256'].items());assert result['snapshot_unchanged'];result['live_source_drift']=[name for name,digest in result['live_source_sha256'].items()if not(ROOT/name).is_file()or sha(ROOT/name)!=digest];result['status']='passed'
 finally:
  result['output_sha256']={name:sha(out/name)for name in ['configure.txt','build.txt','run.txt','original.cpp','actor_voice_caller_reference.inc','reference.hpp','functions.h','original_dispatch.hpp','owned_constants.hpp','ps2_fpu_convert.h']if(out/name).is_file()};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps(dict(status=result['status'],observed=result['observed'],live_source_drift=result['live_source_drift'])))
if __name__=='__main__':main()
