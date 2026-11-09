"""Compare canonical actor transform consumers with full original math execution."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--math-receipt',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 math_path=a.math_receipt.resolve();math=json.loads(math_path.read_bytes());assert math['source_unchanged']and math['observed']['checks']==2998328 and sha(a.compiler)==math['compiler_sha256']
 math_sources=[n for n in math['source_sha256']if n.startswith('recomp/config/')and '195E50'not in n]
 for n in math_sources+['game/native/transform_math/transform_math.cpp','game/native/transform_math/transform_math.hpp','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp']:assert sha(ROOT/n)==math['source_sha256'][n],n
 image=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';blob=image.read_bytes();originals=['recomp/config/output_ovl/o2/o2_0065E3A0_0x65e3a0.cpp','recomp/config/output_ovl/o2/o2_0065E4A0_0x65e4a0.cpp'];proof=[]
 provider='recomp/config/output_ovl/o2/o2_006657B0_0x6657b0.cpp'
 for n in originals+[provider]:
  begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/n).read_text()).groups()];proof.append(compare_source('canonical actor transforms or explicit remaining surface provider',n,begin,end,lambda at,size:blob[at-0x570000:at-0x570000+size]))
 native_cpp=['game/native/transform_math/transform_math.cpp','game/native/gameplay_world/motion_transforms.cpp','game/native/gameplay_world/motion.cpp','game/native/gameplay_world/world.cpp','game/native/gameplay_actors/entity.cpp','game/native/gameplay_actors/input.cpp','game/native/gameplay_actors/health.cpp'];native=set(native_cpp);pending=list(native_cpp)
 while pending:
  name=pending.pop()
  for relative in re.findall(r'^#include "([^"]+)"',(ROOT/name).read_text(),re.M):
   dep=((ROOT/name).parent/relative).resolve();assert dep.is_relative_to(ROOT/'game/native')and dep.is_file();key=dep.relative_to(ROOT).as_posix()
   if key not in native:native.add(key);pending.append(key)
 helpers=['tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','tools/native_reconstruction/gameplay_world_oracle/motion_transform_tests.cpp','tools/native_reconstruction/verify_motion_transforms.py'];files=sorted(native)+math_sources+originals+[provider]+helpers;before={n:sha(ROOT/n)for n in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),qualified_math_receipt=dict(path=str(math_path),sha256=sha(math_path)),original_owned_bodies=proof,original_math_helpers_executed=True,surface_provider_native=False,actual_game_run=False,stage4_complete=False)
 try:
  for n in files:
   dest=out/'source'/n;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes((ROOT/n).read_bytes())
  (out/'reference.hpp').write_bytes((ROOT/helpers[0]).read_bytes());(out/'tests.cpp').write_bytes((ROOT/helpers[1]).read_bytes());math_body='\n'.join((ROOT/n).read_text()for n in math_sources);outer_body='\n'.join((ROOT/n).read_text()for n in originals);(out/'original_transforms.cpp').write_text(math_body);(out/'original_motion_transforms.cpp').write_text(outer_body)
  constants=math_path.parent/'owned_constants.hpp';assert sha(constants)==math['output_sha256']['owned_constants.hpp'];(out/'owned_constants.hpp').write_bytes(constants.read_bytes())
  actual={Path(n).stem for n in math_sources+originals};names=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',math_body+'\n'+outer_body));decl=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual));decl+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for n in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl)
  for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
  for n in ['ps2_recompiled_functions.h','o0_functions.h','o2_functions.h']:(out/n).write_text('#pragma once\n#include "functions.h"\n')
  for n in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/n).write_text('#pragma once\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'native-motion-transforms.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source')]+[str(out/'source'/n)for n in native_cpp]+[str(out/'tests.cpp'),'-o',str(binary)];record['command']=command
  result=subprocess.run(command,env=env,capture_output=True,text=True,timeout=180);(out/'compile.txt').write_text(result.stdout+result.stderr);assert result.returncode==0,'compile failed; see sealed compile.txt'
  result=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=120);(out/'run.txt').write_text(result.stdout+result.stderr);assert result.returncode==0,'original motion comparison failed; see run.txt'
  observed=json.loads(result.stdout);assert observed['local_cases']==4097 and observed['pose_cases']==4096 and observed['failure_cases']==16 and observed['frame_cases']==3
  assert all(sha(ROOT/n)==h for n,h in before.items()),'source drift during compile/qualification'
  record.update(status='canonical native local-motion and affine-pose consumers match actual complete original/math chains with explicit surface provider; failure/order/World composition passed',observed=observed,binary_sha256=sha(binary),source_unchanged=True,limits=['Full65E3A0/65E4A0 bodies and their real original math chain execute;6657B0 remains the declared required native surface/pose boundary.','The fixture compares the complete actor projection and surface-provider observations/effects; native production never shadows an actor or executes guest instructions.','Native affine basis excludes arbitrary nonaffine fourth lanes; the independent math qualification covers general preserved matrix lanes.','Native output/profile readiness is a new capability invariant, not an original guest field. Unsupported math/profile/provider errors cannot become successful legacy fallbacks.','This is isolated original-body qualification, not an installed game/native-world playtest or whole Stage4 completion.'])
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
