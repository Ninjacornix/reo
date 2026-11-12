"""Qualify canonical actor archive activation against complete owned main bodies."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
CMAKE=Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
NINJA=CMAKE.parent.parent.parent/'Ninja/ninja.exe'
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser()
 for name in ['compiler','audio-archive','output']:p.add_argument('--'+name,type=Path,required=True)
 a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes())
 audit_path=ROOT/'build-native-sjuni/actor-voice-archive-activation-audit-v1/receipt.json';audit=json.loads(audit_path.read_bytes());assert audit['status']=='static_source_and_owned_archive_audit'and len(audit['archives'])==8 and sum(row['members']for row in audit['archives'])==8000
 entries={};proof=[]
 for at in [0x1ba440,0x1ab450,0x1ab2f0,0x1ab050,0x1ba330]:
  path=next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*'));begin,end=[int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];proof.append(compare_source('complete actor voice activation/reset/lookup body executed',path.relative_to(ROOT).as_posix(),begin,end,read));entries[at]=path
 result=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),owned_elf_sha256=sha(elf),owned_archive_audit=dict(receipt=audit_path.relative_to(ROOT).as_posix(),sha256=sha(audit_path),members=8000),original_owned_bodies=proof,game_run=False,audio_device_opened=False,stage4_complete=False,limits=['Complete1BA440/1AB450/1AB2F0/1AB050/1BA330 execute; standard bounded string routines and SDK archive open/poll are declared test boundaries. Native actual metadata is prepared from the verified8 nested archives and retained by the same sealed StreamAssetCatalog.','Only five ordinary loaded selections are owned. The distinct NPC/common index5 remains unsupported; activation slot>=5 is the original no-op. Byte-valued characters8..255 are proved known filename misses.','Prevalidated metadata replaces the original synchronous SDK archive-ready wait. Missing native bindings return unbound preserving prior state; they are not fabricated as known missing files.','Three actual native stream instances are constructed, but no decoder/playback source is started and no audio device is opened.'])
 try:
  source=out/'source'
  for name in ['game/native','runtime','tools/native_reconstruction','recomp/overrides/native_banks']:shutil.copytree(ROOT/name,source/name,ignore=shutil.ignore_patterns('__pycache__'))
  result['source_sha256']={path.relative_to(source).as_posix():sha(path)for path in source.rglob('*')if path.is_file()};result['live_source_sha256']=dict(result['source_sha256'])
  reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n';(out/'reference.hpp').write_text(reference)
  body='\n'.join(path.read_text()for path in entries.values());actual={path.stem for path in entries.values()};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+path.stem+'(memory,context,runtime);return;\n'for at,path in entries.items()));(out/'actor_voice_archive_reference.inc').write_bytes((ROOT/'tools/native_reconstruction/actor_voice_archive_reference.inc').read_bytes())
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  for name in ['ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  constants=[]
  for at,size in [(0x2337c0,422*4),(0x250220,32),(0x24fd10,32)]+[(pointer,128)for pointer in __import__('struct').unpack('<422I',read(0x2337c0,422*4))]:
   data=read(at,size);constants.append('{const std::uint8_t b[]{'+','.join(map(str,data))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}')
  (out/'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* p){\n'+'\n'.join(constants)+'\n}\n')
  cmake=source/'tools/native_reconstruction/gameplay_scenario/stream_instances_oracle/CMakeLists.txt';cmake.write_text(cmake.read_text()+'\nset_source_files_properties("'+str(out/'original.cpp').replace('\\','/')+'" PROPERTIES COMPILE_OPTIONS "-Wno-unused-label;-Wno-unused-parameter;-Wno-unused-variable")\n');result['source_sha256'][cmake.relative_to(source).as_posix()]=sha(cmake)
  with a.audio_archive.open('rb')as stream:
   for row in audit['archives']:
    stream.seek(row['offset']);data=stream.read(row['bytes']);assert len(data)==row['bytes']and hashlib.sha256(data).hexdigest()==row['archive_sha256']
  build=out/'build';env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');stamp=a.audio_archive.stat().st_size,a.audio_archive.stat().st_mtime_ns
  commands=[('configure',[str(CMAKE),'-S',str(source/'tools/native_reconstruction/gameplay_scenario/stream_instances_oracle'),'-B',str(build),'-G','Ninja','-DCMAKE_MAKE_PROGRAM='+str(NINJA),'-DCMAKE_CXX_COMPILER='+str(a.compiler.resolve()),'-DCMAKE_BUILD_TYPE=Release','-DREO_ACTOR_ARCHIVE_REFERENCE_DIR='+str(out)]),('build',[str(CMAKE),'--build',str(build),'--parallel','2','--target','actor_voice_archive_checks']),('run',[str(build/'actor_voice_archive_checks.exe'),str(a.audio_archive.resolve())])];result['commands']=commands
  for name,command in commands:
   done=subprocess.run(command,capture_output=True,env=env,timeout=900);(out/(name+'.txt')).write_bytes(done.stdout+done.stderr);assert done.returncode==0,name+' failed: '+(done.stdout+done.stderr).decode(errors='replace')[-1500:]
   if name=='run':result['observed']=json.loads(done.stdout)
  assert stamp==(a.audio_archive.stat().st_size,a.audio_archive.stat().st_mtime_ns);result['snapshot_unchanged']=all(sha(source/name)==digest for name,digest in result['source_sha256'].items());assert result['snapshot_unchanged'];result['live_source_drift']=[name for name,digest in result['live_source_sha256'].items()if not(ROOT/name).is_file()or sha(ROOT/name)!=digest];result['status']='passed'
 finally:
  result['output_sha256']={name:sha(out/name)for name in ['configure.txt','build.txt','run.txt','original.cpp','actor_voice_archive_reference.inc','reference.hpp','functions.h','original_dispatch.hpp','owned_constants.hpp']if(out/name).is_file()};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps(dict(status=result['status'],observed=result['observed'],live_source_drift=result['live_source_drift'])))
if __name__=='__main__':main()
