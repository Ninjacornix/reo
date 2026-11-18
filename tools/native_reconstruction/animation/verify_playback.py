"""Compare full native actor motion channel configuration, transition and update consumers."""
import argparse,hashlib,json,os,re,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--corpus',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 corpus=a.corpus.resolve();corpus_receipt=corpus/'receipt.json';cr=json.loads(corpus_receipt.read_bytes());assert cr['clips']==59 and cr['skeletons']==2
 for n,h in cr['output_sha256'].items():assert sha(corpus/n)==h
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes())
 pending=[0x58c810,0x58c8a0,0x61b1a0,0x5d1c70,0x5d1da0,0x5d1ea0,0x58c970,0x58cc80,0x18e3c0,0x1a1fd0,0x193c80,0x1a2e00,0x193380,0x193240,0x193230,0x193220,0x192bf0,0x1925c0,0x192b30,0x5d59a0,0x5d5ab0,0x5d5ad0,0x5d5bd0,0x5d5be0,0x5d5fa0,0x5d6850,0x5d42d0,0x5d43c0,0x58ce00,0x192690,0x191900,0x58b9a0,0x58ce60,0x58d0e0,0x58c130,0x58c460,0x58c7b0,0x58c7f0,0x5d5950,0x58c300,0x5d57d0,0x192d80,0x192da0,0x1118b8,0x111d48,0x112470,0x1a4db0,0x192a00];entries={}
 while pending:
  at=pending.pop()
  if at in entries or at in [0x18dca0,0x1a0d70,0x107c68,0x573430]:continue
  bank='o2'if at>=0x570000 else 'o0'if at>=0x370000 else None
  found=list((ROOT/('recomp/config/output_ovl/'+bank)if bank else ROOT/'recomp/config/output').glob(f'{bank or "sub"}_{at:08X}_*'))
  if not found:continue # Internal merged-body labels are not callable definitions.
  name=found[0].relative_to(ROOT).as_posix();entries[at]=name;s=found[0].read_text()
  pending.extend(int(v,16)for v in re.findall(r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)',s)if int(v,16)not in entries)
 o0=ROOT/'build-function-index/owned-overlays/o0.bin';assert sha(o0)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2';o0raw=o0.read_bytes()
 o2=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(o2)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';overlay=o2.read_bytes()
 for at in [0x58bf50,0x58c6a0]:entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*')).relative_to(ROOT).as_posix()
 originals=list(entries.values());proof=[]
 for n in originals:
  begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/n).read_text()).groups()];proof.append(compare_source('complete original skeleton/model/frame/root or math body',n,begin,end,read if begin<0x370000 else (lambda at,size:o0raw[at-0x370000:at-0x370000+size])if begin<0x570000 else lambda at,size:overlay[at-0x570000:at-0x570000+size]))
 native=['game/native/animation/scalar_playback.cpp','game/native/animation/scalar_playback.hpp','game/native/animation/primary_motion_routing.hpp','game/native/animation/primary_track_layouts.inc','game/native/animation/playback.hpp','game/native/animation/playback.cpp','game/native/animation/motion_bank.hpp','game/native/animation/motion_bank.cpp','game/native/animation/model_blend.hpp','game/native/animation/model_blend.cpp','game/native/animation/constraints.hpp','game/native/animation/constraints.cpp','game/native/animation/constraint_math.hpp','game/native/animation/constraint_math.cpp','game/native/animation/model.hpp','game/native/animation/model.cpp','game/native/animation/model_math.hpp','game/native/animation/model_math.cpp','game/native/animation/curves.hpp','game/native/animation/curves.cpp','game/native/transform_math/transform_math.hpp','game/native/transform_math/transform_math.cpp'];helpers=['tools/native_reconstruction/animation/scalar_playback_tests.inc','tools/native_reconstruction/animation/node_topology_tests.inc','tools/native_reconstruction/animation/primary_motion_routing_tests.inc','tools/native_reconstruction/animation/whole_playback_tests.inc','third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','tools/native_reconstruction/animation/playback_tests.cpp','tools/native_reconstruction/animation/verify_playback.py'];files=native+helpers+originals;before={n:sha(ROOT/n)for n in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),corpus=dict(path=str(corpus_receipt),sha256=sha(corpus_receipt)),original_owned_bodies=proof,game_run=False)
 try:
  for n in files:
   target=out/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/n).read_bytes())
  (out/'scalar_playback_tests.inc').write_bytes((ROOT/'tools/native_reconstruction/animation/scalar_playback_tests.inc').read_bytes())
  (out/'node_topology_tests.inc').write_bytes((ROOT/'tools/native_reconstruction/animation/node_topology_tests.inc').read_bytes())
  (out/'primary_motion_routing_tests.inc').write_bytes((ROOT/'tools/native_reconstruction/animation/primary_motion_routing_tests.inc').read_bytes())
  (out/'whole_playback_tests.inc').write_bytes((ROOT/'tools/native_reconstruction/animation/whole_playback_tests.inc').read_bytes());(out/'tests.cpp').write_bytes((ROOT/'tools/native_reconstruction/animation/playback_tests.cpp').read_bytes());reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text().replace('pc{},branch_pc{},fcr31{}','pc{},branch_pc{},fcr31{},vu0_vpu_stat{}')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define FPU_SQRT_S(a) std::sqrt(a)\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n';reference=reference.replace('Register r[32];','std::uint64_t lo{},hi{},lo1{},hi1{};Register r[32];')+'\n#define SRA32(v,n) (std::int32_t(v) >> (n))\n#include \"ps2_fpu_convert.h\"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n';(out/'reference.hpp').write_text(reference);sdk=ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h';(out/'ps2_fpu_convert.h').write_bytes(sdk.read_bytes());record['conversion_profile']=dict(path=str(sdk),sha256=sha(sdk))
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
  for at,size in [(0x70afa8,12),(0x73eaf8,4),(0x73eb00,4),(0x70ad60,320),(0x70f628,104)]:
   raw=overlay[at-0x570000:at-0x570000+size];record['owned_constants'][hex(at)]=raw.hex();init+=' {const std::uint8_t bytes[]{'+','.join(str(v)for v in raw)+'};std::memcpy(p+'+str(at)+',bytes,sizeof bytes); }\n'
  (out/'owned_constants.hpp').write_text(init+'}\n');(out/'owned_clips.bin').write_bytes((corpus/'owned_clips.bin').read_bytes());(out/'owned_skeletons.bin').write_bytes((corpus/'owned_skeletons.bin').read_bytes());import struct;bank_raw=[(corpus/n).read_bytes()for n in ['pc_000.bin','pc_001.bin']];inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';members=json.loads(inventory.read_bytes());record['whole_model_assets']=[]
  for member in ['NETBIO00.DAT/0/757','NETBIO00.DAT/0/758']:
   item=next(x for x in members if x['member']==member)
   with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb')as f:f.seek(item['iso_offset']);raw=f.read(item['bytes'])
   assert __import__('hashlib').sha256(raw).hexdigest()==item['sha256'];bank_raw.append(raw);record['whole_model_assets'].append(item)
  supplemental=[];original_package=(out/'owned_skeletons.bin').read_bytes()
  for member in ['NETBIO00.DAT/0/490','NETBIO00.DAT/0/507']:
   item=next(x for x in members if x['member']==member)
   with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb')as stream:stream.seek(item['iso_offset']);payload=stream.read(item['bytes'])
   assert hashlib.sha256(payload).hexdigest()==item['sha256'];offset,length=struct.unpack_from('<II',payload,0x24);assert offset and length and length<=len(payload)-offset;supplemental.append(payload[offset:offset+length]);record.setdefault('primary_routing_model_assets',[]).append(item)
  (out/'owned_skeletons.bin').write_bytes(struct.pack('<I',struct.unpack_from('<I',original_package)[0]+len(supplemental))+original_package[4:]+b''.join(struct.pack('<I',len(b))+b for b in supplemental))
  record['declared_routing_ports']=['1A0D70 resolves the bounded packed clip header identity; full1A1FD0 packing and count checks execute independently.','22-track playback uses an explicitly controlled first22-track container from owned36-track curves. No stock22-track body clip was found in the admitted scene catalogue.']
  (out/'owned_banks.bin').write_bytes(struct.pack('<I',len(bank_raw))+b''.join(struct.pack('<I',len(b))+b for b in bank_raw));record['bank_assets']=[x for x in cr['assets']if x['name'].lower()in['pc_000.bin','pc_001.bin']]
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-DREO_WHOLE_PLAYBACK_TESTS=1','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/n)for n in native if n.endswith('.cpp')],str(out/'tests.cpp'),'-o',str(binary)];record['command']=command
  r=subprocess.run(command,env=env,capture_output=True,text=True,timeout=180);(out/'compile.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'compile failed'
  r=subprocess.run([str(binary),str(out/'owned_clips.bin'),str(out/'owned_skeletons.bin'),str(out/'owned_banks.bin')],env=env,capture_output=True,text=True,timeout=120);(out/'run.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'comparison failed'
  record.update(status='passed',observed=json.loads(r.stdout),binary_sha256=sha(binary),source_unchanged=all(sha(ROOT/n)==h for n,h in before.items()));assert record['source_unchanged']
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
