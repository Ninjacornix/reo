"""Compare complete primary64-light allocation/retirement/creation bodies."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args();out=args.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 image=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=image.read_bytes();addresses=[0x6b2fa0,0x6b3020,0x6b3090];entries={};proof=[]
 for at in addresses:
  file=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'));name=file.relative_to(ROOT).as_posix();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',file.read_text())[1],16);proof.append(compare_source('complete shared primary lighting pool body',name,at,end,lambda a,n:raw[a-0x570000:a-0x570000+n]));entries[at]=name
 units=['game/native/gameplay_lighting/lights.cpp','game/native/gameplay_scenario/lighting.cpp'];fixture='tools/native_reconstruction/lighting_pool_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';files=list(dict.fromkeys(units+list(entries.values())+[fixture,helper,Path(__file__).relative_to(ROOT).as_posix(),'game/native/gameplay_lighting/CMakeLists.txt','game/native/CMakeLists.txt']))
 for name in files:
  if name.startswith('game/native/')and name.endswith(('.cpp','.hpp')):
   for include in re.findall(r'^\s*#include "([^"]+)"',(ROOT/name).read_text(),re.M):
    local=((ROOT/name).parent/include).resolve();target=local if local.is_file()else(ROOT/include).resolve();assert target.is_file()and target.is_relative_to(ROOT);relative=target.relative_to(ROOT).as_posix()
    if relative not in files:files.append(relative)
 frozen={n:(ROOT/n).read_bytes()for n in files};out.mkdir(parents=True)
 for name,body in frozen.items():target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(body)
 reference=frozen[helper].decode();(out/'reference.hpp').write_text(reference);body='\n'.join(frozen[n].decode()for n in entries.values());(out/'original.cpp').write_text(body);actual={Path(n).stem for n in entries.values()};names=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join(f'void {n}(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual));decl+=''.join(f'inline void {n}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n'for n in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original_dispatch.hpp').write_text(''.join(f'case {at}:{Path(n).stem}(memory,context,runtime);return;\n'for at,n in entries.items()))
 for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
 for name in ['o2_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
 for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
 payload=raw[0x7202c0-0x570000:0x7202c0-0x570000+52];(out/'owned_light.hpp').write_text('inline constexpr std::array<std::uint8_t,52> owned_light{'+','.join(str(v)for v in payload)+'};\n');cc=COMPILERS[args.compiler];exe=out/'lights.exe';cmd=[str(cc),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/n)for n in units],str(out/'source'/fixture),'-o',str(exe)];env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','');record={'schema':1,'status':'failed','game_run':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':{n:hashlib.sha256(b).hexdigest()for n,b in frozen.items()},'compiler_sha256':sha(cc),'original_word_audits':proof,'owned_light_payload':{'address':'0x7202c0','bytes':payload.hex(),'sha256':hashlib.sha256(payload).hexdigest()},'declared_ports':['107C68 actual bounded56-byte record clearing','107AB0 actual bounded52-byte payload copying'],'command':cmd}
 try:
  for label,command in [('compile',cmd),('run',[str(exe)])]:
   result=subprocess.run(command,capture_output=True,env=env,timeout=90);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see retained logs'
   if label=='run':record['observed']=json.loads(result.stdout)
  record['source_unchanged']=all((ROOT/n).read_bytes()==b for n,b in frozen.items());assert record['source_unchanged'];record.update(status='passed',binary_sha256=sha(exe))
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['observed']))
if __name__=='__main__':main()
