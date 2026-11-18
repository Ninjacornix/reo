"""Complete6B80A0 authored dialogue flag duration updates."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';data=overlay.read_bytes();read=lambda at,n:data[at-0x570000:at-0x570000+n];original=ROOT/'recomp/config/output_ovl/o2/o2_006B80A0_0x6b80a0.cpp';begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',original.read_text()).groups()];proof=compare_source('complete authored dialogue flag duration update',original.relative_to(ROOT).as_posix(),begin,end,read)
 units=['game/native/gameplay_world/dialogue_flag_durations.hpp'];files=set(units);pending=list(units)
 while pending:
  name=pending.pop()
  for rel in re.findall(r'^#include "([^"\n]+)"',(ROOT/name).read_text(),re.M):
   dep=((ROOT/name).parent/rel).resolve();dep=dep if dep.is_file()else(ROOT/rel).resolve();assert dep.is_file()and dep.is_relative_to(ROOT),(name,rel);key=dep.relative_to(ROOT).as_posix()
   if key not in files:files.add(key);pending.append(key)
 helpers=['tools/native_reconstruction/dialogue_flag_durations_tests.cpp','tools/native_reconstruction/verify_dialogue_flag_durations.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'];files=sorted(files)+helpers+[original.relative_to(ROOT).as_posix()];before={name:sha(ROOT/name)for name in files};result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),original_owned_body=proof,stage4_complete=False,game_run=False,limits=['Complete6B80A0 compares every512 counters across4096 steps with all bit positions, signed overflow edges and set/unset transition values.','This pure borrowed-state operation does not manufacture its512 flags or initial counters; source6B7610 cold clear and canonical DialoguePool adoption are separately qualified.'])
 try:
  for name in files:
   target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
  (out/'reference.hpp').write_text((ROOT/helpers[2]).read_text()+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n');(out/'functions.h').write_text('#pragma once\nvoid o2_006B80A0_0x6b80a0(std::uint8_t*,R5900Context*,PS2Runtime*);\n');(out/'original.cpp').write_bytes(original.read_bytes());(out/'original_dispatch.hpp').write_text('case 0x6b80a0:o2_006B80A0_0x6b80a0(memory,context,runtime);return;\n')
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  (out/'o2_functions.h').write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units if name.endswith('.cpp')],str(out/'source'/helpers[0]),str(out/'original.cpp'),'-o',str(binary)];result['command']=command
  for label,cmd in [('compile',command),('run',[str(binary)])]:
   done=subprocess.run(cmd,env=env,capture_output=True,timeout=180);(out/(label+'.txt')).write_bytes(done.stdout+done.stderr);assert done.returncode==0,label+' failed: '+(done.stdout+done.stderr).decode(errors='replace')[-1500:]
   if label=='run':result['observed']=json.loads(done.stdout)
  result['snapshot_unchanged']=all(sha(out/'source'/name)==digest for name,digest in before.items());assert result['snapshot_unchanged'];result['live_source_drift']=[name for name,digest in before.items()if not(ROOT/name).is_file()or sha(ROOT/name)!=digest];result['status']='passed'
 finally:
  result['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.iterdir()if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps(dict(status=result['status'],observed=result['observed'],live_source_drift=result['live_source_drift'])))
if __name__=='__main__':main()
