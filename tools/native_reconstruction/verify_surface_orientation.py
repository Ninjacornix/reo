"""Seal/compare actual 6657B0, helper bodies and native canonical surface owner.

617000 is an explicit previously qualified native Grid seam, not transitive
original execution. All other invoked orientation/pose/math bodies execute.
"""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--math-receipt',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 math_path=a.math_receipt.resolve();math=json.loads(math_path.read_bytes());assert math['source_unchanged']and math['observed']['checks']==2998328 and sha(a.compiler)==math['compiler_sha256']
 math_sources=[n for n in math['source_sha256']if n.startswith('recomp/config/')and '195E50'not in n]
 for n in math_sources+['game/native/transform_math/transform_math.cpp','game/native/transform_math/transform_math.hpp','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp']:assert sha(ROOT/n)==math['source_sha256'][n],n
 response_q_path=ROOT/'tools/native_reconstruction/native_gameplay_collision_response_qualification_v1.json';response_q=json.loads(response_q_path.read_bytes())
 for n in ['game/native/gameplay_collision/response.cpp','game/native/gameplay_collision/response.hpp']:
  assert all(sha(ROOT/n)==v['source_sha256'][n]for v in response_q['cohorts'].values()),n
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read_elf=elf_reader(elf.read_bytes())
 blobs={}
 for bank,digest in [('o0','bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'),('o2','45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226')]:
  image=ROOT/'build-function-index/owned-overlays'/f'{bank}.bin';assert sha(image)==digest;blobs[bank]=image.read_bytes()
 extra=[next((ROOT/'recomp/config/output').glob('sub_'+n+'_*')).relative_to(ROOT).as_posix()for n in ['0018F470','00191500','00191740','00191900','00191BC0','00191DF0','00191E50','001920A0','001921A0','001921B0']]
 extra += [f'recomp/config/output_ovl/{bank}/{bank}_{n}_0x{n.lstrip("0").lower()}.cpp'for bank,n in [('o0','00370100'),('o2','00616F20'),('o2','006657B0'),('o2','0065E4A0')]]
 originals=math_sources+extra;proof=[]
 for n in extra:
  begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/n).read_text()).groups()]
  bank='o2'if begin>=0x570000 else 'o0'if begin>=0x370000 else None
  read=read_elf if bank is None else lambda at,size,b=bank:blobs[b][at-(0x570000 if b=='o2'else 0x370000):at-(0x570000 if b=='o2'else 0x370000)+size]
  proof.append(compare_source('surface orientation complete original body/math/wrapper',n,begin,end,read))
 native_cpp=['game/native/'+n for n in ['transform_math/transform_math.cpp','gameplay_world/surface_orientation_math.cpp','gameplay_world/surface_orientation.cpp','gameplay_world/motion_transforms.cpp','gameplay_world/world.cpp','gameplay_actors/entity.cpp','gameplay_actors/input.cpp','gameplay_actors/health.cpp','gameplay_collision/response.cpp','gameplay_collision/collision.cpp']]
 native=set(native_cpp);pending=list(native_cpp)
 while pending:
  n=pending.pop()
  for rel in re.findall(r'^#include "([^"]+)"',(ROOT/n).read_text(),re.M):
   dep=((ROOT/n).parent/rel).resolve();assert dep.is_relative_to(ROOT/'game/native')and dep.is_file();key=dep.relative_to(ROOT).as_posix()
   if key not in native:native.add(key);pending.append(key)
 helpers=['tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','tools/native_reconstruction/gameplay_world_oracle/surface_orientation_tests.cpp','tools/native_reconstruction/verify_surface_orientation.py']
 files=sorted(native)+originals+helpers+[response_q_path.relative_to(ROOT).as_posix()];before={n:sha(ROOT/n)for n in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),qualified_math_receipt=dict(path=str(math_path),sha256=sha(math_path)),qualified_floor= dict(path=response_q_path.relative_to(ROOT).as_posix(),sha256=sha(response_q_path)),original_owned_bodies=proof,declared_native_child_seams=['617000 floor query via unchanged independently qualified response::Grid; optional test provider effects/errors'],complete_transitive_original_execution=False,game_run=False,installed_in_game=False,stage4_complete=False)
 try:
  for n in files:
   dest=out/'source'/n;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes((ROOT/n).read_bytes())
  reference=(ROOT/helpers[0]).read_text()+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_ABS_S(a) std::fabs(a)\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n'
  (out/'reference.hpp').write_text(reference);(out/'tests.cpp').write_bytes((ROOT/helpers[1]).read_bytes());body='\n'.join((ROOT/n).read_text()for n in originals);(out/'original_surface.cpp').write_text(body)
  constants=math_path.parent/'owned_constants.hpp';assert sha(constants)==math['output_sha256']['owned_constants.hpp'];(out/'owned_constants.hpp').write_bytes(constants.read_bytes())
  data=[(at,blobs['o2'][at-0x570000:at-0x570000+size])for at,size in [(0x712b68,12),(0x712b78,12),(0x712b88,12),(0x712b98,12),(0x740430,4),(0x740470,4)]]+[(0x38b290,blobs['o0'][0x38b290-0x370000:0x38b294-0x370000])]
  record['owned_orientation_data']=[dict(address=hex(at),hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest())for at,raw in data]
  (out/'orientation_constants.hpp').write_text('inline void orientation_constants(std::uint8_t* m){\n'+''.join(' {const std::uint8_t b[]{'+','.join(str(v)for v in raw)+'};std::memcpy(m+'+hex(at)+',b,sizeof b);}\n'for at,raw in data)+'}\n')
  actual={Path(n).stem for n in originals};names=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual));decl+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for n in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl)
  (out/'original_dispatch.hpp').write_text(''.join('case 0x'+n.split('_0x')[1]+':'+n+'(memory,context,runtime);return;\n'for n in sorted(actual)))
  for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
  for n in ['ps2_recompiled_functions.h','o0_functions.h','o2_functions.h']:(out/n).write_text('#pragma once\n#include "functions.h"\n')
  for n in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/n).write_text('#pragma once\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'native-surface-orientation.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source')]+[str(out/'source'/n)for n in native_cpp]+[str(out/'tests.cpp'),'-o',str(binary)];record['command']=command
  result=subprocess.run(command,env=env,capture_output=True,text=True,timeout=180);(out/'compile.txt').write_text(result.stdout+result.stderr);assert result.returncode==0,'compile failed; see sealed compile.txt'
  result=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=120);(out/'run.txt').write_text(result.stdout+result.stderr);assert result.returncode==0,'original surface comparison failed; see sealed run.txt'
  observed=json.loads(result.stdout);assert observed['turn_cases']==65536 and observed['orientation_cases']>=8192 and observed['grid_pose_cases']>=32
  assert all(sha(ROOT/n)==h for n,h in before.items()),'source drift during qualification'
  record.update(status='passed',observed=observed,binary_sha256=sha(binary),source_unchanged=True)
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
