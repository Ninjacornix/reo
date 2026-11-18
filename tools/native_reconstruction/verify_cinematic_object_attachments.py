"""Compare full5717C0 attachment math through real native model views."""
import argparse,hashlib,json,os,re,struct,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read_main=elf_reader(elf.read_bytes())
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';two=overlay.read_bytes();pending=[0x5717c0];entries={}
 while pending:
  at=pending.pop()
  if at in entries:continue
  found=list((ROOT/'recomp/config/output_ovl/o2'if at>=0x570000 else ROOT/'recomp/config/output').glob(f'{"o2"if at>=0x570000 else "sub"}_{at:08X}_*'))
  if not found:continue
  key=found[0].relative_to(ROOT).as_posix();entries[at]=key
  pending.extend(int(v,16)for v in re.findall(r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)',found[0].read_text()))
 originals=list(entries.values());proof=[]
 for name in originals:
  begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/name).read_text()).groups()]
  proof.append(compare_source('complete cinematic object attachment/math body',name,begin,end,read_main if begin<0x570000 else lambda at,n:two[at-0x570000:at-0x570000+n]))
 units=['game/native/'+n for n in ['gameplay_world/cinematic_object_attachment.cpp','animation/model.cpp','animation/model_math.cpp','animation/curves.cpp','animation/constraint_math.cpp','transform_math/transform_math.cpp']];native=set(units);pending=list(units)
 while pending:
  name=pending.pop()
  for rel in re.findall(r'^#include "([^"]+)"',(ROOT/name).read_text(),re.M):
   dep=((ROOT/name).parent/rel).resolve();assert dep.is_file()and dep.is_relative_to(ROOT/'game/native'),(name,rel);key=dep.relative_to(ROOT).as_posix()
   if key not in native:native.add(key);pending.append(key)
 helpers=['tools/native_reconstruction/cinematic_object_attachment_tests.cpp','tools/native_reconstruction/verify_cinematic_object_attachments.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h'];files=sorted(native)+helpers+originals;before={n:sha(ROOT/n)for n in files};out.mkdir();record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),game_run=False,installed_in_game=False,stage4_complete=False,original_owned_bodies=proof,limits=['Source parent node matrices project actual native model views from owned skeletons and controlled root poses; original asset packing/construction is not newly executed.','Parent scale is an explicit controlled caller input for both original actor and category10 lookup paths. This does not admit an inferred object model-work scale.','Actual attachment command parent binding, authored stream cadence and complete scene installation remain open.'])
 try:
  for name in files:
   target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
  reference=(ROOT/helpers[2]).read_text().replace('pc{},branch_pc{},fcr31{}','pc{},branch_pc{},fcr31{},vu0_vpu_stat{}').replace('Register r[32];','std::uint64_t lo{},hi{},lo1{},hi1{};Register r[32];')
  reference+='\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define FPU_SQRT_S(a) std::sqrt(a)\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n#define SRA32(v,n) (std::int32_t(v) >> (n))\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n';(out/'reference.hpp').write_text(reference);(out/'ps2_fpu_convert.h').write_bytes((ROOT/helpers[3]).read_bytes())
  actual={Path(n).stem for n in originals};body='\n'.join((ROOT/n).read_text()for n in originals);names=set(re.findall(r'\b((?:sub|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual));decl+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for n in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(n).stem+'(memory,context,runtime);return;\n'for at,n in sorted(entries.items())))
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  for name in ['o2_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  constants='inline void owned_constants(std::uint8_t* p){\n';record['owned_constants']={}
  for at,n in [(0x22fe20,32),(0x241c78,40),(0x241e90,4),(0x73de00,4)]:
   raw=read_main(at,n)if at<0x570000 else two[at-0x570000:at-0x570000+n];record['owned_constants'][hex(at)]=raw.hex();constants+='{const std::uint8_t b[]{'+','.join(map(str,raw))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}\n'
  (out/'owned_constants.hpp').write_text(constants+'}\n')
  seal=ROOT/'tools/native_reconstruction/native_secondary_pose_links_qualification_v1.json';ref=json.loads(seal.read_bytes())['cohorts']['links']['llvm'];receipt=ROOT/ref['receipt'];assert sha(receipt)==ref['receipt_sha256'];r=json.loads(receipt.read_bytes());package=receipt.parent/'owned_skeletons.bin';assert r['status']=='passed'and sha(package)==r['output_sha256']['owned_skeletons.bin'];(out/'owned_skeletons.bin').write_bytes(package.read_bytes());record['skeleton_inputs']=dict(receipt=receipt.relative_to(ROOT).as_posix(),receipt_sha256=sha(receipt),package_sha256=sha(package))
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/n)for n in units],str(out/'original.cpp'),str(out/'source'/helpers[0]),'-o',str(binary)];record['command']=command
  r=subprocess.run(command,env=env,capture_output=True,text=True,timeout=180);(out/'compile.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'compile failed'
  r=subprocess.run([str(binary),str(out/'owned_skeletons.bin')],env=env,capture_output=True,text=True,timeout=120);(out/'run.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'comparison failed'
  record.update(status='passed',observed=json.loads(r.stdout),source_unchanged=all(sha(ROOT/n)==h for n,h in before.items()));assert record['source_unchanged']
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
