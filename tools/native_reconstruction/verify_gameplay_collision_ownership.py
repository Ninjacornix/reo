"""Audit pool/derived geometry/wall caller against owned unchanged originals."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
ENTRIES=[0x5c1120,0x5c11b0,0x5c12a0,0x5c5d30,0x5c6100,0x5c62f0,0x5c63b0,0x5c6480,0x5c6550,0x5c66c0,0x5da420]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
 if out.exists() or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output required')
 image=ROOT/'build-function-index/owned-overlays/o2.bin';data=image.read_bytes()
 if sha(image)!='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226':raise ValueError('Owned image changed')
 sources=[];bodies=[];audits=[]
 for start in ENTRIES:
  source=ROOT/f'recomp/config/output_ovl/o2/o2_{start:08X}_0x{start:x}.cpp';text=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)',text)[1],16);sources.append(source);audits.append(compare_source('collision-owner',str(source.relative_to(ROOT)),start,end,lambda at,n:data[at-0x570000:at-0x570000+n]));bodies.append(text[text.index('// Function:'):])
 base=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp';ports=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/ownership_ports.hpp';header=base.read_text().split('void o0_00370760')[0]
 header+='\n#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))\n#include "tools/native_reconstruction/gameplay_collision_oracle/ownership_ports.hpp"\n'
 header+='\n'.join(f'void o2_{s:08X}_0x{s:x}(std::uint8_t*,R5900Context*,PS2Runtime*);' for s in ENTRIES)
 header+='\ninline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{switch(at){\n'
 header+='\n'.join(f'case 0x{s:x}:return o2_{s:08X}_0x{s:x};' for s in ENTRIES)
 for at,name in [(0x107c68,'memset'),(0x107ab0,'memcpy'),(0x1900e0,'matrix_copy'),(0x191430,'inverse'),(0x370570,'vector'),(0x370500,'vector'),(0x1919d0,'transform'),(0x1920a0,'abs')]:header+=f'\ncase 0x{at:x}:return port_{name};'
 header+='\ncase 0x6177c0:return o2_006177C0_0x6177c0;default:throw std::runtime_error("Undeclared owner support call");}}\n'
 names=['collision.cpp','collision.hpp','response.cpp','response.hpp','sweep.cpp','sweep.hpp','actors.cpp','actors.hpp','ownership.cpp','ownership.hpp','ownership_tests.cpp']
 paths=[ROOT/'game/native/gameplay_collision'/n for n in names]+[ROOT/'game/native/gameplay_actors/entity.hpp',ROOT/'game/native/gameplay_actors/entity.cpp',base,ports,ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',Path(__file__),*sources]
 inputs={p.relative_to(ROOT).as_posix():sha(p) for p in paths};out.mkdir();(out/'ownership_reference.hpp').write_text(header);original=out/'original.cpp';original.write_text('#include "ownership_reference.hpp"\n'+'\n'.join(bodies))
 compiler=COMPILERS[a.compiler];env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');exe=out/'ownership.exe';record=dict(schema=1,status='failed',source_sha256=inputs,compiler_sha256=sha(compiler),original_word_audits=audits,game_launched=False,checks=[])
 command=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out),*[str(ROOT/'game/native/gameplay_collision'/n) for n in names if n.endswith('.cpp')],str(ROOT/'game/native/gameplay_actors/entity.cpp'),str(original),'-o',str(exe)]
 try:
  for label,cmd in [('compile',command),('test',[str(exe)])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=120);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append(dict(label=label,command=cmd,exit=result.returncode))
   if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-3000:])
   if label=='test':record['results']=json.loads(result.stdout)
  for name,digest in inputs.items():
   if sha(ROOT/name)!=digest:raise ValueError('Source changed: '+name)
  record['status']='native collision owner/model geometry/caller comparisons passed'
 finally:
  record['output_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['results']))
if __name__=='__main__':main()
