"""Compare native actor-frame orchestration with the complete owned original body."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
 assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 raw=overlay.read_bytes();source='recomp/config/output_ovl/o2/o2_00669F30_0x669f30.cpp'
 proof=compare_source('complete eight-primary-actor frame',source,0x669f30,0x66a2dc,lambda at,count:raw[at-0x570000:at-0x570000+count])
 files=('game/native/gameplay_actors/frame.hpp','game/native/gameplay_actors/frame.cpp','tools/native_reconstruction/gameplay_actor_oracle/runtime.hpp','tools/native_reconstruction/gameplay_actor_oracle/tests.cpp',source,'tools/native_reconstruction/verify_gameplay_actor_frame.py')
 before={n:sha(ROOT/n) for n in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),source_sha256=before,original_owned_body=proof,original_body_executed=True,declared_callee_ports=True,actual_game_run=False,stage4_complete=False)
 try:
  core=out/'source/game/native/gameplay_actors';core.mkdir(parents=True)
  for name in ('frame.hpp','frame.cpp'):(core/name).write_bytes((ROOT/'game/native/gameplay_actors'/name).read_bytes())
  for name in ('runtime.hpp','tests.cpp'):(out/name).write_bytes((ROOT/'tools/native_reconstruction/gameplay_actor_oracle'/name).read_bytes())
  body=(ROOT/source).read_bytes();(out/'original_actor.cpp').write_bytes(body)
  for name in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/name).write_text('#pragma once\n#include "runtime.hpp"\n',encoding='utf8',newline='\n')
  for name in ('ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h'):(out/name).write_text('#pragma once\n',encoding='utf8',newline='\n')
  names=sorted(set(re.findall(r'\b(o2_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body.decode())))
  (out/'o2_functions.h').write_text('#pragma once\n'+''.join('inline void '+n+'(std::uint8_t* r,R5900Context* c,PS2Runtime* t){original_port(r,c,t);}\n' for n in names),encoding='utf8',newline='\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
  binary=out/'actor-frame.exe';command=[str(a.compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),str(core/'frame.cpp'),str(out/'tests.cpp'),'-o',str(binary)]
  record['command']=command
  result=subprocess.run(command,env=env,capture_output=True,text=True,timeout=120);(out/'compile.txt').write_text(result.stdout+result.stderr,encoding='utf8',newline='\n');assert result.returncode==0,'compile failed; see sealed compile.txt'
  result=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=60);(out/'run.txt').write_text(result.stdout+result.stderr,encoding='utf8',newline='\n');assert result.returncode==0,'differential check failed; see run.txt'
  observed=json.loads(result.stdout);assert observed['cases']==4096 and observed['ordered_calls']>0
  faults={
   'freeze-paused-actors':('if(world.mode==0)services.begin_offline_frame(world);','if(world.paused)return;\n    if(world.mode==0)services.begin_offline_frame(world);'),
   'omit-remote-input-clear':('if(world.filter_nonselected_input && actor.slot!=world.selected_actor)','if(false && actor.slot!=world.selected_actor)'),
   'retain-missing-grid-flag':('actor.status&=~std::uint32_t(0x4000);','actor.status|=0;'),
  }
  detected=[];core_body=(core/'frame.cpp').read_text()
  for label,(anchor,replacement) in faults.items():
   assert core_body.count(anchor)==1
   mutant=core/(label+'.cpp');mutant.write_text(core_body.replace(anchor,replacement),encoding='utf8',newline='\n');exe=out/(label+'.exe')
   cmd=[str(mutant) if v==str(core/'frame.cpp') else str(exe) if v==str(binary) else v for v in command]
   compiled=subprocess.run(cmd,env=env,capture_output=True,text=True,timeout=120);(out/(label+'-compile.txt')).write_text(compiled.stdout+compiled.stderr,encoding='utf8',newline='\n');assert compiled.returncode==0,label+' mutant compile'
   failed=subprocess.run([str(exe)],env=env,capture_output=True,text=True,timeout=60);(out/(label+'-run.txt')).write_text(failed.stdout+failed.stderr,encoding='utf8',newline='\n');assert failed.returncode==1 and 'actor differential case' in failed.stderr,label+' escaped detection';detected.append(label)
  assert all(sha(ROOT/n)==value for n,value in before.items()),'compiled source drift'
  record.update(status='native primary actor frame matches complete original with declared callee ports',observed=observed,detected_faults=detected,binary_sha256=sha(binary),source_unchanged=True,limitations=['Only the complete669F30control-flow/field contract is compared; its callees are declared native fixtures, not migrated actor behaviors.','The native component has no CPU context, guest memory, runtime or source addresses; the oracle fixture deliberately retains those original-body inputs.','Corpus scalar addition uses exactly representable finite values; exceptional PS2 FPU behavior is outside admission.','No game integration or whole Stage4 completion follows from this isolated actor root.'])
 finally:
  record['output_sha256']={x.relative_to(out).as_posix():sha(x) for x in out.rglob('*') if x.is_file() and x.name!='receipt.json'}
  (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8',newline='\n')
 print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
