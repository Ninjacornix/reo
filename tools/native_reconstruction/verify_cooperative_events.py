"""Compare the native cooperative evidence pool with complete owned originals."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 image=ROOT/'build-function-index/owned-overlays/o0.bin';assert sha(image)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2';raw=image.read_bytes();entries={};proof=[]
 for at in [0x37bfb0,0x37c060,0x37c170,0x37c200,0x37c2c0,0x37c3b0]:
  source=next((ROOT/'recomp/config/output_ovl/o0').glob(f'o0_{at:08X}_*'));name=source.relative_to(ROOT).as_posix();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',source.read_text())[1],16);proof.append(compare_source('complete cooperative event pool/admission/pruning body',name,at,end,lambda x,n:raw[x-0x370000:x-0x370000+n]));entries[at]=name
 fixture='tools/native_reconstruction/cooperative_events_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';unit='game/native/gameplay_events/events.cpp';profile='game/native/gameplay_events/event_priority_profile.inc'
 files=[unit,'game/native/gameplay_events/events.hpp',profile,'game/native/gameplay_events/CMakeLists.txt','game/native/CMakeLists.txt',fixture,helper,Path(__file__).relative_to(ROOT).as_posix(),*entries.values()];frozen={n:(ROOT/n).read_bytes()for n in files};priorities=bytes(int(v)for v in re.findall(r'\d+',frozen[profile].decode().split('\n',1)[1]));assert len(priorities)==39 and priorities==raw[0x389d30-0x370000:0x389d30-0x370000+39]
 out.mkdir(parents=True)
 for n,b in frozen.items():target=out/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(b)
 (out/'reference.hpp').write_bytes(frozen[helper]);body='\n'.join(frozen[n].decode()for n in entries.values());(out/'original.cpp').write_text(body);actual={Path(n).stem for n in entries.values()};names=set(re.findall(r'\b((?:sub|o0)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));(out/'functions.h').write_text('#pragma once\n'+''.join(f'void {n}(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in actual)+''.join(f'inline void {n}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n'for n in names-actual));(out/'dispatch.inc').write_text(''.join(f'case {at}:{Path(n).stem}(memory,context,runtime);return;\n'for at,n in entries.items()))
 for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
 for n in ['o0_functions.h','ps2_recompiled_functions.h']:(out/n).write_text('#pragma once\n#include "functions.h"\n')
 for n in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/n).write_text('#pragma once\n')
 (out/'priorities.bin').write_bytes(priorities);cc=COMPILERS[a.compiler];env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','');exe=out/'events.exe';cmd=[str(cc),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-I'+str(out),'-I'+str(out/'source'),str(out/'source'/unit),str(out/'source'/fixture),'-o',str(exe)];r={'schema':1,'status':'failed','game_run':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':{n:hashlib.sha256(b).hexdigest()for n,b in frozen.items()},'compiler_sha256':sha(cc),'original_word_audits':proof,'priority_prefix':{'address':'0x389d30','bytes':priorities.hex()},'command':cmd,'declared_ports':['107C68 bounded actual clearing'],'limitations':['Typed priority admission is the measured39-byte prefix; other IDs remain unavailable.','Native update/recipe caller binding is separate from this pool comparison.']}
 try:
  for label,command in [('compile',cmd),('run',[str(exe),str(out/'priorities.bin')])]:
   result=subprocess.run(command,capture_output=True,env=env,timeout=180);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see retained logs'
   if label=='run':r['observed']=json.loads(result.stdout)
  r['source_unchanged']=all((ROOT/n).read_bytes()==b for n,b in frozen.items());assert r['source_unchanged'];r.update(status='passed',binary_sha256=sha(exe))
 finally:
  r['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(r,indent=2)+'\n')
 print(json.dumps(r['observed']))
if __name__=='__main__':main()
