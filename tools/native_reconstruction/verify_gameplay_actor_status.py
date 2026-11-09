"""Complete owned-body comparison for native actor status timers and actions."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
 assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes()
 ids=['0065FEB0','0065FF70','00660240','00660310','006605B0','006607D0','00660980'];sources=[next((ROOT/'recomp/config/output_ovl/o2').glob('o2_'+n+'_*')).relative_to(ROOT).as_posix() for n in ids];proof=[]
 for src in sources:
  begin,end=[int(x,16) for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/src).read_text()).groups()]
  proof.append(compare_source('complete native health contract',src,begin,end,lambda at,count:raw[at-0x570000:at-0x570000+count]))
 files=sources+[f'game/native/gameplay_actors/{n}' for n in ('health.hpp','health.cpp','status.hpp','status.cpp')]+['game/native/gameplay_session/session.hpp','game/native/gameplay_session/session.cpp','tools/native_reconstruction/gameplay_actor_oracle/status_runtime.hpp','tools/native_reconstruction/gameplay_actor_oracle/status_tests.cpp','tools/native_reconstruction/verify_gameplay_actor_status.py'];before={n:sha(ROOT/n) for n in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),source_sha256=before,original_owned_bodies=proof,declared_service_ports=True,game_run=False,stage4_complete=False)
 try:
  core=out/'source/game/native/gameplay_actors';core.mkdir(parents=True)
  for n in ('health.hpp','health.cpp','status.hpp','status.cpp'):(core/n).write_bytes((ROOT/'game/native/gameplay_actors'/n).read_bytes())
  for src,dst in [('tools/native_reconstruction/gameplay_actor_oracle/status_runtime.hpp','status_runtime.hpp'),('tools/native_reconstruction/gameplay_actor_oracle/status_tests.cpp','tests.cpp')]: (out/dst).write_bytes((ROOT/src).read_bytes())
  session=out/'source/game/native/gameplay_session';session.mkdir(parents=True)
  for n in ('session.hpp','session.cpp'):(session/n).write_bytes((ROOT/'game/native/gameplay_session'/n).read_bytes())
  body='\n'.join((ROOT/src).read_text() for src in sources);(out/'original_status.cpp').write_text(body,encoding='utf8',newline='\n')
  for n in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/n).write_text('#pragma once\n#include "status_runtime.hpp"\n',encoding='utf8',newline='\n')
  for n in ('ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h'):(out/n).write_text('#pragma once\n',encoding='utf8',newline='\n')
  actual={Path(src).stem for src in sources};calls=set(re.findall(r'\b(o2_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
  declarations=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for name in sorted(actual))
  declarations+=''.join('inline void '+name+'(std::uint8_t* r,R5900Context* c,PS2Runtime* t){original_port(r,c,t); }\n' for name in sorted(calls-actual))
  (out/'o2_functions.h').write_text('#pragma once\n'+declarations,encoding='utf8',newline='\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'actor-status.exe'
  command=[str(a.compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-I'+str(out),'-I'+str(out/'source'),str(core/'health.cpp'),str(core/'status.cpp'),str(session/'session.cpp'),str(out/'tests.cpp'),'-o',str(binary)];record['command']=command
  c=subprocess.run(command,env=env,capture_output=True,text=True,timeout=120);(out/'compile.txt').write_text(c.stdout+c.stderr,encoding='utf8',newline='\n');assert c.returncode==0,'compile failed'
  c=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=90);(out/'run.txt').write_text(c.stdout+c.stderr,encoding='utf8',newline='\n');assert c.returncode==0,'original comparison failed'
  observed=json.loads(c.stdout);assert observed['cases']==163840 and observed['rng_requests']==32768
  assert all(sha(ROOT/n)==h for n,h in before.items());record.update(status='native actor status timers and actions match seven complete original bodies',observed=observed,source_unchanged=True,binary_sha256=sha(binary),limits=['Original health arithmetic/admission and periodic gates are executed; class refresh, feedback, publication, cleanup, recovery and snapshots remain declared providers.','No actual game consumers replaced; native entity composition and status/actions remain separate migration work.'])
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p) for p in out.rglob('*') if p.is_file() and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8',newline='\n')
 print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
