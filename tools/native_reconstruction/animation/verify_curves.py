"""Compare native imported curves against original raw packing and sampling."""
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
 pending=[0x18e3c0,0x1a1fd0,0x193c80];entries={}
 while pending:
  at=pending.pop()
  if at in entries:continue
  found=list((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*'))
  if not found:continue # Internal merged-body labels are not callable definitions.
  name=found[0].relative_to(ROOT).as_posix();entries[at]=name;s=found[0].read_text()
  pending.extend(int(v,16)for v in re.findall(r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)',s)if int(v,16)not in entries)
 originals=list(entries.values());proof=[]
 for n in originals:
  begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/n).read_text()).groups()];proof.append(compare_source('complete original raw curve packing or sampled helper',n,begin,end,read))
 native=['game/native/animation/curves.hpp','game/native/animation/curves.cpp','game/native/transform_math/transform_math.hpp','game/native/transform_math/transform_math.cpp'];helpers=['tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','tools/native_reconstruction/animation/curves_tests.cpp','tools/native_reconstruction/animation/verify_curves.py'];files=native+helpers+originals;before={n:sha(ROOT/n)for n in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),corpus=dict(path=str(corpus_receipt),sha256=sha(corpus_receipt)),original_owned_bodies=proof,game_run=False)
 try:
  for n in files:
   target=out/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/n).read_bytes())
  (out/'tests.cpp').write_bytes((ROOT/helpers[1]).read_bytes());reference=(ROOT/helpers[0]).read_text().replace('pc{},branch_pc{},fcr31{}','pc{},branch_pc{},fcr31{},vu0_vpu_stat{}')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define FPU_SQRT_S(a) std::sqrt(a)\n';(out/'reference.hpp').write_text(reference)
  body='\n'.join((ROOT/n).read_text()for n in originals);(out/'original_curves.cpp').write_text(body);actual={Path(n).stem for n in originals};names=set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual));decl+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for n in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl)
  (out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(n).stem+'(memory,context,runtime);return;\n'for at,n in sorted(entries.items())))
  for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
  (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
  for n in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/n).write_text('#pragma once\n')
  init='inline void owned_constants(std::uint8_t* p){\n';record['owned_constants']={}
  for at,size in [(0x22fe20,32),(0x241c78,40),(0x241e90,4)]:
   raw=read(at,size);record['owned_constants'][hex(at)]=raw.hex();init+=' {const std::uint8_t bytes[]{'+','.join(str(v)for v in raw)+'};std::memcpy(p+'+str(at)+',bytes,sizeof bytes);}\n'
  (out/'owned_constants.hpp').write_text(init+'}\n');(out/'owned_clips.bin').write_bytes((corpus/'owned_clips.bin').read_bytes())
  inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';item=next(x for x in json.loads(inventory.read_bytes())if x['member']=='NETBIO00.DAT/0/854')
  with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb')as f:f.seek(item['iso_offset']);raw=f.read(item['bytes'])
  assert len(raw)==item['bytes']and hashlib.sha256(raw).hexdigest()==item['sha256'];table=int.from_bytes(raw[12:16],'little');start=int.from_bytes(raw[table:table+4],'little');size=int.from_bytes(raw[start+8:start+12],'little');assert 20<=size<=len(raw)-start;extra=raw[start:start+size];(out/'owned_object_clip.bin').write_bytes(extra);record['extra_owned_clip']=dict(member=item['member'],bank_sha256=item['sha256'],offset=start,bytes=size,sha256=hashlib.sha256(extra).hexdigest())
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),str(out/'source'/native[1]),str(out/'source'/native[3]),str(out/'tests.cpp'),'-o',str(binary)];record['command']=command
  r=subprocess.run(command,env=env,capture_output=True,text=True,timeout=180);(out/'compile.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'compile failed'
  r=subprocess.run([str(binary),str(out/'owned_clips.bin'),str(out/'owned_object_clip.bin')],env=env,capture_output=True,text=True,timeout=120);(out/'run.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'comparison failed'
  record.update(status='passed',observed=json.loads(r.stdout),binary_sha256=sha(binary),source_unchanged=all(sha(ROOT/n)==h for n,h in before.items()));assert record['source_unchanged']
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
