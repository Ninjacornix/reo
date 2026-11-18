"""Compare native worker and script ordering to complete owned bodies.

Actor, script, task and timer children are declared native fixture ports,
qualified separately. This is not transitive original execution coverage.
"""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from gameplay_update_sources import UPDATE_UNITS
from comparison_objects import compile_objects
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--scenario-ref',help='Explicit immutable scenario cohort commit while independent work continues');a=p.parse_args();out=a.output.resolve()
 assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes()
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';main_read=elf_reader(elf.read_bytes())
 sources=[next((ROOT/'recomp/config/output_ovl/o2').glob('o2_'+n+'_*')).relative_to(ROOT).as_posix() for n in ['005FED00','0068C8D0','005FEE60','005FEA30','005FEE70','005FEE80']];proof=[]
 for src in sources:
  begin,end=[int(x,16) for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/src).read_text()).groups()]
  read=main_read if begin<0x570000 else lambda at,n:raw[at-0x570000:at-0x570000+n]
  proof.append(compare_source('complete native phase and worker ordering',src,begin,end,read))
 groups=dict(gameplay_world=['world.hpp','world.cpp','behavior.hpp','behavior.cpp','surfaces.hpp','surfaces.cpp','motion.hpp','motion.cpp'],
  gameplay_actors=['entity.hpp','entity.cpp','health.hpp','health.cpp','status.hpp','status.cpp','hit.hpp','hit.cpp','input.hpp','input.cpp'],
  gameplay_session=['session.hpp','session.cpp'],gameplay_tasks=['tasks.hpp','tasks.cpp','events.hpp','events.cpp'],
  gameplay_events=['events.hpp','events.cpp','event_priority_profile.inc'],
  gameplay_scenario=['interpreter.hpp','interpreter.cpp','flags.hpp','flags.cpp','offline.hpp','offline.cpp','scene_resources.hpp','scene_resources.cpp','scene_controls.hpp','scene_controls.cpp','content.hpp','content.cpp','sequence_control.hpp','sequence_control.cpp','lighting.hpp','lighting.cpp','scene_channels.hpp','opcode_bindings.inc','offline_bindings.inc','session_counters.hpp','stream_channels.hpp','stream_channels.cpp','stream_gain_curve.inc','saved_controls.hpp','action_choices.hpp'],gameplay_update=['update.hpp','update.cpp'])
 native=['game/native/'+d+'/'+n for d,names in groups.items() for n in names]
 fixture=['tools/native_reconstruction/gameplay_update_oracle/tests.cpp','tools/native_reconstruction/gameplay_actor_oracle/status_runtime.hpp','tools/native_reconstruction/verify_gameplay_update.py']
 native += ['game/native/gameplay_collision/'+n for n in ['collision.cpp','collision.hpp','response.cpp','response.hpp','actors.hpp','contact_component.hpp','hit_regions.hpp','spatial.hpp']]
 # Current concrete VM/World closure, matching the independently compared
 # scenario consumer. The historical hand-maintained header list was incomplete.
 native += UPDATE_UNITS
 native=list(dict.fromkeys(native))
 scenario_revision=subprocess.check_output(['git','rev-parse',a.scenario_ref+'^{commit}'],cwd=ROOT,text=True).strip() if a.scenario_ref else None
 def read_source(n):return subprocess.check_output(['git','show',scenario_revision+':'+n],cwd=ROOT) if scenario_revision and n.startswith('game/native/gameplay_scenario/') else (ROOT/n).read_bytes()
 for name in native:
  for inc in re.findall(r'^\s*#include "([^"]+)"',read_source(name).decode(),re.M):
   local=((ROOT/name).parent/inc).resolve();target=local if local.is_file()else(ROOT/inc).resolve();assert target.is_file()and target.is_relative_to(ROOT),(name,inc);dep=target.relative_to(ROOT).as_posix()
   if dep not in native:native.append(dep)
 fixture+=['tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/comparison_objects.py']
 files=sources+native+fixture;source_bytes={n:read_source(n) for n in files};before={n:hashlib.sha256(body).hexdigest() for n,body in source_bytes.items()};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',compiler=str(a.compiler),compiler_sha256=sha(a.compiler),source_sha256=before,scenario_source_commit=scenario_revision,original_owned_bodies=proof,full_original_worker_and_script_order_bodies=True,declared_child_native_ports=['669F30 canonical world','68C660 Interpreter/OfflineCoordinator','68C7B0 native timers/FlagState','5B91B0 native EventTasks','573840 native Scheduler'],remaining_effect_providers=True,game_launched=False,installed_in_game=False,stage4_complete=False)
 try:
  for n in native:
   target=out/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(source_bytes[n])
  for src,dst in [(fixture[0],'tests.cpp'),(fixture[1],'runtime.hpp')]: (out/dst).write_bytes((ROOT/src).read_bytes())
  body='\n'.join((ROOT/n).read_text() for n in sources);(out/'original_update.cpp').write_text(body,encoding='utf8',newline='\n')
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "runtime.hpp"\n',encoding='utf8')
  for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
  actual={Path(n).stem for n in sources};calls=set(re.findall(r'\b((?:o2|sub)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
  declarations=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in sorted(actual))
  declarations+=''.join('inline void '+n+'(std::uint8_t* r,R5900Context* c,PS2Runtime* t){original_port(r,c,t); }\n' for n in sorted(calls-actual))
  (out/'functions.h').write_text('#pragma once\n'+declarations)
  for name in ['o2_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'native-update.exe'
  flags=['-std=c++20','-O2','-msse4.1','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source')]
  units=[n for n in native if n.endswith('.cpp')];objects,receipts=compile_objects(ROOT,out,a.compiler,flags,units,source_bytes,env);record['production_objects']=receipts
  command=[str(a.compiler),*flags,*objects,str(out/'tests.cpp'),'-o',str(binary)];record['command']=command
  result=subprocess.run(command,env=env,capture_output=True,text=True,timeout=180);(out/'compile.txt').write_text(result.stdout+result.stderr,encoding='utf8');assert result.returncode==0,'compile failed; see compile.txt'
  result=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=90);(out/'run.txt').write_text(result.stdout+result.stderr,encoding='utf8');assert result.returncode==0,'comparison failed; see run.txt'
  record['result']=json.loads(result.stdout);assert record['result']['cases']==2048
  assert all(hashlib.sha256(read_source(n)).hexdigest()==h for n,h in before.items());record.update(status='passed',executable_sha256=sha(binary),checked_owned_instruction_comments=sum(v['matched_comments'] for v in proof))
 finally:(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['result']))
if __name__=='__main__':main()
