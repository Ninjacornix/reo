"""Owned original hit-region pose/reset/queue comparison; no game execution."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
 if out.exists() or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output required')
 image=ROOT/'build-function-index/owned-overlays/o2.bin'
 if sha(image)!='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226':raise ValueError('Owned overlay changed')
 data=image.read_bytes();sources=[];bodies=[];audits=[]
 for start in [0x5dc1b0,0x5dc2a0,0x5dc3a0]:
  source=ROOT/f'recomp/config/output_ovl/o2/o2_{start:08X}_0x{start:x}.cpp';text=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)',text)[1],16);sources.append(source);audits.append(compare_source('hit-regions-original',str(source.relative_to(ROOT)),start,end,lambda at,size:data[at-0x570000:at-0x570000+size]));bodies.append(text[text.index('// Function:'):])
 base=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp';header=base.read_text();header=header[:header.index('inline PS2Runtime::Fn PS2Runtime::lookupFunction')];header=header.replace('#define WRITE32','#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define WRITE32');header+='\n#include "tools/native_reconstruction/gameplay_collision_oracle/hit_regions_ports.hpp"\ninline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{if(at==0x1919d0)return sub_001919D0_0x1919d0;throw std::runtime_error("Undeclared hit-region support call");}\n'
 names=['collision.cpp','collision.hpp','response.cpp','response.hpp','actors.cpp','actors.hpp','spatial.hpp','hit_regions.cpp','hit_regions.hpp','hit_regions_tests.cpp'];paths=[ROOT/'game/native/gameplay_collision'/n for n in names]+[base,Path(__file__),ROOT/'tools/native_reconstruction/gameplay_collision_oracle/hit_regions_ports.hpp',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',ROOT/'game/native/gameplay_actors/entity.cpp']+[ROOT/'game/native/gameplay_actors'/n for n in ['entity.hpp','hit.hpp','status.hpp','health.hpp']]+[ROOT/'game/native/gameplay_session/session.hpp',*sources]
 inputs={p.relative_to(ROOT).as_posix():sha(p) for p in paths};out.mkdir();(out/'hit_regions_reference.hpp').write_text(header);original=out/'original.cpp';original.write_text('#include "hit_regions_reference.hpp"\n'+'\n'.join(bodies));compiler=COMPILERS[a.compiler];env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');exe=out/'hit_regions.exe';record=dict(schema=1,status='failed',source_sha256=inputs,compiler_sha256=sha(compiler),original_word_audits=audits,game_launched=False,checks=[])
 command=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out),*[str(ROOT/'game/native/gameplay_collision'/n) for n in names if n.endswith('.cpp')],str(ROOT/'game/native/gameplay_actors/entity.cpp'),str(original),'-o',str(exe)]
 try:
  for label,cmd in [('compile',command),('test',[str(exe)])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=120);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append(dict(label=label,command=cmd,exit=result.returncode))
   if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-3000:])
   if label=='test':record['results']=json.loads(result.stdout)
  for name,digest in inputs.items():
   if sha(ROOT/name)!=digest:raise ValueError('Source changed: '+name)
  record['status']='native hit-region pose and queue comparisons passed'
 finally:
  record['output_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['results']))
if __name__=='__main__':main()
