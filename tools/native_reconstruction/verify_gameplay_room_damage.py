"""Compare native room-contact counters and actual FlagState binding with complete original functions."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
 if out.exists()or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output required')
 sources=[];bodies=[];audits=[];image=ROOT/'build-function-index/owned-overlays/o2.bin'
 if sha(image)!='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226':raise ValueError('Owned overlay changed')
 data=image.read_bytes()
 for at in [0x5d7cf0,0x570a30,0x570620,0x570670,0x5706b0]:
  source=ROOT/f'recomp/config/output_ovl/o2/o2_{at:08X}_0x{at:x}.cpp';text=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)',text)[1],16);sources.append(source);audits.append(compare_source('native-room-contact-damage',str(source.relative_to(ROOT)),at,end,lambda pos,size:data[pos-0x570000:pos-0x570000+size]));bodies.append(text[text.index('// Function:'):])
 base=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp';ports=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/room_damage_ports.hpp'
 names=['room_damage.hpp','room_damage.cpp','room_damage_tests.cpp','contact_routes.hpp']
 paths=[ROOT/'game/native/gameplay_collision'/n for n in names]+[ROOT/'game/native/gameplay_scenario'/n for n in ['flags.hpp','flags.cpp','interpreter.hpp']]+[base,ports,Path(__file__),ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',*sources];inputs={p.relative_to(ROOT).as_posix():sha(p)for p in paths}
 declarations='\n'.join(f'void o2_{at:08X}_0x{at:x}(std::uint8_t*,R5900Context*,PS2Runtime*);'for at in [0x5d7cf0,0x570a30,0x570620,0x570670,0x5706b0])
 header=base.read_text().split('void o0_00370760_0x370760')[0]+'\n#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))\n'+declarations+'\n'+ports.read_text()
 out.mkdir();(out/'damage_reference.hpp').write_text(header);original=out/'original.cpp';original.write_text('#include "damage_reference.hpp"\n#pragma GCC diagnostic ignored "-Wunused-variable"\n'+'\n'.join(bodies));compiler=COMPILERS[a.compiler];env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');exe=out/'damage.exe'
 command=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out),str(ROOT/'game/native/gameplay_collision/room_damage.cpp'),str(ROOT/'game/native/gameplay_collision/room_damage_tests.cpp'),str(ROOT/'game/native/gameplay_scenario/flags.cpp'),str(original),'-o',str(exe)];record=dict(schema=1,status='failed',source_sha256=inputs,compiler_sha256=sha(compiler),original_word_audits=audits,game_launched=False,checks=[])
 try:
  for label,cmd in [('compile',command),('test',[str(exe)])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=120);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append(dict(label=label,command=cmd,exit=result.returncode))
   if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-2500:])
   if label=='test':record['results']=json.loads(result.stdout)
  for name,digest in inputs.items():
   if sha(ROOT/name)!=digest:raise ValueError('Source changed: '+name)
  record['status']='native room contact counter and canonical FlagState binding match full original bodies with declared matrix-program/notify providers'
 finally:
  record['output_sha256']={p.name:sha(p)for p in out.iterdir()if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['results']))
if __name__=='__main__':main()
