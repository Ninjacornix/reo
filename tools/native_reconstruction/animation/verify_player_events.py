"""Compare complete player schedules and all original family dispatch domains."""
import argparse,hashlib,json,os,re,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--corpus',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir();image=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=image.read_bytes();originals=[];proof=[]
 for at in [0x573430,0x5958b0,0x5959d0,0x5a8fd0,0x5965a0,0x59a820,0x59ebb0,0x59fca0,0x5a04e0]:
  src=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'));begin,end=[int(x,16)for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',src.read_text()).groups()];proof.append(compare_source('complete animation family/player schedule',src.relative_to(ROOT).as_posix(),begin,end,lambda at,n:raw[at-0x570000:at-0x570000+n]));originals.append(src.relative_to(ROOT).as_posix())
 cpp=['game/native/'+n for n in ['gameplay_world/animation_events.cpp','animation/playback.cpp','animation/model_blend.cpp','animation/model.cpp','animation/model_math.cpp','animation/curves.cpp','animation/motion_bank.cpp','animation/constraints.cpp','animation/constraint_math.cpp','transform_math/transform_math.cpp']];native=set(cpp);pending=cpp.copy()
 while pending:
  n=pending.pop()
  for rel in re.findall(r'^#include "([^"\n]+)"',(ROOT/n).read_text(),re.M):
   dep=((ROOT/n).parent/rel).resolve();assert dep.is_relative_to(ROOT/'game/native')and dep.is_file();key=dep.relative_to(ROOT).as_posix()
   if key not in native:native.add(key);pending.append(key)
 helpers=['tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','tools/native_reconstruction/animation/player_event_tests.cpp',Path(__file__).relative_to(ROOT).as_posix()];files=sorted(native)+helpers+originals;before={n:sha(ROOT/n)for n in files};corpus=a.corpus.resolve();cr=json.loads((corpus/'receipt.json').read_bytes());assert cr['skeletons']==2 and sha(corpus/'owned_skeletons.bin')==cr['output_sha256']['owned_skeletons.bin'];record=dict(schema=1,status='failed',source_sha256=before,original_owned_bodies=proof,compiler_sha256=sha(a.compiler),corpus=dict(path=str(corpus/'receipt.json'),sha256=sha(corpus/'receipt.json')),game_run=False)
 try:
  for n in files:target=out/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/n).read_bytes())
  (out/'tests.cpp').write_bytes((ROOT/helpers[1]).read_bytes());(out/'reference.hpp').write_bytes((ROOT/helpers[0]).read_bytes());body='\n'.join((ROOT/n).read_text()for n in originals);(out/'original.cpp').write_text(body);actual={Path(n).stem for n in originals};names=set(re.findall(r'\b(o2_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual));decl+=''.join('inline void '+n+'(std::uint8_t*m,R5900Context*c,PS2Runtime*r){original_transform_port(m,c,r);}\n'for n in sorted(names-actual));(out/'functions.h').write_text(decl)
  for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
  for n in ['o2_functions.h','ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/n).write_text('#pragma once\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';cmd=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/n)for n in cpp],str(out/'tests.cpp'),'-o',str(binary)];record['command']=cmd;r=subprocess.run(cmd,capture_output=True,text=True,env=env,timeout=180);(out/'compile.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'compile failed';r=subprocess.run([str(binary),str(image),str(corpus/'owned_skeletons.bin')],capture_output=True,text=True,env=env,timeout=180);(out/'run.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'comparison failed';record.update(status='passed',observed=json.loads(r.stdout),source_unchanged=all(sha(ROOT/n)==h for n,h in before.items()));assert record['source_unchanged']
 finally:record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps({'status':record['status'],'observed':record['observed']}))
if __name__=='__main__':main()
