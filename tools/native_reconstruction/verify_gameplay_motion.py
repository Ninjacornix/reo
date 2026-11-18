"""Execute complete owned snapshot/interpolation/finish bodies against native actors."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
 assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 image=ROOT/'build-function-index/owned-overlays/o2.bin';elf=ROOT/'game_data/SLUS_207.65'
 assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'and sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
 raw=image.read_bytes();read_main=elf_reader(elf.read_bytes());proof=[]
 originals=['recomp/config/output_ovl/o2/o2_00667370_0x667370.cpp','recomp/config/output_ovl/o2/o2_0065E670_0x65e670.cpp','recomp/config/output_ovl/o2/o2_0065E5C0_0x65e5c0.cpp','recomp/config/output_ovl/o2/o2_005DA620_0x5da620.cpp','recomp/config/output/sub_001B02D0_0x1b02d0.cpp']
 for n in originals:
  begin,end=[int(x,16)for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/n).read_text()).groups()]
  read=read_main if begin<0x570000 else lambda at,size:raw[at-0x570000:at-0x570000+size]
  proof.append(compare_source('native canonical motion policy original',n,begin,end,read))
 getter='recomp/config/output/sub_001B0300_0x1b0300.cpp';proof.append(compare_source('exact three-word mode getter declared port; remaining merged entries unexecuted',getter,0x1b0300,0x1b030c,read_main))
 native=['game/native/gameplay_world/'+n for n in ['world.hpp','world.cpp','motion.hpp','motion.cpp']]+['game/native/gameplay_actors/'+n for n in ['entity.hpp','entity.cpp','health.hpp','health.cpp','status.hpp','hit.hpp','input.hpp','input.cpp']]+['game/native/gameplay_session/session.hpp','game/native/gameplay_collision/actors.hpp','game/native/gameplay_collision/response.hpp','game/native/gameplay_collision/collision.hpp','game/native/gameplay_collision/spatial.hpp']
 files=originals+[getter]+native+['tools/native_reconstruction/gameplay_actor_oracle/runtime.hpp','tools/native_reconstruction/gameplay_world_oracle/motion_tests.cpp','tools/native_reconstruction/verify_gameplay_motion.py']
 before={n:sha(ROOT/n)for n in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),source_sha256=before,original_owned_bodies=proof,actual_game_run=False,stage4_complete=False,original_body_executed=True)
 try:
  for n in files:
   dest=out/'source'/n;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes((ROOT/n).read_bytes())
  (out/'runtime.hpp').write_bytes((ROOT/'tools/native_reconstruction/gameplay_actor_oracle/runtime.hpp').read_bytes())
  (out/'tests.cpp').write_bytes((ROOT/'tools/native_reconstruction/gameplay_world_oracle/motion_tests.cpp').read_bytes())
  body='\n'.join((ROOT/n).read_text()for n in originals);(out/'original_motion.cpp').write_text(body)
  for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "runtime.hpp"\n')
  for n in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/n).write_text('#pragma once\n')
  actual={Path(n).stem for n in originals};names=set(re.findall(r'\b((?:o2|sub)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
  declarations='void original_port(std::uint8_t*,R5900Context*,PS2Runtime*);\n'
  declarations+=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual))
  declarations+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_port(m,c,r);}\n'for n in sorted(names-actual))
  (out/'functions.h').write_text('#pragma once\n'+declarations)
  for n in ['o2_functions.h','ps2_recompiled_functions.h']:(out/n).write_text('#pragma once\n#include "functions.h"\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
  binary=out/'native-motion.exe';command=[str(a.compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source')]+[str(out/'source'/n)for n in ['game/native/gameplay_world/motion.cpp','game/native/gameplay_world/world.cpp','game/native/gameplay_actors/entity.cpp','game/native/gameplay_actors/input.cpp','game/native/gameplay_actors/health.cpp']]+[str(out/'tests.cpp'),'-o',str(binary)]
  record['command']=command;result=subprocess.run(command,env=env,capture_output=True,text=True,timeout=120);(out/'compile.txt').write_text(result.stdout+result.stderr);assert result.returncode==0,'compile failed; see sealed compile.txt'
  result=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=90);(out/'run.txt').write_text(result.stdout+result.stderr);assert result.returncode==0,'comparison failed; see run.txt'
  observed=json.loads(result.stdout);assert observed['snapshot_cases']==4096 and observed['shape_cases']==4096 and observed['finish_cases']==16896 and observed['native_boundary_cases']==5
  assert all(sha(ROOT/n)==v for n,v in before.items()),'source drift after sealed compile'
  record.update(status='canonical native action snapshot/local-shape interpolation/tagged-finish policy matches complete originals; real frame intercept/failure checks passed',observed=observed,binary_sha256=sha(binary),source_unchanged=True,limits=['Native production uses canonical Actor/World references; legacy byte projection appears only in the comparison fixture.','Native tagged queue owner remains a required MotionServices provider; the fixture compares its bounded records against executed original5DA620. Renderer/pose queue consumers are not reconstructed here.','Interpolation arithmetic corpus is finite exactly representable eighths; snapshot copies additionally cover arbitrary bit patterns. Exceptional PS2 arithmetic and aliased mutable target pointers are not admitted.','Original signed pause semantics cover all256 byte patterns; complete1B02D0 executes, with only its exact three-word1B0300 getter declared as a value port.','65E3A0/65E4A0 full Euler/PS2 trig, model motion extraction and live installation remain separate.'])
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
