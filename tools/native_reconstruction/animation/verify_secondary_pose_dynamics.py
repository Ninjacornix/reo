"""Compare native complete secondary dynamics and selector with complete owned source bodies."""
import argparse,hashlib,json,os,re,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';main_read=elf_reader(elf.read_bytes());overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes();o0=ROOT/'build-function-index/owned-overlays/o0.bin';assert sha(o0)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2';raw0=o0.read_bytes();read=lambda at,n:main_read(at,n)if at<0x370000 else raw0[at-0x370000:at-0x370000+n]if at<0x570000 else raw[at-0x570000:at-0x570000+n]
 pending=[0x61a620,0x61a820,0x61aaa0,0x61b1a0,0x61b920];entries={}
 while pending:
  at=pending.pop()
  if at in entries:continue
  bank='o2'if at>=0x570000 else'o0'if at>=0x370000 else'sub';directory=ROOT/('recomp/config/output_ovl/'+bank if bank!='sub'else'recomp/config/output');paths=list(directory.glob(f'{bank}_{at:08X}_*'));
  if not paths:continue # Merged-body branch labels are not callable source units.
  assert len(paths)==1,hex(at);path=paths[0];entries[at]=path.relative_to(ROOT).as_posix()
  #1920A0's file also contains separately entered helpers after its return.
  # Their unprojected calls get throwing wrappers, not fabricated bodies.
  if at!=0x1920a0:pending.extend(int(x,16)for x in re.findall(r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)',path.read_text()))
 originals=sorted(set(entries.values()));proof=[]
 callers=['recomp/config/output_ovl/o2/o2_0066B8E0_0x66b8e0.cpp','recomp/config/output_ovl/o2/o2_00683B90_0x683b90.cpp','recomp/config/output_ovl/o2/o2_00682D10_0x682d10.cpp','recomp/config/output_ovl/o2/o2_005F1290_0x5f1290.cpp']
 for name in callers:
  begin,end=[int(x,16)for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/name).read_text()).groups()];proof.append(compare_source('actual history/record-clear initialization caller',name,begin,end,read))
 for name in originals:
  begin,end=[int(x,16)for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/name).read_text()).groups()];proof.append(compare_source('complete secondary pose selector/dynamics/math body',name,begin,end,read))
 units=['game/native/animation/secondary_pose_math.cpp','game/native/animation/constraint_math.cpp','game/native/transform_math/transform_math.cpp','game/native/animation/model.cpp','game/native/animation/model_math.cpp','game/native/animation/curves.cpp','game/native/gameplay_world/secondary_pose_contacts.cpp','game/native/gameplay_world/secondary_pose_dynamics.cpp','game/native/transform_math/heading.cpp'];native=set(units+['game/native/gameplay_world/actor_initial_state.hpp']);pending=list(native)
 while pending:
  name=pending.pop()
  for rel in re.findall(r'^#include "([^"]+)"',(ROOT/name).read_text(),re.M):
   dep=((ROOT/name).parent/rel).resolve();assert dep.is_file()and dep.is_relative_to(ROOT);key=dep.relative_to(ROOT).as_posix()
   if key not in native:native.add(key);pending.append(key)
 helpers=['tools/native_reconstruction/animation/secondary_pose_dynamics_tests.cpp','tools/native_reconstruction/animation/verify_secondary_pose_dynamics.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','game/native/animation/CMakeLists.txt','game/native/gameplay_world/CMakeLists.txt'];files=sorted(native)+helpers+originals+callers;before={name:sha(ROOT/name)for name in files};out.mkdir();record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),game_run=False,installed_in_game=False,stage4_complete=False,original_owned_bodies=proof,limits=['Finite FP32 model inputs and four owned secondary descriptor profiles only; no physical PS2 exceptional arithmetic claim.','Complete61A820 comparisons use P07 for profile0 and HP07 for profiles1..3; unsupported table extents and mismatched topology remain refused.','No game run or full Stage4 acceptance in this standalone helper qualification.'])
 try:
  for name in files:
   target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
  reference=(ROOT/helpers[2]).read_text().replace('pc{},branch_pc{},fcr31{}','pc{},branch_pc{},fcr31{},vu0_vpu_stat{}')+'\n#define SRA32(a,b) (std::int32_t(a)>>unsigned(b))\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define FPU_SQRT_S(a) std::sqrt(a)\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n';(out/'reference.hpp').write_text(reference)
  body='\n'.join((ROOT/name).read_text()for name in originals);actual={Path(name).stem for name in originals};names=set(re.findall(r'\b((?:sub|o2|o0)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in sorted(entries.items())))
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  for name in ['o2_functions.h','o0_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';members={r['member']:r for r in json.loads(inventory.read_bytes())};skeletons=[];record['owned_assets']=[]
  with(ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb')as stream:
   for member in [507,490]:
    row=members[f'NETBIO00.DAT/0/{member}'];stream.seek(row['iso_offset']);payload=stream.read(row['bytes']);assert hashlib.sha256(payload).hexdigest()==row['sha256'];offset,size=struct.unpack_from('<II',payload,0x24);assert offset and size and size<=len(payload)-offset;skeletons.append(payload[offset:offset+size]);record['owned_assets'].append(row)
  (out/'owned_skeletons.bin').write_bytes(struct.pack('<I',len(skeletons))+b''.join(struct.pack('<I',len(b))+b for b in skeletons))
  constants='inline void owned_constants(std::uint8_t* p){\n';record['owned_constants']={}
  for at,n in [(0x73fc38,20),(0x70f298,0x480),(0x22fe20,32),(0x241c78,40),(0x241e90,4),(0x2392b8,76),(0x240000,0x2000)]:
   data=read(at,n);record['owned_constants'][hex(at)]=data.hex();constants+='{const std::uint8_t b[]{'+','.join(map(str,data))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}\n'
  (out/'owned_constants.hpp').write_text(constants+'}\n');env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/helpers[0]),str(out/'original.cpp'),'-o',str(binary)];record['command']=command
  result=subprocess.run(command,env=env,capture_output=True,timeout=180);(out/'compile.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'compile failed'
  result=subprocess.run([str(binary),str(out/'owned_skeletons.bin')],env=env,capture_output=True,timeout=120);(out/'run.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'comparison failed'
  record.update(status='passed',observed=json.loads(result.stdout),source_unchanged=all(sha(ROOT/name)==digest for name,digest in before.items()));assert record['source_unchanged']
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
