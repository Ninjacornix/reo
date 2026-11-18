"""Compare native actor-frame orchestration with the complete owned original body."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
 assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 raw=overlay.read_bytes();sources=['recomp/config/output_ovl/o2/o2_00669F30_0x669f30.cpp','recomp/config/output/sub_001B0B80_0x1b0b80.cpp'];elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read_main=elf_reader(elf.read_bytes());proof=[]
 for src in sources:
  begin,end=[int(x,16) for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/src).read_text()).groups()]
  read=read_main if begin<0x570000 else lambda at,n:raw[at-0x570000:at-0x570000+n]
  proof.append(compare_source('native owned actor frame and direct input',src,begin,end,read))
 files=sources+['game/native/gameplay_world/world.hpp','game/native/gameplay_world/world.cpp','game/native/gameplay_world/tests.cpp','game/native/gameplay_actors/entity.hpp','game/native/gameplay_actors/entity.cpp','game/native/gameplay_actors/health.hpp','game/native/gameplay_actors/health.cpp','game/native/gameplay_actors/status.hpp','game/native/gameplay_actors/hit.hpp','game/native/gameplay_actors/input.hpp','game/native/gameplay_actors/input.cpp','game/native/gameplay_session/session.hpp','tools/native_reconstruction/gameplay_actor_oracle/runtime.hpp','tools/native_reconstruction/gameplay_world_oracle/tests.cpp','tools/native_reconstruction/verify_gameplay_world.py']
 files += ['game/native/gameplay_collision/'+n for n in ['actors.hpp','response.hpp','collision.hpp']]
 native_units=['game/native/'+group+'/'+name+'.cpp'for group,names in [
  ('gameplay_world',['world','linked_models','auxiliary_actors','scene_primary_actors','model_poses','model_constraints','bodies']),
  ('gameplay_actors',['entity','input','health']),
  ('gameplay_collision',['collision','response','actors','actor_views']),
  ('animation',['model','model_math','curves','constraints','constraint_math']),
  ('transform_math',['transform_math']),('gameplay_session',['session'])
 ]for name in names]
 files+=native_units
 # Freeze the current transitive native headers, including added canonical
 # resource/notice state. No private checkout header may satisfy a missing copy.
 files=list(dict.fromkeys(files))
 for name in files:
  if not name.startswith('game/native/'):continue
  for include in re.findall(r'^\s*#include "([^"\n]+)"',(ROOT/name).read_text(),re.M):
   target=((ROOT/name).parent/include).resolve()
   if not target.is_file():target=(ROOT/include).resolve()
   assert target.is_relative_to(ROOT/'game/native')and target.is_file(),(name,include)
   relative=target.relative_to(ROOT).as_posix()
   if relative not in files:files.append(relative)
 before={n:sha(ROOT/n) for n in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),source_sha256=before,original_owned_body=proof,original_body_executed=True,declared_callee_ports=True,actual_game_run=False,stage4_complete=False)
 try:
  core=out/'source/game/native/gameplay_world';core.mkdir(parents=True)
  for name in files:
   if name.startswith('game/native/'):
    target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
  (out/'runtime.hpp').write_bytes((ROOT/'tools/native_reconstruction/gameplay_actor_oracle/runtime.hpp').read_bytes());(out/'tests.cpp').write_bytes((ROOT/'tools/native_reconstruction/gameplay_world_oracle/tests.cpp').read_bytes())
  body='\n'.join((ROOT/source).read_text() for source in sources).encode();(out/'original_actor.cpp').write_bytes(body)
  for name in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/name).write_text('#pragma once\n#include "runtime.hpp"\n',encoding='utf8',newline='\n')
  for name in ('ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h'):(out/name).write_text('#pragma once\n',encoding='utf8',newline='\n')
  names=sorted(set(re.findall(r'\b((?:o2|sub)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body.decode())))
  actual={Path(n).stem for n in sources};declarations=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in sorted(actual))
  declarations+=''.join('inline void '+n+'(std::uint8_t* r,R5900Context* c,PS2Runtime* t){original_port(r,c,t); }\n' for n in names if n not in actual)
  (out/'functions.h').write_text('#pragma once\n'+declarations,encoding='utf8',newline='\n')
  for n in ('o2_functions.h','ps2_recompiled_functions.h'):(out/n).write_text('#pragma once\n#include "functions.h"\n',encoding='utf8',newline='\n')
  import struct
  remaps=struct.unpack('<18I',read_main(0x2343c0,72));(out/'owned_remaps.hpp').write_text('inline constexpr std::array<g::input::Remap,6> owned_remaps{{'+','.join('{'+','.join(str(v)+'u' for v in remaps[i:i+3])+'}' for i in range(0,18,3))+'}};\n',encoding='utf8',newline='\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
  binary=out/'native-world.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in native_units],str(out/'tests.cpp'),'-o',str(binary)]
  record['command']=command
  result=subprocess.run(command,env=env,capture_output=True,text=True,timeout=120);(out/'compile.txt').write_text(result.stdout+result.stderr,encoding='utf8',newline='\n');assert result.returncode==0,'compile failed; see sealed compile.txt'
  result=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=60);(out/'run.txt').write_text(result.stdout+result.stderr,encoding='utf8',newline='\n');assert result.returncode==0,'differential check failed; see run.txt'
  observed=json.loads(result.stdout);assert observed['cases']==4096 and observed['ordered_calls']>0
  lifecycle=out/'native-world-lifetime.exe';cmd=[str(core/'tests.cpp') if v==str(out/'tests.cpp') else str(lifecycle) if v==str(binary) else v for v in command]
  record['lifetime_command']=cmd
  result=subprocess.run(cmd,env=env,capture_output=True,text=True,timeout=120);(out/'lifetime-compile.txt').write_text(result.stdout+result.stderr,encoding='utf8',newline='\n');assert result.returncode==0,'lifetime compilation'
  result=subprocess.run([str(lifecycle)],env=env,capture_output=True,text=True,timeout=30);(out/'lifetime-run.txt').write_text(result.stdout+result.stderr,encoding='utf8',newline='\n');assert result.returncode==0,'lifetime tests'
  lifetime=json.loads(result.stdout);assert lifetime['status']=='passed' and lifetime['checks']>50;observed['native_lifetime']=lifetime
  assert all(sha(ROOT/n)==value for n,value in before.items()),'compiled source drift'
  record.update(status='canonical native primary world and direct input match complete originals with explicit remaining providers',observed=observed,binary_sha256=sha(binary),source_unchanged=True,limitations=['Complete669F30 plus actual1B0B80 reference executes; native direct input is composed with the canonical entity owner. Other behavior/AI/pose/grid providers are declared fixtures.','The native component has no CPU context, guest memory, runtime or source addresses; the oracle fixture deliberately retains those original-body inputs.','Corpus scalar addition uses exactly representable finite values; exceptional PS2 FPU behavior is outside admission.','No game integration or whole Stage4 completion follows from this actor owner comparison.'])
 finally:
  record['output_sha256']={x.relative_to(out).as_posix():sha(x) for x in out.rglob('*') if x.is_file() and x.name!='receipt.json'}
  (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8',newline='\n')
 print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
