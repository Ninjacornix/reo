"""Compare complete native ground/constraint World consumers with owned models and floors."""
import argparse,hashlib,json,os,re,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--corpus',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--floor-receipt',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 corpus=a.corpus.resolve();corpus_receipt=corpus/'receipt.json';cr=json.loads(corpus_receipt.read_bytes());assert cr['clips']==59 and cr['skeletons']==2
 for n,h in cr['output_sha256'].items():assert sha(corpus/n)==h
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes())
 pending=[0x18e3c0,0x1a1fd0,0x193c80,0x1a2e00,0x193380,0x193240,0x193230,0x193220,0x192bf0,0x1925c0,0x192b30,0x5d59a0,0x5d5ab0,0x5d5ad0,0x5d5bd0,0x5d5be0,0x5d5fa0,0x5d6850,0x616f20,0x5d6400];entries={}
 while pending:
  at=pending.pop()
  if at in entries or at in [0x18dca0,0x617000]:continue
  bank='o2'if at>=0x570000 else 'o0'if at>=0x370000 else None
  found=list((ROOT/('recomp/config/output_ovl/'+bank)if bank else ROOT/'recomp/config/output').glob(f'{bank or "sub"}_{at:08X}_*'))
  if not found:continue # Internal merged-body labels are not callable definitions.
  name=found[0].relative_to(ROOT).as_posix();entries[at]=name;s=found[0].read_text()
  pending.extend(int(v,16)for v in re.findall(r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)',s)if int(v,16)not in entries)
 o2=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(o2)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';overlay=o2.read_bytes()
 for at in [0x58bf50,0x58c6a0]:entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
 o0=ROOT/'build-function-index/owned-overlays/o0.bin';assert sha(o0)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2';o0raw=o0.read_bytes()
 for at in [0x5d6400,0x5d6fc0,0x662db0]:entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
 for at in [0x3769f0,0x376ae0,0x376d50]:entries[at]=next((ROOT/'recomp/config/output_ovl/o0').glob(f'o0_{at:08X}_*')).relative_to(ROOT).as_posix()
 originals=list(entries.values());proof=[]
 for n in originals:
  begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/n).read_text()).groups()];proof.append(compare_source('complete original skeleton/model/frame/root or math body',n,begin,end,read if begin<0x370000 else (lambda at,size:o0raw[at-0x370000:at-0x370000+size])if begin<0x570000 else lambda at,size:overlay[at-0x570000:at-0x570000+size]))
 native_cpp=['game/native/'+n for n in ['animation/constraints.cpp','animation/constraint_math.cpp','animation/model.cpp','animation/model_math.cpp','animation/curves.cpp','transform_math/transform_math.cpp','gameplay_world/model_poses.cpp','gameplay_world/model_constraints.cpp','gameplay_world/linked_models.cpp','gameplay_world/auxiliary_actors.cpp','gameplay_world/scene_primary_actors.cpp','gameplay_world/world.cpp','gameplay_world/bodies.cpp','gameplay_actors/entity.cpp','gameplay_actors/input.cpp','gameplay_actors/health.cpp','gameplay_collision/collision.cpp','gameplay_collision/response.cpp','gameplay_collision/actors.cpp','gameplay_collision/actor_views.cpp']]
 native=set(native_cpp);pending=list(native_cpp)
 while pending:
  n=pending.pop()
  for rel in re.findall(r'^#include "([^"]+)"',(ROOT/n).read_text(),re.M):
   dep=((ROOT/n).parent/rel).resolve();assert dep.is_relative_to(ROOT/'game/native')and dep.is_file();key=dep.relative_to(ROOT).as_posix()
   if key not in native:native.add(key);pending.append(key)
 native=sorted(native);helpers=['tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','tools/native_reconstruction/animation/ground_constraint_tests.cpp','tools/native_reconstruction/animation/verify_ground_constraints.py'];files=native+helpers+originals;before={n:sha(ROOT/n)for n in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),corpus=dict(path=str(corpus_receipt),sha256=sha(corpus_receipt)),original_owned_bodies=proof,game_run=False)
 try:
  for n in files:
   target=out/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/n).read_bytes())
  (out/'tests.cpp').write_bytes((ROOT/helpers[1]).read_bytes());reference=(ROOT/helpers[0]).read_text().replace('pc{},branch_pc{},fcr31{}','pc{},branch_pc{},fcr31{},vu0_vpu_stat{}')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define FPU_SQRT_S(a) std::sqrt(a)\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n';(out/'reference.hpp').write_text(reference)
  body='\n'.join((ROOT/n).read_text()for n in originals);(out/'original_models.cpp').write_text(body);actual={Path(n).stem for n in originals};names=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual));decl+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for n in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl)
  (out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(n).stem+'(memory,context,runtime);return;\n'for at,n in sorted(entries.items())))
  for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
  (out/'o0_functions.h').write_text('#pragma once\n#include "functions.h"\n')
  (out/'o2_functions.h').write_text('#pragma once\n#include "functions.h"\n')
  (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
  for n in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/n).write_text('#pragma once\n')
  init='inline void owned_constants(std::uint8_t* p){\n';record['owned_constants']={}
  for at,size in [(0x22fe20,32),(0x241c78,40),(0x241e90,4)]:
   raw=read(at,size);record['owned_constants'][hex(at)]=raw.hex();init+=' {const std::uint8_t bytes[]{'+','.join(str(v)for v in raw)+'};std::memcpy(p+'+str(at)+',bytes,sizeof bytes);}\n'
  profile_path=ROOT/'build-native-sjuni/model-scale-profile-v1/receipt.json';profile=json.loads(profile_path.read_bytes());assert profile['status']=='passed'and hashlib.sha256((ROOT/'game/native/gameplay_world/model_scale_profile.inc').read_bytes()).hexdigest()==profile['output_sha256'];record['scale_profile']=dict(path=str(profile_path),sha256=sha(profile_path))
  correction={}
  for at,count,stride in [(0x71ae00,8,12),(0x73eae0,3,4),(0x70afc0,16,4),(0x73eaf8,1,4),(0x73eb00,1,4)]:
   correction[hex(at)]=[]
   for i in range(count):
    raw=overlay[at+i*stride-0x570000:at+i*stride-0x570000+4];correction[hex(at)].append(raw.hex());init+=' {const std::uint8_t bytes[]{'+','.join(str(v)for v in raw)+'};std::memcpy(p+'+str(at+i*stride)+',bytes,sizeof bytes); }\n'
  for index,bits in profile['variant_scale_bits']:
   at=0x716444+20*index;raw=overlay[at-0x570000:at-0x570000+4];assert int.from_bytes(raw,'little')==bits;correction[hex(at)]=raw.hex();init+=' {const std::uint8_t bytes[]{'+','.join(str(v)for v in raw)+'};std::memcpy(p+'+str(at)+',bytes,sizeof bytes); }\n'
  record['correction_tables']=correction
  floor_receipt=a.floor_receipt.resolve();floorq=json.loads(floor_receipt.read_bytes());assert floorq['results']['checks']==205015
  for n in ['game/native/gameplay_collision/response.hpp','game/native/gameplay_collision/response.cpp']:assert sha(ROOT/n)==floorq['source_sha256'][n]
  archive=ROOT/'iso/Resident Evil - Outbreak (v2.00).iso';chosen=[];package=[];record['floor_image']=str(archive)
  for name in ['g0010100.bin','g0022205.bin','g0280200.bin','g0350100.bin','g0410100.bin']:
   item=next(x for x in floorq['owned_assets']if x['names'][-1]==name)
   with archive.open('rb')as f:f.seek(item['iso_offset']);raw=f.read(item['bytes'])
   assert hashlib.sha256(raw).hexdigest()==item['sha256'];chosen.append(item);package.append(raw)
  import struct
  (out/'owned_floors.bin').write_bytes(struct.pack('<I',len(package))+b''.join(struct.pack('<I',len(raw))+raw for raw in package));record['owned_floors']=chosen;record['floor_receipt']=dict(path=str(floor_receipt),sha256=sha(floor_receipt))
  (out/'owned_constants.hpp').write_text(init+'}\n');(out/'owned_clips.bin').write_bytes((corpus/'owned_clips.bin').read_bytes());(out/'owned_skeletons.bin').write_bytes((corpus/'owned_skeletons.bin').read_bytes())
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/n)for n in native_cpp],str(out/'tests.cpp'),'-o',str(binary)];record['command']=command
  r=subprocess.run(command,env=env,capture_output=True,text=True,timeout=180);(out/'compile.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'compile failed'
  r=subprocess.run([str(binary),str(out/'owned_clips.bin'),str(out/'owned_skeletons.bin'),str(out/'owned_floors.bin')],env=env,capture_output=True,text=True,timeout=120);(out/'run.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'comparison failed'
  record.update(status='passed',observed=json.loads(r.stdout),binary_sha256=sha(binary),source_unchanged=all(sha(ROOT/n)==h for n,h in before.items()));assert record['source_unchanged']
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
