"""Complete owned-body comparison for native actor/menu input and repeat behavior."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
 assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes())
 ids=['001B0980','001B0B80','001B0DB0'];sources=[next((ROOT/'recomp/config/output').glob('sub_'+n+'_*')).relative_to(ROOT).as_posix() for n in ids];proof=[]
 for src in sources:
  begin,end=[int(x,16) for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/src).read_text()).groups()]
  proof.append(compare_source('complete native actor input contract',src,begin,end,read))
 files=sources+['game/native/gameplay_actors/input.hpp','game/native/gameplay_actors/input.cpp','tools/native_reconstruction/gameplay_actor_oracle/runtime.hpp','tools/native_reconstruction/gameplay_actor_oracle/input_tests.cpp','tools/native_reconstruction/verify_gameplay_actor_input.py'];before={n:sha(ROOT/n) for n in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),source_sha256=before,original_owned_bodies=proof,declared_service_ports=True,game_run=False,stage4_complete=False)
 try:
  core=out/'source/game/native/gameplay_actors';core.mkdir(parents=True)
  for n in ('input.hpp','input.cpp'):(core/n).write_bytes((ROOT/'game/native/gameplay_actors'/n).read_bytes())
  for src,dst in [('tools/native_reconstruction/gameplay_actor_oracle/runtime.hpp','runtime.hpp'),('tools/native_reconstruction/gameplay_actor_oracle/input_tests.cpp','tests.cpp')]: (out/dst).write_bytes((ROOT/src).read_bytes())
  body='\n'.join((ROOT/src).read_text() for src in sources);(out/'original_input.cpp').write_text(body,encoding='utf8',newline='\n')
  for n in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/n).write_text('#pragma once\n#include "runtime.hpp"\n',encoding='utf8',newline='\n')
  for n in ('ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h'):(out/n).write_text('#pragma once\n',encoding='utf8',newline='\n')
  actual={Path(src).stem for src in sources};calls=set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));declarations=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in sorted(actual))
  declarations+=''.join('inline void '+n+'(std::uint8_t* r,R5900Context* c,PS2Runtime* t){original_port(r,c,t); }\n' for n in sorted(calls-actual));(out/'functions.h').write_text('#pragma once\n'+declarations,encoding='utf8',newline='\n');(out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n',encoding='utf8',newline='\n')
  import struct
  remaps=struct.unpack('<18I',read(0x2343c0,72));record['owned_remaps_sha256']=hashlib.sha256(read(0x2343c0,72)).hexdigest();(out/'owned_remaps.hpp').write_text('inline constexpr std::array<g::Remap,6> owned_remaps{{'+','.join('{'+','.join(str(x)+'u' for x in remaps[i:i+3])+'}' for i in range(0,18,3))+'}};\n',encoding='utf8',newline='\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'actor-input.exe'
  command=[str(a.compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-I'+str(out),'-I'+str(out/'source'),str(core/'input.cpp'),str(out/'tests.cpp'),'-o',str(binary)];record['command']=command
  c=subprocess.run(command,env=env,capture_output=True,text=True,timeout=120);(out/'compile.txt').write_text(c.stdout+c.stderr,encoding='utf8',newline='\n');assert c.returncode==0,'compile failed'
  c=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=90);(out/'run.txt').write_text(c.stdout+c.stderr,encoding='utf8',newline='\n');assert c.returncode==0,'original comparison failed'
  observed=json.loads(c.stdout);assert observed['cases']==196608 and observed['invalid_cases']==4
  assert all(sha(ROOT/n)==h for n,h in before.items());record.update(status='native actor/menu input and repeat match three complete original bodies',observed=observed,source_unchanged=True,binary_sha256=sha(binary),limits=['Native normalized controller inputs are provided; original platform packet polling/deadzones remain outside this boundary.','No actual game consumers replaced; native platform sampling and actual actor/menu consumers remain separate migration work.'])
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p) for p in out.rglob('*') if p.is_file() and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8',newline='\n')
 print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
