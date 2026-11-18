"""Full58DA20/58DAB0/58DB50 subtype0 through current shared visual ownership."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 parent=ROOT/'build-native-sjuni'/f'surface-follower-owner-current-{a.compiler}-v1';prior=json.loads((parent/'receipt.json').read_bytes());assert prior['status']=='passed'
 units=[];fixture='game/native/gameplay_effects/surface_follower_owner_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';owned={fixture,Path(__file__).relative_to(ROOT).as_posix()};frozen={}
 for name,digest in prior['source_sha256'].items():assert sha(parent/'source'/name)==digest;frozen[name]=(parent/'source'/name).read_bytes()
 pending=list(owned)+[helper]
 for name in pending:
  if name not in frozen or name in owned:frozen[name]=(ROOT/name).read_bytes()
  if name.startswith('game/native/'):
   for include in re.findall(r'^\s*#include "([^"\n]+)"',frozen[name].decode(),re.M):
    if name==fixture and include in ['reference.hpp','functions.h','original_dispatch.hpp','owned_constants.hpp']:continue
    path=((ROOT/name).parent/include).resolve();path=path if path.is_file()else(ROOT/include).resolve();assert path.is_file()and path.is_relative_to(ROOT);key=path.relative_to(ROOT).as_posix()
    if key not in pending:pending.append(key)
 from audit_retail_effect_descriptors import compare_source
 image=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=image.read_bytes();entries={};proof=[]
 for at in [0x58da20,0x58dab0,0x58db50]:
  path=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'));name=path.relative_to(ROOT).as_posix();body=path.read_bytes();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',body.decode())[1],16);proof.append(compare_source('complete projectile visual constructor or controller',name,at,end,lambda address,n:raw[address-0x570000:address-0x570000+n]));frozen[name]=body;entries[at]=name
 assert int.from_bytes(raw[0x73e070-0x570000:0x73e074-0x570000],'little')==0x58dae0
 out.mkdir(parents=True)
 for name,data in frozen.items():
  target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(data)
 (out/'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* memory){const std::uint8_t table[]{'+','.join(str(v)for v in raw[0x73e070-0x570000:0x73e090-0x570000])+'};std::memcpy(memory+0x73e070,table,sizeof table); }\n')
 (out/'reference.hpp').write_bytes(frozen[helper]);body='\n'.join(frozen[name].decode()for name in entries.values());actual={Path(name).stem for name in entries.values()};called=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));declarations=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));declarations+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r); }\n'for name in sorted(called-actual));(out/'functions.h').write_text('#pragma once\n'+declarations);(out/'original.cpp').write_text('#include "reference.hpp"\n#include "functions.h"\n'+body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in entries.items()))
 for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
 for name in ['ps2_recompiled_functions.h','o2_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
 for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
 libraries=[]
 for name,digest in prior['native_library_sha256'].items():
  source=parent/'libraries'/name;assert sha(source)==digest;target=out/'libraries'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,target);libraries.append(str(target))
 source=parent/'owned_effect_geometry.bin';assert sha(source)==prior['owned_assets'][source.name];shutil.copyfile(source,out/source.name);assets=[out/source.name]
 compiler=COMPILERS[a.compiler];binary=out/'checks.exe';command=[str(compiler),'-std=c++20','-DREO_SURFACE_FOLLOWER_ORIGINAL=1','-O2','-msse4.1','-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),str(out/'source'/fixture),str(out/'original.cpp'),'-Wl,--gc-sections','-Wl,--start-group',*libraries,'-Wl,--end-group','-o',str(binary)];env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''));record=dict(schema=1,status='failed',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256={n:hashlib.sha256(v).hexdigest()for n,v in frozen.items()},original_owned_bodies=proof,admitted_subtype=0,compiler_sha256=sha(compiler),native_parent={'path':str(parent/'receipt.json'),'sha256':sha(parent/'receipt.json')},native_library_sha256=prior['native_library_sha256'],owned_assets={p.name:sha(p)for p in assets},command=command,limits=['Complete58DA20 constructor,58DAB0 dispatch and58DB50 subtype0 execute against pinned owned words.651A30 allocation/clear/category and651D00 retirement are observed source ports; native actualshared168workpool runs independently. The original592-byte clear is included in the declared allocation boundary.','Subtype0 is the actual584760 caller. Other58DAB0 subtypes remain unadmitted, and CPU billboard state is an immutable rendering handoff; Stage5 texture/GPU/pixel parity is not claimed.','Parent archives/headers are copied from the current rebuilt source graph with enlarged VisualOutput; no old-layout archive overlay. Parent leases preserve old generations rather than retargeting recycled slots.','No game/device/power or completeStage4 claim.'])
 try:
  for label,cmd in [('compile',command),('run',[str(binary),*[str(p)for p in assets]])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=300);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see logs'
   if label=='run':record['observed']=json.loads(result.stdout);assert record['observed']['owned_banks']==6
  owned|={n for n in pending if n not in prior['source_sha256']};record['owned_source_drift']={n:sha(ROOT/n)for n in owned if(ROOT/n).read_bytes()!=frozen[n]};assert not record['owned_source_drift'];record['subsequent_parent_changes']={n:sha(ROOT/n)for n in pending if n in prior['source_sha256']and n not in owned and(ROOT/n).read_bytes()!=frozen[n]};record.update(status='passed',binary_sha256=sha(binary))
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['observed']))
if __name__=='__main__':main()
