"""Full6B25B0/5D83D0 projectile lights through actual native scheduler and scene pools."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 parent=ROOT/'build-native-sjuni'/f'projectile-trail-owner-current-{a.compiler}-v1';prior=json.loads((parent/'receipt.json').read_bytes());assert prior['status']=='passed'
 units=['game/native/gameplay_lighting/transient_light_policy.cpp','game/native/gameplay_lighting/transient_lights.cpp','game/native/gameplay_world/projectile_pose_lights.cpp','game/native/gameplay_world/transient_weapon_effects.cpp'];fixture='tools/native_reconstruction/transient_light_policy_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';owned={fixture,Path(__file__).relative_to(ROOT).as_posix(),*units,'game/native/gameplay_lighting/transient_lights.hpp','game/native/gameplay_world/projectile_pose_lights.hpp','tools/native_reconstruction/transient_lights_owner_tests.inc','tools/native_reconstruction/projectile_lights_owner_tests.inc','tools/native_reconstruction/auxiliary_lighting_tests.inc'};frozen={}
 for name,digest in prior['source_sha256'].items():assert sha(parent/'source'/name)==digest;frozen[name]=(parent/'source'/name).read_bytes()
 pending=list(owned)+[helper]
 for name in pending:
  if name not in frozen or name in owned:frozen[name]=(ROOT/name).read_bytes()
  if name.startswith(('game/native/','tools/native_reconstruction/')):
   for include in re.findall(r'^\s*#include "([^"\n]+)"',frozen[name].decode(),re.M):
    if include in ['reference.hpp','functions.h','original_dispatch.hpp','owned_constants.hpp']:continue
    path=((ROOT/name).parent/include).resolve();path=path if path.is_file()else(ROOT/include).resolve();assert path.is_file()and path.is_relative_to(ROOT);key=path.relative_to(ROOT).as_posix()
    if key not in pending:pending.append(key)
 from audit_retail_effect_descriptors import compare_source
 image=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=image.read_bytes();entries={};proof=[]
 for at in [0x6b25b0,0x6b24f0,0x5d83d0,0x6b2bd0,0x6b2cc0,0x6b2c50,0x6b3090,0x6b2fa0,0x6b3020,0x616f60,0x371760,0x370490]:
  bank='o2' if at>=0x570000 else 'o0';path=next((ROOT/'recomp/config/output_ovl'/bank).glob(f'{bank}_{at:08X}_*'));overlay=(ROOT/'build-function-index/owned-overlays'/f'{bank}.bin').read_bytes();base=0x570000 if bank=='o2' else 0x370000;name=path.relative_to(ROOT).as_posix();body=path.read_bytes();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',body.decode())[1],16);proof.append(compare_source('complete projectile visual constructor or controller',name,at,end,lambda address,n:overlay[address-base:address-base+n]));frozen[name]=body;entries[at]=name
 assert raw[0x720280-0x570000:0x720280-0x570000+52]==raw[0x720240-0x570000:0x720240-0x570000+52]
 out.mkdir(parents=True)
 for name,data in frozen.items():
  target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(data)
 (out/'reference.hpp').write_text(frozen[helper].decode()+'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define FPU_DIV_S(a,b) ((a)/(b))\n');body='\n'.join(frozen[name].decode()for name in entries.values());actual={Path(name).stem for name in entries.values()};called=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));declarations=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));declarations+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r); }\n'for name in sorted(called-actual));(out/'functions.h').write_text('#pragma once\n'+declarations);(out/'original.cpp').write_text('#include "reference.hpp"\n#include "functions.h"\n'+body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in entries.items()))
 for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
 for name in ['ps2_recompiled_functions.h','o2_functions.h','o0_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
 for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
 libraries=[]
 for name,digest in prior['native_library_sha256'].items():
  source=parent/'libraries'/name;assert sha(source)==digest;target=out/'libraries'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,target);libraries.append(str(target))
 source=ROOT/'build-native-sjuni/resource-flight-owner-llvm-v4/owned_flight_floors.bin';shutil.copyfile(source,out/source.name);assets=[out/source.name]
 constants='inline void owned_constants(std::uint8_t* memory){'
 for at,size in [(0x70b350,16),(0x720240,52),(0x720280,52),(0x73eb30,4)]:
  data=raw[at-0x570000:at-0x570000+size];constants+='{const std::uint8_t data[]{'+','.join(str(v)for v in data)+'};std::memcpy(memory+'+str(at)+',data,sizeof data);}'
 (out/'owned_constants.hpp').write_text(constants+'}\n')
 compiler=COMPILERS[a.compiler];binary=out/'checks.exe';command=[str(compiler),'-std=c++20','-DREO_PROJECTILE_LIGHT_OWNER=1','-DREO_TRANSIENT_OWNER=1','-DREO_AUXILIARY_LIGHT_POOL=1','-O2','-msse4.1','-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/n)for n in units],str(out/'source'/fixture),str(out/'original.cpp'),'-Wl,--gc-sections','-Wl,--start-group',*libraries,'-Wl,--end-group','-o',str(binary)];env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''));record=dict(schema=1,status='failed',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256={n:hashlib.sha256(v).hexdigest()for n,v in frozen.items()},original_owned_bodies=proof,definitions_byte_identical=True,compiler_sha256=sha(compiler),native_parent={'path':str(parent/'receipt.json'),'sha256':sha(parent/'receipt.json')},native_library_sha256=prior['native_library_sha256'],owned_assets={p.name:sha(p)for p in assets},command=command,limits=['Complete6B25B0/6B24F0/5D83D0 and both actual original light pool bodies execute against pinned original words. Canonical native scheduler admission is independently matched against the declared573890/573740 original ports.','Complete616F60 executes, with617000 explicitly bound to the same independently qualified retained native Grid. Transitive original grid traversal is not rerun here.','Parent archives and headers are frozen together. Only the ABI-preserving transient-light implementation is recompiled plus the new room adapter; no Actor/World or existing class layout changes.','No installed-game, device, power or fullStage4 acceptance claim.'])
 try:
  for label,cmd in [('compile',command),('run',[str(binary),*[str(p)for p in assets]])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=300);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see logs'
   if label=='run':record['observed']=json.loads(result.stdout);assert record['observed']['projectile_cases']>0
  owned|={n for n in pending if n not in prior['source_sha256']};record['owned_source_drift']={n:sha(ROOT/n)for n in owned if(ROOT/n).read_bytes()!=frozen[n]};assert not record['owned_source_drift'];record['subsequent_parent_changes']={n:sha(ROOT/n)for n in pending if n in prior['source_sha256']and n not in owned and(ROOT/n).read_bytes()!=frozen[n]};record.update(status='passed',binary_sha256=sha(binary))
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['observed']))
if __name__=='__main__':main()
