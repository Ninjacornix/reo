"""Seal complete581870 scene-trigger source bodies and native comparisons."""
import argparse,hashlib,json,os,re,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';main_read=elf_reader(elf.read_bytes());banks={}
 for bank,digest in [('o2','45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'),('o0','bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2')]:
  path=ROOT/f'build-function-index/owned-overlays/{bank}.bin';assert sha(path)==digest;banks[bank]=path.read_bytes()
 def read(at,n):
  if at>=0x570000:return banks['o2'][at-0x570000:at-0x570000+n]
  if at>=0x370000:return banks['o0'][at-0x370000:at-0x370000+n]
  return main_read(at,n)
 pending=[0x581870,0x5c1710,0x5c2f00];entries={}
 while pending:
  at=pending.pop()
  if at in entries:continue
  bank='o2'if at>=0x570000 else'o0'if at>=0x370000 else'sub';directory=ROOT/('recomp/config/output_ovl/'+bank if bank!='sub'else'recomp/config/output');paths=list(directory.glob(f'{bank}_{at:08X}_*'))
  if not paths:continue
  path=paths[0];entries[at]=path.relative_to(ROOT).as_posix()
  if at not in [0x1920a0,0x191500,0x191ef0,0x191f80,0x371880,0x66a3a0,0x1b0300]:pending.extend(int(x,16)for x in re.findall(r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)',path.read_text()))
 originals=sorted(set(entries.values()));proof=[]
 for name in originals:
  begin,end=[int(x,16)for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/name).read_text()).groups()];proof.append(compare_source('complete head reaction, targeting or reached math body',name,begin,end,read))
 units=['game/native/'+group+'/'+name+'.cpp'for group,names in [
  ('gameplay_world',['actor_scene_triggers','head_reaction','world','linked_models','auxiliary_actors','scene_primary_actors','model_poses','model_constraints','bodies','target_metrics','cinematic_objects','secondary_pose_dynamics','secondary_pose_contacts']),
  ('gameplay_actors',['entity','input','health']),('gameplay_collision',['collision','response','actors','actor_views','trace']),
  ('animation',['model','model_math','curves','constraints','constraint_math','playback','model_blend','motion_bank','scalar_playback','secondary_pose_math']),('transform_math',['transform_math','heading']),('gameplay_scenario',['content','scene_controls','flags','scene_matrix_programs','scene_matrix_tables','scene_models','scene_model_bindings']),('gameplay_session',['session']),('gameplay_navigation',['bank'])]for name in names]
 files=set(units);pending=list(units)
 while pending:
  name=pending.pop()
  for rel in re.findall(r'^#include "([^"\n]+)"',(ROOT/name).read_text(),re.M):
   dep=((ROOT/name).parent/rel).resolve();dep=dep if dep.is_file()else(ROOT/rel).resolve();assert dep.is_file()and dep.is_relative_to(ROOT),(name,rel);key=dep.relative_to(ROOT).as_posix()
   if key not in files:files.add(key);pending.append(key)
 helpers=['tools/native_reconstruction/animation/actor_scene_triggers_tests.cpp','tools/native_reconstruction/animation/verify_actor_scene_triggers.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h']
 files=sorted(files)+helpers+originals;before={name:sha(ROOT/name)for name in files};out.mkdir();record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),original_owned_bodies=proof,game_run=False,installed_in_game=False,stage4_complete=False,limits=['Complete581870, reached5C1710/5C2F00 and polygon/local-actor helpers execute on actual typed native Records,World,SceneMatrixPrograms,FlagState.','Finite admitted128-record/16-channel profile only; no game run or full Stage4 acceptance.'])
 try:
  for name in files:
   target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
  reference=(ROOT/helpers[2]).read_text().replace('Register r[32];','std::uint64_t lo{},hi{},lo1{},hi1{};Register r[32];').replace('pc{},branch_pc{},fcr31{}','pc{},branch_pc{},fcr31{},vu0_vpu_stat{}')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define FPU_SQRT_S(a) std::sqrt(a)\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n';(out/'reference.hpp').write_text(reference);(out/'ps2_fpu_convert.h').write_bytes((ROOT/helpers[3]).read_bytes())
  body='\n'.join((ROOT/name).read_text()for name in originals);actual={Path(name).stem for name in originals};names=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in sorted(entries.items())))
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  for name in ['o0_functions.h','o2_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  constants='inline void owned_constants(std::uint8_t* p){\n';record['owned_constants']={}
  for at,n in [(0x70a720,32)]:
   data=read(at,n);record['owned_constants'][hex(at)]=data.hex();constants+='{const std::uint8_t b[]{'+','.join(map(str,data))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}'+'\n'
  (out/'owned_constants.hpp').write_text(constants+'}\n');env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/helpers[0]),str(out/'original.cpp'),'-Wl,--gc-sections','-o',str(binary)];record['command']=command
  result=subprocess.run(command,env=env,capture_output=True,timeout=240);(out/'compile.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'compile failed'
  result=subprocess.run([str(binary)],env=env,capture_output=True,timeout=180);(out/'run.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'comparison failed'
  record.update(status='passed',observed=json.loads(result.stdout),source_unchanged=all(sha(ROOT/name)==digest for name,digest in before.items()));assert record['source_unchanged']
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
