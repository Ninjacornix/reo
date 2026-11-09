"""Complete owned-body comparison for native health class derivation."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
 assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes();assert raw[0x71b030-0x570000:0x71b038-0x570000]==bytes.fromhex('000048420000c841')
 sources=['recomp/config/output_ovl/o2/o2_0065FAB0_0x65fab0.cpp'];proof=[]
 for src in sources:
  begin,end=[int(x,16) for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/src).read_text()).groups()]
  proof.append(compare_source('complete native health class contract',src,begin,end,lambda at,count:raw[at-0x570000:at-0x570000+count]))
 files=sources+['game/native/gameplay_actors/health.hpp','game/native/gameplay_actors/health_class.hpp','game/native/gameplay_actors/health_class.cpp','tools/native_reconstruction/gameplay_actor_oracle/class_runtime.hpp','tools/native_reconstruction/gameplay_actor_oracle/health_class_tests.cpp','tools/native_reconstruction/verify_gameplay_actor_health_class.py'];before={n:sha(ROOT/n) for n in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),source_sha256=before,original_owned_bodies=proof,declared_service_ports=True,game_run=False,stage4_complete=False)
 try:
  core=out/'source/game/native/gameplay_actors';core.mkdir(parents=True)
  for n in ('health.hpp','health_class.hpp','health_class.cpp'):(core/n).write_bytes((ROOT/'game/native/gameplay_actors'/n).read_bytes())
  for src,dst in [('tools/native_reconstruction/gameplay_actor_oracle/class_runtime.hpp','class_runtime.hpp'),('tools/native_reconstruction/gameplay_actor_oracle/health_class_tests.cpp','tests.cpp')]: (out/dst).write_bytes((ROOT/src).read_bytes())
  body='\n'.join((ROOT/src).read_text() for src in sources);(out/'original_class.cpp').write_text(body,encoding='utf8',newline='\n')
  for n in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/n).write_text('#pragma once\n#include "class_runtime.hpp"\n',encoding='utf8',newline='\n')
  for n in ('ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h'):(out/n).write_text('#pragma once\n',encoding='utf8',newline='\n')
  (out/'o2_functions.h').write_text('#pragma once\n',encoding='utf8',newline='\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'actor-health-class.exe'
  command=[str(a.compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-I'+str(out),'-I'+str(out/'source'),str(core/'health_class.cpp'),str(out/'tests.cpp'),'-o',str(binary)];record['command']=command
  c=subprocess.run(command,env=env,capture_output=True,text=True,timeout=120);(out/'compile.txt').write_text(c.stdout+c.stderr,encoding='utf8',newline='\n');assert c.returncode==0,'compile failed'
  c=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=90);(out/'run.txt').write_text(c.stdout+c.stderr,encoding='utf8',newline='\n');assert c.returncode==0,'original comparison failed'
  observed=json.loads(c.stdout);assert observed['cases']==589824 and observed['zero_maximum_cases']==64
  assert all(sha(ROOT/n)==h for n,h in before.items());record.update(status='native health class matches complete original on admitted finite ratios',observed=observed,source_unchanged=True,binary_sha256=sha(binary),limits=['Finite signed health/max ratios and actual50/25 source thresholds compared; zero-maximum division is explicitly unadmitted.','No actual game consumers replaced by this comparison.'])
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p) for p in out.rglob('*') if p.is_file() and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8',newline='\n')
 print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
