"""Compare complete native frame-window semantics with owned original573480."""
import argparse,hashlib,json,os,re,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');image=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=image.read_bytes();source=next((ROOT/'recomp/config/output_ovl/o2').glob('o2_00573480_*'));begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',source.read_text()).groups()];proof=compare_source('complete original frame crossing',source.relative_to(ROOT).as_posix(),begin,end,lambda at,n:raw[at-0x570000:at-0x570000+n]);cpp=['game/native/animation/frame_events.cpp','game/native/transform_math/transform_math.cpp'];native=set(cpp);pending=cpp.copy()
 while pending:
  n=pending.pop()
  for rel in re.findall(r'^#include "([^"\n]+)"',(ROOT/n).read_text(),re.M):
   dep=((ROOT/n).parent/rel).resolve();assert dep.is_relative_to(ROOT/'game/native')and dep.is_file();key=dep.relative_to(ROOT).as_posix()
   if key not in native:native.add(key);pending.append(key)
 helpers=['tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','tools/native_reconstruction/animation/frame_event_tests.cpp',Path(__file__).relative_to(ROOT).as_posix()];files=sorted(native)+helpers+[source.relative_to(ROOT).as_posix()];before={n:sha(ROOT/n)for n in files};out.mkdir();q=dict(schema=1,status='failed',game_run=False,source_sha256=before,compiler_sha256=sha(a.compiler),original_owned_bodies=[proof])
 try:
  for n in files:dest=out/'source'/n;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes((ROOT/n).read_bytes())
  (out/'tests.cpp').write_bytes((ROOT/helpers[1]).read_bytes());(out/'reference.hpp').write_bytes((ROOT/helpers[0]).read_bytes());(out/'original.cpp').write_bytes(source.read_bytes());(out/'functions.h').write_text('void '+source.stem+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n')
  for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
  for n in ['o2_functions.h','ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/n).write_text('#pragma once\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/n)for n in cpp],str(out/'tests.cpp'),'-o',str(binary)];q['command']=command;r=subprocess.run(command,env=env,capture_output=True,text=True,timeout=90);(out/'compile.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'compile failed';r=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=90);(out/'run.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'comparison failed';q.update(status='passed',observed=json.loads(r.stdout),source_unchanged=all(sha(ROOT/n)==h for n,h in before.items()));assert q['source_unchanged']
 finally:q['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(q,indent=2)+'\n')
 print(json.dumps({'status':q['status'],'observed':q['observed']}))
if __name__=='__main__':main()
