"""Compare native worker and script ordering to complete owned bodies.

Actor, script, task and timer children are declared native fixture ports,
qualified separately. This is not transitive original execution coverage.
"""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
 assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes()
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';main_read=elf_reader(elf.read_bytes())
 sources=[next((ROOT/'recomp/config/output_ovl/o2').glob('o2_'+n+'_*')).relative_to(ROOT).as_posix() for n in ['005FED00','0068C8D0','005FEE60','005FEA30','005FEE70','005FEE80']];proof=[]
 for src in sources:
  begin,end=[int(x,16) for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/src).read_text()).groups()]
  read=main_read if begin<0x570000 else lambda at,n:raw[at-0x570000:at-0x570000+n]
  proof.append(compare_source('complete canonical actor behavior orchestration',src,begin,end,read))
 native=[p.relative_to(ROOT).as_posix() for d in ['gameplay_world','gameplay_actors','gameplay_session','gameplay_tasks','gameplay_scenario','gameplay_update'] for p in (ROOT/'game/native'/d).glob('*') if p.suffix in ['.hpp','.cpp','.inc'] and not (d=='gameplay_scenario' and p.name.startswith('stream_'))]
 fixture=['tools/native_reconstruction/gameplay_update_oracle/tests.cpp','tools/native_reconstruction/gameplay_actor_oracle/status_runtime.hpp','tools/native_reconstruction/verify_gameplay_update.py']
 native += ['game/native/gameplay_collision/'+n for n in ['collision.cpp','collision.hpp','response.cpp','response.hpp']]
 files=sources+native+fixture;before={n:sha(ROOT/n) for n in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',compiler=str(a.compiler),compiler_sha256=sha(a.compiler),source_sha256=before,original_owned_bodies=proof,full_original_worker_and_script_order_bodies=True,declared_child_native_ports=['669F30 canonical world','68C660 Interpreter/OfflineCoordinator','68C7B0 native timers/FlagState','5B91B0 native EventTasks','573840 native Scheduler'],remaining_effect_providers=True,game_launched=False,installed_in_game=False,stage4_complete=False)
 try:
  for n in native:
   target=out/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/n).read_bytes())
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
  units=['gameplay_world/world.cpp','gameplay_world/behavior.cpp','gameplay_world/surfaces.cpp','gameplay_collision/response.cpp','gameplay_collision/collision.cpp','gameplay_actors/entity.cpp','gameplay_actors/input.cpp','gameplay_actors/health.cpp','gameplay_actors/status.cpp','gameplay_actors/hit.cpp','gameplay_session/session.cpp','gameplay_tasks/tasks.cpp','gameplay_tasks/events.cpp','gameplay_update/update.cpp']
  units += ['gameplay_scenario/'+n+'.cpp' for n in ['interpreter','flags','offline','scene_resources','scene_controls','content','sequence_control','lighting']]
  command=[str(a.compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source')]+[str(out/'source/game/native'/n) for n in units]+[str(out/'tests.cpp'),'-o',str(binary)];record['command']=command
  result=subprocess.run(command,env=env,capture_output=True,text=True,timeout=180);(out/'compile.txt').write_text(result.stdout+result.stderr,encoding='utf8');assert result.returncode==0,'compile failed; see compile.txt'
  result=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=90);(out/'run.txt').write_text(result.stdout+result.stderr,encoding='utf8');assert result.returncode==0,'comparison failed; see run.txt'
  record['result']=json.loads(result.stdout);assert record['result']['cases']==2048
  assert all(sha(ROOT/n)==h for n,h in before.items());record.update(status='passed',executable_sha256=sha(binary),checked_owned_instruction_comments=sum(v['matched_comments'] for v in proof))
 finally:(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['result']))
if __name__=='__main__':main()
