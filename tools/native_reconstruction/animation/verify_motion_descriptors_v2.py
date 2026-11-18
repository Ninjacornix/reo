"""Compare native concrete File1 descriptor lookup/unpack with complete original bodies."""
import argparse,hashlib,json,os,re,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');image=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=image.read_bytes();read=lambda at,n:raw[at-0x570000:at-0x570000+n];profile=ROOT/'build-native-sjuni/motion-descriptor-profile-v2/receipt.json';q=json.loads(profile.read_bytes());assert q['status']=='passed';assert sha(ROOT/'game/native/animation/motion_descriptor_profile.inc')==q['output_sha256'];entries={};proof=[]
 for at in [0x5d4570,0x5d46c0]:
  f=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'));begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',f.read_text()).groups()];name=f.relative_to(ROOT).as_posix();proof.append(compare_source('complete original descriptor consumer',name,begin,end,read));entries[at]=name
 native=['game/native/animation/'+x for x in ['motion_descriptors.hpp','motion_descriptors.cpp','motion_descriptor_profile.inc']];helpers=['tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','tools/native_reconstruction/animation/motion_descriptor_v2_tests.cpp','tools/native_reconstruction/animation/verify_motion_descriptors_v2.py'];files=native+helpers+list(entries.values());before={n:sha(ROOT/n)for n in files};out.mkdir(parents=True);record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),original_owned_bodies=proof,profile=dict(path=str(profile),sha256=sha(profile)),game_run=False)
 try:
  for n in files:
   dest=out/'source'/n;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes((ROOT/n).read_bytes())
  (out/'tests.cpp').write_bytes((ROOT/helpers[1]).read_bytes());(out/'reference.hpp').write_text((ROOT/helpers[0]).read_text()+'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define SRA32(v,n) (std::int32_t(v) >> (n))\n');(out/'original.cpp').write_text('\n'.join((ROOT/n).read_text()for n in entries.values()));(out/'functions.h').write_text(''.join('void '+Path(n).stem+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in entries.values()));(out/'dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(n).stem+'(memory,context,runtime);return;\n'for at,n in entries.items()))
  for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
  (out/'o2_functions.h').write_text('#pragma once\n#include "functions.h"\n')
  for n in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/n).write_text('#pragma once\n')
  init='inline void constants(std::uint8_t* p){\n';record['owned_metadata']={}
  for at,size in [(0x725ca0,0x726aa0-0x725ca0),(0x726aa0,1112*8),(0x719a60,64*68)]:
   b=read(at,size);record['owned_metadata'][hex(at)]=dict(bytes=size,sha256=hashlib.sha256(b).hexdigest());init+='{const std::uint8_t b[]{'+','.join(map(str,b))+'};std::memcpy(p+'+str(at)+',b,sizeof b); }\n'
  (out/'constants.hpp').write_text(init+'}\n');env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';cmd=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),str(out/'source/game/native/animation/motion_descriptors.cpp'),str(out/'tests.cpp'),'-o',str(binary)];record['command']=cmd;r=subprocess.run(cmd,env=env,capture_output=True,text=True,timeout=90);(out/'compile.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'compile failed';r=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=90);(out/'run.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'comparison failed';record.update(status='passed',observed=json.loads(r.stdout),source_unchanged=all(sha(ROOT/n)==h for n,h in before.items()));assert record['source_unchanged']
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
